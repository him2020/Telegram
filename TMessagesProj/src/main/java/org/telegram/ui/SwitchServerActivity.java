package org.telegram.ui;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import org.telegram.messenger.AndroidUtilities;
import org.telegram.messenger.LocaleController;
import org.telegram.messenger.R;
import org.telegram.ui.ActionBar.ActionBar;
import org.telegram.ui.ActionBar.ActionBarMenu;
import org.telegram.ui.ActionBar.BaseFragment;
import org.telegram.ui.ActionBar.Theme;
import org.telegram.ui.ActionBar.ThemeDescription;
import org.telegram.ui.Cells.ConnectServerCell;
import org.telegram.ui.Cells.LanguageCell;
import org.telegram.ui.Cells.ShadowSectionCell;
import org.telegram.ui.Components.EmptyTextProgressView;
import org.telegram.ui.Components.LayoutHelper;
import org.telegram.ui.Components.RecyclerListView;

public class SwitchServerActivity extends BaseFragment {

    private ListAdapter listAdapter;
    private RecyclerListView listView;
    private EmptyTextProgressView emptyView;
    private LocaleController.ConnectServerInfo currentServerInfo;

    private ArrayList<LocaleController.ConnectServerInfo> listServerInfo;

    @Override
    public boolean onFragmentCreate() {
        fillConnectServerInfo();
        return super.onFragmentCreate();
    }

    @Override
    public void onFragmentDestroy() {
        super.onFragmentDestroy();
    }

    @Override
    public View createView(Context context) {
        actionBar.setBackButtonImage(R.drawable.ic_ab_back);
        actionBar.setAllowOverlayTitle(true);
        actionBar.setTitle(LocaleController.getString("ConnectServer", R.string.ConnectServer));

        actionBar.setActionBarMenuOnItemClick(new ActionBar.ActionBarMenuOnItemClick() {
            @Override
            public void onItemClick(int id) {
                if (id == -1) {
                    finishFragment();
                } else if (id == 1) {
                    if (currentServerInfo != null) {
                        LocaleController.getInstance().applyConnectServer(currentServerInfo.hostName, currentServerInfo.hostAddress);
                    }
                    finishFragment();
                }
            }
        });

        ActionBarMenu menu = actionBar.createMenu();
        menu.addItem(0, R.drawable.msg_edit);
        menu.addItem(1, R.drawable.ic_ab_done);

        listAdapter = new ListAdapter(context);
        fragmentView = new FrameLayout(context);
        fragmentView.setBackgroundColor(Theme.getColor(Theme.key_windowBackgroundGray));
        FrameLayout frameLayout = (FrameLayout) fragmentView;

        emptyView = new EmptyTextProgressView(context);
        emptyView.setText(LocaleController.getString("NoResult", R.string.NoResult));
        emptyView.showTextView();
        emptyView.setShowAtCenter(true);
        frameLayout.addView(emptyView, LayoutHelper.createFrame(LayoutHelper.MATCH_PARENT, LayoutHelper.MATCH_PARENT));

        listView = new RecyclerListView(context);
        listView.setEmptyView(emptyView);
        listView.setLayoutManager(new LinearLayoutManager(context, LinearLayoutManager.VERTICAL, false));
        listView.setVerticalScrollBarEnabled(false);
        listView.setAdapter(listAdapter);
        frameLayout.addView(listView, LayoutHelper.createFrame(LayoutHelper.MATCH_PARENT, LayoutHelper.MATCH_PARENT));

        listView.setOnItemClickListener((view, position) -> {
            if (getParentActivity() == null || parentLayout == null || !(view instanceof ConnectServerCell)) {
                return;
            }
            ConnectServerCell cell = (ConnectServerCell) view;
            LocaleController.ConnectServerInfo serverInfo = cell.getCurrentServerInfo();
            if (serverInfo != null) {
                currentServerInfo = serverInfo;
                if (listAdapter != null) {
                    listAdapter.notifyDataSetChanged();
                }
            }
        });

        listView.setOnItemLongClickListener((view, position) -> {
            if (getParentActivity() == null || parentLayout == null || !(view instanceof ConnectServerCell)) {
                return false;
            }
//            LanguageCell cell = (LanguageCell) view;
//            LocaleController.LocaleInfo localeInfo = cell.getCurrentLocale();
//            if (localeInfo == null || localeInfo.pathToFile == null || localeInfo.isRemote() && localeInfo.serverIndex != Integer.MAX_VALUE) {
//                return false;
//            }
//            final LocaleController.LocaleInfo finalLocaleInfo = localeInfo;
//            AlertDialog.Builder builder = new AlertDialog.Builder(getParentActivity());
//            builder.setTitle(LocaleController.getString("DeleteLocalizationTitle", R.string.DeleteLocalizationTitle));
//            builder.setMessage(AndroidUtilities.replaceTags(LocaleController.formatString("DeleteLocalizationText", R.string.DeleteLocalizationText, localeInfo.name)));
//            builder.setPositiveButton(LocaleController.getString("Delete", R.string.Delete), (dialogInterface, i) -> {
//                if (LocaleController.getInstance().deleteLanguage(finalLocaleInfo, currentAccount)) {
//                    fillLanguages();
//                    if (searchResult != null) {
//                        searchResult.remove(finalLocaleInfo);
//                    }
//                    if (listAdapter != null) {
//                        listAdapter.notifyDataSetChanged();
//                    }
//                    if (searchListViewAdapter != null) {
//                        searchListViewAdapter.notifyDataSetChanged();
//                    }
//                }
//            });
//            builder.setNegativeButton(LocaleController.getString("Cancel", R.string.Cancel), null);
//            AlertDialog alertDialog = builder.create();
//            showDialog(alertDialog);
//            TextView button = (TextView) alertDialog.getButton(DialogInterface.BUTTON_POSITIVE);
//            if (button != null) {
//                button.setTextColor(Theme.getColor(Theme.key_dialogTextRed2));
//            }
            return true;
        });

        listView.setOnScrollListener(new RecyclerView.OnScrollListener() {
            @Override
            public void onScrollStateChanged(RecyclerView recyclerView, int newState) {
                if (newState == RecyclerView.SCROLL_STATE_DRAGGING) {
                    AndroidUtilities.hideKeyboard(getParentActivity().getCurrentFocus());
                }
            }
        });

        return fragmentView;
    }

    private void fillConnectServerInfo() {
        listServerInfo = new ArrayList<>();
        listServerInfo.add(new LocaleController.ConnectServerInfo("开发", "develop", "10.191.73.183", "10.191.73.183"));
        listServerInfo.add(new LocaleController.ConnectServerInfo("测试", "test", "10.191.80.198", "10.191.80.198"));
        listServerInfo.add(new LocaleController.ConnectServerInfo("线上", "release", "aim.dobest.com", "180.101.193.205"));
        for (int i=0; i < listServerInfo.size(); ++i) {
            LocaleController.ConnectServerInfo serverInfo = listServerInfo.get(i);
           if (serverInfo.IsCurrentServerInfo()) {
               currentServerInfo = serverInfo;
           }
        }
    }

    @Override
    public void onResume() {
        super.onResume();
        if (listAdapter != null) {
            listAdapter.notifyDataSetChanged();
        }
    }

    private class ListAdapter extends RecyclerListView.SelectionAdapter {

        private Context mContext;

        public ListAdapter(Context context) {
            mContext = context;
        }

        @Override
        public boolean isEnabled(RecyclerView.ViewHolder holder) {
            return holder.getItemViewType() == 0;
        }

        @Override
        public int getItemCount() {
                int count = listServerInfo.size();
                if (count != 0) {
                    count++;
                }
                return count;
        }

        @Override
        public RecyclerView.ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
            View view;
            switch (viewType) {
                case 0: {
                    view = new ConnectServerCell(mContext, false);
                    view.setBackgroundColor(Theme.getColor(Theme.key_windowBackgroundWhite));
                    break;
                }
                case 1:
                default: {
                    view = new ShadowSectionCell(mContext);
                    break;
                }
            }
            return new RecyclerListView.Holder(view);
        }

        @Override
        public void onBindViewHolder(RecyclerView.ViewHolder holder, int position) {
            switch (holder.getItemViewType()) {
                case 0: {
                    ConnectServerCell textSettingsCell = (ConnectServerCell) holder.itemView;
                    LocaleController.ConnectServerInfo serverInfo = listServerInfo.get(position);
                    boolean last = position == listServerInfo.size() - 1;
                    textSettingsCell.setServerInfo(serverInfo, String.format("%1$s (%2$s)", serverInfo.name, serverInfo.hostName), !last);
                    textSettingsCell.setSelected(currentServerInfo == null ? false : currentServerInfo.hostName.equals(serverInfo.hostName));
                    break;
                }
                case 1: {
                    ShadowSectionCell sectionCell = (ShadowSectionCell) holder.itemView;
                    sectionCell.setBackgroundDrawable(Theme.getThemedDrawable(mContext, R.drawable.greydivider_bottom, Theme.key_windowBackgroundGrayShadow));
                    break;
                }
            }
        }

        @Override
        public int getItemViewType(int i) {
            if (i == listServerInfo.size()) {
                return 1;
            }
            return 0;
        }
    }

    @Override
    public ArrayList<ThemeDescription> getThemeDescriptions() {
        ArrayList<ThemeDescription> themeDescriptions = new ArrayList<>();

        themeDescriptions.add(new ThemeDescription(listView, ThemeDescription.FLAG_CELLBACKGROUNDCOLOR, new Class[]{ConnectServerCell.class}, null, null, null, Theme.key_windowBackgroundWhite));
        themeDescriptions.add(new ThemeDescription(fragmentView, ThemeDescription.FLAG_BACKGROUND, null, null, null, null, Theme.key_windowBackgroundGray));

        themeDescriptions.add(new ThemeDescription(actionBar, ThemeDescription.FLAG_BACKGROUND, null, null, null, null, Theme.key_actionBarDefault));
        themeDescriptions.add(new ThemeDescription(listView, ThemeDescription.FLAG_LISTGLOWCOLOR, null, null, null, null, Theme.key_actionBarDefault));
        themeDescriptions.add(new ThemeDescription(actionBar, ThemeDescription.FLAG_AB_ITEMSCOLOR, null, null, null, null, Theme.key_actionBarDefaultIcon));
        themeDescriptions.add(new ThemeDescription(actionBar, ThemeDescription.FLAG_AB_TITLECOLOR, null, null, null, null, Theme.key_actionBarDefaultTitle));
        themeDescriptions.add(new ThemeDescription(actionBar, ThemeDescription.FLAG_AB_SELECTORCOLOR, null, null, null, null, Theme.key_actionBarDefaultSelector));
        themeDescriptions.add(new ThemeDescription(actionBar, ThemeDescription.FLAG_AB_SEARCH, null, null, null, null, Theme.key_actionBarDefaultSearch));
        themeDescriptions.add(new ThemeDescription(actionBar, ThemeDescription.FLAG_AB_SEARCHPLACEHOLDER, null, null, null, null, Theme.key_actionBarDefaultSearchPlaceholder));

        themeDescriptions.add(new ThemeDescription(listView, ThemeDescription.FLAG_SELECTOR, null, null, null, null, Theme.key_listSelector));

        themeDescriptions.add(new ThemeDescription(emptyView, ThemeDescription.FLAG_TEXTCOLOR, null, null, null, null, Theme.key_emptyListPlaceholder));

        themeDescriptions.add(new ThemeDescription(listView, 0, new Class[]{View.class}, Theme.dividerPaint, null, null, Theme.key_divider));

        themeDescriptions.add(new ThemeDescription(listView, ThemeDescription.FLAG_BACKGROUNDFILTER, new Class[]{ShadowSectionCell.class}, null, null, null, Theme.key_windowBackgroundGrayShadow));

        themeDescriptions.add(new ThemeDescription(listView, 0, new Class[]{ConnectServerCell.class}, new String[]{"textView"}, null, null, null, Theme.key_windowBackgroundWhiteBlackText));
        themeDescriptions.add(new ThemeDescription(listView, 0, new Class[]{ConnectServerCell.class}, new String[]{"textView2"}, null, null, null, Theme.key_windowBackgroundWhiteGrayText3));
        themeDescriptions.add(new ThemeDescription(listView, 0, new Class[]{ConnectServerCell.class}, new String[]{"checkImage"}, null, null, null, Theme.key_featuredStickers_addedIcon));

        return themeDescriptions;
    }
}

/**
public class SwitchServerActivity2 extends Activity {
    private SwitchServerBean currentServerBean;
    private String currentHostName;

    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        LinearLayout linearLayout = new LinearLayout((Context) this);
        linearLayout.setBackgroundColor(Theme.getColor(Theme.key_windowBackgroundWhite));
        linearLayout.setOrientation(LinearLayout.VERTICAL);
        float padding = (float) AndroidUtilities.dp(15.0F);
        currentHostName = ConnectionsManager.getInstance(UserConfig.selectedAccount).getHostName();
        linearLayout.addView((View) this.goBack(), (LayoutParams) LayoutHelper.createFrame(LayoutHelper.WRAP_CONTENT, 56.0F));
        linearLayout.addView((View) this.groupServer(), (LayoutParams) LayoutHelper.createLinear(LayoutHelper.MATCH_PARENT, 0, 1.0F));
        linearLayout.addView((View) this.confirmSwitch(), (LayoutParams) LayoutHelper.createLinear(LayoutHelper.MATCH_PARENT, 56, padding / (float) 2, padding, padding / (float) 2, padding));
        this.setContentView((View) linearLayout);
    }

    private final ImageView goBack() {
        ImageButton ibBack = new ImageButton((Context) this);
        ibBack.setScaleType(ScaleType.FIT_CENTER);
        ibBack.setImageResource(R.drawable.ic_ab_back);
        ibBack.setBackground((Drawable) null);
        ibBack.setOnClickListener(view -> {
            finish();
        });
        return (ImageView) ibBack;
    }

    private final RadioGroup groupServer() {
        RadioGroup radioGroup = new RadioGroup((Context) this);
        android.widget.LinearLayout.LayoutParams layoutParams = new android.widget.LinearLayout.LayoutParams(-1, 48);
        List serverBeans = this.getServerBeans();
        for (int i = 0; i < serverBeans.size(); ++i) {
            SwitchServerBean serverBean = (SwitchServerBean) serverBeans.get(i);
            RadioButton radioButton = new RadioButton((Context) this);
            radioButton.setLayoutParams((LayoutParams) layoutParams);
            radioButton.setTextSize(TypedValue.COMPLEX_UNIT_DIP, 18f);
            radioButton.setTextColor(Theme.getColor(Theme.key_dialogTextBlack));
            radioButton.setBackgroundColor(Theme.getColor(Theme.key_dialogRadioBackground));
            radioButton.setGravity(Gravity.CENTER_VERTICAL);
            radioButton.setText((CharSequence) (serverBean.alias + '(' + serverBean.hostName + ')'));
            radioButton.setId(i);
            boolean checked = serverBean.hostName.equals(this.currentHostName);
            if (checked) {
                currentServerBean = serverBean;
            }
            radioButton.setChecked(checked);
            radioGroup.addView((View) radioButton, (LayoutParams) LayoutHelper.createLinear(-1, 56));
        }

        radioGroup.setOnCheckedChangeListener((v, i) -> {
            if (serverBeans != null) {
                ((RadioButton) v.getChildAt(i)).setChecked(true);
                currentServerBean = (SwitchServerBean) serverBeans.get(i);
            }
        });
        return radioGroup;
    }

    private final Button confirmSwitch() {
        Button button = new Button((Context) this);
        button.setText(LocaleController.getString("Settings", R.string.Settings));
        // button.setBackground(Theme.createLoginStyleButton());
        button.setBackgroundDrawable(Theme.createSimpleSelectorRoundRectDrawable(AndroidUtilities.dp(4), 0xff50a8eb, 0xff439bde));
        button.setTextColor(0xffffffff);
        button.setOnClickListener(v -> {
             if (currentServerBean != null && currentHostName != currentServerBean.hostName) {
                 ConnectionsManager.getInstance(UserConfig.selectedAccount).switchConnectServer(currentServerBean.hostName, currentServerBean.hostAddress);
            }
            finish();
        });
        return button;
    }

    public final List getServerBeans() {
        List serverBeans = (List) (new ArrayList());
        serverBeans.add(new SwitchServerBean("develop", "开发", "10.191.73.183", "10.191.73.183"));
        serverBeans.add(new SwitchServerBean("test", "测试", "10.191.80.198", "10.191.80.198"));
        serverBeans.add(new SwitchServerBean("release", "线上", "aim.dobest.com", "180.101.193.205"));
        return serverBeans;
    }
}
*/


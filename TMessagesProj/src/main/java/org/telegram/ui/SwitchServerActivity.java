package org.telegram.ui;

import android.app.Activity;
import android.content.Context;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.view.View;
import android.util.TypedValue;
import android.view.Gravity;
import android.view.ViewGroup.LayoutParams;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.ImageView.ScaleType;
import androidx.annotation.Nullable;
import java.util.ArrayList;
import java.util.List;
import org.telegram.messenger.AndroidUtilities;
import org.telegram.messenger.LocaleController;
import org.telegram.messenger.R;
import org.telegram.messenger.UserConfig;
import org.telegram.tgnet.ConnectionsManager;
import org.telegram.ui.ActionBar.Theme;
import org.telegram.ui.Components.LayoutHelper;

public class SwitchServerActivity extends Activity {
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


// WARNING! All changes made in this file will be lost!
// Created from 'mtproto.tl', 'api.tl' by 'generate.py'
//
#pragma once

#include "types.h"
#include "core_types.h"
#include "assertion.h"
#include "flags.h"

// Layer is 132

// Type id constants
enum {
	mtpc_resPQ = 0x5162463,
	mtpc_p_q_inner_data = 0x83c95aec,
	mtpc_p_q_inner_data_dc = 0xa9f55f95,
	mtpc_p_q_inner_data_temp = 0x3c6a84d4,
	mtpc_p_q_inner_data_temp_dc = 0x56fddf88,
	mtpc_bind_auth_key_inner = 0x75a3f765,
	mtpc_server_DH_params_fail = 0x79cb045d,
	mtpc_server_DH_params_ok = 0xd0e8075c,
	mtpc_server_DH_inner_data = 0xb5890dba,
	mtpc_client_DH_inner_data = 0x6643b654,
	mtpc_dh_gen_ok = 0x3bcbf734,
	mtpc_dh_gen_retry = 0x46dc1fb9,
	mtpc_dh_gen_fail = 0xa69dae02,
	mtpc_destroy_auth_key_ok = 0xf660e1d4,
	mtpc_destroy_auth_key_none = 0xa9f2259,
	mtpc_destroy_auth_key_fail = 0xea109b13,
	mtpc_req_pq = 0x60469778,
	mtpc_req_pq_multi = 0xbe7e8ef1,
	mtpc_req_DH_params = 0xd712e4be,
	mtpc_set_client_DH_params = 0xf5045f1f,
	mtpc_destroy_auth_key = 0xd1435160,
	mtpc_msgs_ack = 0x62d6b459,
	mtpc_bad_msg_notification = 0xa7eff811,
	mtpc_bad_server_salt = 0xedab447b,
	mtpc_msgs_state_req = 0xda69fb52,
	mtpc_msgs_state_info = 0x4deb57d,
	mtpc_msgs_all_info = 0x8cc0d131,
	mtpc_msg_detailed_info = 0x276d3ec6,
	mtpc_msg_new_detailed_info = 0x809db6df,
	mtpc_msg_resend_req = 0x7d861a08,
	mtpc_rpc_error = 0x2144ca19,
	mtpc_rpc_answer_unknown = 0x5e2ad36e,
	mtpc_rpc_answer_dropped_running = 0xcd78e586,
	mtpc_rpc_answer_dropped = 0xa43ad8b7,
	mtpc_future_salt = 0x949d9dc,
	mtpc_future_salts = 0xae500895,
	mtpc_pong = 0x347773c5,
	mtpc_destroy_session_ok = 0xe22045fc,
	mtpc_destroy_session_none = 0x62d350c9,
	mtpc_new_session_created = 0x9ec20908,
	mtpc_http_wait = 0x9299359f,
	mtpc_ipPort = 0xd433ad73,
	mtpc_ipPortSecret = 0x37982646,
	mtpc_accessPointRule = 0x4679b65f,
	mtpc_help_configSimple = 0x5a592a6c,
	mtpc_tlsClientHello = 0x6c52c484,
	mtpc_tlsBlockString = 0x4218a164,
	mtpc_tlsBlockRandom = 0x4d4dc41e,
	mtpc_tlsBlockZero = 0x9333afb,
	mtpc_tlsBlockDomain = 0x10e8636f,
	mtpc_tlsBlockGrease = 0xe675a1c1,
	mtpc_tlsBlockPublicKey = 0x9eb95b5c,
	mtpc_tlsBlockScope = 0xe725d44f,
	mtpc_rpc_drop_answer = 0x58e4a740,
	mtpc_get_future_salts = 0xb921bd04,
	mtpc_ping = 0x7abe77ec,
	mtpc_ping_delay_disconnect = 0xf3427b8c,
	mtpc_destroy_session = 0xe7512126,
	mtpc_boolFalse = 0xbc799737,
	mtpc_boolTrue = 0x997275b5,
	mtpc_true = 0x3fedd339,
	mtpc_error = 0xc4b9f9bb,
	mtpc_null = 0x56730bcc,
	mtpc_inputPeerEmpty = 0x7f3b18ea,
	mtpc_inputPeerSelf = 0x7da07ec9,
	mtpc_inputPeerChat = 0x179be863,
	mtpc_inputPeerUser = 0x7b8e7de6,
	mtpc_inputPeerChannel = 0x20adaef8,
	mtpc_inputPeerUserFromMessage = 0x17bae2e6,
	mtpc_inputPeerChannelFromMessage = 0x9c95f7bb,
	mtpc_inputUserEmpty = 0xb98886cf,
	mtpc_inputUserSelf = 0xf7c1b13f,
	mtpc_inputUser = 0xd8292816,
	mtpc_inputUserFromMessage = 0x2d117597,
	mtpc_inputPhoneContact = 0xf392b7f4,
	mtpc_inputFile = 0xf52ff27f,
	mtpc_inputFileBig = 0xfa4f0bb5,
	mtpc_inputMediaEmpty = 0x9664f57f,
	mtpc_inputMediaUploadedPhoto = 0x1e287d04,
	mtpc_inputMediaPhoto = 0xb3ba0635,
	mtpc_inputMediaGeoPoint = 0xf9c44144,
	mtpc_inputMediaContact = 0xf8ab7dfb,
	mtpc_inputMediaUploadedDocument = 0x5b38c6c1,
	mtpc_inputMediaDocument = 0x33473058,
	mtpc_inputMediaVenue = 0xc13d1c11,
	mtpc_inputMediaPhotoExternal = 0xe5bbfe1a,
	mtpc_inputMediaDocumentExternal = 0xfb52dc99,
	mtpc_inputMediaGame = 0xd33f43f3,
	mtpc_inputMediaInvoice = 0xd9799874,
	mtpc_inputMediaGeoLive = 0x971fa843,
	mtpc_inputMediaPoll = 0xf94e5f1,
	mtpc_inputMediaDice = 0xe66fbf7b,
	mtpc_inputChatPhotoEmpty = 0x1ca48f57,
	mtpc_inputChatUploadedPhoto = 0xc642724e,
	mtpc_inputChatPhoto = 0x8953ad37,
	mtpc_inputGeoPointEmpty = 0xe4c123d6,
	mtpc_inputGeoPoint = 0x48222faf,
	mtpc_inputPhotoEmpty = 0x1cd7bf0d,
	mtpc_inputPhoto = 0x3bb3b94a,
	mtpc_inputFileLocation = 0xdfdaabe1,
	mtpc_inputEncryptedFileLocation = 0xf5235d55,
	mtpc_inputDocumentFileLocation = 0xbad07584,
	mtpc_inputSecureFileLocation = 0xcbc7ee28,
	mtpc_inputTakeoutFileLocation = 0x29be5899,
	mtpc_inputPhotoFileLocation = 0x40181ffe,
	mtpc_inputPhotoLegacyFileLocation = 0xd83466f3,
	mtpc_inputPeerPhotoFileLocation = 0x37257e99,
	mtpc_inputStickerSetThumb = 0x9d84f3db,
	mtpc_inputGroupCallStream = 0x598a92a,
	mtpc_peerUser = 0x9db1bc6d,
	mtpc_peerChat = 0xbad0e5bb,
	mtpc_peerChannel = 0xbddde532,
	mtpc_storage_fileUnknown = 0xaa963b05,
	mtpc_storage_filePartial = 0x40bc6f52,
	mtpc_storage_fileJpeg = 0x7efe0e,
	mtpc_storage_fileGif = 0xcae1aadf,
	mtpc_storage_filePng = 0xa4f63c0,
	mtpc_storage_filePdf = 0xae1e508d,
	mtpc_storage_fileMp3 = 0x528a0677,
	mtpc_storage_fileMov = 0x4b09ebbc,
	mtpc_storage_fileMp4 = 0xb3cea0e4,
	mtpc_storage_fileWebp = 0x1081464c,
	mtpc_userEmpty = 0x200250ba,
	mtpc_user = 0x938458c1,
	mtpc_userProfilePhotoEmpty = 0x4f11bae1,
	mtpc_userProfilePhoto = 0x82d1f706,
	mtpc_userStatusEmpty = 0x9d05049,
	mtpc_userStatusOnline = 0xedb93949,
	mtpc_userStatusOffline = 0x8c703f,
	mtpc_userStatusRecently = 0xe26f42f1,
	mtpc_userStatusLastWeek = 0x7bf09fc,
	mtpc_userStatusLastMonth = 0x77ebc742,
	mtpc_chatEmpty = 0x9ba2d800,
	mtpc_chat = 0x3bda1bde,
	mtpc_chatForbidden = 0x7328bdb,
	mtpc_channel = 0xd31a961e,
	mtpc_channelForbidden = 0x289da732,
	mtpc_chatFull = 0x49a0a5d9,
	mtpc_channelFull = 0x2f532f3c,
	mtpc_chatParticipant = 0xc8d7493e,
	mtpc_chatParticipantCreator = 0xda13538a,
	mtpc_chatParticipantAdmin = 0xe2d6e436,
	mtpc_chatParticipantsForbidden = 0xfc900c2b,
	mtpc_chatParticipants = 0x3f460fed,
	mtpc_chatPhotoEmpty = 0x37c1011c,
	mtpc_chatPhoto = 0x1c6e1c11,
	mtpc_messageEmpty = 0x90a6ca84,
	mtpc_message = 0xbce383d2,
	mtpc_messageService = 0x2b085862,
	mtpc_messageMediaEmpty = 0x3ded6320,
	mtpc_messageMediaPhoto = 0x695150d7,
	mtpc_messageMediaGeo = 0x56e0d474,
	mtpc_messageMediaContact = 0xcbf24940,
	mtpc_messageMediaUnsupported = 0x9f84f49e,
	mtpc_messageMediaDocument = 0x9cb070d7,
	mtpc_messageMediaWebPage = 0xa32dd600,
	mtpc_messageMediaVenue = 0x2ec0533f,
	mtpc_messageMediaGame = 0xfdb19008,
	mtpc_messageMediaInvoice = 0x84551347,
	mtpc_messageMediaGeoLive = 0xb940c666,
	mtpc_messageMediaPoll = 0x4bd6e798,
	mtpc_messageMediaDice = 0x3f7ee58b,
	mtpc_messageActionEmpty = 0xb6aef7b0,
	mtpc_messageActionChatCreate = 0xa6638b9a,
	mtpc_messageActionChatEditTitle = 0xb5a1ce5a,
	mtpc_messageActionChatEditPhoto = 0x7fcb13a8,
	mtpc_messageActionChatDeletePhoto = 0x95e3fbef,
	mtpc_messageActionChatAddUser = 0x488a7337,
	mtpc_messageActionChatDeleteUser = 0xb2ae9b0c,
	mtpc_messageActionChatJoinedByLink = 0xf89cf5e8,
	mtpc_messageActionChannelCreate = 0x95d2ac92,
	mtpc_messageActionChatMigrateTo = 0x51bdb021,
	mtpc_messageActionChannelMigrateFrom = 0xb055eaee,
	mtpc_messageActionPinMessage = 0x94bd38ed,
	mtpc_messageActionHistoryClear = 0x9fbab604,
	mtpc_messageActionGameScore = 0x92a72876,
	mtpc_messageActionPaymentSentMe = 0x8f31b327,
	mtpc_messageActionPaymentSent = 0x40699cd0,
	mtpc_messageActionPhoneCall = 0x80e11a7f,
	mtpc_messageActionScreenshotTaken = 0x4792929b,
	mtpc_messageActionCustomAction = 0xfae69f56,
	mtpc_messageActionBotAllowed = 0xabe9affe,
	mtpc_messageActionSecureValuesSentMe = 0x1b287353,
	mtpc_messageActionSecureValuesSent = 0xd95c6154,
	mtpc_messageActionContactSignUp = 0xf3f25f76,
	mtpc_messageActionGeoProximityReached = 0x98e0d697,
	mtpc_messageActionGroupCall = 0x7a0d7f42,
	mtpc_messageActionInviteToGroupCall = 0x76b9f11a,
	mtpc_messageActionSetMessagesTTL = 0xaa1afbfd,
	mtpc_messageActionGroupCallScheduled = 0xb3a07661,
	mtpc_messageActionSetChatTheme = 0xaa786345,
	mtpc_dialog = 0x2c171f72,
	mtpc_dialogFolder = 0x71bd134c,
	mtpc_photoEmpty = 0x2331b22d,
	mtpc_photo = 0xfb197a65,
	mtpc_photoSizeEmpty = 0xe17e23c,
	mtpc_photoSize = 0x75c78e60,
	mtpc_photoCachedSize = 0x21e1ad6,
	mtpc_photoStrippedSize = 0xe0b0bc2e,
	mtpc_photoSizeProgressive = 0xfa3efb95,
	mtpc_photoPathSize = 0xd8214d41,
	mtpc_geoPointEmpty = 0x1117dd5f,
	mtpc_geoPoint = 0xb2a2f663,
	mtpc_auth_sentCode = 0x5e002502,
	mtpc_auth_authorization = 0xcd050916,
	mtpc_auth_authorizationSignUpRequired = 0x44747e9a,
	mtpc_auth_exportedAuthorization = 0xdf969c2d,
	mtpc_inputNotifyPeer = 0xb8bc5b0c,
	mtpc_inputNotifyUsers = 0x193b4417,
	mtpc_inputNotifyChats = 0x4a95e84e,
	mtpc_inputNotifyBroadcasts = 0xb1db7c7e,
	mtpc_inputPeerNotifySettings = 0x9c3d198e,
	mtpc_peerNotifySettings = 0xaf509d20,
	mtpc_peerSettings = 0x733f2961,
	mtpc_wallPaper = 0xa437c3ed,
	mtpc_wallPaperNoFile = 0xe0804116,
	mtpc_inputReportReasonSpam = 0x58dbcab8,
	mtpc_inputReportReasonViolence = 0x1e22c78d,
	mtpc_inputReportReasonPornography = 0x2e59d922,
	mtpc_inputReportReasonChildAbuse = 0xadf44ee3,
	mtpc_inputReportReasonOther = 0xc1e4a2b1,
	mtpc_inputReportReasonCopyright = 0x9b89f93a,
	mtpc_inputReportReasonGeoIrrelevant = 0xdbd4feed,
	mtpc_inputReportReasonFake = 0xf5ddd6e7,
	mtpc_userFull = 0xd697ff05,
	mtpc_contact = 0xf911c994,
	mtpc_importedContact = 0xd0028438,
	mtpc_contactStatus = 0xd3680c61,
	mtpc_contacts_contactsNotModified = 0xb74ba9d2,
	mtpc_contacts_contacts = 0xeae87e42,
	mtpc_contacts_importedContacts = 0x77d01c3b,
	mtpc_contacts_blocked = 0xade1591,
	mtpc_contacts_blockedSlice = 0xe1664194,
	mtpc_messages_dialogs = 0x15ba6c40,
	mtpc_messages_dialogsSlice = 0x71e094f3,
	mtpc_messages_dialogsNotModified = 0xf0e3e596,
	mtpc_messages_messages = 0x8c718e87,
	mtpc_messages_messagesSlice = 0x3a54685e,
	mtpc_messages_channelMessages = 0x64479808,
	mtpc_messages_messagesNotModified = 0x74535f21,
	mtpc_messages_chats = 0x64ff9fd5,
	mtpc_messages_chatsSlice = 0x9cd81144,
	mtpc_messages_chatFull = 0xe5d7d19c,
	mtpc_messages_affectedHistory = 0xb45c69d1,
	mtpc_inputMessagesFilterEmpty = 0x57e2f66c,
	mtpc_inputMessagesFilterPhotos = 0x9609a51c,
	mtpc_inputMessagesFilterVideo = 0x9fc00e65,
	mtpc_inputMessagesFilterPhotoVideo = 0x56e9f0e4,
	mtpc_inputMessagesFilterDocument = 0x9eddf188,
	mtpc_inputMessagesFilterUrl = 0x7ef0dd87,
	mtpc_inputMessagesFilterGif = 0xffc86587,
	mtpc_inputMessagesFilterVoice = 0x50f5c392,
	mtpc_inputMessagesFilterMusic = 0x3751b49e,
	mtpc_inputMessagesFilterChatPhotos = 0x3a20ecb8,
	mtpc_inputMessagesFilterPhoneCalls = 0x80c99768,
	mtpc_inputMessagesFilterRoundVoice = 0x7a7c17a4,
	mtpc_inputMessagesFilterRoundVideo = 0xb549da53,
	mtpc_inputMessagesFilterMyMentions = 0xc1f8e69a,
	mtpc_inputMessagesFilterGeo = 0xe7026d0d,
	mtpc_inputMessagesFilterContacts = 0xe062db83,
	mtpc_inputMessagesFilterPinned = 0x1bb00451,
	mtpc_updateNewMessage = 0x1f2b0afd,
	mtpc_updateMessageID = 0x4e90bfd6,
	mtpc_updateDeleteMessages = 0xa20db0e5,
	mtpc_updateUserTyping = 0x5c486927,
	mtpc_updateChatUserTyping = 0x86cadb6c,
	mtpc_updateChatParticipants = 0x7761198,
	mtpc_updateUserStatus = 0x1bfbd823,
	mtpc_updateUserName = 0xa7332b73,
	mtpc_updateUserPhoto = 0x95313b0c,
	mtpc_updateNewEncryptedMessage = 0x12bcbd9a,
	mtpc_updateEncryptedChatTyping = 0x1710f156,
	mtpc_updateEncryption = 0xb4a2e88d,
	mtpc_updateEncryptedMessagesRead = 0x38fe25b7,
	mtpc_updateChatParticipantAdd = 0xea4b0e5c,
	mtpc_updateChatParticipantDelete = 0x6e5f8c22,
	mtpc_updateDcOptions = 0x8e5e9873,
	mtpc_updateNotifySettings = 0xbec268ef,
	mtpc_updateServiceNotification = 0xebe46819,
	mtpc_updatePrivacy = 0xee3b272a,
	mtpc_updateUserPhone = 0x12b9417b,
	mtpc_updateReadHistoryInbox = 0x9c974fdf,
	mtpc_updateReadHistoryOutbox = 0x2f2f21bf,
	mtpc_updateWebPage = 0x7f891213,
	mtpc_updateReadMessagesContents = 0x68c13933,
	mtpc_updateChannelTooLong = 0xeb0467fb,
	mtpc_updateChannel = 0xb6d45656,
	mtpc_updateNewChannelMessage = 0x62ba04d9,
	mtpc_updateReadChannelInbox = 0x330b5424,
	mtpc_updateDeleteChannelMessages = 0xc37521c9,
	mtpc_updateChannelMessageViews = 0x98a12b4b,
	mtpc_updateChatParticipantAdmin = 0xb6901959,
	mtpc_updateNewStickerSet = 0x688a30aa,
	mtpc_updateStickerSetsOrder = 0xbb2d201,
	mtpc_updateStickerSets = 0x43ae3dec,
	mtpc_updateSavedGifs = 0x9375341e,
	mtpc_updateBotInlineQuery = 0x3f2038db,
	mtpc_updateBotInlineSend = 0xe48f964,
	mtpc_updateEditChannelMessage = 0x1b3f4df7,
	mtpc_updateBotCallbackQuery = 0xe73547e1,
	mtpc_updateEditMessage = 0xe40370a3,
	mtpc_updateInlineBotCallbackQuery = 0xf9d27a5a,
	mtpc_updateReadChannelOutbox = 0x25d6c9c7,
	mtpc_updateDraftMessage = 0xee2bb969,
	mtpc_updateReadFeaturedStickers = 0x571d2742,
	mtpc_updateRecentStickers = 0x9a422c20,
	mtpc_updateConfig = 0xa229dd06,
	mtpc_updatePtsChanged = 0x3354678f,
	mtpc_updateChannelWebPage = 0x40771900,
	mtpc_updateDialogPinned = 0x6e6fe51c,
	mtpc_updatePinnedDialogs = 0xfa0f3ca2,
	mtpc_updateBotWebhookJSON = 0x8317c0c3,
	mtpc_updateBotWebhookJSONQuery = 0x9b9240a6,
	mtpc_updateBotShippingQuery = 0xe0cdc940,
	mtpc_updateBotPrecheckoutQuery = 0x5d2f3aa9,
	mtpc_updatePhoneCall = 0xab0f6b1e,
	mtpc_updateLangPackTooLong = 0x46560264,
	mtpc_updateLangPack = 0x56022f4d,
	mtpc_updateFavedStickers = 0xe511996d,
	mtpc_updateChannelReadMessagesContents = 0x89893b45,
	mtpc_updateContactsReset = 0x7084a7be,
	mtpc_updateChannelAvailableMessages = 0x70db6837,
	mtpc_updateDialogUnreadMark = 0xe16459c3,
	mtpc_updateMessagePoll = 0xaca1657b,
	mtpc_updateChatDefaultBannedRights = 0x54c01850,
	mtpc_updateFolderPeers = 0x19360dc0,
	mtpc_updatePeerSettings = 0x6a7e7366,
	mtpc_updatePeerLocated = 0xb4afcfb0,
	mtpc_updateNewScheduledMessage = 0x39a51dfb,
	mtpc_updateDeleteScheduledMessages = 0x90866cee,
	mtpc_updateTheme = 0x8216fba3,
	mtpc_updateGeoLiveViewed = 0x871fb939,
	mtpc_updateLoginToken = 0x564fe691,
	mtpc_updateMessagePollVote = 0x37f69f0b,
	mtpc_updateDialogFilter = 0x26ffde7d,
	mtpc_updateDialogFilterOrder = 0xa5d72105,
	mtpc_updateDialogFilters = 0x3504914f,
	mtpc_updatePhoneCallSignalingData = 0x2661bf09,
	mtpc_updateChannelMessageForwards = 0x6e8a84df,
	mtpc_updateReadChannelDiscussionInbox = 0x1cc7de54,
	mtpc_updateReadChannelDiscussionOutbox = 0x4638a26c,
	mtpc_updatePeerBlocked = 0x246a4b22,
	mtpc_updateChannelUserTyping = 0x6b171718,
	mtpc_updatePinnedMessages = 0xed85eab5,
	mtpc_updatePinnedChannelMessages = 0x8588878b,
	mtpc_updateChat = 0x1330a196,
	mtpc_updateGroupCallParticipants = 0xf2ebdb4e,
	mtpc_updateGroupCall = 0xa45eb99b,
	mtpc_updatePeerHistoryTTL = 0xbb9bb9a5,
	mtpc_updateChatParticipant = 0xf3b3781f,
	mtpc_updateChannelParticipant = 0x7fecb1ec,
	mtpc_updateBotStopped = 0x7f9488a,
	mtpc_updateGroupCallConnection = 0xb783982,
	mtpc_updateBotCommands = 0xcf7e0873,
	mtpc_updates_state = 0xa56c2a3e,
	mtpc_updates_differenceEmpty = 0x5d75a138,
	mtpc_updates_difference = 0xf49ca0,
	mtpc_updates_differenceSlice = 0xa8fb1981,
	mtpc_updates_differenceTooLong = 0x4afe8f6d,
	mtpc_updatesTooLong = 0xe317af7e,
	mtpc_updateShortMessage = 0xfaeff833,
	mtpc_updateShortChatMessage = 0x1157b858,
	mtpc_updateShort = 0x78d4dec1,
	mtpc_updatesCombined = 0x725b04c3,
	mtpc_updates = 0x74ae4240,
	mtpc_updateShortSentMessage = 0x9015e101,
	mtpc_photos_photos = 0x8dca6aa5,
	mtpc_photos_photosSlice = 0x15051f54,
	mtpc_photos_photo = 0x20212ca8,
	mtpc_upload_file = 0x96a18d5,
	mtpc_upload_fileCdnRedirect = 0xf18cda44,
	mtpc_dcOption = 0x18b7a10d,
	mtpc_config = 0x330b4067,
	mtpc_nearestDc = 0x8e1a1775,
	mtpc_help_appUpdate = 0xccbbce30,
	mtpc_help_noAppUpdate = 0xc45a6536,
	mtpc_help_inviteText = 0x18cb9f78,
	mtpc_encryptedChatEmpty = 0xab7ec0a0,
	mtpc_encryptedChatWaiting = 0x3bf703dc,
	mtpc_encryptedChatRequested = 0x62718a82,
	mtpc_encryptedChat = 0xfa56ce36,
	mtpc_encryptedChatDiscarded = 0x1e1c7c45,
	mtpc_inputEncryptedChat = 0xf141b5e1,
	mtpc_encryptedFileEmpty = 0xc21f497e,
	mtpc_encryptedFile = 0x4a70994c,
	mtpc_inputEncryptedFileEmpty = 0x1837c364,
	mtpc_inputEncryptedFileUploaded = 0x64bd0306,
	mtpc_inputEncryptedFile = 0x5a17b5e5,
	mtpc_inputEncryptedFileBigUploaded = 0x2dc173c8,
	mtpc_encryptedMessage = 0xed18c118,
	mtpc_encryptedMessageService = 0x23734b06,
	mtpc_messages_dhConfigNotModified = 0xc0e24635,
	mtpc_messages_dhConfig = 0x2c221edd,
	mtpc_messages_sentEncryptedMessage = 0x560f8935,
	mtpc_messages_sentEncryptedFile = 0x9493ff32,
	mtpc_inputDocumentEmpty = 0x72f0eaae,
	mtpc_inputDocument = 0x1abfb575,
	mtpc_documentEmpty = 0x36f8c871,
	mtpc_document = 0x1e87342b,
	mtpc_help_support = 0x17c6b5f6,
	mtpc_notifyPeer = 0x9fd40bd8,
	mtpc_notifyUsers = 0xb4c83b4c,
	mtpc_notifyChats = 0xc007cec3,
	mtpc_notifyBroadcasts = 0xd612e8ef,
	mtpc_sendMessageTypingAction = 0x16bf744e,
	mtpc_sendMessageCancelAction = 0xfd5ec8f5,
	mtpc_sendMessageRecordVideoAction = 0xa187d66f,
	mtpc_sendMessageUploadVideoAction = 0xe9763aec,
	mtpc_sendMessageRecordAudioAction = 0xd52f73f7,
	mtpc_sendMessageUploadAudioAction = 0xf351d7ab,
	mtpc_sendMessageUploadPhotoAction = 0xd1d34a26,
	mtpc_sendMessageUploadDocumentAction = 0xaa0cd9e4,
	mtpc_sendMessageGeoLocationAction = 0x176f8ba1,
	mtpc_sendMessageChooseContactAction = 0x628cbc6f,
	mtpc_sendMessageGamePlayAction = 0xdd6a8f48,
	mtpc_sendMessageRecordRoundAction = 0x88f27fbc,
	mtpc_sendMessageUploadRoundAction = 0x243e1c66,
	mtpc_speakingInGroupCallAction = 0xd92c2285,
	mtpc_sendMessageHistoryImportAction = 0xdbda9246,
	mtpc_sendMessageChooseStickerAction = 0xb05ac6b1,
	mtpc_contacts_found = 0xb3134d9d,
	mtpc_inputPrivacyKeyStatusTimestamp = 0x4f96cb18,
	mtpc_inputPrivacyKeyChatInvite = 0xbdfb0426,
	mtpc_inputPrivacyKeyPhoneCall = 0xfabadc5f,
	mtpc_inputPrivacyKeyPhoneP2P = 0xdb9e70d2,
	mtpc_inputPrivacyKeyForwards = 0xa4dd4c08,
	mtpc_inputPrivacyKeyProfilePhoto = 0x5719bacc,
	mtpc_inputPrivacyKeyPhoneNumber = 0x352dafa,
	mtpc_inputPrivacyKeyAddedByPhone = 0xd1219bdd,
	mtpc_privacyKeyStatusTimestamp = 0xbc2eab30,
	mtpc_privacyKeyChatInvite = 0x500e6dfa,
	mtpc_privacyKeyPhoneCall = 0x3d662b7b,
	mtpc_privacyKeyPhoneP2P = 0x39491cc8,
	mtpc_privacyKeyForwards = 0x69ec56a3,
	mtpc_privacyKeyProfilePhoto = 0x96151fed,
	mtpc_privacyKeyPhoneNumber = 0xd19ae46d,
	mtpc_privacyKeyAddedByPhone = 0x42ffd42b,
	mtpc_inputPrivacyValueAllowContacts = 0xd09e07b,
	mtpc_inputPrivacyValueAllowAll = 0x184b35ce,
	mtpc_inputPrivacyValueAllowUsers = 0x131cc67f,
	mtpc_inputPrivacyValueDisallowContacts = 0xba52007,
	mtpc_inputPrivacyValueDisallowAll = 0xd66b66c9,
	mtpc_inputPrivacyValueDisallowUsers = 0x90110467,
	mtpc_inputPrivacyValueAllowChatParticipants = 0x4c81c1ba,
	mtpc_inputPrivacyValueDisallowChatParticipants = 0xd82363af,
	mtpc_privacyValueAllowContacts = 0xfffe1bac,
	mtpc_privacyValueAllowAll = 0x65427b82,
	mtpc_privacyValueAllowUsers = 0x4d5bbe0c,
	mtpc_privacyValueDisallowContacts = 0xf888fa1a,
	mtpc_privacyValueDisallowAll = 0x8b73e763,
	mtpc_privacyValueDisallowUsers = 0xc7f49b7,
	mtpc_privacyValueAllowChatParticipants = 0x18be796b,
	mtpc_privacyValueDisallowChatParticipants = 0xacae0690,
	mtpc_account_privacyRules = 0x50a04e45,
	mtpc_accountDaysTTL = 0xb8d0afdf,
	mtpc_documentAttributeImageSize = 0x6c37c15c,
	mtpc_documentAttributeAnimated = 0x11b58939,
	mtpc_documentAttributeSticker = 0x6319d612,
	mtpc_documentAttributeVideo = 0xef02ce6,
	mtpc_documentAttributeAudio = 0x9852f9c6,
	mtpc_documentAttributeFilename = 0x15590068,
	mtpc_documentAttributeHasStickers = 0x9801d2f7,
	mtpc_messages_stickersNotModified = 0xf1749a22,
	mtpc_messages_stickers = 0xe4599bbd,
	mtpc_stickerPack = 0x12b299d4,
	mtpc_messages_allStickersNotModified = 0xe86602c3,
	mtpc_messages_allStickers = 0xedfd405f,
	mtpc_messages_affectedMessages = 0x84d19185,
	mtpc_webPageEmpty = 0xeb1477e8,
	mtpc_webPagePending = 0xc586da1c,
	mtpc_webPage = 0xe89c45b2,
	mtpc_webPageNotModified = 0x7311ca11,
	mtpc_authorization = 0xad01d61d,
	mtpc_account_authorizations = 0x1250abde,
	mtpc_account_password = 0x185b184f,
	mtpc_account_passwordSettings = 0x9a5c33e5,
	mtpc_account_passwordInputSettings = 0xc23727c9,
	mtpc_auth_passwordRecovery = 0x137948a5,
	mtpc_receivedNotifyMessage = 0xa384b779,
	mtpc_chatInviteExported = 0x6e24fc9d,
	mtpc_chatInviteAlready = 0x5a686d7c,
	mtpc_chatInvite = 0xdfc2f58e,
	mtpc_chatInvitePeek = 0x61695cb0,
	mtpc_inputStickerSetEmpty = 0xffb62b95,
	mtpc_inputStickerSetID = 0x9de7a269,
	mtpc_inputStickerSetShortName = 0x861cc8a0,
	mtpc_inputStickerSetAnimatedEmoji = 0x28703c8,
	mtpc_inputStickerSetDice = 0xe67f520e,
	mtpc_stickerSet = 0xd7df217a,
	mtpc_messages_stickerSet = 0xb60a24a6,
	mtpc_botCommand = 0xc27ac8c7,
	mtpc_botInfo = 0x98e81d3a,
	mtpc_keyboardButton = 0xa2fa4880,
	mtpc_keyboardButtonUrl = 0x258aff05,
	mtpc_keyboardButtonCallback = 0x35bbdb6b,
	mtpc_keyboardButtonRequestPhone = 0xb16a6c29,
	mtpc_keyboardButtonRequestGeoLocation = 0xfc796b3f,
	mtpc_keyboardButtonSwitchInline = 0x568a748,
	mtpc_keyboardButtonGame = 0x50f41ccf,
	mtpc_keyboardButtonBuy = 0xafd93fbb,
	mtpc_keyboardButtonUrlAuth = 0x10b78d29,
	mtpc_inputKeyboardButtonUrlAuth = 0xd02e7fd4,
	mtpc_keyboardButtonRequestPoll = 0xbbc7515d,
	mtpc_keyboardButtonRow = 0x77608b83,
	mtpc_replyKeyboardHide = 0xa03e5b85,
	mtpc_replyKeyboardForceReply = 0x86b40b08,
	mtpc_replyKeyboardMarkup = 0x85dd99d1,
	mtpc_replyInlineMarkup = 0x48a30254,
	mtpc_messageEntityUnknown = 0xbb92ba95,
	mtpc_messageEntityMention = 0xfa04579d,
	mtpc_messageEntityHashtag = 0x6f635b0d,
	mtpc_messageEntityBotCommand = 0x6cef8ac7,
	mtpc_messageEntityUrl = 0x6ed02538,
	mtpc_messageEntityEmail = 0x64e475c2,
	mtpc_messageEntityBold = 0xbd610bc9,
	mtpc_messageEntityItalic = 0x826f8b60,
	mtpc_messageEntityCode = 0x28a20571,
	mtpc_messageEntityPre = 0x73924be0,
	mtpc_messageEntityTextUrl = 0x76a6d327,
	mtpc_messageEntityMentionName = 0x352dca58,
	mtpc_inputMessageEntityMentionName = 0x208e68c9,
	mtpc_messageEntityPhone = 0x9b69e34b,
	mtpc_messageEntityCashtag = 0x4c4e743f,
	mtpc_messageEntityUnderline = 0x9c4e7e8b,
	mtpc_messageEntityStrike = 0xbf0693d4,
	mtpc_messageEntityBlockquote = 0x20df5d0,
	mtpc_messageEntityBankCard = 0x761e6af4,
	mtpc_inputChannelEmpty = 0xee8c1e86,
	mtpc_inputChannel = 0xafeb712e,
	mtpc_inputChannelFromMessage = 0x2a286531,
	mtpc_contacts_resolvedPeer = 0x7f077ad9,
	mtpc_messageRange = 0xae30253,
	mtpc_updates_channelDifferenceEmpty = 0x3e11affb,
	mtpc_updates_channelDifferenceTooLong = 0xa4bcc6fe,
	mtpc_updates_channelDifference = 0x2064674e,
	mtpc_channelMessagesFilterEmpty = 0x94d42ee7,
	mtpc_channelMessagesFilter = 0xcd77d957,
	mtpc_channelParticipant = 0x15ebac1d,
	mtpc_channelParticipantSelf = 0xa3289a6d,
	mtpc_channelParticipantCreator = 0x447dca4b,
	mtpc_channelParticipantAdmin = 0xccbebbaf,
	mtpc_channelParticipantBanned = 0x50a1dfd6,
	mtpc_channelParticipantLeft = 0x1b03f006,
	mtpc_channelParticipantsRecent = 0xde3f3c79,
	mtpc_channelParticipantsAdmins = 0xb4608969,
	mtpc_channelParticipantsKicked = 0xa3b54985,
	mtpc_channelParticipantsBots = 0xb0d1865b,
	mtpc_channelParticipantsBanned = 0x1427a5e1,
	mtpc_channelParticipantsSearch = 0x656ac4b,
	mtpc_channelParticipantsContacts = 0xbb6ae88d,
	mtpc_channelParticipantsMentions = 0xe04b5ceb,
	mtpc_channels_channelParticipants = 0x9ab0feaf,
	mtpc_channels_channelParticipantsNotModified = 0xf0173fe9,
	mtpc_channels_channelParticipant = 0xdfb80317,
	mtpc_help_termsOfService = 0x780a0310,
	mtpc_messages_savedGifsNotModified = 0xe8025ca2,
	mtpc_messages_savedGifs = 0x2e0709a5,
	mtpc_inputBotInlineMessageMediaAuto = 0x3380c786,
	mtpc_inputBotInlineMessageText = 0x3dcd7a87,
	mtpc_inputBotInlineMessageMediaGeo = 0x96929a85,
	mtpc_inputBotInlineMessageMediaVenue = 0x417bbf11,
	mtpc_inputBotInlineMessageMediaContact = 0xa6edbffd,
	mtpc_inputBotInlineMessageGame = 0x4b425864,
	mtpc_inputBotInlineMessageMediaInvoice = 0xd7e78225,
	mtpc_inputBotInlineResult = 0x88bf9319,
	mtpc_inputBotInlineResultPhoto = 0xa8d864a7,
	mtpc_inputBotInlineResultDocument = 0xfff8fdc4,
	mtpc_inputBotInlineResultGame = 0x4fa417f2,
	mtpc_botInlineMessageMediaAuto = 0x764cf810,
	mtpc_botInlineMessageText = 0x8c7f65e2,
	mtpc_botInlineMessageMediaGeo = 0x51846fd,
	mtpc_botInlineMessageMediaVenue = 0x8a86659c,
	mtpc_botInlineMessageMediaContact = 0x18d1cdc2,
	mtpc_botInlineMessageMediaInvoice = 0x354a9b09,
	mtpc_botInlineResult = 0x11965f3a,
	mtpc_botInlineMediaResult = 0x17db940b,
	mtpc_messages_botResults = 0x947ca848,
	mtpc_exportedMessageLink = 0x5dab1af4,
	mtpc_messageFwdHeader = 0x5f777dce,
	mtpc_auth_codeTypeSms = 0x72a3158c,
	mtpc_auth_codeTypeCall = 0x741cd3e3,
	mtpc_auth_codeTypeFlashCall = 0x226ccefb,
	mtpc_auth_sentCodeTypeApp = 0x3dbb5986,
	mtpc_auth_sentCodeTypeSms = 0xc000bba2,
	mtpc_auth_sentCodeTypeCall = 0x5353e5a7,
	mtpc_auth_sentCodeTypeFlashCall = 0xab03c6d9,
	mtpc_messages_botCallbackAnswer = 0x36585ea4,
	mtpc_messages_messageEditData = 0x26b5dde6,
	mtpc_inputBotInlineMessageID = 0x890c3d89,
	mtpc_inlineBotSwitchPM = 0x3c20629f,
	mtpc_messages_peerDialogs = 0x3371c354,
	mtpc_topPeer = 0xedcdc05b,
	mtpc_topPeerCategoryBotsPM = 0xab661b5b,
	mtpc_topPeerCategoryBotsInline = 0x148677e2,
	mtpc_topPeerCategoryCorrespondents = 0x637b7ed,
	mtpc_topPeerCategoryGroups = 0xbd17a14a,
	mtpc_topPeerCategoryChannels = 0x161d9628,
	mtpc_topPeerCategoryPhoneCalls = 0x1e76a78c,
	mtpc_topPeerCategoryForwardUsers = 0xa8406ca9,
	mtpc_topPeerCategoryForwardChats = 0xfbeec0f0,
	mtpc_topPeerCategoryPeers = 0xfb834291,
	mtpc_contacts_topPeersNotModified = 0xde266ef5,
	mtpc_contacts_topPeers = 0x70b772a8,
	mtpc_contacts_topPeersDisabled = 0xb52c939d,
	mtpc_draftMessageEmpty = 0x1b0c841a,
	mtpc_draftMessage = 0xfd8e711f,
	mtpc_messages_featuredStickersNotModified = 0xc6dc0c66,
	mtpc_messages_featuredStickers = 0xb6abc341,
	mtpc_messages_recentStickersNotModified = 0xb17f890,
	mtpc_messages_recentStickers = 0x22f3afb3,
	mtpc_messages_archivedStickers = 0x4fcba9c8,
	mtpc_messages_stickerSetInstallResultSuccess = 0x38641628,
	mtpc_messages_stickerSetInstallResultArchive = 0x35e410a8,
	mtpc_stickerSetCovered = 0x6410a5d2,
	mtpc_stickerSetMultiCovered = 0x3407e51b,
	mtpc_maskCoords = 0xaed6dbb2,
	mtpc_inputStickeredMediaPhoto = 0x4a992157,
	mtpc_inputStickeredMediaDocument = 0x438865b,
	mtpc_game = 0xbdf9653b,
	mtpc_inputGameID = 0x32c3e77,
	mtpc_inputGameShortName = 0xc331e80a,
	mtpc_highScore = 0x58fffcd0,
	mtpc_messages_highScores = 0x9a3bfd99,
	mtpc_textEmpty = 0xdc3d824f,
	mtpc_textPlain = 0x744694e0,
	mtpc_textBold = 0x6724abc4,
	mtpc_textItalic = 0xd912a59c,
	mtpc_textUnderline = 0xc12622c4,
	mtpc_textStrike = 0x9bf8bb95,
	mtpc_textFixed = 0x6c3f19b9,
	mtpc_textUrl = 0x3c2884c1,
	mtpc_textEmail = 0xde5a0dd6,
	mtpc_textConcat = 0x7e6260d7,
	mtpc_textSubscript = 0xed6a8504,
	mtpc_textSuperscript = 0xc7fb5e01,
	mtpc_textMarked = 0x34b8621,
	mtpc_textPhone = 0x1ccb966a,
	mtpc_textImage = 0x81ccf4f,
	mtpc_textAnchor = 0x35553762,
	mtpc_pageBlockUnsupported = 0x13567e8a,
	mtpc_pageBlockTitle = 0x70abc3fd,
	mtpc_pageBlockSubtitle = 0x8ffa9a1f,
	mtpc_pageBlockAuthorDate = 0xbaafe5e0,
	mtpc_pageBlockHeader = 0xbfd064ec,
	mtpc_pageBlockSubheader = 0xf12bb6e1,
	mtpc_pageBlockParagraph = 0x467a0766,
	mtpc_pageBlockPreformatted = 0xc070d93e,
	mtpc_pageBlockFooter = 0x48870999,
	mtpc_pageBlockDivider = 0xdb20b188,
	mtpc_pageBlockAnchor = 0xce0d37b0,
	mtpc_pageBlockList = 0xe4e88011,
	mtpc_pageBlockBlockquote = 0x263d7c26,
	mtpc_pageBlockPullquote = 0x4f4456d3,
	mtpc_pageBlockPhoto = 0x1759c560,
	mtpc_pageBlockVideo = 0x7c8fe7b6,
	mtpc_pageBlockCover = 0x39f23300,
	mtpc_pageBlockEmbed = 0xa8718dc5,
	mtpc_pageBlockEmbedPost = 0xf259a80b,
	mtpc_pageBlockCollage = 0x65a0fa4d,
	mtpc_pageBlockSlideshow = 0x31f9590,
	mtpc_pageBlockChannel = 0xef1751b5,
	mtpc_pageBlockAudio = 0x804361ea,
	mtpc_pageBlockKicker = 0x1e148390,
	mtpc_pageBlockTable = 0xbf4dea82,
	mtpc_pageBlockOrderedList = 0x9a8ae1e1,
	mtpc_pageBlockDetails = 0x76768bed,
	mtpc_pageBlockRelatedArticles = 0x16115a96,
	mtpc_pageBlockMap = 0xa44f3ef6,
	mtpc_phoneCallDiscardReasonMissed = 0x85e42301,
	mtpc_phoneCallDiscardReasonDisconnect = 0xe095c1a0,
	mtpc_phoneCallDiscardReasonHangup = 0x57adc690,
	mtpc_phoneCallDiscardReasonBusy = 0xfaf7e8c9,
	mtpc_dataJSON = 0x7d748d04,
	mtpc_labeledPrice = 0xcb296bf8,
	mtpc_invoice = 0xcd886e0,
	mtpc_paymentCharge = 0xea02c27e,
	mtpc_postAddress = 0x1e8caaeb,
	mtpc_paymentRequestedInfo = 0x909c3f94,
	mtpc_paymentSavedCredentialsCard = 0xcdc27a1f,
	mtpc_webDocument = 0x1c570ed1,
	mtpc_webDocumentNoProxy = 0xf9c8bcc6,
	mtpc_inputWebDocument = 0x9bed434d,
	mtpc_inputWebFileLocation = 0xc239d686,
	mtpc_inputWebFileGeoPointLocation = 0x9f2221c9,
	mtpc_upload_webFile = 0x21e753bc,
	mtpc_payments_paymentForm = 0x8d0b2415,
	mtpc_payments_validatedRequestedInfo = 0xd1451883,
	mtpc_payments_paymentResult = 0x4e5f810d,
	mtpc_payments_paymentVerificationNeeded = 0xd8411139,
	mtpc_payments_paymentReceipt = 0x10b555d0,
	mtpc_payments_savedInfo = 0xfb8fe43c,
	mtpc_inputPaymentCredentialsSaved = 0xc10eb2cf,
	mtpc_inputPaymentCredentials = 0x3417d728,
	mtpc_inputPaymentCredentialsApplePay = 0xaa1c39f,
	mtpc_inputPaymentCredentialsGooglePay = 0x8ac32801,
	mtpc_account_tmpPassword = 0xdb64fd34,
	mtpc_shippingOption = 0xb6213cdf,
	mtpc_inputStickerSetItem = 0xffa0a496,
	mtpc_inputPhoneCall = 0x1e36fded,
	mtpc_phoneCallEmpty = 0x5366c915,
	mtpc_phoneCallWaiting = 0x1b8f4ad1,
	mtpc_phoneCallRequested = 0x87eabb53,
	mtpc_phoneCallAccepted = 0x997c454a,
	mtpc_phoneCall = 0x8742ae7f,
	mtpc_phoneCallDiscarded = 0x50ca4de1,
	mtpc_phoneConnection = 0x9d4c17c0,
	mtpc_phoneConnectionWebrtc = 0x635fe375,
	mtpc_phoneCallProtocol = 0xfc878fc8,
	mtpc_phone_phoneCall = 0xec82e140,
	mtpc_upload_cdnFileReuploadNeeded = 0xeea8e46e,
	mtpc_upload_cdnFile = 0xa99fca4f,
	mtpc_cdnPublicKey = 0xc982eaba,
	mtpc_cdnConfig = 0x5725e40a,
	mtpc_langPackString = 0xcad181f6,
	mtpc_langPackStringPluralized = 0x6c47ac9f,
	mtpc_langPackStringDeleted = 0x2979eeb2,
	mtpc_langPackDifference = 0xf385c1f6,
	mtpc_langPackLanguage = 0xeeca5ce3,
	mtpc_channelAdminLogEventActionChangeTitle = 0xe6dfb825,
	mtpc_channelAdminLogEventActionChangeAbout = 0x55188a2e,
	mtpc_channelAdminLogEventActionChangeUsername = 0x6a4afc38,
	mtpc_channelAdminLogEventActionChangePhoto = 0x434bd2af,
	mtpc_channelAdminLogEventActionToggleInvites = 0x1b7907ae,
	mtpc_channelAdminLogEventActionToggleSignatures = 0x26ae0971,
	mtpc_channelAdminLogEventActionUpdatePinned = 0xe9e82c18,
	mtpc_channelAdminLogEventActionEditMessage = 0x709b2405,
	mtpc_channelAdminLogEventActionDeleteMessage = 0x42e047bb,
	mtpc_channelAdminLogEventActionParticipantJoin = 0x183040d3,
	mtpc_channelAdminLogEventActionParticipantLeave = 0xf89777f2,
	mtpc_channelAdminLogEventActionParticipantInvite = 0xe31c34d8,
	mtpc_channelAdminLogEventActionParticipantToggleBan = 0xe6d83d7e,
	mtpc_channelAdminLogEventActionParticipantToggleAdmin = 0xd5676710,
	mtpc_channelAdminLogEventActionChangeStickerSet = 0xb1c3caa7,
	mtpc_channelAdminLogEventActionTogglePreHistoryHidden = 0x5f5c95f1,
	mtpc_channelAdminLogEventActionDefaultBannedRights = 0x2df5fc0a,
	mtpc_channelAdminLogEventActionStopPoll = 0x8f079643,
	mtpc_channelAdminLogEventActionChangeLinkedChat = 0xa26f881b,
	mtpc_channelAdminLogEventActionChangeLocation = 0xe6b76ae,
	mtpc_channelAdminLogEventActionToggleSlowMode = 0x53909779,
	mtpc_channelAdminLogEventActionStartGroupCall = 0x23209745,
	mtpc_channelAdminLogEventActionDiscardGroupCall = 0xdb9f9140,
	mtpc_channelAdminLogEventActionParticipantMute = 0xf92424d2,
	mtpc_channelAdminLogEventActionParticipantUnmute = 0xe64429c0,
	mtpc_channelAdminLogEventActionToggleGroupCallSetting = 0x56d6a247,
	mtpc_channelAdminLogEventActionParticipantJoinByInvite = 0x5cdada77,
	mtpc_channelAdminLogEventActionExportedInviteDelete = 0x5a50fca4,
	mtpc_channelAdminLogEventActionExportedInviteRevoke = 0x410a134e,
	mtpc_channelAdminLogEventActionExportedInviteEdit = 0xe90ebb59,
	mtpc_channelAdminLogEventActionParticipantVolume = 0x3e7f6847,
	mtpc_channelAdminLogEventActionChangeHistoryTTL = 0x6e941a38,
	mtpc_channelAdminLogEvent = 0x3b5a3e40,
	mtpc_channels_adminLogResults = 0xed8af74d,
	mtpc_channelAdminLogEventsFilter = 0xea107ae4,
	mtpc_popularContact = 0x5ce14175,
	mtpc_messages_favedStickersNotModified = 0x9e8fa6d3,
	mtpc_messages_favedStickers = 0xf37f2f16,
	mtpc_recentMeUrlUnknown = 0x46e1d13d,
	mtpc_recentMeUrlUser = 0x8dbc3336,
	mtpc_recentMeUrlChat = 0xa01b22f9,
	mtpc_recentMeUrlChatInvite = 0xeb49081d,
	mtpc_recentMeUrlStickerSet = 0xbc0a57dc,
	mtpc_help_recentMeUrls = 0xe0310d7,
	mtpc_inputSingleMedia = 0x1cc6e91f,
	mtpc_webAuthorization = 0xcac943f2,
	mtpc_account_webAuthorizations = 0xed56c9fc,
	mtpc_inputMessageID = 0xa676a322,
	mtpc_inputMessageReplyTo = 0xbad88395,
	mtpc_inputMessagePinned = 0x86872538,
	mtpc_inputMessageCallbackQuery = 0xacfa1a7e,
	mtpc_inputDialogPeer = 0xfcaafeb7,
	mtpc_inputDialogPeerFolder = 0x64600527,
	mtpc_dialogPeer = 0xe56dbf05,
	mtpc_dialogPeerFolder = 0x514519e2,
	mtpc_messages_foundStickerSetsNotModified = 0xd54b65d,
	mtpc_messages_foundStickerSets = 0x5108d648,
	mtpc_fileHash = 0x6242c773,
	mtpc_inputClientProxy = 0x75588b3f,
	mtpc_help_termsOfServiceUpdateEmpty = 0xe3309f7f,
	mtpc_help_termsOfServiceUpdate = 0x28ecf961,
	mtpc_inputSecureFileUploaded = 0x3334b0f0,
	mtpc_inputSecureFile = 0x5367e5be,
	mtpc_secureFileEmpty = 0x64199744,
	mtpc_secureFile = 0xe0277a62,
	mtpc_secureData = 0x8aeabec3,
	mtpc_securePlainPhone = 0x7d6099dd,
	mtpc_securePlainEmail = 0x21ec5a5f,
	mtpc_secureValueTypePersonalDetails = 0x9d2a81e3,
	mtpc_secureValueTypePassport = 0x3dac6a00,
	mtpc_secureValueTypeDriverLicense = 0x6e425c4,
	mtpc_secureValueTypeIdentityCard = 0xa0d0744b,
	mtpc_secureValueTypeInternalPassport = 0x99a48f23,
	mtpc_secureValueTypeAddress = 0xcbe31e26,
	mtpc_secureValueTypeUtilityBill = 0xfc36954e,
	mtpc_secureValueTypeBankStatement = 0x89137c0d,
	mtpc_secureValueTypeRentalAgreement = 0x8b883488,
	mtpc_secureValueTypePassportRegistration = 0x99e3806a,
	mtpc_secureValueTypeTemporaryRegistration = 0xea02ec33,
	mtpc_secureValueTypePhone = 0xb320aadb,
	mtpc_secureValueTypeEmail = 0x8e3ca7ee,
	mtpc_secureValue = 0x187fa0ca,
	mtpc_inputSecureValue = 0xdb21d0a7,
	mtpc_secureValueHash = 0xed1ecdb0,
	mtpc_secureValueErrorData = 0xe8a40bd9,
	mtpc_secureValueErrorFrontSide = 0xbe3dfa,
	mtpc_secureValueErrorReverseSide = 0x868a2aa5,
	mtpc_secureValueErrorSelfie = 0xe537ced6,
	mtpc_secureValueErrorFile = 0x7a700873,
	mtpc_secureValueErrorFiles = 0x666220e9,
	mtpc_secureValueError = 0x869d758f,
	mtpc_secureValueErrorTranslationFile = 0xa1144770,
	mtpc_secureValueErrorTranslationFiles = 0x34636dd8,
	mtpc_secureCredentialsEncrypted = 0x33f0ea47,
	mtpc_account_authorizationForm = 0xad2e1cd8,
	mtpc_account_sentEmailCode = 0x811f854f,
	mtpc_help_deepLinkInfoEmpty = 0x66afa166,
	mtpc_help_deepLinkInfo = 0x6a4ee832,
	mtpc_savedPhoneContact = 0x1142bd56,
	mtpc_account_takeout = 0x4dba4501,
	mtpc_passwordKdfAlgoUnknown = 0xd45ab096,
	mtpc_passwordKdfAlgoModPow = 0x3a912d4a,
	mtpc_securePasswordKdfAlgoUnknown = 0x4a8537,
	mtpc_securePasswordKdfAlgoPBKDF2HMACSHA512iter100000 = 0xbbf2dda0,
	mtpc_securePasswordKdfAlgoSHA512 = 0x86471d92,
	mtpc_secureSecretSettings = 0x1527bcac,
	mtpc_inputCheckPasswordEmpty = 0x9880f658,
	mtpc_inputCheckPasswordSRP = 0xd27ff082,
	mtpc_secureRequiredType = 0x829d99da,
	mtpc_secureRequiredTypeOneOf = 0x27477b4,
	mtpc_help_passportConfigNotModified = 0xbfb9f457,
	mtpc_help_passportConfig = 0xa098d6af,
	mtpc_inputAppEvent = 0x1d1b1245,
	mtpc_jsonObjectValue = 0xc0de1bd9,
	mtpc_jsonNull = 0x3f6d7b68,
	mtpc_jsonBool = 0xc7345e6a,
	mtpc_jsonNumber = 0x2be0dfa4,
	mtpc_jsonString = 0xb71e767a,
	mtpc_jsonArray = 0xf7444763,
	mtpc_jsonObject = 0x99c1d49d,
	mtpc_pageTableCell = 0x34566b6a,
	mtpc_pageTableRow = 0xe0c0c5e5,
	mtpc_pageCaption = 0x6f747657,
	mtpc_pageListItemText = 0xb92fb6cd,
	mtpc_pageListItemBlocks = 0x25e073fc,
	mtpc_pageListOrderedItemText = 0x5e068047,
	mtpc_pageListOrderedItemBlocks = 0x98dd8936,
	mtpc_pageRelatedArticle = 0xb390dc08,
	mtpc_page = 0x98657f0d,
	mtpc_help_supportName = 0x8c05f1c9,
	mtpc_help_userInfoEmpty = 0xf3ae2eed,
	mtpc_help_userInfo = 0x1eb3758,
	mtpc_pollAnswer = 0x6ca9c2e9,
	mtpc_poll = 0x86e18161,
	mtpc_pollAnswerVoters = 0x3b6ddad2,
	mtpc_pollResults = 0xbadcc1a3,
	mtpc_chatOnlines = 0xf041e250,
	mtpc_statsURL = 0x47a971e0,
	mtpc_chatAdminRights = 0x5fb224d5,
	mtpc_chatBannedRights = 0x9f120418,
	mtpc_inputWallPaper = 0xe630b979,
	mtpc_inputWallPaperSlug = 0x72091c80,
	mtpc_inputWallPaperNoFile = 0x967a462e,
	mtpc_account_wallPapersNotModified = 0x1c199183,
	mtpc_account_wallPapers = 0x702b65a9,
	mtpc_codeSettings = 0xdebebe83,
	mtpc_wallPaperSettings = 0x1dc1bca4,
	mtpc_autoDownloadSettings = 0xe04232f3,
	mtpc_account_autoDownloadSettings = 0x63cacf26,
	mtpc_emojiKeyword = 0xd5b3b9f9,
	mtpc_emojiKeywordDeleted = 0x236df622,
	mtpc_emojiKeywordsDifference = 0x5cc761bd,
	mtpc_emojiURL = 0xa575739d,
	mtpc_emojiLanguage = 0xb3fb5361,
	mtpc_folder = 0xff544e65,
	mtpc_inputFolderPeer = 0xfbd2c296,
	mtpc_folderPeer = 0xe9baa668,
	mtpc_messages_searchCounter = 0xe844ebff,
	mtpc_urlAuthResultRequest = 0x92d33a0e,
	mtpc_urlAuthResultAccepted = 0x8f8c0e4e,
	mtpc_urlAuthResultDefault = 0xa9d6db1f,
	mtpc_channelLocationEmpty = 0xbfb5ad8b,
	mtpc_channelLocation = 0x209b82db,
	mtpc_peerLocated = 0xca461b5d,
	mtpc_peerSelfLocated = 0xf8ec284b,
	mtpc_restrictionReason = 0xd072acb4,
	mtpc_inputTheme = 0x3c5693e9,
	mtpc_inputThemeSlug = 0xf5890df1,
	mtpc_theme = 0xe802b8dc,
	mtpc_account_themesNotModified = 0xf41eb622,
	mtpc_account_themes = 0x7f676421,
	mtpc_auth_loginToken = 0x629f1980,
	mtpc_auth_loginTokenMigrateTo = 0x68e9916,
	mtpc_auth_loginTokenSuccess = 0x390d5c5e,
	mtpc_account_contentSettings = 0x57e28221,
	mtpc_messages_inactiveChats = 0xa927fec5,
	mtpc_baseThemeClassic = 0xc3a12462,
	mtpc_baseThemeDay = 0xfbd81688,
	mtpc_baseThemeNight = 0xb7b31ea8,
	mtpc_baseThemeTinted = 0x6d5f77ee,
	mtpc_baseThemeArctic = 0x5b11125a,
	mtpc_inputThemeSettings = 0xff38f912,
	mtpc_themeSettings = 0x8db4e76c,
	mtpc_webPageAttributeTheme = 0x54b56617,
	mtpc_messageUserVote = 0xa28e5559,
	mtpc_messageUserVoteInputOption = 0x36377430,
	mtpc_messageUserVoteMultiple = 0xe8fe0de,
	mtpc_messages_votesList = 0x823f649,
	mtpc_bankCardOpenUrl = 0xf568028a,
	mtpc_payments_bankCardData = 0x3e24e573,
	mtpc_dialogFilter = 0x7438f7e8,
	mtpc_dialogFilterSuggested = 0x77744d4a,
	mtpc_statsDateRangeDays = 0xb637edaf,
	mtpc_statsAbsValueAndPrev = 0xcb43acde,
	mtpc_statsPercentValue = 0xcbce2fe0,
	mtpc_statsGraphAsync = 0x4a27eb2d,
	mtpc_statsGraphError = 0xbedc9822,
	mtpc_statsGraph = 0x8ea464b6,
	mtpc_messageInteractionCounters = 0xad4fc9bd,
	mtpc_stats_broadcastStats = 0xbdf78394,
	mtpc_help_promoDataEmpty = 0x98f6ac75,
	mtpc_help_promoData = 0x8c39793f,
	mtpc_videoSize = 0xde33b094,
	mtpc_statsGroupTopPoster = 0x18f3d0f7,
	mtpc_statsGroupTopAdmin = 0x6014f412,
	mtpc_statsGroupTopInviter = 0x31962a4c,
	mtpc_stats_megagroupStats = 0xef7ff916,
	mtpc_globalPrivacySettings = 0xbea2f424,
	mtpc_help_countryCode = 0x4203c5ef,
	mtpc_help_country = 0xc3878e23,
	mtpc_help_countriesListNotModified = 0x93cc1f32,
	mtpc_help_countriesList = 0x87d0759e,
	mtpc_messageViews = 0x455b853d,
	mtpc_messages_messageViews = 0xb6c4f543,
	mtpc_messages_discussionMessage = 0xa6341782,
	mtpc_messageReplyHeader = 0xa6d57763,
	mtpc_messageReplies = 0x4128faac,
	mtpc_peerBlocked = 0xe8fd8014,
	mtpc_stats_messageStats = 0x8999f295,
	mtpc_groupCallDiscarded = 0x7780bcb4,
	mtpc_groupCall = 0xd597650c,
	mtpc_inputGroupCall = 0xd8aa840f,
	mtpc_groupCallParticipant = 0xeba636fe,
	mtpc_phone_groupCall = 0x9e727aad,
	mtpc_phone_groupParticipants = 0xf47751b6,
	mtpc_inlineQueryPeerTypeSameBotPM = 0x3081ed9d,
	mtpc_inlineQueryPeerTypePM = 0x833c0fac,
	mtpc_inlineQueryPeerTypeChat = 0xd766c50a,
	mtpc_inlineQueryPeerTypeMegagroup = 0x5ec4be43,
	mtpc_inlineQueryPeerTypeBroadcast = 0x6334ee9a,
	mtpc_messages_historyImport = 0x1662af0b,
	mtpc_messages_historyImportParsed = 0x5e0fb7b9,
	mtpc_messages_affectedFoundMessages = 0xef8d3e6c,
	mtpc_chatInviteImporter = 0x1e3e6680,
	mtpc_messages_exportedChatInvites = 0xbdc62dcc,
	mtpc_messages_exportedChatInvite = 0x1871be50,
	mtpc_messages_exportedChatInviteReplaced = 0x222600ef,
	mtpc_messages_chatInviteImporters = 0x81b6b00a,
	mtpc_chatAdminWithInvites = 0xdfd2330f,
	mtpc_messages_chatAdminsWithInvites = 0xb69b72d7,
	mtpc_messages_checkedHistoryImportPeer = 0xa24de717,
	mtpc_phone_joinAsPeers = 0xafe5623f,
	mtpc_phone_exportedGroupCallInvite = 0x204bd158,
	mtpc_groupCallParticipantVideoSourceGroup = 0xdcb118b7,
	mtpc_groupCallParticipantVideo = 0x67753ac8,
	mtpc_stickers_suggestedShortName = 0x85fea03f,
	mtpc_botCommandScopeDefault = 0x2f6cb2ab,
	mtpc_botCommandScopeUsers = 0x3c4f04d8,
	mtpc_botCommandScopeChats = 0x6fe1a881,
	mtpc_botCommandScopeChatAdmins = 0xb9aa606a,
	mtpc_botCommandScopePeer = 0xdb9d897d,
	mtpc_botCommandScopePeerAdmins = 0x3fd863d1,
	mtpc_botCommandScopePeerUser = 0xa1321f3,
	mtpc_account_resetPasswordFailedWait = 0xe3779861,
	mtpc_account_resetPasswordRequestedWait = 0xe9effc7d,
	mtpc_account_resetPasswordOk = 0xe926d63e,
	mtpc_chatTheme = 0xed0b5c33,
	mtpc_account_chatThemesNotModified = 0xe011e1c4,
	mtpc_account_chatThemes = 0xfe4cbebd,
	mtpc_sponsoredMessage = 0xf671f0d1,
	mtpc_messages_sponsoredMessages = 0x65a4c7d5,
	mtpc_invokeAfterMsg = 0xcb9f372d,
	mtpc_invokeAfterMsgs = 0x3dc4b4f0,
	mtpc_initConnection = 0xc1cd5ea9,
	mtpc_invokeWithLayer = 0xda9b0d0d,
	mtpc_invokeWithoutUpdates = 0xbf9459b7,
	mtpc_invokeWithMessagesRange = 0x365275f2,
	mtpc_invokeWithTakeout = 0xaca9fd2e,
	mtpc_auth_sendCode = 0xa677244f,
	mtpc_auth_signUp = 0x80eee427,
	mtpc_auth_signIn = 0xbcd51581,
	mtpc_auth_logOut = 0x5717da40,
	mtpc_auth_resetAuthorizations = 0x9fab0d1a,
	mtpc_auth_exportAuthorization = 0xe5bfffcd,
	mtpc_auth_importAuthorization = 0xe3ef9613,
	mtpc_auth_bindTempAuthKey = 0xcdd42a05,
	mtpc_auth_importBotAuthorization = 0x67a3ff2c,
	mtpc_auth_checkPassword = 0xd18b4d16,
	mtpc_auth_requestPasswordRecovery = 0xd897bc66,
	mtpc_auth_recoverPassword = 0x37096c70,
	mtpc_auth_resendCode = 0x3ef1a9bf,
	mtpc_auth_cancelCode = 0x1f040578,
	mtpc_auth_dropTempAuthKeys = 0x8e48a188,
	mtpc_auth_exportLoginToken = 0xb1b41517,
	mtpc_auth_importLoginToken = 0x95ac5ce4,
	mtpc_auth_acceptLoginToken = 0xe894ad4d,
	mtpc_auth_checkRecoveryPassword = 0xd36bf79,
	mtpc_account_registerDevice = 0x68976c6f,
	mtpc_account_unregisterDevice = 0x3076c4bf,
	mtpc_account_updateNotifySettings = 0x84be5b93,
	mtpc_account_getNotifySettings = 0x12b3ad31,
	mtpc_account_resetNotifySettings = 0xdb7e1747,
	mtpc_account_updateProfile = 0x78515775,
	mtpc_account_updateStatus = 0x6628562c,
	mtpc_account_getWallPapers = 0xaabb1763,
	mtpc_account_reportPeer = 0xc5ba3d86,
	mtpc_account_checkUsername = 0x2714d86c,
	mtpc_account_updateUsername = 0x3e0bdd7c,
	mtpc_account_getPrivacy = 0xdadbc950,
	mtpc_account_setPrivacy = 0xc9f81ce8,
	mtpc_account_deleteAccount = 0x418d4e0b,
	mtpc_account_getAccountTTL = 0x8fc711d,
	mtpc_account_setAccountTTL = 0x2442485e,
	mtpc_account_sendChangePhoneCode = 0x82574ae5,
	mtpc_account_changePhone = 0x70c32edb,
	mtpc_account_updateDeviceLocked = 0x38df3532,
	mtpc_account_getAuthorizations = 0xe320c158,
	mtpc_account_resetAuthorization = 0xdf77f3bc,
	mtpc_account_getPassword = 0x548a30f5,
	mtpc_account_getPasswordSettings = 0x9cd4eaf9,
	mtpc_account_updatePasswordSettings = 0xa59b102f,
	mtpc_account_sendConfirmPhoneCode = 0x1b3faa88,
	mtpc_account_confirmPhone = 0x5f2178c3,
	mtpc_account_getTmpPassword = 0x449e0b51,
	mtpc_account_getWebAuthorizations = 0x182e6d6f,
	mtpc_account_resetWebAuthorization = 0x2d01b9ef,
	mtpc_account_resetWebAuthorizations = 0x682d2594,
	mtpc_account_getAllSecureValues = 0xb288bc7d,
	mtpc_account_getSecureValue = 0x73665bc2,
	mtpc_account_saveSecureValue = 0x899fe31d,
	mtpc_account_deleteSecureValue = 0xb880bc4b,
	mtpc_account_getAuthorizationForm = 0xb86ba8e1,
	mtpc_account_acceptAuthorization = 0xe7027c94,
	mtpc_account_sendVerifyPhoneCode = 0xa5a356f9,
	mtpc_account_verifyPhone = 0x4dd3a7f6,
	mtpc_account_sendVerifyEmailCode = 0x7011509f,
	mtpc_account_verifyEmail = 0xecba39db,
	mtpc_account_initTakeoutSession = 0xf05b4804,
	mtpc_account_finishTakeoutSession = 0x1d2652ee,
	mtpc_account_confirmPasswordEmail = 0x8fdf1920,
	mtpc_account_resendPasswordEmail = 0x7a7f2a15,
	mtpc_account_cancelPasswordEmail = 0xc1cbd5b6,
	mtpc_account_getContactSignUpNotification = 0x9f07c728,
	mtpc_account_setContactSignUpNotification = 0xcff43f61,
	mtpc_account_getNotifyExceptions = 0x53577479,
	mtpc_account_getWallPaper = 0xfc8ddbea,
	mtpc_account_uploadWallPaper = 0xdd853661,
	mtpc_account_saveWallPaper = 0x6c5a5b37,
	mtpc_account_installWallPaper = 0xfeed5769,
	mtpc_account_resetWallPapers = 0xbb3b9804,
	mtpc_account_getAutoDownloadSettings = 0x56da0b3f,
	mtpc_account_saveAutoDownloadSettings = 0x76f36233,
	mtpc_account_uploadTheme = 0x1c3db333,
	mtpc_account_createTheme = 0x8432c21f,
	mtpc_account_updateTheme = 0x5cb367d5,
	mtpc_account_saveTheme = 0xf257106c,
	mtpc_account_installTheme = 0x7ae43737,
	mtpc_account_getTheme = 0x8d9d742b,
	mtpc_account_getThemes = 0x285946f8,
	mtpc_account_setContentSettings = 0xb574b16b,
	mtpc_account_getContentSettings = 0x8b9b4dae,
	mtpc_account_getMultiWallPapers = 0x65ad71dc,
	mtpc_account_getGlobalPrivacySettings = 0xeb2b4cf6,
	mtpc_account_setGlobalPrivacySettings = 0x1edaaac2,
	mtpc_account_reportProfilePhoto = 0xfa8cc6f5,
	mtpc_account_resetPassword = 0x9308ce1b,
	mtpc_account_declinePasswordReset = 0x4c9409f6,
	mtpc_account_getChatThemes = 0xd6d71d7b,
	mtpc_users_getUsers = 0xd91a548,
	mtpc_users_getFullUser = 0xca30a5b1,
	mtpc_users_setSecureValueErrors = 0x90c894b5,
	mtpc_contacts_getContactIDs = 0x2caa4a42,
	mtpc_contacts_getStatuses = 0xc4a353ee,
	mtpc_contacts_getContacts = 0xc023849f,
	mtpc_contacts_importContacts = 0x2c800be5,
	mtpc_contacts_deleteContacts = 0x96a0e00,
	mtpc_contacts_deleteByPhones = 0x1013fd9e,
	mtpc_contacts_block = 0x68cc1411,
	mtpc_contacts_unblock = 0xbea65d50,
	mtpc_contacts_getBlocked = 0xf57c350f,
	mtpc_contacts_search = 0x11f812d8,
	mtpc_contacts_resolveUsername = 0xf93ccba3,
	mtpc_contacts_getTopPeers = 0xd4982db5,
	mtpc_contacts_resetTopPeerRating = 0x1ae373ac,
	mtpc_contacts_resetSaved = 0x879537f1,
	mtpc_contacts_getSaved = 0x82f1e39f,
	mtpc_contacts_toggleTopPeers = 0x8514bdda,
	mtpc_contacts_addContact = 0xe8f463d0,
	mtpc_contacts_acceptContact = 0xf831a20f,
	mtpc_contacts_getLocated = 0xd348bc44,
	mtpc_contacts_blockFromReplies = 0x29a8962c,
	mtpc_messages_getMessages = 0x63c66506,
	mtpc_messages_getDialogs = 0xa0ee3b73,
	mtpc_messages_getHistory = 0xdcbb8260,
	mtpc_messages_search = 0xc352eec,
	mtpc_messages_readHistory = 0xe306d3a,
	mtpc_messages_deleteHistory = 0x1c015b09,
	mtpc_messages_deleteMessages = 0xe58e95d2,
	mtpc_messages_receivedMessages = 0x5a954c0,
	mtpc_messages_setTyping = 0x58943ee2,
	mtpc_messages_sendMessage = 0x520c3870,
	mtpc_messages_sendMedia = 0x3491eba9,
	mtpc_messages_forwardMessages = 0xd9fee60e,
	mtpc_messages_reportSpam = 0xcf1592db,
	mtpc_messages_getPeerSettings = 0x3672e09c,
	mtpc_messages_report = 0x8953ab4e,
	mtpc_messages_getChats = 0x3c6aa187,
	mtpc_messages_getFullChat = 0x3b831c66,
	mtpc_messages_editChatTitle = 0xdc452855,
	mtpc_messages_editChatPhoto = 0xca4c79d8,
	mtpc_messages_addChatUser = 0xf9a0aa09,
	mtpc_messages_deleteChatUser = 0xc534459a,
	mtpc_messages_createChat = 0x9cb126e,
	mtpc_messages_getDhConfig = 0x26cf8950,
	mtpc_messages_requestEncryption = 0xf64daf43,
	mtpc_messages_acceptEncryption = 0x3dbc0415,
	mtpc_messages_discardEncryption = 0xf393aea0,
	mtpc_messages_setEncryptedTyping = 0x791451ed,
	mtpc_messages_readEncryptedHistory = 0x7f4b690a,
	mtpc_messages_sendEncrypted = 0x44fa7a15,
	mtpc_messages_sendEncryptedFile = 0x5559481d,
	mtpc_messages_sendEncryptedService = 0x32d439a4,
	mtpc_messages_receivedQueue = 0x55a5bb66,
	mtpc_messages_reportEncryptedSpam = 0x4b0c8c0f,
	mtpc_messages_readMessageContents = 0x36a73f77,
	mtpc_messages_getStickers = 0x43d4f2c,
	mtpc_messages_getAllStickers = 0x1c9618b1,
	mtpc_messages_getWebPagePreview = 0x8b68b0cc,
	mtpc_messages_exportChatInvite = 0x14b9bcd7,
	mtpc_messages_checkChatInvite = 0x3eadb1bb,
	mtpc_messages_importChatInvite = 0x6c50051c,
	mtpc_messages_getStickerSet = 0x2619a90e,
	mtpc_messages_installStickerSet = 0xc78fe460,
	mtpc_messages_uninstallStickerSet = 0xf96e55de,
	mtpc_messages_startBot = 0xe6df7378,
	mtpc_messages_getMessagesViews = 0x5784d3e1,
	mtpc_messages_editChatAdmin = 0xa9e69f2e,
	mtpc_messages_migrateChat = 0x15a3b8e3,
	mtpc_messages_searchGlobal = 0x4bc6589a,
	mtpc_messages_reorderStickerSets = 0x78337739,
	mtpc_messages_getDocumentByHash = 0x338e2464,
	mtpc_messages_getSavedGifs = 0x83bf3d52,
	mtpc_messages_saveGif = 0x327a30cb,
	mtpc_messages_getInlineBotResults = 0x514e999d,
	mtpc_messages_setInlineBotResults = 0xeb5ea206,
	mtpc_messages_sendInlineBotResult = 0x220815b0,
	mtpc_messages_getMessageEditData = 0xfda68d36,
	mtpc_messages_editMessage = 0x48f71778,
	mtpc_messages_editInlineBotMessage = 0x83557dba,
	mtpc_messages_getBotCallbackAnswer = 0x9342ca07,
	mtpc_messages_setBotCallbackAnswer = 0xd58f130a,
	mtpc_messages_getPeerDialogs = 0xe470bcfd,
	mtpc_messages_saveDraft = 0xbc39e14b,
	mtpc_messages_getAllDrafts = 0x6a3f8d65,
	mtpc_messages_getFeaturedStickers = 0x2dacca4f,
	mtpc_messages_readFeaturedStickers = 0x5b118126,
	mtpc_messages_getRecentStickers = 0x5ea192c9,
	mtpc_messages_saveRecentSticker = 0x392718f8,
	mtpc_messages_clearRecentStickers = 0x8999602d,
	mtpc_messages_getArchivedStickers = 0x57f17692,
	mtpc_messages_getMaskStickers = 0x65b8c79f,
	mtpc_messages_getAttachedStickers = 0xcc5b67cc,
	mtpc_messages_setGameScore = 0x8ef8ecc0,
	mtpc_messages_setInlineGameScore = 0x15ad9f64,
	mtpc_messages_getGameHighScores = 0xe822649d,
	mtpc_messages_getInlineGameHighScores = 0xf635e1b,
	mtpc_messages_getCommonChats = 0xd0a48c4,
	mtpc_messages_getAllChats = 0xeba80ff0,
	mtpc_messages_getWebPage = 0x32ca8f91,
	mtpc_messages_toggleDialogPin = 0xa731e257,
	mtpc_messages_reorderPinnedDialogs = 0x3b1adf37,
	mtpc_messages_getPinnedDialogs = 0xd6b94df2,
	mtpc_messages_setBotShippingResults = 0xe5f672fa,
	mtpc_messages_setBotPrecheckoutResults = 0x9c2dd95,
	mtpc_messages_uploadMedia = 0x519bc2b1,
	mtpc_messages_sendScreenshotNotification = 0xc97df020,
	mtpc_messages_getFavedStickers = 0x21ce0b0e,
	mtpc_messages_faveSticker = 0xb9ffc55b,
	mtpc_messages_getUnreadMentions = 0x46578472,
	mtpc_messages_readMentions = 0xf0189d3,
	mtpc_messages_getRecentLocations = 0xbbc45b09,
	mtpc_messages_sendMultiMedia = 0xcc0110cb,
	mtpc_messages_uploadEncryptedFile = 0x5057c497,
	mtpc_messages_searchStickerSets = 0xc2b7d08b,
	mtpc_messages_getSplitRanges = 0x1cff7e08,
	mtpc_messages_markDialogUnread = 0xc286d98f,
	mtpc_messages_getDialogUnreadMarks = 0x22e24e22,
	mtpc_messages_clearAllDrafts = 0x7e58ee9c,
	mtpc_messages_updatePinnedMessage = 0xd2aaf7ec,
	mtpc_messages_sendVote = 0x10ea6184,
	mtpc_messages_getPollResults = 0x73bb643b,
	mtpc_messages_getOnlines = 0x6e2be050,
	mtpc_messages_getStatsURL = 0x812c2ae6,
	mtpc_messages_editChatAbout = 0xdef60797,
	mtpc_messages_editChatDefaultBannedRights = 0xa5866b41,
	mtpc_messages_getEmojiKeywords = 0x35a0e062,
	mtpc_messages_getEmojiKeywordsDifference = 0x1508b6af,
	mtpc_messages_getEmojiKeywordsLanguages = 0x4e9963b2,
	mtpc_messages_getEmojiURL = 0xd5b10c26,
	mtpc_messages_getSearchCounters = 0x732eef00,
	mtpc_messages_requestUrlAuth = 0x198fb446,
	mtpc_messages_acceptUrlAuth = 0xb12c7125,
	mtpc_messages_hidePeerSettingsBar = 0x4facb138,
	mtpc_messages_getScheduledHistory = 0xe2c2685b,
	mtpc_messages_getScheduledMessages = 0xbdbb0464,
	mtpc_messages_sendScheduledMessages = 0xbd38850a,
	mtpc_messages_deleteScheduledMessages = 0x59ae2b16,
	mtpc_messages_getPollVotes = 0xb86e380e,
	mtpc_messages_toggleStickerSets = 0xb5052fea,
	mtpc_messages_getDialogFilters = 0xf19ed96d,
	mtpc_messages_getSuggestedDialogFilters = 0xa29cd42c,
	mtpc_messages_updateDialogFilter = 0x1ad4a04a,
	mtpc_messages_updateDialogFiltersOrder = 0xc563c1e4,
	mtpc_messages_getOldFeaturedStickers = 0x5fe7025b,
	mtpc_messages_getReplies = 0x24b581ba,
	mtpc_messages_getDiscussionMessage = 0x446972fd,
	mtpc_messages_readDiscussion = 0xf731a9f4,
	mtpc_messages_unpinAllMessages = 0xf025bc8b,
	mtpc_messages_deleteChat = 0x83247d11,
	mtpc_messages_deletePhoneCallHistory = 0xf9cbe409,
	mtpc_messages_checkHistoryImport = 0x43fe19f3,
	mtpc_messages_initHistoryImport = 0x34090c3b,
	mtpc_messages_uploadImportedMedia = 0x2a862092,
	mtpc_messages_startHistoryImport = 0xb43df344,
	mtpc_messages_getExportedChatInvites = 0xa2b5a3f6,
	mtpc_messages_getExportedChatInvite = 0x73746f5c,
	mtpc_messages_editExportedChatInvite = 0x2e4ffbe,
	mtpc_messages_deleteRevokedExportedChatInvites = 0x56987bd5,
	mtpc_messages_deleteExportedChatInvite = 0xd464a42b,
	mtpc_messages_getAdminsWithInvites = 0x3920e6ef,
	mtpc_messages_getChatInviteImporters = 0x26fb7289,
	mtpc_messages_setHistoryTTL = 0xb80e5fe4,
	mtpc_messages_checkHistoryImportPeer = 0x5dc60f03,
	mtpc_messages_setChatTheme = 0xe63be13f,
	mtpc_updates_getState = 0xedd4882a,
	mtpc_updates_getDifference = 0x25939651,
	mtpc_updates_getChannelDifference = 0x3173d78,
	mtpc_photos_updateProfilePhoto = 0x72d4742c,
	mtpc_photos_uploadProfilePhoto = 0x89f30f69,
	mtpc_photos_deletePhotos = 0x87cf7f2f,
	mtpc_photos_getUserPhotos = 0x91cd32a8,
	mtpc_upload_saveFilePart = 0xb304a621,
	mtpc_upload_getFile = 0xb15a9afc,
	mtpc_upload_saveBigFilePart = 0xde7b673d,
	mtpc_upload_getWebFile = 0x24e6818d,
	mtpc_upload_getCdnFile = 0x2000bcc3,
	mtpc_upload_reuploadCdnFile = 0x9b2754a8,
	mtpc_upload_getCdnFileHashes = 0x4da54231,
	mtpc_upload_getFileHashes = 0xc7025931,
	mtpc_help_getConfig = 0xc4f9186b,
	mtpc_help_getNearestDc = 0x1fb33026,
	mtpc_help_getAppUpdate = 0x522d5a7d,
	mtpc_help_getInviteText = 0x4d392343,
	mtpc_help_getSupport = 0x9cdf08cd,
	mtpc_help_getAppChangelog = 0x9010ef6f,
	mtpc_help_setBotUpdatesStatus = 0xec22cfcd,
	mtpc_help_getCdnConfig = 0x52029342,
	mtpc_help_getRecentMeUrls = 0x3dc0f114,
	mtpc_help_getTermsOfServiceUpdate = 0x2ca51fd1,
	mtpc_help_acceptTermsOfService = 0xee72f79a,
	mtpc_help_getDeepLinkInfo = 0x3fedc75f,
	mtpc_help_getAppConfig = 0x98914110,
	mtpc_help_saveAppLog = 0x6f02f748,
	mtpc_help_getPassportConfig = 0xc661ad08,
	mtpc_help_getSupportName = 0xd360e72c,
	mtpc_help_getUserInfo = 0x38a08d3,
	mtpc_help_editUserInfo = 0x66b91b70,
	mtpc_help_getPromoData = 0xc0977421,
	mtpc_help_hidePromoData = 0x1e251c95,
	mtpc_help_dismissSuggestion = 0xf50dbaa1,
	mtpc_help_getCountriesList = 0x735787a8,
	mtpc_channels_readHistory = 0xcc104937,
	mtpc_channels_deleteMessages = 0x84c1fd4e,
	mtpc_channels_deleteUserHistory = 0xd10dd71b,
	mtpc_channels_reportSpam = 0xfe087810,
	mtpc_channels_getMessages = 0xad8c9a23,
	mtpc_channels_getParticipants = 0x123e05e9,
	mtpc_channels_getParticipant = 0xa0ab6cc6,
	mtpc_channels_getChannels = 0xa7f6bbb,
	mtpc_channels_getFullChannel = 0x8736a09,
	mtpc_channels_createChannel = 0x3d5fb10f,
	mtpc_channels_editAdmin = 0xd33c8902,
	mtpc_channels_editTitle = 0x566decd0,
	mtpc_channels_editPhoto = 0xf12e57c9,
	mtpc_channels_checkUsername = 0x10e6bd2c,
	mtpc_channels_updateUsername = 0x3514b3de,
	mtpc_channels_joinChannel = 0x24b524c5,
	mtpc_channels_leaveChannel = 0xf836aa95,
	mtpc_channels_inviteToChannel = 0x199f3a6c,
	mtpc_channels_deleteChannel = 0xc0111fe3,
	mtpc_channels_exportMessageLink = 0xe63fadeb,
	mtpc_channels_toggleSignatures = 0x1f69b606,
	mtpc_channels_getAdminedPublicChannels = 0xf8b036af,
	mtpc_channels_editBanned = 0x96e6cd81,
	mtpc_channels_getAdminLog = 0x33ddf480,
	mtpc_channels_setStickers = 0xea8ca4f9,
	mtpc_channels_readMessageContents = 0xeab5dc38,
	mtpc_channels_deleteHistory = 0xaf369d42,
	mtpc_channels_togglePreHistoryHidden = 0xeabbb94c,
	mtpc_channels_getLeftChannels = 0x8341ecc0,
	mtpc_channels_getGroupsForDiscussion = 0xf5dad378,
	mtpc_channels_setDiscussionGroup = 0x40582bb2,
	mtpc_channels_editCreator = 0x8f38cd1f,
	mtpc_channels_editLocation = 0x58e63f6d,
	mtpc_channels_toggleSlowMode = 0xedd49ef0,
	mtpc_channels_getInactiveChannels = 0x11e831ee,
	mtpc_channels_convertToGigagroup = 0xb290c69,
	mtpc_channels_viewSponsoredMessage = 0xbeaedb94,
	mtpc_channels_getSponsoredMessages = 0xec210fbf,
	mtpc_bots_sendCustomRequest = 0xaa2769ed,
	mtpc_bots_answerWebhookJSONQuery = 0xe6213f4d,
	mtpc_bots_setBotCommands = 0x517165a,
	mtpc_bots_resetBotCommands = 0x3d8de0f9,
	mtpc_bots_getBotCommands = 0xe34c0dd6,
	mtpc_payments_getPaymentForm = 0x8a333c8d,
	mtpc_payments_getPaymentReceipt = 0x2478d1cc,
	mtpc_payments_validateRequestedInfo = 0xdb103170,
	mtpc_payments_sendPaymentForm = 0x30c3bc9d,
	mtpc_payments_getSavedInfo = 0x227d824b,
	mtpc_payments_clearSavedInfo = 0xd83d70c1,
	mtpc_payments_getBankCardData = 0x2e79d779,
	mtpc_stickers_createStickerSet = 0x9021ab67,
	mtpc_stickers_removeStickerFromSet = 0xf7760f51,
	mtpc_stickers_changeStickerPosition = 0xffb6d4ca,
	mtpc_stickers_addStickerToSet = 0x8653febe,
	mtpc_stickers_setStickerSetThumb = 0x9a364e30,
	mtpc_stickers_checkShortName = 0x284b3639,
	mtpc_stickers_suggestShortName = 0x4dafc503,
	mtpc_phone_getCallConfig = 0x55451fa9,
	mtpc_phone_requestCall = 0x42ff96ed,
	mtpc_phone_acceptCall = 0x3bd2b4a0,
	mtpc_phone_confirmCall = 0x2efe1722,
	mtpc_phone_receivedCall = 0x17d54f61,
	mtpc_phone_discardCall = 0xb2cbc1c0,
	mtpc_phone_setCallRating = 0x59ead627,
	mtpc_phone_saveCallDebug = 0x277add7e,
	mtpc_phone_sendSignalingData = 0xff7a9383,
	mtpc_phone_createGroupCall = 0x48cdc6d8,
	mtpc_phone_joinGroupCall = 0xb132ff7b,
	mtpc_phone_leaveGroupCall = 0x500377f9,
	mtpc_phone_inviteToGroupCall = 0x7b393160,
	mtpc_phone_discardGroupCall = 0x7a777135,
	mtpc_phone_toggleGroupCallSettings = 0x74bbb43d,
	mtpc_phone_getGroupCall = 0x41845db,
	mtpc_phone_getGroupParticipants = 0xc558d8ab,
	mtpc_phone_checkGroupCall = 0xb59cf977,
	mtpc_phone_toggleGroupCallRecord = 0xf128c708,
	mtpc_phone_editGroupCallParticipant = 0xa5273abf,
	mtpc_phone_editGroupCallTitle = 0x1ca6ac0a,
	mtpc_phone_getGroupCallJoinAs = 0xef7c213a,
	mtpc_phone_exportGroupCallInvite = 0xe6aa647f,
	mtpc_phone_toggleGroupCallStartSubscription = 0x219c34e6,
	mtpc_phone_startScheduledGroupCall = 0x5680e342,
	mtpc_phone_saveDefaultGroupCallJoinAs = 0x575e1f8c,
	mtpc_phone_joinGroupCallPresentation = 0xcbea6bc4,
	mtpc_phone_leaveGroupCallPresentation = 0x1c50d144,
	mtpc_langpack_getLangPack = 0xf2f2330a,
	mtpc_langpack_getStrings = 0xefea3803,
	mtpc_langpack_getDifference = 0xcd984aa5,
	mtpc_langpack_getLanguages = 0x42c6978f,
	mtpc_langpack_getLanguage = 0x6a596502,
	mtpc_folders_editPeerFolders = 0x6847d0ab,
	mtpc_folders_deleteFolder = 0x1c295881,
	mtpc_stats_getBroadcastStats = 0xab42441a,
	mtpc_stats_loadAsyncGraph = 0x621d5fa0,
	mtpc_stats_getMegagroupStats = 0xdcdf8607,
	mtpc_stats_getMessagePublicForwards = 0x5630281b,
	mtpc_stats_getMessageStats = 0xb6e0a3f5
};

// Type constructors with data

struct MTPDinputMediaUploadedPhoto {
	enum class Flag : uint32 {
		f_stickers = (1U << 0),
		f_ttl_seconds = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputMediaPhoto {
	enum class Flag : uint32 {
		f_ttl_seconds = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputMediaUploadedDocument {
	enum class Flag : uint32 {
		f_nosound_video = (1U << 3),
		f_force_file = (1U << 4),
		f_thumb = (1U << 2),
		f_stickers = (1U << 0),
		f_ttl_seconds = (1U << 1),

		MAX_FIELD = (1U << 4),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputMediaDocument {
	enum class Flag : uint32 {
		f_ttl_seconds = (1U << 0),
		f_query = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputMediaPhotoExternal {
	enum class Flag : uint32 {
		f_ttl_seconds = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputMediaDocumentExternal {
	enum class Flag : uint32 {
		f_ttl_seconds = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputMediaInvoice {
	enum class Flag : uint32 {
		f_photo = (1U << 0),
		f_start_param = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputMediaGeoLive {
	enum class Flag : uint32 {
		f_stopped = (1U << 0),
		f_heading = (1U << 2),
		f_period = (1U << 1),
		f_proximity_notification_radius = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputMediaPoll {
	enum class Flag : uint32 {
		f_correct_answers = (1U << 0),
		f_solution = (1U << 1),
		f_solution_entities = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputChatUploadedPhoto {
	enum class Flag : uint32 {
		f_file = (1U << 0),
		f_video = (1U << 1),
		f_video_start_ts = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputGeoPoint {
	enum class Flag : uint32 {
		f_accuracy_radius = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputPeerPhotoFileLocation {
	enum class Flag : uint32 {
		f_big = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputGroupCallStream {
	enum class Flag : uint32 {
		f_video_channel = (1U << 0),
		f_video_quality = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDuser {
	enum class Flag : uint32 {
		f_self = (1U << 10),
		f_contact = (1U << 11),
		f_mutual_contact = (1U << 12),
		f_deleted = (1U << 13),
		f_bot = (1U << 14),
		f_bot_chat_history = (1U << 15),
		f_bot_nochats = (1U << 16),
		f_verified = (1U << 17),
		f_restricted = (1U << 18),
		f_min = (1U << 20),
		f_bot_inline_geo = (1U << 21),
		f_support = (1U << 23),
		f_scam = (1U << 24),
		f_apply_min_photo = (1U << 25),
		f_fake = (1U << 26),
		f_access_hash = (1U << 0),
		f_first_name = (1U << 1),
		f_last_name = (1U << 2),
		f_username = (1U << 3),
		f_phone = (1U << 4),
		f_photo = (1U << 5),
		f_status = (1U << 6),
		f_bot_info_version = (1U << 14),
		f_restriction_reason = (1U << 18),
		f_bot_inline_placeholder = (1U << 19),
		f_lang_code = (1U << 22),

		MAX_FIELD = (1U << 26),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDuserProfilePhoto {
	enum class Flag : uint32 {
		f_has_video = (1U << 0),
		f_stripped_thumb = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchat {
	enum class Flag : uint32 {
		f_creator = (1U << 0),
		f_kicked = (1U << 1),
		f_left = (1U << 2),
		f_deactivated = (1U << 5),
		f_call_active = (1U << 23),
		f_call_not_empty = (1U << 24),
		f_migrated_to = (1U << 6),
		f_admin_rights = (1U << 14),
		f_default_banned_rights = (1U << 18),

		MAX_FIELD = (1U << 24),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchannel {
	enum class Flag : uint32 {
		f_creator = (1U << 0),
		f_left = (1U << 2),
		f_broadcast = (1U << 5),
		f_verified = (1U << 7),
		f_megagroup = (1U << 8),
		f_restricted = (1U << 9),
		f_signatures = (1U << 11),
		f_min = (1U << 12),
		f_scam = (1U << 19),
		f_has_link = (1U << 20),
		f_has_geo = (1U << 21),
		f_slowmode_enabled = (1U << 22),
		f_call_active = (1U << 23),
		f_call_not_empty = (1U << 24),
		f_fake = (1U << 25),
		f_gigagroup = (1U << 26),
		f_access_hash = (1U << 13),
		f_username = (1U << 6),
		f_restriction_reason = (1U << 9),
		f_admin_rights = (1U << 14),
		f_banned_rights = (1U << 15),
		f_default_banned_rights = (1U << 18),
		f_participants_count = (1U << 17),

		MAX_FIELD = (1U << 26),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchannelForbidden {
	enum class Flag : uint32 {
		f_broadcast = (1U << 5),
		f_megagroup = (1U << 8),
		f_until_date = (1U << 16),

		MAX_FIELD = (1U << 16),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchatFull {
	enum class Flag : uint32 {
		f_can_set_username = (1U << 7),
		f_has_scheduled = (1U << 8),
		f_chat_photo = (1U << 2),
		f_exported_invite = (1U << 13),
		f_bot_info = (1U << 3),
		f_pinned_msg_id = (1U << 6),
		f_folder_id = (1U << 11),
		f_call = (1U << 12),
		f_ttl_period = (1U << 14),
		f_groupcall_default_join_as = (1U << 15),
		f_theme_emoticon = (1U << 16),

		MAX_FIELD = (1U << 16),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchannelFull {
	enum class Flag : uint32 {
		f_can_view_participants = (1U << 3),
		f_can_set_username = (1U << 6),
		f_can_set_stickers = (1U << 7),
		f_hidden_prehistory = (1U << 10),
		f_can_set_location = (1U << 16),
		f_has_scheduled = (1U << 19),
		f_can_view_stats = (1U << 20),
		f_blocked = (1U << 22),
		f_participants_count = (1U << 0),
		f_admins_count = (1U << 1),
		f_kicked_count = (1U << 2),
		f_banned_count = (1U << 2),
		f_online_count = (1U << 13),
		f_exported_invite = (1U << 23),
		f_migrated_from_chat_id = (1U << 4),
		f_migrated_from_max_id = (1U << 4),
		f_pinned_msg_id = (1U << 5),
		f_stickerset = (1U << 8),
		f_available_min_id = (1U << 9),
		f_folder_id = (1U << 11),
		f_linked_chat_id = (1U << 14),
		f_location = (1U << 15),
		f_slowmode_seconds = (1U << 17),
		f_slowmode_next_send_date = (1U << 18),
		f_stats_dc = (1U << 12),
		f_call = (1U << 21),
		f_ttl_period = (1U << 24),
		f_pending_suggestions = (1U << 25),
		f_groupcall_default_join_as = (1U << 26),
		f_theme_emoticon = (1U << 27),

		MAX_FIELD = (1U << 27),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchatParticipantsForbidden {
	enum class Flag : uint32 {
		f_self_participant = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchatPhoto {
	enum class Flag : uint32 {
		f_has_video = (1U << 0),
		f_stripped_thumb = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessageEmpty {
	enum class Flag : uint32 {
		f_peer_id = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessage {
	enum class Flag : uint32 {
		f_out = (1U << 1),
		f_mentioned = (1U << 4),
		f_media_unread = (1U << 5),
		f_silent = (1U << 13),
		f_post = (1U << 14),
		f_from_scheduled = (1U << 18),
		f_legacy = (1U << 19),
		f_edit_hide = (1U << 21),
		f_pinned = (1U << 24),
		f_from_id = (1U << 8),
		f_fwd_from = (1U << 2),
		f_via_bot_id = (1U << 11),
		f_reply_to = (1U << 3),
		f_media = (1U << 9),
		f_reply_markup = (1U << 6),
		f_entities = (1U << 7),
		f_views = (1U << 10),
		f_forwards = (1U << 10),
		f_replies = (1U << 23),
		f_edit_date = (1U << 15),
		f_post_author = (1U << 16),
		f_grouped_id = (1U << 17),
		f_restriction_reason = (1U << 22),
		f_ttl_period = (1U << 25),

		MAX_FIELD = (1U << 25),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessageService {
	enum class Flag : uint32 {
		f_out = (1U << 1),
		f_mentioned = (1U << 4),
		f_media_unread = (1U << 5),
		f_silent = (1U << 13),
		f_post = (1U << 14),
		f_legacy = (1U << 19),
		f_from_id = (1U << 8),
		f_reply_to = (1U << 3),
		f_ttl_period = (1U << 25),

		MAX_FIELD = (1U << 25),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessageMediaPhoto {
	enum class Flag : uint32 {
		f_photo = (1U << 0),
		f_ttl_seconds = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessageMediaDocument {
	enum class Flag : uint32 {
		f_document = (1U << 0),
		f_ttl_seconds = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessageMediaInvoice {
	enum class Flag : uint32 {
		f_shipping_address_requested = (1U << 1),
		f_test = (1U << 3),
		f_photo = (1U << 0),
		f_receipt_msg_id = (1U << 2),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessageMediaGeoLive {
	enum class Flag : uint32 {
		f_heading = (1U << 0),
		f_proximity_notification_radius = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessageActionPaymentSentMe {
	enum class Flag : uint32 {
		f_info = (1U << 0),
		f_shipping_option_id = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessageActionPhoneCall {
	enum class Flag : uint32 {
		f_video = (1U << 2),
		f_reason = (1U << 0),
		f_duration = (1U << 1),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessageActionGroupCall {
	enum class Flag : uint32 {
		f_duration = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDdialog {
	enum class Flag : uint32 {
		f_pinned = (1U << 2),
		f_unread_mark = (1U << 3),
		f_pts = (1U << 0),
		f_draft = (1U << 1),
		f_folder_id = (1U << 4),

		MAX_FIELD = (1U << 4),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDdialogFolder {
	enum class Flag : uint32 {
		f_pinned = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDphoto {
	enum class Flag : uint32 {
		f_has_stickers = (1U << 0),
		f_video_sizes = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDgeoPoint {
	enum class Flag : uint32 {
		f_accuracy_radius = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDauth_sentCode {
	enum class Flag : uint32 {
		f_next_type = (1U << 1),
		f_timeout = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDauth_authorization {
	enum class Flag : uint32 {
		f_tmp_sessions = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDauth_authorizationSignUpRequired {
	enum class Flag : uint32 {
		f_terms_of_service = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputPeerNotifySettings {
	enum class Flag : uint32 {
		f_show_previews = (1U << 0),
		f_silent = (1U << 1),
		f_mute_until = (1U << 2),
		f_sound = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpeerNotifySettings {
	enum class Flag : uint32 {
		f_show_previews = (1U << 0),
		f_silent = (1U << 1),
		f_mute_until = (1U << 2),
		f_sound = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpeerSettings {
	enum class Flag : uint32 {
		f_report_spam = (1U << 0),
		f_add_contact = (1U << 1),
		f_block_contact = (1U << 2),
		f_share_contact = (1U << 3),
		f_need_contacts_exception = (1U << 4),
		f_report_geo = (1U << 5),
		f_autoarchived = (1U << 7),
		f_invite_members = (1U << 8),
		f_geo_distance = (1U << 6),

		MAX_FIELD = (1U << 8),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDwallPaper {
	enum class Flag : uint32 {
		f_creator = (1U << 0),
		f_default = (1U << 1),
		f_pattern = (1U << 3),
		f_dark = (1U << 4),
		f_settings = (1U << 2),

		MAX_FIELD = (1U << 4),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDwallPaperNoFile {
	enum class Flag : uint32 {
		f_default = (1U << 1),
		f_dark = (1U << 4),
		f_settings = (1U << 2),

		MAX_FIELD = (1U << 4),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDuserFull {
	enum class Flag : uint32 {
		f_blocked = (1U << 0),
		f_phone_calls_available = (1U << 4),
		f_phone_calls_private = (1U << 5),
		f_can_pin_message = (1U << 7),
		f_has_scheduled = (1U << 12),
		f_video_calls_available = (1U << 13),
		f_about = (1U << 1),
		f_profile_photo = (1U << 2),
		f_bot_info = (1U << 3),
		f_pinned_msg_id = (1U << 6),
		f_folder_id = (1U << 11),
		f_ttl_period = (1U << 14),
		f_theme_emoticon = (1U << 15),

		MAX_FIELD = (1U << 15),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessages_messagesSlice {
	enum class Flag : uint32 {
		f_inexact = (1U << 1),
		f_next_rate = (1U << 0),
		f_offset_id_offset = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessages_channelMessages {
	enum class Flag : uint32 {
		f_inexact = (1U << 1),
		f_offset_id_offset = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputMessagesFilterPhoneCalls {
	enum class Flag : uint32 {
		f_missed = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateServiceNotification {
	enum class Flag : uint32 {
		f_popup = (1U << 0),
		f_inbox_date = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateReadHistoryInbox {
	enum class Flag : uint32 {
		f_folder_id = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateChannelTooLong {
	enum class Flag : uint32 {
		f_pts = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateReadChannelInbox {
	enum class Flag : uint32 {
		f_folder_id = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateStickerSetsOrder {
	enum class Flag : uint32 {
		f_masks = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateBotInlineQuery {
	enum class Flag : uint32 {
		f_geo = (1U << 0),
		f_peer_type = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateBotInlineSend {
	enum class Flag : uint32 {
		f_geo = (1U << 0),
		f_msg_id = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateBotCallbackQuery {
	enum class Flag : uint32 {
		f_data = (1U << 0),
		f_game_short_name = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateInlineBotCallbackQuery {
	enum class Flag : uint32 {
		f_data = (1U << 0),
		f_game_short_name = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateDialogPinned {
	enum class Flag : uint32 {
		f_pinned = (1U << 0),
		f_folder_id = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdatePinnedDialogs {
	enum class Flag : uint32 {
		f_folder_id = (1U << 1),
		f_order = (1U << 0),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateBotPrecheckoutQuery {
	enum class Flag : uint32 {
		f_info = (1U << 0),
		f_shipping_option_id = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateDialogUnreadMark {
	enum class Flag : uint32 {
		f_unread = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateMessagePoll {
	enum class Flag : uint32 {
		f_poll = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateDialogFilter {
	enum class Flag : uint32 {
		f_filter = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateReadChannelDiscussionInbox {
	enum class Flag : uint32 {
		f_broadcast_id = (1U << 0),
		f_broadcast_post = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateChannelUserTyping {
	enum class Flag : uint32 {
		f_top_msg_id = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdatePinnedMessages {
	enum class Flag : uint32 {
		f_pinned = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdatePinnedChannelMessages {
	enum class Flag : uint32 {
		f_pinned = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdatePeerHistoryTTL {
	enum class Flag : uint32 {
		f_ttl_period = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateChatParticipant {
	enum class Flag : uint32 {
		f_prev_participant = (1U << 0),
		f_new_participant = (1U << 1),
		f_invite = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateChannelParticipant {
	enum class Flag : uint32 {
		f_prev_participant = (1U << 0),
		f_new_participant = (1U << 1),
		f_invite = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateGroupCallConnection {
	enum class Flag : uint32 {
		f_presentation = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateShortMessage {
	enum class Flag : uint32 {
		f_out = (1U << 1),
		f_mentioned = (1U << 4),
		f_media_unread = (1U << 5),
		f_silent = (1U << 13),
		f_fwd_from = (1U << 2),
		f_via_bot_id = (1U << 11),
		f_reply_to = (1U << 3),
		f_entities = (1U << 7),
		f_ttl_period = (1U << 25),

		MAX_FIELD = (1U << 25),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateShortChatMessage {
	enum class Flag : uint32 {
		f_out = (1U << 1),
		f_mentioned = (1U << 4),
		f_media_unread = (1U << 5),
		f_silent = (1U << 13),
		f_fwd_from = (1U << 2),
		f_via_bot_id = (1U << 11),
		f_reply_to = (1U << 3),
		f_entities = (1U << 7),
		f_ttl_period = (1U << 25),

		MAX_FIELD = (1U << 25),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdateShortSentMessage {
	enum class Flag : uint32 {
		f_out = (1U << 1),
		f_media = (1U << 9),
		f_entities = (1U << 7),
		f_ttl_period = (1U << 25),

		MAX_FIELD = (1U << 25),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDdcOption {
	enum class Flag : uint32 {
		f_ipv6 = (1U << 0),
		f_media_only = (1U << 1),
		f_tcpo_only = (1U << 2),
		f_cdn = (1U << 3),
		f_static = (1U << 4),
		f_secret = (1U << 10),

		MAX_FIELD = (1U << 10),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDconfig {
	enum class Flag : uint32 {
		f_phonecalls_enabled = (1U << 1),
		f_default_p2p_contacts = (1U << 3),
		f_preload_featured_stickers = (1U << 4),
		f_ignore_phone_entities = (1U << 5),
		f_revoke_pm_inbox = (1U << 6),
		f_blocked_mode = (1U << 8),
		f_pfs_enabled = (1U << 13),
		f_tmp_sessions = (1U << 0),
		f_autoupdate_url_prefix = (1U << 7),
		f_gif_search_username = (1U << 9),
		f_venue_search_username = (1U << 10),
		f_img_search_username = (1U << 11),
		f_static_maps_provider = (1U << 12),
		f_suggested_lang_code = (1U << 2),
		f_lang_pack_version = (1U << 2),
		f_base_lang_pack_version = (1U << 2),

		MAX_FIELD = (1U << 13),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDhelp_appUpdate {
	enum class Flag : uint32 {
		f_can_not_skip = (1U << 0),
		f_document = (1U << 1),
		f_url = (1U << 2),
		f_sticker = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDencryptedChatRequested {
	enum class Flag : uint32 {
		f_folder_id = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDencryptedChatDiscarded {
	enum class Flag : uint32 {
		f_history_deleted = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDdocument {
	enum class Flag : uint32 {
		f_thumbs = (1U << 0),
		f_video_thumbs = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDdocumentAttributeSticker {
	enum class Flag : uint32 {
		f_mask = (1U << 1),
		f_mask_coords = (1U << 0),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDdocumentAttributeVideo {
	enum class Flag : uint32 {
		f_round_message = (1U << 0),
		f_supports_streaming = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDdocumentAttributeAudio {
	enum class Flag : uint32 {
		f_voice = (1U << 10),
		f_title = (1U << 0),
		f_performer = (1U << 1),
		f_waveform = (1U << 2),

		MAX_FIELD = (1U << 10),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDwebPage {
	enum class Flag : uint32 {
		f_type = (1U << 0),
		f_site_name = (1U << 1),
		f_title = (1U << 2),
		f_description = (1U << 3),
		f_photo = (1U << 4),
		f_embed_url = (1U << 5),
		f_embed_type = (1U << 5),
		f_embed_width = (1U << 6),
		f_embed_height = (1U << 6),
		f_duration = (1U << 7),
		f_author = (1U << 8),
		f_document = (1U << 9),
		f_cached_page = (1U << 10),
		f_attributes = (1U << 12),

		MAX_FIELD = (1U << 12),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDwebPageNotModified {
	enum class Flag : uint32 {
		f_cached_page_views = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDauthorization {
	enum class Flag : uint32 {
		f_current = (1U << 0),
		f_official_app = (1U << 1),
		f_password_pending = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDaccount_password {
	enum class Flag : uint32 {
		f_has_recovery = (1U << 0),
		f_has_secure_values = (1U << 1),
		f_has_password = (1U << 2),
		f_current_algo = (1U << 2),
		f_srp_B = (1U << 2),
		f_srp_id = (1U << 2),
		f_hint = (1U << 3),
		f_email_unconfirmed_pattern = (1U << 4),
		f_pending_reset_date = (1U << 5),

		MAX_FIELD = (1U << 5),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDaccount_passwordSettings {
	enum class Flag : uint32 {
		f_email = (1U << 0),
		f_secure_settings = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDaccount_passwordInputSettings {
	enum class Flag : uint32 {
		f_new_algo = (1U << 0),
		f_new_password_hash = (1U << 0),
		f_hint = (1U << 0),
		f_email = (1U << 1),
		f_new_secure_settings = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchatInviteExported {
	enum class Flag : uint32 {
		f_revoked = (1U << 0),
		f_permanent = (1U << 5),
		f_start_date = (1U << 4),
		f_expire_date = (1U << 1),
		f_usage_limit = (1U << 2),
		f_usage = (1U << 3),

		MAX_FIELD = (1U << 5),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchatInvite {
	enum class Flag : uint32 {
		f_channel = (1U << 0),
		f_broadcast = (1U << 1),
		f_public = (1U << 2),
		f_megagroup = (1U << 3),
		f_participants = (1U << 4),

		MAX_FIELD = (1U << 4),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDstickerSet {
	enum class Flag : uint32 {
		f_archived = (1U << 1),
		f_official = (1U << 2),
		f_masks = (1U << 3),
		f_animated = (1U << 5),
		f_installed_date = (1U << 0),
		f_thumbs = (1U << 4),
		f_thumb_dc_id = (1U << 4),
		f_thumb_version = (1U << 4),

		MAX_FIELD = (1U << 5),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDkeyboardButtonCallback {
	enum class Flag : uint32 {
		f_requires_password = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDkeyboardButtonSwitchInline {
	enum class Flag : uint32 {
		f_same_peer = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDkeyboardButtonUrlAuth {
	enum class Flag : uint32 {
		f_fwd_text = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputKeyboardButtonUrlAuth {
	enum class Flag : uint32 {
		f_request_write_access = (1U << 0),
		f_fwd_text = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDkeyboardButtonRequestPoll {
	enum class Flag : uint32 {
		f_quiz = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDreplyKeyboardHide {
	enum class Flag : uint32 {
		f_selective = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDreplyKeyboardForceReply {
	enum class Flag : uint32 {
		f_single_use = (1U << 1),
		f_selective = (1U << 2),
		f_placeholder = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDreplyKeyboardMarkup {
	enum class Flag : uint32 {
		f_resize = (1U << 0),
		f_single_use = (1U << 1),
		f_selective = (1U << 2),
		f_placeholder = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdates_channelDifferenceEmpty {
	enum class Flag : uint32 {
		f_final = (1U << 0),
		f_timeout = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdates_channelDifferenceTooLong {
	enum class Flag : uint32 {
		f_final = (1U << 0),
		f_timeout = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDupdates_channelDifference {
	enum class Flag : uint32 {
		f_final = (1U << 0),
		f_timeout = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchannelMessagesFilter {
	enum class Flag : uint32 {
		f_exclude_new_messages = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchannelParticipantCreator {
	enum class Flag : uint32 {
		f_rank = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchannelParticipantAdmin {
	enum class Flag : uint32 {
		f_can_edit = (1U << 0),
		f_self = (1U << 1),
		f_inviter_id = (1U << 1),
		f_rank = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchannelParticipantBanned {
	enum class Flag : uint32 {
		f_left = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchannelParticipantsMentions {
	enum class Flag : uint32 {
		f_q = (1U << 0),
		f_top_msg_id = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDhelp_termsOfService {
	enum class Flag : uint32 {
		f_popup = (1U << 0),
		f_min_age_confirm = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputBotInlineMessageMediaAuto {
	enum class Flag : uint32 {
		f_entities = (1U << 1),
		f_reply_markup = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputBotInlineMessageText {
	enum class Flag : uint32 {
		f_no_webpage = (1U << 0),
		f_entities = (1U << 1),
		f_reply_markup = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputBotInlineMessageMediaGeo {
	enum class Flag : uint32 {
		f_heading = (1U << 0),
		f_period = (1U << 1),
		f_proximity_notification_radius = (1U << 3),
		f_reply_markup = (1U << 2),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputBotInlineMessageMediaVenue {
	enum class Flag : uint32 {
		f_reply_markup = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputBotInlineMessageMediaContact {
	enum class Flag : uint32 {
		f_reply_markup = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputBotInlineMessageGame {
	enum class Flag : uint32 {
		f_reply_markup = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputBotInlineMessageMediaInvoice {
	enum class Flag : uint32 {
		f_photo = (1U << 0),
		f_reply_markup = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputBotInlineResult {
	enum class Flag : uint32 {
		f_title = (1U << 1),
		f_description = (1U << 2),
		f_url = (1U << 3),
		f_thumb = (1U << 4),
		f_content = (1U << 5),

		MAX_FIELD = (1U << 5),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputBotInlineResultDocument {
	enum class Flag : uint32 {
		f_title = (1U << 1),
		f_description = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDbotInlineMessageMediaAuto {
	enum class Flag : uint32 {
		f_entities = (1U << 1),
		f_reply_markup = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDbotInlineMessageText {
	enum class Flag : uint32 {
		f_no_webpage = (1U << 0),
		f_entities = (1U << 1),
		f_reply_markup = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDbotInlineMessageMediaGeo {
	enum class Flag : uint32 {
		f_heading = (1U << 0),
		f_period = (1U << 1),
		f_proximity_notification_radius = (1U << 3),
		f_reply_markup = (1U << 2),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDbotInlineMessageMediaVenue {
	enum class Flag : uint32 {
		f_reply_markup = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDbotInlineMessageMediaContact {
	enum class Flag : uint32 {
		f_reply_markup = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDbotInlineMessageMediaInvoice {
	enum class Flag : uint32 {
		f_shipping_address_requested = (1U << 1),
		f_test = (1U << 3),
		f_photo = (1U << 0),
		f_reply_markup = (1U << 2),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDbotInlineResult {
	enum class Flag : uint32 {
		f_title = (1U << 1),
		f_description = (1U << 2),
		f_url = (1U << 3),
		f_thumb = (1U << 4),
		f_content = (1U << 5),

		MAX_FIELD = (1U << 5),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDbotInlineMediaResult {
	enum class Flag : uint32 {
		f_photo = (1U << 0),
		f_document = (1U << 1),
		f_title = (1U << 2),
		f_description = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessages_botResults {
	enum class Flag : uint32 {
		f_gallery = (1U << 0),
		f_next_offset = (1U << 1),
		f_switch_pm = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessageFwdHeader {
	enum class Flag : uint32 {
		f_imported = (1U << 7),
		f_from_id = (1U << 0),
		f_from_name = (1U << 5),
		f_channel_post = (1U << 2),
		f_post_author = (1U << 3),
		f_saved_from_peer = (1U << 4),
		f_saved_from_msg_id = (1U << 4),
		f_psa_type = (1U << 6),

		MAX_FIELD = (1U << 7),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessages_botCallbackAnswer {
	enum class Flag : uint32 {
		f_alert = (1U << 1),
		f_has_url = (1U << 3),
		f_native_ui = (1U << 4),
		f_message = (1U << 0),
		f_url = (1U << 2),

		MAX_FIELD = (1U << 4),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessages_messageEditData {
	enum class Flag : uint32 {
		f_caption = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDdraftMessageEmpty {
	enum class Flag : uint32 {
		f_date = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDdraftMessage {
	enum class Flag : uint32 {
		f_no_webpage = (1U << 1),
		f_reply_to_msg_id = (1U << 0),
		f_entities = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDgame {
	enum class Flag : uint32 {
		f_document = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpageBlockPhoto {
	enum class Flag : uint32 {
		f_url = (1U << 0),
		f_webpage_id = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpageBlockVideo {
	enum class Flag : uint32 {
		f_autoplay = (1U << 0),
		f_loop = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpageBlockEmbed {
	enum class Flag : uint32 {
		f_full_width = (1U << 0),
		f_allow_scrolling = (1U << 3),
		f_url = (1U << 1),
		f_html = (1U << 2),
		f_poster_photo_id = (1U << 4),
		f_w = (1U << 5),
		f_h = (1U << 5),

		MAX_FIELD = (1U << 5),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpageBlockTable {
	enum class Flag : uint32 {
		f_bordered = (1U << 0),
		f_striped = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpageBlockDetails {
	enum class Flag : uint32 {
		f_open = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinvoice {
	enum class Flag : uint32 {
		f_test = (1U << 0),
		f_name_requested = (1U << 1),
		f_phone_requested = (1U << 2),
		f_email_requested = (1U << 3),
		f_shipping_address_requested = (1U << 4),
		f_flexible = (1U << 5),
		f_phone_to_provider = (1U << 6),
		f_email_to_provider = (1U << 7),
		f_max_tip_amount = (1U << 8),
		f_suggested_tip_amounts = (1U << 8),

		MAX_FIELD = (1U << 8),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpaymentRequestedInfo {
	enum class Flag : uint32 {
		f_name = (1U << 0),
		f_phone = (1U << 1),
		f_email = (1U << 2),
		f_shipping_address = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpayments_paymentForm {
	enum class Flag : uint32 {
		f_can_save_credentials = (1U << 2),
		f_password_missing = (1U << 3),
		f_native_provider = (1U << 4),
		f_native_params = (1U << 4),
		f_saved_info = (1U << 0),
		f_saved_credentials = (1U << 1),

		MAX_FIELD = (1U << 4),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpayments_validatedRequestedInfo {
	enum class Flag : uint32 {
		f_id = (1U << 0),
		f_shipping_options = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpayments_paymentReceipt {
	enum class Flag : uint32 {
		f_photo = (1U << 2),
		f_info = (1U << 0),
		f_shipping = (1U << 1),
		f_tip_amount = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpayments_savedInfo {
	enum class Flag : uint32 {
		f_has_saved_credentials = (1U << 1),
		f_saved_info = (1U << 0),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputPaymentCredentials {
	enum class Flag : uint32 {
		f_save = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputStickerSetItem {
	enum class Flag : uint32 {
		f_mask_coords = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDphoneCallWaiting {
	enum class Flag : uint32 {
		f_video = (1U << 6),
		f_receive_date = (1U << 0),

		MAX_FIELD = (1U << 6),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDphoneCallRequested {
	enum class Flag : uint32 {
		f_video = (1U << 6),

		MAX_FIELD = (1U << 6),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDphoneCallAccepted {
	enum class Flag : uint32 {
		f_video = (1U << 6),

		MAX_FIELD = (1U << 6),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDphoneCall {
	enum class Flag : uint32 {
		f_p2p_allowed = (1U << 5),
		f_video = (1U << 6),

		MAX_FIELD = (1U << 6),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDphoneCallDiscarded {
	enum class Flag : uint32 {
		f_need_rating = (1U << 2),
		f_need_debug = (1U << 3),
		f_video = (1U << 6),
		f_reason = (1U << 0),
		f_duration = (1U << 1),

		MAX_FIELD = (1U << 6),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDphoneConnectionWebrtc {
	enum class Flag : uint32 {
		f_turn = (1U << 0),
		f_stun = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDphoneCallProtocol {
	enum class Flag : uint32 {
		f_udp_p2p = (1U << 0),
		f_udp_reflector = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDlangPackStringPluralized {
	enum class Flag : uint32 {
		f_zero_value = (1U << 0),
		f_one_value = (1U << 1),
		f_two_value = (1U << 2),
		f_few_value = (1U << 3),
		f_many_value = (1U << 4),

		MAX_FIELD = (1U << 4),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDlangPackLanguage {
	enum class Flag : uint32 {
		f_official = (1U << 0),
		f_rtl = (1U << 2),
		f_beta = (1U << 3),
		f_base_lang_code = (1U << 1),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchannelAdminLogEventsFilter {
	enum class Flag : uint32 {
		f_join = (1U << 0),
		f_leave = (1U << 1),
		f_invite = (1U << 2),
		f_ban = (1U << 3),
		f_unban = (1U << 4),
		f_kick = (1U << 5),
		f_unkick = (1U << 6),
		f_promote = (1U << 7),
		f_demote = (1U << 8),
		f_info = (1U << 9),
		f_settings = (1U << 10),
		f_pinned = (1U << 11),
		f_edit = (1U << 12),
		f_delete = (1U << 13),
		f_group_call = (1U << 14),
		f_invites = (1U << 15),

		MAX_FIELD = (1U << 15),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputSingleMedia {
	enum class Flag : uint32 {
		f_entities = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDsecureValue {
	enum class Flag : uint32 {
		f_data = (1U << 0),
		f_front_side = (1U << 1),
		f_reverse_side = (1U << 2),
		f_selfie = (1U << 3),
		f_translation = (1U << 6),
		f_files = (1U << 4),
		f_plain_data = (1U << 5),

		MAX_FIELD = (1U << 6),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputSecureValue {
	enum class Flag : uint32 {
		f_data = (1U << 0),
		f_front_side = (1U << 1),
		f_reverse_side = (1U << 2),
		f_selfie = (1U << 3),
		f_translation = (1U << 6),
		f_files = (1U << 4),
		f_plain_data = (1U << 5),

		MAX_FIELD = (1U << 6),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDaccount_authorizationForm {
	enum class Flag : uint32 {
		f_privacy_policy_url = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDhelp_deepLinkInfo {
	enum class Flag : uint32 {
		f_update_app = (1U << 0),
		f_entities = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDsecureRequiredType {
	enum class Flag : uint32 {
		f_native_names = (1U << 0),
		f_selfie_required = (1U << 1),
		f_translation_required = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpageTableCell {
	enum class Flag : uint32 {
		f_header = (1U << 0),
		f_align_center = (1U << 3),
		f_align_right = (1U << 4),
		f_valign_middle = (1U << 5),
		f_valign_bottom = (1U << 6),
		f_text = (1U << 7),
		f_colspan = (1U << 1),
		f_rowspan = (1U << 2),

		MAX_FIELD = (1U << 7),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpageRelatedArticle {
	enum class Flag : uint32 {
		f_title = (1U << 0),
		f_description = (1U << 1),
		f_photo_id = (1U << 2),
		f_author = (1U << 3),
		f_published_date = (1U << 4),

		MAX_FIELD = (1U << 4),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpage {
	enum class Flag : uint32 {
		f_part = (1U << 0),
		f_rtl = (1U << 1),
		f_v2 = (1U << 2),
		f_views = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpoll {
	enum class Flag : uint32 {
		f_closed = (1U << 0),
		f_public_voters = (1U << 1),
		f_multiple_choice = (1U << 2),
		f_quiz = (1U << 3),
		f_close_period = (1U << 4),
		f_close_date = (1U << 5),

		MAX_FIELD = (1U << 5),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpollAnswerVoters {
	enum class Flag : uint32 {
		f_chosen = (1U << 0),
		f_correct = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDpollResults {
	enum class Flag : uint32 {
		f_min = (1U << 0),
		f_results = (1U << 1),
		f_total_voters = (1U << 2),
		f_recent_voters = (1U << 3),
		f_solution = (1U << 4),
		f_solution_entities = (1U << 4),

		MAX_FIELD = (1U << 4),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchatAdminRights {
	enum class Flag : uint32 {
		f_change_info = (1U << 0),
		f_post_messages = (1U << 1),
		f_edit_messages = (1U << 2),
		f_delete_messages = (1U << 3),
		f_ban_users = (1U << 4),
		f_invite_users = (1U << 5),
		f_pin_messages = (1U << 7),
		f_add_admins = (1U << 9),
		f_anonymous = (1U << 10),
		f_manage_call = (1U << 11),
		f_other = (1U << 12),

		MAX_FIELD = (1U << 12),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDchatBannedRights {
	enum class Flag : uint32 {
		f_view_messages = (1U << 0),
		f_send_messages = (1U << 1),
		f_send_media = (1U << 2),
		f_send_stickers = (1U << 3),
		f_send_gifs = (1U << 4),
		f_send_games = (1U << 5),
		f_send_inline = (1U << 6),
		f_embed_links = (1U << 7),
		f_send_polls = (1U << 8),
		f_change_info = (1U << 10),
		f_invite_users = (1U << 15),
		f_pin_messages = (1U << 17),

		MAX_FIELD = (1U << 17),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDcodeSettings {
	enum class Flag : uint32 {
		f_allow_flashcall = (1U << 0),
		f_current_number = (1U << 1),
		f_allow_app_hash = (1U << 4),

		MAX_FIELD = (1U << 4),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDwallPaperSettings {
	enum class Flag : uint32 {
		f_blur = (1U << 1),
		f_motion = (1U << 2),
		f_background_color = (1U << 0),
		f_second_background_color = (1U << 4),
		f_third_background_color = (1U << 5),
		f_fourth_background_color = (1U << 6),
		f_intensity = (1U << 3),
		f_rotation = (1U << 4),

		MAX_FIELD = (1U << 6),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDautoDownloadSettings {
	enum class Flag : uint32 {
		f_disabled = (1U << 0),
		f_video_preload_large = (1U << 1),
		f_audio_preload_next = (1U << 2),
		f_phonecalls_less_data = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDfolder {
	enum class Flag : uint32 {
		f_autofill_new_broadcasts = (1U << 0),
		f_autofill_public_groups = (1U << 1),
		f_autofill_new_correspondents = (1U << 2),
		f_photo = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessages_searchCounter {
	enum class Flag : uint32 {
		f_inexact = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDurlAuthResultRequest {
	enum class Flag : uint32 {
		f_request_write_access = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDtheme {
	enum class Flag : uint32 {
		f_creator = (1U << 0),
		f_default = (1U << 1),
		f_for_chat = (1U << 5),
		f_document = (1U << 2),
		f_settings = (1U << 3),
		f_installs_count = (1U << 4),

		MAX_FIELD = (1U << 5),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDaccount_contentSettings {
	enum class Flag : uint32 {
		f_sensitive_enabled = (1U << 0),
		f_sensitive_can_change = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDinputThemeSettings {
	enum class Flag : uint32 {
		f_message_colors_animated = (1U << 2),
		f_message_colors = (1U << 0),
		f_wallpaper = (1U << 1),
		f_wallpaper_settings = (1U << 1),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDthemeSettings {
	enum class Flag : uint32 {
		f_message_colors_animated = (1U << 2),
		f_message_colors = (1U << 0),
		f_wallpaper = (1U << 1),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDwebPageAttributeTheme {
	enum class Flag : uint32 {
		f_documents = (1U << 0),
		f_settings = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessages_votesList {
	enum class Flag : uint32 {
		f_next_offset = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDdialogFilter {
	enum class Flag : uint32 {
		f_contacts = (1U << 0),
		f_non_contacts = (1U << 1),
		f_groups = (1U << 2),
		f_broadcasts = (1U << 3),
		f_bots = (1U << 4),
		f_exclude_muted = (1U << 11),
		f_exclude_read = (1U << 12),
		f_exclude_archived = (1U << 13),
		f_emoticon = (1U << 25),

		MAX_FIELD = (1U << 25),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDstatsGraph {
	enum class Flag : uint32 {
		f_zoom_token = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDhelp_promoData {
	enum class Flag : uint32 {
		f_proxy = (1U << 0),
		f_psa_type = (1U << 1),
		f_psa_message = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDvideoSize {
	enum class Flag : uint32 {
		f_video_start_ts = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDglobalPrivacySettings {
	enum class Flag : uint32 {
		f_archive_and_mute_new_noncontact_peers = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDhelp_countryCode {
	enum class Flag : uint32 {
		f_prefixes = (1U << 0),
		f_patterns = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDhelp_country {
	enum class Flag : uint32 {
		f_hidden = (1U << 0),
		f_name = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessageViews {
	enum class Flag : uint32 {
		f_views = (1U << 0),
		f_forwards = (1U << 1),
		f_replies = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessages_discussionMessage {
	enum class Flag : uint32 {
		f_max_id = (1U << 0),
		f_read_inbox_max_id = (1U << 1),
		f_read_outbox_max_id = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessageReplyHeader {
	enum class Flag : uint32 {
		f_reply_to_peer_id = (1U << 0),
		f_reply_to_top_id = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessageReplies {
	enum class Flag : uint32 {
		f_comments = (1U << 0),
		f_recent_repliers = (1U << 1),
		f_channel_id = (1U << 0),
		f_max_id = (1U << 2),
		f_read_max_id = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDgroupCall {
	enum class Flag : uint32 {
		f_join_muted = (1U << 1),
		f_can_change_join_muted = (1U << 2),
		f_join_date_asc = (1U << 6),
		f_schedule_start_subscribed = (1U << 8),
		f_can_start_video = (1U << 9),
		f_record_video_active = (1U << 11),
		f_title = (1U << 3),
		f_stream_dc_id = (1U << 4),
		f_record_start_date = (1U << 5),
		f_schedule_date = (1U << 7),
		f_unmuted_video_count = (1U << 10),

		MAX_FIELD = (1U << 11),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDgroupCallParticipant {
	enum class Flag : uint32 {
		f_muted = (1U << 0),
		f_left = (1U << 1),
		f_can_self_unmute = (1U << 2),
		f_just_joined = (1U << 4),
		f_versioned = (1U << 5),
		f_min = (1U << 8),
		f_muted_by_you = (1U << 9),
		f_volume_by_admin = (1U << 10),
		f_self = (1U << 12),
		f_video_joined = (1U << 15),
		f_active_date = (1U << 3),
		f_volume = (1U << 7),
		f_about = (1U << 11),
		f_raise_hand_rating = (1U << 13),
		f_video = (1U << 6),
		f_presentation = (1U << 14),

		MAX_FIELD = (1U << 15),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDmessages_historyImportParsed {
	enum class Flag : uint32 {
		f_pm = (1U << 0),
		f_group = (1U << 1),
		f_title = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDgroupCallParticipantVideo {
	enum class Flag : uint32 {
		f_paused = (1U << 0),
		f_audio_source = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPDsponsoredMessage {
	enum class Flag : uint32 {
		f_media = (1U << 0),
		f_entities = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
// RPC methods

struct MTPinitConnection { // RPC method 'initConnection'
	enum class Flag : uint32 {
		f_proxy = (1U << 0),
		f_params = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPauth_recoverPassword { // RPC method 'auth.recoverPassword'
	enum class Flag : uint32 {
		f_new_settings = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPaccount_registerDevice { // RPC method 'account.registerDevice'
	enum class Flag : uint32 {
		f_no_muted = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPaccount_updateProfile { // RPC method 'account.updateProfile'
	enum class Flag : uint32 {
		f_first_name = (1U << 0),
		f_last_name = (1U << 1),
		f_about = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPaccount_initTakeoutSession { // RPC method 'account.initTakeoutSession'
	enum class Flag : uint32 {
		f_contacts = (1U << 0),
		f_message_users = (1U << 1),
		f_message_chats = (1U << 2),
		f_message_megagroups = (1U << 3),
		f_message_channels = (1U << 4),
		f_files = (1U << 5),
		f_file_max_size = (1U << 5),

		MAX_FIELD = (1U << 5),
	};
	using Flags = base::flags<Flag>;
};
struct MTPaccount_finishTakeoutSession { // RPC method 'account.finishTakeoutSession'
	enum class Flag : uint32 {
		f_success = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPaccount_getNotifyExceptions { // RPC method 'account.getNotifyExceptions'
	enum class Flag : uint32 {
		f_compare_sound = (1U << 1),
		f_peer = (1U << 0),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPaccount_saveAutoDownloadSettings { // RPC method 'account.saveAutoDownloadSettings'
	enum class Flag : uint32 {
		f_low = (1U << 0),
		f_high = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPaccount_uploadTheme { // RPC method 'account.uploadTheme'
	enum class Flag : uint32 {
		f_thumb = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPaccount_createTheme { // RPC method 'account.createTheme'
	enum class Flag : uint32 {
		f_document = (1U << 2),
		f_settings = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPaccount_updateTheme { // RPC method 'account.updateTheme'
	enum class Flag : uint32 {
		f_slug = (1U << 0),
		f_title = (1U << 1),
		f_document = (1U << 2),
		f_settings = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPaccount_installTheme { // RPC method 'account.installTheme'
	enum class Flag : uint32 {
		f_dark = (1U << 0),
		f_format = (1U << 1),
		f_theme = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPaccount_setContentSettings { // RPC method 'account.setContentSettings'
	enum class Flag : uint32 {
		f_sensitive_enabled = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPcontacts_getTopPeers { // RPC method 'contacts.getTopPeers'
	enum class Flag : uint32 {
		f_correspondents = (1U << 0),
		f_bots_pm = (1U << 1),
		f_bots_inline = (1U << 2),
		f_phone_calls = (1U << 3),
		f_forward_users = (1U << 4),
		f_forward_chats = (1U << 5),
		f_groups = (1U << 10),
		f_channels = (1U << 15),

		MAX_FIELD = (1U << 15),
	};
	using Flags = base::flags<Flag>;
};
struct MTPcontacts_addContact { // RPC method 'contacts.addContact'
	enum class Flag : uint32 {
		f_add_phone_privacy_exception = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPcontacts_getLocated { // RPC method 'contacts.getLocated'
	enum class Flag : uint32 {
		f_background = (1U << 1),
		f_self_expires = (1U << 0),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPcontacts_blockFromReplies { // RPC method 'contacts.blockFromReplies'
	enum class Flag : uint32 {
		f_delete_message = (1U << 0),
		f_delete_history = (1U << 1),
		f_report_spam = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_getDialogs { // RPC method 'messages.getDialogs'
	enum class Flag : uint32 {
		f_exclude_pinned = (1U << 0),
		f_folder_id = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_search { // RPC method 'messages.search'
	enum class Flag : uint32 {
		f_from_id = (1U << 0),
		f_top_msg_id = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_deleteHistory { // RPC method 'messages.deleteHistory'
	enum class Flag : uint32 {
		f_just_clear = (1U << 0),
		f_revoke = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_deleteMessages { // RPC method 'messages.deleteMessages'
	enum class Flag : uint32 {
		f_revoke = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_setTyping { // RPC method 'messages.setTyping'
	enum class Flag : uint32 {
		f_top_msg_id = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_sendMessage { // RPC method 'messages.sendMessage'
	enum class Flag : uint32 {
		f_no_webpage = (1U << 1),
		f_silent = (1U << 5),
		f_background = (1U << 6),
		f_clear_draft = (1U << 7),
		f_reply_to_msg_id = (1U << 0),
		f_reply_markup = (1U << 2),
		f_entities = (1U << 3),
		f_schedule_date = (1U << 10),

		MAX_FIELD = (1U << 10),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_sendMedia { // RPC method 'messages.sendMedia'
	enum class Flag : uint32 {
		f_silent = (1U << 5),
		f_background = (1U << 6),
		f_clear_draft = (1U << 7),
		f_reply_to_msg_id = (1U << 0),
		f_reply_markup = (1U << 2),
		f_entities = (1U << 3),
		f_schedule_date = (1U << 10),

		MAX_FIELD = (1U << 10),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_forwardMessages { // RPC method 'messages.forwardMessages'
	enum class Flag : uint32 {
		f_silent = (1U << 5),
		f_background = (1U << 6),
		f_with_my_score = (1U << 8),
		f_drop_author = (1U << 11),
		f_drop_media_captions = (1U << 12),
		f_schedule_date = (1U << 10),

		MAX_FIELD = (1U << 12),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_deleteChatUser { // RPC method 'messages.deleteChatUser'
	enum class Flag : uint32 {
		f_revoke_history = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_discardEncryption { // RPC method 'messages.discardEncryption'
	enum class Flag : uint32 {
		f_delete_history = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_sendEncrypted { // RPC method 'messages.sendEncrypted'
	enum class Flag : uint32 {
		f_silent = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_sendEncryptedFile { // RPC method 'messages.sendEncryptedFile'
	enum class Flag : uint32 {
		f_silent = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_getWebPagePreview { // RPC method 'messages.getWebPagePreview'
	enum class Flag : uint32 {
		f_entities = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_exportChatInvite { // RPC method 'messages.exportChatInvite'
	enum class Flag : uint32 {
		f_legacy_revoke_permanent = (1U << 2),
		f_expire_date = (1U << 0),
		f_usage_limit = (1U << 1),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_searchGlobal { // RPC method 'messages.searchGlobal'
	enum class Flag : uint32 {
		f_folder_id = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_reorderStickerSets { // RPC method 'messages.reorderStickerSets'
	enum class Flag : uint32 {
		f_masks = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_getInlineBotResults { // RPC method 'messages.getInlineBotResults'
	enum class Flag : uint32 {
		f_geo_point = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_setInlineBotResults { // RPC method 'messages.setInlineBotResults'
	enum class Flag : uint32 {
		f_gallery = (1U << 0),
		f_private = (1U << 1),
		f_next_offset = (1U << 2),
		f_switch_pm = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_sendInlineBotResult { // RPC method 'messages.sendInlineBotResult'
	enum class Flag : uint32 {
		f_silent = (1U << 5),
		f_background = (1U << 6),
		f_clear_draft = (1U << 7),
		f_hide_via = (1U << 11),
		f_reply_to_msg_id = (1U << 0),
		f_schedule_date = (1U << 10),

		MAX_FIELD = (1U << 11),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_editMessage { // RPC method 'messages.editMessage'
	enum class Flag : uint32 {
		f_no_webpage = (1U << 1),
		f_message = (1U << 11),
		f_media = (1U << 14),
		f_reply_markup = (1U << 2),
		f_entities = (1U << 3),
		f_schedule_date = (1U << 15),

		MAX_FIELD = (1U << 15),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_editInlineBotMessage { // RPC method 'messages.editInlineBotMessage'
	enum class Flag : uint32 {
		f_no_webpage = (1U << 1),
		f_message = (1U << 11),
		f_media = (1U << 14),
		f_reply_markup = (1U << 2),
		f_entities = (1U << 3),

		MAX_FIELD = (1U << 14),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_getBotCallbackAnswer { // RPC method 'messages.getBotCallbackAnswer'
	enum class Flag : uint32 {
		f_game = (1U << 1),
		f_data = (1U << 0),
		f_password = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_setBotCallbackAnswer { // RPC method 'messages.setBotCallbackAnswer'
	enum class Flag : uint32 {
		f_alert = (1U << 1),
		f_message = (1U << 0),
		f_url = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_saveDraft { // RPC method 'messages.saveDraft'
	enum class Flag : uint32 {
		f_no_webpage = (1U << 1),
		f_reply_to_msg_id = (1U << 0),
		f_entities = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_getRecentStickers { // RPC method 'messages.getRecentStickers'
	enum class Flag : uint32 {
		f_attached = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_saveRecentSticker { // RPC method 'messages.saveRecentSticker'
	enum class Flag : uint32 {
		f_attached = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_clearRecentStickers { // RPC method 'messages.clearRecentStickers'
	enum class Flag : uint32 {
		f_attached = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_getArchivedStickers { // RPC method 'messages.getArchivedStickers'
	enum class Flag : uint32 {
		f_masks = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_setGameScore { // RPC method 'messages.setGameScore'
	enum class Flag : uint32 {
		f_edit_message = (1U << 0),
		f_force = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_setInlineGameScore { // RPC method 'messages.setInlineGameScore'
	enum class Flag : uint32 {
		f_edit_message = (1U << 0),
		f_force = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_toggleDialogPin { // RPC method 'messages.toggleDialogPin'
	enum class Flag : uint32 {
		f_pinned = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_reorderPinnedDialogs { // RPC method 'messages.reorderPinnedDialogs'
	enum class Flag : uint32 {
		f_force = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_setBotShippingResults { // RPC method 'messages.setBotShippingResults'
	enum class Flag : uint32 {
		f_error = (1U << 0),
		f_shipping_options = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_setBotPrecheckoutResults { // RPC method 'messages.setBotPrecheckoutResults'
	enum class Flag : uint32 {
		f_success = (1U << 1),
		f_error = (1U << 0),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_sendMultiMedia { // RPC method 'messages.sendMultiMedia'
	enum class Flag : uint32 {
		f_silent = (1U << 5),
		f_background = (1U << 6),
		f_clear_draft = (1U << 7),
		f_reply_to_msg_id = (1U << 0),
		f_schedule_date = (1U << 10),

		MAX_FIELD = (1U << 10),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_searchStickerSets { // RPC method 'messages.searchStickerSets'
	enum class Flag : uint32 {
		f_exclude_featured = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_markDialogUnread { // RPC method 'messages.markDialogUnread'
	enum class Flag : uint32 {
		f_unread = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_updatePinnedMessage { // RPC method 'messages.updatePinnedMessage'
	enum class Flag : uint32 {
		f_silent = (1U << 0),
		f_unpin = (1U << 1),
		f_pm_oneside = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_getStatsURL { // RPC method 'messages.getStatsURL'
	enum class Flag : uint32 {
		f_dark = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_requestUrlAuth { // RPC method 'messages.requestUrlAuth'
	enum class Flag : uint32 {
		f_peer = (1U << 1),
		f_msg_id = (1U << 1),
		f_button_id = (1U << 1),
		f_url = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_acceptUrlAuth { // RPC method 'messages.acceptUrlAuth'
	enum class Flag : uint32 {
		f_write_allowed = (1U << 0),
		f_peer = (1U << 1),
		f_msg_id = (1U << 1),
		f_button_id = (1U << 1),
		f_url = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_getPollVotes { // RPC method 'messages.getPollVotes'
	enum class Flag : uint32 {
		f_option = (1U << 0),
		f_offset = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_toggleStickerSets { // RPC method 'messages.toggleStickerSets'
	enum class Flag : uint32 {
		f_uninstall = (1U << 0),
		f_archive = (1U << 1),
		f_unarchive = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_updateDialogFilter { // RPC method 'messages.updateDialogFilter'
	enum class Flag : uint32 {
		f_filter = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_deletePhoneCallHistory { // RPC method 'messages.deletePhoneCallHistory'
	enum class Flag : uint32 {
		f_revoke = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_getExportedChatInvites { // RPC method 'messages.getExportedChatInvites'
	enum class Flag : uint32 {
		f_revoked = (1U << 3),
		f_offset_date = (1U << 2),
		f_offset_link = (1U << 2),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPmessages_editExportedChatInvite { // RPC method 'messages.editExportedChatInvite'
	enum class Flag : uint32 {
		f_revoked = (1U << 2),
		f_expire_date = (1U << 0),
		f_usage_limit = (1U << 1),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPupdates_getDifference { // RPC method 'updates.getDifference'
	enum class Flag : uint32 {
		f_pts_total_limit = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPupdates_getChannelDifference { // RPC method 'updates.getChannelDifference'
	enum class Flag : uint32 {
		f_force = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPphotos_uploadProfilePhoto { // RPC method 'photos.uploadProfilePhoto'
	enum class Flag : uint32 {
		f_file = (1U << 0),
		f_video = (1U << 1),
		f_video_start_ts = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPupload_getFile { // RPC method 'upload.getFile'
	enum class Flag : uint32 {
		f_precise = (1U << 0),
		f_cdn_supported = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPchannels_createChannel { // RPC method 'channels.createChannel'
	enum class Flag : uint32 {
		f_broadcast = (1U << 0),
		f_megagroup = (1U << 1),
		f_for_import = (1U << 3),
		f_geo_point = (1U << 2),
		f_address = (1U << 2),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPchannels_exportMessageLink { // RPC method 'channels.exportMessageLink'
	enum class Flag : uint32 {
		f_grouped = (1U << 0),
		f_thread = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPchannels_getAdminedPublicChannels { // RPC method 'channels.getAdminedPublicChannels'
	enum class Flag : uint32 {
		f_by_location = (1U << 0),
		f_check_limit = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPchannels_getAdminLog { // RPC method 'channels.getAdminLog'
	enum class Flag : uint32 {
		f_events_filter = (1U << 0),
		f_admins = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPpayments_getPaymentForm { // RPC method 'payments.getPaymentForm'
	enum class Flag : uint32 {
		f_theme_params = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPpayments_validateRequestedInfo { // RPC method 'payments.validateRequestedInfo'
	enum class Flag : uint32 {
		f_save = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPpayments_sendPaymentForm { // RPC method 'payments.sendPaymentForm'
	enum class Flag : uint32 {
		f_requested_info_id = (1U << 0),
		f_shipping_option_id = (1U << 1),
		f_tip_amount = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPpayments_clearSavedInfo { // RPC method 'payments.clearSavedInfo'
	enum class Flag : uint32 {
		f_credentials = (1U << 0),
		f_info = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPstickers_createStickerSet { // RPC method 'stickers.createStickerSet'
	enum class Flag : uint32 {
		f_masks = (1U << 0),
		f_animated = (1U << 1),
		f_thumb = (1U << 2),
		f_software = (1U << 3),

		MAX_FIELD = (1U << 3),
	};
	using Flags = base::flags<Flag>;
};
struct MTPphone_requestCall { // RPC method 'phone.requestCall'
	enum class Flag : uint32 {
		f_video = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPphone_discardCall { // RPC method 'phone.discardCall'
	enum class Flag : uint32 {
		f_video = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPphone_setCallRating { // RPC method 'phone.setCallRating'
	enum class Flag : uint32 {
		f_user_initiative = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPphone_createGroupCall { // RPC method 'phone.createGroupCall'
	enum class Flag : uint32 {
		f_title = (1U << 0),
		f_schedule_date = (1U << 1),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPphone_joinGroupCall { // RPC method 'phone.joinGroupCall'
	enum class Flag : uint32 {
		f_muted = (1U << 0),
		f_video_stopped = (1U << 2),
		f_invite_hash = (1U << 1),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPphone_toggleGroupCallSettings { // RPC method 'phone.toggleGroupCallSettings'
	enum class Flag : uint32 {
		f_reset_invite_hash = (1U << 1),
		f_join_muted = (1U << 0),

		MAX_FIELD = (1U << 1),
	};
	using Flags = base::flags<Flag>;
};
struct MTPphone_toggleGroupCallRecord { // RPC method 'phone.toggleGroupCallRecord'
	enum class Flag : uint32 {
		f_start = (1U << 0),
		f_video = (1U << 2),
		f_title = (1U << 1),
		f_video_portrait = (1U << 2),

		MAX_FIELD = (1U << 2),
	};
	using Flags = base::flags<Flag>;
};
struct MTPphone_editGroupCallParticipant { // RPC method 'phone.editGroupCallParticipant'
	enum class Flag : uint32 {
		f_muted = (1U << 0),
		f_volume = (1U << 1),
		f_raise_hand = (1U << 2),
		f_video_stopped = (1U << 3),
		f_video_paused = (1U << 4),
		f_presentation_paused = (1U << 5),

		MAX_FIELD = (1U << 5),
	};
	using Flags = base::flags<Flag>;
};
struct MTPphone_exportGroupCallInvite { // RPC method 'phone.exportGroupCallInvite'
	enum class Flag : uint32 {
		f_can_self_unmute = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPstats_getBroadcastStats { // RPC method 'stats.getBroadcastStats'
	enum class Flag : uint32 {
		f_dark = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPstats_loadAsyncGraph { // RPC method 'stats.loadAsyncGraph'
	enum class Flag : uint32 {
		f_x = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPstats_getMegagroupStats { // RPC method 'stats.getMegagroupStats'
	enum class Flag : uint32 {
		f_dark = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};
struct MTPstats_getMessageStats { // RPC method 'stats.getMessageStats'
	enum class Flag : uint32 {
		f_dark = (1U << 0),
		MAX_FIELD = (1U << 0),
	};
	using Flags = base::flags<Flag>;
};

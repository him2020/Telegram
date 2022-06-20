// account.registerDevice.layer71#637ea878 token_type:int token:string = Bool;
bool Serialize_account_registerDevice_71(DumpToTextBuffer &to, int32 stage, int32 lev, Types &types, Types &vtypes, Stages &stages, Flags &flags, const mtpPrime *start, const mtpPrime *end, uint64 iflag) {
    if (stage) {
        to.add(",\n").addSpaces(lev);
    } else {
        to.add("{ account.registerDevice_71");
        to.add("\n").addSpaces(lev);
    }
    switch (stage) {
        case 0: to.add("  token_type: "); ++stages.back(); types.push_back(mtpc_int+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
        case 1: to.add("  token: "); ++stages.back(); types.push_back(mtpc_string+0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
        default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
    }
    return true;
}

// channels.getMessages#93d7b347 channel:InputChannel id:Vector<int> = messages.Messages;
bool Serialize_channels_getMessages_76(DumpToTextBuffer &to, int32 stage, int32 lev, Types &types, Types &vtypes, Stages &stages, Flags &flags, const mtpPrime *start, const mtpPrime *end, uint64 iflag) {
    if (stage) {
        to.add(",\n").addSpaces(lev);
    } else {
        to.add("{ channels.getMessages_76");
        to.add("\n").addSpaces(lev);
    }
    switch (stage) {
        case 0: to.add("  channel: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
        case 1: to.add("  id: "); ++stages.back(); types.push_back(0); vtypes.push_back(mtpc_int+0); stages.push_back(0); flags.push_back(0); break;
        default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
    }
    return true;
}

bool Serialize_messages_getStickerSet_134(DumpToTextBuffer &to, int32 stage, int32 lev, Types &types, Types &vtypes, Stages &stages, Flags &flags, const mtpPrime *start, const mtpPrime *end, uint64 iflag) {
    if (stage) {
        to.add(",\n").addSpaces(lev);
    } else {
        to.add("{ messages_getStickerSet_134");
        to.add("\n").addSpaces(lev);
    }
    switch (stage) {
        case 0: to.add("  stickerset: "); ++stages.back(); types.push_back(0); vtypes.push_back(0); stages.push_back(0); flags.push_back(0); break;
        default: to.add("}"); types.pop_back(); vtypes.pop_back(); stages.pop_back(); flags.pop_back(); break;
    }
    return true;
}

std::map<mtpTypeId, TextSerializer> CreateCompatibleTextSerializers() {
    return {
            {mtpc_account_registerDevice_71, Serialize_account_registerDevice_71},
            {mtpc_channels_getMessages_76, Serialize_channels_getMessages_76},
            {mtpc_messages_getStickerSet_134, Serialize_messages_getStickerSet_134},
    };
}

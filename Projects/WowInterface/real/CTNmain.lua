local addonName, configTable = ...; --传参

local GSCD = GetSpellCooldown; --wowAPI 获得CD信息 返回4个number
local SCM = SendChatMessage; --wowAPI 发送聊天讯息
local nowGConfig = GetLocalGConfig();
local nowPConfig = GetLocalPConfig();

--[[
配置表架构
globalConfig
{
    windowLength = 100;
    singleLineHight = 20;
    opacity = 1;
    anchorX = 0;
    anchorY = 0;
}
personalConfig
{
    spellList = {};
    MessageChannel;
    messa;
}
]]--

function GetDefaultGConfig()--返回一个缺省全局配置
    local defaultConfig = {
        windowLength = 100;
        singleLineHight = 20;
        opacity = 1;
        anchorX = 0;
        anchorY = 0;
    }
    return defaultConfig;
end

function GetDefaultPConfig()--返回一个缺省个人配置
    local _messa = {};
    if GetLocale() == "zhCN" then
        _messa.CDing = "%s 尚未冷却完成"
        _messa.CD = "冷却时间剩余:"
        _messa.CDOver = "%s 已经准备好了"
    elseif GetLocale() == "zhTW" then
        _messa.CDing = "%s 尚未冷却完成"
        _messa.CD = "冷却时间剩余:"
        _messa.CDOver = "%s 已经准备好了"
    else
        _messa.CDing = "%s 尚未冷却完成"
        _messa.CD = "冷却时间剩余:"
        _messa.CDOver = "%s cooldown complete!"
    end

    local defaultConfig = {
        spellList = {};
        MessageChannel = "YELL";
        messa = _messa;
    }
    return defaultConfig;
end

function GetLocalGConfig()--获取储存在默认配置文件中的全局配置表，并返回
    local tempConfig;
    if not CTNGlobalConfig then
        tempConfig = GetDefaultGConfig();
    else
        tempConfig = CTNGlobalConfig;
    end
    return tempConfig;
end

function GetLocalPConfig() --获取储存在默认配置文件中的个人配置表，并返回
    local tempConfig;
    if not CTGPersonalConfig then
        tempConfig = GetDefaultGConfig();
    else
        tempConfig = CTGPersonalConfig;
    end
    return tempConfig;
end

function GetCoolAndNoti(spellID) --核心功能函数，获取CD信息并以聊天讯息形式发出
    local sendingMessa = "";
    if not spellID then
        return
    end
    local startTime, totalTime, state, modRate = GSCD(spellID, "spell");
    if startTime == 0 and totalTime == 0 then
        sendingMessa = sendingMessa .. format(nowPConfig.messa.CDOver, spellID);
    else
        local remainTime = (totalTime - startTime) .. "s";
        sendingMessa = sendingMessa .. format(nowPConfig.messa.CDing, spellID) .. nowPConfig.messa.CD .. remainTime;
    end
    SCM(sendingMessa, nowPConfig.MessageChannel);
    return;
end

--function AddSpelltoList(spellID)
--TODO
--end

local frm = CreateFrame("Frame");
frame:SetScript("OnEvent", function (self, event, ...)
    if type( self[event] ) == "function" then return self[ event ] ( self, ... ) end
end)

frm:RegisterEvent("ADDON_LOADED");
function frm: ADDON_LOADED( name )
    if name == addonName then
        nowGConfig = GetLocalGConfig();
        nowPConfig = GetLocalPConfig();
    end
end

SLASH_CMDIN1 = "/ctn"

SlashCmdList.CMDIN = function(mag, input)
    GetCoolAndNoti(mag);
end
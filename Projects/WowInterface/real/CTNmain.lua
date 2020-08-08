local addonName, configTable = ...; --����

local GSCD = GetSpellCooldown; --wowAPI ���CD��Ϣ ����4��number
local SCM = SendChatMessage; --wowAPI ��������ѶϢ
local nowGConfig = GetLocalGConfig();
local nowPConfig = GetLocalPConfig();

--[[
���ñ�ܹ�
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

function GetDefaultGConfig()--����һ��ȱʡȫ������
    local defaultConfig = {
        windowLength = 100;
        singleLineHight = 20;
        opacity = 1;
        anchorX = 0;
        anchorY = 0;
    }
    return defaultConfig;
end

function GetDefaultPConfig()--����һ��ȱʡ��������
    local _messa = {};
    if GetLocale() == "zhCN" then
        _messa.CDing = "%s ��δ��ȴ���"
        _messa.CD = "��ȴʱ��ʣ��:"
        _messa.CDOver = "%s �Ѿ�׼������"
    elseif GetLocale() == "zhTW" then
        _messa.CDing = "%s ��δ��ȴ���"
        _messa.CD = "��ȴʱ��ʣ��:"
        _messa.CDOver = "%s �Ѿ�׼������"
    else
        _messa.CDing = "%s ��δ��ȴ���"
        _messa.CD = "��ȴʱ��ʣ��:"
        _messa.CDOver = "%s cooldown complete!"
    end

    local defaultConfig = {
        spellList = {};
        MessageChannel = "YELL";
        messa = _messa;
    }
    return defaultConfig;
end

function GetLocalGConfig()--��ȡ������Ĭ�������ļ��е�ȫ�����ñ�������
    local tempConfig;
    if not CTNGlobalConfig then
        tempConfig = GetDefaultGConfig();
    else
        tempConfig = CTNGlobalConfig;
    end
    return tempConfig;
end

function GetLocalPConfig() --��ȡ������Ĭ�������ļ��еĸ������ñ�������
    local tempConfig;
    if not CTGPersonalConfig then
        tempConfig = GetDefaultGConfig();
    else
        tempConfig = CTGPersonalConfig;
    end
    return tempConfig;
end

function GetCoolAndNoti(spellID) --���Ĺ��ܺ�������ȡCD��Ϣ��������ѶϢ��ʽ����
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
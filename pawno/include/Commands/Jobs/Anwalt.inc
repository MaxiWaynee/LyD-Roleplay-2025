#include <YSI\y_hooks>


CMD:befreien(playerid, params[])
{
    if (Spieler[playerid][pJob] != 6) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Anwalt.");
    if (Spieler[playerid][pJailed] != 0) return SendClientMessage(playerid, COLOR_RED, "Du kannst niemanden befreien wenn du im Gefängnis bist.");

    new pID;
    if (sscanf(params, "u", pID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Befreien [SpielerID/Name]");
    if (pID == playerid) return SendClientMessage(playerid, COLOR_RED, "Du kannst dich natürlich nicht selbst befreien.");
    if (!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (Spieler[pID][pJailed] == 0) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht im Gefängnis.");
    if (Spieler[pID][pJailed] > 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Spieler nicht befreien.");

    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x, y, z);
    if (!IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z)) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");

    new message[145], unixtimeNow = gettime(), lawyerTimeout = 10 - (unixtimeNow - GetPVarInt(playerid, "LAWYER.RELEASE"));
    if (lawyerTimeout > 0) {
        if (lawyerTimeout == 1) message = "Du kannst erst in {FFFFFF}einer Sekunde {FBB420}wieder ein Befreiungsangebot stellen.";
        else format(message, sizeof (message), "Du kannst erst in {FFFFFF}%d Sekunden {FBB420}wieder ein Befreiungsangebot stellen.", lawyerTimeout);
        return SendClientMessage(playerid, COLOR_ORANGE, message);
    }

    new playerJailTimeout = JAIL_TIMEOUT - (unixtimeNow - GetPVarInt(pID, "JAIL.TIMESTAMP"));
    if (playerJailTimeout > 0) {
        if (playerJailTimeout == 1) message = "Der Spieler kann erst in {FFFFFF}einer Sekunde {FFFF00}befreit werden.";
        else format(message, sizeof(message), "Der Spieler kann erst in {FFFFFF}%d Sekunden {FFFF00}befreit werden.", playerJailTimeout);
        return SendClientMessage(playerid, COLOR_YELLOW, message);
    }

    if (Spieler[pID][pJailTime] > GetPlayerLawyerSkillValue(playerid)) {
        format(message,sizeof(message),"Dein Anwalt-Skill ist Level %d und damit kannst du nur Inhaftierte bis zu einer Haftzeit von %d Sekunden befreien.", GetPlayerLawyerLevel(playerid), GetPlayerLawyerSkillValue(playerid));
        return SendClientMessage(playerid, COLOR_ORANGE, message);
    }

    SetPVarInt(playerid, "LAWYER.RELEASE", unixtimeNow);
    new preis = floatround(Spieler[pID][pJailTime] / 60, floatround_ceil) * 280;
    format(message, sizeof(message), "* Anwalt %s hat dir eine Befreiung angeboten. (Preis: $%s)", GetName(playerid), AddDelimiters(preis));
    SendClientMessage(pID, COLOR_LIGHTBLUE, message);
    format(message, sizeof(message), "* Du hast %s eine Befreiung für $%s (40 Prozent Staatskosten) angeboten.", GetName(pID), AddDelimiters(preis));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, message);
    SendClientMessage(pID, COLOR_LIGHTBLUE, "Tippe nun '/Accept Anwalt' um die Befreiung anzunehmen.");
    AnwaltID[pID] = playerid;
    AnwaltPreis[pID] = floatround(Spieler[pID][pJailTime] / 60 * 200, floatround_ceil);
    return 1;
}



CMD:acceptanwalt(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Acceptanwalt [SpielerID/Name]");
    if(Spieler[playerid][pJob] != 6)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Anwalt!");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online!");
    if(NeedAWALT[pID] == 0)return SendClientMessage(playerid, COLOR_ORANGE, "Der Spieler benötigt keinen Anwalt. Verwende /sliste um die Service-Liste zu sehen.");
    format(string, sizeof(string), "* Du hast den Service-Anruf von %s angenommen, gehe nun ins LSPD und rede mit ihm!", GetName(pID));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "* Anwalt %s hat deinen Service-Anruf angenommen und ist nun unterwegs ins LSPD!", GetName(playerid));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    NeedAWALT[pID] = 0;
    return 1;
}



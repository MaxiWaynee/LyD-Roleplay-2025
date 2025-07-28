#include <YSI\y_hooks>



CMD:angelshop(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 3.0, FISHINGSHOP_COORDS))
    {
        ShowPlayerDialog(playerid, DIALOG_ASHOP, DIALOG_STYLE_LIST, "Angelshop", COLOR_HEX_WHITE"Angel kaufen "COLOR_HEX_ORANGE"($750)"COLOR_HEX_WHITE"\n10 Köder kaufen "COLOR_HEX_ORANGE"($100)"COLOR_HEX_WHITE"\nAngelschein kaufen "COLOR_HEX_ORANGE"($1.000)"COLOR_HEX_WHITE"\nFische verkaufen "COLOR_HEX_ORANGE"(40$ pro Fisch)", "Auswählen", "Abbrechen");
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Angelshop!");
    }
    return 1;
}


CMD:angeln(playerid, params[])
{
    new a = IsPlayerAtAngelPlatz(playerid);
    if(a == 999)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keinem Angelplatz.");
    if(Spieler[playerid][pAngel] == 0)return SendClientMessage(playerid, COLOR_ORANGE, "Du besitzt keine Angel, kaufe eine im Angelshop. Verwende /Navi -> Weitere Orte um diesen zu finden!");
    if(Spieler[playerid][pKoeder] == 0)return SendClientMessage(playerid, COLOR_ORANGE, "Du besitzt keine Koeder, kaufe welche im Angelshop. Verwende /Navi -> Weitere Orte um diesen zu finden!");
    if(Spieler[playerid][pFische] > 20)return SendClientMessage(playerid, COLOR_ORANGE, "Du hast zuviele Fische, verkaufe sie zuerst!");
    if (Angel[a][Fische] < 1) return SendClientMessage(playerid, COLOR_ORANGE, "Hier sind im Moment keine Fische mehr zu fangen.");
    if(IsPlayerFishing[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Du bist bereits am angeln!");
    FreezePlayer(playerid);
    Spieler[playerid][pKoeder] --;
    LoopingAnim(playerid,"ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1); // Gun Arrest
    SetPlayerFacingAngle(playerid, Angel[a][FacingAngle]);
    PlayerAngel[playerid] = SetPlayerAttachedObject(playerid, 0,18632,6,0.079376,0.037070,0.007706,181.482910,0.000000,0.000000,1.000000,1.000000,1.000000);
    GameTextForPlayer(playerid, "~g~Angel ~y~ausgeworfen", 5000, 1);
    pAngelTimer[playerid] = SetTimerEx("AngelTimer", 5000, 0, "i", playerid);
    IsPlayerFishing[playerid] = 1;
    return 1;
}

CMD:angelstats(playerid, params[])
{
    new pID;
    if (sscanf(params, "u", pID) || pID == playerid) {
        ShowAngelStats(playerid, playerid);
        return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Angelstats [SpielerID/Name] um jemand anderem deine Angel-Statistiken zu zeigen!");
    }

    if (pID == INVALID_PLAYER_ID || !gPlayerLogged[pID]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht online.");
    if (Spieler[pID][pAdminDienst]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist gerade im Admindienst.");
    if (!IsPlayerInRangeOfPlayer(playerid, pID, 5.0)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht in deiner Nähe.");

    SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast %s angeboten, deine Angelstatistiken anzuschauen.", GetName(pID));
    SCMFormatted(pID, COLOR_YELLOW, "[INFO] {FFFFFF}%s %s hat dir angeboten, seine/ihre Angelstatistiken anzuschauen.", GetName(playerid));
    SCMFormatted(pID, COLOR_LIGHTBLUE, "[INFO] {FFFFFF}Nutze '/Accept Angelstats' um dir die Angelstatistiken anzuschauen.", GetName(playerid));
    new pVarString[40];
    format(pVarString, sizeof(pVarString), "%i %i", playerid, Spieler[playerid][pLoginTimestamp]);
    SetPVarString(pID, "SHOW.ANGELSTATS", pVarString);
    return 1;
}


CMD:grillen(playerid, params[])
{
    if(IsPlayerInRangeOfPoint(playerid, 5.0, FISHINGSHOP_GRILL_POINT))
    {
        if(Spieler[playerid][pFische] == 0)return SendClientMessage(playerid, COLOR_RED, "Du hast keine Fische.");
        Spieler[playerid][pFische] --;
        GameTextForPlayer(playerid, "~g~Fisch ~y~gegrillt", 2000, 1);
        ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        new Float:heal;
        GetPlayerHealth(playerid, heal);
        if(heal > 90)return SendClientMessage(playerid, COLOR_ORANGE, "Du kannst keine Fische mehr essen, da du zuviel Leben hast.");
        SetPlayerHealth(playerid, heal+10);
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht am Strand am Lagerfeuer.");
        return 1;
    }
    return 1;
}
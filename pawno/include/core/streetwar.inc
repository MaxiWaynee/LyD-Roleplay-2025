#include <YSI\y_hooks>

//static SW_score[MAX_FACTIONS];
new SW_score[MAX_FACTIONS];

#define SW_STREETWAREND 22

task SW_checkStreetwarEnd[60000]() {
    new hour, minute;
    gettime(hour, minute);

    if (hour != SW_STREETWAREND || minute != 0)
       return 1;
    
    new highScore = 0, winnerCount = 0;
    for (new i; i < MAX_FACTIONS; i++) // find high score
        if (SW_score[i] > highScore) highScore = SW_score[i];

    for (new i; i < MAX_FACTIONS; i++) // count winners
        if (SW_score[i] == highScore) winnerCount++;


    #if defined NEUE_WIRTSCHAFT
        new money, damount;
        money = floatround(RandomEx(200000, 300000) / winnerCount, floatround_ceil);
        damount = floatround(RandomEx(100, 250) / winnerCount, floatround_ceil);
    #else
        new money, wamount, damount;
        money = floatround(RandomEx(200000, 300000) / winnerCount, floatround_ceil);
        wamount = floatround(RandomEx(40000, 50000) / winnerCount, floatround_ceil);
        damount = floatround(RandomEx(700, 1000) / winnerCount, floatround_ceil);
    #endif

    new message[144], winners[144];

    for (new i; i < MAX_FACTIONS; i++) {
        if (SW_score[i] == highScore && highScore != 0) {
            if (i == 6) Kasse[Grove] += money;
            else if (i == 7) Kasse[Ballas] += money;
            else if (i == 10) Kasse[Yakuza] += money;
            else if (i == 11) Kasse[Aztecas] += money;
            else if (i == 12) Kasse[LCN] += money;
            else if (i == 13) Kasse[Vagos] += money;
            else if (i == 14) Kasse[Hitman] += money;
            else if (i == 20) Kasse[OutlawzK] += money;
            else if (i == 21) Kasse[ndgradethaK] += money;

            g_fraktion[i][Fr_FSDrogen] += damount;

            #if !defined NEUE_WIRTSCHAFT
                g_fraktion[i][Fr_FSWaffenteile] += wamount;
            #endif

            format(winners, sizeof(winners), "%s%s, ", winners, factionNames[i]);

            #if defined NEUE_WIRTSCHAFT
                format(message, sizeof(message), "[Streetwar] {FFFFFF}Gewinn: $%s und %sg Drogen", AddDelimiters(money), AddDelimiters(damount));
            #else
                format(message, sizeof(message), "[Streetwar] {FFFFFF}Gewinn: $%s, %s Waffenteile und %sg Drogen", AddDelimiters(money), AddDelimiters(wamount), AddDelimiters(damount));
            #endif
            SendFraktionMessage(i, COLOR_YELLOW, message); 
        }

        SW_score[i] = 0;
    }

    if (highScore) {
        winners[strlen(winners) - 2] = EOS;
        format(winners, sizeof(winners), "[Streetwar] {FFFFFF}Gewinner des heutigen Streetwars: %s", winners);
        SendClientMessageToAll(COLOR_DARKGREEN, winners);
    } else
        SendClientMessageToAll(COLOR_DARKRED, "[Streetwar] {FFFFFF}Keine Gang oder Mafia hat Punkte erkämpft. Niemand hat eine Belohnung bekommen.");

    return 1;
}

CMD:swinfo(playerid, params[]) return cmd_streetwarinfo(playerid, params);
CMD:streetwarinfo(playerid, params[]) {
    new dialogText[256] = "Gang / Mafia\tStreetwar-Punkte\n";

    for (new i = 0; i < sizeof(factionNames); i++)
        if (IsAFightFaction(i))
            format(dialogText, sizeof(dialogText), "%s%s\t%d\n", dialogText, factionNames[i], SW_score[i]);

    return ShowPlayerDialog(playerid, DIALOG_NO_RESPONSE, DIALOG_STYLE_TABLIST_HEADERS, "{32B232}Streetwar Info", dialogText, "Schließen", "");
}

forward LoadStreetwar();
public LoadStreetwar() {
    for (new i; i < cache_get_row_count(); i++)
        SW_score[cache_get_field_content_int(i, "fraktionsid", gSQL)] = cache_get_field_content_int(i, "score", gSQL);

    return 1;
}

hook OnGameModeInit2() {
    mysql_tquery(gSQL, "SELECT * FROM `fraktionen`", "LoadStreetwar");
    return 1;
}

hook SaveAll() {
    saveStreetwar();
    return 1;
}

hook OnGameModeExit() {
    saveStreetwar();
    return 1;
}

/*hook OnPlayerDeath(playerid, killerid, reason) {
    if (killerid == INVALID_PLAYER_ID) return 1;
    if (Spieler[playerid][pFraktion] == Spieler[killerid][pFraktion] || g_Faction[Spieler[killerid][pFraktion]][F_iPartner] == Spieler[playerid][pFraktion]) return 1;
    if (PlayerIsPaintballing[playerid] || PlayerIsPaintballing[killerid]) return 1;
    if (IsAFightFaction(Spieler[playerid][pFraktion]) && IsAFightFaction(Spieler[killerid][pFraktion])) {
        new fightid = GetGangFight(Spieler[playerid][pFraktion]);
        if (fightid != GetGangFight(Spieler[killerid][pFraktion]) || fightid == -1) {
            new message[128], rk[35];
            
            ReturnPlayerRank(killerid, rk);
            format(message, sizeof(message), "[Streetwar] {FFFFFF}%s %s hat %s (%s) getötet.", rk, GetName(killerid), GetName(playerid), factionNames[Spieler[playerid][pFraktion]]);
            GameTextForPlayer(killerid, "+1 Streetwarkill", 3000, 4);
            SendFraktionMessage(Spieler[killerid][pFraktion], COLOR_DARKGREEN, message);
            ReturnPlayerRank(playerid, rk);
            format(message, sizeof(message), "[Streetwar] {FFFFFF}%s %s wurde von %s (%s) getötet.", rk, GetName(playerid), GetName(killerid), factionNames[Spieler[killerid][pFraktion]]);
            SendFraktionMessage(Spieler[playerid][pFraktion], COLOR_RED, message);
            SW_score[Spieler[killerid][pFraktion]]++;
            Spieler[killerid][pKillsStreetwar]++;
            GivePlayerCash(killerid, 450);
        }
    }
    
    return 1;
}*/

stock saveStreetwar() {
    new query[128];
    for (new i = 0; i < sizeof(factionNames); i++) {
        format(query, sizeof(query), "UPDATE `fraktionen` SET `score` = %d WHERE `fraktionsid` = %d", SW_score[i],i);
        mysql_pquery(gSQL, query);
    }

    return 1;
}

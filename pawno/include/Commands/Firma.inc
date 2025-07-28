#include <YSI\y_hooks>

CMD:firmen(playerid, params[]) {
    if( gPlayerLogged[playerid] == 0 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht eingeloggt");
    ShowPlayerDialog(playerid,DIALOG_FIRMENINFO,DIALOG_STYLE_MSGBOX,"Firmen",
        "{FFFFFF}Auf dieser Liste werden alle Firmeninhaber aufgelistet.\n\
        Um eine Firma die noch keinen Besitzer hat zu kaufen,\n\
        muss man ein Antrag beim Gewerbeamt im\n\
        Forum: {4422FF}www.LyD-Roleplay.de{FFFFFF} stellen.","Ansehen","Abbruch");
    return 1;
}

CMD:firmenkasse(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pPlayerFirma] == 999) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du besitzt keine Firma.");

    new sBefehl[16], cash, firmenindex = Spieler[playerid][pPlayerFirma];
    if (sscanf(params, "s[16]d", sBefehl, cash) || cash < 1) {
        if (isnull(params)) SCMFormatted(playerid, COLOR_CHAT_JOB, "[FIRMA] {FFFFFF}Aktueller Kassenstand: {009D00}$%s", AddDelimiters(g_Firma[firmenindex][F_iKasse]));
        return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Firmenkasse [Einzahlen/Auszahlen] [Betrag]");
    }

    if (!strcmp(sBefehl, "einzahlen", true)) {
        if (Spieler[playerid][pCash] < cash) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}So viel Geld hast du nicht dabei.");
        g_Firma[firmenindex][F_iKasse] += cash;
        GivePlayerCash(playerid, -cash);
        SCMFormatted(playerid, COLOR_CHAT_JOB, "[FIRMA] {FFFFFF}Du hast {009D00}$%s {FFFFFF}in deine Firmenkasse eingezahlt.", AddDelimiters(cash));
    }
    else if (!strcmp(sBefehl, "auszahlen", true)) {
        if (g_Firma[firmenindex][F_iKasse] < cash) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}So viel Geld befindest sich nicht in deiner Firmenkasse.");
        g_Firma[firmenindex][F_iKasse] -= cash;
        GivePlayerCash(playerid, cash);
        SCMFormatted(playerid, COLOR_CHAT_JOB, "[FIRMA] {FFFFFF}Du hast {009D00}$%s {FFFFFF}aus deiner Firmenkasse ausgezahlt.", AddDelimiters(cash));
    }
    else return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Firmenkasse [Einzahlen/Auszahlen] [Betrag]");

    return SCMFormatted(playerid, COLOR_CHAT_JOB, "[FIRMA] {FFFFFF}Aktueller Kassenstand: {009D00}$%s", AddDelimiters(g_Firma[firmenindex][F_iKasse]));
}

CMD:firmengehalt(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pPlayerFirma] == 999) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du besitzt keine Firma.");
    new cash;
    if (sscanf(params, "d", cash)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Firmengehalt [Gehalt]");

    #if !defined NEUE_WIRTSCHAFT
        if (cash < 25000 || cash > 50000) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Firmengehalt [Gehalt ($25.000 - $50.000)]");
    #endif
    new message[144], firmenindex = Spieler[playerid][pPlayerFirma];
    g_Firma[firmenindex][F_iGehalt] = cash;
    format(message, sizeof(message), "[%s] {FFFFFF}Das Gehalt wurde von Firmeninhaber %s auf {009D00}$%s {FFFFFF}gesetzt.", g_Firma[firmenindex][F_sBezeichnung], GetName(playerid), AddDelimiters(cash));
    SendJobMessage(g_Firma[firmenindex][F_iJobID], COLOR_CHAT_JOB, message);
    return SCMFormatted(playerid, COLOR_CHAT_JOB, "[FIRMA] {FFFFFF}Du hast das Gehalt deiner Firma auf {009D00}$%s {FFFFFF}gesetzt.", AddDelimiters(cash));
}

CMD:firmennachricht(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pPlayerFirma] == 999) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du besitzt keine Firma.");
    new nachricht[128], message[144], firmenindex = Spieler[playerid][pPlayerFirma];
    if (sscanf(params, "s[128]", nachricht)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Firmennachricht [Text]");
    format(message, sizeof(message), "[%s] {FFFFFF}Firmeninhaber %s sagt: %s", g_Firma[firmenindex][F_sBezeichnung], GetName(playerid), nachricht);
    SendJobMessage(g_Firma[firmenindex][F_iJobID], COLOR_CHAT_JOB, message);
    return SCMFormatted(playerid, COLOR_CHAT_JOB, "[FIRMA] {FFFFFF}Du sagst: %s", nachricht);
}

CMD:entlassen(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pPlayerFirma] == 999) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du besitzt keine Firma.");
    new giveid, firmenindex = Spieler[playerid][pPlayerFirma];
    if (sscanf(params, "u", giveid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Entlassen [Spieler]");
    if (!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht Online.");
    if (playerid == giveid) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst dich selber nicht entlassen.");
    if (Spieler[giveid][pJob] != g_Firma[firmenindex][F_iJobID]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht in deiner Firma tätig.");

    Spieler[giveid][pJob] = 0;
    SCMFormatted(playerid, COLOR_CHAT_JOB, "[%s] {FFFFFF}Sie wurden von Ihrem Chef %s entlassen!", g_Firma[firmenindex][F_sBezeichnung], GetName(playerid));
    return SCMFormatted(playerid, COLOR_CHAT_JOB, "[FIRMA] {FFFFFF}Du hast %s entlassen", GetName(giveid));
}


CMD:mitarbeiter(playerid,params[])
{
    if(Spieler[playerid][pPlayerFirma] == 999) return SendClientMessage(playerid,COLOR_RED,"Du besitzt keine Firma.");
    new string[256],string2[128],string3[128];
    for(new i; i < MAX_PLAYERS; i++)
    {
        if(Spieler[i][pJob] == g_Firma[Spieler[playerid][pPlayerFirma]][F_iJobID])
        {    
            format(string2,sizeof(string2),"%s\t%d\n",GetName(i),i);
            strcat(string3,string2);
        }
    }
    format(string,sizeof(string),"Name\tID\n%s",string3);
    ShowPlayerDialog(playerid,DIALOG_NO_RESPONSE,DIALOG_STYLE_TABLIST_HEADERS,"Mitarbeiter",string,"Okay","Verlassen");
    return 1;
}
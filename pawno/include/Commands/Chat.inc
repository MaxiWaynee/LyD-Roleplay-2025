#include <YSI\y_hooks>

CMD:me(playerid, params[])
{
    if(Spieler[playerid][pMuted]== 1)return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du bist gemutet.");
    new entry[128], string[128], Float:x, Float:y, Float:z;
    if(sscanf(params, "s[128]", entry))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Me [Nachricht]");
    format(string, sizeof(string), "** %s %s **", GetName(playerid), entry);
    GetPlayerPos(playerid, x, y, z);
    SendRoundMessage(x, y, z, COLOR_PURPLE, string);
    return 1;
}


CMD:chatsettings(playerid) {
    return cmd_chatoff(playerid);
}

CMD:chatoff(playerid) {
    new dialogText[400];
    format(dialogText, sizeof(dialogText), "Chat\tEinstellungen\n");
    for (new i = 0; i < sizeof(g_ChatNames); i++) {
        if (i == 6 && !IsBeamter(playerid)) continue;
        format(dialogText, sizeof(dialogText), "%s%s\t%s\n", dialogText, g_ChatNames[i], 
            pChatSettings[playerid][i] ? COLOR_HEX_GREEN "Angeschaltet" : COLOR_HEX_RED "Ausgeschaltet");
    }

    return ShowPlayerDialog(playerid, DIALOG_CHATOFF, DIALOG_STYLE_TABLIST_HEADERS, "Chat-Einstellungen", dialogText, "Ändern", "Abbrechen");
}
/*
CMD:clubfarbe(playerid)
{
    if( gPlayerLogged[playerid] == 0 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht eingeloggt.");
	if(Spieler[playerid][pDuty] == 1 ) return SendClientMessage(playerid,COLOR_RED,"Du bist noch im Frakdienst.");
    if(!(Spieler[playerid][pDonateRank] == 1 || Spieler[playerid][pDonateRank] == 2))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Clubmitglied!");
    {
        if(Spieler[playerid][pBenutzerfarbe]==0)
        {
            SendClientMessage(playerid,COLOR_GREEN,"Clubfarbe wurde aktiviert.");
            SetPlayerColor(playerid, COLOR_CLUB);
            Spieler[playerid][pBenutzerfarbe] = 1;
        }
        else
        {
            SendClientMessage(playerid,COLOR_YELLOW,"Clubfarbe wurde deaktiviert.");
            Spieler[playerid][pBenutzerfarbe] = 0;
            SetPlayerColor(playerid, COLOR_WHITE);
        }
    }
    return 1;
}
*/

CMD:jc(playerid, params[])
{
    if(Spieler[playerid][pMuted]== 1)return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du bist gemutet.");
    if(Spieler[playerid][bMundbinde]){
        SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du hast eine Mundbinde.");
        return 0;
    }
    new text[96];
    if(pChatSettings[playerid][CHAT_JC] == 0)return SendClientMessage(playerid, COLOR_RED, "Du hast den Job Chat für dich deaktiviert, tippe /Chatoff.");
    if(sscanf(params, "s[96]", text))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Jc [Nachricht]");
    if(Spieler[playerid][pJob] >= 1)
    {
        new string[128], pjob[50];
        ReturnPlayerJob(playerid, pjob);
        format(string, sizeof(string), "* %s %s sagt: %s, over *", pjob, GetName(playerid), text);
        SendJobMessage(Spieler[playerid][pJob], COLOR_CHAT_JOB, string);
        if(IsJobFirma( Spieler[playerid][pJob] ))
        {
            for(new i=0;i<MAX_PLAYERS;i++)
            {
                new firmenindex = firmenindex = GetJobFirmaIndex(Spieler[playerid][pJob]);
                if(Spieler[i][pPlayerFirma] == firmenindex && Spieler[i][pJob] != Spieler[playerid][pJob])
                SendClientMessage(i,COLOR_CHAT_JOB,string);
            }
        }
        format(string, sizeof(string), "Job: %s - Name: %s - %s", pjob, GetName(playerid), text);
        LogJobChat(string);
    }
    return 1;
}

CMD:cc(playerid, params[])
{
    if(Spieler[playerid][pMuted]== 1)return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du bist gemutet.");
    if(Spieler[playerid][pDonateRank] != 1) return SendClientMessage(playerid,COLOR_RED,"Du bist kein Clubmitglied");
    if(!g_aSettings[ASETTING_CLUBCHAT][ASETTING_TOGGLE])return SendClientMessage(playerid, COLOR_RED, "Der Globale Chat ist derzeit deaktiviert.");
    new text[96];
    if(sscanf(params, "s[96]", text)) return SendClientMessage(playerid, COLOR_BLUE, "* Club-Chat:"COLOR_HEX_GREENA" /CC [Nachricht]");
    if(pChatSettings[playerid][CHAT_CC] == 0)return SendClientMessage(playerid, COLOR_RED, "Du hast den Clubmitglied Chat für dich deaktiviert, tippe /Chatoff.");
    new string[128];
    format(string, sizeof(string), "* Clubmitglied %s sagt: %s *", GetName(playerid), text);
    SendClubMessage(COLOR_CLUB,string);
    return 1;
}

CMD:o(playerid, params[]) return cmd_gc(playerid, params);
CMD:gc(playerid, params[])
{
    new text[128], string[144];
    if(sscanf(params, "s[128]", text))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Gc [Nachricht]");
    if(Spieler[playerid][bMundbinde]) return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du hast eine Mundbinde.");
    if(Spieler[playerid][pMuted]== 1)return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du bist gemutet.");
    if( Spieler[playerid][pLevel] < 3 ) return SendClientMessage(playerid, COLOR_RED, "Du musst Level 3 sein um im globalen Chat zu schreiben!");
    if(Spieler[playerid][pAdmin] < 2) {
        if(!g_aSettings[ASETTING_GLOBALCHAT][ASETTING_TOGGLE])return SendClientMessage(playerid, COLOR_RED, "Der Globale Chat ist derzeit deaktiviert.");
        if(!pChatSettings[playerid][CHAT_GC])return SendClientMessage(playerid, COLOR_YELLOW, "Du hast den Globalen Chat für dich deaktiviert, tippe /chatoff.");
        format(string, sizeof(string), "(( %s: %s ))", GetName(playerid), text);
        SendGlobalMessage(COLOR_CHAT_GC_NONADM, string);
    } else {
        if(!pChatSettings[playerid][CHAT_GC])return SendClientMessage(playerid, COLOR_YELLOW, "Du hast den Globalen Chat für dich deaktiviert, tippe /chatoff.");
        format(string, sizeof(string), "(( %s %s: %s ))", GetPlayerAdminRang(playerid), GetName(playerid), text);
        SendGlobalMessage(COLOR_CHAT_GC_ADM, string);
    }
    format(string, sizeof(string), "Name: %s - %s", GetName(playerid), text);
    LogGlobalChat(string);
    return 1;
}


CMD:s(playerid,params[]) {
    if( isnull(params)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/S [Nachricht]");
    }
    if(Spieler[playerid][bMundbinde]){
        SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du hast eine Mundbinde.");
        return 0;
    }
    if(Spieler[playerid][pMuted]== 1){
        SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du bist gemutet.");
        return 0;
    }
    return SendSchreiMessage(playerid,params);
}

CMD:f(playerid,params[]) {
    new message[128], giveid;
    if( sscanf(params,"us[128]",giveid,message)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/F [Spieler] [Nachricht]");
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht online.");
    if( giveid == playerid ) return SendClientMessage(playerid,COLOR_RED,"[INFO] {FFFFFF}Du kannst dir nicht selber zuflüstern.");
    if( Spieler[giveid][pAdminDienst] )return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist gerade im Admindienst.");
    if(Spieler[playerid][bMundbinde]) return SendClientMessage(playerid, COLOR_CHAT_MUTED, "[INFO] {FFFFFF}Du hast eine Mundbinde.");
    if(Spieler[playerid][pMuted]== 1)return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du bist gemutet.");
    return SendFluesterMessage(playerid,giveid,message);
}


CMD:werbung(playerid,params[]) {
    new
        tick = gettime();
    if( !IsPlayerInRangeOfPoint(playerid, 5.0, 1412.1915,-1700.3817,13.5395) && !IsPlayerInRangeOfPoint(playerid, 5.0, 2008.1722,1169.3364,10.8203))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht am Werbe-Platz.");
    if( Spieler[playerid][pLevel] < 5 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du musst Level 5 sein um eine Werbung zu schreiben!");
    }
    if( g_unixWerbung > tick ) {
        return SendClientMessage(playerid, COLOR_RED, "Die letzte Werbung ist noch keine 3 Minuten alt.");
    }
    ShowPlayerDialog(playerid,DIALOG_WERBUNG,DIALOG_STYLE_INPUT,"Werbung Kaufen","Du kannst eine Werbung kaufen.\nPro Zeichen fallen 200$ Kosten an","Absenden","Abbrechen");
    return 1;
}



CMD:ic(playerid,params[]) {
    if(Spieler[playerid][pMuted]== 1)return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du bist gemutet.");
    if(Spieler[playerid][bMundbinde]){
        SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du hast eine Mundbinde.");
        return 0;
    }
    if(isnull(params)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Ic [Text]");
    }
    new
        Float:x,
        Float:y,
        Float:z,
        String[200];
    format(String,sizeof(String),"{7F007F}(IC){FFFFFF}: %s",params);
    SetPlayerChatBubble(playerid,String,COLOR_WHITE,40.0 , strlen(params) * 65 + 150);
    if (GetPVarInt(playerid, "USE_CHAT_ANIM") && Spieler[playerid][pTot] == 0 && Cuffed[playerid] != 1 && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
        if (!(gettime() < Spieler[playerid][unixSpiceCooldown] || IsPlayerFalling(playerid))) {
            MakeAnimation[playerid] = 1;
            // TextDrawShowForPlayer(playerid, Leer);
            ApplyAnimation(playerid,"PED","IDLE_CHAT",4.0,0,0,0,0,0);
        }
    }
    GetPlayerPos(playerid,x,y,z);
    format(String,sizeof(String),"%s sagt %s",GetName(playerid),String);
    SendRoundMessage(x,y,z,COLOR_WHITE,String);
    return 1;
}



CMD:nc(playerid,params[]) {
    if( gPlayerLogged[playerid] == 0 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht eingeloggt");
    if(Spieler[playerid][pMuted]== 1)return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du bist gemutet.");
    if(Spieler[playerid][pLevel] >= 3 && Spieler[playerid][pAdmin] == 0 && Spieler[playerid][pAutomatik] == 0) {
        return SendClientMessage(playerid, COLOR_RED, "Dieser Chat ist ausschließlich für Neulinge ( Bis Level 3 ) und Server-Experten");
    }
    if( isnull(params) ) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Nc [Nachricht]");
    }
    new
        String[128+32];
    if( Spieler[playerid][pAdmin] > 0 ) {
        format(String,sizeof(String),"* %s %s sagt: %s",GetPlayerAdminRang(playerid), GetName(playerid),params);
    } else if(Spieler[playerid][pAutomatik] == 1) {
        format(String,sizeof(String),"* Server-Experte %s sagt: %s",GetName(playerid),params);
    } else {
        format(String,sizeof(String),"* Neuling %s (Lvl: %d) sagt: %s",GetName(playerid),Spieler[playerid][pLevel],params);
    }
    for(new i ; i < MAX_PLAYERS ; i++) {
        if( IsPlayerConnected(i) ) {
            if( Spieler[i][pLevel] < 3 || Spieler[i][pAdmin] > 0 || Spieler[playerid][pAutomatik] == 1) {
                SendClientMessage(i,COLOR_ORANGE,String);
            }
        }
    }
    return 1;
}


CMD:a(playerid, params[]) {
    return cmd_admin(playerid, params);
}

CMD:ac(playerid, params[]) {
	return cmd_admin(playerid, params);
}

CMD:admin(playerid, params[])
{
	if( gPlayerLogged[playerid] == 0 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht eingeloggt.");
	new string[150], rk[50], text[128], msg[128];
	if(Spieler[playerid][pAdmin] > 2)
	{
	    if(sscanf(params, "s[128]", text))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/(A)dmin [Nachricht] - Adminchat");
		else if(Spieler[playerid][pAdmin] == ADMIN_RANK_MOD){rk ="Moderator";}
		else if(Spieler[playerid][pAdmin] == ADMIN_RANK_ADMIN){rk ="Administrator";}
		else if(Spieler[playerid][pAdmin] == ADMIN_RANK_DEVELOPER){rk ="Entwickler";}
		else if(Spieler[playerid][pAdmin] == ADMIN_RANK_MANAGER){rk ="Server-Manager";}
		else if(Spieler[playerid][pAdmin] == ADMIN_RANK_CHIEF){rk ="Projektleiter";}
		else if(Spieler[playerid][pAdmin] == ADMIN_RANK_PROJEKTVERWALTER){rk ="Projektverwalter";}
	    format(string, sizeof(string), "[A-Chat] {fca903} %s | %s sagt: %s ", rk, GetName(playerid), text);
	    SendModMessage(COLOR_RED, string);
		format(string, sizeof(string), "Name: %s - %s", GetName(playerid), text);
		LogAdminChat(string);
	}
	else
	{
		if(sscanf(params, "s[128]", msg))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/(A)dmin [Nachricht]");
		format(string, sizeof(string), ">MELDUNG<"#COLOR_HEX_YELLOW" %s (ID: %d) Nachricht: %s", GetName(playerid), playerid, msg);
		SendModMessage(COLOR_RED, string);
		SendClientMessage(playerid, COLOR_LIGHTGREEN, "Deine Meldung wurde an die Admins geschickt!");
	}
	return 1;
}

CMD:sup(playerid, params[])
{
    if( gPlayerLogged[playerid] == 0 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht eingeloggt");
	if(Spieler[playerid][pAdmin] != 0) return SendClientMessage(playerid,COLOR_RED,"Im LyD Team nicht möglich!(Als Admin kannst du keine Tickets erstellen!)");
    if(PlayerNeedsHelp[playerid] == 1)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Du hast vorhin erst ein Ticket abgeschickt. Warte noch einen Moment!");
        return 1;
    }
    new msg[128];
    if(sscanf(params, "s[128]", msg))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Sup [Frage]");
    new string[144];
    format(string, sizeof(string), "> Ticket < - %s (ID: %d) Nachricht: %s", GetName(playerid), playerid, msg);
    SendAdminMessage(COLOR_LIGHTGREEN, string);
    SendClientMessage(playerid, COLOR_LIGHTGREEN, "Dein Ticket wurde an das Support-Team gesendet, warte auf eine Rückmeldung!");
    PlayerNeedsHelp[playerid] = 1;
    format(SupText[playerid], 128 , "%s", msg);
    ReportTimer[playerid] = SetTimerEx("ReportReset", 140000, false, "d", playerid);
    return 1;
}
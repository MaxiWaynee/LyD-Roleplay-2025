#include <YSI\y_hooks>



CMD:interview(playerid,params[]) {
    new
        giveid;
    if(sscanf(params,"u",giveid)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Interview [SPIELERNAME/ID]");
    }
    if( Spieler[playerid][pFraktion] != 4 ) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Du bist kein News-Reporter");
    }
    if(Spieler[playerid][pRank] < 3) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Dein Rank ist zu niedrig! Du musst mind. Rank 3 sein, um ein Interview machen zu dürfen.");
    }
    if( !IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Spieler konnte nicht gefunden werden");
    }
    if( playerid == giveid ) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Das macht keinen Sinn");
    }
    if( Spieler[giveid][pInterviewer] == playerid ) {
        new
            String[128];
        if( Spieler[playerid][ibInterviewStat] == 2) {
            format(String,sizeof(String),"%s hat das Interview mit %s beendet!",GetName(playerid),GetName(giveid));
        }
        else {
            format(String,sizeof(String),"%s hat das Interviewangebot an %s zurückgezogen!",GetName(playerid),GetName(giveid));
        }
        SendClientMessageToAll(COLOR_CHAT_JOB,String);
        Spieler[playerid][pInterviewer] = INVALID_PLAYER_ID;
        Spieler[giveid][pInterviewer] = INVALID_PLAYER_ID;
        Spieler[playerid][ibInterviewStat] = 0;
        Spieler[giveid][ibInterviewStat] = 0;
        UnfreezePlayer(playerid);
        UnfreezePlayer(giveid);
        return 1;
    }
    new
        Float:x,
        Float:y,
        Float:z;
    GetPlayerPos(playerid,x,y,z);
    if( !IsPlayerInRangeOfPoint(giveid,3.0,x,y,z) ) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Dein Gesprächspartner befindet sich nicht in deiner direkten Nähe");
    }
    if( GetPlayerState(playerid) != PLAYER_STATE_ONFOOT ) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Du musst zu Fuß unterwegs sein");
    }
    if( GetPlayerState(giveid) != PLAYER_STATE_ONFOOT ) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Dein Interview Partner muss zu Fuß sein");
    }
    if( Spieler[playerid][pInterviewer] != INVALID_PLAYER_ID ) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Du hast bereits ein Interview(angebot) versendet");
    }
    if( Spieler[giveid][pInterviewer] != INVALID_PLAYER_ID ) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Der Spieler hat bereits ein Interview(angebot)");
    }
    new
        String[128];
    format(String,sizeof(String),"News-Reporter %s möchte mit dir ein Interview führen ( /Acceptinterview , /Stopinterview )",GetName(playerid));
    SendClientMessage(giveid,COLOR_GREEN,String);
    format(String,sizeof(String),"Du hast %s eine Interview Anfrage gesendet",GetName(giveid));
    SendClientMessage(playerid,COLOR_GREEN,String);
    Spieler[giveid][pInterviewer] = playerid;
    Spieler[playerid][pInterviewer] = giveid;
    return 1;
}
CMD:acceptinterview(playerid,params[]) {
    if( Spieler[playerid][pInterviewer] == INVALID_PLAYER_ID ) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Du hast kein Interviewangebot");
    }
    if( Spieler[playerid][ibInterviewStat] != 0) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Du hast bereits ein Interview angenommen");
    }
    new
        interviewer;
    interviewer = Spieler[playerid][pInterviewer];
    if( !IsPlayerConnected(interviewer)) {
        Spieler[playerid][pInterviewer] = INVALID_PLAYER_ID;
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Der News-Reporter ist nicht mehr Online");
    }
    new
        Float:x,
        Float:y,
        Float:z;
    GetPlayerPos(playerid,x,y,z);
    if( !IsPlayerInRangeOfPoint(interviewer,5.0,x,y,z)) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Der News-Reporter ist zu weit weg von dir");
    }
    new
        String[128];
    format(String,sizeof(String),"[INTERVIEW] Reporter %s interviewt nun %s",GetName(interviewer),GetName(playerid));
    SendClientMessageToAll(COLOR_CHAT_JOB,String);
    Spieler[interviewer][ibInterviewStat] = 2; // <- Ist Interviewe
    Spieler[playerid][ibInterviewStat] = 1; // <- Ist Person die interviewt wird
    FreezePlayer(playerid);
    FreezePlayer(interviewer);
    return 1;
}

CMD:stopinterview(playerid,params[]) {
    new
        String[128],
        interviewer;
    interviewer = Spieler[playerid][pInterviewer];
    if( Spieler[playerid][ibInterviewStat] == 1 ) {
        format(String,sizeof(String),"%s hat das Interview mit %s beendet!",GetName(playerid),GetName(interviewer));
        SendClientMessageToAll(COLOR_CHAT_JOB,String);
        Spieler[playerid][ibInterviewStat] = 0;
        Spieler[interviewer][ibInterviewStat] = 0;
        Spieler[playerid][pInterviewer] = INVALID_PLAYER_ID;
        Spieler[interviewer][pInterviewer] = INVALID_PLAYER_ID;
        UnfreezePlayer(playerid);
        UnfreezePlayer(interviewer);
        return 1;
    }
    if( Spieler[playerid][pInterviewer] != INVALID_PLAYER_ID ) {
        format(String,sizeof(String),"%s hat das Interviewangebot von %s abgelehnt",GetName(playerid),GetName(interviewer));
        SendClientMessageToAll(COLOR_CHAT_JOB,String);
        Spieler[playerid][ibInterviewStat] = 0;
        Spieler[interviewer][ibInterviewStat] = 0;
        Spieler[playerid][pInterviewer] = INVALID_PLAYER_ID;
        Spieler[interviewer][pInterviewer] = INVALID_PLAYER_ID;
        UnfreezePlayer(playerid);
        UnfreezePlayer(interviewer);
        return 1;
    }
    SendClientMessage(playerid,COLOR_LIGHTRED2,"Du hast kein Interview(angebot) welches du stoppen kannst");
    return 1;
}


enum e_EventPoint {
    bool:EP_bStatus,
    Float:EP_fX,
    Float:EP_fY,
    Float:EP_fZ,
    EP_iInterior,
    EP_iVirtualworld
}

new g_EventPoint[e_EventPoint];

CMD:starteventpoint(playerid,params[]) {
    if( Spieler[playerid][pFraktion] != 4 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein News-Reporter");
    }
    if(Spieler[playerid][pRank] < 3) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Dein Rank ist zu niedrig! Du musst mind. Rank 3 sein, um ein Event starten zu können.");
    }
    if( g_EventPoint[EP_bStatus] ) {
        return SendClientMessage(playerid, COLOR_RED, "Ein Eventpoint wurde bereits gesetzt");
    }
    new
        String[128],
        Float:X,Float:Y,Float:Z;
    GetPlayerPos(playerid,X,Y,Z);
    format(String,sizeof(String),"[EVENT] Newsreporter %s startet nun ein Event! Mit /eventpoint wird dir der Standort als Marker angezeigt!",GetName(playerid));
    SendClientMessageToAll(COLOR_GREEN,String);

    g_EventPoint[EP_fX] = X;
    g_EventPoint[EP_fY] = Y;
    g_EventPoint[EP_fZ] = Z;
    g_EventPoint[EP_bStatus] = true;
    g_EventPoint[EP_iInterior] =  GetPlayerInterior(playerid);
    g_EventPoint[EP_iVirtualworld] = GetPlayerVirtualWorld(playerid);
    return 1;
}
CMD:stopeventpoint(playerid,params[]) {
    if( Spieler[playerid][pFraktion] != 4 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein News-Reporter");
    }
    if( !g_EventPoint[EP_bStatus] ) {
        return SendClientMessage(playerid, COLOR_RED, "Es wurde kein Eventpoint gesetzt");
    }
    new
        String[128],
        Float:X,Float:Y,Float:Z;
    GetPlayerPos(playerid,X,Y,Z);
    format(String,sizeof(String),"[EVENT] Newsreporter %s hat das Event beendet",GetName(playerid));
    SendClientMessageToAll(COLOR_ORANGE,String);

    g_EventPoint[EP_bStatus] = false;
    return 1;
}
CMD:eventpoint(playerid,params[]) {
    if( !g_EventPoint[EP_bStatus] ) {
        return SendClientMessage(playerid, COLOR_RED, "Es wurde kein Eventpoint gesetzt");
    }
    SendClientMessage(playerid,COLOR_GREEN,"Dir wurde ein Marker zum Event gesetzt!");
    SetPlayerCheckpointEx(playerid,g_EventPoint[EP_fX],g_EventPoint[EP_fY],g_EventPoint[EP_fZ],5.0,CP_EVENTPOINT);
    return 1;
}


CMD:newsspenden(playerid,params[]) {
    new
        betrag;
    if(sscanf(params,"i",betrag)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Newsspenden [BETRAG]");
    }
    if( !IsPlayerInRangeOfPoint(playerid, 3.0, SANABASE_DONATION_POINT)) {
        SendClientMessage(playerid, COLOR_RED, "Falscher Ort um eine Spende durchzuführen.");
        return 1;
    }
    if( !( 50000  <= betrag <= 50000000) ) {
        SendClientMessage(playerid, COLOR_RED, "Ungültiger Betrag (50.000$ - 50.000.000$)");
        return 1;
    }
    if( Spieler[playerid][pCash] < betrag ) {
        SendClientMessage(playerid, COLOR_RED, "Du besitzt diese Menge an Geld nicht auf der Hand.");
        return 1;
    }
    new
        String[128];
    format(String,sizeof(String),"[SPENDE] %s hat $%s an die SA-NA gespendet. Vielen Dank!",GetName(playerid), AddDelimiters(betrag));
    GivePlayerCash(playerid, -betrag);
    Kasse[Sana] += betrag;
    SendClientMessageToAll(COLOR_YELLOW,String);
    return 1;
}


CMD:news(playerid, params[])
{
	new text[96], string[128], vID = GetPlayerVehicleID(playerid);
	if(!(Spieler[playerid][pFraktion] == 4))return SendClientMessage(playerid, COLOR_RED, "Du bist kein San Andreas News Agentur Mitglied.");
	if(sscanf(params, "s[96]", text))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/News [Nachricht]");
	format(string, sizeof(string), "Reporter %s: %s", GetName(playerid), text);
	if(FrakCarInfo[vID][f_frak] == 4)
	{
		SendClientMessageToAll(COLOR_ORANGE, string);
		return 1;
	}
	SendClientMessage(playerid, COLOR_RED, "Du bist in keinem San Andreas News Agentur Fahrzeug.");
	return 1;
}




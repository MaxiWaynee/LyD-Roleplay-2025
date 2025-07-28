#include <YSI\y_hooks>


CMD:raubinfo(playerid,params[])
{
	if(g_iBankraubStatus == Bankraub_Wartezeit) {
		SendClientMessage(playerid,COLOR_YELLOW,"[Los Santos Zentralbank] {FFFFFF}Die Bank kann noch nicht ausgeraubt werden");
	} else {
		SendClientMessage(playerid,COLOR_YELLOW,"[Los Santos Zentralbank] {FFFFFF}Die Bank kann ausgeraubt werden");
	}
    if(g_iBankraubLVStatus == Bankraub_Wartezeit) {
		SendClientMessage(playerid,COLOR_YELLOW,"[Las Venturas Bank] {FFFFFF}Die Bank kann noch nicht ausgeraubt werden");
	} else {
		SendClientMessage(playerid,COLOR_YELLOW,"[Las Venturas Bank] {FFFFFF}Die Bank kann ausgeraubt werden");
	}
	if(g_evidenceRoomHeist[EVIDENCEROOM_HEIST_STATUS] == EVIDENCEROOM_STATUS_COOLDOWN) {
		SendClientMessage(playerid,COLOR_ORANGE,"[Asservatenkammer] {FFFFFF}Die Asservatenkammer kann noch nicht ausgeraubt werden");
	} else {
		SendClientMessage(playerid,COLOR_ORANGE,"[Asservatenkammer] {FFFFFF}Die Asservatenkammer kann ausgeraubt werden");
	}
	if(g_iNDRobStatus == Bankraub_Wartezeit)
	{
		SendClientMessage(playerid,COLOR_GREEN,"[Spice-Lager] {FFFFFF}Das Spice-Lager kann noch nicht ausgeraubt werden");
	} else {
		SendClientMessage(playerid,COLOR_GREEN,"[Spice-Lager] {FFFFFF}Das Spice-Lager kann ausgeraubt werden");
	}
	return 1;
}



CMD:tresoraufbrechen(playerid,params[]) {
    if( (!IsPlayerInRangeOfPoint(playerid,2.0, BANKINTERIORLV_ROB_POINT) ) || (GetPlayerInterior(playerid) != 3) || (GetPlayerVirtualWorld(playerid) != VW_BANKINTERIORLV) ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Las Venturas Zentralbank.");
        return 1;
    }
    if (IsBeamter(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du bist ein Beamter.");
    if (g_aSettings[ASETTING_ROBBLOCK][ASETTING_TOGGLE]) return SendClientMessage(playerid, COLOR_RED, "Zurzeit ist die Überfallsperre aktiviert.");
    if( g_iBankraubLVStatus == Bankraub_Wartezeit ) {
        SendClientMessage(playerid, COLOR_RED, "Die Bank kann zur Zeit nicht ausgeraubt werden.");
        return 1;
    }
    if( g_iBankraubLVStatus == Bankraub_Aktiv ) {
        SendClientMessage(playerid, COLOR_RED, "Ein Bankraub läuft gerade.");
        return 1;
    }
    if( !HasPlayerWeapon(playerid) ) {
        SendClientMessage(playerid, COLOR_RED, "Du kannst die Bank nicht ohne eine Waffe ausrauben.");
        return 1;
    }
    if( GetOnlineExekutive(playerid) < 1) {//4
        SendClientMessage(playerid, COLOR_RED, "Es sind nicht genug Spieler der Exekutive online.");
	    return 1;
	}
	new
	    String[128];
	format(String,sizeof(String),"[ZENTRALBANK] Bankräuber %s raubt die Las Venturas Zentralbank aus!",GetName(playerid));
	SendClientMessageToAll(COLOR_RED,String);
	PlayerPlaySound(playerid,1058,0.0,0.0,0.0);
	MoveDynamicObject(object_bankInteriorLv_vault, BANKINTERIORLV_VAULT_OPEN,4);

    SendClientMessage(playerid,COLOR_RED,"[ACHTUNG] Die Alarmanlage ist angegangen, die Polizei ist unterwegs! Halte 10 Minuten in der Bank aus!");

    g_tPulseBankPosition = SetTimerEx("LVBank_Position",1373,1,"d",playerid);
    g_iBankraubLVStatus = Bankraub_Aktiv;
    g_unixBankraub = gettime();

    GangZoneShowForAll(g_iBankLV, 0xFF000090);
    GangZoneFlashForAll(g_iBankLV, 0x0000FF90);

    SetPlayerAttachedObject( playerid, 0, 1550, 15, 0.000000, 0.280000, -0.310000, 0.000000, 15.000000, 0.000000, 1.000000, 1.000000, 1.000000 );

    KillTimer(g_tPulseBank);
    g_tPulseBank = INVALID_TIMER_ID;

    new breakingNewsMessage[145];
    Spieler[playerid][pWanteds] += 6;
    SendClientMessage(playerid, COLOR_DARKRED, "Du hast ein Verbrechen begangen! (Raub/Überfall) Reporter: Polizeizentrale");
    format(breakingNewsMessage, sizeof(breakingNewsMessage), "Dein Aktuelles Wanted Level: %d", Spieler[playerid][pWanteds]);
    SendClientMessage(playerid, COLOR_YELLOW, breakingNewsMessage);
    format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: %s (ID: %d) hat ein Verbrechen begangen: Raub/Überfall, over.", GetName(playerid), playerid);
    SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
    format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: Reporter: Polizeizentrale, Aktuelles Wantedlevel: %d, over", Spieler[playerid][pWanteds]);
    SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);

    return 1;
}




CMD:kammerausrauben(playerid, params[]) {
    if (!(IsPlayerInRangeOfPoint(playerid, 2.0, EVIDENCEROOM_INTERIOR_HEIST_P) && GetPlayerInterior(playerid) == 18 && GetPlayerVirtualWorld(playerid) == VW_EVIDENCEROOMINTERIOR)) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Asservatenkammer.");
    if (Spieler[playerid][pLevel] < 3) return SendClientMessage(playerid, COLOR_RED, "Du bist noch zu frisch auf dem Server.");
    if (IsBeamter(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du bist ein Beamter.");
    if (g_aSettings[ASETTING_ROBBLOCK][ASETTING_TOGGLE]) return SendClientMessage(playerid, COLOR_RED, "Zurzeit ist die Überfallsperre aktiviert.");
    if (g_evidenceRoomHeist[EVIDENCEROOM_HEIST_STATUS] == EVIDENCEROOM_STATUS_ONGOING) return SendClientMessage(playerid, COLOR_RED, "Es läuft bereits ein Überfall auf die Asservatenkammer.");
    if (g_evidenceRoomHeist[EVIDENCEROOM_HEIST_STATUS] == EVIDENCEROOM_STATUS_COOLDOWN) return SendClientMessage(playerid, COLOR_RED, "Die Asservatenkammer kann noch nicht wieder überfallen werden.");
    if (GetOnlineExekutive(playerid) < 1) return SendClientMessage(playerid, COLOR_RED, "Es sind nicht genug Spieler der Exekutive online.");//2
    if (!HasPlayerWeapon(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Asservatenkammer nicht ohne eine Waffe ausrauben."); // Es wäre besser, wenn du eine Waffe bei dir hättest.

    new breakingNewsMessage[128];
    g_evidenceRoomHeist[EVIDENCEROOM_HEIST_RAIDER] = playerid;
    g_evidenceRoomHeist[EVIDENCEROOM_HEIST_STATUS] = EVIDENCEROOM_STATUS_ONGOING;

    GangZoneShowForAll(g_iEvidenceRoom, 0xFF000090);
    GangZoneFlashForAll(g_iEvidenceRoom, 0x0000FF90);

    Spieler[playerid][pWanteds] += 6;
    SendClientMessage(playerid, COLOR_DARKRED, "Du hast ein Verbrechen begangen! (Raub/Überfall) Reporter: Polizeizentrale");
    format(breakingNewsMessage, sizeof(breakingNewsMessage), "Dein Aktuelles Wanted Level: %d", Spieler[playerid][pWanteds]);
    SendClientMessage(playerid, COLOR_YELLOW, breakingNewsMessage);
    format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: %s (ID: %d) hat ein Verbrechen begangen: Raub/Überfall, over.", GetName(playerid), playerid);
    SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);
    format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: Reporter: Polizeizentrale, Aktuelles Wantedlevel: %d, over", Spieler[playerid][pWanteds]);
    SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
    SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);

    MoveDynamicObject(object_door_evroomInterior, 1254.1525, -14.1255, 999.9403, 999.0, -90.0000, 0.0000, -90.8999);
    MoveDynamicObject(object_door_evroomInterior2,1262.1549, -12.0230, 999.9484, 999.0, -90.0000, 0.0000, 0.0000);

    format(breakingNewsMessage, sizeof(breakingNewsMessage), "[EILMELDUNG] Räuber %s raubt die Asservatenkammer aus!", GetName(playerid));
    SendClientMessageToAll(COLOR_RED, breakingNewsMessage);
    PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
    SendClientMessage(playerid, COLOR_RED, "[ACHTUNG] Die Alarmanlage ist losgegangen, die Polizei ist unterwegs! Halte 10 Minuten in der Kammer aus!");
    g_evidenceRoomHeist[EVIDENCEROOM_HEIST_TIMER] = SetTimer("EvidenceRoomHeistFinished", 600000, false);
    return 1;
}

CMD:bankhacken(playerid,params[]) {
    //if ((!IsPlayerInRangeOfPoint(playerid,2.0,2144.1409,1641.5856,993.5761) ) || (GetPlayerInterior(playerid) != 1)) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Los Santos Zentralbank.");
    if(GetPlayerVirtualWorld(playerid) != VW_BANKINTERIORLS && !IsPlayerInRangeOfPoint(playerid,2.0,1690.5631,-1022.4385,1340.7509)) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Los Santos Bank!");
    if (g_aSettings[ASETTING_ROBBLOCK][ASETTING_TOGGLE]) return SendClientMessage(playerid, COLOR_RED, "Zurzeit ist die Überfallsperre aktiviert.");
    if (g_iBankraubStatus == Bankraub_Wartezeit) return SendClientMessage(playerid, COLOR_RED, "Die Bank kann zur Zeit nicht ausgeraubt werden.");
    if (g_iBankraubStatus == Bankraub_Aktiv) return SendClientMessage(playerid, COLOR_RED, "Ein Bankraub läuft gerade. ");
    if (!HasPlayerWeapon(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Bank nicht ohne eine Waffe ausrauben.");
    if (IsBeamter(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du bist ein Beamter.");
    if (GetOnlineExekutive(playerid) < 1) return SendClientMessage(playerid, COLOR_RED, "Es sind nicht genug Spieler der Exekutive online.");//2
    if(Spieler[playerid][pWantedCodes] < 50) return SendClientMessage(playerid, COLOR_RED, "Du benötigst mindestens 50 Hacker-Codes um den Bankraub zu starten!");

    Spieler[playerid][pWantedCodes] -= 50;
    SendClientMessage(playerid, COLOR_RED, "Das Hacken ist fehlgeschlagen! Die Polizei wurde informiert!");

    new breakingNewsMessage[128];
    format(breakingNewsMessage, sizeof(breakingNewsMessage), "[ZENTRALBANK] Die Los Santos Zentralbank wird gerade ausgeraubt!");
    SendClientMessageToAll(COLOR_RED, breakingNewsMessage);

    //SendClientMessage(playerid,COLOR_RED,"[ACHTUNG] Die Alarmanlage ist angegangen, die Polizei ist unterwegs! Halte 10 Minuten in der Bank aus!");

    g_tPulseBankPosition = SetTimerEx("Bank_Position", 1373, 1, "d", playerid);
    g_iBankraubStatus = Bankraub_Aktiv;
    g_unixBankraub = gettime();

    GangZoneShowForAll(g_iBankLS, 0xFF000090);
    GangZoneFlashForAll(g_iBankLS, 0x0000FF90);

   // SetPlayerAttachedObject( playerid, 0, 1550, 15, 0.000000, 0.280000, -0.310000, 0.000000, 15.000000, 0.000000, 1.000000, 1.000000, 1.000000 );

    KillTimer(g_tPulseBank);
    g_tPulseBank = INVALID_TIMER_ID;

    for(new i = 0; i < MAX_PLAYERS; i++){
        if(GetPlayerVirtualWorld(i) == VW_BANKINTERIORLS){
            if(IsBeamter(i)) continue;
            PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
            SetPlayerAttachedObject( i, 0, 1550, 15, 0.000000, 0.280000, -0.310000, 0.000000, 15.000000, 0.000000, 1.000000, 1.000000, 1.000000 );
            Spieler[i][pWanteds] += 6;
            SendClientMessage(i, COLOR_DARKRED, "Du hast ein Verbrechen begangen! (Raub/Überfall) Reporter: Polizeizentrale");
            format(breakingNewsMessage, sizeof(breakingNewsMessage), "Dein Aktuelles Wanted Level: %d", Spieler[i][pWanteds]);
            SendClientMessage(i, COLOR_YELLOW, breakingNewsMessage);
            format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: %s (ID: %d) hat ein Verbrechen begangen: Raub/Überfall, over.", GetName(i), i);
            SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
            SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
            SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
            SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
            SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);
            format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: Reporter: Polizeizentrale, Aktuelles Wantedlevel: %d, over", Spieler[i][pWanteds]);
            SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
            SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
            SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
            SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
            SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);
            SendClientMessage(i, COLOR_RED, "Du wurdest entdeckt! Die Sicherheitskameras haben alle Personen in der Bank indentifiziert!");
        }
    }
    return 1;
}



CMD:transporterausrauben(playerid,params[]){
    if(Spieler[playerid][pJob] == 12) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist selbst ein Geld-Transportfahrer.");
    }

    if( GetOnlineExekutive(playerid) <  1) {//2
        SendClientMessage(playerid, COLOR_RED, "Es sind nicht genug Polizisten online!");
        return 1;
    }
    if (IsPlayerExecutive(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du bist Teil der Exekutive.");

    new
        vID,
        fahrer = INVALID_PLAYER_ID;
    vID = GetPlayerVehicleID(playerid);
    for(new i=0;i<sizeof(geldt);i++)
    {
        if(vID == geldt[i])
        {
            for(new pID=0; pID < MAX_PLAYERS ; pID++)
            {
                if(JobVehicle[pID] == vID && JobVehicle[playerid] != vID)
                {
                    // Es wird gerade genutzt, möglich Raub!
                    if( Spieler[pID][pTransportActive] ) {
                        SendClientMessage(playerid, COLOR_GREEN, "Der Raub wurde gestartet!");
                        fahrer = pID;
                        JobVehicle[pID] = INVALID_VEHICLE_ID;
                        Spieler[pID][pTransportActive] = false;
                        JobVehicle[playerid] = vID;
                        break;
                    }
                }
            }
        }
    }
    if( !IsPlayerConnected(fahrer) ) {
        return SendClientMessage(playerid,COLOR_RED,"Zu spät");
    }
    new
        String[128];
    DisablePlayerCheckpointEx(fahrer);
    DisablePlayerCheckpointEx(playerid);

    format(String,sizeof(String),"Spieler %s stiehlt deinen Geldtransporter. Job fehlgeschlagen!",GetName(playerid));
    SendClientMessage(fahrer,COLOR_RED,String);
    SendClientMessage(playerid,COLOR_RED,"Du stiehlst den Geldtransporter. Die Polizei wurde alarmiert!");
    SendClientMessage(playerid,COLOR_YELLOW,"Bring den Geld Transporter so schnell wie möglich zum Checkpoint!");
    format(String,sizeof(String),"[NOTRUFZENTRALE] %s hat den Geldtransporter von %s gestohlen",GetName(playerid),GetName(fahrer));
    SendFraktionMessage(1, COLOR_RED, String);
    SendFraktionMessage(2, COLOR_RED, String);
    SendFraktionMessage(16, COLOR_RED, String);
    SendFraktionMessage(18, COLOR_RED, String);
    SendFraktionMessage(22, COLOR_RED, String);
    SetPlayerCheckpointEx(playerid,158.7957,-22.0976,1.5781,5.0,CP_DIEBSTAHL_GT);
    return 1;
}



CMD:wertpapiere(playerid){
    if(g_iBankraubStatus != Bankraub_Aktiv) return SendClientMessage(playerid, COLOR_RED, "Aktuell läuft kein Bankraub!");
    if (IsPlayerExecutive(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du bist Teil der Exekutive.");
    if(IsPlayerInRangeOfPoint(playerid, 1.0, 1696.2445, -1031.0490, 1340.7509)){
        if(Wertpap[0] == true) return SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Hier sind keine Wertpapiere zu finden!");
        LoopingAnim(playerid,"COP_AMBIENT","Coplook_shake",4.1, 1, 0, 0, 0, 0, 1);
        new String[128];
        format(String, sizeof(String), "{FFFFFF}- Wertpapiere stehlen -\n\n{6CD818}Nicht möglich");
        Update3DTextLabelText(Label_bankInteriorLs[0], 0x008080FF, String);
        FreezePlayer(playerid);
        SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Du suchst gerade nach Wertpapieren. Dies kann einen Moment dauern.");
        Wertpap[0] = true;
        wertpaptimer[playerid] = SetTimerEx("unfreezeWertpap", 30000, false, "i", playerid);
        new breakingNewsMessage[128];
        Spieler[playerid][pWanteds] += 2;
        SendClientMessage(playerid, COLOR_DARKRED, "Du hast ein Verbrechen begangen! (Diebstahl von Wertpapieren) Reporter: Polizeizentrale");
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "Dein Aktuelles Wanted Level: %d", Spieler[playerid][pWanteds]);
        SendClientMessage(playerid, COLOR_YELLOW, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: %s (ID: %d) hat ein Verbrechen begangen: Diebstahl von Wertpapieren, over.", GetName(playerid), playerid);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: Reporter: Polizeizentrale, Aktuelles Wantedlevel: %d, over", Spieler[playerid][pWanteds]);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);
    }else if(IsPlayerInRangeOfPoint(playerid, 1.0, 1693.9166,-1029.7340,1340.7509)){
        if(Wertpap[1] == true) return SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Hier sind keine Wertpapiere zu finden!");
        LoopingAnim(playerid,"COP_AMBIENT","Coplook_shake",4.1, 1, 0, 0, 0, 0, 1);
        new String[128];
        format(String, sizeof(String), "{FFFFFF}- Wertpapiere stehlen -\n\n{6CD818}Nicht möglich");
        Update3DTextLabelText(Label_bankInteriorLs[1], 0x008080FF, String);
        FreezePlayer(playerid);
        SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Du suchst gerade nach Wertpapieren. Dies kann einen Moment dauern.");
        Wertpap[1] = true;
        wertpaptimer[playerid] = SetTimerEx("unfreezeWertpap", 30000, false, "i", playerid);
        new breakingNewsMessage[128];
        Spieler[playerid][pWanteds] += 2;
        SendClientMessage(playerid, COLOR_DARKRED, "Du hast ein Verbrechen begangen! (Diebstahl von Wertpapieren) Reporter: Polizeizentrale");
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "Dein Aktuelles Wanted Level: %d", Spieler[playerid][pWanteds]);
        SendClientMessage(playerid, COLOR_YELLOW, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: %s (ID: %d) hat ein Verbrechen begangen: Diebstahl von Wertpapieren, over.", GetName(playerid), playerid);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: Reporter: Polizeizentrale, Aktuelles Wantedlevel: %d, over", Spieler[playerid][pWanteds]);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
    }else if(IsPlayerInRangeOfPoint(playerid, 1.0, 1692.5431,-1027.2142,1340.7509)){
        if(Wertpap[2] == true) return SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Hier sind keine Wertpapiere zu finden!");
        LoopingAnim(playerid,"COP_AMBIENT","Coplook_shake",4.1, 1, 0, 0, 0, 0, 1);
        new String[128];
        format(String, sizeof(String), "{FFFFFF}- Wertpapiere stehlen -\n\n{6CD818}Nicht möglich");
        Update3DTextLabelText(Label_bankInteriorLs[2], 0x008080FF, String);
        FreezePlayer(playerid);
        SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Du suchst gerade nach Wertpapieren. Dies kann einen Moment dauern.");
        Wertpap[2] = true;
        wertpaptimer[playerid] = SetTimerEx("unfreezeWertpap", 30000, false, "i", playerid);
        new breakingNewsMessage[128];
        Spieler[playerid][pWanteds] += 2;
        SendClientMessage(playerid, COLOR_DARKRED, "Du hast ein Verbrechen begangen! (Diebstahl von Wertpapieren) Reporter: Polizeizentrale");
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "Dein Aktuelles Wanted Level: %d", Spieler[playerid][pWanteds]);
        SendClientMessage(playerid, COLOR_YELLOW, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: %s (ID: %d) hat ein Verbrechen begangen: Diebstahl von Wertpapieren, over.", GetName(playerid), playerid);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: Reporter: Polizeizentrale, Aktuelles Wantedlevel: %d, over", Spieler[playerid][pWanteds]);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
    }else if(IsPlayerInRangeOfPoint(playerid, 1.0, 1696.9338,-1028.0938,1340.7509)){
        if(Wertpap[3] == true) return SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Hier sind keine Wertpapiere zu finden!");
        LoopingAnim(playerid,"COP_AMBIENT","Coplook_shake",4.1, 1, 0, 0, 0, 0, 1);
        new String[128];
        format(String, sizeof(String), "{FFFFFF}- Wertpapiere stehlen -\n\n{6CD818}Nicht möglich");
        Update3DTextLabelText(Label_bankInteriorLs[3], 0x008080FF, String);
        FreezePlayer(playerid);
        SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Du suchst gerade nach Wertpapieren. Dies kann einen Moment dauern.");
        Wertpap[3] = true;
        wertpaptimer[playerid] = SetTimerEx("unfreezeWertpap", 30000, false, "i", playerid);
        new breakingNewsMessage[128];
        Spieler[playerid][pWanteds] += 2;
        SendClientMessage(playerid, COLOR_DARKRED, "Du hast ein Verbrechen begangen! (Diebstahl von Wertpapieren) Reporter: Polizeizentrale");
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "Dein Aktuelles Wanted Level: %d", Spieler[playerid][pWanteds]);
        SendClientMessage(playerid, COLOR_YELLOW, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: %s (ID: %d) hat ein Verbrechen begangen: Diebstahl von Wertpapieren, over.", GetName(playerid), playerid);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: Reporter: Polizeizentrale, Aktuelles Wantedlevel: %d, over", Spieler[playerid][pWanteds]);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
    }else{
        SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Hier sind keine Wertpapiere zu finden!");
    }
    return 1;
}




new c4sprengen[MAX_PLAYERS];
new c4id = 0;
new Float:c4x = 0.0;
new Float:c4y = 0.0;
new Float:c4z = 0.0;
new bool:isC4 = false;

CMD:c4legen(playerid){
    if(g_iBankraubStatus != Bankraub_Aktiv) return SendClientMessage(playerid, COLOR_RED, "Aktuell läuft kein Bankraub!");
    if(Spieler[playerid][pC4] < 1) return SendClientMessage(playerid, COLOR_RED, "Du hast kein C4 zum legen dabei!");
    if(isC4 == true) return SendClientMessage(playerid, COLOR_RED, "Es kann nur ein Tresor gleichzeigt gesprengt werden!");
    if (IsPlayerExecutive(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du bist Teil der Exekutive.");
    if(IsPlayerInRangeOfPoint(playerid, 1.0, 1695.7092,-1049.6833,1334.2904)){
        if(Tresor[0] == true) return SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Hier kannst du kein C4 legen!");
        OnePlayAnim(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0); // Place Bomb
        new String[128];
        format(String, sizeof(String), "{FFFFFF}- Tresore sprengen -\n\n{6CD818}Nicht möglich");
        Update3DTextLabelText(Label_bankInteriorLs[5], 0x008080FF, String);
        c4id = CreateObject(1654, 1695.7092,-1049.6833,1334.1500, 0.0, 0.0, 0.0);
        c4x = 1695.7092;
        c4y = -1049.6833;
        c4z = 1334.2000;
        c4sprengen[playerid] = SetTimerEx("c4explodieren", 90000, false, "i", playerid);
        for(new i = 0; i < MAX_PLAYERS; i++){
            if(GetPlayerVirtualWorld(i) == VW_BANKINTERIORLS){
                SendClientMessage(i, COLOR_BLUE, "[BANKRAUB] {FFFFFF}Achtung! Es wurde C4 im Tresorraum gelegt!");
            }
        }
        Tresor[0] = true;
        isC4 = true;
        new breakingNewsMessage[128];
        Spieler[playerid][pWanteds] += 4;
        SendClientMessage(playerid, COLOR_DARKRED, "Du hast ein Verbrechen begangen! (Sprengen von Tresoren) Reporter: Polizeizentrale");
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "Dein Aktuelles Wanted Level: %d", Spieler[playerid][pWanteds]);
        SendClientMessage(playerid, COLOR_YELLOW, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: %s (ID: %d) hat ein Verbrechen begangen: Sprengen von Tresoren, over.", GetName(playerid), playerid);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: Reporter: Polizeizentrale, Aktuelles Wantedlevel: %d, over", Spieler[playerid][pWanteds]);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);
        Spieler[playerid][pC4] --;
    }else if(IsPlayerInRangeOfPoint(playerid, 1.0, 1692.2316,-1048.0509,1334.2904)){
        if(Tresor[1] == true) return SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Hier kannst du kein C4 legen!");
        OnePlayAnim(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0); // Place Bomb
        new String[128];
        format(String, sizeof(String), "{FFFFFF}- Tresore sprengen -\n\n{6CD818}Nicht möglich");
        Update3DTextLabelText(Label_bankInteriorLs[6], 0x008080FF, String);
        c4id = CreateObject(1654, 1692.2316,-1048.0509,1334.1500, 0.0, 0.0, 0.0);
        c4x = 1692.2316;
        c4y = -1048.0509;
        c4z = 1334.1500;
        c4sprengen[playerid] = SetTimerEx("c4explodieren", 90000, false, "i", playerid);
        for(new i = 0; i < MAX_PLAYERS; i++){
            if(GetPlayerVirtualWorld(i) == VW_BANKINTERIORLS){
                SendClientMessage(i, COLOR_BLUE, "[BANKRAUB] {FFFFFF}Achtung! Es wurde C4 im Tresorraum gelegt!");
            }
        }
        Tresor[1] = true;
        isC4 = true;
        new breakingNewsMessage[128];
        Spieler[playerid][pWanteds] += 4;
        SendClientMessage(playerid, COLOR_DARKRED, "Du hast ein Verbrechen begangen! (Sprengen von Tresoren) Reporter: Polizeizentrale");
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "Dein Aktuelles Wanted Level: %d", Spieler[playerid][pWanteds]);
        SendClientMessage(playerid, COLOR_YELLOW, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: %s (ID: %d) hat ein Verbrechen begangen: Sprengen von Tresoren, over.", GetName(playerid), playerid);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: Reporter: Polizeizentrale, Aktuelles Wantedlevel: %d, over", Spieler[playerid][pWanteds]);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);
        Spieler[playerid][pC4] --;
    }else if(IsPlayerInRangeOfPoint(playerid, 1.0, 1687.9445,-1047.8927,1334.2904)){
        if(Tresor[2] == true) return SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Hier kannst du kein C4 legen!");
        OnePlayAnim(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0); // Place Bomb
        new String[128];
        format(String, sizeof(String), "{FFFFFF}- Tresore sprengen -\n\n{6CD818}Nicht möglich");
        Update3DTextLabelText(Label_bankInteriorLs[7], 0x008080FF, String);
        c4id = CreateObject(1654, 1687.9445,-1047.8927,1334.1500, 0.0, 0.0, 0.0);
        c4x = 1687.9445;
        c4y = -1047.8927;
        c4z = 1334.1500;
        c4sprengen[playerid] = SetTimerEx("c4explodieren", 90000, false, "i", playerid);
        for(new i = 0; i < MAX_PLAYERS; i++){
            if(GetPlayerVirtualWorld(i) == VW_BANKINTERIORLS){
                SendClientMessage(i, COLOR_BLUE, "[BANKRAUB] {FFFFFF}Achtung! Es wurde C4 im Tresorraum gelegt!");
            }
        }
        Tresor[2] = true;
        isC4 = true;
        new breakingNewsMessage[128];
        Spieler[playerid][pWanteds] += 4;
        SendClientMessage(playerid, COLOR_DARKRED, "Du hast ein Verbrechen begangen! (Sprengen von Tresoren) Reporter: Polizeizentrale");
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "Dein Aktuelles Wanted Level: %d", Spieler[playerid][pWanteds]);
        SendClientMessage(playerid, COLOR_YELLOW, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: %s (ID: %d) hat ein Verbrechen begangen: Sprengen von Tresoren, over.", GetName(playerid), playerid);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: Reporter: Polizeizentrale, Aktuelles Wantedlevel: %d, over", Spieler[playerid][pWanteds]);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);
        Spieler[playerid][pC4] --;
    }else if(IsPlayerInRangeOfPoint(playerid, 1.0, 1684.5870,-1049.8440,1334.2904)){
        if(Tresor[3] == true) return SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Hier kannst du kein C4 legen!");
        OnePlayAnim(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0); // Place Bomb
        new String[128];
        format(String, sizeof(String), "{FFFFFF}- Tresore sprengen -\n\n{6CD818}Nicht möglich");
        Update3DTextLabelText(Label_bankInteriorLs[8], 0x008080FF, String);
        c4id = CreateObject(1654, 1684.5870,-1049.8440,1334.2904, 0.0, 0.0, 0.0);
        c4x = 1684.5870;
        c4y = -1049.8440;
        c4z = 1334.1500;
        c4sprengen[playerid] = SetTimerEx("c4explodieren", 90000, false, "i", playerid);
        for(new i = 0; i < MAX_PLAYERS; i++){
            if(GetPlayerVirtualWorld(i) == VW_BANKINTERIORLS){
                SendClientMessage(i, COLOR_BLUE, "[BANKRAUB] {FFFFFF}Achtung! Es wurde C4 im Tresorraum gelegt!");
            }
        }
        Tresor[3] = true;
        isC4 = true;
        new breakingNewsMessage[128];
        Spieler[playerid][pWanteds] += 4;
        SendClientMessage(playerid, COLOR_DARKRED, "Du hast ein Verbrechen begangen! (Sprengen von Tresoren) Reporter: Polizeizentrale");
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "Dein Aktuelles Wanted Level: %d", Spieler[playerid][pWanteds]);
        SendClientMessage(playerid, COLOR_YELLOW, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: %s (ID: %d) hat ein Verbrechen begangen: Sprengen von Tresoren, over.", GetName(playerid), playerid);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);
        format(breakingNewsMessage, sizeof(breakingNewsMessage), "HQ: Reporter: Polizeizentrale, Aktuelles Wantedlevel: %d, over", Spieler[playerid][pWanteds]);
        SendFraktionMessage(1, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(2, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(16, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(18, COLOR_LIGHTRED, breakingNewsMessage);
        SendFraktionMessage(22, COLOR_LIGHTRED, breakingNewsMessage);
        Spieler[playerid][pC4] --;
    }else{
        SendClientMessage(playerid, COLOR_RED, "[BANKRAUB] {FFFFFF}Hier kannst du kein C4 legen!");
    }
    return 1;
}



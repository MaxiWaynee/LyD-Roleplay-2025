#include <YSI\y_hooks>

CMD:hmaske(playerid,params[]) {
    return cmd_hitmanmaske(playerid,params);
}

CMD:hitmanmaske(playerid,params[]) {
    if( Spieler[playerid][pFraktion] != 14 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du bist kein Agency Mitglied!");
    }
    if( Spieler[playerid][bMaske] ) {
        KillTimer(Spieler[playerid][tMaske]);
        Spieler[playerid][bMaske] = false;
        SetPlayerColor(playerid, ( GetPlayerColor(playerid) | 0xFF ) );
        for (new i ; i < MAX_PLAYERS ; i++) {
            ShowPlayerNameTagForPlayer(i,playerid,1);
        }
        HITMAN_SKIN(playerid);
        return SendClientMessage(playerid, COLOR_ORANGE, "Du hast deine Maske abgenommen");
    }
    if (Spieler[playerid][pJailed]) return SendClientMessage(playerid, COLOR_RED, "Du bist im Gefängnis und kannst hier keine Maske aufsetzen.");
    SendClientMessage(playerid,COLOR_GREEN,"Du hast deine Maske aufgezogen! Mit /hmaske ziehst du sie wieder ab.");
    Spieler[playerid][bMaske] = true;
    SetPlayerColor(playerid, ( GetPlayerColor(playerid) & 0xFFFFFF00 ) );
    for(new i ; i < MAX_PLAYERS ; i++) {
        ShowPlayerNameTagForPlayer(i,playerid,0);
    }
    
    // Random Skin
    oldskin[playerid] = GetPlayerSkin(playerid);
    SetPlayerSkin(playerid, rskins[random(46)]);
    SendClientMessage(playerid, COLOR_YELLOW, "[INFO] "COLOR_HEX_WHITE"Du hast deine Maske aufgezogen und einen neuen Skin erhalten.");
    return 1;
}


CMD:arz(playerid,params[]) {
    if( Spieler[playerid][pFraktion] != 14 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Agency-Mitglied");
    }
    new
        giveid;
    if( sscanf(params,"u",giveid)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Arz [Spieler/ID]");
    }
    if( !IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid,COLOR_ORANGE,"Der Spieler wurde nicht gefunden");
    }

    new
        Float:x,
        Float:y,
        Float:z,
        modelid,
        vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) {
        return SendClientMessage(playerid,COLOR_RED,"Du bist in keinem Fahrzeug");
    }
    /*if( GetPlayerState(playerid) != PLAYER_STATE_DRIVER ) {
        return SendClientMessage(playerid,COLOR_RED,"Du musst der Fahrer dieses Fahrzeuges sein");
    }*/
    modelid = GetVehicleModel(vehicleid);
    if( GetVehicleSeats(modelid) <= 1 ) {
        return SendClientMessage(playerid,COLOR_RED,"Dieses Fahrzeuge besitzt keinen Beifahrer Sitz");
    }
    GetPlayerPos(playerid,x,y,z);
    new
        vehicleid_ex;
    vehicleid_ex = GetPlayerVehicleID(giveid);
    if( !IsPlayerInRangeOfPoint(giveid,19.0,x,y,z) ) {
        return SendClientMessage(playerid,COLOR_RED,"Der Spieler ist nicht in deiner nähe");
    }
    if( !Spieler[giveid][bKidnapped] && Cuffed[giveid] == 0 ) {
        return SendClientMessage(playerid,COLOR_RED,"Der Spieler wird gerade nicht entführt");
    }
    if( Spieler[playerid][iWheelmanID] != INVALID_PLAYER_ID ) {
        return SendClientMessage(playerid,COLOR_RED,"Du versuchst gerade bereits einen Spieler zu befreien");
    }
    if( !vehicleid_ex) {
        return SendClientMessage(playerid,COLOR_RED,"Die Person sitzt in keine Fahrzeug");
    }
    if( GetPlayerState(giveid) != PLAYER_STATE_PASSENGER ) {
        return SendClientMessage(playerid,COLOR_RED,"Die Person ist bereits kein Beifahrer");
    }
    if( vehicleid == vehicleid_ex ) {
        return SendClientMessage(playerid,COLOR_RED,"Die Person ist bereits in deinem Fahrzeug");
    }
    if( GetFreeVehicleSeat(vehicleid) == -1 ) {
        return SendClientMessage(playerid,COLOR_RED,"Dein Fahrzeug hat keinen Platz für die Person");
    }
    new
        entfuehrer,
        String[128];
    Spieler[playerid][tWheelman] = SetTimerEx("Pulse_Wheelman",1327,true,"ddd",playerid,giveid,gettime() + 11 );

    entfuehrer = VehicleDriverID( vehicleid_ex );
    //printf("entfuehrer %d GetPlayerEntfuehrer(%d)",entfuehrer,giveid);
    format(String,sizeof(String),"Du versuchst %s zu befreien! Bleibe 10 Sekunden am Fahrzeuge dran",GetName(giveid));
    SendClientMessage(playerid,COLOR_YELLOW,String);

    format(String,sizeof(String),"Ein Agency-Agent versucht dich von %s zu befreien",GetName(entfuehrer) );
    SendClientMessage(giveid,COLOR_YELLOW,String);

    format(String,sizeof(String),"Ein Agency-Agent versucht %s aus dem Fahrzeug befreien",GetName(giveid));
    SendClientMessage(entfuehrer,COLOR_YELLOW,String);

    Spieler[playerid][iWheelmanID] = giveid;
    return 1;
}


CMD:agbefreien(playerid,params[]) {
    new giveid;
    if (sscanf(params, "u", giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Agbefreien [Spieler/ID]");
    if (Spieler[playerid][pFraktion] != 14) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Agency-Mitglied.");
    if (!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler wurde nicht gefunden.");

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);

    if (!IsPlayerInRangeOfPoint(giveid, 5.0, x, y, z)) return SendClientMessage(playerid, COLOR_RED, "Du bist zu weit vom Spieler entfernt");
    if (Spieler[giveid][bAugenbinde]) return SendClientMessage(playerid, COLOR_ORANGE, "Der Spieler hat noch eine Augenbinde! Entferne sie erst mit /Augenbinde");
    if (Spieler[giveid][bMundbinde]) return SendClientMessage(playerid, COLOR_ORANGE, "Der Spieler hat noch eine Mundbinde! Entferne sie erst mit /Mundbinde");

    if (Cuffed[giveid]) {
        new String[128];
        format(String, sizeof(String), "Du hast den Spieler %s erfolgreich befreit.", GetName(giveid));
        SendClientMessage(playerid, COLOR_YELLOW, String);
        format(String, sizeof(String), "Ein Agency-Mitglied hat dich entgültig befreit. Du kannst dich nun wieder bewegen.");
        SendClientMessage(giveid, COLOR_YELLOW, String);
        UnfreezePlayer(giveid);
        SetPlayerSpecialAction(giveid, SPECIAL_ACTION_NONE);
        RemovePlayerAttachedObject(giveid, ATTACHED_INDEX_HANDSCHELLE);
        Cuffed[giveid] = 0;
    } else
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat keine Handschellen an.");

    return 1;
}


CMD:agpreis(playerid,params[]) {
    if (Spieler[playerid][pFraktion] != 14) return SendClientMessage(playerid, COLOR_RED, "Dieser Befehl ist nur für Wheelmen möglich.");

    new giveid, modus;

    if (sscanf(params, "ud", giveid, modus) || (modus < 1 || modus > 6)) {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Agpreis [ID] [Nummer]");
        SendClientMessage(playerid, COLOR_RED, "1. Chauffeur - 8.000$");
        SendClientMessage(playerid, COLOR_RED, "2. Personenschutz - 25.000$");
        SendClientMessage(playerid, COLOR_RED, "3. Befreiung von Entführung - 20.000$");
        SendClientMessage(playerid, COLOR_RED, "4. Befreiung von Festnahmen - 25.000$");
        SendClientMessage(playerid, COLOR_RED, "5. Alcatraz Gefangenenbefreiung - 50.000$");
        SendClientMessage(playerid, COLOR_RED, "6. GangJail Gefangenenbefreiung - 15.000$");

        return 1;
    }

    if (!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (giveid == playerid) return SendClientMessage(playerid, COLOR_RED, "Diese Aktion ist nicht möglich.");

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    if (!IsPlayerInRangeOfPoint(giveid, 5.0, x, y, z)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");

    new String[128];
    format(String, sizeof(String), "{FFFFFF}Agency\nBetrag: $%s\nDienstleistung: %s", AddDelimiters(g_WheelmenD[modus][W_iPrice]), g_WheelmenD[modus][W_sName]);
    ShowPlayerDialog(giveid, DIALOG_WPREIS, DIALOG_STYLE_MSGBOX, "Rechnung", String, "Annehmen", "Ablehnen");
    Spieler[giveid][pFLehrer] = playerid;
    Spieler[giveid][pFModus] = modus;
    format(String, sizeof(String), "* Du hast %s ein Angebot unterbreitet. Leistung: %s", GetName(giveid), g_WheelmenD[modus][W_sName]);
    SendClientMessage(playerid, COLOR_YELLOW, String);
    return 1;
}



CMD:hitmanwaffen(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, g_fraktion[14][Fr_WaffenX],g_fraktion[14][Fr_WaffenY],g_fraktion[14][Fr_WaffenZ]))//Hitman
    {
        if(Spieler[playerid][pGunLic] == 0)return SendClientMessage(playerid, COLOR_RED, "Du besitzt keinen Waffenschein.");
        if(CheckMoney(playerid) < 8000)return SendClientMessage(playerid, COLOR_RED, "Du benötigst $8000.");
        if(!(Spieler[playerid][pFraktion] == 14))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Agency-Mitglied.");
        GiveHitmanWeapons(playerid);
        SendClientMessage(playerid, COLOR_GREEN, "Du hast dich ausgeruestet. (Desert Eagle, MP5, Sniper, Messer)");
        GameTextForPlayer(playerid, "~r~-$8000", 2000, 1);
        GivePlayerCash(playerid, -8000);
	}
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, HITMANBASE_SPAWN2_POINT))//Hitman2
    {
        if(Spieler[playerid][pGunLic] == 0)return SendClientMessage(playerid, COLOR_RED, "Du besitzt keinen Waffenschein.");
        if(CheckMoney(playerid) < 8000)return SendClientMessage(playerid, COLOR_RED, "Du benötigst $8000.");
        if(!(Spieler[playerid][pFraktion] == 14))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Agency-Mitglied.");
        GiveHitmanWeapons(playerid);
        SendClientMessage(playerid, COLOR_GREEN, "Du hast dich ausgeruestet. (Desert Eagle, MP5, Sniper, Messer)");
        GameTextForPlayer(playerid, "~r~-$8000", 2000, 1);
        GivePlayerCash(playerid, -8000);
    }
    return 1;
}


CMD:rechnung(playerid, params[])
{
    new pID, grund[64], preis, string[256];
    if(!(Spieler[playerid][pFraktion] == 14))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied der Agency");
    if(sscanf(params, "uis[64]", pID, preis, grund))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Rechnung [SpielerID/Name] [Preis] [Grund]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if(preis < 1 || preis > 100000)return SendClientMessage(playerid, COLOR_RED, "Der Preis sollte zwischen 1 und 100000$ liegen.");
    if(IsPlayerInRangeOfPoint(pID, 10.0, x,y,z))
    {
        format(string, sizeof(string), "Du hast %s einen Rechnung in Höhe von $%s ausgestellt. Grund: %s", GetName(pID), AddDelimiters(preis), grund);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        ZettelID[pID] = playerid;
        ZettelPreis[pID] = preis;
        format(string, sizeof(string), COLOR_HEX_BLUE"Von: "COLOR_HEX_WHITE"%s\n"COLOR_HEX_BLUE"Preis: "COLOR_HEX_WHITE"$%s\n"COLOR_HEX_BLUE"Grund: "COLOR_HEX_WHITE"%s\nNehme diese Rechnung an, indem du auf \"Annehmen\" klickst.", GetName(playerid), AddDelimiters(preis), grund);
        ShowPlayerDialog(pID, DIALOG_SZETTEL1, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"Rechnung", string, "Annehmen", "Abbrechen");
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Umgebung.");
        return 1;
    }
    return 1;
}



CMD:acceptag(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/acceptag [SpielerID/Name]");
    if(Spieler[playerid][pFraktion] != 14) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Agency-Mitglied");
    if(!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online!");
    if(GetPlayerInterior(pID) > 0) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in einem Gebäude.");
    if(NeedWHEEL[pID] == 0) return SendClientMessage(playerid, COLOR_ORANGE, "Der Spieler benötigt keinen Agency-Mitglied. Verwende /sliste um die Service-Liste zu sehen.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x,y,z);
    SetPlayerCheckpointEx(playerid, x,y,z, 5.0, CP_ACCEPTKFZ);
    format(string, sizeof(string), "* Du hast den Service-Anruf von %s angenommen, ein Roter Punkt wurde auf der Karte markiert.", GetName(pID));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "* Ein Agency-Mitglied hat deinen Service-Anruf angenommen und ist nun unterwegs zu dir!");
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    NeedWHEEL[pID] = 0;
    return 1;
}

CMD:alcbefreien(playerid, params[]) {
    return cmd_knastbefreien(playerid, params);
}

CMD:knastbefreien(playerid, params[]) {
    new pID, dialogOfferText[256];

    if (sscanf(params, "u", pID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /knastbefreien [Spieler ID / Name]");
    if (Spieler[playerid][pFraktion] != 14) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Agency-Mitglied!");
    if (!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online!");
    if (pID == playerid) return SendClientMessage(playerid, COLOR_RED, "Du kannst dir selber keine Befreiung anbieten.");
    if (Spieler[pID][pJailed] != 2) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht im Alcatraz gefangen.");
    if (Spieler[playerid][pJailed] == 2) return SendClientMessage(playerid, COLOR_RED, "Du bist selber im Alcatraz gefangen.");
    if (!(IsPlayerInRangeOfPoint(playerid, 10.0, ALCATRAZ_JAILEDGATE_COORDS) && IsPlayerInRangeOfPoint(pID, 10.0, ALCATRAZ_JAILEDGATE_COORDS))) return SendClientMessage(playerid, COLOR_RED, "Ihr seid nicht beide nahe genug am Alcatraz-Tor.");
    if (GetPVarInt(GetPVarInt(playerid, "WHEELMAN.CUSTOMER"), "WHEELMAN.STATUS") == WHEELMAN_STATUS_ESCAPING) return SendClientMessage(playerid, COLOR_RED, "Du befreist bereits jemanden aus dem Alcatraz.");
    if (GetPVarInt(pID, "WHEELMAN.STATUS") == WHEELMAN_STATUS_HAS_OFFER) return SendClientMessage(playerid, COLOR_RED, "Der Gefangene hat bereits ein Befreiungsangebot erhalten.");
    if (GetPVarInt(pID, "WHEELMAN.STATUS") == WHEELMAN_STATUS_ESCAPING) return SendClientMessage(playerid, COLOR_RED, "Der Gefangene wird bereits von einem Agency-Agent befreit.");
    if (CheckMoney(pID) < 50000) return SendClientMessage(playerid, COLOR_RED, "Der Gefangene hat nicht genügend Geld dabei, um dich zu bezahlen.");

    new message[128];
    format(message, sizeof(message), "Du hast %s eine Alcatraz-Befreiung angeboten.", GetName(pID));
    SendClientMessage(playerid, COLOR_YELLOW, message);

    format(dialogOfferText, sizeof(dialogOfferText), COLOR_HEX_WHITE "Ein Agency-Mitglied bietet dir eine Befreiung aus dem Alcatraz an.\nDie Befreiung kostet dich " COLOR_HEX_ORANGE "$50.000 " COLOR_HEX_WHITE "und dauert " COLOR_HEX_ORANGE "4 Minuten" COLOR_HEX_WHITE ".\nDu bezahlst erst bei erfolgreicher Befreiung.");
    SetPVarInt(pID, "WHEELMAN.STATUS", WHEELMAN_STATUS_HAS_OFFER);
    SetPVarInt(pID, "WHEELMAN.WHEELMAN", playerid);
    return ShowPlayerDialog(pID, DIALOG_WHEELMAN_OFFER, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE "Agency Befreiungsangebot:", dialogOfferText, "Akzeptieren", "Ablehnen");
}
 
CMD:atorhacken(playerid, params[]) {
    if (Spieler[playerid][pFraktion] != 14) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Agency-Mitglied");
    if (!IsPlayerInRangeOfPoint(playerid, 10.0, ALCATRAZ_ENTRANCEGATE_FOR_RANGE_COORDS)) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Alcatraz-Tors.");
    if (gettime() < alcatrazGateHackTimestamp) return SendClientMessage(playerid, COLOR_RED, "Das Tor wird bereits gehackt!");
   
    new message[128], Float:fX, Float:fY, Float:fZ;
    GetDynamicObjectPos(object_alcatraz_entranceGate, fX, fY, fZ);
    if (fZ == ALCATRAZ_ENTRANCEGATE_OPEN_Z) return SendClientMessage(playerid, COLOR_RED, "Das Tor ist bereits offen.");
 
    GetPlayerPos(playerid, fX, fY, fZ);
    format(message, sizeof(message), "** Ein Agency-Mitglied beginnt das Alcatraz-Tor zu hacken **");
    SendRoundMessage(fX, fY, fZ, COLOR_ORANGE, message, 20.0);
 
    if (random(2)) {
        SendFraktionMessage(1, COLOR_LIGHTRED, "[HOCHSICHERHEITSTRAKT] Ein Agency Mitglied versucht das Alcatraz-Tor zu hacken!");
        SendFraktionMessage(2, COLOR_LIGHTRED, "[HOCHSICHERHEITSTRAKT] Ein Agency Mitglied versucht das Alcatraz-Tor zu hacken!");
        SendFraktionMessage(16, COLOR_LIGHTRED, "[HOCHSICHERHEITSTRAKT] Ein Agency Mitglied versucht das Alcatraz-Tor zu hacken!");
        SendFraktionMessage(18, COLOR_LIGHTRED, "[HOCHSICHERHEITSTRAKT] Ein Agency Mitglied versucht das Alcatraz-Tor zu hacken!");
        SendFraktionMessage(22, COLOR_LIGHTRED, "[HOCHSICHERHEITSTRAKT] Ein Agency Mitglied versucht das Alcatraz-Tor zu hacken!");
 
        SendClientMessage(playerid, COLOR_RED, "Die Polizei hat dich in den Log-Einträgen erwischt und hat die Zentrale benachrichtigt.");
    }
 
    alcatrazGateHackTimestamp = gettime() + 30;
    return SetTimerEx("WHEELMAN_gateHack_pulse", 2000, false, "dd", playerid, alcatrazGateHackTimestamp);
}




CMD:hwerbung(playerid,params[]) {
    new tick = gettime();

    if( !IsPlayerInRangeOfPoint(playerid, 5.0, -1061.2728, -1201.9796, 129.4548) && !IsPlayerInRangeOfPoint(playerid, 5.0, 1524.3748,-1457.1121,9.5000))return SendClientMessage(playerid,COLOR_RED,"Du bist nicht am Agency-Werbeplatz.");
    if( !(( Spieler[playerid][pFraktion] == 14)) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Agency-Mitglied!");
    }
    if( Spieler[playerid][pLevel] < 3 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du musst Level 3 sein um eine Werbung zu schreiben!");
    }
    if( g_unixWerbungHitman > tick ) {
        return SendClientMessage(playerid, COLOR_RED, "Die letzte H-Werbung ist noch keine 8 Minuten alt.");
    }
    ShowPlayerDialog(playerid,DIALOG_HWERBUNG,DIALOG_STYLE_INPUT,"Werbung Kaufen","Du kannst eine Werbung kaufen.\nPro Zeichen fallen 100$ Kosten an","Absenden","Abbrechen");
    return 1;
}



CMD:killauftrag(playerid,params[]) {
    new giveid, preis;

    if (sscanf(params,"ud",giveid,preis)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Killauftrag [Spieler] [Kopfgeld]");
    if (Spieler[playerid][pLevel] < 3) return SendClientMessage(playerid, COLOR_RED, "Du kannst erst ab Level 3 Kopfgeld setzen.");
    if (!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (Spieler[playerid][pFraktion] == 14) return SendClientMessage(playerid, COLOR_RED, "Du kannst als Agency-Mitglied keine Aufträge setzen.");
    if (playerid == giveid) return SendClientMessage(playerid, COLOR_RED, "Du kannst dir selber kein Kopfgeld geben.");
    if (Spieler[giveid][pLevel] < 3) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist noch unter Level 3.");
    if (Spieler[playerid][pKopfgeldID] != INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "Du hast bereits ein Kopfgeld auf einen Spieler gesetzt.");
    if (!(15000 <= preis <= 100000)) return SendClientMessage(playerid, COLOR_RED, "Das Kopfgeld muss zwischen $15.000 und $100.000 liegen");
    if (CheckMoney(playerid) < preis) return SendClientMessage(playerid, COLOR_RED, "Das gesetzte Kopfgeld besitzt du nicht");
    if(Spieler[giveid][pFraktion] == 3 || Spieler[giveid][pFraktion] == 5) return SendClientMessage(playerid,COLOR_RED,"Auf Ordnungsbeamte und Sanitäter kannst du keine Aufträge setzen.");
    if(KillSperre[giveid] >= 3 && KillBlackSperre[giveid] == 0) return SCMFormatted(playerid,COLOR_RED,"[SPERRE]{FFFFFF} Auf %s wurden bereits 3 Aufträge ausgeführt.",GetName(giveid));
    if(KillSperre[giveid] >= 7 && KillBlackSperre[giveid] == 1) return SCMFormatted(playerid,COLOR_RED,"[SPERRE]{FFFFFF} Auf %s wurden bereits 7 Aufträge ausgeführt.",GetName(giveid));

    new String[128];
    format(String,sizeof(String),"Spieler %s möchte das %s ermordet wird, Preis $%s. Auftrag mit '/Accept Hitman' annehmen!", GetName(playerid),GetName(giveid), AddDelimiters(preis));
    SendFraktionMessage( 14, COLOR_YELLOW, String);
    format(String,sizeof(String),"Du hast $%s auf die Ermordung von %s gesetzt! Warte bis es ein Agency-Mitglied annimmt.", AddDelimiters(preis),GetName(giveid));
    SendClientMessage(playerid,COLOR_BLUE,String);
    GivePlayerCash(playerid,-preis);

    format(String,sizeof(String),"Killauftrag von %s auf %s ($%s)",GetName(playerid),GetName(giveid), AddDelimiters(preis));
    HitmanLog(String);

    Spieler[playerid][pKopfgeldID] = giveid;
    Spieler[playerid][pKopfgeld] = preis;
    Spieler[playerid][pKopfgeldStatus] = false;
    return 1;
}

CMD:hrelease(playerid, params[]) {
    if (Spieler[playerid][pFraktion] != 14) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Agency-Mitglied.");
    if (SelectedPlayer[playerid] == INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "Du hast keinen Auftrag angenommen.");

    new message[128];
    format(message, sizeof(message), "%s hat den Auftrag von %s auf %s wieder freigegeben.", GetName(playerid), GetName(SelectedPlayer[playerid]), GetName(Spieler[SelectedPlayer[playerid]][pKopfgeldID]));
    SendFraktionMessage(14, COLOR_YELLOW, message);

    SendClientMessage(SelectedPlayer[playerid], COLOR_YELLOW, "Dein Auftragskiller hat den Auftrag wieder freigegeben.");
    SendClientMessage(SelectedPlayer[playerid], COLOR_YELLOW, "Dein Auftrag kann wieder von anderen Hitmen angenommen werden.");

    Spieler[SelectedPlayer[playerid]][pKopfgeldStatus] = false;
    SelectedPlayer[playerid] = INVALID_PLAYER_ID;
    Spieler[playerid][pHitmenAuftragID] = INVALID_PLAYER_ID; // fuck berkan

    // Skin zurückgeben
    /*SetPlayerSkin(playerid, oldskin[playerid]);
    SendClientMessage(playerid, COLOR_YELLOW, "[INFO] "COLOR_HEX_WHITE"Du hast deinen alten Skin zurück bekommen.");*/
    return 1;
}




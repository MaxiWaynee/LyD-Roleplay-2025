#include <YSI\y_hooks>


CMD:spritlager(playerid){
    if(Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "[SPRITLAGER] {FFFFFF}Deine Fraktion besitzt kein Spritlager!");
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, 764.9532,347.7378,20.04583)) return SendClientMessage(playerid, COLOR_RED, "[SPRITLAGER] {FFFFFF}Du bist nicht am Spritlager!");
    SCMFormatted(playerid, COLOR_YELLOW, "[SPRITLAGER] {FFFFFF}In Spritlager befinden sich aktuell %i Liter.", g_fraktion[15][Fr_FSSprit]);
    return 1;
}

CMD:spritklauen(playerid, params[]) {
    new veh = GetPlayerVehicleID(playerid), vehiclemodel = GetVehicleModel(veh), string[128], menge;
 	if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
	if(Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid,COLOR_RED,"[FEHLER] {FFFFFF}Du bist kein Nine Demons.");
	if(Spieler[playerid][pRank] < 1) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst mindestens Rank 1 sein.");
	if(!GetPVarInt(playerid, "STARTSPRIT")) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Beginne erst mit der Mission (/Startsprit)");
	if(GetPVarInt(playerid, "SPRITROB")) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du führst bereits die Mission durch!");
	if(vehiclemodel != 499) return SendClientMessage(playerid, COLOR_RED,"[INFO] {FFFFFF}Du bist in keinem Benson!");
	if(FrakCarInfo[veh][f_frak] != 15)return SendClientMessage(playerid, COLOR_RED,"[FEHLER] {FFFFFF}Der Benson gehört nicht zu deiner Fraktion.");
 	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid,COLOR_RED,"[INFO] {FFFFFF}Du musst der Fahrer des Bensons sein!");
 	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 268.9609,1384.2981,10.1610)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht an der Öl-Raffinerie.");
 	if(sscanf(params, "d", menge))return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Spritklauen [Liter]");
 	if(menge < 0 || menge > 400)return SendClientMessage(playerid, COLOR_RED,"[FEHLER] {FFFFFF}Die Menge muss mind. 1 Liter betragen oder max. 400 Liter");
 	
 	SCMFormatted(playerid, COLOR_GREEN, "[INFO] {FFFFFF}Du fängst an %d Liter Sprit zu klauen! Halte es 5 Minuten aus.", menge);
 	SpritTimer[playerid] = SetTimerEx("RobSprit", 300000, false, "d", playerid); // <== 5 Minuten
    SpritCheckTimer[playerid] = SetTimerEx("RobSpritCheck", 3000, true, "d", playerid); // <== 5 Minuten
 	SetPVarInt(playerid, "SPRITROB", 1);
 	SetPVarInt(playerid, "SPRITMENGE", menge);
 	
 	Spieler[playerid][pWanteds] += 6;
	SendClientMessage(playerid, COLOR_DARKRED,"Du hast ein Verbrechen begangen! (Sprit-Raub) Reporter: Polizeizentrale");
	SCMFormatted(playerid, COLOR_YELLOW,"Dein Aktuelles Wanted Level: %d", Spieler[playerid][pWanteds]);
	format(string, sizeof(string), "HQ: %s (ID: %d) hat ein Verbrechen begangen: Sprit-Raub, over.", GetName(playerid), playerid);
	SendFraktionMessage(1, COLOR_RED, string);
	SendFraktionMessage(2, COLOR_RED, string);
	SendFraktionMessage(16, COLOR_RED, string);
	SendFraktionMessage(18, COLOR_RED, string);
	SendFraktionMessage(22, COLOR_RED, string);
    format(string, sizeof(string), "[EILMELDUNG] Räuber %s hat einen Sprit-Raub gestartet!", GetName(playerid), playerid);
    SendFraktionMessage(1, COLOR_RED, string);
	SendFraktionMessage(2, COLOR_RED, string);
	SendFraktionMessage(16, COLOR_RED, string);
	SendFraktionMessage(18, COLOR_RED, string);
	SendFraktionMessage(22, COLOR_RED, string);
	return 1;
}


CMD:startsprit(playerid) {
    new veh = GetPlayerVehicleID(playerid), vehiclemodel = GetVehicleModel(veh), string[128];
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
	if(Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid,COLOR_RED,"[FEHLER] {FFFFFF}Du bist kein Nine Demons.");
	if(Spieler[playerid][pRank] < 1) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst mindestens Rank 1 sein.");
	if(GetPVarInt(playerid, "STARTSPRIT"))return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du hast bereits mit der Mission begonnen. Tippe /Stopsprit");
	if(GetPVarInt(playerid, "SPRITROB")) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du führst bereits die Mission durch!");
	if(vehiclemodel != 499) return SendClientMessage(playerid, COLOR_RED,"[INFO] {FFFFFF}Du bist in keinem Benson!");
	if(FrakCarInfo[veh][f_frak] != 15)return SendClientMessage(playerid, COLOR_RED,"[FEHLER] {FFFFFF}Der Benson gehört nicht zu deiner Fraktion.");
 	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid,COLOR_RED,"[INFO] {FFFFFF}Du musst der Fahrer des Linerunners sein!");
	if(IsPlayerInRangeOfPoint(playerid, 3.0, 268.9609,1384.2981,10.1610))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Spritklauen [Liter]");
	
	SetPlayerCheckpointEx(playerid, 268.9609,1384.2981,10.1610, 3.0, CP_SPRITKLAUEN);
	SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Dir wurde ein Checkpoint zur Öl-Raffinerie gesetzt.");
	
	SetPVarInt(playerid, "STARTSPRIT", 1);
	format(string,sizeof(string), "Fraktionsmitglied %s hat mit der Sprit-Mission begonnen.", GetName(playerid));
	SendFraktionMessage(15, COLOR_YELLOW, string);

    spritstatus = true;
	return 1;
}

CMD:stopsprit(playerid) {
	new string[128];
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
	if(Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid,COLOR_RED,"[FEHLER] {FFFFFF}Du bist kein Nine Demons.");
	if(Spieler[playerid][pRank] < 1) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst mindestens Rank 1 sein.");
	if(!GetPVarInt(playerid, "STARTSPRIT")) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du hast keine Sprit-Mission begonnen.");
	
	DeletePVar(playerid, "STARTSPRIT");
	RemovePlayerFromVehicle(playerid);
	DisablePlayerCheckpointEx(playerid);
	
	format(string,sizeof(string), "Fraktionsmitglied %s hat die Sprit-Mission abgebrochen.", GetName(playerid));
	SendFraktionMessage(15, COLOR_YELLOW, string);

    spritstatus = false;
	return 1;
}

CMD:startwt(playerid){
    new veh = GetPlayerVehicleID(playerid), vehiclemodel = GetVehicleModel(veh), string[128];
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
	if(Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid,COLOR_RED,"[FEHLER] {FFFFFF}Du bist kein Nine Demons.");
	if(Spieler[playerid][pRank] < 1) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst mindestens Rank 1 sein.");
    if(vehiclemodel != 499) return SendClientMessage(playerid, COLOR_RED,"[INFO] {FFFFFF}Du bist in keinem Benson!");
	if(FrakCarInfo[veh][f_frak] != 15)return SendClientMessage(playerid, COLOR_RED,"[FEHLER] {FFFFFF}Der Benson gehört nicht zu deiner Fraktion.");
    if(wtstatus == true) return SendClientMessage(playerid, COLOR_RED,"[FEHLER] {FFFFFF}Die Mission läuft gerade! Benutze /Stopwt zum Beenden!");

    format(string,sizeof(string), "Fraktionsmitglied %s hat mit der Waffenteile-Mission begonnen.", GetName(playerid));
	SendFraktionMessage(15, COLOR_YELLOW, string);
    
    /*SetPlayerCheckpointEx(playerid, 2839.3120,994.9202,10.7467, 3.0, CP_WT_VEH);
	SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Dir wurde ein Checkpoint bei einem Lager gesetzt.");*/
    
    for(new i; i < MAX_PLAYERS; i++){
        if(Spieler[i][pFraktion] == 15 && Spieler[i][pRank] >= 1){
            SetPlayerCheckpointEx(i, 2839.3120,994.9202,10.7467, 3.0, CP_WT_VEH);
	        SendClientMessage(i, COLOR_YELLOW, "[INFO] {FFFFFF}Dir wurde ein Checkpoint bei einem Lager gesetzt.");
        }
    }

    Delete3DTextLabel(terrorVehLabel);
    bestand[veh] = 0;
    format(string, sizeof(string), "{B18904}[TRANSPORTER]\n\n{FFFFFF}Beladene Kisten: %i von 15", bestand[veh]);
    terrorVehLabel = Create3DTextLabel(string, 0xFF0000AA, 0.0, 0.0, 0.0, 50.0, 0, 1 );
	Attach3DTextLabelToVehicle(terrorVehLabel, veh, 0.0, 0.0, 2.0);

    wtstatus = true;
    wtid = playerid;
    return 1;
}

CMD:stopwt(playerid){
    if(wtstatus != true) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Die Mission läuft gerade nicht!");
    for(new i; i < MAX_VEHICLES; i++){
        new vehiclemodel = GetVehicleModel(i);
        if(vehiclemodel == 499 && FrakCarInfo[i][f_frak] == 15){
            bestand[i] = 0;
        }
    }
    Delete3DTextLabel(terrorVehLabel);
    Delete3DTextLabel(terrorBootLabel);
    bestand[speederID] = 0;
    DestroyVehicle(speederID);
    new String[128];
    format(String, sizeof(String), "[WT] Das Mitglied %s hat die Waffenteilmission gestoppt!");
    SendFraktionMessage(15, COLOR_RED, String);
    DisablePlayerCheckpointEx(playerid);
    wtstatus = false;
    wtid = -1;
    return 1;
}

CMD:selbstmord(playerid) 
{
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if(Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid,COLOR_RED,"[FEHLER] {FFFFFF}Du bist kein Mitglied der Nine Demons.");
    if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist Tot.");
    if(GetPlayerInterior(playerid) > 0)return SendClientMessage(playerid, COLOR_RED,"[FEHLER] {FFFFFF}Du kannst den Befehl nicht in einem Interior nutzen!");
    if(Spieler[playerid][pJailed] != 0)return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du kannst hier den Befehl nicht nutzen.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Während du gefesselt bist kannst du dich nicht in die Luft sprengen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist im AFK-Modus.");
    if(GetPlayerInterior(playerid) == MAPS_NDROBINT_INTERIOR && GetPlayerVirtualWorld(playerid) == VW_NINEDEMONSINTERIOR) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst dich im Spice-Lager nicht in die Luft sprengen.");
    if(GetPVarInt(playerid, "TERROR.SELBSTMORD"))return SendClientMessage(playerid, COLOR_RED,"[INFO] {FFFFFF}Du kannst nur alle 30 Minuten den Selbstmord-Befehl nutzen.");
    new Float:Pos[3], string[128];
    SetPVarInt(playerid, "TERROR.SELBSTMORD", 1);
    GameTextForPlayer(playerid,"~n~~n~~r~BOOOOM!!!!",3000,4);
    GetPlayerPos(playerid,Pos[0],Pos[1],Pos[2]);
    new randompos = random(20),randexploderadius = random(40)+10;
    CreateExplosion(Pos[0]+randompos,Pos[1]+randompos,Pos[2]+randompos,7,randexploderadius);
    randexploderadius = random(30)+10;
    randompos = random(10);
    CreateExplosion(Pos[0]+randompos,Pos[1]+randompos,Pos[2]+randompos,7,randexploderadius);
    randexploderadius = random(30)+10;
    randompos = random(10);
    CreateExplosion(Pos[0]+randompos,Pos[1]+randompos,Pos[2]+randompos,7,randexploderadius);
    randexploderadius = random(30)+10;
    randompos = random(10);
    CreateExplosion(Pos[0]+randompos,Pos[1]+randompos,Pos[2]+randompos,7,randexploderadius);
    randexploderadius = random(30)+10;
    randompos = random(10);
    CreateExplosion(Pos[0]+randompos,Pos[1]+randompos,Pos[2]+randompos,7,randexploderadius);
    randexploderadius = random(30)+10;
    randompos = random(10);
    CreateExplosion(Pos[0]+randompos,Pos[1]+randompos,Pos[2]+randompos,7,randexploderadius);
    randexploderadius = random(30)+10;
    randompos = random(10);
    CreateExplosion(Pos[0]+randompos,Pos[1]+randompos,Pos[2]+randompos,7,randexploderadius);
    randexploderadius = random(30)+10;
    randompos = random(10);
    CreateExplosion(Pos[0]+randompos,Pos[1]+randompos,Pos[2]+randompos,7,randexploderadius);
    randexploderadius = random(30)+10;
    randompos = random(10);
    CreateExplosion(Pos[0]+randompos,Pos[1]+randompos,Pos[2]+randompos,7,randexploderadius);
    randexploderadius = random(30)+10;
    randompos = random(10);
    CreateExplosion(Pos[0]+randompos,Pos[1]+randompos,Pos[2]+randompos,7,randexploderadius);
    randexploderadius = random(30)+10;
    randompos = random(10);
    CreateExplosion(Pos[0]+randompos,Pos[1]+randompos,Pos[2]+randompos,7,randexploderadius);
    randexploderadius = random(30)+10;
    randompos = random(10);
    CreateExplosion(Pos[0]+randompos,Pos[1]+randompos,Pos[2]+randompos,7,randexploderadius);
    randexploderadius = random(30)+10;
    randompos = random(10);
    CreateExplosion(Pos[0]+randompos,Pos[1]+randompos,Pos[2]+randompos,7,randexploderadius);
    Spieler[playerid][pWanteds] += 3;
    SendClientMessage(playerid, COLOR_DARKRED,"Du hast ein Verbrechen begangen! (Selbstmord) Reporter: Polizeizentrale");
    SCMFormatted(playerid, COLOR_YELLOW,"Dein Aktuelles Wanted Level: %d", Spieler[playerid][pWanteds]);
    format(string, sizeof(string), "HQ: %s (ID: %d) hat ein Verbrechen begangen: Selbstmord, over.", GetName(playerid), playerid);
    SendFraktionMessage(1, COLOR_RED, string);
    SendFraktionMessage(2, COLOR_RED, string);
    SendFraktionMessage(16, COLOR_RED, string);
    SendFraktionMessage(18, COLOR_RED, string);
    SendFraktionMessage(22, COLOR_GREEN, string);
    for(new i ; i < MAX_PLAYERS; i++)
    {
        new Float:SPos[3];
        GetPlayerPos(i,SPos[0],SPos[1],SPos[2]);
        if(IsPlayerInRangeOfPoint(i, 4, Pos[0],Pos[1],Pos[2]))
        {
            Spieler[i][pTot] = 1;
            Spieler[i][pTotTime] = 60;
            Spieler[i][pTotX] = SPos[0];
            Spieler[i][pTotY] = SPos[1];
            Spieler[i][pTotZ] = SPos[2];
            SpawnPlayer(i);
        }
    }
    // 30 Minuten Pause
    SetTimerEx("uselbstmord",1800000,false,"i",playerid);
    return 1;
}



CMD:spicesperre(playerid, params[]){
    if(Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "[SSPERRE] {FFFFFF}Du bist kein Nine Demons!");
    if(Spieler[playerid][pRank] != 6) return SendClientMessage(playerid, COLOR_RED, "[SSPERRE] {FFFFFF}Du bist kein Leader!");

    new String[128], Anzahl;
    format(String, sizeof(String), INFO_STRING"/Spicesperre [Anzahl] | Aktuelle Sperre: %i | Neue Sperre: %i", schwarzmarktMaxSpice, newSchwarzmarktMaxSpice);
    if(sscanf(params, "i", Anzahl)) return SendClientMessage(playerid,COLOR_BLUE, String);

    if(Anzahl == newSchwarzmarktMaxSpice) return SendClientMessage(playerid, COLOR_YELLOW, "[SSPERRE] {FFFFFF}Die Anzahl entspricht bereits der neuen Spice Sperre!");

    newSchwarzmarktMaxSpice = Anzahl;
    SCMFormatted(playerid, COLOR_GREEN, "[SSPERRE] {FFFFFF}Du hast die wöchentliche Spicesperre auf %i geändert. Diese wird am Montag übernommen!", newSchwarzmarktMaxSpice);

    return 1;
}

CMD:drogensperre(playerid, params[]){
    if(Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "[SSPERRE] {FFFFFF}Du bist kein Nine Demons!");
    if(Spieler[playerid][pRank] != 6) return SendClientMessage(playerid, COLOR_RED, "[SSPERRE] {FFFFFF}Du bist kein Leader!");

    new String[128], Anzahl;
    format(String, sizeof(String), INFO_STRING"/Drogensperre [Anzahl] | Aktuelle Sperre: %i | Neue Sperre: %i", schwarzmarktMaxDrogen, newSchwarzmarktMaxDrogen);
    if(sscanf(params, "i", Anzahl)) return SendClientMessage(playerid,COLOR_BLUE, String);

    if(Anzahl == newSchwarzmarktMaxDrogen) return SendClientMessage(playerid, COLOR_YELLOW, "[SSPERRE] {FFFFFF}Die Anzahl entspricht bereits der neuen Spice Sperre!");

    newSchwarzmarktMaxDrogen = Anzahl;
    SCMFormatted(playerid, COLOR_GREEN, "[SSPERRE] {FFFFFF}Du hast die wöchentliche Drogensperre auf %i geändert. Diese wird am Montag übernommen!", newSchwarzmarktMaxDrogen);

    return 1;
}

CMD:wtsperre(playerid, params[]){
    if(Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "[SSPERRE] {FFFFFF}Du bist kein Nine Demons!");
    if(Spieler[playerid][pRank] != 6) return SendClientMessage(playerid, COLOR_RED, "[SSPERRE] {FFFFFF}Du bist kein Leader!");

    new String[128], Anzahl;
    format(String, sizeof(String), INFO_STRING"/Wtsperre [Anzahl] | Aktuelle Sperre: %i | Neue Sperre: %i", schwarzmarktMaxWT, newSchwarzmarktMaxWT);
    if(sscanf(params, "i", Anzahl)) return SendClientMessage(playerid,COLOR_BLUE, String);

    if(Anzahl == newSchwarzmarktMaxWT) return SendClientMessage(playerid, COLOR_YELLOW, "[SSPERRE] {FFFFFF}Die Anzahl entspricht bereits der neuen Spice Sperre!");

    newSchwarzmarktMaxWT = Anzahl;
    SCMFormatted(playerid, COLOR_GREEN, "[SSPERRE] {FFFFFF}Du hast die wöchentliche Wtsperre auf %i geändert. Diese wird am Montag übernommen!", newSchwarzmarktMaxWT);

    return 1;
}

CMD:wcodessperre(playerid, params[]){
    if(Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "[SSPERRE] {FFFFFF}Du bist kein Nine Demons!");
    if(Spieler[playerid][pRank] != 6) return SendClientMessage(playerid, COLOR_RED, "[SSPERRE] {FFFFFF}Du bist kein Leader!");

    new String[128], Anzahl;
    format(String, sizeof(String), INFO_STRING"/Wcodessperre [Anzahl] | Aktuelle Sperre: %i | Neue Sperre: %i", schwarzmarktMaxWCodes, newSchwarzmarktMaxWCodes);
    if(sscanf(params, "i", Anzahl)) return SendClientMessage(playerid,COLOR_BLUE, String);

    if(Anzahl == newSchwarzmarktMaxWCodes) return SendClientMessage(playerid, COLOR_YELLOW, "[SSPERRE] {FFFFFF}Die Anzahl entspricht bereits der neuen Spice Sperre!");

    newSchwarzmarktMaxWCodes = Anzahl;
    SCMFormatted(playerid, COLOR_GREEN, "[SSPERRE] {FFFFFF}Du hast die wöchentliche Wcodessperre auf %i geändert. Diese wird am Montag übernommen!", newSchwarzmarktMaxWCodes);

    return 1;
}




CMD:schwarzmarkt(playerid, params[]){
    if(IsPlayerInRangeOfPoint(playerid, 1, -1101.9084,-2861.1260,61.1270)){//Waffenteile
        if(Spieler[playerid][pFraktion] == 15 && Spieler[playerid][pRank] > 4){
            ShowPlayerDialog(playerid, DIALOG_SCHWARZMARKT_WAFFENTEILE_ADMIN, DIALOG_STYLE_LIST, "Schwarzmarkt: Waffenteile", "{1EA240}Waffenteile einlagern\n{C82619}Waffenteile auslagern\n{DFE213}Preis anpassen", "Auswählen", "Abbrechen"); //ADMIN SCHWARTMARKT
        }else{
            new String[256];
            format(String, sizeof(String),
            "{FFFFFF}Willkommen am Schwarzmarkt.\n\nHier hast du die Möglichkeit Waffenteile zu erwerben.\nAktueller Lagerbestand: %i Stück\nAktueller Stückpreis: $%i\nWöchentliches Kauflimit: %i von %i\n\nWaffenteile erwerben:", Schwarzmarkt_Waffenteile, Schwarzmarkt_Waffenteile_Preis, Spieler[playerid][swWT], schwarzmarktMaxWT);
            ShowPlayerDialog(playerid, DIALOG_SCHWARZMARKT_WAFFENTEILE, DIALOG_STYLE_INPUT, "Schwarzmarkt: Waffenteile", String, "Kaufen", "Abbrechen");
        }
    }else if(IsPlayerInRangeOfPoint(playerid, 1, -1104.9402,-2861.1267,61.1270)){//Drogen
        if(Spieler[playerid][pFraktion] == 15 && Spieler[playerid][pRank] > 4){
            ShowPlayerDialog(playerid, DIALOG_SCHWARZMARKT_DROGEN_ADMIN, DIALOG_STYLE_LIST, "Schwarzmarkt: Drogen", "{1EA240}Drogen einlagern\n{C82619}Drogen auslagern\n{DFE213}Preis anpassen", "Auswählen", "Abbrechen"); //ADMIN SCHWARTMARKT
        }else{
            new String[256];
            format(String, sizeof(String),
            "{FFFFFF}Willkommen am Schwarzmarkt.\n\nHier hast du die Möglichkeit Drogen zu erwerben.\nAktueller Lagerbestand: %i Stück\nAktueller Stückpreis: $%i\nWöchentliches Kauflimit: %i von %i\n\nDrogen erwerben:", Schwarzmarkt_Drogen, Schwarzmarkt_Drogen_Preis, Spieler[playerid][swDrogen], schwarzmarktMaxDrogen);
            ShowPlayerDialog(playerid, DIALOG_SCHWARZMARKT_DROGEN, DIALOG_STYLE_INPUT, "Schwarzmarkt: Drogen", String, "Kaufen", "Abbrechen");
        }
    }else if(IsPlayerInRangeOfPoint(playerid, 1, -1098.8091,-2861.1267,61.1270)){//Spice
        if(Spieler[playerid][pFraktion] == 15 && Spieler[playerid][pRank] > 4){
            ShowPlayerDialog(playerid, DIALOG_SCHWARZMARKT_SPICE_ADMIN, DIALOG_STYLE_LIST, "Schwarzmarkt: Spice", "{1EA240}Spice einlagern\n{C82619}Spice auslagern\n{DFE213}Preis anpassen", "Auswählen", "Abbrechen"); //ADMIN SCHWARTMARKT
        }else{
            new String[256];
            format(String, sizeof(String),
            "{FFFFFF}Willkommen am Schwarzmarkt.\n\nHier hast du die Möglichkeit Spice zu erwerben.\nAktueller Lagerbestand: %i Stück\nAktueller Stückpreis: $%i\nWöchentliches Kauflimit: %i von %i\n\nSpice erwerben:", Schwarzmarkt_Spice, Schwarzmarkt_Spice_Preis, Spieler[playerid][swSpice], schwarzmarktMaxSpice);
            ShowPlayerDialog(playerid, DIALOG_SCHWARZMARKT_SPICE, DIALOG_STYLE_INPUT, "Schwarzmarkt: Spice", String, "Kaufen", "Abbrechen");
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 1, -1098.1770,-2858.3450,61.1270)){//Wantedcodes
        if(Spieler[playerid][pFraktion] == 15 && Spieler[playerid][pRank] > 4){
            ShowPlayerDialog(playerid, DIALOG_SCHWARZMARKT_WANTEDCODES_ADMIN, DIALOG_STYLE_LIST, "Schwarzmarkt: Wantedcodes", "{1EA240}Wantedcodes einlagern\n{C82619}Wantedcodes auslagern\n{DFE213}Wantedcodes anpassen", "Auswählen", "Abbrechen"); //ADMIN SCHWARTMARKT
        }else{
            new String[256];
            format(String, sizeof(String),
            "{FFFFFF}Willkommen am Schwarzmarkt.\n\nHier hast du die Möglichkeit Wantedcodes zu erwerben.\nAktueller Lagerbestand: %i Stück\nAktueller Stückpreis: $%i\nWöchentliches Kauflimit: %i von %i\n\nWantedcodes erwerben:", Schwarzmarkt_Wantedcodes, Schwarzmarkt_Wantedcodes_Preis, Spieler[playerid][swWCodes], schwarzmarktMaxWCodes);
            ShowPlayerDialog(playerid, DIALOG_SCHWARZMARKT_WANTEDCODES, DIALOG_STYLE_INPUT, "Schwarzmarkt: Wantedcodes", String, "Kaufen", "Abbrechen");
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 1, -1098.1770,-2855.7100,61.1270)){//Waffen
        ShowPlayerDialog(playerid, DIALOG_SCHWARZMARKT_WEAPONS, DIALOG_STYLE_TABLIST_HEADERS, "Schwarzmarkt: Waffen", "{FFFFFF}Waffe\t{FFFFFF}Preis\t{FFFFFF}Stückanzahl\nSniper Rifle\t$30.000\t30 Schuss\nUzi\t$50.000\t200 Schuss\nTec-9\t$50.000\t200 Schuss\nKatana\t$10.000\t1 Stück\nGranate\t$2.000.000\t1 Stück", "Kaufen", "Abbrechen");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 1, -1098.7355,-2854.2180,61.1343)){//Illegale Gegenstände
        ShowPlayerDialog(playerid, DIALOG_SCHWARZMARKT_ILLEGALE_GEGENSTAENDE, DIALOG_STYLE_TABLIST_HEADERS, "Schwarzmarkt: Illegale Gegenstände", "{FFFFFF}Gegenstand\t{FFFFFF}Preis\nC4\t$50.000\nBrecheisen\t$10.000", "Kaufen", "Abbrechen");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 1, -1101.9292,-2854.2185,61.1343)){//Kennzeichen
        if( !PlayerHaveCar[playerid][PlayerKey[playerid]] ) return SendClientMessage(playerid, COLOR_RED, "Du hast gerade kein Fahrzeug gewählt ( /Carkey ).");
        new String[256];
        format(String, sizeof(String),
            "{FFFFFF}Willkommen am Schwarzmarkt.\n\nHier hast du die Möglichkeit, ein individuelles Kennzeichen zu erwerben.\nAktueller Stückpreis: $1.000.000\n\nKennzeichen:");
        ShowPlayerDialog(playerid, DIALOG_SCHWARZMARKT_KENNZEICHEN, DIALOG_STYLE_INPUT, "Schwarzmarkt: Kennzeichen", String, "Kaufen", "Abbrechen");
    }else if(IsPlayerInRangeOfPoint(playerid, 1, -1105.0177,-2854.2180,61.1343)){
        new String[256];
        format(String, sizeof(String),
            "{FFFFFF}Willkommen am Schwarzmarkt.\n\nHier hast du die Möglichkeit, eine individuelle Handynummer zu erwerben.\nAktueller Stückpreis: $500.000\n\nNeue Handynummer:");
        ShowPlayerDialog(playerid, DIALOG_SCHWARZMARKT_SIM, DIALOG_STYLE_INPUT, "Schwarzmarkt: SIM-Karte", String, "Kaufen", "Abbrechen");
    }else{
        SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du befindest dich an keinem Schwarzmarkt.");
    }
    return 1;
}


CMD:lagerpunkt(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pJob] == 17) {
        SetPlayerCheckpointEx(playerid, -38.4148, 56.1184, 3.1172, 2.0, CP_NAVI1);
        return SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Der Lagerpunkt für Drogen wurde dir auf der Karte Rot markiert.");
    }
    else if (Spieler[playerid][pJob] == 18) {
        SetPlayerCheckpointEx(playerid, 2348.1086, -2302.4243, 13.5469, 2.0, CP_NAVI1);
        return SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Der Lagerpunkt für Waffenteile wurde dir auf der Karte Rot markiert.");
    }

    return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Für deinen Job gibt es keinen Lagerpunkt.");
}

CMD:samenlagerpunkt(playerid, params[]){
    SetPlayerCheckpointEx(playerid, -38.4148, 56.1184, 3.1172, 2.0, CP_NAVI1);
    return SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Der Lagerpunkt für Drogensamen wurde dir auf der Karte Rot markiert.");
}

CMD:samenlager(playerid, params[]){
	if(Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Damit kannst du nichts anfangen!");
	SendClientMessage(playerid, COLOR_YELLOW, "Das Samenlager wird dir auf der Karte markiert!");
	SetPlayerCheckpoint(playerid, -111.0688,1133.3749,19.7422, 7.0);
	return 1;
}


CMD:ninowaffen(playerid)
{
    if(HasWeaponBlock(playerid)) {
        SendClientMessage(playerid,COLOR_RED,"Du kannst diesen Befehl nicht ausführen.");
        return SendWeaponBlockInfo(playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, g_fraktion[15][Fr_WaffenX],g_fraktion[15][Fr_WaffenY],g_fraktion[15][Fr_WaffenZ])) //NineDemons
    {
        if(Spieler[playerid][pGunLic] == 0) return SendClientMessage(playerid, COLOR_RED, "Du besitzt keinen Waffenschein.");
        if(CheckMoney(playerid) < 5000) return SendClientMessage(playerid, COLOR_RED, "Du benötigst $5.000.");
        if(!(Spieler[playerid][pFraktion] == 15)) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Nine Demons Mitglied.");
        GiveTerrorWeapons(playerid);
    }
    return 1;
}



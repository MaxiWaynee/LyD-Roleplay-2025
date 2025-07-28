#include <YSI\y_hooks>


new const Float:g_StaatRepair[][] = {
	{LSPD_STATEREPAIR_COORDS}, 	// PD
	{SAMD_STATEREPAIR_COORDS}, 	// Medic
	{POO_STATEREPAIR_COORDS}, 	// Oamt
	{FBI_STATEREPAIR_COORDS}, 	// FBI
    {GOVERNMENT_STATEREPAIR_COORDS }, // Regierung
	{2288.5466, 2444.9841, 	3.2734}, 	// LVPD
	{1442.5435,-1077.5964,23.8561},     //SAMD Landeplatz1
	{1461.5607,-1077.7324,23.8476},      //SAMD Landeplatz2
	{958.5949,-1605.2439,27.0017},   //PD Dach
	{970.7366,-1605.0114,27.0217}, //PD Dach
	{1973.5946,-1291.6208,29.0911},  //OAMT DACH
    {1.5613,-2510.2061,36.6555}//SA-NA
	//{1248.3843, -1833.8750, 13.3930}, 	// Fahrschule
	//{1138.9730, -1820.9103, 33.6354} 	// Fahrschule Dach
};

CMD:bk(playerid)
{
    if(Spieler[playerid][pDuty] == 0)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Dienst.");
    if(!(Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 3 ))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Ordnungsbeamter oder Medic.");
    new string[128];
    new ort[28];
    GetPlayer2DZone(playerid, ort, 28);
    new Rang[32];
    if(Spieler[playerid][pFraktion] == 5){Rang="Ordnungsbeamter";}
    else if(Spieler[playerid][pFraktion] == 3){Rang="Medic";}
    format(string, sizeof(string), "HQ: %s %s (ID: %d) fordert eine Polizeistreife zur Verstärkung in %s an, over.", Rang, GetName(playerid), playerid, ort);
    SendClientMessage(playerid, COLOR_BLUE, "INFO: "COLOR_HEX_WHITE"Nach 30 Sekunden verschwindet der Marker automatisch für alle Polizisten wieder.");
    SendFraktionMessage(1, COLOR_RED, string);
    SendFraktionMessage(2, COLOR_RED, string);
    SendFraktionMessage(16, COLOR_RED, string);
    SendFraktionMessage(18, COLOR_RED, string);
    SendFraktionMessage(22, COLOR_RED, string);
    SendFraktionMessage(5, COLOR_RED, string);
    SendFraktionMessage(3, COLOR_RED, string);
    PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    foreach(new i : Player) {
        if(Spieler[i][pFraktion] == 1 || Spieler[i][pFraktion] == 2 || Spieler[i][pFraktion] == 16 || Spieler[i][pFraktion] == 18) {
            if(Spieler[i][pDuty] == 0)continue;
            if(i != playerid) {
                KillTimer(pBackupTimer[i]);
                SetPlayerCheckpointEx(i, x, y, z, 5.0, CP_BACKUP);
                pBackupTimer[i] = SetTimerEx("RemoveBackupCP", 30000, 0, "i", i);
            }
        }
    }
    return 1;
}



CMD:ofreistellen(playerid, params[]) {
    if (Spieler[playerid][pFraktion] != 5) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist kein Ordnungsbeamter.");
    new vehicleid;
    if (!isnull(params)) {
        if (sscanf(params, "i", vehicleid)) {
            SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Ofreistellen [Fahrzeug-ID]");
            return SendClientMessage(playerid, COLOR_BLUE, "[INFO] {FFFFFF}Du kannst auch in dem Fahrzeug sitzen.");
        }

        if (!GetVehicleModel(vehicleid)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du musst eine gültige Fahrzeug-ID angeben.");
    }
    else {
        vehicleid = GetPlayerVehicleID(playerid);
        if (!vehicleid) {
            SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Ofreistellen [Fahrzeug-ID]");
            return SendClientMessage(playerid, COLOR_BLUE, "[INFO] {FFFFFF}Du kannst auch in dem Fahrzeug sitzen.");
        }
    }

    new fraktion = GetVehicleFraktion(vehicleid);
    if (fraktion && g_FraktionAbschleppen[vehicleid][FA_bAbgeschleppt]) {
        g_FraktionAbschleppen[vehicleid][FA_fX] = 0.0;
        g_FraktionAbschleppen[vehicleid][FA_fY] = 0.0;
        g_FraktionAbschleppen[vehicleid][FA_fZ] = 0.0;
        g_FraktionAbschleppen[vehicleid][FA_fFace] = 0.0;
        g_FraktionAbschleppen[vehicleid][FA_bAbgeschleppt] = false;
        g_FraktionAbschleppen[vehicleid][FA_fraktion] = 0;

        SendClientMessage(playerid, COLOR_LIGHTBLUE, "* Du hast das Fraktionsfahrzeug wieder freigestellt.");
        SendClientMessage(playerid, COLOR_LIGHTBLUE, "* Das Fahrzeug spawnt nun wie gewohnt.");
        new message[145];
        format(message, sizeof(message), "Ordnungsbeamter %s hat euer Fahrzeug wieder freigestellt.", GetName(playerid));
        SendFraktionMessage(fraktion, COLOR_GREEN, message);
        Spieler[playerid][pPayCheck] -= 700;
        return 1;
    }
    else if (fraktion) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Das Fahrzeug ist nicht abgeschleppt.");
    
    new besitzer = GetCarOwner(vehicleid);
    if (besitzer == INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Das Fahrzeug gehört keinem Spieler.");

    new slot = GetCarOwnerSlot(besitzer, vehicleid);
    if (slot == 555) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Das Fahrzeug gehört keinem Spieler.");
    if (PlayerCar[besitzer][slot][CarState] != e_Vehicle_Status_Towed)
        return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Das Fahrzeug ist nicht abgeschleppt.");

    PlayerCar[besitzer][slot][CarState] = e_Vehicle_Status_Normal;
    SendClientMessage(playerid, COLOR_LIGHTBLUE, "* Du hast das Fahrzeug wieder freigestellt.");
    SendClientMessage(playerid, COLOR_LIGHTBLUE, "* Es muss nun wieder per /Parken ordentlich geparkt werden.");
    Spieler[playerid][pPayCheck] -= 700;
    ShowBuyInformation(playerid,"~y~Fahrzeug ~w~freigestellt!");
    SCMFormatted(besitzer, COLOR_LIGHTBLUE, "Ordnungsbeamter %s hat dein Fahrzeug wieder freigestellt.", GetName(playerid));
    return 1;
}

CMD:removekennzeichen(playerid, params[]){
    new vehicleid;
    if(!(Spieler[playerid][pFraktion] == 5))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Ordnungsbeamter.");
    if(sscanf(params, "i", vehicleid))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Removekennzeichen [VEHICLE ID]");
    if (!GetVehicleModel(vehicleid)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du musst eine gültige Fahrzeug-ID angeben.");
    new ownerid = GetCarOwner(vehicleid);
    new String[128];
    new slot = GetCarOwnerSlot(ownerid, vehicleid);
    format(PlayerCar[playerid][slot][CarNumberplate],32,"%s",KEIN_KENNZEICHEN);
    SetVehicleNumberPlate( vehicleid , KEIN_KENNZEICHEN );
    SavePlayerCar(playerid,slot);
    format(String, sizeof(String), "[ZULASSUNGSSTELLE] {FFFFFF}Ordnungsbeamter %s hat ein Kennzeiches des Spielers %s entfernt!", GetName(playerid), GetName(ownerid));
    SendFraktionMessage(5, COLOR_RED, String);
    format(String, sizeof(String), "[OAMT] {FFFFFF}Ordnungsbeamter %s hat ein Kennzeichen von deinen Fahrzeug entfernt!", GetName(playerid));
    SendClientMessage(ownerid, COLOR_RED, String);
    return 1;
}

CMD:oparken(playerid) {
    if(!(Spieler[playerid][pFraktion] == 5))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Ordnungsbeamter.");
    if (GetVehicleModel(GetPlayerVehicleID(playerid)) == 525) {
        if(IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid))) {
            foreach(new i : Player) {
                new trailerid = GetVehicleTrailer(GetPlayerVehicleID(playerid));
                new besitzer = GetCarOwner(trailerid);
                if( IsPlayerConnected(besitzer)) {
                    new Slot = GetCarOwnerSlot(besitzer,trailerid);
                    if(trailerid == PlayerCar[besitzer][Slot][CarId]) {
                        if(PlayerCar[besitzer][Slot][CarState] == 1)return SendClientMessage(playerid, COLOR_RED, "Das Fahrzeug ist bereits abgeschleppt!");
                        new Float:vX, Float:vY, Float:vZ;
                        GetVehiclePos(trailerid, vX, vY, vZ);
                        PlayerCar[besitzer][Slot][CarPos_x] = vX;
                        PlayerCar[besitzer][Slot][CarPos_y] = vY;
                        PlayerCar[besitzer][Slot][CarPos_z] = vZ;
                        PlayerCar[besitzer][Slot][CarState] = e_Vehicle_Status_Towed; //Abgeschleppt
                        new str[128];
                        format(str, sizeof(str), "Dein Fahrzeug wurde aufgrund einer Ordnungswidrigkeit abgeschleppt!");
                        SendClientMessage(besitzer, COLOR_RED, str);
                        format(str, sizeof(str), "Ordnungsbeamter %s hat dein Fahrzeug kostenpflichtig abgeschleppt! Kaufe es am Ordnungsamt wieder frei!", GetName(playerid));
                        SendClientMessage(besitzer, COLOR_RED, str);
                        Spieler[playerid][pPayCheck] += 700;
                        GameTextForPlayer(playerid, "~g~+$700", 2000, 1);
                        SavePlayerCar(besitzer,Slot);
                        format(str,sizeof(str),"Ordnungsbeamter %s hat das Fahrzeug von %s abgeschleppt!",GetName(playerid),GetName(besitzer));
                        SendFraktionMessage(5, COLOR_RED, str);
                        format(str,sizeof(str),"[OAMT] Ordnungsbeamter: %s , Fahrzeughalter: %s",GetName(playerid),GetName(besitzer));
                        OamtLog(str);
                        return 1;
                    }
                }
            }
        }
        else return SendClientMessage(playerid, COLOR_RED, "Du hast kein Fahrzeug am Haken.");
    } else return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Ordnungsamt-Fahrzeug.");
    return 1;
}

CMD:mparkkralle(playerid) {
    if(Spieler[playerid][pFraktion] != 5) {
        SendClientMessage(playerid, COLOR_RED, "Du bist kein Ordnungsbeamter.");
    } else {
        for(new v;v<GetVehiclePoolSize();v++) {
            if(IsABike(GetVehicleModel(v))==1) {
                new Float:vx,Float:vy,Float:vz;
                GetVehiclePos(v,vx,vy,vz);
                new Float:px,Float:py,Float:pz;
                GetPlayerPos(playerid,px,py,pz);
                if(IsPlayerInRangeOfPoint(playerid,4,vx,vy,vz)) {
                    new trailerid = v;
                    new besitzer = GetCarOwner(v);
                    if( IsPlayerConnected(besitzer)) {
                        new Slot = GetCarOwnerSlot(besitzer,trailerid);
                        if(trailerid == PlayerCar[besitzer][Slot][CarId]) {
                            if(PlayerCar[besitzer][Slot][CarState] == 1)return SendClientMessage(playerid, COLOR_RED, "Das Fahrzeug ist bereits abgeschleppt!");
                            new Float:vX, Float:vY, Float:vZ;
                            GetVehiclePos(trailerid, vX, vY, vZ);
                            PlayerCar[besitzer][Slot][CarPos_x] = vX;
                            PlayerCar[besitzer][Slot][CarPos_y] = vY;
                            PlayerCar[besitzer][Slot][CarPos_z] = vZ;
                            PlayerCar[besitzer][Slot][CarState] = e_Vehicle_Status_Towed; //Abgeschleppt
                            new str[128];
                            format(str, sizeof(str), "Dein Fahrzeug wurde aufgrund einer Ordnungswidrigkeit abgeschleppt!");
                            SendClientMessage(besitzer, COLOR_RED, str);
                            format(str, sizeof(str), "Ordnungsbeamter %s hat dein Fahrzeug kostenpflichtig abgeschleppt! Kaufe es am Ordnungsamt wieder frei!", GetName(playerid));
                            SendClientMessage(besitzer, COLOR_RED, str);
                            Spieler[playerid][pPayCheck] += 700;
                            GameTextForPlayer(playerid, "~g~+$700", 2000, 1);
                            SavePlayerCar(besitzer,Slot);
                            format(str,sizeof(str),"Ordnungsbeamter %s hat das Fahrzeug von %s abgeschleppt!",GetName(playerid),GetName(besitzer));
                            SendFraktionMessage(5, COLOR_RED, str);
                            format(str,sizeof(str),"[OAMT] Ordnungsbeamter: %s , Fahrzeughalter: %s",GetName(playerid),GetName(besitzer));
                            OamtLog(str);
                            break;
                        }
                    } else {
                        SendClientMessage(playerid,COLOR_RED,"Der Besitzer ist nicht Online!");
                    }
                }
            }
        }
    }
    return 1;
}


CMD:acceptoamt(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_GREY, "* Benutze /Acceptoamt [SpielerID/Name]");
    if(Spieler[playerid][pFraktion] != 5)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Ordnungsbeamter!");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online!");
    if(GetPlayerInterior(pID) > 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in einem Gebäude.");
    if(NeedOAMT[pID] == 0)return SendClientMessage(playerid, COLOR_ORANGE, "Der Spieler benötigt keinen Ordnungsbeamten. Verwende /sliste um die Service-Liste zu sehen.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x,y,z);
    SetPlayerCheckpointEx(playerid, x,y,z, 5.0, CP_ACCEPTOAMT);
    format(string, sizeof(string), "* Du hast den Service-Anruf von %s angenommen, ein Roter Punkt wurde auf der Karte markiert.", GetName(pID));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "* Ordnungsbeamter %s hat deinen Service-Anruf angenommen und ist nun unterwegs zu dir!", GetName(playerid));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    NeedOAMT[pID] = 0;
    return 1;
}



CMD:oamt(playerid,params[]){
    if( !(Spieler[playerid][pFraktion] == 5) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Ordnungsbeamter!");
    }
    /*
    if( GetPlayerSkin(playerid) != 280 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
    }
    */
    if( IsPlayerAttachedObjectSlotUsed(playerid,1) ) {
        RemovePlayerAttachedObject(playerid,1);
        RemovePlayerAttachedObject(playerid,2);
        RemovePlayerAttachedObject(playerid,3);
        RemovePlayerAttachedObject(playerid,4);
        SendClientMessage(playerid,COLOR_YELLOW,"OAMT-Inventare entfernt");
    } else {
        SetPlayerAttachedObject( playerid, 1, 365, 1, -0.139383, -0.153296, -0.034828, 0.000000, 82.242210, 0.000000, 1.000000, 1.000000, 1.000000 ); // spraycan - spray zivicop
        SetPlayerAttachedObject( playerid, 2, 18642, 1, -0.208978, -0.131534, 0.072422, 0.000000, 283.615112, 0.000000, 1.000000, 1.000000, 1.000000 ); // Taser1 - copcuff
        SetPlayerAttachedObject( playerid, 3, 19942, 1, -0.125000, 0.198000, -0.112999, 172.599914, 85.399932, 2.500000, 1.116999, 1.385999, 0.883999, 0, 0); //Funkgerät Mann
        SetPlayerAttachedObject( playerid, 4, 334, 1, -0.157210, -0.015581, 0.224168, 79.199546, 276.988647, 171.322982, 0.899999, 1.500000, 0.899999 ); // Schlagstock
        SendClientMessage(playerid,COLOR_YELLOW,"OAMT-Inventare genommen");
    }
    return 1;
}


CMD:vrk2(playerid,params[]){
 	if( !(Spieler[playerid][pFraktion] == 5) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Ordnungsbeamter!");
	new modelid, vehicleid;
	vehicleid = GetPlayerVehicleID(playerid);
	if(!vehicleid) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur in einem Fahrzeug nutzen");
	modelid = GetVehicleModel(vehicleid);
	if( (modelid != 596) &&  (modelid != 560) &&  (modelid != 561) &&  (modelid != 598) &&  (modelid != 525) &&  (modelid != 599) ) return SendClientMessage(playerid, COLOR_RED, "Kein Polizei Auto ");
	if( _:g_t3dPolizeiKontrolle[vehicleid] != INVALID_3DTEXT_ID ) {
	    // Entfernen
	    Delete3DTextLabel( g_t3dPolizeiKontrolle[vehicleid] );
	    g_t3dPolizeiKontrolle[vehicleid] = Text3D:INVALID_3DTEXT_ID;
	} else {
	    g_t3dPolizeiKontrolle[vehicleid] = Create3DTextLabel("--> ORDNUNGSAMT <--\nBitte fahren Sie langsamer!", 0xFF4500FF, 0.0, 0.0, 0.0, 25.0, 0, 1);
		Attach3DTextLabelToVehicle( g_t3dPolizeiKontrolle[vehicleid],vehicleid,0.0,0.0,0.5);
	}
	return 1;
}


CMD:ovk(playerid,params[]) {
    new giveid;
    if(!(Spieler[playerid][pFraktion] == 5) ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Ordnungsbeamter!");
    if( sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Ovk [Spieler]");
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    new
        String[128];
    format(String,sizeof(String),"Ordnungsbeamter %s benötigt polizeiliche Verstärkung! Täter: %s, Wantedanzahl: %d!",GetName(playerid),GetName(giveid),Spieler[giveid][pWanteds]);
    SendFraktionMessage(1, COLOR_RED, String);
    SendFraktionMessage(2, COLOR_RED, String);
    SendFraktionMessage(5, COLOR_RED, String);
    SendFraktionMessage(16, COLOR_RED, String);
    SendFraktionMessage(18, COLOR_RED, String);
    SendFraktionMessage(22, COLOR_RED, String);
    PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
    return 1;
}


CMD:festnehmen(playerid, params[]) {
    new pID, string[128];
    if(!(Spieler[playerid][pFraktion] == 5))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Ordnungsbeamter.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Festnehmen [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    #if defined USE_NPCS
    if( IsPlayerNPC(pID) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an einem Bot ausführen!");
    #endif
    if(playerid == pID ) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nicht an dir selbst ausführen!");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if(!IsPlayerInRangeOfPoint(pID, 3.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");
    if( IsPlayerAttachedObjectSlotUsed(pID,ATTACHED_INDEX_HANDSCHELLE) ) {
        format(string, sizeof(string), "* Ordnungsbeamter %s hat %s die Handschellen abgemacht.", GetName(playerid), GetName(pID));
        foreach(new i : Player) {
            if(IsPlayerInRangeOfPoint(i, 10.0, x,y,z)) {
                SendClientMessage(i, COLOR_LIGHTRED2, string);
            }
        }
        SetPlayerSpecialAction(pID,SPECIAL_ACTION_NONE);
        RemovePlayerAttachedObject(pID,ATTACHED_INDEX_HANDSCHELLE);
        Cuffed[pID] = 0;
    } else {
        format(string, sizeof(string), "* Ordnungsbeamter %s hat %s die Handschellen angelegt.", GetName(playerid), GetName(pID));
        foreach(new i : Player) {
            if(IsPlayerInRangeOfPoint(i, 10.0, x,y,z)) {
                SendClientMessage(i, COLOR_LIGHTRED2, string);
            }
        }
        SetPlayerAttachedObject(pID, ATTACHED_INDEX_HANDSCHELLE, 19418, 6, -0.011000, 0.028000, -0.022000, -15.600012, -33.699977, -81.700035, 0.891999, 1.000000, 1.168000);
        SetPlayerSpecialAction(pID,SPECIAL_ACTION_CUFFED);
        Cuffed[pID] = 1;
    }
    UnFreeze(pID);
    return 1;
}


CMD:ov(playerid,params[]) {
    #pragma unused params
    if (Spieler[playerid][pFraktion] != 5) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Ordnungsbeamter.");
    if( Spieler[playerid][pDuty] == 0 ) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Dienst.");
    new String[128];
    if( Spieler[playerid][pDutyTask] == 1 ) {
        format(String,sizeof(String),"[LEITZENTRALE] Ordnungsbeamter %s ist wieder verfügbar!",GetName(playerid));
        SendFraktionMessage(5, COLOR_GREEN, String);
        Spieler[playerid][pDutyTask] = 0;
    } else {
        format(String,sizeof(String),"[LEITZENTRALE] Ordnungsbeamter %s meldet sich als nicht verfügbar!",GetName(playerid));
        SendFraktionMessage(5, COLOR_ORANGE, String);
        Spieler[playerid][pDutyTask] = 1;
    }
    return 1;
}


CMD:fparken(playerid) {
	if(!(Spieler[playerid][pFraktion] == 5))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Ordnungsbeamter.");
	new vehicleid = GetPlayerVehicleID(playerid);
	if (GetVehicleModel( vehicleid ) == 525) {
	    if(IsTrailerAttachedToVehicle(vehicleid)) {
			foreach(new i : Player) {
				new trailerid = GetVehicleTrailer(vehicleid);
				new fraktion = GetVehicleFraktion(trailerid);
				new modelid = GetVehicleModel(trailerid);
				if( fraktion ) {
    			    new Float:vX, Float:vY, Float:vZ,Float:vAngle;
    			    GetVehiclePos(trailerid, vX, vY, vZ);
    			    GetVehicleZAngle(trailerid,vAngle);
    				FrakCarInfo[trailerid][f_sperre] = true;
			        FrakCarInfo[trailerid][fA_x] = vX;
			        FrakCarInfo[trailerid][fA_y] = vY;
			        FrakCarInfo[trailerid][fA_z] = vZ;
			        FrakCarInfo[trailerid][fA_angle] = vAngle;
					new str[128];
					format(str, sizeof(str), "[OAMT] Euer %s wurde aufgrund einer Ordnungswidrigkeit durch Ordnungsbeamten %s abgeschleppt!", CarName[modelid-400],GetName(playerid));
					SendFraktionMessage(fraktion, COLOR_RED, str);
					Spieler[playerid][pPayCheck] += 200;
					GameTextForPlayer(playerid, "~g~+$200", 2000, 1);
				    new frakname[50];
		            ReturnFraktionByID( fraktion , frakname );
					format(str,sizeof(str),"Ordnungsbeamter %s hat das Fahrzeug von der Fraktion %s abgeschleppt!",GetName(playerid),frakname);
					SendFraktionMessage(5, COLOR_RED, str);
					format(str,sizeof(str),"[OAMT] Ordnungsbeamter: %s , Fahrzeughalter: %s [%d]",GetName(playerid),frakname,fraktion);
					OamtLog(str);
    			    return 1;
    			} else {
	    			return SendClientMessage(playerid, COLOR_RED, "Der Wagen ist kein Fraktionsfahrzeug.");
    			}
			}
		} else {
		    return SendClientMessage(playerid, COLOR_RED, "Du hast kein Fahrzeug hinten dran.");
		}
	} else {
		SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Ordnungsamt-Fahrzeug.");
		return 1;
	}
	return 1;
}


CMD:fmparkkralle(playerid) {
	if(Spieler[playerid][pFraktion] != 5) {
		SendClientMessage(playerid, COLOR_RED, "Du bist kein Ordnungsbeamter.");
	} else {
		for(new v;v<GetVehiclePoolSize();v++) {
		    if(IsABike(GetVehicleModel(v))) {
		    	new Float:vx,Float:vy,Float:vz;
			    GetVehiclePos(v,vx,vy,vz);
			    if(IsPlayerInRangeOfPoint(playerid,4,vx,vy,vz)) {
					foreach(new i : Player) {
						new trailerid = v;
						new fraktion = GetVehicleFraktion(trailerid);
						new modelid = GetVehicleModel(trailerid);
						if(fraktion) {
							if(FrakCarInfo[trailerid][f_sperre] == true)return SendClientMessage(playerid, COLOR_RED, "Das Fahrzeug ist bereits abgeschleppt!");
		    			    new Float:vX, Float:vY, Float:vZ,Float:vAngle;
		    			    GetVehiclePos(trailerid, vX, vY, vZ);
		    			    GetVehicleZAngle(trailerid,vAngle);
		    			    FrakCarInfo[trailerid][fA_x] = vX;
					        FrakCarInfo[trailerid][fA_y] = vY;
					        FrakCarInfo[trailerid][fA_z] = vZ;
					        FrakCarInfo[trailerid][fA_angle] = vAngle;
		    			    FrakCarInfo[trailerid][f_sperre] = true;
							new str[128];
							format(str, sizeof(str), "[OAMT] Euer %s wurde aufgrund einer Ordnungswidrigkeit durch Ordnungsbeamten %s abgeschleppt!", CarName[modelid-400],GetName(playerid));
							SendFraktionMessage(fraktion, COLOR_RED, str);
							Spieler[playerid][pPayCheck] += 5000;
							GameTextForPlayer(playerid, "~g~+$5.000", 2000, 1);
						    new frakname[50];
				            ReturnFraktionByID( fraktion , frakname );
							format(str,sizeof(str),"Ordnungsbeamter %s hat das Fahrzeug von der Fraktion %s abgeschleppt!",GetName(playerid),frakname);
							SendFraktionMessage(5, COLOR_RED, str);
							format(str,sizeof(str),"[OAMT] Ordnungsbeamter: %s , Fahrzeughalter: %s [%d]",GetName(playerid),frakname,fraktion);
							OamtLog(str);
		    			    break;
		    			} else {
			    			SendClientMessage(playerid, COLOR_RED, "Das Motorrad ist kein Fraktionsfahrzeug.");
			    			break;
		    			}
					}
				}
			}
		}
	}
	return 1;
}


CMD:fpunkte(playerid,params[])
{
    new pID,dialogText[128];
    if( Spieler[playerid][pFraktion] != 5 && Spieler[playerid][pFraktion] != 1 && Spieler[playerid][pFraktion] != 2 && Spieler[playerid][pFraktion] != 16 )return SendClientMessage(playerid,COLOR_RED,"Du bist kein Mitarbeiter des Ordnungsamtes");
    if( sscanf(params,"us[128]",pID)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Fpunkte [Spieler]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid,COLOR_RED,"Kein Spieler mit angegebener ID Online");
    pFpunkteID[playerid] = pID;
    format(dialogText,sizeof(dialogText),"Vergeben\nEntfernen");
    ShowPlayerDialog(playerid, DIALOG_FPUNKTE_LIST, DIALOG_STYLE_LIST, "{FF9900}Strafpunkte vergeben", dialogText, "Bestätigen", "Schließen");
    return 1;
}


CMD:kzsuchen(playerid,params[]) {
    if( Spieler[playerid][pFraktion] != 5 && Spieler[playerid][pFraktion] != 1 && Spieler[playerid][pFraktion] != 2 && Spieler[playerid][pFraktion] != 16 && Spieler[playerid][pFraktion] != 22) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist.");
    new kennzeichen[32];
    if(sscanf(params,"s[32]",kennzeichen)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/kzsuchen [Kennzeichen]");
    if(!strcmp(kennzeichen,KEIN_KENNZEICHEN)) return SendClientMessage(playerid,COLOR_BLUE, "Ungültiges Kennzeichen.");
    new giveid = INVALID_PLAYER_ID, slot;
    foreach(new i : Player) {
        if( IsPlayerConnected(i) ) {
            for(new x = 0 , j = MaxVehicles(i) ; x < j;x++) {
                if( (0 < PlayerCar[i][x][CarId] < INVALID_VEHICLE_ID) ) {
                    if( !strcmp(PlayerCar[i][x][CarNumberplate],kennzeichen,true) ) {
                        slot = x;
                        giveid = i;
                        break;
                    }
                }
            }
        }
    }
    if( giveid == INVALID_PLAYER_ID ) return SendClientMessage(playerid,COLOR_BLUE, "Kein Fahrzeughalter mit diesem Kennzeichen gefunden.");
    new vehicleid, modelid, job[50], String[128];
    vehicleid = PlayerCar[giveid][slot][CarId];
    modelid = GetVehicleModel(vehicleid);
    SendClientMessage(playerid,COLOR_LIGHTRED2,"_______KFZ-AKTE_______");
    format(String,sizeof(String),"Fahrzeughalter: %s",GetName(giveid));
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Amtskennzeichen: %s", PlayerCar[giveid][slot][CarNumberplate] );
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Zulassung: %s",HasVehicleLicence(giveid,slot) ? ("Ja"):("Nein"));
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Fahrzeug: %s",CarName[modelid-400]);
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"TÜV: %s", PlayerCar[giveid][slot][TUV] == 0 ? ("Vorhanden") : ("Nicht vorhanden") );
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Steuern: $%s", AddDelimiters(Spieler[giveid][pKFZSteuer]));
    SendClientMessage(playerid,COLOR_WHITE,String);
    ReturnPlayerJob(giveid,job);
    format(String,sizeof(String),"Beruf: %s",job);
    SendClientMessage(playerid,COLOR_WHITE,String);
    return 1;
}

CMD:kfzsuchen(playerid,params[]) {
    if( Spieler[playerid][pFraktion] != 5 && Spieler[playerid][pFraktion] != 1 && Spieler[playerid][pFraktion] != 2 && Spieler[playerid][pFraktion] != 16 && Spieler[playerid][pFraktion] != 22 ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist.");
    new giveid, slot;
    if(sscanf(params,"ud",giveid,slot)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Kfzsuchen [Spieler] [Fahrzeug]");
    if( !IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht Online.");
    if( !( 0 <= slot < MaxVehicles(playerid) ) ) return SendClientMessage(playerid, COLOR_RED, "Das Fahrzeug muss zwischen 0 und "#MaxVeh" liegen.");
    if( !PlayerHaveCar[giveid][slot] ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat in diesem Slot kein Fahrzeug");
    new vehicleid, modelid, job[50], String[128];
    vehicleid = PlayerCar[giveid][slot][CarId];
    modelid = GetVehicleModel(vehicleid);
    SendClientMessage(playerid,COLOR_LIGHTRED2,"_______KFZ-AKTE_______");
    format(String,sizeof(String),"Fahrzeughalter: %s",GetName(giveid));
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Amtskennzeichen: %s", PlayerCar[giveid][slot][CarNumberplate] );
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Zulassung: %s",HasVehicleLicence(giveid,slot) ? ("Ja"):("Nein"));
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Fahrzeug: %s",CarName[modelid-400]);
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"TÜV: %s", PlayerCar[giveid][slot][TUV] == 0 ? ("Vorhanden") : ("Nicht vorhanden") );
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Steuern: $%s", AddDelimiters(Spieler[giveid][pKFZSteuer]));
    SendClientMessage(playerid,COLOR_WHITE,String);
    format(String,sizeof(String),"Bargeld: $%s", AddDelimiters(Spieler[giveid][pCash]));
    SendClientMessage(playerid,COLOR_WHITE,String);
    ReturnPlayerJob(playerid,job);
    format(String,sizeof(String),"Beruf: %s",job);
    SendClientMessage(playerid,COLOR_WHITE,String);
    return 1;
}



CMD:staatrepair(playerid,params[]) {
    if( Spieler[playerid][pFraktion] != 1 && Spieler[playerid][pFraktion] != 2 && Spieler[playerid][pFraktion] != 3 && Spieler[playerid][pFraktion] != 4 && Spieler[playerid][pFraktion] != 5 && Spieler[playerid][pFraktion] != 9 && Spieler[playerid][pFraktion] != 16 && Spieler[playerid][pFraktion] != 18 && Spieler[playerid][pFraktion] != 22 && Spieler[playerid][pFraktion] != 8) return SendClientMessage(playerid,COLOR_RED,"Du kannst diese Funktion nicht nutzen.");
    new vehicleid; vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) return SendClientMessage(playerid,COLOR_RED,"Du bist in keinem Fahrzeug.");
    for(new i ; i < sizeof(g_StaatRepair); i++) {
        if( IsPlayerInRangeOfPoint(playerid,5.0, g_StaatRepair[i][0], g_StaatRepair[i][1], g_StaatRepair[i][2])) {
            RepairVehicle(vehicleid);
            if (IsArmoredVehicle(vehicleid)) SetVehicleHealth(vehicleid, 2000.0);
            gGas[vehicleid] = GetMaxTank(vehicleid);
            SendClientMessage(playerid,COLOR_YELLOW,"Dein Fahrzeug wurde repariert und aufgetankt!");
            return 1;
        }
    }
    SendClientMessage(playerid,COLOR_RED,"Du bist nicht in der Nähe eines Staatrepair-Spots.");
    return 1;
}


CMD:blitzeraufstellen(playerid,params[]) {
    if( Spieler[playerid][pFraktion] != 1 && Spieler[playerid][pFraktion] != 2 && Spieler[playerid][pFraktion] != 5  && Spieler[playerid][pFraktion] != 16 ) return SendClientMessage(playerid,COLOR_RED,"Du bist kein Mitarbeiter des Ordnungsamtes oder der Polizei");
    new limit,geldstrafe, vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if(sscanf(params,"dd",limit,geldstrafe)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Blitzeraufstellen [Geschwindigkeit] [Geldstrafe]");
    if( !vehicleid) return SendClientMessage(playerid,COLOR_RED,"Du sitzt in keinem Fahrzeug");
    if( GetPlayerState(playerid) != PLAYER_STATE_DRIVER ) return SendClientMessage(playerid,COLOR_RED,"Du kannst nur als Fahrer den Blitzer installieren");
    if( !IsACar( GetVehicleModel(vehicleid) ) ) return SendClientMessage(playerid,COLOR_RED,"Du kannst nur in Autos einen Blitzer installieren");
    if( aiVehicleBlitzer[vehicleid][FB_iBlitzerIndex] != -1 ) return SendClientMessage(playerid,COLOR_RED,"Ein Blitzer ist bereits installiert");
    if(geldstrafe < 0) return GiveCheckpointPrison(playerid, 120, "Bugusing, Gruß das Entwickler-Team (Blitzer).");
    new String[128];
    if( AddVehicleBlitzer(vehicleid,limit,geldstrafe) ) {
        format(String,sizeof(String),"%s hat einen Blitzer im Auto installiert (%d km/h, $%d)",GetName(playerid),limit,geldstrafe);
        SendFraktionMessage(1, COLOR_RED, String);
        SendFraktionMessage(2, COLOR_RED, String);
        SendFraktionMessage(5, COLOR_RED, String);
        SendFraktionMessage(16, COLOR_RED, String);
        FreezePlayer(playerid);
    } else {
        SendClientMessage(playerid,COLOR_RED,"Es können keine weiteren Blitzer erstellt werden.");
    }
    return 1;
}

CMD:blitzerabbauen(playerid,params[]) {
    if( Spieler[playerid][pFraktion] != 1 && Spieler[playerid][pFraktion] != 2 && Spieler[playerid][pFraktion] != 5  && Spieler[playerid][pFraktion] != 16 ) return SendClientMessage(playerid,COLOR_RED,"Du bist kein Mitarbeiter des Ordnungsamtes oder der Polizei");
    new vehicleid; 
    vehicleid = GetPlayerVehicleID(playerid);
    if( !vehicleid) return SendClientMessage(playerid,COLOR_RED,"Du sitzt in keinem Fahrzeug");
    if( GetPlayerState(playerid) != PLAYER_STATE_DRIVER ) return SendClientMessage(playerid,COLOR_RED,"Du kannst nur als Fahrer den Blitzer deinstallieren");
    if( !IsACar( GetVehicleModel(vehicleid) ) ) return SendClientMessage(playerid,COLOR_RED,"In diesem Fahrzeug kann kein Blitzer installiert sein");
    if( aiVehicleBlitzer[vehicleid][FB_iBlitzerIndex] == -1 ) return SendClientMessage(playerid,COLOR_RED,"Es ist kein Blitzer installiert");
    new String[128];
    DestroyVehicleBlitzer(vehicleid);
    format(String,sizeof(String),"%s hat den Blitzer im Auto deinstalliert",GetName(playerid));
    SendFraktionMessage(1, COLOR_RED, String);
    SendFraktionMessage(2, COLOR_RED, String);
    SendFraktionMessage(5, COLOR_RED, String);
    SendFraktionMessage(16, COLOR_RED, String);
    UnfreezePlayer(playerid);
    return 1;
}


CMD:deltierverbot(playerid,params[]) {
    if( Spieler[playerid][pFraktion] != 5 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht beim Ordnungsamt.");
    new giveid;
    if(sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Deltierverbot [SpielerID/Name]");
    if( !IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Spieler nicht Online.");
    if( Spieler[giveid][pHaustier] != -1 ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler hat kein Tierhalteverbot.");
    new String[128];
    format(String,sizeof(String),"[TIERAMT] Beamter %s hat Ihr Tierhalteverbot zurückgezogen. Sie dürfen wieder Haustiere besitzen!",GetName(playerid));
    SendClientMessage(giveid,COLOR_YELLOW,String);
    format(String,sizeof(String),"Du hast %s das Tierhalteverbot zurückgezogen.",GetName(giveid));
    SendClientMessage(playerid,COLOR_YELLOW,String);
    Spieler[giveid][pHaustier] = 0;
    return 1;
}


CMD:tierverbot(playerid,params[]) {
    if( Spieler[playerid][pFraktion] != 5 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht beim Ordnungsamt.");
    new giveid;
    if(sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Tierverbot [SpielerID/Name]");
    if( !IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Spieler nicht Online.");
    new String[128];
    Haustier_RemovePlayer(giveid);
    format(String,sizeof(String),"[TIERAMT] Beamter %s hat Ihnen aufgrund eines Verstoßes ein Tierhalteverbot erteilt!",GetName(playerid));
    SendClientMessage(giveid,COLOR_YELLOW,String);
    format(String,sizeof(String),"Beamter %s hat Spieler %s ein Tierhalteverbot erteilt!",GetName(playerid),GetName(giveid));
    SendFraktionMessage(5, COLOR_YELLOW, String);
    Spieler[giveid][pHaustier] = -1;
    Spieler[giveid][pHaustierCooldown] = 0;
    Spieler[giveid][pHaustierSpawned] = false;
    return 1;
}


CMD:parkscheinkontrolle(playerid,params[]) {
    #pragma unused params
    if( Spieler[playerid][pFraktion] != 1 &&
        Spieler[playerid][pFraktion] != 5 &&
        Spieler[playerid][pFraktion] != 16 ) {
        SendClientMessage(playerid, COLOR_RED, "Dieser Befehl ist nur für das Ordnungsamt und Polizisten möglich.");
        return 1;
    }
    new vehicleid = GetClosestVehicle(playerid,4.0);
    if( vehicleid == INVALID_VEHICLE_ID ) {
        SendClientMessage(playerid, COLOR_RED, "Du befindest dich nicht in der Nähe eines Fahrzeuges.");
        return 1;
    }
    new besitzer, slot, String[128];
    SendClientMessage(playerid,COLOR_BLUE,"=== PARKSCHEIN-KONTROLLE ===");
    besitzer = GetCarOwner(vehicleid);
    if( IsPlayerConnected(besitzer)) {
        slot = GetCarOwnerSlot(besitzer, vehicleid);
        format(String,sizeof(String),"Fahrzeug: %s", CarName[GetVehicleModel(vehicleid) - 400]);
        SendClientMessage(playerid,COLOR_WHITE,String);
        format(String,sizeof(String),"Fahrzeughalter: %s", GetName(besitzer) );
        SendClientMessage(playerid,COLOR_WHITE,String);
        if( HasVehicleLicence( besitzer,slot ) ) {
            format(String,sizeof(String),"Kennzeichen: {00FF00}%s", PlayerCar[besitzer][slot][CarNumberplate] );
        } else {
            format(String,sizeof(String),"Kennzeichen: {FF0000}Nicht zugelassen" );
        }
        SendClientMessage(playerid,COLOR_WHITE,String);
        if( g_Parkschein[vehicleid] > gettime() ) {
            format(String,sizeof(String),"Parkschein: {00FF00}Vorhanden", PlayerCar[besitzer][slot][CarNumberplate] );
        } else {
            format(String,sizeof(String),"Parkschein: {FF0000}Nicht vorhanden" );
        }
        SendClientMessage(playerid,COLOR_WHITE,String);
    }
    return 1;
}


CMD:okamera(playerid) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pFraktion] != 5) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist nicht beim Ordnungsamt.");
    GivePlayerWeapon(playerid, WEAPON_CAMERA, 50);
    SetPlayerAmmo(playerid, WEAPON_CAMERA, 50);
    return 1;
}

CMD:olight(playerid,params[]) return cmd_hsirene(playerid, params);



CMD:bc(playerid, params[])
{
    if(Spieler[playerid][pMuted]== 1)return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du bist gemutet.");
    if(Spieler[playerid][bMundbinde]){
        SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du hast eine Mundbinde.");
        return 0;
    }
    new text[96];
    if(pChatSettings[playerid][CHAT_BC] == 0)return SendClientMessage(playerid, COLOR_RED, "Du hast den Beamten Chat für dich deaktiviert, tippe /Chatoff.");
    if(sscanf(params, "s[96]", text))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Bc [Nachricht]");
    if(!IsBeamter(playerid))return SendClientMessage(playerid, COLOR_RED, "Nur für SAPD, FBI, SA-MD, Zollbeamte und O-AMT verfügbar.");
    new string[128];
    new rk[50];
    if(Spieler[playerid][pFraktion] == 1){rk ="LSPD Beamter";}
    else if(Spieler[playerid][pFraktion] == 2){rk ="FBI-Agent";}
    else if(Spieler[playerid][pFraktion] == 3){rk ="Sanitäter";}
    else if(Spieler[playerid][pFraktion] == 5){rk ="Verkehrsüberwachung";}
    else if(Spieler[playerid][pFraktion] == 9){rk ="Regierung";}
    else if(Spieler[playerid][pFraktion] == 16){rk ="LVPD Beamter";}
    else if(Spieler[playerid][pFraktion] == 18){rk ="Soldat";}
    else if(Spieler[playerid][pFraktion] == 22){rk ="Zollbeamter";}
    format(string, sizeof(string), "((** %s %s sagt: %s. **))", rk, GetName(playerid), text);
    for(new i=0;i<MAX_PLAYERS;i++)
    {
        if(IsPlayerConnected(i))
        {
            if(pChatSettings[i][CHAT_BC] == 1)
            {
                if(IsBeamter(i))
                {
                    SendClientMessage(i, COLOR_BCHAT, string);
                }
            }
        }
    }
    printf("[BC] [%s]: %s", GetName(playerid), text);
    return 1;
}
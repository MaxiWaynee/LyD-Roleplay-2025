#include <YSI\y_hooks>


CMD:aufnehmen(playerid, params[])
{
	new Float:x, Float:y, Float:z, Float:distance, Float:smallestDistance = 10000, index = 0, pID, String[128], StringPat[128], vID;
	GetPlayerPos(playerid,x,y,z);
	if(!(Spieler[playerid][pFraktion] == 3))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Sanitäter.");
    if(!Spieler[playerid][pDuty]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Dienst.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Aufnehmen [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pTot] == 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht tot.");
    if(pID == playerid)return SendClientMessage(playerid, COLOR_RED, "Du kannst dich nicht selbst in den Krankenwagen aufnehmen!");
	vID = GetVehicleModel(GetPlayerVehicleID(playerid));
	if(!(vID == 416 || vID == 560 || vID == 426 || vID == 490)) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich nicht in einem geeigneten Fahrzeug!");
	if(GetPlayerVehicleSeat(playerid) != 0)return SendClientMessage(playerid, COLOR_RED, "Nur der Fahrer kann Patienten in das Fahrzeug aufnehmen!");
    if(IsPlayerInRangeOfPoint(playerid, 10.0, Spieler[pID][pTotX], Spieler[pID][pTotY], Spieler[pID][pTotZ])){
        if(Spieler[pID][aufgenommen] == 1) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler wurde bereits aufgenommen!");
    	Spieler[pID][pTotTime] += 30; //Sobald der Tote aufgenommen wurde, ist er 30 Sek länger tot
    	GivePlayerCash(playerid, 800);
     	Kasse[Samd] += 500;
    	format(String, sizeof(String), "* Sanitäter %s hat Patienten %s in sein Fahrzeug aufgenommen.", GetName(playerid), GetName(pID));
    	SendRoundMessage(x, y, z, COLOR_PURPLE, String);
    	ClearAnimations(pID);
		PutPlayerInVehicle(pID, GetPlayerVehicleID(playerid), 3);
		RemovePlayerFromVehicle(pID);
		PutPlayerInVehicle(pID, GetPlayerVehicleID(playerid), 3);
        format(StringPat, sizeof(StringPat), "Sanitäter %s wird dich ins nächste Krankenhaus bringen, wo du behandelt wirst.", GetName(playerid));
        SendClientMessage(pID, COLOR_BLUE, StringPat);
        
		GetPlayerPos(playerid, x, y, z);
		for (new i = 0; i < sizeof(HOSPITAL); i++)
		if ((distance = GetDistance(x, y, z, HOSPITAL[i][0], HOSPITAL[i][1], HOSPITAL[i][2])) < smallestDistance) index = i, smallestDistance = distance;

		SetPlayerCheckpoint(playerid, HOSPITAL[index][0], HOSPITAL[index][1], HOSPITAL[index][2], 2.0);
		SetPlayerCheckpoint(pID, HOSPITAL[index][0], HOSPITAL[index][1], HOSPITAL[index][2], 2.0);
        Spieler[pID][aufgenommen] = 1;
    }
    return 1;
 }

 CMD:deskwb(playerid, params[]){
    new pID;
    if(!(Spieler[playerid][pFraktion] == 3))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Sanitäter.");
    if(!Spieler[playerid][pDuty]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Dienst.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Deskwb [SpielerID/Name]");
    if(Spieler[pID][pTotTime] > 0){
        if(Spieler[pID][aufgenommen] == 1){
	        if(IsPlayerInRangeOfPoint(playerid, 10.0, 1463.9080, -1063.1261, 23.8477) || IsPlayerInRangeOfPoint(playerid, 10.0, 1185.7225,-1323.6067,13.5590) || IsPlayerInRangeOfPoint(playerid, 10.0, 2002.5291,-1445.5175,13.5615)){
				new Float:x, Float:y, Float:z, Float:distance, Float:smallestDistance = 10000, index = 0, String[128], string[128];
				format(String, sizeof(String), "* Patienten %s wurde ins Krankenhaus abgeliefert.", GetName(pID));
				SendRoundMessage(x, y, z, COLOR_PURPLE, String);
				format(string, sizeof(string), "[NOTRUFZENTRALE] Verletzter %s wurde wiederbelebt.", GetName(pID));
	    		SendFraktionMessage(3, COLOR_YELLOW, string);
	    		Spieler[pID][aufgenommen] = 0;
				DisablePlayerCheckpointEx(playerid);
				GetPlayerPos(pID,x,y,z);

                for (new i = 0; i < sizeof(HOSPITAL_Player_POS); i++)
				if ((distance = GetDistance(x, y, z, HOSPITAL_Player_POS[i][0], HOSPITAL_Player_POS[i][1], HOSPITAL_Player_POS[i][2])) < smallestDistance) index = i, smallestDistance = distance;
				SetPlayerPos(pID, HOSPITAL_Player_POS[index][0], HOSPITAL_Player_POS[index][1], HOSPITAL_Player_POS[index][2]);

			    for (new i = 0; i < sizeof(HOSPITAL_CAMERA_POS); i++)
				if ((distance = GetDistance(x, y, z, HOSPITAL_CAMERA_POS[i][0], HOSPITAL_CAMERA_POS[i][1], HOSPITAL_CAMERA_POS[i][2])) < smallestDistance) index = i, smallestDistance = distance;
				SetPlayerCameraPos(pID, HOSPITAL_CAMERA_POS[index][0], HOSPITAL_CAMERA_POS[index][1], HOSPITAL_CAMERA_POS[index][2]);

				for (new i = 0; i < sizeof(HOSPITAL); i++)
				if ((distance = GetDistance(x, y, z, HOSPITAL[i][0], HOSPITAL[i][1], HOSPITAL[i][2])) < smallestDistance) index = i, smallestDistance = distance;
                SetPlayerCameraLookAt(pID, HOSPITAL[index][0], HOSPITAL[index][1], HOSPITAL[index][2]);
				ShowPlayerDialog(pID, DIALOG_REVIVE_SPAWN, DIALOG_STYLE_LIST, COLOR_HEX_ORANGE"Spawnpunkt wählen", COLOR_HEX_WHITE"Gesetzter Spawnpunkt\nKrankenhaus", "Ausführen", "Abbrechen");
			}
        }
    }
    return 1;
 }

CMD:wiederbeleben(playerid, params[])
{
    new pID, string[128];
    if(!(Spieler[playerid][pFraktion] == 3))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Sanitäter.");
    if (!Spieler[playerid][pDuty]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Dienst.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Wiederbeleben [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pTot] == 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht tot.");
    if(pID == playerid)return SendClientMessage(playerid, COLOR_RED, "Du kannst dich nicht selbst wiederbeleben!");
    if( GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) {
        return SendClientMessage(playerid, COLOR_RED, "Du musst zu Fuß unterwegs sein.");
    }
    if( Spieler[playerid][pWiederbelebung] == 1 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du belebst bereits einen Spieler wieder.");
    }
    if( Spieler[pID][pWiederbelebung] == 1 ) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler wird gerade bereits wiederbelebt.");
    }
    if(IsPlayerInRangeOfPoint(playerid, 10.0, Spieler[pID][pTotX], Spieler[pID][pTotY], Spieler[pID][pTotZ]))
    {
        ApplyAnimation(playerid,"MEDIC","CPR", 4.0, 1, 0, 0, 0, 0,1);
        SetTimerEx("Delay_Wiederbeleben",3003,0,"dd",playerid,pID);
        Spieler[pID][pTotTime] += 5;
        if( HasKrankenversicherung(pID) ) {
            format(string, sizeof(string), "* Du belebst %s gerade wieder. (Krankenversicherung)", GetName(pID));
        }
        else {
            Spieler[playerid][pPayCheck] += 2500;
            Kasse[Samd] += 2500;
            format(string, sizeof(string), "* Du belebst %s gerade wieder. (+$2.500 beim PayDay)", GetName(pID));
        }
        SendClientMessage(playerid, COLOR_GREEN, string);
        if (Spieler[playerid][pDuty] == 1) SetPlayerColor(playerid, COLOR_BLUE);
        Spieler[pID][pWiederbelebung] = 1;
        Spieler[playerid][pWiederbelebung] = 1;
    }
    return 1;
}
CMD:sampgarage(playerid,params[]) return cmd_samdgate(playerid,params);
CMD:samdgate(playerid,params[]) {
    new Float:fX, Float:fY, Float:fZ;
    GetDynamicObjectPos(object_samdExteriortor[0], fX, fY, fZ);
    if(IsPlayerInRangeOfPoint(playerid, 8.0, fX, fY, fZ) && !IsPlayerInAnyVehicle(playerid) || IsPlayerInRangeOfPoint(playerid, 8.0, fX, fY, fZ) && IsPlayerInAnyVehicle(playerid)) //Los Santos Ordnungsamt TÜV
    {
        if(!(Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pAdmin] >= 2))return SendClientMessage(playerid, COLOR_WHITE, ERROR_FRAKTION);
        if(SERVER_GATE[7] == 0)
        {	
            SERVER_GATE[7] = 1; MoveDynamicObject(object_samdExteriortor[0], fX, fY,SAMD_CLOSED,3.25);
        }
        else
        {					
            SERVER_GATE[7] = 0; MoveDynamicObject(object_samdExteriortor[0], fX, fY,SAMD_OPEN, 3.25);
        }
    }
    GetDynamicObjectPos(object_samdExteriortor[1], fX, fY, fZ);
    if(IsPlayerInRangeOfPoint(playerid, 8.0, fX, fY, fZ) && !IsPlayerInAnyVehicle(playerid) || IsPlayerInRangeOfPoint(playerid, 8.0, fX, fY, fZ) && IsPlayerInAnyVehicle(playerid)) //Los Santos Ordnungsamt TÜV
    {
        if(!(Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pAdmin] >= 2))return SendClientMessage(playerid, COLOR_WHITE, ERROR_FRAKTION);
        if(SERVER_GATE[8] == 0)
        {	
            SERVER_GATE[8] = 1; MoveDynamicObject(object_samdExteriortor[1], fX, fY, SAMD_CLOSED,3.25);
        }
        else
        {					
            SERVER_GATE[8] = 0; MoveDynamicObject(object_samdExteriortor[1], fX, fY, SAMD_OPEN, 3.25);
        }
    }
    GetDynamicObjectPos(object_samdExteriortor[2], fX, fY, fZ);
    if(IsPlayerInRangeOfPoint(playerid, 8.0, fX, fY, fZ) && !IsPlayerInAnyVehicle(playerid) || IsPlayerInRangeOfPoint(playerid, 8.0, fX, fY, fZ) && IsPlayerInAnyVehicle(playerid)) //Los Santos Ordnungsamt TÜV
    {
        if(!(Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pAdmin] >= 2))return SendClientMessage(playerid, COLOR_WHITE, ERROR_FRAKTION);
        if(SERVER_GATE[9] == 0)
        {	
            SERVER_GATE[9] = 1; MoveDynamicObject(object_samdExteriortor[2], fX, fY,SAMD_CLOSED,3.25);
        }
        else
        {					
            SERVER_GATE[9] = 0; MoveDynamicObject(object_samdExteriortor[2], fX, fY, SAMD_OPEN, 3.25);
        }
    }
    GetDynamicObjectPos(object_samdExteriortor[3], fX, fY, fZ);
    if(IsPlayerInRangeOfPoint(playerid, 8.0, fX, fY, fZ) && !IsPlayerInAnyVehicle(playerid) || IsPlayerInRangeOfPoint(playerid, 8.0, fX, fY, fZ) && IsPlayerInAnyVehicle(playerid)) //Los Santos Ordnungsamt TÜV
    {
        if(!(Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pAdmin] >= 2))return SendClientMessage(playerid, COLOR_WHITE, ERROR_FRAKTION);
        if(SERVER_GATE[10] == 0)
        {	
            SERVER_GATE[10] = 1; MoveDynamicObject(object_samdExteriortor[3], fX, fY, SAMD_CLOSED,3.25);
        }
        else
        {					
            SERVER_GATE[10] = 0; MoveDynamicObject(object_samdExteriortor[3], fX, fY, SAMD_OPEN, 3.25);
        }
    }
    GetDynamicObjectPos(object_samdExteriortor[4], fX, fY, fZ);
    if(IsPlayerInRangeOfPoint(playerid, 8.0, fX, fY, fZ) && !IsPlayerInAnyVehicle(playerid) || IsPlayerInRangeOfPoint(playerid, 8.0, fX, fY, fZ) && IsPlayerInAnyVehicle(playerid)) //Los Santos Ordnungsamt TÜV
    {
        if(!(Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pAdmin] >= 2))return SendClientMessage(playerid, COLOR_WHITE, ERROR_FRAKTION);
        if(SERVER_GATE[11] == 0)
        {	
            SERVER_GATE[11] = 1; MoveDynamicObject(object_samdExteriortor[4], fX, fY, SAMD_CLOSED,3.25);
        }
        else
        {					
            SERVER_GATE[11] = 0; MoveDynamicObject(object_samdExteriortor[4], fX, fY, SAMD_OPEN, 3.25);
        }
    }
    GetDynamicObjectPos(object_samdExteriortor[5], fX, fY, fZ);
    if(IsPlayerInRangeOfPoint(playerid, 8.0, fX, fY, fZ) && !IsPlayerInAnyVehicle(playerid) || IsPlayerInRangeOfPoint(playerid, 8.0, fX, fY, fZ) && IsPlayerInAnyVehicle(playerid)) //Los Santos Ordnungsamt TÜV
    {
        if(!(Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pAdmin] >= 2))return SendClientMessage(playerid, COLOR_WHITE, ERROR_FRAKTION);
        if(SERVER_GATE[12] == 0)
        {	
            SERVER_GATE[12] = 1; MoveDynamicObject(object_samdExteriortor[5], fX, fY, SAMD_CLOSED,3.25);
        }
        else
        {					
            SERVER_GATE[12] = 0; MoveDynamicObject(object_samdExteriortor[5], fX, fY, SAMD_OPEN, 3.25);
        }
    }
    return 1;
}

new Float:DOC_BAG_POS[][][] = {
    {
        {0.333000, 0.030000, 0.042000, 0.000000, -98.400009, -19.999998, 1.055999, 0.523000, 1.271001},
        {0.357000, 0.030000, 0.033000, 0.000000, -98.400009, 4.100003, 1.055999, 0.523000, 1.271001}
    },
    {
        {0.297000, 0.030000, 0.030000, 0.000000, -98.400009, -19.999998, 1.055999, 0.523000, 1.271001},
        {0.335000, 0.030000, 0.045000, -14.200003, -98.400009, 4.100003, 1.055999, 0.523000, 1.271001}
    }
};


CMD:dtasche(playerid, params[]) {
    new doctorBag = GetPVarInt(playerid, "DOCTOR_BAG"), bone = 6;
    if (Spieler[playerid][pFraktion] != 3 && !doctorBag) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Sanitäter.");
    if (!Spieler[playerid][pDuty] && !doctorBag) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Dienst.");

    if (!strcmp(params, "links", true)) bone = 5;
    if (!doctorBag || doctorBag != bone && Spieler[playerid][pFraktion] == 3) {
        new skinIndex, handIndex, playerSkin = GetPlayerSkin(playerid);
        if (279 >= playerSkin >= 277) skinIndex = 1;
        if (bone == 5) handIndex = 1;
        SetPlayerAttachedObject(playerid, 4, 11738, bone, DOC_BAG_POS[skinIndex][handIndex][0], DOC_BAG_POS[skinIndex][handIndex][1], DOC_BAG_POS[skinIndex][handIndex][2],
            DOC_BAG_POS[skinIndex][handIndex][3], DOC_BAG_POS[skinIndex][handIndex][4], DOC_BAG_POS[skinIndex][handIndex][5], DOC_BAG_POS[skinIndex][handIndex][6],
            DOC_BAG_POS[skinIndex][handIndex][7], DOC_BAG_POS[skinIndex][handIndex][8]);

        new message[128];
        format(message, sizeof(message), "Du hast deine Doktortasche in die %s Hand genommen.", bone == 5 ? "linke" : "rechte");
        SendClientMessage(playerid, COLOR_GREEN, message);
    }
    else {
        RemovePlayerAttachedObject(playerid, 4);
        SendClientMessage(playerid, COLOR_ORANGE, "Du hast deine Doktortasche weggesteckt.");
    }

    SetPVarInt(playerid, "DOCTOR_BAG", doctorBag == bone ? 0 : bone);
    return 1;
}

CMD:sfinden(playerid, params[])
{
    new pID, string[128];
    if(!(Spieler[playerid][pFraktion] == 3)) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Sanitäter.");
    if(sscanf(params, "u", pID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Sfinden [SpielerID/Name]");
    if(!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pTot] == 0) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht tot.");
    SetPlayerCheckpointEx(playerid, Spieler[pID][pTotX], Spieler[pID][pTotY], Spieler[pID][pTotZ], 5.0, CP_TOT);
    format(string, sizeof(string), "* %s wurde auf der Karte makiert, Gebäude-Komplex: %d. Fahre schnell zu ihm/ihr!", GetName(pID), GetPlayerInterior(pID));
    SendClientMessage(playerid, COLOR_LIGHTRED2, string);
    return 1;
}

CMD:sheilen(playerid, params[])
{
    new pID, string[128];
    if(!(Spieler[playerid][pFraktion] == 3))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Sanitäter.");
    if (!Spieler[playerid][pDuty]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Dienst.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Sheilen [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(pID == playerid)return SendClientMessage(playerid, COLOR_RED, "Du kannst dich selber nicht heilen.");
    new vID = GetPlayerVehicleID(playerid);
    new pvID = GetPlayerVehicleID(pID);
    if(pvID == vID)
    {
        if(IsPlayerInAnyVehicle(playerid) && IsPlayerInAnyVehicle(pID))
        {
            if( aiVehicles[vID] == VEH_SANICARS ) {
                new Float:health;
                GetPlayerHealth(pID, health);
                if(health >= 90)
                {
                    return SendClientMessage(playerid, COLOR_ORANGE, "Der Spieler hat noch genug Leben.");
                }
                new seat1 = GetPlayerVehicleSeat(playerid);
                new seat2 = GetPlayerVehicleSeat(pID);
                if( seat1 != 2 && seat1 != 3 && seat2 != 2 && seat2 != 3 ) {
                    return SendClientMessage(playerid, COLOR_ORANGE, "Für die Behandlung müssen Arzt und Patient im Behandlungsbereich des Wagens sein");
                }
                format(string, sizeof(string), "Sanitäter %s bietet Ihnen eine ärztliche Behandlung für 100$ an. Mit '/Accept Arzt' können Sie dem einwilligen!", GetName(playerid));
                SendClientMessage(pID, COLOR_LIGHTBLUE, string);
                format(string, sizeof(string), "Du hast %s angeboten,ihn zu heilen.", GetName(pID));
                SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                /*
                format(string, sizeof(string), "Sanitäter %s hat dich geheilt.", GetName(playerid));
                format(string, sizeof(string), "Du hast %s geheilt.", GetName(pID));
                SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                */
                Spieler[pID][pSHeilen] = playerid;
                return 1;
            }
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du oder der andere Spieler seit nicht im selben Fahrzeug.");
            return 1;
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deinem Fahrzeug.");
        return 1;
    }
    return 1;
}


CMD:acceptsani(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Acceptsani [SpielerID/Name]");
    if(Spieler[playerid][pFraktion] != 3)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Sanitäter!");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online!");
    if(GetPlayerInterior(pID) > 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in einem Gebäude.");
    if(NeedMedic[pID] == 0)return SendClientMessage(playerid, COLOR_ORANGE, "Der Spieler benötigt keinen Sanitäter. Verwende /sliste um die Service-Liste zu sehen.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x,y,z);
    SetPlayerCheckpointEx(playerid, x,y,z, 5.0, CP_ACCEPTSANI);
    format(string, sizeof(string), "* Du hast den Notruf von %s angenommen, ein Roter Punkt wurde auf der Karte markiert.", GetName(pID));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "[RETTUNGSDIENST] Sanitäter %s hat deinen Notruf angenommen und ist nun unterwegs zu dir!", GetName(playerid));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    NeedMedic[pID] = 0;
    return 1;
}



CMD:medic(playerid,params[]){
    if( !(Spieler[playerid][pFraktion] == 3) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Medic!");
    }
    /*
    if( GetPlayerSkin(playerid) != 280 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur mit dem Polizei Skin nutzen");
    }
    */
    if( IsPlayerAttachedObjectSlotUsed(playerid,1) ) {
        RemovePlayerAttachedObject(playerid,1);
        RemovePlayerAttachedObject(playerid,2);
        SendClientMessage(playerid,COLOR_YELLOW,"Medic-Inventare entfernt");
    }
    else {
        SetPlayerAttachedObject( playerid, 1, 2690, 1, 0.054082, -0.264567, 0.004729, 0.000000, 64.513916, 0.000000, 1.000000, 1.000000, 1.000000 ); // Feuerlöscher
        SetPlayerAttachedObject( playerid, 2, 19472, 2, -0.023322, 0.084270, 0.005550, 334.849060, 172.559661, 15.323401, 1.000000, 1.000000, 1.000000 ); // gasmask01 - gas
        SendClientMessage(playerid,COLOR_YELLOW,"Medic-Inventare genommen");
    }
    return 1;
}

CMD:meinsatz(playerid,params[]){
    if (Spieler[playerid][pFraktion] != 3) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied des SAMD.");
    new vehicleid = GetPlayerVehicleID(playerid);
    if (!vehicleid) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur in einem SAMD-Fahrzeug nutzen.");

	if(FrakCarInfo[vehicleid][f_frak] == 3){
		if (_:g_t3dPolizeiKontrolle[vehicleid] != INVALID_3DTEXT_ID) {
  			Delete3DTextLabel(g_t3dPolizeiKontrolle[vehicleid]);
            g_t3dPolizeiKontrolle[vehicleid] = Text3D:INVALID_3DTEXT_ID;
     	}
        else {
        	g_t3dPolizeiKontrolle[vehicleid] = Create3DTextLabel("--> MEDIC IM EINSATZ <--\nBitte überholen!", 0xFF2000FF, 0.0, 0.0, 0.0, 25.0, 0, 1);
            Attach3DTextLabelToVehicle( g_t3dPolizeiKontrolle[vehicleid],vehicleid,0.0,0.0,0.5);
        }
        return 1;
    }

    return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur in einem SAMD-Fahrzeug nutzen.");
}



CMD:sanagarage(playerid, params[]) {
	if (Spieler[playerid][pFraktion] != 4) return SendClientMessage(playerid, COLOR_RED, "Du bist kein News-Reporter.");
	if (!IsPlayerInRangeOfPoint(playerid, 20.0, SANABASE_GARAGE_FOR_RANGE_COORDS)) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Garagentores.");

	new Float:fX, Float:fY, Float:fZ;
	GetDynamicObjectPos(object_sanaBase_garageDoor, fX, fY, fZ);

	if (fZ == SANABASE_GARAGE_OPEN_Z)
		MoveDynamicObject(object_sanaBase_garageDoor, fX, fY, SANABASE_GARAGE_CLOSED_Z, 2.0);
	else
		MoveDynamicObject(object_sanaBase_garageDoor, fX, fY, SANABASE_GARAGE_OPEN_Z, 2.0);

	return 1;
}



CMD:mv(playerid,params[]) {
    #pragma unused params
    if( Spieler[playerid][pFraktion] != 3) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Sanitäter.");
    }
    if( Spieler[playerid][pDuty] == 0 ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Dienst.");
        return 1;
    }
    new
        String[128];
    if( Spieler[playerid][pDutyTask] == 1 ) {
        format(String,sizeof(String),"[LEITZENTRALE] Notarzt %s ist wieder verfügbar!",GetName(playerid));
        SendFraktionMessage(3, COLOR_GREEN, String);
        Spieler[playerid][pDutyTask] = 0;
    }
    else {
        format(String,sizeof(String),"[LEITZENTRALE] Notarzt %s meldet sich als nicht verfügbar!",GetName(playerid));
        SendFraktionMessage(3, COLOR_ORANGE, String);
        Spieler[playerid][pDutyTask] = 1;
    }
    return 1;
}
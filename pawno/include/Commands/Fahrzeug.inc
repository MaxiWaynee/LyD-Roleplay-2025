#include <YSI\y_hooks>

CMD:flugzeugrepair(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid,10.0, AIRPORTLS_REPAIR_POINT))
    {
        if(IsAPlane(GetVehicleModel(GetPlayerVehicleID(playerid))))
        {
            if(Spieler[playerid][pCash]>=2000)
            {
                SetVehicleHealth(GetPlayerVehicleID(playerid),1000);
                GivePlayerCash(playerid,-2000);
                RepairVehicle(GetPlayerVehicleID(playerid));
            }
            else
            {
                SendClientMessage(playerid,COLOR_RED,"Du benötigst für die Reparatur 2.000$.");
            }
        }
        else
        {
            SendClientMessage(playerid,COLOR_RED,"Du sitzt in keinem Flugzeug!");
        }
    }
    else
    {
        SendClientMessage(playerid,COLOR_RED,"Du befindest dich nicht an der Werkstatt am Los Santos Airport.");
    }
    return 1;
}


CMD:tuningabbauen(playerid)
{
    new newcar = GetPlayerVehicleID(playerid);
    if(newcar == PlayerCar[playerid][PlayerKey[playerid]][CarId])
    {
        if(IsPlayerInRangeOfPoint(playerid, 5.0, 1782.8275,-1702.7240,13.5096))
        {
            if(Spieler[playerid][pCash]>=3000)
            {
                PlayerCar[playerid][PlayerKey[playerid]][CarNitro]=0;
                PlayerCar[playerid][PlayerKey[playerid]][CarHyd]=0;
                PlayerCar[playerid][PlayerKey[playerid]][CarWheel]=0;
                PlayerCar[playerid][PlayerKey[playerid]][CarAusp]=0;
                PlayerCar[playerid][PlayerKey[playerid]][CarSideL]=0;
                PlayerCar[playerid][PlayerKey[playerid]][CarSideR]=0;
                PlayerCar[playerid][PlayerKey[playerid]][CarFB]=0;
                PlayerCar[playerid][PlayerKey[playerid]][CarRB]=0;
                PlayerCar[playerid][PlayerKey[playerid]][CarSpoiler]=0;
                PlayerCar[playerid][PlayerKey[playerid]][CarRoof]=0;
                PlayerCar[playerid][PlayerKey[playerid]][CarHood]=0;
                PlayerCar[playerid][PlayerKey[playerid]][CarVents]=0;
                PlayerCar[playerid][PlayerKey[playerid]][CarLamps]=0;
                PlayerCar[playerid][PlayerKey[playerid]][CarPJ]=-1;
                new Float:X, Float:Y,Float:Z,Float:xa,Float:xb,Float:xc;
                new Float:z_rot,Float:xz;
                GetPlayerPos(playerid, X,Y,Z);
                GetVehicleZAngle(newcar, z_rot);
                xa=PlayerCar[playerid][PlayerKey[playerid]][CarPos_x];
                xb=PlayerCar[playerid][PlayerKey[playerid]][CarPos_y];
                xc=PlayerCar[playerid][PlayerKey[playerid]][CarPos_z];
                xz=PlayerCar[playerid][PlayerKey[playerid]][CarRotate];
                //
                PlayerCar[playerid][PlayerKey[playerid]][CarPos_x] = X;
                PlayerCar[playerid][PlayerKey[playerid]][CarPos_y] = Y;
                PlayerCar[playerid][PlayerKey[playerid]][CarPos_z] = Z;
                PlayerCar[playerid][PlayerKey[playerid]][CarRotate] = z_rot;
                SendClientMessage(playerid, COLOR_GREEN, "Dein Tuning wurde vollständig für $3.000 abgebaut.");
                SavePlayerCar( playerid, PlayerKey[playerid] );
                PlayerCarSpawn(playerid,PlayerKey[playerid]);
                Spieler[playerid][pCash]-=3000;
                PlayerCar[playerid][PlayerKey[playerid]][CarPos_x]=xa;
                PlayerCar[playerid][PlayerKey[playerid]][CarPos_y]=xb;
                PlayerCar[playerid][PlayerKey[playerid]][CarPos_z]=xc;
                PlayerCar[playerid][PlayerKey[playerid]][CarRotate]=xz;
                SavePlayerCar( playerid, PlayerKey[playerid] );
            }
            else
            {
                SendClientMessage(playerid,COLOR_RED,"Du hast nicht genügend Geld. Du benötigst $3.000.");
            }
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED,"Du befindest dich nicht an der Werkstatt, wo du dein Tuning abbauen lassen kannst.");
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht in deinem Fahrzeug oder du hast keinen Schlüssel.");
    }
    return 1;
}


CMD:mieten(playerid)
{
    if(Spieler[playerid][pLevel] > 4 && Spieler[playerid][pAdmin] < ADMIN_RANK_MANAGER) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht unter Level 5.");//3 4
    if(pCar[playerid] != INVALID_VEHICLE_ID)return SendClientMessage(playerid, COLOR_WHITE, "Du hast bereits ein Fahrzeug gemietet. Tippe /Entmieten.");
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, BIKERENTAL_NOOBSPAWN_COORDS) && !IsPlayerInRangeOfPoint(playerid, 2.0, BIKERENTAL_DRIVINGSCHOOL_COORDS) && !IsPlayerInRangeOfPoint(playerid, 2.0, BIKERENTAL_CITYHALL_COORDS))
    {
        return SendClientMessage(playerid, COLOR_RED, "Du bist nicht am Verleih.");
    }
    ShowPlayerDialog(playerid, DIALOG_MIETEN, DIALOG_STYLE_LIST, "Mieten eines Fahrzeugs", "Bike - $250\nMountain Bike - $300\nBMX - $250\nFaggio - $500", "Mieten", "Abbrechen");
    return 1;
}


CMD:entmieten(playerid)
{
    if(Spieler[playerid][pVehicleVerleih] == INVALID_VEHICLE_ID && pCar[playerid] == INVALID_VEHICLE_ID) return SendClientMessage(playerid, COLOR_WHITE, "Du hast kein Fahrzeug gemietet.");
    SendClientMessage(playerid, COLOR_GREEN, "Du hast dein Mietfahrzeug wieder abgegeben.");
    if (pCar[playerid] != INVALID_VEHICLE_ID) {
        DestroyVehicleEx(pCar[playerid] );
        aiVehicles[pCar[playerid] ] = VEH_INVALID;
        pCar[playerid] = INVALID_VEHICLE_ID;
    }

    if (Spieler[playerid][pVehicleVerleih] != INVALID_VEHICLE_ID) {
        DestroyVehicleEx(Spieler[playerid][pVehicleVerleih]);
        aiVehicles[Spieler[playerid][pVehicleVerleih]] = VEH_INVALID;
        Spieler[playerid][pVehicleVerleih] = INVALID_VEHICLE_ID;
    }
    return 1;
}


CMD:joblock(playerid)
{
    if(Spieler[playerid][pJob] == 0)// Arbeitslos
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist Arbeitslos.");
        return 1;
    }
    new vehicleid = GetPlayerVehicleID(playerid);
    if( !vehicleid ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in einem Fahrzeug.");
    }
    // So geht es viel schneller
    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
    if( VEH_DROGEN <= aiVehicles[vehicleid] <= VEH_KFZCARS ) {
        if(doors == VEHICLE_PARAMS_ON)
        {
            UnLockCar(vehicleid);
            GameTextForPlayer(playerid, "~w~Job-Fahrzeug~n~~g~Aufgeschlossen", 3000, 4);
        }
        else if(doors == VEHICLE_PARAMS_OFF || doors == VEHICLE_PARAMS_UNSET)
        {
            LockCar(vehicleid);
            GameTextForPlayer(playerid, "~w~Job-Fahrzeug~n~~r~Abgeschlossen", 3000, 4);
        }
    }
    return 1;
}

CMD:vlock(playerid,params[])
{
    if( Spieler[playerid][pVehicleVerleih] != INVALID_VEHICLE_ID)
    {
        new engine, lights, alarm, doors, bonnet, boot, objective;
        GetVehicleParamsEx( Spieler[playerid][pVehicleVerleih], engine, lights, alarm, doors, bonnet, boot, objective);
        if(doors == VEHICLE_PARAMS_ON)
        {
            UnLockCar( Spieler[playerid][pVehicleVerleih]);
            GameTextForPlayer(playerid, "~w~Verleih-Fahrzeug~n~~g~Aufgeschlossen", 3000, 4);
        }
        else if(doors == VEHICLE_PARAMS_OFF || doors == VEHICLE_PARAMS_UNSET)
        {
            LockCar( Spieler[playerid][pVehicleVerleih]);
            GameTextForPlayer(playerid, "~w~Verleih-Fahrzeug~n~~r~Abgeschlossen", 3000, 4);
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "Du hast kein Fahrzeug geliehen.");
        return 1;
    }
    return 1;
}

CMD:mietlock(playerid,params[]) {
    return cmd_vlock(playerid,params);
}



CMD:lock(playerid)
{
    if(pCar[playerid] != INVALID_VEHICLE_ID)
    {
        new engine, lights, alarm, doors, bonnet, boot, objective;
        GetVehicleParamsEx(pCar[playerid], engine, lights, alarm, doors, bonnet, boot, objective);
        if(doors == VEHICLE_PARAMS_ON)
        {
            UnLockCar(pCar[playerid]);
            GameTextForPlayer(playerid, "~w~Miet-Fahrzeug~n~~g~Aufgeschlossen", 3000, 4);
        }
        else if(doors == VEHICLE_PARAMS_OFF || doors == VEHICLE_PARAMS_UNSET)
        {
            LockCar(pCar[playerid]);
            GameTextForPlayer(playerid, "~w~Miet-Fahrzeug~n~~r~Abgeschlossen", 3000, 4);
        }
    }
    else
    {
        // vllt /veh
        new vehicleid = GetPlayerVehicleID(playerid);
        if( vehicleid && (aiVehicles[ vehicleid ] == VEH_CAR || aiVehicles[ vehicleid ] == VEH_SUPCAR)  ) {
            if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
                new engine, lights, alarm, doors, bonnet, boot, objective;
                GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
                if(doors == VEHICLE_PARAMS_ON)
                {
                    UnLockCar(vehicleid);
                    GameTextForPlayer(playerid, "~w~Fahrzeug~n~~g~Aufgeschlossen", 3000, 4);
                }
                else if(doors == VEHICLE_PARAMS_OFF || doors == VEHICLE_PARAMS_UNSET)
                {
                    LockCar(vehicleid);
                    GameTextForPlayer(playerid, "~w~Fahrzeug~n~~r~Abgeschlossen", 3000, 4);
                }
            }
            else {
                SendClientMessage(playerid, COLOR_WHITE, "Nur der Fahrer kann das Fahrzeug abschließen.");
            }
        }
        else {
            SendClientMessage(playerid, COLOR_WHITE, "Du hast kein Fahrzeug gemietet.");
        }
        return 1;
    }
    return 1;
}



CMD:radio(playerid)
{
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        new vID = GetPlayerVehicleID(playerid);
        new mod = GetVehicleModel(vID);
        if(IsBicycle(mod))return SendClientMessage(playerid, COLOR_ORANGE, "Du kannst kein Radio auf einem Fahrrad hören.");
        ShowPlayerDialog(playerid, DIALOG_RADIO, DIALOG_STYLE_LIST, COLOR_HEX_ORANGE"Radiosender", COLOR_HEX_WHITE"Radio ausschalten\n1-Live\nTechnoBase.FM\nHardBase.FM\nI Love Radio\nBreakz.us\nYouFM\nPlanet Radio\nThe Club\nNightWax\nI Love Mashup\nDas Hitradio\nI Love the Battle\nI Love 2Dance\nLogin-Musik\niTunes Hot 40\nRMF MAXXX\nEigener Audiostream", "Auswählen", "Abbrechen");
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Dazu musst du der Fahrer sein.");
        return 1;
    }
    return 1;
}




CMD:kanister(playerid)
{
    new vID = GetPlayerVehicleID(playerid);
    if (!vID) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist in keinem Fahrzeug.");
    if (Spieler[playerid][pKanister] == 0) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du besitzt keinen Kanister.");
    if (Refueling[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du tankst gerade!");
    if (vehicleRefueling[vID]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Das Fahrzeug wird bereits betankt!");
    if (gGas[vID] == gMaxGas[vID]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Das Fahrzeug ist bereits vollgetankt.");
    Spieler[playerid][pKanister]--;
    gGas[vID] += 10;
    if (gGas[vID] > gMaxGas[vID]) gGas[vID] = gMaxGas[vID];
    return SendClientMessage(playerid, COLOR_GREEN, "[INFO] {FFFFFF}Du hast 10 Liter aufgefüllt.");
}

CMD:tanken(playerid)
{
    new t = IsPlayerAtTanke(playerid);
    if (t == 999) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keiner Tankstelle.");
    if (!strcmp(Tanke[t][tBesitzer], "Niemand", true)) return SendClientMessage(playerid, COLOR_RED, "Die Tankstelle hat keinen Besitzer.");
    new vehid = GetPlayerVehicleID(playerid), model = GetVehicleModel(vehid);
    if (!vehid) {
        UnfreezePlayer(playerid);
        return SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Fahrzeug.");
    }

    if (Refueling[playerid] || vehicleRefueling[vehid]) return SendClientMessage(playerid, COLOR_RED, "Das Fahrzeug wird bereits betankt.");
    if (IsBicycle(model)) return SendClientMessage(playerid, COLOR_RED, "Fahrräder können nicht aufgetankt werden.");

    LoadTankKraftstoff(playerid,t);
    return 1;
}

CMD:sellcarto(playerid,params[]) return cmd_carsellto(playerid,params);

CMD:carsellto(playerid, params[])
{
    new pID, string[128], price;
    if(sscanf(params, "ui", pID, price))return SendClientMessage(playerid, COLOR_GREY, "* Benutze /carsellto [SpielerID/Name] [Preis]");
    if(pID == playerid)return SendClientMessage(playerid, COLOR_GREY, "Du kannst dir selbst kein Auto schenken.");
    if(PlayerCar[playerid][PlayerKey[playerid]][CarPreis] == 0) PlayerCar[playerid][PlayerKey[playerid]][CarPreis] = 100000;
    new prozent = PlayerCar[playerid][PlayerKey[playerid]][CarPreis]*40/100;
    new maxpreis = PlayerCar[playerid][PlayerKey[playerid]][CarPreis] + prozent;
    new minpreis = PlayerCar[playerid][PlayerKey[playerid]][CarPreis] - prozent;
    if(price < minpreis || price > maxpreis)return SCMFormatted(playerid, COLOR_GREY, "Der Preis muss zwischen $%s und $%s liegen.",AddDelimiters(minpreis),AddDelimiters(maxpreis));
    new Float:tempX, Float:tempY, Float:tempZ;
    GetPlayerPos(pID, tempX, tempY, tempZ);
    if(!IsPlayerInRangeOfPoint(playerid, 5.0, tempX, tempY, tempZ))return SendClientMessage(playerid, COLOR_GREY, "Der Spieler ist nicht in deiner Nähe.");
    if(PlayerHaveCar[playerid][PlayerKey[playerid]])
    {
        if(!PlayerHaveCar[pID][PlayerKey[pID]])
        {
            format(string, sizeof(string), "* %s hat dir sein Fahrzeug \"%s\" für $%d angeboten.", GetName(playerid), CarName[PlayerCar[playerid][0][CarModel]-400], price);
            SendClientMessage(pID, COLOR_YELLOW, string);
            format(string, sizeof(string), "* Du hast dein Fahrzeug \"%s\" für $%d für %s angeboten.", CarName[PlayerCar[playerid][0][CarModel]-400], price, GetName(pID));
            SendClientMessage(playerid, COLOR_YELLOW, string);
            SendClientMessage(pID, COLOR_BLUE, "INFO: "COLOR_HEX_WHITE"Tippe \"/accept carsell\" um den Fahrzeug-Kauf anzunehmen.");
            AcceptCarSell[pID] = playerid;
            AcceptCarSellPreis[pID] = price;
        }
        else
        {
            SendClientMessage(playerid, COLOR_GREY, "Der Spieler hat auf dem Schlüssel bereits ein Fahrzeug.");
            return 1;
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_GREY, "Du hast auf dem Schlüssel kein Fahrzeug.");
        return 1;
    }
    return 1;
}


CMD:carlock(playerid)
{
    new Float:X1, Float:Y1, Float:Z1;
    if(PlayerHaveCar[playerid][PlayerKey[playerid]])
    {
        new engine, light, alarm, doors, bonnet, boot, objective;
        GetVehicleParamsEx(PlayerCar[playerid][PlayerKey[playerid]][CarId], engine, light, alarm, doors, bonnet, boot, objective);
        new State = doors;
        GetVehiclePos(PlayerCar[playerid][PlayerKey[playerid]][CarId], X1, Y1, Z1);
        for(new i = 0 ; i < MAX_PLAYERS ; i++)
        {
            if(IsPlayerConnected(i) && IsPlayerInRangeOfPoint(i, 20.0, X1,Y1,Z1))
            {
                PlayerPlaySound(i, 1147, X1,Y1,Z1);
            }
        }
        //printf("CMD: carlock State = %d ",State);
        if(State == VEHICLE_PARAMS_OFF || State == VEHICLE_PARAMS_UNSET)
        {
            GameTextForPlayer(playerid, "~w~Fahrzeug~n~~r~abgeschlossen", 3000, 4);
            PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);
            LockCar(PlayerCar[playerid][PlayerKey[playerid]][CarId]);
        }
        else if(State == VEHICLE_PARAMS_ON)
        {
            GameTextForPlayer(playerid, "~w~Fahrzeug~n~~g~aufgeschlossen", 3000, 4);
            PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);
            UnLockCar(PlayerCar[playerid][PlayerKey[playerid]][CarId]);
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Auf dem ausgewählten Schlüssel ist kein Fahrzeug.");
        return 1;
    }
    return 1;
}

CMD:movecarkey(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt.");
    return ShowPlayerCarkeys(playerid, CARKEY_TYPE_MOVE1);
}


CMD:carkey(playerid)
{
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt.");
    return ShowPlayerCarkeys(playerid, CARKEY_TYPE_NORMAL);
}

CMD:findcar(playerid)
{
    if(PlayerHaveCar[playerid][PlayerKey[playerid]])
    {
        if(PlayerCar[playerid][PlayerKey[playerid]][CarState] == e_Vehicle_Status_Destroyed )
        {
            SendClientMessage(playerid,COLOR_RED,"Dein Fahrzeug ist für 1.500$ in Reparatur.");
            SendClientMessage(playerid,COLOR_RED,"Mit /Fahrzeugreparieren zahlst du die Kosten und erhältst dein Fahrzeug.");
        }
        new Float:x, Float: y, Float:z;
        GetVehiclePos(PlayerCar[playerid][PlayerKey[playerid]][CarId], x, y, z);
        SetPlayerCheckpointEx(playerid, x,y,z, 5.0, CP_FINDCAR);
        SendClientMessage(playerid, COLOR_WHITE, "Dein Fahrzeug wurde geortet.");
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "Auf diesem Schlüssel ist kein Fahrzeug belegt.");
        return 1;
    }
    return 1;
}


CMD:findmietcar(playerid)
{
    if(Spieler[playerid][pVehicleVerleih]!=INVALID_VEHICLE_ID)
    {
        new Float:x, Float: y, Float:z;
        GetVehiclePos(Spieler[playerid][pVehicleVerleih],x,y,z);
        SetPlayerCheckpointEx(playerid, x,y,z, 5.0, CP_FINDCAR);
        SendClientMessage(playerid, COLOR_WHITE, "Dein Mietfahrzeug wurde geortet.");
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "Du besitzt kein Mietfahrzeug.");
        return 1;
    }
    return 1;
}

CMD:parken(playerid)
{
    if(PlayerHaveCar[playerid][PlayerKey[playerid]])
    {
            new newcar = GetPlayerVehicleID(playerid);
            if(newcar == PlayerCar[playerid][PlayerKey[playerid]][CarId])
            {
                new Float:X, Float:Y,Float:Z;
                new Float:z_rot;
                GetPlayerPos(playerid, X,Y,Z);
                GetVehicleZAngle(newcar, z_rot);
                PlayerCar[playerid][PlayerKey[playerid]][CarPos_x] = X;
                PlayerCar[playerid][PlayerKey[playerid]][CarPos_y] = Y;
                PlayerCar[playerid][PlayerKey[playerid]][CarPos_z] = Z;
                PlayerCar[playerid][PlayerKey[playerid]][CarRotate] = z_rot;
                SendClientMessage(playerid, COLOR_YELLOW, "Dein Fahrzeug wurde erfolgreich geparkt.");
                SavePlayerCar( playerid, PlayerKey[playerid] );
            }
            else
            {
                SendClientMessage(playerid, COLOR_RED, "Du bist nicht in deinem Fahrzeug oder du hast keinen Schlüssel.");
                return 1;
            }
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du besitzt kein Fahrzeug.");
        return 1;
    }
    return 1;
}

CMD:sellcar(playerid) return cmd_carsell(playerid);

CMD:carsell(playerid)
{
    if(PlayerHaveCar[playerid][PlayerKey[playerid]])
    {
        if(PlayerCar[playerid][PlayerKey[playerid]][CarState] != e_Vehicle_Status_Normal) {
            SendClientMessage(playerid,COLOR_RED,"Du kannst dein Fahrzeug nicht verkaufen, da es zerstört oder abgeschleppt ist.");
            return 1;
        }
        new dialogText[512];
        format(dialogText, sizeof(dialogText),
        "{FFFFFF}Bist du sicher, dass du das Fahrzeug verkaufen willst?\n\n\
        {3592D7}Fahrzeug: {FFFFFF}%s\n\
        {3592D7}Kennzeichen: {FFFFFF}%s\n\
        {3592D7}Slot: {FFFFFF}%d \n\
        {3592D7}Verkaufspreis: {FFFFFF}$%s",
            CarName[PlayerCar[playerid][PlayerKey[playerid]][CarModel] - 400], PlayerCar[playerid][PlayerKey[playerid]][CarNumberplate],
            PlayerKey[playerid] + 1, AddDelimiters(PlayerCar[playerid][PlayerKey[playerid]][CarPreis]));
        return ShowPlayerDialog(playerid, DIALOG_CARSELL, DIALOG_STYLE_MSGBOX, "Fahrzeug verkaufen", dialogText, "Verkaufen", "Abbrechen");
    }

    return SendClientMessage(playerid, COLOR_RED, "Du besitzt kein Fahrzeug oder auf dem Schlüssel ist kein Fahrzeug.");
}


CMD:motor(playerid) {
    new engine, lights, alarm, doors, bonnet, boot, objective, player_fraktion = Spieler[playerid][pFraktion], vID = GetPlayerVehicleID(playerid), fraktion = GetVehicleFraktion(vID),
		mod = GetVehicleModel(GetPlayerVehicleID(playerid)), slot = GetCarOwnerSlot(playerid, vID), besitzer = GetCarOwner(vID);
    if(!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist nicht eingeloggt!");
	if(vID == INVALID_VEHICLE_ID) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist in keinem Fahrzeug.");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst der Fahrer des Fahrzeuges sein!");
    if(IsBicycle(mod))return SendClientMessage(playerid, COLOR_RED,"[INFO] {FFFFFF}Fahrräder haben keinen Motor.");
    if(vID == vehicle_cityhallExterior[0])return SendClientMessage(playerid,COLOR_WHITE,"Jeff: Hey, wieso willst Du meinen Van klauen?");
    //if(vID == vehicle_cityhallExterior[0])return SendClientMessage(playerid,COLOR_WHITE,"Mr. Whoopee: Das Schloss ist eingefroren, damit kommst du nicht weg!");
    if( gGas[vID] < 1 ) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Das Fahrzeug hat kein Benzin mehr.");
    GetVehicleParamsEx(vID, engine, lights, alarm, doors, bonnet, boot, objective);
    if(engine == VEHICLE_PARAMS_OFF || engine == VEHICLE_PARAMS_UNSET) {
        if( fraktion && ( fraktion != 8) ) {
            if( (fraktion != player_fraktion) && !IsPoliceVehicleAllowed(player_fraktion,fraktion) ) {
                if(engine == VEHICLE_PARAMS_OFF || engine == VEHICLE_PARAMS_UNSET) {
                    SendClientMessage(playerid, COLOR_YELLOW, "Du kannst den Motor nicht starten, da du nicht der Fraktion angehörst.");
                }
                else {
                    SendClientMessage(playerid, COLOR_YELLOW, "Du kannst den Motor nicht ausschalten, da du nicht der Fraktion angehörst.");
				}
				return 1;
			}
		}
		KillTimer(carmsgwait[playerid]);
  		SetVehicleParamsEx(vID, VEHICLE_PARAMS_ON, lights, alarm, doors, bonnet, boot, objective);
  		SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast deinen Motor eingeschaltet.");
  		if( playerid == besitzer ) {
			if( PlayerCar[playerid][slot][TUV] == 1 && !IsBicycle(GetVehicleModel(vID))) {
                SendClientMessage(playerid, COLOR_YELLOW, "FAHRZEUGHINWEIS: Das Fahrzeug hat viel an Kilometern zurückgelegt, weshalb allgemeine TÜV-Wartungen anfallen!");
                SendClientMessage(playerid, COLOR_YELLOW, "Suche die TÜV-Werkstatt auf, um alle nötigen Wartungen abzuschließen. Befehl: /Werkstattplatz");
			}
		}
    }
    else {
    	KillTimer(carmsgwait[playerid]);
    	SetVehicleParamsEx(vID, VEHICLE_PARAMS_OFF, lights, alarm, doors, bonnet, boot, objective);
    	SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast deinen Motor ausgeschaltet.");
    }
	return 1;
}

CMD:licht(playerid) {
	new engine, light, alarm, doors, bonnet, boot, objective, vid = GetPlayerVehicleID(playerid), mod = GetVehicleModel(GetPlayerVehicleID(playerid));
	if(!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist nicht eingeloggt!");
	if(vid == INVALID_VEHICLE_ID) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist in keinem Fahrzeug.");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst der Fahrer des Fahrzeuges sein!");
    if(IsBicycle(mod))return SendClientMessage(playerid, COLOR_RED,"[INFO] {FFFFFF}Das Licht kann an Fahrrädern nicht bedient werden.");
    GetVehicleParamsEx(vid, engine, light, alarm, doors, bonnet, boot, objective);
    if(light == VEHICLE_PARAMS_OFF || light == VEHICLE_PARAMS_UNSET) {
    	KillTimer(carmsgwait[playerid]);
    	SetVehicleParamsEx(vid, engine, VEHICLE_PARAMS_ON, alarm, doors, bonnet, boot, objective);
    	SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast das Licht eingeschaltet.");
    }
    else {
    	KillTimer(carmsgwait[playerid]);
    	SetVehicleParamsEx(vid, engine, VEHICLE_PARAMS_OFF, alarm, doors, bonnet, boot, objective);
    	SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast das Licht ausgeschaltet.");
    }
	return 1;
}

CMD:fenster(playerid, params[]) {
	new window[9],string[128],w_driver,w_passenger,w_backleft,w_backright,veh = GetPlayerVehicleID(playerid),Float:x,Float:y,Float:z;
 	if(!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist nicht eingeloggt!");
	if(veh == INVALID_VEHICLE_ID) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist in keinem Fahrzeug.");
	if(!IsACar(GetVehicleModel(veh))) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du kannst das Fenster nur in Autos öffnen.");
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst der Fahrer des Fahrzeuges sein!");
	if(sscanf(params,"s[9]",window)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Fenster [Alle | Vorne | VLinks | VRechts | Hinten | HLinks | HRechts]");
	GetVehicleParamsCarWindows(veh,w_driver,w_passenger,w_backleft,w_backright);
	GetPlayerPos(playerid, x, y, z);
	if(strfind(window, "Alle",true) != -1) {
	    if(w_driver == 0 || w_passenger == 0 ||w_backleft == 0 || w_backright == 0) {
	        format(string,sizeof(string),"* %s hat alle Fenster vom Fahrzeug geschlossen.",GetName(playerid));
	        SendRoundMessage(x, y, z, COLOR_PURPLE, string);
	        return SetVehicleParamsCarWindows(veh,1,1,1,1);
	    }
	    format(string,sizeof(string),"* %s hat alle Fenster vom Fahrzeug geöffnet.",GetName(playerid));
     	SendRoundMessage(x, y, z, COLOR_PURPLE, string);
	    return SetVehicleParamsCarWindows(veh,0,0,0,0);
	}
	else if(strfind(window, "Vorne",true) != -1) {
		if(w_driver == 0 || w_passenger == 0) {
	        format(string,sizeof(string),"* %s hat das Vordere Fenster vom Fahrzeug geschlossen.",GetName(playerid));
	        SendRoundMessage(x, y, z, COLOR_PURPLE, string);
	        return SetVehicleParamsCarWindows(veh,1,1,w_backleft,w_backright);
	    }
	    format(string,sizeof(string),"* %s hat das Vordere Fenster vom Fahrzeug geöffnet.",GetName(playerid));
     	SendRoundMessage(x, y, z, COLOR_PURPLE, string);
	    return SetVehicleParamsCarWindows(veh,0,0,w_backleft,w_backright);
	}
	else if(strfind(window, "VLinks",true) != -1) {
	    if(w_driver == 0) {
	        format(string,sizeof(string),"* %s hat das Vordere Fenster Links vom Fahrzeug geschlossen.",GetName(playerid));
	        SendRoundMessage(x, y, z, COLOR_PURPLE, string);
	        return SetVehicleParamsCarWindows(veh,1,w_passenger,w_backleft,w_backright);
	    }
	    format(string,sizeof(string),"* %s hat das Vordere Fenster Links vom Fahrzeug geöffnet.",GetName(playerid));
     	SendRoundMessage(x, y, z, COLOR_PURPLE, string);
	    return SetVehicleParamsCarWindows(veh,0,w_passenger,w_backleft,w_backright);
	}
	else if(strfind(window, "VRechts",true) != -1) {
		if(w_passenger == 0) {
	        format(string,sizeof(string),"* %s hat das Vordere Fenster Rechts vom Fahrzeug geschlossen.",GetName(playerid));
	        SendRoundMessage(x, y, z, COLOR_PURPLE, string);
	        return SetVehicleParamsCarWindows(veh,w_driver,1,w_backleft,w_backright);
	    }
	    format(string,sizeof(string),"* %s hat das Vordere Fenster Rechts vom Fahrzeug geöffnet.",GetName(playerid));
     	SendRoundMessage(x, y, z, COLOR_PURPLE, string);
	    return SetVehicleParamsCarWindows(veh,w_driver,0,w_backleft,w_backright);
	}
	else if(strfind(window, "Hinten",true) != -1) {
	    if(w_backleft == 0 || w_backright == 0) {
	    	format(string,sizeof(string),"* %s hat das Hintere Fenster vom Fahrzeug geschlossen.",GetName(playerid));
	        SendRoundMessage(x, y, z, COLOR_PURPLE, string);
	        return SetVehicleParamsCarWindows(veh,w_driver,w_passenger,1,1);
	    }
	    format(string,sizeof(string),"* %s hat das Hintere Fenster vom Fahrzeug geöffnet.",GetName(playerid));
     	SendRoundMessage(x, y, z, COLOR_PURPLE, string);
	    return SetVehicleParamsCarWindows(veh,w_driver,w_passenger,0,0);
	}
	else if(strfind(window, "HLinks",true) != -1) {
	    if(w_backleft == 0) {
	        format(string,sizeof(string),"* %s hat das Hintere Fenster Links vom Fahrzeug geschlossen.",GetName(playerid));
	        SendRoundMessage(x, y, z, COLOR_PURPLE, string);
	        return SetVehicleParamsCarWindows(veh,w_driver,w_passenger,1,w_backright);
	    }
	    format(string,sizeof(string),"* %s hat das Hintere Fenster Links vom Fahrzeug geöffnet.",GetName(playerid));
     	SendRoundMessage(x, y, z, COLOR_PURPLE, string);
		SetVehicleParamsCarWindows(veh,w_driver,w_passenger,0,w_backright);
	}
	else if(strfind(window, "HRechts",true) != -1) {
	    if(w_backright == 0) {
	        format(string,sizeof(string),"* %s hat das Hintere Fenster Rechts vom Fahrzeug geschlossen.",GetName(playerid));
	        SendRoundMessage(x, y, z, COLOR_PURPLE, string);
	        return SetVehicleParamsCarWindows(veh,w_driver,w_passenger,w_backleft,1);
	    }
	    format(string,sizeof(string),"* %s hat das Hintere Fenster Rechts vom Fahrzeug geöffnet.",GetName(playerid));
     	SendRoundMessage(x, y, z, COLOR_PURPLE, string);
		SetVehicleParamsCarWindows(veh,w_driver,w_passenger,w_backleft,0);
	}
	return 1;
}


CMD:rauswerfen(playerid,params[]) {
    new
        my_vehicle,
        giveid_vehicle,
        giveid;
    my_vehicle = GetPlayerVehicleID(playerid);
    if(!my_vehicle) {
        return SendClientMessage(playerid,COLOR_RED,"Diese Funktion funktioniert nur in einem Fahrzeug!");
    }
    if( GetPlayerVehicleSeat(playerid) != 0 ) {
        return SendClientMessage(playerid,COLOR_RED,"Diese Funktion funktioniert nur als Fahrer des Fahrzeuges!");
    }
    if( sscanf(params,"u",giveid)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Rauswerfen [Spieler]");
    }
    if(!IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    }
    if(playerid == giveid) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst dich nicht selber aus dem Fahrzeug werfen.");
    }
    giveid_vehicle = GetPlayerVehicleID(giveid);
    if( giveid_vehicle != my_vehicle ) {
        return SendClientMessage(playerid,COLOR_RED,"Der genannte Spieler befindet sich nicht in deinem Fahrzeug");
    }
    new
        String[128];
    format(String,sizeof(String),"%s hat %s aus seinem Fahrzeug geworfen!",GetName(playerid),GetName(giveid));
    RemovePlayerFromVehicle(giveid);
    OnPlayerExitVehicle(giveid,my_vehicle);
    SendClientMessage(playerid,COLOR_WHITE,String);
    return 1;
}


CMD:werkstattplatz(playerid)
{
    SetPlayerCheckpointEx(playerid, TUEV_AUTO_POINT, 2.0, CP_SHOWJOB1);
    SendClientMessage(playerid, COLOR_GREEN, "Die TÜV-Werkstatt für Autos und Motorräder wurde dir auf der Karte markiert!");
    return 1;
}


CMD:rtwsirene(playerid,params[]) {

    new
        modelid,
        vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) return SendClientMessage(playerid, COLOR_RED, "Diese Funktion ist nur in einem Fahrzeug möglich.");
    if( GetPlayerState(playerid) != PLAYER_STATE_DRIVER ) return SendClientMessage(playerid, COLOR_RED, "Diese Funktion ist nur als Fahrer möglich.");
    modelid = GetVehicleModel(vehicleid);
    if( (modelid != 416) ) return SendClientMessage(playerid, COLOR_RED, "Diese Funktion kann nur in einem Krankenwagen ausgeführt werden!");
    if( g_aiVehicleSirene[vehicleid][0] == INVALID_OBJECT_ID ) {
        g_aiVehicleSirene[vehicleid][0] = CreateDynamicObject( 11701, 0.0, 0.0, 0.0, 0.0, 0.0, 80.0 ); // <rtw hsirene>
        AttachDynamicObjectToVehicle( g_aiVehicleSirene[vehicleid][0] , vehicleid,0.000000, 0.899999, 1.200000, 0.000000, 0.000000, 0.000000 ); // <rtw hsirene>
        g_aiVehicleSirene[vehicleid][1] = CreateDynamicObject( 18646 , 0.0 , 0.0 , 0.0, 0.0 , 0.0, 0.80 );
        AttachDynamicObjectToVehicle( g_aiVehicleSirene[vehicleid][1] , vehicleid,1.000000, -3.399999, 1.800000, 0.000000, 0.000000, 0.000000);
        g_aiVehicleSirene[vehicleid][2] = CreateDynamicObject( 18646 , 0.0 , 0.0 , 0.0, 0.0 , 0.0, 0.80 );
        AttachDynamicObjectToVehicle( g_aiVehicleSirene[vehicleid][2] , vehicleid,-1.000000, -3.399998, 1.800000, 0.000000, 0.000000, 0.000000);
        SendClientMessage(playerid,COLOR_GREEN,"Sirene eingeschaltet");
    }
    else {
        DestroyDynamicObject( g_aiVehicleSirene[vehicleid][0] );
        g_aiVehicleSirene[vehicleid][0] = INVALID_OBJECT_ID;
        DestroyDynamicObject( g_aiVehicleSirene[vehicleid][1] );
        g_aiVehicleSirene[vehicleid][1] = INVALID_OBJECT_ID;
        DestroyDynamicObject( g_aiVehicleSirene[vehicleid][2] );
        g_aiVehicleSirene[vehicleid][2] = INVALID_OBJECT_ID;
        SendClientMessage(playerid,COLOR_ORANGE,"Sirene ausgeschaltet");
    }
    Streamer_Update(playerid);
    return 1;
}


CMD:neonweis(playerid)  return cmd_neon(playerid);
CMD:neonblau(playerid)  return cmd_neon(playerid);
CMD:neongruen(playerid) return cmd_neon(playerid);
CMD:neonrot(playerid) return cmd_neon(playerid);
CMD:neonpink(playerid) return cmd_neon(playerid);
CMD:neongelb(playerid) return cmd_neon(playerid);

CMD:neon(playerid) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pPremiumNeon] != 1) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du besitzt kein Premium-Neon.");
    if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst der Fahrer eines Fahrzeugs sein.");
    new vehicleid = GetPlayerVehicleID(playerid);
    if (!IsACar(GetVehicleModel(vehicleid))) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Neon kann nur an Autos angebracht werden.");

    if (g_aiVehicleSirene[vehicleid][0] != INVALID_OBJECT_ID) {
        DestroyDynamicObject(g_aiVehicleSirene[vehicleid][0]);
        g_aiVehicleSirene[vehicleid][0] = INVALID_OBJECT_ID;
        DestroyDynamicObject(g_aiVehicleSirene[vehicleid][1]);
        g_aiVehicleSirene[vehicleid][1] = INVALID_OBJECT_ID;
        return SendClientMessage(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Neonlichter deaktiviert.");
    }

    new dialogText[256];
    for (new i = 0; i < sizeof(g_NeonLights); i++)
        format(dialogText, sizeof(dialogText), "%s%s%se Neonröhren\n", dialogText, g_NeonLights[i][NEON_HEX_COLOR], g_NeonLights[i][NEON_NAME]);

    return ShowPlayerDialog(playerid, DIALOG_NEON, DIALOG_STYLE_LIST, "{FF9900}Neonlichter anbauen", dialogText, "Anbauen", "Schließen");
}


CMD:flock(playerid, params[]) {
    new vehicleid = GetPlayerVehicleID(playerid), fraktion;
    if (!vehicleid) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in einem Fahrzeug.");
    fraktion = GetVehicleFraktion(vehicleid);
    if (!fraktion) return SendClientMessage(playerid, COLOR_RED, "Das Fahrzeug ist kein Fraktionsfahrzeug.");
    if (fraktion != Spieler[playerid][pFraktion]) return SendClientMessage(playerid, COLOR_RED, "Du hast keine Schlüssel für dieses Fraktionsfahrzeug.");

    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
    if(doors == VEHICLE_PARAMS_ON)
    {
        UnLockCar(vehicleid);
        GameTextForPlayer(playerid, "~w~Fraktions-Fahrzeug~n~~g~Aufgeschlossen", 3000, 4);
    }
    else if(doors == VEHICLE_PARAMS_OFF || doors == VEHICLE_PARAMS_UNSET)
    {
        LockCar(vehicleid);
        GameTextForPlayer(playerid, "~w~Fraktions-Fahrzeug~n~~r~Abgeschlossen", 3000, 4);
    }
    return 1;
}


CMD:bikefarbe(playerid,params[]) {
    if( !IsPlayerInRangeOfPoint(playerid,5.0,1702.9427,-1470.3704,13.5469)) {
        return SendClientMessage(playerid,COLOR_GREEN,"Du bist nicht an einer Bikelackiererei");
    }
    new
        color1,
        color2,
        vehicleid,
        modelid,
        colorid[2];
    if(sscanf(params,"iI(-1)",colorid[0],colorid[1])) {
        SendClientMessage(playerid,COLOR_BLUE, "* Benutze:"COLOR_HEX_GREENA" /Bikefarbe [ID]");
        return SendClientMessage(playerid,COLOR_GREEN,"0 = Schwarz, 1 = Weiß, 2 = Blau, 3 = Rot, 5 = Pink, 6 = Gelb, 7 = Grün, 8 = Grau, 9 = Braun");
    }
    if( colorid[1] == -1) { // keine farbe 2, dann farbe1 doppeln
        colorid[1] = colorid[0];
    }
    if( !(0 <= colorid[0] <= 9 ) || !(0 <= colorid[1] <= 9 )) {
        SendClientMessage(playerid,COLOR_BLUE, "* Benutze:"COLOR_HEX_GREENA" /Bikefarbe [ID]");
        return SendClientMessage(playerid,COLOR_GREEN,"0 = Schwarz, 1 = Weiß, 2 = Blau, 3 = Rot, 5 = Pink, 6 = Gelb, 7 = Grün, 8 = Grau, 9 = Braun");
    }
    if( CheckMoney(playerid) < 2000 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du benötigst 2.000$ um dein Motorrad/Fahrrad umzulackieren.");
    }
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) {
        return SendClientMessage(playerid,COLOR_RED,"Du benötigst ein Motorrad/Fahrrad");
    }
    modelid = GetVehicleModel(vehicleid);
    if(!IsABike(modelid) || IsAMBike(modelid)) {
        return SendClientMessage(playerid,COLOR_RED,"Du benötigst ein Motorrad/Fahrrad");
    }
    new
        owner,
        String[128];
    format(String,sizeof(String),"Die Farbe deines Motorrades wurde geändert auf ID %d und %d",colorid[0],colorid[1]);
    SendClientMessage(playerid,COLOR_GREEN,String);
    switch(colorid[0]) {
        case 0: color1 = 0;
        case 1: color1 = 1;
        case 2: color1 = 7;
        case 3: color1 = 3;
        case 4: color1 = 16;
        case 5: color1 = 126;
        case 6: color1 = 6;
        case 7: color1 = 16;
        case 8: color1 = 13;
        case 9: color1 = 30;
    }
    switch(colorid[1]) {
        case 0: color2 = 0;
        case 1: color2 = 1;
        case 2: color2 = 7;
        case 3: color2 = 3;
        case 4: color2 = 16;
        case 5: color2 = 126;
        case 6: color2 = 6;
        case 7: color2 = 16;
        case 8: color2 = 13;
        case 9: color2 = 30;
    }
    GivePlayerCash(playerid,-2000);
    ChangeVehicleColor(vehicleid,color1,color2);
    owner = GetCarOwner(vehicleid);
    if( owner == playerid ) { // Wenn man als Besitzer die Farbe ändert
        new
            slot;
        slot = GetCarOwnerSlot(owner,vehicleid);
        if( slot != 555 ) {
            PlayerCar[owner][slot][CarC1] = color1;
            PlayerCar[owner][slot][CarC2] = color2;
        }
    }
    return 1;
}

CMD:autofarbe(playerid,params[]) {
    if( !IsPlayerInRangeOfPoint(playerid,5.0,1763.4915,2080.2959,10.8203)) {
        return SendClientMessage(playerid,COLOR_GREEN,"Du bist nicht an einer Autolackiererei!");
    }
    new
        color1,
        color2,
        vehicleid,
        modelid,
        colorid[2];
    if(sscanf(params,"iI(-1)",colorid[0],colorid[1])) {
        SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Autofarbe [Farben-ID] ([Farben-ID])");
        return SendClientMessage(playerid,COLOR_GREEN,"0 = Schwarz, 1 = Weiß, 2 = Blau, 3 = Rot, 5 = Pink, 6 = Gelb");
    }
    if( colorid[1] == -1) { // keine farbe 2, dann farbe1 doppeln
        colorid[1] = colorid[0];
    }
    if( !(0 <= colorid[0] <= 6 ) || !(0 <= colorid[1] <= 6 )) {
        SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Autofarbe [Farben-ID]  ([Farben-ID])");
        return SendClientMessage(playerid,COLOR_GREEN,"0 = Schwarz, 1 = Weiß, 2 = Blau, 3 = Rot, 5 = Pink, 6 = Gelb");
    }
    if( CheckMoney(playerid) < 1500 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du benötigst 1500$ um dein Auto umzulackieren");
    }
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) {
        return SendClientMessage(playerid,COLOR_RED,"Du benötigst ein Auto");
    }
    modelid = GetVehicleModel(vehicleid);
    if(!IsACar(modelid)) {
        return SendClientMessage(playerid,COLOR_RED,"Du benötigst ein Auto");
    }
    new
        owner,
        String[128];
    format(String,sizeof(String),"Die Farbe deines Autos wurde geändert auf ID %d und %d",colorid[0],colorid[1]);
    SendClientMessage(playerid,COLOR_GREEN,String);
    switch(colorid[0]) {
        case 0: color1 = 0;
        case 1: color1 = 1;
        case 2: color1 = 7;
        case 3: color1 = 3;
        case 4: color1 = 16;
        case 5: color1 = 126;
        case 6: color1 = 6;
    }
    switch(colorid[1]) {
        case 0: color2 = 0;
        case 1: color2 = 1;
        case 2: color2 = 7;
        case 3: color2 = 3;
        case 4: color2 = 16;
        case 5: color2 = 126;
        case 6: color2 = 6;
    }
    GivePlayerCash(playerid,-1500);
    ChangeVehicleColor(vehicleid,color1,color2);
    owner = GetCarOwner(vehicleid);
    if( owner == playerid ) { // Wenn man als Besitzer die Farbe ändert
        new
            slot;
        slot = GetCarOwnerSlot(owner,vehicleid);
        if( slot != 555 ) {
            PlayerCar[owner][slot][CarC1] = color1;
            PlayerCar[owner][slot][CarC2] = color2;
        }
    }
    return 1;
}
CMD:flugzeugfarbe(playerid,params[]) {
    if( !IsPlayerInRangeOfPoint(playerid,5.0, AIRPORTLS_PAINTJOB_POINT)) {
        return SendClientMessage(playerid,COLOR_GREEN,"Du bist nicht an einer Flugzeuglackiererei!");
    }
    new
        color1,
        color2,
        vehicleid,
        modelid,
        colorid[2];
    if(sscanf(params,"iI(-1)",colorid[0],colorid[1])) {
        SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Flugzeugfarbe [Farben-ID] ([Farben-ID])");
        return SendClientMessage(playerid,COLOR_GREEN,"0 = Schwarz, 1 = Weiß, 2 = Blau, 3 = Rot, 5 = Pink, 6 = Gelb");
    }
    if( colorid[1] == -1) { // keine farbe 2, dann farbe1 doppeln
        colorid[1] = colorid[0];
    }
    if( !(0 <= colorid[0] <= 6 ) || !(0 <= colorid[1] <= 6 )) {
        SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/flugzeugfarbe [Farben-ID]  ([Farben-ID])");
        return SendClientMessage(playerid,COLOR_GREEN,"0 = Schwarz, 1 = Weiß, 2 = Blau, 3 = Rot, 5 = Pink, 6 = Gelb");
    }
    if( CheckMoney(playerid) < 4500 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du benötigst 4500$ um dein Flugzeug umzulackieren");
    }
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) {
        return SendClientMessage(playerid,COLOR_RED,"Du benötigst ein Flugzeug");
    }
    modelid = GetVehicleModel(vehicleid);
    if(!IsAPlane(modelid)) {
        return SendClientMessage(playerid,COLOR_RED,"Du benötigst ein Flugzeug");
    }
    new
        owner,
        String[128];
    format(String,sizeof(String),"Die Farbe von deinem Flugzeug wurde geändert auf ID %d und %d",colorid[0],colorid[1]);
    SendClientMessage(playerid,COLOR_GREEN,String);
    switch(colorid[0]) {
        case 0: color1 = 0;
        case 1: color1 = 1;
        case 2: color1 = 7;
        case 3: color1 = 3;
        case 4: color1 = 16;
        case 5: color1 = 126;
        case 6: color1 = 6;
    }
    switch(colorid[1]) {
        case 0: color2 = 0;
        case 1: color2 = 1;
        case 2: color2 = 7;
        case 3: color2 = 3;
        case 4: color2 = 16;
        case 5: color2 = 126;
        case 6: color2 = 6;
    }
    GivePlayerCash(playerid,-4500);
    ChangeVehicleColor(vehicleid,color1,color2);
    owner = GetCarOwner(vehicleid);
    if( owner == playerid ) { // Wenn man als Besitzer die Farbe ändert
        new
            slot;
        slot = GetCarOwnerSlot(owner,vehicleid);
        if( slot != 555 ) {
            PlayerCar[owner][slot][CarC1] = color1;
            PlayerCar[owner][slot][CarC2] = color2;
        }
    }
    return 1;
}


CMD:fahrzeugschein(playerid,params[]) {
    new
        str[64],
        giveid;
    format(str,sizeof(str),"U(%d)",playerid);
    if(sscanf(params,str,giveid)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Fahrzeugschein [Spieler]");
    }
    if( !IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht Online.");
    }
    new
        Float:X,Float:Y,Float:Z;
    GetPlayerPos(playerid,X,Y,Z);
    if( !IsPlayerInRangeOfPoint(giveid,5.0,X,Y,Z)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Nähe.");
    }
    if( !PlayerHaveCar[playerid][PlayerKey[playerid]] ) {
        return SendClientMessage(playerid, COLOR_RED, "Du hast gerade kein Fahrzeug gewählt ( /carkey ).");
    }
    new
        slot,
        vehicleid,
        modelid,
        String[128];
    slot = PlayerKey[playerid];
    vehicleid = PlayerCar[playerid][slot][CarId];
    modelid = GetVehicleModel(vehicleid);
    if(playerid != giveid) {
        format(String,sizeof(String),"Du hast dein Fahrzeugschein %s gezeigt",GetName(giveid));
        SendClientMessage(playerid,COLOR_WHITE,String);
        format(String,sizeof(String),"Spieler %s zeigt dir seinen Fahrzeugschein",GetName(playerid));
        SendClientMessage(giveid,COLOR_LIGHTRED2,String);
    }
    SendClientMessage(giveid,COLOR_GREEN,"_______FAHRZEUGSCHEIN_______");
    format(String,sizeof(String),"Fahrzeughalter: %s", GetName(playerid) );
    SendClientMessage(giveid,COLOR_WHITE,String);
    format(String,sizeof(String),"Amtskennzeichen: %s", PlayerCar[playerid][slot][CarNumberplate] );
    SendClientMessage(giveid,COLOR_WHITE,String);
    format(String,sizeof(String),"Zulassung: %s", HasVehicleLicence(playerid,slot) ? ("ZUGELASSEN"):("NICHT ZUGELASSEN") );
    SendClientMessage(giveid,COLOR_WHITE,String);
    format(String,sizeof(String),"Fahrzeug: %s",CarName[modelid-400]);
    SendClientMessage(giveid,COLOR_WHITE,String);
    format(String,sizeof(String),"TÜV: %s", PlayerCar[playerid][slot][TUV] == 0 ? ("Vorhanden") : ("Nicht vorhanden") );
    SendClientMessage(giveid,COLOR_WHITE,String);
    return 1;
}

CMD:kr(playerid, params[]) return cmd_kofferraum(playerid, params);

CMD:kofferraum(playerid,params[]) {
    new
        vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Fahrzeug.");
    }
    if( GetPlayerState(playerid) != PLAYER_STATE_DRIVER ) {
        return SendClientMessage(playerid, COLOR_RED, "Du musst der Fahrer dieses Fahrzeuges zum Öffnen sein.");
    }
    new engine,lights,doors,bonnet,boot,objective,alarm;
    GetVehicleParamsEx(vehicleid,engine,lights,alarm,doors,bonnet,boot,objective);
    if(boot > 0 ) {
        SetVehicleParamsEx(vehicleid,engine,lights,alarm,doors,bonnet,false,objective);
        SendClientMessage(playerid, COLOR_ORANGE, "Kofferraum geschlossen" );
    }
    else {
        SetVehicleParamsEx(vehicleid,engine,lights,alarm,doors,bonnet,true,objective);
        SendClientMessage(playerid, COLOR_GREEN, "Kofferraum geöffnet" );
    }
    return 1;
}

CMD:kra(playerid, params[]) return cmd_kofferraumansehen(playerid, params);

CMD:kofferraumansehen(playerid,params[]) {
    new
        vehicleid;
    vehicleid = GetClosestVehicle(playerid,4.0);
    if( IsPlayerInAnyVehicle(playerid)) {
        SendClientMessage(playerid, COLOR_RED, "Du musst am Kofferraum sein");
        return 1;
    }
    if( vehicleid == INVALID_VEHICLE_ID ) {
        SendClientMessage(playerid, COLOR_RED, "Du befindest dich in direkter Nähe zu einem Fahrzeug");
        return 1;
    }
    if( !IsTrunkOpen(vehicleid) ) {
        return SendClientMessage(playerid, COLOR_RED, "Der Kofferraum dieses Fahrzeuges ist geschlossen");
    }
    if( Spieler[playerid][pLevel] < 4 ) {
        SendClientMessage(playerid, COLOR_RED, "Diese Funktion ist für Spieler unter Level 4 nicht möglich.");
        return 1;
    }
    ShowKofferraum(playerid,vehicleid);
    return 1;
}

CMD:zulassungsstelle(playerid,params[]) {
	if( !IsPlayerInRangeOfPoint(playerid,5.0,2316.4529,-12.6540,26.7422) || !IsPlayerInRangeOfPoint(playerid,5.0,2316.3318,-9.9532,26.7422) )
        return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe der Zulassungsstelle.");

	return
	ShowPlayerDialog(playerid,DIALOG_ZULASSUNGSSTELLE,DIALOG_STYLE_LIST,"Zulassungsstelle","Fahrzeug zulassen\nFahrzeug abmelden","Weiter","Abbruch");

}


CMD:motorhaube(playerid,parmas[]) return cmd_haube(playerid);

CMD:haube(playerid) {
    new
        vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Fahrzeug!");
    }
    if( GetPlayerState(playerid) != PLAYER_STATE_DRIVER ) {
        return SendClientMessage(playerid, COLOR_RED, "Du musst der Fahrer dieses Fahrzeuges zum Öffnen sein!");
    }
    new engine,lights,doors,bonnet,boot,objective,alarm;
    GetVehicleParamsEx(vehicleid,engine,lights,alarm,doors,bonnet,boot,objective);
    if(bonnet > 0 ) {
        SetVehicleParamsEx(vehicleid,engine,lights,alarm,doors,false,boot,objective);
        SendClientMessage(playerid, COLOR_ORANGE, "Motorhaube geschlossen" );
    }
    else {
        SetVehicleParamsEx(vehicleid,engine,lights,alarm,doors,true,boot,objective);
        SendClientMessage(playerid, COLOR_GREEN, "Motorhaube geöffnet" );
    }
    return 1;
}


CMD:helm(playerid,params[]) {
    if(!Spieler[playerid][pHelm]) {
        return SendClientMessage(playerid, COLOR_RED,"Du besitzt keinen Motorrad Helm!");
    }
    if( IsPlayerAttachedObjectSlotUsed(playerid,ATTACHED_INDEX_HELM)) {
        RemovePlayerAttachedObject(playerid,ATTACHED_INDEX_HELM);
        SendClientMessage(playerid,COLOR_ORANGE,"Helm abgesetzt");
    }
    else {
        Helmet_SetPlayerHelmet(playerid);
        SendClientMessage(playerid,COLOR_GREEN,"Helm aufgesetzt");
    }
    return 1;
}



CMD:warnblinker(playerid,params[]) {
    new vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) return SendClientMessage(playerid,COLOR_RED,"Du kannst den Warnblinker nur in einem Fahrzeug aktivieren.");
    if( GetPlayerState(playerid) != PLAYER_STATE_DRIVER ) return SendClientMessage(playerid,COLOR_RED,"Du kannst den Warnblinker nur als Fahrer aktivieren.");
    new modelid = GetVehicleModel(vehicleid);
    if(!IsACar(modelid)) return SendClientMessage(playerid,COLOR_RED,"Du kannst den Warnblinker nur in Autos aktivieren.");
    if( GetVehicleIndicator(vehicleid) == 3 ) {
        DestroyBlinker(vehicleid,0);
        DestroyBlinker(vehicleid,1);
        SendClientMessage(playerid,COLOR_YELLOW,"Warnblinker deaktiviert");
    }
    else {
        SetVehicleIndicator(vehicleid,1,1);
        SendClientMessage(playerid,COLOR_GREEN,"Warnblinker aktiviert");
    }
    return 1;
}




CMD:parkschein(playerid,params[]) {
    #pragma unused params
    new automat = IsPlayerAtParkautomat(playerid);
    if(automat == 999)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keinem Parkschein Automat.");
    if(!PlayerHaveCar[playerid][PlayerKey[playerid]]) SendClientMessage(playerid, COLOR_RED, "Auf dem ausgewählten Schlüssel ist kein Fahrzeug.");
    new
        sInfo[512];
    sInfo = "{3333FF}STAATLICHER PARKSCHEINAUTOMAT\n\n\
        {FFFFFF}Ein Parkschein kostet 300$.\n\
        Damit haben Sie die Berechtigung für 3 Stunden Ihr Fahrzeug\n\
        auf den öffentlichen Parkplätzen der Stadthalle und am Hauptammunation abzustellen.\n\n\
        Fahrzeuge die auf den öffentlichen Parkplätzen der Stadthalle oder am Hauptammunation ohne\n\
        gültigem Parkschein abgestellt werden, erhalten ein Bußgeld in Höhe von 3,000$.\n\n\
        HINWEIS:\n\
        Wenn du dich ausloggst, erlischt die Gültigkeit von deinem Parkschein.";
    ShowPlayerDialog(playerid,DIALOG_PARKSCHEIN,DIALOG_STYLE_MSGBOX,"Parkschein Automat",sInfo,"Kaufen","Abbrechen");
    return 1;
}



CMD:fahrzeuginfo(playerid,params[]) {
    #pragma unused params
    new
        vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) {
        return SendClientMessage(playerid,COLOR_RED,"Du befindest dich in keinem Fahrzeug");
    }
    new
        sNameUnpacked[MAX_PLAYER_NAME],
        String[128];
    SendClientMessage(playerid,COLOR_BLUE,"Die letzten "#MAX_PASSANGERS_TRACKER" Fahrer waren:");
    for(new i ; i < MAX_PASSANGERS_TRACKER ; i++) {
        strunpack(sNameUnpacked,g_aiLastPassengers[vehicleid][i]);
        if(!isnull(sNameUnpacked)) {
            format(String,sizeof(String),"%d) %s",(i+1),sNameUnpacked);
            SendClientMessage(playerid,COLOR_YELLOW,String);
        }
    }
    return 1;
}


CMD:fixcar(playerid, params[]) return cmd_fahrzeugreparieren(playerid, params);

CMD:fahrzeugreparieren(playerid,params[]) {
    #pragma unused params
    if(PlayerHaveCar[playerid][PlayerKey[playerid]])
    {
        new
            String[128],
            key;
        key = PlayerKey[playerid];
        if( PlayerCar[playerid][key][CarState] == e_Vehicle_Status_Destroyed ) {
            format(String,sizeof(String),"Du hast die Reparaturkosten in Höhe von 1.500$ für deinen %s bezahlt.", CarName[ PlayerCar[playerid][key][CarModel] - 400] );
            SendClientMessage(playerid,COLOR_ORANGE,String);
            Spieler[playerid][pBank] -= 1500;
            PlayerCar[playerid][key][CarState] = e_Vehicle_Status_Normal;
            PlayerHaveCar[playerid][key] = 0;//system
            PlayerCarSpawn(playerid,key);
        }
        else {
            SendClientMessage(playerid, COLOR_RED, "Das ausgewählte Fahrzeug muss nicht repariert werden.");
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Auf dem ausgewählten Schlüssel ist kein Fahrzeug.");
    }
    return 1;
}


CMD:mechaniker(playerid,params[])
{
    new firmenindex = GetJobFirmaIndexByID(12); 
    if(g_Firma[firmenindex][F_iGehalt] > CheckMoney(playerid)) return PlayerPlaySound(playerid, 20600, 0.0, 0.0, 0.0), SendClientMessage(playerid, COLOR_YELLOW, "[SMS]: Du hast nicht genug Geld für diesen Service!, Von: Mechaniker (Nr. 111)");
    if(GetPlayerInterior(playerid) != 0) return PlayerPlaySound(playerid, 20600, 0.0, 0.0, 0.0), SendClientMessage(playerid, COLOR_YELLOW, "[SMS]: Ich kann dir nichts in ein Interior liefern!, Von: Mechaniker (Nr. 111)");
    if(!PlayerHaveCar[playerid][PlayerKey[playerid]]) return PlayerPlaySound(playerid, 20600, 0.0, 0.0, 0.0), SendClientMessage(playerid, COLOR_YELLOW, "[SMS]: Besitzt du überhaupt ein Fahrzeug?, Von: Mechaniker (Nr. 111)");
    if(IsVehicleOccupied(PlayerCar[playerid][PlayerKey[playerid]][CarId])) return PlayerPlaySound(playerid, 20600, 0.0, 0.0, 0.0), SendClientMessage(playerid, COLOR_YELLOW, "[SMS]: Das Fahrzeug ist besetzt!, Von: Mechaniker (Nr. 111)");
    if(PlayerCar[playerid][PlayerKey[playerid]][CarState] != e_Vehicle_Status_Normal) return PlayerPlaySound(playerid, 20600, 0.0, 0.0, 0.0), SendClientMessage(playerid, COLOR_YELLOW, "[SMS]: Dieses Fahrzeug ist abgeschleppt oder Kaputt!, Von: Mechaniker (Nr. 111)");
    if(GetTowedCar(PlayerCar[playerid][PlayerKey[playerid]][CarId])) return PlayerPlaySound(playerid, 20600, 0.0, 0.0, 0.0), SendClientMessage(playerid, COLOR_YELLOW, "[SMS]: Dieses Fahrzeug wird gerade abgeschleppt!, Von: Mechaniker (Nr. 111)");
    if(Mechanikersperre[playerid] > 0) return PlayerPlaySound(playerid, 20600, 0.0, 0.0, 0.0), SCMFormatted(playerid,COLOR_YELLOW,"[SMS]: Sorry, ich bin gerade Beschäftigt. Versuchs doch in %d Minuten nochmal., Von: Mechaniker (Nr. 111)",Mechanikersperre[playerid]/60);
    if(IsBoot(PlayerCar[playerid][PlayerKey[playerid]][CarId])) return PlayerPlaySound(playerid, 20600, 0.0, 0.0, 0.0), SendClientMessage(playerid, COLOR_YELLOW, "[SMS]: Boote kann ich dir nicht liefern.!, Von: Mechaniker (Nr. 111)");
    
    new Float:PlayerPos[3],Float:VehPos[3];
    new Float:distance, Float:smallestDistance = 1000,index;
    GetPlayerPos(playerid,PlayerPos[0],PlayerPos[1],PlayerPos[2]);

    for (new i = 0; i < MaxVehicles(playerid); i++) 
    {
        if (PlayerHaveCar[playerid][i]) 
        {
            GetVehiclePos(PlayerCar[playerid][i][CarId],VehPos[0],VehPos[1],VehPos[2]);
            new Float:vehdist,Float:vehsdist = 25;
            if ((vehdist = GetDistance(PlayerPos[0],PlayerPos[1],PlayerPos[2], VehPos[0],VehPos[1],VehPos[2])) < vehsdist)
            { 
                vehsdist = vehdist;
                return PlayerPlaySound(playerid, 20600, 0.0, 0.0, 0.0), SendClientMessage(playerid, COLOR_YELLOW, "[SMS]: Du hast noch ein Fahrzeug in der Nähe., Von: Mechaniker (Nr. 111)");
            }
        }
    }

    for (new i = 0; i < sizeof(e_streets); i++)
        if ((distance = GetDistance(PlayerPos[0],PlayerPos[1],PlayerPos[2], e_streets[i][StreetX],e_streets[i][StreetY],e_streets[i][StreetZ])) < smallestDistance) index = i, smallestDistance = distance;

    PlayerPlaySound(playerid, 20600, 0.0, 0.0, 0.0);
    SendClientMessage(playerid, COLOR_YELLOW, "[SMS]: Hey, ich bring dir dein Fahrzeug gleich vorbei., Von: Mechaniker (Nr. 111)");
    GivePlayerCash(playerid,-g_Firma[firmenindex][F_iGehalt]);
    g_Firma[firmenindex][F_iKasse] += g_Firma[firmenindex][F_iGehalt];
    SetVehiclePos(PlayerCar[playerid][PlayerKey[playerid]][CarId], e_streets[index][StreetX],e_streets[index][StreetY],e_streets[index][StreetZ]+0.2);
    SetPlayerCheckpointEx(playerid, e_streets[index][StreetX],e_streets[index][StreetY],e_streets[index][StreetZ], 2.0, CP_NAVI1);
    Mechanikersperre[playerid] = 900;
    return 1;
}


CMD:carcolor(playerid,params[]){
    new t = IsPlayerAtTanke(playerid),
    farbe1,farbe2,
    vehid = GetPlayerVehicleID(playerid),
    preis = PlayerCar[playerid][PlayerKey[playerid]][CarPreis] > 200000 ? PlayerCar[playerid][PlayerKey[playerid]][CarPreis]*2/100 : PlayerCar[playerid][PlayerKey[playerid]][CarPreis]*20/100;
    if (t == 999) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keiner Tankstelle.");
    if (!strcmp(Tanke[t][tBesitzer], "Niemand", true)) return SendClientMessage(playerid, COLOR_RED, "Die Tankstelle hat keinen Besitzer.");
    if(sscanf(params, "dd", farbe1,farbe2)) return SCMFormatted(playerid, COLOR_BLUE, INFO_STRING"/carcolor [Farbe 1] [Farbe 2] (Kosten: $%s)",AddDelimiters(preis));
    if(vehid != PlayerCar[playerid][PlayerKey[playerid]][CarId]) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht in deinem Fahrzeug.");
    if (CheckMoney(playerid) < preis) return SCMFormatted(playerid, COLOR_RED, "Du benötigst mindestens $%s um dein Fahrzeug zu färben.",AddDelimiters(preis));
    if(farbe1 < 0 || farbe1 > 255) return SendClientMessage(playerid,COLOR_RED,"Du hast als erste Farbe eine Ungültige gewählt. (0-255)");
    if(farbe2 < 0 || farbe2 > 255) return SendClientMessage(playerid,COLOR_RED,"Du hast als zweite Farbe eine Ungültige gewählt. (0-255)");
    if (!vehid) {
        UnfreezePlayer(playerid);
        return SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Fahrzeug.");
    }
    PlayerCar[playerid][PlayerKey[playerid]][CarC1] = farbe1;
    PlayerCar[playerid][PlayerKey[playerid]][CarC2] = farbe2;
    ChangeVehicleColor(vehid,farbe1,farbe2);
    GivePlayerCash(playerid,- preis);
    Tanke[t][tKasse] += preis*50/100;
    SCMFormatted(playerid,COLOR_GREEN,"Du hast dein Fahrzeug in die Farb ID's %d und %d für $%s gefärbt.",farbe1,farbe2,AddDelimiters(preis));
    return 1;
}


CMD:clubneon(playerid,paramas[]) {
    if( !IsPlayerInRangeOfPoint(playerid,6.0,1747.8992,2243.8093,10.8203)) {
        return SendClientMessage(playerid,COLOR_RED,"Du kannst diese Funktion hier nicht aufrufen.");
    }
    if( Spieler[playerid][pDonateRank] != 2 ) {
        return SendClientMessage(playerid,COLOR_RED,"Aufgrund eines Fehlers werden zeitweise keine Neonröhren verkauft!");
    }
    /*if( Spieler[playerid][pDonateRank] != 1 ) {
        return SendClientMessage(playerid,COLOR_RED,"Nur Clubmitglieder können diese Funktion nutzen");
    }*/
    new vehicleid = GetPlayerVehicleID(playerid);
    if( !vehicleid ) {
        return SendClientMessage(playerid,COLOR_RED,"Du benötigst ein Fahrzeug für diese Funktion.");
    }
    new owner = GetCarOwner( vehicleid );
    if( owner != playerid ) {
        return SendClientMessage(playerid,COLOR_RED,"Dieses Fahrzeug gehört nicht dir.");
    }
    ShowPlayerDialog(playerid,DIALOG_CLUBNEON,DIALOG_STYLE_LIST,"Clubneon","{FF0000}Entfernen{FFFFFF}\nWeiß\nBlau\nGrün\nRot\nPink\nGelb","Anbringen","Abbruch");

    return 1;
}


CMD:wartungen(playerid,params[]) {
    #pragma unused params
    new
        slot,
        besitzer,
        vehicleid;
    if( !IsPlayerInRangeOfPoint(playerid, 10, TUEV_AUTO_POINT) && !IsPlayerInRangeOfPoint(playerid, 10, TUEV_AIRCRAFT_POINT)) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht an der TÜV-Werkstatt");
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) {
        return SendClientMessage(playerid,COLOR_RED,"Du musst in deinem Fahrzeug sitzen!");
    }
    besitzer = GetCarOwner(vehicleid);
    if( besitzer == INVALID_PLAYER_ID || playerid != besitzer ) {
        return SendClientMessage(playerid,COLOR_RED,"Dieses Fahrzeug gehört dir nicht.");
    }
    slot = GetCarOwnerSlot(besitzer, vehicleid);
    if( slot == 555 || PlayerCar[besitzer][slot][TUV] == 0 || IsBicycle(GetVehicleModel(vehicleid))) {
        return SendClientMessage(playerid,COLOR_RED,"Dieses Fahrzeug benötigt keine Wartung vom TÜV.");
    }
    ShowPlayerDialog(playerid,DIALOG_WARTUNG,DIALOG_STYLE_MSGBOX,"{4444FF}Wartung","{FFFFFF}An Ihrem Fahrzeug stehen allgemeine Wartungen an!\n\
        Die Werkstatt wird die nötigen Wartungen durchführen, damit das Fahrzeug weiterhin\n\
        sicher auf den Straßen fahren kann.\n\
        Erneuert wird die Auspuffanlage, Zahnriemen, Bremsbelege, Reifen und Motoröl, \n\
        außerdem wird der Motor fachgerecht gereinigt!\n\n\
        Preis: $25.000","Bezahlen","Ablehnen");
    return 1;
}


CMD:driveby(playerid){
	if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER]{FFFFFF} Du bist in keinem Fahrzeug!");
	if(GetPlayerVehicleSeat(playerid) == 0) return SendClientMessage(playerid, COLOR_RED, "[FEHLER]{FFFFFF} Du kannst das nur als Beifahrer!");
	new weapID1, weapID2, weapNAME1[128], weapNAME2[128], weapAmmo, String[128];
	GetPlayerWeaponData(playerid, 4, weapID1, weapAmmo);
	GetPlayerWeaponData(playerid, 5, weapID2, weapAmmo);
	if(weapID1 != 29 && weapID2 != 30 && weapID2 != 31) return SendClientMessage(playerid, COLOR_RED, "[FEHLER]{FFFFFF} Du hast keine geeignete Waffe!");
	if(weapID1 != 29) { weapNAME1 = "Keine"; } else { GetWeaponName(weapID1, weapNAME1, sizeof(weapNAME1)); }
	if(weapID2 != 30 && weapID2 != 31) { weapNAME2 = "Keine"; } else { GetWeaponName(weapID2, weapNAME2, sizeof(weapNAME2)); }
	format(String, sizeof(String), "%s\n%s\nDriveBy stoppen", weapNAME1, weapNAME2);
    ShowPlayerDialog(playerid, DRIVEBYDIALOG, DIALOG_STYLE_LIST, "Drive-By", String, "Drive-By", "Stop");
	return 1;
}



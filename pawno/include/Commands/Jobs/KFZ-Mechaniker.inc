#include <YSI\y_hooks>



CMD:nachtanken(playerid, params[])
{
    if (Spieler[playerid][pJob] == 5 || Spieler[playerid][pFraktion] == 5) {
        new pID, preis;
        if (sscanf(params, "ui", pID, preis)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Nachtanken [SpielerID/Name] [Preis]");
        new Float:x, Float:y, Float:z;
        if (pID == playerid) return SendClientMessage(playerid, COLOR_RED, "Du kannst dein eigenes Fahrzeug nicht auftanken.");
        if (preis < 10000 || preis > 50000) return SendClientMessage(playerid, COLOR_RED, "Der Preis muss zwischen $10000 und $50000 liegen.");
        if (meslock[playerid] == 1) {
            return SendClientMessage(playerid, COLOR_RED, "Du hast den Spieler bereits eine Anfrage gestellt. Warte bis er sie akzeptiert." );
        }
        meslock[playerid]=1;
        SetTimerEx("meslockrelease",20000,false,"i",playerid);
        if (IsPlayerConnected(pID)) {
            if (IsPlayerInAnyVehicle(pID)) {
                GetPlayerPos(pID, x,y,z);
                if (IsPlayerInRangeOfPoint(playerid, 10.0, x,y,z)) {
                    RefillCar[pID] = playerid;
                    RefillCarPreis[pID] = preis;
                    new string[128];
                    format(string, sizeof(string), "* Du hast %s angeboten sein Fahrzeug für $%s aufzutanken.", GetName(pID), AddDelimiters(preis));
                    SendClientMessage(playerid, COLOR_BLUE, string);
                    format(string, sizeof(string), "* KFZ-Mechatroniker %s hat dir angeboten, dein Fahrzeug für $%s aufzutanken.", GetName(playerid), AddDelimiters(preis));
                    SendClientMessage(pID, COLOR_BLUE, string);
                    SendClientMessage(pID, COLOR_BLUE, "* Tippe '/Accept refill' um das Nachfüllen anzunehmen.");
                    return 1;
                }
            } else {
                SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in keinem Fahrzeug.");
                return 1;
            }
        } else {
            SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
            return 1;
        }
    } else {
        SendClientMessage(playerid, COLOR_RED, "Du bist kein KFZ-Mechatroniker.");
    }
    return 1;
}

CMD:reparieren(playerid, params[])
{
    if (Spieler[playerid][pJob] == 5 || Spieler[playerid][pFraktion] == 5) {
        new pID, preis;
        if (sscanf(params, "ui", pID, preis)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Reparieren [SpielerID/Name] [Preis]");
        new Float:x, Float:y, Float:z;
        if (pID == playerid) return SendClientMessage(playerid, COLOR_RED, "Du kannst dein eigenes Fahrzeug nicht reparieren.");
        if (preis < 5000 || preis > 20000) return SendClientMessage(playerid, COLOR_RED, "Der Preis muss zwischen 5000$ und 20000$ liegen.");
        if (meslock[playerid] == 1) {
            return SendClientMessage(playerid, COLOR_RED, "Du hast den Spieler bereits eine Anfrage gestellt. Warte bis er sie akzeptiert." );
        }
        meslock[playerid]=1;
        SetTimerEx("meslockrelease",20000,false,"i",playerid);
        if (IsPlayerInAnyVehicle(playerid)) {
            SendClientMessage(playerid, COLOR_RED, "Du darfst für die Anfrage nicht im Fahrzeug sitzen");
            return 1;
        }
        if (IsPlayerConnected(pID)) {
            if (IsPlayerInAnyVehicle(pID)) {
                GetPlayerPos(pID, x,y,z);
                if (IsPlayerInRangeOfPoint(playerid, 8.0, x,y,z)) {
                    if (GetPlayerState(pID) != PLAYER_STATE_DRIVER) {
                        SendClientMessage(playerid, COLOR_RED, "Du kannst die Anfrage nur an den Fahrer senden!");
                        return 1;
                    }
                    new engine,lights,doors,bonnet,boot,objective,alarm;
                    GetVehicleParamsEx( GetPlayerVehicleID(pID) ,engine,lights,alarm,doors,bonnet,boot,objective);
                    if (bonnet != 1) {
                        SendClientMessage(playerid, COLOR_RED, "Die Motorhaube ist nicht geöffnet!");
                        return 1;
                    }

                    RepairCar[pID] = playerid;
                    RepairCarPreis[pID] = preis;
                    new string[128];
                    format(string, sizeof(string), "* Du hast %s angeboten sein Fahrzeug für $%s zu reparieren.", GetName(pID), AddDelimiters(preis));
                    SendClientMessage(playerid, COLOR_BLUE, string);
                    format(string, sizeof(string), "* KFZ-Mechatroniker %s hat dir eine Reparatur für $%s angeboten.", GetName(playerid), AddDelimiters(preis));
                    SendClientMessage(pID, COLOR_BLUE, string);
                    SendClientMessage(pID, COLOR_BLUE, "* Tippe '/Accept repair' um die Reparatur anzunehmen.");
                    return 1;
                }
            } else {
                SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in keinem Fahrzeug.");
                return 1;
            }
        } else {
            SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
            return 1;
        }
    } else {
        SendClientMessage(playerid, COLOR_RED, "Du bist kein KFZ-Mechatroniker.");
    }
    return 1;
}


CMD:acceptkfz(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Acceptkfz [SpielerID/Name]");
    if(Spieler[playerid][pJob] != 5)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mechatroniker!");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online!");
    if(GetPlayerInterior(pID) > 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist in einem Gebäude.");
    if(NeedKFZ[pID] == 0)return SendClientMessage(playerid, COLOR_ORANGE, "Der Spieler benötigt keinen Mechatroniker. Verwende /sliste um die Service-Liste zu sehen.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x,y,z);
    SetPlayerCheckpointEx(playerid, x,y,z, 5.0, CP_ACCEPTKFZ);
    format(string, sizeof(string), "* Du hast den Service-Anruf von %s angenommen, ein Roter Punkt wurde auf der Karte markiert.", GetName(pID));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "* KFZ-Mechatroniker %s hat deinen Service-Anruf angenommen und ist nun unterwegs zu dir!", GetName(playerid));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    NeedKFZ[pID] = 0;
    return 1;
}
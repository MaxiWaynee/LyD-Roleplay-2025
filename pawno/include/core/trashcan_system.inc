#include <YSI\y_hooks>

// Global defines
#define MAX_MUELLTONNEN 		33

// Variables
enum MuelltonnenInfo {
	_ObjectModel,
	Float:_posx,
	Float:_posy,
	Float:_posz,
	Float:_posrx,
	Float:_posry,
	Float:_posrz,
	_vworld
}

enum MObjectInfo {
    Pfandflaschen
}

new MTInfo[MAX_MUELLTONNEN][MObjectInfo];

// Forwards
forward PfandcooldownTimer(playerid);
forward CanCooldownTimer(id);

// load the map
#include <maps\trashcan_map>

// -----

hook OnPlayerDeath(playerid, killerid, reason) {
    SetPVarInt(playerid,"Pfandcooldown",0);
	return 1;
}

// Commands

CMD:pfandfinden(playerid) {
    new nearestmt = ReturnMUELLTONNENID(playerid),pfandrand = random(25),pfandgeld = random(127)+37;
   	if (nearestmt == -1) {
 	    return SendClientMessage(playerid,COLOR_RED,"[FEHLER] {FFFFFF}Du bist an keiner Mülltonne.");
 	}
    if (Spieler[playerid][pPfand] > 75) {
        return SendClientMessage(playerid,COLOR_RED,"[FEHLER] {FFFFFF}Du kannst nicht mehr als 75 Pfandflaschen tragen.");
    }
    ApplyAnimation(playerid, "BAR", "Barserve_bottle", 4.0, 0, 0, 0, 0, 0, 1);
	if (GetPVarInt(playerid, "Pfandcooldown")) {
		SendClientMessage(playerid,COLOR_RED,"[INFO] {FFFFFF}Du hast vor kurzem erst Pfandflaschen gefunden.");
    	PlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);
 	    return 1;
	}
    if (MTInfo[nearestmt][Pfandflaschen] > 0) {
        if (pfandrand == 12 || pfandrand == 24) {
	        PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
	        SCMFormatted(playerid, COLOR_GREEN,"[MÜLLTONNE] {FFFFFF}Du hast ein Geldbeutel mit $%s gefunden!", AddDelimiters(pfandgeld));
	        GivePlayerCash(playerid, pfandgeld);
	        MTInfo[nearestmt][Pfandflaschen] = 0;
	        SetPVarInt(playerid, "Pfandcooldown", 1);
	        SetTimerEx("PfandcooldownTimer", 60000, false, "i", playerid); // 1 minute Player cooldown
			SetTimerEx("CanCooldownTimer", 900000, false, "i", nearestmt); // 15 minuten Mülltonnen cooldown
	        return 1;
        } else {
	        PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
	        SCMFormatted(playerid, COLOR_GREEN,"[MÜLLTONNE] {FFFFFF}Du konntest %d Pfandflaschen aus der Mülltonne rausziehen.",MTInfo[nearestmt][Pfandflaschen]);
	        Spieler[playerid][pPfand] += MTInfo[nearestmt][Pfandflaschen];
	        MTInfo[nearestmt][Pfandflaschen] = 0;
	       	SetPVarInt(playerid, "Pfandcooldown", 1);
	        SetTimerEx("PfandcooldownTimer", 60000, false, "i", playerid); // 1 minute Player cooldown
			SetTimerEx("CanCooldownTimer", 900000, false, "i", nearestmt); // 15 minuten Mülltonnen cooldown
	        return 1;
		}
    } else {
    	SendClientMessage(playerid,COLOR_RED,"[INFO] {FFFFFF}Du konntest leider nichts in der Mülltonne finden.");
    	PlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);
 	    return 1;
    }
}

// ----

public PfandcooldownTimer(playerid) {
	DeletePVar(playerid, "Pfandcooldown");
	return 1;
}

public CanCooldownTimer(id) {
	MTInfo[id][Pfandflaschen] = random(4) + 1;
	return 1;
}

stock ReturnMUELLTONNENID(playerid) {
  	for(new i = 0; i < MAX_MUELLTONNEN; i++)
  	{
	  	if (!IsPlayerInAnyVehicle(playerid)) {
	  	    if (MuellTonnen[i][_ObjectModel] != 1264 && MuellTonnen[i][_ObjectModel] != 1265) {
		   		if (IsPlayerInRangeOfPoint(playerid, 1.5, MuellTonnen[i][_posx], MuellTonnen[i][_posy], MuellTonnen[i][_posz]) && GetPlayerVirtualWorld(playerid) == MuellTonnen[i][_vworld])
				return i;
			}
	    }
    }
	return -1;
}

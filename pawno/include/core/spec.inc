#include <YSI\y_hooks>

new Float:posX[MAX_PLAYERS],
	Float:posY[MAX_PLAYERS],
	Float:posZ[MAX_PLAYERS],
	iWorld[MAX_PLAYERS],
	iInterior[MAX_PLAYERS],
	iSpectatorID[MAX_PLAYERS],
	bIsSpectating[MAX_PLAYERS],
	bIsBeingSpectated[MAX_PLAYERS],
	iWeaponID[MAX_PLAYERS][12],
	iWeaponAmmo[MAX_PLAYERS][12],
	Float:iHealth[MAX_PLAYERS],
	Float:iArmour[MAX_PLAYERS],
	bWasInVehiclePrior[MAX_PLAYERS],
	iVehicleID[MAX_PLAYERS],
	iVehicleSeat[MAX_PLAYERS],
	Float:vehX[MAX_PLAYERS],
	Float:vehY[MAX_PLAYERS],
	Float:vehZ[MAX_PLAYERS],
	Float:vehXCheck,
	Float:vehYCheck,
	Float:vehZCheck,
	PlayerText:Spectate[4][MAX_PLAYERS],
    //spectimer[MAX_PLAYERS],
    Text3D:cNametag[MAX_PLAYERS][MAX_PLAYERS];

#define NT_DISTANCE 500.0

hook OnGameModeInit2() {
    foreach(new i : Player) {
	    iSpectatorID[i] = -1;
	}
    return 1;
}

hook OnGameModeExit() {
    foreach(new i : Player) {
		if (bIsSpectating[i] == 1) {
			TogglePlayerSpectating(i, false);
		}
	}
    return 1;
}

hook OnPlayerConnect(playerid) {
    Spectate[0][playerid] = CreatePlayerTextDraw(playerid, 98.000000, 191.000000, "_");
    PlayerTextDrawFont(playerid, Spectate[0][playerid], 2);
    PlayerTextDrawLetterSize(playerid, Spectate[0][playerid], 0.600000, 10.000000);
    PlayerTextDrawTextSize(playerid, Spectate[0][playerid], 309.000000, 167.000000);
    PlayerTextDrawSetOutline(playerid, Spectate[0][playerid], 1);
    PlayerTextDrawSetShadow(playerid, Spectate[0][playerid], 0);
    PlayerTextDrawAlignment(playerid, Spectate[0][playerid], 2);
    PlayerTextDrawColor(playerid, Spectate[0][playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, Spectate[0][playerid], 255);
    PlayerTextDrawBoxColor(playerid, Spectate[0][playerid], 1296911741);
    PlayerTextDrawUseBox(playerid, Spectate[0][playerid], 1);
    PlayerTextDrawSetProportional(playerid, Spectate[0][playerid], 1);
    PlayerTextDrawSetSelectable(playerid, Spectate[0][playerid], 0);

    Spectate[1][playerid] = CreatePlayerTextDraw(playerid, 84.000000, 207.000000, "~g~Name: ~w~Name~n~~g~HP:~w~100~n~~g~Ammo:~w~100~n~~g~FPS:~w~93~n~~g~Packetloss:~w~0.00~n~~g~Fraktion:~w~0");
    PlayerTextDrawFont(playerid, Spectate[1][playerid], 2);
    PlayerTextDrawLetterSize(playerid, Spectate[1][playerid], 0.200000, 1.100000);
    PlayerTextDrawTextSize(playerid, Spectate[1][playerid], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, Spectate[1][playerid], 1);
    PlayerTextDrawSetShadow(playerid, Spectate[1][playerid], 0);
    PlayerTextDrawAlignment(playerid, Spectate[1][playerid], 1);
    PlayerTextDrawColor(playerid, Spectate[1][playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, Spectate[1][playerid], 255);
    PlayerTextDrawBoxColor(playerid, Spectate[1][playerid], 50);
    PlayerTextDrawUseBox(playerid, Spectate[1][playerid], 0);
    PlayerTextDrawSetProportional(playerid, Spectate[1][playerid], 1);
    PlayerTextDrawSetSelectable(playerid, Spectate[1][playerid], 0);

    Spectate[2][playerid] = CreatePlayerTextDraw(playerid, 15.000000, 207.000000, "~g~ID: ~w~0~n~~g~AP: ~w~100~n~~g~Waffe: ~w~Deagle~n~~g~Level: ~W~15~n~~g~Ping: ~w~100~n~~g~Skin: ~w~186~n~~g~SAMPCAC: ~w~AN");
    PlayerTextDrawFont(playerid, Spectate[2][playerid], 2);
    PlayerTextDrawLetterSize(playerid, Spectate[2][playerid], 0.200000, 1.100000);
    PlayerTextDrawTextSize(playerid, Spectate[2][playerid], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, Spectate[2][playerid], 1);
    PlayerTextDrawSetShadow(playerid, Spectate[2][playerid], 0);
    PlayerTextDrawAlignment(playerid, Spectate[2][playerid], 1);
    PlayerTextDrawColor(playerid, Spectate[2][playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, Spectate[2][playerid], 255);
    PlayerTextDrawBoxColor(playerid, Spectate[2][playerid], 50);
    PlayerTextDrawUseBox(playerid, Spectate[2][playerid], 0);
    PlayerTextDrawSetProportional(playerid, Spectate[2][playerid], 1);
    PlayerTextDrawSetSelectable(playerid, Spectate[2][playerid], 0);
    
    Spectate[3][playerid] = CreatePlayerTextDraw(playerid, 4.000000, 178.000000, "]                   ]");
    PlayerTextDrawFont(playerid, Spectate[3][playerid], 2);
    PlayerTextDrawLetterSize(playerid, Spectate[3][playerid], 0.600000, 1.850000);
    PlayerTextDrawTextSize(playerid, Spectate[3][playerid], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, Spectate[3][playerid], 1);
    PlayerTextDrawSetShadow(playerid, Spectate[3][playerid], 0);
    PlayerTextDrawAlignment(playerid, Spectate[3][playerid], 1);
    PlayerTextDrawColor(playerid, Spectate[3][playerid], -16711681);
    PlayerTextDrawBackgroundColor(playerid, Spectate[3][playerid], 255);
    PlayerTextDrawBoxColor(playerid, Spectate[3][playerid], 50);
    PlayerTextDrawUseBox(playerid, Spectate[3][playerid], 0);
    PlayerTextDrawSetProportional(playerid, Spectate[3][playerid], 1);
    PlayerTextDrawSetSelectable(playerid, Spectate[3][playerid], 0);

    foreach(new i : Player) {
        if (IsPlayerConnected(i) && gPlayerLogged[i]) {
            if (IsPlayerNPC(i)) continue; 
            if (playerid == i) continue;

            if (IsValidDynamic3DTextLabel(cNametag[i][playerid]))
                DestroyDynamic3DTextLabel(cNametag[i][playerid]);
        }
    }

    //spectimer[playerid] = SetTimerEx("UpdateNametag", 1000, true, "d", playerid);

    bIsSpectating[playerid] = 0;
    bIsBeingSpectated[playerid] = 0;
    iSpectatorID[playerid] = -1;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason) {
    if (bIsBeingSpectated[playerid] == 1) {
	    foreach(new i : Player) {
	        if (iSpectatorID[i] == playerid) {
	            TogglePlayerSpectating(i, false); 
                if (IsValidDynamic3DTextLabel(cNametag[i][playerid]))
                    DestroyDynamic3DTextLabel(cNametag[i][playerid]);
	        }
	    }
	}

    foreach(new i : Player) {
        if (IsPlayerConnected(i) && gPlayerLogged[i]) {
            if (IsPlayerNPC(i)) continue; 
            if (playerid == i) continue;

            if (IsValidDynamic3DTextLabel(cNametag[i][playerid]))
                DestroyDynamic3DTextLabel(cNametag[i][playerid]);
        }
    }

    PlayerTextDrawDestroy(playerid, Spectate[0][playerid]);
    PlayerTextDrawDestroy(playerid, Spectate[1][playerid]);
    PlayerTextDrawDestroy(playerid, Spectate[2][playerid]);
    PlayerTextDrawDestroy(playerid, Spectate[3][playerid]);

    //KillTimer(spectimer[playerid]);

    if (bIsSpectating[playerid] == 1) {
        foreach(new i : Player) {
            if (IsPlayerConnected(i) && gPlayerLogged[i]) {
                if (IsPlayerNPC(i)) continue; 
                if (playerid == i) continue;

                if (IsValidDynamic3DTextLabel(cNametag[playerid][i]))
                    DestroyDynamic3DTextLabel(cNametag[playerid][i]);
            }
        }
    }

    bIsSpectating[playerid] = 0;
    bIsBeingSpectated[playerid] = 0;
    iSpectatorID[playerid] = -1;
    return 1;
}

hook HauptTimer() {
    foreach(new i : Player) {
        if (IsPlayerConnected(i) && gPlayerLogged[i]) {
            if (IsPlayerNPC(i)) continue;

            if (bIsSpectating[i] == 1) {
                new string[500], weaponstring[32], Float:pHealth, Float:pArmor;
                SetPlayerInterior(i, GetPlayerInterior(iSpectatorID[i]));
                SetPlayerVirtualWorld(i, GetPlayerVirtualWorld(iSpectatorID[i]));
                GetWeaponName(GetPlayerWeapon(iSpectatorID[i]), weaponstring, 32);
                GetPlayerHealth(iSpectatorID[i], pHealth);
                GetPlayerArmour(iSpectatorID[i], pArmor);
                format(string, sizeof(string), "~g~Name: ~w~%s~n~~g~HP: ~w~%.2f~n~~g~Ammo: ~w~%d~n~~g~FPS: ~w~%d~n~~g~Packetloss: ~w~%.2f~n~~g~Fraktion: ~w~%s~n~~g~Beruf: ~w~%s", 
                GetName(iSpectatorID[i]), pHealth, GetPlayerAmmo(iSpectatorID[i]), GetPlayerFPS(iSpectatorID[i]), NetStats_PacketLossPercent(iSpectatorID[i]), GetFactionName(Spieler[iSpectatorID[i]][pFraktion]), jobNames[Spieler[iSpectatorID[i]][pJob]]);
                PlayerTextDrawSetString(i, Spectate[1][i], string);
                format(string, sizeof(string), "~g~ID: ~w~%d~n~~g~AP: ~w~%.2f~n~~g~Waffe: ~w~%s~n~~g~Level: ~W~%d~n~~g~Ping: ~w~%d~n~~g~Skin: ~w~%d", 
                iSpectatorID[i], pArmor, weaponstring, Spieler[iSpectatorID[i]][pLevel], GetPlayerPing(iSpectatorID[i]), Spieler[iSpectatorID[i]][pSkin]);
                PlayerTextDrawSetString(i, Spectate[2][i], string);
                PlayerTextDrawShow(i, Spectate[0][i]);
                PlayerTextDrawShow(i, Spectate[1][i]);
                PlayerTextDrawShow(i, Spectate[2][i]);
                PlayerTextDrawShow(i, Spectate[3][i]);
            } else {
                PlayerTextDrawHide(i, Spectate[0][i]);
                PlayerTextDrawHide(i, Spectate[1][i]);
                PlayerTextDrawHide(i, Spectate[2][i]);
                PlayerTextDrawHide(i, Spectate[3][i]);
            }
        }
    }
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate) {
    if (oldstate == PLAYER_STATE_ONFOOT && newstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_ONFOOT && newstate == PLAYER_STATE_PASSENGER || oldstate == PLAYER_STATE_DRIVER && newstate == PLAYER_STATE_ONFOOT || oldstate == PLAYER_STATE_PASSENGER && newstate == PLAYER_STATE_ONFOOT) {
	    if (bIsBeingSpectated[playerid] == 1) {
	        foreach(new i : Player) {
	            if (iSpectatorID[i] == playerid) {
	            	SpectatePlayer(i, playerid);   
	            }    
	        }    
	    }
	}
    return 1;
}

hook OnPlayerEnterCheckpoint(playerid) {
    if (bIsBeingSpectated[playerid] == 1) {		
		foreach(new i : Player) {
		    if (iSpectatorID[i] == playerid) {
		        SetPlayerVirtualWorld(i, GetPlayerVirtualWorld(playerid));       
		    }	    
		}		
	}
    return 1;
}

hook OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid) {
    if (newinteriorid != oldinteriorid) {
		if (bIsBeingSpectated[playerid] == 1) {	
		    foreach(new i : Player) {   
		        if (iSpectatorID[i] == playerid) {    
		            SetPlayerInterior(i, GetPlayerInterior(playerid));    
		        }
		    }	
		}
	}
    return 1;
}

CMD:spec(playerid, params[]) {
	if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_WHITE, ERROR_LOGGED);
	if (!Spieler[playerid][pAdmin]) return SendClientMessage(playerid, COLOR_WHITE, ERROR_ADMIN);
	new pID, string[128];
	if (sscanf(params, "u", pID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Spec [SpielerID/Name]");
	if (pID == playerid) return SendClientMessage(playerid, COLOR_RED, "Du kannst dich selbst nicht spectaten!");
	if (!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online!");
	if (bIsSpectating[pID] == 1) return SendClientMessage(playerid, COLOR_RED, "Der Spieler spectatet selbst gerade!");
	if ((GetPlayerState(pID)) == PLAYER_STATE_WASTED) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist Tot!");
	if (bIsSpectating[playerid] == 0) {
	    for(new iSlot = 0; iSlot != 12; iSlot++) 
	    {
			GetPlayerWeaponData(playerid, iSlot, iWeaponID[playerid][iSlot], iWeaponAmmo[playerid][iSlot]);    
	    }
	 
	    GetPlayerHealth(playerid, iHealth[playerid]);
	    GetPlayerArmour(playerid, iArmour[playerid]);
		iInterior[playerid] = GetPlayerInterior(playerid);
		iWorld[playerid] = GetPlayerVirtualWorld(playerid);
		
		if (IsPlayerInAnyVehicle(playerid)) {
		    iVehicleID[playerid] = GetPlayerVehicleID(playerid);
			iVehicleSeat[playerid] = GetPlayerVehicleSeat(playerid);
			GetVehiclePos(iVehicleID[playerid], vehX[playerid], vehY[playerid], vehZ[playerid]);
			bWasInVehiclePrior[playerid] = 1;
		} else {
		    GetPlayerPos(playerid, posX[playerid], posY[playerid], posZ[playerid]);
		}
  		TogglePlayerSpectating(playerid, true);
		SpectatePlayer(playerid, pID);
        format(string, sizeof(string), "%s spectatet nun %s.", GetName(playerid), GetName(pID));
		SendManagerMessage(COLOR_YELLOW, string);

		bIsSpectating[playerid] = 1;
		bIsBeingSpectated[pID] = 1;
		iSpectatorID[playerid] = pID;
        Spieler[playerid][pHandyState] = 0;
        Spieler[playerid][pAdminDienst] = 1;
        SendClientMessage(playerid, COLOR_YELLOW, "Dein Handy wurde automatisch ausgeschaltet.");
        SetDamageFeedForPlayer(playerid, 1);
        SetPlayerColor(playerid, TEAM_SANI_COLOR);
		return 1;
	} else {
        SpectatePlayer(playerid, pID);
		bIsBeingSpectated[pID] = 1;
		iSpectatorID[playerid] = pID;
		format(string, sizeof(string), "%s spectatet nun %s.", GetName(playerid), GetName(pID));
		SendManagerMessage(COLOR_YELLOW, string);
        return 1;
	}
}

CMD:specoff(playerid) {
	if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_WHITE, ERROR_LOGGED);
    if (!Spieler[playerid][pAdmin]) return SendClientMessage(playerid, COLOR_WHITE, ERROR_ADMIN);
	if (bIsSpectating[playerid] == 0) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht am spectaten");
    if (Spieler[playerid][pDuty] == 1) SetPlayerColor(playerid, COLOR_BLUE);
    if (Spieler[playerid][pAdminDienst] == 1) SetPlayerColor(playerid, TEAM_SANI_COLOR);

    KillTimer(GFFlucht[playerid]);
	TogglePlayerSpectating(playerid, false);
	return 1;
}

forward SpectatePlayer(playerid, id);
public SpectatePlayer(playerid, id) {
    SetPlayerInterior(playerid, GetPlayerInterior(id));
	SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(id));
	if (IsPlayerInAnyVehicle(id)) {
		PlayerSpectateVehicle(playerid, GetPlayerVehicleID(id));
	} else {
		PlayerSpectatePlayer(playerid, id);
	}
	return 1;
}

static GetHealthDots(playerid) {
    new dots[64], Float: HP;
 
    GetPlayerHealth(playerid, HP);
 
    if(HP >= 100)
        dots = "••••••••••";
    else if(HP >= 90)
        dots = "•••••••••{660000}•";
    else if(HP >= 80)
        dots = "••••••••{660000}••";
    else if(HP >= 70)
        dots = "•••••••{660000}•••";
    else if(HP >= 60)
        dots = "••••••{660000}••••";
    else if(HP >= 50)
        dots = "•••••{660000}•••••";
    else if(HP >= 40)
        dots = "••••{660000}••••••";
    else if(HP >= 30)
        dots = "•••{660000}•••••••";
    else if(HP >= 20)
        dots = "••{660000}••••••••";
    else if(HP >= 10)
        dots = "•{660000}•••••••••";
    else if(HP >= 0)
        dots = "{660000}••••••••••";
 
    return dots;
}

static GetArmorDots(playerid) {
    new dots[64], Float: AR;
 
    GetPlayerArmour(playerid, AR);
 
    if(AR >= 100)
        dots = "••••••••••";
    else if(AR >= 90)
        dots = "•••••••••{666666}•";
    else if(AR >= 80)
        dots = "••••••••{666666}••";
    else if(AR >= 70)
        dots = "•••••••{666666}•••";
    else if(AR >= 60)
        dots = "••••••{666666}••••";
    else if(AR >= 50)
        dots = "•••••{666666}•••••";
    else if(AR >= 40)
        dots = "••••{666666}••••••";
    else if(AR >= 30)
        dots = "•••{666666}•••••••";
    else if(AR >= 20)
        dots = "••{666666}••••••••";
    else if(AR >= 10)
        dots = "•{666666}•••••••••";
    else if(AR >= 0)
        dots = "{666666}••••••••••";
 
    return dots;
}

forward UpdateNametag(playerid);
public UpdateNametag(playerid) {
    if (bIsSpectating[playerid] == 1 && Spieler[playerid][pAdmin] > 0) {
        foreach(new i : Player) {
            if (IsPlayerConnected(i) && gPlayerLogged[i]) {
                if (IsPlayerNPC(i)) continue;     
                if (playerid == i) continue;
                new string[128], Float:armour;
                GetPlayerArmour(i, armour);
                if (armour > 1.0) {
                    format(string, sizeof(string), "{%06x}%s {FFFFFF}(%i)\n{FFFFFF}%s\n{FF0000}%s", GetPlayerColor(i) >>> 8, GetName(i), i, GetArmorDots(i), GetHealthDots(i));
                } else {
                    format(string, sizeof(string), "{%06x}%s {FFFFFF}(%i)\n{FF0000}%s", GetPlayerColor(i) >>> 8, GetName(i), i, GetHealthDots(i));
                }
                if (IsValidDynamic3DTextLabel(cNametag[playerid][i])) {
                    ShowPlayerNameTagForPlayer(playerid, i, 0);
                    UpdateDynamic3DTextLabelText(cNametag[playerid][i], 0xFFFFFFFF, string);
                } else {
                    ShowPlayerNameTagForPlayer(playerid, i, 0);
                    cNametag[playerid][i] = CreateDynamic3DTextLabel("Loading nametag...", 0xFFFFFFFF, 0.0, 0.0, 0.1, NT_DISTANCE, .attachedplayer = i, .testlos = 0, .playerid = playerid);
                }
            }
        }
    } else {
        foreach(new i : Player) {
            if (IsPlayerConnected(i) && gPlayerLogged[i]) {
                if (IsPlayerNPC(i)) continue;     
                if (playerid == i) continue;
                if (IsValidDynamic3DTextLabel(cNametag[playerid][i])) {
                    DestroyDynamic3DTextLabel(cNametag[playerid][i]);
                    ShowPlayerNameTagForPlayer(playerid, i, 1);
                }
            }
        }
    }
}
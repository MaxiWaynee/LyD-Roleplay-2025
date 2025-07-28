#include <sampcac>
#include <YSI\y_hooks>

#define DIALOG_GLITCHSTATUS     0xCAC
#define DIALOG_GAMEOPTIONSTATUS 0xCAC+1

new const g_szGlitchNames     [][] = {"Quick reload", "Fast fire", "Fast move", "C-Bug", "Fast sprint", "Quick stand"};
new const g_szGameOptionNames [][] = {"Vehicle blips", "Manual reloading", "Drive on water", "Fireproof", "Sprint", "Infinite sprint", "Infinite oxygen", "Infinite ammo", "Night vision", "Thermal vision"};

// Define factions that must use the AC
//static AC_factions[] = {
    //1, // LSPD
    //2, // FBI
    //6, // Grove Street
    //7, // Ballas
    //10, // Yakuza
    //11, // Aztecas
    //12, // CK 
    //13, // Vagos
    //14, // Agency
    //15, // Nine-Demons
    //20, // LCN
    //21 // Triaden
//};

//forward OnGameModeInit();
hook OnGameModeInit() {
    // Define allowed glitches
    CAC_SetGlitchStatus(CAC_GLITCH__ALL, 1);
    CAC_SetGlitchStatus(CAC_GLITCH__CROUCHBUG, 0);

    // Define allowed game options
    CAC_SetGameOptionStatus(CAC_GAMEOPTION__ALL, 0);
    CAC_SetGameOptionStatus(CAC_GAMEOPTION__VEHICLEBLIPS, 1);
    CAC_SetGameOptionStatus(CAC_GAMEOPTION__MANUALRELOADING, 1);
    CAC_SetGameOptionStatus(CAC_GAMEOPTION__SPRINT, CAC_GAMEOPTION_STATUS__SPRINT_ALLSURFACES);

    // Define disallowed game ressources (reporting)
    CAC_SetGameResourceReportStatus(CAC_GAMERESOURCE_MODELTYPEFLAG__ALL, 0);
    CAC_SetGameResourceReportStatus(CAC_GAMERESOURCE_MODELTYPEFLAG__PEDIFP, 1);

    CAC_SetGameResourceReportType(CAC_GAMERESOURCE_REPORTTYPE__ONLY_IF_MODDED);

    return 1;
}

hook OnPlayerSpawn(playerid) {
	if (gPlayerLogged[playerid] && AC_mustUseAC(playerid) && !CAC_GetStatus(playerid))
        return AC_kick(playerid, "Anti-Cheat Client Pflicht");

    if (gPlayerLogged[playerid] && GetPVarInt(playerid, "AC_cheatDetected") > 0)
        return AC_OnCheatDetect(playerid, GetPVarInt(playerid, "AC_cheatDetected") - 1, 0, 0);
    
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch (dialogid) {
		case DIALOG_GLITCHSTATUS: {
            if (response) {
                new string[128];
                new newstatus = !CAC_GetGlitchStatus(listitem);
                
                CAC_SetGlitchStatus(listitem, newstatus);
                
                format(string, sizeof(string), "%s %s hat Glitch \"%s\" %s", GetPlayerAdminRang(playerid), GetName(playerid), g_szGlitchNames[listitem], (newstatus != 0) ? ("{00BC00}erlaubt") : ("{EE5555}blockiert"));
                SendManagerMessage(COLOR_YELLOW, string);
            }
            return 1;
        }
        case DIALOG_GAMEOPTIONSTATUS: {
            if (response) {
                new string[128];
                new newstatus = CAC_GetGameOptionStatus(listitem)+1;
                new newstatusname[32];
                
                if (listitem != CAC_GAMEOPTION__SPRINT) {
                    newstatus %= 2;
                    if (newstatus == 0)
                        strcat(newstatusname, "{EE5555}deaktiviert");
                    else
                        strcat(newstatusname, "{00BC00}aktiviert");
                } else {
                    newstatus %= 3;
                    switch (newstatus) {
                        case CAC_GAMEOPTION_STATUS__SPRINT_DEFAULT:
                            strcat(newstatusname, "{00BC00}Default");
                        case CAC_GAMEOPTION_STATUS__SPRINT_ALLSURFACES:
                            strcat(newstatusname, "{00BC00}All surfaces");
                        case CAC_GAMEOPTION_STATUS__SPRINT_DISABLED:
                            strcat(newstatusname, "{EE5555}Disabled");
                    }            
                }
                CAC_SetGameOptionStatus(listitem, newstatus);

                format(string, sizeof(string), "%s %s hat Game option \"%s\" %s", GetPlayerAdminRang(playerid), GetName(playerid), g_szGameOptionNames[listitem], newstatusname);
                SendManagerMessage(COLOR_YELLOW, string);
            }
            return 1;
        }
    }
    return 0;
}

CMD:cac_glitchtoggle(playerid, params[])
{
    if (Spieler[playerid][pAdmin] < 5) return ERROR_RANG_MSG(playerid);
    new string[512] = "Glitch\tStatus\n";
    for (new i = 0; i != CAC_GLITCH__ALL; ++i) {
        format(string, sizeof(string), "%s{FFFFFF}%s\t%s\n", string, g_szGlitchNames[i], (CAC_GetGlitchStatus(i) != 0) ? ("{00BC00}Allowed") : ("{EE5555}Blocked"));
    }
    ShowPlayerDialog(playerid, DIALOG_GLITCHSTATUS, DIALOG_STYLE_TABLIST_HEADERS, "Toggle glitch status", string, "Toggle", "Exit");
    return 1;
}

CMD:cac_gameoptiontoggle(playerid, params[])
{
    if (Spieler[playerid][pAdmin] < 5) return ERROR_RANG_MSG(playerid);
    new string[1024] = "Game option\tStatus\n";
    for (new i = 0; i != CAC_GAMEOPTION__ALL; ++i) {
		if (i != CAC_GAMEOPTION__SPRINT) {
			format(string, sizeof(string), "%s{FFFFFF}%s\t%s\n", string, g_szGameOptionNames[i], (CAC_GetGameOptionStatus(i) != 0) ? ("{00BC00}Activated") : ("{EE5555}Deactivated"));
		} else {
			new status[32];
			switch (CAC_GetGameOptionStatus(i)) {
				case CAC_GAMEOPTION_STATUS__SPRINT_DEFAULT:
					strcat(status, "{00BC00}Default");
				case CAC_GAMEOPTION_STATUS__SPRINT_ALLSURFACES:
					strcat(status, "{00BC00}All surfaces");
				case CAC_GAMEOPTION_STATUS__SPRINT_DISABLED:
					strcat(status, "{EE5555}Disabled");
			}
			format(string, sizeof(string), "%s{FFFFFF}%s\t%s\n", string, g_szGameOptionNames[i], status);
		}
	}
    ShowPlayerDialog(playerid, DIALOG_GAMEOPTIONSTATUS, DIALOG_STYLE_TABLIST_HEADERS, "Toggle game option status", string, "Toggle", "Exit");
    return 1;
}

forward AC_OnPlayerKick(player_id, reason_id);
public AC_OnPlayerKick(player_id, reason_id) {
    static const kickReasons[][] = { "Verbindungsprobleme mit dem AC Client", "AC Client Version nicht kompatibel" };

    if (IsPlayerConnected(player_id))
        AC_kick(player_id, kickReasons[reason_id]);

    return 1;
}

forward AC_OnCheatDetect(player_id, cheat_id, opt1, opt2);
public AC_OnCheatDetect(player_id, cheat_id, opt1, opt2) {
    if (!gPlayerLogged[player_id])
        return SetPVarInt(player_id, "AC_cheatDetected", ++cheat_id);

    switch (cheat_id) {
        /*case CAC_CHEAT__AIMBOT_1,
             CAC_CHEAT__AIMBOT_2,
             CAC_CHEAT__AIMBOT_3,
             CAC_CHEAT__AIMBOT_4,
             CAC_CHEAT__AIMBOT_5,
             CAC_CHEAT__AIMBOT_6: {
            AC_ban(player_id, "Aimbot");
        }*/

        case CAC_CHEAT__AIMBOT_1: {
            AC_ban(player_id, "Aimbot (1)");
        }

        case CAC_CHEAT__AIMBOT_2: {
            AC_ban(player_id, "Aimbot (2)");
        }

        case CAC_CHEAT__AIMBOT_3: {
            AC_ban(player_id, "Aimbot (3)");
        }

        case CAC_CHEAT__AIMBOT_4: {
            AC_ban(player_id, "Aimbot (4)");
        }

        case CAC_CHEAT__AIMBOT_5: {
            AC_ban(player_id, "Aimbot (5)");
        }

        case CAC_CHEAT__AIMBOT_6: {
            AC_kick(player_id, "Verdacht auf Aimassist");
        }

        case CAC_CHEAT__TRIGGERBOT_1,
             CAC_CHEAT__TRIGGERBOT_2: {
            AC_ban(player_id, "Triggerbot");
        }

        case CAC_CHEAT__NAMETAG_1: {
            AC_ban(player_id, "Nametag ESP");
        }

        case CAC_CHEAT__ESP_1: {
            AC_ban(player_id, "ESP");
        }

        case CAC_CHEAT__FAKE_PING_1: {
            AC_kick(player_id, "Fake Ping");
        }

        case CAC_CHEAT__WEAPON_INFO_1: {
            AC_ban(player_id, "Veränderungen in der weapon.dat Datei");
        }

        case CAC_CHEAT__NORECOIL_1,
             CAC_CHEAT__NORECOIL_2,
             CAC_CHEAT__NORECOIL_3: {
            AC_ban(player_id, "NoRecoil");
        }

        case CAC_CHEAT__UNTRUSTED_1,
             CAC_CHEAT__UNTRUSTED_2,
             CAC_CHEAT__UNTRUSTED_3,
             CAC_CHEAT__UNTRUSTED_4: {
            AC_kick(player_id, "Verdächtiges Verhalten");
        }
    }

    return 1;
}

forward AC_OnGameResourceMismatch(player_id, model_id, component_type, checksum);
public AC_OnGameResourceMismatch(player_id, model_id, component_type, checksum) {
    if (model_id == CAC_GAMERESOURCE_MODELID__PEDIFP)
        AC_kick(player_id, "Veränderungen in der PED.IFP Datei");
    
    return 1;
}

AC_kick(playerid, reason[]) {
    new string[256];

    if (GetPVarInt(playerid, "AC_isGettingKicked") == 1)
        return 1;

    SetPVarInt(playerid, "AC_isGettingKicked", 1);

    format(string, sizeof(string), "[KICK]: Spieler %s wurde vom Anti-Cheat aus dem Server gekickt. Grund: %s", GetName(playerid), reason);
    SendAdminMessage(COLOR_RED, string);

    format(string, sizeof(string), "[KICK] Du wurdest soeben vom Anti-Cheat aus dem Server gekickt. Grund: %s", reason);
    SendClientMessage(playerid, COLOR_RED, string);

    format(string, sizeof(string), "Du wurdest aufgrund eines Regelverstoßes (oder einem anderen Grund) aus dem Server gekickt!\nDu wurdest vom Anti-Cheat aus dem Server gekickt!\nGrund: %s", reason);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "Kick Information", string, "Exit", "");

    KickDelay(playerid);

    return 1;
}

AC_ban(playerid, reason[]) {
    new string[256];

    if (GetPVarInt(playerid, "AC_isGettingKicked") == 1)
        return 1;

    SetPVarInt(playerid, "AC_isGettingKicked", 1);

    format(string, sizeof(string), "[BANNED]: Spieler %s wurde vom Anti-Cheat dauerhaft aus dem Server gebannt, Grund: %s", GetName(playerid), reason);
    SendAdminMessage(COLOR_RED, string);

    format(string, sizeof(string), "[BANNED] Du wurdest soeben vom Anti-Cheat dauerhaft aus dem Server gebannt. Grund: %s", reason);
    SendClientMessage(playerid, COLOR_RED, string);
    SendClientMessage(playerid, COLOR_RED, "Sind Sie der Meinung das diese Sperre falsch war? Dann schreiben Sie auf www.LyD-Roleplay.de ein Entbannantrag!");

    mysql_real_escape_string(reason, reason, gSQL, strlen(reason));
    format(string, sizeof(string), "UPDATE `accounts` SET `GebanntVon` = 'Anti-Cheat', `BanGrund` = '%s', `Banned` = 1 WHERE `Name` = '%s'", reason, GetName(playerid));
    mysql_pquery(string, THREAD_BAN, playerid, gSQL, MySQLThreadOwner);

    format(string, sizeof(string), "Gebannt: %s von: Anti-Cheat, Grund: %s, Dauer: %s", GetName(playerid), reason, "Immer");
    BanLog(string);

    format(string, sizeof(string), "%s wurde vom Anti-Cheat dauerhaft gebannt, Grund: %s", GetName(playerid), reason);
    SendUCPAktenEintrag(playerid, "Anti-Cheat", GetName(playerid), string);

    format(string, sizeof(string), "Anti-Cheat hat Spieler %s dauerhaft gebannt, Grund: %s", GetName(playerid), reason);
    AdminLog(string);
    
    return 1;
}

AC_mustUseAC(playerid) {
    if (Spieler[playerid][pMustUseAC])
        return true;

    //for (new i = 0; i < sizeof(AC_factions); i++)
        //if (Spieler[playerid][pFraktion] == AC_factions[i])
          //  return true;
    
    return false;
}

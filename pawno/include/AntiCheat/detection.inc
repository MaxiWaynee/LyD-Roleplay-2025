#define     AC_COLOR_HEX_WHITE     "{FFFFFE}"
#define     AC_COLOR_HEX_RED       "{FF0000}"
#define     AC_COLOR_RED           0xFF0000AA
#define     AC_COLOR_DARKRED       0xAA2222FF

#include <AntiCheat\BustAim>

stock AntiCheatLog(text[])
{
    new File:LogFile, jahr, monat, tag, stunde, minute, sekunde, string[256], path[64];
    getdate(jahr, monat, tag);
    gettime(stunde, minute, sekunde);
    format(path, sizeof(path), "/Logs/AntiCheat/AntiCheatLog.txt");
    LogFile = fopen(path, io_append);
    format(string, sizeof(string), "[%02d %02d %d %02d:%02d:%02d] - %s\r\n", tag, monat, jahr , stunde, minute, sekunde, text);
    fwrite(LogFile, string);
    fclose(LogFile);
    return 1;
}

public OnPlayerSuspectedForAimbot(playerid,hitid,weaponid,warnings)
{
	new string[128];
	
	if (warnings & WARNING_OUT_OF_RANGE_SHOT) {
		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Pro/Silent Aim(Out of Range)", GetName(playerid), playerid);
		SendManagerMessage(AC_COLOR_RED, string);
		AntiCheatLog(string);
	} 
	if (warnings & WARNING_PROAIM_TELEPORT) {
		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Pro Aim(Teleport Detected)", GetName(playerid), playerid);
		SendManagerMessage(AC_COLOR_RED, string);
		AntiCheatLog(string);
	} 
	if (warnings & WARNING_RANDOM_AIM) {
		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Pro/Silent Aim(Random Aim)", GetName(playerid), playerid);
		SendManagerMessage(AC_COLOR_RED, string);
		AntiCheatLog(string);
	} 
	if (warnings & WARNING_CONTINOUS_SHOTS) {
	    format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Aimbot", GetName(playerid), playerid);
		SendManagerMessage(AC_COLOR_RED, string);
		AntiCheatLog(string);
	}
	return 0;
}

forward OnCheatDetected(playerid, ip_address[], type, code);
public OnCheatDetected(playerid, ip_address[], type, code)
{
    if (type) BlockIpAddress(ip_address, 0);
    else
    {
		new string[128];
        switch(code)
        {
        	case 0:
        	{
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"AirBreak (onfoot)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 1:
        	{
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"AirBreak (vehicle)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 2:
        	{
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Teleport Hack (onfoot)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 3:
        	{
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Teleport Hack (vehicle)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 4:
        	{
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Teleport Hack (into/between vehicles)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 5:
        	{
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Teleport Hack (vehicle to player)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 6:
        	{
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Teleport Hack (pickups)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 7:
        	{
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Fly Hack (onfoot)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 8:
        	{
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Fly Hack (vehicle)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 9:
        	{
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Speed Hack (onfoot)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 10:
        	{
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Speed Hack (vehicle)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 11:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Health Hack (vehicle)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 12:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Health Hack (onfoot)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 13:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Armour Hack", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 14:
        	{
        		AntiCheatKickWithDesync(playerid, code);
        	}
        	case 15:
        	{
        		AntiCheatKickWithDesync(playerid, code);
        	}
        	case 16:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Ammo Hack (add)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 17:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Ammo Hack (infinite)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 18:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Special Actions Hack", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
        		AntiCheatLog(string);
        	}
        	case 19:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"GodMode (onfoot)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 20:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"GodMode (vehicle)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 21:
        	{
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Invisible Hack", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 22:
        	{
				SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: lagcomp-spoof");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"lagcomp-spoof", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 23:
        	{
				SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Tuning Hack");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Tuning Hack", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 24:
        	{
        		SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Parkour Mod");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Parkour Mod", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 25:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Quick turn", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 26:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Rapid fire", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 27:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"FakeSpawn", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 28:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"FakeKill", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 29:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Pro/Silent Aim", GetName(playerid), playerid);
		        SendManagerMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 30:
        	{
        		SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: CJ run");
		        format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"CJ run", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 31:
        	{
				SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: CarShot");
		        format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"CarShot", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 33:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"UnFreeze Hack", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 34:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"AFK Ghost", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 35:
        	{
				format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) Verdacht auf "AC_COLOR_HEX_RED"Full Aiming (vehicle)", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
        	}
        	case 36:
        	{
        		SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Fake NPC");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Fake NPC", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 38:
        	{
				SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: High Ping");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"High Ping", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 39:
        	{
        		SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Dialog Hack");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Dialog Hack", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
            case 40:
            {
            	SendClientMessage(playerid, AC_COLOR_DARKRED, MAX_CONNECTS_MSG);
            	AntiCheatKickWithDesync(playerid, code);
            }
            case 41:
            {
            	SendClientMessage(playerid, AC_COLOR_DARKRED, UNKNOWN_CLIENT_MSG);
            	AntiCheatKickWithDesync(playerid, code);
            }
            case 42:
        	{
        		SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Falsches Rcon Passwort");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Falsches Rcon Passwort", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 43:
        	{
				SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Tuning Crasher");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Tuning Crasher", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 44:
        	{
				SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Invalid seat Crasher");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Invalid seat Crasher", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 45:
        	{
				SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Dialog Crasher");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Dialog Crasher", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 46:
        	{
				SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Attached object Crasher");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Attached object Crasher", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 47:
        	{
				SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Weapon Crasher");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Weapon Crasher", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 48:
        	{
				SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Connection Flood");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Connection Flood", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 49:
        	{
        		SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Callback Functions Flood");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Callback Functions Flood", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 50:
        	{
        		SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Flood by seat changing");
		        format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Flood by seat changing", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 51:
        	{
        		SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: Ddos");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"Ddos", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
        	case 52:
        	{
        		SendClientMessage(playerid, AC_COLOR_DARKRED, "Du wurdest vom AntiCheat gekickt! Grund: NOP's");
        		format(string, sizeof(string), "[ANTICHEAT] "AC_COLOR_HEX_WHITE"%s (ID: %d) wurde vom AntiCheat gekickt! Grund: "AC_COLOR_HEX_RED"NOP's", GetName(playerid), playerid);
		        SendAdminMessage(AC_COLOR_RED, string);
		        AntiCheatLog(string);
		        FreezePlayer(playerid);
				AntiCheatKickWithDesync(playerid, code);
        	}
            default:
            {
                new strtmp[sizeof KICK_MSG];
                format(strtmp, sizeof strtmp, KICK_MSG, code);
                SendClientMessage(playerid, AC_COLOR_DARKRED, strtmp);
            }
        }
    }
    return 1;
}
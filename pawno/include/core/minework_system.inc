#include <YSI\y_hooks>

// Global worker define
#define MINE1 		679.7410, 825.1132, -42.9609
#define MINE2   	637.5282, 831.3797, -42.9609
#define MINE3   	584.4053, 921.9302, -42.6729
#define MINE4   	540.9487, 838.2302, -41.5093
#define EQUIPMENT   590.7204, 875.8160, -42.4973
#define INFOS       588.9069, 875.8036, -42.4973
#define STOPWORK    30

#if defined _ALS_ShowPlayerDialog
    #undef ShowPlayerDialog
#else
    #define _ALS_ShowPlayerDialog
#endif
#define ShowPlayerDialog _ShowPlayerDialog

// Forwards
forward Minenhaken(playerid);
forward Animstop(playerid);
forward Minenpausedone(playerid);

// Variables
new pickup_Mine[4];
new textlabel_Mine[4];
new pickup_equipment[1];
new pickup_earnedinfo[1];
new textlabel_equipment[1];
new textlabel_earnedinfo[1];

// -----

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, MINE1) || IsPlayerInRangeOfPoint(playerid, 3.0, MINE2) || IsPlayerInRangeOfPoint(playerid, 3.0, MINE3) || IsPlayerInRangeOfPoint(playerid, 3.0, MINE4)) { // ENTER TASTE
       		if (GetPVarInt(playerid, "Minenpause"))return SendClientMessage(playerid, COLOR_RED,"Du hast noch eine Pause die bis zu " #STOPWORK " Sekunden geht!");
			if (GetPVarInt(playerid, "Minenstart"))return SendClientMessage(playerid, COLOR_RED,"Du kannst nicht nochmal anfangen zu haken!");
			if (GetPVarInt(playerid, "Minenausruestung"))
			{
				if(IsPlayerInRangeOfPoint(playerid, 3.0, MINE1) || IsPlayerInRangeOfPoint(playerid, 3.0, MINE2) || IsPlayerInRangeOfPoint(playerid, 3.0, MINE3) || IsPlayerInRangeOfPoint(playerid, 3.0, MINE4))
				{
				    SendClientMessage(playerid,COLOR_BLUE,"Du beginnst an der Mine zu haken...");
				    ApplyAnimation(playerid, "BASEBALL", "Bat_4", 4.0, 1, 0, 0, 0, 0, 1);
				    SetTimerEx("Minenhaken" ,13000 ,false, "i", playerid); //13 seconds
				    SetPVarInt(playerid, "Minenstart", 1);
				}
				else
				{
				    SendClientMessage(playerid,COLOR_RED,"Du bist an keinem Minenplatz!");
				    return 1;
				}
			}
			else
			{
			    SetPlayerCheckpoint(playerid,EQUIPMENT,3.0);
			    return SendClientMessage(playerid,COLOR_RED,"Ziehe zuerst deine Minenausrüstung an!");
			}
        }
    }
    return 1;
}

hook OnGameModeInit() {
	// Pickups
    pickup_Mine[0] = CreateDynamicPickup(1274, 1, MINE1, 0); // Mine1 Pickup
    pickup_Mine[1] = CreateDynamicPickup(1274, 1, MINE2, 0); // Mine2 Pickup
    pickup_Mine[2] = CreateDynamicPickup(1274, 1, MINE3, 0); // Mine3 Pickup
    pickup_Mine[3] = CreateDynamicPickup(1274, 1, MINE4, 0); // Mine4 Pickup
    pickup_equipment[0] = CreateDynamicPickup(1275, 1, EQUIPMENT, 0); // Equipment Pickup
    pickup_earnedinfo[0] = CreateDynamicPickup(1212, 1, INFOS, 0); // Erlös Pickup
    
    // Textlabels
    textlabel_Mine[0] = _:CreateDynamic3DTextLabel("[ MINE ]\n"COLOR_HEX_WHITE"Drücke 'ENTER'", COLOR_BLUE, MINE1, 10.0); // Mine 1
    textlabel_Mine[1] = _:CreateDynamic3DTextLabel("[ MINE ]\n"COLOR_HEX_WHITE"Drücke 'ENTER'", COLOR_BLUE, MINE2, 10.0); // Mine 2
    textlabel_Mine[2] = _:CreateDynamic3DTextLabel("[ MINE ]\n"COLOR_HEX_WHITE"Drücke 'ENTER'", COLOR_BLUE, MINE3, 10.0); // Mine 3
    textlabel_Mine[3] = _:CreateDynamic3DTextLabel("[ MINE ]\n"COLOR_HEX_WHITE"Drücke 'ENTER'", COLOR_BLUE, MINE4, 10.0); // Mine 4
    textlabel_equipment[0] = _:CreateDynamic3DTextLabel("Arbeitskleidung für Minenarbeiter\n"COLOR_HEX_WHITE"Tippe /Minenausruestung", COLOR_YELLOW, EQUIPMENT, 10.0); // Equipment
    textlabel_earnedinfo[0] = _:CreateDynamic3DTextLabel("Erlösinformationen\n"COLOR_HEX_WHITE"Tippe /Earnedmoney", COLOR_YELLOW, INFOS, 10.0); // Earned information
    
    // -----
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    switch(dialogid)
    {
		case DIALOG_EARNEDMONEY:
		{
		    if(response)
		    {
		        if(listitem==0) // shows the earned money
		        {
		            if(Spieler[playerid][pMinenErlos] == 0)return SendClientMessage(playerid,COLOR_RED,"Du hast aktuell keinen Erlös.");
		            SCMFormatted(playerid,COLOR_WHITE,"Dein aktueller Erlös liegt bei "COLOR_HEX_ORANGE"$%s.",AddDelimiters(Spieler[playerid][pMinenErlos]));
		        }
				if(listitem==1) // money now
				{
				    if(Spieler[playerid][pMinenErlos] == 0)return SendClientMessage(playerid,COLOR_RED,"Du hast nicht gearbeitet, somit kannst du auch keine Auszahlung beantragen.");
				    SCMFormatted(playerid,COLOR_WHITE,"Du erhälst deinen Erlös von "COLOR_HEX_ORANGE"$%s "COLOR_HEX_WHITE"Bar auf die Hand!",AddDelimiters(Spieler[playerid][pMinenErlos]));
				    GivePlayerCash(playerid, Spieler[playerid][pMinenErlos]);
				    Spieler[playerid][pMinenErlos] = 0;
				}
				if(listitem==2) // money on payday
				{
				    if(Spieler[playerid][pMinenErlos] == 0)return SendClientMessage(playerid,COLOR_RED,"Du hast nicht gearbeitet, somit kannst du auch keine Auszahlung beantragen.");
				    SCMFormatted(playerid,COLOR_WHITE,"Du erhälst deinen Erlös von "COLOR_HEX_ORANGE"$%s "COLOR_HEX_WHITE"an deinem PayDay!",AddDelimiters(Spieler[playerid][pMinenErlos]));
				    Spieler[playerid][pPayCheck] += Spieler[playerid][pMinenErlos];
				    Spieler[playerid][pMinenErlos] = 0;
				}
		    }
		}
	}
	return 1;
}

// Commands

CMD:mineninfo(playerid)
{
	SendClientMessage(playerid, COLOR_YELLOW,"_____________________ MINENINFORMATIONEN ______________________");
	SendClientMessage(playerid, COLOR_WHITE,"Die Minen sind an der Steingrube in Las Venturas zu finden.");
	SendClientMessage(playerid, COLOR_WHITE,"Wenn du eine Mine in der Steingrube gefunden hast, so kannst du via die");
	SendClientMessage(playerid, COLOR_WHITE,"ENTER-Taste anfangen an der Mine zu haken.");
	SendClientMessage(playerid, COLOR_WHITE,"Der Erlös kann bis zu $1.500 gehen.");
	SendClientMessage(playerid, COLOR_WHITE,"Nach dem Haken hat man eine " #STOPWORK " sekündige Pause!");
	return 1;
}

CMD:earnedmoney(playerid,params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 3.0, INFOS))
	{
		ShowPlayerDialog(playerid, DIALOG_EARNEDMONEY,DIALOG_STYLE_LIST,""COLOR_HEX_ORANGE"Erlösinformationen",""COLOR_HEX_WHITE"Aktuellen Erlös einsehen\nDirekte Auszahlung beantragen\nAuszahlung am PayDay beantragen","Auswählen","Abbrechen");
	}
	else {
	    SetPlayerCheckpoint(playerid, INFOS, 3.0);
	    return SendClientMessage(playerid,COLOR_RED,"Du bist nicht an der Erlös-Informationsstelle!");
	}
	return 1;
}

CMD:minenausruestung(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 3.0, EQUIPMENT))
    {
	    if( IsPlayerAttachedObjectSlotUsed(playerid,1) && IsPlayerAttachedObjectSlotUsed(playerid, 3) ) {
	        RemovePlayerAttachedObject(playerid,1);
	        RemovePlayerAttachedObject(playerid,3);
	        SendClientMessage(playerid,COLOR_YELLOW,"Du hast deine Minenausrüstung abgelegt.");
	        DeletePVar(playerid, "Minenausruestung");
	    }
	    else {
	    	SetPlayerAttachedObject(playerid, 1, 3026, 1);
	    	SetPlayerAttachedObject(playerid, 3, 18635, 6);
	    	SendClientMessage(playerid,COLOR_YELLOW,"Du hast deine Minenausrüstung angezogen.");
	    	SetPVarInt(playerid, "Minenausruestung", 1);
	    }
	}
	else
	{
	    return SendClientMessage(playerid, COLOR_RED,"Du bist nicht am Ausrüstungspunkt der Mine!");
	}
	return 1;
}

// -----

public Minenhaken(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.0, MINE1) || IsPlayerInRangeOfPoint(playerid, 3.0, MINE2) || IsPlayerInRangeOfPoint(playerid, 3.0, MINE3) || IsPlayerInRangeOfPoint(playerid, 3.0, MINE4)) {
			new erlosmine = (random(300) * 5 );
			SCMFormatted(playerid,COLOR_GREEN,"Deine Arbeit hat sich gelohnt! Dein Erlös steigert sich um +$%s!",AddDelimiters(erlosmine));
			Spieler[playerid][pMinenErlos] += erlosmine;
			OnePlayAnim(playerid,"benchpress","gym_bp_celebrate", 4.0, 1, 0, 0, 0, 0);
			SetTimerEx("Animstop", 4500, false, "i", playerid);
			SetPVarInt(playerid, "Minenpause", 1);
			DeletePVar(playerid, "Minenstart");
			SetTimerEx("Minenpausedone" ,30000 ,false, "i", playerid);
		}
		else {
		    DeletePVar(playerid, "Minenstart");
			return SendClientMessage(playerid,COLOR_RED,"Du bist nicht mehr an der Mine! Somit kriegst du keinen Erlös.");
		}
	}
	return 1;
}

public Animstop(playerid)
{
	UnfreezePlayer(playerid);
	return 1;
}

public Minenpausedone(playerid)
{
	DeletePVar(playerid, "Minenpause");
	return 1;
}

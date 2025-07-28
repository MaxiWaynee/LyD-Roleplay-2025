#include <YSI\y_hooks>

new NDAufbrechen[MAX_PLAYERS];
new NDSpiceSuche[MAX_PLAYERS];
new NDC4[1];
new Pulse_NDAufbrechen2;
new NDLagerZeit2;
new NDSAufbrechen2;
new NDCheckRaub2;
new NDRemoveGate2;
new unfreezeSpice2[MAX_PLAYERS];
new NDRaub[MAX_PLAYERS];
new NDSpiceStatus[6];
new IsInInt[MAX_PLAYERS] = 0;
new SpicePoint[MAX_PLAYERS] = -1;
new SpicePointTimer[MAX_PLAYERS];
new bool:isNDC4 = false;
new bool:C4Finish = false;
enum e_SpiceBeute
{
	pBeute
}

new Beute[e_SpiceBeute];


CMD:ndaufbrechen(playerid, params[])
{
	new Float:x, Float:y, Float:z, string[128];
	if(!IsPlayerInRangeOfPoint(playerid, 2.0,NDAUFBRECHEN_COORDS)) return SendClientMessage(playerid,COLOR_RED,"Du befindest dich nicht am Spice-Lager");
	if(Spieler[playerid][pBrecheisen] == 0 || Spieler[playerid][pC4] == 0) return SendClientMessage(playerid,COLOR_RED,"Du benötigst ein Brecheisen und C4");
	if (g_aSettings[ASETTING_ROBBLOCK][ASETTING_TOGGLE]) return SendClientMessage(playerid, COLOR_RED, "Zurzeit ist die Überfallsperre aktiviert.");
	if( g_iNDRobStatus == Bankraub_Wartezeit ) return SendClientMessage(playerid, COLOR_RED, "Das Spice-Lager kann zur Zeit nicht ausgeraubt werden.");
	if( !HasPlayerWeapon(playerid) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst das Spice-Lager nicht ohne eine Waffe ausrauben.");
	if(GetOnlineND(playerid) < 2) return SendClientMessage(playerid,COLOR_RED,"Es sind nicht genügend Mitglieder der Nine Demons online.");
	if(IsPlayerExecutive(playerid)) return SendClientMessage(playerid,COLOR_RED,"Du bist Teil der Exekutive.");
	if(Spieler[playerid][pFraktion] == 15) return SendClientMessage(playerid,COLOR_RED,"Du kannst dein eigenes Lager nicht ausrauben!");
	GetPlayerPos(playerid, x, y, z);
	for(new i=0;i<GetMaxPlayers();i++)
	{
		if(IsPlayerConnected(i))
		{
			if(NDAufbrechen[i] == 1) return SCMFormatted(playerid,COLOR_RED, "Das Spice-Lager wird bereits von %s aufgebrochen.",GetName(i));
			if(NDRaub[i] == 1) return SendClientMessage(playerid,COLOR_RED,"Das Spice-Lager wird bereits ausgeraubt.");
		}
	}
	NDAufbrechen[playerid]=1;
	format(string,sizeof(string),"[SPICE-LAGER]{FFFFFF} %s versucht in das Spice-Lager einzubrechen.",GetName(playerid));
	SendRoundMessage(x, y, z, COLOR_GREEN, string,20.0);
	Pulse_NDAufbrechen2 = SetTimerEx("Pulse_NDAufbrechen",3000,true,"d",playerid);
	NDSAufbrechen2 = SetTimerEx("NDSAufbrechen", 120000, false, "i", playerid);
	return 1;
}


CMD:tresorsprengen(playerid, params[])
{
	if(NDRaub[playerid] == 1)
	{
		new Float:x, Float:y, Float:z, string[128];
		if(Spieler[playerid][pC4] == 0) return SendClientMessage(playerid, COLOR_RED, "Du besitzt kein C4!");
		if(!IsPlayerInRangeOfPoint(playerid,2.0,NDRobInt_C4_COORDS)) return SendClientMessage(playerid, COLOR_RED,"Hier kannst du kein C4 legen.");
		if(isNDC4 == true) return SendClientMessage(playerid,COLOR_RED,"Du hast bereits C4 gelegt.");
		if(C4Finish == true) return SendClientMessage(playerid,COLOR_RED,"Was willst du noch sprengen?");
		Spieler[playerid][pC4] --;
		OnePlayAnim(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
		GetPlayerPos(playerid, x, y, z);
		SendRoundMessage(x, y, z, COLOR_GREEN, "[TRESOR]{FFFFFF} Eine Ladung C4 wurde platziert.",100.0);
		format(string,sizeof(string),"[TRESOR]: %s hat eine Ladung C4 platziert.!",GetName(playerid));
		SendFraktionMessage(15,COLOR_RED,string);
		NDC4[0] = CreateObject(1654, NDRobInt_C4_COORDS, 0.0, 0.0, 0.0);
		isNDC4 = true;
		SetTimerEx("NDSprengen", 120000, false, "i", playerid);
		}
	else
	{
		SendClientMessage(playerid, COLOR_RED,"Du bist nicht am Raub beteiligt!");
	}
	return 1;
}

CMD:spicerauben(playerid, params[])
{
	if(NDRaub[playerid] == 1)
	{
		if(IsPlayerInRangeOfPoint(playerid,1.0,ND_SPICEROB_COORDS1))
		{
			if(NDSpiceStatus[0] == 1) return SendClientMessage(playerid,COLOR_RED,"Hier gibt es kein Spice mehr.");
			if(NDSpiceSuche[playerid] == 1) return SendClientMessage(playerid,COLOR_RED,"Du stiehlst bereits Spice.");
			if(C4Finish == false) return SendClientMessage(playerid, COLOR_RED,"Wie bist du hier her gekommen?");
			SpicePointTimer[playerid] = SetTimerEx("checkSpice", 5000, true, "i", playerid);
			SpicePoint[playerid] = 1;
			Update3DTextLabelText(text3D_NDRobInt_Spice[0], 0xF5FF00FF, "{FFFFFF}- Spice -\n\n{CB2720}Nicht möglich");
			unfreezeSpice2[playerid] = SetTimerEx("unfreezeSpice", 60000, false, "i", playerid);
			NDSpiceStatus[0] = 1;
			NDSpiceSuche[playerid] = 1;
		}
		else if(IsPlayerInRangeOfPoint(playerid,1.0,ND_SPICEROB_COORDS2))
		{
			if(NDSpiceStatus[1] == 1) return SendClientMessage(playerid,COLOR_RED,"Hier gibt es kein Spice mehr.");
			if(NDSpiceSuche[playerid] == 1) return SendClientMessage(playerid,COLOR_RED,"Du stiehlst bereits Spice.");
			SpicePointTimer[playerid] = SetTimerEx("checkSpice", 5000, true, "i", playerid);
			SpicePoint[playerid] = 2;
			Update3DTextLabelText(text3D_NDRobInt_Spice[1], 0xF5FF00FF, "{FFFFFF}- Spice -\n\n{CB2720}Nicht möglich");
			unfreezeSpice2[playerid]  = SetTimerEx("unfreezeSpice", 60000, false, "i", playerid);
			NDSpiceStatus[1] = 1;
			NDSpiceSuche[playerid] = 1;
		}
		else if(IsPlayerInRangeOfPoint(playerid,1.0,ND_SPICEROB_COORDS3))
		{
			if(NDSpiceStatus[2] == 1) return SendClientMessage(playerid,COLOR_RED,"Hier gibt es kein Spice mehr.");
			if(NDSpiceSuche[playerid] == 1) return SendClientMessage(playerid,COLOR_RED,"Du stiehlst bereits Spice.");
			SpicePointTimer[playerid] = SetTimerEx("checkSpice", 5000, true, "i", playerid);
			SpicePoint[playerid] = 3;
			Update3DTextLabelText(text3D_NDRobInt_Spice[2], 0xF5FF00FF, "{FFFFFF}- Spice -\n\n{CB2720}Nicht möglich");
			unfreezeSpice2[playerid]  = SetTimerEx("unfreezeSpice", 60000, false, "i", playerid);
			NDSpiceStatus[2] = 1;
			NDSpiceSuche[playerid] = 1;
		}
		else if(IsPlayerInRangeOfPoint(playerid,1.0,ND_SPICEROB_COORDS4))
		{
			if(NDSpiceStatus[3] == 1) return SendClientMessage(playerid,COLOR_RED,"Hier gibt es kein Spice mehr.");
			if(NDSpiceSuche[playerid] == 1) return SendClientMessage(playerid,COLOR_RED,"Du stiehlst bereits Spice.");
			SpicePointTimer[playerid] = SetTimerEx("checkSpice", 5000, true, "i", playerid);
			SpicePoint[playerid] = 4;
			Update3DTextLabelText(text3D_NDRobInt_Spice[3], 0xF5FF00FF, "{FFFFFF}- Spice -\n\n{CB2720}Nicht möglich");
			unfreezeSpice2[playerid]  = SetTimerEx("unfreezeSpice", 60000, false, "i", playerid);
			NDSpiceStatus[3] = 1;
			NDSpiceSuche[playerid] = 1;
		}
		else if(IsPlayerInRangeOfPoint(playerid,1.0,ND_SPICEROB_COORDS5))
		{
			if(NDSpiceStatus[4] == 1) return SendClientMessage(playerid,COLOR_RED,"Hier gibt es kein Spice mehr.");
			if(NDSpiceSuche[playerid] == 1) return SendClientMessage(playerid,COLOR_RED,"Du stiehlst bereits Spice.");
			Update3DTextLabelText(text3D_NDRobInt_Spice[4], 0xF5FF00FF, "{FFFFFF}- Spice -\n\n{CB2720}Nicht möglich");
			unfreezeSpice2[playerid]  = SetTimerEx("unfreezeSpice", 60000, false, "i", playerid);
			SpicePointTimer[playerid] = SetTimerEx("checkSpice", 5000, true, "i", playerid);
			SpicePoint[playerid] = 5;
			NDSpiceStatus[4] = 1;
			NDSpiceSuche[playerid] = 1;
		}
		else if(IsPlayerInRangeOfPoint(playerid,1.0,ND_SPICEROB_COORDS6))
		{
			if(NDSpiceStatus[5] == 1) return SendClientMessage(playerid,COLOR_RED,"Hier gibt es kein Spice mehr.");
			if(NDSpiceSuche[playerid] == 1) return SendClientMessage(playerid,COLOR_RED,"Du stiehlst bereits Spice.");
			Update3DTextLabelText(text3D_NDRobInt_Spice[5], 0xF5FF00FF, "{FFFFFF}- Spice -\n\n{CB2720}Nicht möglich");
			unfreezeSpice2[playerid]  = SetTimerEx("unfreezeSpice", 60000, false, "i", playerid);
			SpicePointTimer[playerid] = SetTimerEx("checkSpice", 5000, true, "i", playerid);
			SpicePoint[playerid] = 6;
			NDSpiceStatus[5] = 1;
			NDSpiceSuche[playerid] = 1;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_RED,"Du bist nicht am Raub beteiligt!");
	}
	return 1;
}


forward checkSpice(playerid);
public checkSpice(playerid)
{
	if(SpicePoint[playerid] == 1)
	{
		if(!IsPlayerInRangeOfPoint(playerid,4.0,ND_SPICEROB_COORDS1))
		{
			SendClientMessage(playerid, COLOR_RED, "Du hast dich zu weit vom Regal entfernt!");
			Update3DTextLabelText(text3D_NDRobInt_Spice[0], 0xF5FF00FF, "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.");
			NDSpiceStatus[0] = 0;
			NDSpiceSuche[playerid] = 0;
			KillTimer(SpicePointTimer[playerid]);
			KillTimer(unfreezeSpice2[playerid]);
		}
	}
	else if(SpicePoint[playerid] == 2)
	{
		if(!IsPlayerInRangeOfPoint(playerid,4.0,ND_SPICEROB_COORDS2))
		{
			SendClientMessage(playerid, COLOR_RED, "Du hast dich zu weit vom Regal entfernt!");
			Update3DTextLabelText(text3D_NDRobInt_Spice[1], 0xF5FF00FF, "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.");
			NDSpiceStatus[1] = 0;
			NDSpiceSuche[playerid] = 0;
			KillTimer(SpicePointTimer[playerid]);
			KillTimer(unfreezeSpice2[playerid]);
		}
	}
	else if(SpicePoint[playerid] == 3)
	{
		if(!IsPlayerInRangeOfPoint(playerid,4.0,ND_SPICEROB_COORDS3))
		{
			SendClientMessage(playerid, COLOR_RED, "Du hast dich zu weit vom Regal entfernt!");
			Update3DTextLabelText(text3D_NDRobInt_Spice[2], 0xF5FF00FF, "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.");
			NDSpiceStatus[2] = 0;
			NDSpiceSuche[playerid] = 0;
			KillTimer(SpicePointTimer[playerid]);
			KillTimer(unfreezeSpice2[playerid]);
		}
	}
	else if(SpicePoint[playerid] == 4)
	{
		if(!IsPlayerInRangeOfPoint(playerid,4.0,ND_SPICEROB_COORDS4))
		{
			SendClientMessage(playerid, COLOR_RED, "Du hast dich zu weit vom Regal entfernt!");
			Update3DTextLabelText(text3D_NDRobInt_Spice[3], 0xF5FF00FF, "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.");
			NDSpiceStatus[3] = 0;
			NDSpiceSuche[playerid] = 0;
			KillTimer(SpicePointTimer[playerid]);
			KillTimer(unfreezeSpice2[playerid]);
		}
	}
	else if(SpicePoint[playerid] == 5)
	{
		if(!IsPlayerInRangeOfPoint(playerid,4.0,ND_SPICEROB_COORDS5))
		{
			SendClientMessage(playerid, COLOR_RED, "Du hast dich zu weit vom Regal entfernt!");
			Update3DTextLabelText(text3D_NDRobInt_Spice[4], 0xF5FF00FF, "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.");
			NDSpiceStatus[4] = 0;
			NDSpiceSuche[playerid] = 0;
			KillTimer(SpicePointTimer[playerid]);
			KillTimer(unfreezeSpice2[playerid]);
		}
	}
	else if(SpicePoint[playerid] == 6)
	{
		if(!IsPlayerInRangeOfPoint(playerid,4.0,ND_SPICEROB_COORDS6))
		{
			SendClientMessage(playerid, COLOR_RED, "Du hast dich zu weit vom Regal entfernt!");
			Update3DTextLabelText(text3D_NDRobInt_Spice[5], 0xF5FF00FF, "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.");
			NDSpiceStatus[5] = 0;
			NDSpiceSuche[playerid] = 0;
			KillTimer(SpicePointTimer[playerid]);
			KillTimer(unfreezeSpice2[playerid]);
		}
	}
	else
	{
		//Zur Sicherheit
		NDSpiceSuche[playerid] = 0;
		KillTimer(SpicePointTimer[playerid]);
		KillTimer(unfreezeSpice2[playerid]);
	}


	return 1;
}

forward unfreezeSpice(playerid);
public unfreezeSpice(playerid)
{
	new SBeute;
    if(NDRaub[playerid] == 1)
	{
		KillTimer(SpicePointTimer[playerid]);
		SBeute += RandomEx(25, 100);
		Beute[pBeute] += SBeute;
        SCMFormatted(playerid, COLOR_GREEN, "[SPICE-LAGER] {FFFFFF}Du hast %d Spice gestohlen! Eure Beute liegt bei %d Gramm Spice", SBeute, Beute[pBeute]);
		NDSpiceSuche[playerid] = 0;
    }
}


forward NDSprengen(playerid);
public NDSprengen(playerid)
{
	if(NDRaub[playerid] == 1)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		SendRoundMessage(x, y, z, COLOR_GREEN, "[TRESOR]{FFFFFF} Die Ladung C4 ist explodiert.",100.0);
		SendFraktionMessage(15,COLOR_RED,"[TRESOR]{FFFFFF} Der Tresor wurde gesprengt.");
		CreateExplosion(NDRobInt_C4_COORDS, 0, 10.0);
		DestroyObject(NDC4[0]);
		isNDC4 = false;
		C4Finish = true;
		MoveDynamicObject(NDRobInt[14],-1201.1771, -1224.3874, 990.9299, 10, 0.0000, 0.0000, -90.0000 );
	}
	return 1;
}

forward Pulse_NDAufbrechen(playerid);
public Pulse_NDAufbrechen(playerid)
{
	new string[128];
    if(NDAufbrechen[playerid] == 1)
	{
		if(!IsPlayerInRangeOfPoint(playerid, 5.0, NDAUFBRECHEN_COORDS))
		{
			KillTimer(NDSAufbrechen2);
			NDAufbrechen[playerid] = 0;
			SendClientMessage(playerid, COLOR_RED, "Du hast dich zu weit von der Tür entfernt.");
			format(string,sizeof(string),"[SPICE-LAGER]: %s hat sich zu weit von der Tür entfernt.",GetName(playerid));
			SendFraktionMessage(15,COLOR_RED,string);
		}
	}
    return 1;
}

forward NDSAufbrechen(playerid);
public NDSAufbrechen(playerid)
{
	new count;
	if(NDAufbrechen[playerid] == 1)
	{
		for(new i=0;i<GetMaxPlayers();i++)
		{
			if(IsPlayerConnected(i))
			{
				if(IsPlayerInRangeOfPoint(i,20.0,NDAUFBRECHEN_COORDS))
				{
					if(!IsBeamter(i) && Spieler[i][pFraktion] != 15 && !IsPlayerExecutive(i))
					{
						SetPlayerPosEx(i,NDINTERIOR_EXIT_COORDS, MAPS_NDROBINT_INTERIOR,VW_NINEDEMONSINTERIOR);
						SendClientMessage(i,COLOR_YELLOW,"{E1FF00}[Überwachungssystem]{FFFFFF} Die Nine Demons wurden informiert, ihr habt 10 Minuten Zeit.");
						NDRaub[i] = 1;
						count ++;
					}
				}
			}
		}
		new Float:x, Float:y, Float:z, string[128];
		GetPlayerPos(playerid, x, y, z);
		format(string,sizeof(string),"[SPICE-LAGER]{FFFFFF} %s hat es geschafft die Tür aufzubrechen.",GetName(playerid));
		SendRoundMessage(x, y, z, COLOR_GREEN, string,20.0);
		format(string,sizeof(string),"[SPICE-LAGER]{FFFFFF} %s hat es geschafft in eurer Spice-Lager einzubrechen! Ihr habt 10 Minuten Zeit es zu verteidigen!",GetName(playerid));
		SendFraktionMessage(15,COLOR_RED,string);
		format(string,sizeof(string),"[SPICE-LAGER]{FFFFFF} Es befinden sich %d Spieler im Spice-Lager!",count);
		SendFraktionMessage(15,COLOR_RED,string);
		Spieler[playerid][pBrecheisen] --;
		NDAufbrechen[playerid]=0;
		IsInInt[playerid] = 1;
		g_iNDRobStatus = Bankraub_Aktiv;
		NDCheckRaub2 = SetTimerEx("NDCheckRaub",1500,true,"i",playerid);
		NDLagerZeit2 = SetTimerEx("NDLagerZeit", 600000, false, "i", playerid);
		KillTimer(Pulse_NDAufbrechen2);
	}
	return 1;
}

forward NDCheckRaub(playerid);
public NDCheckRaub(playerid)
{
	new count;
	for(new i=0;i<GetMaxPlayers();i++)
	{
		if(IsPlayerConnected(i))
		{
			if(NDRaub[i] == 1) count++;
		}
	}
	if(count == 0)
	{
		SendClientMessageToAll(COLOR_GREEN,"[SPICE-LAGER]{FFFFFF}Alle Spieler haben das Spice-Lager verlassen oder wurden getötet, der Raub wurde abgebrochen!");
		SendFraktionMessage(15,COLOR_GREEN,"[SPICE-LAGER]{FFFFFF}Der Raub ist fehlgeschlagen Ihr habt 50.000$ in die Fraktionskasse bekommen.");
		Beute[pBeute] = 0;
		Update3DTextLabelText(text3D_NDRobInt_Spice[0], 0xF5FF00FF, "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.");
		Update3DTextLabelText(text3D_NDRobInt_Spice[1], 0xF5FF00FF, "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.");
		Update3DTextLabelText(text3D_NDRobInt_Spice[2], 0xF5FF00FF, "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.");
		Update3DTextLabelText(text3D_NDRobInt_Spice[3], 0xF5FF00FF, "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.");
		Update3DTextLabelText(text3D_NDRobInt_Spice[4], 0xF5FF00FF, "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.");
		Update3DTextLabelText(text3D_NDRobInt_Spice[5], 0xF5FF00FF, "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.");
		NDSpiceStatus[0] = 0;
		NDSpiceStatus[1] = 0;
		NDSpiceStatus[2] = 0;
		NDSpiceStatus[3] = 0;
		NDSpiceStatus[4] = 0;
		NDSpiceStatus[5] = 0;
		isNDC4 = false;
		C4Finish = false;
		Kasse[BBikerZ] += 50000;
		NDRemoveGate2 = SetTimerEx("NDRemoveGate",1500,true,"i",playerid);
		Pulse_NDRob();
		KillTimer(NDLagerZeit2);
		KillTimer(NDCheckRaub2);
	}
	return 1;
}

forward NDRemoveGate(playerid);
public NDRemoveGate(playerid)
{
	for(new i=0;i<GetMaxPlayers();i++)
	{
		if(IsPlayerConnected(i))
		{
			if(IsInInt[i] == 0)
			{
				MoveDynamicObject(NDRobInt[14],-1201.1771, -1224.3874, 1002.5615, 10, 0.0000, 0.0000, -90.0000 );
				KillTimer(NDRemoveGate2);
			}
		}
	}
	return 1;
}

forward NDLagerZeit(playerid);
public NDLagerZeit(playerid)
{
	new count = 0;
	for(new i=0;i<GetMaxPlayers();i++)
	{
		if(IsPlayerConnected(i))
		{
			if(NDRaub[i] == 1) count++;
		}
	}
	new EndBeute = (Beute[pBeute]/count);
	for(new i=0;i<GetMaxPlayers();i++)
	{
		if(IsPlayerConnected(i))
		{
			if(NDRaub[i] == 1)
			{
				Spieler[i][pSpice] += EndBeute;
				g_fraktion[15][Fr_FSSpice] -= EndBeute;
				SCMFormatted(i,COLOR_GREEN,"[SPICE-LAGER]{FFFFFF} Ihr habt den Raub beendet. Eure Beute: %d Gramm, Dein Anteil: %d Gramm Spice",Beute[pBeute],EndBeute);
				NDRaub[i] = 0;
			}
		}
	}
	SendClientMessageToAll(COLOR_RED,"[SPICE-LAGER]{FFFFFF} Das Spice-Lager der NineDemons wurde erfolgreich ausgeraubt!");
	new string[128];
	format(string,sizeof(string),"[SPICE-LAGER]{FFFFFF] Es wurden %d Gramm aus dem Spice-Lager gestohlen.",Beute[pBeute]);
	SendFraktionMessage(15,COLOR_RED,string);
	Update3DTextLabelText(text3D_NDRobInt_Spice[0], 0xF5FF00FF, "{008718}- Spice -\n{FFFFFF}Tippe /spicerauben.");
	Update3DTextLabelText(text3D_NDRobInt_Spice[1], 0xF5FF00FF, "{008718}- Spice -\n{FFFFFF}Tippe /spicerauben.");
	Update3DTextLabelText(text3D_NDRobInt_Spice[2], 0xF5FF00FF, "{008718}- Spice -\n{FFFFFF}Tippe /spicerauben.");
	Update3DTextLabelText(text3D_NDRobInt_Spice[3], 0xF5FF00FF, "{008718}- Spice -\n{FFFFFF}Tippe /spicerauben.");
	Update3DTextLabelText(text3D_NDRobInt_Spice[4], 0xF5FF00FF, "{008718}- Spice -\n{FFFFFF}Tippe /spicerauben.");
	Update3DTextLabelText(text3D_NDRobInt_Spice[5], 0xF5FF00FF, "{008718}- Spice -\n{FFFFFF}Tippe /spicerauben.");
	NDSpiceStatus[0] = 0;
	NDSpiceStatus[1] = 0;
	NDSpiceStatus[2] = 0;
	NDSpiceStatus[3] = 0;
	NDSpiceStatus[4] = 0;
	NDSpiceStatus[5] = 0;
	Beute[pBeute] = 0;
	isNDC4 = false;
	C4Finish = false;
	Pulse_NDRob();
	KillTimer(NDCheckRaub2);
	return 1;
}



hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (newkeys & KEY_SECONDARY_ATTACK)
	{
        if (IsPlayerInRangeOfPoint(playerid, 2.0, NDINTERIOR_EXIT_COORDS))
		{
            SetPlayerPosEx(playerid, NDAUFBRECHEN_COORDS , MAPS_NDROBINT_INTERIOR, VW_MAIN);
            SetCameraBehindPlayer(playerid);
			IsInInt[playerid] = 0;
			if(NDRaub[playerid] == 1) return SendClientMessage(playerid,COLOR_RED,"[Spice-Lager]{FFFFFF} Da du das Spice-Lager verlassen hast bekommst du keinen Anteil mehr an der Beute.");
			NDRaub[playerid] = 0;
            return 1;
        }
		if (IsPlayerInRangeOfPoint(playerid, 2.0, NDAUFBRECHEN_COORDS))
		{
            if (Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied der Nine Demons.");
            SetPlayerPosEx(playerid, NDINTERIOR_EXIT_COORDS , MAPS_NDROBINT_INTERIOR, VW_NINEDEMONSINTERIOR);
            SetCameraBehindPlayer(playerid);
			IsInInt[playerid] = 1;
            return 1;
        }
    }
    return 1;
}

hook OnPlayerSpawn(playerid)
{
	NDRaub[playerid] = 0;
	IsInInt[playerid] = 0;
	//Pulse_NDRob();
	return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
	NDRaub[playerid] = 0;
	IsInInt[playerid] = 0;
	//Pulse_NDRob();
	return 1;
}

enum {
	ROBBING_STATE_NONE = 0,
	ROBBING_STATE_WARM_UP,
	ROBBING_STATE_ROBBING,
	ROBBING_STATE_COOLDOWN
}

#define INVALID_ROBBING_BIZ -1

#define ROBBING_ROBBING_TIME (100) // Anzahl an Sekunden bis die Überfall durchgeführt ist
#define ROBBING_COOL_DOWN_TIME (15*60) // alle 15 Minuten kann ein Biz ausgeraubt werden
//#define ROBBING_COOL_DOWN_TIME (1*60) // alle 15 Minuten kann ein Biz ausgeraubt werden
#define ROBBING_POLICE_MEN_ONLINE (2) // Anzahl an Polizisten (2,4,16,22) Online damit Überfall gestartet werden kann
new biz_index;
new
	g_iRobbingNotice[MAX_PLAYERS char];
new robbingvar[20];
enum e_RobbingBiz {
	RB_sName[MAX_PLAYER_NAME],
	Float:RB_fX,
	Float:RB_fY,
	Float:RB_fZ,
	Float:RB_fFace,
	RB_iBizID, // WICHTIG! Ordnet den Verkäufer dem Biz zu
	RB_iInterior,
	RB_iSkin,
	
	RB_ibState,
	RB_iBotID,
	RB_iRobberID,
	RB_iTmpRobberID,
	
	RB_timeAction,
	RB_iError,
}
new
	static g_RobbingBiz[][e_RobbingBiz] = {
	    {"",375.3219,-117.2778,1001.4922,182.0720,7,5,209, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //Pizzaria
	    {"",369.7922,-4.0278,1001.8589,182.6751,13,9,167, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //Clucking Bell
	    {"",369.7692,-4.0484,1001.8589,181.9826,3,9,167, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //Clucking Ball
	    {"",375.5814,-116.9216,1001.4922,180.5784,6,5,209, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //Pizzaria
	    {"",377.3261,-65.5061,1001.5078,185.7865,2,10,205, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //BSN
	    {"",377.1947,-65.5314,1001.5078,179.3449,4,10,205, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //BSN
	    {"",2000.6720,1007.1480,994.4688,359.6239,51,10,189, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //Casino
	    {"",207.4890,-98.6237,1005.2578,182.5992,37,15,151, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //Victim Skinshop
	    {"",2.2230,-30.7024,1003.5494,0.5089,23,10,172, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //247 Shop
	    {"",2.0706,-30.7009,1003.5494,0.4608,22,10,172, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //247 Shop
	    {"",2.0412,-30.7012,1003.5494,358.2410,26,10,172, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //247 Shop
	    {"",296.6713,-40.4204,1001.5156,7.2681,1,4,179, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //Hauptammu LS
	    {"",501.8529,-21.1311,1000.6797,86.4007,42,17,172, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //Alhambra
	    {"",2.1166,-30.7914,1003.5494,358.4960,60,10,172, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //247 Shop Stadthalle
		// {"",1375.8090,-980.6082,31.2592,351.6009,24,10,172, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //247 Shop | [*] R.I.P Verkäufer Label auf der Strasse 2018
		{"",370.0415,-4.4723,1001.8589,178.8840,18,9,167, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}, //Clucking Ball
		{"",370.0415,-4.4723,1001.8589,178.8840,25,9,167, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID},  //Clucking Ball
		{"",161.5822,-80.8033,1001.8047,179.1740,36,18,151, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID},  //Skin Shop ZIP
		{"",207.9627,-98.6561,1005.2578,178.7352,28,15,151, ROBBING_STATE_NONE, INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID}  //Skin Shop Binco
	};
	
stock Robbing_OnPlayerDisconnect(playerid) {
	for(new i ; i < sizeof(g_RobbingBiz) ; i++) {
	    if( g_RobbingBiz[i][RB_iRobberID] == playerid ) {
            g_RobbingBiz[i][RB_timeAction] = gettime() + ROBBING_COOL_DOWN_TIME;
            g_RobbingBiz[i][RB_ibState] = ROBBING_STATE_COOLDOWN;
            g_RobbingBiz[i][RB_iRobberID] = INVALID_PLAYER_ID;
            g_RobbingBiz[i][RB_iError] = 0;
	        ClearActorAnimations( g_RobbingBiz[i][RB_iBotID]);
	        break;
	    }
	}
	return 1;
}

stock Robbing_OnPlayerDeath(playerid) {
	for(new i ; i < sizeof(g_RobbingBiz) ; i++) {
	    if( g_RobbingBiz[i][RB_iRobberID] == playerid ) {
	        SendClientMessage(g_RobbingBiz[i][RB_iRobberID],COLOR_RED,"Überfall fehlgeschlagen!");
            g_RobbingBiz[i][RB_timeAction] = gettime() + ROBBING_COOL_DOWN_TIME;
            g_RobbingBiz[i][RB_ibState] = ROBBING_STATE_COOLDOWN;
            g_RobbingBiz[i][RB_iRobberID] = INVALID_PLAYER_ID;
            g_RobbingBiz[i][RB_iError] = 0;
	        ClearActorAnimations( g_RobbingBiz[i][RB_iBotID]);
	        break;
	    }
	}
	return 1;
}

stock Robbing_Init() {
	SetTimer("Robbing_ConnectBots",4509 + random(3) * 532,false);
	for(new i ; i < sizeof(g_RobbingBiz) ; i++) {
	    g_RobbingBiz[i][RB_ibState] = ROBBING_STATE_NONE;
	    g_RobbingBiz[i][RB_iError] = 0;
	}
	return 1;
}

forward Robbing_Pulse();
public Robbing_Pulse() {
	new
	    biz,
	    bizindex,
	    playerid,
	    time = gettime(),
	    String[128],
	    target;
	for(new i=0; i < MAX_PLAYERS ; i++)
	{
	    if( IsPlayerConnected(i))
		{
	        if( !IsPlayerNPC(i))
			{
	        	target = GetPlayerTargetActor(i);
				bizindex = Robbing_GetBizByBot(target);
				if(bizindex>=0&&target!=INVALID_ACTOR_ID)
				{
					if( g_RobbingBiz[bizindex][RB_ibState] == ROBBING_STATE_NONE)
					{
			 			if(IsWeaponValidForRobbing(GetPlayerWeapon(i)))
						 {
				    		g_RobbingBiz[bizindex][RB_iTmpRobberID] = i;
    					}
	    			}
				}
			}
		}
	}
	for(new i ; i < sizeof(g_RobbingBiz) ; i++)
	{
	    if( g_RobbingBiz[i][RB_ibState] == ROBBING_STATE_NONE)
		{
	        // Prüfen ob Jemand zielt und starten
	        if(IsPlayerConnected(g_RobbingBiz[i][RB_iTmpRobberID]))
			{
				if (g_aSettings[ASETTING_ROBBLOCK][ASETTING_TOGGLE]) {
					SendClientMessage(g_RobbingBiz[i][RB_iTmpRobberID], COLOR_RED, "Zurzeit ist die Überfallsperre aktiviert.");
					g_RobbingBiz[i][RB_iTmpRobberID]=MAX_PLAYERS+1;
					break;
				}
				if( GetOnlineExekutive(g_RobbingBiz[i][RB_iTmpRobberID]) < ROBBING_POLICE_MEN_ONLINE )
				{
					SendClientMessage(g_RobbingBiz[i][RB_iTmpRobberID],COLOR_RED,"Es sind nicht genügend Polizisten online, um ein Raub zu starten!");
					g_RobbingBiz[i][RB_iTmpRobberID]=MAX_PLAYERS+1;
					break;
				}
				else
				{
		            playerid = g_RobbingBiz[i][RB_iTmpRobberID];
		 			g_RobbingBiz[i][RB_iRobberID] = playerid;
		 			g_RobbingBiz[i][RB_ibState] = ROBBING_STATE_WARM_UP;
		 			g_RobbingBiz[i][RB_timeAction] = time + 2;
		 			g_RobbingBiz[i][RB_iError] = 0;
					g_RobbingBiz[i][RB_iTmpRobberID] = INVALID_PLAYER_ID;
		 			SendSchreiMessage(playerid,"Hände hoch! Geld her!!!", 30.0);
					SendClientMessage(playerid,COLOR_WHITE,"Verkäuferin schreit: Ahh.. Bitte nicht schießen! Ich gebe Ihnen das Geld!");
					SetPlayerChatBubble(target,"Ahh.. Bitte nicht schießen! Ich gebe Ihnen das Geld!",0xFFFF00FF,20.0,6500);
					g_iRobbingNotice{i} = 0;
					ApplyActorAnimation(target, "PED", "HANDSUP", 4.0, 0, 1, 0, 1, 2000);
					break;
				}
			}
	    }
	    else if( g_RobbingBiz[i][RB_ibState] == ROBBING_STATE_WARM_UP)
		{
            if( g_RobbingBiz[i][RB_timeAction] <= time )
			{
            	playerid = g_RobbingBiz[i][RB_iRobberID];
				target = GetPlayerTargetActor(playerid);
				g_RobbingBiz[i][RB_iTmpRobberID] = INVALID_PLAYER_ID;
		        if( target == g_RobbingBiz[i][RB_iBotID] && IsWeaponValidForRobbing(GetPlayerWeapon(playerid)) )
				{
					//
					if( GetOnlineExekutive(playerid) < ROBBING_POLICE_MEN_ONLINE )
					{
						SendClientMessage(playerid,COLOR_RED,"Es sind nicht genügend Polizisten online, um ein Raub zu starten!");

	                    g_RobbingBiz[i][RB_timeAction] = time + ROBBING_COOL_DOWN_TIME;
	                    g_RobbingBiz[i][RB_ibState] = ROBBING_STATE_COOLDOWN;
	                    g_RobbingBiz[i][RB_iRobberID] = INVALID_PLAYER_ID;
	                    g_RobbingBiz[i][RB_iError] = 0;
	                    ClearAnimationsExx( g_RobbingBiz[i][RB_iBotID],7500);
					}
					else
					{
						biz = g_RobbingBiz[i][RB_iBizID];
						bizindex = GetBizIndexByID(biz);
						new ort[28];
    					GetPoint2DZone(Biz[bizindex][EnterX], Biz[bizindex][EnterY], ort, 28);
						format(String,sizeof(String),"[ZENTRALE] Geschäft: %s, Inhaber: %s wird von %s ausgeraubt! Ort: %s.",Biz[bizindex][bName],Biz[bizindex][bBesitzer],GetName(playerid), ort);
						SendExecutiveMessage(COLOR_RED,String);
						SendClientMessage(playerid,COLOR_YELLOW,"Ziele weiter auf die Verkäuferin, bis sie die Beute in den Beutel gepackt hat!");

	                    g_RobbingBiz[i][RB_timeAction] = time + ROBBING_ROBBING_TIME;
		 				g_RobbingBiz[i][RB_ibState] = ROBBING_STATE_ROBBING;

					}
                }
		        else {
		            // Abbruch, da nicht zielt.
                    g_RobbingBiz[i][RB_timeAction] = time + ROBBING_COOL_DOWN_TIME;
                    g_RobbingBiz[i][RB_ibState] = ROBBING_STATE_COOLDOWN;
                    g_RobbingBiz[i][RB_iRobberID] = INVALID_PLAYER_ID;
                    g_RobbingBiz[i][RB_iError] = 0;
                    ClearAnimationsExx( g_RobbingBiz[i][RB_iBotID],7500);
		        }
	        }
	    }
	    else if( g_RobbingBiz[i][RB_ibState] == ROBBING_STATE_ROBBING) {
	        new
	            sTimeLeft[32],
                timeleft;
         	playerid = g_RobbingBiz[i][RB_iRobberID];
			target = GetPlayerTargetActor(playerid);
			timeleft = g_RobbingBiz[i][RB_timeAction] - time;
			
			if(timeleft == (ROBBING_ROBBING_TIME - 2) ) {
			    ApplyActorAnimation(target, "ped", "cower", 3.0, 1, 0, 0, 0, 0);
			}
			if(timeleft == (ROBBING_ROBBING_TIME - 5) ) {
			    SetPlayerChatBubble(target,"Ich hole das Geld.",0xFFFF00FF,16.0,3500);
			}
			
	        if( target == g_RobbingBiz[i][RB_iBotID] && IsWeaponValidForRobbing(GetPlayerWeapon(playerid)) ) {
				format(sTimeLeft,sizeof(sTimeLeft),"~g~%d",timeleft);
                if( g_RobbingBiz[i][RB_timeAction] <= time ) {
                    // Geldregen
					biz = g_RobbingBiz[i][RB_iBizID];
					bizindex = GetBizIndexByID(biz);
					if( Biz[bizindex][bKasse] <= 0 ) {
                    	SendClientMessage(playerid,COLOR_RED,"Ich kann dir kein Geld geben, das Geschäft ist pleite. Bitte töte mich nicht");
					    SetPlayerChatBubble(target,"Das Geschäft ist pleite. Ich habe kein Geld!",0xFFFF00FF,17.0,6500);
					}
					else {
					    new
					        beute;
                        if( Biz[bizindex][bKasse] < 1000 ) {
                            beute = RandomEx(1, Biz[bizindex][bKasse] );
                        }
                        else if( Biz[bizindex][bKasse] < 40000 ) {
                            beute = RandomEx(1000, Biz[bizindex][bKasse] );
                        }
                        else {
                            beute = RandomEx(1000, 40000 );
                        }
                        Biz[bizindex][bKasse] -= beute;
                        GivePlayerCash(playerid,beute);
                        format(String,sizeof(String),"Du hast das Geschäft erfolgreich ausgeraubt. Deine Beute: %d$",beute);
                    	SendClientMessage(playerid,COLOR_GREEN,String);
					    SetPlayerChatBubble(target,"Hier hast du das Geld! Bitte töte mich nicht!",0xFFFF00FF,17.0,6800);
					}
					
                    g_RobbingBiz[i][RB_timeAction] = time + ROBBING_COOL_DOWN_TIME;
                    g_RobbingBiz[i][RB_ibState] = ROBBING_STATE_COOLDOWN;
                    g_RobbingBiz[i][RB_iRobberID] = INVALID_PLAYER_ID;
                    g_RobbingBiz[i][RB_iError] = 0;
                    ClearAnimationsExx( g_RobbingBiz[i][RB_iBotID],12000);
                }
	        }
	        else {
				format(sTimeLeft,sizeof(sTimeLeft),"~r~%d",timeleft);
	            // Zielt nicht mehr auf Verkäufer.
	            if( g_iRobbingNotice{i} == 0 ) {
                	SendClientMessage(playerid,COLOR_RED,"Der Überfall scheitert, wenn du die Verkäuferin nicht regelmäßig anzielst!");
		            g_iRobbingNotice{i} = 1;
	            }
	            g_RobbingBiz[i][RB_iError]++;
				if( g_RobbingBiz[i][RB_iError] >= 30 ) {
				    // Abbruch, zu wenig eingeschüchtert.
		            SendClientMessage( g_RobbingBiz[i][RB_iRobberID], COLOR_RED,"Du hast es nicht geschafft, den Verkäufer genug einzuschüchtern. Der Überfall ist gescheitert!");
                    g_RobbingBiz[i][RB_timeAction] = time + ROBBING_COOL_DOWN_TIME;
                    g_RobbingBiz[i][RB_ibState] = ROBBING_STATE_COOLDOWN;
                    g_RobbingBiz[i][RB_iRobberID] = INVALID_PLAYER_ID;
                    g_RobbingBiz[i][RB_iError] = 0;
				    SetPlayerChatBubble(target,"Du machst mir keine Angst! Die Polizei wird bald hier sein!",0xFFFF00FF,15.0,6500);
                    ClearAnimationsExx( g_RobbingBiz[i][RB_iBotID],3800);
				}
				/*
				else {
		            SendClientMessage( g_RobbingBiz[i][RB_iRobberID], COLOR_RED,"Ziel wieder auf den Verkäufer, sonst scheitert der Raubzug!");
				}
				*/
	        }
	        if(timeleft > 0 ) {
				GameTextForPlayer(playerid,sTimeLeft,875,6);
	        }
	    }
	    else if( g_RobbingBiz[i][RB_ibState] == ROBBING_STATE_COOLDOWN) {
			if( time >= g_RobbingBiz[i][RB_timeAction] ) {
			    g_RobbingBiz[i][RB_ibState] = ROBBING_STATE_NONE;
			    g_RobbingBiz[i][RB_timeAction] = 0;
	 			g_RobbingBiz[i][RB_iError] = 0;
	 			g_RobbingBiz[i][RB_iRobberID] = INVALID_PLAYER_ID;
			}
	    }
	}
	
	return 1;
}

stock Robbing_GetBizByBot(botid) {
	for(new i ; i < sizeof(g_RobbingBiz) ; i++) {
		if( g_RobbingBiz[i][RB_iBotID] == botid ) {
		    return i;
		}
	}
	return INVALID_ROBBING_BIZ;
}


forward Robbing_ConnectBots();
public Robbing_ConnectBots()
{
	for(new i;i<sizeof(g_RobbingBiz);i++)
	{
 		g_RobbingBiz[i][RB_iBotID] = CreateActor(g_RobbingBiz[i][RB_iSkin],g_RobbingBiz[i][RB_fX],g_RobbingBiz[i][RB_fY],g_RobbingBiz[i][RB_fZ],g_RobbingBiz[i][RB_fFace]);
	    biz_index = GetBizIndexByID(g_RobbingBiz[i][RB_iBizID]);
	    SetActorVirtualWorld(g_RobbingBiz[i][RB_iBotID],biz_index);
	    SetActorInvulnerable(g_RobbingBiz[i][RB_iBotID]);
	    CreateDynamic3DTextLabel("Verkäufer", 0xFFFFFFFF, g_RobbingBiz[i][RB_fX], g_RobbingBiz[i][RB_fY], g_RobbingBiz[i][RB_fZ] + 1.05, 10.0, .worldid = biz_index);
		robbingvar[g_RobbingBiz[i][RB_iBotID]]=i;
	}
    SetTimer("Robbing_Pulse", 523, true);
	return 1;
}


stock IsWeaponValidForRobbing(weaponid) {
	switch(weaponid) {
	    case 4,5,8,9,10,22..38: {
	        return true;
		}
	}
	return 0;
}


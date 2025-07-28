stock GZ_OnPlayerSpawn(playerid) {
	new
	    frak = Spieler[playerid][pFraktion];
	if( IsAFightFaction(frak) ) {
	    if( IsGangInFight(frak)) {

	    }
	    return 1;
	}
	return 0;
}

stock GZ_OnPlayerDeath(playerid,killerid,reason) {
	#pragma unused reason
	if( killerid != INVALID_PLAYER_ID ) {
		new
		    frak = Spieler[playerid][pFraktion];
	    if(IsAFightFaction(frak)) {
		    if( IsGangInFight(frak)) {
			    new
					fightid,
			        index = GetPlayerGangZone(playerid);
				if( index != -1 ) {
				    fightid = GetGangFight(frak);
				    if( fightid == index ) {
						new
						    cur_level,
						    new_level,

						    String[128],
						    killerfraktion;
						killerfraktion = Spieler[killerid][pFraktion];
						if( killerfraktion == frak ) {
						    // teamkill
							if( killerfraktion == g_GangZone[index][GZ_iAttacker]) {
							    g_GangZone[index][GZ_iOwnerScore] += 3;
							}
							else if( killerfraktion == g_GangZone[index][GZ_iOwner]) {
							    g_GangZone[index][GZ_iAttackerScore] += 3;
							}
							format(String,sizeof(String),"->TEAMKILL<- {FF8800}%s hat sein Partner %s im Gangfight getötet! {00CC00}(3P. an die gegnerische Gang)",GetName(killerid),GetName(playerid),GetFactionNameOfFaction(killerfraktion)); 						SendFraktionMessage( killerfraktion , COLOR_YELLOW,String);
							SendFraktionMessage( frak , COLOR_YELLOW,String);
							GameTextForPlayer(killerid, "~r~TEAMKILL",1550,6);
						}
						else {
							Spieler[killerid][pKillsGangFightSession]++;
							cur_level = GetPlayerGangFightSkillLevel(killerid);
							Spieler[killerid][pKillsGangFight]++;
							new_level = GetPlayerGangFightSkillLevel(killerid);
							if( new_level > cur_level ) {
							    // Skill Upgrade
							    format(String,sizeof(String),"Herzlichen Glückwunsch! "#COL_GREEN"Du hast %s-Skill %d erreicht!",("Gangfight"),new_level);
							    SendClientMessage(killerid,COLOR_YELLOW,String);
							    format(String,sizeof(String),"~y~GANGFIGHT-SKILL ~g~%d ~y~erreicht!",new_level);
							    SkillUpgrade(killerid,String);
							    format(String,sizeof(String),"%s hat %s-Skill %d erreicht",GetName(killerid),("Gangfight"),new_level);
							    SkillLog(String);
							}

							if( killerfraktion == g_GangZone[index][GZ_iAttacker]) {
							    g_GangZone[index][GZ_iAttackerScore] += 3;
							}
							else if( killerfraktion == g_GangZone[index][GZ_iOwner]) {
							    g_GangZone[index][GZ_iOwnerScore] += 3;
							}
							format(String,sizeof(String),"->GANGFIGHTKILL<- {0088FF}%s Gangfightkill an %s {00CC00}(3P. an die %s)",GetName(killerid),GetName(playerid),GetFactionNameOfFaction(killerfraktion));
							SendFraktionMessage( killerfraktion , COLOR_YELLOW,String);
							SendFraktionMessage( frak , COLOR_YELLOW,String);
							GameTextForPlayer(killerid, "~g~GANGFIGHTKILL",1550,6);
						}
						if( g_GangZone[index][GZ_iFlaggePlayer] == playerid) {
					        g_GangZone[index][GZ_iFlaggeEnd] = 0;
					        g_GangZone[index][GZ_iFlaggePlayer] = INVALID_PLAYER_ID;
						}
						UpdateGangFightInfo(index);
						return 1;
				    }
				}
		    }
		}
	}
	return 0;
}

stock Gang_OnPlayerEnterDynamicArea(playerid,areaid) {
	new
	    val = Streamer_GetIntData(STREAMER_TYPE_AREA,areaid,E_STREAMER_EXTRA_ID);
	if( val == 1909 ) {
	    for(new i ; i < iGangZones ; i++) {
	        if( areaid == g_GangZone[i][GZ_iAreaID] ) {
				if( g_GangZone[i][GZ_iStatus] == 1 ) {
		            // In Diese Zone & gangfight
		            new
		                frak,
		                String[128];
					frak = Spieler[playerid][pFraktion];
				    if( frak == g_GangZone[i][GZ_iAttacker] || frak == g_GangZone[i][GZ_iOwner]) {
					 	TextDrawShowForPlayer(playerid,tdGangZoneHeader);
					 	TextDrawShowForPlayer(playerid,g_GangZone[i][GZ_tdInfo]);
				    }
				    else {
				        format(String,sizeof(String),"Achtung: {FFFFFF}Hier findet zur Zeit ein Gangwar zwischen %s und %s statt!",GetFactionNameOfFaction(g_GangZone[i][GZ_iOwner]),GetFactionNameOfFaction(g_GangZone[i][GZ_iAttacker]));
				        SendClientMessage(playerid,COLOR_RED,String);
				    }
				    break;
				}
	        }
	    }
		return 1;
	}
	return 0;
}

stock Gang_OnPlayerLeaveDynamicArea(playerid,areaid) {
	new
	    val = Streamer_GetIntData(STREAMER_TYPE_AREA,areaid,E_STREAMER_EXTRA_ID);
	if( val == 1909 ) {
	    for(new i ; i < iGangZones ; i++) {
	        if( areaid == g_GangZone[i][GZ_iAreaID] ) {
			 	TextDrawHideForPlayer(playerid,tdGangZoneHeader);
			 	TextDrawHideForPlayer(playerid,g_GangZone[i][GZ_tdInfo]);
			 	break;
	        }
	    }
		return 1;
	}
	return 0;
}

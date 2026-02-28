/************************************************************ pOneArmedBandit***
*
* Scriptname:
* -» pOneArmedBandit
*
* Author:
* -» Pablo_Borsellino
*
* Creation Date:
* -» 15th October 2011
*
* Release Date:
* -» 16th October 2011
*
* Version:
* -» 1.0
*
* Need to use:
* -» Sa:Mp 0.3d RC5-3 or higher
*
* Language:
* -» English
*
* Description:
* -» Player can play One-armed Bandit without being in the Casino.
*
* Functions:
* -» StartOnArmedBanditForPlayer(playerid);
* -» StopOnArmedBanditForPlayer(playerid);
*
* Public's:
* -» OnPlayerFinishOnArmedBandit(playerid,correct)
*
* Credit's:
* -» n/a
*											Copyright © 2011 by Pablo_Borsellino
*******************************************************************************/

//_____________________________________________________________________Include's
#include <a_samp>

//_______________________________________________________________Variable's & co.
new bool:_OAB_PlayerPlays[MAX_PLAYERS],
	bool:_OAB_AUTORETRY[MAX_PLAYERS],
	_OAB_TICKS[MAX_PLAYERS],
	
	bool:_OAB_PICKED[MAX_PLAYERS][3],
	
	_OAB_CURRENT_TD_SLOT_1[MAX_PLAYERS],
	_OAB_CURRENT_TD_SLOT_2[MAX_PLAYERS],
	_OAB_CURRENT_TD_SLOT_3[MAX_PLAYERS],
	Text:_OAB_Info,
	Text:_OAB_TD_SLOT_1[MAX_PLAYERS],
	Text:_OAB_TD_SLOT_2[MAX_PLAYERS],
	Text:_OAB_TD_SLOT_3[MAX_PLAYERS];

//_______________________________________________________________User Function's
OAB_OnGameModeInit() {
	// Create the textdraws:
	_OAB_Info = TextDrawCreate(175.000000, 281.000000, "~w~Druecke ~b~~k~~PED_SPRINT~ ~w~zum Stoppen");
	TextDrawBackgroundColor(_OAB_Info, 255);
	TextDrawFont(_OAB_Info, 1);
	TextDrawLetterSize(_OAB_Info, 0.500000, 1.800000);
	TextDrawColor(_OAB_Info, -1);
	TextDrawSetOutline(_OAB_Info, 1);
	TextDrawSetProportional(_OAB_Info, 1);
	TextDrawUseBox(_OAB_Info, 1);
	TextDrawBoxColor(_OAB_Info, 68);
	TextDrawTextSize(_OAB_Info, 464.000000, 3.000000);
	return 1;
}
forward StartOnArmedBanditForPlayer(playerid);
public StartOnArmedBanditForPlayer(playerid)
{
	//printf("StartOnArmedBanditForPlayer(%d)",playerid);
	if(_OAB_PlayerPlays[playerid]==true)return true;
	//printf("StartOnArmedBanditForPlayer(%d) #1",playerid);
	_OAB_PlayerPlays[playerid]=true;
	_OAB_AUTORETRY[playerid]=false;
	_OAB_TICKS[playerid]=30;
	_OAB_PICKED[playerid][0] = false;
	_OAB_PICKED[playerid][1] = false;
	_OAB_PICKED[playerid][2] = false;
	_OAB_CURRENT_TD_SLOT_1[playerid]=random(5-2)+2;
	_OAB_CURRENT_TD_SLOT_2[playerid]=random(5-2)+2;
	_OAB_CURRENT_TD_SLOT_3[playerid]=random(5-2)+2;
    _OAB_TD_SLOT_1[playerid] = TextDrawCreate(274,300,"LD_SLOT:r_69");
    _OAB_TD_SLOT_2[playerid] = TextDrawCreate(200,300,"LD_SLOT:r_69");
    _OAB_TD_SLOT_3[playerid] = TextDrawCreate(348,300,"LD_SLOT:r_69");
    TextDrawFont(_OAB_TD_SLOT_1[playerid],4);
    TextDrawFont(_OAB_TD_SLOT_2[playerid],4);
    TextDrawFont(_OAB_TD_SLOT_3[playerid],4);
    TextDrawColor(_OAB_TD_SLOT_1[playerid],0xFFFFFFFF);
    TextDrawColor(_OAB_TD_SLOT_2[playerid],0xFFFFFFFF);
    TextDrawColor(_OAB_TD_SLOT_3[playerid],0xFFFFFFFF);
    TextDrawTextSize(_OAB_TD_SLOT_1[playerid],75,75);
    TextDrawTextSize(_OAB_TD_SLOT_2[playerid],75,75);
    TextDrawTextSize(_OAB_TD_SLOT_3[playerid],75,75);
    TextDrawShowForPlayer(playerid,_OAB_TD_SLOT_1[playerid]);
    TextDrawShowForPlayer(playerid,_OAB_TD_SLOT_2[playerid]);
    TextDrawShowForPlayer(playerid,_OAB_TD_SLOT_3[playerid]);
    TextDrawShowForPlayer(playerid,_OAB_Info);
    StartOABForPlayer(playerid);
	return true;
}

//______________________________________________________________________________
forward StartOABForPlayer(playerid);
public StartOABForPlayer(playerid)
{
	if(_OAB_PlayerPlays[playerid]==false)return true;
	
	if( _OAB_PICKED[playerid][0] == false || _OAB_PICKED[playerid][1] == false || _OAB_PICKED[playerid][2] == false ) {
	    SetTimerEx("_OAB_PLAYER_TIMER",71,false,"d",playerid);
	}
	else {
		_OAB_PLAYER_FINISH_TURN(playerid);
	}
	/*
	if(_OAB_TICKS[playerid]>=30)return SetTimerEx("_OAB_PLAYER_TIMER",50,false,"d",playerid);
	else if(_OAB_TICKS[playerid]>=20)return SetTimerEx("_OAB_PLAYER_TIMER",60,false,"d",playerid);
	else if(_OAB_TICKS[playerid]>=10)return SetTimerEx("_OAB_PLAYER_TIMER",70,false,"d",playerid);
	else if(_OAB_TICKS[playerid]==9)return SetTimerEx("_OAB_PLAYER_TIMER",80,false,"d",playerid);
	if(_OAB_TICKS[playerid]==8)return SetTimerEx("_OAB_PLAYER_TIMER",90,false,"d",playerid);
	else if(_OAB_TICKS[playerid]==7)return SetTimerEx("_OAB_PLAYER_TIMER",100,false,"d",playerid);
	else if(_OAB_TICKS[playerid]==6)return SetTimerEx("_OAB_PLAYER_TIMER",110,false,"d",playerid);
	else if(_OAB_TICKS[playerid]==5)return SetTimerEx("_OAB_PLAYER_TIMER",120,false,"d",playerid);
	else if(_OAB_TICKS[playerid]==4)return SetTimerEx("_OAB_PLAYER_TIMER",130,false,"d",playerid);
	else if(_OAB_TICKS[playerid]==3)return SetTimerEx("_OAB_PLAYER_TIMER",140,false,"d",playerid);
	else if(_OAB_TICKS[playerid]==2)return SetTimerEx("_OAB_PLAYER_TIMER",150,false,"d",playerid);
	else if(_OAB_TICKS[playerid]==1)return SetTimerEx("_OAB_PLAYER_TIMER",160,false,"d",playerid);
	else if(_OAB_TICKS[playerid]==0)
	{
		SetTimerEx("StopOnArmedBanditForPlayer",2500,false,"d",playerid);
		_OAB_PLAYER_FINISH_TURN(playerid);
	}
	*/
	return true;
}

/*______________________________________________________________________________
Example for OnPlayerFinishOnArmedBandit(..) in the Gamemode:
________________________________________________________________________________
*/
#define OAB_MONEY_AT_WIN_OR_LOSE 8000
#define OAB_MONEY_AT_PLAYCOST 500

forward OnPlayerFinishOnArmedBandit(playerid,correct);
public OnPlayerFinishOnArmedBandit(playerid,correct)
{
	if(correct==3) //All three are the same
	{
		GameTextForPlayer(playerid,"~g~Gewonnen!",2000,6);
		GivePlayerCash(playerid,OAB_MONEY_AT_WIN_OR_LOSE);
		Biz[CasinoBiz_Index][bKasse] -= OAB_MONEY_AT_WIN_OR_LOSE;
		PlayerPlaySound(playerid,5449,0,0,0);
	    ShowBuyInformation(playerid,"~g~+"#OAB_MONEY_AT_WIN_OR_LOSE"$");
	}
	else if(correct<=2) //None are the same or only two are the same
	{
	    PlayerPlaySound(playerid,5454,0,0,0);
		GameTextForPlayer(playerid,"~r~Verloren",2000,6);
	}
	return 1;
}

forward StopOnArmedBanditForPlayer(playerid);
public StopOnArmedBanditForPlayer(playerid)
{
	//printf("StopOnArmedBanditForPlayer(%d)",playerid);
	TextDrawDestroy(_OAB_TD_SLOT_1[playerid]);
	TextDrawDestroy(_OAB_TD_SLOT_2[playerid]);
	TextDrawDestroy(_OAB_TD_SLOT_3[playerid]);
    TextDrawHideForPlayer(playerid,_OAB_Info);
	_OAB_PlayerPlays[playerid]=false;
	_OAB_AUTORETRY[playerid]=false;
	return true;
}

//______________________________________________________________Script Function's
forward _OAB_PLAYER_FINISH_TURN(playerid);
public _OAB_PLAYER_FINISH_TURN(playerid)
{
	if(_OAB_CURRENT_TD_SLOT_1[playerid]==_OAB_CURRENT_TD_SLOT_2[playerid]&&_OAB_CURRENT_TD_SLOT_1[playerid]!=_OAB_CURRENT_TD_SLOT_3[playerid])return CallRemoteFunction("OnPlayerFinishOnArmedBandit","dd",playerid,2);
	else if(_OAB_CURRENT_TD_SLOT_2[playerid]==_OAB_CURRENT_TD_SLOT_3[playerid]&&_OAB_CURRENT_TD_SLOT_2[playerid]!=_OAB_CURRENT_TD_SLOT_1[playerid])return CallRemoteFunction("OnPlayerFinishOnArmedBandit","dd",playerid,2);
	else if(_OAB_CURRENT_TD_SLOT_1[playerid]==_OAB_CURRENT_TD_SLOT_3[playerid]&&_OAB_CURRENT_TD_SLOT_1[playerid]!=_OAB_CURRENT_TD_SLOT_2[playerid])return CallRemoteFunction("OnPlayerFinishOnArmedBandit","dd",playerid,2);
	else if(_OAB_CURRENT_TD_SLOT_1[playerid]==_OAB_CURRENT_TD_SLOT_2[playerid]&&_OAB_CURRENT_TD_SLOT_1[playerid]==_OAB_CURRENT_TD_SLOT_3[playerid])return CallRemoteFunction("OnPlayerFinishOnArmedBandit","dd",playerid,3);
	else if(_OAB_CURRENT_TD_SLOT_1[playerid]!=_OAB_CURRENT_TD_SLOT_2[playerid]&&_OAB_CURRENT_TD_SLOT_1[playerid]!=_OAB_CURRENT_TD_SLOT_3[playerid])return CallRemoteFunction("OnPlayerFinishOnArmedBandit","dd",playerid,0);
	else return CallRemoteFunction("OnPlayerFinishOnArmedBandit","dd",playerid,1);
}

forward _OAB_PLAYER_TIMER(playerid);
public _OAB_PLAYER_TIMER(playerid)
{
    if( _OAB_PICKED[playerid][0] == false ) {
		_OAB_CURRENT_TD_SLOT_1[playerid]++;
	    if(_OAB_CURRENT_TD_SLOT_1[playerid]>6)_OAB_CURRENT_TD_SLOT_1[playerid]=1;
		TextDrawSetString(_OAB_TD_SLOT_1[playerid],_OAB_GET_TEXTURE(_OAB_CURRENT_TD_SLOT_1[playerid]));
	    TextDrawShowForPlayer(playerid,_OAB_TD_SLOT_1[playerid]);
	}
    if( _OAB_PICKED[playerid][1] == false ) {
		_OAB_CURRENT_TD_SLOT_2[playerid]--;
	    if(_OAB_CURRENT_TD_SLOT_2[playerid]<1)_OAB_CURRENT_TD_SLOT_2[playerid]=6;
		TextDrawSetString(_OAB_TD_SLOT_2[playerid],_OAB_GET_TEXTURE(_OAB_CURRENT_TD_SLOT_2[playerid]));
	    TextDrawShowForPlayer(playerid,_OAB_TD_SLOT_2[playerid]);
	}
    if( _OAB_PICKED[playerid][2] == false ) {
		_OAB_CURRENT_TD_SLOT_3[playerid]++;
	    if(_OAB_CURRENT_TD_SLOT_3[playerid]>6)_OAB_CURRENT_TD_SLOT_3[playerid]=1;
		TextDrawSetString(_OAB_TD_SLOT_3[playerid],_OAB_GET_TEXTURE(_OAB_CURRENT_TD_SLOT_3[playerid]));
	    TextDrawShowForPlayer(playerid,_OAB_TD_SLOT_3[playerid]);
	}
    _OAB_TICKS[playerid]--;
    StartOABForPlayer(playerid);
	return true;
}

stock _OAB_GET_TEXTURE(id)
{
	new TextureName[20];
	if(id==1)TextureName="LD_SLOT:r_69";
	if(id==2)TextureName="LD_SLOT:grapes";
	if(id==3)TextureName="LD_SLOT:cherry";
	if(id==4)TextureName="LD_SLOT:bell";
	if(id==5)TextureName="LD_SLOT:bar2_o";
	if(id==6)TextureName="LD_SLOT:bar1_o";
	return TextureName;
}

OAB_OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	#pragma unused oldkeys
	if(_OAB_PlayerPlays[playerid]==true) {
	    if( newkeys & KEY_SPRINT ) {
			// Neustart
			if( _OAB_AUTORETRY[playerid] == true ) {
		        //StopOnArmedBanditForPlayer(playerid);
			    if( Spieler[playerid][pCash] < OAB_MONEY_AT_PLAYCOST ) {
     				SendClientMessage(playerid,COLOR_RED,"Du besitzt nicht genug Geld ( "#OAB_MONEY_AT_PLAYCOST "$ )um weiter am Banditen zu spielen");
			        return cmd_spielautomatstop(playerid,"");
			    }
		        SendClientMessage(playerid,COLOR_YELLOW,"Neuer Durchgang wird gestartet!");
			    ShowBuyInformation(playerid,"~r~-"#OAB_MONEY_AT_PLAYCOST"$");
				GivePlayerCash(playerid,-OAB_MONEY_AT_PLAYCOST);
				Biz[CasinoBiz_Index][bKasse] += OAB_MONEY_AT_PLAYCOST;
		        //
				_OAB_PlayerPlays[playerid]=true;
				_OAB_AUTORETRY[playerid]=false;
				_OAB_TICKS[playerid]=30;
				_OAB_PICKED[playerid][0] = false;
				_OAB_PICKED[playerid][1] = false;
				_OAB_PICKED[playerid][2] = false;
				_OAB_CURRENT_TD_SLOT_1[playerid]=random(5-2)+2;
				_OAB_CURRENT_TD_SLOT_2[playerid]=random(5-2)+2;
				_OAB_CURRENT_TD_SLOT_3[playerid]=random(5-2)+2;
			    StartOABForPlayer(playerid);
			    return 1;
			}
	        //SendClientMessage(playerid,COLOR_YELLOW,"OAB_OnPlayerKeyStateChange");
	        PlayerPlaySound(playerid,1054,0.0,0.0,0.0);
	        if( _OAB_PICKED[playerid][1] == false )  {
				_OAB_PICKED[playerid][1] = true;
				return 1;
			}
	        if( _OAB_PICKED[playerid][0] == false )  {
				_OAB_PICKED[playerid][0] = true;
				return 1;
			}
	        if( _OAB_PICKED[playerid][2] == false )  {
				_OAB_PICKED[playerid][2] = true;
				// Damit info für rerun sofort kommt
				if( random(3) == 0 ) {
				    // Ab und zu Nachricht senden,wie man das Spiel beenden kann
					SendClientMessage(playerid,COLOR_WHITE,"*Info: Drücke die Leertaste um weiter zu spielen oder /Spielautomatstop um aufzuhören");
				}
				_OAB_AUTORETRY[playerid] = true;
				return 1;
			}
			
	    }
		return 1;
	}
	return 0;
}

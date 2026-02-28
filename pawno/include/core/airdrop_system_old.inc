#include <YSI\y_hooks>

// Variables
new bool:AktDrop[MAX_PLAYERS];
new AirDropO[MAX_PLAYERS];
new Gewinn[MAX_PLAYERS];
new bool:Pause[MAX_PLAYERS];

new Float:RandomDrop[][] =
{
	{2588.5522,2428.1016,10.8203,5.0624}, // <== Nähe Rock Hotel
	{946.9341,1877.3815,10.8203,341.1042}, // <== Nähe Wheelman Base
	{-373.0914,1534.3586,75.3594,215.3994}, // <== Fernseherturm
	{-925.3245,1413.4336,29.8203,313.1753}, // <== Terrorbase
	{-1435.9821,839.1251,7.1875,5.5883}, // <== SF Nähe alte FBI Base
	{-952.9545,-446.3116,32.9683,219.5331}, // <== Nähe alte Wheelman Base
	{975.3647,-2144.8613,13.0938,167.6237} // <== LS neben Anglershop
};

// Forwards
forward StartDrop(playerid);
forward Loot(playerid);
forward FindAirDrop(playerid);
forward DropTimer(playerid);

// -------------

hook OnGameModeInit() {
	SetTimer("DropTimer", 60013, 1);
}

hook OnPlayerConnect(playerid) {
    Pause[playerid] = true;
}

hook OnPlayerUpdate(playerid) {
	if(AktDrop[playerid] == true) {
 		if(Pause[playerid] == true) {
            return 1;
        }
        new Float:ObjAP[3];
        GetDynamicObjectPos(AirDropO[playerid], ObjAP[0], ObjAP[1], ObjAP[2]);
        if(IsPlayerInRangeOfPoint(playerid, 10.0, ObjAP[0], ObjAP[1], ObjAP[2])) {
            if(IsAFightFaction(Spieler[playerid][pFraktion])) {
				CreateDynamic3DTextLabel(COLOR_HEX_GREEN"AirDrop\n"COLOR_HEX_WHITE"Tippe /Openad",COLOR_WHITE,ObjAP[0], ObjAP[1], ObjAP[2]+25, 3.0);
			}
        }
    }
	return 1;
}

// Commands

CMD:openad(playerid) {
    new Float:ObjAP[3];
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt!");
    if(Pause[playerid] == true) return SendClientMessage(playerid,COLOR_RED,"Es wurde kein Paket gedropt!");
    if(!IsAFightFaction(Spieler[playerid][pFraktion]))return SendClientMessage(playerid,COLOR_RED,"Du bist in keiner Gang/Mafia.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid,COLOR_RED,"Du öffnest bereits einen AirDrop!");
    GetDynamicObjectPos(AirDropO[playerid], ObjAP[0], ObjAP[1], ObjAP[2]);
	if (!IsPlayerInRangeOfPoint(playerid, 7.0 , ObjAP[0], ObjAP[1], ObjAP[2]))
        return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des AirDrops!");
    if(AktDrop[playerid] == true) {
        if(IsPlayerInRangeOfPoint(playerid, 10.0, ObjAP[0], ObjAP[1], ObjAP[2])) {
            ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Crouch_In", 4.0, 1, 0, 0, 0, 0);
            Gewinn[playerid] = SetTimerEx("Loot", 180000, false, "i", playerid); // <== 3 Minuten
            SetPVarInt(playerid, "OPEN.AIRDROP", 1);
        }
    }
	return 1;
}

CMD:gotoad(playerid) return cmd_gotoairdrop(playerid);

CMD:gotoairdrop(playerid) {
    new Float:ObjAP[3];
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt!");
    if(Spieler[playerid][pAdmin] < 4) return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die benötigten Rechte.");
    if(Pause[playerid] == true) return SendClientMessage(playerid,COLOR_RED,"Es wurde kein Paket gedropt!");
    GetDynamicObjectPos(AirDropO[playerid], ObjAP[0], ObjAP[1], ObjAP[2]);
	SetPlayerPos(playerid, ObjAP[0], ObjAP[1], ObjAP[2]);
	SendClientMessage(playerid,COLOR_GREEN,"Du hast dich zum AirDrop teleportiert.");
	return 1;
}

// -------------

public DropTimer(playerid) {
	new stunde, minute, sekunde;
	gettime(stunde, minute, sekunde);

	if(Pause[playerid] == true) {
	    if (stunde == 12 && minute == 1) {
        	SetTimer("StartDrop", 10, 0);
    	}

    	if (stunde == 18 && minute == 1) {
        	SetTimer("StartDrop", 10, 0);
    	}

    	if (stunde == 23 && minute == 1) {
        	SetTimer("StartDrop", 10, 0);
   		}
	}
	return 1;
}

public StartDrop(playerid) {
	new RandomV = random(sizeof(RandomDrop));
    AirDropO[playerid] = CreateDynamicObject(18849, RandomDrop[RandomV][0], RandomDrop[RandomV][1], RandomDrop[RandomV][2]+100, 0.0, 0.0, 0.0);
    MoveDynamicObject(AirDropO[playerid], RandomDrop[RandomV][0], RandomDrop[RandomV][1], RandomDrop[RandomV][2]+6, 3.0);

    for(new i=0;i<MAX_PLAYERS;i++) {
    	SetPlayerMapIcon(i, 37, RandomDrop[RandomV][0], RandomDrop[RandomV][1], RandomDrop[RandomV][2] , 37, -1, MAPICON_LOCAL);
    }
    
    new string[128], zoneText[MAX_ZONE_NAME];
    GetPoint2DZone(RandomDrop[RandomV][0], RandomDrop[RandomV][1], zoneText, sizeof(zoneText));
	format(string,sizeof(string),"[AIRDROP] "COLOR_HEX_WHITE"Ein AirDrop wurde soeben in %s gesichtet. Macht euch auf die Suche! (/openad)", zoneText);
	for(new i; i < MAX_PLAYERS; i++){
		if(IsAFightFaction(Spieler[playerid][pFraktion])) SendClientMessage(i, COLOR_YELLOW, string);
		//SendClientMessageToAll(COLOR_YELLOW,string);
   	}
    AktDrop[playerid] = true;
    Pause[playerid] = false;
    
    // Prüfen ob AirDrop gefunden wurde
    SetTimer("FindAirDrop", 900000, 0); // <== 15 Minuten
	return 1;
}

public FindAirDrop(playerid) {
	if(Pause[playerid] == false) {
	    new string[128], zoneText[MAX_ZONE_NAME], RandomV = random(sizeof(RandomDrop));
	    GetPoint2DZone(RandomDrop[RandomV][0], RandomDrop[RandomV][1], zoneText, sizeof(zoneText));
	    format(string,sizeof(string),"[AIRDROP] "COLOR_HEX_WHITE"Der AirDrop wurde noch nicht gefunden! Der Drop befindet sich in %s.",zoneText);
	    SendClientMessageToAll(COLOR_YELLOW,string);
	}
	return 1;
}

public Loot(playerid) {
	new money, wamount, damount, string[128], frak = Spieler[playerid][pFraktion];

    #if defined NEUE_WIRTSCHAFT
        money = floatround(RandomEx(60000, 120000) / 1, floatround_ceil);
        wamount = floatround(RandomEx(5000, 8000) / 1, floatround_ceil);
        damount = floatround(RandomEx(100, 200) / 1, floatround_ceil);
    #else
        money = floatround(RandomEx(300000, 400000) / 1, floatround_ceil);
        wamount = floatround(RandomEx(45000, 60000) / 1, floatround_ceil);
        damount = floatround(RandomEx(1000, 2000) / 1, floatround_ceil);
    #endif
    
    Spieler[playerid][pCash] += money;
    Spieler[playerid][pDrugs] += damount;
    Spieler[playerid][pWaffenteile] += wamount;
    SCMFormatted(playerid,COLOR_GREEN,"[AIRDROP] "COLOR_HEX_WHITE"Du erhälst vom AirDrop: $%s, %d Drogen & %s Waffenteile",AddDelimiters(money),damount,AddDelimiters(wamount));

	format(string,sizeof(string),"[AIRDROP] "COLOR_HEX_WHITE"%s der %s hat das Paket gefunden und geöffnet.",GetName(playerid),GetFactionNameOfFaction(frak));
	SendClientMessageToAll(COLOR_GREEN,string);

    KillTimer(Gewinn[playerid]);
    ClearAnimations(playerid);
    DestroyDynamicObject(AirDropO[playerid]);
    RemovePlayerMapIcon(playerid, 37);
    
    Pause[playerid] = true;
    DeletePVar(playerid, "OPEN.AIRDROP");
	return 1;
}

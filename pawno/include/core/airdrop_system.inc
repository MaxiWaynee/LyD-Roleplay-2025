#include <YSI\y_hooks>

// Variables
new bool:AktDrop = false;
new AirDropOpen = false;
new bool:AirDropWirdGeoeffnet = false;
new Gewinn[MAX_PLAYERS];

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
forward IsAliveTimer(playerid);

// -------------

hook OnGameModeInit() {
	SetTimer("DropTimer", 60013, 1);
}

hook OnPlayerUpdate(playerid) {
	if(AktDrop == true) {
        new Float:ObjAP[3];
        GetDynamicObjectPos(AirDropOpen, ObjAP[0], ObjAP[1], ObjAP[2]);
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
    if(AktDrop != true) return SendClientMessage(playerid,COLOR_RED,"Es wurde kein Paket gedropt!");
    //if(!IsAFightFaction(Spieler[playerid][pFraktion]))return SendClientMessage(playerid,COLOR_RED,"Du bist in keiner Gang/Mafia.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid,COLOR_RED,"Du öffnest bereits einen AirDrop!");
	if(AirDropWirdGeoeffnet == true) return SendClientMessage(playerid, COLOR_RED, "Der AirDrop wird bereits geöffnet!");
    GetDynamicObjectPos(AirDropOpen, ObjAP[0], ObjAP[1], ObjAP[2]);
	if (!IsPlayerInRangeOfPoint(playerid, 7.0 , ObjAP[0], ObjAP[1], ObjAP[2]))
        return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des AirDrops!");
    if(AktDrop == true) {
        if(IsPlayerInRangeOfPoint(playerid, 10.0, ObjAP[0], ObjAP[1], ObjAP[2])) {
            ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Crouch_In", 4.0, 1, 0, 0, 0, 0);
            Gewinn[playerid] = SetTimerEx("Loot", 180000, false, "i", playerid); // <== 3 Minuten
            SetPVarInt(playerid, "OPEN.AIRDROP", 1);
			new string[128], name[MAX_PLAYER_NAME];
			GetPlayerName(playerid, name, sizeof(name));
			AirDropWirdGeoeffnet = true;
			format(string,sizeof(string),"[AIRDROP] "COLOR_HEX_WHITE"%s öffnet gerade den AirDrop!", name);
			SendClientMessageToAll(COLOR_YELLOW, string);
			/*for(new i; i < MAX_PLAYERS; i++){
				if(IsAFightFaction(Spieler[playerid][pFraktion])) SendClientMessage(i, COLOR_YELLOW, string);
			}*/
        }
    }
	return 1;
}

CMD:gotoad(playerid) return cmd_gotoairdrop(playerid);

CMD:gotoairdrop(playerid) {
    new Float:ObjAP[3];
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt!");
    if(Spieler[playerid][pAdmin] < 4) return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die benötigten Rechte.");
    if(AktDrop == false) return SendClientMessage(playerid,COLOR_RED,"Es wurde kein Paket gedropt!");
    GetDynamicObjectPos(AirDropOpen, ObjAP[0], ObjAP[1], ObjAP[2]);
	SetPlayerPos(playerid, ObjAP[0], ObjAP[1], ObjAP[2]);
	SendClientMessage(playerid,COLOR_GREEN,"Du hast dich zum AirDrop teleportiert.");
	return 1;
}

// -------------

public DropTimer(playerid) {
	new stunde, minute, sekunde;
	gettime(stunde, minute, sekunde);

	if(AktDrop == false) {
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

CMD:startairdrop(playerid){
	if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt!");
    if(Spieler[playerid][pAdmin] < 4) return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die benötigten Rechte.");
	if(AktDrop == true) return SendClientMessage(playerid, COLOR_RED, "Es gibt bereits einen AirDrop auf der Map! (/gotoad)");
	AirDropWirdGeoeffnet = false;
	StartDrop(playerid);
	return 1;
}

public StartDrop(playerid) {
	new RandomV = random(sizeof(RandomDrop));
    AirDropOpen = CreateDynamicObject(18849, RandomDrop[RandomV][0], RandomDrop[RandomV][1], RandomDrop[RandomV][2]+100, 0.0, 0.0, 0.0);
    MoveDynamicObject(AirDropOpen, RandomDrop[RandomV][0], RandomDrop[RandomV][1], RandomDrop[RandomV][2]+6, 3.0);
	CreateDynamic3DTextLabel(COLOR_HEX_GREEN"AirDrop\n"COLOR_HEX_WHITE"Tippe /Openad",COLOR_WHITE,RandomDrop[RandomV][0], RandomDrop[RandomV][1], RandomDrop[RandomV][2], 3.0);
    
    new string[128], zoneText[MAX_ZONE_NAME];
    GetPoint2DZone(RandomDrop[RandomV][0], RandomDrop[RandomV][1], zoneText, sizeof(zoneText));
	format(string,sizeof(string),"[AIRDROP] "COLOR_HEX_WHITE"Ein AirDrop wurde soeben in %s gesichtet. Macht euch auf die Suche! (/openad)", zoneText);
	SendClientMessageToAll(COLOR_YELLOW, string);
	/*for(new i; i < MAX_PLAYERS; i++){
		if(IsAFightFaction(Spieler[playerid][pFraktion])) SendClientMessage(i, COLOR_YELLOW, string);
   	}*/
    AktDrop = true;
	AirDropWirdGeoeffnet = false;
    
    // Prüfen ob AirDrop gefunden wurde
    SetTimer("FindAirDrop", 900000, 0); // <== 15 Minuten
	return 1;
}

public FindAirDrop(playerid) {
	if(AktDrop == true) {
	    new string[128], zoneText[MAX_ZONE_NAME], Float:ObjAP[3];
		GetDynamicObjectPos(AirDropOpen, ObjAP[0], ObjAP[1], ObjAP[2]);
	    GetPoint2DZone(ObjAP[0], ObjAP[1], zoneText, sizeof(zoneText));
	    format(string,sizeof(string),"[AIRDROP] "COLOR_HEX_WHITE"Der AirDrop wurde noch nicht gefunden! Der Drop befindet sich in %s.",zoneText);
	    SendClientMessageToAll(COLOR_YELLOW,string);
	}
	return 1;
}
	

public Loot(playerid) {
	new money, wamount, damount, string[128];
    money = floatround(RandomEx(300000, 400000) / 1, floatround_ceil);
    wamount = floatround(RandomEx(5000, 10000) / 1, floatround_ceil);
    damount = floatround(RandomEx(1000, 2000) / 1, floatround_ceil);
    
    Spieler[playerid][pCash] += money;
    Spieler[playerid][pDrugs] += damount;
    Spieler[playerid][pWaffenteile] += wamount;
    SCMFormatted(playerid,COLOR_GREEN,"[AIRDROP] "COLOR_HEX_WHITE"Du erhälst vom AirDrop: $%s, %d Drogen & %s Waffenteile",AddDelimiters(money),damount,AddDelimiters(wamount));

	format(string,sizeof(string),"[AIRDROP] "COLOR_HEX_WHITE"%s hat das Paket gefunden und geöffnet.",GetName(playerid));
	SendClientMessageToAll(COLOR_GREEN,string);
	/*for(new i; i < MAX_PLAYERS; i++){
		if(IsAFightFaction(Spieler[playerid][pFraktion])) SendClientMessage(i, COLOR_GREEN, string);
   	}*/

    KillTimer(Gewinn[playerid]);
    ClearAnimations(playerid);
    DestroyDynamicObject(AirDropOpen);
    
    AktDrop = false;
    DeletePVar(playerid, "OPEN.AIRDROP");
	return 1;
}

#include <YSI\y_hooks>

#define MAX_GANG_BIZ MAX_BIZES * 0.75
#define Bizfightplayers 		2
#define BizfightDauer 			30
#define COLOR_BIZFIGHT 			0x00B9FFFF
#define COLOR_BIZEND 			0x00B9FFFF

new PlayerText:BizfightTD[5];
new BFKills[MAX_PLAYERS];
new BFZone[MAX_BIZES];
new InBiz[MAX_PLAYERS];

enum e_Bizfight {
    BF_Owner,
    BF_OKills,
    BF_Angreifer,
    BF_AKills,
	BF_BizfightEnd,
	BF_BizStatus,
	BF_Timeout,
	BF_Interior,
	BF_VW,
	Float:BF_X,
	Float:BF_Y,
	Float:BF_Z,
	BF_Aufgeber
};

new Bizfight[MAX_BIZES][e_Bizfight];

new const Float:g_BFZonen[][] = {
	{1362.9106,-1294.6874,1417.3877,-1259.7670},
	{2157.0095,935.5446,2183.6787,963.1585},
	{2364.7666,-2009.6293,2406.9431,-1979.6927},
	{-1674.1517,1186.6152,-1652.6349,1256.8090},
	{2099.1184,-1823.0129,2126.2610,-1783.0463},
	{1094.9370,-1461.7349,1107.3141,-1453.6051},
	{2322.5840,67.2046,2338.9685,81.8622},
	{2075.9141,2223.1689,2103.0032,2238.9143},
	{193.4010,-205.9983,224.0960,-180.1869},
	{2368.3723,2024.3041,2409.2888,2046.8221},
	{1093.3009,-1469.3987,1106.3281,-1471.5439},
	{2093.2244,2223.0586,2104.4958,2234.4421},
	{2382.0120,-1916.5403,2405.7969,-1896.7604},
	{2403.4446,-1515.6910,2422.4343,-1492.9803},
	{1860.8160,2067.5432,1889.8180,2101.0784},
	{1135.1421,2068.9207,1166.2394,2102.2722},
	{-2348.0676,-170.8914,-2318.9326,-136.7776},
	{790.1084,-1631.8663,817.7990,-1603.2517},
	{-1935.1423,800.0197,-1908.3822,832.3842},
	{1179.4363,-919.0278,1216.0493,-883.9724},
	{1304.7218,-903.4583,1330.7559,-872.8061},
	{1340.4861,-1773.9706,1381.4717,-1737.6305},
	{1830.9237,-1855.6125,1859.9662,-1832.8992},
	{2420.7957,-1759.9846,2449.2708,-1737.9216},
	{1151.0530,-1462.8049,1162.3243,-1451.2876},
	{2228.6123,-1682.6550,2255.8989,-1664.0844},
	{1651.6505,1726.8756,1677.7473,1762.0121},
	{2086.1035,2243.1252,2106.0662,2264.4866},
	{1446.4364,-1150.5209,1474.0841,-1111.5798},
	{2564.3035,1899.2137,2598.9395,1946.6064},
	{-1889.0826,856.7546,-1861.5068,882.3882},
	{0.0,0.0,0.0,0.0},
	{2084.2756,2217.3538,2105.1960,2242.6064},
	{-1702.3527,942.5436,-1659.7488,970.9777},
	{2797.4192,2420.3425,2825.4192,2448.3425},
	{457.4481,-1511.8589,488.8699,-1472.3226},
	{2072.6719,-1789.6521,2084.3625,-1775.7374},
	{893.0906,-1420.9255,909.7934,-1403.9867},
	{930.9816,-1774.5525,946.6342,-1759.4158},
	{1188.1759,-1055.3678,1209.1721,-1040.4855},
	{1569.0703,2607.9404,1587.6969,2629.5984},
	{1329.9075,-1271.5618,1341.1371,-1248.1290},
	{759.6984,-1356.9934,774.4193,-1338.3363},
	{1464.2885,-2422.0806,1476.6411,-2394.9673},
	{-80.0142,-563.9343,-68.7565,-546.9711},
	{2116.1294,-1137.7139,2150.9966,-1114.2444},
	{1801.1901,-1894.3745,1818.3129,-1871.6816},
	{210.1551,-1452.7914,223.7918,-1416.7920},
	{1004.6974,-1440.2267,1031.9315,-1419.3533},
	{2084.7788,1374.4282,2106.5977,1406.0504},
	{1828.7139,-2583.3411,1853.2848,-2561.0029},
	{1281.3895,1319.9309,1308.9095,1350.2341},
	{2497.7258,-1532.5216,2525.4053,-1511.2999},
	{-1505.3552,703.4977,-1472.9922,739.0321},
	{975.7883,-2006.6323,1012.2933,-1967.1794},
	{820.4074,-2053.7756,836.7900,-2026.3601},
	{674.0544,-1223.4957,702.0544,-1139.4957},
	{1488.5067,-1593.8578,1516.5067,-1551.8578},
	{1319.3705,-1566.5247,1361.3705,-1538.5247},
	{1827.6852,-1699.3843,1869.6852,-1671.3843},
	{2412.7839,-1231.6938,2440.7839,-1203.6938},
	{1797.9583,-1732.2338,1811.9680,-1704.1451},
	{1733.2415,-1590.2220,1748.5275,-1562.5718},
	{1185.3262,-1450.5781,1241.4011,-1408.2451},
	{-2554.3655,-682.1448,-2470.3557,-584.4087}
};

hook OnGameModeInit2() {
	for(new i; i < sizeof(g_BFZonen); i++) {
		if(i != 32) {
			BFZone[i] = GangZoneCreate(g_BFZonen[i][0],g_BFZonen[i][1],g_BFZonen[i][2],g_BFZonen[i][3]);
		}
	}
}


hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if(newkeys ==  KEY_SECONDARY_ATTACK) {
		new bizid = InBiz[playerid];
		if(bizid != 0 && !IsEnemyInZone(playerid)) {
			SetPlayerPosEx(playerid, Biz[bizid][EnterX], Biz[bizid][EnterY], Biz[bizid][EnterZ], 0, 0);
			InBiz[playerid] = 0;
		}
	}
	return 1;
}

hook OnPlayerConnect(playerid) {
	BizfightTD[0] = CreatePlayerTextDraw(playerid, 555.000000, 194.000000, "_");
	PlayerTextDrawFont(playerid, BizfightTD[0], 1);
	PlayerTextDrawLetterSize(playerid, BizfightTD[0], 0.591665, 8.550000);
	PlayerTextDrawTextSize(playerid, BizfightTD[0], 280.000000, 154.000000);
	PlayerTextDrawSetOutline(playerid, BizfightTD[0], 1);
	PlayerTextDrawSetShadow(playerid, BizfightTD[0], 0);
	PlayerTextDrawAlignment(playerid, BizfightTD[0], 2);
	PlayerTextDrawColor(playerid, BizfightTD[0], -1);
	PlayerTextDrawBackgroundColor(playerid, BizfightTD[0], 16711935);
	PlayerTextDrawBoxColor(playerid, BizfightTD[0], 55);
	PlayerTextDrawUseBox(playerid, BizfightTD[0], 1);
	PlayerTextDrawSetProportional(playerid, BizfightTD[0], 1);
	PlayerTextDrawSetSelectable(playerid, BizfightTD[0], 0);

	BizfightTD[1] = CreatePlayerTextDraw(playerid, 523.000000, 176.000000, "Bizfight");
	PlayerTextDrawFont(playerid, BizfightTD[1], 0);
	PlayerTextDrawLetterSize(playerid, BizfightTD[1], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, BizfightTD[1], 594.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BizfightTD[1], 1);
	PlayerTextDrawSetShadow(playerid, BizfightTD[1], 0);
	PlayerTextDrawAlignment(playerid, BizfightTD[1], 1);
	PlayerTextDrawColor(playerid, BizfightTD[1], 11862015);
	PlayerTextDrawBackgroundColor(playerid, BizfightTD[1], 255);
	PlayerTextDrawBoxColor(playerid, BizfightTD[1], 50);
	PlayerTextDrawUseBox(playerid, BizfightTD[1], 0);
	PlayerTextDrawSetProportional(playerid, BizfightTD[1], 1);
	PlayerTextDrawSetSelectable(playerid, BizfightTD[1], 0);

	BizfightTD[2] = CreatePlayerTextDraw(playerid, 480.000000, 200.000000, "~w~Biz: Name~n~~n~~y~Verteidiger: Name~n~~n~~w~Angreifer: Name");
	PlayerTextDrawFont(playerid, BizfightTD[2], 1);
	PlayerTextDrawLetterSize(playerid, BizfightTD[2], 0.229166, 1.200000);
	PlayerTextDrawTextSize(playerid, BizfightTD[2], 641.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BizfightTD[2], 1);
	PlayerTextDrawSetShadow(playerid, BizfightTD[2], 0);
	PlayerTextDrawAlignment(playerid, BizfightTD[2], 1);
	PlayerTextDrawColor(playerid, BizfightTD[2], -1);
	PlayerTextDrawBackgroundColor(playerid, BizfightTD[2], 255);
	PlayerTextDrawBoxColor(playerid, BizfightTD[2], 50);
	PlayerTextDrawUseBox(playerid, BizfightTD[2], 0);
	PlayerTextDrawSetProportional(playerid, BizfightTD[2], 1);
	PlayerTextDrawSetSelectable(playerid, BizfightTD[2], 0);

	BizfightTD[3] = CreatePlayerTextDraw(playerid, 586.000000, 222.000000, "~g~Kills: Kills~n~~n~Kills: Kills");
	PlayerTextDrawFont(playerid, BizfightTD[3], 1);
	PlayerTextDrawLetterSize(playerid, BizfightTD[3], 0.229166, 1.200000);
	PlayerTextDrawTextSize(playerid, BizfightTD[3], 625.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BizfightTD[3], 1);
	PlayerTextDrawSetShadow(playerid, BizfightTD[3], 0);
	PlayerTextDrawAlignment(playerid, BizfightTD[3], 1);
	PlayerTextDrawColor(playerid, BizfightTD[3], -1);
	PlayerTextDrawBackgroundColor(playerid, BizfightTD[3], 255);
	PlayerTextDrawBoxColor(playerid, BizfightTD[3], 50);
	PlayerTextDrawUseBox(playerid, BizfightTD[3], 0);
	PlayerTextDrawSetProportional(playerid, BizfightTD[3], 1);
	PlayerTextDrawSetSelectable(playerid, BizfightTD[3], 0);

	BizfightTD[4] = CreatePlayerTextDraw(playerid, 530.000000, 256.000000, "~w~Zeit: Zeit");
	PlayerTextDrawFont(playerid, BizfightTD[4], 1);
	PlayerTextDrawLetterSize(playerid, BizfightTD[4], 0.266665, 1.500000);
	PlayerTextDrawTextSize(playerid, BizfightTD[4], 630.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BizfightTD[4], 1);
	PlayerTextDrawSetShadow(playerid, BizfightTD[4], 0);
	PlayerTextDrawAlignment(playerid, BizfightTD[4], 1);
	PlayerTextDrawColor(playerid, BizfightTD[4], -1);
	PlayerTextDrawBackgroundColor(playerid, BizfightTD[4], 255);
	PlayerTextDrawBoxColor(playerid, BizfightTD[4], 50);
	PlayerTextDrawUseBox(playerid, BizfightTD[4], 0);
	PlayerTextDrawSetProportional(playerid, BizfightTD[4], 1);
	PlayerTextDrawSetSelectable(playerid, BizfightTD[4], 0);
	BFKills[playerid] = 0;
	return 1;
}


hook OnPlayerSpawn(playerid) {
	if(HasBizfight(Spieler[playerid][pFraktion])) {
		PlayerTextDrawShow(playerid, BizfightTD[0]);
		PlayerTextDrawShow(playerid, BizfightTD[1]);
		PlayerTextDrawShow(playerid, BizfightTD[2]);
		PlayerTextDrawShow(playerid, BizfightTD[3]);
		PlayerTextDrawShow(playerid, BizfightTD[4]);
		InBiz[playerid] = 0;
	}
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
	PlayerTextDrawDestroy(playerid, BizfightTD[0]);
	PlayerTextDrawDestroy(playerid, BizfightTD[1]);
	PlayerTextDrawDestroy(playerid, BizfightTD[2]);
	PlayerTextDrawDestroy(playerid, BizfightTD[3]);
	PlayerTextDrawDestroy(playerid, BizfightTD[4]);
	BFKills[playerid] = 0;
	return 1;
}

forward BF_OnPlayerDeath(playerid,killerid,reason);
public BF_OnPlayerDeath(playerid, killerid, reason) {
	#pragma unused reason
	if( killerid != INVALID_PLAYER_ID ) {
		if(IsAFightFaction(Spieler[playerid][pFraktion])) {
			if(HasBizfight(Spieler[playerid][pFraktion])) {
				new b = GetBizfightID(Spieler[playerid][pFraktion]);
				new string[128];
				if(GetPlayerVirtualWorld(playerid) == Bizfight[b][BF_VW] && GetPlayerVirtualWorld(killerid) == Bizfight[b][BF_VW]) {
					if(Spieler[playerid][pFraktion] == Spieler[killerid][pFraktion]) {
						if(Spieler[killerid][pFraktion] == Bizfight[b][BF_Angreifer]) {
							format(string,sizeof(string),"->TEAMKILL<- {FF8800}%s hat seinen Partner %s im Bizfight getötet! {00CC00}(2P. an die %s)",GetName(killerid),GetName(playerid),GetFactionName(Bizfight[b][BF_Owner]));
							SendFraktionMessage(Bizfight[b][BF_Owner],COLOR_ORANGE,string);
							Bizfight[b][BF_AKills] -= 2;
						} else {
							format(string,sizeof(string),"->TEAMKILL<- {FF8800}%s hat seinen Partner %s im Bizfight getötet! {00CC00}(2P. an die %s)",GetName(killerid),GetName(playerid),GetFactionName(Bizfight[b][BF_Angreifer]));
							SendFraktionMessage(Bizfight[b][BF_Angreifer],COLOR_ORANGE,string);
							Bizfight[b][BF_OKills] -= 2;
						}
						GameTextForPlayer(killerid, "~r~TEAMKILL",1550,6);
					}
					if(Spieler[killerid][pFraktion] == Bizfight[b][BF_Angreifer]) Bizfight[b][BF_AKills] ++;
					if(Spieler[killerid][pFraktion] == Bizfight[b][BF_Owner]) Bizfight[b][BF_OKills] ++;
					Spieler[killerid][pKills] ++;
					BFKills[killerid] ++;
					Spieler[playerid][pTotTime] = 15;
					InBiz[playerid] = 0;
					format(string,sizeof(string),"->BIZFIGHTKILL<- {FF6C1B}%s Bizfightkill an %s {00CC00}(1 Kill an die %s)",GetName(killerid),GetName(playerid),GetFactionNameOfFaction(Spieler[killerid][pFraktion]));
					SendFraktionMessage( Spieler[killerid][pFraktion],COLOR_BIZFIGHT,string);
					SendFraktionMessage( Spieler[playerid][pFraktion],COLOR_BIZFIGHT,string);
					GameTextForPlayer(killerid, "~g~BIZFIGHTKILL + 5000$",1550,6);
					Spieler[killerid][pCash] += 5000;
					return 1;
				}
			}
		}
	}
	return 0;
}



CMD:bizfight(playerid,params[]) {
    new frak = GetPlayerFaction(playerid), String[128], b = IsPlayerAtBiz(playerid),besitzer = Biz[b][bErpresserFraktion];
    if ( b == 999) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keinem Geschäft");
    if ( !IsAFightFaction( frak ) ) return SendClientMessage(playerid, COLOR_RED, "Du bist in keiner DM Fraktion.");
    if ( Spieler[playerid][pRank] < 4 ) return SendClientMessage(playerid, COLOR_RED, "Diese Funktion kann erst als Ausbilder verfügbar.");
    if ( besitzer == frak) return SendClientMessage(playerid, COLOR_RED, "Dieses Geschäft ist bereits im Besitz deiner Fraktion.");
    if ( GetErpresserCount(frak) >= MAX_GANG_BIZ )return SendClientMessage(playerid, COLOR_RED, "Deine Fraktion hat das Biz-Limit erreicht.");
	if ( IsGangInFight(frak)) return SendClientMessage(playerid, COLOR_RED, "Deine Gang befindet sich zur Zeit in einem Gangfight.");
    if ( IsGangInFight(besitzer)) return SendClientMessage(playerid, COLOR_RED, "Die Gang ist bereits in einem Gangfight involviert.");
    if ( HasBizfight(frak)) return SendClientMessage(playerid, COLOR_RED, "Deine Gang befindet sich zur Zeit in einem Bizfight.");
    if ( HasBizfight(besitzer)) return SendClientMessage(playerid, COLOR_RED, "Die Gang ist bereits in einem Bizfight involviert.");
	if ( GetFactionOnlinePlayers(frak) < Bizfightplayers) return SCMFormatted(playerid, COLOR_RED, "Es müssen mindestens %d Gangmitglieder deiner Fraktion online sein.", Bizfightplayers);
	if ( GetFactionOnlinePlayers(besitzer) < Bizfightplayers) return SCMFormatted(playerid, COLOR_RED, "Es müssen mindestens %d Gangmitglieder der Gegnerischen Fraktion online sein.", Bizfightplayers);
	if ( Bizfight[b][BF_Timeout] > gettime()) return SendClientMessage(playerid,COLOR_RED,"Dieses Biz hat noch eine Zeitsperre.");
	if ( Bizfight[b][BF_BizStatus] == 1)return SendClientMessage(playerid, COLOR_RED, "Hier läuft bereits ein Bizfight.");
	if (gangfightpause[frak] >= gettime()) return SendClientMessage(playerid,COLOR_RED,"Ihr habt eine 10 minütige Bizfightpause, da ihr vor kurzem einen Bizfight hattet.");
    if (gangfightpause[besitzer] >= gettime()) return SCMFormatted(playerid, COLOR_RED, "Die %s kann nicht angegriffen werden, da sie vor 10 Minuten zuletzt einen Bizfight hatten.",\
    GetFactionNameOfFaction(besitzer));
	new interior, Float:Pos[3]; 
	GetBizInterior(b,interior, Pos[0], Pos[1], Pos[2]);
	Bizfight[b][BF_Owner] = besitzer;
	Bizfight[b][BF_Angreifer] = frak;
	Bizfight[b][BF_OKills] = 0;
	Bizfight[b][BF_AKills] = 0;
	Bizfight[b][BF_BizStatus] = 1;
	Bizfight[b][BF_Interior] = interior;
	Bizfight[b][BF_VW] = Biz[b][bID] + 100;
	Bizfight[b][BF_X] = Pos[0];
	Bizfight[b][BF_Y] = Pos[1];
	Bizfight[b][BF_Z] = Pos[2];
	Bizfight[b][BF_BizfightEnd] = gettime() + BizfightDauer * 60;
	new bizzone = Biz[b][bID]-1;
	GangZoneShowForAll(BFZone[bizzone],GetZoneColorOfFaction( Bizfight[b][BF_Owner] ));
    GangZoneFlashForAll(BFZone[bizzone], GetZoneColorOfFaction( Bizfight[b][BF_Angreifer] ));
	foreach(new i : Player) {
		if(Spieler[i][pFraktion] == frak || Spieler[i][pFraktion] == besitzer) {
			new secs_left = Bizfight[b][BF_BizfightEnd] - gettime(),
			sec, minute, hour;
			ConvertSec(secs_left,sec,minute,hour);
			PlayerTextDrawShow(i, BizfightTD[0]);
			PlayerTextDrawShow(i, BizfightTD[1]);
			PlayerTextDrawShow(i, BizfightTD[2]);
			PlayerTextDrawShow(i, BizfightTD[3]);
			PlayerTextDrawShow(i, BizfightTD[4]);
			format(String,sizeof(String),"~w~Biz: %s~n~~n~~y~Verteidiger: %s~n~~n~~w~Angreifer: %s",Biz[b][bName],GetFactionName(Bizfight[b][BF_Owner]),GetFactionName(Bizfight[b][BF_Angreifer]));
			PlayerTextDrawSetString(playerid, BizfightTD[2], String);
			format(String,sizeof(String),"~g~Kills: %d~n~~n~Kills: %d",Bizfight[b][BF_OKills],Bizfight[b][BF_AKills]);
			PlayerTextDrawSetString(playerid, BizfightTD[3], String);
			format(String,sizeof(String),"~w~Zeit: %02d:%02d",minute,sec);
			PlayerTextDrawSetString(playerid, BizfightTD[4], String);
		}
	}
	format(String,sizeof(String),"Deine Fraktion startet einen Bizfight gegen die %s im Biz %s.",GetFactionName(besitzer),Biz[b][bName]);
    SendFraktionMessage(frak, COLOR_BIZFIGHT, String);
	format(String,sizeof(String),"Die %s startet einen Bizfight gegen euch im Biz %s.",GetFactionName(frak),Biz[b][bName]);
    SendFraktionMessage(besitzer, COLOR_BIZFIGHT, String);
	format(String,sizeof(String),"Die %s startet einen Bizfight gegen die %s im Biz %s. Der Kampf dauert " #BizfightDauer " Minuten.",GetFactionName(frak),GetFactionName(besitzer),Biz[b][bName]);
    SendClientMessageToAll(COLOR_BIZEND, String);
	SetTimerEx("Pulse_Bizfight",1000,false,"d",b);
    return 1;
}


CMD:bfinfo(playerid) return cmd_bizfightinfo(playerid);
CMD:bizfightinfo(playerid) {
    new string[400], bool:BizfightRunning = false;
    for(new i=1;i<MAX_BIZES;i++) {
        if(Bizfight[i][BF_Angreifer]!=0) {
            new wartime;
            wartime=gettime()-Bizfight[i][BF_BizfightEnd];
			format(string,400,"Biz: %s, %s (%i Kills) vs. %s (%i Kills), Bizfightende: in %02i:%02i Minuten.",Biz[i][bName],
			GetFactionNameOfFaction(Bizfight[i][BF_Angreifer]),Bizfight[i][BF_AKills],
			GetFactionNameOfFaction(Bizfight[i][BF_Owner]),Bizfight[i][BF_OKills], floatround(-wartime / 60, floatround_floor), floatround(-wartime % 60, floatround_floor));
			SendClientMessage(playerid,COLOR_YELLOW,string);
			BizfightRunning = true;
        }
    }
    if (!BizfightRunning) SendClientMessage(playerid, COLOR_YELLOW, "Zur Zeit läuft kein Bizfight.");
    return 1;
}

CMD:bfstop(playerid) return cmd_bizfightstop(playerid);
CMD:bizfightstop(playerid) {
	if(Spieler[playerid][pRank] < 4) return SendClientMessage(playerid,COLOR_RED,"Du benötigst mindestens Rank 4 um aufzugeben.");
	if(!HasBizfight(Spieler[playerid][pFraktion])) return SendClientMessage(playerid, COLOR_RED, "Deine Gang befindet sich zur Zeit in keinem Bizfight.");
	if(HasBizfight(Spieler[playerid][pFraktion])) {
		new b = GetBizfightID(Spieler[playerid][pFraktion]);
		if(Spieler[playerid][pFraktion] == Bizfight[b][BF_Angreifer]) {
			Bizfight[b][BF_AKills] = -1;
			Bizfight[b][BF_BizfightEnd] = gettime();
			Bizfight[b][BF_Aufgeber] = Bizfight[b][BF_Angreifer];
		} else {
			if(Spieler[playerid][pFraktion] == Bizfight[b][BF_Owner]) {
				Bizfight[b][BF_OKills] = -1;
				Bizfight[b][BF_BizfightEnd] = gettime();
				Bizfight[b][BF_Aufgeber] = Bizfight[b][BF_Owner];
			}
		}
	}
	return 1;
}

CMD:setbizowner(playerid,params[]) {
	new bizid,fraktion[32],string[128];
    if(Spieler[playerid][pAdmin] < 3 && !Spieler[playerid][pFV]) return ERROR_RANG_MSG(playerid);
    if(sscanf(params,"ds[32]",bizid,fraktion)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Setbizowner [BizID] [Fraktion]");
	new bizzid = GetBizIndexByID(bizid);
    if (bizzid < 1 || bizzid >= MAX_BIZES) return SendClientMessage(playerid, COLOR_RED, "Keine gültige Biz-ID.");
	if (Bizfight[bizzid][BF_BizStatus] == 1) return SendClientMessage(playerid, COLOR_RED, "In dem Biz findet gerade ein Bizfight statt.");
	new BID = GetGangFactionIDByName(fraktion);
	Biz[bizzid][bErpresserFraktion] = BID;
	format(string,sizeof(string),"%s %s hat das Biz %s auf die Fraktion %s übertragen.",GetPlayerAdminRang(playerid),GetName(playerid),Biz[bizzid][bName],GetFactionName(BID));
	SendAdminMessage(COLOR_GREEN,string);
	UpdateBizText(bizzid);
	return 1;
}



forward Pulse_Bizfight(bizid);
public Pulse_Bizfight(bizid) {
	if(Bizfight[bizid][BF_BizStatus] == 1) {
		if(gettime() < Bizfight[bizid][BF_BizfightEnd]) {
			new secs_left = Bizfight[bizid][BF_BizfightEnd] - gettime(),
			sec, minute, hour;
			new String[128];
			ConvertSec(secs_left,sec,minute,hour);
			foreach(new i : Player) {
				if(Spieler[i][pFraktion] == Bizfight[bizid][BF_Owner] || Spieler[i][pFraktion] == Bizfight[bizid][BF_Angreifer]) {
					format(String,sizeof(String),"~w~Biz: %s~n~~n~~y~Verteidiger: %s~n~~n~~w~Angreifer: %s",Biz[bizid][bName],GetFactionName(Bizfight[bizid][BF_Owner]),GetFactionName(Bizfight[bizid][BF_Angreifer]));
					PlayerTextDrawSetString(i, BizfightTD[2], String);
					format(String,sizeof(String),"~g~Kills: %d~n~~n~Kills: %d",Bizfight[bizid][BF_OKills],Bizfight[bizid][BF_AKills]);
					PlayerTextDrawSetString(i, BizfightTD[3], String);
					format(String,sizeof(String),"~w~Zeit: %02d:%02d",minute,sec);
					PlayerTextDrawSetString(i, BizfightTD[4], String);
				}
			}
			SetTimerEx("Pulse_Bizfight",1000,false,"d",bizid);
		}
		else
		{
			if(Bizfight[bizid][BF_BizStatus] == 1) {
				new String[128],winner,loser,score;
				if( Bizfight[bizid][BF_AKills] > Bizfight[bizid][BF_OKills]) {
                    winner = Bizfight[bizid][BF_Angreifer];
                    loser = Bizfight[bizid][BF_Owner];
                    score = Bizfight[bizid][BF_AKills];
                }
                else if( Bizfight[bizid][BF_AKills] <= Bizfight[bizid][BF_OKills]) {
                    loser = Bizfight[bizid][BF_Angreifer];
                    winner = Bizfight[bizid][BF_Owner];
                    score = Bizfight[bizid][BF_OKills];
                }
				gangfightpause[loser]=gettime()+600;
				gangfightpause[winner]=gettime()+600;
				new AKiller = GetBizfightKiller(Bizfight[bizid][BF_Angreifer]);
				new OKiller = GetBizfightKiller(Bizfight[bizid][BF_Owner]);
				new bizzone = Biz[bizid][bID]-1;
				GangZoneStopFlashForAll(BFZone[bizzone]);
				GangZoneHideForAll(BFZone[bizzone]);
				Bizfight[bizid][BF_Owner] = winner;
				Bizfight[bizid][BF_Angreifer] = 0;
				Bizfight[bizid][BF_OKills] = 0;
				Bizfight[bizid][BF_AKills] = 0;
				Bizfight[bizid][BF_BizStatus] = 0;
				Bizfight[bizid][BF_BizfightEnd] = 0;
				Bizfight[bizid][BF_Timeout] = gettime()+ 90 * 60;
				Biz[bizid][bErpresserFraktion] = winner;
				g_fraktion[winner][Fr_Fraktionspunkte] += 3;
				UpdateBizText(bizid);
				if(Bizfight[bizid][BF_Aufgeber] != 0) {
					format(String,sizeof(String),"->BIZFIGHT<- {FFFFFF}Die %s hat den Bizfight aufgegeben!",GetFactionNameOfFaction(loser));
					SendFraktionMessage(winner,COLOR_BIZFIGHT,String);
					SendFraktionMessage(loser,COLOR_BIZFIGHT,String);
					Bizfight[bizid][BF_Aufgeber] = 0;
				} else {
					format(String,sizeof(String),"->BIZFIGHT<- {FFFFFF}Die %s hat den Bizfight mit %d Kills gewonnen!",GetFactionNameOfFaction(winner),score);
					SendFraktionMessage(winner,COLOR_BIZFIGHT,String);
					SendFraktionMessage(loser,COLOR_BIZFIGHT,String);
				}
				format(String,sizeof(String),"->BIZFIGHT<- {00FF00}3 Fraktionspunkte und das Biz gehen an die %s.",GetFactionNameOfFaction(winner));
				SendFraktionMessage(winner,COLOR_BIZFIGHT,String);
				SendFraktionMessage(loser,COLOR_BIZFIGHT,String);
				format(String,sizeof(String),"[BIZFIGHT-MELDUNG] {FFFFFF}Die %s haben den Bizfight mit %d Kills gegen die %s gewonnen!",GetFactionNameOfFaction(winner),score,GetFactionNameOfFaction(loser));
				SendClientMessageToAll(COLOR_BIZEND, String);
				format(String,sizeof(String),"->BIZFIGHT<- %s aus der %s hat mit %d die meisten Kills gemacht.",GetName(AKiller),GetFactionNameOfFaction(Spieler[AKiller][pFraktion]),BFKills[AKiller]);
				SendClientMessageToAll(COLOR_BIZEND, String);
				format(String,sizeof(String),"->BIZFIGHT<- %s aus der %s hat mit %d die meisten Kills gemacht.",GetName(OKiller),GetFactionNameOfFaction(Spieler[OKiller][pFraktion]),BFKills[OKiller]);
				SendClientMessageToAll(COLOR_BIZEND, String);
				foreach(new i : Player) {
					if(Spieler[i][pFraktion] == winner || Spieler[i][pFraktion] == loser) {
						PlayerTextDrawHide(i, BizfightTD[0]);
						PlayerTextDrawHide(i, BizfightTD[1]);
						PlayerTextDrawHide(i, BizfightTD[2]);
						PlayerTextDrawHide(i, BizfightTD[3]);
						PlayerTextDrawHide(i, BizfightTD[4]);
						BFKills[i] = 0;
					}
				}
			}
		}
	}
	return 1;
}

forward GetBizInterior(biz, &interior, &Float:PositionX, &Float:PositionY, &Float:PositionZ);
public GetBizInterior(biz, &interior, &Float:PositionX, &Float:PositionY, &Float:PositionZ) {
	new bizid = Biz[biz][bID];
	new randomspawn = RandomEx(1,10);
	switch(bizid) {
		case 1: {
			interior = 7;
			switch(randomspawn) {
				case 1: {
					PositionX = 309.3210, PositionY = -136.1402, PositionZ = 999.6016;
				}
				case 2: {
					PositionX = 315.2621, PositionY = -143.2986, PositionZ = 999.6016;
				}
				case 3: {
					PositionX = 304.3624, PositionY = -142.6148, PositionZ = 999.6016;
				}
				case 4: {
					PositionX = 314.1216, PositionY = -131.6274, PositionZ = 999.6083;
				}
				case 5: {
					PositionX = 304.7501, PositionY = -127.6551, PositionZ = 999.6016;
				}
				case 6: {
					PositionX = 315.8395, PositionY = -127.4412, PositionZ = 1004.0625;
				}
				case 7: {
					PositionX = 308.9130, PositionY = -133.0836, PositionZ = 1004.0625;
				}
				case 8: {
					PositionX = 306.3470, PositionY = -142.0527, PositionZ = 1004.0547;
				}
				case 9: {
					PositionX = 315.1932, PositionY = -142.8452, PositionZ = 1004.0625;
				}
				case 10: {
					PositionX = 308.9157, PositionY = -136.2452, PositionZ = 1004.0625;
				}
			}
		}
		case 2: {
			interior = 7;
			switch(randomspawn) {
				case 1: {
					PositionX = 309.3210, PositionY = -136.1402, PositionZ = 999.6016;
				}
				case 2: {
					PositionX = 315.2621, PositionY = -143.2986, PositionZ = 999.6016;
				}
				case 3: {
					PositionX = 304.3624, PositionY = -142.6148, PositionZ = 999.6016;
				}
				case 4: {
					PositionX = 314.1216, PositionY = -131.6274, PositionZ = 999.6083;
				}
				case 5: {
					PositionX = 304.7501, PositionY = -127.6551, PositionZ = 999.6016;
				}
				case 6: {
					PositionX = 315.8395, PositionY = -127.4412, PositionZ = 1004.0625;
				}
				case 7: {
					PositionX = 308.9130, PositionY = -133.0836, PositionZ = 1004.0625;
				}
				case 8: {
					PositionX = 306.3470, PositionY = -142.0527, PositionZ = 1004.0547;
				}
				case 9: {
					PositionX = 315.1932, PositionY = -142.8452, PositionZ = 1004.0625;
				}
				case 10: {
					PositionX = 308.9157, PositionY = -136.2452, PositionZ = 1004.0625;
				}
			}
		}
		case 3: {
			interior = 7;
			switch(randomspawn) {
				case 1: {
					PositionX = 309.3210, PositionY = -136.1402, PositionZ = 999.6016;
				}
				case 2: {
					PositionX = 315.2621, PositionY = -143.2986, PositionZ = 999.6016;
				}
				case 3: {
					PositionX = 304.3624, PositionY = -142.6148, PositionZ = 999.6016;
				}
				case 4: {
					PositionX = 314.1216, PositionY = -131.6274, PositionZ = 999.6083;
				}
				case 5: {
					PositionX = 304.7501, PositionY = -127.6551, PositionZ = 999.6016;
				}
				case 6: {
					PositionX = 315.8395, PositionY = -127.4412, PositionZ = 1004.0625;
				}
				case 7: {
					PositionX = 308.9130, PositionY = -133.0836, PositionZ = 1004.0625;
				}
				case 8: {
					PositionX = 306.3470, PositionY = -142.0527, PositionZ = 1004.0547;
				}
				case 9: {
					PositionX = 315.1932, PositionY = -142.8452, PositionZ = 1004.0625;
				}
				case 10: {
					PositionX = 308.9157, PositionY = -136.2452, PositionZ = 1004.0625;
				}
			}
		}
		case 4: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 5: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 372.1386, PositionY = -133.1398, PositionZ = 1001.4922;
				}
				case 2: {
					PositionX = 377.9659, PositionY = -132.8562, PositionZ = 1001.4922;
				}
				case 3: {
					PositionX = 369.2527, PositionY = -128.4055, PositionZ = 1001.4995;
				}
				case 4: {
					PositionX = 367.5687, PositionY = -119.7031, PositionZ = 1001.4922;
				}
				case 5: {
					PositionX = 379.8543, PositionY = -119.4254, PositionZ = 1001.4922;
				}
				case 6: {
					PositionX = 377.8043, PositionY = -126.8933, PositionZ = 1001.4922;
				}
				case 7: {
					PositionX = 369.3436, PositionY = -116.2476, PositionZ = 1001.4922;
				}
				case 8: {
					PositionX = 373.4267, PositionY = -114.4623, PositionZ = 1001.4922;
				}
				case 9: {
					PositionX = 378.5029, PositionY = -114.9355, PositionZ = 1001.4922;
				}
				case 10: {
					PositionX = 374.0859, PositionY = -124.1691, PositionZ = 1001.4922;
				}
			}
		}
		case 6: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 372.1386, PositionY = -133.1398, PositionZ = 1001.4922;
				}
				case 2: {
					PositionX = 377.9659, PositionY = -132.8562, PositionZ = 1001.4922;
				}
				case 3: {
					PositionX = 369.2527, PositionY = -128.4055, PositionZ = 1001.4995;
				}
				case 4: {
					PositionX = 367.5687, PositionY = -119.7031, PositionZ = 1001.4922;
				}
				case 5: {
					PositionX = 379.8543, PositionY = -119.4254, PositionZ = 1001.4922;
				}
				case 6: {
					PositionX = 377.8043, PositionY = -126.8933, PositionZ = 1001.4922;
				}
				case 7: {
					PositionX = 369.3436, PositionY = -116.2476, PositionZ = 1001.4922;
				}
				case 8: {
					PositionX = 373.4267, PositionY = -114.4623, PositionZ = 1001.4922;
				}
				case 9: {
					PositionX = 378.5029, PositionY = -114.9355, PositionZ = 1001.4922;
				}
				case 10: {
					PositionX = 374.0859, PositionY = -124.1691, PositionZ = 1001.4922;
				}
			}
		}
		case 7: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 372.1386, PositionY = -133.1398, PositionZ = 1001.4922;
				}
				case 2: {
					PositionX = 377.9659, PositionY = -132.8562, PositionZ = 1001.4922;
				}
				case 3: {
					PositionX = 369.2527, PositionY = -128.4055, PositionZ = 1001.4995;
				}
				case 4: {
					PositionX = 367.5687, PositionY = -119.7031, PositionZ = 1001.4922;
				}
				case 5: {
					PositionX = 379.8543, PositionY = -119.4254, PositionZ = 1001.4922;
				}
				case 6: {
					PositionX = 377.8043, PositionY = -126.8933, PositionZ = 1001.4922;
				}
				case 7: {
					PositionX = 369.3436, PositionY = -116.2476, PositionZ = 1001.4922;
				}
				case 8: {
					PositionX = 373.4267, PositionY = -114.4623, PositionZ = 1001.4922;
				}
				case 9: {
					PositionX = 378.5029, PositionY = -114.9355, PositionZ = 1001.4922;
				}
				case 10: {
					PositionX = 374.0859, PositionY = -124.1691, PositionZ = 1001.4922;
				}
			}
		}
		case 8: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 372.1386, PositionY = -133.1398, PositionZ = 1001.4922;
				}
				case 2: {
					PositionX = 377.9659, PositionY = -132.8562, PositionZ = 1001.4922;
				}
				case 3: {
					PositionX = 369.2527, PositionY = -128.4055, PositionZ = 1001.4995;
				}
				case 4: {
					PositionX = 367.5687, PositionY = -119.7031, PositionZ = 1001.4922;
				}
				case 5: {
					PositionX = 379.8543, PositionY = -119.4254, PositionZ = 1001.4922;
				}
				case 6: {
					PositionX = 377.8043, PositionY = -126.8933, PositionZ = 1001.4922;
				}
				case 7: {
					PositionX = 369.3436, PositionY = -116.2476, PositionZ = 1001.4922;
				}
				case 8: {
					PositionX = 373.4267, PositionY = -114.4623, PositionZ = 1001.4922;
				}
				case 9: {
					PositionX = 378.5029, PositionY = -114.9355, PositionZ = 1001.4922;
				}
				case 10: {
					PositionX = 374.0859, PositionY = -124.1691, PositionZ = 1001.4922;
				}
			}
		}
		case 9: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 372.1386, PositionY = -133.1398, PositionZ = 1001.4922;
				}
				case 2: {
					PositionX = 377.9659, PositionY = -132.8562, PositionZ = 1001.4922;
				}
				case 3: {
					PositionX = 369.2527, PositionY = -128.4055, PositionZ = 1001.4995;
				}
				case 4: {
					PositionX = 367.5687, PositionY = -119.7031, PositionZ = 1001.4922;
				}
				case 5: {
					PositionX = 379.8543, PositionY = -119.4254, PositionZ = 1001.4922;
				}
				case 6: {
					PositionX = 377.8043, PositionY = -126.8933, PositionZ = 1001.4922;
				}
				case 7: {
					PositionX = 369.3436, PositionY = -116.2476, PositionZ = 1001.4922;
				}
				case 8: {
					PositionX = 373.4267, PositionY = -114.4623, PositionZ = 1001.4922;
				}
				case 9: {
					PositionX = 378.5029, PositionY = -114.9355, PositionZ = 1001.4922;
				}
				case 10: {
					PositionX = 374.0859, PositionY = -124.1691, PositionZ = 1001.4922;
				}
			}
		}
		case 10: {
			interior = 1;
			switch(randomspawn) {
				case 1: {
					PositionX = 963.1697, PositionY = 2096.8413, PositionZ = 1011.0222;
				}
				case 2: {
					PositionX = 962.3846, PositionY = 2107.9692, PositionZ = 1011.0303;
				}
				case 3: {
					PositionX = 934.6528, PositionY = 2106.4495, PositionZ = 1011.0234;
				}
				case 4: {
					PositionX = 933.4204, PositionY = 2129.4302, PositionZ = 1011.0234;
				}
				case 5: {
					PositionX = 950.1257, PositionY = 2142.6577, PositionZ = 1011.0222;
				}
				case 6: {
					PositionX = 933.5214, PositionY = 2150.2444, PositionZ = 1011.0234;
				}
				case 7: {
					PositionX = 934.1619, PositionY = 2176.1675, PositionZ = 1011.0234;
				}
				case 8: {
					PositionX = 954.6150, PositionY = 2159.8381, PositionZ = 1011.0234;
				}
				case 9: {
					PositionX = 963.0410, PositionY = 2173.1328, PositionZ = 1011.0234;
				}
				case 10: {
					PositionX = 964.3431, PositionY = 2159.4385, PositionZ = 1011.0303;
				}
			}
		}
		case 11: {
			interior = 1;
			switch(randomspawn) {
				case 1: {
					PositionX = 963.1697, PositionY = 2096.8413, PositionZ = 1011.0222;
				}
				case 2: {
					PositionX = 962.3846, PositionY = 2107.9692, PositionZ = 1011.0303;
				}
				case 3: {
					PositionX = 934.6528, PositionY = 2106.4495, PositionZ = 1011.0234;
				}
				case 4: {
					PositionX = 933.4204, PositionY = 2129.4302, PositionZ = 1011.0234;
				}
				case 5: {
					PositionX = 950.1257, PositionY = 2142.6577, PositionZ = 1011.0222;
				}
				case 6: {
					PositionX = 933.5214, PositionY = 2150.2444, PositionZ = 1011.0234;
				}
				case 7: {
					PositionX = 934.1619, PositionY = 2176.1675, PositionZ = 1011.0234;
				}
				case 8: {
					PositionX = 954.6150, PositionY = 2159.8381, PositionZ = 1011.0234;
				}
				case 9: {
					PositionX = 963.0410, PositionY = 2173.1328, PositionZ = 1011.0234;
				}
				case 10: {
					PositionX = 964.3431, PositionY = 2159.4385, PositionZ = 1011.0303;
				}
			}
		}
		case 12: {
			interior = 1;
			switch(randomspawn) {
				case 1: {
					PositionX = 963.1697, PositionY = 2096.8413, PositionZ = 1011.0222;
				}
				case 2: {
					PositionX = 962.3846, PositionY = 2107.9692, PositionZ = 1011.0303;
				}
				case 3: {
					PositionX = 934.6528, PositionY = 2106.4495, PositionZ = 1011.0234;
				}
				case 4: {
					PositionX = 933.4204, PositionY = 2129.4302, PositionZ = 1011.0234;
				}
				case 5: {
					PositionX = 950.1257, PositionY = 2142.6577, PositionZ = 1011.0222;
				}
				case 6: {
					PositionX = 933.5214, PositionY = 2150.2444, PositionZ = 1011.0234;
				}
				case 7: {
					PositionX = 934.1619, PositionY = 2176.1675, PositionZ = 1011.0234;
				}
				case 8: {
					PositionX = 954.6150, PositionY = 2159.8381, PositionZ = 1011.0234;
				}
				case 9: {
					PositionX = 963.0410, PositionY = 2173.1328, PositionZ = 1011.0234;
				}
				case 10: {
					PositionX = 964.3431, PositionY = 2159.4385, PositionZ = 1011.0303;
				}
			}
		}
		case 13: {
			interior = 1;
			switch(randomspawn) {
				case 1: {
					PositionX = 963.1697, PositionY = 2096.8413, PositionZ = 1011.0222;
				}
				case 2: {
					PositionX = 962.3846, PositionY = 2107.9692, PositionZ = 1011.0303;
				}
				case 3: {
					PositionX = 934.6528, PositionY = 2106.4495, PositionZ = 1011.0234;
				}
				case 4: {
					PositionX = 933.4204, PositionY = 2129.4302, PositionZ = 1011.0234;
				}
				case 5: {
					PositionX = 950.1257, PositionY = 2142.6577, PositionZ = 1011.0222;
				}
				case 6: {
					PositionX = 933.5214, PositionY = 2150.2444, PositionZ = 1011.0234;
				}
				case 7: {
					PositionX = 934.1619, PositionY = 2176.1675, PositionZ = 1011.0234;
				}
				case 8: {
					PositionX = 954.6150, PositionY = 2159.8381, PositionZ = 1011.0234;
				}
				case 9: {
					PositionX = 963.0410, PositionY = 2173.1328, PositionZ = 1011.0234;
				}
				case 10: {
					PositionX = 964.3431, PositionY = 2159.4385, PositionZ = 1011.0303;
				}
			}
		}
		case 14: {
			interior = 1;
			switch(randomspawn) {
				case 1: {
					PositionX = 963.1697, PositionY = 2096.8413, PositionZ = 1011.0222;
				}
				case 2: {
					PositionX = 962.3846, PositionY = 2107.9692, PositionZ = 1011.0303;
				}
				case 3: {
					PositionX = 934.6528, PositionY = 2106.4495, PositionZ = 1011.0234;
				}
				case 4: {
					PositionX = 933.4204, PositionY = 2129.4302, PositionZ = 1011.0234;
				}
				case 5: {
					PositionX = 950.1257, PositionY = 2142.6577, PositionZ = 1011.0222;
				}
				case 6: {
					PositionX = 933.5214, PositionY = 2150.2444, PositionZ = 1011.0234;
				}
				case 7: {
					PositionX = 934.1619, PositionY = 2176.1675, PositionZ = 1011.0234;
				}
				case 8: {
					PositionX = 954.6150, PositionY = 2159.8381, PositionZ = 1011.0234;
				}
				case 9: {
					PositionX = 963.0410, PositionY = 2173.1328, PositionZ = 1011.0234;
				}
				case 10: {
					PositionX = 964.3431, PositionY = 2159.4385, PositionZ = 1011.0303;
				}
			}
		}
		case 15: {
			interior = 10;
			switch(randomspawn) {
				case 1: {
					PositionX = 363.4144, PositionY = -74.5770, PositionZ = 1001.5078;
				}
				case 2: {
					PositionX = 363.2440, PositionY = -65.8892, PositionZ = 1001.5151;
				}
				case 3: {
					PositionX = 364.8000, PositionY = -57.1770, PositionZ = 1001.5078;
				}
				case 4: {
					PositionX = 371.1385, PositionY = -60.6052, PositionZ = 1001.5078;
				}
				case 5: {
					PositionX = 367.3110, PositionY = -66.4099, PositionZ = 1001.5078;
				}
				case 6: {
					PositionX = 375.5554, PositionY = -74.8974, PositionZ = 1001.5078;
				}
				case 7: {
					PositionX = 381.6683, PositionY = -66.3294, PositionZ = 1001.5078;
				}
				case 8: {
					PositionX = 378.6399, PositionY = -59.5448, PositionZ = 1001.5078;
				}
				case 9: {
					PositionX = 372.8651, PositionY = -65.4130, PositionZ = 1001.5078;
				}
				case 10: {
					PositionX = 371.1347, PositionY = -73.0125, PositionZ = 1001.5078;
				}
			}
		}
		case 16: {
			interior = 10;
			switch(randomspawn) {
				case 1: {
					PositionX = 363.4144, PositionY = -74.5770, PositionZ = 1001.5078;
				}
				case 2: {
					PositionX = 363.2440, PositionY = -65.8892, PositionZ = 1001.5151;
				}
				case 3: {
					PositionX = 364.8000, PositionY = -57.1770, PositionZ = 1001.5078;
				}
				case 4: {
					PositionX = 371.1385, PositionY = -60.6052, PositionZ = 1001.5078;
				}
				case 5: {
					PositionX = 367.3110, PositionY = -66.4099, PositionZ = 1001.5078;
				}
				case 6: {
					PositionX = 375.5554, PositionY = -74.8974, PositionZ = 1001.5078;
				}
				case 7: {
					PositionX = 381.6683, PositionY = -66.3294, PositionZ = 1001.5078;
				}
				case 8: {
					PositionX = 378.6399, PositionY = -59.5448, PositionZ = 1001.5078;
				}
				case 9: {
					PositionX = 372.8651, PositionY = -65.4130, PositionZ = 1001.5078;
				}
				case 10: {
					PositionX = 371.1347, PositionY = -73.0125, PositionZ = 1001.5078;
				}
			}
		}
		case 17: {
			interior = 10;
			switch(randomspawn) {
				case 1: {
					PositionX = 363.4144, PositionY = -74.5770, PositionZ = 1001.5078;
				}
				case 2: {
					PositionX = 363.2440, PositionY = -65.8892, PositionZ = 1001.5151;
				}
				case 3: {
					PositionX = 364.8000, PositionY = -57.1770, PositionZ = 1001.5078;
				}
				case 4: {
					PositionX = 371.1385, PositionY = -60.6052, PositionZ = 1001.5078;
				}
				case 5: {
					PositionX = 367.3110, PositionY = -66.4099, PositionZ = 1001.5078;
				}
				case 6: {
					PositionX = 375.5554, PositionY = -74.8974, PositionZ = 1001.5078;
				}
				case 7: {
					PositionX = 381.6683, PositionY = -66.3294, PositionZ = 1001.5078;
				}
				case 8: {
					PositionX = 378.6399, PositionY = -59.5448, PositionZ = 1001.5078;
				}
				case 9: {
					PositionX = 372.8651, PositionY = -65.4130, PositionZ = 1001.5078;
				}
				case 10: {
					PositionX = 371.1347, PositionY = -73.0125, PositionZ = 1001.5078;
				}
			}
		}
		case 18: {
			interior = 10;
			switch(randomspawn) {
				case 1: {
					PositionX = 363.4144, PositionY = -74.5770, PositionZ = 1001.5078;
				}
				case 2: {
					PositionX = 363.2440, PositionY = -65.8892, PositionZ = 1001.5151;
				}
				case 3: {
					PositionX = 364.8000, PositionY = -57.1770, PositionZ = 1001.5078;
				}
				case 4: {
					PositionX = 371.1385, PositionY = -60.6052, PositionZ = 1001.5078;
				}
				case 5: {
					PositionX = 367.3110, PositionY = -66.4099, PositionZ = 1001.5078;
				}
				case 6: {
					PositionX = 375.5554, PositionY = -74.8974, PositionZ = 1001.5078;
				}
				case 7: {
					PositionX = 381.6683, PositionY = -66.3294, PositionZ = 1001.5078;
				}
				case 8: {
					PositionX = 378.6399, PositionY = -59.5448, PositionZ = 1001.5078;
				}
				case 9: {
					PositionX = 372.8651, PositionY = -65.4130, PositionZ = 1001.5078;
				}
				case 10: {
					PositionX = 371.1347, PositionY = -73.0125, PositionZ = 1001.5078;
				}
			}
		}
		case 19: {
			interior = 10;
			switch(randomspawn) {
				case 1: {
					PositionX = 363.4144, PositionY = -74.5770, PositionZ = 1001.5078;
				}
				case 2: {
					PositionX = 363.2440, PositionY = -65.8892, PositionZ = 1001.5151;
				}
				case 3: {
					PositionX = 364.8000, PositionY = -57.1770, PositionZ = 1001.5078;
				}
				case 4: {
					PositionX = 371.1385, PositionY = -60.6052, PositionZ = 1001.5078;
				}
				case 5: {
					PositionX = 367.3110, PositionY = -66.4099, PositionZ = 1001.5078;
				}
				case 6: {
					PositionX = 375.5554, PositionY = -74.8974, PositionZ = 1001.5078;
				}
				case 7: {
					PositionX = 381.6683, PositionY = -66.3294, PositionZ = 1001.5078;
				}
				case 8: {
					PositionX = 378.6399, PositionY = -59.5448, PositionZ = 1001.5078;
				}
				case 9: {
					PositionX = 372.8651, PositionY = -65.4130, PositionZ = 1001.5078;
				}
				case 10: {
					PositionX = 371.1347, PositionY = -73.0125, PositionZ = 1001.5078;
				}
			}
		}
		case 20: {
			interior = 10;
			switch(randomspawn) {
				case 1: {
					PositionX = 363.4144, PositionY = -74.5770, PositionZ = 1001.5078;
				}
				case 2: {
					PositionX = 363.2440, PositionY = -65.8892, PositionZ = 1001.5151;
				}
				case 3: {
					PositionX = 364.8000, PositionY = -57.1770, PositionZ = 1001.5078;
				}
				case 4: {
					PositionX = 371.1385, PositionY = -60.6052, PositionZ = 1001.5078;
				}
				case 5: {
					PositionX = 367.3110, PositionY = -66.4099, PositionZ = 1001.5078;
				}
				case 6: {
					PositionX = 375.5554, PositionY = -74.8974, PositionZ = 1001.5078;
				}
				case 7: {
					PositionX = 381.6683, PositionY = -66.3294, PositionZ = 1001.5078;
				}
				case 8: {
					PositionX = 378.6399, PositionY = -59.5448, PositionZ = 1001.5078;
				}
				case 9: {
					PositionX = 372.8651, PositionY = -65.4130, PositionZ = 1001.5078;
				}
				case 10: {
					PositionX = 371.1347, PositionY = -73.0125, PositionZ = 1001.5078;
				}
			}
		}
		case 21: {
			interior = 17;
			switch(randomspawn) {
				case 1: {
					PositionX = -25.8840, PositionY = -185.8686, PositionZ = 1003.5469;
				}
				case 2: {
					PositionX = -19.3360, PositionY = -185.4995, PositionZ = 1003.5469;
				}
				case 3: {
					PositionX = -4.9875, PositionY = -179.2016, PositionZ = 1003.5469;
				}
				case 4: {
					PositionX = -7.1463, PositionY = -170.3724, PositionZ = 1003.5469;
				}
				case 5: {
					PositionX = -25.7981, PositionY = -172.1958, PositionZ = 1003.5469;
				}
				case 6: {
					PositionX = -29.5934, PositionY = -173.2238, PositionZ = 1003.5469;
				}
				case 7: {
					PositionX = -33.0116, PositionY = -176.3769, PositionZ = 1003.5469;
				}
				case 8: {
					PositionX = -13.7482, PositionY = -173.4632, PositionZ = 1003.5469;
				}
				case 9: {
					PositionX = -5.4385, PositionY = -174.0408, PositionZ = 1003.5469;
				}
				case 10: {
					PositionX = -5.6696, PositionY = -174.3979, PositionZ = 1003.5469;
				}
			}
		}
		case 22: {
			interior = 17;
			switch(randomspawn) {
				case 1: {
					PositionX = -25.8840, PositionY = -185.8686, PositionZ = 1003.5469;
				}
				case 2: {
					PositionX = -19.3360, PositionY = -185.4995, PositionZ = 1003.5469;
				}
				case 3: {
					PositionX = -4.9875, PositionY = -179.2016, PositionZ = 1003.5469;
				}
				case 4: {
					PositionX = -7.1463, PositionY = -170.3724, PositionZ = 1003.5469;
				}
				case 5: {
					PositionX = -25.7981, PositionY = -172.1958, PositionZ = 1003.5469;
				}
				case 6: {
					PositionX = -29.5934, PositionY = -173.2238, PositionZ = 1003.5469;
				}
				case 7: {
					PositionX = -33.0116, PositionY = -176.3769, PositionZ = 1003.5469;
				}
				case 8: {
					PositionX = -13.7482, PositionY = -173.4632, PositionZ = 1003.5469;
				}
				case 9: {
					PositionX = -5.4385, PositionY = -174.0408, PositionZ = 1003.5469;
				}
				case 10: {
					PositionX = -5.6696, PositionY = -174.3979, PositionZ = 1003.5469;
				}
			}
		}
		case 23: {
			interior = 17;
			switch(randomspawn) {
				case 1: {
					PositionX = -25.8840, PositionY = -185.8686, PositionZ = 1003.5469;
				}
				case 2: {
					PositionX = -19.3360, PositionY = -185.4995, PositionZ = 1003.5469;
				}
				case 3: {
					PositionX = -4.9875, PositionY = -179.2016, PositionZ = 1003.5469;
				}
				case 4: {
					PositionX = -7.1463, PositionY = -170.3724, PositionZ = 1003.5469;
				}
				case 5: {
					PositionX = -25.7981, PositionY = -172.1958, PositionZ = 1003.5469;
				}
				case 6: {
					PositionX = -29.5934, PositionY = -173.2238, PositionZ = 1003.5469;
				}
				case 7: {
					PositionX = -33.0116, PositionY = -176.3769, PositionZ = 1003.5469;
				}
				case 8: {
					PositionX = -13.7482, PositionY = -173.4632, PositionZ = 1003.5469;
				}
				case 9: {
					PositionX = -5.4385, PositionY = -174.0408, PositionZ = 1003.5469;
				}
				case 10: {
					PositionX = -5.6696, PositionY = -174.3979, PositionZ = 1003.5469;
				}
			}
		}
		case 24: {
			interior = 17;
			switch(randomspawn) {
				case 1: {
					PositionX = -25.8840, PositionY = -185.8686, PositionZ = 1003.5469;
				}
				case 2: {
					PositionX = -19.3360, PositionY = -185.4995, PositionZ = 1003.5469;
				}
				case 3: {
					PositionX = -4.9875, PositionY = -179.2016, PositionZ = 1003.5469;
				}
				case 4: {
					PositionX = -7.1463, PositionY = -170.3724, PositionZ = 1003.5469;
				}
				case 5: {
					PositionX = -25.7981, PositionY = -172.1958, PositionZ = 1003.5469;
				}
				case 6: {
					PositionX = -29.5934, PositionY = -173.2238, PositionZ = 1003.5469;
				}
				case 7: {
					PositionX = -33.0116, PositionY = -176.3769, PositionZ = 1003.5469;
				}
				case 8: {
					PositionX = -13.7482, PositionY = -173.4632, PositionZ = 1003.5469;
				}
				case 9: {
					PositionX = -5.4385, PositionY = -174.0408, PositionZ = 1003.5469;
				}
				case 10: {
					PositionX = -5.6696, PositionY = -174.3979, PositionZ = 1003.5469;
				}
			}
		}
		case 25: {
			interior = 17;
			switch(randomspawn) {
				case 1: {
					PositionX = -25.8840, PositionY = -185.8686, PositionZ = 1003.5469;
				}
				case 2: {
					PositionX = -19.3360, PositionY = -185.4995, PositionZ = 1003.5469;
				}
				case 3: {
					PositionX = -4.9875, PositionY = -179.2016, PositionZ = 1003.5469;
				}
				case 4: {
					PositionX = -7.1463, PositionY = -170.3724, PositionZ = 1003.5469;
				}
				case 5: {
					PositionX = -25.7981, PositionY = -172.1958, PositionZ = 1003.5469;
				}
				case 6: {
					PositionX = -29.5934, PositionY = -173.2238, PositionZ = 1003.5469;
				}
				case 7: {
					PositionX = -33.0116, PositionY = -176.3769, PositionZ = 1003.5469;
				}
				case 8: {
					PositionX = -13.7482, PositionY = -173.4632, PositionZ = 1003.5469;
				}
				case 9: {
					PositionX = -5.4385, PositionY = -174.0408, PositionZ = 1003.5469;
				}
				case 10: {
					PositionX = -5.6696, PositionY = -174.3979, PositionZ = 1003.5469;
				}
			}
		}
		case 26: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 227.2748, PositionY = -8.1426, PositionZ = 1002.2109;
				}
				case 2: {
					PositionX = 218.8037, PositionY = -12.0517, PositionZ = 1001.2109;
				}
				case 3: {
					PositionX = 200.5015, PositionY = -10.5221, PositionZ = 1001.2109;
				}
				case 4: {
					PositionX = 200.4146, PositionY = -5.8217, PositionZ = 1001.2109;
				}
				case 5: {
					PositionX = 208.7941, PositionY = -3.9461, PositionZ = 1001.2178;
				}
				case 6: {
					PositionX = 210.9132, PositionY = -12.0936, PositionZ = 1005.2109;
				}
				case 7: {
					PositionX = 204.9166, PositionY = -9.1855, PositionZ = 1005.2109;
				}
				case 8: {
					PositionX = 208.0700, PositionY = -4.4648, PositionZ = 1005.2109;
				}
				case 9: {
					PositionX = 227.3412, PositionY = -4.6564, PositionZ = 1002.2109;
				}
				case 10: {
					PositionX = 210.4878, PositionY = -8.6443, PositionZ = 1001.2109;
				}
			}
		}
		case 27: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 227.2748, PositionY = -8.1426, PositionZ = 1002.2109;
				}
				case 2: {
					PositionX = 218.8037, PositionY = -12.0517, PositionZ = 1001.2109;
				}
				case 3: {
					PositionX = 200.5015, PositionY = -10.5221, PositionZ = 1001.2109;
				}
				case 4: {
					PositionX = 200.4146, PositionY = -5.8217, PositionZ = 1001.2109;
				}
				case 5: {
					PositionX = 208.7941, PositionY = -3.9461, PositionZ = 1001.2178;
				}
				case 6: {
					PositionX = 210.9132, PositionY = -12.0936, PositionZ = 1005.2109;
				}
				case 7: {
					PositionX = 204.9166, PositionY = -9.1855, PositionZ = 1005.2109;
				}
				case 8: {
					PositionX = 208.0700, PositionY = -4.4648, PositionZ = 1005.2109;
				}
				case 9: {
					PositionX = 227.3412, PositionY = -4.6564, PositionZ = 1002.2109;
				}
				case 10: {
					PositionX = 210.4878, PositionY = -8.6443, PositionZ = 1001.2109;
				}
			}
		}
		case 28: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 227.2748, PositionY = -8.1426, PositionZ = 1002.2109;
				}
				case 2: {
					PositionX = 218.8037, PositionY = -12.0517, PositionZ = 1001.2109;
				}
				case 3: {
					PositionX = 200.5015, PositionY = -10.5221, PositionZ = 1001.2109;
				}
				case 4: {
					PositionX = 200.4146, PositionY = -5.8217, PositionZ = 1001.2109;
				}
				case 5: {
					PositionX = 208.7941, PositionY = -3.9461, PositionZ = 1001.2178;
				}
				case 6: {
					PositionX = 210.9132, PositionY = -12.0936, PositionZ = 1005.2109;
				}
				case 7: {
					PositionX = 204.9166, PositionY = -9.1855, PositionZ = 1005.2109;
				}
				case 8: {
					PositionX = 208.0700, PositionY = -4.4648, PositionZ = 1005.2109;
				}
				case 9: {
					PositionX = 227.3412, PositionY = -4.6564, PositionZ = 1002.2109;
				}
				case 10: {
					PositionX = 210.4878, PositionY = -8.6443, PositionZ = 1001.2109;
				}
			}
		}
		case 29: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 227.2748, PositionY = -8.1426, PositionZ = 1002.2109;
				}
				case 2: {
					PositionX = 218.8037, PositionY = -12.0517, PositionZ = 1001.2109;
				}
				case 3: {
					PositionX = 200.5015, PositionY = -10.5221, PositionZ = 1001.2109;
				}
				case 4: {
					PositionX = 200.4146, PositionY = -5.8217, PositionZ = 1001.2109;
				}
				case 5: {
					PositionX = 208.7941, PositionY = -3.9461, PositionZ = 1001.2178;
				}
				case 6: {
					PositionX = 210.9132, PositionY = -12.0936, PositionZ = 1005.2109;
				}
				case 7: {
					PositionX = 204.9166, PositionY = -9.1855, PositionZ = 1005.2109;
				}
				case 8: {
					PositionX = 208.0700, PositionY = -4.4648, PositionZ = 1005.2109;
				}
				case 9: {
					PositionX = 227.3412, PositionY = -4.6564, PositionZ = 1002.2109;
				}
				case 10: {
					PositionX = 210.4878, PositionY = -8.6443, PositionZ = 1001.2109;
				}
			}
		}
		case 30: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 227.2748, PositionY = -8.1426, PositionZ = 1002.2109;
				}
				case 2: {
					PositionX = 218.8037, PositionY = -12.0517, PositionZ = 1001.2109;
				}
				case 3: {
					PositionX = 200.5015, PositionY = -10.5221, PositionZ = 1001.2109;
				}
				case 4: {
					PositionX = 200.4146, PositionY = -5.8217, PositionZ = 1001.2109;
				}
				case 5: {
					PositionX = 208.7941, PositionY = -3.9461, PositionZ = 1001.2178;
				}
				case 6: {
					PositionX = 210.9132, PositionY = -12.0936, PositionZ = 1005.2109;
				}
				case 7: {
					PositionX = 204.9166, PositionY = -9.1855, PositionZ = 1005.2109;
				}
				case 8: {
					PositionX = 208.0700, PositionY = -4.4648, PositionZ = 1005.2109;
				}
				case 9: {
					PositionX = 227.3412, PositionY = -4.6564, PositionZ = 1002.2109;
				}
				case 10: {
					PositionX = 210.4878, PositionY = -8.6443, PositionZ = 1001.2109;
				}
			}
		}
		case 31: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 227.2748, PositionY = -8.1426, PositionZ = 1002.2109;
				}
				case 2: {
					PositionX = 218.8037, PositionY = -12.0517, PositionZ = 1001.2109;
				}
				case 3: {
					PositionX = 200.5015, PositionY = -10.5221, PositionZ = 1001.2109;
				}
				case 4: {
					PositionX = 200.4146, PositionY = -5.8217, PositionZ = 1001.2109;
				}
				case 5: {
					PositionX = 208.7941, PositionY = -3.9461, PositionZ = 1001.2178;
				}
				case 6: {
					PositionX = 210.9132, PositionY = -12.0936, PositionZ = 1005.2109;
				}
				case 7: {
					PositionX = 204.9166, PositionY = -9.1855, PositionZ = 1005.2109;
				}
				case 8: {
					PositionX = 208.0700, PositionY = -4.4648, PositionZ = 1005.2109;
				}
				case 9: {
					PositionX = 227.3412, PositionY = -4.6564, PositionZ = 1002.2109;
				}
				case 10: {
					PositionX = 210.4878, PositionY = -8.6443, PositionZ = 1001.2109;
				}
			}
		}
		case 32: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 227.2748, PositionY = -8.1426, PositionZ = 1002.2109;
				}
				case 2: {
					PositionX = 218.8037, PositionY = -12.0517, PositionZ = 1001.2109;
				}
				case 3: {
					PositionX = 200.5015, PositionY = -10.5221, PositionZ = 1001.2109;
				}
				case 4: {
					PositionX = 200.4146, PositionY = -5.8217, PositionZ = 1001.2109;
				}
				case 5: {
					PositionX = 208.7941, PositionY = -3.9461, PositionZ = 1001.2178;
				}
				case 6: {
					PositionX = 210.9132, PositionY = -12.0936, PositionZ = 1005.2109;
				}
				case 7: {
					PositionX = 204.9166, PositionY = -9.1855, PositionZ = 1005.2109;
				}
				case 8: {
					PositionX = 208.0700, PositionY = -4.4648, PositionZ = 1005.2109;
				}
				case 9: {
					PositionX = 227.3412, PositionY = -4.6564, PositionZ = 1002.2109;
				}
				case 10: {
					PositionX = 210.4878, PositionY = -8.6443, PositionZ = 1001.2109;
				}
			}
		}
		case 33: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 227.2748, PositionY = -8.1426, PositionZ = 1002.2109;
				}
				case 2: {
					PositionX = 218.8037, PositionY = -12.0517, PositionZ = 1001.2109;
				}
				case 3: {
					PositionX = 200.5015, PositionY = -10.5221, PositionZ = 1001.2109;
				}
				case 4: {
					PositionX = 200.4146, PositionY = -5.8217, PositionZ = 1001.2109;
				}
				case 5: {
					PositionX = 208.7941, PositionY = -3.9461, PositionZ = 1001.2178;
				}
				case 6: {
					PositionX = 210.9132, PositionY = -12.0936, PositionZ = 1005.2109;
				}
				case 7: {
					PositionX = 204.9166, PositionY = -9.1855, PositionZ = 1005.2109;
				}
				case 8: {
					PositionX = 208.0700, PositionY = -4.4648, PositionZ = 1005.2109;
				}
				case 9: {
					PositionX = 227.3412, PositionY = -4.6564, PositionZ = 1002.2109;
				}
				case 10: {
					PositionX = 210.4878, PositionY = -8.6443, PositionZ = 1001.2109;
				}
			}
		}
		case 34: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 227.2748, PositionY = -8.1426, PositionZ = 1002.2109;
				}
				case 2: {
					PositionX = 218.8037, PositionY = -12.0517, PositionZ = 1001.2109;
				}
				case 3: {
					PositionX = 200.5015, PositionY = -10.5221, PositionZ = 1001.2109;
				}
				case 4: {
					PositionX = 200.4146, PositionY = -5.8217, PositionZ = 1001.2109;
				}
				case 5: {
					PositionX = 208.7941, PositionY = -3.9461, PositionZ = 1001.2178;
				}
				case 6: {
					PositionX = 210.9132, PositionY = -12.0936, PositionZ = 1005.2109;
				}
				case 7: {
					PositionX = 204.9166, PositionY = -9.1855, PositionZ = 1005.2109;
				}
				case 8: {
					PositionX = 208.0700, PositionY = -4.4648, PositionZ = 1005.2109;
				}
				case 9: {
					PositionX = 227.3412, PositionY = -4.6564, PositionZ = 1002.2109;
				}
				case 10: {
					PositionX = 210.4878, PositionY = -8.6443, PositionZ = 1001.2109;
				}
			}
		}
		case 35: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 227.2748, PositionY = -8.1426, PositionZ = 1002.2109;
				}
				case 2: {
					PositionX = 218.8037, PositionY = -12.0517, PositionZ = 1001.2109;
				}
				case 3: {
					PositionX = 200.5015, PositionY = -10.5221, PositionZ = 1001.2109;
				}
				case 4: {
					PositionX = 200.4146, PositionY = -5.8217, PositionZ = 1001.2109;
				}
				case 5: {
					PositionX = 208.7941, PositionY = -3.9461, PositionZ = 1001.2178;
				}
				case 6: {
					PositionX = 210.9132, PositionY = -12.0936, PositionZ = 1005.2109;
				}
				case 7: {
					PositionX = 204.9166, PositionY = -9.1855, PositionZ = 1005.2109;
				}
				case 8: {
					PositionX = 208.0700, PositionY = -4.4648, PositionZ = 1005.2109;
				}
				case 9: {
					PositionX = 227.3412, PositionY = -4.6564, PositionZ = 1002.2109;
				}
				case 10: {
					PositionX = 210.4878, PositionY = -8.6443, PositionZ = 1001.2109;
				}
			}
		}
		case 36: {
			interior = 5;
			switch(randomspawn) {
				case 1: {
					PositionX = 227.2748, PositionY = -8.1426, PositionZ = 1002.2109;
				}
				case 2: {
					PositionX = 218.8037, PositionY = -12.0517, PositionZ = 1001.2109;
				}
				case 3: {
					PositionX = 200.5015, PositionY = -10.5221, PositionZ = 1001.2109;
				}
				case 4: {
					PositionX = 200.4146, PositionY = -5.8217, PositionZ = 1001.2109;
				}
				case 5: {
					PositionX = 208.7941, PositionY = -3.9461, PositionZ = 1001.2178;
				}
				case 6: {
					PositionX = 210.9132, PositionY = -12.0936, PositionZ = 1005.2109;
				}
				case 7: {
					PositionX = 204.9166, PositionY = -9.1855, PositionZ = 1005.2109;
				}
				case 8: {
					PositionX = 208.0700, PositionY = -4.4648, PositionZ = 1005.2109;
				}
				case 9: {
					PositionX = 227.3412, PositionY = -4.6564, PositionZ = 1002.2109;
				}
				case 10: {
					PositionX = 210.4878, PositionY = -8.6443, PositionZ = 1001.2109;
				}
			}
		}
		case 37: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 38: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 39: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 40: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 41: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 42: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 43: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 44: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 45: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 46: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 47: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 48: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 49: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 50: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 51: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 52: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 53: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 54: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 55: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 56: {
			interior = 6;
			switch(randomspawn) {
				case 1: {
					PositionX = -2221.7480, PositionY = 133.0828, PositionZ = 1035.7578;
				}
				case 2: {
					PositionX = -2219.7334, PositionY = 135.7479, PositionZ = 1035.6328;
				}
				case 3: {
					PositionX = -2224.8308, PositionY = 129.3692, PositionZ = 1035.4210;
				}
				case 4: {
					PositionX = -2230.5938, PositionY = 133.0282, PositionZ = 1035.4210;
				}
				case 5: {
					PositionX = -2232.0225, PositionY = 137.4612, PositionZ = 1035.4141;
				}
				case 6: {
					PositionX = -2239.4475, PositionY = 136.3371, PositionZ = 1035.4141;
				}
				case 7: {
					PositionX = -2240.0596, PositionY = 128.0508, PositionZ = 1035.4210;
				}
				case 8: {
					PositionX = -2234.1555, PositionY = 130.8308, PositionZ = 1035.4141;
				}
				case 9: {
					PositionX = -2235.7153, PositionY = 128.5864, PositionZ = 1035.4141;
				}
				case 10: {
					PositionX = -2224.5779, PositionY = 130.3091, PositionZ = 1035.4210;
				}
			}
		}
		case 57: { //Same as 55
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1309.4430, PositionY = -55.7994, PositionZ = 1002.4948;
				}
				case 2: {
					PositionX = 1280.7654, PositionY = -68.1951, PositionZ = 1002.4936;
				}
				case 3: {
					PositionX = 1254.2473, PositionY = -47.0734, PositionZ = 1001.0193;
				}
				case 4: {
					PositionX = 1266.0681, PositionY = -25.5088, PositionZ = 1001.0285;
				}
				case 5: {
					PositionX = 1250.8276, PositionY = 4.5751, PositionZ = 1001.0351;
				}
				case 6: {
					PositionX = 1290.1991, PositionY = 6.7272, PositionZ = 1001.0078;
				}
				case 7: {
					PositionX = 1305.3170, PositionY = 3.8144, PositionZ = 1001.0270;
				}
				case 8: {
					PositionX = 1261.0201, PositionY = 5.8350, PositionZ = 1008.2578;
				}
				case 9: {
					PositionX = 1283.7308, PositionY = -32.2366, PositionZ = 1001.0211;
				}
				case 10: {
					PositionX = 1308.3413, PositionY = -24.4243, PositionZ = 1001.0344;
				}
			}
		}
		case 58: {
			interior = 10;
			switch(randomspawn) {
				case 1: {
					PositionX = 2018.7518, PositionY = 1017.8284, PositionZ = 996.8750;
				}
				case 2: {
					PositionX = 1964.2230, PositionY = 1062.7091, PositionZ = 994.4688;
				}
				case 3: {
					PositionX = 1928.7123, PositionY = 1061.8018, PositionZ = 994.4688;
				}
				case 4: {
					PositionX = 1927.2584, PositionY = 1021.8909, PositionZ = 994.4688;
				}
				case 5: {
					PositionX = 1958.6156, PositionY = 1016.0810, PositionZ = 992.4688;
				}
				case 6: {
					PositionX = 1940.7672, PositionY = 990.2513, PositionZ = 992.4609;
				}
				case 7: {
					PositionX = 1963.6193, PositionY = 972.5910, PositionZ = 994.4688;
				}
				case 8: {
					PositionX = 1966.1014, PositionY = 991.1375, PositionZ = 992.4688;
				}
				case 9: {
					PositionX = 1951.7272, PositionY = 1029.7424, PositionZ = 992.4688;
				}
				case 10: {
					PositionX = 1939.7095, PositionY = 1053.1097, PositionZ = 992.4688;
				}
			}
		}
		case 59: {
			interior = 18;
			switch(randomspawn) {
				case 1: {
					PositionX = 1726.9164, PositionY = -1638.4091, PositionZ = 20.2232;
				}
				case 2: {
					PositionX = 1735.0863, PositionY = -1659.9396, PositionZ = 23.7190;
				}
				case 3: {
					PositionX = 1713.8479, PositionY = -1641.3698, PositionZ = 23.6797;
				}
				case 4: {
					PositionX = 1711.6868, PositionY = -1672.4580, PositionZ = 23.7045;
				}
				case 5: {
					PositionX = 1710.4950, PositionY = -1676.1943, PositionZ = 27.2073;
				}
				case 6: {
					PositionX = 1727.1333, PositionY = -1670.9669, PositionZ = 27.1953;
				}
				case 7: {
					PositionX = 1734.4058, PositionY = -1654.5383, PositionZ = 27.2265;
				}
				case 8: {
					PositionX = 1728.4329, PositionY = -1640.3542, PositionZ = 27.2394;
				}
				case 9: {
					PositionX = 1714.2789, PositionY = -1641.7159, PositionZ = 27.2111;
				}
				case 10: {
					PositionX = 1709.4022, PositionY = -1659.9275, PositionZ = 27.1953;
				}
			}
		}
		case 60: {
			interior = 17;
			switch(randomspawn) {
				case 1: {
					PositionX = 493.2109, PositionY = -24.3472, PositionZ = 1000.6797;
				}
				case 2: {
					PositionX = 502.3421, PositionY = -12.7743, PositionZ = 1000.6797;
				}
				case 3: {
					PositionX = 503.1976, PositionY = -4.9345, PositionZ = 1000.6797;
				}
				case 4: {
					PositionX = 496.8328, PositionY = -3.4553, PositionZ = 1002.0781;
				}
				case 5: {
					PositionX = 487.8918, PositionY = -2.7538, PositionZ = 1002.3828;
				}
				case 6: {
					PositionX = 479.2682, PositionY = -13.2351, PositionZ = 1000.6828;
				}
				case 7: {
					PositionX = 485.3499, PositionY = -22.5843, PositionZ = 1003.1094;
				}
				case 8: {
					PositionX = 475.3263, PositionY = -12.4311, PositionZ = 1003.6953;
				}
				case 9: {
					PositionX = 481.4424, PositionY = -19.3927, PositionZ = 1000.6719;
				}
				case 10: {
					PositionX = 487.0526, PositionY = -13.8784, PositionZ = 1000.6797;
				}
			}
		}
		case 61: {
			interior = 2;
			switch(randomspawn) {
				case 1: {
					PositionX = 1204.9646, PositionY = -13.5471, PositionZ = 1000.9219;
				}
				case 2: {
					PositionX = 1202.6827, PositionY = 9.4000, PositionZ = 1000.9219;
				}
				case 3: {
					PositionX = 1211.0870, PositionY = -5.8428, PositionZ = 1000.9219;
				}
				case 4: {
					PositionX = 1211.5061, PositionY = -14.9774, PositionZ = 1000.9219;
				}
				case 5: {
					PositionX = 1221.2195, PositionY = -14.7890, PositionZ = 1000.9219;
				}
				case 6: {
					PositionX = 1221.0110, PositionY = 7.8009, PositionZ = 1001.3356;
				}
				case 7: {
					PositionX = 1210.9614, PositionY = 4.9193, PositionZ = 1000.9219;
				}
				case 8: {
					PositionX = 1204.7157, PositionY = 11.9482, PositionZ = 1000.9219;
				}
				case 9: {
					PositionX = 1202.2045, PositionY = 10.1701, PositionZ = 1000.9219;
				}
				case 10: {
					PositionX = 1218.0044, PositionY = -1.9969, PositionZ = 1000.9219;
				}
			}
		}
		case 62: {
			interior = 6;
			switch(randomspawn) {
				case 1: {
					PositionX = -2221.3748, PositionY = 133.1454, PositionZ = 1035.7578;
				}
				case 2: {
					PositionX = -2220.3369, PositionY = 136.0132, PositionZ = 1035.6328;
				} 
				case 3: {
					PositionX = -2224.8179, PositionY = 129.6690, PositionZ = 1035.4210;
				}
				case 4: {
					PositionX = -2225.5227, PositionY = 133.9836, PositionZ = 1035.4141;
				}
				case 5: {
					PositionX = -2228.8789, PositionY = 132.3281, PositionZ = 1035.4210;
				}
				case 6: {
					PositionX = -2233.5422, PositionY = 133.8398, PositionZ = 1035.4210;
				}
				case 7: {
					PositionX = -2233.9758, PositionY = 131.0203, PositionZ = 1035.4141;
				}
				case 8: {
					PositionX = -2232.8872, PositionY = 128.4971, PositionZ = 1035.4141;
				}
				case 9: {
					PositionX = -2240.0598, PositionY = 128.2847, PositionZ = 1035.4210;
				}
				case 10: {
					PositionX = -2240.1938, PositionY = 137.7583, PositionZ = 1035.4141;
				}
			}
		}
		case 63: {
			interior = 10;
			switch(randomspawn) {
				case 1: {
					PositionX = -1132.6171, PositionY = 1091.0743, PositionZ = 1345.7924;
				}
				case 2: {
					PositionX = -1128.2109, PositionY = 1066.3367, PositionZ = 1345.7407;
				}
				case 3: {
					PositionX = -1130.4889, PositionY = 1042.4547, PositionZ = 1345.7307;
				}
				case 4: {
					PositionX = -1131.4597, PositionY = 1030.8726, PositionZ = 1345.7266;
				}
				case 5: {
					PositionX = -1083.9877, PositionY = 1041.7418, PositionZ = 1343.5283;
				}
				case 6: {
					PositionX = -1050.1229, PositionY = 1064.7987, PositionZ = 1343.9711;
				}
				case 7: {
					PositionX = -1026.4717, PositionY = 1082.9927, PositionZ = 1343.3309;
				}
				case 8: {
					PositionX = -976.8871, PositionY = 1089.2777, PositionZ = 1344.9639;
				}
				case 9: {
					PositionX = -975.2461, PositionY = 1061.1351, PositionZ = 1345.6719;
				}
				case 10: {
					PositionX = -974.7925, PositionY = 1028.3907, PositionZ = 1345.0364;
				}
			}
		}
		case 64: {
			interior = 3;
			switch(randomspawn) {
				case 1: {
					PositionX = -100.4099, PositionY = -24.5757, PositionZ = 1000.7188;
				}
				case 2: {
					PositionX = -107.4838, PositionY = -24.0650, PositionZ = 1000.7188;
				}
				case 3: {
					PositionX = -107.2762, PositionY = -17.7529, PositionZ = 1000.7188;
				}
				case 4: {
					PositionX = -115.2870, PositionY = -11.8913, PositionZ = 1000.7188;
				}
				case 5: {
					PositionX = -113.3718, PositionY = -8.8117, PositionZ = 1000.7188;
				}
				case 6: {
					PositionX = -106.3750, PositionY = -8.7108, PositionZ = 1000.7188;
				}
				case 7: {
					PositionX = -100.1142, PositionY = -16.1410, PositionZ = 1000.7188;
				}
				case 8: {
					PositionX = -103.9134, PositionY = -17.0319, PositionZ = 1000.7188;
				}
				case 9: {
					PositionX = -99.2303, PositionY = -12.3866, PositionZ = 1000.7188;
				}
				case 10: {
					PositionX = -104.0994, PositionY = -21.1183, PositionZ = 1000.7188;
				}
			}
		}
		case 65: {
			interior = 17;
			switch(randomspawn) {
				case 1: {
					PositionX = -942.3096, PositionY = 1846.4830, PositionZ = 5.0000;
				}
				case 2: {
					PositionX = -959.9595, PositionY = 1848.0760, PositionZ = 9.0000;
				}
				case 3: {
					PositionX = -953.8923, PositionY = 1861.7925, PositionZ = 9.0000;
				}
				case 4: {
					PositionX = -961.8008, PositionY = 1875.8372, PositionZ = 9.0000;
				}
				case 5: {
					PositionX = -956.6901, PositionY = 1889.0039, PositionZ = 5.0000;
				}
				case 6: {
					PositionX = -942.8404, PositionY = 1899.2654, PositionZ = 5.0051;
				}
				case 7: {
					PositionX = -955.4063, PositionY = 1905.0863, PositionZ = 9.0000;
				}
				case 8: {
					PositionX = -960.2462, PositionY = 1923.4200, PositionZ = 9.0000;
				}
				case 9: {
					PositionX = -956.7693, PositionY = 1931.6019, PositionZ = 5.0000;
				}
				case 10: {
					PositionX = -942.5430, PositionY = 1952.1938, PositionZ = 5.0000;
				}
			}
		}
	}
	return 1;
}


stock HasBizfight(fraktion) {
    for(new i=1 ; i < MAX_BIZES ; i++) {
        if( Bizfight[i][BF_BizStatus] == 1 ) {
            if( Bizfight[i][BF_Owner] == fraktion || Bizfight[i][BF_Angreifer] == fraktion) {
                return 1;
            }
        }
    }
    return 0;
}


stock GetBizfightID(fraktion) {
    for(new i=1 ; i < MAX_BIZES ; i++) {
        if( Bizfight[i][BF_BizStatus] == 1 ) {
            if( Bizfight[i][BF_Owner] == fraktion || Bizfight[i][BF_Angreifer] == fraktion) {
                return i;
            }
        }
    }
    return -1;
}

stock GetBizfightKiller(fraktion) {
    new
        Kills = -1,
        playerid = INVALID_PLAYER_ID;
    foreach(new i : Player) {
        if( IsPlayerConnected(i) ) {
            if( Spieler[i][pFraktion] == fraktion ) {
                if( BFKills[i] > Kills ) {
                    Kills = BFKills[i];
                    playerid = i;
                }
            }
        }
    }
    return playerid;
}
#include <YSI\y_hooks>

// Global interior define
#define MAPS_SHISHABAR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 100.0;
static Float:DRAWDISTANCE   = 90.0;

// Shisha bar points
#define SHISHABAR_ENTER_COORDS      1786.5337, -1300.0994, 13.4494
#define SHISHABAR_ENTER_FACING      360.0
#define SHISHABAR_EXIT_COORDS       1786.4310, -1300.1693, 120.2656

#define SHISHABAR_VIP_ENTER         1805.3218, -1307.5023, 120.2585
#define SHISHABAR_VIP_ENTER_FACING  270.0
#define SHISHABAR_VIP_EXIT          1807.8176, -1307.3773, 120.3192
#define SHISHABAR_O18_ENTER         1783.8964, -1296.5836, 120.2656
#define SHISHABAR_O18_ENTER_FACING  90.0
#define SHISHABAR_O18_EXIT          1781.4067, -1296.5382, 120.2656
#define SHISHABAR_DRINK_POINT       1814.7476, -1294.2003, 120.2656
#define SHISHABAR_SLOTS_POINT       1831.1813, -1274.4621, 120.2656
#define SHISHABAR_PIPES_POINT       1833.2487, -1285.7264, 120.2656

#define SOUND_SHISHA "http://sounds.lyd-roleplay.de/sounds/shisha.mp3"

// Map variables
new object_shishaBar[434];
new pickup_shishaBar[8];
new text3D_shishaBar[7];
new actor_shishaBar[5];

new const Float:g_shishaPoints[][3] = {
	{1833.4843, -1289.0989, 120.7427},
	{1833.4807, -1296.9984, 120.7427},
	{1833.2511, -1303.0813, 120.7427},
	{2491.7261, -1701.2618, 1018.3438},
	{-791.3092, 508.1032, 	1367.3672},
	{308.2954,  1120.7721, 	1083.8828},
	{1833.5000, -1310.5891,	120.7427},
	{1826.6648, -1306.8662,	120.7427},
	{1826.5094, -1299.6204,	120.7427},
	{1826.7908, -1292.8218,	120.7427},
	{1819.6852, -1314.7180,	120.7515},
	{1822.8683, -1314.5635,	120.3193}
};

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys & KEY_SECONDARY_ATTACK) {
        new bizIndex = GetBizIndexByID(11);
		if (IsPlayerInRangeOfPoint(playerid, 2.0, SHISHABAR_ENTER_COORDS) && GetPlayerVirtualWorld(playerid) == VW_MAIN) { // Lounge Enter
			if (Spieler[playerid][pCash] < Biz[bizIndex][bEintritt]) return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genug Geld, um die Shisha-Bar zu betreten.");
			GivePlayerCash(playerid, Biz[bizIndex][bEintritt] * -1);
			Biz[bizIndex][bKasse] += Biz[bizIndex][bEintritt];
            SetPlayerPos(playerid, SHISHABAR_EXIT_COORDS);
            SetPlayerFacingAngle(playerid, SHISHABAR_ENTER_FACING);
			SetCameraBehindPlayer(playerid);
            PlayAudioStreamForPlayer(playerid, SOUND_SHISHA);
		} else if (IsPlayerInRangeOfPoint(playerid, 2.0, SHISHABAR_EXIT_COORDS) && GetPlayerVirtualWorld(playerid) == VW_MAIN) { // Lounge Exit
			SetPlayerPos(playerid, SHISHABAR_ENTER_COORDS);
            SetPlayerFacingAngle(playerid, SHISHABAR_ENTER_FACING);
			SetCameraBehindPlayer(playerid);
            StopAudioStreamForPlayer(playerid);
            SetPVarInt(playerid, "MP3.PLAYER", 0);
        } else if (IsPlayerInRangeOfPoint(playerid, 2.0, SHISHABAR_VIP_ENTER)) { // VIP Enter
			if (Spieler[playerid][pCash] < 25000) return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genug Geld dabei, um den VIP-Bereich zu betreten.");
			GivePlayerCash(playerid, -25000);
			Biz[bizIndex][bKasse] += 25000;
			SetPlayerPos(playerid, SHISHABAR_VIP_EXIT);
            SetPlayerFacingAngle(playerid, SHISHABAR_VIP_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
		} else if (IsPlayerInRangeOfPoint(playerid, 2.0, SHISHABAR_VIP_EXIT)) { // VIP Exit
			SetPlayerPos(playerid, SHISHABAR_VIP_ENTER);
            SetPlayerFacingAngle(playerid, SHISHABAR_VIP_ENTER_FACING + 180.0);
            SetCameraBehindPlayer(playerid);
		} else if (IsPlayerInRangeOfPoint(playerid, 2.0, SHISHABAR_O18_ENTER)) { // O18 Enter
			if (Spieler[playerid][pCash] < 40000) return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genug Geld dabei, um den Ü18-Bereich zu betreten.");
			GivePlayerCash(playerid, -40000);
			Biz[bizIndex][bKasse] += 40000;
			SetPlayerPos(playerid, SHISHABAR_O18_EXIT);
            SetPlayerFacingAngle(playerid, SHISHABAR_O18_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
		} else if (IsPlayerInRangeOfPoint(playerid, 2.0, SHISHABAR_O18_EXIT)) { // O18 Enter
			SetPlayerPos(playerid, SHISHABAR_O18_ENTER);
            SetPlayerFacingAngle(playerid, SHISHABAR_O18_ENTER_FACING + 180.0);
            SetCameraBehindPlayer(playerid);
		}
    }
	return 1;
}

hook OnGameModeInit() {
	// Pickups
    pickup_shishaBar[0] = CreateDynamicPickup(19197, 1, SHISHABAR_ENTER_COORDS, VW_MAIN, MAPS_SHISHABAR_INTERIOR); // Entry
	pickup_shishaBar[1] = CreateDynamicPickup(19197, 1, SHISHABAR_EXIT_COORDS, VW_MAIN, MAPS_SHISHABAR_INTERIOR);
    pickup_shishaBar[2] = CreateDynamicPickup(19197, 1, SHISHABAR_VIP_ENTER, VW_MAIN, MAPS_SHISHABAR_INTERIOR);
	pickup_shishaBar[3] = CreateDynamicPickup(19197, 1, SHISHABAR_VIP_EXIT, VW_MAIN, MAPS_SHISHABAR_INTERIOR);
    pickup_shishaBar[4] = CreateDynamicPickup(19197, 1, SHISHABAR_O18_ENTER, VW_MAIN, MAPS_SHISHABAR_INTERIOR);
    pickup_shishaBar[5] = CreateDynamicPickup(19197, 1, SHISHABAR_O18_EXIT, VW_MAIN, MAPS_SHISHABAR_INTERIOR);
    pickup_shishaBar[6] = CreateDynamicPickup(1239, 1, SHISHABAR_DRINK_POINT, VW_MAIN, MAPS_SHISHABAR_INTERIOR);
    pickup_shishaBar[7] = CreateDynamicPickup(2726, 1, SHISHABAR_PIPES_POINT, VW_MAIN, MAPS_SHISHABAR_INTERIOR);

	// 3DTextLabels
    text3D_shishaBar[0] = _:CreateDynamic3DTextLabel("SHISHA - LOUNGE\n" COLOR_HEX_WHITE "Betreten mit 'Enter'", COLOR_BLUE, SHISHABAR_ENTER_COORDS, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SHISHABAR_INTERIOR);
    text3D_shishaBar[1] = _:CreateDynamic3DTextLabel("SHISHA - LOUNGE\n" COLOR_HEX_WHITE "Verlassen mit 'Enter'", COLOR_BLUE, SHISHABAR_EXIT_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SHISHABAR_INTERIOR);
    text3D_shishaBar[2] = _:CreateDynamic3DTextLabel("VIP - Bereich\n" COLOR_HEX_WHITE "Betreten mit 'Enter'\n" COLOR_HEX_YELLOW "Preis: 25.000$", COLOR_BLUE, SHISHABAR_VIP_ENTER, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SHISHABAR_INTERIOR);
    text3D_shishaBar[3] = _:CreateDynamic3DTextLabel("Ü18 - Bereich\n" COLOR_HEX_WHITE "Betreten mit 'Enter'\n" COLOR_HEX_YELLOW "Preis: 40.000$", COLOR_BLUE, SHISHABAR_O18_ENTER, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SHISHABAR_INTERIOR);
    text3D_shishaBar[4] = _:CreateDynamic3DTextLabel("SHISHA - BAR\n" COLOR_HEX_WHITE "Tippe /Getraenk", COLOR_BLUE, SHISHABAR_DRINK_POINT, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SHISHABAR_INTERIOR);
    text3D_shishaBar[5] = _:CreateDynamic3DTextLabel("Spielautomat\n" COLOR_HEX_YELLOW "Tippe /Spielautomat", COLOR_ORANGE, SHISHABAR_SLOTS_POINT, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SHISHABAR_INTERIOR);
    text3D_shishaBar[6] = _:CreateDynamic3DTextLabel("SHISHA - LOUNGE\n" COLOR_HEX_BLUE "Befehl: /Shisha", COLOR_YELLOW, SHISHABAR_PIPES_POINT, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SHISHABAR_INTERIOR);

    // Actors
    actor_shishaBar[0] = CreateDynamicActor(178, 1773.0791, -1305.8956, 120.8335, 309.2963, .worldid = VW_MAIN, .interiorid = MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE); // STR_C2
    ApplyDynamicActorAnimation(actor_shishaBar[0], "STRIP", "STR_C2", 4.0, 1, 0, 0, 0, 0);
    actor_shishaBar[1] = CreateDynamicActor(244, 1773.3668, -1301.5859, 120.8335, 244.9450, .worldid = VW_MAIN, .interiorid = MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE); // STR_LOOP_B
    ApplyDynamicActorAnimation(actor_shishaBar[1], "STRIP", "STR_LOOP_B", 4.0, 1, 0, 0, 0, 0);
    actor_shishaBar[2] = CreateDynamicActor(246, 1776.0927, -1306.4264, 120.8335, 352.8502, .worldid = VW_MAIN, .interiorid = MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE); // STR_A2B
    ApplyDynamicActorAnimation(actor_shishaBar[2], "STRIP", "STR_A2B", 4.0, 1, 0, 0, 0, 0);
    actor_shishaBar[3] = CreateDynamicActor(257, 1780.1315, -1300.4202, 120.7395, 342.7451, .worldid = VW_MAIN, .interiorid = MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE); // STR_B2C
    ApplyDynamicActorAnimation(actor_shishaBar[3], "STRIP", "STR_B2C", 4.0, 1, 0, 0, 0, 0);
    actor_shishaBar[4] = CreateDynamicActor(238, 1786.6031, -1311.8911, 120.2656, 180.0000, .worldid = VW_MAIN, .interiorid = MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE); // STRIP_G
    ApplyDynamicActorAnimation(actor_shishaBar[4], "STRIP", "STRIP_G", 4.0, 1, 0, 0, 0, 0);

	// Objects
    object_shishaBar[0] = CreateDynamicObject(11686, 1816.3457, -1299.1093, 119.2656, 0.0000, 0.0000, -89.6999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CBarSection1
    object_shishaBar[1] = CreateDynamicObject(11686, 1816.3199, -1294.3095, 119.2656, 0.0000, 0.0000, -89.6999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CBarSection1
    object_shishaBar[2] = CreateDynamicObject(11686, 1816.2944, -1289.5101, 119.2656, 0.0000, 0.0000, -89.6999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CBarSection1
    object_shishaBar[3] = CreateDynamicObject(1665, 1816.2926, -1287.6877, 120.3756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propashtray1
    object_shishaBar[4] = CreateDynamicObject(1666, 1816.3771, -1289.2325, 120.4356, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propbeerglass1
    object_shishaBar[5] = CreateDynamicObject(1666, 1816.3771, -1289.6125, 120.4356, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propbeerglass1
    object_shishaBar[6] = CreateDynamicObject(1546, 1816.2823, -1291.6960, 120.4356, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[7] = CreateDynamicObject(1546, 1816.2823, -1292.1962, 120.4356, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[8] = CreateDynamicObject(19823, 1816.4140, -1294.6036, 120.3556, 0.0000, 0.0000, -88.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle4
    object_shishaBar[9] = CreateDynamicObject(19823, 1816.4053, -1294.1539, 120.3556, 0.0000, 0.0000, -88.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle4
    object_shishaBar[10] = CreateDynamicObject(19822, 1816.3410, -1296.4802, 120.3356, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle3
    object_shishaBar[11] = CreateDynamicObject(19822, 1816.3410, -1296.9907, 120.3356, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle3
    object_shishaBar[12] = CreateDynamicObject(1517, 1816.4199, -1298.8927, 120.5656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_BREAK
    object_shishaBar[13] = CreateDynamicObject(1517, 1816.4199, -1299.3625, 120.5656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_BREAK
    object_shishaBar[14] = CreateDynamicObject(2778, 1819.7166, -1286.4864, 119.2656, 0.0000, 0.0000, -179.3999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_COIN_OP_1
    object_shishaBar[15] = CreateDynamicObject(2681, 1821.5029, -1286.5346, 119.2656, 0.0000, 0.0000, -179.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_COIN_OP
    object_shishaBar[16] = CreateDynamicObject(2779, 1823.3666, -1286.4697, 119.2656, 0.0000, 0.0000, 179.2000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_COIN_OP_2
    object_shishaBar[17] = CreateDynamicObject(1716, 1819.9893, -1284.7177, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_slot_stool
    object_shishaBar[18] = CreateDynamicObject(1716, 1821.7298, -1284.7177, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_slot_stool
    object_shishaBar[19] = CreateDynamicObject(1716, 1823.6701, -1284.7177, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_slot_stool
    object_shishaBar[20] = CreateDynamicObject(18648, 1818.4602, -1287.9688, 124.1856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[21] = CreateDynamicObject(18648, 1818.4602, -1289.8986, 124.1856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[22] = CreateDynamicObject(18648, 1818.4602, -1291.7686, 124.1856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[23] = CreateDynamicObject(18648, 1818.4602, -1293.6887, 124.1856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[24] = CreateDynamicObject(18648, 1818.4602, -1295.6893, 124.1856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[25] = CreateDynamicObject(18648, 1818.4602, -1297.6296, 124.1856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[26] = CreateDynamicObject(18648, 1818.4602, -1299.4494, 124.1856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[27] = CreateDynamicObject(18648, 1818.4602, -1301.2993, 124.1856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[28] = CreateDynamicObject(11717, 1824.5942, -1289.1258, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[29] = CreateDynamicObject(11717, 1824.5852, -1292.9472, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[30] = CreateDynamicObject(11717, 1824.6123, -1296.4989, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[31] = CreateDynamicObject(11717, 1824.6190, -1299.7102, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[32] = CreateDynamicObject(11717, 1824.6177, -1303.2119, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[33] = CreateDynamicObject(11717, 1824.6083, -1307.0228, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[34] = CreateDynamicObject(11717, 1824.5703, -1310.3725, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[35] = CreateDynamicObject(2111, 1826.4868, -1289.1630, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[36] = CreateDynamicObject(2111, 1826.4868, -1293.0534, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[37] = CreateDynamicObject(2111, 1826.4868, -1296.4935, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[38] = CreateDynamicObject(2111, 1826.4868, -1299.7033, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[39] = CreateDynamicObject(2111, 1826.4868, -1303.2337, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[40] = CreateDynamicObject(2111, 1826.4868, -1306.9942, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[41] = CreateDynamicObject(2111, 1833.4071, -1310.3945, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[42] = CreateDynamicObject(19362, 1782.8582, -1296.6149, 124.5186, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall010
    SetDynamicObjectMaterial(object_shishaBar[42], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    object_shishaBar[43] = CreateDynamicObject(11717, 1828.3760, -1307.0758, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[44] = CreateDynamicObject(11717, 1828.4234, -1303.3447, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[45] = CreateDynamicObject(11717, 1828.4088, -1299.6920, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[46] = CreateDynamicObject(11717, 1828.3723, -1296.3895, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[47] = CreateDynamicObject(11717, 1828.3532, -1292.8668, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[48] = CreateDynamicObject(11717, 1828.3835, -1289.0454, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[49] = CreateDynamicObject(11717, 1835.2956, -1310.6854, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[50] = CreateDynamicObject(11717, 1835.2832, -1307.2929, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[51] = CreateDynamicObject(11717, 1835.2706, -1303.5603, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[52] = CreateDynamicObject(11717, 1835.3056, -1299.9091, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[53] = CreateDynamicObject(11717, 1835.2794, -1296.6071, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[54] = CreateDynamicObject(11717, 1835.3096, -1293.0854, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[55] = CreateDynamicObject(11717, 1835.3001, -1289.2623, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[56] = CreateDynamicObject(11717, 1831.6077, -1310.5565, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[57] = CreateDynamicObject(2111, 1826.4868, -1310.3945, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[58] = CreateDynamicObject(2111, 1833.4071, -1307.3443, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[59] = CreateDynamicObject(2111, 1833.4071, -1303.5438, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[60] = CreateDynamicObject(2111, 1833.4071, -1299.8635, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[61] = CreateDynamicObject(2111, 1833.4071, -1296.5732, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[62] = CreateDynamicObject(2111, 1833.4071, -1293.0932, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[63] = CreateDynamicObject(2111, 1833.4071, -1289.2725, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_DINNING_5
    object_shishaBar[64] = CreateDynamicObject(11717, 1831.6223, -1289.3092, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[65] = CreateDynamicObject(11717, 1831.6037, -1293.0900, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[66] = CreateDynamicObject(11717, 1831.5531, -1296.5596, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[67] = CreateDynamicObject(11717, 1831.5667, -1299.8718, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[68] = CreateDynamicObject(11717, 1831.5097, -1303.5612, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[69] = CreateDynamicObject(11717, 1831.5917, -1307.2844, 119.2656, 0.0000, 0.0000, 88.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[70] = CreateDynamicObject(19324, 1790.9886, -1303.7802, 119.8556, 0.0000, 0.0000, 89.2999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Unknown Model
    object_shishaBar[71] = CreateDynamicObject(2872, 1834.4843, -1274.2832, 119.2656, 0.0000, 0.0000, -50.4999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_COIN_OP_3
    object_shishaBar[72] = CreateDynamicObject(2872, 1833.1866, -1272.7095, 119.2656, 0.0000, 0.0000, -50.4999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_COIN_OP_3
    object_shishaBar[73] = CreateDynamicObject(2872, 1831.7561, -1270.9738, 119.2656, 0.0000, 0.0000, -50.4999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_COIN_OP_3
    object_shishaBar[74] = CreateDynamicObject(1820, 1833.2353, -1274.1413, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_LOW_4
    object_shishaBar[75] = CreateDynamicObject(1820, 1831.9652, -1272.3913, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_LOW_4
    object_shishaBar[76] = CreateDynamicObject(1487, 1833.8437, -1273.8404, 119.9456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_1
    object_shishaBar[77] = CreateDynamicObject(1487, 1833.5334, -1273.4100, 119.9456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_1
    object_shishaBar[78] = CreateDynamicObject(1487, 1832.2429, -1271.7996, 119.9456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_1
    object_shishaBar[79] = CreateDynamicObject(1487, 1832.6433, -1272.1197, 119.9456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_1
    object_shishaBar[80] = CreateDynamicObject(1722, 1818.8923, -1274.5881, 119.2656, 0.0000, 0.0000, 107.0999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_shishaBar[81] = CreateDynamicObject(1722, 1815.3126, -1276.1561, 119.2656, 0.0000, 0.0000, -71.0997, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_shishaBar[82] = CreateDynamicObject(1722, 1815.3045, -1274.4656, 119.2656, 0.0000, 0.0000, -105.6997, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_shishaBar[83] = CreateDynamicObject(338, 1797.8356, -1305.2539, 120.0625, 0.0000, -89.3998, -1.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //poolcue
    object_shishaBar[84] = CreateDynamicObject(19474, 1823.4468, -1275.3127, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pokertable01
    object_shishaBar[85] = CreateDynamicObject(18648, 1823.7204, -1288.3282, 124.3455, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[86] = CreateDynamicObject(18648, 1823.7204, -1290.9685, 124.3455, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[87] = CreateDynamicObject(18648, 1823.7204, -1293.1987, 124.3455, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[88] = CreateDynamicObject(18648, 1823.7204, -1295.2790, 124.3455, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[89] = CreateDynamicObject(18648, 1823.7204, -1298.0092, 124.3455, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[90] = CreateDynamicObject(18648, 1823.7204, -1300.7293, 124.3455, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[91] = CreateDynamicObject(18648, 1823.7204, -1303.2193, 124.3455, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[92] = CreateDynamicObject(18648, 1823.7204, -1306.1097, 124.3455, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[93] = CreateDynamicObject(18648, 1823.7204, -1308.7401, 124.3455, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[94] = CreateDynamicObject(18648, 1823.7204, -1310.6801, 124.3455, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[95] = CreateDynamicObject(19474, 1817.1367, -1275.3127, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pokertable01
    object_shishaBar[96] = CreateDynamicObject(2726, 1827.1383, -1289.1815, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[97] = CreateDynamicObject(2726, 1825.8881, -1289.1815, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[98] = CreateDynamicObject(1546, 1797.5006, -1302.8020, 120.2056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[99] = CreateDynamicObject(1722, 1821.6929, -1275.9057, 119.2656, 0.0000, 0.0000, -71.0997, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_shishaBar[100] = CreateDynamicObject(1722, 1821.6827, -1274.4202, 119.2756, 0.0000, 0.0000, -109.5998, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_shishaBar[101] = CreateDynamicObject(1722, 1818.9737, -1276.0059, 119.2656, 0.0000, 0.0000, 76.4001, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_shishaBar[102] = CreateDynamicObject(1722, 1825.2877, -1274.5440, 119.2756, 0.0000, 0.0000, 108.8002, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_shishaBar[103] = CreateDynamicObject(1722, 1825.1418, -1276.1889, 119.2756, 0.0000, 0.0000, 68.3002, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
    object_shishaBar[104] = CreateDynamicObject(2357, 1797.2572, -1304.4626, 119.6855, 0.0000, 0.0000, -87.6999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DUNC_DINNING
    object_shishaBar[105] = CreateDynamicObject(1546, 1797.1606, -1303.4520, 120.2056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[106] = CreateDynamicObject(1546, 1796.9504, -1304.0322, 120.2056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[107] = CreateDynamicObject(2345, 1824.3966, -1288.0844, 121.5956, 0.0000, 0.0000, 86.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_shishaBar[108] = CreateDynamicObject(19604, 1817.0146, -1272.5106, 119.1840, -89.9001, 31.0000, 61.7000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WaterPlane2
    object_shishaBar[109] = CreateDynamicObject(1902, 1823.7431, -1275.5822, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chip_stack08
    object_shishaBar[110] = CreateDynamicObject(1902, 1823.6030, -1275.5822, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chip_stack08
    object_shishaBar[111] = CreateDynamicObject(19173, 1818.4260, -1289.7772, 122.8255, 0.0000, 0.0000, -90.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_shishaBar[112] = CreateDynamicObject(19173, 1818.3698, -1293.8074, 122.8255, 0.0000, 0.0000, -90.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_shishaBar[113] = CreateDynamicObject(19173, 1818.3239, -1297.1273, 122.8255, 0.0000, 0.0000, -90.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_shishaBar[114] = CreateDynamicObject(19173, 1818.2805, -1300.2774, 122.8255, 0.0000, 0.0000, -90.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_shishaBar[115] = CreateDynamicObject(19174, 1806.3653, -1303.8137, 122.3556, 0.0000, 0.0000, -91.0999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    object_shishaBar[116] = CreateDynamicObject(2261, 1822.3410, -1286.4534, 121.6756, 0.0000, 0.0000, 175.9999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_2
    object_shishaBar[117] = CreateDynamicObject(2261, 1820.6652, -1286.3363, 121.6756, 0.0000, 0.0000, 175.9999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_2
    object_shishaBar[118] = CreateDynamicObject(11691, 1808.1741, -1300.6264, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CTable2
    object_shishaBar[119] = CreateDynamicObject(11691, 1813.5247, -1300.6264, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CTable2
    object_shishaBar[120] = CreateDynamicObject(19893, 1814.2259, -1300.4549, 120.0356, 0.0000, 0.0000, -178.5999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_shishaBar[121] = CreateDynamicObject(19893, 1812.6865, -1300.4925, 120.0356, 0.0000, 0.0000, -178.5999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_shishaBar[122] = CreateDynamicObject(19893, 1808.9267, -1300.5843, 120.0356, 0.0000, 0.0000, -178.5999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_shishaBar[123] = CreateDynamicObject(19893, 1807.4473, -1300.6204, 120.0356, 0.0000, 0.0000, -178.5999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_shishaBar[124] = CreateDynamicObject(1716, 1809.2525, -1298.8336, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_slot_stool
    object_shishaBar[125] = CreateDynamicObject(1716, 1807.7821, -1298.8336, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_slot_stool
    object_shishaBar[126] = CreateDynamicObject(1716, 1813.1025, -1298.8336, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_slot_stool
    object_shishaBar[127] = CreateDynamicObject(1716, 1814.6026, -1298.8336, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_slot_stool
    object_shishaBar[128] = CreateDynamicObject(18756, 1788.4125, -1303.2031, 121.1455, 0.0000, 0.0000, -90.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElevatorDoor1
    object_shishaBar[129] = CreateDynamicObject(18756, 1786.4328, -1303.1655, 121.1455, 0.0000, 0.0000, -90.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElevatorDoor1
    object_shishaBar[130] = CreateDynamicObject(19325, 1832.4099, -1311.7321, 121.2856, 0.0000, 0.0000, -89.6999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_shishaBar[130], 0, 16640, "a51", "a51_glass", 0xFFFFFFFF);
    object_shishaBar[131] = CreateDynamicObject(970, 1833.6634, -1286.9780, 119.8256, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_shishaBar[131], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_shishaBar[132] = CreateDynamicObject(11717, 1828.3890, -1310.4683, 119.2656, 0.0000, 0.0000, -91.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WooziesCouch1
    object_shishaBar[133] = CreateDynamicObject(970, 1826.2825, -1286.9780, 119.8256, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_shishaBar[133], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_shishaBar[134] = CreateDynamicObject(1546, 1797.5504, -1304.0322, 120.2056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[135] = CreateDynamicObject(18762, 1816.2034, -1289.5738, 124.4155, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    object_shishaBar[136] = CreateDynamicObject(19325, 1816.3483, -1312.0989, 125.4056, 0.0000, 0.0000, -80.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    object_shishaBar[137] = CreateDynamicObject(18762, 1816.2034, -1294.5350, 124.4155, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    object_shishaBar[138] = CreateDynamicObject(2452, 1810.6342, -1312.0368, 119.2656, 0.0000, 0.0000, -179.2000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_FRIDGE2
    object_shishaBar[139] = CreateDynamicObject(2452, 1813.1638, -1312.0013, 119.2656, 0.0000, 0.0000, -179.2000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_FRIDGE2
    object_shishaBar[140] = CreateDynamicObject(1814, 1828.0527, -1314.1810, 119.2587, -0.7999, 0.0000, -91.0999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_MED_1
    object_shishaBar[141] = CreateDynamicObject(2028, 1828.5344, -1314.6685, 119.8205, 2.4000, 0.0000, -90.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_CONSOLE
    object_shishaBar[142] = CreateDynamicObject(1814, 1816.4316, -1306.9161, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_MED_1
    object_shishaBar[143] = CreateDynamicObject(1814, 1814.7315, -1306.9161, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_MED_1
    object_shishaBar[144] = CreateDynamicObject(1814, 1813.0313, -1306.9161, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_MED_1
    object_shishaBar[145] = CreateDynamicObject(1814, 1811.3208, -1306.9161, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_MED_1
    object_shishaBar[146] = CreateDynamicObject(1814, 1809.6203, -1306.9161, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_MED_1
    object_shishaBar[147] = CreateDynamicObject(19525, 1810.6015, -1306.5555, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WeddingCake1
    object_shishaBar[148] = CreateDynamicObject(2452, 1808.1137, -1312.0712, 119.2656, 0.0000, 0.0000, -179.2000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FF_FRIDGE2
    object_shishaBar[149] = CreateDynamicObject(19525, 1809.6414, -1306.5555, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WeddingCake1
    object_shishaBar[150] = CreateDynamicObject(11740, 1811.3000, -1306.5478, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MCake2
    object_shishaBar[151] = CreateDynamicObject(11740, 1811.8803, -1306.5478, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MCake2
    object_shishaBar[152] = CreateDynamicObject(11740, 1812.3608, -1306.5478, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MCake2
    object_shishaBar[153] = CreateDynamicObject(2726, 1812.9804, -1306.6339, 120.1156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[154] = CreateDynamicObject(2726, 1813.5805, -1306.6339, 120.1156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[155] = CreateDynamicObject(1546, 1826.9772, -1288.8706, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[156] = CreateDynamicObject(1546, 1826.0368, -1288.8706, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[157] = CreateDynamicObject(1546, 1826.0368, -1289.5008, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[158] = CreateDynamicObject(1546, 1826.9768, -1289.5008, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[159] = CreateDynamicObject(18762, 1816.2034, -1299.4458, 124.4155, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    object_shishaBar[160] = CreateDynamicObject(19786, 1810.8413, -1301.6514, 122.8455, 0.0000, 0.0000, -179.1000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    object_shishaBar[161] = CreateDynamicObject(1703, 1818.7158, -1314.5778, 119.2585, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch02
    object_shishaBar[162] = CreateDynamicObject(1557, 1806.4067, -1306.7115, 119.2527, -0.4999, 0.0000, -89.6000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT19
    object_shishaBar[163] = CreateDynamicObject(19387, 1806.4539, -1307.5024, 121.0186, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    object_shishaBar[164] = CreateDynamicObject(19362, 1806.5100, -1310.6368, 124.4986, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall010
    SetDynamicObjectMaterial(object_shishaBar[164], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    object_shishaBar[165] = CreateDynamicObject(19362, 1806.5100, -1307.4462, 124.4986, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall010
    SetDynamicObjectMaterial(object_shishaBar[165], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    object_shishaBar[166] = CreateDynamicObject(19325, 1825.7795, -1311.7668, 121.2856, 0.0000, 0.0000, -89.6999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_shishaBar[166], 0, 16640, "a51", "a51_glass", 0xFFFFFFFF);
    object_shishaBar[167] = CreateDynamicObject(1546, 1826.0368, -1292.6209, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[168] = CreateDynamicObject(1546, 1826.0368, -1293.3913, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[169] = CreateDynamicObject(1546, 1826.8873, -1293.3413, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[170] = CreateDynamicObject(1546, 1826.8973, -1292.6312, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[171] = CreateDynamicObject(1546, 1826.8973, -1296.1911, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[172] = CreateDynamicObject(1546, 1826.8973, -1296.9914, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[173] = CreateDynamicObject(1546, 1826.1466, -1296.9914, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[174] = CreateDynamicObject(1546, 1826.1466, -1296.1510, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[175] = CreateDynamicObject(1546, 1826.1466, -1299.2412, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[176] = CreateDynamicObject(1546, 1826.1466, -1300.0513, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[177] = CreateDynamicObject(1546, 1826.9067, -1300.0513, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[178] = CreateDynamicObject(1546, 1826.9067, -1299.2711, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[179] = CreateDynamicObject(1546, 1826.9067, -1302.8107, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[180] = CreateDynamicObject(1546, 1826.9067, -1303.5610, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[181] = CreateDynamicObject(1546, 1826.0762, -1303.5610, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[182] = CreateDynamicObject(1546, 1826.0762, -1302.7906, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[183] = CreateDynamicObject(1546, 1826.0762, -1306.6608, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[184] = CreateDynamicObject(1546, 1833.0270, -1292.7867, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[185] = CreateDynamicObject(1546, 1826.8966, -1307.3410, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[186] = CreateDynamicObject(1546, 1826.8966, -1306.6506, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[187] = CreateDynamicObject(1546, 1826.2164, -1310.0709, 119.7555, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[188] = CreateDynamicObject(1546, 1826.1060, -1310.8715, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[189] = CreateDynamicObject(1546, 1826.8966, -1310.8615, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[190] = CreateDynamicObject(1546, 1826.8966, -1310.0112, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[191] = CreateDynamicObject(1546, 1832.9769, -1310.0112, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[192] = CreateDynamicObject(1546, 1833.8369, -1307.0607, 119.7656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[193] = CreateDynamicObject(1546, 1832.9769, -1310.7213, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[194] = CreateDynamicObject(1546, 1833.8472, -1310.7213, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[195] = CreateDynamicObject(1546, 1833.8472, -1309.9711, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[196] = CreateDynamicObject(1546, 1833.8472, -1307.7908, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[197] = CreateDynamicObject(1546, 1832.9670, -1307.7908, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[198] = CreateDynamicObject(1546, 1832.8468, -1296.9008, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[199] = CreateDynamicObject(1546, 1832.9670, -1307.0111, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[200] = CreateDynamicObject(1546, 1832.9670, -1303.9307, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[201] = CreateDynamicObject(1546, 1832.9670, -1303.1405, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[202] = CreateDynamicObject(1546, 1833.8375, -1303.1405, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[203] = CreateDynamicObject(1546, 1833.8375, -1303.8505, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[204] = CreateDynamicObject(1546, 1833.9270, -1296.9008, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[205] = CreateDynamicObject(1546, 1826.0762, -1307.3410, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[206] = CreateDynamicObject(1546, 1833.8375, -1300.2006, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[207] = CreateDynamicObject(1546, 1833.8375, -1299.5207, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[208] = CreateDynamicObject(1546, 1833.9270, -1296.1107, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[209] = CreateDynamicObject(1546, 1832.8470, -1299.5207, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[210] = CreateDynamicObject(1546, 1832.8470, -1300.2309, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[211] = CreateDynamicObject(1546, 1832.9562, -1296.1107, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[212] = CreateDynamicObject(1546, 1833.0270, -1293.4769, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[213] = CreateDynamicObject(1546, 1833.8073, -1293.4769, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[214] = CreateDynamicObject(1546, 1833.8073, -1292.7069, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[215] = CreateDynamicObject(1546, 1832.8569, -1288.8754, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[216] = CreateDynamicObject(1546, 1833.8073, -1288.8963, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[217] = CreateDynamicObject(1546, 1833.8073, -1289.6564, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[218] = CreateDynamicObject(1546, 1832.8872, -1289.6564, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PINT_GLASS
    object_shishaBar[219] = CreateDynamicObject(2231, 1823.8513, -1287.0045, 123.1682, -0.2000, -0.1000, 90.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_SPEAKER_3
    object_shishaBar[220] = CreateDynamicObject(2231, 1823.8513, -1311.2065, 123.1260, -0.2000, -0.1000, 90.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_SPEAKER_3
    object_shishaBar[221] = CreateDynamicObject(2345, 1824.2791, -1290.1815, 121.5956, 0.0000, 0.0000, 86.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_shishaBar[222] = CreateDynamicObject(2345, 1824.1633, -1292.2484, 121.5956, 0.0000, 0.0000, 86.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_shishaBar[223] = CreateDynamicObject(2345, 1824.3527, -1292.2589, 121.5956, 0.0000, 0.0000, 86.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_shishaBar[224] = CreateDynamicObject(2345, 1824.4044, -1294.3856, 121.5956, 0.0000, 0.0000, 86.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_shishaBar[225] = CreateDynamicObject(2345, 1824.2817, -1296.5729, 121.5956, 0.0000, 0.0000, 86.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_shishaBar[226] = CreateDynamicObject(2345, 1824.2912, -1298.7373, 121.5956, 0.0000, 0.0000, 86.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_shishaBar[227] = CreateDynamicObject(2345, 1824.2707, -1300.7194, 121.5956, 0.0000, 0.0000, 86.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_shishaBar[228] = CreateDynamicObject(2345, 1824.3184, -1302.7353, 121.5956, 0.0000, 0.0000, 86.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_shishaBar[229] = CreateDynamicObject(2345, 1824.2827, -1304.8067, 121.5956, 0.0000, 0.0000, 86.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_shishaBar[230] = CreateDynamicObject(2345, 1824.2796, -1306.8302, 121.5956, 0.0000, 0.0000, 86.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_shishaBar[231] = CreateDynamicObject(2345, 1824.2873, -1308.8443, 121.5956, 0.0000, 0.0000, 86.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_shishaBar[232] = CreateDynamicObject(2345, 1824.3015, -1310.7390, 121.5956, 0.0000, 0.0000, 86.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_23
    object_shishaBar[233] = CreateDynamicObject(19604, 1833.6431, -1315.6859, 119.4110, -90.5000, 61.2000, 121.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WaterPlane2
    object_shishaBar[234] = CreateDynamicObject(2726, 1834.0800, -1289.2515, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[235] = CreateDynamicObject(2726, 1832.7600, -1289.2515, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[236] = CreateDynamicObject(2726, 1832.7600, -1293.1022, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[237] = CreateDynamicObject(2248, 1819.9473, -1271.0653, 119.8256, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_16
    object_shishaBar[238] = CreateDynamicObject(2726, 1834.0800, -1293.1022, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[239] = CreateDynamicObject(2726, 1834.0800, -1296.6124, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[240] = CreateDynamicObject(2726, 1832.7193, -1296.6124, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[241] = CreateDynamicObject(2726, 1832.7193, -1299.8829, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[242] = CreateDynamicObject(2726, 1834.0997, -1299.8829, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[243] = CreateDynamicObject(2726, 1834.0997, -1303.5632, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[244] = CreateDynamicObject(2726, 1832.8098, -1303.5632, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[245] = CreateDynamicObject(2248, 1814.4299, -1274.3493, 119.7856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_16
    object_shishaBar[246] = CreateDynamicObject(2726, 1832.8098, -1307.4045, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[247] = CreateDynamicObject(2726, 1834.1502, -1307.4045, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[248] = CreateDynamicObject(2726, 1834.1502, -1310.3950, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[249] = CreateDynamicObject(2726, 1832.7402, -1310.3950, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[250] = CreateDynamicObject(2726, 1825.8881, -1293.0618, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[251] = CreateDynamicObject(2726, 1827.1583, -1293.0618, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[252] = CreateDynamicObject(2726, 1827.1583, -1296.5617, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[253] = CreateDynamicObject(2726, 1825.8377, -1296.5617, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[254] = CreateDynamicObject(2726, 1825.8377, -1299.6716, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[255] = CreateDynamicObject(2726, 1827.2280, -1299.6716, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[256] = CreateDynamicObject(2726, 1827.2280, -1303.3120, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[257] = CreateDynamicObject(2726, 1825.8073, -1303.3120, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[258] = CreateDynamicObject(2726, 1825.8073, -1307.0422, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[259] = CreateDynamicObject(2726, 1827.1876, -1307.0422, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[260] = CreateDynamicObject(2726, 1827.1876, -1310.3931, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[261] = CreateDynamicObject(2726, 1825.7473, -1310.3931, 120.0056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[262] = CreateDynamicObject(19564, 1815.7397, -1306.7443, 119.7556, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //JuiceBox2
    object_shishaBar[263] = CreateDynamicObject(2726, 1814.1510, -1306.6339, 120.1156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[264] = CreateDynamicObject(19564, 1815.2995, -1306.7443, 119.7556, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //JuiceBox2
    object_shishaBar[265] = CreateDynamicObject(19564, 1814.7897, -1306.7443, 119.7556, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //JuiceBox2
    object_shishaBar[266] = CreateDynamicObject(19811, 1817.3308, -1306.6772, 119.8285, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BurgerBox1
    object_shishaBar[267] = CreateDynamicObject(19811, 1816.9105, -1306.6772, 119.8285, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BurgerBox1
    object_shishaBar[268] = CreateDynamicObject(2726, 1813.5119, -1300.3937, 120.3856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[269] = CreateDynamicObject(2726, 1808.2114, -1300.3937, 120.3856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[270] = CreateDynamicObject(2726, 1816.3552, -1301.1082, 120.7156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[271] = CreateDynamicObject(19173, 1824.2160, -1303.4705, 123.0556, 0.0000, 0.0000, -89.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_shishaBar[272] = CreateDynamicObject(19173, 1824.2326, -1290.0269, 123.0556, 0.0000, 0.0000, -89.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_shishaBar[273] = CreateDynamicObject(19173, 1824.2071, -1294.3083, 123.0556, 0.0000, 0.0000, -89.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_shishaBar[274] = CreateDynamicObject(19173, 1824.2354, -1298.8291, 123.0556, 0.0000, 0.0000, -89.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_shishaBar[275] = CreateDynamicObject(19173, 1824.2214, -1307.8314, 123.0556, 0.0000, 0.0000, -89.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_shishaBar[276] = CreateDynamicObject(19089, 1834.9910, -1313.2392, 126.5956, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    object_shishaBar[277] = CreateDynamicObject(18762, 1818.5446, -1289.6136, 119.7255, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    object_shishaBar[278] = CreateDynamicObject(18762, 1818.5446, -1294.6046, 119.7255, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    object_shishaBar[279] = CreateDynamicObject(19362, 1782.8582, -1299.8051, 121.0085, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall010
    SetDynamicObjectMaterial(object_shishaBar[279], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    object_shishaBar[280] = CreateDynamicObject(19089, 1832.3613, -1318.0505, 126.5956, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    object_shishaBar[281] = CreateDynamicObject(18762, 1818.5446, -1299.5645, 119.7255, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    object_shishaBar[282] = CreateDynamicObject(19822, 1818.2104, -1288.5251, 120.2156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle3
    object_shishaBar[283] = CreateDynamicObject(19822, 1818.2104, -1289.2457, 120.2156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle3
    object_shishaBar[284] = CreateDynamicObject(19822, 1818.2104, -1289.8659, 120.2156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle3
    object_shishaBar[285] = CreateDynamicObject(1541, 1818.3902, -1289.1953, 121.2756, 0.0000, 0.0000, -89.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_TAPS_1
    object_shishaBar[286] = CreateDynamicObject(19824, 1818.1745, -1291.2247, 120.1956, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle5
    object_shishaBar[287] = CreateDynamicObject(19824, 1818.1745, -1291.6549, 120.1956, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle5
    object_shishaBar[288] = CreateDynamicObject(1541, 1818.3928, -1290.5958, 121.2756, 0.0000, 0.0000, -89.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_TAPS_1
    object_shishaBar[289] = CreateDynamicObject(1541, 1818.3951, -1292.0662, 121.2756, 0.0000, 0.0000, -89.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_TAPS_1
    object_shishaBar[290] = CreateDynamicObject(1541, 1818.3983, -1293.8261, 121.2756, 0.0000, 0.0000, -89.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_TAPS_1
    object_shishaBar[291] = CreateDynamicObject(19824, 1818.1745, -1292.0051, 120.1956, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle5
    object_shishaBar[292] = CreateDynamicObject(1541, 1818.4011, -1295.4664, 121.2756, 0.0000, 0.0000, -89.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_TAPS_1
    object_shishaBar[293] = CreateDynamicObject(1541, 1818.4038, -1297.0566, 121.2756, 0.0000, 0.0000, -89.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_TAPS_1
    object_shishaBar[294] = CreateDynamicObject(1541, 1818.4067, -1298.6763, 121.2756, 0.0000, 0.0000, -89.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_TAPS_1
    object_shishaBar[295] = CreateDynamicObject(1541, 1818.4088, -1300.0167, 121.2756, 0.0000, 0.0000, -89.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_TAPS_1
    object_shishaBar[296] = CreateDynamicObject(19824, 1818.1745, -1292.3652, 120.1956, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle5
    object_shishaBar[297] = CreateDynamicObject(1520, 1818.1490, -1293.6888, 120.2456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_BOUNCE
    object_shishaBar[298] = CreateDynamicObject(1520, 1818.1490, -1293.9989, 120.2456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_BOUNCE
    object_shishaBar[299] = CreateDynamicObject(1520, 1818.1490, -1294.2590, 120.2456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_BOUNCE
    object_shishaBar[300] = CreateDynamicObject(19820, 1818.2259, -1295.0632, 120.1756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle1
    object_shishaBar[301] = CreateDynamicObject(19820, 1818.2259, -1295.4936, 120.1756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle1
    object_shishaBar[302] = CreateDynamicObject(19820, 1818.2259, -1295.9038, 120.1756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle1
    object_shishaBar[303] = CreateDynamicObject(19821, 1818.1968, -1296.9201, 120.1956, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle2
    object_shishaBar[304] = CreateDynamicObject(1716, 1815.6839, -1297.6225, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_slot_stool
    object_shishaBar[305] = CreateDynamicObject(19821, 1818.1968, -1297.2705, 120.1956, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle2
    object_shishaBar[306] = CreateDynamicObject(19821, 1818.1968, -1297.5805, 120.1956, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle2
    object_shishaBar[307] = CreateDynamicObject(19823, 1818.2147, -1298.4753, 120.2256, 0.0000, 0.0000, -95.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle4
    object_shishaBar[308] = CreateDynamicObject(19823, 1818.1832, -1298.7843, 120.2256, 0.0000, 0.0000, -95.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle4
    object_shishaBar[309] = CreateDynamicObject(19823, 1818.1528, -1299.0832, 120.2256, 0.0000, 0.0000, -95.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle4
    object_shishaBar[310] = CreateDynamicObject(1668, 1818.1727, -1299.7784, 120.3956, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propvodkabotl1
    object_shishaBar[311] = CreateDynamicObject(1716, 1815.6839, -1295.1433, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_slot_stool
    object_shishaBar[312] = CreateDynamicObject(1668, 1818.1727, -1300.0286, 120.3956, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propvodkabotl1
    object_shishaBar[313] = CreateDynamicObject(1668, 1818.1727, -1300.3087, 120.3956, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propvodkabotl1
    object_shishaBar[314] = CreateDynamicObject(1716, 1815.6839, -1292.8232, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_slot_stool
    object_shishaBar[315] = CreateDynamicObject(2726, 1818.2451, -1301.1082, 120.5856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[316] = CreateDynamicObject(1716, 1815.6839, -1290.3927, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_slot_stool
    object_shishaBar[317] = CreateDynamicObject(1716, 1815.6839, -1287.9332, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_slot_stool
    object_shishaBar[318] = CreateDynamicObject(1703, 1821.6162, -1314.5780, 119.2585, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch02
    object_shishaBar[319] = CreateDynamicObject(1902, 1823.4528, -1275.5822, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chip_stack08
    object_shishaBar[320] = CreateDynamicObject(1902, 1823.3227, -1275.5822, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chip_stack08
    object_shishaBar[321] = CreateDynamicObject(1902, 1823.1926, -1275.5822, 119.7756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chip_stack08
    object_shishaBar[322] = CreateDynamicObject(1930, 1817.3236, -1274.4774, 119.7456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chip_stack13
    object_shishaBar[323] = CreateDynamicObject(1814, 1819.1618, -1316.5668, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_MED_1
    object_shishaBar[324] = CreateDynamicObject(1814, 1822.0321, -1316.5679, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_MED_1
    object_shishaBar[325] = CreateDynamicObject(1703, 1820.7456, -1317.5587, 119.2585, 0.0000, 0.0000, 179.4999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch02
    object_shishaBar[326] = CreateDynamicObject(1703, 1823.6354, -1317.5739, 119.2585, 0.0000, 0.0000, 179.4999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch02
    object_shishaBar[327] = CreateDynamicObject(2726, 1819.2116, -1315.7656, 120.1156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[328] = CreateDynamicObject(2726, 1820.1312, -1315.7650, 120.1156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[329] = CreateDynamicObject(338, 1797.8034, -1306.2241, 120.0625, 0.0000, -89.3998, -1.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //poolcue
    object_shishaBar[330] = CreateDynamicObject(1930, 1817.2135, -1274.4774, 119.7456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chip_stack13
    object_shishaBar[331] = CreateDynamicObject(338, 1797.8131, -1305.9340, 120.0625, 0.0000, -89.3998, -1.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //poolcue
    object_shishaBar[332] = CreateDynamicObject(338, 1797.8215, -1305.6740, 120.0625, 0.0000, -89.3998, -1.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //poolcue
    object_shishaBar[333] = CreateDynamicObject(338, 1797.8286, -1305.4641, 120.0625, 0.0000, -89.3998, -1.9000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //poolcue
    object_shishaBar[334] = CreateDynamicObject(2726, 1820.1312, -1316.3753, 120.1156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[335] = CreateDynamicObject(2726, 1822.0515, -1316.3778, 120.1156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[336] = CreateDynamicObject(2726, 1823.0618, -1316.4155, 120.1156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[337] = CreateDynamicObject(2726, 1819.2116, -1316.3756, 120.1156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[338] = CreateDynamicObject(2726, 1822.0515, -1315.7061, 120.1156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[339] = CreateDynamicObject(2726, 1823.0618, -1315.7060, 120.1156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LM_stripLamp
    object_shishaBar[340] = CreateDynamicObject(1551, 1818.9144, -1316.0687, 119.9756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_BIG
    object_shishaBar[341] = CreateDynamicObject(1551, 1820.3140, -1316.1464, 119.9756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_BIG
    object_shishaBar[342] = CreateDynamicObject(1551, 1821.7740, -1316.0268, 119.9756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_BIG
    object_shishaBar[343] = CreateDynamicObject(1551, 1823.2043, -1316.1571, 119.9756, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_BIG
    object_shishaBar[344] = CreateDynamicObject(19811, 1816.4805, -1306.6772, 119.8285, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BurgerBox1
    object_shishaBar[345] = CreateDynamicObject(2631, 1808.5120, -1311.3942, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[346] = CreateDynamicObject(2631, 1812.4218, -1311.3942, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[347] = CreateDynamicObject(2631, 1812.4218, -1309.5042, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[348] = CreateDynamicObject(2631, 1816.3109, -1311.4042, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[349] = CreateDynamicObject(2631, 1808.5109, -1305.6943, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[350] = CreateDynamicObject(2631, 1812.4104, -1305.7429, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[351] = CreateDynamicObject(2631, 1808.5109, -1307.5942, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[352] = CreateDynamicObject(2631, 1812.4104, -1307.5942, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[353] = CreateDynamicObject(2631, 1816.2907, -1305.7429, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[354] = CreateDynamicObject(2631, 1816.3206, -1307.5942, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[355] = CreateDynamicObject(2631, 1820.2218, -1309.5042, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[356] = CreateDynamicObject(2631, 1808.5109, -1309.5042, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[357] = CreateDynamicObject(2631, 1820.2205, -1307.5942, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[358] = CreateDynamicObject(2631, 1820.2205, -1305.6947, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[359] = CreateDynamicObject(2631, 1816.3317, -1309.5042, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[360] = CreateDynamicObject(2631, 1820.2315, -1311.4042, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[361] = CreateDynamicObject(2631, 1816.3109, -1313.3043, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[362] = CreateDynamicObject(2631, 1816.3109, -1315.2148, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[363] = CreateDynamicObject(2631, 1816.3109, -1317.1346, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[364] = CreateDynamicObject(2631, 1816.3109, -1317.9154, 119.2356, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[365] = CreateDynamicObject(2631, 1820.2105, -1313.3043, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[366] = CreateDynamicObject(2631, 1824.1103, -1312.7438, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[367] = CreateDynamicObject(2631, 1824.1103, -1314.6840, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[368] = CreateDynamicObject(2631, 1820.2200, -1316.6146, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[369] = CreateDynamicObject(2631, 1824.1103, -1317.8846, 119.2456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[370] = CreateDynamicObject(2631, 1828.0015, -1316.6146, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[371] = CreateDynamicObject(2631, 1828.0015, -1314.6735, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[372] = CreateDynamicObject(2631, 1828.0015, -1312.7429, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[373] = CreateDynamicObject(2631, 1831.9219, -1316.6146, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[374] = CreateDynamicObject(2631, 1831.9219, -1314.6542, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[375] = CreateDynamicObject(2631, 1831.9219, -1312.7142, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[376] = CreateDynamicObject(2631, 1833.7630, -1312.7042, 119.2456, 0.0000, 0.0000, 0.6000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[377] = CreateDynamicObject(2631, 1833.7835, -1314.6337, 119.2456, 0.0000, 0.0000, 0.6000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[378] = CreateDynamicObject(2631, 1828.0106, -1317.8846, 119.2456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[379] = CreateDynamicObject(2631, 1831.8903, -1317.8846, 119.2456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[380] = CreateDynamicObject(2631, 1824.1103, -1316.6146, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[381] = CreateDynamicObject(2631, 1820.2110, -1317.9154, 119.2356, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[382] = CreateDynamicObject(2631, 1820.2105, -1315.1949, 119.2556, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_mat1
    object_shishaBar[383] = CreateDynamicObject(18648, 1823.1892, -1311.7633, 124.2115, 0.0000, 0.0000, -89.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[384] = CreateDynamicObject(18648, 1821.2290, -1311.7702, 124.2115, 0.0000, 0.0000, -89.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[385] = CreateDynamicObject(19173, 1818.4525, -1310.3479, 122.7892, 0.0000, 0.0000, -89.1000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_shishaBar[386] = CreateDynamicObject(18648, 1819.4582, -1311.7768, 124.2115, 0.0000, 0.0000, -89.8000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlueNeonTube1
    object_shishaBar[387] = CreateDynamicObject(19173, 1818.4677, -1307.1573, 122.7892, 0.0000, 0.0000, -90.9999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_shishaBar[388] = CreateDynamicObject(19362, 1790.5380, -1308.0352, 121.0085, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall010
    object_shishaBar[389] = CreateDynamicObject(19362, 1790.5388, -1311.2456, 121.0085, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall010
    object_shishaBar[390] = CreateDynamicObject(19362, 1790.5479, -1308.0352, 124.5085, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall010
    object_shishaBar[391] = CreateDynamicObject(19362, 1790.5576, -1311.2257, 124.4985, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall010
    object_shishaBar[392] = CreateDynamicObject(19172, 1782.9663, -1297.9312, 120.6506, 0.0000, 0.0000, 88.7999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_shishaBar[392], 0,"+18 Lounge", 90, "Arial", 30, 1, 0xFF000000, 0x0, 0);
    object_shishaBar[393] = CreateDynamicObject(19387, 1782.8732, -1296.6119, 121.0186, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
    object_shishaBar[394] = CreateDynamicObject(19362, 1782.8582, -1299.8051, 124.5186, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall010
    SetDynamicObjectMaterial(object_shishaBar[394], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    object_shishaBar[395] = CreateDynamicObject(19173, 1806.3660, -1309.4088, 121.2356, 0.0000, 0.0000, -88.2000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_shishaBar[395], 0,"VIP Lounge", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
    object_shishaBar[396] = CreateDynamicObject(1557, 1782.9454, -1297.3392, 119.2656, -0.4999, -0.6000, 91.8999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT19
    object_shishaBar[397] = CreateDynamicObject(11685, 1786.0209, -1309.7476, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneCouch4
    object_shishaBar[398] = CreateDynamicObject(14809, 1776.4934, -1302.8065, 120.7085, 0.0000, 0.0000, -10.3999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Strip2_Platforms
    object_shishaBar[399] = CreateDynamicObject(18651, 1771.4442, -1297.8591, 124.4585, 0.0000, 0.0000, -66.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinkNeonTube1
    object_shishaBar[400] = CreateDynamicObject(18651, 1773.4528, -1296.9854, 124.4585, 0.0000, 0.0000, -66.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinkNeonTube1
    object_shishaBar[401] = CreateDynamicObject(18651, 1775.5124, -1296.1550, 124.4685, 0.0000, 0.0000, -66.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinkNeonTube1
    object_shishaBar[402] = CreateDynamicObject(18651, 1777.4322, -1295.3532, 124.4685, 0.0000, 0.0000, -66.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinkNeonTube1
    object_shishaBar[403] = CreateDynamicObject(18651, 1778.1900, -1295.0891, 124.4685, 0.0000, 0.0000, -66.5000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinkNeonTube1
    object_shishaBar[404] = CreateDynamicObject(19172, 1773.0366, -1297.8389, 122.6486, 0.0000, 0.0000, 23.6000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    object_shishaBar[405] = CreateDynamicObject(19172, 1777.1774, -1296.1275, 122.6486, 0.0000, 0.0000, 23.6000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    object_shishaBar[406] = CreateDynamicObject(1930, 1817.1134, -1274.4774, 119.7456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chip_stack13
    object_shishaBar[407] = CreateDynamicObject(1930, 1817.0133, -1274.4774, 119.7456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chip_stack13
    object_shishaBar[408] = CreateDynamicObject(1930, 1816.9031, -1274.4774, 119.7456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chip_stack13
    object_shishaBar[409] = CreateDynamicObject(2241, 1791.1684, -1302.2086, 119.7256, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_5
    object_shishaBar[410] = CreateDynamicObject(2241, 1791.1684, -1305.2789, 119.7256, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_5
    object_shishaBar[411] = CreateDynamicObject(2241, 1805.8333, -1305.0776, 119.7356, 0.0000, 0.0000, -103.0999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_5
    object_shishaBar[412] = CreateDynamicObject(2241, 1805.8146, -1302.3308, 119.7356, 0.0000, 0.0000, -103.0999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_5
    object_shishaBar[413] = CreateDynamicObject(2001, 1805.9022, -1303.7365, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant_ofc
    object_shishaBar[414] = CreateDynamicObject(2964, 1799.6865, -1304.0075, 119.2656, 0.0000, 0.0000, -87.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_pooltablesm
    object_shishaBar[415] = CreateDynamicObject(2964, 1794.9028, -1304.2583, 119.2656, 0.0000, 0.0000, -87.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_pooltablesm
    object_shishaBar[416] = CreateDynamicObject(19920, 1828.5336, -1314.0628, 119.7692, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneRemote1
    object_shishaBar[417] = CreateDynamicObject(18651, 1790.1966, -1311.7517, 122.8656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinkNeonTube1
    object_shishaBar[418] = CreateDynamicObject(18651, 1790.1966, -1308.1715, 122.8656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PinkNeonTube1
    object_shishaBar[419] = CreateDynamicObject(19172, 1784.6495, -1306.5689, 122.0856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    object_shishaBar[420] = CreateDynamicObject(19172, 1788.8997, -1306.5689, 122.0856, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    object_shishaBar[421] = CreateDynamicObject(2253, 1790.1708, -1306.7329, 119.5356, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_22
    object_shishaBar[422] = CreateDynamicObject(2253, 1782.9406, -1306.7329, 119.5356, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_22
    object_shishaBar[423] = CreateDynamicObject(2241, 1810.6530, -1301.0433, 119.7356, 0.0000, 0.0000, -103.0999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_5
    object_shishaBar[424] = CreateDynamicObject(1550, 1817.6068, -1301.3750, 119.6456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
    object_shishaBar[425] = CreateDynamicObject(1550, 1816.9661, -1301.3750, 119.6456, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
    object_shishaBar[426] = CreateDynamicObject(11685, 1787.2713, -1309.7476, 119.2656, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneCouch4
    object_shishaBar[427] = CreateDynamicObject(19786, 1829.0593, -1314.6347, 122.0955, 0.0000, 0.0000, -90.8999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_shishaBar[427], 1, 10101, "2notherbuildsfe", "ferry_build14", 0xFFFFFFFF);
    object_shishaBar[428] = CreateDynamicObject(19362, 1806.5100, -1310.6368, 121.0085, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall010
    SetDynamicObjectMaterial(object_shishaBar[428], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    object_shishaBar[429] = CreateDynamicObject(19325, 1832.4099, -1311.7321, 125.4056, 0.0000, 0.0000, -89.6999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_shishaBar[429], 0, 16640, "a51", "a51_glass", 0xFFFFFFFF);
    object_shishaBar[430] = CreateDynamicObject(19325, 1825.7795, -1311.7668, 125.4156, 0.0000, 0.0000, -89.6999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
    SetDynamicObjectMaterial(object_shishaBar[430], 0, 16640, "a51", "a51_glass", 0xFFFFFFFF);
    object_shishaBar[431] = CreateDynamicObject(18757, 1786.4008, -1303.1583, 14.6668, 0.0000, 0.0000, -89.5999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElevatorDoor2
    object_shishaBar[432] = CreateDynamicObject(18757, 1784.4310, -1303.1922, 14.6668, 0.0000, 0.0000, -89.5999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElevatorDoor2
    object_shishaBar[433] = CreateDynamicObject(19172, 1785.9235, -1301.0517, 15.5839, 0.0000, 0.0000, 179.0999, VW_MAIN, MAPS_SHISHABAR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_shishaBar[433], 0,"Shisha Lounge", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 0);
}

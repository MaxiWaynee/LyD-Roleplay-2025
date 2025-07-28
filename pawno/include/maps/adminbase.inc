#include <YSI\y_hooks>

// Global interior define
#define MAPS_ADMINBASE      0

static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 150.0;

//Enter/Exit/Heal
#define aBase_WEAPON_POINT	1285.4982, -985.8291, 32.7003
#define aBase_RANGE_COORDS	1287.9040, -1006.1270, 31.4447
#define aBase_RANGE_COORDS2	1287.9040, -966.3336, 34.7849
#define aBase_GATE_OPEN_Z   27.954719
#define aBase_GATE_CLOSED_Z 31.444799
#define aBase_GATE2_OPEN_Z   24.7849
#define aBase_GATE2_CLOSED_Z 34.7849

//#define aBase_POINT_FACING  0.0
/*#define aBase_HAZE       	1294.6079, -982.4129, 32.7531
#define aBase_KUSH        	1294.4303, -980.6702, 32.7531
#define aBase_PURPLE		1294.4307, -979.1359, 32.7531*/

//Mapvariables
//new object_aBase[69];
new object_aBase_gate[2];
//new pickup_aBase[1];


/*CMD:admintor(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 3)
		return SendClientMessage(playerid, COLOR_RED, "Nicht befugt.");

    if (IsPlayerInRangeOfPoint(playerid, 6.0, aBase_RANGE_COORDS)) {
        new Float:fX, Float:fY, Float:fZ;
        GetDynamicObjectPos(object_aBase_gate[0], fX, fY, fZ);
        
        if (fZ == aBase_GATE_OPEN_Z)
            MoveDynamicObject(object_aBase_gate, fX, fY, aBase_GATE_CLOSED_Z, 3.25);
        else
            MoveDynamicObject(object_aBase_gate, fX, fY, aBase_GATE_OPEN_Z, 3.25);

        return 1;
    }
    
    return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Tores.");
}*/

hook OnPlayerConnect(playerid) {
	//RemoveBuildingForPlayer(playerid, 5881, 1310.0200, -985.4379, 41.9062, 0.10); // skyscr02_LAwN
	//RemoveBuildingForPlayer(playerid, 5883, 1310.0200, -985.4379, 41.9062, 0.10); // LOD Model of skyscr02_LAwN
}

hook OnGameModeInit() {
	//Pickups
	//pickup_aBase[0] = CreateDynamicPickup(1240,  1, aBase_WEAPON_POINT, VW_MAIN); // AWAFFENPUNKT

	/*object_aBase[0] = CreateDynamicObject(19381, 1296.2812, -983.1115, 29.4372, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
	SetDynamicObjectMaterial(object_aBase[0], 0, 17588, "lae2coast_alpha", "plainglass", 0x00000000);
	object_aBase[1] = CreateDynamicObject(359, 1295.8498, -992.9170, 35.6430, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rocketla
	object_aBase[2] = CreateDynamicObject(5881, 1310.0047, -985.4298, 41.9112, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //skyscr02_LAwN
	SetDynamicObjectMaterial(object_aBase[2], 1, 3979, "civic01_lan", "sl_flagstone1", 0x00000000);
	SetDynamicObjectMaterial(object_aBase[2], 12, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	object_aBase[3] = CreateDynamicObject(19823, 1292.5971, -985.4100, 32.2067, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle4
	object_aBase[4] = CreateDynamicObject(3092, 1285.0947, -991.1322, 33.5735, -3.0000, -3.1999, -96.0999, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //dead_tied_cop
	object_aBase[5] = CreateDynamicObject(3092, 1285.2644, -992.1970, 33.5669, -3.0000, -3.1999, -96.0999, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //dead_tied_cop
	object_aBase[6] = CreateDynamicObject(1829, 1297.2692, -986.0681, 32.1592, -0.7000, 0.2000, -88.5999, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //man_safenew
	object_aBase[7] = CreateDynamicObject(19356, 1298.1900, -988.2575, 34.0429, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall004
	SetObjectMaterialText(object_aBase[7], "LyD | Adminlounge", 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0x00000000, 0);
	object_aBase[8] = CreateDynamicObject(19381, 1298.2226, -992.3162, 31.2872, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
	SetDynamicObjectMaterial(object_aBase[8], 0, 1929, "kbroul2", "oliveash_256", 0x00000000);
	object_aBase[9] = CreateDynamicObject(2350, 1297.3640, -991.3606, 32.0676, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL_2
	object_aBase[10] = CreateDynamicObject(1550, 1297.7742, -986.7671, 32.1032, -5.4999, -0.0000, 58.8999, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
	object_aBase[11] = CreateDynamicObject(19172, 1284.9395, -990.1166, 34.4230, 0.0000, 0.0999, 89.2001, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetObjectMaterialText(object_aBase[11], "Puma", 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(object_aBase[11], 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	object_aBase[12] = CreateDynamicObject(1670, 1292.0052, -985.2661, 32.2299, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
	object_aBase[13] = CreateDynamicObject(1893, 1291.6020, -982.4863, 34.2290, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
	object_aBase[14] = CreateDynamicObject(19172, 1284.9448, -991.2576, 34.4650, 0.0000, 0.0999, 89.2001, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetObjectMaterialText(object_aBase[14], "Bizzy", 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(object_aBase[14], 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	object_aBase[15] = CreateDynamicObject(19897, 1293.4208, -985.4302, 32.2130, 0.0000, 0.0000, -14.7999, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CigarettePack2
	object_aBase[16] = CreateDynamicObject(19897, 1294.7746, -985.4294, 32.2430, 0.0000, 0.0000, -14.7999, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CigarettePack2
	object_aBase[17] = CreateDynamicObject(2350, 1296.2731, -991.3506, 32.1276, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL_2
	object_aBase[18] = CreateDynamicObject(19896, 1292.9427, -985.0266, 32.2330, 0.0000, 0.0000, -44.0999, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CigarettePack1
	object_aBase[19] = CreateDynamicObject(2350, 1295.3022, -991.3306, 32.1276, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL_2
	object_aBase[20] = CreateDynamicObject(2932, 1285.0030, -991.6979, 31.7328, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_container_blue
	SetDynamicObjectMaterial(object_aBase[20], 0, 16322, "a51_stores", "fence_64", 0x00000000);
	SetDynamicObjectMaterial(object_aBase[20], 1, 16322, "a51_stores", "fence_64", 0x00000000);
	object_aBase[21] = CreateDynamicObject(19896, 1293.7227, -985.6361, 32.2330, 0.0000, 0.0000, -30.8000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CigarettePack1
	object_aBase[22] = CreateDynamicObject(2350, 1294.1605, -991.3306, 32.1276, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BARSTOOL_2
	object_aBase[23] = CreateDynamicObject(19356, 1298.2000, -982.0168, 34.7629, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall004
	SetObjectMaterialText(object_aBase[23], "42O blaze it", 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFFFFFFFF, 0x00000000, 0);
	object_aBase[24] = CreateDynamicObject(2964, 1294.8748, -988.3270, 31.6726, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_pooltablesm
	object_aBase[25] = CreateDynamicObject(338, 1295.3664, -987.5549, 32.0264, 6.5999, 0.2999, -4.3999, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //poolcue
	object_aBase[26] = CreateDynamicObject(19786, 1295.8153, -993.0136, 34.5131, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
	SetDynamicObjectMaterial(object_aBase[26], 1, 2577, "cj_sex", "CJ_PAINTING9", 0x00000000);
	object_aBase[27] = CreateDynamicObject(19833, 1286.0001, -992.0128, 32.3156, -30.3000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cow1
	object_aBase[28] = CreateDynamicObject(19381, 1296.2812, -983.1115, 29.4372, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
	SetDynamicObjectMaterial(object_aBase[28], 0, 17588, "lae2coast_alpha", "plainglass", 0x00000000);
	object_aBase[29] = CreateDynamicObject(19833, 1285.9600, -992.1810, 31.6754, -0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cow1
	object_aBase[30] = CreateDynamicObject(338, 1294.3764, -988.3257, 32.5714, 78.4999, 64.7000, -0.3999, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //poolcue
	object_aBase[31] = CreateDynamicObject(2995, 1295.0672, -988.0892, 32.6030, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballstp01
	object_aBase[32] = CreateDynamicObject(3003, 1295.4310, -988.2783, 32.6130, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballcue
	object_aBase[33] = CreateDynamicObject(2997, 1294.2994, -988.6857, 32.6030, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballstp03
	object_aBase[34] = CreateDynamicObject(3100, 1295.8063, -987.9678, 32.6130, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballspt02
	object_aBase[35] = CreateDynamicObject(3106, 1294.5207, -987.9481, 32.6130, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolball8
	object_aBase[36] = CreateDynamicObject(3000, 1295.6601, -988.6376, 32.6130, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballstp06
	object_aBase[37] = CreateDynamicObject(19173, 1298.1252, -988.5106, 34.7204, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
	SetObjectMaterialText(object_aBase[37], "created by LyD Team 2019", 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFF0000CD, 0x00000000, 0);
	object_aBase[38] = CreateDynamicObject(3102, 1294.1137, -987.8861, 32.6130, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballspt04
	object_aBase[39] = CreateDynamicObject(352, 1293.7746, -985.2259, 32.2148, 88.6000, -0.3999, 10.6999, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //micro_uzi
	object_aBase[40] = CreateDynamicObject(2942, 1292.7639, -994.2083, 32.3353, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
	*/
	object_aBase_gate[0] = CreateDynamicObject(17951, 1287.9040, -1006.1270, 31.4447, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cjgaragedoor
	/*object_aBase[42] = CreateDynamicObject(5881, 1310.0047, -985.4298, 41.9112, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //skyscr02_LAwN
	SetDynamicObjectMaterial(object_aBase[42], 1, 3979, "civic01_lan", "sl_flagstone1", 0x00000000);
	SetDynamicObjectMaterial(object_aBase[42], 12, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	*/
	object_aBase_gate[1] = CreateDynamicObject(17951, 1287.9040, -966.3336, 34.7849, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cjgaragedoor
	/*object_aBase[44] = CreateDynamicObject(19381, 1296.2806, -982.7218, 31.6270, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
	SetDynamicObjectMaterial(object_aBase[44], 0, 16640, "a51", "pavegrey128", 0x00000000);
	object_aBase[45] = CreateDynamicObject(19381, 1296.2812, -992.3543, 31.6270, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
	SetDynamicObjectMaterial(object_aBase[45], 0, 16640, "a51", "pavegrey128", 0x00000000);
	object_aBase[46] = CreateDynamicObject(19381, 1298.2226, -982.6831, 31.2872, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
	SetDynamicObjectMaterial(object_aBase[46], 0, 1929, "kbroul2", "oliveash_256", 0x00000000);
	object_aBase[47] = CreateDynamicObject(19381, 1298.2226, -992.3162, 31.2872, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
	SetDynamicObjectMaterial(object_aBase[47], 0, 1929, "kbroul2", "oliveash_256", 0x00000000);
	object_aBase[48] = CreateDynamicObject(1709, 1291.7551, -984.8618, 31.7021, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch08
	object_aBase[49] = CreateDynamicObject(2311, 1291.8066, -985.2755, 31.7066, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE2
	SetDynamicObjectMaterial(object_aBase[49], 0, 14652, "ab_trukstpa", "CJ_WOOD1(EDGE)", 0x00000000);
	object_aBase[50] = CreateDynamicObject(2311, 1294.1986, -985.2747, 31.7066, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TV_TABLE2
	SetDynamicObjectMaterial(object_aBase[50], 0, 14652, "ab_trukstpa", "CJ_WOOD1(EDGE)", 0x00000000);
	object_aBase[51] = CreateDynamicObject(1670, 1292.0052, -985.2661, 32.2299, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
	object_aBase[52] = CreateDynamicObject(1670, 1293.2464, -985.2661, 32.2299, 0.0000, 0.0000, -119.2997, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
	object_aBase[53] = CreateDynamicObject(1670, 1294.4748, -985.2794, 32.2299, 0.0000, 0.0000, -175.1997, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
	object_aBase[54] = CreateDynamicObject(2453, 1293.5019, -992.5531, 33.1744, 0.0000, 0.0000, 84.1000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_DISPf
	object_aBase[55] = CreateDynamicObject(19571, 1295.7707, -985.4907, 32.2197, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PizzaBox1
	object_aBase[56] = CreateDynamicObject(11686, 1295.6417, -992.5313, 31.7035, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CBarSection1
	object_aBase[57] = CreateDynamicObject(19571, 1295.7707, -985.4907, 32.2699, -90.0000, 0.0000, 25.9999, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PizzaBox1
	object_aBase[58] = CreateDynamicObject(19571, 1295.6446, -985.1602, 32.3199, -90.0000, 159.8999, 25.9999, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PizzaBox1
	object_aBase[59] = CreateDynamicObject(3409, 1292.4681, -980.8198, 31.4934, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grassplant
	object_aBase[60] = CreateDynamicObject(19381, 1296.2806, -978.3602, 31.6672, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
	SetDynamicObjectMaterial(object_aBase[60], 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
	object_aBase[61] = CreateDynamicObject(1893, 1291.6020, -979.1538, 34.2290, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
	object_aBase[62] = CreateDynamicObject(19381, 1296.2806, -978.3803, 34.3171, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
	SetDynamicObjectMaterial(object_aBase[62], 0, 8391, "ballys01", "CJ_blackplastic", 0x00000000);
	object_aBase[63] = CreateDynamicObject(19086, 1291.6014, -985.2813, 32.4752, 0.0000, 0.0000, -44.7999, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ChainsawDildo1
	object_aBase[64] = CreateDynamicObject(1893, 1291.6020, -980.8056, 34.2290, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
	object_aBase[65] = CreateDynamicObject(1893, 1295.3750, -980.8056, 34.2290, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
	object_aBase[66] = CreateDynamicObject(1893, 1295.3750, -982.4572, 34.2290, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
	object_aBase[67] = CreateDynamicObject(1893, 1295.3750, -979.1644, 34.2290, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
	object_aBase[68] = CreateDynamicObject(3409, 1296.1003, -980.8198, 31.4934, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ADMINBASE, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grassplant*/
}
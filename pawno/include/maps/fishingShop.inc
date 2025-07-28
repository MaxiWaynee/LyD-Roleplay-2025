#include <YSI\y_hooks>

// Global interior define
#define MAPS_FISHINGSHOP_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Electronics shop points
#define FISHINGSHOP_COORDS          825.6833, -2038.6458, 12.8684
#define FISHINGSHOP_GRILL_POINT     847.1649, -2043.4889, 13.7553
	

// Map variables
new object_fishingShop[107];
new pickup_fishingShop[1];
new text3D_fishingShop[2];
new actor_fishingShop[1];

hook OnPlayerConnect(playerid) {
	RemoveBuildingForPlayer(playerid, 1281, 821.8125, -2042.2969, 12.6172, 0.25);
	RemoveBuildingForPlayer(playerid, 1281, 824.7969, -2036.6797, 12.6172, 0.25);
	RemoveBuildingForPlayer(playerid, 1281, 821.8125, -2031.3516, 12.6172, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
	// Pickups
    pickup_fishingShop[0] = CreateDynamicPickup(1239, 1, FISHINGSHOP_COORDS, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR); // Fishing shop

    // 3DTextLabels
    text3D_fishingShop[0] = _:CreateDynamic3DTextLabel("Angelshop\n" COLOR_HEX_WHITE "Tippe /Angelshop", COLOR_BLUE, FISHINGSHOP_COORDS, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_FISHINGSHOP_INTERIOR);
    text3D_fishingShop[1] = _:CreateDynamic3DTextLabel("FISCHE GRILLEN\n" COLOR_HEX_WHITE "Tippe /Grillen", COLOR_GREEN, FISHINGSHOP_GRILL_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_FISHINGSHOP_INTERIOR);

    // Actors
    actor_fishingShop[0] = CreateDynamicActor(35, 823.2678, -2038.7002, 12.8684, 268.5636, .worldid = VW_MAIN, .interiorid = MAPS_FISHINGSHOP_INTERIOR); // Nerdy snotty sales guy (Zero)
    ApplyDynamicActorAnimation(actor_fishingShop[0], "SMOKING", "m_smk_loop", 4.0, 1, 0, 0, 0, 0);

	// Objects
	object_fishingShop[0] = CreateDynamicObject(18632, 844.6036, -2067.4682, 12.8231, 0.0000, 121.1997, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FishingRod
	object_fishingShop[1] = CreateDynamicObject(19373, 823.7982, -2037.0140, 11.7825, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[1], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
	object_fishingShop[2] = CreateDynamicObject(1893, 825.9136, -2037.1159, 15.0305, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
	object_fishingShop[3] = CreateDynamicObject(997, 849.6137, -2067.7402, 11.9215, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
	object_fishingShop[4] = CreateDynamicObject(997, 846.3134, -2067.7402, 11.9215, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
	object_fishingShop[5] = CreateDynamicObject(970, 822.0723, -2021.8524, 12.3992, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
	object_fishingShop[6] = CreateDynamicObject(970, 826.2421, -2021.8524, 12.3992, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
	object_fishingShop[7] = CreateDynamicObject(970, 850.8333, -2021.8524, 12.3992, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
	object_fishingShop[8] = CreateDynamicObject(997, 839.7227, -2067.7402, 11.9215, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
	object_fishingShop[9] = CreateDynamicObject(997, 843.0133, -2067.7402, 11.9215, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
	object_fishingShop[10] = CreateDynamicObject(997, 823.2827, -2067.7402, 11.9215, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
	object_fishingShop[11] = CreateDynamicObject(19373, 827.2702, -2045.1257, 13.4639, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[11], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_fishingShop[12] = CreateDynamicObject(19366, 822.1281, -2040.3835, 13.3184, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall014
	SetDynamicObjectMaterial(object_fishingShop[12], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
	object_fishingShop[13] = CreateDynamicObject(19373, 827.3214, -2040.2263, 15.2770, 0.0000, 98.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[13], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_fishingShop[14] = CreateDynamicObject(997, 836.4329, -2067.7402, 11.9215, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
	object_fishingShop[15] = CreateDynamicObject(19373, 827.2899, -2037.0140, 11.7825, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[15], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
	object_fishingShop[16] = CreateDynamicObject(997, 833.1331, -2067.7402, 11.9215, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
	object_fishingShop[17] = CreateDynamicObject(997, 829.8532, -2067.7402, 11.9215, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
	object_fishingShop[18] = CreateDynamicObject(997, 826.5634, -2067.7402, 11.9215, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
	object_fishingShop[19] = CreateDynamicObject(997, 820.0009, -2067.7402, 11.9215, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
	object_fishingShop[20] = CreateDynamicObject(19373, 827.2899, -2040.2148, 11.7825, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[20], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
	object_fishingShop[21] = CreateDynamicObject(19373, 823.7896, -2040.2148, 11.7825, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[21], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
	object_fishingShop[22] = CreateDynamicObject(19373, 827.2899, -2043.4250, 11.7825, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[22], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
	object_fishingShop[23] = CreateDynamicObject(19373, 823.7999, -2043.4250, 11.7825, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[23], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
	object_fishingShop[24] = CreateDynamicObject(19373, 823.8032, -2040.2258, 15.3570, 0.0000, 99.7996, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[24], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_fishingShop[25] = CreateDynamicObject(19373, 823.7999, -2043.4350, 15.0523, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[25], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_fishingShop[26] = CreateDynamicObject(3041, 820.9467, -2063.5722, 11.8502, 0.0000, 0.0000, 90.0999, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ct_table
	SetDynamicObjectMaterial(object_fishingShop[26], 2, 1600, "fish2", "fish3", 0xFFFFFFFF);
	object_fishingShop[27] = CreateDynamicObject(19373, 828.9721, -2037.1362, 13.4639, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[27], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_fishingShop[28] = CreateDynamicObject(19373, 827.2996, -2037.0141, 14.8625, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[28], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
	object_fishingShop[29] = CreateDynamicObject(19373, 827.2999, -2043.4350, 15.0523, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[29], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_fishingShop[30] = CreateDynamicObject(19373, 823.8098, -2037.0141, 15.0424, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[30], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_fishingShop[31] = CreateDynamicObject(19373, 827.3098, -2037.0141, 15.0424, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[31], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_fishingShop[32] = CreateDynamicObject(19373, 823.7993, -2045.1263, 13.4639, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[32], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
	object_fishingShop[33] = CreateDynamicObject(19373, 827.3001, -2035.4748, 13.4639, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[33], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_fishingShop[34] = CreateDynamicObject(19397, 829.0230, -2040.2253, 13.3172, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall045
	SetDynamicObjectMaterial(object_fishingShop[34], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
	object_fishingShop[35] = CreateDynamicObject(19373, 828.9699, -2043.4691, 13.4639, 90.0000, 90.0000, -90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[35], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_fishingShop[36] = CreateDynamicObject(19366, 822.1281, -2037.1732, 13.3184, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall014
	SetDynamicObjectMaterial(object_fishingShop[36], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
	object_fishingShop[37] = CreateDynamicObject(19366, 822.3184, -2037.1839, 13.3184, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall014
	SetDynamicObjectMaterial(object_fishingShop[37], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
	object_fishingShop[38] = CreateDynamicObject(19373, 823.7993, -2035.4748, 13.4639, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[38], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
	object_fishingShop[39] = CreateDynamicObject(19397, 822.1325, -2043.5957, 13.3172, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall045
	SetDynamicObjectMaterial(object_fishingShop[39], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
	object_fishingShop[40] = CreateDynamicObject(19397, 822.3126, -2043.5957, 13.3172, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall045
	SetDynamicObjectMaterial(object_fishingShop[40], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
	object_fishingShop[41] = CreateDynamicObject(19366, 822.3084, -2040.3835, 13.3184, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall014
	SetDynamicObjectMaterial(object_fishingShop[41], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
	object_fishingShop[42] = CreateDynamicObject(19373, 823.7993, -2035.6550, 13.4639, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[42], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
	object_fishingShop[43] = CreateDynamicObject(19397, 828.8433, -2040.2253, 13.3172, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall045
	SetDynamicObjectMaterial(object_fishingShop[43], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
	object_fishingShop[44] = CreateDynamicObject(19172, 829.1021, -2040.2290, 14.1675, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterial(object_fishingShop[44], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterialText(object_fishingShop[44], 1, "Angelshop", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
	object_fishingShop[45] = CreateDynamicObject(19373, 823.7993, -2044.9460, 13.4639, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[45], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
	object_fishingShop[46] = CreateDynamicObject(19373, 823.7998, -2037.0141, 14.8625, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[46], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
	object_fishingShop[47] = CreateDynamicObject(19373, 823.7998, -2043.4337, 14.8625, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[47], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
	object_fishingShop[48] = CreateDynamicObject(19373, 827.2996, -2043.4370, 14.8625, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_fishingShop[48], 0, 1714, "cj_office", "BLUE_FABRIC", 0xFFFFFFFF);
	object_fishingShop[49] = CreateDynamicObject(19926, 824.0512, -2036.7075, 11.8083, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWorkTop2
	SetDynamicObjectMaterial(object_fishingShop[49], 1, 9514, "711_sfw", "pcut_bot_law", 0xFFFFFFFF);
	object_fishingShop[50] = CreateDynamicObject(2405, 824.9833, -2035.8095, 13.1726, -3.2999, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SURF_BOARD2
	object_fishingShop[51] = CreateDynamicObject(1514, 824.0543, -2038.6528, 12.9778, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_FF_TILL
	object_fishingShop[52] = CreateDynamicObject(19926, 824.0512, -2038.6269, 11.8083, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWorkTop2
	SetDynamicObjectMaterial(object_fishingShop[52], 1, 9514, "711_sfw", "pcut_bot_law", 0xFFFFFFFF);
	object_fishingShop[53] = CreateDynamicObject(2406, 822.4741, -2037.5517, 14.0158, 0.0000, -70.0000, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SURF_BOARD3
	object_fishingShop[54] = CreateDynamicObject(18632, 824.9791, -2044.8376, 12.9804, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FishingRod
	object_fishingShop[55] = CreateDynamicObject(18632, 824.5592, -2044.8376, 12.9804, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FishingRod
	object_fishingShop[56] = CreateDynamicObject(18632, 822.8687, -2044.8376, 14.2503, 180.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FishingRod
	object_fishingShop[57] = CreateDynamicObject(18632, 822.8687, -2044.8376, 13.7903, 180.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FishingRod
	object_fishingShop[58] = CreateDynamicObject(18632, 822.8687, -2044.8376, 13.2503, 180.0000, -90.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FishingRod
	object_fishingShop[59] = CreateDynamicObject(1842, 826.4372, -2042.8786, 12.3465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_shelf05
	SetDynamicObjectMaterial(object_fishingShop[59], 1, 6284, "bev_law2", "glass_fence_64hv", 0xFFFFFFFF);
	object_fishingShop[60] = CreateDynamicObject(2002, 822.8963, -2042.2655, 11.8563, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //water_coolnu
	object_fishingShop[61] = CreateDynamicObject(19925, 824.0520, -2040.0200, 11.8083, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWorkTop1
	SetDynamicObjectMaterial(object_fishingShop[61], 1, 9514, "711_sfw", "pcut_bot_law", 0xFFFFFFFF);
	object_fishingShop[62] = CreateDynamicObject(970, 846.6624, -2021.8524, 12.3992, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
	object_fishingShop[63] = CreateDynamicObject(970, 842.4921, -2021.8524, 12.3992, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
	object_fishingShop[64] = CreateDynamicObject(970, 836.4215, -2021.8524, 12.3992, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
	object_fishingShop[65] = CreateDynamicObject(970, 830.4179, -2021.8524, 12.3992, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
	object_fishingShop[66] = CreateDynamicObject(1842, 826.4372, -2042.8786, 11.5665, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_shelf05
	SetDynamicObjectMaterial(object_fishingShop[66], 1, 3474, "freightcrane", "bluecab3_256", 0xFFFFFFFF);
	object_fishingShop[67] = CreateDynamicObject(1599, 827.1832, -2043.7297, 12.2189, 0.0000, 0.0000, 90.2000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fish1single
	object_fishingShop[68] = CreateDynamicObject(1601, 826.4566, -2042.7214, 12.3724, 0.0000, 0.0000, 92.5000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fish3s
	object_fishingShop[69] = CreateDynamicObject(1599, 827.3074, -2042.4748, 12.3748, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fish1single
	object_fishingShop[70] = CreateDynamicObject(1886, 822.7797, -2037.0333, 15.1035, 17.2999, 0.0000, 54.8000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
	object_fishingShop[71] = CreateDynamicObject(18632, 834.7415, -2067.4733, 12.8145, 0.0000, 121.1997, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FishingRod
	object_fishingShop[72] = CreateDynamicObject(1368, 843.6651, -2043.5615, 12.5520, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
	object_fishingShop[73] = CreateDynamicObject(638, 829.4855, -2037.0858, 12.5570, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
	object_fishingShop[74] = CreateDynamicObject(638, 829.4855, -2043.4260, 12.5570, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
	object_fishingShop[75] = CreateDynamicObject(1463, 847.4268, -2044.1754, 12.2747, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WOODPILE2
	object_fishingShop[76] = CreateDynamicObject(18693, 847.9807, -2042.5117, 10.6019, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Flame99
	object_fishingShop[77] = CreateDynamicObject(1491, 822.1052, -2042.8122, 11.5636, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
	SetDynamicObjectMaterial(object_fishingShop[77], 0, 8409, "gnhotel1", "glass_64", 0xFFFFFFFF);
	object_fishingShop[78] = CreateDynamicObject(1893, 825.9136, -2043.3790, 15.0305, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
	object_fishingShop[79] = CreateDynamicObject(18693, 847.9807, -2044.5532, 10.6019, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Flame99
	object_fishingShop[80] = CreateDynamicObject(18632, 847.7043, -2067.4682, 12.8231, 0.0000, 121.1997, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FishingRod
	object_fishingShop[81] = CreateDynamicObject(18693, 847.1199, -2042.5117, 10.6019, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Flame99
	object_fishingShop[82] = CreateDynamicObject(18693, 847.0910, -2044.5532, 10.6019, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Flame99
	object_fishingShop[83] = CreateDynamicObject(1463, 847.4268, -2042.9942, 12.2747, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WOODPILE2
	object_fishingShop[84] = CreateDynamicObject(18693, 847.0910, -2043.5522, 10.6019, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Flame99
	object_fishingShop[85] = CreateDynamicObject(1842, 847.4333, -2043.5441, 12.2765, 0.0000, 0.0000, -90.3000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_shelf05
	SetDynamicObjectMaterial(object_fishingShop[85], 0, 18231, "cs_coast", "cunt_botrock", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_fishingShop[85], 1, 11499, "des_dinerw", "gate1_LAe", 0xFFFFFFFF);
	object_fishingShop[86] = CreateDynamicObject(18693, 847.9215, -2043.5522, 10.6019, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Flame99
	object_fishingShop[87] = CreateDynamicObject(18632, 831.4815, -2067.4733, 12.8145, 0.0000, 121.1997, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FishingRod
	object_fishingShop[88] = CreateDynamicObject(18632, 841.3427, -2067.4682, 12.8231, 0.0000, 121.1997, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FishingRod
	object_fishingShop[89] = CreateDynamicObject(2359, 848.8980, -2065.5512, 12.0570, 0.0000, 0.0000, -39.9000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c5
	SetDynamicObjectMaterial(object_fishingShop[89], 0, 16322, "a51_stores", "des_ghotwood1", 0xFFFFFFFF);
	object_fishingShop[90] = CreateDynamicObject(18632, 838.0525, -2067.4733, 12.8145, 0.0000, 121.1997, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FishingRod
	object_fishingShop[91] = CreateDynamicObject(18632, 828.1715, -2067.4733, 12.8145, 0.0000, 121.1997, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FishingRod
	object_fishingShop[92] = CreateDynamicObject(18632, 824.9113, -2067.4733, 12.8145, 0.0000, 121.1997, 90.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FishingRod
	object_fishingShop[93] = CreateDynamicObject(1368, 847.4102, -2038.8592, 12.5520, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
	object_fishingShop[94] = CreateDynamicObject(1368, 847.4028, -2048.1682, 12.5520, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
	object_fishingShop[95] = CreateDynamicObject(3041, 852.0661, -2063.5187, 11.8502, 0.0000, 0.0000, -89.5999, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ct_table
	SetDynamicObjectMaterial(object_fishingShop[95], 2, 1600, "fish2", "fish3", 0xFFFFFFFF);
	object_fishingShop[96] = CreateDynamicObject(2359, 837.7908, -2064.3859, 12.0570, 0.0000, 0.0000, 89.6999, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c5
	SetDynamicObjectMaterial(object_fishingShop[96], 0, 16322, "a51_stores", "des_ghotwood1", 0xFFFFFFFF);
	object_fishingShop[97] = CreateDynamicObject(2359, 834.6503, -2064.3688, 12.0570, 0.0000, 0.0000, 73.3999, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c5
	SetDynamicObjectMaterial(object_fishingShop[97], 0, 16322, "a51_stores", "des_ghotwood1", 0xFFFFFFFF);
	object_fishingShop[98] = CreateDynamicObject(2359, 831.3294, -2064.2036, 12.0570, 0.0000, 0.0000, 114.4999, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c5
	SetDynamicObjectMaterial(object_fishingShop[98], 0, 16322, "a51_stores", "des_ghotwood1", 0xFFFFFFFF);
	object_fishingShop[99] = CreateDynamicObject(2359, 828.1367, -2063.9997, 12.0570, 0.0000, 0.0000, 39.6999, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c5
	SetDynamicObjectMaterial(object_fishingShop[99], 0, 16322, "a51_stores", "des_ghotwood1", 0xFFFFFFFF);
	object_fishingShop[100] = CreateDynamicObject(2359, 825.0097, -2063.9968, 12.0570, 0.0000, -1.3999, -28.7000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c5
	SetDynamicObjectMaterial(object_fishingShop[100], 0, 16322, "a51_stores", "des_ghotwood1", 0xFFFFFFFF);
	object_fishingShop[101] = CreateDynamicObject(19630, 837.8502, -2064.7028, 12.0122, -76.5999, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Fish1
	object_fishingShop[102] = CreateDynamicObject(2359, 841.3810, -2064.4040, 12.0570, 0.0000, 0.0000, 43.3999, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c5
	SetDynamicObjectMaterial(object_fishingShop[102], 0, 16322, "a51_stores", "des_ghotwood1", 0xFFFFFFFF);
	object_fishingShop[103] = CreateDynamicObject(2359, 844.6901, -2065.1958, 12.0570, 0.0000, 0.0000, -32.3000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c5
	SetDynamicObjectMaterial(object_fishingShop[103], 0, 16322, "a51_stores", "des_ghotwood1", 0xFFFFFFFF);
	object_fishingShop[104] = CreateDynamicObject(19630, 837.8502, -2064.4433, 12.0021, -76.5999, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Fish1
	object_fishingShop[105] = CreateDynamicObject(19630, 844.4505, -2065.1420, 12.0001, -76.5999, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Fish1
	object_fishingShop[106] = CreateDynamicObject(19630, 824.7493, -2063.8273, 11.9952, -76.5999, 0.0000, 0.0000, VW_MAIN, MAPS_FISHINGSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Fish1
}
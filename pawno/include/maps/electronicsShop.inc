#include <YSI\y_hooks>

// Global interior define
#define MAPS_ELECTRONICSSHOP_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 100.0;
static Float:DRAWDISTANCE   = 100.0;

// Electronics shop points
#define ELECTRONICSSHOP_COORDS     1228.1368, -1423.4741, 13.5548

// Map variables
new object_electronicsShop[205];
new pickup_electronicsShop[1];
new text3D_electronicsShop[1];
new actor_electronicsShop[1];

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 6068, 1247.9141, -1429.9688, 15.1250, 0.25);
	RemoveBuildingForPlayer(playerid, 6052, 1247.9141, -1429.9688, 15.1250, 0.25);
	RemoveBuildingForPlayer(playerid, 627, 1230.1250, -1416.5703, 14.1406, 0.25);
	RemoveBuildingForPlayer(playerid, 627, 1209.8984, -1416.5703, 14.1406, 0.25);
	RemoveBuildingForPlayer(playerid, 792, 1256.9844, -1417.7031, 12.7188, 0.25);
	RemoveBuildingForPlayer(playerid, 792, 1236.2813, -1417.7031, 12.7188, 0.25);
	RemoveBuildingForPlayer(playerid, 1283, 1244.0391, -1406.5313, 15.1641, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
	// Pickups
    pickup_electronicsShop[0] = CreateDynamicPickup(1239, 1, ELECTRONICSSHOP_COORDS, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR); // Sales point

    // 3DTextLabels
    text3D_electronicsShop[0] = _:CreateDynamic3DTextLabel("ELEKTROMARKT\n" COLOR_HEX_WHITE "Tippe /Elektromarkt", COLOR_BLUE, ELECTRONICSSHOP_COORDS, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_ELECTRONICSSHOP_INTERIOR);

    // Actors
    actor_electronicsShop[0] = CreateDynamicActor(289, 1230.3973, -1423.6211, 13.5548, 94.2039, .worldid = VW_MAIN, .interiorid = MAPS_ELECTRONICSSHOP_INTERIOR); // Nerdy snotty sales guy (Zero)
    ApplyDynamicActorAnimation(actor_electronicsShop[0], "COP_AMBIENT", "Coplook_loop", 4.0, 1, 0, 0, 0, 0);

	// Objects
	object_electronicsShop[0] = CreateDynamicObject(19353, 1217.5797, -1428.8034, 18.6434, 45.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[0], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[1] = CreateDynamicObject(19929, 1229.6097, -1423.7740, 12.5135, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWorkTop5
	SetDynamicObjectMaterial(object_electronicsShop[1], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_electronicsShop[1], 1, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[2] = CreateDynamicObject(19353, 1221.6174, -1428.8034, 14.6058, 45.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[2], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[3] = CreateDynamicObject(19378, 1217.6783, -1428.9084, 14.2459, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[3], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[4] = CreateDynamicObject(8418, 1259.8723, -1427.7342, 12.1422, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgshpgrnd04_lvS
	object_electronicsShop[5] = CreateDynamicObject(2475, 1231.9233, -1423.0887, 12.4111, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_3
	object_electronicsShop[6] = CreateDynamicObject(18980, 1218.1850, -1429.1606, 14.8908, 45.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_electronicsShop[6], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[7] = CreateDynamicObject(8661, 1222.1297, -1435.9493, 12.5548, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
	SetDynamicObjectMaterial(object_electronicsShop[7], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
	object_electronicsShop[8] = CreateDynamicObject(19929, 1208.3192, -1425.8758, 12.5135, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWorkTop5
	SetDynamicObjectMaterial(object_electronicsShop[8], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_electronicsShop[8], 1, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[9] = CreateDynamicObject(19929, 1208.3192, -1421.3358, 12.5135, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWorkTop5
	SetDynamicObjectMaterial(object_electronicsShop[9], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_electronicsShop[9], 1, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[10] = CreateDynamicObject(14438, 1219.2170, -1422.4294, 18.0442, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Carter-light04
	object_electronicsShop[11] = CreateDynamicObject(19353, 1219.3973, -1428.8034, 16.8262, 45.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[11], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[12] = CreateDynamicObject(19378, 1212.5052, -1421.1191, 18.6079, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[12], 0, 10023, "bigwhitesfe", "sfe_arch10", 0xFFFFFFFF);
	object_electronicsShop[13] = CreateDynamicObject(8661, 1217.8558, -1435.9493, 12.5537, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
	SetDynamicObjectMaterial(object_electronicsShop[13], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
	object_electronicsShop[14] = CreateDynamicObject(1491, 1232.0417, -1425.8127, 12.5488, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
	SetDynamicObjectMaterial(object_electronicsShop[14], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
	object_electronicsShop[15] = CreateDynamicObject(19378, 1217.6766, -1431.6202, 18.6039, 0.0000, -90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[15], 0, 10023, "bigwhitesfe", "sfe_arch10", 0xFFFFFFFF);
	object_electronicsShop[16] = CreateDynamicObject(18980, 1232.3945, -1419.5438, 12.4299, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_electronicsShop[16], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[17] = CreateDynamicObject(19925, 1229.6103, -1421.9110, 12.5129, 0.0000, 0.0000, 270.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWorkTop1
	SetDynamicObjectMaterial(object_electronicsShop[17], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[18] = CreateDynamicObject(19353, 1219.9403, -1417.5644, 12.4834, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[18], 0, 10765, "airportgnd_sfse", "white", 0xFF252527);
	object_electronicsShop[19] = CreateDynamicObject(19378, 1227.3087, -1431.5714, 18.6039, 0.0000, -90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[19], 0, 10023, "bigwhitesfe", "sfe_arch10", 0xFFFFFFFF);
	object_electronicsShop[20] = CreateDynamicObject(19378, 1232.0412, -1430.6499, 7.3119, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[20], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[21] = CreateDynamicObject(19445, 1212.5412, -1428.8806, 11.1351, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_electronicsShop[21], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[22] = CreateDynamicObject(19931, 1231.5565, -1421.9027, 12.5211, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWorkTop7
	SetDynamicObjectMaterial(object_electronicsShop[22], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[23] = CreateDynamicObject(19378, 1232.0412, -1440.2790, 7.3119, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[23], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[24] = CreateDynamicObject(19378, 1227.3087, -1421.1191, 18.6058, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[24], 0, 10023, "bigwhitesfe", "sfe_arch10", 0xFFFFFFFF);
	object_electronicsShop[25] = CreateDynamicObject(19926, 1215.6389, -1428.3784, 12.5544, 0.0000, 0.0000, 270.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWorkTop2
	SetDynamicObjectMaterial(object_electronicsShop[25], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[26] = CreateDynamicObject(19378, 1212.5052, -1442.1202, 18.6100, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[26], 0, 10023, "bigwhitesfe", "sfe_arch10", 0xFFFFFFFF);
	object_electronicsShop[27] = CreateDynamicObject(19378, 1232.0412, -1449.9105, 7.3119, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[27], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[28] = CreateDynamicObject(19378, 1217.6766, -1421.1191, 18.6058, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[28], 0, 10023, "bigwhitesfe", "sfe_arch10", 0xFFFFFFFF);
	object_electronicsShop[29] = CreateDynamicObject(19378, 1232.0412, -1459.5510, 7.3119, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[29], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[30] = CreateDynamicObject(19378, 1212.5052, -1431.6197, 18.6100, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[30], 0, 10023, "bigwhitesfe", "sfe_arch10", 0xFFFFFFFF);
	object_electronicsShop[31] = CreateDynamicObject(19445, 1207.7905, -1422.3497, 11.1351, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_electronicsShop[31], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[32] = CreateDynamicObject(19378, 1227.3087, -1442.0716, 18.6039, 0.0000, -90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[32], 0, 10023, "bigwhitesfe", "sfe_arch10", 0xFFFFFFFF);
	object_electronicsShop[33] = CreateDynamicObject(1491, 1232.0616, -1428.8330, 12.5488, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
	SetDynamicObjectMaterial(object_electronicsShop[33], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
	object_electronicsShop[34] = CreateDynamicObject(19378, 1212.6269, -1428.9060, 14.2459, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[34], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[35] = CreateDynamicObject(19426, 1208.7662, -1416.6770, 17.7467, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
	SetDynamicObjectMaterial(object_electronicsShop[35], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[36] = CreateDynamicObject(19353, 1223.8446, -1428.8034, 12.3784, 45.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[36], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[37] = CreateDynamicObject(19353, 1232.6529, -1423.5505, 19.3649, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[37], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[38] = CreateDynamicObject(19378, 1232.0412, -1427.4381, 20.2959, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[38], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[39] = CreateDynamicObject(19378, 1232.0394, -1421.0157, 14.2459, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[39], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[40] = CreateDynamicObject(19378, 1227.3087, -1428.9084, 14.2459, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[40], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[41] = CreateDynamicObject(19353, 1207.7806, -1426.3620, 16.2534, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[41], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[42] = CreateDynamicObject(1514, 1229.6313, -1422.7220, 13.6857, 0.0000, 0.0000, -89.1996, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_FF_TILL
	object_electronicsShop[43] = CreateDynamicObject(18980, 1221.2913, -1429.1606, 17.9950, 45.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_electronicsShop[43], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[44] = CreateDynamicObject(957, 1224.9508, -1421.9101, 18.4867, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_LIGHT_FIT_EXT
	object_electronicsShop[45] = CreateDynamicObject(19445, 1207.7912, -1424.0703, 11.1351, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_electronicsShop[45], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[46] = CreateDynamicObject(19929, 1230.6754, -1424.8415, 12.5135, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWorkTop5
	SetDynamicObjectMaterial(object_electronicsShop[46], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_electronicsShop[46], 1, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[47] = CreateDynamicObject(18980, 1219.6943, -1416.3691, 12.0934, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_electronicsShop[47], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[48] = CreateDynamicObject(19445, 1222.1512, -1428.8807, 11.1351, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_electronicsShop[48], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[49] = CreateDynamicObject(19786, 1215.6457, -1428.8547, 14.8493, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
	object_electronicsShop[50] = CreateDynamicObject(2028, 1216.0072, -1428.3675, 13.5331, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_CONSOLE
	object_electronicsShop[51] = CreateDynamicObject(2028, 1215.2867, -1428.3675, 13.5331, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_CONSOLE
	object_electronicsShop[52] = CreateDynamicObject(19353, 1232.6529, -1418.6639, 14.4785, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[52], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[53] = CreateDynamicObject(19353, 1232.6529, -1421.1391, 16.9538, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[53], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[54] = CreateDynamicObject(19353, 1232.0124, -1418.8485, 14.6626, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[54], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[55] = CreateDynamicObject(19353, 1232.6529, -1418.3940, 18.7215, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[55], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[56] = CreateDynamicObject(19353, 1232.0124, -1421.1385, 16.9538, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[56], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[57] = CreateDynamicObject(19353, 1232.0124, -1423.5979, 19.4144, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[57], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[58] = CreateDynamicObject(19353, 1232.0124, -1418.2967, 18.4811, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[58], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[59] = CreateDynamicObject(19353, 1207.7806, -1428.5256, 14.0896, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[59], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[60] = CreateDynamicObject(19445, 1231.9796, -1421.0184, 11.1351, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_electronicsShop[60], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[61] = CreateDynamicObject(19378, 1232.0412, -1465.1313, 7.3098, 180.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[61], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[62] = CreateDynamicObject(18980, 1207.3935, -1427.5913, 12.4301, -45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_electronicsShop[62], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[63] = CreateDynamicObject(19378, 1207.7550, -1422.7175, 14.2459, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[63], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[64] = CreateDynamicObject(19353, 1207.1809, -1426.4858, 16.1333, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[64], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[65] = CreateDynamicObject(19353, 1207.1809, -1424.2087, 18.4102, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[65], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[66] = CreateDynamicObject(19353, 1207.1809, -1428.9001, 18.6578, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[66], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[67] = CreateDynamicObject(19353, 1207.1809, -1428.7547, 13.8634, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[67], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[68] = CreateDynamicObject(19353, 1207.7806, -1424.2545, 18.3605, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[68], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[69] = CreateDynamicObject(19426, 1208.7662, -1416.6770, 14.2467, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
	SetDynamicObjectMaterial(object_electronicsShop[69], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[70] = CreateDynamicObject(19353, 1207.7806, -1428.8800, 18.6151, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[70], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[71] = CreateDynamicObject(19426, 1231.0660, -1416.7270, 17.7467, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
	SetDynamicObjectMaterial(object_electronicsShop[71], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[72] = CreateDynamicObject(19353, 1207.1809, -1429.7811, 17.7880, 45.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_electronicsShop[72], 0, 10765, "airportgnd_sfse", "white", 0xFFBDBEC6);
	object_electronicsShop[73] = CreateDynamicObject(19378, 1228.7889, -1415.9987, 21.4057, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[73], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[74] = CreateDynamicObject(19378, 1219.1594, -1416.0288, 21.4057, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[74], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[75] = CreateDynamicObject(19378, 1210.9476, -1416.0180, 21.4057, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[75], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[76] = CreateDynamicObject(19172, 1221.0456, -1415.8935, 17.4827, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterial(object_electronicsShop[76], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterialText(object_electronicsShop[76], 1,"Elektro", 90, "Calibri", 100, 1, 0xFFFFFFFF, 0x0, 1);
	object_electronicsShop[77] = CreateDynamicObject(19172, 1219.5439, -1417.5345, 12.5726, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterial(object_electronicsShop[77], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterialText(object_electronicsShop[77], 1,"Willkommen", 90, "Calibri", 42, 1, 0xFFFFFFFF, 0x0, 0);
	object_electronicsShop[78] = CreateDynamicObject(19426, 1231.0660, -1416.7170, 14.2467, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
	SetDynamicObjectMaterial(object_electronicsShop[78], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[79] = CreateDynamicObject(19172, 1218.8957, -1415.8935, 17.4827, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterial(object_electronicsShop[79], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterialText(object_electronicsShop[79], 1,"  markt", 90, "Calibri", 100, 1, 0xFFFFFFFF, 0x0, 1);
	object_electronicsShop[80] = CreateDynamicObject(19426, 1231.6391, -1417.9560, 14.2467, 0.0000, 0.0000, 47.7999, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
	SetDynamicObjectMaterial(object_electronicsShop[80], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[81] = CreateDynamicObject(19426, 1231.6391, -1417.9560, 17.7367, 0.0000, 0.0000, 47.7999, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
	SetDynamicObjectMaterial(object_electronicsShop[81], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[82] = CreateDynamicObject(19426, 1208.1955, -1417.9587, 14.0565, 0.0000, 0.0000, -47.5998, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
	SetDynamicObjectMaterial(object_electronicsShop[82], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[83] = CreateDynamicObject(19426, 1208.1955, -1417.9587, 17.5566, 0.0000, 0.0000, -47.5998, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
	SetDynamicObjectMaterial(object_electronicsShop[83], 0, 9514, "711_sfw", "ws_carpark2", 0xFFFFFFFF);
	object_electronicsShop[84] = CreateDynamicObject(19378, 1213.6374, -1415.9647, 10.9055, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[84], 0, 17588, "lae2coast_alpha", "plainglass", 0xFFFFFFFF);
	object_electronicsShop[85] = CreateDynamicObject(19378, 1226.1673, -1415.9647, 10.9055, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[85], 0, 17588, "lae2coast_alpha", "plainglass", 0xFFFFFFFF);
	object_electronicsShop[86] = CreateDynamicObject(19445, 1227.1612, -1428.8807, 11.1351, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_electronicsShop[86], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[87] = CreateDynamicObject(19378, 1254.3259, -1421.0791, 12.5958, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[87], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
	object_electronicsShop[88] = CreateDynamicObject(19378, 1244.6956, -1421.0791, 12.5958, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[88], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
	object_electronicsShop[89] = CreateDynamicObject(19378, 1244.6956, -1421.0791, 12.4177, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall026
	SetDynamicObjectMaterial(object_electronicsShop[89], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
	object_electronicsShop[90] = CreateDynamicObject(4642, 1258.1408, -1416.0163, 14.1524, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //paypark_lan
	object_electronicsShop[91] = CreateDynamicObject(367, 1213.9594, -1423.8543, 13.4594, 0.0000, 0.0000, -45.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //camera
	object_electronicsShop[92] = CreateDynamicObject(2684, 1231.8778, -1423.1533, 14.0634, -18.8000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post
	SetDynamicObjectMaterial(object_electronicsShop[92], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_electronicsShop[93] = CreateDynamicObject(18872, 1208.2496, -1420.7707, 13.5669, 70.2000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MobilePhone8
	object_electronicsShop[94] = CreateDynamicObject(18865, 1208.2589, -1422.3039, 13.5658, 75.3000, 0.0000, 94.7000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MobilePhone1
	object_electronicsShop[95] = CreateDynamicObject(19940, 1208.4685, -1422.1785, 12.7869, 74.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[95], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[96] = CreateDynamicObject(2229, 1212.1158, -1428.7781, 12.5154, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_SPEAKER
	object_electronicsShop[97] = CreateDynamicObject(19424, 1208.0144, -1425.9829, 13.5646, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones04
	object_electronicsShop[98] = CreateDynamicObject(18871, 1208.2545, -1422.1092, 13.5645, 72.0999, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MobilePhone7
	object_electronicsShop[99] = CreateDynamicObject(18868, 1208.2462, -1420.5554, 13.5679, 73.6000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MobilePhone4
	object_electronicsShop[100] = CreateDynamicObject(19940, 1208.4685, -1420.6574, 12.7869, 74.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[100], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[101] = CreateDynamicObject(334, 1207.8697, -1425.4685, 13.7652, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nitestick
	object_electronicsShop[102] = CreateDynamicObject(334, 1207.8697, -1424.9279, 13.7652, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nitestick
	object_electronicsShop[103] = CreateDynamicObject(334, 1207.8697, -1426.0190, 13.7652, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nitestick
	object_electronicsShop[104] = CreateDynamicObject(19421, 1207.8863, -1425.4340, 13.5669, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones01
	object_electronicsShop[105] = CreateDynamicObject(19421, 1207.9664, -1425.4340, 13.5669, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones01
	object_electronicsShop[106] = CreateDynamicObject(19421, 1208.0565, -1425.4340, 13.5669, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones01
	object_electronicsShop[107] = CreateDynamicObject(19421, 1208.1555, -1425.4340, 13.5669, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones01
	object_electronicsShop[108] = CreateDynamicObject(19424, 1207.9343, -1425.9829, 13.5546, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones04
	object_electronicsShop[109] = CreateDynamicObject(19424, 1208.0844, -1425.9829, 13.5646, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones04
	object_electronicsShop[110] = CreateDynamicObject(19422, 1207.8802, -1424.8940, 13.5563, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones02
	object_electronicsShop[111] = CreateDynamicObject(19424, 1208.1645, -1425.9829, 13.5746, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones04
	object_electronicsShop[112] = CreateDynamicObject(19422, 1207.9603, -1424.8940, 13.5563, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones02
	object_electronicsShop[113] = CreateDynamicObject(19422, 1208.0404, -1424.8940, 13.5563, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones02
	object_electronicsShop[114] = CreateDynamicObject(19422, 1208.1405, -1424.8940, 13.5563, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones02
	object_electronicsShop[115] = CreateDynamicObject(334, 1207.8697, -1426.6093, 13.7652, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nitestick
	object_electronicsShop[116] = CreateDynamicObject(19423, 1207.9228, -1426.5805, 13.5661, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones03
	object_electronicsShop[117] = CreateDynamicObject(19423, 1208.0129, -1426.5805, 13.5661, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones03
	object_electronicsShop[118] = CreateDynamicObject(19423, 1208.0930, -1426.5805, 13.5661, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones03
	object_electronicsShop[119] = CreateDynamicObject(19423, 1208.1730, -1426.5805, 13.5661, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //headphones03
	object_electronicsShop[120] = CreateDynamicObject(19610, 1210.6857, -1428.3245, 14.1586, 51.1000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Microphone1
	object_electronicsShop[121] = CreateDynamicObject(19611, 1210.6905, -1428.3011, 12.5415, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MicrophoneStand1
	object_electronicsShop[122] = CreateDynamicObject(19611, 1211.4613, -1428.3011, 12.5415, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MicrophoneStand1
	object_electronicsShop[123] = CreateDynamicObject(19940, 1210.7078, -1428.3996, 12.8668, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[123], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_electronicsShop[124] = CreateDynamicObject(19610, 1211.4462, -1428.3245, 14.1586, 51.1000, 0.0000, -13.6999, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Microphone1
	object_electronicsShop[125] = CreateDynamicObject(1513, 1231.7679, -1424.8326, 13.7178, 0.0000, 0.0000, 270.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_SWEETIE_TRAY
	object_electronicsShop[126] = CreateDynamicObject(19940, 1211.4282, -1428.5621, 13.1183, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[126], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_electronicsShop[127] = CreateDynamicObject(19940, 1214.9300, -1423.9849, 13.4218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[127], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[128] = CreateDynamicObject(2412, 1222.2244, -1417.0955, 12.5557, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_DETECTOR
	object_electronicsShop[129] = CreateDynamicObject(2412, 1218.3642, -1417.0955, 12.5557, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_DETECTOR
	object_electronicsShop[130] = CreateDynamicObject(19940, 1217.9965, -1423.8449, 12.4218, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[130], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[131] = CreateDynamicObject(2684, 1231.8524, -1423.8640, 14.0098, -18.8000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post
	SetDynamicObjectMaterialText(object_electronicsShop[131], 0,"5000$", 90, "Arial", 100, 1, 0xFF000000, 0x0, 0);
	object_electronicsShop[132] = CreateDynamicObject(2229, 1213.3961, -1428.7781, 12.5154, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_SPEAKER
	object_electronicsShop[133] = CreateDynamicObject(2232, 1208.4582, -1427.8659, 11.0094, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SPEAKER_4
	object_electronicsShop[134] = CreateDynamicObject(2233, 1207.6947, -1423.4720, 12.5577, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_SPEAKER_4
	object_electronicsShop[135] = CreateDynamicObject(2233, 1207.6947, -1422.9114, 12.5577, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_SPEAKER_4
	object_electronicsShop[136] = CreateDynamicObject(2232, 1213.0683, -1428.4357, 13.1494, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SPEAKER_4
	object_electronicsShop[137] = CreateDynamicObject(19940, 1218.9759, -1423.1729, 12.7618, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[137], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[138] = CreateDynamicObject(19940, 1217.9959, -1423.4045, 12.4218, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[138], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[139] = CreateDynamicObject(19940, 1218.9689, -1424.0554, 13.2018, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[139], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[140] = CreateDynamicObject(19940, 1218.9680, -1424.0554, 12.7618, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[140], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[141] = CreateDynamicObject(19623, 1213.1328, -1423.9488, 13.4935, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Camera1
	object_electronicsShop[142] = CreateDynamicObject(19940, 1220.9677, -1423.1743, 12.7618, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[142], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[143] = CreateDynamicObject(19940, 1218.9759, -1423.1729, 13.2018, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[143], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[144] = CreateDynamicObject(19940, 1221.9493, -1423.4045, 12.4218, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[144], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[145] = CreateDynamicObject(19940, 1220.9681, -1423.1743, 13.2018, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[145], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[146] = CreateDynamicObject(19920, 1214.8317, -1428.3546, 13.4847, 0.0000, 0.0000, -152.2999, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneRemote1
	object_electronicsShop[147] = CreateDynamicObject(19614, 1208.7412, -1427.8017, 12.5514, 0.0000, 0.0000, 135.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GuitarAmp3
	object_electronicsShop[148] = CreateDynamicObject(19940, 1221.9493, -1423.8449, 12.4218, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[148], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[149] = CreateDynamicObject(19940, 1220.9681, -1424.0551, 13.2018, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[149], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[150] = CreateDynamicObject(19940, 1220.9681, -1424.0551, 12.7618, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[150], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[151] = CreateDynamicObject(19317, 1209.9017, -1428.7960, 14.0674, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bassguitar01
	object_electronicsShop[152] = CreateDynamicObject(19940, 1218.9680, -1423.2442, 13.4218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[152], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[153] = CreateDynamicObject(19940, 1218.9680, -1423.6846, 13.4218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[153], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[154] = CreateDynamicObject(19940, 1220.9683, -1423.2442, 13.4218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[154], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[155] = CreateDynamicObject(19940, 1220.9683, -1423.6846, 13.4218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[155], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[156] = CreateDynamicObject(19940, 1220.9683, -1423.9849, 13.4218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[156], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[157] = CreateDynamicObject(1788, 1213.0706, -1428.4511, 13.8191, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWANK_VIDEO_1
	object_electronicsShop[158] = CreateDynamicObject(19940, 1218.9686, -1423.9849, 13.4218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[158], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[159] = CreateDynamicObject(19893, 1220.9530, -1423.9154, 13.4366, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
	object_electronicsShop[160] = CreateDynamicObject(19893, 1220.9530, -1423.3148, 13.4366, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
	object_electronicsShop[161] = CreateDynamicObject(19893, 1219.9521, -1423.3148, 13.4366, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
	object_electronicsShop[162] = CreateDynamicObject(2226, 1212.4564, -1423.5045, 13.4362, 0.0000, 0.0000, -135.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LOW_HI_FI_3
	object_electronicsShop[163] = CreateDynamicObject(19893, 1219.0014, -1423.3148, 13.4366, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
	object_electronicsShop[164] = CreateDynamicObject(2100, 1208.1933, -1418.2250, 12.5461, 0.0000, 0.0000, 42.1999, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_HI_FI_2
	object_electronicsShop[165] = CreateDynamicObject(19319, 1209.1936, -1428.7952, 14.0373, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //warlock01
	object_electronicsShop[166] = CreateDynamicObject(19318, 1208.4934, -1428.8231, 14.0222, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flyingv01
	object_electronicsShop[167] = CreateDynamicObject(19808, 1215.3853, -1423.3286, 13.4475, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
	object_electronicsShop[168] = CreateDynamicObject(19894, 1221.6713, -1423.6202, 13.4538, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP2
	object_electronicsShop[169] = CreateDynamicObject(19893, 1219.9523, -1423.9154, 13.4366, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
	object_electronicsShop[170] = CreateDynamicObject(19893, 1219.0014, -1423.9154, 13.4366, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
	object_electronicsShop[171] = CreateDynamicObject(19894, 1218.2485, -1423.6202, 13.4538, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP2
	object_electronicsShop[172] = CreateDynamicObject(19940, 1214.9240, -1423.1710, 13.2018, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[172], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[173] = CreateDynamicObject(19940, 1212.9334, -1423.1729, 13.2018, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[173], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[174] = CreateDynamicObject(19940, 1212.9334, -1423.1729, 12.7618, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[174], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[175] = CreateDynamicObject(19940, 1214.9255, -1424.0539, 12.7618, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[175], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[176] = CreateDynamicObject(19940, 1212.9338, -1424.0554, 13.2018, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[176], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[177] = CreateDynamicObject(19940, 1211.9548, -1423.8449, 12.4218, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[177], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[178] = CreateDynamicObject(19940, 1211.9533, -1423.4045, 12.4218, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[178], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[179] = CreateDynamicObject(19940, 1215.9050, -1423.4045, 12.4218, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[179], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[180] = CreateDynamicObject(19940, 1215.9050, -1423.8449, 12.4218, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[180], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[181] = CreateDynamicObject(19940, 1214.9255, -1424.0539, 13.2018, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[181], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[182] = CreateDynamicObject(19940, 1214.9240, -1423.1710, 12.7618, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[182], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[183] = CreateDynamicObject(19940, 1212.9338, -1424.0554, 12.7618, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[183], 0, 14789, "ab_sfgymmain", "ab_wood02", 0xFFFFFFFF);
	object_electronicsShop[184] = CreateDynamicObject(19940, 1214.9300, -1423.5947, 13.4218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[184], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[185] = CreateDynamicObject(19940, 1212.9300, -1423.9849, 13.4218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[185], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[186] = CreateDynamicObject(19940, 1214.9300, -1423.2543, 13.4218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[186], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[187] = CreateDynamicObject(19940, 1212.9300, -1423.6046, 13.4218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[187], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[188] = CreateDynamicObject(19940, 1212.9300, -1423.2542, 13.4218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKShelf3
	SetDynamicObjectMaterial(object_electronicsShop[188], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_electronicsShop[189] = CreateDynamicObject(2684, 1231.8778, -1423.8537, 14.0634, -18.8000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post
	SetDynamicObjectMaterial(object_electronicsShop[189], 0, 10765, "airportgnd_sfse", "white", 0xFF193826);
	object_electronicsShop[190] = CreateDynamicObject(2684, 1231.8778, -1422.8129, 14.0634, -18.8000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post
	SetDynamicObjectMaterial(object_electronicsShop[190], 0, 10765, "airportgnd_sfse", "white", 0xFF162248);
	object_electronicsShop[191] = CreateDynamicObject(19808, 1215.3852, -1423.9189, 13.4475, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
	SetDynamicObjectMaterial(object_electronicsShop[191], 0, 16644, "a51_detailstuff", "Gen_Keyboard", 0xFFFFFFFF);
	object_electronicsShop[192] = CreateDynamicObject(11705, 1213.4713, -1423.3603, 13.4109, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlackTelephone1
	object_electronicsShop[193] = CreateDynamicObject(19807, 1214.4302, -1423.3178, 13.5098, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Telephone1
	object_electronicsShop[194] = CreateDynamicObject(2684, 1231.8778, -1423.4936, 14.0634, -18.8000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post
	SetDynamicObjectMaterial(object_electronicsShop[194], 0, 10765, "airportgnd_sfse", "white", 0xFF335F3F);
	object_electronicsShop[195] = CreateDynamicObject(8418, 1259.8723, -1427.7342, 13.2242, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgshpgrnd04_lvS
	object_electronicsShop[196] = CreateDynamicObject(8656, 1255.1525, -1438.6096, 12.7150, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shbbyhswall09_lvs
	SetDynamicObjectMaterial(object_electronicsShop[196], 0, 15034, "genhotelsave", "ab_mottleWhite", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_electronicsShop[196], 1, 14888, "gf6", "mp_millie_wallwhite", 0xFFFFFFFF);
	object_electronicsShop[197] = CreateDynamicObject(2684, 1231.8524, -1423.1933, 14.0098, -18.8000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post
	SetDynamicObjectMaterialText(object_electronicsShop[197], 0,"500$", 90, "Arial", 100, 1, 0xFF000000, 0x0, 0);
	object_electronicsShop[198] = CreateDynamicObject(2684, 1231.8671, -1423.2231, 13.3171, -18.8000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post
	SetDynamicObjectMaterial(object_electronicsShop[198], 0, 10765, "airportgnd_sfse", "white", 0xFF624428);
	object_electronicsShop[199] = CreateDynamicObject(2684, 1231.8524, -1423.5036, 14.0098, -18.8000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post
	SetDynamicObjectMaterialText(object_electronicsShop[199], 0,"1000$", 90, "Arial", 100, 1, 0xFF000000, 0x0, 0);
	object_electronicsShop[200] = CreateDynamicObject(2684, 1231.8524, -1422.8430, 14.0098, -18.8000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post
	SetDynamicObjectMaterialText(object_electronicsShop[200], 0,"100$", 90, "Arial", 100, 1, 0xFF000000, 0x0, 0);
	object_electronicsShop[201] = CreateDynamicObject(2684, 1231.8671, -1423.4934, 13.3171, -18.8000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post
	SetDynamicObjectMaterial(object_electronicsShop[201], 0, 10765, "airportgnd_sfse", "white", 0xFF624428);
	object_electronicsShop[202] = CreateDynamicObject(2684, 1231.8481, -1423.3631, 13.3236, -18.8000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post
	SetDynamicObjectMaterialText(object_electronicsShop[202], 0,"$", 0, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 2);
	object_electronicsShop[203] = CreateDynamicObject(2684, 1231.8481, -1423.3232, 13.3236, -18.8000, 0.0000, -90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_food_post
	SetDynamicObjectMaterialText(object_electronicsShop[203], 0,"10000$", 90, "Arial", 100, 1, 0xFFFFFFFF, 0x0, 0);
	object_electronicsShop[204] = CreateDynamicObject(19172, 1231.9523, -1423.3642, 14.7227, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_ELECTRONICSSHOP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterial(object_electronicsShop[204], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterialText(object_electronicsShop[204], 1,"Guthaben", 90, "Calibri", 40, 1, 0xFFFFFFFF, 0x0, 1);
}
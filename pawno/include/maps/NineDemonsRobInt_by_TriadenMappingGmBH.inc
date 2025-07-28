#include <YSI\y_hooks>

//#define NDAUFBRECHEN_COORDS 		-1438.6826,-1544.8363,102.2578
#define NDAUFBRECHEN_COORDS 		-572.3885,-1498.6389,9.5587
#define NDINTERIOR_EXIT_COORDS		-1210.7473,-1200.3148,1001.5000
#define NDRobInt_C4_COORDS 			-1201.0833,-1223.0980,1001.5000
#define NDEXTERIOR_ENTER_COORDS		-1068.3521,-1205.6052,129.7565
#define MAPS_NDROBINT_INTERIOR   	0

#define ND_SPICEROB_COORDS1			-1202.3131,-1225.9441,1001.5000
#define ND_SPICEROB_COORDS2			-1202.3129,-1229.2037,1001.5000
#define ND_SPICEROB_COORDS3			-1202.3132,-1232.1127,1001.5000
#define ND_SPICEROB_COORDS4			-1199.9542,-1232.3296,1001.5000
#define ND_SPICEROB_COORDS5			-1199.9550,-1229.2733,1001.5000
#define ND_SPICEROB_COORDS6			-1199.9618,-1226.0671,1001.5000

new NDRobInt[287];
new NDRobInt_Pickup[3];
new text3D_NDRobInt[2];
new Text3D:text3D_NDRobInt_Spice[6];





// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;


hook OnGameModeInit()
{
	NDRobInt[0] = CreateDynamicObject(19445, -1214.1700, -1223.4100, 1002.2285, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[0], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[1] = CreateDynamicObject(19445, -1189.3277, -1201.1069, 1002.2285, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[1], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[2] = CreateDynamicObject(19445, -1214.1700, -1213.7750, 1002.2285, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[2], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[3] = CreateDynamicObject(19445, -1194.2408, -1224.2386, 1002.2285, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[3], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[4] = CreateDynamicObject(19445, -1214.1700, -1204.1999, 1002.2285, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[4], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[5] = CreateDynamicObject(19445, -1203.7967, -1199.3962, 1002.2285, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[5], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[6] = CreateDynamicObject(19445, -1194.1782, -1199.3962, 1002.2285, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[6], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[7] = CreateDynamicObject(19445, -1213.4063, -1199.3962, 1002.2285, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[7], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[8] = CreateDynamicObject(19353, -1194.1938, -1215.6898, 1005.7196, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[8], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[9] = CreateDynamicObject(19353, -1214.4897, -1224.2386, 1005.7166, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[9], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[10] = CreateDynamicObject(19445, -1189.3277, -1219.4870, 1002.2285, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[10], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[11] = CreateDynamicObject(18766, -1201.3944, -1229.3138, 1000.0000, 90.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(NDRobInt[11], 0, 9583, "bigshap_sfw", "shipfloor_sfw", 0xFFF8F8FF);
	NDRobInt[12] = CreateDynamicObject(19445, -1189.3277, -1210.7374, 1002.2285, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[12], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[13] = CreateDynamicObject(19445, -1198.9383, -1229.1180, 1002.2285, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[13], 0, 6863, "vgsnbuild07", "vegasbank3_256", 0xFFF8F8FF);
	NDRobInt[14] = CreateDynamicObject(2963, -1201.1771, -1224.3874, 1002.5615, 0.0000, 0.0000, -89.7997, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //freezer_door
	NDRobInt[15] = CreateDynamicObject(19445, -1203.3398, -1229.1180, 1002.2285, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[15], 0, 6863, "vgsnbuild07", "vegasbank3_256", 0xFFF8F8FF);
	NDRobInt[16] = CreateDynamicObject(2475, -1203.1479, -1226.1888, 1001.3543, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_3
	NDRobInt[17] = CreateDynamicObject(19445, -1198.6003, -1233.8479, 1002.2285, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[17], 0, 6863, "vgsnbuild07", "vegasbank3_256", 0xFFF8F8FF);
	NDRobInt[18] = CreateDynamicObject(19445, -1208.0727, -1224.2386, 1002.2285, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[18], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[19] = CreateDynamicObject(3130, -1201.1783, -1233.5699, 1000.3515, 0.0000, 0.0000, 180.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MTSafe
	NDRobInt[20] = CreateDynamicObject(2475, -1203.1479, -1232.4099, 1001.3543, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_3
	NDRobInt[21] = CreateDynamicObject(2475, -1203.1479, -1229.3498, 1001.3543, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_3
	NDRobInt[22] = CreateDynamicObject(2475, -1199.1184, -1225.6883, 1001.3543, 0.0000, 0.0000, 270.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_3
	NDRobInt[23] = CreateDynamicObject(2475, -1199.1184, -1228.8790, 1001.3543, 0.0000, 0.0000, 270.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_3
	NDRobInt[24] = CreateDynamicObject(2475, -1199.1184, -1232.0227, 1001.3543, 0.0000, 0.0000, 270.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_3
	NDRobInt[25] = CreateDynamicObject(1580, -1202.8614, -1225.5190, 1001.4816, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_red
	NDRobInt[26] = CreateDynamicObject(1580, -1203.0013, -1226.3901, 1002.1621, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_red
	NDRobInt[27] = CreateDynamicObject(1580, -1202.9615, -1225.9498, 1002.8626, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_red
	NDRobInt[28] = CreateDynamicObject(1575, -1202.9615, -1229.5400, 1002.8513, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
	NDRobInt[29] = CreateDynamicObject(1575, -1202.9615, -1228.5394, 1002.1306, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
	NDRobInt[30] = CreateDynamicObject(1575, -1202.9615, -1229.0898, 1001.4802, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
	NDRobInt[31] = CreateDynamicObject(1578, -1202.9615, -1232.1656, 1002.1507, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_green
	NDRobInt[32] = CreateDynamicObject(1578, -1202.9615, -1232.5262, 1002.8416, 0.0000, 0.0000, 90.0998, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_green
	NDRobInt[33] = CreateDynamicObject(1578, -1202.9615, -1232.6062, 1001.4702, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_green
	NDRobInt[34] = CreateDynamicObject(1576, -1199.3227, -1231.8032, 1002.8496, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_orange
	NDRobInt[35] = CreateDynamicObject(1576, -1199.3227, -1232.8227, 1002.1594, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_orange
	NDRobInt[36] = CreateDynamicObject(1576, -1199.3227, -1232.3225, 1001.4591, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_orange
	NDRobInt[37] = CreateDynamicObject(939, -1206.6134, -1204.1789, 1001.3676, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_DF_UNIT
	NDRobInt[38] = CreateDynamicObject(19353, -1194.1938, -1215.6898, 1002.2285, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[38], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[39] = CreateDynamicObject(3383, -1209.9591, -1218.6500, 1000.3728, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_labtable1_
	NDRobInt[40] = CreateDynamicObject(941, -1197.1866, -1207.4898, 1000.9691, 0.0000, 0.0000, 103.7999, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_DF_WORKTOP_3
	SetDynamicObjectMaterial(NDRobInt[40], 0, -1, "none", "none", 0xFF006400);
	NDRobInt[41] = CreateDynamicObject(2977, -1209.2285, -1209.7960, 1000.3630, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmilitary_crate
	NDRobInt[42] = CreateDynamicObject(19353, -1207.7850, -1201.1013, 1002.2285, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[42], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[43] = CreateDynamicObject(19353, -1207.7850, -1204.3134, 1005.7196, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[43], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[44] = CreateDynamicObject(19383, -1207.7850, -1207.5229, 1002.2285, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall031
	SetDynamicObjectMaterial(NDRobInt[44], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[45] = CreateDynamicObject(19383, -1195.7136, -1220.5423, 1002.2285, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall031
	SetDynamicObjectMaterial(NDRobInt[45], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[46] = CreateDynamicObject(3386, -1213.5477, -1222.7110, 1000.4349, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack2_
	NDRobInt[47] = CreateDynamicObject(19353, -1209.3005, -1209.1999, 1002.2285, 0.0000, 0.0000, -90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[47], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[48] = CreateDynamicObject(3389, -1212.5401, -1223.6800, 1000.4265, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack1_
	NDRobInt[49] = CreateDynamicObject(3396, -1213.5439, -1220.3217, 1000.4992, 0.0000, 0.0000, 180.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_sdsk_4_
	NDRobInt[50] = CreateDynamicObject(19353, -1212.5114, -1209.1999, 1002.2285, 0.0000, 0.0000, -90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[50], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[51] = CreateDynamicObject(1491, -1207.8050, -1206.7192, 1000.4873, 0.0000, 0.0000, -90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
	SetDynamicObjectMaterial(NDRobInt[51], 0, 3241, "conhooses", "trail_door", 0x00000000);
	NDRobInt[52] = CreateDynamicObject(939, -1205.1434, -1200.5986, 1001.3676, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_DF_UNIT
	NDRobInt[53] = CreateDynamicObject(3395, -1213.5642, -1216.7563, 1000.5076, 0.0000, 0.0000, 180.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_sdsk_3_
	NDRobInt[54] = CreateDynamicObject(1703, -1193.0598, -1200.0637, 1000.4022, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch02
	NDRobInt[55] = CreateDynamicObject(1575, -1209.8071, -1218.2369, 1001.3720, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
	NDRobInt[56] = CreateDynamicObject(1575, -1209.8072, -1218.4018, 1001.4080, 19.0000, 0.7998, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
	NDRobInt[57] = CreateDynamicObject(1580, -1209.7016, -1219.6898, 1001.4019, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_red
	NDRobInt[58] = CreateDynamicObject(1580, -1209.8216, -1220.1402, 1001.4019, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_red
	NDRobInt[59] = CreateDynamicObject(1578, -1209.9575, -1219.6582, 1001.5014, 0.0000, -22.6000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_green
	NDRobInt[60] = CreateDynamicObject(1577, -1210.1507, -1219.0107, 1001.4232, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_yellow
	NDRobInt[61] = CreateDynamicObject(1575, -1210.1579, -1217.3198, 1001.3834, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
	NDRobInt[62] = CreateDynamicObject(1806, -1209.9632, -1222.3916, 1000.4724, 0.0000, 0.0000, 158.9998, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
	NDRobInt[63] = CreateDynamicObject(1806, -1212.4843, -1220.4321, 1000.4724, 0.0000, 0.0000, 70.5998, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
	NDRobInt[64] = CreateDynamicObject(939, -1199.9035, -1200.5986, 1001.3676, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_DF_UNIT
	NDRobInt[65] = CreateDynamicObject(3396, -1210.2849, -1223.5526, 1000.4992, 0.0000, 0.0000, -90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_sdsk_4_
	NDRobInt[66] = CreateDynamicObject(1703, -1194.0622, -1202.9256, 1000.4022, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch02
	NDRobInt[67] = CreateDynamicObject(19305, -1203.6551, -1224.2099, 1002.0078, 0.0000, 0.0000, 180.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subbridge_lift
	NDRobInt[68] = CreateDynamicObject(1823, -1192.4809, -1202.3652, 1000.4721, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_MED_5
	SetDynamicObjectMaterial(NDRobInt[68], 0, -1, "none", "none", 0xFFF0E68C);
	NDRobInt[69] = CreateDynamicObject(2977, -1213.5478, -1209.7641, 1000.3630, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmilitary_crate
	NDRobInt[70] = CreateDynamicObject(2977, -1212.4886, -1209.7641, 1000.3630, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmilitary_crate
	NDRobInt[71] = CreateDynamicObject(2977, -1213.5694, -1210.8449, 1000.3630, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmilitary_crate
	NDRobInt[72] = CreateDynamicObject(2977, -1213.5694, -1209.8039, 1001.4038, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmilitary_crate
	NDRobInt[73] = CreateDynamicObject(348, -1191.9554, -1202.1263, 1001.0206, -85.5998, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
	NDRobInt[74] = CreateDynamicObject(2977, -1211.4000, -1209.7960, 1000.3630, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmilitary_crate
	NDRobInt[75] = CreateDynamicObject(2977, -1210.3193, -1209.7960, 1000.3630, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmilitary_crate
	NDRobInt[76] = CreateDynamicObject(2977, -1210.3081, -1209.8239, 1001.4038, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmilitary_crate
	NDRobInt[77] = CreateDynamicObject(1535, -1211.8858, -1199.4776, 1000.5040, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT14
	SetDynamicObjectMaterial(NDRobInt[77], 0, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	NDRobInt[78] = CreateDynamicObject(356, -1192.2844, -1201.7711, 1001.0219, -95.1998, -17.5000, -4.5000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //m4
	NDRobInt[79] = CreateDynamicObject(3092, -1189.8192, -1200.0708, 1001.4096, 21.8999, 5.3998, 130.5998, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //dead_tied_cop
	NDRobInt[81] = CreateDynamicObject(19075, -1187.8420, -1198.0887, 1001.0899, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cage5mx5mx3mv2
	NDRobInt[82] = CreateDynamicObject(1576, -1209.6833, -1217.7541, 1001.4014, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_orange
	NDRobInt[83] = CreateDynamicObject(14680, -1209.8758, -1221.2502, 1002.9912, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	NDRobInt[84] = CreateDynamicObject(1575, -1189.5628, -1208.5269, 1001.8989, 0.0000, 0.0000, -91.0999, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
	NDRobInt[85] = CreateDynamicObject(19445, -1208.0727, -1224.2386, 1005.7196, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[85], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[86] = CreateDynamicObject(19445, -1189.3277, -1219.4870, 1005.7196, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[86], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[87] = CreateDynamicObject(19353, -1195.7136, -1217.3614, 1002.2285, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[87], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[88] = CreateDynamicObject(19353, -1190.9842, -1215.6898, 1002.2285, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[88], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[89] = CreateDynamicObject(19353, -1195.7136, -1223.7508, 1002.2285, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[89], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[90] = CreateDynamicObject(1491, -1195.7141, -1219.7602, 1000.4873, 0.0000, 0.0000, -90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
	SetDynamicObjectMaterial(NDRobInt[90], 0, 3241, "conhooses", "trail_door", 0x00000000);
	NDRobInt[91] = CreateDynamicObject(19445, -1214.1700, -1223.4100, 1005.7196, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[91], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[92] = CreateDynamicObject(3633, -1213.4007, -1213.1909, 1000.9547, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //imoildrum4_LAS
	NDRobInt[93] = CreateDynamicObject(19445, -1189.3277, -1210.7374, 1005.7196, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[93], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[94] = CreateDynamicObject(3675, -1214.0318, -1214.3316, 1004.0830, 180.0000, 0.0000, -90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //laxrf_refinerypipe
	NDRobInt[95] = CreateDynamicObject(19786, -1189.3382, -1202.1024, 1001.8646, 0.0000, 0.0000, -90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
	NDRobInt[96] = CreateDynamicObject(18979, -1191.6324, -1201.7697, 1001.0883, 89.5000, -0.7998, -62.2999, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MotorcycleHelmet5
	SetDynamicObjectMaterial(NDRobInt[96], 0, -1, "none", "none", 0xFF006400);
	NDRobInt[97] = CreateDynamicObject(2964, -1192.6933, -1204.8571, 1000.4594, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_pooltablesm
	SetDynamicObjectMaterial(NDRobInt[97], 0, -1, "none", "none", 0xFF006400);
	SetDynamicObjectMaterial(NDRobInt[97], 1, -1, "none", "none", 0xFF006400);
	NDRobInt[98] = CreateDynamicObject(3104, -1193.2832, -1204.6197, 1001.3911, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballspt06
	NDRobInt[99] = CreateDynamicObject(18981, -1201.7495, -1211.8237, 1000.0000, 0.0000, -90.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(NDRobInt[99], 0, 9583, "bigshap_sfw", "shipfloor_sfw", 0xFFF8F8FF);
	NDRobInt[100] = CreateDynamicObject(3105, -1193.1784, -1205.1652, 1001.3881, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballspt07
	NDRobInt[101] = CreateDynamicObject(3102, -1192.4931, -1204.8940, 1001.3930, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballspt04
	NDRobInt[102] = CreateDynamicObject(16151, -1190.4858, -1210.7386, 1000.7567, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_bar
	NDRobInt[103] = CreateDynamicObject(3000, -1192.0050, -1204.5572, 1001.3944, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballstp06
	NDRobInt[104] = CreateDynamicObject(338, -1193.3505, -1204.1494, 1000.7751, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //poolcue
	NDRobInt[105] = CreateDynamicObject(18981, -1201.7495, -1211.8237, 1005.1314, 0.0000, -90.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(NDRobInt[105], 0, 16640, "a51", "ws_metalpanel1", 0x00000000);
	NDRobInt[106] = CreateDynamicObject(2995, -1192.0780, -1205.2064, 1001.3936, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballstp01
	NDRobInt[107] = CreateDynamicObject(19353, -1195.7136, -1217.3614, 1005.7199, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[107], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[108] = CreateDynamicObject(19353, -1195.7136, -1220.5732, 1005.7199, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[108], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[109] = CreateDynamicObject(2998, -1192.7081, -1204.6906, 1001.3914, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //k_poolballstp04
	NDRobInt[110] = CreateDynamicObject(19353, -1195.7136, -1223.7543, 1005.7199, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[110], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[111] = CreateDynamicObject(19445, -1194.2408, -1224.2386, 1005.7196, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[111], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[112] = CreateDynamicObject(338, -1192.2089, -1205.5936, 1000.8259, -7.7999, 0.5999, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //poolcue
	NDRobInt[113] = CreateDynamicObject(19445, -1189.3277, -1201.1069, 1005.7196, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[113], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[114] = CreateDynamicObject(19445, -1194.1782, -1199.3962, 1005.7196, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[114], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[115] = CreateDynamicObject(19353, -1214.4897, -1224.2386, 1002.2285, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[115], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[116] = CreateDynamicObject(19445, -1203.7967, -1199.3962, 1005.7196, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[116], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[117] = CreateDynamicObject(19445, -1214.1700, -1204.1999, 1005.7196, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[117], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[118] = CreateDynamicObject(19445, -1213.4063, -1199.3962, 1005.7196, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[118], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[119] = CreateDynamicObject(19445, -1214.1700, -1213.7750, 1005.7196, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[119], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[120] = CreateDynamicObject(19353, -1190.9842, -1215.6898, 1005.7196, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[120], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[121] = CreateDynamicObject(19445, -1203.3398, -1229.1180, 1005.7196, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[121], 0, 6863, "vgsnbuild07", "vegasbank3_256", 0xFFF8F8FF);
	NDRobInt[122] = CreateDynamicObject(19445, -1198.6003, -1233.8479, 1005.7196, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[122], 0, 6863, "vgsnbuild07", "vegasbank3_256", 0xFFF8F8FF);
	NDRobInt[123] = CreateDynamicObject(19445, -1198.6003, -1233.8479, 1002.2285, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[123], 0, 6863, "vgsnbuild07", "vegasbank3_256", 0xFFF8F8FF);
	NDRobInt[124] = CreateDynamicObject(18766, -1201.3944, -1229.3138, 1005.1314, 90.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(NDRobInt[124], 0, 13628, "8stad", "stadroof", 0xFFF8F8FF);
	NDRobInt[125] = CreateDynamicObject(19445, -1198.9383, -1229.1180, 1005.7196, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(NDRobInt[125], 0, 6863, "vgsnbuild07", "vegasbank3_256", 0xFFF8F8FF);
	NDRobInt[126] = CreateDynamicObject(19353, -1212.5114, -1209.1999, 1005.7196, 0.0000, 0.0000, -90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[126], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[127] = CreateDynamicObject(19353, -1207.7850, -1204.3134, 1002.2199, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[127], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[128] = CreateDynamicObject(19353, -1209.3005, -1209.1999, 1005.7196, 0.0000, 0.0000, -90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[128], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[129] = CreateDynamicObject(19353, -1207.7850, -1201.1013, 1005.7196, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[129], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[130] = CreateDynamicObject(19353, -1207.7850, -1207.4947, 1005.7196, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(NDRobInt[130], 0, 18065, "ab_sfammumain", "breezewall", 0xFFF8F8FF);
	NDRobInt[131] = CreateDynamicObject(1886, -1199.4129, -1233.2554, 1004.6812, 15.7000, -0.6000, -149.3003, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
	NDRobInt[132] = CreateDynamicObject(14680, -1201.1740, -1206.7967, 1002.9912, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	NDRobInt[133] = CreateDynamicObject(1720, -1212.1267, -1208.5518, 1000.7742, 177.6999, -91.5000, -57.8998, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rest_chair
	SetDynamicObjectMaterial(NDRobInt[133], 0, -1, "none", "none", 0xFF006400);
	NDRobInt[134] = CreateDynamicObject(2635, -1211.4301, -1208.5821, 1000.8875, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_TABLE
	SetDynamicObjectMaterial(NDRobInt[134], 0, -1, "none", "none", 0xFF006400);
	NDRobInt[135] = CreateDynamicObject(11729, -1189.6633, -1216.1403, 1000.4727, 0.0000, 0.0000, -89.1000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
	NDRobInt[154] = CreateDynamicObject(1670, -1211.3592, -1208.5350, 1001.3272, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
	NDRobInt[155] = CreateDynamicObject(11729, -1189.6523, -1216.8510, 1000.4727, 0.0000, 0.0000, -89.1000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
	NDRobInt[156] = CreateDynamicObject(11729, -1189.6408, -1217.5817, 1000.4727, 0.0000, 0.0000, -89.1000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
	NDRobInt[157] = CreateDynamicObject(11729, -1189.6314, -1218.2624, 1000.4727, 0.0000, 0.0000, -89.1000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
	NDRobInt[158] = CreateDynamicObject(11730, -1189.6276, -1218.9497, 1000.4727, 0.0000, 0.0000, -91.3999, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerOpen1
	NDRobInt[159] = CreateDynamicObject(11730, -1189.6437, -1219.6103, 1000.4727, 0.0000, 0.0000, -91.3999, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerOpen1
	NDRobInt[160] = CreateDynamicObject(11729, -1189.5993, -1220.3016, 1000.4727, 0.0000, 0.0000, -89.1000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
	NDRobInt[161] = CreateDynamicObject(11729, -1189.5883, -1220.9923, 1000.4727, 0.0000, 0.0000, -89.1000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
	NDRobInt[162] = CreateDynamicObject(11729, -1189.5786, -1221.6729, 1000.4727, 0.0000, 0.0000, -89.1000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
	NDRobInt[163] = CreateDynamicObject(1520, -1191.1149, -1207.4111, 1001.4462, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WINE_BOUNCE
	NDRobInt[164] = CreateDynamicObject(11691, -1194.5600, -1217.6000, 1000.5087, 0.0000, 0.0000, -88.0999, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CTable2
	SetDynamicObjectMaterial(NDRobInt[164], 0, -1, "none", "none", 0xFF2F4F4F);
	NDRobInt[165] = CreateDynamicObject(362, -1195.0026, -1218.1361, 1001.5269, 0.0000, 25.9000, -34.8000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //minigun
	NDRobInt[166] = CreateDynamicObject(1886, -1213.6881, -1208.5976, 1004.6991, 15.7000, -0.6000, 157.1998, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
	NDRobInt[167] = CreateDynamicObject(355, -1194.5538, -1217.2017, 1001.3698, -82.4999, 138.7999, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ak47
	NDRobInt[168] = CreateDynamicObject(2041, -1194.1821, -1217.7984, 1001.5000, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M2
	NDRobInt[169] = CreateDynamicObject(14680, -1201.1740, -1213.8403, 1002.9912, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	NDRobInt[170] = CreateDynamicObject(3383, -1208.0290, -1218.6602, 1000.3728, 0.0000, 0.0000, -90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_labtable1_
	NDRobInt[171] = CreateDynamicObject(14680, -1201.1740, -1221.3410, 1002.9912, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	NDRobInt[172] = CreateDynamicObject(14680, -1192.6218, -1206.7967, 1002.9912, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	NDRobInt[173] = CreateDynamicObject(1550, -1195.4132, -1223.9188, 1000.8478, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
	NDRobInt[174] = CreateDynamicObject(1550, -1194.9627, -1223.9188, 1000.8478, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
	NDRobInt[175] = CreateDynamicObject(1550, -1194.5323, -1223.9188, 1000.8478, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
	NDRobInt[176] = CreateDynamicObject(14680, -1192.6218, -1213.8099, 1002.9912, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	NDRobInt[177] = CreateDynamicObject(922, -1208.3433, -1202.6735, 1001.3692, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Packing_carates1
	NDRobInt[178] = CreateDynamicObject(19172, -1192.1092, -1199.5377, 1002.3938, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	NDRobInt[179] = CreateDynamicObject(19823, -1191.3902, -1208.3886, 1001.3843, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle4
	NDRobInt[180] = CreateDynamicObject(19822, -1191.3218, -1208.9787, 1001.4451, 1.8000, -90.6999, 50.4999, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle3
	NDRobInt[181] = CreateDynamicObject(19823, -1191.4241, -1208.4891, 1001.3843, 0.0000, 0.0000, 128.4999, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AlcoholBottle4
	NDRobInt[182] = CreateDynamicObject(1665, -1191.5200, -1209.8757, 1001.4143, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propashtray1
	NDRobInt[183] = CreateDynamicObject(19818, -1191.6477, -1210.2824, 1001.4716, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WineGlass1
	NDRobInt[184] = CreateDynamicObject(2628, -1190.3056, -1223.0709, 1000.4688, 0.0000, 0.0000, -90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bench2
	NDRobInt[185] = CreateDynamicObject(630, -1193.8568, -1200.0396, 1001.5137, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_palmkb8
	NDRobInt[186] = CreateDynamicObject(1829, -1201.2324, -1232.9141, 1001.0178, 0.0000, 0.0000, 179.8999, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //man_safenew
	NDRobInt[187] = CreateDynamicObject(2629, -1192.0792, -1223.4134, 1000.4583, 0.0000, 0.0000, 180.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bench1
	NDRobInt[188] = CreateDynamicObject(2630, -1193.7954, -1223.3707, 1000.4713, 0.0000, 0.0000, 180.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gym_bike
	NDRobInt[189] = CreateDynamicObject(14680, -1209.8758, -1214.9318, 1002.9912, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	NDRobInt[190] = CreateDynamicObject(2616, -1193.6682, -1215.5452, 1002.1505, 0.0000, 0.0000, 180.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_NB04
	NDRobInt[191] = CreateDynamicObject(1541, -1191.0155, -1211.4686, 1001.5689, 0.0000, 0.0000, -89.6000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_TAPS_1
	NDRobInt[192] = CreateDynamicObject(1666, -1191.5866, -1208.1611, 1001.4771, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propbeerglass1
	NDRobInt[193] = CreateDynamicObject(630, -1213.6000, -1199.9797, 1001.5137, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_palmkb8
	NDRobInt[194] = CreateDynamicObject(2235, -1190.8732, -1219.0219, 1000.5097, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_MED_6
	NDRobInt[195] = CreateDynamicObject(630, -1208.3175, -1199.9996, 1001.5137, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_palmkb8
	NDRobInt[196] = CreateDynamicObject(2961, -1209.6964, -1199.5155, 1001.9702, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire_break
	NDRobInt[197] = CreateDynamicObject(19996, -1196.0229, -1206.3515, 1000.4896, 0.0000, 0.0000, -49.5000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneFoldChair1
	NDRobInt[198] = CreateDynamicObject(1438, -1204.3356, -1203.1197, 1000.4659, 0.0000, 0.0000, 86.1999, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_BOX_PILE_2
	NDRobInt[199] = CreateDynamicObject(19996, -1195.7529, -1207.5144, 1000.4696, 0.0000, 0.0000, -79.9999, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneFoldChair1
	NDRobInt[200] = CreateDynamicObject(19996, -1198.2133, -1208.0634, 1000.7298, 0.0000, -90.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneFoldChair1
	NDRobInt[201] = CreateDynamicObject(19165, -1208.0274, -1218.4896, 1001.4251, -0.4999, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAMap2
	NDRobInt[202] = CreateDynamicObject(19996, -1198.6560, -1207.0091, 1000.4996, 0.0000, 0.0000, 82.0999, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneFoldChair1
	NDRobInt[203] = CreateDynamicObject(1550, -1208.1235, -1220.0002, 1001.7482, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
	NDRobInt[204] = CreateDynamicObject(1550, -1207.6534, -1219.7696, 1001.6798, 0.0000, 80.2999, 23.9000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
	NDRobInt[205] = CreateDynamicObject(1550, -1207.7231, -1217.3287, 1001.7482, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
	NDRobInt[206] = CreateDynamicObject(1654, -1197.3856, -1206.8043, 1001.5046, -33.0000, 90.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //dynamite
	NDRobInt[207] = CreateDynamicObject(1654, -1197.3856, -1206.4895, 1001.4918, -33.0000, 90.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //dynamite
	NDRobInt[208] = CreateDynamicObject(335, -1197.3347, -1208.0418, 1001.4199, 90.0000, 32.9999, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //knifecur
	NDRobInt[209] = CreateDynamicObject(352, -1197.0959, -1207.2565, 1001.4399, 90.0000, -36.3001, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //micro_uzi
	NDRobInt[210] = CreateDynamicObject(352, -1196.8682, -1207.8096, 1001.5067, -84.9000, 90.5999, 176.5000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //micro_uzi
	NDRobInt[211] = CreateDynamicObject(922, -1196.2823, -1217.4969, 1001.3692, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Packing_carates1
	NDRobInt[212] = CreateDynamicObject(2235, -1190.8732, -1217.4105, 1000.5097, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //COFFEE_MED_6
	NDRobInt[213] = CreateDynamicObject(1210, -1199.4035, -1228.8674, 1001.5731, 90.0000, -90.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //briefcase
	NDRobInt[214] = CreateDynamicObject(19941, -1199.1855, -1226.6429, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[215] = CreateDynamicObject(19941, -1199.1855, -1226.5628, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[216] = CreateDynamicObject(19941, -1199.1855, -1226.4827, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[217] = CreateDynamicObject(19941, -1199.1855, -1226.3927, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[218] = CreateDynamicObject(19941, -1199.1855, -1226.3026, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[219] = CreateDynamicObject(19941, -1199.1855, -1226.2125, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[220] = CreateDynamicObject(19941, -1199.1855, -1226.1224, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[221] = CreateDynamicObject(19941, -1199.1855, -1226.0323, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[222] = CreateDynamicObject(19941, -1199.1855, -1225.9526, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[223] = CreateDynamicObject(19941, -1199.1855, -1225.8725, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[224] = CreateDynamicObject(19941, -1199.1855, -1225.7924, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[225] = CreateDynamicObject(19941, -1199.1855, -1225.7023, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[226] = CreateDynamicObject(19941, -1199.1855, -1225.6223, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[227] = CreateDynamicObject(19941, -1199.1855, -1225.5322, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[228] = CreateDynamicObject(19941, -1199.1855, -1225.4521, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[229] = CreateDynamicObject(19941, -1199.1855, -1225.3820, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[230] = CreateDynamicObject(19941, -1199.1855, -1225.2919, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[231] = CreateDynamicObject(19941, -1199.3757, -1225.2919, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[232] = CreateDynamicObject(19941, -1199.3757, -1225.3820, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[233] = CreateDynamicObject(19941, -1199.3757, -1225.4621, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[234] = CreateDynamicObject(19941, -1199.3757, -1225.5322, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[235] = CreateDynamicObject(19941, -1199.3757, -1225.6923, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[236] = CreateDynamicObject(19941, -1199.3757, -1225.6022, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[237] = CreateDynamicObject(19941, -1199.3757, -1225.7824, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[238] = CreateDynamicObject(19941, -1199.3757, -1225.8725, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[239] = CreateDynamicObject(19941, -1199.3757, -1225.9526, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[240] = CreateDynamicObject(19941, -1199.3757, -1226.0327, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[241] = CreateDynamicObject(19941, -1199.3757, -1226.1228, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[242] = CreateDynamicObject(19941, -1199.3757, -1226.2028, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[243] = CreateDynamicObject(19941, -1199.3757, -1226.2929, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[244] = CreateDynamicObject(19941, -1199.3757, -1226.3730, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[245] = CreateDynamicObject(19941, -1199.3757, -1226.4531, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[246] = CreateDynamicObject(19941, -1199.3757, -1226.5332, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[247] = CreateDynamicObject(19941, -1199.3757, -1226.6132, 1001.4810, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[248] = CreateDynamicObject(19941, -1199.1755, -1226.6132, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[249] = CreateDynamicObject(19941, -1199.1755, -1226.5131, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[250] = CreateDynamicObject(19941, -1199.1755, -1226.4230, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[251] = CreateDynamicObject(19941, -1199.1755, -1226.3330, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[252] = CreateDynamicObject(19941, -1199.1755, -1226.2429, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[253] = CreateDynamicObject(19941, -1199.1755, -1226.1628, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[254] = CreateDynamicObject(19941, -1199.1755, -1226.0727, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[255] = CreateDynamicObject(19941, -1199.1755, -1225.9826, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[256] = CreateDynamicObject(19941, -1199.1755, -1225.9025, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[257] = CreateDynamicObject(19941, -1199.1755, -1225.8225, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[258] = CreateDynamicObject(19941, -1199.1755, -1225.7316, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[259] = CreateDynamicObject(19941, -1199.1755, -1225.5715, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[260] = CreateDynamicObject(19941, -1199.1755, -1225.6416, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[261] = CreateDynamicObject(19941, -1199.1755, -1225.4814, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[262] = CreateDynamicObject(19941, -1199.1755, -1225.4013, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[263] = CreateDynamicObject(19941, -1199.1755, -1225.3212, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[264] = CreateDynamicObject(19941, -1199.3657, -1225.3413, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[265] = CreateDynamicObject(19941, -1199.3657, -1225.4213, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[266] = CreateDynamicObject(19941, -1199.3657, -1225.5114, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[267] = CreateDynamicObject(19941, -1199.3657, -1225.5815, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[268] = CreateDynamicObject(19941, -1199.3657, -1225.6616, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[269] = CreateDynamicObject(19941, -1199.3657, -1225.7510, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[270] = CreateDynamicObject(19941, -1199.3657, -1225.8409, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[271] = CreateDynamicObject(19941, -1199.3657, -1225.9110, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[272] = CreateDynamicObject(19941, -1199.3657, -1225.9910, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[273] = CreateDynamicObject(19941, -1199.3657, -1226.0811, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[274] = CreateDynamicObject(19941, -1199.3657, -1226.1613, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[275] = CreateDynamicObject(19941, -1199.3657, -1226.2514, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[276] = CreateDynamicObject(19941, -1199.3657, -1226.3415, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[277] = CreateDynamicObject(19941, -1199.3657, -1226.4316, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[278] = CreateDynamicObject(19941, -1199.3657, -1226.5117, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[279] = CreateDynamicObject(19941, -1199.3657, -1226.5917, 1001.5211, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GoldBar1
	NDRobInt[280] = CreateDynamicObject(1636, -1199.1540, -1228.6973, 1002.9701, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rcbomb
	NDRobInt[281] = CreateDynamicObject(1210, -1199.4035, -1229.1477, 1001.6332, 90.0000, -90.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //briefcase
	NDRobInt[282] = CreateDynamicObject(1636, -1199.1540, -1229.4481, 1002.9701, 0.0000, 0.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rcbomb
	NDRobInt[283] = CreateDynamicObject(1210, -1199.4035, -1229.3979, 1001.5731, 90.0000, -90.0000, 0.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //briefcase
	NDRobInt[284] = CreateDynamicObject(1578, -1199.2797, -1229.0938, 1002.1507, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_green
	NDRobInt[285] = CreateDynamicObject(1575, -1199.2398, -1226.2193, 1002.1306, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_white
	NDRobInt[286] = CreateDynamicObject(1279, -1199.0983, -1225.8612, 1002.9167, 0.0000, 0.0000, 90.0000, VW_NINEDEMONSINTERIOR, MAPS_NDROBINT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //craigpackage

	//PickUps

	NDRobInt_Pickup[0] = CreateDynamicPickup(1239, 1, NDAUFBRECHEN_COORDS, -1); //info
	NDRobInt_Pickup[2] = CreateDynamicPickup(19197, 1,NDINTERIOR_EXIT_COORDS , -1); //EnExMarker2

	//Textlabels

	text3D_NDRobInt[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "-> Nine Demons Spice Lager <-\n" COLOR_HEX_WHITE "Tippe /ndaufbrechen um ins Lager einzubrechen.", COLOR_WHITE, NDAUFBRECHEN_COORDS, 5.0, .testlos = 1, .worldid = VW_NINEDEMONSINTERIOR, .interiorid = MAPS_NDROBINT_INTERIOR); // Aufbrechen Point
	text3D_NDRobInt[1] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "-> Nine Demons Spice Tresor <-\n" COLOR_HEX_WHITE "Tippe /tresorsprengen um ein C4 zu platzieren.", COLOR_WHITE, NDRobInt_C4_COORDS, 5.0, .testlos = 1, .worldid = VW_NINEDEMONSINTERIOR, .interiorid = MAPS_NDROBINT_INTERIOR); // Tresor Point
	text3D_NDRobInt_Spice[0] = Create3DTextLabel(COLOR_HEX_YELLOW "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.", COLOR_WHITE, ND_SPICEROB_COORDS1, 5.0, VW_NINEDEMONSINTERIOR, 1); // Spiceklauen 1
	text3D_NDRobInt_Spice[1] = Create3DTextLabel(COLOR_HEX_YELLOW "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.", COLOR_WHITE, ND_SPICEROB_COORDS2, 5.0, VW_NINEDEMONSINTERIOR, 1); // Spiceklauen 2
	text3D_NDRobInt_Spice[2] = Create3DTextLabel(COLOR_HEX_YELLOW "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.", COLOR_WHITE, ND_SPICEROB_COORDS3, 5.0, VW_NINEDEMONSINTERIOR, 1); // Spiceklauen 3
	text3D_NDRobInt_Spice[3] = Create3DTextLabel(COLOR_HEX_YELLOW "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.", COLOR_WHITE, ND_SPICEROB_COORDS4, 5.0, VW_NINEDEMONSINTERIOR, 1); // Spiceklauen 4
	text3D_NDRobInt_Spice[4] = Create3DTextLabel(COLOR_HEX_YELLOW "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.", COLOR_WHITE, ND_SPICEROB_COORDS5, 5.0, VW_NINEDEMONSINTERIOR, 1); // Spiceklauen 5
	text3D_NDRobInt_Spice[5] = Create3DTextLabel(COLOR_HEX_YELLOW "-> Spice <-\n" COLOR_HEX_WHITE "Tippe /spicerauben.", COLOR_WHITE, ND_SPICEROB_COORDS6, 5.0, VW_NINEDEMONSINTERIOR, 1); // Spiceklauen 6
}
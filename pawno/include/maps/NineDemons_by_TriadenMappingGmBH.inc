#include <YSI\y_hooks>

#define MAPS_NINEDEMONSEXTERIOR_INTERIOR      0
#define MAPS_NINEDEMONSINTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Nine Demons points
#define NINEDEMONS_INTERIOR_ENTER_COORDS        -217.7166, 979.2784, 19.5020
#define NINEDEMONS_INTERIOR_EXIT_COORDS         743.6995, 383.8317, 948.5355
#define NINEDEMONS_INTERIOR_ENTER_FACING        270.0
#define NINEDEMONS_INTERIOR_EXIT_FACING         90.5

new object_nineDemonsExterior[68];
new pickup_nineDemonsExterior[2];
new text3D_nineDemonsExterior[1];

hook OnGameModeInit() 
{

	pickup_nineDemonsExterior[0] = CreateDynamicPickup(1239, 1, -226.1139, 985.1643, 19.5802, -1); //info
	pickup_nineDemonsExterior[1] = CreateDynamicPickup(19198, 1, -217.7166, 979.2784, 19.5020,-1); //EnExMarker3
	text3D_nineDemonsExterior[0] = _:CreateDynamic3DTextLabel("Territorium der\n" COLOR_HEX_GREEN "NINE DEMONS", COLOR_YELLOW, NINEDEMONS_INTERIOR_ENTER_COORDS, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_NINEDEMONSEXTERIOR_INTERIOR);

	object_nineDemonsExterior[0] = CreateDynamicObject(16563, -222.5558, 979.2672, 17.0198, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cn2_polis
	object_nineDemonsExterior[1] = CreateDynamicObject(19641, -215.1156, 970.8505, 15.9357, 0.0000, 0.0000, 180.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FenceSection1
	object_nineDemonsExterior[2] = CreateDynamicObject(19641, -223.1156, 970.8505, 15.9357, 0.0000, 0.0000, 180.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FenceSection1
	object_nineDemonsExterior[3] = CreateDynamicObject(19641, -231.1157, 970.8505, 15.9357, 0.0000, 0.0000, 180.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FenceSection1
	object_nineDemonsExterior[4] = CreateDynamicObject(16281, -204.0164, 979.1013, 20.6105, 0.0000, 0.0000, 95.4000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //des_fgateway01
	object_nineDemonsExterior[5] = CreateDynamicObject(2949, -225.1970, 985.7802, 18.2404, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_lockeddoor
	object_nineDemonsExterior[6] = CreateDynamicObject(19865, -203.4194, 973.4807, 17.4778, 0.0000, 0.0000, 5.4998, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceWood1
	object_nineDemonsExterior[7] = CreateDynamicObject(19641, -207.1154, 970.8505, 15.9357, 0.0000, 0.0000, 180.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FenceSection1
	object_nineDemonsExterior[8] = CreateDynamicObject(19641, -235.0157, 974.9411, 15.9357, 0.0000, 0.0000, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FenceSection1
	object_nineDemonsExterior[9] = CreateDynamicObject(19641, -235.0157, 982.9417, 15.9357, 0.0000, 0.0000, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FenceSection1
	object_nineDemonsExterior[10] = CreateDynamicObject(2810, -216.6526, 979.5006, 23.3407, 0.0000, 0.0000, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_STAT_2_bit
	object_nineDemonsExterior[11] = CreateDynamicObject(19865, -204.5010, 984.7069, 18.2378, 0.0000, 0.0000, 5.4998, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceWood1
	object_nineDemonsExterior[12] = CreateDynamicObject(19641, -235.0157, 990.9417, 15.9357, 0.0000, 0.0000, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FenceSection1
	object_nineDemonsExterior[13] = CreateDynamicObject(19865, -204.9821, 989.7025, 18.2278, 0.0000, 0.0000, 5.4998, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceWood1
	object_nineDemonsExterior[14] = CreateDynamicObject(19641, -235.0157, 998.9415, 15.9357, 0.0000, 0.0000, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FenceSection1
	object_nineDemonsExterior[15] = CreateDynamicObject(19865, -205.3240, 994.7034, 18.2080, 0.0000, -0.0996, 1.8997, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceWood1
	object_nineDemonsExterior[16] = CreateDynamicObject(19865, -205.5585, 1005.9066, 18.2082, 0.0000, -0.0996, 0.0996, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceWood1
	object_nineDemonsExterior[17] = CreateDynamicObject(19865, -205.4904, 999.7191, 18.2080, 0.0000, -0.0996, 1.8997, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceWood1
	object_nineDemonsExterior[18] = CreateDynamicObject(19865, -205.5567, 1004.7357, 18.2082, 0.0000, -0.0996, 0.0996, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceWood1
	object_nineDemonsExterior[19] = CreateDynamicObject(19865, -208.0386, 1008.3969, 18.2124, 0.0000, -0.0996, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceWood1
	object_nineDemonsExterior[20] = CreateDynamicObject(19865, -213.0487, 1008.3969, 18.2124, 0.0000, -0.0996, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceWood1
	object_nineDemonsExterior[21] = CreateDynamicObject(19865, -224.5686, 1008.3969, 18.2124, 0.0000, -0.0996, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceWood1
	object_nineDemonsExterior[22] = CreateDynamicObject(19865, -229.5688, 1008.3969, 18.2124, 0.0000, -0.0996, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceWood1
	object_nineDemonsExterior[23] = CreateDynamicObject(19865, -232.6392, 1008.3869, 18.2124, 0.0000, -0.0996, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceWood1
	object_nineDemonsExterior[24] = CreateDynamicObject(19641, -235.0556, 1004.4113, 15.9357, 0.0000, 0.0000, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FenceSection1
	object_nineDemonsExterior[25] = CreateDynamicObject(16281, -218.8063, 1008.3333, 21.4405, 0.0000, 0.0000, 180.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //des_fgateway01
	object_nineDemonsExterior[26] = CreateDynamicObject(869, -225.3793, 1006.3485, 19.6480, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_nineDemonsExterior[27] = CreateDynamicObject(869, -228.1392, 1006.3485, 19.6480, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_nineDemonsExterior[28] = CreateDynamicObject(869, -228.1392, 1004.0189, 19.6480, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_nineDemonsExterior[29] = CreateDynamicObject(869, -225.6293, 1004.0189, 19.6480, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_nineDemonsExterior[30] = CreateDynamicObject(618, -209.7628, 1004.6126, 18.7949, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_treea3
	object_nineDemonsExterior[31] = CreateDynamicObject(869, -212.0590, 1006.2288, 19.6480, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_nineDemonsExterior[32] = CreateDynamicObject(869, -212.0590, 1004.1787, 19.6480, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_nineDemonsExterior[33] = CreateDynamicObject(869, -208.1690, 1004.1787, 19.6480, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_nineDemonsExterior[34] = CreateDynamicObject(869, -208.0191, 1006.0678, 19.6480, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_nineDemonsExterior[35] = CreateDynamicObject(2395, -206.5659, 985.6243, 17.2949, 0.0000, 0.0000, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SPORTS_WALL
	object_nineDemonsExterior[36] = CreateDynamicObject(1420, -227.5043, 979.5056, 20.8894, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_AIRCON
	object_nineDemonsExterior[37] = CreateDynamicObject(19866, -230.4700, 999.4141, 18.3700, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
	object_nineDemonsExterior[38] = CreateDynamicObject(808, -233.1961, 999.1740, 19.5743, 0.0000, 0.0000, -15.6997, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //genVEG_bush12
	object_nineDemonsExterior[39] = CreateDynamicObject(19866, -230.4700, 994.4130, 18.3700, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
	object_nineDemonsExterior[40] = CreateDynamicObject(19866, -230.4700, 989.4119, 18.3700, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
	object_nineDemonsExterior[41] = CreateDynamicObject(19866, -230.4700, 984.4110, 18.3700, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
	object_nineDemonsExterior[42] = CreateDynamicObject(19866, -230.4700, 979.4099, 18.3700, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
	object_nineDemonsExterior[43] = CreateDynamicObject(808, -232.7893, 993.1134, 19.5743, 0.0000, 0.0000, 104.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //genVEG_bush12
	object_nineDemonsExterior[44] = CreateDynamicObject(808, -232.7893, 986.9130, 19.5743, 0.0000, 0.0000, -134.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //genVEG_bush12
	object_nineDemonsExterior[45] = CreateDynamicObject(808, -232.7893, 981.8734, 19.5743, 0.0000, 0.0000, 167.3999, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //genVEG_bush12
	object_nineDemonsExterior[46] = CreateDynamicObject(3035, -228.4851, 972.2993, 19.2035, 0.0000, 0.0000, 360.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tmp_bin
	object_nineDemonsExterior[47] = CreateDynamicObject(808, -232.7893, 1004.6345, 19.5743, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //genVEG_bush12
	object_nineDemonsExterior[48] = CreateDynamicObject(2744, -216.6542, 979.5040, 23.3523, 0.0000, 0.0000, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_STAT_2
	object_nineDemonsExterior[49] = CreateDynamicObject(1441, -226.0285, 972.6063, 19.1005, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_BOX_PILE_4
	object_nineDemonsExterior[50] = CreateDynamicObject(1337, -204.0923, 985.2395, 18.9733, 0.0000, 0.0000, 96.2996, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BinNt07_LA
	object_nineDemonsExterior[51] = CreateDynamicObject(1343, -203.9938, 986.1469, 19.1846, 0.0000, 0.0000, 95.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Dumpster3
	object_nineDemonsExterior[52] = CreateDynamicObject(1264, -204.0225, 987.1561, 18.6410, 0.0000, 0.0000, 0.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BlackBag1
	object_nineDemonsExterior[53] = CreateDynamicObject(1223, -203.7431, 982.6043, 18.0573, 0.0000, 0.0000, 7.7999, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	object_nineDemonsExterior[54] = CreateDynamicObject(1223, -202.8117, 975.8081, 17.7374, 0.0000, 0.0000, 7.7999, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	object_nineDemonsExterior[55] = CreateDynamicObject(1223, -215.3213, 1008.9135, 18.6774, 0.0000, 0.0000, 91.8999, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	object_nineDemonsExterior[56] = CreateDynamicObject(19922, -228.5811, 981.1074, 18.5820, 0.0000, 0.0000, 179.8000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
	object_nineDemonsExterior[57] = CreateDynamicObject(1223, -222.2758, 1008.9343, 18.6774, 0.0000, 0.0000, 91.8999, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	object_nineDemonsExterior[58] = CreateDynamicObject(19866, -218.4118, 976.6427, 18.4916, 0.0000, 0.0000, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
	object_nineDemonsExterior[59] = CreateDynamicObject(1503, -208.0773, 963.3236, 16.9563, 0.0000, 0.0000, 12.9996, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_RAMP
	object_nineDemonsExterior[60] = CreateDynamicObject(19866, -218.4118, 982.0034, 18.4916, 0.0000, 0.0000, 90.0000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
	object_nineDemonsExterior[61] = CreateDynamicObject(359, -229.4629, 980.9790, 19.3733, 87.9000, 0.6998, -31.8999, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rocketla
	object_nineDemonsExterior[62] = CreateDynamicObject(356, -228.9259, 981.3225, 19.3868, 97.4998, 32.9999, -69.1998, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //m4
	object_nineDemonsExterior[63] = CreateDynamicObject(336, -227.9868, 981.0217, 19.4174, -93.2997, 0.0000, -58.2000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bat
	object_nineDemonsExterior[64] = CreateDynamicObject(343, -228.4476, 980.5385, 19.4468, 0.0000, 0.0000, 76.6998, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //teargas
	object_nineDemonsExterior[65] = CreateDynamicObject(362, -229.2005, 980.1724, 20.0666, -0.4999, 0.0000, 4.7999, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //minigun
	object_nineDemonsExterior[66] = CreateDynamicObject(356, -228.6045, 981.4754, 19.3603, 79.1996, 0.0000, -64.5000, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //m4
	object_nineDemonsExterior[67] = CreateDynamicObject(2047, -203.4255, 974.3051, 18.8773, 0.6000, 1.5999, 95.7997, VW_MAIN,MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FLAG1
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) 
{
    if (newkeys & KEY_SECONDARY_ATTACK) 
	{
        if (IsPlayerInRangeOfPoint(playerid, 2.0, NINEDEMONS_INTERIOR_ENTER_COORDS)) { // Nine Demons Entrance
            if (Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied der Nine Demons.");
            SetPlayerPosEx(playerid, NINEDEMONS_INTERIOR_EXIT_COORDS, MAPS_NINEDEMONSINTERIOR_INTERIOR, VW_NINEDEMONSINTERIOR);
            SetPlayerFacingAngle(playerid, NINEDEMONS_INTERIOR_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnPlayerConnect(playerid) 
{
	RemoveBuildingForPlayer(playerid, 16563, -222.1950, 979.2500, 17.3827, 0.10); // cn2_polis
	RemoveBuildingForPlayer(playerid, 16566, -222.1950, 979.2500, 17.3827, 0.10); // LOD Model of cn2_polis
	RemoveBuildingForPlayer(playerid, 780, -209.1640, 1005.5599, 18.1797, 0.10); // Elmsparse_hism
	RemoveBuildingForPlayer(playerid, 1308, -234.9530, 1007.6300, 17.3672, 0.10); // telgrphpole02
	RemoveBuildingForPlayer(playerid, 1294, -198.6799, 984.0159, 23.2031, 0.10); // mlamppost
}
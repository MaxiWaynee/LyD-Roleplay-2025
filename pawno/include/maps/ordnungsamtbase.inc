#include <YSI\y_hooks>

// Global interior define
#define VW_ORDNUNGSAMT              0
#define MAPS_ORDNUNGSAMT            0
#define MAPS_POOEXTERIOR_INTERIOR      0
#define MAPS_POOINTERIOR_INTERIOR      0

// POO points
#define POO_INTERIOR_ENTER_COORDS		1706.7778,-1137.2699,24.0859
#define POO_INTERIOR_EXIT_COORDS		1932.5820, -2002.2120, 823.4130
#define POO_INTERIOR_ENTER_FACING		181.8887
#define POO_INTERIOR_EXIT_FACING   	    	239.3597
#define POO_STATEREPAIR_COORDS			1805.2598,-1118.8279,24.0859

#define POO_INTERIOR_ROOF_POINT         1709.5337,-1116.7572,41.0622
#define POO_INTERIOR_ROOF_POINT_FACING  180.0000
#define POO_ROOF_POINT                  1945.5930,-2024.9916,823.4130
#define POO_ROOF_POINT_FACING           84.9632

#define POO_BARRIER_FOR_RANGE_COORDS    1982.4076, -1330.9158, 24.0087
#define POO_BARRIER_OPEN_RY             0.0000
#define POO_BARRIER_CLOSED_RY           -90.0000

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 150.0;

new LS_ORDNUNGSAMT[308];
new ORDNUNGSAMT_TOR[3];
new pickup_pooExterior[2];
new text3D_pooExterior[2];

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) 
{
	/*if (IsPlayerInRangeOfPoint(playerid, 2.0, POO_INTERIOR_ROOF_POINT)) 
	{   
		// Roof Entrance
            	SetPlayerFacingAngle(playerid, POO_INTERIOR_ROOF_POINT_FACING);
            	SetCameraBehindPlayer(playerid);
            	SetPlayerPosEx(playerid, POO_ROOF_POINT, MAPS_POOINTERIOR_INTERIOR, VW_POOINTERIOR);
            	return 1;
        }*/
	return 1;
}

hook OnGameModeInit() {

	// Map Icon
    CreateDynamicMapIcon(POO_INTERIOR_ENTER_COORDS, 11, 0, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR);
    
	// Pickups
	pickup_pooExterior[0] = CreateDynamicPickup(1239, 1, POO_STATEREPAIR_COORDS, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR); // Staterepair
    pickup_pooExterior[1] = CreateDynamicPickup(19197, 1, POO_ROOF_POINT, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR); // Roof Entrance

  	// 3DTextLabels
    text3D_pooExterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Staats-Reparatur\n" COLOR_HEX_WHITE "Tippe /Staatrepair", COLOR_WHITE, POO_STATEREPAIR_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_POOEXTERIOR_INTERIOR); // Staterepair
	//text3D_pooExterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Auto-Freikaufen\n" COLOR_HEX_WHITE "Tippe /freecar", COLOR_WHITE, 1742.3522,-1142.3438,24.0859, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_POOEXTERIOR_INTERIOR); // Autofreikaufen

	LS_ORDNUNGSAMT[0] = CreateDynamicObject(2960, 1752.7390, -1103.6926, 25.3537, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_beam
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[0], 0, 1717, "cj_tv", "CJ_STEEL", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[1] = CreateDynamicObject(14693, 1730.7093, -1124.5920, 23.4799, 0.0000, 0.0000, 18.3999, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_tools
	LS_ORDNUNGSAMT[2] = CreateDynamicObject(19445, 1729.6208, -1099.0096, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[2], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[3] = CreateDynamicObject(19445, 1734.5311, -1094.2794, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[3], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[4] = CreateDynamicObject(19445, 1752.9781, -1094.2794, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[4], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[5] = CreateDynamicObject(19445, 1762.6070, -1094.2794, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[5], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[6] = CreateDynamicObject(19445, 1772.2363, -1094.2794, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[6], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[7] = CreateDynamicObject(19445, 1781.8653, -1094.2794, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[7], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[8] = CreateDynamicObject(19445, 1791.4941, -1094.2794, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[8], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[9] = CreateDynamicObject(3066, 1767.2635, -1146.2596, 23.9388, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ammotrn_obj
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[9], 2, 5787, "melrose02_lawn", "melrgren2_law", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[10] = CreateDynamicObject(19445, 1801.1230, -1094.2794, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[10], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[11] = CreateDynamicObject(19445, 1810.7523, -1094.2794, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[11], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[12] = CreateDynamicObject(5422, 1727.8645, -1120.3253, 26.9498, 0.0000, 90.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //laespraydoor1
	LS_ORDNUNGSAMT[13] = CreateDynamicObject(19903, 1730.2644, -1124.5177, 23.0566, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MechanicComputer1
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[13], 1, 14668, "711c", "cj_white_wall2", 0xFFD78E10);
	LS_ORDNUNGSAMT[14] = CreateDynamicObject(19325, 1721.7307, -1134.3531, 25.9451, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	LS_ORDNUNGSAMT[15] = CreateDynamicObject(19377, 1719.3939, -1123.6389, 23.1989, 90.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[15], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[16] = CreateDynamicObject(8843, 1738.4121, -1125.5975, 23.0806, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
	LS_ORDNUNGSAMT[17] = CreateDynamicObject(18762, 1730.4632, -1118.7799, 25.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[17], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[18] = CreateDynamicObject(18762, 1725.2623, -1133.9089, 25.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[18], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[19] = CreateDynamicObject(5422, 1727.8645, -1132.3868, 26.9498, 0.0000, 90.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //laespraydoor1
	LS_ORDNUNGSAMT[20] = CreateDynamicObject(18762, 1733.9897, -1133.9089, 25.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[20], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[21] = CreateDynamicObject(18075, 1801.1512, -1102.6407, 30.7509, 0.0000, 10.7999, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	LS_ORDNUNGSAMT[22] = CreateDynamicObject(18762, 1727.4825, -1133.9089, 27.5216, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[22], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[23] = CreateDynamicObject(19325, 1732.4221, -1134.3531, 24.6951, 90.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	LS_ORDNUNGSAMT[24] = CreateDynamicObject(18762, 1733.9897, -1123.7696, 25.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[24], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[25] = CreateDynamicObject(18762, 1733.9897, -1128.8397, 25.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[25], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[26] = CreateDynamicObject(19325, 1732.0318, -1118.4143, 24.6951, 90.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	LS_ORDNUNGSAMT[27] = CreateDynamicObject(19325, 1734.4499, -1131.3736, 24.6853, 90.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	LS_ORDNUNGSAMT[28] = CreateDynamicObject(19325, 1734.4499, -1126.3237, 24.6853, 90.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	LS_ORDNUNGSAMT[29] = CreateDynamicObject(18762, 1733.9897, -1118.7799, 25.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[29], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[30] = CreateDynamicObject(19325, 1734.4499, -1121.2740, 24.6853, 90.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	LS_ORDNUNGSAMT[31] = CreateDynamicObject(18762, 1730.4632, -1133.9079, 25.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[31], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[32] = CreateDynamicObject(19279, 1766.5843, -1104.4045, 27.4689, 180.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCSmallLight1
	LS_ORDNUNGSAMT[33] = CreateDynamicObject(19425, 1805.4145, -1120.9051, 23.0589, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
	LS_ORDNUNGSAMT[34] = CreateDynamicObject(19872, 1727.9433, -1126.2966, 21.1590, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CarFixerRamp2
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[34], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	LS_ORDNUNGSAMT[35] = CreateDynamicObject(19445, 1720.2248, -1118.3784, 24.6375, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[35], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[36] = CreateDynamicObject(640, 1742.8016, -1132.1711, 23.7541, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
	LS_ORDNUNGSAMT[37] = CreateDynamicObject(2960, 1752.7110, -1095.0321, 24.4736, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_beam
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[37], 0, 1717, "cj_tv", "CJ_STEEL", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[38] = CreateDynamicObject(2169, 1722.8020, -1127.1893, 23.0720, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE3_DESK_1
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[38], 0, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[38], 1, 14668, "711c", "CJ_CHIP_M2", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[39] = CreateDynamicObject(3386, 1733.8055, -1122.4759, 23.0841, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_srack2_
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[39], 1, 14577, "casinovault01", "compound_roof1", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[40] = CreateDynamicObject(18980, 1694.2900, -1136.0013, 23.6438, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[40], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[41] = CreateDynamicObject(18980, 1718.9610, -1136.0013, 23.6438, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[41], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[42] = CreateDynamicObject(19377, 1729.2445, -1129.5969, 28.0888, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	ORDNUNGSAMT_TOR[2] = CreateDynamicObject(19872, 1727.9433, -1126.2966, 21.1888, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CarFixerRamp2
	LS_ORDNUNGSAMT[44] = CreateDynamicObject(6874, 1707.3951, -1116.7845, 22.9803, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgn_corpbuild2
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[44], 0, 8409, "gnhotel1", "gnhotelwindow01_128", 0xFFD6DAD6);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[44], 1, 8409, "gnhotel1", "gnhotelwindow01_128", 0xFFD6DAD6);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[44], 2, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[45] = CreateDynamicObject(19419, 1812.7596, -1118.1861, 24.6403, 0.0000, 0.0000, -95.4000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //police_lights01
	LS_ORDNUNGSAMT[46] = CreateDynamicObject(19377, 1729.2430, -1123.0882, 28.0883, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	LS_ORDNUNGSAMT[47] = CreateDynamicObject(18075, 1813.5611, -1102.6407, 30.7509, 0.0000, 10.7999, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	LS_ORDNUNGSAMT[48] = CreateDynamicObject(2690, 1733.6499, -1124.4071, 23.9923, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FIRE_EXT
	LS_ORDNUNGSAMT[49] = CreateDynamicObject(19477, 1727.8015, -1134.4111, 27.4102, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[49], 0, "____________", OBJECT_MATERIAL_SIZE_512x256, "Arial", 88, 1, 0xFFFFFFFF, 0x00000000, 1);
	LS_ORDNUNGSAMT[50] = CreateDynamicObject(640, 1742.8016, -1123.5704, 23.7541, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
	LS_ORDNUNGSAMT[51] = CreateDynamicObject(2166, 1742.9792, -1139.2425, 23.1627, 0.0000, 0.0000, 47.1999, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_2
	LS_ORDNUNGSAMT[52] = CreateDynamicObject(19419, 1813.3868, -1118.2456, 24.6403, 0.0000, 0.0000, -78.3999, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //police_lights01
	LS_ORDNUNGSAMT[53] = CreateDynamicObject(5837, 1744.5902, -1140.1214, 24.3057, 0.4000, -1.1000, 315.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ci_guardhouse1
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[53], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[53], 3, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[54] = CreateDynamicObject(14680, 1818.7113, -1121.8918, 28.7406, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	LS_ORDNUNGSAMT[55] = CreateDynamicObject(2605, 1746.4873, -1142.1352, 23.5074, 0.0000, 0.0000, -144.7998, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLCE_DESK1
	LS_ORDNUNGSAMT[56] = CreateDynamicObject(12943, 1748.7038, -1120.6201, 23.0067, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sw_SHED07
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[56], 2, 3452, "bballvgnint", "bballconcrete3_256", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[57] = CreateDynamicObject(19279, 1780.5438, -1104.4045, 27.4689, 180.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCSmallLight1
	LS_ORDNUNGSAMT[58] = CreateDynamicObject(2169, 1722.8020, -1129.1391, 23.0720, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE3_DESK_1
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[58], 0, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[58], 1, 14668, "711c", "CJ_CHIP_M2", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[59] = CreateDynamicObject(18641, 1746.5633, -1142.2585, 23.9465, 0.8999, 92.9999, -108.0998, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Flashlight1
	LS_ORDNUNGSAMT[60] = CreateDynamicObject(19377, 1776.1246, -1099.5439, 27.2903, 0.0000, 95.6996, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[60], 0, 13059, "ce_fact03", "sw_newcorrug", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[61] = CreateDynamicObject(994, 1783.2750, -1147.6258, 22.9321, 0.0000, -1.8997, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[61], 0, 16093, "a51_ext", "ws_whitewall2_bottom", 0xFFD78E10);
	LS_ORDNUNGSAMT[62] = CreateDynamicObject(1722, 1746.5207, -1140.9958, 23.1089, 0.8999, -0.8000, 165.0995, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
	LS_ORDNUNGSAMT[63] = CreateDynamicObject(18762, 1711.4410, -1104.5887, 25.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[63], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[64] = CreateDynamicObject(18980, 1718.9610, -1096.7591, 23.6438, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[64], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[65] = CreateDynamicObject(18980, 1694.2790, -1096.7591, 23.6438, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[65], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[66] = CreateDynamicObject(19445, 1720.2248, -1134.3105, 24.6375, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[66], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[67] = CreateDynamicObject(18762, 1727.4825, -1118.7799, 27.5216, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[67], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[68] = CreateDynamicObject(18762, 1725.2623, -1118.7790, 25.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[68], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[69] = CreateDynamicObject(19325, 1721.7307, -1118.3927, 25.9451, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	LS_ORDNUNGSAMT[70] = CreateDynamicObject(19445, 1734.3845, -1129.5411, 23.1275, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[70], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[71] = CreateDynamicObject(19445, 1734.3945, -1123.5339, 23.1275, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[71], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[72] = CreateDynamicObject(19377, 1718.7452, -1129.5969, 28.0888, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	LS_ORDNUNGSAMT[73] = CreateDynamicObject(19377, 1718.7436, -1123.0882, 28.0883, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	LS_ORDNUNGSAMT[74] = CreateDynamicObject(1010, 1729.7110, -1124.1933, 23.4178, 0.0000, 90.7994, -90.8999, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nto_b_tw
	LS_ORDNUNGSAMT[75] = CreateDynamicObject(19426, 1730.3321, -1124.0904, 23.5116, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[75], 0, 10023, "bigwhitesfe", "bigwhite_3", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[76] = CreateDynamicObject(19899, 1733.8376, -1127.0334, 22.9918, 0.0000, 0.0000, -179.5997, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToolCabinet1
	LS_ORDNUNGSAMT[77] = CreateDynamicObject(19377, 1732.3363, -1106.6883, 23.1989, 90.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[77], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[78] = CreateDynamicObject(19377, 1721.8370, -1106.6883, 23.1989, 90.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[78], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[79] = CreateDynamicObject(19377, 1719.3739, -1130.2478, 23.1989, 90.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[79], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[80] = CreateDynamicObject(19445, 1739.8824, -1109.0924, 24.8076, 0.0000, 0.0000, 45.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[80], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[81] = CreateDynamicObject(2186, 1721.3127, -1130.1947, 23.0508, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PHOTOCOPIER_1
	LS_ORDNUNGSAMT[82] = CreateDynamicObject(19445, 1743.2585, -1117.2497, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[82], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[83] = CreateDynamicObject(19445, 1743.2585, -1126.8785, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[83], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[84] = CreateDynamicObject(640, 1742.8016, -1115.1689, 23.7541, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
	LS_ORDNUNGSAMT[85] = CreateDynamicObject(1703, 1719.9603, -1132.9748, 23.0242, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch02
	LS_ORDNUNGSAMT[86] = CreateDynamicObject(19355, 1743.2641, -1133.2768, 24.8097, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall003
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[86], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[87] = CreateDynamicObject(922, 1719.9936, -1120.8690, 23.9566, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Packing_carates1
	LS_ORDNUNGSAMT[88] = CreateDynamicObject(1522, 1719.4243, -1125.5688, 23.0351, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[88], 0, 16093, "a51_ext", "des_backdoor1", 0xFF9F9D94);
	LS_ORDNUNGSAMT[89] = CreateDynamicObject(19377, 1721.8446, -1096.3680, 23.1989, 90.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[89], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[90] = CreateDynamicObject(19377, 1732.3363, -1096.3581, 23.1989, 90.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[90], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[91] = CreateDynamicObject(19377, 1737.5898, -1101.5273, 23.1989, 90.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[91], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[92] = CreateDynamicObject(18762, 1737.1811, -1106.2915, 25.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[92], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[93] = CreateDynamicObject(18762, 1737.1811, -1096.7589, 25.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[93], 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[94] = CreateDynamicObject(19377, 1732.8642, -1101.5273, 28.0883, 0.0000, 90.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	LS_ORDNUNGSAMT[95] = CreateDynamicObject(19377, 1723.2862, -1101.5273, 28.0883, 0.0000, 90.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	LS_ORDNUNGSAMT[96] = CreateDynamicObject(1522, 1737.6278, -1102.4392, 23.0351, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[96], 0, 16093, "a51_ext", "des_backdoor1", 0xFF9F9D94);
	LS_ORDNUNGSAMT[97] = CreateDynamicObject(1620, 1735.9078, -1106.7778, 26.9353, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_vent2_01
	LS_ORDNUNGSAMT[98] = CreateDynamicObject(1620, 1734.3175, -1106.7778, 26.9353, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_vent2_01
	LS_ORDNUNGSAMT[99] = CreateDynamicObject(10831, 1809.3725, -1110.4420, 27.9930, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drydock3_SFSe
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[99], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[99], 1, 6000, "con_drivein", "Desrtmetal", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[100] = CreateDynamicObject(19445, 1820.3315, -1094.2794, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[100], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[101] = CreateDynamicObject(19445, 1825.0616, -1099.0179, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[101], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[102] = CreateDynamicObject(16302, 1804.3586, -1130.8813, 20.6366, 0.0000, 0.0000, -124.5000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //des_gravelpile04
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[102], 0, 17081, "cuntwlandcent", "ws_traingravel", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[103] = CreateDynamicObject(2960, 1780.7020, -1103.6926, 25.3537, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_beam
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[103], 0, 1717, "cj_tv", "CJ_STEEL", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[104] = CreateDynamicObject(16302, 1805.0329, -1138.1267, 20.5666, 0.0000, 0.0000, 80.3001, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //des_gravelpile04
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[104], 0, 4811, "beach_las", "sandnew_law", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[105] = CreateDynamicObject(3257, 1817.9726, -1137.5279, 15.9139, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //refinerybox1
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[105], 0, 10756, "airportroads_sfse", "ws_white_wall1", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[105], 1, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[105], 3, 3440, "airportpillar", "metalic_64", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[106] = CreateDynamicObject(2960, 1780.7020, -1095.0321, 24.4736, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_beam
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[106], 0, 1717, "cj_tv", "CJ_STEEL", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[107] = CreateDynamicObject(19377, 1766.5035, -1099.5439, 27.2903, 0.0000, 95.6996, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[107], 0, 13059, "ce_fact03", "sw_newcorrug", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[108] = CreateDynamicObject(19377, 1756.9427, -1099.5439, 27.2903, 0.0000, 95.6996, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[108], 0, 13059, "ce_fact03", "sw_newcorrug", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[109] = CreateDynamicObject(2960, 1766.7204, -1103.6926, 25.3537, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_beam
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[109], 0, 1717, "cj_tv", "CJ_STEEL", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[110] = CreateDynamicObject(2960, 1766.7204, -1095.0321, 24.4736, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_beam
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[110], 0, 1717, "cj_tv", "CJ_STEEL", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[111] = CreateDynamicObject(18766, 1804.5000, -1126.9000, 23.5844, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[111], 0, 10756, "airportroads_sfse", "Heliconcrete", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[112] = CreateDynamicObject(18766, 1809.0898, -1131.3935, 23.5844, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[112], 0, 10756, "airportroads_sfse", "Heliconcrete", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[113] = CreateDynamicObject(18766, 1809.1201, -1137.4951, 23.5645, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[113], 0, 10756, "airportroads_sfse", "Heliconcrete", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[114] = CreateDynamicObject(18766, 1804.5000, -1134.4499, 23.5844, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[114], 0, 10756, "airportroads_sfse", "Heliconcrete", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[115] = CreateDynamicObject(18766, 1804.5000, -1142.0000, 23.5844, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[115], 0, 10756, "airportroads_sfse", "Heliconcrete", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[116] = CreateDynamicObject(19445, 1746.6429, -1138.2259, 24.8076, 0.0000, 0.0000, 45.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[116], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[117] = CreateDynamicObject(19445, 1761.2757, -1147.7607, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[117], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	ORDNUNGSAMT_TOR[0] = CreateDynamicObject(969, 1756.3326, -1147.6872, 23.2500, 0.0000, 0.0000, 135.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Electricgate
	SetDynamicObjectMaterial(ORDNUNGSAMT_TOR[0], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
	SetDynamicObjectMaterial(ORDNUNGSAMT_TOR[0], 1, -1, "none", "none", 0xFFFFFFFF);
	SetDynamicObjectMaterial(ORDNUNGSAMT_TOR[0], 3, -1, "none", "none", 0xFFFFFFFF);
	SetDynamicObjectMaterial(ORDNUNGSAMT_TOR[0], 4, 6000, "con_drivein", "Desrtmetal", 0xFF515459);
	LS_ORDNUNGSAMT[119] = CreateDynamicObject(19445, 1770.9150, -1147.7607, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[119], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[120] = CreateDynamicObject(19445, 1780.5338, -1147.7607, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[120], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[121] = CreateDynamicObject(19445, 1790.1628, -1147.7607, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[121], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[122] = CreateDynamicObject(19445, 1799.7917, -1147.7607, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[122], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[123] = CreateDynamicObject(19445, 1809.4206, -1147.7607, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[123], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[124] = CreateDynamicObject(19445, 1819.0498, -1147.7607, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[124], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[125] = CreateDynamicObject(19445, 1825.0616, -1108.6468, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[125], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[126] = CreateDynamicObject(19445, 1825.0616, -1118.2760, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[126], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[127] = CreateDynamicObject(19445, 1825.0616, -1127.9050, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[127], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[128] = CreateDynamicObject(19445, 1825.0616, -1137.5340, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[128], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[129] = CreateDynamicObject(19445, 1825.0516, -1143.0343, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[129], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[130] = CreateDynamicObject(19355, 1823.5257, -1147.7585, 24.8097, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall003
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[130], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[131] = CreateDynamicObject(638, 1708.9327, -1135.9514, 23.7444, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
	LS_ORDNUNGSAMT[132] = CreateDynamicObject(19899, 1801.0920, -1096.9215, 22.9918, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToolCabinet1
	LS_ORDNUNGSAMT[133] = CreateDynamicObject(1676, 1776.7701, -1143.7136, 24.5344, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //washgaspump
	LS_ORDNUNGSAMT[134] = CreateDynamicObject(638, 1703.4527, -1136.9614, 23.7444, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
	LS_ORDNUNGSAMT[135] = CreateDynamicObject(1685, 1753.7043, -1124.4934, 23.8213, 0.0000, 0.0000, -92.0998, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //blockpallet
	LS_ORDNUNGSAMT[136] = CreateDynamicObject(1280, 1710.9383, -1136.9029, 23.4612, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
	LS_ORDNUNGSAMT[137] = CreateDynamicObject(1229, 1745.0146, -1128.1201, 24.5100, 0.0000, 0.0000, 86.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bussign1
	LS_ORDNUNGSAMT[138] = CreateDynamicObject(19479, 1712.5052, -1139.3481, 26.0594, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane005
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[138], 0, "Los Santos", OBJECT_MATERIAL_SIZE_512x256, "Arial", 30, 1, 0xFF000000, 0x00000000, 1);
	LS_ORDNUNGSAMT[139] = CreateDynamicObject(18880, 1751.1157, -1125.3044, 23.3966, 270.0000, 90.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SpeedCamera1
	LS_ORDNUNGSAMT[140] = CreateDynamicObject(19899, 1808.8537, -1096.9215, 22.9918, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToolCabinet1
	LS_ORDNUNGSAMT[141] = CreateDynamicObject(3287, 1776.7967, -1145.9470, 26.1933, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cxrf_oiltank
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[141], 0, 11150, "ab_acc_control", "ws_shipmetal5", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[141], 3, 3440, "airportpillar", "metalic_64", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[142] = CreateDynamicObject(1676, 1779.8601, -1143.7136, 24.5344, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //washgaspump
	LS_ORDNUNGSAMT[143] = CreateDynamicObject(19817, 1797.6894, -1102.5167, 22.1807, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CarFixerRamp1
	LS_ORDNUNGSAMT[144] = CreateDynamicObject(19817, 1813.3103, -1102.5167, 22.1807, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CarFixerRamp1
	LS_ORDNUNGSAMT[145] = CreateDynamicObject(19815, 1817.0367, -1096.4643, 24.7469, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToolBoard1
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[145], 1, 3474, "freightcrane", "metalwheel1_256", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[145], 3, 3961, "lee_kitch", "metal6", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[146] = CreateDynamicObject(3934, 1709.5200, -1128.3419, 40.0541, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
	LS_ORDNUNGSAMT[147] = CreateDynamicObject(19377, 1709.5321, -1128.3695, 39.9780, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[147], 0, 16640, "a51", "ws_metalpanel1", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[148] = CreateDynamicObject(1617, 1724.5710, -1106.7060, 26.9461, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_aircon1_01
	LS_ORDNUNGSAMT[149] = CreateDynamicObject(16095, 1709.7821, -1113.3929, 39.4001, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //des_a51guardbox02
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[149], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[149], 1, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[149], 2, 16093, "a51_ext", "des_backdoor1", 0xFF515459);
	LS_ORDNUNGSAMT[150] = CreateDynamicObject(1617, 1722.1715, -1106.7060, 26.9461, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_aircon1_01
	LS_ORDNUNGSAMT[151] = CreateDynamicObject(19903, 1803.0865, -1096.9272, 23.0624, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MechanicComputer1
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[151], 1, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[152] = CreateDynamicObject(19903, 1810.8475, -1096.9272, 23.0223, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MechanicComputer1
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[152], 1, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[153] = CreateDynamicObject(922, 1748.3022, -1113.4078, 23.9465, 0.0000, 0.0000, -179.1997, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Packing_carates1
	LS_ORDNUNGSAMT[154] = CreateDynamicObject(18880, 1752.2258, -1119.2845, 23.8465, 270.0000, 90.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SpeedCamera1
	LS_ORDNUNGSAMT[155] = CreateDynamicObject(19991, 1744.9498, -1127.3590, 22.9864, 0.0000, 0.0000, 89.4999, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign44
	LS_ORDNUNGSAMT[156] = CreateDynamicObject(19991, 1745.1097, -1127.3603, 22.9864, 0.0000, 0.0000, 89.4999, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign44
	LS_ORDNUNGSAMT[157] = CreateDynamicObject(19950, 1745.0067, -1126.5196, 22.9612, 0.0000, 0.0000, 88.2994, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
	LS_ORDNUNGSAMT[158] = CreateDynamicObject(19960, 1745.0781, -1126.1540, 22.9993, 0.0000, 0.0000, 88.6996, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign13
	LS_ORDNUNGSAMT[159] = CreateDynamicObject(19970, 1744.9476, -1125.6014, 22.7719, 0.0000, 0.0000, 89.1996, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign23
	LS_ORDNUNGSAMT[160] = CreateDynamicObject(19980, 1744.9487, -1124.6219, 22.1210, 0.0000, 0.0000, 88.8999, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign33
	LS_ORDNUNGSAMT[161] = CreateDynamicObject(19972, 1745.0559, -1122.8503, 22.8992, 0.0000, 0.0000, 86.1996, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign25
	LS_ORDNUNGSAMT[162] = CreateDynamicObject(19975, 1745.2561, -1123.9881, 22.5692, 0.0000, 0.0000, 90.1996, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign28
	LS_ORDNUNGSAMT[163] = CreateDynamicObject(19954, 1745.2102, -1125.0588, 22.5625, 0.0000, 0.0000, 82.9000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	LS_ORDNUNGSAMT[164] = CreateDynamicObject(1459, 1745.7091, -1126.8896, 23.6217, 0.0000, 0.0000, -91.4999, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_ROADBARRIER_6
	LS_ORDNUNGSAMT[165] = CreateDynamicObject(1238, 1745.6129, -1125.1285, 23.3717, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trafficcone
	LS_ORDNUNGSAMT[166] = CreateDynamicObject(1238, 1745.6129, -1124.3380, 23.3717, 0.0000, 0.0000, -57.5998, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //trafficcone
	LS_ORDNUNGSAMT[167] = CreateDynamicObject(3761, 1745.7705, -1118.5931, 24.9811, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //industshelves
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[167], 3, 2990, "arsex", "steel128", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[168] = CreateDynamicObject(1685, 1753.7712, -1122.6645, 23.8213, 0.0000, 0.0000, -92.0998, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //blockpallet
	LS_ORDNUNGSAMT[169] = CreateDynamicObject(19817, 1805.4599, -1102.5167, 22.1807, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CarFixerRamp1
	LS_ORDNUNGSAMT[170] = CreateDynamicObject(19917, 1819.2048, -1101.8624, 23.9792, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneEngine1
	LS_ORDNUNGSAMT[171] = CreateDynamicObject(2917, 1819.0644, -1110.5218, 30.4293, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //a51_crane
	LS_ORDNUNGSAMT[172] = CreateDynamicObject(937, 1816.2319, -1097.2027, 23.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_DF_WORKTOP
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[172], 0, 3629, "arprtxxref_las", "metaldoor_128", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[172], 1, 16640, "a51", "redmetal", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[173] = CreateDynamicObject(18980, 1809.0216, -1110.4907, 31.5837, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[173], 0, 14548, "ab_cargo_int", "metal_frame", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[174] = CreateDynamicObject(937, 1818.0904, -1097.2027, 23.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_DF_WORKTOP
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[174], 0, 3629, "arprtxxref_las", "metaldoor_128", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[174], 1, 16640, "a51", "redmetal", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[175] = CreateDynamicObject(937, 1819.9204, -1097.2027, 23.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_DF_WORKTOP
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[175], 0, 3629, "arprtxxref_las", "metaldoor_128", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[175], 1, 16640, "a51", "redmetal", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[176] = CreateDynamicObject(937, 1821.7904, -1097.2027, 23.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_DF_WORKTOP
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[176], 0, 3629, "arprtxxref_las", "metaldoor_128", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[176], 1, 16640, "a51", "redmetal", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[177] = CreateDynamicObject(937, 1819.2016, -1101.9331, 23.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_DF_WORKTOP
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[177], 0, 3629, "arprtxxref_las", "metaldoor_128", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[177], 1, 16640, "a51", "redmetal", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[178] = CreateDynamicObject(19815, 1820.9466, -1096.4643, 24.7469, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToolBoard1
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[178], 1, 3474, "freightcrane", "metalwheel1_256", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[178], 3, 3961, "lee_kitch", "metal6", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[179] = CreateDynamicObject(19425, 1805.4145, -1121.4852, 23.0589, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
	LS_ORDNUNGSAMT[180] = CreateDynamicObject(19279, 1752.5736, -1104.4045, 27.4689, 180.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCSmallLight1
	LS_ORDNUNGSAMT[181] = CreateDynamicObject(19425, 1805.4145, -1116.1955, 23.0589, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
	LS_ORDNUNGSAMT[182] = CreateDynamicObject(19425, 1805.4145, -1115.6351, 23.0589, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
	LS_ORDNUNGSAMT[183] = CreateDynamicObject(919, 1804.6601, -1123.6665, 23.4172, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AIRCON
	LS_ORDNUNGSAMT[184] = CreateDynamicObject(919, 1806.0810, -1123.6665, 23.4172, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AIRCON
	LS_ORDNUNGSAMT[185] = CreateDynamicObject(3761, 1813.2009, -1120.2032, 24.9811, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //industshelves
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[185], 3, 2990, "arsex", "steel128", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[186] = CreateDynamicObject(3761, 1817.0212, -1120.2032, 24.9811, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //industshelves
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[186], 3, 2990, "arsex", "steel128", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[187] = CreateDynamicObject(3761, 1820.7816, -1120.2032, 24.9811, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //industshelves
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[187], 3, 2990, "arsex", "steel128", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[188] = CreateDynamicObject(994, 1802.9536, -1121.6966, 23.1014, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[188], 0, 16093, "a51_ext", "ws_whitewall2_bottom", 0xFFD78E10);
	LS_ORDNUNGSAMT[189] = CreateDynamicObject(994, 1807.9438, -1121.6966, 23.1014, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[189], 0, 16093, "a51_ext", "ws_whitewall2_bottom", 0xFFD78E10);
	LS_ORDNUNGSAMT[190] = CreateDynamicObject(19903, 1807.7871, -1124.0686, 23.0223, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MechanicComputer1
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[190], 1, 10101, "2notherbuildsfe", "ferry_build14", 0xFFD78E10);
	LS_ORDNUNGSAMT[191] = CreateDynamicObject(19425, 1727.9443, -1123.1153, 23.0589, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
	LS_ORDNUNGSAMT[192] = CreateDynamicObject(19425, 1727.9443, -1122.5351, 23.0589, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
	LS_ORDNUNGSAMT[193] = CreateDynamicObject(19445, 1805.4161, -1119.2801, 22.9974, 0.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[193], 0, 915, "airconext", "cj_plating3", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[194] = CreateDynamicObject(19279, 1795.3846, -1106.8443, 29.9388, 270.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCSmallLight1
	LS_ORDNUNGSAMT[195] = CreateDynamicObject(19972, 1757.0931, -1148.4001, 22.5429, 0.0000, 0.0000, -45.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign25
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[195], 2, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[196] = CreateDynamicObject(3633, 1811.3232, -1122.8548, 23.5216, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //imoildrum4_LAS
	LS_ORDNUNGSAMT[197] = CreateDynamicObject(19477, 1757.0743, -1148.4188, 25.2502, 0.0000, 0.0000, 225.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[197], 0, "Betriebshof", OBJECT_MATERIAL_SIZE_512x256, "Arial", 50, 1, 0xFF58595A, 0x00000000, 1);
	LS_ORDNUNGSAMT[198] = CreateDynamicObject(14680, 1807.2502, -1121.8918, 28.7406, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	LS_ORDNUNGSAMT[199] = CreateDynamicObject(19477, 1757.0743, -1148.4188, 24.9801, 0.0000, 0.0000, 225.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[199], 0, "Los Santos", OBJECT_MATERIAL_SIZE_512x256, "Arial", 50, 1, 0xFF3B4E78, 0x00000000, 1);
	LS_ORDNUNGSAMT[200] = CreateDynamicObject(14680, 1750.5399, -1127.2224, 26.5305, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	LS_ORDNUNGSAMT[201] = CreateDynamicObject(14680, 1750.5399, -1119.1717, 26.4806, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	LS_ORDNUNGSAMT[202] = CreateDynamicObject(14680, 1722.8354, -1126.9162, 26.3614, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	LS_ORDNUNGSAMT[203] = CreateDynamicObject(14680, 1729.7396, -1126.1019, 26.4605, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	LS_ORDNUNGSAMT[204] = CreateDynamicObject(14680, 1729.7396, -1131.7121, 26.4605, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights01
	LS_ORDNUNGSAMT[205] = CreateDynamicObject(1278, 1781.2507, -1094.8874, 23.2639, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_floodlite
	LS_ORDNUNGSAMT[206] = CreateDynamicObject(1278, 1751.6809, -1094.8874, 23.2639, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_floodlite
	LS_ORDNUNGSAMT[207] = CreateDynamicObject(1278, 1757.3717, -1147.3973, 23.2639, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_floodlite
	LS_ORDNUNGSAMT[208] = CreateDynamicObject(1278, 1783.8916, -1147.3973, 23.2639, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_floodlite
	LS_ORDNUNGSAMT[209] = CreateDynamicObject(1439, 1770.4287, -1120.1643, 23.1853, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_DUMPSTER_1
	LS_ORDNUNGSAMT[210] = CreateDynamicObject(12925, 1775.3277, -1124.6130, 23.0575, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sw_SHED01
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[210], 4, 3452, "bballvgnint", "bballconcrete3_256", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[211] = CreateDynamicObject(19621, 1801.2873, -1096.9393, 24.3003, 0.0000, 0.0000, -144.8999, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //OilCan1
	LS_ORDNUNGSAMT[212] = CreateDynamicObject(955, 1724.0329, -1133.8552, 23.4127, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_EXT_SPRUNK
	LS_ORDNUNGSAMT[213] = CreateDynamicObject(2690, 1751.4597, -1128.1866, 23.9923, 0.0000, 0.0000, -179.9998, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FIRE_EXT
	LS_ORDNUNGSAMT[214] = CreateDynamicObject(2690, 1808.6103, -1124.3867, 23.9923, 0.0000, 0.0000, -179.9998, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_FIRE_EXT
	LS_ORDNUNGSAMT[215] = CreateDynamicObject(19279, 1752.9449, -1115.1853, 26.8589, 270.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCSmallLight1
	LS_ORDNUNGSAMT[216] = CreateDynamicObject(11392, 1809.3127, -1103.0185, 23.0753, 0.0000, 0.0000, -71.6996, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //hubfloorstains_SFSe
	LS_ORDNUNGSAMT[217] = CreateDynamicObject(1439, 1772.4586, -1120.1643, 23.1853, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_DUMPSTER_1
	LS_ORDNUNGSAMT[218] = CreateDynamicObject(1415, 1775.2956, -1120.0758, 23.1364, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_DUMPSTER
	LS_ORDNUNGSAMT[219] = CreateDynamicObject(1358, 1746.9641, -1111.3100, 24.2362, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SKIP_Rubbish
	LS_ORDNUNGSAMT[220] = CreateDynamicObject(1299, 1810.7749, -1119.9350, 23.4941, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //smashboxpile
	LS_ORDNUNGSAMT[221] = CreateDynamicObject(3932, 1791.4830, -1097.1689, 24.7168, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //hanger
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[221], 0, 13059, "ce_fact03", "sw_newcorrug", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[221], 1, 13059, "ce_fact03", "sw_newcorrug", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[222] = CreateDynamicObject(3932, 1785.5030, -1097.1689, 24.7168, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //hanger
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[222], 0, 13059, "ce_fact03", "sw_newcorrug", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[222], 1, 13059, "ce_fact03", "sw_newcorrug", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[223] = CreateDynamicObject(12928, 1748.7038, -1120.6201, 23.0067, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sw_shedInterior04
	LS_ORDNUNGSAMT[224] = CreateDynamicObject(19477, 1748.6617, -1128.6302, 27.1002, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[224], 0, "Halle 01", OBJECT_MATERIAL_SIZE_512x256, "Arial", 90, 1, 0xFF58595A, 0x00000000, 1);
	LS_ORDNUNGSAMT[225] = CreateDynamicObject(19477, 1748.6617, -1128.6302, 26.7402, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[225], 0, "Straßenbau", OBJECT_MATERIAL_SIZE_512x256, "Arial", 60, 1, 0xFF58595A, 0x00000000, 1);
	LS_ORDNUNGSAMT[226] = CreateDynamicObject(19477, 1767.3220, -1124.6505, 26.7402, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[226], 0, "Betriebslager", OBJECT_MATERIAL_SIZE_512x256, "Arial", 60, 1, 0xFF58595A, 0x00000000, 1);
	LS_ORDNUNGSAMT[227] = CreateDynamicObject(19477, 1767.3220, -1124.6505, 27.1002, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[227], 0, "Halle 02", OBJECT_MATERIAL_SIZE_512x256, "Arial", 90, 1, 0xFF58595A, 0x00000000, 1);
	LS_ORDNUNGSAMT[228] = CreateDynamicObject(19954, 1727.9342, -1106.9952, 22.5625, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	LS_ORDNUNGSAMT[229] = CreateDynamicObject(19954, 1732.9243, -1106.9952, 22.5625, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	LS_ORDNUNGSAMT[230] = CreateDynamicObject(19477, 1737.6822, -1101.7008, 25.8101, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[230], 0, "Zutritt nur für Mitarbeiter", OBJECT_MATERIAL_SIZE_512x256, "Arial", 26, 1, 0xFF58595A, 0x00000000, 1);
	LS_ORDNUNGSAMT[231] = CreateDynamicObject(19477, 1737.6822, -1101.7008, 26.0902, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[231], 0, "Verwaltung", OBJECT_MATERIAL_SIZE_512x256, "Arial", 60, 1, 0xFF58595A, 0x00000000, 1);
	LS_ORDNUNGSAMT[232] = CreateDynamicObject(19477, 1743.2436, -1140.9100, 25.6002, 0.0000, 0.0000, 225.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[232], 0, "Pforte", OBJECT_MATERIAL_SIZE_512x256, "Arial", 50, 1, 0xFF3B4E78, 0x00000000, 1);
	LS_ORDNUNGSAMT[233] = CreateDynamicObject(994, 1773.4034, -1147.6258, 22.9321, 0.0000, -1.8997, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[233], 0, 16093, "a51_ext", "ws_whitewall2_bottom", 0xFFD78E10);
	LS_ORDNUNGSAMT[234] = CreateDynamicObject(994, 1750.5013, -1141.0666, 23.1266, 0.0000, 0.0000, 135.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[234], 0, 16093, "a51_ext", "ws_whitewall2_bottom", 0xFFD78E10);
	LS_ORDNUNGSAMT[235] = CreateDynamicObject(994, 1769.8348, -1117.6229, 23.1067, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[235], 0, 16093, "a51_ext", "ws_whitewall2_bottom", 0xFFD78E10);
	LS_ORDNUNGSAMT[236] = CreateDynamicObject(19477, 1797.7917, -1096.4886, 26.5902, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[236], 0, "01", OBJECT_MATERIAL_SIZE_512x256, "Arial", 200, 1, 0xFFD78E10, 0x00000000, 1);
	LS_ORDNUNGSAMT[237] = CreateDynamicObject(19445, 1800.2655, -1106.4095, 21.3274, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[237], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_btm", 0xFFD78E10);
	LS_ORDNUNGSAMT[238] = CreateDynamicObject(19477, 1805.5825, -1096.4886, 26.5902, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[238], 0, "02", OBJECT_MATERIAL_SIZE_512x256, "Arial", 200, 1, 0xFFD78E10, 0x00000000, 1);
	LS_ORDNUNGSAMT[239] = CreateDynamicObject(19477, 1813.2331, -1096.4886, 26.5902, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[239], 0, "03", OBJECT_MATERIAL_SIZE_512x256, "Arial", 200, 1, 0xFFD78E10, 0x00000000, 1);
	LS_ORDNUNGSAMT[240] = CreateDynamicObject(19445, 1809.8956, -1106.4095, 21.3274, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[240], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_btm", 0xFFD78E10);
	LS_ORDNUNGSAMT[241] = CreateDynamicObject(19445, 1818.4355, -1106.4095, 21.3374, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[241], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_btm", 0xFFD78E10);
	LS_ORDNUNGSAMT[242] = CreateDynamicObject(19445, 1815.1153, -1101.5406, 21.3274, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[242], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_btm", 0xFFD78E10);
	LS_ORDNUNGSAMT[243] = CreateDynamicObject(19445, 1807.2551, -1119.2712, 21.3274, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[243], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_btm", 0xFFD78E10);
	LS_ORDNUNGSAMT[244] = CreateDynamicObject(19445, 1803.5849, -1119.2712, 21.3274, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[244], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_btm", 0xFFD78E10);
	LS_ORDNUNGSAMT[245] = CreateDynamicObject(19445, 1761.2757, -1147.7607, 21.3173, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[245], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[246] = CreateDynamicObject(19445, 1770.9150, -1147.7607, 21.3173, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[246], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[247] = CreateDynamicObject(19445, 1780.5338, -1147.7607, 21.3173, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[247], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[248] = CreateDynamicObject(19445, 1790.1628, -1147.7607, 21.3173, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[248], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[249] = CreateDynamicObject(19445, 1799.7917, -1147.7607, 21.3173, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[249], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[250] = CreateDynamicObject(19445, 1809.4206, -1147.7607, 21.3173, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[250], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[251] = CreateDynamicObject(19445, 1819.0498, -1147.7607, 21.3173, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[251], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[252] = CreateDynamicObject(19355, 1823.5257, -1147.7585, 21.3173, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall003
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[252], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[253] = CreateDynamicObject(19445, 1825.0516, -1143.0343, 21.3173, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[253], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[254] = CreateDynamicObject(19445, 1775.5456, -1103.7900, 21.3274, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[254], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_btm", 0xFFD78E10);
	LS_ORDNUNGSAMT[255] = CreateDynamicObject(19445, 1765.9361, -1103.7900, 21.3274, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[255], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_btm", 0xFFD78E10);
	LS_ORDNUNGSAMT[256] = CreateDynamicObject(19445, 1757.5865, -1103.7900, 21.3374, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[256], 0, 10765, "airportgnd_sfse", "ws_whiteplaster_btm", 0xFFD78E10);
	LS_ORDNUNGSAMT[257] = CreateDynamicObject(19477, 1727.8015, -1134.4111, 27.4803, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[257], 0, "TÜV Center", OBJECT_MATERIAL_SIZE_512x256, "Arial", 90, 1, 0xFFFFFFFF, 0x00000000, 1);
	LS_ORDNUNGSAMT[258] = CreateDynamicObject(19477, 1727.8015, -1134.4111, 28.0102, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[258], 0, "____________", OBJECT_MATERIAL_SIZE_512x256, "Arial", 88, 1, 0xFFFFFFFF, 0x00000000, 1);
	LS_ORDNUNGSAMT[259] = CreateDynamicObject(19477, 1722.5012, -1118.4807, 24.9601, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[259], 0, "z", OBJECT_MATERIAL_SIZE_512x256, "Webdings", 120, 1, 0xFF840410, 0x00000000, 1);
	LS_ORDNUNGSAMT[260] = CreateDynamicObject(19477, 1730.4715, -1134.4110, 25.4801, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[260], 0, "Einfahrt", OBJECT_MATERIAL_SIZE_512x256, "Arial", 50, 1, 0xFFFFFFFF, 0x00000000, 1);
	LS_ORDNUNGSAMT[261] = CreateDynamicObject(19477, 1730.5113, -1134.4110, 25.9500, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[261], 0, "5", OBJECT_MATERIAL_SIZE_512x256, "Webdings", 220, 1, 0xFFFFFFFF, 0x00000000, 1);
	LS_ORDNUNGSAMT[262] = CreateDynamicObject(19477, 1795.5583, -1110.5544, 31.3176, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[262], 0, "@", OBJECT_MATERIAL_SIZE_512x256, "Webdings", 255, 1, 0xFF263739, 0x00000000, 1);
	LS_ORDNUNGSAMT[263] = CreateDynamicObject(19279, 1795.3846, -1114.1954, 29.9388, 270.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCSmallLight1
	LS_ORDNUNGSAMT[264] = CreateDynamicObject(19477, 1795.5583, -1110.5544, 30.3076, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[264], 0, "Werkstatthalle", OBJECT_MATERIAL_SIZE_512x256, "Arial", 88, 1, 0xFF263739, 0x00000000, 1);
	LS_ORDNUNGSAMT[265] = CreateDynamicObject(1703, 1722.6999, -1133.7253, 23.0242, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_couch02
	LS_ORDNUNGSAMT[266] = CreateDynamicObject(2010, 1719.9836, -1133.6716, 23.0578, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nu_plant3_ofc
	LS_ORDNUNGSAMT[267] = CreateDynamicObject(19477, 1719.5814, -1131.9409, 25.8801, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[267], 0, "Herzlich willkommen im", OBJECT_MATERIAL_SIZE_512x256, "Arial", 30, 1, 0xFFFFFFFF, 0x00000000, 1);
	LS_ORDNUNGSAMT[268] = CreateDynamicObject(19786, 1719.4444, -1131.9425, 25.5925, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[268], 1, 10765, "airportgnd_sfse", "white", 0xFF4C75B7);
	LS_ORDNUNGSAMT[269] = CreateDynamicObject(19477, 1719.5814, -1131.9409, 25.5902, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[269], 0, "TÜV Center", OBJECT_MATERIAL_SIZE_512x256, "Arial", 60, 1, 0xFFFFFFFF, 0x00000000, 1);
	LS_ORDNUNGSAMT[270] = CreateDynamicObject(2167, 1719.4781, -1129.0423, 23.0557, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_7
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[270], 0, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[270], 1, 6094, "canalsg_law", "block2bb", 0xFFBDBEC6);
	LS_ORDNUNGSAMT[271] = CreateDynamicObject(19477, 1719.5814, -1131.9409, 25.3101, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[271], 0, "Bitte melden Sie sich an.", OBJECT_MATERIAL_SIZE_512x256, "Arial", 30, 1, 0xFFFFFFFF, 0x00000000, 1);
	LS_ORDNUNGSAMT[272] = CreateDynamicObject(2167, 1719.4781, -1128.1118, 23.0557, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_7
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[272], 0, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[272], 1, 6094, "canalsg_law", "block2bb", 0xFFBDBEC6);
	LS_ORDNUNGSAMT[273] = CreateDynamicObject(2265, 1722.5262, -1127.3645, 24.3001, 0.0000, 90.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_6
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[273], 1, 10765, "airportgnd_sfse", "white", 0xFF4C75B7);
	LS_ORDNUNGSAMT[274] = CreateDynamicObject(2265, 1723.5063, -1128.0849, 24.3001, 0.0000, 90.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_6
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[274], 1, 10765, "airportgnd_sfse", "white", 0xFF000000);
	LS_ORDNUNGSAMT[275] = CreateDynamicObject(19808, 1722.8028, -1127.7159, 23.8817, 0.0000, 0.0000, -93.2996, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
	LS_ORDNUNGSAMT[276] = CreateDynamicObject(18633, 1723.2298, -1127.7165, 23.8896, 90.0000, 90.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAWrench1
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[276], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	LS_ORDNUNGSAMT[277] = CreateDynamicObject(19807, 1722.8618, -1128.3757, 23.9041, 0.0000, 0.0000, -105.5998, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Telephone1
	LS_ORDNUNGSAMT[278] = CreateDynamicObject(1671, 1721.5323, -1127.4892, 23.5132, 0.0000, 0.0000, 69.8999, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
	LS_ORDNUNGSAMT[279] = CreateDynamicObject(2894, 1722.8597, -1129.0228, 23.8588, 0.0000, 0.0000, -109.3999, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_rhymesbook
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[279], 0, 14842, "genintintpolicea", "cop_notice", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[280] = CreateDynamicObject(922, 1721.2434, -1120.8690, 23.9566, 0.0000, 0.0000, -92.6996, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Packing_carates1
	LS_ORDNUNGSAMT[281] = CreateDynamicObject(2169, 1721.8016, -1126.3802, 23.0720, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE3_DESK_1
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[281], 0, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[281], 1, 14668, "711c", "CJ_CHIP_M2", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[282] = CreateDynamicObject(2164, 1719.4847, -1127.1744, 23.0398, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_5
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[282], 1, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[282], 2, 6094, "canalsg_law", "block2bb", 0xFFBDBEC6);
	LS_ORDNUNGSAMT[283] = CreateDynamicObject(19477, 1719.4914, -1124.7707, 26.0902, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[283], 0, "Verwaltung", OBJECT_MATERIAL_SIZE_512x256, "Arial", 60, 1, 0xFF58595A, 0x00000000, 1);
	LS_ORDNUNGSAMT[284] = CreateDynamicObject(19477, 1719.4907, -1124.7624, 25.8101, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane003
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[284], 0, "Zutritt nur für Mitarbeiter", OBJECT_MATERIAL_SIZE_512x256, "Arial", 26, 1, 0xFF58595A, 0x00000000, 1);
	LS_ORDNUNGSAMT[285] = CreateDynamicObject(19479, 1705.6263, -1139.3481, 26.0594, 0.0000, 0.0000, 270.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane005
	SetDynamicObjectMaterialText(LS_ORDNUNGSAMT[285], 0, "Straßen und Ordnungsamt", OBJECT_MATERIAL_SIZE_512x256, "Arial", 30, 1, 0xFF000000, 0x00000000, 1);
	LS_ORDNUNGSAMT[286] = CreateDynamicObject(638, 1712.9128, -1135.9514, 23.7444, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
	ORDNUNGSAMT_TOR[1] = CreateDynamicObject(969, 1748.0399, -1094.2713, 23.2500, 0.0000, 0.0000, 180.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Electricgate
	SetDynamicObjectMaterial(ORDNUNGSAMT_TOR[1], 0, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
	SetDynamicObjectMaterial(ORDNUNGSAMT_TOR[1], 1, -1, "none", "none", 0xFFFFFFFF);
	SetDynamicObjectMaterial(ORDNUNGSAMT_TOR[1], 3, -1, "none", "none", 0xFFFFFFFF);
	SetDynamicObjectMaterial(ORDNUNGSAMT_TOR[1], 4, 6000, "con_drivein", "Desrtmetal", 0xFF515459);
	LS_ORDNUNGSAMT[288] = CreateDynamicObject(19445, 1825.0354, -1089.3974, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[288], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[289] = CreateDynamicObject(19445, 1825.0354, -1079.7645, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[289], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[290] = CreateDynamicObject(19445, 1825.0354, -1070.1247, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[290], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[291] = CreateDynamicObject(19445, 1820.1341, -1065.4044, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[291], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[292] = CreateDynamicObject(19445, 1810.4947, -1065.4044, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[292], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[293] = CreateDynamicObject(19445, 1800.8636, -1065.4044, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[293], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[294] = CreateDynamicObject(19445, 1791.2309, -1065.4044, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[294], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[295] = CreateDynamicObject(19445, 1781.6108, -1065.4044, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[295], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[296] = CreateDynamicObject(19445, 1771.9615, -1065.4044, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[296], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[297] = CreateDynamicObject(19445, 1762.3326, -1065.4044, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[297], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[298] = CreateDynamicObject(19445, 1752.7026, -1065.4044, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[298], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[299] = CreateDynamicObject(19445, 1743.0417, -1065.4044, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[299], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[300] = CreateDynamicObject(19445, 1733.4211, -1065.4044, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[300], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[301] = CreateDynamicObject(19445, 1723.8215, -1065.4044, 24.8076, 0.0000, 0.0000, 90.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[301], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[302] = CreateDynamicObject(19445, 1719.0595, -1070.3144, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[302], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[303] = CreateDynamicObject(19445, 1719.0595, -1095.5296, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[303], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[304] = CreateDynamicObject(19445, 1719.0595, -1085.8980, 24.8076, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(LS_ORDNUNGSAMT[304], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
	LS_ORDNUNGSAMT[305] = CreateDynamicObject(3934, 1819.4753, -1088.8869, 23.1235, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
	LS_ORDNUNGSAMT[306] = CreateDynamicObject(3934, 1819.4753, -1070.3469, 23.1235, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
	LS_ORDNUNGSAMT[307] = CreateDynamicObject(3934, 1819.4753, -1079.3969, 23.1235, 0.0000, 0.0000, 0.0000, VW_ORDNUNGSAMT, MAPS_ORDNUNGSAMT, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
}

hook OnPlayerConnect(playerid) {
	RemoveBuildingForPlayer(playerid, 4748, 1760.1600, -1127.2700, 43.6641, 0.10); // LTSLAbuild7_LAn2
	RemoveBuildingForPlayer(playerid, 4719, 1760.1600, -1127.2700, 43.6641, 0.10); // LOD Model of LTSLAbuild7_LAn2
	RemoveBuildingForPlayer(playerid, 1215, 1704.0200, -1142.8399, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1721.1199, -1142.8399, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1702.6999, -1141.2299, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1702.6999, -1129.8800, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1702.6999, -1118.5200, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1702.6999, -1107.1600, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1702.6999, -1095.8100, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1704.0200, -1094.5300, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1721.1199, -1094.5300, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1738.2099, -1142.8399, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1755.3000, -1142.8399, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1772.4000, -1142.8399, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1789.4899, -1142.8399, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1227, 1800.4499, -1148.3000, 23.6797, 0.10); // dump1
	RemoveBuildingForPlayer(playerid, 1215, 1806.5799, -1142.8399, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1738.2099, -1094.5300, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1755.3000, -1094.5300, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 4718, 1760.1600, -1127.2700, 43.6641, 1.10); // gm_build4_LAn2
	RemoveBuildingForPlayer(playerid, 4719, 1760.1600, -1127.2700, 43.6641, 1.10); // LOD Model of gm_build4_LAn2
	RemoveBuildingForPlayer(playerid, 1215, 1772.4000, -1094.5300, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1227, 1789.7700, -1116.0600, 23.8906, 0.10); // dump1
	RemoveBuildingForPlayer(playerid, 1227, 1789.9100, -1112.6400, 23.8906, 0.10); // dump1
	RemoveBuildingForPlayer(playerid, 1215, 1789.4899, -1094.5300, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 1215, 1806.5799, -1094.5300, 23.6093, 0.10); // bollardlight
	RemoveBuildingForPlayer(playerid, 4640, 1728.7900, -1065.0899, 24.5000, 0.10); // paypark_lan03
}
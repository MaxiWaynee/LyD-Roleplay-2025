#include <YSI\y_hooks>

// Global interior define
#define MAPS_TERROR      0

//static Float:STREAMDISTANCE = 250.0;
//static Float:DRAWDISTANCE   = 250.0;

#define TERROR_GARAGE_FOR_RANGE_COORDS  977.6314, 2072.5798, 10.6723
#define TERROR_GARAGE_CLOSED_Z          10.6723
#define TERROR_GARAGE_OPEN_Z            5.2022
#define TERRORBASE_SPRITLAGER           952.1439,2083.6968,10.8203

/*new terror_Object[122];
new terror_Actor[4];


CMD:terrorgate(playerid, params[]) {
 	if (Spieler[playerid][pFraktion] != 19) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Terrorist.");
	if (!IsPlayerInRangeOfPoint(playerid, 20.0, TERROR_GARAGE_FOR_RANGE_COORDS)) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Tores.");

	new Float:fX, Float:fY, Float:fZ;
	GetObjectPos(terror_Object[1], fX, fY, fZ);

	if (fZ == TERROR_GARAGE_OPEN_Z)
		MoveDynamicObject(terror_Object[1], fX, fY, TERROR_GARAGE_CLOSED_Z, 2.0);
	else
		MoveDynamicObject(terror_Object[1], fX, fY, TERROR_GARAGE_OPEN_Z, 2.0);

	return 1;
}*/

hook OnGameModeInit() {
    /*terror_Object[0] = CreateDynamicObject(19866, 945.0592, 2065.5000, 9.0752, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(terror_Object[0], 0, -1, "none", "none", 0xFFFFFF00);
    terror_Object[1] = CreateDynamicObject(971, 977.6314, 2072.5798, 10.6723, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //subwaygate Terror Torzu
    SetDynamicObjectMaterial(terror_Object[1], 2, 3629, "arprtxxref_las", "ws_corrugated1", 0x00000000);
    SetDynamicObjectMaterial(terror_Object[1], 3, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    terror_Object[2] = CreateDynamicObject(19650, 944.2948, 2064.9956, 7.8281, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TubeFlat25x25m1
    SetDynamicObjectMaterial(terror_Object[2], 0, 10765, "airportgnd_sfse", "coasty_bit3_sfe", 0x00000000);
    terror_Object[3] = CreateDynamicObject(19381, 957.9860, 2058.5583, 14.1216, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(terror_Object[3], 0, 13659, "8bars", "bridgeconc", 0x00000000);
    terror_Object[4] = CreateDynamicObject(1670, 966.4869, 2056.5593, 15.0177, 0.0000, 0.0000, -115.5000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
    terror_Object[5] = CreateDynamicObject(19866, 945.0592, 2083.0000, 9.0752, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(terror_Object[5], 0, -1, "none", "none", 0xFFFFFF00);
    terror_Object[6] = CreateDynamicObject(19650, 942.3129, 2074.8137, 7.8281, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TubeFlat25x25m1
    SetDynamicObjectMaterial(terror_Object[6], 0, 10765, "airportgnd_sfse", "coasty_bit3_sfe", 0x00000000);
    terror_Object[7] = CreateDynamicObject(3943, 949.5847, 2057.6616, 14.3247, 0.0000, 0.0000, -180.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //mid_staircase
    terror_Object[8] = CreateDynamicObject(928, 957.5809, 2063.5969, 10.0996, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //RUBBISH_BOX1
    terror_Object[9] = CreateDynamicObject(19866, 945.0592, 2079.5000, 9.0752, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(terror_Object[9], 0, -1, "none", "none", 0xFFFFFF00);
    terror_Object[10] = CreateDynamicObject(19391, 948.2980, 2054.9064, 11.5560, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall039
    SetDynamicObjectMaterial(terror_Object[10], 0, 10765, "airportgnd_sfse", "coasty_bit3_sfe", 0x00000000);
    terror_Object[11] = CreateDynamicObject(19866, 945.0592, 2076.0000, 9.0752, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(terror_Object[11], 0, -1, "none", "none", 0xFFFFFF00);
    terror_Object[12] = CreateDynamicObject(19464, 956.6563, 2061.7885, 11.6273, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(terror_Object[12], 0, 10765, "airportgnd_sfse", "coasty_bit3_sfe", 0x00000000);
    terror_Object[13] = CreateDynamicObject(19464, 953.8615, 2058.1262, 11.6072, 0.0000, 0.0000, 105.0998, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(terror_Object[13], 0, 10765, "airportgnd_sfse", "coasty_bit3_sfe", 0x00000000);
    terror_Object[14] = CreateDynamicObject(19464, 951.1892, 2057.3957, 11.6072, 0.0000, 0.0000, 106.6997, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(terror_Object[14], 0, 10765, "airportgnd_sfse", "coasty_bit3_sfe", 0x00000000);
    terror_Object[15] = CreateDynamicObject(19866, 945.0592, 2069.0000, 9.0752, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(terror_Object[15], 0, -1, "none", "none", 0xFFFFFF00);
    terror_Object[16] = CreateDynamicObject(19464, 954.5471, 2056.6735, 16.7572, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(terror_Object[16], 0, 10765, "airportgnd_sfse", "coasty_bit3_sfe", 0x00000000);
    terror_Object[17] = CreateDynamicObject(19464, 956.6563, 2062.2290, 16.7273, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(terror_Object[17], 0, 10765, "airportgnd_sfse", "coasty_bit3_sfe", 0x00000000);
    terror_Object[18] = CreateDynamicObject(19464, 950.5324, 2056.4038, 13.6316, 0.0000, 77.8000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(terror_Object[18], 0, 10765, "airportgnd_sfse", "coasty_bit3_sfe", 0x00000000);
    terror_Object[19] = CreateDynamicObject(19866, 945.0592, 2086.5000, 9.0752, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(terror_Object[19], 0, -1, "none", "none", 0xFFFFFF00);
    terror_Object[20] = CreateDynamicObject(19381, 968.4755, 2058.5583, 14.1015, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(terror_Object[20], 0, 13659, "8bars", "bridgeconc", 0x00000000);
    terror_Object[21] = CreateDynamicObject(19866, 945.0592, 2072.5000, 9.0752, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(terror_Object[21], 0, -1, "none", "none", 0xFFFFFF00);
    terror_Object[22] = CreateDynamicObject(19381, 972.7188, 2058.5583, 14.1316, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(terror_Object[22], 0, 13659, "8bars", "bridgeconc", 0x00000000);
    terror_Object[23] = CreateDynamicObject(19650, 940.4046, 2053.6379, 7.8281, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TubeFlat25x25m1
    SetDynamicObjectMaterial(terror_Object[23], 0, 10765, "airportgnd_sfse", "coasty_bit3_sfe", 0x00000000);
    terror_Object[24] = CreateDynamicObject(970, 967.1776, 2063.1481, 14.6990, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(terror_Object[24], 0, 1649, "wglass", "carshowwin2", 0x00000000);
    terror_Object[25] = CreateDynamicObject(970, 963.0062, 2063.1481, 14.6990, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(terror_Object[25], 0, 1649, "wglass", "carshowwin2", 0x00000000);
    terror_Object[26] = CreateDynamicObject(970, 958.8660, 2063.1481, 14.6990, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(terror_Object[26], 0, 1649, "wglass", "carshowwin2", 0x00000000);
    terror_Object[27] = CreateDynamicObject(970, 971.3189, 2063.1481, 14.6990, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(terror_Object[27], 0, 1649, "wglass", "carshowwin2", 0x00000000);
    terror_Object[28] = CreateDynamicObject(970, 975.4511, 2063.1481, 14.6990, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(terror_Object[28], 0, 1649, "wglass", "carshowwin2", 0x00000000);
    terror_Object[29] = CreateDynamicObject(19464, 977.8195, 2056.8356, 16.7273, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(terror_Object[29], 0, 8130, "vgsschurch", "vgschurchwall04_256", 0x00000000);
    terror_Object[30] = CreateDynamicObject(19866, 971.4000, 2083.3979, 9.0853, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(terror_Object[30], 0, -1, "none", "none", 0xFFFFFF00);
    terror_Object[31] = CreateDynamicObject(19465, 969.0526, 2059.9189, 16.7191, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall105
    SetDynamicObjectMaterial(terror_Object[31], 0, 8130, "vgsschurch", "vgschurchwall04_256", 0x00000000);
    terror_Object[32] = CreateDynamicObject(19464, 963.3325, 2058.9287, 16.7273, 0.0000, 0.0000, 109.7998, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(terror_Object[32], 0, 8130, "vgsschurch", "vgschurchwall04_256", 0x00000000);
    terror_Object[33] = CreateDynamicObject(19464, 958.5061, 2055.8764, 16.7273, 0.0000, 0.0000, 134.7998, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(terror_Object[33], 0, 8130, "vgsschurch", "vgschurchwall04_256", 0x00000000);
    terror_Object[34] = CreateDynamicObject(19866, 974.9000, 2083.3979, 9.0853, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(terror_Object[34], 0, -1, "none", "none", 0xFFFFFF00);
    terror_Object[35] = CreateDynamicObject(1491, 969.8110, 2059.9572, 14.1970, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
    SetDynamicObjectMaterial(terror_Object[35], 0, 1649, "wglass", "carshowwin2", 0x00000000);
    terror_Object[36] = CreateDynamicObject(19866, 967.9000, 2083.3979, 9.0853, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(terror_Object[36], 0, -1, "none", "none", 0xFFFFFF00);
    terror_Object[37] = CreateDynamicObject(19464, 974.9694, 2059.9187, 16.7273, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(terror_Object[37], 0, 8130, "vgsschurch", "vgschurchwall04_256", 0x00000000);
    terror_Object[38] = CreateDynamicObject(19866, 964.4000, 2083.3979, 9.0853, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(terror_Object[38], 0, -1, "none", "none", 0xFFFFFF00);
    terror_Object[39] = CreateDynamicObject(19866, 960.9000, 2083.3979, 9.0853, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(terror_Object[39], 0, -1, "none", "none", 0xFFFFFF00);
    terror_Object[40] = CreateDynamicObject(19866, 957.4000, 2083.3979, 9.0853, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MIFenceBlocks1
    SetDynamicObjectMaterial(terror_Object[40], 0, -1, "none", "none", 0xFFFFFF00);
    terror_Object[41] = CreateDynamicObject(11691, 967.1157, 2056.5793, 14.2095, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CTable2
    terror_Object[42] = CreateDynamicObject(11691, 970.1268, 2056.5793, 14.2095, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CTable2
    terror_Object[43] = CreateDynamicObject(11691, 973.1378, 2056.5793, 14.2095, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CTable2
    terror_Object[44] = CreateDynamicObject(1829, 977.0778, 2055.0793, 10.2897, 0.1999, 0.1999, -163.2001, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //man_safenew
    terror_Object[45] = CreateDynamicObject(19171, 977.7061, 2055.9477, 16.0895, 90.0000, -90.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAMap8
    terror_Object[46] = CreateDynamicObject(19170, 977.7061, 2057.4291, 16.0895, 90.0000, -90.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAMap7
    terror_Object[47] = CreateDynamicObject(1550, 976.5822, 2054.3662, 10.2077, 12.5999, 7.8998, 38.5998, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
    terror_Object[48] = CreateDynamicObject(19169, 977.7022, 2055.9440, 17.5900, 90.0000, -90.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAMap6
    terror_Object[49] = CreateDynamicObject(19168, 977.7075, 2057.4291, 17.5816, 90.0000, -90.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAMap5
    terror_Object[50] = CreateDynamicObject(19075, 959.2883, 2061.7292, 11.2602, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cage5mx5mx3mv2
    terror_Object[51] = CreateDynamicObject(1550, 977.5607, 2054.5441, 11.1233, 8.6998, 9.3999, 11.0999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MONEY_BAG
    terror_Object[52] = CreateDynamicObject(18688, 957.4099, 2063.4250, 8.3902, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire
    terror_Object[53] = CreateDynamicObject(2180, 973.0109, 2054.3908, 9.8084, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE5_DESK_3
    terror_Object[54] = CreateDynamicObject(19583, 977.4017, 2055.9626, 16.1002, 2.5999, -59.1999, 85.3999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MarcosKnife1
    terror_Object[55] = CreateDynamicObject(1714, 975.6510, 2056.1579, 14.1947, 0.0000, 0.0000, -119.0999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    terror_Object[56] = CreateDynamicObject(2670, 959.1329, 2061.4462, 9.9102, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PROC_RUBBISH_1
    terror_Object[57] = CreateDynamicObject(1721, 973.9418, 2055.8012, 14.1907, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[58] = CreateDynamicObject(1721, 973.1995, 2054.8981, 14.1907, 0.0000, 0.0000, 12.3000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[59] = CreateDynamicObject(1721, 971.9992, 2054.8796, 14.1907, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[60] = CreateDynamicObject(1721, 970.8688, 2054.8796, 14.1907, 0.0000, 0.0000, -4.3998, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[61] = CreateDynamicObject(1721, 969.5878, 2054.8796, 14.1907, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[62] = CreateDynamicObject(1721, 967.9171, 2055.7805, 14.1907, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[63] = CreateDynamicObject(1721, 967.1262, 2055.7805, 14.1907, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[64] = CreateDynamicObject(1721, 966.2457, 2055.7805, 14.1907, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[65] = CreateDynamicObject(1721, 966.2457, 2057.3820, 14.1907, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[66] = CreateDynamicObject(1721, 967.0164, 2057.3820, 14.1907, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[67] = CreateDynamicObject(926, 960.3538, 2063.0917, 10.0555, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //RUBBISH_BOX2
    terror_Object[68] = CreateDynamicObject(2602, 957.1777, 2061.0266, 10.3402, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Police_cell_Toilet
    terror_Object[69] = CreateDynamicObject(1721, 967.9570, 2058.4030, 14.1907, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[70] = CreateDynamicObject(363, 974.3731, 2053.9985, 10.8861, -19.2999, -2.0000, 140.3999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //satchel
    terror_Object[71] = CreateDynamicObject(1721, 969.0479, 2058.4030, 14.1907, 0.0000, 0.0000, -168.6999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[72] = CreateDynamicObject(1721, 970.0488, 2058.4030, 14.1907, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[73] = CreateDynamicObject(1721, 971.2097, 2058.4030, 14.1907, 0.0000, 0.0000, 172.7998, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[74] = CreateDynamicObject(1721, 972.4503, 2058.4030, 14.1907, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[75] = CreateDynamicObject(1721, 973.4309, 2057.3520, 14.1907, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[76] = CreateDynamicObject(1721, 974.2619, 2058.4230, 14.1907, 0.0000, 0.0000, -173.8997, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //est_chair1
    terror_Object[77] = CreateDynamicObject(19873, 956.8936, 2060.5048, 9.8964, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToiletPaperRoll1
    terror_Object[78] = CreateDynamicObject(1670, 973.6724, 2056.5769, 15.0177, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
    terror_Object[79] = CreateDynamicObject(1670, 972.4221, 2056.5769, 15.0177, 0.0000, 0.0000, 65.7998, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
    terror_Object[80] = CreateDynamicObject(1670, 970.7756, 2056.5825, 15.0177, 0.0000, 0.0000, 146.0998, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
    terror_Object[81] = CreateDynamicObject(1670, 969.3162, 2056.5446, 15.0177, 0.0000, 0.0000, 174.8000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
    terror_Object[82] = CreateDynamicObject(1670, 967.6411, 2056.4543, 15.0177, 0.0000, 0.0000, 174.8000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //propcollecttable
    terror_Object[83] = CreateDynamicObject(19381, 962.2352, 2058.5583, 19.1116, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(terror_Object[83], 0, 13659, "8bars", "bridgeconc", 0x00000000);
    terror_Object[84] = CreateDynamicObject(19381, 972.7188, 2058.5583, 19.1215, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(terror_Object[84], 0, 13659, "8bars", "bridgeconc", 0x00000000);
    terror_Object[85] = CreateDynamicObject(359, 972.9133, 2054.5278, 10.5875, 77.4998, 0.0000, -26.7999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rocketla
    terror_Object[86] = CreateDynamicObject(19381, 951.7437, 2058.5583, 19.1116, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall029
    SetDynamicObjectMaterial(terror_Object[86], 0, 13659, "8bars", "bridgeconc", 0x00000000);
    terror_Object[87] = CreateDynamicObject(355, 962.1989, 2060.1889, 10.9968, 0.0000, 46.5998, 84.9999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ak47
    terror_Object[88] = CreateDynamicObject(2985, 977.4592, 2061.2753, 11.1595, 0.0000, 0.0000, -180.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //minigun_base
    terror_Object[89] = CreateDynamicObject(363, 974.2160, 2054.0861, 10.9029, -39.8998, 0.3000, -162.7001, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //satchel
    terror_Object[90] = CreateDynamicObject(363, 974.3385, 2054.0676, 10.9292, -22.4999, 4.3998, -160.7003, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //satchel
    terror_Object[91] = CreateDynamicObject(1271, 977.4492, 2061.7600, 10.1702, 0.0000, 0.0000, 11.3999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gunbox
    terror_Object[92] = CreateDynamicObject(1271, 977.3920, 2060.8378, 10.1702, 0.0000, 0.0000, -20.6000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gunbox
    terror_Object[93] = CreateDynamicObject(1271, 977.5239, 2061.2741, 10.8603, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gunbox
    terror_Object[94] = CreateDynamicObject(364, 973.9874, 2054.3110, 10.6472, 0.0000, -56.0000, -99.8998, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bomb
    terror_Object[95] = CreateDynamicObject(19650, 965.3989, 2053.6379, 7.8281, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TubeFlat25x25m1
    SetDynamicObjectMaterial(terror_Object[95], 0, 10765, "airportgnd_sfse", "coasty_bit3_sfe", 0x00000000);
    terror_Object[96] = CreateDynamicObject(342, 973.7230, 2054.1862, 10.6508, -0.0998, -0.2998, -72.5000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grenade
    terror_Object[97] = CreateDynamicObject(342, 973.6220, 2054.1982, 10.6468, 4.6999, -8.4998, -67.5998, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grenade
    terror_Object[98] = CreateDynamicObject(342, 973.6854, 2054.2797, 10.6567, 14.8999, -8.4998, -61.1999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grenade
    terror_Object[99] = CreateDynamicObject(342, 973.6640, 2054.3818, 10.6384, 14.8999, 6.5000, -80.0999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grenade
    terror_Object[100] = CreateDynamicObject(342, 973.5952, 2054.2863, 10.6289, 14.8999, 6.5000, -61.1999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //grenade
    terror_Object[101] = CreateDynamicObject(14782, 967.9712, 2054.2470, 10.8097, 0.0000, 0.0000, -180.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //int3int_boxing30
    terror_Object[102] = CreateDynamicObject(19173, 973.7587, 2053.8942, 16.4688, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    terror_Object[103] = CreateDynamicObject(1242, 972.7205, 2054.1027, 10.8272, 0.0000, 0.0000, -12.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bodyarmour
    terror_Object[104] = CreateDynamicObject(19173, 969.0661, 2060.0515, 17.0088, 0.0000, 0.0000, 0.0000); //SAMPPicture2
    SetDynamicObjectMaterialText(terror_Object[104], 0, "Besprechungsraum", OBJECT_MATERIAL_SIZE_256x128, "Arial", 30, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(terror_Object[104], 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
    terror_Object[105] = CreateDynamicObject(19174, 967.0456, 2053.8842, 16.8432, 0.0000, 0.0000, -180.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    terror_Object[106] = CreateDynamicObject(1654, 973.4855, 2053.9587, 10.8136, -11.9998, 1.7999, 173.4999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //dynamite
    terror_Object[107] = CreateDynamicObject(1654, 973.6307, 2053.9365, 10.8162, -11.9998, 1.7999, 146.5001, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //dynamite
    terror_Object[108] = CreateDynamicObject(1654, 973.3568, 2053.9689, 10.7851, -26.3998, -3.7999, -143.4999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //dynamite
    terror_Object[109] = CreateDynamicObject(18075, 974.1419, 2057.6066, 19.0709, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    terror_Object[110] = CreateDynamicObject(19440, 954.8252, 2059.6857, 18.2692, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall080
    SetDynamicObjectMaterial(terror_Object[110], 0, 10765, "airportgnd_sfse", "coasty_bit3_sfe", 0x00000000);
    terror_Object[111] = CreateDynamicObject(18075, 965.4202, 2057.6066, 19.0709, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    terror_Object[112] = CreateDynamicObject(18075, 955.9192, 2057.6066, 19.0709, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    terror_Object[113] = CreateDynamicObject(349, 977.6593, 2057.9370, 11.9380, 6.2000, 10.5999, 96.9000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chromegun
    terror_Object[114] = CreateDynamicObject(348, 977.6327, 2057.6315, 10.5922, 10.3000, 24.7000, 86.4999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    terror_Object[115] = CreateDynamicObject(2475, 977.7771, 2058.4323, 9.6957, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOBBY_SHELF_3
    terror_Object[116] = CreateDynamicObject(335, 977.6394, 2058.4316, 10.5926, -1.8000, 0.0000, 74.5999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //knifecur
    terror_Object[117] = CreateDynamicObject(335, 977.6099, 2058.3269, 10.5926, -2.8999, 13.0000, 74.5999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //knifecur
    terror_Object[118] = CreateDynamicObject(355, 977.7009, 2057.9873, 11.2812, 0.0000, -10.9000, 84.3998, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ak47
    terror_Object[119] = CreateDynamicObject(335, 977.5900, 2058.5073, 10.6069, 2.9000, 14.8000, 52.3999, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //knifecur
    terror_Object[120] = CreateDynamicObject(3399, 940.25641, 2091.37720, 16.45920,   0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Treppe
    terror_Object[121] = CreateDynamicObject(3399, 951.96851, 2091.37720, 11.75520,   0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_TERROR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Treppe
    terror_Actor[0] = CreateActor(297, 960.8994, 2062.0764, 10.8203, -104.3998); //Madd Dogg
    ApplyActorAnimation(terror_Actor[0], "RIOT", "RIOT_ANGRY_B", 4.0900, 1, 0, 0, 0, 0);
    terror_Actor[1] = CreateActor(142, 962.0300, 2060.1640, 10.8102, -87.6999); //Taxi Driver
    ApplyActorAnimation(terror_Actor[1], "COP_AMBIENT", "COPLOOK_LOOP", 4.0998, 1, 0, 0, 0, 0);
    terror_Actor[2] = CreateActor(14, 962.7107, 2062.5793, 15.5048, 0.0000); //Normal Ped
    ApplyActorAnimation(terror_Actor[2], "BAR", "BARSERVE_LOOP", 4.0999, 1, 0, 0, 0, 0);
    terror_Actor[3] = CreateActor(12, 957.7106, 2061.5036, 10.5457, -85.1001); //Rich Woman
    ApplyActorAnimation(terror_Actor[3], "CRACK", "CRCKIDLE3", 4.0999, 1, 0, 0, 0, 0);*/
}

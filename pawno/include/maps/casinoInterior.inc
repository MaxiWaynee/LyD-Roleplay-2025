#include <YSI\y_hooks>

// Global interior define

// Local drawdistance & streamdistance setting
//static Float:STREAMDISTANCE = 350.0;
//static Float:DRAWDISTANCE   = 350.0;

// Casino points
// #define CASINO_INTERIOR_SPAWN_POINT           246.3446, 185.5452, 1008.1719 // + 0.5
// #define CASINO_INTERIOR_SPAWN_POINT_FACING    0.0


// Map variables
//new object_casinoInterior[71];


hook OnPlayerConnect(playerid) {
	// ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// Entrances/Exits of BIZ are handled im lyd.pwn

	return 1;
}

hook OnGameModeInit() {    

/*
	// Objects - VW_ALL because they are necessary for LV Bank as well
	object_casinoInterior[0] = CreateDynamicObject(6047, 1953.79980, 1012.09961, 999.00000, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[1] = CreateDynamicObject(6047, 1953.19922, 1002.79980, 999.00000, 0.00000, 0.00000, 24.00000);
	object_casinoInterior[2] = CreateDynamicObject(6047, 1953.29980, 1030.39941, 999.00000, 0.00000, 0.00000, 341.49899);
	object_casinoInterior[3] = CreateDynamicObject(2784, 1995.50000, 1013.55859, 995.16998, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[4] = CreateDynamicObject(2592, 1989.54907, 1013.29980, 994.69989, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[5] = CreateDynamicObject(2592, 1989.58008, 1013.82910, 994.69800, 0.00000, 0.00000, 179.99500);
	object_casinoInterior[6] = CreateDynamicObject(1836, 1997.71582, 1013.68970, 994.68799, 0.00000, 0.00000, 179.99500);
	object_casinoInterior[7] = CreateDynamicObject(1836, 1993.29004, 1013.69824, 994.68799, 0.00000, 0.00000, 179.99500);
	object_casinoInterior[8] = CreateDynamicObject(1835, 1995.18945, 1013.70801, 994.68799, 0.00000, 0.00000, 179.99500);
	object_casinoInterior[9] = CreateDynamicObject(1835, 1995.80273, 1013.69946, 994.68799, 0.00000, 0.00000, 179.99500);
	object_casinoInterior[10] = CreateDynamicObject(2125, 1998.50000, 1009.20001, 993.79999, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[11] = CreateDynamicObject(2125, 2003.50000, 1009.19922, 993.79999, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[12] = CreateDynamicObject(2125, 2002.50000, 1009.19922, 993.79999, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[13] = CreateDynamicObject(2125, 2001.50000, 1009.19922, 993.79999, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[14] = CreateDynamicObject(2125, 2000.50000, 1009.19922, 993.79999, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[15] = CreateDynamicObject(2125, 1999.50000, 1009.19922, 993.79999, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[16] = CreateDynamicObject(2784, 1995.40002, 1022.00000, 995.20001, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[17] = CreateDynamicObject(1836, 1997.50000, 1021.90002, 994.70001, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[18] = CreateDynamicObject(1836, 1993.09998, 1021.90002, 994.70001, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[19] = CreateDynamicObject(1833, 1995.00000, 1021.90002, 994.70001, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[20] = CreateDynamicObject(1834, 1995.59998, 1021.90002, 994.70001, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[21] = CreateDynamicObject(2592, 1989.42944, 1022.32983, 994.79999, 0.00000, 0.00000, 179.99500);
	object_casinoInterior[22] = CreateDynamicObject(2592, 1989.39990, 1021.79999, 994.79999, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[23] = CreateDynamicObject(1836, 1989.40002, 1021.89996, 994.70001, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[24] = CreateDynamicObject(14565, 2005.80005, 1001.90002, 997.20001, 0.00000, 0.00000, 270.00000);
	object_casinoInterior[25] = CreateDynamicObject(3471, 2005.19995, 1011.79999, 994.70001, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[26] = CreateDynamicObject(3471, 2005.19995, 1024.00000, 994.70001, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[27] = CreateDynamicObject(1775, 2004.09998, 1004.29999, 994.59998, 0.00000, 0.00000, 268.00000);
	object_casinoInterior[28] = CreateDynamicObject(1302, 2004.09998, 1006.20001, 993.50000, 0.00000, 0.00000, 270.00000);
	object_casinoInterior[29] = CreateDynamicObject(1824, 1985.50000, 1005.50000, 993.91998, 0.00000, 0.00000, -180.00000);
	object_casinoInterior[30] = CreateDynamicObject(1824, 1991.31604, 1005.51208, 993.91998, 0.00000, 0.00000, -180.00000);
	object_casinoInterior[31] = CreateDynamicObject(2188, 1981.00000, 1010.00000, 994.50000, 0.00000, 0.00000, 90.00000);
	object_casinoInterior[32] = CreateDynamicObject(2188, 1981.00000, 1013.79999, 994.50000, 0.00000, 0.00000, 90.00000);
	object_casinoInterior[33] = CreateDynamicObject(1895, 1980.19995, 1018.79999, 995.60004, 0.00000, 0.00000, 88.00000);
	object_casinoInterior[34] = CreateDynamicObject(1896, 1981.40002, 1019.00000, 994.50000, 0.00000, 0.00000, 90.00000);
	object_casinoInterior[35] = CreateDynamicObject(1896, 1981.50000, 1023.50000, 994.50000, 0.00000, 0.00000, 90.00000);
	object_casinoInterior[36] = CreateDynamicObject(1895, 1980.19995, 1023.59998, 995.60004, 0.00000, 0.00000, 87.99500);
	object_casinoInterior[37] = CreateDynamicObject(2773, 2018.19995, 1019.70001, 996.40002, 0.00000, 0.00000, 270.00000);
	object_casinoInterior[38] = CreateDynamicObject(2773, 2018.19995, 1016.20001, 996.40002, 0.00000, 0.00000, 270.00000);
	object_casinoInterior[39] = CreateDynamicObject(1835, 1989.53064, 1013.73004, 994.60004, 0.00000, 0.00000, 180.00000);
	object_casinoInterior[40] = CreateDynamicObject(1835, 1990.79907, 1013.73004, 994.60004, 0.00000, 0.00000, 179.99500);
	object_casinoInterior[41] = CreateDynamicObject(1835, 1990.15967, 1013.73004, 994.60004, 0.00000, 0.00000, 179.99500);
	object_casinoInterior[42] = CreateDynamicObject(1835, 1988.90015, 1013.73004, 994.60004, 0.00000, 0.00000, 180.00000);
	object_casinoInterior[43] = CreateDynamicObject(1835, 1988.26929, 1013.73004, 994.60004, 0.00000, 0.00000, 180.00000);
	object_casinoInterior[44] = CreateDynamicObject(2596, 2003.70239, 1032.40039, 997.70001, 9.00000, 0.00000, 326.00000);
	object_casinoInterior[45] = CreateDynamicObject(2439, 2003.64539, 1008.09662, 993.46558, 0.00000, 0.00000, -180.00000);
	object_casinoInterior[46] = CreateDynamicObject(2439, 2002.66248, 1008.09662, 993.46558, 0.00000, 0.00000, -180.00000);
	object_casinoInterior[47] = CreateDynamicObject(2439, 2001.66199, 1008.09662, 993.46558, 0.00000, 0.00000, -180.00000);
	object_casinoInterior[48] = CreateDynamicObject(2439, 2000.69580, 1008.09662, 993.46558, 0.00000, 0.00000, -180.00000);
	object_casinoInterior[49] = CreateDynamicObject(2439, 1999.69739, 1008.09662, 993.46558, 0.00000, 0.00000, -180.29990);
	object_casinoInterior[50] = CreateDynamicObject(2439, 1998.69629, 1008.09662, 993.46558, 0.00000, 0.00000, -180.00000);
	object_casinoInterior[51] = CreateDynamicObject(2440, 1997.70715, 1008.09662, 993.46558, 0.00000, 0.00000, 180.00000);
	object_casinoInterior[52] = CreateDynamicObject(2439, 1997.67212, 1007.09521, 993.46558, 0.00000, 0.00000, -90.00000);
	object_casinoInterior[53] = CreateDynamicObject(2439, 1997.67212, 1006.09521, 993.46558, 0.00000, 0.00000, -90.00000);
	object_casinoInterior[54] = CreateDynamicObject(2439, 1997.67212, 1005.09521, 993.46558, 0.00000, 0.00000, -90.00000);
	object_casinoInterior[55] = CreateDynamicObject(2433, 2002.79810, 1003.18060, 993.27588, 0.00000, 0.00000, -180.00000);
	object_casinoInterior[56] = CreateDynamicObject(2433, 2000.89612, 1003.20050, 993.27588, 0.00000, 0.00000, -180.00000);
	object_casinoInterior[57] = CreateDynamicObject(3437, 1979.71436, 1011.73108, 993.89392, 0.00000, 0.00000, -99.71994);
	object_casinoInterior[58] = CreateDynamicObject(3437, 1979.66418, 1021.16193, 993.89392, 0.00000, 0.00000, -99.71994);
	object_casinoInterior[59] = CreateDynamicObject(3437, 1980.81519, 1004.64044, 993.89392, 0.00000, 0.00000, -56.99992);
	object_casinoInterior[60] = CreateDynamicObject(3437, 1981.07739, 1031.36963, 993.89392, 0.00000, 0.00000, -106.55994);
	object_casinoInterior[61] = CreateDynamicObject(1978, 1988.00000, 1028.56287, 994.48511, 0.00000, 0.00000, 90.00000);
	object_casinoInterior[62] = CreateDynamicObject(1726, 2003.62585, 1029.28174, 993.42883, 0.00000, 0.00000, -449.52005);
	object_casinoInterior[63] = CreateDynamicObject(1978, 1995.02002, 1028.56372, 994.48511, 0.00000, 0.00000, 90.00000);
	object_casinoInterior[64] = CreateDynamicObject(1726, 2003.61084, 1031.61548, 993.42883, 0.00000, 0.00000, -449.52005);
	object_casinoInterior[65] = CreateDynamicObject(1726, 2000.84204, 1032.25720, 993.42877, 0.00000, 0.00000, -359.40021);
	object_casinoInterior[66] = CreateDynamicObject(1726, 1998.49377, 1032.25720, 993.42877, 0.00000, 0.00000, -359.40021);
	object_casinoInterior[67] = CreateDynamicObject(1726, 1983.55481, 1032.01904, 993.42877, 0.00000, 0.00000, -359.40021);
	object_casinoInterior[68] = CreateDynamicObject(1726, 1982.95361, 1029.37354, 993.42877, 0.00000, 0.00000, -269.28040);
	object_casinoInterior[69] = CreateDynamicObject(633, 1982.99023, 1032.11865, 994.46417, 0.00000, 0.00000, 0.00000);
	object_casinoInterior[70] = CreateDynamicObject(633, 2003.70667, 1032.25574, 994.47815, 0.00000, 0.00000, 0.00000);*/
}

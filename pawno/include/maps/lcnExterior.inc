#include <YSI\y_hooks>

// Global interior define
#define LCNEXTERIOR_WORLD      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 130.0;

// Map variables
new lcnExterior_objects[74];

hook OnPlayerConnect(playerid) {
    // Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 727, 893.2656, -916.9375, 41.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 727, 876.0469, -924.8828, 43.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 727, 859.8984, -934.8906, 45.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 727, 972.0781, -936.7813, 40.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 866.1875, -923.8281, 50.4297, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 882.6641, -912.2813, 46.2813, 0.25);
	RemoveBuildingForPlayer(playerid, 717, 888.5000, -942.6094, 40.4453, 0.25);
	RemoveBuildingForPlayer(playerid, 717, 896.1563, -942.6094, 41.4844, 0.25);
	RemoveBuildingForPlayer(playerid, 717, 908.4063, -942.6094, 41.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 717, 916.3672, -942.6094, 41.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 717, 923.8203, -942.6094, 41.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 717, 953.4375, -939.4141, 41.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 974.4766, -907.5547, 41.7422, 0.25);
	RemoveBuildingForPlayer(playerid, 3643, 992.4844, -896.2813, 46.4063, 0.25);
	RemoveBuildingForPlayer(playerid, 1307, 998.5781, -951.0703, 41.4844, 0.25);
	RemoveBuildingForPlayer(playerid, 3643, 1005.0625, -895.5547, 45.8594, 0.25);
	RemoveBuildingForPlayer(playerid, 3379, 845.8672, -888.3750, 64.8594, 0.25);
	RemoveBuildingForPlayer(playerid, 1315, 838.6016, -875.8906, 70.8047, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 874.1016, -907.2969, 57.9219, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// On the Main-Script
    return 1;
}

hook OnGameModeInit() {

    // Objects
    lcnExterior_objects[0] = CreateDynamicObject(3660, 886.82245, -922.46423, 43.13931,   0.00000, 0.00000, 25.98001, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[1] = CreateDynamicObject(3660, 869.76385, -932.09534, 43.50265,   0.00000, 2.00000, 33.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[2] = CreateDynamicObject(8661, 924.19073, -933.80664, 41.61532,   0.00000, 0.00000, 4.74000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[3] = CreateDynamicObject(717, 908.71045, -944.62738, 41.80226,   0.00000, 0.00000, 3.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[4] = CreateDynamicObject(3524, 905.30945, -945.86859, 44.87415,   0.00000, 0.00000, 32.22002, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[5] = CreateDynamicObject(3524, 900.19611, -946.39404, 44.87415,   0.00000, 0.00000, -19.44000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[6] = CreateDynamicObject(717, 918.60382, -943.45746, 41.80226,   0.00000, 0.00000, 3.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[7] = CreateDynamicObject(717, 927.25140, -942.74670, 41.80226,   0.00000, 0.00000, 3.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[8] = CreateDynamicObject(717, 893.27112, -917.48730, 41.75891,   0.00000, 0.00000, 26.04000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[9] = CreateDynamicObject(717, 884.18866, -921.26001, 41.80226,   0.00000, 0.00000, 26.04000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[10] = CreateDynamicObject(717, 875.13715, -926.32526, 41.80226,   0.00000, 0.00000, 26.04000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[11] = CreateDynamicObject(717, 865.78601, -932.14465, 41.91239,   0.00000, 0.00000, 26.04000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[12] = CreateDynamicObject(717, 857.41144, -940.17322, 44.01608,   0.00000, 0.00000, 26.04000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[13] = CreateDynamicObject(620, 862.30560, -931.60376, 45.00291,   356.85840, 0.00000, -2.49966, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[14] = CreateDynamicObject(973, 871.21698, -891.87775, 64.55782,   0.00000, -4.00000, 113.08000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[15] = CreateDynamicObject(973, 872.19128, -900.65723, 63.90912,   0.00000, -4.00000, 78.51998, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[16] = CreateDynamicObject(973, 869.28583, -909.29852, 62.79850,   -0.12000, -9.54000, 64.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[17] = CreateDynamicObject(973, 865.07556, -917.04395, 61.11718,   0.00000, -12.00000, 58.77999, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[18] = CreateDynamicObject(973, 860.28882, -924.65613, 58.86560,   0.00000, -16.00000, 57.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[19] = CreateDynamicObject(973, 855.44928, -931.86719, 55.96651,   0.00000, -20.84000, 55.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[20] = CreateDynamicObject(973, 850.98456, -939.17847, 52.42038,   0.00000, -24.00000, 62.50001, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[21] = CreateDynamicObject(717, 976.49780, -941.52466, 40.37809,   356.85840, 0.00000, 3.14159, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[22] = CreateDynamicObject(717, 967.85822, -940.80988, 39.91918,   356.85840, 0.00000, 3.14159, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[23] = CreateDynamicObject(3934, 968.42371, -919.40814, 44.75976,   0.00000, 0.00000, 92.39999, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[24] = CreateDynamicObject(19122, 978.17865, -927.70355, 45.22543,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[25] = CreateDynamicObject(19122, 977.12769, -911.78552, 45.22543,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[26] = CreateDynamicObject(19122, 964.30573, -912.18756, 45.22543,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[27] = CreateDynamicObject(19122, 957.88306, -918.59961, 45.22543,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[28] = CreateDynamicObject(19122, 962.44537, -928.86578, 45.22543,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[29] = CreateDynamicObject(717, 952.90912, -941.21979, 41.88281,   356.85840, 0.00000, 3.14159, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[30] = CreateDynamicObject(13754, 920.48438, -856.51563, 90.50781,   356.85840, 0.00000, -2.01699, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[31] = CreateDynamicObject(717, 977.55939, -929.14795, 41.86415,   356.85840, 0.00000, 3.14159, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[32] = CreateDynamicObject(10183, 1009.26465, -893.20795, 41.32460,   0.00000, 0.00000, 47.76001, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[33] = CreateDynamicObject(10183, 1065.15161, -897.88110, 42.27946,   0.00000, 0.00000, -43.68000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[34] = CreateDynamicObject(19377, 909.83618, -904.62354, 66.50974,   0.00000, 90.00000, 3.90000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[35] = CreateDynamicObject(970, 902.25623, -921.25385, 42.11844,   0.00000, 0.00000, -86.09999, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[36] = CreateDynamicObject(2946, 900.62201, -901.80389, 44.68207,   0.00000, 0.00000, 3.06000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[37] = CreateDynamicObject(2946, 900.63165, -901.72223, 44.68207,   0.00000, 0.00000, -177.18005, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[38] = CreateDynamicObject(19372, 902.30646, -903.28613, 45.30103,   0.00000, 0.00000, -89.69999, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[39] = CreateDynamicObject(19372, 902.09314, -900.24335, 45.31583,   0.00000, 0.00000, -89.09999, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[40] = CreateDynamicObject(19372, 902.35553, -901.68536, 46.98598,   0.00000, 90.00000, 3.10000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[41] = CreateDynamicObject(19122, 900.59058, -946.40338, 39.82837,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[42] = CreateDynamicObject(19122, 904.82025, -945.90948, 39.82837,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[43] = CreateDynamicObject(19124, 989.05927, -890.38086, 41.87802,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[44] = CreateDynamicObject(19124, 1029.19031, -888.67584, 41.87802,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[45] = CreateDynamicObject(19124, 1068.59143, -877.66199, 42.54692,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[46] = CreateDynamicObject(10183, 1065.15161, -897.88110, 42.27946,   0.00000, 0.00000, -43.68000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[47] = CreateDynamicObject(19124, 1069.20398, -917.89624, 42.54692,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[48] = CreateDynamicObject(18648, 905.57312, -924.69720, 46.23086,   0.00000, 0.00000, -86.22001, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[49] = CreateDynamicObject(18648, 910.94427, -924.38379, 46.23082,   0.00000, 0.00000, -86.22001, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[50] = CreateDynamicObject(18648, 916.21454, -924.02625, 46.22495,   0.00000, 0.00000, -86.22001, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[51] = CreateDynamicObject(18648, 921.40399, -923.67236, 46.23434,   0.00000, 0.00000, -86.22001, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[52] = CreateDynamicObject(18648, 926.61432, -923.34753, 46.23903,   0.00000, 0.00000, -86.22001, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[53] = CreateDynamicObject(869, 907.99402, -939.95520, 42.09524,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[54] = CreateDynamicObject(869, 912.85443, -936.45477, 42.09524,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[55] = CreateDynamicObject(869, 919.05884, -936.24847, 42.09524,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[56] = CreateDynamicObject(869, 926.38617, -936.69318, 42.09524,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[57] = CreateDynamicObject(869, 913.95276, -941.59448, 42.09524,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[58] = CreateDynamicObject(869, 921.25018, -940.63885, 42.09524,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[59] = CreateDynamicObject(1307, 904.10455, -960.64954, 38.13413,   356.85840, 0.00000, -3.14159, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[60] = CreateDynamicObject(1985, 905.27460, -919.11890, 48.13319,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[61] = CreateDynamicObject(1985, 909.17468, -918.88403, 48.07933,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[62] = CreateDynamicObject(19983, 839.60260, -885.12183, 66.93459,   0.00000, 0.00000, -129.29997, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[63] = CreateDynamicObject(19983, 977.75916, -943.16101, 39.80026,   0.00000, 0.00000, -301.37973, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[64] = CreateDynamicObject(19122, 902.75818, -946.14362, 39.82837,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[65] = CreateDynamicObject(18648, 905.73956, -917.50018, 54.12276,   0.00000, 0.00000, -86.52002, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[66] = CreateDynamicObject(18648, 919.65283, -916.56470, 54.11661,   0.00000, 0.00000, -86.64002, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[67] = CreateDynamicObject(19122, 881.79382, -945.63696, 40.01884,   0.00000, 0.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[68] = CreateDynamicObject(620, 853.55005, -945.15979, 44.77193,   3.14159, 0.00000, 2.35619, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[69] = CreateDynamicObject(620, 888.36993, -910.73065, 45.61993,   356.85840, 0.00000, -2.49966, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[70] = CreateDynamicObject(620, 872.18518, -918.08240, 48.01854,   356.85840, 0.00000, -2.49966, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[71] = CreateDynamicObject(973, 858.78638, -946.49274, 45.34623,   0.00000, -18.00000, -178.43996, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[72] = CreateDynamicObject(1307, 849.78485, -944.68939, 47.94565,   356.85840, 0.00000, -3.14159, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	lcnExterior_objects[73] = CreateDynamicObject(19122, 863.13947, -946.42358, 43.67207,   0.00000, 16.00000, 0.00000, VW_MAIN, LCNEXTERIOR_WORLD, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}

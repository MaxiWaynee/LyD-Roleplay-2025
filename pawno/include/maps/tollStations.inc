#include <YSI\y_hooks>

// Global interior define
#define MAPS_TOLLSTATIONS_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Map variables
new object_tollStations[123];

hook OnPlayerConnect(playerid) {
    //Zoll LS
    RemoveBuildingForPlayer(playerid, 4504, 56.3828, -1531.4531, 6.7266, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Objects
    //ZOLL1
    object_tollStations[0] = CreateDynamicObject(8168, 62.2639, -1533.1334, 6.0103, 0.0000, 0.0000, 8.0999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Vgs_guardhouse01
    object_tollStations[1] = CreateDynamicObject(8168, 45.8672, -1530.7719, 6.1303, 0.0000, 0.0000, 188.1000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Vgs_guardhouse01
    object_tollStations[2] = CreateDynamicObject(973, 53.7509, -1534.2060, 5.0679, 0.0000, -0.4999, 172.2998, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[3] = CreateDynamicObject(973, 54.4191, -1529.7448, 5.0685, 0.0000, -0.4999, -7.5001, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[4] = CreateDynamicObject(973, 70.5445, -1533.0570, 4.9836, 0.0000, -0.9998, -21.6000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[5] = CreateDynamicObject(973, 70.1585, -1535.4470, 5.0250, 0.0000, 0.6000, -173.8999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[6] = CreateDynamicObject(1237, 75.1227, -1534.9157, 4.2719, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //strtbarrier01
    object_tollStations[7] = CreateDynamicObject(1237, 32.9127, -1529.0660, 4.2817, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //strtbarrier01
    object_tollStations[8] = CreateDynamicObject(973, 37.9784, -1528.5140, 5.2071, 0.5000, 0.0000, 7.3997, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[9] = CreateDynamicObject(973, 37.5949, -1530.8525, 5.1906, -0.1999, -0.1999, 158.0997, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier

    //ZOLL2
    object_tollStations[10] = CreateDynamicObject(10832, 96.3298, -1275.1402, 14.7564, 0.0000, 0.0000, 34.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gatehouse2_SFSe
    object_tollStations[11] = CreateDynamicObject(973, 87.5731, -1288.4625, 13.4245, 0.0000, 2.2999, -140.7000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[12] = CreateDynamicObject(973, 94.8260, -1282.5267, 13.8009, 0.0000, 2.2999, -140.7000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[13] = CreateDynamicObject(973, 80.3219, -1294.3969, 13.0081, 0.0000, 2.7999, -140.7000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[14] = CreateDynamicObject(973, 72.1528, -1297.4921, 12.5758, 0.0000, 2.7999, -178.1000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[15] = CreateDynamicObject(10832, 87.5280, -1262.0917, 15.0864, 0.0000, 0.0000, 213.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gatehouse2_SFSe
    object_tollStations[16] = CreateDynamicObject(973, 63.8647, -1300.6112, 12.1223, 0.0000, 2.7999, -140.9999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[17] = CreateDynamicObject(973, 55.9589, -1305.1704, 11.6640, 0.0000, 2.7999, -159.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[18] = CreateDynamicObject(973, 83.8633, -1298.7634, 12.9310, 0.0000, -2.2000, 40.8999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[19] = CreateDynamicObject(973, 77.7438, -1305.5852, 12.5743, 0.0000, -2.2000, 55.0999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[20] = CreateDynamicObject(973, 90.9461, -1292.6286, 13.3410, 0.0000, -2.8999, 40.8999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[21] = CreateDynamicObject(973, 98.1218, -1286.6105, 13.8156, 0.0000, -2.8999, 38.9999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[22] = CreateDynamicObject(973, 105.5798, -1281.0255, 14.2886, 0.0000, -2.8999, 34.6000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[23] = CreateDynamicObject(973, 113.9952, -1278.2851, 14.7860, 0.0000, -2.8999, 1.1000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[24] = CreateDynamicObject(973, 104.0957, -1275.6842, 14.3362, 0.0000, 2.6999, -145.6000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[25] = CreateDynamicObject(973, 109.4736, -1268.8126, 14.7677, 0.0000, 2.6999, -110.7000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[26] = CreateDynamicObject(973, 112.7854, -1260.0480, 15.2096, 0.0000, 2.6999, -110.7000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[27] = CreateDynamicObject(973, 80.0690, -1261.2658, 14.1520, 0.0000, -0.7999, 35.4000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[28] = CreateDynamicObject(973, 74.3018, -1268.1235, 14.0214, 0.0000, -0.7999, 64.3000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[29] = CreateDynamicObject(973, 70.2345, -1276.5750, 13.8904, 0.0000, -0.7999, 64.3000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[30] = CreateDynamicObject(973, 89.3757, -1254.9698, 14.3091, 0.0000, -0.7999, 33.5000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[31] = CreateDynamicObject(973, 97.1958, -1249.7939, 14.4701, 0.0000, -1.0999, 33.5000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[32] = CreateDynamicObject(973, 105.6843, -1247.0206, 14.6520, 0.0000, -1.0999, 2.8000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[33] = CreateDynamicObject(973, 114.2848, -1244.2025, 14.8329, 0.0000, -1.0999, 33.5000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[34] = CreateDynamicObject(973, 122.5100, -1242.9604, 15.0161, 0.0000, -1.0999, -16.3999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[35] = CreateDynamicObject(973, 77.0246, -1256.9196, 14.3072, 0.0000, 0.6999, -145.9001, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[36] = CreateDynamicObject(973, 84.7918, -1251.6605, 14.4731, 0.0000, 1.3999, -145.9001, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[37] = CreateDynamicObject(973, 92.5482, -1246.4094, 14.6385, 0.0000, 0.5999, -145.9001, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[38] = CreateDynamicObject(973, 98.1853, -1239.6208, 14.7458, 0.0000, 0.5999, -113.3001, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[39] = CreateDynamicObject(973, 68.5897, -1260.0202, 14.1872, 0.0000, 0.6999, -173.7001, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrie

    //ZOLL3
    object_tollStations[40] = CreateDynamicObject(4638, -88.2897, -904.8724, 18.2335, 0.0000, 4.8000, 63.9000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //paypark_lan01
    object_tollStations[41] = CreateDynamicObject(4638, -79.7021, -912.1043, 18.2171, 0.0000, -4.0000, -115.7997, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //paypark_lan01
    object_tollStations[42] = CreateDynamicObject(973, -93.1125, -913.8204, 18.1240, 0.0000, -4.6999, -130.3999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[43] = CreateDynamicObject(973, -82.6404, -918.8504, 17.9335, 0.0000, 4.8997, 76.4999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[44] = CreateDynamicObject(973, -85.1151, -897.3777, 16.4993, 0.0000, -5.7999, -102.3998, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[45] = CreateDynamicObject(973, -74.7322, -902.3571, 16.3381, 0.0000, 4.8997, 51.5998, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[46] = CreateDynamicObject(973, -88.1091, -906.1087, 17.3616, 0.0000, -4.6999, -115.3999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[47] = CreateDynamicObject(973, -79.5754, -910.1397, 17.1371, 0.0000, 4.8997, 64.5998, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier

    //ZOLL4
    object_tollStations[48] = CreateDynamicObject(4641, -969.4844, -327.5071, 36.7993, 0.0000, 0.0000, 78.5998, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //paypark_lan04
    object_tollStations[49] = CreateDynamicObject(4641, -960.1766, -332.0859, 36.7993, 0.0000, 0.0000, -101.0998, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //paypark_lan04
    object_tollStations[50] = CreateDynamicObject(973, -972.1134, -334.2049, 36.5713, 0.0000, 0.0000, -100.6999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[51] = CreateDynamicObject(973, -970.3709, -324.9877, 36.5713, 0.0000, 0.0000, -100.6999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[52] = CreateDynamicObject(973, -973.8557, -343.4220, 36.5713, 0.0000, 0.0000, -100.6999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[53] = CreateDynamicObject(973, -968.6291, -315.7707, 36.5713, 0.0000, 0.0000, -100.6999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[54] = CreateDynamicObject(973, -957.9467, -327.6869, 36.2211, 0.0000, 0.0000, 78.6996, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[55] = CreateDynamicObject(973, -959.7122, -336.5578, 36.2211, 0.0000, 0.0000, 78.6996, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[56] = CreateDynamicObject(973, -970.4195, -307.4782, 36.5713, 0.0000, 0.0000, -54.9999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[57] = CreateDynamicObject(973, -961.5429, -345.7522, 36.2211, 0.0000, 0.0000, 78.6997, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[58] = CreateDynamicObject(973, -956.1466, -318.6951, 36.2211, 0.0000, 0.0000, 78.6996, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[59] = CreateDynamicObject(973, -952.0499, -310.8183, 36.4410, 0.0000, -2.6999, 46.2999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[60] = CreateDynamicObject(973, -978.8676, -349.8336, 36.5713, 0.0000, 0.0000, -155.4002, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[61] = CreateDynamicObject(973, -960.1781, -354.2810, 36.2212, 0.0000, 0.0000, 119.4000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier

    //ZOLL5
    object_tollStations[62] = CreateDynamicObject(973, -1262.5432, 968.5139, 44.7150, 0.0000, 0.0000, -114.4999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[63] = CreateDynamicObject(973, -1264.8615, 970.7904, 44.7151, 0.0000, 0.0000, 24.7000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[64] = CreateDynamicObject(4638, -1257.5008, 956.2531, 45.6191, 0.0000, 0.0000, -133.3000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //paypark_lan01
    object_tollStations[65] = CreateDynamicObject(973, -1261.6757, 951.5891, 44.9050, 0.0000, 1.6999, 60.6000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[66] = CreateDynamicObject(973, -1268.5633, 962.2156, 44.7150, 0.0000, 0.0000, -152.9998, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[67] = CreateDynamicObject(970, -1254.2564, 953.6062, 44.6495, 0.0000, 0.0000, -45.5000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_tollStations[68] = CreateDynamicObject(973, -1270.8054, 964.6029, 44.7150, 0.0000, 0.0000, 67.4001, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[69] = CreateDynamicObject(970, -1254.2564, 953.6062, 45.6395, 0.0000, 0.0000, -45.5000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_tollStations[70] = CreateDynamicObject(970, -1280.3999, 978.0861, 44.6630, 0.0000, 0.0000, -44.5000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_tollStations[71] = CreateDynamicObject(970, -1280.3999, 978.0861, 45.6330, 0.0000, 0.0000, -44.5000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_tollStations[72] = CreateDynamicObject(973, -1253.0770, 960.6354, 44.6013, 0.0000, 1.6999, 32.6000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[73] = CreateDynamicObject(1237, -1272.6470, 960.2780, 44.4608, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //strtbarrier01
    object_tollStations[74] = CreateDynamicObject(1237, -1260.6335, 972.8485, 44.0508, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //strtbarrier01
    object_tollStations[75] = CreateDynamicObject(4638, -1277.3817, 975.1455, 45.6491, 0.0000, 0.0000, 46.4999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //paypark_lan01
    object_tollStations[76] = CreateDynamicObject(973, -1281.7683, 970.8783, 44.9648, 0.0000, -2.5999, -146.5999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[77] = CreateDynamicObject(973, -1273.4323, 979.5726, 44.5442, 0.0000, -2.2000, -120.6999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier

    //ZOLL6
    object_tollStations[78] = CreateDynamicObject(973, -2667.8244, 1274.4438, 55.2588, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[79] = CreateDynamicObject(973, -2686.3347, 1274.4533, 55.2588, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[80] = CreateDynamicObject(19134, -2679.4633, 1270.1530, 59.9472, 0.0000, 180.0000, 90.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ArrowType5
    object_tollStations[81] = CreateDynamicObject(19134, -2677.2321, 1270.1530, 59.9472, 0.0000, 180.0000, 90.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ArrowType5
    object_tollStations[82] = CreateDynamicObject(19134, -2674.8801, 1270.1430, 59.9472, 0.0000, 180.0000, 90.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ArrowType5
    object_tollStations[83] = CreateDynamicObject(19134, -2692.6135, 1279.1024, 59.9472, 0.0000, 180.0000, 90.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ArrowType5
    object_tollStations[84] = CreateDynamicObject(19134, -2695.0739, 1279.1024, 59.9472, 0.0000, 180.0000, 90.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ArrowType5
    object_tollStations[85] = CreateDynamicObject(19134, -2697.4143, 1279.1024, 59.9472, 0.0000, 180.0000, 90.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ArrowType5

    //ZOLL7
    object_tollStations[86] = CreateDynamicObject(4638, -173.5056, 368.7872, 12.7825, 0.0000, 0.0000, 74.8999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //paypark_lan01
    object_tollStations[87] = CreateDynamicObject(4638, -163.2553, 362.9766, 12.7825, 0.0000, 0.0000, -105.8999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //paypark_lan01
    object_tollStations[88] = CreateDynamicObject(973, -164.3850, 356.8477, 11.9105, 0.0000, 0.0000, 92.2999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[89] = CreateDynamicObject(973, -161.1870, 368.8588, 11.9105, 0.0000, 0.0000, 58.7999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[90] = CreateDynamicObject(973, -175.4907, 362.9841, 11.9105, 0.0000, 0.0000, -121.9999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[91] = CreateDynamicObject(973, -172.3786, 374.8708, 11.9105, 0.0000, 0.0000, -87.6999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier

    //ZOLL8
    object_tollStations[92] = CreateDynamicObject(4639, 528.7304, 471.3728, 19.6360, 0.0000, 0.0000, -54.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //paypark_lan02
    object_tollStations[93] = CreateDynamicObject(4639, 517.6807, 467.0162, 19.6360, 0.0000, 0.0000, 125.8999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //paypark_lan02
    object_tollStations[94] = CreateDynamicObject(973, 532.6129, 466.4129, 18.7281, 0.0000, 0.0000, 139.4999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[95] = CreateDynamicObject(973, 525.4859, 476.5396, 18.7281, 0.0000, 0.0000, 110.2999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[96] = CreateDynamicObject(973, 513.7104, 471.8090, 18.7281, 0.0000, 0.0000, -36.8000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[97] = CreateDynamicObject(973, 520.7729, 461.7516, 18.7281, 0.0000, 0.0000, -73.5000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier

    //ZOLL9
    object_tollStations[98] = CreateDynamicObject(970, 1738.6262, 521.6348, 27.4928, 0.0000, 0.0000, -20.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_tollStations[99] = CreateDynamicObject(7033, 1736.3959, 515.6359, 31.8036, -3.1000, 0.0000, -20.3000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgnhsegate02
    object_tollStations[100] = CreateDynamicObject(973, 1745.4581, 500.1199, 28.6691, 0.0000, 2.4999, 95.0999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[101] = CreateDynamicObject(973, 1746.2922, 490.7859, 29.0782, 0.0000, 2.4999, 95.0999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[102] = CreateDynamicObject(973, 1719.4741, 509.9206, 28.6721, 0.0000, -2.4999, -136.7997, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[103] = CreateDynamicObject(1250, 1740.4736, 521.0422, 27.4154, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //smashbarpost
    object_tollStations[104] = CreateDynamicObject(1250, 1749.3569, 517.4368, 27.3554, 0.0000, 0.0000, 250.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //smashbarpost
    object_tollStations[105] = CreateDynamicObject(973, 1712.6430, 503.5058, 29.0813, 0.0000, -2.4999, -136.7997, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[106] = CreateDynamicObject(973, 1731.5699, 504.8169, 28.7336, 0.0000, 2.4999, 79.5999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[107] = CreateDynamicObject(973, 1733.0908, 504.2654, 28.7398, 0.0000, -2.4999, -119.2997, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[108] = CreateDynamicObject(973, 1747.3649, 509.1493, 28.2416, 0.0000, 2.4999, 70.9999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[109] = CreateDynamicObject(1250, 1727.8140, 525.6479, 27.4154, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //smashbarpost
    object_tollStations[110] = CreateDynamicObject(973, 1748.8078, 513.3338, 28.0484, 0.0000, 2.4999, 70.9999, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[111] = CreateDynamicObject(1250, 1736.7062, 522.0385, 27.3554, 0.0000, 0.0000, 250.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //smashbarpost
    object_tollStations[112] = CreateDynamicObject(973, 1724.0010, 517.7824, 28.2534, 0.0000, -2.4999, -110.2998, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[113] = CreateDynamicObject(973, 1725.5344, 521.9334, 28.0602, 0.0000, -2.4999, -110.2998, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[114] = CreateDynamicObject(1250, 1736.7042, 522.0364, 26.9155, 0.0000, 0.0000, 250.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //smashbarpost
    object_tollStations[115] = CreateDynamicObject(1250, 1740.4715, 521.0402, 26.9355, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //smashbarpost
    object_tollStations[116] = CreateDynamicObject(1250, 1749.3548, 517.4348, 26.6854, 0.0000, 0.0000, 250.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //smashbarpost
    object_tollStations[117] = CreateDynamicObject(1250, 1727.8120, 525.6458, 26.9154, 0.0000, 0.0000, 70.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //smashbarpost
    object_tollStations[118] = CreateDynamicObject(973, 1753.0778, 521.2570, 27.4308, 0.0000, 3.5999, 46.2000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[119] = CreateDynamicObject(973, 1759.5571, 528.0136, 26.8418, 0.0000, 3.5999, 46.2000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[120] = CreateDynamicObject(973, 1726.9246, 530.7320, 27.3570, 0.0000, -2.8999, -82.7000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[121] = CreateDynamicObject(973, 1725.7329, 540.0245, 26.8824, 0.0000, -2.8999, -82.7000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_tollStations[122] = CreateDynamicObject(1250, 1730.4224, 499.7070, 28.7215, 21.0999, 0.0000, 160.0000, VW_MAIN, MAPS_TOLLSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //smashbarpost
}
#include <YSI\y_hooks>

// Global interior define
#define MAPS_NINEDEMONSEXTERIOR_INTERIOR      0
#define MAPS_NINEDEMONSINTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Nine Demons points
#define NINEDEMONS_INTERIOR_ENTER_COORDS        758.3181, 374.9177, 23.1962
#define NINEDEMONS_INTERIOR_EXIT_COORDS         743.6995, 383.8317, 948.5355
#define NINEDEMONS_INTERIOR_ENTER_FACING        270.0
#define NINEDEMONS_INTERIOR_EXIT_FACING         90.5

// Map variables
new object_nineDemonsExterior[41];

hook OnPlayerConnect(playerid) {
    // Remove RenderWare objects
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {

}

hook OnGameModeInit() {
    // Vehicles

    // Pickups
    // Actors

    // Objects
    object_nineDemonsExterior[0] = CreateDynamicObject(1410, 752.1041, 386.4375, 22.8125, 3.1414, 0.0000, 8.6913, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[1] = CreateDynamicObject(1410, 759.3817, 387.6729, 22.8125, 3.1414, 0.0000, 8.6148, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[2] = CreateDynamicObject(3276, 779.1259, 391.9841, 22.1965, 0.0000, -4.0000, 195.6172, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[3] = CreateDynamicObject(3276, 813.0324, 349.3297, 19.5398, 0.0000, 5.0000, 83.4906, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[4] = CreateDynamicObject(3276, 813.7481, 371.0299, 19.0419, 3.1414, 0.0000, 91.9859, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[5] = CreateDynamicObject(3276, 810.4708, 381.3851, 18.9409, 3.1414, 0.0000, 126.5391, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[6] = CreateDynamicObject(3276, 801.9168, 389.0195, 19.3469, 3.0000, -4.0000, 150.5637, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[7] = CreateDynamicObject(1407, 771.2645, 390.0036, 22.5659, 3.1414, 3.0000, 11.9131, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[8] = CreateDynamicObject(2115, 760.3549, 377.5455, 22.1688, 0.0000, 0.0000, 10.1611, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[9] = CreateDynamicObject(1575, 760.9204, 377.3959, 22.9153, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[10] = CreateDynamicObject(1575, 760.3604, 377.3800, 22.9253, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[11] = CreateDynamicObject(1575, 760.6646, 377.3641, 23.0473, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[12] = CreateDynamicObject(336, 759.6481, 376.7632, 22.8761, 0.0000, -169.8998, -75.5170, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[13] = CreateDynamicObject(3014, 760.4600, 377.5220, 22.3924, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[14] = CreateDynamicObject(3052, 761.3748, 377.7828, 23.0834, 0.0000, 0.0000, 312.9519, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[15] = CreateDynamicObject(19918, 761.2645, 377.6549, 22.1781, 0.0000, 0.0000, 42.1612, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[16] = CreateDynamicObject(12987, 763.4937, 379.7377, 22.3381, 0.0000, 0.0000, 12.2257, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[17] = CreateDynamicObject(19922, 765.3187, 376.0101, 22.2175, 0.0000, 0.0000, 12.5000, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    object_nineDemonsExterior[18] = CreateDynamicObject(1431, 763.5891, 377.3215, 22.7504, 0.0000, 0.0000, 278.2697, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[19] = CreateDynamicObject(1280, 767.8908, 374.1119, 22.6236, 0.0000, 0.0000, 192.6782, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    object_nineDemonsExterior[20] = CreateDynamicObject(355, 766.3471, 376.3753, 22.9799, 84.5998, -79.0998, 13.1997, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ak47
    object_nineDemonsExterior[21] = CreateDynamicObject(348, 765.7128, 375.8428, 23.0076, 82.3999, 0.0000, -29.5000, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_nineDemonsExterior[22] = CreateDynamicObject(2040, 765.4677, 375.6466, 23.1112, 0.0000, 0.0000, -117.1996, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M1
    object_nineDemonsExterior[23] = CreateDynamicObject(358, 765.5330, 376.2391, 23.0053, 82.4996, -122.6996, 0.0000, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sniper
    object_nineDemonsExterior[24] = CreateDynamicObject(2359, 764.1411, 375.7626, 23.2059, 0.0000, 0.0000, 84.3999, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_c5
    object_nineDemonsExterior[25] = CreateDynamicObject(1215, 760.5504, 332.6770, 19.7199, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_nineDemonsExterior[26] = CreateDynamicObject(1223, 756.4237, 354.4959, 18.7052, 0.0000, 0.0000, -60.0998, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_nineDemonsExterior[27] = CreateDynamicObject(1215, 748.7598, 330.6968, 19.7199, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_nineDemonsExterior[28] = CreateDynamicObject(1893, 760.0103, 378.9382, 24.9871, 0.0000, 0.0000, 9.5999, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shoplight1
    object_nineDemonsExterior[29] = CreateDynamicObject(1223, 772.0045, 353.3634, 17.7252, 0.0000, 0.0000, 115.5000, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_nineDemonsExterior[30] = CreateDynamicObject(1223, 791.8344, 354.4400, 17.3451, 0.0000, 0.0000, 96.0998, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_nineDemonsExterior[31] = CreateDynamicObject(1223, 808.0598, 368.9970, 17.2252, 0.0000, 0.0000, 172.3999, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_nineDemonsExterior[32] = CreateDynamicObject(1223, 790.8673, 371.9967, 19.0151, 0.0000, 0.0000, -19.9999, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_nineDemonsExterior[33] = CreateDynamicObject(1223, 779.3479, 378.4992, 19.0951, 0.0000, 0.0000, 96.0998, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_nineDemonsExterior[34] = CreateDynamicObject(1223, 796.8449, 391.2825, 18.0352, 0.0000, 0.0000, -116.3998, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_nineDemonsExterior[35] = CreateDynamicObject(1223, 747.7655, 378.8724, 21.0750, 0.0000, 0.0000, 101.5000, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_nineDemonsExterior[36] = CreateDynamicObject(3785, 757.8566, 373.6571, 24.5941, 0.0000, 0.0000, 100.6998, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bulkheadlight
    object_nineDemonsExterior[37] = CreateDynamicObject(3785, 766.5062, 375.4967, 24.6641, 0.0000, 0.0000, 102.9000, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bulkheadlight
    object_nineDemonsExterior[38] = CreateDynamicObject(1223, 765.6060, 388.6069, 21.0652, 0.0000, 0.0000, -79.5998, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_nineDemonsExterior[39] = CreateDynamicObject(1223, 744.9395, 347.3016, 18.4552, 0.0000, 0.0000, -14.8999, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_nineDemonsExterior[40] = CreateDynamicObject(335, 760.5045, 377.7874, 22.9417, 90.0000, 90.0000, -34.0000, VW_MAIN, MAPS_NINEDEMONSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //knifecur
}

#include <YSI\y_hooks>

// Global interior define
#define MAPS_CARRENTALSTATIONS_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 130.0;

// Car rental stations
#define CARRENTALSTATIONS_COORDS_AMMU         1335.2418, -1250.3275, 14.5218
#define CARRENTALSTATIONS_COORDS_IDLEWOOD     2079.6814, -1772.0012, 14.5999
#define CARRENTALSTATIONS_COORDS_NOOB    766.9273,  -1338.6477, 13.5313
#define CARRENTALSTATIONS_COORDS_NOOB2   894.4424,  -1413.3195, 14.2623
#define CARRENTALSTATIONS_COORDS_LSBEACH      949.5546,  -1770.8784, 15.1941
#define CARRENTALSTATIONS_COORDS_BSN          1187.8488, -1046.9332, 32.8951
#define CARRENTALSTATIONS_COORDS_LV           1580.6417,  2610.4766, 11.8126
#define CARRENTALSTATIONS_COORDS_LSSUD		  597.6666,  -1574.3059, 17.2997

// Map variables
new object_carRentalStations[65];
new text3D_carRentalStations[8];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // 3DTextLabels
    text3D_carRentalStations[0] = _:CreateDynamic3DTextLabel("CarSharing-Station\n" COLOR_HEX_WHITE "Steige zum Mieten in ein beliebiges Fahrzeug ein!", COLOR_BLUE, CARRENTALSTATIONS_COORDS_AMMU, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CARRENTALSTATIONS_INTERIOR);
    text3D_carRentalStations[1] = _:CreateDynamic3DTextLabel("CarSharing-Station\n" COLOR_HEX_WHITE "Steige zum Mieten in ein beliebiges Fahrzeug ein!", COLOR_BLUE, CARRENTALSTATIONS_COORDS_IDLEWOOD, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CARRENTALSTATIONS_INTERIOR);
    //text3D_carRentalStations[2] = _:CreateDynamic3DTextLabel("CarSharing-Station\n" COLOR_HEX_WHITE "Steige zum Mieten in ein beliebiges Fahrzeug ein!", COLOR_BLUE, CARRENTALSTATIONS_COORDS_NOOB, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CARRENTALSTATIONS_INTERIOR);
    text3D_carRentalStations[3] = _:CreateDynamic3DTextLabel("CarSharing-Station\n" COLOR_HEX_WHITE "Steige zum Mieten in ein beliebiges Fahrzeug ein!", COLOR_BLUE, CARRENTALSTATIONS_COORDS_NOOB2, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CARRENTALSTATIONS_INTERIOR);
    text3D_carRentalStations[4] = _:CreateDynamic3DTextLabel("CarSharing-Station\n" COLOR_HEX_WHITE "Steige zum Mieten in ein beliebiges Fahrzeug ein!", COLOR_BLUE, CARRENTALSTATIONS_COORDS_LSBEACH, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CARRENTALSTATIONS_INTERIOR);
    text3D_carRentalStations[5] = _:CreateDynamic3DTextLabel("CarSharing-Station\n" COLOR_HEX_WHITE "Steige zum Mieten in ein beliebiges Fahrzeug ein!", COLOR_BLUE, CARRENTALSTATIONS_COORDS_BSN, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CARRENTALSTATIONS_INTERIOR);
    text3D_carRentalStations[6] = _:CreateDynamic3DTextLabel("CarSharing-Station\n" COLOR_HEX_WHITE "Steige zum Mieten in ein beliebiges Fahrzeug ein!", COLOR_BLUE, CARRENTALSTATIONS_COORDS_LV, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CARRENTALSTATIONS_INTERIOR);
	text3D_carRentalStations[7] = _:CreateDynamic3DTextLabel("CarSharing-Station\n" COLOR_HEX_WHITE "Steige zum Mieten in ein beliebiges Fahrzeug ein!", COLOR_BLUE, CARRENTALSTATIONS_COORDS_LSSUD, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CARRENTALSTATIONS_INTERIOR);

    // Objects
    object_carRentalStations[0] = CreateDynamicObject(970, 1179.93176, -1047.23828, 31.32900, 0.00000, 0.00000, 90.37750, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[1] = CreateDynamicObject(970, 1182.02917, -1049.29382, 31.33340, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[2] = CreateDynamicObject(970, 1186.13879, -1049.29968, 31.34800, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[3] = CreateDynamicObject(970, 1187.85535, -1047.24329, 31.34050, 0.00000, 0.00000, 89.44410, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[4] = CreateDynamicObject(970, 1190.24915, -1049.30737, 31.34730, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[5] = CreateDynamicObject(970, 1194.38599, -1049.30054, 31.33198, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[6] = CreateDynamicObject(970, 1196.45374, -1047.23315, 31.32360, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[7] = CreateDynamicObject(970, 2081.34302, -1764.23950, 13.04130, 0.00000, 0.00000, 343.69641, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[8] = CreateDynamicObject(970, 2078.78442, -1765.64783, 13.04090, 0.00000, 0.00000, 74.32000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[9] = CreateDynamicObject(970, 2077.67407, -1769.67505, 13.04320, 0.00000, 0.00000, 74.81210, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[10] = CreateDynamicObject(970, 2079.22314, -1771.90332, 13.04530, 0.00000, 0.00000, 344.95236, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[11] = CreateDynamicObject(970, 2076.53784, -1773.63245, 13.04840, 0.00000, -0.02000, 73.12640, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[12] = CreateDynamicObject(970, 2075.35815, -1777.59131, 13.04660, 0.00000, 0.00000, 73.51505, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[13] = CreateDynamicObject(970, 2076.77148, -1780.09668, 13.04440, 0.00000, 0.00000, 344.69409, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[14] = CreateDynamicObject(3666, 2078.74927, -1780.65601, 13.06500, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[15] = CreateDynamicObject(3666, 2081.13965, -1772.41736, 13.07130, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[16] = CreateDynamicObject(3666, 2083.29907, -1764.81604, 13.07040, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[17] = CreateDynamicObject(3666, 1179.92822, -1045.14307, 31.37620, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[18] = CreateDynamicObject(3666, 1187.89807, -1045.20691, 31.38490, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[19] = CreateDynamicObject(3666, 1196.45093, -1045.20142, 31.36530, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[20] = CreateDynamicObject(970, 957.68079, -1772.00391, 13.63180, 0.00000, 0.00000, 259.29901, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[21] = CreateDynamicObject(970, 956.01892, -1769.57715, 13.63450, 0.00000, 0.00000, 348.40799, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[22] = CreateDynamicObject(970, 951.98810, -1768.76514, 13.64330, 0.00000, 0.00000, 348.71530, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[23] = CreateDynamicObject(970, 949.64209, -1770.41870, 13.63950, 0.00000, 0.00000, 81.35970, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[24] = CreateDynamicObject(970, 947.93207, -1767.95667, 13.62350, 0.00000, 0.00000, 348.27704, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[25] = CreateDynamicObject(970, 943.90936, -1767.18481, 13.61560, 0.00000, 0.00000, 350.33157, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[26] = CreateDynamicObject(970, 941.53119, -1768.86487, 13.60470, 0.00000, 0.00000, 81.14670, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[27] = CreateDynamicObject(3666, 941.19360, -1770.87756, 13.39020, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[28] = CreateDynamicObject(3666, 949.34180, -1772.38879, 13.55410, 0.00000, -0.24000, -0.02000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[29] = CreateDynamicObject(4639, 938.90576, -1767.43774, 14.45360, 0.00000, 0.00000, 350.26144, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[30] = CreateDynamicObject(3666, 957.26892, -1774.00415, 13.64210, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[31] = CreateDynamicObject(4639, 1200.30688, -1047.94849, 32.29781, 0.00000, 0.00000, 180.43439, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[32] = CreateDynamicObject(4639, 2076.18604, -1783.24963, 14.16343, 0.00000, 0.00000, 74.80316, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[33] = CreateDynamicObject(970, 902.79480, -1413.80847, 12.81760, 0.00000, 0.00000, 90.39240, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[34] = CreateDynamicObject(970, 894.40088, -1413.82312, 12.70750, 0.00000, -0.02000, 89.33300, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[35] = CreateDynamicObject(970, 887.07959, -1413.81714, 12.73320, 0.00000, 0.00000, 268.63779, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[36] = CreateDynamicObject(3666, 902.78259, -1411.71936, 12.76466, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[37] = CreateDynamicObject(3666, 894.42316, -1411.82190, 12.62931, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[38] = CreateDynamicObject(3666, 887.14478, -1411.75232, 12.55729, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[39] = CreateDynamicObject(4639, 904.61530, -1414.49451, 13.76180, 0.00000, 360.00000, 179.37233, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[40] = CreateDynamicObject(970, 1334.73694, -1242.73608, 12.94919, 0.00000, 0.00000, 359.70853, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[41] = CreateDynamicObject(3666, 1336.81079, -1242.75415, 12.98800, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[42] = CreateDynamicObject(970, 1334.75842, -1250.30225, 12.96720, 0.00000, 0.00000, 359.57751, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[43] = CreateDynamicObject(3666, 1336.74133, -1250.29761, 13.00840, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[44] = CreateDynamicObject(970, 1334.70984, -1258.26086, 12.96730, 0.00000, 0.00000, 0.70910, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[45] = CreateDynamicObject(3666, 1336.75464, -1258.25110, 13.00840, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[46] = CreateDynamicObject(4639, 1333.88879, -1260.31287, 14.15495, 0.00000, 0.00000, 89.63667, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[47] = CreateDynamicObject(970, 1579.90894, 2602.31982, 10.28880, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[48] = CreateDynamicObject(970, 1577.83533, 2604.34961, 10.27560, 0.00000, 0.00000, 269.45831, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[49] = CreateDynamicObject(970, 1577.87622, 2608.48291, 10.28120, 0.00000, 0.00000, 90.11050, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[50] = CreateDynamicObject(970, 1579.93420, 2610.53174, 10.25800, 0.00000, 0.00000, 0.01950, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[51] = CreateDynamicObject(970, 1577.89648, 2612.57349, 10.27920, 0.00000, 0.00000, 89.38330, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[52] = CreateDynamicObject(970, 1577.91602, 2616.69141, 10.27910, 0.00000, 0.00000, 90.06078, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[53] = CreateDynamicObject(970, 1579.99707, 2618.74512, 10.25360, 0.00000, 0.00000, 359.88501, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[54] = CreateDynamicObject(3666, 1582.04102, 2618.75757, 10.34626, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[55] = CreateDynamicObject(3666, 1582.01270, 2610.53418, 10.28075, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[56] = CreateDynamicObject(3666, 1581.87891, 2602.31689, 10.20422, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[57] = CreateDynamicObject(4639, 1578.62842, 2621.25977, 11.46658, 0.00000, 0.00000, 90.30301, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_carRentalStations[58] = CreateDynamicObject(4639, 605.29828, -1573.11536, 16.92720,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[59] = CreateDynamicObject(970, 603.49866, -1574.19275, 15.74520,   -0.02000, 0.20000, 90.94000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[60] = CreateDynamicObject(970, 591.66766, -1574.19727, 15.74520,   0.02000, -0.04000, 90.96000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[61] = CreateDynamicObject(970, 597.63721, -1574.20825, 15.74520,   0.02000, -0.04000, 90.96000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[62] = CreateDynamicObject(3666, 603.54913, -1576.41492, 15.48730,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[63] = CreateDynamicObject(3666, 591.69379, -1576.42163, 15.48730,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_carRentalStations[64] = CreateDynamicObject(3666, 597.66046, -1576.43152, 15.48730,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_CARRENTALSTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}
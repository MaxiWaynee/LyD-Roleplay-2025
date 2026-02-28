#include <YSI\y_hooks>

// Global interior define
#define MAPS_OLDTIMERDEALERSHIP_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 200.0;
static Float:DRAWDISTANCE   = 180.0;

// Oldtimer dealership points
#define OLDTIMERDEALERSHIP_COORDS  902.5354, -945.0310, 40.9409

// Map variables
new object_oldtimerDealership[296];
new text3D_oldtimerDealership[1];
new actor_oldtimerDealership[1];

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 727, 893.2659, -916.9379, 41.6796, 0.10); // tree_hipoly04
    RemoveBuildingForPlayer(playerid, 727, 876.0469, -924.8829, 43.0625, 0.10); // tree_hipoly04
    RemoveBuildingForPlayer(playerid, 717, 888.5000, -942.6090, 40.4453, 0.10); // sm_bevhiltreepv
    RemoveBuildingForPlayer(playerid, 717, 896.1560, -942.6090, 41.4844, 0.10); // sm_bevhiltreepv
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
	// Map Icon
    CreateDynamicMapIcon(OLDTIMERDEALERSHIP_COORDS, 55, 0, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR);

    // 3DTextLabels
    text3D_oldtimerDealership[0] = _:CreateDynamic3DTextLabel("Autohaus - Oldtimer\n" COLOR_HEX_WHITE "Steige in ein beliebiges Fahrzeug deiner Wahl ein!", COLOR_BLUE, OLDTIMERDEALERSHIP_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_OLDTIMERDEALERSHIP_INTERIOR);

    // Actors
    actor_oldtimerDealership[0] = CreateDynamicActor(76, 884.4954, -926.4102, 42.4216, 188.5966, .worldid = VW_MAIN, .interiorid = MAPS_OLDTIMERDEALERSHIP_INTERIOR); // Rich saleswoman
    ApplyDynamicActorAnimation(actor_oldtimerDealership[0], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);

	// Objects
	object_oldtimerDealership[0] = CreateDynamicObject(19464, 913.8308, -944.9367, 40.2709, 0.0000, 0.0000, -83.3999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[0], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[1] = CreateDynamicObject(3935, 926.0872, -928.4506, 42.8885, 0.0000, 0.0000, 94.5998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //statue
	object_oldtimerDealership[2] = CreateDynamicObject(19464, 907.9697, -945.6145, 40.2807, 0.0000, 0.0000, -83.3999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[2], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[3] = CreateDynamicObject(19464, 897.5253, -946.4732, 40.2308, -0.0996, 0.0000, -92.1996, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[3], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[4] = CreateDynamicObject(19464, 919.7000, -944.3795, 40.2709, 0.0000, 0.0000, -87.4998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[4], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[5] = CreateDynamicObject(19464, 891.6546, -946.2631, 40.2410, -0.0996, 0.0000, -92.1996, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[5], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[6] = CreateDynamicObject(19464, 885.7686, -946.0371, 40.2513, -0.0996, 0.0000, -92.1996, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[6], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[7] = CreateDynamicObject(19464, 925.6115, -944.0919, 40.2709, 0.0000, 0.0000, -86.8999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[7], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[8] = CreateDynamicObject(19464, 879.8527, -945.9196, 40.2616, -0.0996, 0.0000, -90.1996, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[8], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[9] = CreateDynamicObject(19464, 873.9760, -946.0092, 40.2719, -0.0996, 0.0000, -87.9999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[9], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[10] = CreateDynamicObject(18980, 928.3963, -943.5784, 32.5713, 0.0000, 0.0000, 3.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_oldtimerDealership[10], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[11] = CreateDynamicObject(19464, 868.0665, -946.1522, 40.2821, -0.0996, 0.0000, -89.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[11], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[12] = CreateDynamicObject(19464, 862.1270, -946.2354, 40.2924, -0.0996, 0.0000, -89.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[12], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[13] = CreateDynamicObject(19464, 931.8502, -943.7244, 40.2709, 0.0000, 0.0000, -85.9999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[13], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[14] = CreateDynamicObject(19464, 937.7559, -943.3114, 40.2709, 0.0000, 0.0000, -85.9999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[14], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[15] = CreateDynamicObject(18980, 917.0543, -944.2221, 32.5713, 0.0000, 0.0000, 3.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_oldtimerDealership[15], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[16] = CreateDynamicObject(18980, 905.4942, -945.5612, 32.5713, 0.0000, 0.0000, 3.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_oldtimerDealership[16], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[17] = CreateDynamicObject(19464, 897.5332, -946.2733, 40.2308, -0.0996, 0.0000, -92.1996, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[17], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[18] = CreateDynamicObject(18980, 900.0374, -946.2661, 32.5713, 0.0000, 0.0000, 3.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_oldtimerDealership[18], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[19] = CreateDynamicObject(19464, 891.6624, -946.0634, 40.2410, -0.0996, 0.0000, -92.1996, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[19], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[20] = CreateDynamicObject(19464, 885.7764, -945.8474, 40.2513, -0.0996, 0.0000, -92.2995, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[20], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[21] = CreateDynamicObject(19464, 879.8546, -945.6395, 40.2616, -0.0996, 0.0000, -91.4998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[21], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[22] = CreateDynamicObject(19464, 873.9777, -945.8189, 40.2719, -0.0996, 0.0000, -85.1996, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_oldtimerDealership[22], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[23] = CreateDynamicObject(19463, 898.3366, -941.4901, 41.6304, -0.5999, 88.5998, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[23], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[24] = CreateDynamicObject(19353, 932.6243, -943.6679, 43.6487, 0.0000, 0.0000, -85.9000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[24], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[25] = CreateDynamicObject(19353, 935.8159, -943.4301, 43.6487, 0.0000, 0.0000, -85.9000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[25], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[26] = CreateDynamicObject(19353, 929.4304, -943.8781, 43.6487, 0.0000, 0.0000, -86.3000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[26], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[27] = CreateDynamicObject(8623, 916.6505, -934.3764, 42.3502, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush03_lvs
	object_oldtimerDealership[28] = CreateDynamicObject(3920, 930.9943, -943.5363, 44.1198, 0.0000, 0.2998, -176.3999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lib_veg3
	object_oldtimerDealership[29] = CreateDynamicObject(19463, 884.3256, -941.0689, 41.4598, -0.5999, 90.3999, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[29], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[30] = CreateDynamicObject(19463, 894.1704, -931.9381, 41.4636, -0.2998, 88.5998, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[30], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[31] = CreateDynamicObject(19463, 890.6865, -931.7008, 41.3763, -0.2998, 88.5998, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[31], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[32] = CreateDynamicObject(19463, 891.3258, -941.2700, 41.4524, -0.5999, 88.5998, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[32], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[33] = CreateDynamicObject(19463, 887.1929, -931.6058, 41.3582, -0.3998, 90.3999, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[33], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[34] = CreateDynamicObject(19463, 890.0291, -922.1624, 41.3502, 0.0000, 88.5998, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[34], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[35] = CreateDynamicObject(1232, 928.4251, -943.6422, 42.6257, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
	object_oldtimerDealership[36] = CreateDynamicObject(19463, 894.8209, -941.5167, 41.5424, -0.5999, 88.5998, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[36], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[37] = CreateDynamicObject(19463, 886.5214, -922.0020, 41.3111, -0.1999, 90.1996, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[37], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[38] = CreateDynamicObject(19463, 887.8336, -941.1942, 41.4393, -0.5999, 90.3999, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[38], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[39] = CreateDynamicObject(19353, 926.2186, -944.0662, 43.6487, 0.0000, 0.0000, -86.5998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[39], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[40] = CreateDynamicObject(18980, 888.4185, -945.8239, 32.5312, 0.0000, 0.0000, 3.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_oldtimerDealership[40], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[41] = CreateDynamicObject(18980, 877.9633, -945.5709, 32.5312, 0.0000, 0.0000, 3.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_oldtimerDealership[41], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[42] = CreateDynamicObject(19463, 873.9121, -941.2357, 41.5265, -0.5999, 90.3999, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[42], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[43] = CreateDynamicObject(1232, 917.0701, -944.4887, 42.5959, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
	object_oldtimerDealership[44] = CreateDynamicObject(1232, 905.5072, -945.7791, 42.5572, 0.0000, 0.0000, 4.8000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
	object_oldtimerDealership[45] = CreateDynamicObject(1232, 900.0471, -946.4290, 42.6072, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
	object_oldtimerDealership[46] = CreateDynamicObject(1232, 888.4265, -945.8994, 42.5671, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
	object_oldtimerDealership[47] = CreateDynamicObject(1232, 877.9862, -945.6895, 42.5671, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
	object_oldtimerDealership[48] = CreateDynamicObject(19463, 883.6671, -931.4912, 41.3804, -0.3998, 90.3999, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[48], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[49] = CreateDynamicObject(19463, 880.8389, -941.0925, 41.4818, -0.5999, 90.3999, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[49], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[50] = CreateDynamicObject(19353, 923.0426, -944.2019, 43.6487, 0.0000, 0.0000, -87.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[50], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[51] = CreateDynamicObject(19463, 880.1989, -931.4923, 41.4028, -0.3998, 90.3999, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[51], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[52] = CreateDynamicObject(19353, 919.8458, -944.3438, 43.6487, 0.0000, 0.0000, -87.4999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[52], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[53] = CreateDynamicObject(19463, 882.9970, -921.9141, 41.3133, -0.3998, 90.3999, 4.0000); //wall103
	object_oldtimerDealership[54] = CreateDynamicObject(19353, 916.6522, -944.6358, 43.6487, 0.0000, 0.0000, -83.6997, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[54], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[55] = CreateDynamicObject(19353, 913.4611, -944.9846, 43.6487, 0.0000, 0.0000, -83.4000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[55], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[56] = CreateDynamicObject(19353, 910.2719, -945.3530, 43.6487, 0.0000, 0.0000, -83.4000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[56], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[57] = CreateDynamicObject(19463, 877.3715, -941.1043, 41.5037, -0.5999, 90.3999, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[57], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[58] = CreateDynamicObject(19463, 876.7769, -931.7318, 41.4267, -0.3998, 90.3999, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[58], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[59] = CreateDynamicObject(19463, 873.3048, -931.9749, 41.4510, -0.3998, 90.3999, 4.0000); //wall103
	object_oldtimerDealership[60] = CreateDynamicObject(19353, 907.0618, -945.7141, 43.6487, 0.0000, 0.0000, -83.4000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[60], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[61] = CreateDynamicObject(19463, 870.4093, -941.3203, 41.5494, -0.5999, 90.3999, 4.0000); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[61], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[62] = CreateDynamicObject(3920, 918.4049, -944.3892, 44.0241, 0.0000, 0.2998, -174.5997, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lib_veg3
	object_oldtimerDealership[63] = CreateDynamicObject(19463, 866.9500, -941.4520, 41.5722, -0.5999, 90.3999, 4.0000); //wall103
	object_oldtimerDealership[64] = CreateDynamicObject(19353, 885.2891, -945.9738, 43.6487, 0.0000, 0.0000, -92.1997, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[64], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[65] = CreateDynamicObject(19353, 898.0291, -946.4882, 43.6487, 0.0000, 0.0000, -91.8998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[65], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[66] = CreateDynamicObject(19353, 894.8311, -946.3629, 43.6487, 0.0000, 0.0000, -91.6997, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[66], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[67] = CreateDynamicObject(19353, 891.6450, -946.1981, 43.6487, 0.0000, 0.0000, -92.1997, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[67], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[68] = CreateDynamicObject(3920, 912.2526, -944.9810, 44.0717, 0.0000, 0.2998, -172.7998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lib_veg3
	object_oldtimerDealership[69] = CreateDynamicObject(19353, 888.4675, -946.0759, 43.6487, 0.0000, 0.0000, -92.1997, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[69], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[70] = CreateDynamicObject(19445, 899.8775, -939.7702, 43.2038, 0.0000, 0.0000, 3.8998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[70], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_oldtimerDealership[71] = CreateDynamicObject(19353, 882.1088, -945.8914, 43.6487, 0.0000, 0.0000, -89.2998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[71], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[72] = CreateDynamicObject(19361, 899.3707, -933.3496, 43.1657, 0.0000, 0.0000, 3.7000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[72], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_oldtimerDealership[73] = CreateDynamicObject(19373, 894.7131, -933.7202, 48.5028, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[73], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[74] = CreateDynamicObject(3920, 893.3295, -946.2183, 44.0712, 0.0000, 0.2998, 178.3000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lib_veg3
	object_oldtimerDealership[75] = CreateDynamicObject(19445, 899.4411, -933.3651, 46.6439, 0.0000, 0.0000, 3.8998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[75], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[76] = CreateDynamicObject(19361, 899.0023, -926.9743, 46.6459, 0.0000, 0.0000, 3.9000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[76], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[77] = CreateDynamicObject(3920, 880.6859, -945.8029, 44.0648, 0.0000, 0.2998, 178.3000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lib_veg3
	object_oldtimerDealership[78] = CreateDynamicObject(3920, 870.8347, -945.7608, 44.1333, 0.0000, 0.2998, -177.2998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lib_veg3
	object_oldtimerDealership[79] = CreateDynamicObject(19361, 900.0930, -942.9766, 46.6459, 0.0000, 0.0000, 3.9000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[79], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[80] = CreateDynamicObject(18980, 864.7105, -945.7791, 32.6711, 0.0000, 0.0000, 3.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_oldtimerDealership[80], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_oldtimerDealership[81] = CreateDynamicObject(19445, 892.8098, -921.0100, 43.1138, 0.0000, 0.0000, -68.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[81], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_oldtimerDealership[82] = CreateDynamicObject(638, 898.3358, -924.0029, 42.1640, 0.0000, 0.0000, 3.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
	object_oldtimerDealership[83] = CreateDynamicObject(1232, 864.7459, -945.6895, 42.6571, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
	object_oldtimerDealership[84] = CreateDynamicObject(19445, 879.7589, -929.0800, 43.2038, 0.0000, 0.0000, -35.7999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[84], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_oldtimerDealership[85] = CreateDynamicObject(19445, 871.6790, -938.8939, 43.2038, 0.0000, 0.0000, -43.1999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[85], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_oldtimerDealership[86] = CreateDynamicObject(19353, 878.8353, -945.6765, 43.6487, 0.0000, 0.0000, -92.1997, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[86], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[87] = CreateDynamicObject(19353, 875.6574, -945.7929, 43.6487, 0.0000, 0.0000, -85.6997, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[87], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[88] = CreateDynamicObject(19353, 872.4522, -945.9738, 43.6487, 0.0000, 0.0000, -84.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[88], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[89] = CreateDynamicObject(19353, 869.2644, -946.1115, 43.6487, 0.0000, 0.0000, -89.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[89], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[90] = CreateDynamicObject(19353, 865.9744, -946.1591, 43.6487, 0.0000, 0.0000, -90.8000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
	SetDynamicObjectMaterial(object_oldtimerDealership[90], 0, 1419, "break_fence3", "ornatefence", 0xFFFFFFFF);
	object_oldtimerDealership[91] = CreateDynamicObject(19445, 879.7589, -929.0800, 46.6338, 0.0000, 0.0000, -35.7999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[91], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[92] = CreateDynamicObject(19445, 871.6790, -938.8939, 46.6338, 0.0000, 0.0000, -43.1999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[92], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[93] = CreateDynamicObject(19361, 875.9163, -934.2279, 46.6459, 0.0000, 0.0000, -39.7999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[93], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[94] = CreateDynamicObject(19361, 899.8748, -939.7741, 46.6459, 0.0000, 0.0000, 3.9000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[94], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[95] = CreateDynamicObject(19361, 868.3269, -943.9619, 43.1758, 0.0000, 0.0000, -3.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[95], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[96] = CreateDynamicObject(19361, 897.9246, -920.7758, 43.2056, 0.0000, 0.0000, 26.1998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[96], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[97] = CreateDynamicObject(19361, 886.9755, -923.3740, 43.1259, 0.0000, 0.0000, -67.9999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[97], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
// 	object_oldtimerDealership[98] = CreateDynamicObject(19872, 877.7033, -941.6188, 40.5219, -15.1997, 0.0000, -58.0000); //CarFixerRamp2
	// SetDynamicObjectMaterial(object_oldtimerDealership[98], 0, 11085, "crack_intkb", "ws_metalrafter1", 0xFFFFFFFF);
	object_oldtimerDealership[99] = CreateDynamicObject(19361, 898.7847, -923.7816, 46.6459, 0.0000, 0.0000, 3.9000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[99], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[100] = CreateDynamicObject(19361, 886.9755, -923.3740, 46.6156, 0.0000, 0.0000, -67.9999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[100], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[101] = CreateDynamicObject(19361, 884.0548, -924.5540, 46.6259, 0.0000, 0.0000, -67.9999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[101], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[102] = CreateDynamicObject(19445, 892.8098, -921.0100, 46.6138, 0.0000, 0.0000, -68.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[102], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[103] = CreateDynamicObject(19361, 897.9337, -920.7713, 46.6357, 0.0000, 0.0000, 27.2999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[103], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[104] = CreateDynamicObject(14877, 885.1146, -943.1586, 42.8981, 0.0000, 0.0000, 179.4998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //michelle-stairs
	SetDynamicObjectMaterial(object_oldtimerDealership[104], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[105] = CreateDynamicObject(638, 878.2183, -931.9445, 42.1640, 0.0000, 0.0000, -36.2999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
	object_oldtimerDealership[106] = CreateDynamicObject(638, 874.2368, -936.8883, 42.2439, 0.0000, 0.0000, -43.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
	object_oldtimerDealership[107] = CreateDynamicObject(1232, 888.4301, -945.7739, 42.5951, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
	object_oldtimerDealership[108] = CreateDynamicObject(1232, 917.0504, -944.2777, 42.5666, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
	object_oldtimerDealership[109] = CreateDynamicObject(1232, 900.0241, -946.3330, 42.5984, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
// 	object_oldtimerDealership[110] = CreateDynamicObject(19872, 872.4213, -941.2160, 40.3162, -8.7996, 0.0000, -58.0000); //CarFixerRamp2
	// SetDynamicObjectMaterial(object_oldtimerDealership[110], 0, 11085, "crack_intkb", "ws_metalrafter1", 0xFFFFFFFF);
	object_oldtimerDealership[111] = CreateDynamicObject(19445, 872.9733, -945.0734, 43.2038, 0.0000, 0.0000, -84.6997, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[111], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_oldtimerDealership[112] = CreateDynamicObject(19445, 882.5468, -944.7352, 43.2038, 0.0000, 0.0000, -91.3999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[112], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_oldtimerDealership[113] = CreateDynamicObject(19361, 868.3269, -943.9619, 46.6160, 0.0000, 0.0000, -3.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[113], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[114] = CreateDynamicObject(9833, 915.7052, -934.4229, 45.2582, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fountain_SFW
	object_oldtimerDealership[115] = CreateDynamicObject(19445, 892.1602, -944.7354, 43.2038, 0.0000, 0.0000, -88.9000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[115], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_oldtimerDealership[116] = CreateDynamicObject(3515, 916.2211, -934.4644, 41.3067, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgsfountain
	object_oldtimerDealership[117] = CreateDynamicObject(19361, 898.5750, -944.5258, 43.1758, 0.0000, 0.0000, -86.9999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[117], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_oldtimerDealership[118] = CreateDynamicObject(19463, 897.6677, -931.9337, 41.5499, -0.2998, 88.5998, 4.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[118], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[119] = CreateDynamicObject(1280, 920.0847, -943.7368, 42.1212, 0.0000, 0.0000, -87.9999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
	object_oldtimerDealership[120] = CreateDynamicObject(870, 923.3292, -931.3637, 39.6245, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
	object_oldtimerDealership[121] = CreateDynamicObject(878, 925.6599, -937.0441, 43.3847, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers02
	object_oldtimerDealership[122] = CreateDynamicObject(19361, 884.0548, -924.5540, 43.1557, 0.0000, 0.0000, -67.9999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[122], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[123] = CreateDynamicObject(19445, 882.5266, -944.7348, 46.6236, 0.0000, 0.0000, -91.3999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[123], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[124] = CreateDynamicObject(1280, 912.5803, -944.5275, 42.1212, 0.0000, 0.0000, -83.3999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
	object_oldtimerDealership[125] = CreateDynamicObject(1280, 922.1483, -928.6256, 42.0713, 0.0000, 0.0000, -173.3999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
	object_oldtimerDealership[126] = CreateDynamicObject(877, 926.6436, -928.5313, 43.3823, 0.0000, 0.0000, 84.3000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers04
	object_oldtimerDealership[127] = CreateDynamicObject(19445, 892.1502, -944.7357, 46.6338, 0.0000, 0.0000, -88.9000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[127], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[128] = CreateDynamicObject(19463, 896.9982, -922.3673, 41.5199, 0.0000, 88.5998, 4.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[128], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[129] = CreateDynamicObject(19361, 898.5750, -944.5258, 46.6357, 0.0000, 0.0000, -87.8999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[129], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
// 	object_oldtimerDealership[130] = CreateDynamicObject(19872, 882.5089, -929.9780, 39.8842, -5.4998, 0.0000, -120.8000); //CarFixerRamp2
	// SetDynamicObjectMaterial(object_oldtimerDealership[130], 0, 11085, "crack_intkb", "ws_metalrafter1", 0xFFFFFFFF);
	object_oldtimerDealership[131] = CreateDynamicObject(2125, 877.0529, -942.6362, 45.3655, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
	object_oldtimerDealership[132] = CreateDynamicObject(2125, 876.0830, -942.6362, 45.3655, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
// 	object_oldtimerDealership[133] = CreateDynamicObject(1685, 896.9243, -933.5278, 41.4580, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[133], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[134] = CreateDynamicObject(1685, 895.1981, -933.6334, 41.4519, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[134], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
	object_oldtimerDealership[135] = CreateDynamicObject(19445, 872.9733, -945.0734, 46.6138, 0.0000, 0.0000, -84.6997, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
	SetDynamicObjectMaterial(object_oldtimerDealership[135], 0, 17324, "cwsbarn", "des_redslats", 0xFFFFFFFF);
	object_oldtimerDealership[136] = CreateDynamicObject(14877, 889.3065, -943.4075, 42.9080, 179.7001, 0.1999, -2.2999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //michelle-stairs
	SetDynamicObjectMaterial(object_oldtimerDealership[136], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
// 	object_oldtimerDealership[137] = CreateDynamicObject(19872, 882.9584, -941.7446, 40.2136, -15.2996, 0.0000, -58.0000); //CarFixerRamp2
	// SetDynamicObjectMaterial(object_oldtimerDealership[137], 0, 11085, "crack_intkb", "ws_metalrafter1", 0xFFFFFFFF);
// 	object_oldtimerDealership[138] = CreateDynamicObject(1685, 893.4716, -933.7390, 41.4458, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[138], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[139] = CreateDynamicObject(1685, 893.5789, -935.4956, 41.4458, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[139], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[140] = CreateDynamicObject(1685, 895.2957, -935.3906, 41.4519, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[140], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[141] = CreateDynamicObject(1685, 897.0225, -935.2849, 41.4579, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[141], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[142] = CreateDynamicObject(1685, 893.6818, -937.2224, 42.1758, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[142], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[143] = CreateDynamicObject(1685, 895.3883, -937.1181, 42.1819, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[143], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[144] = CreateDynamicObject(1685, 897.1347, -937.0112, 42.1879, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[144], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[145] = CreateDynamicObject(1685, 897.2409, -938.7479, 42.1879, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[145], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[146] = CreateDynamicObject(1685, 895.5042, -938.8541, 42.1819, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[146], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[147] = CreateDynamicObject(1685, 893.7874, -938.9591, 42.1758, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[147], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[148] = CreateDynamicObject(1685, 893.8969, -940.6956, 41.4458, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[148], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[149] = CreateDynamicObject(1685, 894.0031, -942.4323, 41.4458, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[149], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[150] = CreateDynamicObject(1685, 895.6337, -940.5894, 41.4519, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[150], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[151] = CreateDynamicObject(1685, 897.3806, -940.4827, 41.4580, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[151], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[152] = CreateDynamicObject(1685, 897.4868, -942.2191, 41.4580, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[152], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
// 	object_oldtimerDealership[153] = CreateDynamicObject(1685, 895.7598, -942.3248, 41.4519, 0.0000, -0.1999, 3.4999); //blockpallet
	// SetDynamicObjectMaterial(object_oldtimerDealership[153], 0, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
	object_oldtimerDealership[154] = CreateDynamicObject(19361, 898.7528, -923.7901, 43.1657, 0.0000, 0.0000, 3.7000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[154], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_oldtimerDealership[155] = CreateDynamicObject(19361, 899.1655, -930.1765, 43.1657, 0.0000, 0.0000, 3.7000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
	SetDynamicObjectMaterial(object_oldtimerDealership[155], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	object_oldtimerDealership[156] = CreateDynamicObject(2773, 892.1486, -934.0972, 42.0257, 0.0000, 0.0000, 3.5999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	object_oldtimerDealership[157] = CreateDynamicObject(2773, 892.3197, -936.8131, 42.0457, 0.0000, 0.0000, 3.5999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	object_oldtimerDealership[158] = CreateDynamicObject(2773, 892.4956, -939.6080, 42.0858, 0.0000, 0.0000, 3.5999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	object_oldtimerDealership[159] = CreateDynamicObject(2773, 892.6726, -942.4229, 42.1058, 0.0000, 0.0000, 3.5999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	object_oldtimerDealership[160] = CreateDynamicObject(2773, 893.0863, -932.4221, 42.0758, 0.0000, 0.0000, -86.7998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	object_oldtimerDealership[161] = CreateDynamicObject(2773, 895.7921, -932.2709, 42.1258, 0.0000, 0.0000, -86.7998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	object_oldtimerDealership[162] = CreateDynamicObject(2773, 898.2583, -932.1333, 42.2057, 0.0000, 0.0000, -86.7998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	object_oldtimerDealership[163] = CreateDynamicObject(19463, 893.5394, -922.3477, 41.4356, 0.0000, 88.5998, 4.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall103
	SetDynamicObjectMaterial(object_oldtimerDealership[163], 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	object_oldtimerDealership[164] = CreateDynamicObject(19354, 870.6867, -942.3992, 44.9925, 0.0000, 90.4000, 45.9000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[164], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[165] = CreateDynamicObject(19354, 880.6220, -943.0426, 44.9393, 0.0000, 90.4000, -0.7998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[165], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[166] = CreateDynamicObject(19354, 880.0877, -936.6115, 44.9197, 0.0000, 90.4000, 51.1999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[166], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[167] = CreateDynamicObject(19354, 882.4133, -936.7321, 44.9267, 0.0000, 90.4000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[167], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[168] = CreateDynamicObject(19354, 873.1068, -939.8718, 44.9681, 0.0000, 90.4000, 46.7999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[168], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[169] = CreateDynamicObject(19354, 882.4122, -943.0673, 44.9267, 0.0000, 90.4000, -0.7998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[169], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[170] = CreateDynamicObject(19354, 877.6875, -934.6812, 44.9197, 0.0000, 90.4000, 51.1999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[170], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[171] = CreateDynamicObject(19354, 877.2498, -943.1350, 44.9630, 0.0000, 90.4000, 4.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[171], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[172] = CreateDynamicObject(19354, 870.3342, -943.6826, 45.0113, 0.0000, 90.4000, 4.4998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[172], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[173] = CreateDynamicObject(19354, 873.7863, -943.3211, 44.9870, 0.0000, 90.4000, 4.4998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[173], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[174] = CreateDynamicObject(19354, 882.4133, -939.9024, 44.9267, 0.0000, 90.4000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[174], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[175] = CreateDynamicObject(19354, 882.4133, -930.3424, 44.9267, 0.0000, 90.4000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[175], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[176] = CreateDynamicObject(19354, 879.7578, -931.9392, 44.8956, 0.0000, 90.4000, 54.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[176], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[177] = CreateDynamicObject(19354, 881.7979, -929.1207, 44.8712, 0.0000, 90.4000, 54.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[177], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[178] = CreateDynamicObject(19354, 882.4133, -933.5424, 44.9267, 0.0000, 90.4000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[178], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[179] = CreateDynamicObject(19354, 879.0203, -939.8934, 44.9509, 0.0000, 90.4000, 2.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[179], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[180] = CreateDynamicObject(19354, 875.5875, -940.0935, 44.9748, 0.0000, 90.4000, 4.3998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[180], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[181] = CreateDynamicObject(19354, 875.4666, -937.2901, 44.9436, 0.0000, 90.4000, 48.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[181], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[182] = CreateDynamicObject(19354, 880.6444, -932.7789, 44.8969, 0.0000, 90.4000, 54.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[182], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[183] = CreateDynamicObject(19354, 877.0578, -938.5560, 44.9427, 0.0000, 90.4000, 48.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[183], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[184] = CreateDynamicObject(2161, 868.7490, -944.5070, 45.0898, 0.0000, 0.0000, -93.2998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
	object_oldtimerDealership[185] = CreateDynamicObject(2161, 868.8270, -943.1596, 45.0898, 0.0000, 0.0000, -93.2998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
// 	object_oldtimerDealership[186] = CreateDynamicObject(19872, 895.8150, -922.5363, 40.0970, -8.7996, 0.0000, 124.3000); //CarFixerRamp2
	// SetDynamicObjectMaterial(object_oldtimerDealership[186], 0, 11085, "crack_intkb", "ws_metalrafter1", 0xFFFFFFFF);
	object_oldtimerDealership[187] = CreateDynamicObject(2638, 873.4251, -938.7711, 45.6915, 0.0000, 0.0000, -43.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_CHAIR2
	object_oldtimerDealership[188] = CreateDynamicObject(19354, 873.5955, -941.0167, 44.9715, 0.0000, 90.4000, 46.7999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
	SetDynamicObjectMaterial(object_oldtimerDealership[188], 0, 2823, "gb_kitchtake", "deep_red64", 0xFFFFFFFF);
	object_oldtimerDealership[189] = CreateDynamicObject(2638, 875.4221, -936.6668, 45.6915, 0.0000, 0.0000, -43.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_CHAIR2
	object_oldtimerDealership[190] = CreateDynamicObject(19173, 875.7711, -934.5668, 47.2776, 0.0000, 0.0000, 50.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
	object_oldtimerDealership[191] = CreateDynamicObject(2639, 877.3967, -934.6287, 45.6044, 0.0000, 0.0000, 136.5998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_CHAIR3
	object_oldtimerDealership[192] = CreateDynamicObject(2639, 871.5888, -940.7814, 45.6044, 0.0000, 0.0000, -44.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_CHAIR3
	object_oldtimerDealership[193] = CreateDynamicObject(2682, 876.4793, -935.6096, 46.0819, 0.0000, 0.0000, -43.1999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PIZZA_MENU
	object_oldtimerDealership[194] = CreateDynamicObject(2637, 876.4891, -935.6157, 45.4519, 0.0000, 0.0000, -42.9000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_TABLE2
	object_oldtimerDealership[195] = CreateDynamicObject(2637, 874.5150, -937.7398, 45.4519, 0.0000, 0.0000, -42.9000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_TABLE2
	object_oldtimerDealership[196] = CreateDynamicObject(2637, 872.4113, -940.0029, 45.4519, 0.0000, 0.0000, -42.9000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_TABLE2
	object_oldtimerDealership[197] = CreateDynamicObject(19173, 871.8696, -938.8585, 47.2725, 0.0000, 0.0000, 47.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
	object_oldtimerDealership[198] = CreateDynamicObject(2682, 874.5075, -937.7091, 46.0819, 0.0000, 0.0000, -43.1999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PIZZA_MENU
	object_oldtimerDealership[199] = CreateDynamicObject(2682, 872.3989, -939.9542, 46.0819, 0.0000, 0.0000, -43.1999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PIZZA_MENU
	object_oldtimerDealership[200] = CreateDynamicObject(3850, 882.7340, -928.0352, 45.4472, 0.0000, 0.0000, 53.6999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carshowbann_SFSX
	object_oldtimerDealership[201] = CreateDynamicObject(2592, 875.6488, -943.5581, 45.9502, 0.0000, 0.0000, -176.3999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ab_slotTable
	object_oldtimerDealership[202] = CreateDynamicObject(1541, 876.4765, -944.5888, 46.3143, 0.0000, 0.0000, 4.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_TAPS_1
	object_oldtimerDealership[203] = CreateDynamicObject(1541, 875.5003, -944.6754, 46.3143, 0.0000, 0.0000, 4.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_TAPS_1
	object_oldtimerDealership[204] = CreateDynamicObject(1543, 876.8897, -943.6911, 45.8573, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_B_2
	object_oldtimerDealership[205] = CreateDynamicObject(1543, 876.7296, -943.6911, 45.8573, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_B_2
	object_oldtimerDealership[206] = CreateDynamicObject(1543, 876.5595, -943.6911, 45.8573, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_B_2
	object_oldtimerDealership[207] = CreateDynamicObject(3850, 884.0571, -930.7716, 45.4571, 0.0000, 0.0000, -0.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carshowbann_SFSX
	object_oldtimerDealership[208] = CreateDynamicObject(3850, 884.0512, -934.2415, 45.4571, 0.0000, 0.0000, -0.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carshowbann_SFSX
	object_oldtimerDealership[209] = CreateDynamicObject(3850, 884.0451, -937.7213, 45.4571, 0.0000, 0.0000, -0.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carshowbann_SFSX
	object_oldtimerDealership[210] = CreateDynamicObject(3850, 884.0316, -939.9013, 45.4571, 0.0000, 0.0000, -0.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carshowbann_SFSX
	object_oldtimerDealership[211] = CreateDynamicObject(2125, 875.0625, -942.6962, 45.3655, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
	object_oldtimerDealership[212] = CreateDynamicObject(2125, 874.0419, -942.7963, 45.3655, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
	object_oldtimerDealership[213] = CreateDynamicObject(638, 898.6762, -930.2244, 42.1640, 0.0000, 0.0000, 3.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
	object_oldtimerDealership[214] = CreateDynamicObject(19373, 871.3010, -944.2025, 48.4816, 0.5999, 89.9999, 3.5999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[214], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[215] = CreateDynamicObject(1811, 884.8649, -927.5756, 41.8709, 0.0000, 0.0000, -73.3000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	object_oldtimerDealership[216] = CreateDynamicObject(19373, 898.8568, -943.7232, 48.4828, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[216], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[217] = CreateDynamicObject(19373, 895.4736, -943.9417, 48.4828, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[217], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[218] = CreateDynamicObject(1715, 884.3692, -925.6439, 41.3605, 0.0000, 0.0000, 4.3998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair2
	object_oldtimerDealership[219] = CreateDynamicObject(19373, 892.0852, -944.0545, 48.4828, 0.0000, 89.9999, -0.6000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[219], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[220] = CreateDynamicObject(19373, 888.6256, -944.0181, 48.4729, 0.0000, 89.9999, -0.6000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[220], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[221] = CreateDynamicObject(19373, 881.6262, -943.9450, 48.4828, 0.0000, 89.9999, -0.6000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[221], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[222] = CreateDynamicObject(19373, 885.1361, -943.9818, 48.4828, 0.0000, 89.9999, -0.6000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[222], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[223] = CreateDynamicObject(1549, 885.5144, -926.4326, 41.2939, 0.0000, 0.0000, 15.4998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_ASHTRAY_b
	object_oldtimerDealership[224] = CreateDynamicObject(19373, 898.6516, -940.5391, 48.4828, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[224], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[225] = CreateDynamicObject(19373, 870.0855, -942.0684, 48.4813, 0.0000, 89.9999, 51.6999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[225], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[226] = CreateDynamicObject(19373, 872.2484, -939.3295, 48.4813, 0.0000, 89.9999, 51.6999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[226], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[227] = CreateDynamicObject(19373, 874.4174, -936.5831, 48.4813, 0.0000, 89.9999, 51.6999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[227], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[228] = CreateDynamicObject(19373, 876.5805, -933.8441, 48.4813, 0.0000, 89.9999, 51.6999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[228], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[229] = CreateDynamicObject(19373, 878.7371, -931.1132, 48.4813, 0.0000, 89.9999, 51.6999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[229], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[230] = CreateDynamicObject(19373, 880.8942, -928.3822, 48.4813, 0.0000, 89.9999, 51.6999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[230], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[231] = CreateDynamicObject(19373, 883.0322, -925.6748, 48.4813, 0.0000, 89.9999, 51.6999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[231], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[232] = CreateDynamicObject(19373, 885.0706, -924.1458, 48.5214, 0.0000, 89.9999, 21.4999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[232], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[233] = CreateDynamicObject(19373, 888.2622, -922.8889, 48.4813, 0.0000, 89.9999, 21.4999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[233], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[234] = CreateDynamicObject(19373, 891.4815, -921.6204, 48.4813, 0.0000, 89.9999, 21.4999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[234], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[235] = CreateDynamicObject(19373, 894.7285, -920.3413, 48.4813, 0.0000, 89.9999, 21.4999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[235], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[236] = CreateDynamicObject(19373, 896.3416, -920.5150, 48.5013, 0.0000, 89.9999, -33.9000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[236], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[237] = CreateDynamicObject(19373, 897.4624, -922.2161, 48.4813, 0.0000, 89.9999, -80.5999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[237], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[238] = CreateDynamicObject(2162, 884.1801, -924.7575, 41.4413, 0.0000, 0.0000, 20.5000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
	object_oldtimerDealership[239] = CreateDynamicObject(19373, 897.6734, -925.4221, 48.4828, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[239], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[240] = CreateDynamicObject(19373, 897.8786, -928.5952, 48.4828, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[240], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[241] = CreateDynamicObject(19373, 898.0844, -931.7783, 48.4828, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[241], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[242] = CreateDynamicObject(19373, 898.2442, -934.2531, 48.5028, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[242], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[243] = CreateDynamicObject(19373, 898.4453, -937.3665, 48.4828, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[243], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[244] = CreateDynamicObject(2166, 884.7777, -926.4606, 41.4151, 0.0000, 0.0000, 108.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_2
	object_oldtimerDealership[245] = CreateDynamicObject(19373, 878.1267, -943.9085, 48.4828, 0.0000, 89.9999, -0.6000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[245], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[246] = CreateDynamicObject(19893, 884.8060, -926.5684, 42.1995, 0.0000, 0.0000, -148.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
	SetDynamicObjectMaterial(object_oldtimerDealership[246], 1, 10249, "ottos2_sfw", "ottos_pics_sfe", 0xFFFFFFFF);
	object_oldtimerDealership[247] = CreateDynamicObject(19172, 886.1508, -944.9129, 46.9762, 0.0000, 0.0000, -1.0999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(object_oldtimerDealership[247], 0,"haus", 90, "Arial", 120, 1, 0xFFFFFFFF, 0x0, 0);
	SetDynamicObjectMaterial(object_oldtimerDealership[247], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_oldtimerDealership[248] = CreateDynamicObject(2773, 902.0465, -920.3745, 42.1258, 0.0000, 0.0000, -178.1999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	object_oldtimerDealership[249] = CreateDynamicObject(2773, 902.1066, -922.2937, 42.1258, 0.0000, 0.0000, -178.1999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	object_oldtimerDealership[250] = CreateDynamicObject(19786, 884.1300, -924.4855, 43.9053, 0.0000, 0.0000, 21.9999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
	SetDynamicObjectMaterial(object_oldtimerDealership[250], 1, 10249, "ottos2_sfw", "ottos_pics_sfe", 0xFFFFFFFF);
	object_oldtimerDealership[251] = CreateDynamicObject(19373, 895.2174, -940.7597, 48.4827, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[251], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[252] = CreateDynamicObject(2773, 913.4448, -918.8568, 42.1258, 0.0000, 0.0000, -178.1999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	object_oldtimerDealership[253] = CreateDynamicObject(2773, 913.5648, -922.6851, 42.1258, 0.0000, 0.0000, -178.1999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	object_oldtimerDealership[254] = CreateDynamicObject(19172, 899.1115, -927.0944, 45.7882, 0.0000, 0.0000, 95.4000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(object_oldtimerDealership[254], 0,"Eingang", 90, "Arial", 22, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_oldtimerDealership[254], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_oldtimerDealership[255] = CreateDynamicObject(19172, 883.6912, -944.8659, 46.9762, 0.0000, 0.0000, -1.0999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(object_oldtimerDealership[255], 0,"Auto", 90, "Arial", 120, 1, 0xFFFFFFFF, 0x0, 0);
	SetDynamicObjectMaterial(object_oldtimerDealership[255], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_oldtimerDealership[256] = CreateDynamicObject(2773, 913.5042, -920.7562, 42.1258, 0.0000, 0.0000, -178.1999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	object_oldtimerDealership[257] = CreateDynamicObject(1692, 892.4111, -937.2044, 49.2809, 0.0000, 0.0000, 3.5999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //roofstuff18
	SetDynamicObjectMaterial(object_oldtimerDealership[257], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_oldtimerDealership[257], 2, 3902, "libertyhi3", "glass2_64", 0xFFFFFFFF);
	object_oldtimerDealership[258] = CreateDynamicObject(19172, 888.7401, -944.9627, 46.9762, 0.0000, 0.0000, -1.0999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(object_oldtimerDealership[258], 0,"-Old", 90, "Arial", 120, 1, 0xFFFFFFFF, 0x0, 0);
	SetDynamicObjectMaterial(object_oldtimerDealership[258], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_oldtimerDealership[259] = CreateDynamicObject(19172, 890.9901, -945.0054, 46.9762, 0.0000, 0.0000, -1.0999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(object_oldtimerDealership[259], 0,"timer", 90, "Arial", 120, 1, 0xFFFFFFFF, 0x0, 0);
	SetDynamicObjectMaterial(object_oldtimerDealership[259], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_oldtimerDealership[260] = CreateDynamicObject(3850, 884.0512, -934.2415, 45.4571, 0.0000, 0.0000, -0.0998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carshowbann_SFSX
	object_oldtimerDealership[261] = CreateDynamicObject(19373, 887.7485, -934.1804, 48.5028, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[261], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[262] = CreateDynamicObject(1692, 891.9661, -930.1286, 49.2809, 0.0000, 0.0000, 3.5999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //roofstuff18
	SetDynamicObjectMaterial(object_oldtimerDealership[262], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_oldtimerDealership[262], 2, 3902, "libertyhi3", "glass2_64", 0xFFFFFFFF);
	object_oldtimerDealership[263] = CreateDynamicObject(19373, 891.2307, -933.9450, 48.5028, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[263], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[264] = CreateDynamicObject(19172, 899.1115, -927.0944, 46.3983, 0.0000, 0.0000, 95.4000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(object_oldtimerDealership[264], 0,"Autohaus-Oldtimer", 90, "Arial", 26, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_oldtimerDealership[264], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_oldtimerDealership[265] = CreateDynamicObject(19373, 887.0960, -937.4080, 48.5028, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[265], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[266] = CreateDynamicObject(19373, 887.3012, -940.5806, 48.4729, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[266], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[267] = CreateDynamicObject(19373, 891.7446, -940.9841, 48.4827, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[267], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[268] = CreateDynamicObject(19373, 888.2619, -941.2091, 48.4827, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[268], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[269] = CreateDynamicObject(19373, 894.2775, -926.6743, 48.5027, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[269], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[270] = CreateDynamicObject(19373, 890.7946, -926.8994, 48.5027, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[270], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[271] = CreateDynamicObject(19373, 874.7243, -943.9876, 48.4816, 0.5999, 89.9999, 3.5999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[271], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[272] = CreateDynamicObject(19373, 887.3020, -927.1251, 48.5027, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[272], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[273] = CreateDynamicObject(19373, 894.3447, -923.5335, 48.5127, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[273], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[274] = CreateDynamicObject(19373, 890.8718, -923.7578, 48.5127, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[274], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[275] = CreateDynamicObject(19373, 887.3991, -923.9821, 48.5127, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[275], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[276] = CreateDynamicObject(19373, 884.2720, -933.7238, 48.5028, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[276], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[277] = CreateDynamicObject(19373, 880.8228, -934.6176, 48.5129, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[277], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[278] = CreateDynamicObject(19373, 884.4760, -936.8767, 48.5028, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[278], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[279] = CreateDynamicObject(19373, 884.7940, -941.7854, 48.5228, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[279], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[280] = CreateDynamicObject(19373, 884.6123, -938.9711, 48.4828, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[280], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[281] = CreateDynamicObject(19373, 881.2396, -940.9027, 48.5027, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[281], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[282] = CreateDynamicObject(19373, 877.7368, -941.1290, 48.5027, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[282], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[283] = CreateDynamicObject(19373, 874.2650, -941.3538, 48.5027, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[283], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[284] = CreateDynamicObject(19373, 886.6201, -930.3662, 48.5027, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[284], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[285] = CreateDynamicObject(19373, 883.7990, -927.3516, 48.5327, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[285], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[286] = CreateDynamicObject(19373, 883.1575, -930.5899, 48.4928, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[286], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[287] = CreateDynamicObject(19373, 886.7390, -932.2019, 48.4828, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[287], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[288] = CreateDynamicObject(19373, 869.5906, -943.9287, 48.4756, 0.5999, 89.9999, 3.5999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[288], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[289] = CreateDynamicObject(19373, 869.6140, -944.2987, 48.5017, 0.5999, 89.9999, 3.5999, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[289], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[290] = CreateDynamicObject(19373, 872.0897, -941.4943, 48.4728, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[290], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[291] = CreateDynamicObject(19373, 880.6239, -931.5343, 48.4929, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[291], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[292] = CreateDynamicObject(19373, 881.0266, -937.7713, 48.5028, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[292], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[293] = CreateDynamicObject(19373, 877.5642, -937.9951, 48.5028, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[293], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[294] = CreateDynamicObject(19373, 875.5584, -938.1245, 48.4528, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[294], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
	object_oldtimerDealership[295] = CreateDynamicObject(19373, 877.9310, -934.8449, 48.5028, 0.0000, 89.9999, 3.6998, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall021
	SetDynamicObjectMaterial(object_oldtimerDealership[295], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0xFFFFFFFF);
}

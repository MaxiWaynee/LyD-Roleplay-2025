#include <YSI\y_hooks>

// Global interior define
#define MAPS_AIRPORTLS_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Airport LS points
#define AIRPORTLS_JOBSKIN_POINT             1893.2450, -2328.8833, 13.5469
#define AIRPORTLS_PAINTJOB_POINT            1798.4768, -2423.4924, 13.5547
#define AIRPORTLS_REPAIR_POINT              1819.9427, -2400.1108, 13.5547
#define AIRPORTLS_PLANE_DEALERSHIP_POINT    1841.7158, -2568.3242, 13.5469

// Map variables
new object_airportLs[21];
new pickup_airportLs[3];
new text3D_airportLs[3];
new vehicle_airportLs[18];

hook OnPlayerConnect(playerid) {
	// ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Map Icons
    CreateDynamicMapIcon(AIRPORTLS_PLANE_DEALERSHIP_POINT, 5, 0, VW_MAIN, MAPS_AIRPORTLS_INTERIOR);

	// Pickups
	pickup_airportLs[0] = CreateDynamicPickup(1275, 1, AIRPORTLS_JOBSKIN_POINT, VW_MAIN, MAPS_AIRPORTLS_INTERIOR); // Job skin
    pickup_airportLs[1] = CreateDynamicPickup(1239, 1, AIRPORTLS_PAINTJOB_POINT, VW_MAIN, MAPS_AIRPORTLS_INTERIOR); // Flugzeuglackiererei
    pickup_airportLs[2] = CreateDynamicPickup(1239, 1, AIRPORTLS_REPAIR_POINT, VW_MAIN, MAPS_AIRPORTLS_INTERIOR); // Flugzeug-Reparatur

    // 3DTextLabels
    text3D_airportLs[0] = _:CreateDynamic3DTextLabel("Arbeitskleidung für Piloten\n" COLOR_HEX_WHITE "Tippe /Jobkleidung", COLOR_YELLOW, AIRPORTLS_JOBSKIN_POINT, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_AIRPORTLS_INTERIOR); // Job skin point
    text3D_airportLs[1] = _:CreateDynamic3DTextLabel("Flugzeuglackiererei\n" COLOR_HEX_ORANGE "Preis: $5.000\n" COLOR_HEX_WHITE "Tippe /Flugzeugfarbe", COLOR_YELLOW, AIRPORTLS_PAINTJOB_POINT, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_AIRPORTLS_INTERIOR); // Flugzeuglackiererei
    text3D_airportLs[2] = _:CreateDynamic3DTextLabel("Flugzeug-Reparatur\n" COLOR_HEX_WHITE "Tippe /Flugzeugrepair", COLOR_YELLOW, AIRPORTLS_REPAIR_POINT, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_AIRPORTLS_INTERIOR); // Flugzeug Reparatur

    // Vehicles
	vehicle_airportLs[0] = AddStaticVehicleEx(593, 1989.8000, -2382.1000, 15.8000, 90.0000, 0, 1, 60 * 10); //Dodo
	vehicle_airportLs[1] = AddStaticVehicleEx(593, 1874.4000, -2288.6999, 15.8000, 270.0000, 0, 1, 60 * 10); //Dodo
	vehicle_airportLs[2] = AddStaticVehicleEx(593, 1989.5000, -2315.2998, 15.8000, 90.0000, 0, 1, 60 * 10); //Dodo
	vehicle_airportLs[3] = AddStaticVehicleEx(553, 1922.3994, -2245.0996, 15.8000, 180.0000, 0, 1, 60 * 10); //Nevada
	vehicle_airportLs[4] = AddStaticVehicleEx(553, 1992.7014, -2254.7300, 14.8799, 119.9558, 0, 1, 60 * 10); //Nevada
	vehicle_airportLs[5] = AddStaticVehicleEx(553, 1990.7866, -2442.7192, 14.8776, 88.9283, 0, 1, 60 * 10); //Nevada
	vehicle_airportLs[6] = AddStaticVehicleEx(519, 1738.6254, -2443.9441, 14.4781, 178.9727, 0, 1, 60 * 10); //Shamal
	vehicle_airportLs[7] = AddStaticVehicleEx(519, 1640.6844, -2440.9424, 14.4741, 182.0059, 0, 1, 60 * 10); //Shamal
	vehicle_airportLs[8] = AddStaticVehicleEx(577, 1900.8926, -2390.1277, 13.4547, 90.6319, 0, 1, 60 * 10); //AT400
	
	// Objects
    object_airportLs[0] = CreateDynamicObject(3465,1792.59997559,-2428.60009766,13.89999962,0.00000000,0.00000000,354.25000000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //object(vegspetrolpump) (1)
    object_airportLs[1] = CreateDynamicObject(3287,1791.09997559,-2423.39990234,17.29999924,0.00000000,0.00000000,354.00000000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //object(cxrf_oiltank) (1)
    object_airportLs[2] = CreateDynamicObject(3287,1790.40002441,-2430.30004883,17.29999924,0.00000000,0.00000000,353.99597168, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //object(cxrf_oiltank) (2)
    object_airportLs[3] = CreateDynamicObject(3465,1792.00000000,-2434.60009766,13.89999962,0.00000000,0.00000000,353.74645996, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //object(vegspetrolpump) (2)
    object_airportLs[4] = CreateDynamicObject(3465,1793.19995117,-2422.19995117,13.89999962,0.00000000,0.00000000,355.99865723, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //object(vegspetrolpump) (3)
    object_airportLs[5] = CreateDynamicObject(3934,1797.19995117,-2435.39990234,12.60000038,0.00000000,0.00000000,354.00000000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //object(helipad01) (1)
    object_airportLs[6] = CreateDynamicObject(3934,1798.59997559,-2423.50000000,12.60000038,0.00000000,0.00000000,353.99597168, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //object(helipad01) (2)
    object_airportLs[7] = CreateDynamicObject(10832, 1468.06104, -2407.57617, 14.02800, 0.00000, 0.00000, 137.61520, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_airportLs[8] = CreateDynamicObject(3934, 1819.8819, -2399.9238, 12.5397, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_airportLs[9] = CreateDynamicObject(19815, 1819.8889, -2390.0454, 14.2303, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToolBoard1
    object_airportLs[10] = CreateDynamicObject(19464, 1820.8887, -2389.9272, 12.7691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    object_airportLs[11] = CreateDynamicObject(19899, 1816.7089, -2390.6867, 12.5468, 0.0000, 0.0000, -41.7000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToolCabinet1
    object_airportLs[12] = CreateDynamicObject(19900, 1823.4523, -2390.3732, 13.4212, 0.0000, 180.0000, 0.0000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToolCabinet2
    object_airportLs[13] = CreateDynamicObject(19921, 1821.4660, -2390.6049, 13.4003, 0.0000, 0.0000, -30.2000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneToolBox1
    object_airportLs[14] = CreateDynamicObject(11687, 1821.5791, -2390.4064, 12.5434, 0.0000, 0.0000, -13.3000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CBarStool1
    object_airportLs[15] = CreateDynamicObject(19893, 1817.3651, -2390.0617, 13.7976, 0.0000, 0.0000, 10.8000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    object_airportLs[16] = CreateDynamicObject(18633, 1816.3281, -2391.1174, 13.8194, 1.4000, 90.0000, 90.0000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GTASAWrench1
    object_airportLs[17] = CreateDynamicObject(19627, 1816.0424, -2391.4819, 13.8040, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Wrench1
    object_airportLs[18] = CreateDynamicObject(19921, 1816.3435, -2391.4284, 14.2603, 0.0000, 0.0000, 55.5999, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CutsceneToolBox1
    object_airportLs[19] = CreateDynamicObject(19903, 1822.4952, -2390.3881, 12.5393, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MechanicComputer1
    object_airportLs[20] = CreateDynamicObject(1437, 1815.4636, -2392.1694, 11.6241, 0.0000, 0.0000, -41.7000, VW_MAIN, MAPS_AIRPORTLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_LADDER_2
}

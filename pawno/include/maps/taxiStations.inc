#include <YSI\y_hooks>

// Global interior define
#define MAPS_TAXISTATIONS_INTERIOR      0

// Taxi stations in LS points
#define TAXISTATIONS_JOBSKIN_POINT_CITYHALL     1501.3168, -1664.8496, 13.4684
#define TAXISTATIONS_JOBSKIN_POINT_BUSSTATION   1272.3879, -1353.3357, 13.5069

// Map variables
/*new pickup_taxiStations[1];
new text3D_taxiStations[1];
new actor_taxiStations[1];
new vehicle_taxiStations[6];*/

new pickup_taxiStations[2];
new text3D_taxiStations[2];
new actor_taxiStations[2];
new vehicle_taxiStations[10];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
    // Pickups
    pickup_taxiStations[0] = CreateDynamicPickup(1275, 1, TAXISTATIONS_JOBSKIN_POINT_CITYHALL, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR); // Job clothes point
    pickup_taxiStations[0] = CreateDynamicPickup(1275, 1, TAXISTATIONS_JOBSKIN_POINT_BUSSTATION, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR); // Job clothes point

    // 3DTextLabels
    text3D_taxiStations[0] = _:CreateDynamic3DTextLabel("Arbeitskleidung für Taxifahrer\n" COLOR_HEX_WHITE "Tippe /Jobkleidung", COLOR_YELLOW, TAXISTATIONS_JOBSKIN_POINT_CITYHALL, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_TAXISTATIONS_INTERIOR); // Job clothes
    text3D_taxiStations[0] = _:CreateDynamic3DTextLabel("Arbeitskleidung für Taxifahrer\n" COLOR_HEX_WHITE "Tippe /Jobkleidung", COLOR_YELLOW, TAXISTATIONS_JOBSKIN_POINT_BUSSTATION, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_TAXISTATIONS_INTERIOR); // Job clothes
    

    actor_taxiStations[0] = CreateDynamicActor(189, 1271.5378, -1350.7891, 13.5032, 271.0947, .worldid = VW_MAIN, .interiorid = MAPS_TAXISTATIONS_INTERIOR); // Greeting woman
    ApplyDynamicActorAnimation(actor_taxiStations[0], "GANGS", "leanIDLE", 4.0, 1, 0, 0, 0, 0);
    
    // Vehicles
    vehicle_taxiStations[0] = AddStaticVehicleEx(420, 1276.6396, -1375.7363, 13.0149, 179.8286, 6, 6, 60*10); // Taxicar1
    vehicle_taxiStations[1] = AddStaticVehicleEx(438, 1276.5221, -1365.5522, 13.2643, 180.2328, 6, 6, 60*10); // Taxicar1
    vehicle_taxiStations[2] = AddStaticVehicleEx(420, 1276.4287, -1355.7947, 13.1203, 179.3606, 6, 6, 60*10); // Taxicar1
    vehicle_taxiStations[3] = AddStaticVehicleEx(420, 1276.6139, -1320.3938, 13.1200, 180.2275, 6, 6, 60*10); // Taxicar1
    vehicle_taxiStations[4] = AddStaticVehicleEx(438, 1276.5392, -1310.1168, 13.3321, 180.3863, 6, 6, 60*10); // Taxicar1
    vehicle_taxiStations[5] = AddStaticVehicleEx(420, 1276.4485, -1299.5356, 13.1214, 180.5707, 6, 6, 60*10); // Taxicar1
    vehicle_taxiStations[6] = AddStaticVehicleEx(420, 1485.0638, -1661.3295, 13.2482, 178.9796, 6, 6, 60*10); // Taxi Stadthalle
	vehicle_taxiStations[7] = AddStaticVehicleEx(420, 1488.9866, -1661.3267, 13.2483, 179.0140, 6, 6, 60*10); // Taxi Stadthalle
	vehicle_taxiStations[8] = AddStaticVehicleEx(438, 1494.0458, -1660.9277, 13.4706, 181.0724, 6, 6, 60*10); // Taxi Stadthalle
	vehicle_taxiStations[9] = AddStaticVehicleEx(438, 1497.7656,- 1660.9489, 13.4721, 181.1496, 6, 6, 60*10); // Taxi Stadthalle
}

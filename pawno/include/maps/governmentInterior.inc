#include <YSI\y_hooks>

// Global interior define
#define MAPS_GOVERNMENTEXTERIOR_INTERIOR      0
#define MAPS_GOVERNMENTINTERIOR_INTERIOR      3

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Government points
#define GOVERNMENT_INTERIOR_SPAWN_POINT               345.7072, 162.2307, 1025.7964 // + 0.5
#define GOVERNMENT_INTERIOR_SPAWN_POINT_FACING        270.0
#define GOVERNMENT_INTERIOR_DUTY_POINT                349.5995, 162.2307, 1025.7964

// Map variables
new object_governmentInterior[2];

hook OnPlayerConnect(playerid) {
	// ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) { 
    
            /*else if (IsPlayerInRangeOfPoint(playerid, 2.0, GOVERNMENT_ROOF_ENTER_COORDS)) { // Roof
            SetPlayerPosEx(playerid, GOVERNMENT_ROOF_EXIT_COORDS, MAPS_GOVERNMENTEXTERIOR_INTERIOR, VW_MAIN);
            SetPlayerFacingAngle(playerid, GOVERNMENT_ROOF_EXIT_FACING);
            SetCameraBehindPlayer(playerid);
            
            return 1;
        } else if (IsPlayerInRangeOfPoint(playerid, 2.0, GOVERNMENT_GARAGE_ENTER_COORDS)) { // Garage
            SetPlayerPosEx(playerid, GOVERNMENT_GARAGE_EXIT_COORDS, MAPS_GOVERNMENTEXTERIOR_INTERIOR, VW_MAIN);
            SetPlayerFacingAngle(playerid, GOVERNMENT_GARAGE_EXIT_FACING);
            SetCameraBehindPlayer(playerid);
            
            return 1;
        }*/

	return 1;
}

hook OnGameModeInit() {    
	// Pickups
	// Objects
	object_governmentInterior[0] = CreateDynamicObject(18756, 370.6662, 164.4160, 1026.6489, 0.0000, 0.0000, 0.0000, VW_GOVERNMENTINTERIOR, MAPS_GOVERNMENTINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_governmentInterior[1] = CreateDynamicObject(18757, 370.6662, 160.4193, 1026.6489, 0.0000, 0.0000, 0.0000, VW_GOVERNMENTINTERIOR, MAPS_GOVERNMENTINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}
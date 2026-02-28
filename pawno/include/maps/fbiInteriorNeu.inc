#include <YSI\y_hooks>


#define MAPS_FBINEU_INTERIOR 0
// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 150.0;

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
	//F.B.I 
	CreateDynamicObject(19325,243.13,119.49,1005.35, 0.00,-10.00,90.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19325,249.74,119.49,1005.35, 0.00,-10.00,90.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19325,239.62,110.83,1003.08, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19325,253.19,115.90,1003.08, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19325,232.88,123.96,1010.50, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19303,214.70,112.62,999.31, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19304,215.55,112.58,1001.14, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19302,216.46,112.67,999.32, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19302,220.40,112.63,999.32, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19303,218.64,112.63,999.31, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19304,219.51,112.63,1001.14, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19302,224.36,112.62,999.32, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19304,223.52,112.60,1001.14, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19303,222.63,112.62,999.31, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19302,228.27,112.62,999.32, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19303,226.52,112.61,999.31, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19304,227.40,112.60,1001.14, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19304,221.15,116.43,999.82, 0.00,90.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19304,222.79,116.48,999.82, 0.00,90.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19304,224.29,116.46,999.82, 0.00,90.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(19304,225.75,116.48,999.82, 0.00,90.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(1535,214.74,127.10,1002.20, 0.00,0.00,0.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	CreateDynamicObject(1535,213.63,117.02,1002.20, 0.00,0.00,90.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	
	CreateDynamicObject(1495,239.59,116.08,1002.21, 0.00,0.00,90.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//fbi innenraum tor 1
	CreateDynamicObject(1495,239.55,119.08,1002.21, 0.00,0.00,-90.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//fbi innenraum tor 1
	CreateDynamicObject(1495,253.19,110.57,1002.21, 0.00,0.00,-90.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//fbi innenraum tor 2
	CreateDynamicObject(1495,253.23,107.58,1002.21, 0.00,0.00,90.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//fbi innenraum tor 2
	CreateDynamicObject(1495,253.19,126.74,1002.21, 0.00,0.00,-90.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//fbi innenraum tor 3
	CreateDynamicObject(1495,253.23,123.75,1002.21, 0.00,0.00,90.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//fbi innenraum tor 3
	CreateDynamicObject(1495,239.59,123.58,1002.21, 0.00,0.00,90.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//fbi innenraum tor 4
	CreateDynamicObject(1495,239.56,126.58,1002.21, 0.00,0.00,-90.00, VW_MAIN, MAPS_FBINEU_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);//fbi innenraum tor 4

	}

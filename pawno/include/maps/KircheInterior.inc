#include <YSI\y_hooks>



//Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 150.0;


// Kirchen Points
#define KIRCHE_EXIT_POINT      700.05, -1327.01, -56.930
#define KIRCHE_ENTER_POINT     1765.14, -1767.16, 13.76
#define MAPS_KIRCHENINTERIOR_INTERIOR 0

new Kirchenint_object[131];


hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) 
{
    if (newkeys & KEY_SECONDARY_ATTACK) 
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.0, KIRCHE_EXIT_COORDS))
		{
			Streamer_UpdateEx(playerid, KIRCHE_ENTER_COORDS, VW_MAIN, STREAMER_TYPE_OBJECT);           
			SetPlayerVirtualWorld(playerid, VW_MAIN);
			SetPlayerInterior(playerid, 0);
			SetPlayerPos(playerid, KIRCHE_ENTER_COORDS);
			SetCameraBehindPlayer(playerid);
			return 1;
		}
    }
	return 1;
}
  


hook OnGameModeInit() 
{  
	//Kircheninterior mapped by Snoopy

	//bodenplatte
	Kirchenint_object[0] = CreateDynamicObject(10023,700.64,-1279.03,-49.64, 0.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[1] = CreateDynamicObject(9931,700.07,-1371.46,-42.55, 0.00,0.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[2] = CreateDynamicObject(3980,778.83,-1326.98,-51.68, 0.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[3] = CreateDynamicObject(3980,621.27,-1337.40,-51.68, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[4] = CreateDynamicObject(19379,1545.41,-1639.78,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[5] = CreateDynamicObject(19379,1545.41,-1630.17,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[6] = CreateDynamicObject(19379,1545.43,-1620.58,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[7] = CreateDynamicObject(19379,1545.44,-1611.10,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[8] = CreateDynamicObject(19379,1534.91,-1639.72,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[9] = CreateDynamicObject(19379,1534.92,-1630.14,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[10] = CreateDynamicObject(19379,1534.96,-1620.58,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[11] = CreateDynamicObject(19379,1534.98,-1611.01,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[12] = CreateDynamicObject(19379,1524.66,-1639.25,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[13] = CreateDynamicObject(19379,1524.49,-1627.30,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[14] = CreateDynamicObject(19379,1524.60,-1617.51,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[15] = CreateDynamicObject(3980,657.15,-1297.89,-52.66, 0.00,0.00,181.06, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[16] = CreateDynamicObject(19380,1535.09,-1640.89,-41.55, 0.00,58.06,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[17] = CreateDynamicObject(19380,1535.10,-1631.53,-41.55, 0.00,58.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[18] = CreateDynamicObject(19380,1535.10,-1622.00,-41.55, 0.00,58.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[19] = CreateDynamicObject(19380,1535.09,-1612.52,-41.55, 0.00,58.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[20] = CreateDynamicObject(19380,1544.09,-1641.07,-41.55, 0.00,-58.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[21] = CreateDynamicObject(19380,1544.08,-1631.58,-41.55, 0.00,-58.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[22] = CreateDynamicObject(19380,1544.06,-1622.16,-41.55, 0.00,-58.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[23] = CreateDynamicObject(19380,1544.03,-1612.74,-41.55, 0.00,-58.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[24] = CreateDynamicObject(3980,723.57,-1286.41,-32.58, 180.00,0.00,181.06, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[25] = CreateDynamicObject(19377,695.64,-1343.19,-41.25, 0.00,58.06,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[26] = CreateDynamicObject(19377,704.50,-1343.63,-41.25, 0.00,-58.06,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[27] = CreateDynamicObject(19379,706.15,-1315.06,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[28] = CreateDynamicObject(19379,695.73,-1315.03,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[29] = CreateDynamicObject(19379,685.35,-1314.75,-58.03, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[30] = CreateDynamicObject(19377,695.62,-1333.56,-41.25, 0.00,58.06,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[31] = CreateDynamicObject(19377,695.60,-1324.04,-41.25, 0.00,58.06,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[32] = CreateDynamicObject(19377,695.61,-1314.58,-41.25, 0.00,58.06,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[33] = CreateDynamicObject(19377,704.52,-1334.08,-41.25, 0.00,-58.06,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[34] = CreateDynamicObject(19377,704.53,-1324.44,-41.25, 0.00,-58.06,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[35] = CreateDynamicObject(19377,704.52,-1314.83,-41.25, 0.00,-58.06,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[36] = CreateDynamicObject(2808,706.19,-1340.59,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[37] = CreateDynamicObject(2808,704.04,-1340.59,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[38] = CreateDynamicObject(2808,704.04,-1338.44,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[39] = CreateDynamicObject(2808,706.19,-1338.44,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[40] = CreateDynamicObject(2321,705.31,-1339.65,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[41] = CreateDynamicObject(2321,703.37,-1339.64,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[42] = CreateDynamicObject(2321,705.30,-1341.65,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[43] = CreateDynamicObject(2321,703.37,-1341.65,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[44] = CreateDynamicObject(2208,698.80,-1346.24,-57.94, 0.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[45] = CreateDynamicObject(2869,702.92,-1349.36,-57.94, 0.00,0.00,-37.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[46] = CreateDynamicObject(2869,697.36,-1349.35,-57.94, 0.00,0.00,-37.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[47] = CreateDynamicObject(1667,701.24,-1346.44,-56.98, 0.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[48] = CreateDynamicObject(2251,698.78,-1346.24,-56.24, 0.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[49] = CreateDynamicObject(3462,705.35,-1349.87,-56.50, 0.00,0.00,-90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[50] = CreateDynamicObject(3462,694.78,-1349.78,-56.50, 0.00,0.00,-90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[51] = CreateDynamicObject(19429,700.07,-1350.00,-46.95, 0.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[52] = CreateDynamicObject(19429,700.04,-1350.97,-46.01, 0.00,90.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[53] = CreateDynamicObject(8675,709.49,-1338.18,-62.41, 0.00,12.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[54] = CreateDynamicObject(2321,703.39,-1337.50,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[55] = CreateDynamicObject(2321,705.29,-1337.53,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[56] = CreateDynamicObject(2808,706.19,-1336.24,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[57] = CreateDynamicObject(2808,704.04,-1336.23,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[58] = CreateDynamicObject(7666,711.15,-1332.21,-50.94, 0.00,0.00,30.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[59] = CreateDynamicObject(2321,703.39,-1335.30,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[60] = CreateDynamicObject(2321,705.30,-1335.32,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[61] = CreateDynamicObject(2808,704.04,-1333.95,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[62] = CreateDynamicObject(2808,706.19,-1333.95,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[63] = CreateDynamicObject(19446,700.01,-1337.42,-58.02, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[64] = CreateDynamicObject(19446,700.01,-1327.87,-58.02, 0.00,90.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[65] = CreateDynamicObject(2321,705.30,-1333.05,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[66] = CreateDynamicObject(2321,703.39,-1333.06,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[67] = CreateDynamicObject(2808,704.04,-1331.79,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[68] = CreateDynamicObject(2808,706.19,-1331.79,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[69] = CreateDynamicObject(2321,703.39,-1330.88,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[70] = CreateDynamicObject(2321,705.30,-1330.88,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[71] = CreateDynamicObject(2808,704.04,-1329.65,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[72] = CreateDynamicObject(2808,706.19,-1329.65,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[73] = CreateDynamicObject(2321,703.39,-1328.70,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[74] = CreateDynamicObject(2321,705.30,-1328.70,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[75] = CreateDynamicObject(7666,688.94,-1332.21,-50.94, 0.00,0.00,210.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[76] = CreateDynamicObject(11489,709.20,-1332.28,-58.88, 0.00,0.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[77] = CreateDynamicObject(2808,704.04,-1327.55,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[78] = CreateDynamicObject(2808,706.19,-1327.55,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[79] = CreateDynamicObject(2321,703.39,-1326.64,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[80] = CreateDynamicObject(2321,705.30,-1326.64,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[81] = CreateDynamicObject(3061,701.66,-1325.80,-56.79, 0.00,0.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[82] = CreateDynamicObject(3061,698.39,-1325.73,-56.79, 0.00,0.00,-90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[83] = CreateDynamicObject(2321,695.00,720.00,-1341.00, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[84] = CreateDynamicObject(2321,695.00,2111.00,-1341.00, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[85] = CreateDynamicObject(2321,695.28,-1341.65,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[86] = CreateDynamicObject(2808,696.17,-1340.59,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[87] = CreateDynamicObject(2808,693.99,-1340.59,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[88] = CreateDynamicObject(2321,693.31,-1341.65,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[89] = CreateDynamicObject(2321,695.28,-1339.64,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[90] = CreateDynamicObject(2321,693.31,-1339.64,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[91] = CreateDynamicObject(2808,696.17,-1338.44,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[92] = CreateDynamicObject(2808,694.01,-1338.44,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[93] = CreateDynamicObject(2321,695.28,-1337.50,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[94] = CreateDynamicObject(2321,693.34,-1337.51,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[95] = CreateDynamicObject(2808,696.17,-1336.23,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[96] = CreateDynamicObject(2808,696.17,-1333.95,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[97] = CreateDynamicObject(2808,696.17,-1331.79,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[98] = CreateDynamicObject(2808,696.17,-1329.65,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[99] = CreateDynamicObject(2808,696.17,-1327.55,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[100] = CreateDynamicObject(2808,694.01,-1336.23,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[101] = CreateDynamicObject(2808,694.03,-1333.95,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[102] = CreateDynamicObject(2808,694.03,-1331.80,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[103] = CreateDynamicObject(2808,694.01,-1329.66,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[104] = CreateDynamicObject(2808,694.03,-1327.55,-57.46, 0.00,0.00,180.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[105] = CreateDynamicObject(2321,695.28,-1335.28,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[106] = CreateDynamicObject(2321,693.35,-1335.29,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[107] = CreateDynamicObject(2321,695.30,-1333.00,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[108] = CreateDynamicObject(2321,693.36,-1333.01,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[109] = CreateDynamicObject(2321,693.38,-1330.86,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[110] = CreateDynamicObject(2321,695.26,-1330.87,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[111] = CreateDynamicObject(2321,695.26,-1328.73,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[112] = CreateDynamicObject(2321,693.36,-1328.72,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[113] = CreateDynamicObject(2321,693.36,-1326.60,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[114] = CreateDynamicObject(2321,695.26,-1326.60,-57.52, 90.00,0.00,0.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[115] = CreateDynamicObject(8675,694.38,-1338.19,-62.41, 0.00,12.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[116] = CreateDynamicObject(2025,708.86,-1347.32,-58.29, 0.00,0.00,-90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[117] = CreateDynamicObject(2025,691.20,-1347.93,-58.29, 0.00,0.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[118] = CreateDynamicObject(11489,690.72,-1332.28,-58.88, 0.00,0.00,-90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[119] = CreateDynamicObject(11489,690.72,-1342.09,-58.88, 0.00,0.00,-90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[120] = CreateDynamicObject(11489,709.20,-1342.33,-58.88, 0.00,0.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[121] = CreateDynamicObject(3525,690.94,-1337.31,-52.50, 0.00,0.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[122] = CreateDynamicObject(3525,690.98,-1347.52,-52.50, 0.00,0.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[123] = CreateDynamicObject(3525,690.94,-52.50,-52.50, 0.00,0.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[124] = CreateDynamicObject(3525,709.21,-1337.31,-52.50, 0.00,0.00,-90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[125] = CreateDynamicObject(3525,709.16,-1327.21,-52.50, 0.00,0.00,-90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[126] = CreateDynamicObject(3525,690.91,-1327.21,-52.50, 0.00,0.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[127] = CreateDynamicObject(3525,709.15,-1347.76,-52.50, 0.00,0.00,-90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[128] = CreateDynamicObject(2869,700.15,-1346.01,-57.72, 0.00,0.00,-37.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[129] = CreateDynamicObject(3061,699.90,-1325.80,-56.79, 0.00,0.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	Kirchenint_object[130] = CreateDynamicObject(3061,700.68,-1325.78,-56.79, 0.00,0.00,90.00, MAPS_KIRCHENVW,MAPS_KIRCHENINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}
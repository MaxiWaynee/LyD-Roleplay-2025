#include <YSI\y_hooks>

// Global interior define
#define MAPS_KIRCHE_INTERIOR      0
#define MAPS_KIRCHENVW 2065

//Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 200.0;
static Float:DRAWDISTANCE   = 200.0;


// Bank Exterior LS Points
#define KIRCHE_EXIT_COORDS      700.05, -1327.01, -56.93
#define KIRCHE_EXIT_FACING      180.0
#define KIRCHE_ENTER_COORDS     1765.14, -1767.16, 13.76
#define KIRCHE_ENTER_FACING     180.0
#define KIRCHE_INTERIOR_EXTERIOR 0

// Map variables
//new object_Kirche[0];
new pickup_Kirche[1];
new kirchen_object[119];

hook OnPlayerConnect(playerid) {
RemoveBuildingForPlayer(playerid, 4025, 1777.8359, -1773.9063, 12.5234, 0.25);
RemoveBuildingForPlayer(playerid, 4070, 1719.7422, -1770.7813, 23.4297, 0.25);
RemoveBuildingForPlayer(playerid, 1531, 1724.7344, -1741.5000, 14.1016, 0.25);
RemoveBuildingForPlayer(playerid, 4215, 1777.5547, -1775.0391, 36.7500, 0.25);
RemoveBuildingForPlayer(playerid, 3986, 1719.7422, -1770.7813, 23.4297, 0.25);
RemoveBuildingForPlayer(playerid, 4019, 1777.8359, -1773.9063, 12.5234, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) 
{
    if (newkeys & KEY_SECONDARY_ATTACK) 
    {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, KIRCHE_ENTER_COORDS)) 
        { 
            Streamer_UpdateEx(playerid, KIRCHE_EXIT_COORDS, STREAMER_TYPE_OBJECT);
            SetPlayerVirtualWorld(playerid, MAPS_KIRCHENVW);
            SetPlayerInterior(playerid,KIRCHE_INTERIOR_EXTERIOR);
            SetPlayerPos(playerid, KIRCHE_EXIT_COORDS);
            SetPlayerFacingAngle(playerid, KIRCHE_EXIT_FACING);
            SetCameraBehindPlayer(playerid);
        }
    }
    return 1;
}

hook OnGameModeInit() {
// Map Icons
CreateDynamicMapIcon(KIRCHE_ENTER_COORDS, 52, 0, VW_MAIN, MAPS_KIRCHE_INTERIOR);
	
// Pickups
pickup_Kirche[0] = CreateDynamicPickup(19197, 1, KIRCHE_ENTER_COORDS, VW_MAIN); // Kircheinterior enter 
		
kirchen_object[0] = CreateDynamicObject(8678, 1771.45862, -1762.35425, 13.08090,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[1] = CreateDynamicObject(8675, 1779.73718, -1764.38245, 21.73350,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[2] = CreateDynamicObject(8676, 1734.15674, -1745.95093, 17.48020,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[3] = CreateDynamicObject(8679, 1771.71667, -1762.53430, 12.52865,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[4] = CreateDynamicObject(748, 1736.90332, -1804.43726, 12.50048,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[5] = CreateDynamicObject(1231, 1753.61060, -1744.82947, 15.49280,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[6] = CreateDynamicObject(1231, 1770.06494, -1744.82947, 15.49280,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[7] = CreateDynamicObject(1231, 1786.13391, -1744.82947, 15.49280,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[8] = CreateDynamicObject(1231, 1801.78320, -1744.82947, 15.49280,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[9] = CreateDynamicObject(1231, 1801.78320, -1779.45605, 15.49280,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[10] = CreateDynamicObject(1231, 1786.13391, -1779.45605, 15.49280,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[11] = CreateDynamicObject(1231, 1770.06494, -1779.45605, 15.49280,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[12] = CreateDynamicObject(1231, 1753.61060, -1779.45605, 15.49280,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[13] = CreateDynamicObject(1231, 1740.86206, -1779.44312, 15.49280,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[14] = CreateDynamicObject(3520, 1754.40112, -1750.16907, 12.74521,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[15] = CreateDynamicObject(3520, 1734.14575, -1749.80054, 12.74521,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[16] = CreateDynamicObject(3520, 1734.82275, -1773.09424, 12.74521,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[17] = CreateDynamicObject(3520, 1769.69873, -1779.30676, 12.74520,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[18] = CreateDynamicObject(3520, 1753.38367, -1779.40698, 12.74520,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[19] = CreateDynamicObject(3520, 1740.52808, -1779.35034, 12.74520,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[20] = CreateDynamicObject(3520, 1786.02063, -1779.33801, 12.74520,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[21] = CreateDynamicObject(3520, 1802.25012, -1779.28052, 12.74520,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[22] = CreateDynamicObject(3520, 1801.38904, -1744.41821, 12.74520,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[23] = CreateDynamicObject(3520, 1785.76135, -1744.55115, 12.74520,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[24] = CreateDynamicObject(3520, 1769.53271, -1744.63745, 12.74520,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[25] = CreateDynamicObject(3520, 1759.47168, -1744.63940, 12.74520,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[26] = CreateDynamicObject(3520, 1776.94995, -1744.69104, 12.74520,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[27] = CreateDynamicObject(1231, 1733.96265, -1751.79834, 15.49280,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[28] = CreateDynamicObject(1231, 1734.55994, -1773.73926, 15.49280,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[29] = CreateDynamicObject(669, 1735.22998, -1777.83667, 12.73670,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[30] = CreateDynamicObject(700, 1808.18066, -1777.72998, 13.22610,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[31] = CreateDynamicObject(669, 1807.72937, -1748.80200, 12.73670,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[32] = CreateDynamicObject(3458, 1703.38000, -1761.02844, 14.11930,   0.00000, 0.00000, -90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[33] = CreateDynamicObject(1280, 1715.92090, -1781.19995, 12.86000,   0.00000, 0.00000, -90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[34] = CreateDynamicObject(1280, 1715.92090, -1782.00000, 12.86000,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[35] = CreateDynamicObject(1280, 1715.92090, -1774.00000, 12.86000,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[36] = CreateDynamicObject(1280, 1715.92090, -1766.00000, 12.86000,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[37] = CreateDynamicObject(1280, 1715.92090, -1758.00000, 12.86000,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[38] = CreateDynamicObject(1280, 1715.90857, -1750.01575, 12.86000,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[39] = CreateDynamicObject(1280, 1715.92090, -1773.19995, 12.86000,   0.00000, 0.00000, -90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[40] = CreateDynamicObject(1280, 1715.92090, -1765.19995, 12.86000,   0.00000, 0.00000, -90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[41] = CreateDynamicObject(1280, 1715.94092, -1757.19958, 12.86000,   0.00000, 0.00000, -90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[42] = CreateDynamicObject(1280, 1715.92090, -1749.19995, 12.86000,   0.00000, 0.00000, -90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[43] = CreateDynamicObject(1280, 1720.00000, -1749.19995, 12.86000,   0.00000, 0.00000, -90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[44] = CreateDynamicObject(1300, 1717.94019, -1749.66663, 12.87960,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[45] = CreateDynamicObject(1280, 1720.00000, -1757.19995, 12.86000,   0.00000, 0.00000, -90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[46] = CreateDynamicObject(1280, 1720.00000, -1765.19995, 12.86000,   0.00000, 0.00000, -90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[47] = CreateDynamicObject(1280, 1720.00000, -1773.19995, 12.86000,   0.00000, 0.00000, -90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[48] = CreateDynamicObject(1280, 1720.00000, -1781.19995, 12.86000,   0.00000, 0.00000, -90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[49] = CreateDynamicObject(1280, 1720.00000, -1750.00000, 12.86000,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[50] = CreateDynamicObject(1280, 1720.00000, -1758.00000, 12.86000,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[51] = CreateDynamicObject(1280, 1720.00000, -1766.00000, 12.86000,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[52] = CreateDynamicObject(1280, 1720.00000, -1774.00000, 12.86000,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[53] = CreateDynamicObject(1280, 1720.00000, -1782.00000, 12.86000,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[54] = CreateDynamicObject(1300, 1717.94019, -1757.57544, 12.87960,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[55] = CreateDynamicObject(1300, 1717.94019, -1765.59338, 12.87960,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[56] = CreateDynamicObject(1300, 1717.94019, -1773.57739, 12.87960,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[57] = CreateDynamicObject(1300, 1717.94019, -1781.53674, 12.87960,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[58] = CreateDynamicObject(1257, 1735.74158, -1809.34338, 13.81740,   0.00000, 0.00000, 75.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[59] = CreateDynamicObject(1341, 1745.20837, -1808.05530, 13.57740,   0.00000, 0.00000, 75.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[60] = CreateDynamicObject(1340, 1749.23767, -1808.73706, 13.67740,   0.00000, 0.00000, 75.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[61] = CreateDynamicObject(1342, 1753.96008, -1809.63196, 13.59740,   0.00000, 0.00000, 75.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[62] = CreateDynamicObject(1340, 1757.87146, -1811.02502, 13.61740,   0.00000, 0.00000, 75.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[63] = CreateDynamicObject(1775, 1752.36951, -1809.18958, 13.67670,   0.00000, 0.00000, 165.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[64] = CreateDynamicObject(6965, 1789.90088, -1799.61169, 16.15140,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[65] = CreateDynamicObject(6964, 1789.99329, -1799.57837, 11.83070,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[66] = CreateDynamicObject(1281, 1768.38708, -1785.51550, 13.32840,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[67] = CreateDynamicObject(1281, 1759.57935, -1785.71826, 13.32840,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[68] = CreateDynamicObject(1281, 1750.73303, -1785.65308, 13.32840,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[69] = CreateDynamicObject(1281, 1742.49988, -1785.40930, 13.32840,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[70] = CreateDynamicObject(1281, 1735.39075, -1785.28650, 13.32840,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[71] = CreateDynamicObject(1281, 1733.97314, -1801.51868, 13.32840,   0.00000, 0.00000, -14.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[72] = CreateDynamicObject(1281, 1727.36646, -1799.86462, 13.32840,   0.00000, 0.00000, -14.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[73] = CreateDynamicObject(1281, 1720.64539, -1798.24097, 13.32840,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[74] = CreateDynamicObject(1281, 1741.15491, -1803.53967, 13.32840,   0.00000, 0.00000, -14.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[75] = CreateDynamicObject(1281, 1705.11536, -1789.26038, 13.32840,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[76] = CreateDynamicObject(4642, 1780.90588, -1815.70178, 14.22830,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[77] = CreateDynamicObject(838, 1808.55994, -1818.22375, 15.24600,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[78] = CreateDynamicObject(618, 1782.77820, -1817.87708, 12.85660,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[79] = CreateDynamicObject(729, 1811.02710, -1804.72205, 12.57820,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[80] = CreateDynamicObject(950, 1808.56494, -1805.02698, 13.12379,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[81] = CreateDynamicObject(949, 1809.68567, -1805.03735, 13.17630,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[82] = CreateDynamicObject(8990, 1811.25171, -1810.78662, 13.24750,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[83] = CreateDynamicObject(8990, 1811.17700, -1789.78491, 13.24750,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[84] = CreateDynamicObject(729, 1810.95129, -1795.97107, 12.57820,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[85] = CreateDynamicObject(729, 1810.77856, -1787.97192, 12.57820,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[86] = CreateDynamicObject(729, 1811.03687, -1813.20447, 12.57820,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[87] = CreateDynamicObject(18014, 1808.72205, -1804.17175, 12.97270,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[88] = CreateDynamicObject(1571, 1762.62598, -1811.67944, 13.62020,   0.00000, 0.00000, 165.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[89] = CreateDynamicObject(6299, 1709.85510, -1791.92151, 14.55620,   0.00000, 0.00000, 180.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[90] = CreateDynamicObject(19355, 1809.97095, -1798.68701, 12.47870,   0.00000, 90.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[91] = CreateDynamicObject(19355, 1806.48425, -1798.68701, 12.47870,   0.00000, 90.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[92] = CreateDynamicObject(19355, 1802.98206, -1798.68701, 12.47870,   0.00000, 90.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[93] = CreateDynamicObject(19355, 1809.97095, -1801.89185, 12.47870,   0.00000, 90.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[94] = CreateDynamicObject(19355, 1806.48425, -1801.89185, 12.47870,   0.00000, 90.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[95] = CreateDynamicObject(19355, 1802.98206, -1801.89185, 12.47870,   0.00000, 90.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[96] = CreateDynamicObject(18014, 1808.86475, -1796.51318, 12.97270,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[97] = CreateDynamicObject(8990, 1756.82178, -1812.72546, 13.24750,   0.00000, 0.00000, -14.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[98] = CreateDynamicObject(8990, 1743.43286, -1809.15308, 13.24750,   0.00000, 0.00000, -14.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[99] = CreateDynamicObject(19355, 1737.59302, -1807.01074, 12.47870,   0.00000, 0.00000, -105.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[100] = CreateDynamicObject(19355, 1741.57300, -1808.10132, 12.47870,   0.00000, 0.00000, -105.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[101] = CreateDynamicObject(19355, 1745.64807, -1809.15454, 12.47870,   0.00000, 0.00000, -105.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[102] = CreateDynamicObject(19355, 1750.21753, -1810.32031, 12.47870,   0.00000, 0.00000, -105.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[103] = CreateDynamicObject(19355, 1754.54639, -1811.53284, 12.47870,   0.00000, 0.00000, -105.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[104] = CreateDynamicObject(19355, 1758.50989, -1812.60571, 12.47870,   0.00000, 0.00000, -105.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[105] = CreateDynamicObject(19355, 1762.85486, -1813.80737, 12.47870,   0.00000, 0.00000, -105.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[106] = CreateDynamicObject(1281, 1748.61914, -1805.16223, 13.32840,   0.00000, 0.00000, -14.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[107] = CreateDynamicObject(1281, 1756.22937, -1806.64563, 13.32840,   0.00000, 0.00000, -14.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[108] = CreateDynamicObject(1281, 1763.56738, -1807.36121, 13.32840,   0.00000, 0.00000, -14.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[109] = CreateDynamicObject(1281, 1777.35706, -1785.42297, 13.32840,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[110] = CreateDynamicObject(618, 1760.55615, -1813.91699, 13.33661,   0.00000, 0.00000, 0.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[111] = CreateDynamicObject(618, 1756.96033, -1812.28394, 13.33660,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[112] = CreateDynamicObject(618, 1748.31726, -1809.66528, 13.33660,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[113] = CreateDynamicObject(618, 1739.78674, -1806.94189, 13.33660,   0.00000, 0.00000, 134.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[114] = CreateDynamicObject(618, 1743.90454, -1808.04883, 13.33660,   0.00000, 0.00000, 134.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[115] = CreateDynamicObject(618, 1752.70422, -1810.79517, 13.33660,   0.00000, 0.00000, 134.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[116] = CreateDynamicObject(8990, 1730.95081, -1749.65430, 13.24750,   0.00000, 0.00000, 90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[117] = CreateDynamicObject(8990, 1730.48169, -1761.16345, 13.24750,   0.00000, 0.00000, -90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
kirchen_object[118] = CreateDynamicObject(8990, 1730.45203, -1775.06519, 13.24750,   0.00000, 0.00000, -90.00000, VW_MAIN,MAPS_KIRCHE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}

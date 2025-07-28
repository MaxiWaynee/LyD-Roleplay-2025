#include <YSI\y_hooks>

// Global interior define
#define MAPS_TRIADSEXTERIOR_INTERIOR      0
#define MAPS_TRIADSINTERIOR_INTERIOR      3

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Triads points
#define TRIADS_INTERIOR_ENTER_COORDS        690.9656,-1275.9060,13.5603
#define TRIADS_INTERIOR_EXIT_COORDS         774.1301, -49.8932, 1000.5859
#define TRIADS_INTERIOR_ENTER_FACING        0.0
#define TRIADS_INTERIOR_EXIT_FACING         180

// Map variables
new object_triadsExterior[125];


hook OnPlayerConnect(playerid) {
    // Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 3276, -1427.8499, -1600.0899, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1439.2700, -1600.3399, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1451.0999, -1599.5999, 101.5550, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1462.6500, -1599.1999, 101.6330, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1468.4799, -1593.0600, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1417.8000, -1583.0300, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1468.9799, -1581.4799, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1469.2399, -1569.8100, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1469.6300, -1558.2600, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 17053, -1458.4499, -1522.6300, 100.7500, 0.10); // cw_bigbarn03
    RemoveBuildingForPlayer(playerid, 17354, -1458.4499, -1522.6300, 100.7500, 0.10); // LOD Model of cw_bigbarn03
    RemoveBuildingForPlayer(playerid, 17056, -1462.0200, -1532.5300, 101.9059, 0.10); // cw_corrug01
    RemoveBuildingForPlayer(playerid, 17057, -1451.5300, -1569.6099, 100.7419, 0.10); // cw_haypile03
    RemoveBuildingForPlayer(playerid, 17059, -1458.7700, -1535.5699, 100.7500, 0.10); // cw_haypile05
    RemoveBuildingForPlayer(playerid, 17335, -1432.5500, -1545.8699, 108.5309, 0.10); // farmhouse02
    RemoveBuildingForPlayer(playerid, 17351, -1432.5500, -1545.8699, 108.5309, 0.10); // LOD Model of farmhouse02
    RemoveBuildingForPlayer(playerid, 1501, -1437.8900, -1545.2299, 101.2809, 0.10); // Gen_doorEXT04
    RemoveBuildingForPlayer(playerid, 17050, -1411.2199, -1530.5500, 100.7500, 0.10); // cw_Silo02
    RemoveBuildingForPlayer(playerid, 3276, -1411.1600, -1561.0999, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1414.5999, -1572.0899, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1403.1700, -1528.8399, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1402.6700, -1540.1999, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1406.4200, -1550.8399, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 17049, -1412.8399, -1520.4000, 100.7500, 0.10); // cw_Silo01
    RemoveBuildingForPlayer(playerid, 3276, -1405.3800, -1517.0500, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3425, -1439.7900, -1520.9399, 112.1250, 0.10); // nt_windmill
    RemoveBuildingForPlayer(playerid, 3276, -1407.5899, -1505.7199, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 17052, -1458.0899, -1499.7800, 100.6330, 0.10); // cw_bigbarn02
    RemoveBuildingForPlayer(playerid, 17352, -1458.0899, -1499.7800, 100.6330, 0.10); // LOD Model of cw_bigbarn02
    RemoveBuildingForPlayer(playerid, 3276, -1409.4899, -1494.2399, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1472.0500, -1501.3299, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3374, -1435.1500, -1499.2900, 102.1640, 0.10); // SW_haybreak02
    RemoveBuildingForPlayer(playerid, 17061, -1423.5899, -1490.4799, 100.6559, 0.10); // cw_barnie
    RemoveBuildingForPlayer(playerid, 17353, -1423.5899, -1490.4799, 100.6559, 0.10); // LOD Model of cw_barnie
    RemoveBuildingForPlayer(playerid, 3276, -1470.5300, -1489.8900, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3374, -1435.1999, -1490.5200, 102.1640, 0.10); // SW_haybreak02
    RemoveBuildingForPlayer(playerid, 17060, -1457.6899, -1485.7600, 100.6330, 0.10); // cw_haypile06
    RemoveBuildingForPlayer(playerid, 3276, -1411.0100, -1482.8000, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1468.2700, -1478.3199, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1467.5500, -1467.2399, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1468.2199, -1455.6899, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 17054, -1440.8100, -1460.1099, 100.6330, 0.10); // cw_bigbarn04
    RemoveBuildingForPlayer(playerid, 17355, -1440.8100, -1460.1099, 100.6330, 0.10); // LOD Model of cw_bigbarn04
    RemoveBuildingForPlayer(playerid, 3276, -1411.9499, -1461.7600, 101.0390, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3374, -1419.0999, -1454.3699, 102.1019, 0.10); // SW_haybreak02
    RemoveBuildingForPlayer(playerid, 3374, -1423.5799, -1460.7199, 102.1640, 0.10); // SW_haybreak02
    RemoveBuildingForPlayer(playerid, 17055, -1439.2399, -1446.6600, 102.9300, 0.10); // cw_fueldrum03
    RemoveBuildingForPlayer(playerid, 3276, -1412.2700, -1450.2299, 101.0390, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1463.4300, -1447.6400, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3374, -1427.2700, -1453.7700, 102.1019, 0.10); // SW_haybreak02
    RemoveBuildingForPlayer(playerid, 3276, -1452.9599, -1443.3499, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1441.4599, -1440.7900, 101.4840, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1417.9799, -1443.6800, 100.7969, 0.10); // cxreffencesld
    RemoveBuildingForPlayer(playerid, 3276, -1429.5300, -1441.8199, 101.0390, 0.10); // cxreffencesld
}


hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {

}

hook OnGameModeInit() {
    // Vehicles

    // Pickups
    
    // Actors

    // Objects
    object_triadsExterior[0] = CreateDynamicObject(5986, -1450.7113, -1525.9558, 103.9000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[1] = CreateDynamicObject(8645, -1418.6999, -1564.3359, 101.6288, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[2] = CreateDynamicObject(8645, -1473.4000, -1520.1363, 101.6278, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[3] = CreateDynamicObject(8645, -1473.4072, -1497.2207, 101.6288, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[4] = CreateDynamicObject(8645, -1473.4051, -1475.2343, 101.6306, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[5] = CreateDynamicObject(8645, -1458.7578, -1460.6004, 101.6288, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[6] = CreateDynamicObject(8645, -1429.4498, -1460.6004, 101.6327, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[7] = CreateDynamicObject(8645, -1409.7718, -1460.6004, 101.6306, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[8] = CreateDynamicObject(8645, -1458.6842, -1496.0998, 101.6315, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[9] = CreateDynamicObject(8645, -1430.9898, -1496.1020, 101.6306, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[10] = CreateDynamicObject(10183, -1452.5361, -1491.8322, 100.9198, 0.0000, 0.0000, 225.4120, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[11] = CreateDynamicObject(10183, -1452.3393, -1464.7436, 100.9198, 0.0000, 0.0000, 45.5060, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[12] = CreateDynamicObject(3934, -1433.3182, -1535.8393, 100.9198, 0.0000, 0.0000, -0.0599, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[13] = CreateDynamicObject(3934, -1433.3182, -1548.2260, 100.9198, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[14] = CreateDynamicObject(1506, -1454.5179, -1502.1507, 100.9000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[15] = CreateDynamicObject(8645, -1430.5589, -1564.3338, 101.6306, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[16] = CreateDynamicObject(970, -1431.9895, -1467.0998, 101.4163, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[17] = CreateDynamicObject(970, -1431.9895, -1462.9444, 101.4163, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[18] = CreateDynamicObject(970, -1406.3508, -1496.2700, 101.3798, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[19] = CreateDynamicObject(3515, -1422.4255, -1507.2580, 101.0345, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[20] = CreateDynamicObject(19454, -1416.2501, -1552.7398, 100.8368, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[21] = CreateDynamicObject(19454, -1422.7802, -1555.8071, 100.8388, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[22] = CreateDynamicObject(19454, -1428.1898, -1555.8071, 100.8368, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[23] = CreateDynamicObject(19454, -1437.3016, -1555.8071, 100.8388, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[24] = CreateDynamicObject(19454, -1460.5594, -1555.8071, 100.8348, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[25] = CreateDynamicObject(19454, -1422.8011, -1528.0903, 100.8388, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[26] = CreateDynamicObject(19454, -1433.8022, -1528.0903, 100.8388, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[27] = CreateDynamicObject(19454, -1443.4034, -1528.0903, 100.8377, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[28] = CreateDynamicObject(19454, -1466.2038, -1547.3680, 110.5998, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[29] = CreateDynamicObject(19454, -1449.9531, -1540.7452, 100.8388, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[30] = CreateDynamicObject(19454, -1449.9531, -1531.1583, 100.8388, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[31] = CreateDynamicObject(19454, -1416.2501, -1544.3381, 100.8377, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[32] = CreateDynamicObject(19454, -1416.2501, -1534.7994, 100.8388, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[33] = CreateDynamicObject(19454, -1416.2501, -1525.1975, 100.8377, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[34] = CreateDynamicObject(19454, -1416.2501, -1515.7301, 100.8368, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[35] = CreateDynamicObject(19454, -1410.1999, -1498.1577, 100.8300, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[36] = CreateDynamicObject(19454, -1425.9873, -1528.0903, 100.8368, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[37] = CreateDynamicObject(8645, -1458.4041, -1564.3359, 101.6288, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[38] = CreateDynamicObject(8645, -1473.4051, -1549.6920, 101.6306, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[39] = CreateDynamicObject(3604, -1467.5587, -1552.9139, 103.3466, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[40] = CreateDynamicObject(19454, -1446.8823, -1555.8071, 100.8377, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[41] = CreateDynamicObject(19454, -1471.7187, -1549.7530, 100.9036, 0.0000, 90.0000, 179.7832, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[42] = CreateDynamicObject(717, -1432.8752, -1504.5091, 101.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[43] = CreateDynamicObject(717, -1450.6867, -1498.1092, 101.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[44] = CreateDynamicObject(717, -1450.6867, -1504.5091, 101.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[45] = CreateDynamicObject(19454, -1430.0400, -1548.2590, 100.8300, 0.0000, 90.0000, 0.0599, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[46] = CreateDynamicObject(1597, -1419.7474, -1546.7691, 102.9000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[47] = CreateDynamicObject(1597, -1419.7474, -1536.7207, 102.9000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[48] = CreateDynamicObject(1597, -1446.3000, -1546.7691, 102.9000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[49] = CreateDynamicObject(1597, -1446.3000, -1536.7207, 102.9000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[50] = CreateDynamicObject(1231, -1406.6964, -1531.7021, 103.4898, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[51] = CreateDynamicObject(1231, -1441.9521, -1504.5091, 103.4898, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[52] = CreateDynamicObject(1231, -1446.3000, -1531.1876, 103.4898, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[53] = CreateDynamicObject(1231, -1446.3000, -1552.7457, 103.4898, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[54] = CreateDynamicObject(1231, -1419.7474, -1552.7457, 103.4898, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[55] = CreateDynamicObject(19454, -1449.9531, -1549.7655, 100.8368, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[56] = CreateDynamicObject(19543, -1435.2569, -1503.7762, 100.9058, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[57] = CreateDynamicObject(19543, -1411.3968, -1532.9359, 100.9100, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[58] = CreateDynamicObject(19543, -1421.9167, -1532.9359, 100.9078, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[59] = CreateDynamicObject(19543, -1436.8968, -1532.9359, 100.9078, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[60] = CreateDynamicObject(19543, -1451.8968, -1532.9359, 100.9078, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[61] = CreateDynamicObject(19543, -1465.8968, -1532.9359, 100.9100, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[62] = CreateDynamicObject(8661, -1413.9106, -1480.5295, 100.9000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[63] = CreateDynamicObject(8661, -1433.8696, -1480.5295, 100.9010, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[64] = CreateDynamicObject(8661, -1453.8094, -1480.5295, 100.9000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[65] = CreateDynamicObject(8661, -1463.3796, -1480.5295, 100.9020, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[66] = CreateDynamicObject(970, -1431.9895, -1493.7993, 101.4163, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[67] = CreateDynamicObject(19454, -1437.0063, -1535.9179, 100.8300, 0.0000, 90.0000, 0.0599, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[68] = CreateDynamicObject(19454, -1433.5251, -1548.2590, 100.8300, 0.0000, 90.0000, 0.0599, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[69] = CreateDynamicObject(19454, -1437.0063, -1548.2590, 100.8300, 0.0000, 90.0000, 0.0599, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[70] = CreateDynamicObject(19454, -1433.5251, -1535.8884, 100.8300, 0.0000, 90.0000, 0.0599, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[71] = CreateDynamicObject(19454, -1430.0400, -1535.9040, 100.8300, 0.0000, 90.0000, 0.0599, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[72] = CreateDynamicObject(1231, -1441.9521, -1498.1092, 103.4898, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[73] = CreateDynamicObject(717, -1432.8752, -1498.1092, 101.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[74] = CreateDynamicObject(1280, -1423.8358, -1513.0030, 101.3000, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[75] = CreateDynamicObject(19454, -1456.2011, -1555.8071, 100.8368, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[76] = CreateDynamicObject(19454, -1471.5938, -1559.3459, 100.9036, 0.0000, 90.0000, 179.7832, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[77] = CreateDynamicObject(19454, -1468.0938, -1559.3459, 100.9037, 0.0000, 90.0000, 179.7832, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[78] = CreateDynamicObject(19454, -1464.5938, -1559.3459, 100.9037, 0.0000, 90.0000, 179.7832, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[79] = CreateDynamicObject(1280, -1470.1955, -1560.7840, 101.3867, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[80] = CreateDynamicObject(8645, -1404.0465, -1549.7351, 101.6306, 0.0000, 0.0000, -270.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[81] = CreateDynamicObject(8645, -1404.0465, -1520.2351, 101.6306, 0.0000, 0.0000, -270.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[82] = CreateDynamicObject(8645, -1404.0450, -1495.5888, 101.6288, 0.0000, 0.0000, -270.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[83] = CreateDynamicObject(8645, -1409.7700, -1460.6020, 100.7310, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[84] = CreateDynamicObject(19454, -1450.3974, -1501.3530, 100.8377, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[85] = CreateDynamicObject(19454, -1440.7673, -1501.3530, 100.8388, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[86] = CreateDynamicObject(19454, -1431.2673, -1501.3530, 100.8377, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[87] = CreateDynamicObject(19454, -1421.7673, -1501.3530, 100.8388, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[88] = CreateDynamicObject(19454, -1413.2673, -1501.3530, 100.8368, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[89] = CreateDynamicObject(19454, -1416.2501, -1506.4808, 100.8348, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[90] = CreateDynamicObject(3515, -1422.4255, -1522.4746, 101.0345, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[91] = CreateDynamicObject(717, -1406.6964, -1509.5201, 101.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[92] = CreateDynamicObject(1231, -1424.4521, -1498.1092, 103.4898, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[93] = CreateDynamicObject(1280, -1465.7358, -1560.7840, 101.3867, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[94] = CreateDynamicObject(1280, -1423.8358, -1517.0030, 101.3000, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[95] = CreateDynamicObject(717, -1415.8752, -1498.1092, 101.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[96] = CreateDynamicObject(717, -1406.6964, -1524.5201, 101.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[97] = CreateDynamicObject(717, -1406.6964, -1539.5201, 101.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[98] = CreateDynamicObject(717, -1406.6964, -1554.5201, 101.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[99] = CreateDynamicObject(1231, -1419.7474, -1531.1876, 103.4898, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[100] = CreateDynamicObject(1231, -1406.6964, -1547.2021, 103.4898, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[101] = CreateDynamicObject(1231, -1406.6964, -1516.7021, 103.4898, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[102] = CreateDynamicObject(8645, -1473.4030, -1475.2325, 100.6306, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[103] = CreateDynamicObject(8645, -1473.4030, -1497.2198, 100.6288, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[104] = CreateDynamicObject(8645, -1473.3979, -1520.1345, 100.6278, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[105] = CreateDynamicObject(8645, -1458.7558, -1460.5988, 100.6288, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[106] = CreateDynamicObject(8645, -1429.4477, -1460.5988, 100.6327, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[107] = CreateDynamicObject(8645, -1418.6988, -1564.3337, 100.6288, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[108] = CreateDynamicObject(8645, -1404.0489, -1520.2331, 101.1306, 0.0000, 0.0000, -270.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[109] = CreateDynamicObject(8645, -1404.0445, -1549.7331, 100.6306, 0.0000, 0.0000, -270.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[110] = CreateDynamicObject(17052, -1412.6544, -1592.9931, 100.8000, -1.5000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[111] = CreateDynamicObject(970, -1431.9895, -1489.6999, 101.4163, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[112] = CreateDynamicObject(970, -1414.0500, -1496.2700, 101.3798, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[113] = CreateDynamicObject(19121, -1410.1993, -1496.2700, 101.4423, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[114] = CreateDynamicObject(8661, -1383.9912, -1470.7623, 99.8538, 0.0000, 3.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[115] = CreateDynamicObject(8661, -1384.6966, -1480.7384, 89.8750, 93.0000, -90.0000, 90.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[116] = CreateDynamicObject(717, -1416.1964, -1562.0201, 101.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[117] = CreateDynamicObject(1231, -1424.1964, -1562.2021, 103.4898, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[118] = CreateDynamicObject(717, -1431.6964, -1562.0201, 101.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[119] = CreateDynamicObject(1231, -1439.6964, -1562.2021, 103.4898, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[120] = CreateDynamicObject(717, -1447.6964, -1562.0201, 101.0000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[121] = CreateDynamicObject(1280, -1411.3358, -1516.7021, 101.3000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[122] = CreateDynamicObject(1280, -1411.3358, -1516.7021, 101.3000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[123] = CreateDynamicObject(1280, -1411.3358, -1531.7021, 101.3000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsExterior[124] = CreateDynamicObject(1280, -1411.3358, -1547.2021, 101.3000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	
}

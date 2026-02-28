
#include <YSI\y_hooks>

// Global interior define
#define MAPS_CHRISTMASMARKET_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 180.0;
static Float:DRAWDISTANCE   = 160.0;

// Map variables
new object_christmasMarket[280];

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 713, 1457.9399, -1620.6999, 13.4531, 0.10); // veg_bevtree1
    RemoveBuildingForPlayer(playerid, 713, 1496.8699, -1707.8199, 13.4062, 0.10); // veg_bevtree1
    RemoveBuildingForPlayer(playerid, 1283, 1430.1700, -1719.4699, 15.6250, 0.10); // MTraffic1
    RemoveBuildingForPlayer(playerid, 1226, 1451.6300, -1727.6700, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1226, 1467.9799, -1727.6700, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1226, 1485.1700, -1727.6700, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1280, 1468.9799, -1713.5100, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 1231, 1479.6999, -1716.6999, 15.6250, 0.10); // Streetlamp2
    RemoveBuildingForPlayer(playerid, 1226, 1505.1800, -1727.6700, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1280, 1488.7700, -1713.6999, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 1289, 1504.7500, -1711.8800, 13.5937, 0.10); // newstandnew1
    RemoveBuildingForPlayer(playerid, 1258, 1445.0100, -1704.7700, 13.6953, 0.10); // Mpostbox1
    RemoveBuildingForPlayer(playerid, 1226, 1433.7099, -1702.3599, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1226, 1433.7099, -1676.6899, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1258, 1445.0100, -1692.2299, 13.6953, 0.10); // Mpostbox1
    RemoveBuildingForPlayer(playerid, 1226, 1433.7099, -1656.2500, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1226, 1433.7099, -1636.2299, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 712, 1445.8100, -1650.0200, 22.2577, 0.10); // vgs_palm03
    RemoveBuildingForPlayer(playerid, 1226, 1433.7099, -1619.0500, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1283, 1443.1999, -1592.9499, 15.6250, 0.10); // MTraffic1
    RemoveBuildingForPlayer(playerid, 673, 1457.7299, -1710.0600, 12.3984, 0.10); // sm_bevhiltree
    RemoveBuildingForPlayer(playerid, 620, 1461.6600, -1707.6899, 11.8359, 0.10); // veg_palm04
    RemoveBuildingForPlayer(playerid, 1280, 1468.9799, -1704.6400, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 700, 1463.0600, -1701.5699, 13.7265, 0.10); // sm_veg_tree6
    RemoveBuildingForPlayer(playerid, 1231, 1479.6999, -1702.5300, 15.6250, 0.10); // Streetlamp2
    RemoveBuildingForPlayer(playerid, 673, 1457.5500, -1697.2900, 12.3984, 0.10); // sm_bevhiltree
    RemoveBuildingForPlayer(playerid, 1280, 1468.9799, -1694.0500, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 1231, 1479.3800, -1692.3900, 15.6328, 0.10); // Streetlamp2
    RemoveBuildingForPlayer(playerid, 4186, 1479.5500, -1693.1400, 19.5781, 0.10); // PershingSq2_LAn
    RemoveBuildingForPlayer(playerid, 4057, 1479.5500, -1693.1400, 19.5781, 0.10); // LOD Model of PershingSq2_LAn
    RemoveBuildingForPlayer(playerid, 620, 1461.1300, -1687.5600, 11.8359, 0.10); // veg_palm04
    RemoveBuildingForPlayer(playerid, 700, 1463.0600, -1690.6500, 13.7265, 0.10); // sm_veg_tree6
    RemoveBuildingForPlayer(playerid, 641, 1458.6199, -1684.1300, 11.1015, 0.10); // veg_palmkb13
    RemoveBuildingForPlayer(playerid, 625, 1457.2700, -1666.3000, 13.6953, 0.10); // veg_palmkb1
    RemoveBuildingForPlayer(playerid, 1280, 1468.9799, -1682.7199, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 712, 1471.4100, -1666.1800, 22.2577, 0.10); // vgs_palm03
    RemoveBuildingForPlayer(playerid, 1231, 1479.3800, -1682.3100, 15.6328, 0.10); // Streetlamp2
    RemoveBuildingForPlayer(playerid, 625, 1458.2600, -1659.2600, 13.6953, 0.10); // veg_palmkb1
    RemoveBuildingForPlayer(playerid, 712, 1449.8499, -1655.9399, 22.2577, 0.10); // vgs_palm03
    RemoveBuildingForPlayer(playerid, 1231, 1477.9399, -1652.7299, 15.6328, 0.10); // Streetlamp2
    RemoveBuildingForPlayer(playerid, 1280, 1479.6099, -1653.2500, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 625, 1457.3499, -1650.5699, 13.6953, 0.10); // veg_palmkb1
    RemoveBuildingForPlayer(playerid, 625, 1454.4200, -1642.4899, 13.6953, 0.10); // veg_palmkb1
    RemoveBuildingForPlayer(playerid, 1280, 1467.8499, -1646.5899, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 1280, 1472.9000, -1651.5100, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 1280, 1465.9399, -1639.8199, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 1231, 1466.4699, -1637.9599, 15.6328, 0.10); // Streetlamp2
    RemoveBuildingForPlayer(playerid, 625, 1449.5899, -1635.0500, 13.6953, 0.10); // veg_palmkb1
    RemoveBuildingForPlayer(playerid, 1280, 1467.7099, -1632.8900, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 1232, 1465.8900, -1629.9799, 15.5312, 0.10); // Streetlamp1
    RemoveBuildingForPlayer(playerid, 1280, 1472.6600, -1627.8800, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 1280, 1479.4699, -1626.0200, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 3985, 1479.5600, -1631.4499, 12.0781, 0.10); // PershingSq1_LAn
    RemoveBuildingForPlayer(playerid, 4210, 1479.5600, -1631.4499, 12.0781, 0.10); // LOD Model of PershingSq1_LAn
    RemoveBuildingForPlayer(playerid, 4206, 1479.5500, -1639.6099, 13.6484, 0.10); // PershingPool_LAn
    RemoveBuildingForPlayer(playerid, 1232, 1465.8399, -1608.3800, 15.3750, 0.10); // Streetlamp1
    RemoveBuildingForPlayer(playerid, 1229, 1466.4799, -1598.0899, 14.1093, 0.10); // bussign1
    RemoveBuildingForPlayer(playerid, 1226, 1451.3399, -1596.6999, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1226, 1471.3499, -1596.6999, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1280, 1488.7700, -1704.5899, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 700, 1494.2099, -1694.4399, 13.7265, 0.10); // sm_veg_tree6
    RemoveBuildingForPlayer(playerid, 1280, 1488.7700, -1693.7299, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 620, 1496.9799, -1686.8499, 11.8359, 0.10); // veg_palm04
    RemoveBuildingForPlayer(playerid, 641, 1494.1400, -1689.2299, 11.1015, 0.10); // veg_palmkb13
    RemoveBuildingForPlayer(playerid, 1280, 1488.7700, -1682.6700, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 712, 1480.6099, -1666.1800, 22.2577, 0.10); // vgs_palm03
    RemoveBuildingForPlayer(playerid, 712, 1488.2299, -1666.1800, 22.2577, 0.10); // vgs_palm03
    RemoveBuildingForPlayer(playerid, 1280, 1486.4100, -1651.3900, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 1280, 1491.3699, -1646.3800, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 1280, 1493.1300, -1639.4499, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 1280, 1486.1800, -1627.7700, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 1280, 1491.2199, -1632.6800, 13.4531, 0.10); // parkbench1
    RemoveBuildingForPlayer(playerid, 1232, 1494.4100, -1629.9799, 15.5312, 0.10); // Streetlamp1
    RemoveBuildingForPlayer(playerid, 1232, 1494.3599, -1608.3800, 15.3750, 0.10); // Streetlamp1
    RemoveBuildingForPlayer(playerid, 1226, 1488.5300, -1596.6999, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1229, 1498.0500, -1598.0899, 14.1093, 0.10); // bussign1
    RemoveBuildingForPlayer(playerid, 1288, 1504.7500, -1705.4100, 13.5937, 0.10); // newstandnew2
    RemoveBuildingForPlayer(playerid, 1287, 1504.7500, -1704.4699, 13.5937, 0.10); // newstandnew3
    RemoveBuildingForPlayer(playerid, 1286, 1504.7500, -1695.0500, 13.5937, 0.10); // newstandnew4
    RemoveBuildingForPlayer(playerid, 1285, 1504.7500, -1694.0400, 13.5937, 0.10); // newstandnew5
    RemoveBuildingForPlayer(playerid, 673, 1498.9599, -1684.6099, 12.3984, 0.10); // sm_bevhiltree
    RemoveBuildingForPlayer(playerid, 625, 1504.1600, -1662.0200, 13.6953, 0.10); // veg_palmkb1
    RemoveBuildingForPlayer(playerid, 625, 1504.7199, -1670.9200, 13.6953, 0.10); // veg_palmkb1
    RemoveBuildingForPlayer(playerid, 620, 1503.1899, -1621.1300, 11.8359, 0.10); // veg_palm04
    RemoveBuildingForPlayer(playerid, 673, 1501.2800, -1624.5799, 12.3984, 0.10); // sm_bevhiltree
    RemoveBuildingForPlayer(playerid, 673, 1498.3599, -1616.9699, 12.3984, 0.10); // sm_bevhiltree
    RemoveBuildingForPlayer(playerid, 1226, 1504.8900, -1596.6999, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 712, 1508.4499, -1668.7399, 22.2577, 0.10); // vgs_palm03
    RemoveBuildingForPlayer(playerid, 625, 1505.6999, -1654.8399, 13.6953, 0.10); // veg_palmkb1
    RemoveBuildingForPlayer(playerid, 625, 1508.5200, -1647.8599, 13.6953, 0.10); // veg_palmkb1
    RemoveBuildingForPlayer(playerid, 625, 1513.2700, -1642.4899, 13.6953, 0.10); // veg_palmkb1
    RemoveBuildingForPlayer(playerid, 1258, 1510.8900, -1607.3100, 13.6953, 0.10); // Mpostbox1
    RemoveBuildingForPlayer(playerid, 1226, 1524.8299, -1721.6300, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1226, 1524.8299, -1705.2700, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1229, 1524.2199, -1693.9699, 14.1093, 0.10); // bussign1
    RemoveBuildingForPlayer(playerid, 1226, 1524.8299, -1688.0899, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1229, 1524.2199, -1673.7099, 14.1093, 0.10); // bussign1
    RemoveBuildingForPlayer(playerid, 1226, 1524.8299, -1668.0799, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1226, 1524.8299, -1647.6400, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1226, 1524.8299, -1621.9599, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1226, 1525.3800, -1611.1600, 16.4218, 0.10); // lamppost3
    RemoveBuildingForPlayer(playerid, 1283, 1528.9499, -1605.8599, 15.6250, 0.10); // MTraffic1
}

hook OnGameModeInit() {
	// Objects
    object_christmasMarket[0] = CreateDynamicObject(19533, 1493.3591, -1673.0946, 12.3000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    SetDynamicObjectMaterial(object_christmasMarket[0], 0, 10756, "airportroads_sfse", "sf_junction5", 0x00000000);
    object_christmasMarket[1] = CreateDynamicObject(19634, 1479.5920, -1707.5062, 2.1447, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Ramp360Degree2
    SetDynamicObjectMaterial(object_christmasMarket[1], 0, 19297, "matlights", "invisible", 0x00000000);
    SetDynamicObjectMaterial(object_christmasMarket[1], 1, 3979, "civic01_lan", "crazy paving", 0xFFFFFFFF);
    object_christmasMarket[2] = CreateDynamicObject(19533, 1465.7351, -1673.0841, 12.3009, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
    SetDynamicObjectMaterial(object_christmasMarket[2], 0, 10756, "airportroads_sfse", "sf_junction5", 0x00000000);
    object_christmasMarket[3] = CreateDynamicObject(18753, 1461.5904, -1640.7932, 11.7964, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Base125mx125m1
    SetDynamicObjectMaterial(object_christmasMarket[3], 0, 3922, "bistro", "mp_snow", 0x00000000);
    object_christmasMarket[4] = CreateDynamicObject(19447, 1452.8530, -1650.1350, 12.2144, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[4], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[5] = CreateDynamicObject(1463, 1466.7364, -1649.9062, 12.6084, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WOODPILE2
    object_christmasMarket[6] = CreateDynamicObject(19633, 1480.1319, -1631.3542, 12.3465, 0.0000, 180.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Ramp360Degree1
    SetDynamicObjectMaterial(object_christmasMarket[6], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    SetDynamicObjectMaterial(object_christmasMarket[6], 1, 3979, "civic01_lan", "crazy paving", 0xFFFFFFFF);
    object_christmasMarket[7] = CreateDynamicObject(19447, 1480.1827, -1596.7888, 12.2742, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[7], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[8] = CreateDynamicObject(19447, 1480.1816, -1660.8879, 12.2742, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[8], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[9] = CreateDynamicObject(19447, 1495.2613, -1631.6070, 12.2341, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[9], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[10] = CreateDynamicObject(18981, 1471.8900, -1715.4415, 11.8730, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_christmasMarket[10], 0, 6312, "beacliff_law2", "concretebigblu4256128", 0xFFFFFFFF);
    object_christmasMarket[11] = CreateDynamicObject(19447, 1504.8819, -1631.6070, 12.2341, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[11], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[12] = CreateDynamicObject(19447, 1514.5117, -1631.6070, 12.2341, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[12], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[13] = CreateDynamicObject(19447, 1464.8620, -1631.6070, 12.2341, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[13], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[14] = CreateDynamicObject(19447, 1455.2220, -1631.6070, 12.2341, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[14], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[15] = CreateDynamicObject(19447, 1445.6019, -1631.6070, 12.2341, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[15], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[16] = CreateDynamicObject(19447, 1480.1827, -1616.0378, 12.2341, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[16], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[17] = CreateDynamicObject(19447, 1439.2513, -1631.6070, 12.2944, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[17], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[18] = CreateDynamicObject(19447, 1480.1827, -1606.4089, 12.2341, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[18], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[19] = CreateDynamicObject(19447, 1480.1827, -1646.6673, 12.2341, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[19], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[20] = CreateDynamicObject(19447, 1480.1827, -1656.2768, 12.2341, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[20], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[21] = CreateDynamicObject(19076, 1480.1169, -1631.4326, 12.2854, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasTree1
    object_christmasMarket[22] = CreateDynamicObject(19447, 1504.1827, -1638.1673, 12.2341, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[22], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[23] = CreateDynamicObject(19447, 1504.1827, -1647.7983, 12.2341, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[23], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[24] = CreateDynamicObject(19447, 1504.1827, -1657.3979, 12.2341, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[24], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[25] = CreateDynamicObject(18981, 1496.8797, -1715.4415, 11.8750, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_christmasMarket[25], 0, 6312, "beacliff_law2", "concretebigblu4256128", 0xFFFFFFFF);
    object_christmasMarket[26] = CreateDynamicObject(18981, 1514.6562, -1715.4415, 11.8730, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_christmasMarket[26], 0, 6312, "beacliff_law2", "concretebigblu4256128", 0xFFFFFFFF);
    object_christmasMarket[27] = CreateDynamicObject(19447, 1520.1329, -1631.6070, 12.2398, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[27], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[28] = CreateDynamicObject(19447, 1504.1827, -1660.8491, 12.2444, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[28], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[29] = CreateDynamicObject(19447, 1504.1827, -1625.0483, 12.2341, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[29], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[30] = CreateDynamicObject(19447, 1504.1827, -1615.4183, 12.2341, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[30], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[31] = CreateDynamicObject(19447, 1504.1827, -1605.7976, 12.2341, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[31], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[32] = CreateDynamicObject(19447, 1504.1827, -1596.1767, 12.2742, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[32], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[33] = CreateDynamicObject(18980, 1524.0985, -1693.0941, 12.6603, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[33], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[34] = CreateDynamicObject(19447, 1452.8530, -1602.1069, 12.2144, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[34], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[35] = CreateDynamicObject(19447, 1452.8530, -1611.6861, 12.2144, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[35], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[36] = CreateDynamicObject(3863, 1486.1413, -1620.7414, 13.4777, 0.0000, 0.0000, -32.2998, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //marketstall03_SFXRF
    SetDynamicObjectMaterial(object_christmasMarket[36], 0, 19058, "xmasboxes", "wrappingpaper16", 0x00000000);
    object_christmasMarket[37] = CreateDynamicObject(19447, 1452.8530, -1621.2956, 12.2144, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[37], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[38] = CreateDynamicObject(19447, 1452.8530, -1630.9161, 12.2144, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[38], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[39] = CreateDynamicObject(19447, 1452.8530, -1640.5356, 12.2144, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[39], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[40] = CreateDynamicObject(18981, 1446.8927, -1715.4415, 11.8730, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_christmasMarket[40], 0, 4835, "airoads_las", "concretenewb256", 0xFFFFFFFF);
    object_christmasMarket[41] = CreateDynamicObject(19447, 1452.8530, -1659.7641, 12.2144, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[41], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[42] = CreateDynamicObject(19447, 1452.8520, -1661.6451, 12.2243, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[42], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[43] = CreateDynamicObject(10183, 1491.7060, -1722.1097, 12.3886, 0.0000, 0.0000, 225.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
    object_christmasMarket[44] = CreateDynamicObject(3660, 1480.0882, -1703.7054, 14.0417, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    object_christmasMarket[45] = CreateDynamicObject(18980, 1524.0985, -1653.1025, 12.6603, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[45], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[46] = CreateDynamicObject(10183, 1466.5561, -1721.8934, 12.3899, 0.0000, 0.0000, 225.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
    object_christmasMarket[47] = CreateDynamicObject(8843, 1503.6871, -1711.2722, 12.3908, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
    object_christmasMarket[48] = CreateDynamicObject(3660, 1511.0384, -1703.7054, 14.0417, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    object_christmasMarket[49] = CreateDynamicObject(3660, 1447.9488, -1703.7054, 14.0417, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    object_christmasMarket[50] = CreateDynamicObject(19957, 1524.0229, -1722.3553, 11.8254, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_christmasMarket[51] = CreateDynamicObject(19957, 1519.5677, -1726.8105, 11.8254, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_christmasMarket[52] = CreateDynamicObject(19967, 1434.9565, -1722.3602, 12.0495, 0.0000, 0.0000, -45.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign20
    object_christmasMarket[53] = CreateDynamicObject(19967, 1439.5400, -1726.8164, 12.0495, 0.0000, 0.0000, -45.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign20
    object_christmasMarket[54] = CreateDynamicObject(1368, 1461.5412, -1648.7479, 12.9441, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[55] = CreateDynamicObject(18980, 1524.0975, -1709.8315, 12.6590, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[55], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[56] = CreateDynamicObject(1368, 1462.8900, -1652.6384, 12.9441, 0.0000, 0.0000, 135.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[57] = CreateDynamicObject(1368, 1466.7745, -1654.6678, 12.9441, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[58] = CreateDynamicObject(1368, 1470.7109, -1652.7497, 12.9441, 0.0000, 0.0000, 225.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[59] = CreateDynamicObject(1368, 1472.0930, -1648.6114, 12.9441, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[60] = CreateDynamicObject(18980, 1524.0985, -1609.7867, 12.6603, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[60], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[61] = CreateDynamicObject(19058, 1479.6522, -1698.7761, 12.8978, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox5
    object_christmasMarket[62] = CreateDynamicObject(3863, 1474.2303, -1620.6510, 13.4777, 0.0000, 0.0000, 32.5000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //marketstall03_SFXRF
    SetDynamicObjectMaterial(object_christmasMarket[62], 0, 19058, "xmasboxes", "wrappingpaper28", 0x00000000);
    object_christmasMarket[63] = CreateDynamicObject(1368, 1492.4643, -1606.7484, 12.9441, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[64] = CreateDynamicObject(1368, 1489.1046, -1608.1833, 12.9441, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[65] = CreateDynamicObject(18762, 1521.1070, -1597.7900, 12.6590, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[65], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[66] = CreateDynamicObject(3863, 1469.4652, -1625.3525, 13.4777, 0.0000, 0.0000, 56.0997, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //marketstall03_SFXRF
    SetDynamicObjectMaterial(object_christmasMarket[66], 0, 19058, "xmasboxes", "wrappingpaper4-2", 0x00000000);
    object_christmasMarket[67] = CreateDynamicObject(1368, 1495.8625, -1608.2121, 12.9441, 0.0000, 0.0000, -45.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[68] = CreateDynamicObject(3863, 1490.5539, -1625.1590, 13.4777, 0.0000, 0.0000, -56.1996, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //marketstall03_SFXRF
    SetDynamicObjectMaterial(object_christmasMarket[68], 0, 19058, "xmasboxes", "wrappingpaper4-2", 0x00000000);
    object_christmasMarket[69] = CreateDynamicObject(3863, 1490.5677, -1637.5694, 13.4777, 0.0000, 0.0000, -122.9997, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //marketstall03_SFXRF
    SetDynamicObjectMaterial(object_christmasMarket[69], 0, 19058, "xmasboxes", "wrappingpaper28", 0x00000000);
    object_christmasMarket[70] = CreateDynamicObject(18762, 1516.1075, -1597.7900, 12.6590, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[70], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[71] = CreateDynamicObject(3863, 1486.6971, -1641.5693, 13.4777, 0.0000, 0.0000, -146.3999, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //marketstall03_SFXRF
    SetDynamicObjectMaterial(object_christmasMarket[71], 0, 19058, "xmasboxes", "wrappingpaper20", 0x00000000);
    object_christmasMarket[72] = CreateDynamicObject(3863, 1474.5738, -1642.2429, 13.4777, 0.0000, 0.0000, 151.5997, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //marketstall03_SFXRF
    SetDynamicObjectMaterial(object_christmasMarket[72], 0, 19058, "xmasboxes", "wrappingpaper16", 0x00000000);
    object_christmasMarket[73] = CreateDynamicObject(3863, 1470.3238, -1638.5926, 13.4777, 0.0000, 0.0000, 123.3999, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //marketstall03_SFXRF
    SetDynamicObjectMaterial(object_christmasMarket[73], 0, 19058, "xmasboxes", "wrappingpaper1", 0x00000000);
    object_christmasMarket[74] = CreateDynamicObject(18762, 1524.0985, -1624.7866, 12.6590, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[74], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[75] = CreateDynamicObject(18762, 1524.0985, -1638.1035, 12.6590, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[75], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[76] = CreateDynamicObject(1368, 1487.8719, -1612.1416, 12.9441, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[77] = CreateDynamicObject(659, 1515.1942, -1659.2738, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[78] = CreateDynamicObject(18762, 1524.0975, -1635.8518, 12.6576, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[78], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[79] = CreateDynamicObject(18762, 1524.0975, -1627.3613, 12.6576, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[79], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[80] = CreateDynamicObject(659, 1515.1942, -1649.7038, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[81] = CreateDynamicObject(659, 1515.1942, -1640.5849, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[82] = CreateDynamicObject(659, 1515.1942, -1622.4437, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[83] = CreateDynamicObject(659, 1515.1942, -1613.8332, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[84] = CreateDynamicObject(659, 1515.1942, -1605.1125, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[85] = CreateDynamicObject(1368, 1496.9735, -1612.1416, 12.9441, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[86] = CreateDynamicObject(659, 1442.9659, -1622.4437, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[87] = CreateDynamicObject(659, 1442.9659, -1613.8332, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[88] = CreateDynamicObject(659, 1442.9659, -1605.1125, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[89] = CreateDynamicObject(659, 1442.9659, -1640.5849, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[90] = CreateDynamicObject(659, 1442.9659, -1649.7038, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[91] = CreateDynamicObject(659, 1442.9659, -1659.2738, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[92] = CreateDynamicObject(659, 1496.6842, -1659.2738, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[93] = CreateDynamicObject(659, 1487.3238, -1605.1125, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[94] = CreateDynamicObject(18761, 1524.1131, -1673.3563, 15.4127, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //RaceFinishLine1
    SetDynamicObjectMaterial(object_christmasMarket[94], 0, 10765, "airportgnd_sfse", "white", 0xFF800000);
    SetDynamicObjectMaterial(object_christmasMarket[94], 1, 2423, "cj_ff_counters", "CJ_Laminate1", 0x00000000);
    SetDynamicObjectMaterial(object_christmasMarket[94], 2, 2423, "cj_ff_counters", "CJ_Laminate1", 0x00000000);
    object_christmasMarket[95] = CreateDynamicObject(1974, 1474.3076, -1641.3078, 13.5819, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_golfball
    SetDynamicObjectMaterial(object_christmasMarket[95], 0, 10765, "airportgnd_sfse", "white", 0xFFA0522D);
    object_christmasMarket[96] = CreateDynamicObject(659, 1487.3238, -1659.2738, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[97] = CreateDynamicObject(659, 1472.1025, -1659.2738, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[98] = CreateDynamicObject(659, 1461.1020, -1659.2738, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[99] = CreateDynamicObject(659, 1496.6842, -1605.1125, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[100] = CreateDynamicObject(18980, 1511.1278, -1702.5002, 12.6590, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[100], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[101] = CreateDynamicObject(18980, 1480.1827, -1702.5002, 12.6590, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[101], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[102] = CreateDynamicObject(18980, 1447.9820, -1702.5002, 12.6590, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[102], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[103] = CreateDynamicObject(18980, 1434.9863, -1709.8315, 12.6590, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[103], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[104] = CreateDynamicObject(18980, 1434.9853, -1693.0941, 12.6603, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[104], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[105] = CreateDynamicObject(18980, 1434.9863, -1653.1025, 12.6603, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[105], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[106] = CreateDynamicObject(18762, 1434.9853, -1638.1035, 12.6590, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[106], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[107] = CreateDynamicObject(18762, 1434.9863, -1635.8518, 12.6576, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[107], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[108] = CreateDynamicObject(18762, 1434.9863, -1627.3613, 12.6576, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[108], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[109] = CreateDynamicObject(18762, 1434.9853, -1624.7866, 12.6590, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[109], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[110] = CreateDynamicObject(18980, 1434.9863, -1609.7867, 12.6603, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[110], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[111] = CreateDynamicObject(18762, 1511.1075, -1597.7900, 12.6590, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[111], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[112] = CreateDynamicObject(19447, 1480.1827, -1685.2773, 12.2117, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[112], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[113] = CreateDynamicObject(18980, 1434.0655, -1675.0334, 11.8780, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    object_christmasMarket[114] = CreateDynamicObject(8843, 1480.0272, -1711.2722, 12.3908, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
    object_christmasMarket[115] = CreateDynamicObject(18980, 1525.0583, -1675.0334, 11.8780, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    object_christmasMarket[116] = CreateDynamicObject(18980, 1507.0582, -1726.8115, 12.6590, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[116], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[117] = CreateDynamicObject(18980, 1482.0589, -1726.8115, 12.6590, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[117], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[118] = CreateDynamicObject(18762, 1467.0775, -1726.8105, 12.6590, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[118], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[119] = CreateDynamicObject(19055, 1480.1556, -1632.6352, 12.9019, 0.0000, 0.0000, 143.4998, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox2
    object_christmasMarket[120] = CreateDynamicObject(8843, 1455.8369, -1711.2722, 12.3908, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
    object_christmasMarket[121] = CreateDynamicObject(19076, 1480.1169, -1697.7229, 12.2854, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasTree1
    object_christmasMarket[122] = CreateDynamicObject(19054, 1481.0257, -1697.1346, 12.8957, 0.0000, 0.0000, 21.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox1
    object_christmasMarket[123] = CreateDynamicObject(19054, 1479.0427, -1631.5875, 12.8957, 0.0000, 0.0000, 21.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox1
    object_christmasMarket[124] = CreateDynamicObject(19055, 1479.4692, -1696.9637, 12.9019, 0.0000, 0.0000, 143.4998, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox2
    object_christmasMarket[125] = CreateDynamicObject(19057, 1481.2999, -1699.0035, 12.9032, 0.0000, 0.0000, -17.1998, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox4
    object_christmasMarket[126] = CreateDynamicObject(18980, 1452.0770, -1726.8115, 12.6590, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_christmasMarket[126], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[127] = CreateDynamicObject(19057, 1481.2705, -1631.5277, 12.9032, 0.0000, 0.0000, -17.1998, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox4
    object_christmasMarket[128] = CreateDynamicObject(19058, 1479.6522, -1630.1855, 12.8978, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //XmasBox5
    object_christmasMarket[129] = CreateDynamicObject(1231, 1511.9293, -1725.7270, 14.9757, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_christmasMarket[130] = CreateDynamicObject(1231, 1446.2690, -1725.1766, 14.9757, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_christmasMarket[131] = CreateDynamicObject(1231, 1464.0649, -1702.6772, 14.9757, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_christmasMarket[132] = CreateDynamicObject(1231, 1495.6361, -1702.6772, 14.9757, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_christmasMarket[133] = CreateDynamicObject(1231, 1479.2408, -1726.0174, 14.9757, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_christmasMarket[134] = CreateDynamicObject(18762, 1508.4249, -1597.7910, 12.6597, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[134], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[135] = CreateDynamicObject(1463, 1492.5672, -1611.2624, 12.6084, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_WOODPILE2
    object_christmasMarket[136] = CreateDynamicObject(18762, 1499.9349, -1597.7910, 12.6597, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[136], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[137] = CreateDynamicObject(18762, 1494.9377, -1597.7910, 12.6597, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[137], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[138] = CreateDynamicObject(18762, 1489.9377, -1597.7910, 12.6597, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[138], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[139] = CreateDynamicObject(18762, 1484.9465, -1597.7900, 12.6610, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[139], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[140] = CreateDynamicObject(18762, 1484.4267, -1597.7910, 12.6597, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[140], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[141] = CreateDynamicObject(18762, 1475.9377, -1597.7910, 12.6597, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[141], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[142] = CreateDynamicObject(19447, 1452.8530, -1592.4875, 12.2742, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_christmasMarket[142], 0, 3979, "civic01_lan", "crazy paving", 0x00000000);
    object_christmasMarket[143] = CreateDynamicObject(18762, 1470.9383, -1597.7910, 12.6597, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[143], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[144] = CreateDynamicObject(18762, 1465.9387, -1597.7910, 12.6597, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[144], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[145] = CreateDynamicObject(18762, 1460.9383, -1597.7910, 12.6597, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[145], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[146] = CreateDynamicObject(18762, 1457.0904, -1597.7900, 12.6610, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[146], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[147] = CreateDynamicObject(18762, 1448.6024, -1597.7900, 12.6610, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[147], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[148] = CreateDynamicObject(18762, 1443.6024, -1597.7900, 12.6610, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[148], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[149] = CreateDynamicObject(18762, 1438.6024, -1597.7900, 12.6610, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_christmasMarket[149], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[150] = CreateDynamicObject(18763, 1435.9836, -1598.7790, 10.6862, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_christmasMarket[150], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[151] = CreateDynamicObject(18763, 1523.1053, -1598.7790, 10.6862, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_christmasMarket[151], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
    object_christmasMarket[152] = CreateDynamicObject(18688, 1492.4294, -1611.3342, 11.4406, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire
    object_christmasMarket[153] = CreateDynamicObject(18688, 1466.7291, -1649.9842, 11.4406, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire
    object_christmasMarket[154] = CreateDynamicObject(659, 1516.7646, -1690.9947, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[155] = CreateDynamicObject(659, 1504.3238, -1690.9947, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[156] = CreateDynamicObject(659, 1443.3232, -1690.9947, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[157] = CreateDynamicObject(659, 1455.6540, -1690.9947, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[158] = CreateDynamicObject(1368, 1452.0654, -1691.0577, 12.9441, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[159] = CreateDynamicObject(1368, 1447.3448, -1691.0577, 12.9441, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[160] = CreateDynamicObject(1368, 1508.0655, -1691.0577, 12.9441, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[161] = CreateDynamicObject(1368, 1513.2364, -1691.0577, 12.9441, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BLOCKER_BENCH
    object_christmasMarket[162] = CreateDynamicObject(18981, 1537.0155, -1631.0218, 11.8730, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    object_christmasMarket[163] = CreateDynamicObject(1223, 1477.8636, -1662.4150, 12.2117, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[164] = CreateDynamicObject(1223, 1482.5244, -1653.3636, 12.2117, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[165] = CreateDynamicObject(1223, 1482.5244, -1618.5329, 12.2117, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[166] = CreateDynamicObject(1223, 1482.5244, -1600.2301, 12.2117, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[167] = CreateDynamicObject(1223, 1477.8636, -1644.3137, 12.2117, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[168] = CreateDynamicObject(1223, 1477.8636, -1609.3330, 12.2117, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[169] = CreateDynamicObject(1223, 1522.9444, -1633.7036, 12.2117, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[170] = CreateDynamicObject(1223, 1506.4237, -1633.7036, 12.2117, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[171] = CreateDynamicObject(1223, 1490.8824, -1633.7036, 12.2117, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[172] = CreateDynamicObject(1223, 1514.4842, -1629.4735, 12.2117, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[173] = CreateDynamicObject(1223, 1498.3237, -1629.4735, 12.2117, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[174] = CreateDynamicObject(1223, 1469.3425, -1629.4735, 12.2117, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[175] = CreateDynamicObject(1223, 1454.9416, -1629.4735, 12.2117, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[176] = CreateDynamicObject(1223, 1436.1009, -1629.4735, 12.2117, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[177] = CreateDynamicObject(1223, 1462.1136, -1633.7036, 12.2117, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[178] = CreateDynamicObject(1223, 1445.5726, -1633.7036, 12.2117, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_christmasMarket[179] = CreateDynamicObject(19341, 1483.1191, -1643.4245, 12.7861, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //easter_egg01
    SetDynamicObjectMaterial(object_christmasMarket[179], 0, 3922, "bistro", "mp_snow", 0x00000000);
    object_christmasMarket[180] = CreateDynamicObject(18864, 1477.8706, -1636.4227, 6.2901, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FakeSnow1
    object_christmasMarket[181] = CreateDynamicObject(19342, 1483.1197, -1643.4194, 13.6056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //easter_egg02
    SetDynamicObjectMaterial(object_christmasMarket[181], 0, 3922, "bistro", "mp_snow", 0x00000000);
    object_christmasMarket[182] = CreateDynamicObject(18945, 1483.1120, -1643.4836, 14.0860, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //HatBoater2
    object_christmasMarket[183] = CreateDynamicObject(19578, 1483.1540, -1643.8148, 13.5064, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Banana1
    SetDynamicObjectMaterial(object_christmasMarket[183], 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    object_christmasMarket[184] = CreateDynamicObject(19578, 1483.1540, -1643.7746, 13.6764, 90.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Banana1
    SetDynamicObjectMaterial(object_christmasMarket[184], 0, 6985, "vgnfremnt2", "striplightsorange_256", 0x00000000);
    object_christmasMarket[185] = CreateDynamicObject(19344, 1483.0124, -1643.5544, 13.7964, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //easter_egg04
    SetDynamicObjectMaterial(object_christmasMarket[185], 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    object_christmasMarket[186] = CreateDynamicObject(19344, 1483.1728, -1643.7746, 13.0164, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //easter_egg04
    SetDynamicObjectMaterial(object_christmasMarket[186], 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    object_christmasMarket[187] = CreateDynamicObject(19344, 1483.2329, -1643.5445, 13.8163, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //easter_egg04
    SetDynamicObjectMaterial(object_christmasMarket[187], 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    object_christmasMarket[188] = CreateDynamicObject(19344, 1483.1728, -1643.8347, 12.8064, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //easter_egg04
    SetDynamicObjectMaterial(object_christmasMarket[188], 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    object_christmasMarket[189] = CreateDynamicObject(334, 1482.3498, -1643.3917, 13.3682, 0.0000, -127.3999, 180.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nitestick
    object_christmasMarket[190] = CreateDynamicObject(334, 1483.8852, -1643.3917, 13.3204, 0.0000, -127.3999, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nitestick
    object_christmasMarket[191] = CreateDynamicObject(19344, 1483.1728, -1643.8447, 12.6063, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //easter_egg04
    SetDynamicObjectMaterial(object_christmasMarket[191], 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    object_christmasMarket[192] = CreateDynamicObject(970, 1487.2584, -1647.1789, 12.7917, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasMarket[193] = CreateDynamicObject(970, 1491.4289, -1647.1789, 12.7917, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasMarket[194] = CreateDynamicObject(970, 1493.5096, -1649.2607, 12.7917, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasMarket[195] = CreateDynamicObject(970, 1493.5096, -1653.4216, 12.7917, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasMarket[196] = CreateDynamicObject(970, 1491.4095, -1655.5028, 12.7917, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasMarket[197] = CreateDynamicObject(970, 1487.2386, -1655.5028, 12.7917, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasMarket[198] = CreateDynamicObject(970, 1485.1789, -1653.4123, 12.7917, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasMarket[199] = CreateDynamicObject(970, 1485.1789, -1649.2429, 12.7917, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_christmasMarket[200] = CreateDynamicObject(19315, 1487.2939, -1653.4095, 12.7517, 0.0000, 0.0000, 66.9000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_christmasMarket[201] = CreateDynamicObject(19315, 1491.6308, -1650.0457, 12.7517, 0.0000, 0.0000, 115.5000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_christmasMarket[202] = CreateDynamicObject(19315, 1489.8840, -1649.7060, 12.7517, 0.0000, 0.0000, -133.5997, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_christmasMarket[203] = CreateDynamicObject(19315, 1486.9415, -1648.7213, 12.7517, 0.0000, 0.0000, 156.1000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //deer01
    object_christmasMarket[204] = CreateDynamicObject(18864, 1477.8706, -1826.8934, 6.2901, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FakeSnow1
    object_christmasMarket[205] = CreateDynamicObject(19552, 1485.1661, -1665.0489, 12.0214, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = -1, .drawdistance = -1); //Plane125x125Conc2
    object_christmasMarket[206] = CreateDynamicObject(19622, 1483.9195, -1643.3581, 12.9962, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Broom1
    object_christmasMarket[207] = CreateDynamicObject(2803, 1485.8918, -1641.4331, 13.5811, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MEAT_BAG_1
    object_christmasMarket[208] = CreateDynamicObject(2369, 1487.0118, -1640.7967, 13.1063, 0.0000, 0.0000, -149.6000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Till
    object_christmasMarket[209] = CreateDynamicObject(2369, 1489.5925, -1638.1002, 13.1063, 0.0000, 0.0000, -122.2998, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Till
    object_christmasMarket[210] = CreateDynamicObject(19933, 1473.8341, -1621.7452, 13.5125, 0.0000, 0.0000, 124.5998, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWallOven1
    object_christmasMarket[211] = CreateDynamicObject(19066, 1490.3839, -1636.3663, 13.1293, 0.0000, 26.1000, 142.8000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat3
    object_christmasMarket[212] = CreateDynamicObject(19066, 1490.1357, -1636.6932, 13.1293, 0.0000, 26.1000, 142.8000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat3
    object_christmasMarket[213] = CreateDynamicObject(11744, 1474.6218, -1621.3558, 13.1324, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MPlate1
    object_christmasMarket[214] = CreateDynamicObject(19066, 1489.8636, -1637.0517, 13.1293, 0.0000, 26.1000, 142.8000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SantaHat3
    object_christmasMarket[215] = CreateDynamicObject(11744, 1474.7219, -1620.7652, 13.1324, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MPlate1
    object_christmasMarket[216] = CreateDynamicObject(11744, 1475.5526, -1620.7652, 13.1323, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MPlate1
    object_christmasMarket[217] = CreateDynamicObject(11739, 1475.5506, -1620.7690, 13.1374, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MCake1
    object_christmasMarket[218] = CreateDynamicObject(11740, 1474.7198, -1620.7525, 13.1373, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MCake2
    object_christmasMarket[219] = CreateDynamicObject(2492, 1488.5438, -1624.6997, 13.7165, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MANHUNT_TOY2_1
    object_christmasMarket[220] = CreateDynamicObject(2492, 1488.5438, -1624.5797, 13.7165, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MANHUNT_TOY2_1
    object_christmasMarket[221] = CreateDynamicObject(11741, 1474.6159, -1621.3458, 13.1373, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MCake3
    object_christmasMarket[222] = CreateDynamicObject(2494, 1490.1976, -1627.1174, 13.7364, 0.0000, 0.0000, -106.4000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MANHUNT_TOY2_2
    object_christmasMarket[223] = CreateDynamicObject(19833, 1488.7260, -1651.3518, 12.2014, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cow1
    object_christmasMarket[224] = CreateDynamicObject(19833, 1491.1899, -1651.0551, 12.2014, 0.0000, 0.0000, -106.8999, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cow1
    object_christmasMarket[225] = CreateDynamicObject(2494, 1490.3488, -1627.1740, 13.7364, 0.0000, 0.0000, 62.5998, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MANHUNT_TOY2_2
    object_christmasMarket[226] = CreateDynamicObject(19835, 1485.4356, -1621.2080, 13.2025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    SetDynamicObjectMaterial(object_christmasMarket[226], 0, 19058, "xmasboxes", "wrappingpaper20", 0x00000000);
    SetDynamicObjectMaterial(object_christmasMarket[226], 1, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_christmasMarket[227] = CreateDynamicObject(2469, 1470.4554, -1624.8674, 13.0764, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MODEL_PLANES_3
    object_christmasMarket[228] = CreateDynamicObject(2469, 1469.2945, -1626.5781, 13.0764, 0.0000, 0.0000, 58.5998, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MODEL_PLANES_3
    object_christmasMarket[229] = CreateDynamicObject(2485, 1470.0367, -1625.7257, 13.1663, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MODEL_CAR_1
    object_christmasMarket[230] = CreateDynamicObject(2369, 1490.2799, -1625.8283, 13.1063, 0.0000, 0.0000, -55.1999, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Till
    object_christmasMarket[231] = CreateDynamicObject(2507, 1491.0941, -1623.8634, 13.7917, 0.0000, 0.0000, -52.3998, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MODEL_toy_3
    object_christmasMarket[232] = CreateDynamicObject(1956, 1484.9493, -1620.7739, 13.1364, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //turn_platerL
    object_christmasMarket[233] = CreateDynamicObject(19584, 1484.9516, -1620.5268, 13.2863, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MarcosSaucepan1
    object_christmasMarket[234] = CreateDynamicObject(2504, 1491.5633, -1624.5289, 13.5200, 0.0000, 0.0000, -52.4000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Train_toy_3
    object_christmasMarket[235] = CreateDynamicObject(1972, 1474.4034, -1641.4066, 13.3465, 0.0000, 0.0000, 151.6999, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_cuntopdisp2
    SetDynamicObjectMaterial(object_christmasMarket[235], 0, 19297, "matlights", "invisible", 0x00000000);
    object_christmasMarket[236] = CreateDynamicObject(2507, 1492.0888, -1625.1552, 13.7917, 0.0000, 0.0000, -52.3998, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MODEL_toy_3
    object_christmasMarket[237] = CreateDynamicObject(19835, 1486.3066, -1621.2080, 13.2025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    SetDynamicObjectMaterial(object_christmasMarket[237], 0, 19058, "xmasboxes", "wrappingpaper20", 0x00000000);
    SetDynamicObjectMaterial(object_christmasMarket[237], 1, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_christmasMarket[238] = CreateDynamicObject(19835, 1485.8663, -1621.4582, 13.2025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    SetDynamicObjectMaterial(object_christmasMarket[238], 0, 19058, "xmasboxes", "wrappingpaper20", 0x00000000);
    SetDynamicObjectMaterial(object_christmasMarket[238], 1, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_christmasMarket[239] = CreateDynamicObject(19835, 1486.3265, -1621.5782, 13.2025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    SetDynamicObjectMaterial(object_christmasMarket[239], 0, 19058, "xmasboxes", "wrappingpaper20", 0x00000000);
    SetDynamicObjectMaterial(object_christmasMarket[239], 1, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_christmasMarket[240] = CreateDynamicObject(19835, 1486.9071, -1621.5782, 13.2025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    SetDynamicObjectMaterial(object_christmasMarket[240], 0, 19058, "xmasboxes", "wrappingpaper20", 0x00000000);
    SetDynamicObjectMaterial(object_christmasMarket[240], 1, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_christmasMarket[241] = CreateDynamicObject(19835, 1486.5566, -1621.9586, 13.2025, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CoffeeCup1
    SetDynamicObjectMaterial(object_christmasMarket[241], 0, 19058, "xmasboxes", "wrappingpaper20", 0x00000000);
    SetDynamicObjectMaterial(object_christmasMarket[241], 1, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_christmasMarket[242] = CreateDynamicObject(2369, 1475.4189, -1642.1278, 13.1063, 0.0000, 0.0000, 145.8999, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Till
    object_christmasMarket[243] = CreateDynamicObject(11733, 1477.4101, -1630.5937, 12.3348, 0.0000, 0.0000, -29.3999, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WRockingHorse1
    object_christmasMarket[244] = CreateDynamicObject(841, 1491.8270, -1648.8087, 12.3662, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DEAD_TREE_13
    object_christmasMarket[245] = CreateDynamicObject(841, 1489.4364, -1654.1982, 12.3662, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DEAD_TREE_13
    object_christmasMarket[246] = CreateDynamicObject(839, 1491.1297, -1651.3010, 13.7735, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DEAD_TREE_11
    object_christmasMarket[247] = CreateDynamicObject(18761, 1434.9625, -1673.3563, 15.4127, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //RaceFinishLine1
    SetDynamicObjectMaterial(object_christmasMarket[247], 0, 10765, "airportgnd_sfse", "white", 0xFF800000);
    SetDynamicObjectMaterial(object_christmasMarket[247], 1, 2423, "cj_ff_counters", "CJ_Laminate1", 0x00000000);
    SetDynamicObjectMaterial(object_christmasMarket[247], 2, 2423, "cj_ff_counters", "CJ_Laminate1", 0x00000000);
    object_christmasMarket[248] = CreateDynamicObject(1974, 1474.5877, -1641.4179, 13.5819, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_golfball
    SetDynamicObjectMaterial(object_christmasMarket[248], 0, 10765, "airportgnd_sfse", "white", 0xFFA0522D);
    object_christmasMarket[249] = CreateDynamicObject(1974, 1474.4477, -1641.4179, 13.5819, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_golfball
    SetDynamicObjectMaterial(object_christmasMarket[249], 0, 10765, "airportgnd_sfse", "white", 0xFFA0522D);
    object_christmasMarket[250] = CreateDynamicObject(1974, 1474.4477, -1641.4179, 13.3719, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_golfball
    SetDynamicObjectMaterial(object_christmasMarket[250], 0, 10765, "airportgnd_sfse", "white", 0xFFA0522D);
    object_christmasMarket[251] = CreateDynamicObject(1974, 1474.2976, -1641.2479, 13.3719, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_golfball
    SetDynamicObjectMaterial(object_christmasMarket[251], 0, 10765, "airportgnd_sfse", "white", 0xFFA0522D);
    object_christmasMarket[252] = CreateDynamicObject(1974, 1473.9671, -1641.1176, 13.3719, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_golfball
    SetDynamicObjectMaterial(object_christmasMarket[252], 0, 10765, "airportgnd_sfse", "white", 0xFFA0522D);
    object_christmasMarket[253] = CreateDynamicObject(19581, 1470.1474, -1637.6738, 13.1656, 0.0000, 0.0000, 103.8000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MarcosFryingPan1
    object_christmasMarket[254] = CreateDynamicObject(1974, 1473.9671, -1641.1176, 13.5819, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_golfball
    SetDynamicObjectMaterial(object_christmasMarket[254], 0, 10765, "airportgnd_sfse", "white", 0xFFA0522D);
    object_christmasMarket[255] = CreateDynamicObject(19175, 1524.1230, -1669.9267, 18.3227, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_christmasMarket[255], 0, "arkt", OBJECT_MATERIAL_SIZE_256x128, "Arial", 80, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_christmasMarket[255], 1, 19297, "matlights", "invisible", 0x00000000);
    object_christmasMarket[256] = CreateDynamicObject(11744, 1470.9388, -1637.9001, 13.1392, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MPlate1
    object_christmasMarket[257] = CreateDynamicObject(1956, 1470.5887, -1637.5650, 13.1364, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //turn_platerL
    object_christmasMarket[258] = CreateDynamicObject(19175, 1524.1230, -1672.1075, 18.3227, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_christmasMarket[258], 0, "chtsm", OBJECT_MATERIAL_SIZE_256x128, "Arial", 80, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_christmasMarket[258], 1, 19297, "matlights", "invisible", 0x00000000);
    object_christmasMarket[259] = CreateDynamicObject(19175, 1524.1230, -1674.7375, 18.3227, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_christmasMarket[259], 0, "Weihna", OBJECT_MATERIAL_SIZE_256x128, "Arial", 80, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_christmasMarket[259], 1, 19297, "matlights", "invisible", 0x00000000);
    object_christmasMarket[260] = CreateDynamicObject(11744, 1470.9388, -1637.9001, 13.1492, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MPlate1
    object_christmasMarket[261] = CreateDynamicObject(11744, 1470.9388, -1637.9001, 13.1691, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MPlate1
    object_christmasMarket[262] = CreateDynamicObject(11744, 1470.9388, -1637.9001, 13.1591, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MPlate1
    object_christmasMarket[263] = CreateDynamicObject(19601, 1458.3509, -1600.8438, 12.5204, -47.2999, 0.0000, 42.9000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SnowPlow1
    object_christmasMarket[264] = CreateDynamicObject(19175, 1434.9426, -1676.5371, 18.3227, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_christmasMarket[264], 0, "arkt", OBJECT_MATERIAL_SIZE_256x128, "Arial", 80, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_christmasMarket[264], 1, 19297, "matlights", "invisible", 0x00000000);
    object_christmasMarket[265] = CreateDynamicObject(2369, 1470.9703, -1638.7030, 13.1063, 0.0000, 0.0000, 123.8999, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Till
    object_christmasMarket[266] = CreateDynamicObject(19175, 1524.1230, -1673.3365, 17.8528, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_christmasMarket[266], 0, "__", OBJECT_MATERIAL_SIZE_256x128, "Arial", 70, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_christmasMarket[266], 1, 19297, "matlights", "invisible", 0x00000000);
    object_christmasMarket[267] = CreateDynamicObject(19175, 1524.1230, -1670.5863, 17.8528, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_christmasMarket[267], 0, "__", OBJECT_MATERIAL_SIZE_256x128, "Arial", 70, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_christmasMarket[267], 1, 19297, "matlights", "invisible", 0x00000000);
    object_christmasMarket[268] = CreateDynamicObject(19175, 1524.1230, -1672.1357, 17.4627, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_christmasMarket[268], 0, "2023", OBJECT_MATERIAL_SIZE_256x128, "Arial", 60, 1, 0xFF006400, 0x00000000, 0);
    SetDynamicObjectMaterial(object_christmasMarket[268], 1, 19297, "matlights", "invisible", 0x00000000);
    object_christmasMarket[269] = CreateDynamicObject(19175, 1434.9426, -1673.9277, 18.3227, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_christmasMarket[269], 0, "achtsm", OBJECT_MATERIAL_SIZE_256x128, "Arial", 80, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_christmasMarket[269], 1, 19297, "matlights", "invisible", 0x00000000);
    object_christmasMarket[270] = CreateDynamicObject(19175, 1434.9426, -1671.7275, 18.3227, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_christmasMarket[270], 0, "Weihn", OBJECT_MATERIAL_SIZE_256x128, "Arial", 80, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_christmasMarket[270], 1, 19297, "matlights", "invisible", 0x00000000);
    object_christmasMarket[271] = CreateDynamicObject(19175, 1434.9426, -1676.1667, 17.8628, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_christmasMarket[271], 0, "__", OBJECT_MATERIAL_SIZE_256x128, "Arial", 70, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_christmasMarket[271], 1, 19297, "matlights", "invisible", 0x00000000);
    object_christmasMarket[272] = CreateDynamicObject(19175, 1434.9426, -1672.9663, 17.8628, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_christmasMarket[272], 0, "__", OBJECT_MATERIAL_SIZE_256x128, "Arial", 70, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_christmasMarket[272], 1, 19297, "matlights", "invisible", 0x00000000);
    object_christmasMarket[273] = CreateDynamicObject(19175, 1434.9426, -1674.0368, 17.6128, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_christmasMarket[273], 0, "2023", OBJECT_MATERIAL_SIZE_256x128, "Arial", 80, 1, 0xFF006400, 0x00000000, 0);
    SetDynamicObjectMaterial(object_christmasMarket[273], 1, 19297, "matlights", "invisible", 0x00000000);
    object_christmasMarket[274] = CreateDynamicObject(337, 1461.4542, -1616.5871, 13.3854, 0.0000, 178.0998, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shovel
    object_christmasMarket[275] = CreateDynamicObject(337, 1469.1966, -1616.4171, 13.6424, 0.0000, 178.0998, -173.8999, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shovel
    object_christmasMarket[276] = CreateDynamicObject(659, 1472.1025, -1605.1125, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
    object_christmasMarket[277] = CreateDynamicObject(337, 1473.4289, -1608.5869, 12.9643, 39.1999, 103.8000, 51.9000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shovel
    object_christmasMarket[278] = CreateDynamicObject(19633, 1465.8564, -1609.4809, 11.9406, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Ramp360Degree1
    SetDynamicObjectMaterial(object_christmasMarket[278], 0, 3922, "bistro", "mp_snow", 0xFFFFFAFA);
    object_christmasMarket[279] = CreateDynamicObject(659, 1461.1020, -1605.1125, 12.0677, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHRISTMASMARKET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree01
}
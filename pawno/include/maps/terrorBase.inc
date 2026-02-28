#include <YSI\y_hooks>

// Global interior define
#define MAPS_TERRORBASE_INTERIOR      0

// Local drawdistance & streamdistance setting
// static Float:STREAMDISTANCE = 350.0;
// static Float:DRAWDISTANCE   = 350.0;

// Terror base points
#define TERRORBASE_SPAWN_POINT          -795.0400, 1557.1365, 27.1244
#define TERRORBASE_SPAWN_POINT_FACING   90.0

// Map variables
// new object_terrorBase[94];
// new pickup_terrorBase[1];
// new text3D_terrorBase[1];

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 3297, -789.0625, 1630.1641, 27.9453, 0.25);
    RemoveBuildingForPlayer(playerid, 3344, -831.4375, 1587.5313, 25.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 11668, -816.6719, 1602.3516, 27.6875, 0.25);
    RemoveBuildingForPlayer(playerid, 11669, -821.4141, 1558.7813, 26.0313, 0.25);
    RemoveBuildingForPlayer(playerid, 11436, -821.4141, 1558.7813, 26.0313, 0.25);
    RemoveBuildingForPlayer(playerid, 11426, -800.8438, 1525.2734, 25.8594, 0.25);
    RemoveBuildingForPlayer(playerid, 11433, -788.0391, 1522.6250, 28.0938, 0.25);
    RemoveBuildingForPlayer(playerid, 11476, -825.7891, 1564.1641, 30.3984, 0.25);
    RemoveBuildingForPlayer(playerid, 3171, -831.4375, 1587.5313, 25.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 669, -826.3984, 1594.5781, 25.9609, 0.25);
    RemoveBuildingForPlayer(playerid, 11425, -816.6719, 1602.3516, 27.6875, 0.25);
    RemoveBuildingForPlayer(playerid, 11566, -792.3984, 1610.1719, 27.4531, 0.25);
    RemoveBuildingForPlayer(playerid, 669, -783.1875, 1601.2266, 26.2031, 0.25);
    RemoveBuildingForPlayer(playerid, 3242, -789.0625, 1630.1641, 27.9453, 0.25);
    RemoveBuildingForPlayer(playerid, 11567, -756.1016, 1638.7656, 25.7734, 0.25);
    RemoveBuildingForPlayer(playerid, 11434, -743.9688, 1592.1172, 30.8594, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Pickups
    //pickup_terrorBase[0] = CreateDynamicPickup(1240, 1, TERRORBASE_SPAWN_POINT, VW_MAIN, MAPS_TERRORBASE_INTERIOR); // Spawn point

    // 3DTextLabels
    //text3D_terrorBase[0] = _:CreateDynamic3DTextLabel("Terroristenlager\n" COLOR_HEX_WHITE "Tippe /Terrorwaffen zum Ausrüsten\nTippe /Gheilen zum Heilen", COLOR_BLUE, TERRORBASE_SPAWN_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_TERRORBASE_INTERIOR);

    // Vehicles
    /*vehicle_terrorBase[0] = AddStaticVehicleEx(468, -793.5461, 1606.8418, 26.6697, 232.6591, 45, 132, -1); // nrg1
	vehicle_terrorBase[1] = AddStaticVehicleEx(468, -793.6014, 1605.1918, 26.6710, 230.6999, 6, 6, -1); // nrg2
	vehicle_terrorBase[2] = AddStaticVehicleEx(468, -789.8359, 1606.4724, 26.7862, 238.1966, 12, 12, -1); // sanchez1
	vehicle_terrorBase[3] = AddStaticVehicleEx(468, -790.1686, 1604.6023, 26.7861, 236.2739, 0, 0, -1); // sanchez2neu
	vehicle_terrorBase[4] = AddStaticVehicleEx(560, -786.4879, 1605.6173, 26.5718, 179.8917, 163, 163, -1); // sultan1
	vehicle_terrorBase[5] = AddStaticVehicleEx(560, -783.1884, 1605.7771, 26.5744, 180.0599, 131, 131, -1); // sultan2
	vehicle_terrorBase[6] = AddStaticVehicleEx(579, -779.9321, 1605.4313, 27.0454, 181.6307, 0, 0, -1); // huntley1
	vehicle_terrorBase[7] = AddStaticVehicleEx(579, -776.4337, 1605.4574, 27.0494, 181.1379, 1, 1, -1); // huntley2
	vehicle_terrorBase[8] = AddStaticVehicleEx(554, -773.0320, 1605.4667, 26.9489, 180.0479, 4, 4, -1); // buffalo1
	vehicle_terrorBase[9] = AddStaticVehicleEx(402, -769.5782, 1605.4597, 26.9207, 179.8260, 87, 87, -1); // sabre1
	vehicle_terrorBase[10] = AddStaticVehicleEx(475, -764.3019, 1599.6383, 26.6535, 86.9992, 81, 81, -1); // cheetah1
	vehicle_terrorBase[11] = AddStaticVehicleEx(526, -764.6872, 1596.2074, 26.8311, 87.7339, 77, 77, -1); // bullet1
	vehicle_terrorBase[12] = AddStaticVehicleEx(526, -764.9205, 1592.8184, 26.8759, 86.6844, 123, 123, -1); // infi1
	vehicle_terrorBase[13] = AddStaticVehicleEx(542, -765.1465, 1589.6088, 26.8759, 86.8303, 17, 17, -1); // infi2
	vehicle_terrorBase[14] = AddStaticVehicleEx(476, -780.1793, 1635.1915, 27.7771, 268.5923, 145, 0, -1); // rustler1
	vehicle_terrorBase[15] = AddStaticVehicleEx(487, -781.8011, 1618.2927, 27.3038, 270.0000, 97, 23, -1); // heli*/

    // Objects
    /*object_terrorBase[0] = CreateDynamicObject(11457, -737.32343, 1592.15918, 25.50940, 0.00000, 0.00000, -50.52000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[1] = CreateDynamicObject(17070, -780.39221, 1598.08118, 26.11068, -0.18000, 0.12000, 182.33990, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[2] = CreateDynamicObject(11458, -797.15222, 1589.49109, 26.11920, 0.00000, 0.00000, -110.22000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[3] = CreateDynamicObject(11441, -819.52667, 1606.99280, 26.07931, 0.00000, 0.00000, 15.30007, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[4] = CreateDynamicObject(16635, -768.94513, 1560.44629, 26.65340, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[5] = CreateDynamicObject(16635, -768.94513, 1554.36206, 26.65340, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[6] = CreateDynamicObject(16635, -770.80774, 1552.48560, 26.65340, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[7] = CreateDynamicObject(16635, -774.43878, 1552.48560, 26.65340, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[8] = CreateDynamicObject(16635, -778.07941, 1552.48560, 26.65340, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[9] = CreateDynamicObject(16635, -779.95422, 1554.38086, 26.65340, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[10] = CreateDynamicObject(16635, -779.95422, 1557.94055, 26.65340, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[11] = CreateDynamicObject(16635, -770.80127, 1562.28247, 26.65340, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[12] = CreateDynamicObject(16635, -774.43231, 1562.28247, 26.65340, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[13] = CreateDynamicObject(16635, -778.08582, 1562.28247, 26.65340, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[14] = CreateDynamicObject(16635, -779.95422, 1560.44104, 26.65340, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[15] = CreateDynamicObject(754, -769.99103, 1565.98279, 26.16406, 356.85840, 0.00000, -2.09439, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[16] = CreateDynamicObject(754, -778.20844, 1564.01257, 26.16406, 356.85840, 0.00000, -2.09439, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[17] = CreateDynamicObject(754, -782.25018, 1553.48059, 26.16406, 356.85840, 0.00000, -2.09439, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[18] = CreateDynamicObject(16690, -797.62775, 1524.65686, 30.10301, 0.00000, 0.00000, -90.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[19] = CreateDynamicObject(761, -783.81104, 1525.10754, 26.02352, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[20] = CreateDynamicObject(11426, -778.93927, 1520.73840, 26.03720, 0.00000, 0.00000, -231.87830, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[21] = CreateDynamicObject(3276, -797.64301, 1602.94263, 26.90908, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[22] = CreateDynamicObject(3276, -791.93066, 1610.20154, 26.90910, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[23] = CreateDynamicObject(3276, -774.04199, 1609.89014, 26.90910, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[24] = CreateDynamicObject(3276, -763.85162, 1606.07312, 26.90910, 0.00000, 0.00000, -41.28002, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[25] = CreateDynamicObject(3276, -759.75000, 1596.41748, 26.90910, 0.00000, 0.00000, -92.82000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[26] = CreateDynamicObject(669, -800.63434, 1603.43079, 25.96094, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[27] = CreateDynamicObject(669, -751.98029, 1597.44775, 25.96094, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[28] = CreateDynamicObject(761, -791.68097, 1589.85413, 26.21094, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[29] = CreateDynamicObject(761, -790.03009, 1586.65808, 26.00476, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[30] = CreateDynamicObject(669, -773.52563, 1549.32153, 25.93132, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[31] = CreateDynamicObject(754, -771.62738, 1524.50171, 26.04406, 356.85840, 0.00000, -2.09439, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[32] = CreateDynamicObject(761, -819.31140, 1539.35889, 26.02605, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[33] = CreateDynamicObject(3276, -739.92981, 1646.65173, 27.19612, 0.00000, 0.00000, -17.52001, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[34] = CreateDynamicObject(3276, -752.86957, 1648.49377, 27.12577, 0.00000, 0.00000, 3.71999, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[35] = CreateDynamicObject(3276, -767.32086, 1647.58582, 27.34302, 0.00000, 0.00000, 3.71999, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[36] = CreateDynamicObject(3276, -779.00940, 1642.75134, 26.93046, 0.12000, -2.58000, 38.40003, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[37] = CreateDynamicObject(3276, -789.58282, 1634.16663, 26.90414, 0.00000, 0.00000, 43.49996, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[38] = CreateDynamicObject(3276, -801.74524, 1624.65405, 26.90414, 0.00000, 0.00000, 37.37996, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[39] = CreateDynamicObject(3276, -738.67987, 1572.10266, 26.87020, 0.00000, 0.00000, -86.57999, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[40] = CreateDynamicObject(761, -737.45642, 1564.36926, 25.97656, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[41] = CreateDynamicObject(761, -751.40186, 1556.01343, 25.72652, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[42] = CreateDynamicObject(761, -751.82776, 1545.86816, 25.72652, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[43] = CreateDynamicObject(3425, -816.87140, 1531.33447, 36.31941, 0.00000, 0.00000, -213.35979, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[44] = CreateDynamicObject(3275, -832.86310, 1609.91174, 26.79405, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[45] = CreateDynamicObject(16410, -777.40704, 1551.63232, 26.36786, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[46] = CreateDynamicObject(16410, -776.54547, 1557.59570, 26.36786, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[47] = CreateDynamicObject(16410, -769.14532, 1554.92017, 26.31444, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[48] = CreateDynamicObject(16410, -774.72626, 1557.56958, 26.34948, 0.00000, 0.00000, -45.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[49] = CreateDynamicObject(1280, -773.86810, 1564.59460, 26.45580, 0.00000, 0.00000, 282.11951, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[50] = CreateDynamicObject(758, -788.98730, 1547.59692, 26.02308, 0.00000, 0.00000, 17.28000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[51] = CreateDynamicObject(750, -760.83514, 1582.57385, 25.93791, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[52] = CreateDynamicObject(669, -808.31842, 1520.72009, 26.13924, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[53] = CreateDynamicObject(3887, -824.78156, 1569.31604, 33.48524, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[54] = CreateDynamicObject(669, -827.55627, 1537.12354, 25.67815, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[55] = CreateDynamicObject(761, -839.74591, 1604.47632, 25.90055, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[56] = CreateDynamicObject(11426, -833.01538, 1603.80005, 26.01405, 0.00000, 0.00000, -270.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[57] = CreateDynamicObject(761, -823.08392, 1601.50952, 25.87384, 356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[58] = CreateDynamicObject(1516, -796.21735, 1561.12134, 26.23093, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[59] = CreateDynamicObject(1516, -796.21735, 1553.24011, 26.28093, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[60] = CreateDynamicObject(2035, -796.13110, 1553.40686, 26.82718, 0.00000, 0.00000, -40.99999, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[61] = CreateDynamicObject(2035, -795.94836, 1561.11353, 26.76718, 0.00000, 0.00000, -104.99992, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[62] = CreateDynamicObject(2036, -795.74670, 1562.26086, 26.69131, -4.09998, -64.30005, -11.39999, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[63] = CreateDynamicObject(1226, -799.48346, 1543.00134, 29.67719, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[64] = CreateDynamicObject(2036, -795.80212, 1561.89063, 26.64223, -4.09998, -64.30005, -11.39999, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[65] = CreateDynamicObject(2044, -796.41846, 1552.96912, 26.82718, 0.00000, 0.00000, -27.49999, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[66] = CreateDynamicObject(1226, -799.41339, 1570.43469, 29.67719, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[67] = CreateDynamicObject(19121, -816.77527, 1543.01416, 26.03092, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[68] = CreateDynamicObject(19121, -816.77527, 1554.69824, 26.03092, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[69] = CreateDynamicObject(19121, -816.77527, 1555.59875, 26.03092, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[70] = CreateDynamicObject(19121, -824.59613, 1569.04773, 26.05092, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[71] = CreateDynamicObject(19121, -824.58612, 1581.89124, 26.05092, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[72] = CreateDynamicObject(18652, -832.63367, 1576.07227, 30.00097, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[73] = CreateDynamicObject(19121, -824.57422, 1568.32800, 26.03092, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[74] = CreateDynamicObject(18652, -832.63367, 1562.46216, 30.00097, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[75] = CreateDynamicObject(18652, -832.63367, 1547.90125, 30.00097, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[76] = CreateDynamicObject(19121, -819.66541, 1595.43652, 26.05092, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[77] = CreateDynamicObject(19121, -824.59307, 1582.61841, 26.06718, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[78] = CreateDynamicObject(1226, -798.14001, 1581.94824, 29.67719, 0.00000, 0.00000, 91.59993, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[79] = CreateDynamicObject(1231, -788.27686, 1608.47571, 27.28718, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[80] = CreateDynamicObject(1231, -781.52338, 1608.46667, 27.28718, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[81] = CreateDynamicObject(1231, -794.85034, 1608.46399, 27.28718, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[82] = CreateDynamicObject(1231, -774.73743, 1608.49097, 27.28718, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[83] = CreateDynamicObject(1231, -768.15601, 1608.50549, 27.28718, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[84] = CreateDynamicObject(1231, -761.75684, 1601.00793, 27.28720, 0.00000, 0.00000, -90.70000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[85] = CreateDynamicObject(1231, -762.03650, 1594.44971, 27.28720, 0.00000, 0.00000, -90.70000, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[86] = CreateDynamicObject(1231, -762.33191, 1587.85315, 27.28720, 0.00000, 0.00000, -90.69990, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[87] = CreateDynamicObject(1575, -796.44714, 1561.18420, 26.75718, 0.00000, 0.00000, -88.80001, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[88] = CreateDynamicObject(3350, -790.25598, 1562.49622, 25.98718, 0.00000, 0.00000, -131.40001, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[89] = CreateDynamicObject(3350, -801.07758, 1525.60364, 25.98718, 0.00000, 0.00000, -155.80002, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[90] = CreateDynamicObject(3350, -819.38757, 1604.07251, 25.99092, 0.00000, 0.00000, 42.80001, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[91] = CreateDynamicObject(8483, -722.12677, 1541.65881, 66.10001, 0.00000, 0.00000, 172.90008, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[92] = CreateDynamicObject(898, -722.016052, 1544.51916, 65.36016, 0.00000, 47.09999, 36.29999, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_terrorBase[93] = CreateDynamicObject(898, -721.998291, 1540.16565, 65.56657,  -12.20001, 57.10005, 25.39998, VW_MAIN, MAPS_TERRORBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);*/
}

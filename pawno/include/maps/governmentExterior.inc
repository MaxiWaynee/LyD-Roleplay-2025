#include <YSI\y_hooks>

// Global interior define
#define MAPS_GOVERNMENTEXTERIOR_INTERIOR      0
#define MAPS_GOVERNMENTINTERIOR_INTERIOR      3

// Local drawdistance & streamdistance setting
//static Float:STREAMDISTANCE = 150.0;
//static Float:DRAWDISTANCE   = 140.0;

#define GOVERNMENT_INTERIOR_ENTER_COORDS        1123.2910, -2036.9863, 69.8875
#define GOVERNMENT_INTERIOR_ENTER_FACING        90.0
#define GOVERNMENT_INTERIOR_EXIT_COORDS         367.6177, 162.2955, 1025.7891
#define GOVERNMENT_INTERIOR_EXIT_FACING         90.0
#define GOVERNMENT_ROOF_ENTER_COORDS            0.0, 0.0, 0.0
#define GOVERNMENT_ROOF_ENTER_FACING            0.0
#define GOVERNMENT_ROOF_EXIT_COORDS             1565.0472, -1684.4788, 28.3956
#define GOVERNMENT_ROOF_EXIT_FACING             0.0
#define GOVERNMENT_GARAGE_ENTER_COORDS          0.0, 0.0, 0.0
#define GOVERNMENT_GARAGE_ENTER_FACING          0.0
#define GOVERNMENT_GARAGE_EXIT_COORDS           1524.4835, -1677.9160, 6.2188
#define GOVERNMENT_GARAGE_EXIT_FACING           90.0
#define GOVERNMENT_GATE_FOR_RANGE_COORDS        1588.2906, -1637.9502, 13.4238
#define GOVERNMENT_GATE_OPEN_Z                  7.75
#define GOVERNMENT_GATE_CLOSED_Z                15.0256
#define GOVERNMENT_BARRIER_FOR_RANGE_COORDS     1544.6835, -1627.1996, 13.3828
#define GOVERNMENT_BARRIER_OPEN_RY              0.0000
#define GOVERNMENT_BARRIER_CLOSED_RY            90.0000
#define GOVERNMENT_STATEREPAIR_COORDS           1258.0894, -2044.4088, 59.4669

// Map variables
/*new object_governmentExterior[162];
new object_government_barrier;
new object_government_gate;*/
new text3D_governmentExterior[1];
new pickup_governmentExterior[1];

/*CMD:rgate(playerid, params[]) {
	if (!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 9 || Spieler[playerid][pFraktion] == 18))
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Staatsbeamter.");

	if (IsPlayerInRangeOfPoint(playerid, 12.5, GOVERNMENT_GATE_FOR_RANGE_COORDS)) {
        new Float:fX, Float:fY, Float:fZ;
        GetDynamicObjectPos(object_government_gate, fX, fY, fZ);
        
        if (fZ == GOVERNMENT_GATE_OPEN_Z)
            MoveDynamicObject(object_government_gate, fX, fY, GOVERNMENT_GATE_CLOSED_Z, 3.25);
        else
            MoveDynamicObject(object_government_gate, fX, fY, GOVERNMENT_GATE_OPEN_Z, 3.25);

        return 1;
    } else if (IsPlayerInRangeOfPoint(playerid, 10.0, GOVERNMENT_BARRIER_FOR_RANGE_COORDS)) {
        new Float:fX, Float:fY, Float:fZ, Float:fRX, Float:fRY, Float:fRZ;
        GetDynamicObjectPos(object_government_barrier, fX, fY, fZ);
        GetDynamicObjectRot(object_government_barrier, fRX, fRY, fRZ);

        if (fRY == GOVERNMENT_BARRIER_OPEN_RY)
            MoveDynamicObject(object_government_barrier, fX, fY, fZ + 0.0001, 0.0002, fRX, GOVERNMENT_BARRIER_CLOSED_RY, fRZ);
        else
            MoveDynamicObject(object_government_barrier, fX, fY, fZ - 0.0001, 0.0002, fRX, GOVERNMENT_BARRIER_OPEN_RY, fRZ);

        return 1;
    }
    
    return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der N�he des Tores.");
}*/

hook OnPlayerConnect(playerid) {
    /*RemoveBuildingForPlayer(playerid, 647, 1546.5999, -1693.3900, 14.4375, 0.10);
    RemoveBuildingForPlayer(playerid, 620, 1547.5699, -1689.9799, 13.0468, 0.10);
    RemoveBuildingForPlayer(playerid, 647, 1546.8699, -1687.0999, 14.4375, 0.10);
    RemoveBuildingForPlayer(playerid, 647, 1546.5999, -1664.6300, 14.4375, 0.10);
    RemoveBuildingForPlayer(playerid, 647, 1546.8699, -1658.3399, 14.4375, 0.10);
    RemoveBuildingForPlayer(playerid, 620, 1547.5699, -1661.0300, 13.0468, 0.10);*/
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {

}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(GOVERNMENT_INTERIOR_ENTER_COORDS, 34, 0, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR); // R icon

    // Pickups
    pickup_governmentExterior[0] = CreateDynamicPickup(1239, 1, GOVERNMENT_STATEREPAIR_COORDS, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR); // Staterepair

    // 3DTextLabels
    text3D_governmentExterior[0] = _:CreateDynamic3DTextLabel("Staats-Reparatur\n" COLOR_HEX_WHITE "Tippe /Staatrepair", COLOR_YELLOW, GOVERNMENT_STATEREPAIR_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_GOVERNMENTEXTERIOR_INTERIOR); // Staterepair

    // Vehicles
    /*vehicle_governmentExterior[0] = AddStaticVehicle(409, 1528.7433, -1683.8628, 5.6721, 269.4835, 1, 1); // gov
    vehicle_governmentExterior[1] = AddStaticVehicle(409, 1528.9263, -1688.0830, 5.6606, 268.8083, 1, 1); // gov
    vehicle_governmentExterior[2] = AddStaticVehicle(490, 1545.6693, -1672.2111, 6.0186, 90.8823, 1, 1); // gov
    vehicle_governmentExterior[3] = AddStaticVehicle(490, 1545.7642, -1667.8514, 6.0373, 90.4662, 1, 1); // gov
    vehicle_governmentExterior[4] = AddStaticVehicle(596, 1545.0056, -1663.1222, 5.6128, 90.6918, 1, 1); // gov
    vehicle_governmentExterior[5] = AddStaticVehicle(596, 1544.9977, -1658.9619, 5.6130, 90.0701, 1, 1); // gov
    vehicle_governmentExterior[6] = AddStaticVehicle(580, 1545.0693, -1655.1567, 5.6875, 89.8633, 1, 1); // gov
    vehicle_governmentExterior[7] = AddStaticVehicle(580, 1545.0206, -1651.0193, 5.6874, 89.1158, 1, 1); // gov
    vehicle_governmentExterior[8] = AddStaticVehicle(545, 1538.6676, -1643.8425, 5.7027, 180.0343, 1, 1); // gov
    vehicle_governmentExterior[9] = AddStaticVehicle(545, 1534.7583, -1644.1050, 5.7024, 180.0741, 1, 1); // gov
    vehicle_governmentExterior[10] = AddStaticVehicle(475, 1530.5110, -1643.8022, 5.6919, 180.0314, 1, 1); // gov
    vehicle_governmentExterior[11] = AddStaticVehicle(475, 1526.4708, -1644.0272, 5.6941, 180.5679, 1, 1); // gov
    vehicle_governmentExterior[12] = AddStaticVehicle(523, 1529.8032, -1671.8353, 5.7915, 269.9579, 1, 1); // gov
    vehicle_governmentExterior[13] = AddStaticVehicle(523, 1529.7935, -1669.4871, 5.7856, 272.5232, 1, 1); // gov
    vehicle_governmentExterior[14] = AddStaticVehicle(523, 1529.6549, -1667.1039, 5.7902, 271.1700, 1, 1); // gov
    vehicle_governmentExterior[15] = AddStaticVehicle(523, 1529.4812, -1664.3744, 5.7885, 271.2509, 1, 1); // gov
    vehicle_governmentExterior[16] = AddStaticVehicle(487, 1566.1991, -1703.9496, 28.5721, 89.6789, 1, 1); // gov*/
    
    // Objects
    /*object_governmentExterior[0] = CreateDynamicObject(2614, 1524.1695, -1677.9045, 9.3204, 0.0000, 0.0000, 89.9999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_US_FLAG
    object_governmentExterior[1] = CreateDynamicObject(1215, 1542.6268, -1650.6562, 27.3264, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[2] = CreateDynamicObject(1215, 1542.6468, -1700.6096, 27.3264, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[3] = CreateDynamicObject(1215, 1542.6368, -1637.3358, 27.3264, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[4] = CreateDynamicObject(1495, 1582.6046, -1638.1169, 12.3715, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT01
    object_governmentExterior[5] = CreateDynamicObject(1215, 1553.5970, -1650.6562, 27.3264, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[6] = CreateDynamicObject(1215, 1577.7286, -1714.3608, 27.3264, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[7] = CreateDynamicObject(19174, 1543.4514, -1633.8006, 14.7327, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_governmentExterior[7], 0, "** ACHTUNG **", OBJECT_MATERIAL_SIZE_512x128, "Arial", 45, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[7], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[8] = CreateDynamicObject(7090, 1557.8553, -1669.9089, 40.1926, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vegasflag1
    object_governmentExterior[10] = CreateDynamicObject(18762, 1547.4182, -1664.6462, 14.4097, 0.0000, 0.0000, 18.5998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[10], 0, 2176, "casino_props", "marblebox", 0x00000000);
    object_governmentExterior[12] = CreateDynamicObject(1215, 1542.6468, -1714.3608, 27.3264, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[13] = CreateDynamicObject(18766, 1545.1195, -1617.5278, 13.4392, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[13], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[14] = CreateDynamicObject(18766, 1539.6185, -1613.0279, 13.4392, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[14], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[15] = CreateDynamicObject(18766, 1545.1164, -1602.5378, 13.4392, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[15], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[16] = CreateDynamicObject(18766, 1539.6164, -1607.0362, 13.4384, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[16], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[17] = CreateDynamicObject(19172, 1568.6234, -1689.6147, 8.2503, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[17], 0, "Zum Dach", OBJECT_MATERIAL_SIZE_256x128, "Arial", 40, 1, 0xFF8FBC8F, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[17], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[18] = CreateDynamicObject(638, 1563.1112, -1685.1639, 27.7553, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_governmentExterior[19] = CreateDynamicObject(19172, 1546.4726, -1662.3076, 15.0857, 0.0000, 0.0000, -71.7995, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[19], 0, "Kanzler: /", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[19], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[20] = CreateDynamicObject(18766, 1555.1158, -1602.5378, 13.4392, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[20], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[21] = CreateDynamicObject(18766, 1565.1151, -1602.5378, 13.4392, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[21], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[22] = CreateDynamicObject(18766, 1575.1152, -1602.5378, 13.4392, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[22], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[23] = CreateDynamicObject(18766, 1585.1145, -1602.5378, 13.4392, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[23], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[24] = CreateDynamicObject(18766, 1544.6003, -1618.6334, 13.4385, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[24], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[25] = CreateDynamicObject(18766, 1595.1140, -1602.5378, 13.4392, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[25], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[26] = CreateDynamicObject(3928, 1564.8768, -1703.9586, 27.3899, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad
    object_governmentExterior[27] = CreateDynamicObject(18766, 1603.3531, -1602.5356, 13.4383, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[27], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[28] = CreateDynamicObject(18766, 1607.8537, -1608.0356, 13.4383, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[28], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[29] = CreateDynamicObject(18766, 1607.8537, -1618.0350, 13.4383, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[29], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[30] = CreateDynamicObject(18766, 1607.8514, -1633.3719, 13.4371, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[30], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[31] = CreateDynamicObject(18766, 1607.8537, -1628.0340, 13.4383, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[31], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[32] = CreateDynamicObject(3526, 1561.1434, -1700.1466, 27.4689, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vegasairportlight
    object_governmentExterior[33] = CreateDynamicObject(18766, 1603.3199, -1638.3758, 13.4362, 0.0000, 0.0000, 6.6999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[33], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[34] = CreateDynamicObject(3526, 1568.4433, -1700.1466, 27.4689, 0.0000, 0.0000, -179.4001, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vegasairportlight
    object_governmentExterior[35] = CreateDynamicObject(3526, 1568.4648, -1707.9471, 27.4689, 0.0000, 0.0000, -179.4001, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vegasairportlight
    object_governmentExterior[36] = CreateDynamicObject(1343, 1543.4250, -1616.5427, 13.1014, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Dumpster3
    object_governmentExterior[37] = CreateDynamicObject(3526, 1561.1434, -1707.9267, 27.4689, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vegasairportlight
    object_governmentExterior[38] = CreateDynamicObject(1345, 1540.8686, -1615.8725, 13.1316, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Dumpster
    object_governmentExterior[39] = CreateDynamicObject(1569, 1563.5096, -1683.7451, 27.2551, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ADAM_V_DOOR
    object_governmentExterior[40] = CreateDynamicObject(19174, 1543.4514, -1633.8006, 14.2826, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_governmentExterior[40], 0, "Grundst�ck der Regierung", OBJECT_MATERIAL_SIZE_512x128, "Arial", 45, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[19], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[41] = CreateDynamicObject(1569, 1566.5008, -1683.7242, 27.2551, 0.0000, 0.0000, -179.7998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ADAM_V_DOOR
    object_governmentExterior[42] = CreateDynamicObject(638, 1566.8519, -1685.1639, 27.7553, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_governmentExterior[43] = CreateDynamicObject(1215, 1563.0802, -1686.7695, 27.3659, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[44] = CreateDynamicObject(1215, 1566.8601, -1686.7193, 27.3659, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[45] = CreateDynamicObject(1215, 1553.6573, -1678.5168, 27.3264, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[46] = CreateDynamicObject(1215, 1553.7071, -1700.6096, 27.3264, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[47] = CreateDynamicObject(18766, 1543.9497, -1636.1833, 13.4994, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[47], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[48] = CreateDynamicObject(1215, 1553.6573, -1672.7269, 27.3264, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[49] = CreateDynamicObject(1215, 1577.7685, -1637.3358, 27.3264, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[50] = CreateDynamicObject(1495, 1582.6046, -1638.1169, 14.8697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT01
    object_governmentExterior[51] = CreateDynamicObject(7090, 1557.8553, -1681.2196, 40.1926, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vegasflag1
    object_governmentExterior[52] = CreateDynamicObject(18981, 1549.0539, -1632.7884, 11.4982, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_governmentExterior[52], 0, 16640, "a51", "Metal3_128", 0x00000000);
    object_governmentExterior[53] = CreateDynamicObject(19464, 1546.3155, -1661.4233, 13.8915, 0.0000, 0.0000, 18.4999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_governmentExterior[53], 0, 14623, "mafcasmain", "marble_wall2", 0x00000000);
    object_governmentExterior[54] = CreateDynamicObject(19172, 1546.6230, -1662.8137, 15.8212, 0.0000, 0.0000, -72.0998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[54], 0, "Regierung", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[54], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[55] = CreateDynamicObject(19441, 1549.6025, -1612.7491, 12.3596, -0.2998, -89.9999, -56.5998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall081
    SetDynamicObjectMaterial(object_governmentExterior[55], 0, 12871, "ce_ground01", "dirttracksgrass256", 0x00000000);
    object_governmentExterior[56] = CreateDynamicObject(19441, 1547.3603, -1610.9687, 12.3521, -0.2998, -89.9999, -20.7999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall081
    SetDynamicObjectMaterial(object_governmentExterior[56], 0, 12871, "ce_ground01", "dirttracksgrass256", 0x00000000);
    object_governmentExterior[57] = CreateDynamicObject(19441, 1544.5438, -1610.8033, 12.3760, -0.2998, -89.9999, 14.0999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall081
    SetDynamicObjectMaterial(object_governmentExterior[57], 0, 12871, "ce_ground01", "dirttracksgrass256", 0x00000000);
    object_governmentExterior[58] = CreateDynamicObject(19441, 1541.6987, -1615.3081, 12.3810, -0.2998, -89.9999, -90.9001, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall081
    SetDynamicObjectMaterial(object_governmentExterior[58], 0, 12871, "ce_ground01", "dirttracksgrass256", 0x00000000);
    object_governmentExterior[59] = CreateDynamicObject(19441, 1551.1927, -1615.6844, 12.3893, -0.0996, -91.4998, -66.1997, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall081
    SetDynamicObjectMaterial(object_governmentExterior[59], 0, 12871, "ce_ground01", "dirttracksgrass256", 0x00000000);
    object_governmentExterior[60] = CreateDynamicObject(19441, 1542.5694, -1612.3332, 12.3814, -0.2998, -90.3998, 60.6999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall081
    SetDynamicObjectMaterial(object_governmentExterior[60], 0, 12871, "ce_ground01", "dirttracksgrass256", 0x00000000);
    object_governmentExterior[61] = CreateDynamicObject(19543, 1569.9460, -1610.4514, 12.3850, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane62_5x15Grass1
    object_governmentExterior[62] = CreateDynamicObject(19441, 1543.2823, -1615.3369, 12.3821, -0.2998, -89.9999, 88.7995, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall081
    SetDynamicObjectMaterial(object_governmentExterior[62], 0, 12871, "ce_ground01", "dirttracksgrass256", 0x00000000);
    object_governmentExterior[63] = CreateDynamicObject(19172, 1547.0307, -1687.9188, 15.0913, 0.0000, 0.0000, -109.0998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[63], 0, " ", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[63], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[64] = CreateDynamicObject(3515, 1563.0958, -1611.1197, 12.2129, 0.0000, 18.6000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgsfountain
    object_governmentExterior[65] = CreateDynamicObject(19175, 1564.9919, -1683.8332, 30.2464, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_governmentExterior[65], 0, "Zum Untergeschoss", OBJECT_MATERIAL_SIZE_256x128, "Arial", 30, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[65], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[66] = CreateDynamicObject(3515, 1570.7362, -1610.8536, 12.2384, 0.0000, 18.6000, -177.7998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgsfountain
    object_governmentExterior[67] = CreateDynamicObject(870, 1564.9781, -1615.4393, 12.6068, 0.0000, 0.0000, 40.0998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_governmentExterior[68] = CreateDynamicObject(18762, 1567.0312, -1610.8774, 11.4315, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[68], 0, 3922, "bistro", "Marble2", 0x00000000);
    object_governmentExterior[69] = CreateDynamicObject(3462, 1567.0024, -1610.8658, 14.9287, 0.0000, 0.0000, 90.3000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //csrangel_lvs
    object_governmentExterior[70] = CreateDynamicObject(18766, 1544.9300, -1636.1833, 13.4994, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[70], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[71] = CreateDynamicObject(18981, 1549.0539, -1657.7475, 11.4982, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_governmentExterior[71], 0, 16640, "a51", "Metal3_128", 0x00000000);
    object_governmentExterior[72] = CreateDynamicObject(19355, 1568.7646, -1610.9643, 12.3330, 0.0000, 89.9999, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall003
    SetDynamicObjectMaterial(object_governmentExterior[72], 0, 11496, "des_nwstuff", "brdwalkwater_la", 0x00000000);
    object_governmentExterior[73] = CreateDynamicObject(19172, 1545.7346, -1660.0570, 15.0857, 0.0000, 0.0000, -71.7995, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[73], 0, "Pr�sident: /", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[73], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[74] = CreateDynamicObject(19355, 1565.2823, -1610.9643, 12.3330, 0.0000, 89.9999, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall003
    SetDynamicObjectMaterial(object_governmentExterior[74], 0, 11496, "des_nwstuff", "brdwalkwater_la", 0x00000000);
    object_governmentExterior[75] = CreateDynamicObject(18981, 1520.6948, -1657.7475, 11.4982, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_governmentExterior[75], 0, 16640, "a51", "Metal3_128", 0x00000000);
    object_governmentExterior[76] = CreateDynamicObject(18981, 1524.0555, -1632.7884, 11.4982, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_governmentExterior[76], 0, 16640, "a51", "Metal3_128", 0x00000000);
    object_governmentExterior[77] = CreateDynamicObject(19172, 1545.6817, -1659.9045, 13.9757, 0.0000, 0.0000, -71.7995, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[77], 0, "Richter: /", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[77], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[78] = CreateDynamicObject(2190, 1579.9582, -1632.9918, 13.6469, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PC_1
    object_governmentExterior[79] = CreateDynamicObject(19808, 1579.9311, -1633.6103, 13.6822, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    object_governmentExterior[80] = CreateDynamicObject(3931, 1564.8939, -1612.9466, 12.5186, 1.1999, -73.1997, 20.1998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d_rock02
    object_governmentExterior[81] = CreateDynamicObject(19172, 1546.4809, -1662.3288, 13.9757, 0.0000, 0.0000, -71.7995, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[81], 0, "Richter: /", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[81], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[82] = CreateDynamicObject(1886, 1587.0593, -1651.9715, 14.0025, 0.0000, 0.0000, 173.3000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_governmentExterior[83] = CreateDynamicObject(18762, 1567.0201, -1612.7967, 10.4947, 30.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[83], 0, 10871, "blacksky_sfse", "ws_blackmarble", 0xFFFFFFFF);
    object_governmentExterior[84] = CreateDynamicObject(2921, 1557.9835, -1637.5891, 20.3640, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_cam
    object_governmentExterior[85] = CreateDynamicObject(2921, 1530.3380, -1658.9906, 9.4735, 0.0000, 0.0000, -126.6996, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_cam
    object_governmentExterior[86] = CreateDynamicObject(3931, 1565.8310, -1612.9636, 12.3732, 1.1999, -73.1997, -2.0999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d_rock02
    object_governmentExterior[87] = CreateDynamicObject(1663, 1579.9868, -1634.7187, 13.0326, 0.0000, 0.0000, -180.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_B
    object_governmentExterior[88] = CreateDynamicObject(3931, 1566.5815, -1612.8574, 12.2440, 1.1999, -73.1997, -18.1000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d_rock02
    object_governmentExterior[89] = CreateDynamicObject(3931, 1567.2320, -1612.8326, 12.2410, 1.1999, -94.1996, -2.0999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d_rock02
    object_governmentExterior[90] = CreateDynamicObject(3931, 1567.8360, -1612.7038, 12.1967, 1.1999, -94.1996, -106.9000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d_rock02
    object_governmentExterior[91] = CreateDynamicObject(2861, 1578.1800, -1633.4267, 13.6604, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gb_foodwrap03
    object_governmentExterior[92] = CreateDynamicObject(3931, 1568.3116, -1612.7569, 12.1625, 2.5999, -90.0998, -165.6999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d_rock02
    object_governmentExterior[93] = CreateDynamicObject(19873, 1581.5780, -1634.0196, 13.7166, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ToiletPaperRoll1
    object_governmentExterior[94] = CreateDynamicObject(3931, 1569.1007, -1612.9071, 12.3163, 2.5999, -90.0998, 112.5998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d_rock02
    object_governmentExterior[95] = CreateDynamicObject(18766, 1550.0123, -1620.0030, 12.0881, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[95], 0, 17545, "burnsground", "indund_64", 0x00000000);
    object_governmentExterior[96] = CreateDynamicObject(3931, 1564.7838, -1609.4947, 11.9827, 2.1998, -94.1996, -8.8001, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d_rock02
    object_governmentExterior[97] = CreateDynamicObject(3931, 1567.7854, -1609.3968, 12.2124, 59.9999, -94.1996, -176.6000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d_rock02
    object_governmentExterior[98] = CreateDynamicObject(3931, 1568.8006, -1609.3043, 12.1534, 2.1998, -94.1996, -151.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d_rock02
    object_governmentExterior[99] = CreateDynamicObject(3931, 1566.1031, -1609.3894, 12.1288, 2.1998, -94.1996, -83.4000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d_rock02
    object_governmentExterior[100] = CreateDynamicObject(3931, 1566.9226, -1609.3579, 12.1415, 2.1998, -94.1996, 159.1999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d_rock02
    object_governmentExterior[101] = CreateDynamicObject(2894, 1581.3730, -1633.5323, 13.6604, 0.0000, 0.0000, -45.7999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_rhymesbook
    SetDynamicObjectMaterial(object_governmentExterior[101], 0, 2577, "cj_sex", "CJ_PAINTING9", 0x00000000);
    object_governmentExterior[102] = CreateDynamicObject(3931, 1565.2943, -1609.4156, 12.0754, 2.1998, -94.1996, 159.1999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //d_rock02
    object_governmentExterior[103] = CreateDynamicObject(19172, 1567.0246, -1613.9532, 12.7082, -60.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[103], 0, "LyD since", OBJECT_MATERIAL_SIZE_256x128, "Roman", 25, 1, 0xFFFFD700, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[103], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[104] = CreateDynamicObject(870, 1568.7833, -1615.4908, 12.6068, 0.0000, 0.0000, -100.9999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_governmentExterior[105] = CreateDynamicObject(19172, 1567.0246, -1614.1612, 12.5881, -60.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[105], 0, "2012", OBJECT_MATERIAL_SIZE_256x128, "Roman", 20, 1, 0xFFFFD700, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[105], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[106] = CreateDynamicObject(870, 1561.3861, -1613.6009, 12.6068, 0.0000, 0.0000, 40.0998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_governmentExterior[107] = CreateDynamicObject(817, 1556.4758, -1611.1466, 12.8200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
    SetDynamicObjectMaterial(object_governmentExterior[107], 0, -1, "none", "none", 0xFFFFFF00);
    object_governmentExterior[108] = CreateDynamicObject(870, 1572.4106, -1613.8835, 12.6068, 0.0000, 0.0000, 37.2999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_governmentExterior[109] = CreateDynamicObject(8623, 1567.0511, -1606.3774, 13.1468, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush03_lvs
    object_governmentExterior[110] = CreateDynamicObject(1886, 1543.4597, -1712.5400, 11.1526, 17.2999, 0.0000, 180.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_governmentExterior[111] = CreateDynamicObject(817, 1578.5566, -1615.1866, 12.8200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
    SetDynamicObjectMaterial(object_governmentExterior[111], 0, -1, "none", "none", 0xFFFFFF00);
    object_governmentExterior[112] = CreateDynamicObject(817, 1580.1870, -1608.8066, 12.8200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
    SetDynamicObjectMaterial(object_governmentExterior[112], 0, -1, "none", "none", 0xFFFFFF00);
    object_governmentExterior[113] = CreateDynamicObject(817, 1575.4973, -1608.8066, 12.8200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
    SetDynamicObjectMaterial(object_governmentExterior[113], 0, -1, "none", "none", 0xFFFFFF00);
    object_governmentExterior[114] = CreateDynamicObject(3660, 1592.4925, -1612.8653, 14.3542, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    object_governmentExterior[115] = CreateDynamicObject(18766, 1560.0118, -1620.0030, 12.0881, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[115], 0, 17545, "burnsground", "indund_64", 0x00000000);
    object_governmentExterior[116] = CreateDynamicObject(18766, 1570.0113, -1620.0030, 12.0881, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[116], 0, 17545, "burnsground", "indund_64", 0x00000000);
    object_governmentExterior[117] = CreateDynamicObject(18766, 1580.0096, -1620.0030, 12.0881, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[117], 0, 17545, "burnsground", "indund_64", 0x00000000);
    object_governmentExterior[118] = CreateDynamicObject(18766, 1588.6977, -1620.0008, 12.0874, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[118], 0, 17545, "burnsground", "indund_64", 0x00000000);
    object_governmentExterior[119] = CreateDynamicObject(18766, 1550.0123, -1620.5035, 12.0874, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[119], 0, 17545, "burnsground", "indund_64", 0x00000000);
    object_governmentExterior[120] = CreateDynamicObject(18766, 1569.9913, -1620.5035, 12.0874, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[120], 0, 17545, "burnsground", "indund_64", 0x00000000);
    object_governmentExterior[121] = CreateDynamicObject(18766, 1560.0118, -1620.5035, 12.0874, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[121], 0, 17545, "burnsground", "indund_64", 0x00000000);
    object_governmentExterior[122] = CreateDynamicObject(1215, 1566.3018, -1613.9210, 12.3000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[123] = CreateDynamicObject(18766, 1579.9903, -1620.5035, 12.0874, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[123], 0, 13060, "ce_fact01", "puttywall1", 0x00000000);
    object_governmentExterior[124] = CreateDynamicObject(18766, 1588.6933, -1620.5035, 12.0864, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[124], 0, 17545, "burnsground", "indund_64", 0x00000000);
    object_governmentExterior[125] = CreateDynamicObject(618, 1550.8454, -1608.1179, 12.6609, 0.0000, 0.0000, -108.5998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_treea3
    object_governmentExterior[126] = CreateDynamicObject(817, 1546.8155, -1613.4863, 12.8201, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
    SetDynamicObjectMaterial(object_governmentExterior[126], 0, -1, "none", "none", 0xFFFFFF00);
    object_governmentExterior[127] = CreateDynamicObject(817, 1586.6368, -1608.5267, 12.8200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
    SetDynamicObjectMaterial(object_governmentExterior[127], 0, -1, "none", "none", 0xFFFFFF00);
    object_governmentExterior[128] = CreateDynamicObject(18981, 1547.2928, -1699.0566, 11.4982, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_governmentExterior[128], 0, 16640, "a51", "Metal3_128", 0x00000000);
    object_governmentExterior[129] = CreateDynamicObject(738, 1586.8690, -1608.7347, 12.3781, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //aw_streettree2
    object_governmentExterior[130] = CreateDynamicObject(817, 1550.7563, -1609.0362, 12.8200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
    SetDynamicObjectMaterial(object_governmentExterior[130], 0, -1, "none", "none", 0xFFFFFF00);
    object_governmentExterior[131] = CreateDynamicObject(817, 1544.3662, -1606.5456, 12.8200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
    SetDynamicObjectMaterial(object_governmentExterior[131], 0, -1, "none", "none", 0xFFFFFF00);
    object_governmentExterior[132] = CreateDynamicObject(19172, 1545.8249, -1660.3476, 15.8212, 0.0000, 0.0000, -71.3000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[132], 0, "San Andreas", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[132], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[133] = CreateDynamicObject(18762, 1545.2370, -1658.1623, 14.3999, 0.0000, 0.0000, 18.5998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[133], 0, 2176, "casino_props", "marblebox", 0x00000000);
    object_governmentExterior[134] = CreateDynamicObject(19172, 1546.0155, -1690.8358, 15.1014, 0.0000, 0.0000, -109.0998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[134], 0, " ", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[134], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[135] = CreateDynamicObject(19174, 1543.4514, -1633.8006, 13.8225, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_governmentExterior[135], 0, "Kamera�berwacht!", OBJECT_MATERIAL_SIZE_512x128, "Arial", 45, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterialText(object_governmentExterior[135], 1, "Example Text", OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0x00000000, 0);
    object_governmentExterior[136] = CreateDynamicObject(2921, 1577.1965, -1632.9781, 16.7740, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_cam
    object_governmentExterior[137] = CreateDynamicObject(18762, 1547.6743, -1686.2757, 14.3999, 0.0000, 0.0000, -18.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[137], 0, 2176, "casino_props", "marblebox", 0x00000000);
    object_governmentExterior[138] = CreateDynamicObject(18762, 1545.5321, -1692.8668, 14.3999, 0.0000, 0.0000, -18.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[138], 0, 2176, "casino_props", "marblebox", 0x00000000);
    object_governmentExterior[139] = CreateDynamicObject(19464, 1546.5904, -1689.5472, 13.8915, 0.0000, 0.0000, -19.1000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_governmentExterior[139], 0, 14623, "mafcasmain", "marble_wall2", 0x00000000);
    object_governmentExterior[140] = CreateDynamicObject(19172, 1546.8690, -1688.3822, 15.8212, 0.0000, 0.0000, -109.0998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[140], 0, "San Andreas", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[140], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[141] = CreateDynamicObject(19172, 1545.9980, -1690.8509, 15.8212, 0.0000, 0.0000, -109.0998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[141], 0, "Regierung", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[141], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[142] = CreateDynamicObject(19172, 1547.0329, -1687.9188, 14.1814, 0.0000, 0.0000, -109.0998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[142], 0, " ", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[142], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[143] = CreateDynamicObject(19172, 1546.0124, -1690.8675, 14.1814, 0.0000, 0.0000, -109.0998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[143], 0, " ", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_governmentExterior[143], 1, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[144] = CreateDynamicObject(18981, 1547.2928, -1724.0572, 11.4982, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_governmentExterior[144], 0, 16640, "a51", "Metal3_128", 0x00000000);
    object_governmentExterior[145] = CreateDynamicObject(18981, 1522.3022, -1699.0566, 11.4982, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_governmentExterior[145], 0, 16640, "a51", "Metal3_128", 0x00000000);
    object_governmentExterior[146] = CreateDynamicObject(18981, 1522.2921, -1724.0572, 11.4982, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_governmentExterior[146], 0, 16640, "a51", "Metal3_128", 0x00000000);
    object_governmentExterior[147] = CreateDynamicObject(19172, 1524.1235, -1677.8929, 8.2503, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_governmentExterior[147], 0, "Zum Obergeschoss", OBJECT_MATERIAL_SIZE_256x128, "Arial", 32, 1, 0xFF8FBC8F, 0x00000000, 1);
    SetDynamicObjectMaterialText(object_governmentExterior[147], 1, "Example Text", OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0x00000000, 0);
    object_governmentExterior[148] = CreateDynamicObject(1622, 1542.7779, -1650.0886, 22.6884, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam2_01
    object_governmentExterior[149] = CreateDynamicObject(19441, 1551.6236, -1618.5927, 12.4392, 0.0000, 90.0000, -96.9998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall081
    SetDynamicObjectMaterial(object_governmentExterior[149], 0, 12871, "ce_ground01", "dirttracksgrass256", 0x00000000);
    object_governmentExterior[150] = CreateDynamicObject(1622, 1548.6071, -1650.4802, 22.7283, 0.0000, -11.1000, 68.0999, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //nt_securecam2_01
    object_governmentExterior[151] = CreateDynamicObject(2921, 1554.2756, -1681.3183, 21.6487, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_cam
    object_governmentExterior[152] = CreateDynamicObject(2921, 1543.1660, -1703.2392, 21.6487, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_cam
    object_governmentExterior[153] = CreateDynamicObject(2921, 1545.3287, -1701.1059, 21.6487, 0.0000, 0.0000, -70.0998, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_cam
    object_governmentExterior[154] = CreateDynamicObject(18766, 1579.9903, -1620.5035, 12.0874, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_governmentExterior[154], 0, 17545, "burnsground", "indund_64", 0x00000000);
    object_governmentExterior[155] = CreateDynamicObject(3660, 1592.4903, -1613.2154, 14.3521, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    SetDynamicObjectMaterial(object_governmentExterior[155], 2, 19297, "matlights", "invisible", 0x00000000);
    SetDynamicObjectMaterial(object_governmentExterior[155], 3, 19297, "matlights", "invisible", 0x00000000);
    SetDynamicObjectMaterial(object_governmentExterior[155], 4, 19297, "matlights", "invisible", 0x00000000);
    object_governmentExterior[156] = CreateDynamicObject(2921, 1569.0256, -1683.1612, 33.5102, 0.0000, 0.0000, 93.8000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_cam
    object_governmentExterior[157] = CreateDynamicObject(19175, 1543.4562, -1633.8028, 14.2528, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterial(object_governmentExterior[157], 0, 15041, "bigsfsave", "andydark", 0x00000000);
    SetDynamicObjectMaterial(object_governmentExterior[157], 1, 18365, "sawmillcs_t", "bricklayerdark_hi64HV", 0x00000000);
    object_governmentExterior[158] = CreateDynamicObject(19441, 1540.0979, -1615.2824, 12.3830, -0.2998, -89.9999, -90.9001, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall081
    SetDynamicObjectMaterial(object_governmentExterior[158], 0, 12871, "ce_ground01", "dirttracksgrass256", 0x00000000);
    object_governmentExterior[159] = CreateDynamicObject(1215, 1567.7225, -1613.9210, 12.3000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_governmentExterior[160] = CreateDynamicObject(968, 1544.6907, -1630.8317, 13.1292, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_governmentExterior[161] = CreateDynamicObject(971, 1588.9991, -1638.1402, 15.0256, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_GOVERNMENTEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);

    object_government_barrier = object_governmentExterior[160];
    object_government_gate = object_governmentExterior[161];*/
}

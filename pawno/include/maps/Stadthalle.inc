#include <YSI\y_hooks>

// Global interior define
#define MAPS_CITYHALLEXTERIOR_INTERIOR      0
#define MAPS_CITYHALLINTERIOR_INTERIOR      0
#define MAPS_REGISTRATIONOFFICE_INTERIOR    0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 210.0;
static Float:DRAWDISTANCE   = 200.0;

// Cityhall coords & points
#define CITYHALL_INTERIOR_ENTER_COORDS              1481.1821,-1771.8053,18.7958
#define CITYHALL_INTERIOR_EXIT_COORDS               920.2045, -1475.2966, 2754.3318
#define CITYHALL_INTERIOR_ENTER_FACING              0.0
#define CITYHALL_INTERIOR_EXIT_FACING               0.0
#define REGISTRATIONOFFICE_INTERIOR_ENTER_COORDS    1473.4260,-1771.8975,18.7958
#define REGISTRATIONOFFICE_INTERIOR_EXIT_COORDS     2305.8259, -16.1325, 26.7496
#define REGISTRATIONOFFICE_INTERIOR_ENTER_FACING    180.0
#define REGISTRATIONOFFICE_INTERIOR_EXIT_FACING     270.0
#define JEFF_VAN_COORDS                             1339.6373, -1808.8037, 13.6913, 180.0000
#define JEFF_COORDS									1338.7585, -1805.1331, 13.5469
#define JEFF_COORDS_FACING                          1338.7585, -1805.1331, 13.5469, 270.0000

// Map variables
new stadthalle_Obj[157];
new pickup_cityhallExterior[2];
new text3D_cityhallExterior[3];
new actor_cityhallExterior[1];
new vehicle_cityhallExterior[1];

hook OnPlayerConnect(playerid) {
	// Remove RenderWare objects
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

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys & KEY_SECONDARY_ATTACK) {
		if (IsPlayerInRangeOfPoint(playerid, 2.0, CITYHALL_INTERIOR_ENTER_COORDS)) { // Cityhall Entrance
			SetPlayerFacingAngle(playerid, CITYHALL_INTERIOR_EXIT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, CITYHALL_INTERIOR_EXIT_COORDS, MAPS_CITYHALLINTERIOR_INTERIOR, VW_CITYHALLINTERIOR);
			return 1;
		} else if (IsPlayerInRangeOfPoint(playerid, 2.0, REGISTRATIONOFFICE_INTERIOR_ENTER_COORDS)) { // Registration office Entrance
            SendClientMessage(playerid, COLOR_WHITE, "Sachbearbeiter sagt: Herzlich Willkommen beim Kraftfahrtbundesamt (Zulassungsstelle)!");
		    SetPlayerFacingAngle(playerid, REGISTRATIONOFFICE_INTERIOR_EXIT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, REGISTRATIONOFFICE_INTERIOR_EXIT_COORDS, MAPS_REGISTRATIONOFFICE_INTERIOR, VW_REGISTRATIONOFFICE);
			return 1;
		} else if (IsPlayerInRangeOfPoint(playerid, 2.0, REGISTRATIONOFFICE_INTERIOR_EXIT_COORDS)) { // Registration office Exit
			SendClientMessage(playerid, COLOR_WHITE, "Sachbearbeiter sagt: Vielen Dank für Ihr Besuch! Wir wünschen Ihnen einen schönen Tag.");
		    SetPlayerFacingAngle(playerid, REGISTRATIONOFFICE_INTERIOR_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, REGISTRATIONOFFICE_INTERIOR_ENTER_COORDS, MAPS_CITYHALLEXTERIOR_INTERIOR, VW_MAIN);
            return 1;
		}
	}

	return 1;
}

hook OnGameModeInit() {
	// Map Icon
    CreateDynamicMapIcon(CITYHALL_INTERIOR_ENTER_COORDS, 38, 0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR);

	// Pickups
    pickup_cityhallExterior[0] = CreateDynamicPickup(19197, 1, CITYHALL_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR); // Cityhall
    pickup_cityhallExterior[1] = CreateDynamicPickup(19197, 1, REGISTRATIONOFFICE_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR); // Registration office

	// 3DTextLabels
    text3D_cityhallExterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "-> San Andreas Stadtamt <-\n" COLOR_HEX_WHITE "Arbeitsamt, Meldeamt, Passbehörde\nGebäude betreten mit 'Enter'", COLOR_WHITE, CITYHALL_INTERIOR_ENTER_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CITYHALLEXTERIOR_INTERIOR); // Cityhall
    text3D_cityhallExterior[1] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "-> Kraftfahrtbundesamt - Zulassungsstelle <-\n" COLOR_HEX_WHITE "Gebäude betreten mit 'Enter'", COLOR_WHITE, REGISTRATIONOFFICE_INTERIOR_ENTER_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CITYHALLEXTERIOR_INTERIOR); // Registration office
    text3D_cityhallExterior[2] = _:CreateDynamic3DTextLabel(COLOR_HEX_BLUE "Illegaler Jobvermittler - Jeff\n" COLOR_HEX_WHITE "Tippe /Illegalejobs", COLOR_WHITE, JEFF_COORDS, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CITYHALLEXTERIOR_INTERIOR); // Jeff

    // Actors
    actor_cityhallExterior[0] = CreateDynamicActor(32, JEFF_COORDS_FACING, .streamdistance = STREAMDISTANCE);
    ApplyDynamicActorAnimation(actor_cityhallExterior[0], "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0);

    // Vehicles
    vehicle_cityhallExterior[0] = AddStaticVehicleEx(482, JEFF_VAN_COORDS, 0, 0, -1); //Burrito // burrito (Jeff)

    // Parking ATM


	// Objects
	CreateDynamicObject(2942, 1466.9621, -1749.8344, 15.0809, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
	CreateDynamicObject(2942, 1495.3919, -1749.8344, 15.0809, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
	CreateDynamicObject(2942, 1488.2028, -1634.4946, 12.9274, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
	stadthalle_Obj[0] = CreateDynamicObject(1522, 1511.5583, -1680.9597, 12.4370, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
	stadthalle_Obj[1] = CreateDynamicObject(19978, 1447.9643, -1665.2762, 12.2536, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
	stadthalle_Obj[2] = CreateDynamicObject(19533, 1493.3591, -1673.0946, 12.3140, 0.0000, 0.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
	SetDynamicObjectMaterial(stadthalle_Obj[2], 0, 10756, "airportroads_sfse", "sf_junction5", 0x00000);
	stadthalle_Obj[3] = CreateDynamicObject(19634, 1479.5920, -1707.5062, 2.1459, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Ramp360Degree2
	SetDynamicObjectMaterial(stadthalle_Obj[3], 0, 19297, "matlights", "invisible", 0x00000);
	SetDynamicObjectMaterial(stadthalle_Obj[3], 1, 3979, "civic01_lan", "crazy paving", 0xFFFFFFFF);
	stadthalle_Obj[4] = CreateDynamicObject(19533, 1465.7351, -1673.0841, 12.3179, 0.0000, 0.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //no comment
	SetDynamicObjectMaterial(stadthalle_Obj[4], 0, 10756, "airportroads_sfse", "sf_junction5", 0x00000);
	stadthalle_Obj[5] = CreateObject(18753, 1461.5904, -1640.7932, 11.7964, 0.0000, 0.0000, 0.0000); //Base125mx125m1
	SetObjectMaterial(stadthalle_Obj[5], 0, 4829, "airport_las", "Grass_128HV", 0x00000000);
	SetDynamicObjectMaterial(stadthalle_Obj[5], 0, 4829, "airport_las", "Grass_128HV", 0x00000);
	stadthalle_Obj[6] = CreateDynamicObject(19447, 1480.1827, -1596.7888, 12.2742, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[6], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[7] = CreateDynamicObject(19447, 1480.1816, -1660.8879, 12.2241, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[7], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[8] = CreateDynamicObject(19447, 1495.2613, -1631.6070, 12.2341, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[8], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[9] = CreateDynamicObject(18981, 1471.8900, -1715.4415, 11.8730, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[9], 0, 6312, "beacliff_law2", "concretebigblu4256128", 0xFFFFFFFF);
	stadthalle_Obj[10] = CreateDynamicObject(19447, 1504.8819, -1631.6070, 12.2341, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[10], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[11] = CreateDynamicObject(19447, 1514.5117, -1631.6070, 12.2341, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[11], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[12] = CreateDynamicObject(19447, 1464.8620, -1631.6070, 12.2341, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[12], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[13] = CreateDynamicObject(19447, 1455.2220, -1631.6070, 12.2341, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[13], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[14] = CreateDynamicObject(19447, 1445.6019, -1631.6070, 12.2341, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[14], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[15] = CreateDynamicObject(19447, 1480.1827, -1616.0378, 12.2341, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[15], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[16] = CreateDynamicObject(19447, 1439.2513, -1631.6070, 12.2944, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[16], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[17] = CreateDynamicObject(19447, 1480.1827, -1606.4089, 12.2341, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[17], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[18] = CreateDynamicObject(19447, 1480.1827, -1646.6673, 12.2341, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[18], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[19] = CreateDynamicObject(19447, 1480.1827, -1656.2768, 12.2341, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[19], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[20] = CreateDynamicObject(18981, 1496.8797, -1715.4415, 11.8750, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[20], 0, 6312, "beacliff_law2", "concretebigblu4256128", 0xFFFFFFFF);
	stadthalle_Obj[21] = CreateDynamicObject(18981, 1514.6562, -1715.4415, 11.8730, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[21], 0, 6312, "beacliff_law2", "concretebigblu4256128", 0xFFFFFFFF);
	stadthalle_Obj[22] = CreateDynamicObject(19447, 1520.1329, -1631.6070, 12.2398, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[22], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[23] = CreateDynamicObject(18980, 1524.0985, -1693.0941, 12.6603, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[23], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[24] = CreateDynamicObject(18981, 1446.8927, -1715.4415, 11.8730, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[24], 0, 6312, "beacliff_law2", "concretebigblu4256128", 0xFFFFFFFF);//< DESCH OBJEKT
	stadthalle_Obj[25] = CreateDynamicObject(10183, 1491.7060, -1722.1097, 12.3886, 0.0000, 0.0000, 225.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
	stadthalle_Obj[26] = CreateDynamicObject(3660, 1480.0882, -1703.7054, 14.0417, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
	stadthalle_Obj[27] = CreateDynamicObject(18980, 1524.0985, -1653.1025, 12.6603, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[27], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[28] = CreateDynamicObject(10183, 1466.5561, -1721.8934, 12.3899, 0.0000, 0.0000, 225.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
	stadthalle_Obj[29] = CreateDynamicObject(8843, 1492.7054, -1711.2722, 12.3908, 0.0000, 0.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
	stadthalle_Obj[30] = CreateDynamicObject(3660, 1511.0384, -1703.7054, 14.0417, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
	stadthalle_Obj[31] = CreateDynamicObject(3660, 1447.9488, -1703.7054, 14.0417, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
	stadthalle_Obj[32] = CreateDynamicObject(19957, 1524.0229, -1722.3553, 11.8254, 0.0000, 0.0000, 45.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
	stadthalle_Obj[33] = CreateDynamicObject(19957, 1519.5677, -1726.8105, 11.8254, 0.0000, 0.0000, 45.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
	stadthalle_Obj[34] = CreateDynamicObject(19967, 1434.9565, -1722.3602, 12.0495, 0.0000, 0.0000, -45.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign20
	stadthalle_Obj[35] = CreateDynamicObject(19967, 1439.5400, -1726.8164, 12.0495, 0.0000, 0.0000, -45.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign20
	stadthalle_Obj[36] = CreateDynamicObject(18980, 1524.0975, -1709.8315, 12.6590, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[36], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[37] = CreateDynamicObject(18980, 1524.0985, -1609.7867, 12.6603, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[37], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[38] = CreateDynamicObject(18762, 1524.0985, -1624.7866, 12.6590, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[38], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[39] = CreateDynamicObject(18762, 1524.0985, -1638.1035, 12.6590, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[39], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[40] = CreateDynamicObject(18762, 1524.0975, -1635.8518, 12.6576, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[40], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[41] = CreateDynamicObject(18762, 1524.0975, -1627.3613, 12.6576, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[41], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[42] = CreateDynamicObject(18980, 1511.1278, -1702.5002, 12.6590, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[42], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[43] = CreateDynamicObject(18980, 1480.1827, -1702.5002, 12.6590, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[43], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[44] = CreateDynamicObject(18980, 1447.9820, -1702.5002, 12.6590, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[44], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[45] = CreateDynamicObject(18980, 1434.9863, -1709.8315, 12.6590, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[45], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[46] = CreateDynamicObject(18980, 1434.9853, -1693.0941, 12.6603, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[46], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[47] = CreateDynamicObject(18980, 1434.9863, -1653.1025, 12.6603, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[47], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[48] = CreateDynamicObject(18762, 1434.9853, -1638.1035, 12.6590, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[48], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[49] = CreateDynamicObject(18762, 1434.9863, -1635.8518, 12.6576, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[49], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[50] = CreateDynamicObject(18762, 1434.9863, -1627.3613, 12.6576, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[50], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[51] = CreateDynamicObject(18762, 1434.9853, -1624.7866, 12.6590, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[51], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[52] = CreateDynamicObject(18980, 1434.9863, -1609.7867, 12.6603, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[52], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[53] = CreateDynamicObject(19447, 1480.1827, -1685.2773, 12.2130, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
	SetDynamicObjectMaterial(stadthalle_Obj[53], 0, 3979, "civic01_lan", "crazy paving", 0x00000);
	stadthalle_Obj[54] = CreateDynamicObject(18980, 1434.0655, -1675.0334, 11.8780, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	stadthalle_Obj[56] = CreateDynamicObject(18980, 1525.0583, -1674.2124, 11.8780, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	stadthalle_Obj[57] = CreateDynamicObject(18980, 1507.0582, -1726.8115, 12.6590, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[57], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[58] = CreateDynamicObject(18980, 1482.0589, -1726.8115, 12.6590, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[58], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[59] = CreateDynamicObject(18762, 1467.0775, -1726.8105, 12.6590, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[59], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[60] = CreateDynamicObject(8843, 1464.5163, -1711.2722, 12.3908, 0.0000, 0.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arrows01_lvs
	stadthalle_Obj[61] = CreateDynamicObject(18980, 1452.0770, -1726.8115, 12.6590, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[61], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[62] = CreateDynamicObject(1231, 1511.9293, -1725.7270, 14.9757, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
	stadthalle_Obj[63] = CreateDynamicObject(1231, 1446.2690, -1725.1766, 14.9757, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
	stadthalle_Obj[64] = CreateDynamicObject(1231, 1464.0649, -1702.6772, 14.9757, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
	stadthalle_Obj[65] = CreateDynamicObject(1231, 1495.6361, -1702.6772, 14.9757, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
	stadthalle_Obj[66] = CreateDynamicObject(1231, 1479.2408, -1726.0174, 14.9757, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
	stadthalle_Obj[67] = CreateDynamicObject(18763, 1435.9836, -1598.7790, 10.6862, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[67], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[68] = CreateDynamicObject(18763, 1523.1053, -1598.7790, 10.6862, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[68], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[69] = CreateDynamicObject(1223, 1478.2661, -1662.3474, 12.0572, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	stadthalle_Obj[70] = CreateDynamicObject(1223, 1482.5705, -1653.3548, 12.0403, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	stadthalle_Obj[71] = CreateDynamicObject(1223, 1482.5244, -1618.5329, 12.2117, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	stadthalle_Obj[72] = CreateDynamicObject(1223, 1482.5244, -1600.2301, 12.2117, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	stadthalle_Obj[73] = CreateDynamicObject(1223, 1477.8636, -1644.3137, 12.2117, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	stadthalle_Obj[74] = CreateDynamicObject(1223, 1478.0438, -1608.8835, 12.2117, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	stadthalle_Obj[75] = CreateDynamicObject(1223, 1522.6765, -1633.6767, 12.0403, 0.0000, 0.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	stadthalle_Obj[76] = CreateDynamicObject(1223, 1490.8824, -1633.7036, 12.2117, 0.0000, 0.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	stadthalle_Obj[77] = CreateDynamicObject(1223, 1514.4842, -1629.4735, 12.2117, 0.0000, 0.0000, -90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	stadthalle_Obj[78] = CreateDynamicObject(19467, 1459.5787, -1629.7547, 12.3308, 180.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vehicle_barrier01
	stadthalle_Obj[79] = CreateDynamicObject(19425, 1435.5527, -1609.1783, 14.8659, 0.0000, -90.0000, -90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
	stadthalle_Obj[80] = CreateDynamicObject(1560, 1503.5096, -1638.1550, 13.4996, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT7_11L
	stadthalle_Obj[81] = CreateDynamicObject(994, 1501.7275, -1664.1711, 12.5558, 0.0000, 0.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
	stadthalle_Obj[82] = CreateDynamicObject(1223, 1497.8238, -1629.4735, 12.2117, 0.0000, 0.0000, -90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	stadthalle_Obj[83] = CreateDynamicObject(19633, 1480.1319, -1631.3542, 12.3163, 0.0000, 180.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Ramp360Degree1
	SetDynamicObjectMaterial(stadthalle_Obj[83], 0, 19297, "matlights", "invisible", 0x00000);
	SetDynamicObjectMaterial(stadthalle_Obj[83], 1, 3979, "civic01_lan", "crazy paving", 0xFFFFFFFF);
	stadthalle_Obj[84] = CreateDynamicObject(18980, 1449.9361, -1597.7806, 12.6590, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[84], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[85] = CreateDynamicObject(18980, 1509.1062, -1597.7806, 12.6590, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[85], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[86] = CreateDynamicObject(18765, 1445.1700, -1684.4587, 9.9703, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx10mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[86], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000);
	stadthalle_Obj[87] = CreateDynamicObject(19467, 1452.7148, -1629.7547, 12.3308, 180.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vehicle_barrier01
	stadthalle_Obj[88] = CreateDynamicObject(5409, 1445.9233, -1613.7517, 16.6776, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //laepetrol1a
	stadthalle_Obj[89] = CreateDynamicObject(6977, 1503.5129, -1648.6250, 12.0703, 0.0000, 0.0000, -90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //stripshopn1
	stadthalle_Obj[90] = CreateDynamicObject(18980, 1525.0583, -1621.0533, 11.8780, 0.0000, 90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	stadthalle_Obj[91] = CreateDynamicObject(18765, 1486.8967, -1661.5350, 9.9684, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx10mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[91], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000);
	stadthalle_Obj[92] = CreateDynamicObject(10631, 1511.7464, -1689.8575, 16.4190, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ammunation_SFS
	stadthalle_Obj[93] = CreateDynamicObject(18765, 1496.8957, -1661.3048, 9.9684, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx10mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[93], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000);
	stadthalle_Obj[94] = CreateDynamicObject(18239, 1440.4975, -1687.0780, 12.1183, 0.0000, 0.0000, -180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cuntw_restrnt1
	stadthalle_Obj[96] = CreateDynamicObject(18765, 1445.1684, -1688.6003, 9.9799, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx10mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[96], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000);
	stadthalle_Obj[97] = CreateDynamicObject(1594, 1447.9820, -1692.0150, 12.9490, 0.0000, 0.0000, 34.5998); //chairsntable
	stadthalle_Obj[98] = CreateDynamicObject(19174, 1489.3476, -1656.5471, 15.8430, 0.0000, 20.5000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
	SetDynamicObjectMaterial(stadthalle_Obj[98], 0, 19297, "matlights", "invisible", 0x00000);
	SetDynamicObjectMaterialText(stadthalle_Obj[98], 1, "TAXI", OBJECT_MATERIAL_SIZE_256x128, "Arial Black", 143, 1, 0xFFFFFF00, 0x00000000, 1);
	stadthalle_Obj[99] = CreateDynamicObject(8661, 1445.1169, -1612.0550, 12.3107, 0.0000, 0.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
	SetDynamicObjectMaterial(stadthalle_Obj[99], 0, 4835, "airoads_las", "concretenewb256", 0xFFD3D3D3);
	stadthalle_Obj[100] = CreateDynamicObject(8661, 1468.6374, -1612.0550, 12.3107, 0.0000, 0.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
	SetDynamicObjectMaterial(stadthalle_Obj[100], 0, 4835, "airoads_las", "concretenewb256", 0xFFD3D3D3);
	stadthalle_Obj[101] = CreateDynamicObject(8661, 1458.2474, -1612.0550, 12.3086, 0.0000, 0.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
	SetDynamicObjectMaterial(stadthalle_Obj[101], 0, 4835, "airoads_las", "concretenewb256", 0xFFD3D3D3);
	stadthalle_Obj[102] = CreateDynamicObject(19467, 1466.3105, -1629.7547, 12.3308, 180.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vehicle_barrier01
	stadthalle_Obj[103] = CreateDynamicObject(19467, 1445.2624, -1629.7547, 12.3308, 180.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vehicle_barrier01
	stadthalle_Obj[104] = CreateDynamicObject(19467, 1438.3006, -1629.7547, 12.3308, 180.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vehicle_barrier01
	stadthalle_Obj[105] = CreateDynamicObject(19467, 1471.1815, -1625.3409, 12.3308, 180.0000, 0.0000, 55.9999); //vehicle_barrier01
	stadthalle_Obj[106] = CreateDynamicObject(19467, 1475.4521, -1621.9455, 12.3308, 180.0000, 0.0000, 25.6998); //vehicle_barrier01
	stadthalle_Obj[107] = CreateDynamicObject(19467, 1478.3658, -1617.7218, 12.3308, 180.0000, 0.0000, 89.7994); //vehicle_barrier01
	stadthalle_Obj[108] = CreateDynamicObject(19467, 1478.3856, -1612.0317, 12.3308, 180.0000, 0.0000, 89.7994); //vehicle_barrier01
	stadthalle_Obj[109] = CreateDynamicObject(19467, 1478.4089, -1605.8098, 12.3308, 180.0000, 0.0000, 89.7994); //vehicle_barrier01
	stadthalle_Obj[110] = CreateDynamicObject(19467, 1478.4305, -1599.9869, 12.3308, 180.0000, 0.0000, 89.7994); //vehicle_barrier01
	stadthalle_Obj[111] = CreateDynamicObject(19425, 1435.4813, -1618.2917, 14.8659, 0.0000, -90.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
	stadthalle_Obj[112] = CreateDynamicObject(19174, 1491.1374, -1656.5471, 14.5691, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
	SetDynamicObjectMaterial(stadthalle_Obj[112], 0, 19297, "matlights", "invisible", 0x00000);
	SetDynamicObjectMaterialText(stadthalle_Obj[112], 1, "PARK", OBJECT_MATERIAL_SIZE_256x128, "Arial", 100, 1, 0xFFFFFF00, 0x00000000, 1);
	stadthalle_Obj[113] = CreateDynamicObject(19174, 1493.8470, -1656.5471, 14.5691, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
	SetDynamicObjectMaterial(stadthalle_Obj[113], 0, 19297, "matlights", "invisible", 0x00000);
	SetDynamicObjectMaterialText(stadthalle_Obj[113], 1, "PLATZ", OBJECT_MATERIAL_SIZE_256x128, "Arial", 100, 1, 0xFFFFFF00, 0x00000000, 1);
	stadthalle_Obj[114] = CreateDynamicObject(1594, 1447.8684, -1683.5328, 12.9490, 0.0000, 0.0000, 121.5998); //chairsntable
	stadthalle_Obj[115] = CreateDynamicObject(1594, 1447.7320, -1687.7961, 12.9490, 0.0000, 0.0000, 121.5998); //chairsntable
	stadthalle_Obj[116] = CreateDynamicObject(18765, 1453.0559, -1660.6037, 9.9684, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx10mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[116], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000);
	stadthalle_Obj[117] = CreateDynamicObject(18765, 1458.2772, -1660.5965, 9.9582, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx10mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[117], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000);
	stadthalle_Obj[118] = CreateDynamicObject(18765, 1458.2772, -1650.6070, 9.9582, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx10mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[118], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000);
	stadthalle_Obj[119] = CreateDynamicObject(18765, 1453.0559, -1650.6113, 9.9684, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx10mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[119], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000);
	stadthalle_Obj[120] = CreateDynamicObject(1223, 1463.0366, -1629.4735, 12.2117, 0.0000, 0.0000, -90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	stadthalle_Obj[121] = CreateDynamicObject(19978, 1463.3591, -1665.2762, 12.2536, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
	stadthalle_Obj[122] = CreateDynamicObject(1686, 1468.7563, -1606.7661, 12.2418, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //petrolpumpnew
	stadthalle_Obj[123] = CreateDynamicObject(1686, 1468.7563, -1614.0671, 12.2418, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //petrolpumpnew
	stadthalle_Obj[124] = CreateDynamicObject(1223, 1441.6921, -1629.4735, 12.2117, 0.0000, 0.0000, -90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
	stadthalle_Obj[125] = CreateDynamicObject(994, 1482.0069, -1664.1711, 12.5558, 0.0000, 0.0000, 90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
	stadthalle_Obj[126] = CreateDynamicObject(717, 1495.6361, -1685.6164, 12.3520, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
	stadthalle_Obj[127] = CreateDynamicObject(19174, 1466.4061, -1633.2384, 25.3094, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
	SetDynamicObjectMaterialText(stadthalle_Obj[127], 0, "O", OBJECT_MATERIAL_SIZE_256x128, "Arial", 200, 1, 0xFFFFFFFF, 0x00000000, 1);
	SetDynamicObjectMaterial(stadthalle_Obj[127], 1, 19297, "matlights", "invisible", 0x00000);
	stadthalle_Obj[128] = CreateDynamicObject(19174, 1466.4061, -1633.2384, 26.9794, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
	SetDynamicObjectMaterialText(stadthalle_Obj[128], 0, "H", OBJECT_MATERIAL_SIZE_256x128, "Arial", 200, 1, 0xFFFFFFFF, 0x00000000, 1);
	SetDynamicObjectMaterial(stadthalle_Obj[128], 1, 19297, "matlights", "invisible", 0x00000);
	stadthalle_Obj[129] = CreateDynamicObject(19174, 1466.4061, -1633.2384, 23.4993, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
	SetDynamicObjectMaterialText(stadthalle_Obj[129], 0, "T", OBJECT_MATERIAL_SIZE_256x128, "Arial", 200, 1, 0xFFFFFFFF, 0x00000000, 1);
	SetDynamicObjectMaterial(stadthalle_Obj[129], 1, 19297, "matlights", "invisible", 0x00000);
	stadthalle_Obj[130] = CreateDynamicObject(19174, 1466.4061, -1633.2384, 21.6394, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
	SetDynamicObjectMaterialText(stadthalle_Obj[130], 0, "E", OBJECT_MATERIAL_SIZE_256x128, "Arial", 200, 1, 0xFFFFFFFF, 0x00000000, 1);
	SetDynamicObjectMaterial(stadthalle_Obj[130], 1, 19297, "matlights", "invisible", 0x00000);
	stadthalle_Obj[131] = CreateDynamicObject(19174, 1466.4061, -1633.2384, 19.7992, 0.0000, 0.0000, 180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
	SetDynamicObjectMaterialText(stadthalle_Obj[131], 0, "L", OBJECT_MATERIAL_SIZE_256x128, "Arial", 200, 1, 0xFFFFFFFF, 0x00000000, 1);
	SetDynamicObjectMaterial(stadthalle_Obj[131], 1, 19297, "matlights", "invisible", 0x00000);
	stadthalle_Obj[132] = CreateDynamicObject(19978, 1453.2921, -1742.2995, 12.5087, 0.0000, 0.0000, -180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
	stadthalle_Obj[133] = CreateDynamicObject(4018, 1442.8149, -1638.5113, 12.3000, 0.0000, 0.0000, -180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //newbuildsm02
	SetDynamicObjectMaterial(stadthalle_Obj[133], 1, 9515, "bigboxtemp1", "ws_garagedoor3_white", 0x00000);
	SetDynamicObjectMaterial(stadthalle_Obj[133], 2, 6522, "cuntclub_law2", "marinawindow1_256", 0x00000);
	SetDynamicObjectMaterial(stadthalle_Obj[133], 3, 14794, "ab_vegasgymmain", "studiowall2_law", 0x00000);
	SetDynamicObjectMaterial(stadthalle_Obj[133], 4, 8409, "gnhotel1", "glass_64", 0x00000);
	stadthalle_Obj[134] = CreateDynamicObject(18980, 1494.4453, -1597.7906, 12.6527, 0.0000, 90.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(stadthalle_Obj[134], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[135] = CreateDynamicObject(4828, 1504.0904, -1613.8507, 2.1895, 0.0000, 0.0000, 89.1996, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairprt5
	SetDynamicObjectMaterial(stadthalle_Obj[135], 2, 7088, "casinoshops1", "fakestone1_LA", 0x00000);
	stadthalle_Obj[136] = CreateDynamicObject(6965, 1504.2043, -1613.6854, 15.9097, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //venefountain02
	SetDynamicObjectMaterial(stadthalle_Obj[136], 0, 16644, "a51_detailstuff", "roucghstonebrtb", 0x00000);
	stadthalle_Obj[137] = CreateDynamicObject(6964, 1504.2043, -1613.6854, 11.5698, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //venefountwat02
	stadthalle_Obj[138] = CreateDynamicObject(6965, 1504.2043, -1613.6854, 15.4596, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //venefountain02
	SetDynamicObjectMaterial(stadthalle_Obj[138], 0, 16644, "a51_detailstuff", "roucghstonebrtb", 0x00000);
	stadthalle_Obj[139] = CreateDynamicObject(2664, 1475.8830, -1635.3269, 13.4849, 0.0000, 0.0000, -90.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SUBURB_DOOR
	SetDynamicObjectMaterial(stadthalle_Obj[139], 3, 11008, "firehouse_sfse", "halldoor01_law", 0xFFFFFFFF);
	stadthalle_Obj[140] = CreateDynamicObject(717, 1464.0649, -1685.6164, 12.3520, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
	stadthalle_Obj[141] = CreateDynamicObject(1364, 1486.8194, -1624.1124, 13.0866, 0.0000, 0.0000, -43.9999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP
	stadthalle_Obj[142] = CreateDynamicObject(19978, 1509.4718, -1742.2995, 12.5087, 0.0000, 0.0000, -180.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
	stadthalle_Obj[143] = CreateDynamicObject(18763, 1522.8957, -1636.3885, 11.9362, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[143], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[144] = CreateDynamicObject(18763, 1522.8950, -1636.6097, 11.9350, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
	SetDynamicObjectMaterial(stadthalle_Obj[144], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	stadthalle_Obj[145] = CreateDynamicObject(1364, 1473.3470, -1624.2148, 13.0866, 0.0000, 0.0000, 40.2999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP
	stadthalle_Obj[146] = CreateDynamicObject(1364, 1468.2425, -1690.5522, 13.1183, 0.0000, 0.0000, 33.6999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP
	stadthalle_Obj[147] = CreateDynamicObject(1364, 1491.3680, -1690.9145, 13.1183, 0.0000, 0.0000, -34.2, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP
	stadthalle_Obj[148] = CreateDynamicObject(717, 1470.9354, -1657.4836, 12.3520, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
	stadthalle_Obj[149] = CreateDynamicObject(717, 1441.6938, -1657.4836, 12.3520, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
	stadthalle_Obj[150] = CreateDynamicObject(717, 1512.2154, -1660.8337, 12.3520, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
	stadthalle_Obj[151] = CreateDynamicObject(8623, 1512.2629, -1660.8193, 12.9841, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush03_lvs
	stadthalle_Obj[152] = CreateDynamicObject(8623, 1470.9422, -1657.4576, 12.9841, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush03_lvs
	stadthalle_Obj[153] = CreateDynamicObject(8623, 1441.7220, -1657.4576, 12.9841, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush03_lvs
	stadthalle_Obj[154] = CreateDynamicObject(8623, 1464.0721, -1685.6081, 12.9841, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush03_lvs
	stadthalle_Obj[155] = CreateDynamicObject(8623, 1495.6335, -1685.6081, 12.9841, 0.0000, 0.0000, 0.0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush03_lvs

}

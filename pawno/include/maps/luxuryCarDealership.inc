#include <YSI\y_hooks>

// Global interior define
#define MAPS_LUXURYCARDEALERSHIP_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 130.0;

// Luxury car dealership points
#define LUXURYCARDEALERSHIP_COORDS    216.2475, -1442.8593, 13.1543

// Map variables
new autoHausLuxus_Obj[165];
new text3D_luxuryCarDealership[1];
new pickup_luxuryCarDealership[2];

hook OnPlayerConnect(playerid) {
	//Removes
	RemoveBuildingForPlayer(playerid, 6350, 247.3910, -1454.8299, 37.7344, 0.10); // SunBils01_LAw2
	RemoveBuildingForPlayer(playerid, 1259, 218.2270, -1434.5600, 24.6406, 0.10); // BillBd1
	RemoveBuildingForPlayer(playerid, 1268, 218.2270, -1434.5600, 24.6406, 0.10); // LOD Model of BillBd1
	RemoveBuildingForPlayer(playerid, 1226, 203.1950, -1429.1999, 15.8125, 0.10); // lamppost3
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	//
	if (newkeys & KEY_SECONDARY_ATTACK)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.0, 202.3835,-1428.5140,13.2964))
		{
		    SetPlayerPos(playerid, 204.2198,-1430.5114,17.6751);
		    SetPlayerFacingAngle(playerid, 40.0599);
		    SetCameraBehindPlayer(playerid);
		}
		else if(IsPlayerInRangeOfPoint(playerid, 2.0, 204.2198,-1430.5114,17.6751))
		{
		    SetPlayerPos(playerid, 202.3835,-1428.5140,13.2964);
		    SetPlayerFacingAngle(playerid, 40.4397);
		    SetCameraBehindPlayer(playerid);
		}
	}
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(LUXURYCARDEALERSHIP_COORDS, 55, 0, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR);

	// Pickups
	pickup_luxuryCarDealership[0] = CreateDynamicPickup(19197, 1, 202.3835,-1428.5140,13.2964, 0); //Unten
	pickup_luxuryCarDealership[1] = CreateDynamicPickup(19197, 1, 204.2198,-1430.5114,17.6751, 0); //Oben

    // 3DTextLabels
    text3D_luxuryCarDealership[0] = _:CreateDynamic3DTextLabel("Autohaus - Luxus\n" COLOR_HEX_WHITE "Steig in ein beliebiges Fahrzeug deiner Wahl ein!", COLOR_BLUE, LUXURYCARDEALERSHIP_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_LUXURYCARDEALERSHIP_INTERIOR);

	// Objects
	autoHausLuxus_Obj[0] = CreateDynamicObject(18762, 219.2359, -1438.4603, 12.3849, 0.0000, 90.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[0], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[1] = CreateDynamicObject(18980, 217.7290, -1424.4847, 11.8332, 0.0000, 90.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[1], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFD3D3D3);
	autoHausLuxus_Obj[2] = CreateDynamicObject(18980, 197.8110, -1444.1317, 11.8343, 0.0000, 90.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[2], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFD3D3D3);
	autoHausLuxus_Obj[3] = CreateDynamicObject(18980, 215.3329, -1443.7097, 11.8332, 0.0000, 90.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[3], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFD3D3D3);
	autoHausLuxus_Obj[4] = CreateDynamicObject(18762, 224.5894, -1434.5799, 11.8322, 0.0000, 90.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[4], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFD3D3D3);
	autoHausLuxus_Obj[5] = CreateObject(8661, 199.4803, -1431.1529, 12.2952, 0.0000, 0.0000, -46.4000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[5], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	autoHausLuxus_Obj[6] = CreateObject(8661, 205.4181, -1425.4946, 12.2964, 0.0000, 0.0000, -46.4000); //gnhtelgrnd_lvs
	SetDynamicObjectMaterial(autoHausLuxus_Obj[6], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	autoHausLuxus_Obj[7] = CreateDynamicObject(18981, 197.8338, -1442.7568, 9.6532, 0.0000, 0.0000, -136.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[7], 0, 14706, "labig2int2", "whitecarpet01", 0xFFA9A9A9);
	autoHausLuxus_Obj[8] = CreateObject(8661, 199.1134, -1430.2469, 16.6751, 0.0000, 0.0000, -46.4000); //gnhtelgrnd_lvs
	SetDynamicObjectMaterial(autoHausLuxus_Obj[8], 0, 4835, "airoads_las", "concretenewb256", 0xFF808080);
	autoHausLuxus_Obj[9] = CreateObject(8661, 204.1739, -1425.2275, 16.6040, 0.0000, 180.0000, -46.4000); //gnhtelgrnd_lvs
	SetDynamicObjectMaterial(autoHausLuxus_Obj[9], 0, 14706, "labig2int2", "whitecarpet01", 0xFFFFFFFF);
	autoHausLuxus_Obj[10] = CreateObject(8661, 199.2783, -1429.8874, 16.6030, 0.0000, 180.0000, -46.4000); //gnhtelgrnd_lvs
	SetDynamicObjectMaterial(autoHausLuxus_Obj[10], 0, 14706, "labig2int2", "whitecarpet01", 0xFFFFFFFF);
	autoHausLuxus_Obj[11] = CreateDynamicObject(18762, 223.3318, -1434.3912, 16.6951, 0.0000, 90.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[11], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[12] = CreateDynamicObject(18980, 216.5030, -1424.2679, 16.6982, 0.0000, 90.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[12], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[13] = CreateDynamicObject(18980, 224.8128, -1432.9543, 9.4630, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[13], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[14] = CreateDynamicObject(18981, 206.0921, -1434.8559, 21.9605, 0.0000, 90.0000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[14], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
	autoHausLuxus_Obj[15] = CreateDynamicObject(18981, 201.7483, -1408.8789, 16.0963, -25.7000, 0.0000, -136.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[15], 0, 18800, "mroadhelix1", "concreteoldpainted1", 0xFFFFFFFF);
	autoHausLuxus_Obj[16] = CreateDynamicObject(18981, 208.5518, -1432.4759, 21.9615, 0.0000, 90.0000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[16], 0, 9514, "711_sfw", "ws_carpark2", 0xFFD3D3D3);
	autoHausLuxus_Obj[17] = CreateDynamicObject(1649, 207.9936, -1449.5118, 14.5452, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[17], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[18] = CreateDynamicObject(18762, 208.1860, -1449.3863, 12.3829, 0.0000, 90.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[18], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[19] = CreateDynamicObject(18762, 211.6457, -1445.9487, 12.3849, 0.0000, 90.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[19], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[20] = CreateDynamicObject(18980, 214.6239, -1442.9748, 16.6930, 0.0000, 90.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[20], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[21] = CreateDynamicObject(18980, 213.7763, -1443.8398, 9.4630, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[21], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[22] = CreateDynamicObject(1649, 211.8457, -1445.7137, 14.5452, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[22], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[23] = CreateDynamicObject(1649, 211.8457, -1445.7137, 18.8355, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[23], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[24] = CreateDynamicObject(1649, 207.9936, -1449.5118, 18.8355, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[24], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[25] = CreateDynamicObject(18980, 214.6239, -1442.9748, 20.9729, 0.0000, 90.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[25], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[26] = CreateDynamicObject(18762, 223.3318, -1434.3912, 20.9740, 0.0000, 90.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[26], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[27] = CreateDynamicObject(18981, 200.4609, -1424.9188, 10.6183, 0.0000, 25.7000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[27], 0, 18800, "mroadhelix1", "concreteoldpainted1", 0xFFFFFFFF);
	autoHausLuxus_Obj[28] = CreateDynamicObject(18981, 195.9889, -1440.9853, 5.6950, -25.7000, 0.0000, -136.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[28], 0, 14706, "labig2int2", "whitecarpet01", 0xFF696969);
	autoHausLuxus_Obj[29] = CreateDynamicObject(18980, 216.5030, -1424.2679, 20.9729, 0.0000, 90.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[29], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[30] = CreateDynamicObject(18980, 206.1356, -1451.4482, 9.4630, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[30], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[31] = CreateDynamicObject(1649, 215.5621, -1442.0511, 18.8355, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[31], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[32] = CreateDynamicObject(18980, 217.1085, -1440.5549, 9.4630, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[32], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[33] = CreateDynamicObject(1649, 219.0153, -1438.6477, 18.8355, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[33], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[34] = CreateDynamicObject(1649, 222.8818, -1434.8314, 18.8355, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[34], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[35] = CreateDynamicObject(1649, 222.9084, -1431.0227, 18.8355, 0.0000, 0.0000, 134.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[35], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[36] = CreateDynamicObject(18980, 221.0480, -1429.0389, 9.7481, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[36], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[37] = CreateDynamicObject(1649, 219.0959, -1427.1556, 18.8355, 0.0000, 0.0000, 134.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[37], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[38] = CreateDynamicObject(18980, 217.3103, -1425.1129, 9.7481, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[38], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[39] = CreateDynamicObject(1649, 215.2904, -1423.2965, 18.8355, 0.0000, 0.0000, 134.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[39], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[40] = CreateDynamicObject(18980, 213.5726, -1421.1850, 9.7481, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[40], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[41] = CreateDynamicObject(1649, 211.5545, -1419.5072, 18.8355, 0.0000, 0.0000, 134.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[41], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[42] = CreateDynamicObject(1649, 222.9084, -1431.0227, 14.5452, 0.0000, 0.0000, 134.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[42], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[43] = CreateDynamicObject(1649, 219.1528, -1427.0992, 14.5452, 0.0000, 0.0000, 134.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[43], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[44] = CreateDynamicObject(1649, 215.4044, -1423.1832, 14.5452, 0.0000, 0.0000, 134.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[44], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[45] = CreateDynamicObject(1649, 211.7398, -1419.3232, 14.5452, 0.0000, 0.0000, 134.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[45], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[46] = CreateDynamicObject(18980, 216.5030, -1424.2679, 12.3849, 0.0000, 90.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[46], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[47] = CreateDynamicObject(1649, 207.9936, -1449.5118, 18.8355, 0.0000, 0.0000, 224.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[47], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[48] = CreateDynamicObject(1649, 211.8457, -1445.7137, 18.8355, 0.0000, 0.0000, 224.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[48], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[49] = CreateDynamicObject(1649, 215.5621, -1442.0511, 18.8355, 0.0000, 0.0000, 224.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[49], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[50] = CreateDynamicObject(1649, 219.0153, -1438.6477, 18.8355, 0.0000, 0.0000, 224.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[50], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[51] = CreateDynamicObject(1649, 222.8818, -1434.8314, 18.8355, 0.0000, 0.0000, 224.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[51], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[52] = CreateDynamicObject(1649, 207.9936, -1449.5118, 14.5452, 0.0000, 0.0000, 224.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[52], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[53] = CreateDynamicObject(1649, 211.8457, -1445.7137, 14.5452, 0.0000, 0.0000, 224.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[53], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[54] = CreateDynamicObject(1649, 222.9084, -1431.0227, 14.5452, 0.0000, 0.0000, 314.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[54], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[55] = CreateDynamicObject(1649, 219.1528, -1427.0992, 14.5452, 0.0000, 0.0000, 314.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[55], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[56] = CreateDynamicObject(1649, 215.4044, -1423.1832, 14.5452, 0.0000, 0.0000, 314.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[56], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[57] = CreateDynamicObject(1649, 211.7398, -1419.3232, 14.5452, 0.0000, 0.0000, 314.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[57], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[58] = CreateDynamicObject(1649, 222.9084, -1431.0227, 18.8355, 0.0000, 0.0000, 314.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[58], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[59] = CreateDynamicObject(1649, 219.0959, -1427.1556, 18.8355, 0.0000, 0.0000, 314.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[59], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[60] = CreateDynamicObject(1649, 215.2904, -1423.2965, 18.8355, 0.0000, 0.0000, 314.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[60], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[61] = CreateDynamicObject(1649, 211.5545, -1419.5072, 18.8355, 0.0000, 0.0000, 314.5997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[61], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[62] = CreateDynamicObject(18980, 209.9385, -1447.6256, 9.0429, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[62], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[63] = CreateDynamicObject(18981, 199.5565, -1425.7989, 10.6183, 0.0000, 25.7000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[63], 0, 18800, "mroadhelix1", "concreteoldpainted1", 0xFFFFFFFF);
	autoHausLuxus_Obj[64] = CreateDynamicObject(18763, 201.0733, -1427.1031, 14.1364, 0.0000, 0.0000, 44.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[64], 0, 9515, "bigboxtemp1", "sf_concrete1", 0xFFFFFFFF);
	autoHausLuxus_Obj[65] = CreateDynamicObject(18763, 202.6703, -1428.7998, 19.1464, 0.0000, 0.0000, 44.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[65], 0, 9515, "bigboxtemp1", "sf_concrete1", 0xFFFFFFFF);
	autoHausLuxus_Obj[66] = CreateDynamicObject(19464, 209.8661, -1442.9516, 9.7559, 0.0000, 0.0000, -136.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(autoHausLuxus_Obj[66], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	autoHausLuxus_Obj[67] = CreateDynamicObject(18766, 206.9656, -1443.4167, 11.8020, 90.0000, 0.0000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[67], 0, 10412, "hotel1", "carpet_red_256", 0xFF8B0000);
	autoHausLuxus_Obj[68] = CreateDynamicObject(18766, 203.3679, -1446.8852, 11.8000, 90.0000, 0.0000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[68], 0, 10412, "hotel1", "carpet_red_256", 0xFF8B0000);
	autoHausLuxus_Obj[69] = CreateDynamicObject(18766, 196.4208, -1439.6922, 11.8000, 90.0000, 0.0000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[69], 0, 10412, "hotel1", "carpet_red_256", 0xFF8B0000);
	autoHausLuxus_Obj[70] = CreateDynamicObject(18766, 193.0180, -1432.5754, 11.8037, 90.0000, 0.0000, -136.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[70], 0, 10412, "hotel1", "carpet_red_256", 0xFF8B0000);
	autoHausLuxus_Obj[71] = CreateDynamicObject(18766, 200.0178, -1436.2252, 11.8000, 90.0000, 0.0000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[71], 0, 10412, "hotel1", "carpet_red_256", 0xFF8B0000);
	autoHausLuxus_Obj[72] = CreateDynamicObject(19464, 205.7449, -1438.6839, 9.7559, 0.0000, 0.0000, -136.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(autoHausLuxus_Obj[72], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	autoHausLuxus_Obj[73] = CreateDynamicObject(19464, 201.6230, -1434.4156, 9.7559, 0.0000, 0.0000, -136.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(autoHausLuxus_Obj[73], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	autoHausLuxus_Obj[74] = CreateDynamicObject(19464, 197.5010, -1430.1479, 9.7559, 0.0000, 0.0000, -136.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(autoHausLuxus_Obj[74], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	autoHausLuxus_Obj[75] = CreateDynamicObject(18766, 210.4302, -1426.8365, 11.8020, 90.0000, 0.0000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[75], 0, 10412, "hotel1", "carpet_red_256", 0xFF8B0000);
	autoHausLuxus_Obj[76] = CreateDynamicObject(18766, 217.3771, -1434.0284, 11.8020, 90.0000, 0.0000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[76], 0, 10412, "hotel1", "carpet_red_256", 0xFF8B0000);
	autoHausLuxus_Obj[77] = CreateDynamicObject(18766, 203.4835, -1419.6434, 11.8020, 90.0000, 0.0000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[77], 0, 10412, "hotel1", "carpet_red_256", 0xFF8B0000);
	autoHausLuxus_Obj[78] = CreateDynamicObject(1649, 219.0153, -1438.6477, 14.5452, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[78], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[79] = CreateDynamicObject(19464, 204.0249, -1423.8459, 9.7559, 0.0000, 0.0000, -136.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(autoHausLuxus_Obj[79], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	autoHausLuxus_Obj[80] = CreateDynamicObject(18766, 219.8585, -1431.6291, 11.8009, 90.0000, 0.0000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[80], 0, 10412, "hotel1", "carpet_red_256", 0xFF8B0000);
	autoHausLuxus_Obj[81] = CreateDynamicObject(18766, 213.4949, -1423.8769, 11.8009, 90.0000, 0.0000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[81], 0, 10412, "hotel1", "carpet_red_256", 0xFF8B0000);
	autoHausLuxus_Obj[82] = CreateDynamicObject(18766, 205.9002, -1417.3083, 11.8009, 90.0000, 0.0000, -46.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[82], 0, 10412, "hotel1", "carpet_red_256", 0xFF8B0000);
	autoHausLuxus_Obj[83] = CreateDynamicObject(19464, 208.1459, -1428.1142, 9.7559, 0.0000, 0.0000, -136.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(autoHausLuxus_Obj[83], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	autoHausLuxus_Obj[84] = CreateDynamicObject(19464, 212.2680, -1432.3819, 9.7559, 0.0000, 0.0000, -136.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(autoHausLuxus_Obj[84], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	autoHausLuxus_Obj[85] = CreateDynamicObject(19464, 216.3898, -1436.6510, 9.7559, 0.0000, 0.0000, -136.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(autoHausLuxus_Obj[85], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	autoHausLuxus_Obj[86] = CreateDynamicObject(18762, 222.7893, -1434.9520, 12.3830, 0.0000, 90.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[86], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[87] = CreateDynamicObject(18980, 220.9678, -1436.7451, 9.4630, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[87], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[88] = CreateDynamicObject(1649, 222.8674, -1434.8443, 14.5452, 0.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[88], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[89] = CreateDynamicObject(1649, 222.8674, -1434.8443, 14.5452, 180.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[89], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[90] = CreateDynamicObject(1649, 219.0153, -1438.6477, 14.5452, 180.0000, 0.0000, 44.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[90], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[91] = CreateObject(8661, 204.2772, -1425.3358, 16.6742, 0.0000, 0.0000, -46.4000); //gnhtelgrnd_lvs
	SetDynamicObjectMaterial(autoHausLuxus_Obj[91], 0, 10412, "hotel1", "carpet_red_256", 0xFF8B0000);
	autoHausLuxus_Obj[92] = CreateDynamicObject(1886, 223.3710, -1432.9704, 21.6371, 15.0000, 0.0000, -84.0998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
	autoHausLuxus_Obj[93] = CreateDynamicObject(19426, 207.3361, -1452.7237, 18.8393, 0.0000, 0.0000, -136.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
	SetDynamicObjectMaterial(autoHausLuxus_Obj[93], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	autoHausLuxus_Obj[94] = CreateDynamicObject(2664, 202.6647, -1427.6313, 13.4638, 0.0000, 0.0000, 224.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SUBURB_DOOR
	SetDynamicObjectMaterial(autoHausLuxus_Obj[94], 3, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[95] = CreateDynamicObject(2664, 204.2198, -1429.3159, 17.8339, 0.0000, 0.0000, 224.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SUBURB_DOOR
	SetDynamicObjectMaterial(autoHausLuxus_Obj[95], 3, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
	autoHausLuxus_Obj[96] = CreateDynamicObject(1886, 206.1380, -1450.0467, 21.6452, 13.0999, 0.0000, 175.6000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
	autoHausLuxus_Obj[97] = CreateDynamicObject(1886, 195.3394, -1438.7259, 21.6543, 13.0999, 0.0000, 94.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
	autoHausLuxus_Obj[98] = CreateDynamicObject(1886, 206.1320, -1450.1223, 16.6422, 13.0999, 0.0000, 175.6000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
	autoHausLuxus_Obj[99] = CreateDynamicObject(1886, 193.4933, -1436.8331, 16.6508, 13.0999, 0.0000, 94.0998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
	autoHausLuxus_Obj[100] = CreateDynamicObject(1886, 211.0863, -1419.9641, 16.6508, 12.4996, 0.0000, 0.6000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
	autoHausLuxus_Obj[101] = CreateDynamicObject(1886, 223.4627, -1432.9659, 16.6252, 16.5998, 0.0000, -87.6996, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
	autoHausLuxus_Obj[102] = CreateDynamicObject(18075, 212.2686, -1438.6937, 16.5664, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	SetDynamicObjectMaterial(autoHausLuxus_Obj[102], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
	autoHausLuxus_Obj[103] = CreateDynamicObject(1886, 212.6226, -1421.6866, 21.6284, 15.0000, 0.0000, -14.9996, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
	autoHausLuxus_Obj[104] = CreateDynamicObject(18762, 199.3399, -1435.5914, 17.1049, 0.0000, 90.0000, -136.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(autoHausLuxus_Obj[104], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFD3D3D3);
	autoHausLuxus_Obj[105] = CreateDynamicObject(19565, 206.6264, -1451.9809, 19.7712, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(autoHausLuxus_Obj[105], 0, 3440, "airportpillar", "metalic_64", 0x00000000);
	autoHausLuxus_Obj[106] = CreateDynamicObject(19172, 207.5715, -1452.8546, 18.8554, 0.0000, 90.0000, -226.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(autoHausLuxus_Obj[106], 0, "Autohaus", OBJECT_MATERIAL_SIZE_256x128, "Arial", 65, 1, 0xFF000000, 0x00000000, 1);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[106], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[107] = CreateDynamicObject(18075, 204.8809, -1431.0063, 16.5664, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	SetDynamicObjectMaterial(autoHausLuxus_Obj[107], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
	autoHausLuxus_Obj[108] = CreateDynamicObject(19172, 207.1163, -1452.3769, 18.8554, 0.0000, 90.0000, -226.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(autoHausLuxus_Obj[108], 0, "Luxus", OBJECT_MATERIAL_SIZE_256x128, "Arial", 65, 1, 0xFFFF0000, 0x00000000, 1);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[108], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[109] = CreateDynamicObject(19172, 207.0829, -1452.5725, 18.8554, 180.0000, -90.0000, -226.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(autoHausLuxus_Obj[109], 0, "Autohaus", OBJECT_MATERIAL_SIZE_256x128, "Arial", 65, 1, 0xFF000000, 0x00000000, 1);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[109], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[110] = CreateDynamicObject(19172, 207.5106, -1453.0218, 18.8554, 180.0000, -90.0000, -226.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(autoHausLuxus_Obj[110], 0, "Luxus", OBJECT_MATERIAL_SIZE_256x128, "Arial", 65, 1, 0xFFFF0000, 0x00000000, 1);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[110], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[111] = CreateDynamicObject(1671, 198.9268, -1433.5012, 17.1226, 0.0000, 0.0000, 44.9999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
	autoHausLuxus_Obj[112] = CreateDynamicObject(19565, 206.6264, -1451.9809, 17.5510, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(autoHausLuxus_Obj[112], 0, 3440, "airportpillar", "metalic_64", 0x00000000);
	autoHausLuxus_Obj[113] = CreateDynamicObject(1722, 200.4281, -1444.5179, 16.6688, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
	autoHausLuxus_Obj[114] = CreateDynamicObject(19438, 198.6340, -1436.2452, 17.5240, 0.0000, 90.0000, -136.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall078
	SetDynamicObjectMaterial(autoHausLuxus_Obj[114], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFFFFFFFF);
	autoHausLuxus_Obj[115] = CreateDynamicObject(19893, 199.9411, -1434.3581, 17.6044, 0.0000, 0.0000, -129.6000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
	SetDynamicObjectMaterial(autoHausLuxus_Obj[115], 1, 10249, "ottos2_sfw", "ottos_pics_sfe", 0x00000000);
	autoHausLuxus_Obj[116] = CreateDynamicObject(2202, 196.1522, -1439.4267, 16.6427, 0.0000, 0.0000, -226.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PHOTOCOPIER_2
	autoHausLuxus_Obj[117] = CreateDynamicObject(19893, 198.2295, -1436.0738, 17.6044, 0.0000, 0.0000, -153.7998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
	SetDynamicObjectMaterial(autoHausLuxus_Obj[117], 1, 10249, "ottos2_sfw", "ottos_pics_sfe", 0x00000000);
	autoHausLuxus_Obj[118] = CreateDynamicObject(19438, 200.0334, -1434.9178, 17.5249, 0.0000, 90.0000, -136.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall078
	SetDynamicObjectMaterial(autoHausLuxus_Obj[118], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFFFFFFFF);
	autoHausLuxus_Obj[119] = CreateDynamicObject(1671, 197.4709, -1434.9337, 17.1226, 0.0000, 0.0000, 35.0998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
	autoHausLuxus_Obj[120] = CreateDynamicObject(1234, 211.1024, -1441.7292, 19.9906, 0.0000, 90.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[120], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[120], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[121] = CreateDynamicObject(2165, 206.6192, -1448.1040, 16.6382, 0.0000, 0.0000, 77.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
	SetDynamicObjectMaterial(autoHausLuxus_Obj[121], 5, 10765, "airportgnd_sfse", "black64", 0x00000000);
	autoHausLuxus_Obj[122] = CreateDynamicObject(1649, 208.0686, -1445.6888, 18.3253, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[122], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[123] = CreateDynamicObject(1649, 208.0686, -1445.6888, 18.3253, 0.0000, 0.0000, -226.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[123], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[124] = CreateDynamicObject(1649, 211.5704, -1442.2081, 18.3253, 0.0000, 0.0000, -226.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[124], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[125] = CreateDynamicObject(1234, 207.5937, -1445.1999, 19.9906, 0.0000, 90.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[125], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[125], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[126] = CreateDynamicObject(1234, 209.4214, -1447.1175, 19.9906, 0.0000, 90.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[126], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[126], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[127] = CreateDynamicObject(1234, 206.5247, -1444.0782, 18.1907, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[127], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[127], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[128] = CreateDynamicObject(1234, 206.5247, -1444.0782, 18.9080, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[128], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[128], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[129] = CreateDynamicObject(2773, 212.0711, -1433.8243, 17.1944, 0.0000, 0.0000, 44.2999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	autoHausLuxus_Obj[130] = CreateDynamicObject(1722, 204.9736, -1448.1623, 16.6688, 0.0000, 0.0000, -81.0999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
	autoHausLuxus_Obj[131] = CreateDynamicObject(1234, 210.0471, -1440.6207, 18.9060, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[131], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[131], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[132] = CreateDynamicObject(1234, 212.9095, -1443.6263, 19.9906, 0.0000, 90.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[132], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[132], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[133] = CreateDynamicObject(1649, 211.5704, -1442.2081, 18.3253, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[133], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[134] = CreateDynamicObject(1234, 210.0471, -1440.6207, 18.1958, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[134], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[134], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[135] = CreateDynamicObject(19174, 199.4812, -1443.7727, 19.0951, 0.0000, 0.0000, -226.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
	SetDynamicObjectMaterial(autoHausLuxus_Obj[135], 0, 10249, "ottos2_sfw", "ottos_pics_sfe", 0x00000000);
	autoHausLuxus_Obj[136] = CreateDynamicObject(1649, 206.5236, -1444.0666, 18.3253, 0.0000, 0.0000, 43.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[136], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[137] = CreateDynamicObject(1234, 204.9172, -1445.6097, 18.9080, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[137], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[137], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[138] = CreateDynamicObject(1234, 208.1253, -1442.5577, 18.9080, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[138], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[138], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[139] = CreateDynamicObject(1649, 206.5236, -1444.0666, 18.3253, 0.0000, 0.0000, -136.6000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(autoHausLuxus_Obj[139], 0, 1717, "cj_tv", "green_glass_64", 0xFF000000);
	autoHausLuxus_Obj[140] = CreateDynamicObject(1234, 208.1253, -1442.5577, 18.1679, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[140], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[140], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[141] = CreateDynamicObject(1234, 204.9172, -1445.6097, 18.1879, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[141], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[141], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[142] = CreateDynamicObject(1806, 209.9109, -1445.3342, 16.6790, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
	SetDynamicObjectMaterial(autoHausLuxus_Obj[142], 0, 18081, "cj_barb", "ab_leather_strips", 0x00000000);
	autoHausLuxus_Obj[143] = CreateDynamicObject(2165, 209.2760, -1444.1899, 16.6382, 0.0000, 0.0000, 16.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
	SetDynamicObjectMaterial(autoHausLuxus_Obj[143], 5, 2577, "cj_sex", "CJ_PAINTING9", 0x00000000);
	autoHausLuxus_Obj[144] = CreateDynamicObject(1234, 206.9963, -1443.6090, 19.9906, 0.0000, 90.0000, -136.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[144], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[144], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[145] = CreateDynamicObject(1234, 205.7073, -1444.8359, 19.9906, 0.0000, 90.0000, -136.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonesign
	SetDynamicObjectMaterial(autoHausLuxus_Obj[145], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[145], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[146] = CreateDynamicObject(19172, 204.9060, -1445.6114, 18.2350, 0.0000, 0.0000, -136.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(autoHausLuxus_Obj[146], 0, "1", OBJECT_MATERIAL_SIZE_256x128, "Arial", 100, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[146], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[147] = CreateDynamicObject(19172, 206.5428, -1444.0544, 18.2350, 0.0000, 0.0000, -136.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
	SetDynamicObjectMaterialText(autoHausLuxus_Obj[147], 0, "2", OBJECT_MATERIAL_SIZE_256x128, "Arial", 100, 1, 0xFFFFFFFF, 0x00000000, 0);
	SetDynamicObjectMaterial(autoHausLuxus_Obj[147], 1, 19297, "matlights", "invisible", 0x00000000);
	autoHausLuxus_Obj[148] = CreateDynamicObject(2162, 209.2153, -1446.6921, 16.6972, 0.0000, 0.0000, -226.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
	autoHausLuxus_Obj[149] = CreateDynamicObject(2162, 208.4750, -1446.3070, 16.6972, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
	autoHausLuxus_Obj[150] = CreateDynamicObject(1722, 208.7220, -1442.6075, 16.6688, 0.0000, 0.0000, -133.7998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
	autoHausLuxus_Obj[151] = CreateDynamicObject(1722, 209.9918, -1442.0875, 16.6688, 0.0000, 0.0000, -176.8999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
	autoHausLuxus_Obj[152] = CreateDynamicObject(1806, 208.0021, -1448.0173, 16.6790, 0.0000, 0.0000, 72.0998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_CHAIR
	SetDynamicObjectMaterial(autoHausLuxus_Obj[152], 0, 18081, "cj_barb", "ab_leather_strips", 0x00000000);
	autoHausLuxus_Obj[153] = CreateDynamicObject(1722, 205.2489, -1446.7590, 16.6688, 0.0000, 0.0000, -102.5999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
	autoHausLuxus_Obj[154] = CreateDynamicObject(2773, 208.8468, -1437.2403, 17.1944, 0.0000, 0.0000, 44.2999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	autoHausLuxus_Obj[155] = CreateDynamicObject(2773, 212.2411, -1440.7187, 17.1944, 0.0000, 0.0000, 44.2999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	autoHausLuxus_Obj[156] = CreateDynamicObject(18075, 211.6891, -1438.0849, 21.4563, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	SetDynamicObjectMaterial(autoHausLuxus_Obj[156], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
	autoHausLuxus_Obj[157] = CreateDynamicObject(2773, 215.5980, -1437.4405, 17.1944, 0.0000, 0.0000, 44.2999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	autoHausLuxus_Obj[158] = CreateDynamicObject(2773, 208.4058, -1433.5422, 17.1944, 0.0000, 0.0000, 137.0997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
	autoHausLuxus_Obj[159] = CreateDynamicObject(1722, 199.8762, -1443.9388, 16.6688, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
	autoHausLuxus_Obj[160] = CreateDynamicObject(1722, 199.3246, -1443.3597, 16.6688, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
	autoHausLuxus_Obj[161] = CreateDynamicObject(1722, 198.7866, -1442.7950, 16.6688, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //off_chairnu
	autoHausLuxus_Obj[162] = CreateDynamicObject(1808, 198.0041, -1441.8387, 16.6371, 0.0000, 0.0000, -226.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_WATERCOOLER2
	autoHausLuxus_Obj[163] = CreateDynamicObject(18075, 204.6479, -1430.6909, 21.4563, 0.0000, 0.0000, -46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	SetDynamicObjectMaterial(autoHausLuxus_Obj[163], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
	autoHausLuxus_Obj[164] = CreateObject(8661, 204.2772, -1425.3358, 16.6700, 0.0000, 0.0000, -46.4000); //gnhtelgrnd_lvs
}

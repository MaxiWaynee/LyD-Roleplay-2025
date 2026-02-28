#include <YSI\y_hooks>

// Global interior define
#define MAPS_CHEAPCARDEALERSHIPLS_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 130.0;

// Cheap car dealership points
#define CHEAPCARDEALERSHIPLS_COORDS    1808.0851, -1889.7792, 13.4073

// Map variables
new object_cheapCarDealershipLs[98];
new text3D_cheapCarDealershipLs[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(CHEAPCARDEALERSHIPLS_COORDS, 55, 0, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR);

    // 3DTextLabels
    text3D_cheapCarDealershipLs[0] = _:CreateDynamic3DTextLabel("Autohaus - Günstig\n" COLOR_HEX_WHITE "Steige in ein beliebiges Fahrzeug deiner Wahl ein!", COLOR_BLUE, CHEAPCARDEALERSHIPLS_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CHEAPCARDEALERSHIPLS_INTERIOR);

    // Objects
	object_cheapCarDealershipLs[0] = CreateDynamicObject(970, 1810.4207, -1881.6275, 13.0843, 0.0000, 0.0000, -89.5999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[0], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_cheapCarDealershipLs[1] = CreateDynamicObject(974, 1774.3227, -1894.5893, 11.4274, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[1], 0, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[1], 1, 6293, "lawland2", "lightglass", 0xFFFFFFFF);
    object_cheapCarDealershipLs[2] = CreateDynamicObject(974, 1774.3227, -1901.2198, 11.4274, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[2], 0, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[2], 1, 6293, "lawland2", "lightglass", 0xFFFFFFFF);
    object_cheapCarDealershipLs[3] = CreateDynamicObject(974, 1774.3227, -1907.8492, 11.4274, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[3], 0, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[3], 1, 6293, "lawland2", "lightglass", 0xFFFFFFFF);
    object_cheapCarDealershipLs[4] = CreateDynamicObject(974, 1774.3227, -1914.4986, 11.4274, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[4], 0, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[4], 1, 6293, "lawland2", "lightglass", 0xFFFFFFFF);
    object_cheapCarDealershipLs[5] = CreateDynamicObject(974, 1774.3227, -1921.1696, 11.4274, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[5], 0, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[5], 1, 6293, "lawland2", "lightglass", 0xFFFFFFFF);
    object_cheapCarDealershipLs[6] = CreateDynamicObject(974, 1774.3227, -1927.8496, 11.4274, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[6], 0, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[6], 1, 6293, "lawland2", "lightglass", 0xFFFFFFFF);
    object_cheapCarDealershipLs[7] = CreateDynamicObject(974, 1774.3227, -1931.1499, 11.4274, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[7], 0, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[7], 1, 6293, "lawland2", "lightglass", 0xFFFFFFFF);
    object_cheapCarDealershipLs[8] = CreateDynamicObject(974, 1777.7364, -1935.5697, 11.4274, 0.0000, 0.0000, 179.9998, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[8], 0, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[8], 1, 6293, "lawland2", "lightglass", 0xFFFFFFFF);
    object_cheapCarDealershipLs[9] = CreateDynamicObject(974, 1784.3967, -1935.5697, 11.4274, 0.0000, 0.0000, 179.9998, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[9], 0, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[9], 1, 6293, "lawland2", "lightglass", 0xFFFFFFFF);
    object_cheapCarDealershipLs[10] = CreateDynamicObject(974, 1790.9874, -1935.5697, 11.4274, 0.0000, 0.0000, 179.9998, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[10], 0, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[10], 1, 6293, "lawland2", "lightglass", 0xFFFFFFFF);
    object_cheapCarDealershipLs[11] = CreateDynamicObject(974, 1797.5783, -1935.5697, 11.4274, 0.0000, 0.0000, 179.9998, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[11], 0, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[11], 1, 6293, "lawland2", "lightglass", 0xFFFFFFFF);
    object_cheapCarDealershipLs[12] = CreateDynamicObject(974, 1800.8773, -1935.5697, 11.4274, 0.0000, 0.0000, 179.9998, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[12], 0, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[12], 1, 6293, "lawland2", "lightglass", 0xFFFFFFFF);
    object_cheapCarDealershipLs[13] = CreateDynamicObject(974, 1774.3227, -1888.0090, 11.4274, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[13], 0, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[13], 1, 6293, "lawland2", "lightglass", 0xFFFFFFFF);
    object_cheapCarDealershipLs[14] = CreateDynamicObject(19121, 1804.4953, -1935.6887, 13.0525, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_cheapCarDealershipLs[15] = CreateDynamicObject(19121, 1774.1739, -1935.3498, 13.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_cheapCarDealershipLs[16] = CreateDynamicObject(19121, 1774.1739, -1934.8393, 13.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_cheapCarDealershipLs[17] = CreateDynamicObject(19121, 1805.0860, -1935.6887, 13.0525, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_cheapCarDealershipLs[18] = CreateDynamicObject(19121, 1805.6159, -1935.6887, 13.0525, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_cheapCarDealershipLs[19] = CreateDynamicObject(19121, 1806.0864, -1935.6887, 13.0525, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_cheapCarDealershipLs[20] = CreateDynamicObject(19121, 1806.5067, -1935.6887, 13.0525, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_cheapCarDealershipLs[21] = CreateDynamicObject(19172, 1808.8957, -1881.5987, 13.9465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_cheapCarDealershipLs[21], 0,"Kauf dir ein Auto deiner Wahl!", 90, "Arial", 18, 1, 0xFF000000, 0x0, 0);
    object_cheapCarDealershipLs[22] = CreateDynamicObject(1223, 1774.4000, -1884.5000, 12.5000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lampost_coast
    object_cheapCarDealershipLs[23] = CreateDynamicObject(19172, 1809.0460, -1881.5987, 14.1965, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_cheapCarDealershipLs[23], 0,"Autohaus Günstig", 90, "Arial", 24, 1, 0xFF000000, 0x0, 0);
    object_cheapCarDealershipLs[24] = CreateDynamicObject(19121, 1811.2813, -1895.1325, 13.1134, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_cheapCarDealershipLs[25] = CreateDynamicObject(970, 1811.2850, -1897.4703, 13.0843, 0.0000, 0.0000, -90.0999, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[25], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_cheapCarDealershipLs[26] = CreateDynamicObject(19121, 1810.3713, -1884.0627, 13.1134, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_cheapCarDealershipLs[27] = CreateDynamicObject(3675, 1762.3000, -1883.8000, 19.3999, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //laxrf_refinerypipe
    object_cheapCarDealershipLs[28] = CreateDynamicObject(3675, 1763.3000, -1883.6999, 19.3999, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //laxrf_refinerypipe
    object_cheapCarDealershipLs[29] = CreateDynamicObject(3675, 1764.3000, -1883.6999, 19.3999, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //laxrf_refinerypipe
    object_cheapCarDealershipLs[30] = CreateDynamicObject(3675, 1765.3000, -1883.6999, 19.3999, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //laxrf_refinerypipe
    object_cheapCarDealershipLs[31] = CreateDynamicObject(983, 1787.6999, -1910.0998, 13.1000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[31], 4, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[31], 5, 6284, "bev_law2", "glass_fence_64hv", 0xFFFFFFFF);
    object_cheapCarDealershipLs[32] = CreateDynamicObject(983, 1790.9000, -1913.3000, 13.1000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[32], 4, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[32], 5, 6284, "bev_law2", "glass_fence_64hv", 0xFFFFFFFF);
    object_cheapCarDealershipLs[33] = CreateDynamicObject(983, 1790.9000, -1906.9000, 13.1000, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[33], 4, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[33], 5, 6284, "bev_law2", "glass_fence_64hv", 0xFFFFFFFF);
    object_cheapCarDealershipLs[34] = CreateDynamicObject(857, 1793.5000, -1907.8000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[35] = CreateDynamicObject(857, 1793.5000, -1908.5000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[36] = CreateDynamicObject(857, 1793.5000, -1909.3000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[37] = CreateDynamicObject(857, 1793.5000, -1910.0998, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[38] = CreateDynamicObject(857, 1793.5000, -1910.9000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[39] = CreateDynamicObject(857, 1793.5000, -1911.5998, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[40] = CreateDynamicObject(857, 1793.4000, -1912.8000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[41] = CreateDynamicObject(857, 1793.4000, -1912.1999, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[42] = CreateDynamicObject(857, 1792.8000, -1912.9000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[43] = CreateDynamicObject(857, 1792.0998, -1913.0000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[44] = CreateDynamicObject(857, 1791.1999, -1913.0000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[45] = CreateDynamicObject(857, 1790.0998, -1913.0998, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[46] = CreateDynamicObject(857, 1790.5000, -1913.0000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[47] = CreateDynamicObject(857, 1789.5998, -1912.9000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[48] = CreateDynamicObject(857, 1788.5000, -1912.9000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[49] = CreateDynamicObject(857, 1788.9000, -1912.9000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[50] = CreateDynamicObject(857, 1788.4000, -1912.1999, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[51] = CreateDynamicObject(857, 1788.3000, -1911.4000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[52] = CreateDynamicObject(857, 1788.1999, -1910.5000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[53] = CreateDynamicObject(857, 1788.3000, -1909.6999, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[54] = CreateDynamicObject(857, 1788.3000, -1908.6999, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[55] = CreateDynamicObject(857, 1788.1999, -1907.9000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[56] = CreateDynamicObject(857, 1788.8000, -1907.6999, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[57] = CreateDynamicObject(857, 1789.5000, -1907.6999, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[58] = CreateDynamicObject(857, 1790.1999, -1907.5998, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[59] = CreateDynamicObject(857, 1790.8000, -1907.5000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[60] = CreateDynamicObject(857, 1791.4000, -1907.5998, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[61] = CreateDynamicObject(857, 1792.1999, -1907.5998, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[62] = CreateDynamicObject(857, 1792.9000, -1907.5000, 12.6998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //procweegrs
    object_cheapCarDealershipLs[63] = CreateDynamicObject(870, 1792.3000, -1911.6999, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[64] = CreateDynamicObject(870, 1792.0000, -1911.5000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[65] = CreateDynamicObject(870, 1790.9000, -1911.5998, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[66] = CreateDynamicObject(870, 1790.0998, -1911.5998, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[67] = CreateDynamicObject(870, 1789.3000, -1911.4000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[68] = CreateDynamicObject(870, 1789.4000, -1910.5000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[69] = CreateDynamicObject(870, 1789.6999, -1910.5998, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[70] = CreateDynamicObject(870, 1789.5000, -1909.5000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[71] = CreateDynamicObject(870, 1789.6999, -1909.0000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[72] = CreateDynamicObject(870, 1789.6999, -1908.5000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[73] = CreateDynamicObject(870, 1789.0998, -1908.8000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[74] = CreateDynamicObject(870, 1790.3000, -1908.3000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[75] = CreateDynamicObject(870, 1790.9000, -1908.6999, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[76] = CreateDynamicObject(870, 1791.5000, -1908.1999, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[77] = CreateDynamicObject(870, 1792.0998, -1908.5998, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[78] = CreateDynamicObject(870, 1792.0998, -1909.0998, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[79] = CreateDynamicObject(870, 1791.6999, -1909.4000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[80] = CreateDynamicObject(870, 1791.5000, -1910.3000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[81] = CreateDynamicObject(870, 1791.5000, -1910.2998, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[82] = CreateDynamicObject(870, 1792.0998, -1911.4000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[83] = CreateDynamicObject(870, 1792.0998, -1911.5000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[84] = CreateDynamicObject(870, 1791.5000, -1911.3000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[85] = CreateDynamicObject(870, 1790.4000, -1911.3000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[86] = CreateDynamicObject(870, 1789.9000, -1911.3000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[87] = CreateDynamicObject(870, 1789.5000, -1911.3000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[88] = CreateDynamicObject(870, 1789.5998, -1909.6999, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[89] = CreateDynamicObject(870, 1789.6999, -1908.8000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[90] = CreateDynamicObject(870, 1789.6999, -1908.5000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[91] = CreateDynamicObject(870, 1791.0998, -1908.5998, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[92] = CreateDynamicObject(870, 1792.1999, -1908.5998, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[93] = CreateDynamicObject(870, 1792.0998, -1908.8000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[94] = CreateDynamicObject(870, 1791.9000, -1910.1999, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[95] = CreateDynamicObject(870, 1791.8000, -1910.5000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[96] = CreateDynamicObject(870, 1790.8000, -1910.9000, 12.6000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_cheapCarDealershipLs[97] = CreateDynamicObject(983, 1794.0998, -1910.0998, 13.1000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CHEAPCARDEALERSHIPLS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[97], 4, 18064, "ab_sfammuunits", "gun_blackbox", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_cheapCarDealershipLs[97], 5, 6284, "bev_law2", "glass_fence_64hv", 0xFFFFFFFF);
}

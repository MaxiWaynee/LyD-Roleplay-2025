#include <YSI\y_hooks>

// Global interior define
#define MAPS_PAINTBALLLOBBYINTERIOR_INTERIOR      15
#define MAPS_PAINTBALLLOBBYEXTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
//static Float:STREAMDISTANCE = 350.0;
//static Float:DRAWDISTANCE   = 350.0;

// Paintball Looby Interior points
#define PAINTBALLLOBBYINTERIOR_INFO_POINT            2217.4167, -1146.7381, 1025.8204
#define PAINTBALLLOBBYINTERIOR_EXIT_COORDS           2214.8164, -1150.5255, 1025.8259

#define PAINTBALLLOBBYINTERIOR_SPAWN_POINT1          2222.8162, -1150.1945, 1025.8259
#define PAINTBALLLOBBYINTERIOR_SPAWN_POINT2          2222.8162, -1150.1945, 1025.8259
#define PAINTBALLLOBBYINTERIOR_SPAWN_FACING          90.0

// Map variables

new pickup_paintballLobbyInterior[2];
new text3D_paintballLobbyInterior[1];
new object_paintballLobbyInterior[51];
new actor_paintballLobbyInterior[1];

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 14517, 2221.8798, -1148.0899, 1026.1500, 0.10); // im_xtra1
    RemoveBuildingForPlayer(playerid, 1775, 2225.1999, -1153.4200, 1025.9100, 0.10); // CJ_SPRUNK1
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, PAINTBALLLOBBYINTERIOR_EXIT_COORDS)) { // Exit
            ExitPaintBallInterior(playerid);
        }
    }
}

hook OnGameModeInit() {
    // Pickups
    pickup_paintballLobbyInterior[0] = CreateDynamicPickup(1239, 1, PAINTBALLLOBBYINTERIOR_INFO_POINT, VW_PAINTBALLLOBBY, MAPS_PAINTBALLLOBBYINTERIOR_INTERIOR); // Info point
    pickup_paintballLobbyInterior[1] = CreateDynamicPickup(19197, 1, PAINTBALLLOBBYINTERIOR_EXIT_COORDS, VW_PAINTBALLLOBBY, MAPS_PAINTBALLLOBBYINTERIOR_INTERIOR); // Exit

    // 3DTextLabels
    text3D_paintballLobbyInterior[0] = _:CreateDynamic3DTextLabel("Paintball-Arena\n" COLOR_HEX_WHITE "Tippe /Paintball", COLOR_BLUE, PAINTBALLLOBBYINTERIOR_INFO_POINT, 15.0, .testlos = 1); // Info point
    
    // Actors
    actor_paintballLobbyInterior[0] = CreateDynamicActor(179, 2217.4929, -1144.9099, 1026.4416, 180.0); // Ammunation Salesman
    ApplyDynamicActorAnimation(actor_paintballLobbyInterior[0], "BAR", "BARMAN_IDLE", 4.1, 1, 0, 0, 0, 0);

    // Objects
    object_paintballLobbyInterior[0] = CreateDynamicObject(2700, 2226.0659, -1151.2381, 1027.2253, 0.0000, 0.0000, 90.0000); //CJ_SEX_TV2
    SetDynamicObjectMaterial(object_paintballLobbyInterior[0], 0, 14489, "carlspics", "AH_picture4", 0x00000000);
    object_paintballLobbyInterior[1] = CreateDynamicObject(1723, 2224.7768, -1144.6086, 1024.7368, 0.0000, 0.0000, 0.0000); //mrk_seating1
    object_paintballLobbyInterior[2] = CreateDynamicObject(8661, 2229.8276, -1148.5196, 1024.8259, 0.0000, 0.0000, 0.0000); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_paintballLobbyInterior[2], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_paintballLobbyInterior[3] = CreateDynamicObject(19464, 2221.9233, -1143.8398, 1025.8220, 0.0000, 0.0000, 90.0000); //wall104
    SetDynamicObjectMaterial(object_paintballLobbyInterior[3], 0, 19853, "mihouse1", "brownwall1", 0xFFBC8F8F);
    object_paintballLobbyInterior[4] = CreateDynamicObject(1656, 2228.8217, -1150.5118, 1027.6429, -90.0000, 0.0000, 90.0000); //Esc_step
    SetDynamicObjectMaterial(object_paintballLobbyInterior[4], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_paintballLobbyInterior[5] = CreateDynamicObject(19172, 2228.7055, -1150.5008, 1027.6279, 0.0000, 0.0000, -90.0000); //SAMPPicture1
    SetDynamicObjectMaterialText(object_paintballLobbyInterior[5], 0, "STAFF", OBJECT_MATERIAL_SIZE_256x128, "Arial", 20, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_paintballLobbyInterior[5], 1, 19297, "matlights", "invisible", 0x00000000);
    object_paintballLobbyInterior[6] = CreateDynamicObject(19464, 2227.8601, -1143.8398, 1025.8220, 0.0000, 0.0000, 90.0000); //wall104
    SetDynamicObjectMaterial(object_paintballLobbyInterior[6], 0, 19853, "mihouse1", "brownwall1", 0xFFBC8F8F);
    object_paintballLobbyInterior[7] = CreateDynamicObject(19363, 2222.9311, -1143.9995, 1026.5461, 0.0000, 0.0000, 0.0000); //wall011
    SetDynamicObjectMaterial(object_paintballLobbyInterior[7], 0, 2755, "ab_dojowall", "ab_trellis", 0x00000000);
    object_paintballLobbyInterior[8] = CreateDynamicObject(356, 2217.2741, -1139.6451, 1025.8392, -106.0998, -4.5000, -9.3999); //m4
    object_paintballLobbyInterior[9] = CreateDynamicObject(19454, 2216.6330, -1141.1070, 1024.8927, 0.0000, 90.0000, 0.0000); //wall094
    object_paintballLobbyInterior[10] = CreateDynamicObject(2372, 2215.1701, -1140.7937, 1025.0421, 0.0000, 0.0000, 0.0000); //CLOTHES_RAIL2
    object_paintballLobbyInterior[11] = CreateDynamicObject(1723, 2228.1367, -1145.9593, 1024.7368, 0.0000, 0.0000, -90.0000); //mrk_seating1
    object_paintballLobbyInterior[12] = CreateDynamicObject(373, 2214.9846, -1141.0742, 1026.0654, -28.3999, -51.5998, 4.0998); //armour
    object_paintballLobbyInterior[13] = CreateDynamicObject(1723, 2218.5964, -1154.8509, 1024.7368, 0.0000, 0.0000, 180.0000); //mrk_seating1
    object_paintballLobbyInterior[14] = CreateDynamicObject(2002, 2225.1132, -1152.9709, 1024.8076, 0.0000, 0.0000, -90.0000); //water_coolnu
    object_paintballLobbyInterior[15] = CreateDynamicObject(2001, 2214.6501, -1154.9160, 1024.8103, 0.0000, 0.0000, 0.0000); //nu_plant_ofc
    object_paintballLobbyInterior[16] = CreateDynamicObject(1724, 2214.7976, -1153.4166, 1024.7402, 0.0000, 0.0000, 90.0000); //mrk_seating1b
    object_paintballLobbyInterior[17] = CreateDynamicObject(2315, 2216.8281, -1152.9056, 1024.7878, 0.0000, 0.0000, 0.0000); //CJ_TV_TABLE4
    object_paintballLobbyInterior[18] = CreateDynamicObject(373, 2214.9399, -1140.4150, 1026.0638, -28.3999, -51.5998, 4.0998); //armour
    object_paintballLobbyInterior[19] = CreateDynamicObject(1742, 2219.9086, -1143.8736, 1024.8050, 0.0000, 0.0000, 0.0000); //Med_BOOKSHELF
    object_paintballLobbyInterior[20] = CreateDynamicObject(373, 2214.9755, -1139.6645, 1026.0526, -28.3999, -51.5998, 4.0998); //armour
    object_paintballLobbyInterior[21] = CreateDynamicObject(19922, 2217.6262, -1139.1424, 1025.0039, 0.0000, 0.0000, -0.1999); //MKTable1
    object_paintballLobbyInterior[22] = CreateDynamicObject(2059, 2217.3574, -1152.8126, 1025.2917, 0.0000, 0.0000, 0.0000); //CJ_GUNSTUFF1
    object_paintballLobbyInterior[23] = CreateDynamicObject(19922, 2217.6298, -1138.3293, 1024.9936, 0.0000, 0.0000, -0.1999); //MKTable1
    object_paintballLobbyInterior[24] = CreateDynamicObject(19922, 2219.9284, -1139.1490, 1025.0029, 0.0000, 0.0000, -0.1999); //MKTable1
    object_paintballLobbyInterior[25] = CreateDynamicObject(19922, 2219.9291, -1138.3198, 1025.0008, 0.0000, 0.0000, -0.1999); //MKTable1
    object_paintballLobbyInterior[26] = CreateDynamicObject(8661, 2229.8276, -1145.8907, 1028.2956, 0.0000, 180.0000, 0.0000); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_paintballLobbyInterior[26], 0, 3442, "vegashse4", "Est_corridor_ceiling", 0x00000000);
    object_paintballLobbyInterior[27] = CreateDynamicObject(2001, 2228.1735, -1144.4974, 1024.8103, 0.0000, 0.0000, 0.0000); //nu_plant_ofc
    object_paintballLobbyInterior[28] = CreateDynamicObject(348, 2216.2778, -1139.1555, 1025.8546, -83.8999, 0.3998, 0.0000); //desert_eagle
    object_paintballLobbyInterior[29] = CreateDynamicObject(19835, 2218.2890, -1152.8227, 1025.3725, 0.0000, 0.0000, 0.0000); //CoffeeCup1
    object_paintballLobbyInterior[30] = CreateDynamicObject(19835, 2216.6381, -1152.7828, 1025.3725, 0.0000, 0.0000, 0.0000); //CoffeeCup1
    object_paintballLobbyInterior[31] = CreateDynamicObject(19835, 2217.9189, -1153.1529, 1025.3725, 0.0000, 0.0000, 0.0000); //CoffeeCup1
    object_paintballLobbyInterior[32] = CreateDynamicObject(19835, 2218.1391, -1145.1722, 1026.0931, 0.0000, 0.0000, 0.0000); //CoffeeCup1
    object_paintballLobbyInterior[33] = CreateDynamicObject(1823, 2220.6218, -1155.4160, 1024.7596, 0.0000, 0.0000, 0.0000); //COFFEE_MED_5
    object_paintballLobbyInterior[34] = CreateDynamicObject(19835, 2220.8281, -1155.1689, 1025.3425, 0.0000, 0.0000, 0.0000); //CoffeeCup1
    object_paintballLobbyInterior[35] = CreateDynamicObject(19835, 2220.8281, -1155.1689, 1025.3824, 0.0000, 0.0000, 0.0000); //CoffeeCup1
    object_paintballLobbyInterior[36] = CreateDynamicObject(19835, 2220.8281, -1155.1689, 1025.4123, 0.0000, 0.0000, 0.0000); //CoffeeCup1
    object_paintballLobbyInterior[37] = CreateDynamicObject(19835, 2220.8281, -1155.1689, 1025.4526, 0.0000, 0.0000, 0.0000); //CoffeeCup1
    object_paintballLobbyInterior[38] = CreateDynamicObject(11743, 2221.3823, -1155.0671, 1025.2126, 0.0000, 0.0000, 180.0000); //MCoffeeMachine1
    object_paintballLobbyInterior[39] = CreateDynamicObject(19835, 2221.0385, -1154.9990, 1025.3425, 0.0000, 0.0000, 0.0000); //CoffeeCup1
    object_paintballLobbyInterior[40] = CreateDynamicObject(19835, 2220.7910, -1154.7281, 1025.3425, 0.0000, 0.0000, -59.5998); //CoffeeCup1
    object_paintballLobbyInterior[41] = CreateDynamicObject(19835, 2228.0324, -1145.5539, 1025.6827, 0.0000, 0.0000, -59.5998); //CoffeeCup1
    object_paintballLobbyInterior[42] = CreateDynamicObject(8661, 2229.8276, -1155.4300, 1024.8259, -90.0000, 0.0000, 0.0000); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_paintballLobbyInterior[42], 0, 19853, "mihouse1", "brownwall1", 0xFFBC8F8F);
    object_paintballLobbyInterior[43] = CreateDynamicObject(1724, 2221.3491, -1144.4873, 1024.7402, 0.0000, 0.0000, -27.3999); //mrk_seating1b
    object_paintballLobbyInterior[44] = CreateDynamicObject(18075, 2218.4812, -1149.1440, 1028.3675, 0.0000, 0.0000, 0.0000); //lightD
    object_paintballLobbyInterior[45] = CreateDynamicObject(2987, 2223.5493, -1155.4150, 1026.0246, 0.0000, 0.0000, 180.0000); //lxr_motel_doorsim
    object_paintballLobbyInterior[46] = CreateDynamicObject(19172, 2223.5305, -1155.3131, 1027.5378, 0.0000, 0.0000, -180.0000); //SAMPPicture1
    SetDynamicObjectMaterialText(object_paintballLobbyInterior[46], 0, "STAFF", OBJECT_MATERIAL_SIZE_256x128, "Arial", 20, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_paintballLobbyInterior[46], 1, 19297, "matlights", "invisible", 0x00000000);
    object_paintballLobbyInterior[47] = CreateDynamicObject(1656, 2223.5266, -1155.4348, 1027.5531, -90.0000, 90.0000, 90.0000); //Esc_step
    SetDynamicObjectMaterial(object_paintballLobbyInterior[47], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0x00000000);
    object_paintballLobbyInterior[48] = CreateDynamicObject(2001, 2225.2412, -1154.9160, 1024.8103, 0.0000, 0.0000, 0.0000); //nu_plant_ofc
    object_paintballLobbyInterior[49] = CreateDynamicObject(19786, 2225.8208, -1143.8745, 1027.0063, 0.0000, 0.0000, 0.0000); //LCDTVBig1
    SetDynamicObjectMaterial(object_paintballLobbyInterior[49], 0, 14581, "ab_mafiasuitea", "ab_wood01", 0x00000000);
    SetDynamicObjectMaterial(object_paintballLobbyInterior[49], 1, 14420, "dr_gsbits", "mp_apt1_pic5", 0x00000000);
    object_paintballLobbyInterior[50] = CreateDynamicObject(19786, 2217.5842, -1155.5455, 1026.9565, 0.0000, 0.0000, 180.0000); //LCDTVBig1
    SetDynamicObjectMaterial(object_paintballLobbyInterior[50], 0, 14581, "ab_mafiasuitea", "ab_wood01", 0x00000000);
    SetDynamicObjectMaterial(object_paintballLobbyInterior[50], 1, 14420, "dr_gsbits", "mp_apt1_pic6", 0x00000000);
}

stock ExitPaintBallInterior(playerid) {
    SetPlayerInterior(playerid,0);
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerPos(playerid, 1739.3101,-1583.1500,14.1583);
    SetPlayerFacingAngle(playerid, 39.7703);
    SetCameraBehindPlayer(playerid);
    return 1;
}

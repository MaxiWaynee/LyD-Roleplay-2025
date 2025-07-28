#include <YSI\y_hooks>

// Global interior define
#define MAPS_BANKEXTERIORLV_INTERIOR      0
#define MAPS_BANKINTERIORLV_INTERIOR      3

// Local drawdistance & streamdistance setting
//static Float:STREAMDISTANCE = 350.0;
//static Float:DRAWDISTANCE   = 350.0;

// Bank Exterior LV Points
#define BANKINTERIORLV_EXIT_COORDS      288.7102, 167.3666, 1007.1719
#define BANKINTERIORLV_EXIT_FACING      0.0
#define BANKINTERIORLV_ENTER_COORDS     1952.5675, 1342.9261, 15.3672
#define BANKINTERIORLV_ENTER_FACING     270.0
#define BANKINTERIORLV_VAULT_CLOSED     296.91638, 189.45781, 1008.11816
#define BANKINTERIORLV_VAULT_OPEN       296.91638-3, 189.45781, 1008.11816

// Map variables
//new object_bankExteriorLv[0];
new pickup_bankExteriorLv[1];
new text3D_bankExteriorLv[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, BANKINTERIORLV_ENTER_COORDS)) {
            if (g_iBankraubLVStatus == Bankraub_Aktiv)
		        if (!IsPlayerExecutive(playerid))
					return SendClientMessage(playerid, COLOR_RED, "Du kannst die Zentralbank nicht betreten, weil die Polizei aufgrund eines Überfalles die Bank gesperrt hat!");
            
            SetPlayerVirtualWorld(playerid, VW_BANKINTERIORLV);
            SetPlayerInterior(playerid, MAPS_BANKINTERIORLV_INTERIOR);
            SetPlayerPos(playerid, BANKINTERIORLV_EXIT_COORDS);
            SetPlayerFacingAngle(playerid, BANKINTERIORLV_EXIT_FACING);
            SetCameraBehindPlayer(playerid);

            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Map Icons
    CreateDynamicMapIcon(BANKINTERIORLV_ENTER_COORDS, 52, 0, VW_MAIN, MAPS_BANKEXTERIORLV_INTERIOR);

    // Pickups
    pickup_bankExteriorLv[0] = CreateDynamicPickup(19197, 1, BANKINTERIORLV_ENTER_COORDS, VW_MAIN, MAPS_BANKEXTERIORLV_INTERIOR); // Bank interior enter 

    // 3DTextLabels
    text3D_bankExteriorLv[0] = _:CreateDynamic3DTextLabel("Zentralbank Las Venturas\n" COLOR_HEX_WHITE "Gebäude betreten mit 'Enter'", COLOR_BLUE, BANKINTERIORLV_ENTER_COORDS, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BANKEXTERIORLV_INTERIOR);

    // Objects
    
}
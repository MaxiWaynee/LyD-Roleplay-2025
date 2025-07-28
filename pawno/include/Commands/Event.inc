#include <YSI\y_hooks>


enum E_AEVENT_ITEM {
    AEVENT_ITEM_INDEX,
    AEVENT_ITEM_AMMO
}

#define MAX_EVENT_ITEMS 32
new aEventItems[12][E_AEVENT_ITEM];
new bool:gEventItem;
new bool:gEventItemType;

enum {
    WEAPON_MELEE,
    WEAPON_SPRAY,
    WEAPON_GUN,
    WEAPON_THROWABLE,
    WEAPON_OTHER
}

enum E_EVENT_ITEM {
    EVENT_ITEM_TYPE,
    EVENT_ITEM_SLOT,
    EVENT_ITEM_ID,
    EVENT_ITEM_NAME[30]
}

new const g_EventItems[][E_EVENT_ITEM] = {
    {WEAPON_GUN,     2, 24, "Desert Eagle"},
    {WEAPON_GUN,     4, 29, "MP5"},
    {WEAPON_GUN,     5, 31, "M4"},
    {WEAPON_GUN,     5, 30, "AK-47"},
    {WEAPON_GUN,     6, 34, "Sniper"},
    {WEAPON_GUN,     3, 25, "Schrotflinte"},
    {WEAPON_GUN,     2, 22, "9mm Pistole"},
    {WEAPON_GUN,     2, 23, "Schallgedämpfte Pistole"},
    {WEAPON_GUN,     3, 26, "Abgesägte Schrotflinte"},
    {WEAPON_GUN,     3, 27, "Combat Shotgun"},
    {WEAPON_GUN,     4, 28, "Uzi"},
    {WEAPON_GUN,     4, 32, "Tec-9"},
    {WEAPON_GUN,     6, 33, "Jagdgewehr"},
    {WEAPON_MELEE,   0,  1, "Schlagring"},
    {WEAPON_MELEE,   1,  5, "Baseballschläger"},
    {WEAPON_MELEE,   1,  8, "Katana"},
    {WEAPON_MELEE,   1,  2, "Golfschläger"},
    {WEAPON_MELEE,   1,  3, "Schlagstock"},
    {WEAPON_MELEE,   1,  6, "Schaufel"},
    {WEAPON_MELEE,   1,  7, "Pool Cue"},
    {WEAPON_MELEE,   1,  9, "Kettensäge"},
    {WEAPON_MELEE,  10, 10, "Violetter Dildo"},
    {WEAPON_MELEE,  10, 11, "Normaler Dildo"},
    {WEAPON_MELEE,  10, 12, "Vibrator"},
    {WEAPON_MELEE,  10, 13, "Silbener Vibrator"},
    {WEAPON_MELEE,  10, 14, "Blumenstrauß"},
    {WEAPON_MELEE,  10, 15, "Gehstock"},
    {WEAPON_SPRAY,   9, 41, "Spraydose"},
    {WEAPON_SPRAY,   9, 42, "Feuerlöscher"},
    {WEAPON_OTHER,   0, -1, "Schutzweste"},
    {WEAPON_OTHER,  11, 46, "Fallschirm"},
    {WEAPON_OTHER,   9, 43, "Kamera"}
};

CMD:eventitem(playerid)
{
    if (Spieler[playerid][pLevel] < 3) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst mindestens Level 3 dafür sein.");
    if (!gEventItem) return SendClientMessage(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Die Eventitems sind nicht aktiv.");
    if (gEventItemType && GetPVarInt(playerid, "EVENTITEM")) return SendClientMessage(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Die Eventitems können nur einmal genutzt werden.");
    
    ResetPlayerWeapons(playerid);
    SetPlayerHealth(playerid, 100.0);
    SetPlayerArmour(playerid, aEventItems[0][AEVENT_ITEM_AMMO]);
    for (new i = 1; i < sizeof(aEventItems); i++) {
        if (!aEventItems[i][AEVENT_ITEM_INDEX]) continue;
        GivePlayerWeapon(playerid, g_EventItems[aEventItems[i][AEVENT_ITEM_INDEX] - 1][EVENT_ITEM_ID], aEventItems[i][AEVENT_ITEM_AMMO]);
    }

    SetPVarInt(playerid, "EVENTITEM", 1);
    return SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Eventitems erhalten.");
}


CMD:gotoevent(playerid,params[]) {
    if( !g_Event[E_bStatus] ) {
        return SendClientMessage(playerid, COLOR_BLUE, "Aktuell läuft kein Event");
    }
    if( 1 <= Spieler[playerid][pJailed] <= 3 ) {
        return SendClientMessage(playerid, COLOR_RED, "Pech gehabt! Du kannst aus dem Gefängnis heraus an keinem Event teilnehmen!");
    }
    new
        String[128];
    format(String,sizeof(String),"[EVENT] %s hat sich zum Event teleportiert ( /Gotoevent )",GetName(playerid));
    SendClientMessageToAll(COLOR_ORANGE,String);

    Streamer_UpdateEx(playerid,g_Event[E_fX],g_Event[E_fY],g_Event[E_fZ],g_Event[E_iVirtualworld],g_Event[E_iVirtualworld]);
    SetPlayerPos(playerid,g_Event[E_fX],g_Event[E_fY],g_Event[E_fZ]);
    SetPlayerVirtualWorld(playerid,g_Event[E_iVirtualworld]);
    SetPlayerInterior(playerid,g_Event[E_iInterior]);
    return 1;
}
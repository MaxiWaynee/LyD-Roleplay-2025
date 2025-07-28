#include <YSI\y_hooks>

// Defines

#define MAX_PUMPKINS 100

// Custom functions

// Function hooks

// hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
//     return 1;
// }

// hook OnPlayerSpawn(playerid) {
//     return 1;
// }

// hook OnPlayerDisconnect(playerid, reason) {
//     return 1;
// }

enum {
    PUMPKIN_STATUS_NONE,
    PUMPKIN_STATUS_CREATED,
    PUMPKIN_STATUS_FOUND
}

enum E_PUMPKIN {
    bool:PUMPKIN_INUSE,
    bool:PUMPKIN_VISIBLE,
    PUMPKIN_ID,
    PUMPKIN_STATUS,
    Float:PUMPKIN_X,
    Float:PUMPKIN_Y,
    Float:PUMPKIN_Z,
    PUMPKIN_OBJECT,
    STREAMER_TAG_3D_TEXT_LABEL:PUMPKIN_TEXT3D
}

new g_Pumpkins[MAX_PUMPKINS][E_PUMPKIN];


// Custom Functions

stock AddPumpkin(Float:x, Float:y, Float:z, status = PUMPKIN_STATUS_CREATED, bool:visible = false) {
    for (new i = 0; i < sizeof(g_Pumpkins); i++) {
        if (g_Pumpkins[i][PUMPKIN_INUSE]) continue;
        g_Pumpkins[i][PUMPKIN_INUSE] = true;
        g_Pumpkins[i][PUMPKIN_X] = x;
        g_Pumpkins[i][PUMPKIN_Y] = y;
        g_Pumpkins[i][PUMPKIN_Z] = z;
        g_Pumpkins[i][PUMPKIN_STATUS] = status;
        g_Pumpkins[i][PUMPKIN_VISIBLE] = visible;
        if (visible) {
            g_Pumpkins[i][PUMPKIN_OBJECT] = CreateDynamicObject(19320, x, y, z - 0.67, 0.0, 0.0, 0.0, VW_MAIN, .streamdistance = 90.0, .drawdistance = 80.0);
            g_Pumpkins[i][PUMPKIN_TEXT3D] = CreateDynamic3DTextLabel(status == PUMPKIN_STATUS_FOUND ? "[ {FF9900}Kürbis {FFFFFF}]\n\n{FF2200}Dieser Kürbis wurde bereits gefunden!" :
                "[ {FF9900}Kürbis {FFFFFF}]\n\n{FFFF00}Ernte den Kürbis mit /kuerbis!", COLOR_WHITE, x, y, z - 0.67, .testlos = 1, .streamdistance = 30.0, .drawdistance = 20.0);
        }
        return i;
    }

    return -1;
}

stock DeletePumpkin(pumpkinID) {
    if (!g_Pumpkins[pumpkinID][PUMPKIN_INUSE]) return 0;
    g_Pumpkins[pumpkinID][PUMPKIN_INUSE] = false;
    g_Pumpkins[pumpkinID][PUMPKIN_X] = 0.0;
    g_Pumpkins[pumpkinID][PUMPKIN_Y] = 0.0;
    g_Pumpkins[pumpkinID][PUMPKIN_Z] = 0.0;
    g_Pumpkins[pumpkinID][PUMPKIN_STATUS] = PUMPKIN_STATUS_NONE;
    if (g_Pumpkins[pumpkinID][PUMPKIN_VISIBLE]) {
        DestroyDynamicObject(g_Pumpkins[pumpkinID][PUMPKIN_OBJECT]);
        g_Pumpkins[pumpkinID][PUMPKIN_OBJECT] = 0;
        DestroyDynamic3DTextLabel(g_Pumpkins[pumpkinID][PUMPKIN_TEXT3D]);
        g_Pumpkins[pumpkinID][PUMPKIN_TEXT3D] = STREAMER_TAG_3D_TEXT_LABEL:INVALID_3DTEXT_ID;
    }

    g_Pumpkins[pumpkinID][PUMPKIN_VISIBLE] = false;
    return 1;
}

stock HidePumpkin(pumpkinID) {
    if (!g_Pumpkins[pumpkinID][PUMPKIN_INUSE]) return 0;
    if (!g_Pumpkins[pumpkinID][PUMPKIN_VISIBLE]) return 1;

    DestroyDynamicObject(g_Pumpkins[pumpkinID][PUMPKIN_OBJECT]);
    g_Pumpkins[pumpkinID][PUMPKIN_OBJECT] = 0;
    DestroyDynamic3DTextLabel(g_Pumpkins[pumpkinID][PUMPKIN_TEXT3D]);
    g_Pumpkins[pumpkinID][PUMPKIN_TEXT3D] = STREAMER_TAG_3D_TEXT_LABEL:INVALID_3DTEXT_ID;
    g_Pumpkins[pumpkinID][PUMPKIN_VISIBLE] = false;
    return 1;
}

stock ShowPumpkin(pumpkinID) {
    if (!g_Pumpkins[pumpkinID][PUMPKIN_INUSE]) return 0;
    if (g_Pumpkins[pumpkinID][PUMPKIN_VISIBLE]) return 1;

    g_Pumpkins[i][PUMPKIN_OBJECT] = CreateDynamicObject(19320, x, y, z - 0.67, 0.0, 0.0, 0.0, VW_MAIN, .streamdistance = 90.0, .drawdistance = 80.0);
    g_Pumpkins[i][PUMPKIN_TEXT3D] = CreateDynamic3DTextLabel(PUMPKIN_STATUS_FOUND ? "[ {FF9900}Kürbis {FFFFFF}]\n\n{FF2200}Dieser Kürbis wurde bereits gefunden!" :
        "[ {FF9900}Kürbis {FFFFFF}]\n\n{FFFF00}Ernte den Kürbis mit /kuerbis!", COLOR_WHITE, x, y, z - 0.67, .testlos = 1, .streamdistance = 30.0, .drawdistance = 20.0);
    
    g_Pumpkins[pumpkinID][PUMPKIN_VISIBLE] = true;
    return 1;
}

stock InitPumpkins() {
    for (new i = 0; i < sizeof(g_Pumpkins); i++) g_Pumpkins[i][PUMPKIN_TEXT3D] = STREAMER_TAG_3D_TEXT_LABEL:INVALID_3DTEXT_ID;
    return 1;
}

stock GetClosestPumpkin(playerid, Float:radius = 5.0, found = false) {
    new index = -1, Float:distance, Float:smallestDistance = 10000.0, Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    for (new i = 0; i < sizeof(g_Pumpkins); i++) {
        if (!g_Pumpkins[i][PUMPKIN_INUSE]) continue;
        if (!found && (g_Pumpkins[i][PUMPKIN_STATUS] == PUMPKIN_STATUS_FOUND || !g_Pumpkins[i][PUMPKIN_VISIBLE])) continue;
        distance = GetDistance(x, y, z, g_Pumpkins[i][PUMPKIN_X], g_Pumpkins[i][PUMPKIN_Y], g_Pumpkins[i][PUMPKIN_Z]);
        if (distance < smallestDistance && distance <= radius) {
            smallestDistance = distance;
            index = i;
        }
    }

    return index;
}

stock FindPumpkin(playerid, pumpkinID) {
    g_Pumpkins[pumpkinID][PUMPKIN_STATUS] = PUMPKIN_STATUS_FOUND;
    new message[145];
    format(message, sizeof(message), "[HALLOWEEN] {FFFFFF}%s hat einen Kürbis gefunden!", GetName(playerid));
    UpdateDynamic3DTextLabelText(g_Pumpkins[pumpkinID][PUMPKIN_TEXT3D], COLOR_WHITE, "[ {FF9900}Kürbis {FFFFFF}]\n\n{FF2200}Dieser Kürbis wurde bereits gefunden!");
    SendClientMessageToAll(COLOR_ORANGE, message);
    // Kürbispunkte oder so vergeben
    return 1;
}

// Commands

CMD:placepumpkin(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pAdmin] < ADMIN_RANK_MANAGER) return 0;
    new Float:x, Float:y, Float:z, pumpkinID;
    GetPlayerPos(playerid, x, y, z);
    new status = 0;
    sscanf(params, "d", status);
    pumpkinID = AddPumpkin(x, y, z, PUMPKIN_STATUS_CREATED, status ? true : false);
    if (pumpkinID == -1) return SCMFormatted(playerid, COLOR_RED, "[INFO] {FFFFFF}Es wurden bereits %d Kürbisse erstellt.", MAX_PUMPKINS);
    return SCMFormatted(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Es wurde ein Kürbis (ID: %d) erstellt.", pumpkinID);
}

CMD:delpumpkin(playerid) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pAdmin] < ADMIN_RANK_MANAGER) return 0;
    new pumpkinID;
    pumpkinID = GetClosestPumpkin(playerid, 20.0, true);
    if (pumpkinID == -1) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Es ist kein Kürbis in deiner Nähe.");
    if (DeletePumpkin(pumpkinID)) return SCMFormatted(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Kürbis mit der ID %d wurde gelöscht.", pumpkinID);
    return SCMFormatted(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Die Kürbis ID %d gibt es nicht.", pumpkinID);
}

CMD:kuerbis(playerid) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    // Schon 2-3 Kürbisse gefunden? Per setable var
    new pumpkinID;
    pumpkinID = GetClosestPumpkin(playerid, 5.0, false);
    if (pumpkinID == -1) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist nicht in der Nähe eines Kürbisses, der noch nicht gefunden wurde.");
    FindPumpkin(playerid, pumpkinID);
    return 1;
}
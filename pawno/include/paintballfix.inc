#include <YSI\y_hooks>

// Defines

enum {
    LEAVE_REASON_COMMAND,
    LEAVE_REASON_DISCONNECT,
    LEAVE_REASON_PARTNER_COMMAND,
    LEAVE_REASON_PARTNER_DISCONNECT
}

enum {
    PAINTBALL_STATUS_NONE,
    PAINTBALL_STATUS_MENU,
    PAINTBALL_STATUS_1V1,
    PAINTBALL_STATUS_NORMAL,
    PAINTBALL_STATUS_INVITE,
    PAINTBALL_STATUS_INVITED
}

enum E_PB_INFO {
    E_PB_INFO_STATUS,
    E_PB_INFO_SETTINGS[7],
    E_PB_INFO_KILLS,
    E_PB_INFO_DEATHS,
    E_PB_INFO_PARTNER,
    bool:E_PB_INFO_SESSION_OWNER,
    PlayerText:E_PB_INFO_TEXTDRAW
}

enum {
    DIALOG_PAINTBALL_MODE = 2000,
    DIALOG_PAINTBALL_1V1MENU,
    DIALOG_PAINTBALL_SEND1V1INV,
    DIALOG_PAINTBALL_WAIT1V1,
    DIALOG_PAINTBALL_ACCEPT1V1INV
}

new paintballInfo[MAX_PLAYERS][E_PB_INFO];

#define ClosePlayerDialog(%0); \
    ShowPlayerDialog(%0, -1, 0, NULL, NULL, NULL, NULL);

stock _ShowPlayerDialog(playerid, dialogid, style, caption[], info[], button1[], button2[]) {
    if (dialogid != DIALOG_PAINTBALL_ACCEPT1V1INV && dialogid != DIALOG_PAINTBALL_SEND1V1INV && dialogid != DIALOG_PAINTBALL_WAIT1V1) {
        if (paintballInfo[playerid][E_PB_INFO_STATUS] == PAINTBALL_STATUS_MENU) {
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
            ClosePlayerDialog(playerid);
        }
        else if (paintballInfo[playerid][E_PB_INFO_STATUS] == PAINTBALL_STATUS_INVITED) {
            new pID = paintballInfo[playerid][E_PB_INFO_PARTNER];
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
            paintballInfo[pID] = temp;

            ClosePlayerDialog(pID);
            SCMFormatted(playerid, COLOR_RED, "[Paintball] {FFFFFF}Du hast die Anfrage zu einem 1v1-Match von %s abgelehnt.", GetName(pID));
            SCMFormatted(pID, COLOR_RED, "[Paintball] {FFFFFF}%s hat deine Anfrage zu einem 1v1-Match abgelehnt.", GetName(playerid));
        }
        else if (paintballInfo[playerid][E_PB_INFO_STATUS] == PAINTBALL_STATUS_INVITE) {
            new pID = paintballInfo[playerid][E_PB_INFO_PARTNER];
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
            paintballInfo[pID] = temp;

            ClosePlayerDialog(pID);
            SCMFormatted(playerid, COLOR_RED, "[Paintball] {FFFFFF}Du hast die Anfrage zu einem 1v1-Match mit %s zurückgezogen.", GetName(pID));
            SCMFormatted(pID, COLOR_RED, "[Paintball] {FFFFFF}%s hat die Anfrage zu einem 1v1-Match zurückgezogen.", GetName(playerid));
        }
    }

    ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2);
    return 1;
}

#if defined _ALS_ShowPlayerDialog
    #undef ShowPlayerDialog
#else
    #define _ALS_ShowPlayerDialog
#endif
#define ShowPlayerDialog _ShowPlayerDialog

// Custom functions

stock Show1v1MenuDialog(playerid) {
    new dialogText[400];
    format(dialogText, sizeof(dialogText), "%sDesert Eagle (150 Schuss) - %s\n", dialogText, paintballInfo[playerid][E_PB_INFO_SETTINGS][0] ? "{00FF00}Ja" : "{FF0000}Nein");
    format(dialogText, sizeof(dialogText), "%sSchutzweste (100 Prozent) - %s\n", dialogText, paintballInfo[playerid][E_PB_INFO_SETTINGS][1] ? "{00FF00}Ja" : "{FF0000}Nein");
    format(dialogText, sizeof(dialogText), "%sMP5 (150 Schuss) - %s\n", dialogText, paintballInfo[playerid][E_PB_INFO_SETTINGS][2] ? "{00FF00}Ja" : "{FF0000}Nein");
    format(dialogText, sizeof(dialogText), "%sM4 (200 Schuss) - %s\n", dialogText, paintballInfo[playerid][E_PB_INFO_SETTINGS][3] ? "{00FF00}Ja" : "{FF0000}Nein");
    format(dialogText, sizeof(dialogText), "%sSniper Rifle (50 Schuss) - %s\n", dialogText, paintballInfo[playerid][E_PB_INFO_SETTINGS][4] ? "{00FF00}Ja" : "{FF0000}Nein");
    format(dialogText, sizeof(dialogText), "%sShotgun (100 Schuss) - %s\n", dialogText, paintballInfo[playerid][E_PB_INFO_SETTINGS][5] ? "{00FF00}Ja" : "{FF0000}Nein");
    format(dialogText, sizeof(dialogText), "%sRifle (100 Schuss) - %s\n", dialogText, paintballInfo[playerid][E_PB_INFO_SETTINGS][6] ? "{00FF00}Ja" : "{FF0000}Nein");
    format(dialogText, sizeof(dialogText), "%sEinen Spieler einladen", dialogText);
    ShowPlayerDialog(playerid, DIALOG_PAINTBALL_1V1MENU, DIALOG_STYLE_LIST, "{47A1AE}Paintball - 1v1 - Einstellungen", dialogText, "Ändern", "Abbrechen");
    return -1;
}

stock GivePlayerPaintballWeapons(playerid) {
    ResetPlayerWeapons(playerid);
    if (paintballInfo[playerid][E_PB_INFO_SETTINGS][1]) SetPlayerArmour(playerid, 100.0);
    if (paintballInfo[playerid][E_PB_INFO_SETTINGS][2]) GivePlayerWeapon(playerid, WEAPON_MP5, 150);
    if (paintballInfo[playerid][E_PB_INFO_SETTINGS][3]) GivePlayerWeapon(playerid, WEAPON_M4, 200);
    if (paintballInfo[playerid][E_PB_INFO_SETTINGS][0]) GivePlayerWeapon(playerid, WEAPON_DEAGLE, 150);
    if (paintballInfo[playerid][E_PB_INFO_SETTINGS][4]) GivePlayerWeapon(playerid, WEAPON_SNIPER, 50);
    if (paintballInfo[playerid][E_PB_INFO_SETTINGS][5]) GivePlayerWeapon(playerid, WEAPON_SHOTGUN, 100);
    if (paintballInfo[playerid][E_PB_INFO_SETTINGS][6]) GivePlayerWeapon(playerid, WEAPON_RIFLE, 100);
    SetPlayerHealth(playerid, 100.0);

    return 1;
}

stock SetPlayerPaintballPos(playerid) {
    if (paintballInfo[playerid][E_PB_INFO_SESSION_OWNER]) {
        SetPlayerPosEx(playerid, PAINTBALLGYMLS_INTERIOR_SPAWN_POINT1, MAPS_PAINTBALLGYMLS_INTERIOR, VW_PAINTBALLGYMLS + playerid);
        SetPlayerFacingAngle(playerid, PAINTBALLGYMLS_INTERIOR_SPAWN_POINT_FACING1);
    }
    else {
        SetPlayerPosEx(playerid, PAINTBALLGYMLS_INTERIOR_SPAWN_POINT2, MAPS_PAINTBALLGYMLS_INTERIOR, VW_PAINTBALLGYMLS + paintballInfo[playerid][E_PB_INFO_PARTNER]);
        SetPlayerFacingAngle(playerid, PAINTBALLGYMLS_INTERIOR_SPAWN_POINT_FACING2);
    }

    GivePlayerPaintballWeapons(playerid);
    SetCameraBehindPlayer(playerid);
    return 1;
}

stock LeavePaintball(playerid, reason) {
    new pID = paintballInfo[playerid][E_PB_INFO_PARTNER];
    switch (reason) {
        case LEAVE_REASON_COMMAND: {
                SCMFormatted(playerid, COLOR_ORANGE, "[Paintball] {FFFFFF}Du hast das 1v1-Match mit %s verlassen.", GetName(pID));
                SCMFormatted(playerid, COLOR_ORANGE, "[Paintball] {FFFFFF}Endstand: %s (%i) : %s (%i)", GetName(playerid), paintballInfo[playerid][E_PB_INFO_KILLS], GetName(pID), \
                    paintballInfo[playerid][E_PB_INFO_DEATHS]);
        }
        case LEAVE_REASON_DISCONNECT: {}
        case LEAVE_REASON_PARTNER_COMMAND: {
            SCMFormatted(playerid, COLOR_ORANGE, "[Paintball] {FFFFFF}%s hat das 1v1-Match verlassen.", GetName(pID));
            SCMFormatted(playerid, COLOR_ORANGE, "[Paintball] {FFFFFF}Endstand: %s (%i) : %s (%i)", GetName(playerid), paintballInfo[playerid][E_PB_INFO_KILLS], GetName(pID), \
                paintballInfo[playerid][E_PB_INFO_DEATHS]);
        }
        case LEAVE_REASON_PARTNER_DISCONNECT: {
            SCMFormatted(playerid, COLOR_ORANGE, "[Paintball] {FFFFFF}%s hat das 1v1-Match verlassen (Logout/Timeout).", GetName(pID));
            SCMFormatted(playerid, COLOR_ORANGE, "[Paintball] {FFFFFF}Endstand: %s (%i) : %s (%i)", GetName(playerid), paintballInfo[playerid][E_PB_INFO_KILLS], GetName(pID), \
                paintballInfo[playerid][E_PB_INFO_DEATHS]);
        }
    }

    PlayerTextDrawDestroy(playerid, paintballInfo[playerid][E_PB_INFO_TEXTDRAW]);
    for (new i = 0; i < 5; i++) SendDeathMessageToPlayer(playerid, 1001, 1001, 200);
    ResetPlayerWeapons(playerid);
    ReStore_PlayerWeapons(playerid);

    if (reason > 1) SetPlayerPosEx(playerid, PAINTBALLLOBBYINTERIOR_SPAWN_POINT2, MAPS_PAINTBALLLOBBYINTERIOR_INTERIOR, VW_PAINTBALLLOBBY);
    else SetPlayerPosEx(playerid, PAINTBALLLOBBYINTERIOR_SPAWN_POINT1, MAPS_PAINTBALLLOBBYINTERIOR_INTERIOR, VW_PAINTBALLLOBBY);
    SetPlayerFacingAngle(playerid, PAINTBALLLOBBYINTERIOR_SPAWN_FACING);
    SetCameraBehindPlayer(playerid);

    new temp[E_PB_INFO];
    paintballInfo[playerid] = temp;

    return 1;
}

// Function hooks

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    if (dialogid == DIALOG_PAINTBALL_MODE) {
        if (!response) {
            paintballInfo[playerid][E_PB_INFO_STATUS] = PAINTBALL_STATUS_NONE;
            return 1;
        }

        if (listitem == 0) {
            SetPlayerInterior(playerid, MAPS_PAINTBALLBASEMENT_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_PAINTBALLBASEMENT);
            SetPlayerPos(playerid, PAINTBALLBASEMENT_SPAWN_POINT);
            PlayerIsPaintballing[playerid] = 1;
            Store_PlayerWeapons(playerid);
            ResetPlayerWeapons(playerid);
            SetPlayerHealth(playerid, 100.0);
            SetPlayerArmour(playerid, 0.0);
            GivePlayerWeapon(playerid, WEAPON_MP5, 150);
            GivePlayerWeapon(playerid, 24, 150);
            new message[145];
            format(message, sizeof(message), "%s hat die Paintball-Halle betreten.", GetName(playerid));
            paintballInfo[playerid][E_PB_INFO_STATUS] = PAINTBALL_STATUS_NORMAL;
            SendPaintballMessage(COLOR_GREEN, message);
            SendClientMessage(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Benutze den Ausgang oder /Leave um die Paintball-Halle wieder zu verlassen.");
            return 1;
        }

        if (listitem == 1) {
            paintballInfo[playerid][E_PB_INFO_SETTINGS] = {1, 0, 0, 0, 0, 0, 0};
            return Show1v1MenuDialog(playerid);
        }

        return SendClientMessage(playerid, COLOR_GREEN, "[Paintball] {FFFFFF}Es werden in Kürze weitere Paintball-Modi folgen :)");
    }
    if (dialogid == DIALOG_PAINTBALL_1V1MENU) {
        if (!response) return 1;
        if (listitem < 0 || listitem > 7) {
            SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du hast keine gültige Auswahl getroffen.");
            return Show1v1MenuDialog(playerid);
        }
        if (listitem == 7) return ShowPlayerDialog(playerid, DIALOG_PAINTBALL_SEND1V1INV, DIALOG_STYLE_INPUT, "{47A1AE}Paintball - 1v1 - Einladen", "{FFFFFF}Gebe \
            eine Spieler ID oder den Namen eines Spielers ein:", "Einladen", "Zurück");

        paintballInfo[playerid][E_PB_INFO_SETTINGS][listitem] = !paintballInfo[playerid][E_PB_INFO_SETTINGS][listitem];
        return Show1v1MenuDialog(playerid);
    }
    if (dialogid == DIALOG_PAINTBALL_SEND1V1INV) {
        if (!response) return Show1v1MenuDialog(playerid);

        new pID;
        if (sscanf(inputtext, "u", pID) || pID == INVALID_PLAYER_ID) {
            SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du hast keinen gültigen Spieler angegeben.");
            return Show1v1MenuDialog(playerid);
        }

        if (pID == playerid) {
            SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du kannst dich nicht selber einladen.");
            return Show1v1MenuDialog(playerid);
        }

        if (!IsPlayerInRangeOfPlayer(playerid, pID, 5.0)) {
            SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht in deiner Nähe.");
            return Show1v1MenuDialog(playerid);
        }

        if (Spieler[pID][pLevel] < 3) {
            SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler muss mindestens Level 3 sein.");
            return Show1v1MenuDialog(playerid);
        }

        if (HasWeaponBlock(pID)) {
            SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler hat eine Waffensperre.");
            return Show1v1MenuDialog(playerid);
        }
        
        if (paintballInfo[pID][E_PB_INFO_STATUS] == PAINTBALL_STATUS_INVITED) {
            SendClientMessage(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Der Spieler hat bereits eine 1v1 Anfrage erhalten."); 
            return Show1v1MenuDialog(playerid);
        }

        if (paintballInfo[pID][E_PB_INFO_STATUS] == PAINTBALL_STATUS_INVITE) {
            SendClientMessage(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Der Spieler hat bereits selber eine 1v1 Anfrage gestellt."); 
            return Show1v1MenuDialog(playerid);
        }
        
        new set[7];
        set[0] = paintballInfo[playerid][E_PB_INFO_SETTINGS][0];
        set[1] = paintballInfo[playerid][E_PB_INFO_SETTINGS][1];
        set[2] = paintballInfo[playerid][E_PB_INFO_SETTINGS][2];
        set[3] = paintballInfo[playerid][E_PB_INFO_SETTINGS][3];
        set[4] = paintballInfo[playerid][E_PB_INFO_SETTINGS][4];
        set[5] = paintballInfo[playerid][E_PB_INFO_SETTINGS][5];
        set[6] = paintballInfo[playerid][E_PB_INFO_SETTINGS][6];
        SCMFormatted(playerid, COLOR_LIGHTBLUE, "[Paintball] {FFFFFF}Du hast " COLOR_HEX_LIGHTBLUE "%s" COLOR_HEX_WHITE " zu einem 1v1-Match eingeladen.", GetName(pID));
        SCMFormatted(pID, COLOR_LIGHTBLUE, "[Paintball] {FFFFFF}Du hast von " COLOR_HEX_LIGHTBLUE "%s" COLOR_HEX_WHITE " eine 1v1-Match Anfrage erhalten.", GetName(playerid));

        new dialogText[500];
        format(dialogText, sizeof(dialogText), "{FFFFFF}Du wurdest von {FFFF00}%s {FFFFFF}zu einem 1v1-Match eingeladen.\n\n{FF9900}Einstellungen:\n{FFFFFF}Desert Eagle\
         - %s\n{FFFFFF}Schutzweste - %s\n{FFFFFF}MP5 - %s\n{FFFFFF}M4 - %s\n{FFFFFF}Sniper Rifle - %s\n{FFFFFF}Shotgun - %s\n{FFFFFF}Rifle - %s\n\n{FFFFFF}Wähle 'Annehmen' oder 'Ablehnen'.", GetName(playerid), set[0] ? "{00FF00}Ja" : "{FF0000}Nein", 
            set[1] ? "{00FF00}Ja" : "{FF0000}Nein", set[2] ? "{00FF00}Ja" : "{FF0000}Nein", set[3] ? "{00FF00}Ja" : "{FF0000}Nein", set[4] ? "{00FF00}Ja" : "{FF0000}Nein",
            set[5] ? "{00FF00}Ja" : "{FF0000}Nein", set[6] ? "{00FF00}Ja" : "{FF0000}Nein");

        paintballInfo[pID][E_PB_INFO_STATUS] = PAINTBALL_STATUS_INVITED;
        paintballInfo[pID][E_PB_INFO_PARTNER] = playerid;
        paintballInfo[playerid][E_PB_INFO_STATUS] = PAINTBALL_STATUS_INVITE;
        paintballInfo[playerid][E_PB_INFO_PARTNER] = pID;

        ShowPlayerDialog(pID, DIALOG_PAINTBALL_ACCEPT1V1INV, DIALOG_STYLE_MSGBOX, "{47A1AE}Paintball - 1v1 - Einladung", dialogText, "Annehmen", "Ablehnen");
        format(dialogText, sizeof(dialogText), "{FFFFFF}Du hast {FFFF00}%s {FFFFFF}zu einem 1v1-Match eingeladen.\n\n{FF9900}Einstellungen:\n{FFFFFF}Desert Eagle\
         - %s\n{FFFFFF}Schutzweste - %s\n{FFFFFF}MP5 - %s\n{FFFFFF}M4 - %s\n{FFFFFF}Sniper Rifle - %s\n{FFFFFF}Shotgun - %s\n{FFFFFF}Rifle - %s\n\n{FFFFFF}Wähle 'Abbrechen' um die Anfrage zurückzunehmen.", GetName(pID), set[0] ? "{00FF00}Ja" : "{FF0000}Nein", 
            set[1] ? "{00FF00}Ja" : "{FF0000}Nein", set[2] ? "{00FF00}Ja" : "{FF0000}Nein", set[3] ? "{00FF00}Ja" : "{FF0000}Nein", set[4] ? "{00FF00}Ja" : "{FF0000}Nein",
            set[5] ? "{00FF00}Ja" : "{FF0000}Nein", set[6] ? "{00FF00}Ja" : "{FF0000}Nein");

        ShowPlayerDialog(playerid, DIALOG_PAINTBALL_WAIT1V1, DIALOG_STYLE_MSGBOX, "{47A1AE}Paintball - 1v1 - Einladung", dialogText, "Abbrechen", "");
        return -1;
    }
    if (dialogid == DIALOG_PAINTBALL_ACCEPT1V1INV) {
        if (paintballInfo[playerid][E_PB_INFO_STATUS] == PAINTBALL_STATUS_NONE) 
            return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du hast keine Anfrage zu einem 1v1-Match erhalten.");
        
        new pID = paintballInfo[playerid][E_PB_INFO_PARTNER];
        if (!IsPlayerInRangeOfPoint(playerid, 5.0, PAINTBALLLOBBYINTERIOR_INFO_POINT) || !IsPlayerInRangeOfPoint(pID, 5.0, PAINTBALLLOBBYINTERIOR_INFO_POINT)) {
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
            paintballInfo[pID] = temp;

            ClosePlayerDialog(playerid);
            ClosePlayerDialog(pID);
            SendClientMessage(playerid, COLOR_RED, "[Paintball] {FFFFFF}Du oder dein 1v1-Partner ist nicht mehr an der Paintball-Arena.");
            SendClientMessage(pID, COLOR_RED, "[Paintball] {FFFFFF}Du oder dein 1v1-Partner ist nicht mehr an der Paintball-Arena.");
            return -1;
        }

        if (!response) {
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
            paintballInfo[pID] = temp;

            ClosePlayerDialog(playerid);
            ClosePlayerDialog(pID);
            SCMFormatted(playerid, COLOR_RED, "[Paintball] {FFFFFF}Du hast die Anfrage zu einem 1v1-Match von %s abgelehnt.", GetName(pID));
            SCMFormatted(pID, COLOR_RED, "[Paintball] {FFFFFF}%s hat deine Anfrage zu einem 1v1-Match abgelehnt.", GetName(playerid));
            return -1;
        }

        // BIZ Eintritt etc.?

        paintballInfo[playerid][E_PB_INFO_STATUS] = PAINTBALL_STATUS_1V1;
        paintballInfo[playerid][E_PB_INFO_SESSION_OWNER] = false;
        paintballInfo[playerid][E_PB_INFO_SETTINGS][0] = paintballInfo[pID][E_PB_INFO_SETTINGS][0];
        paintballInfo[playerid][E_PB_INFO_SETTINGS][1] = paintballInfo[pID][E_PB_INFO_SETTINGS][1];
        paintballInfo[playerid][E_PB_INFO_SETTINGS][2] = paintballInfo[pID][E_PB_INFO_SETTINGS][2];
        paintballInfo[playerid][E_PB_INFO_SETTINGS][3] = paintballInfo[pID][E_PB_INFO_SETTINGS][3];
        paintballInfo[playerid][E_PB_INFO_SETTINGS][4] = paintballInfo[pID][E_PB_INFO_SETTINGS][4];
        paintballInfo[playerid][E_PB_INFO_SETTINGS][5] = paintballInfo[pID][E_PB_INFO_SETTINGS][5];
        paintballInfo[playerid][E_PB_INFO_SETTINGS][6] = paintballInfo[pID][E_PB_INFO_SETTINGS][6];

        paintballInfo[pID][E_PB_INFO_STATUS] = PAINTBALL_STATUS_1V1;
        paintballInfo[pID][E_PB_INFO_SESSION_OWNER] = true;

        ClosePlayerDialog(playerid);
        ClosePlayerDialog(pID);

        Store_PlayerWeapons(playerid);
        Store_PlayerWeapons(pID);

        SetPlayerPaintballPos(pID);
        SetPlayerPaintballPos(playerid);

        new tdString[128];
        format(tdString, sizeof(tdString), "~g~~h~%s ~w~~h~0 : 0 ~r~~h~%s", GetName(playerid), GetName(pID));
        paintballInfo[playerid][E_PB_INFO_TEXTDRAW] = CreatePlayerTextDraw(playerid, 608.0, 204.0, tdString);
        format(tdString, sizeof(tdString), "~g~~h~%s ~w~~h~0 : 0 ~r~~h~%s", GetName(pID), GetName(playerid));
        paintballInfo[pID][E_PB_INFO_TEXTDRAW] = CreatePlayerTextDraw(pID, 608.0, 204.0, tdString);

        PlayerTextDrawAlignment(playerid, paintballInfo[playerid][E_PB_INFO_TEXTDRAW], 3);
        PlayerTextDrawAlignment(pID, paintballInfo[pID][E_PB_INFO_TEXTDRAW], 3);

        PlayerTextDrawLetterSize(playerid, paintballInfo[playerid][E_PB_INFO_TEXTDRAW], 0.290, 1.720);
        PlayerTextDrawLetterSize(pID, paintballInfo[pID][E_PB_INFO_TEXTDRAW], 0.290, 1.720);

        PlayerTextDrawSetShadow(playerid, paintballInfo[playerid][E_PB_INFO_TEXTDRAW], 1);
        PlayerTextDrawSetShadow(pID, paintballInfo[pID][E_PB_INFO_TEXTDRAW], 1);

        PlayerTextDrawSetProportional(playerid, paintballInfo[playerid][E_PB_INFO_TEXTDRAW], 1);
        PlayerTextDrawSetProportional(pID, paintballInfo[pID][E_PB_INFO_TEXTDRAW], 1);

        PlayerTextDrawFont(playerid, paintballInfo[playerid][E_PB_INFO_TEXTDRAW], 1);
        PlayerTextDrawFont(pID, paintballInfo[pID][E_PB_INFO_TEXTDRAW], 1);

        PlayerTextDrawShow(playerid, paintballInfo[playerid][E_PB_INFO_TEXTDRAW]);
        PlayerTextDrawShow(pID, paintballInfo[pID][E_PB_INFO_TEXTDRAW]);

        SCMFormatted(playerid, COLOR_ORANGE, "[Paintball] {FFFFFF}Das 1v1-Match gegen {FFFF00}%s {FFFFFF}beginnt!", GetName(pID));
        SendClientMessage(playerid, COLOR_ORANGE, "[Paintball] {FFFFFF}Du kannst das Match jederzeit mit '/Leave' verlassen.");

        SCMFormatted(pID, COLOR_ORANGE, "[Paintball] {FFFFFF}Das 1v1-Match gegen {FFFF00}%s {FFFFFF}beginnt!", GetName(playerid));
        SendClientMessage(pID, COLOR_ORANGE, "[Paintball] {FFFFFF}Du kannst das Match jederzeit mit '/Leave' verlassen.");

        return -1;
    }
    if (dialogid == DIALOG_PAINTBALL_WAIT1V1) {
        new pID = paintballInfo[playerid][E_PB_INFO_PARTNER];
        new temp[E_PB_INFO];
        paintballInfo[playerid] = temp;
        paintballInfo[pID] = temp;

        ClosePlayerDialog(playerid);
        ClosePlayerDialog(pID);
        SCMFormatted(playerid, COLOR_RED, "[Paintball] {FFFFFF}Du hast die Anfrage zu einem 1v1-Match mit %s zurückgezogen.", GetName(pID));
        SCMFormatted(pID, COLOR_RED, "[Paintball] {FFFFFF}%s hat die Anfrage zu einem 1v1-Match zurückgezogen.", GetName(playerid));
        return -1;
    }

    return 1;
}

hook OnPlayerSpawn(playerid) {
    new pID = paintballInfo[playerid][E_PB_INFO_PARTNER];
    switch (paintballInfo[playerid][E_PB_INFO_STATUS]) {
        case PAINTBALL_STATUS_NONE: return 1;
        case PAINTBALL_STATUS_MENU: {
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
            ClosePlayerDialog(playerid);
        }
        case PAINTBALL_STATUS_1V1: {
            SetPlayerPaintballPos(playerid);
            SetPlayerSkin(playerid, Spieler[playerid][pSkin]);
            SetPlayerHealth(playerid, 10000.0);
            Spieler[playerid][pAntiSpawnKillOn] = true;
            SetTimerEx("ASKTimer", 2000, 0, "i", playerid);
            return -1;
        }
        case PAINTBALL_STATUS_INVITE: {
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
            paintballInfo[pID] = temp;
            ShowPlayerDialog(playerid, -1, 0, " ", " ", " ", " ");
            ShowPlayerDialog(pID, -1, 0, " ", " ", " ", " ");
            SCMFormatted(pID, COLOR_RED, "[Paintball] {FFFFFF}%s hat die Anfrage zu einem 1v1-Match zurückgezogen.", GetName(playerid));
        }
        case PAINTBALL_STATUS_INVITED: {
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
            paintballInfo[pID] = temp;
            ClosePlayerDialog(playerid);
            ClosePlayerDialog(pID);
            SCMFormatted(pID, COLOR_RED, "[Paintball] {FFFFFF}%s hat die Anfrage zu einem 1v1-Match abgelehnt.", GetName(playerid));
        }
    }

    return 1;
}

hook OnPlayerDisconnect(playerid, reason) {
    switch (paintballInfo[playerid][E_PB_INFO_STATUS]) {
        case PAINTBALL_STATUS_NONE: {}
        case PAINTBALL_STATUS_MENU: {
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
        }
        case PAINTBALL_STATUS_1V1: {
            LeavePaintball(paintballInfo[playerid][E_PB_INFO_PARTNER], LEAVE_REASON_PARTNER_DISCONNECT);
            LeavePaintball(playerid, LEAVE_REASON_DISCONNECT);
        }
        case PAINTBALL_STATUS_INVITE: {
            new pID = paintballInfo[playerid][E_PB_INFO_PARTNER];
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
            paintballInfo[pID] = temp;
            ClosePlayerDialog(pID);
            SCMFormatted(pID, COLOR_RED, "[Paintball] {FFFFFF}%s hat die Anfrage zu einem 1v1-Match zurückgezogen.", GetName(playerid));
        }
        case PAINTBALL_STATUS_INVITED: {
            new pID = paintballInfo[playerid][E_PB_INFO_PARTNER];
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
            paintballInfo[pID] = temp;
            ClosePlayerDialog(playerid);
            SCMFormatted(playerid, COLOR_RED, "[Paintball] {FFFFFF}%s hat die Anfrage zu einem 1v1-Match abgelehnt.", GetName(playerid));
        }
    }
    
    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason) {
    new pID = paintballInfo[playerid][E_PB_INFO_PARTNER];
    switch (paintballInfo[playerid][E_PB_INFO_STATUS]) {
        case PAINTBALL_STATUS_NONE: return 1;
        case PAINTBALL_STATUS_MENU: {
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
            ClosePlayerDialog(playerid);
        }
        case PAINTBALL_STATUS_1V1: {
            if (killerid == INVALID_PLAYER_ID) return -1;

            paintballInfo[playerid][E_PB_INFO_DEATHS]++;
            paintballInfo[pID][E_PB_INFO_KILLS]++;
            SpawnPlayer(playerid);
            GivePlayerPaintballWeapons(pID);
            SendDeathMessageToPlayer(pID, pID, playerid, reason);
            SendDeathMessageToPlayer(playerid, pID, playerid, reason);

            new tdString[128];
            format(tdString, sizeof(tdString), "~g~~h~%s ~w~~h~%i : %i ~r~~h~%s", GetName(pID), paintballInfo[pID][E_PB_INFO_KILLS], 
                paintballInfo[pID][E_PB_INFO_DEATHS], GetName(playerid));
            PlayerTextDrawSetString(pID, paintballInfo[pID][E_PB_INFO_TEXTDRAW], tdString);

            format(tdString, sizeof(tdString), "~g~~h~%s ~w~~h~%i : %i ~r~~h~%s", GetName(playerid), paintballInfo[playerid][E_PB_INFO_KILLS], 
                paintballInfo[playerid][E_PB_INFO_DEATHS], GetName(pID));
            PlayerTextDrawSetString(playerid, paintballInfo[playerid][E_PB_INFO_TEXTDRAW], tdString);
            return -1;
        }
        case PAINTBALL_STATUS_INVITE: {
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
            paintballInfo[pID] = temp;
            ClosePlayerDialog(playerid);
            ClosePlayerDialog(pID);
            SCMFormatted(pID, COLOR_RED, "[Paintball] {FFFFFF}%s hat die Anfrage zu einem 1v1-Match zurückgezogen.", GetName(playerid));
        }
        case PAINTBALL_STATUS_INVITED: {
            new temp[E_PB_INFO];
            paintballInfo[playerid] = temp;
            paintballInfo[pID] = temp;
            ClosePlayerDialog(playerid);
            ClosePlayerDialog(pID);
            SCMFormatted(pID, COLOR_RED, "[Paintball] {FFFFFF}%s hat die Anfrage zu einem 1v1-Match abgelehnt.", GetName(playerid));
        }
    }

    return 1;
}

// Commands

CMD:leave(playerid) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (PlayerIsPaintballing[playerid]) ExitPaintballArena(playerid);
    if (paintballInfo[playerid][E_PB_INFO_STATUS] != PAINTBALL_STATUS_1V1) return 1;
    LeavePaintball(paintballInfo[playerid][E_PB_INFO_PARTNER], LEAVE_REASON_PARTNER_COMMAND);
    LeavePaintball(playerid, LEAVE_REASON_COMMAND);
    return 1;
}

CMD:paintball(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (!IsPlayerInRangeOfPoint(playerid, 5.0, PAINTBALLLOBBYINTERIOR_INFO_POINT)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist nicht an der Paintballarena.");
    if (Spieler[playerid][pLevel] < 3) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst dafür mindestens Level 3 sein.");
    if (HasWeaponBlock(playerid)) {
        SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du hast eine Waffensperre.");
        return SendWeaponBlockInfo(playerid);
    }

    if (IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du darfst dafür nicht im Fahrzeug sitzen.");
    paintballInfo[playerid][E_PB_INFO_STATUS] = PAINTBALL_STATUS_MENU;

    new playerCount;
    for (new i = 0; i <= GetPlayerPoolSize(); i++) if (PlayerIsPaintballing[i]) playerCount++;
    new dialogText[128];
    format(dialogText, sizeof(dialogText), "Normaler Modus (%d Spieler)\n1v1 Match\n{86989A}Weitere werden folgen...", playerCount);
    ShowPlayerDialog(playerid, DIALOG_PAINTBALL_MODE, DIALOG_STYLE_LIST, "{47A1AE}Paintball - Modus", dialogText, "Weiter", "Abbrechen");
    return 1;
}
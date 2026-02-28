#include <YSI\y_hooks>

// Defines and variables

#define MAX_DROGEN_PFLANZEN 200
#define DROGENPFLANZE_REIF 70*60
#define DROGENPFLANZE_UEBERREIF 10*60
#define DROGENPFLANZEN_WASSER_COOLDOWN 30*60
#define DROGENPFLANZEN_WASSER_NOTICE 10*60

#define MAX_SAMEN 25

enum e_DrogenPflanzen {
    Float:DP_fX,
    Float:DP_fY,
    Float:DP_fZ,
    DP_iObject,
    DP_iFireObject,
    DP_iWasser,
    DP_iFortschritt,
    bool:DP_bInUse,
    bool:DP_bDestroyed,
    STREAMER_TAG_3D_TEXT_LABEL:DP_text3D
}

new const PFLANZEN_HELP[][] = {
    "/Pflanzen help{FFFFFF}\t\tDiese Liste anzeigen",
    "/Pflanzen anzahl{FFFFFF}\tDie Anzahl der angebauten Pflanzen anzeigen",
    "/Pflanzen suchen{FFFFFF}\tEine Pflanze auf der Karte anzeigen",
    //"/Pflanzen info{FFFFFF}\t\tInfo über nächstgelegene Pflanze (Reifezeit, Gießzeit)",
    "/Pflanzen anbauen{FFFFFF}\tEine Pflanze anbauen (maximal 200 Pflanzen gleichzeitig)",
    "/Pflanzen giessen{FFFFFF}\tNächstgelegene Pflanze giessen (Zeit zum Gießen: 600 Sekunden)",
    "/Pflanzen verbrennen{FFFFFF}\tNächstgelegene Pflanze wird verbrannt",
    "/Pflanzen abbauen{FFFFFF}\tNächstgelegene Pflanze wird geerntet",
    "/Nimmspice{FFFFFF}\t\tEin Gramm Spice einnehmen (10 Sekunden Cooldown)",
    "/Sellspice{FFFFFF}\t\tSpice verkaufen",
    //"{00FF33}/Geben [ID] Spice [Menge]\tEinem Spieler Spice geben",
    "/Samen{FFFFFF}\t\t\tSamenanzahl im Inventar anzeigen",
    "/Getsamen{FFFFFF}\t\tAn einem Samenpunkt Samen holen",
    "/Samenpunkte{FFFFFF}\t\tDie Samenpunkte auf der Karte anzeigen"
};

enum E_SEED_POINT {
    Float:SEED_POINT_fX,
    Float:SEED_POINT_fY,
    Float:SEED_POINT_fZ,
    SEED_POINT_LOCATION_NAME[32]
}

new const seedPoints[][E_SEED_POINT] = {
    {-85.5813, 2.2551, 3.1172, "Bauernhof in Blueberry Acres"},//Datenbank Infotab Samen1
    {760.4857, 378.9007, 23.1683, "Hütte in Red County"},//Datenbank Infotab Samen2
    {797.5535, -617.8438, 16.3358, "Garage in Dillimore"},//Datenbank Infotab Samen3
    {-1669.6538, 2598.6924, 81.4453, "Hütte in LV"},//Datenbank Infotab Samen4
    {-2533.2542, -21.5024, 25.6172, "Markt in SF"}//Datenbank Infotab Samen5
};

new g_DrogenPflanzenCount = 0;
new g_DrogenPflanzen[MAX_DROGEN_PFLANZEN][e_DrogenPflanzen];


// Function hooks

hook OnPlayerDisconnect(playerid, reason) {
    RemovePlayerFromPlantArrayData(playerid);
    return 1;
}

hook OnGameModeInit() {
    for (new i = 0; i < sizeof(seedPoints); i++) {
        CreateDynamicPickup(1279, 1, seedPoints[i][SEED_POINT_fX], seedPoints[i][SEED_POINT_fY], seedPoints[i][SEED_POINT_fZ], 0);
        CreateDynamic3DTextLabel("Spicesamen\n" COLOR_HEX_WHITE "Tippe /Getsamen", COLOR_YELLOW, seedPoints[i][SEED_POINT_fX], seedPoints[i][SEED_POINT_fY], seedPoints[i][SEED_POINT_fZ], 15.0);
    }
}

// Custom functions

stock InitDrogenPflanzen() {
    for (new i = 0; i < sizeof(g_DrogenPflanzen); i++) g_DrogenPflanzen[i][DP_text3D] = STREAMER_TAG_3D_TEXT_LABEL:INVALID_3DTEXT_ID;
    SetTimer("Pulse_DrogenPflanzen",997,true);
    return 1;
}

stock ShowPflanzenHelp(playerid) {
    new dialogText[1024];
    for (new i = 0; i < sizeof(PFLANZEN_HELP); i++) format(dialogText, sizeof(dialogText), "%s{B4C12E}%s\n", dialogText, PFLANZEN_HELP[i]);
    return ShowPlayerDialog(playerid, DIALOG_NO_RESPONSE, DIALOG_STYLE_LIST, "{FFFFFF}Pflanzen Hilfe", dialogText, "Schließen", "");
}

stock RemovePlayerFromPlantArrayData(playerid) {
    for (new i = 0; i < sizeof(g_DrogenPflanzen); i++) {
        if (g_DrogenPflanzen[i][DP_text3D] == STREAMER_TAG_3D_TEXT_LABEL:INVALID_3DTEXT_ID) continue;
        Streamer_RemoveArrayData(STREAMER_TYPE_3D_TEXT_LABEL, g_DrogenPflanzen[i][DP_text3D], E_STREAMER_PLAYER_ID, playerid);
    }
    
    return 1;
}

stock AddPlayerToPlantArrayData(playerid) {
    if (Spieler[playerid][pFraktion] != 15) return 1;
    for (new i = 0; i < sizeof(g_DrogenPflanzen); i++) {
        if (g_DrogenPflanzen[i][DP_text3D] == STREAMER_TAG_3D_TEXT_LABEL:INVALID_3DTEXT_ID) continue;
        Streamer_AppendArrayData(STREAMER_TYPE_3D_TEXT_LABEL, g_DrogenPflanzen[i][DP_text3D], E_STREAMER_PLAYER_ID, playerid);
    }
    
    return 1;
}

stock CreateDrogenPflanzen(playerid, Float:x, Float:y, Float:z) {
    new index = GetFreeDrogenPflanzenSlot();
    if (index == -1) return 0;

    g_DrogenPflanzen[index][DP_fX] = x;
    g_DrogenPflanzen[index][DP_fY] = y;
    g_DrogenPflanzen[index][DP_fZ] = z;
    g_DrogenPflanzen[index][DP_iWasser] = DROGENPFLANZEN_WASSER_COOLDOWN + 15;
    g_DrogenPflanzen[index][DP_iFortschritt] = 0;
    g_DrogenPflanzen[index][DP_bInUse] = true;
    g_DrogenPflanzen[index][DP_bDestroyed] = false;
    g_DrogenPflanzenCount++;
    g_DrogenPflanzen[index][DP_iObject] = CreateDynamicObject(808, x, y, z - 1.5, 0.0, 0.0, 0.0);
    g_DrogenPflanzen[index][DP_text3D] = CreateDynamic3DTextLabel("[ {009D00}Spicepflanze {FFFFFF}]", COLOR_WHITE, x, y, z, 20.0, .testlos = 1, .streamdistance = 30.0);
    new pArray[1];
    pArray[0] = playerid;
    Streamer_SetArrayData(STREAMER_TYPE_3D_TEXT_LABEL, g_DrogenPflanzen[index][DP_text3D], E_STREAMER_PLAYER_ID, pArray);

    for (new i = 0; i <= GetPlayerPoolSize(); i++)
        if (Spieler[i][pFraktion] == 15) Streamer_AppendArrayData(STREAMER_TYPE_3D_TEXT_LABEL, g_DrogenPflanzen[index][DP_text3D], E_STREAMER_PLAYER_ID, i);

    g_DrogenPflanzen[index][DP_iFireObject] = INVALID_OBJECT_ID;
    MoveDynamicObject(g_DrogenPflanzen[index][DP_iObject], x, y, z, 0.1);
    return 1;
}
stock GetFreeDrogenPflanzenSlot() {
    for(new i ; i < sizeof(g_DrogenPflanzen) ; i++) {
        if( g_DrogenPflanzen[i][DP_bInUse] == false ) {
            return i;
        }
    }
    return -1;
}

new BrenennTimer[MAX_DROGEN_PFLANZEN];

stock SetDrogenPflanzenOnFire(index) {
    g_DrogenPflanzen[index][DP_iFireObject] = CreateDynamicObject( 18688 , g_DrogenPflanzen[index][DP_fX] , g_DrogenPflanzen[index][DP_fY], g_DrogenPflanzen[index][DP_fZ] - 2.0, 0.0,0.0,0.0 );
    g_DrogenPflanzen[index][DP_bDestroyed] = true;
    UpdateDynamic3DTextLabelText(g_DrogenPflanzen[index][DP_text3D], COLOR_WHITE, "[ {009D00}Spicepflanze {FFFFFF}]\n{FF9900}> Die Pflanze wurde verbrannt <");
    //SetTimerEx("DestroyDrogenPflanze",10*1000,false,"d",index);
	BrenennTimer[index] = SetTimerEx("DestroyDrogenPflanze",60*5000,false,"d",index);
    return 1;
}

stock DrogenPflanzenFeuerLoeschen(index) {
	DestroyDynamicObject(g_DrogenPflanzen[index][DP_iFireObject]);
    g_DrogenPflanzen[index][DP_bDestroyed] = false;
    Pulse_DrogenPflanzen();
	KillTimer(BrenennTimer[index]);
    return 1;
}

forward DestroyDrogenPflanze(index);
public DestroyDrogenPflanze(index) {
    DestroyDynamicObject(g_DrogenPflanzen[index][DP_iObject]);
    g_DrogenPflanzen[index][DP_iObject] = INVALID_OBJECT_ID;
    DestroyDynamicObject(g_DrogenPflanzen[index][DP_iFireObject]);
    g_DrogenPflanzen[index][DP_iFireObject] = INVALID_OBJECT_ID;
    DestroyDynamic3DTextLabel(g_DrogenPflanzen[index][DP_text3D]);
    g_DrogenPflanzen[index][DP_text3D] = STREAMER_TAG_3D_TEXT_LABEL:INVALID_3DTEXT_ID;
    g_DrogenPflanzenCount--;
    g_DrogenPflanzen[index][DP_bInUse] = false;
    g_DrogenPflanzen[index][DP_bDestroyed] = false;
    return 1;
}
stock GetClosestDrogenPflanze(playerid,Float:radius = 8.0) {
    new
        index = -1,
        Float:distance,
        Float:best_distance = 100.0,
        Float:x,
        Float:y,
        Float:z;
    GetPlayerPos(playerid,x,y,z);
    for(new i ; i < sizeof(g_DrogenPflanzen) ; i++) {
        if( g_DrogenPflanzen[i][DP_bInUse] == true/* && !g_DrogenPflanzen[i][DP_bDestroyed]*/) {
            distance = GetDistance(x,y,z,g_DrogenPflanzen[i][DP_fX],g_DrogenPflanzen[i][DP_fY],g_DrogenPflanzen[i][DP_fZ]);
            if( distance < best_distance && distance <= radius ) {
                best_distance = distance;
                index = i;
            }
        }
    }
    return index;
}

forward Pulse_DrogenPflanzen();
public Pulse_DrogenPflanzen() {
    for (new i; i < sizeof(g_DrogenPflanzen); i++) {
        if (!g_DrogenPflanzen[i][DP_bInUse] || g_DrogenPflanzen[i][DP_bDestroyed]) continue;

        g_DrogenPflanzen[i][DP_iFortschritt]++;
        if (g_DrogenPflanzen[i][DP_iFortschritt] >= (DROGENPFLANZE_REIF + DROGENPFLANZE_UEBERREIF)) {
            DestroyDrogenPflanze(i);
            g_DrogenPflanzenCount--;
            SendFraktionMessage(15, COLOR_ORANGE, "Eine Spicepflanze ist eingegangen.");
        }
        else if (g_DrogenPflanzen[i][DP_iFortschritt] < DROGENPFLANZE_REIF) {
            g_DrogenPflanzen[i][DP_iWasser]--;
            if (g_DrogenPflanzen[i][DP_iWasser] <= 0) {
                DestroyDrogenPflanze(i);
                g_DrogenPflanzenCount--;
                SendFraktionMessage(15, COLOR_ORANGE, "Eine Spicepflanze ist vertrocknet.");
            }
        }

        if (!g_DrogenPflanzen[i][DP_bInUse] || g_DrogenPflanzen[i][DP_bDestroyed]) continue;

        new labelText[256] = "[ {009D00}Spicepflanze {FFFFFF}]\n";
        if (g_DrogenPflanzen[i][DP_iFortschritt] >= DROGENPFLANZE_REIF)
            format(labelText, sizeof(labelText), "%s{FFFF00}> Die Pflanze ist reif <", labelText);
        else if (g_DrogenPflanzen[i][DP_iWasser] < DROGENPFLANZEN_WASSER_NOTICE) {
            format(labelText, sizeof(labelText), "%s{FFFF00}Reif in: {FFFFFF}%i Minute(n)\n{FFFF00}Vertrocknet in: {FFFFFF}%i Minute(n)\n{FFFF00}> Jetzt gießen <", labelText, 
                floatround(float(DROGENPFLANZE_REIF - g_DrogenPflanzen[i][DP_iFortschritt]) / 60.0, floatround_ceil), 
                floatround(float(g_DrogenPflanzen[i][DP_iWasser]) / 60.0, floatround_ceil));
        }
        else
            format(labelText, sizeof(labelText), "%s{FFFF00}Reif in: {FFFFFF}%i Minute(n)\n{FFFF00}Gießen in: {FFFFFF}%i Minute(n)\n{FFFF00}Vertrocknet in: {FFFFFF}%i Minute(n)", labelText, 
                floatround(float(DROGENPFLANZE_REIF - g_DrogenPflanzen[i][DP_iFortschritt]) / 60.0, floatround_ceil), floatround(float(g_DrogenPflanzen[i][DP_iWasser] - DROGENPFLANZEN_WASSER_NOTICE) / 60, floatround_ceil), 
                floatround(float(g_DrogenPflanzen[i][DP_iWasser]) / 60.0, floatround_ceil));

        UpdateDynamic3DTextLabelText(g_DrogenPflanzen[i][DP_text3D], COLOR_WHITE, labelText);
    }

    return 1;
}

// Commands

COMMAND:pflanzeverbrennen(playerid) {
    if (!IsPlayerExecutive(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Exekutivbeamter.");
    if(bIsSpectating[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst beim Spectaten keine Pflanzen verbrennen.");
    new pflanze = GetClosestDrogenPflanze(playerid, 3.0);
    if (pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Spicepflanze in deiner Nähe.");
    SendClientMessage(playerid, COLOR_YELLOW, "Die Spicepflanze wurde verbrannt.");
    SetDrogenPflanzenOnFire(pflanze);
    return SendFraktionMessage(15, COLOR_RED, "Ein Exekutivbeamter hat eine Spicepflanze verbrannt.");
}

COMMAND:pflanzen(playerid, params[]) {
    if (Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied der Nine Demons.");
    if (isnull(params)) return ShowPflanzenHelp(playerid);

    new entry[32], value;
    if (sscanf(params, "s[32]D(-1)", entry, value)) return SendClientMessage(playerid, COLOR_BLUE, "* Benutze: {00CC00}/Pflanzen für eine Übersicht");
	
	if (!strcmp(entry, "loeschen", true)) {
        new pflanze = GetClosestDrogenPflanze(playerid, 3.0);
        if (pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Spicepflanze in deiner Nähe.");
		if(g_DrogenPflanzen[pflanze][DP_bDestroyed] != true) return SendClientMessage(playerid, COLOR_RED, "Diese Spicepflanze brennt nicht.");
        SendClientMessage(playerid, COLOR_YELLOW, "Das Feuer wurde gelöscht.");

        new message[145];
        format(message, sizeof(message), "Member %s hat eine Spicepflanze gelöscht.", GetName(playerid));
        DrogenPflanzenFeuerLoeschen(pflanze);
        return SendFraktionMessage(15, COLOR_YELLOW, message);
    }
	
    if (!strcmp(entry, "zerstoeren", true)) {
        new pflanze = GetClosestDrogenPflanze(playerid, 3.0);
        if (pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Spicepflanze in deiner Nähe.");
        SendClientMessage(playerid, COLOR_YELLOW, "Die Spicepflanze wurde zerstoert.");

        new message[145];
        format(message, sizeof(message), "Member %s hat eine Spicepflanze zerstoert.", GetName(playerid));
        DestroyDrogenPflanze(pflanze);
        return SendFraktionMessage(15, COLOR_YELLOW, message);
    }

    if (!strcmp(entry, "suchen", true)) {
        if (value == -1) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Pflanzen suchen [Index]");
        if (g_DrogenPflanzenCount == 0) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Es sind momentan keine Pflanzen angebaut.");
        if (value > MAX_DROGEN_PFLANZEN || value < 1) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Index muss zwischen 1 und 200 liegen.");
        if (!g_DrogenPflanzen[value - 1][DP_bInUse]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Die Pflanze ist nicht angebaut.");
        SetPlayerCheckpointEx(playerid, g_DrogenPflanzen[value - 1][DP_fX], g_DrogenPflanzen[value - 1][DP_fY], g_DrogenPflanzen[value - 1][DP_fZ], 1.0, CP_NAVI4);
        return SendClientMessage(playerid, COLOR_GREEN, "[INFO] {FFFFFF}Die Pflanze wurde auf der Karte Rot markiert.");
    }

    if (!strcmp(entry, "help", true)) return ShowPflanzenHelp(playerid);

    if (!strcmp(entry, "anzahl", true)) {
        if (g_DrogenPflanzenCount == 0) return SendClientMessage(playerid, COLOR_GREEN, "Es sind momentan {7FFFD4}keine {009D00}Spicepflanze angebaut.");
        if (g_DrogenPflanzenCount == 1) return SendClientMessage(playerid, COLOR_GREEN, "Es ist momentan {7FFFD4}eine von 200 {009D00}Spicepflanze angebaut.");

        new message[148];
        format(message, sizeof(message), "Es sind momentan {7FFFD4}%i von 200 {009D00}Spicepflanze angebaut.", g_DrogenPflanzenCount);
        return SendClientMessage(playerid, COLOR_GREEN, message);
    }

    if (!strcmp(entry, "anbauen", true)) {
        if (IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Fahrzeug keine Spicepflanze anbauen.");
        if (g_DrogenPflanzenCount >= 200) return SendClientMessage(playerid, COLOR_RED, "Es sind bereits 200 Spicepflanze angebaut.");
        new pflanze = GetClosestDrogenPflanze(playerid); 
        if (pflanze != -1) return SendClientMessage(playerid, COLOR_RED, "Hier ist bereits eine Spicepflanze.");
        if (Spieler[playerid][pDrogenSamen] < 1) return SendClientMessage(playerid, COLOR_RED, "Du besitzt keine Samen, um eine Spicepflanze anzubauen.");
        if (IsPlayerInDynamicArea(playerid, g_NDanbauSperre)) return SendClientMessage(playerid,COLOR_RED,"Du kannst hier keine Pflanzen anbauen.");

        new Float:x, Float:y, Float:z;
        GetPlayerPos(playerid, x, y, z);
        if (!CreateDrogenPflanzen(playerid, x, y, z)) return SendClientMessage(playerid, COLOR_RED, "Du kannst gerade keine Pflanze anbauen.");
        Spieler[playerid][pDrogenSamen]--;
        new message[145];
        if (Spieler[playerid][pDrogenSamen] == 0) message = "Eine Spicepflanze wird gezogen. Du hast {FFFFFF}keine {FFFF00}Samen mehr übrig.";
        else if (Spieler[playerid][pDrogenSamen] == 1) message = "Eine Spicepflanze wird gezogen. Du hast noch {FFFFFF}einen {FFFF00}Samen übrig.";
        else format(message, sizeof(message), "Eine Spicepflanze wird gezogen. Du hast noch {FFFFFF}%d {FFFF00}Samen übrig.", Spieler[playerid][pDrogenSamen]);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        SetTimerEx("TogglePlayerControllableEx", 1000, false, "dd", playerid, true);
        FreezePlayer(playerid);
        SetPlayerPos(playerid, x, y, z + 0.01);
        return 1;
    }
    
    // if (!strcmp(params, "info", true)) {
    //     new pflanze = GetClosestDrogenPflanze(playerid, 3.0);
    //     if (pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Spicepflanze in deiner Nähe.");
    //     if (g_DrogenPflanzen[pflanze][DP_iFortschritt] > DROGENPFLANZE_REIF) return SendClientMessage(playerid,COLOR_YELLOW,"Diese Spicepflanze ist reif.");

    //     new message[145];
    //     format(message, sizeof(message), "Die Spicepflanze ist reif in: %d Sekunden.", DROGENPFLANZE_REIF - g_DrogenPflanzen[pflanze][DP_iFortschritt]);
    //     SendClientMessage(playerid, COLOR_WHITE, message);
    //     format(message, sizeof(message), "Die Spicepflanze benötigt Wasser in: %d bis %d Sekunden.", g_DrogenPflanzen[pflanze][DP_iWasser] - DROGENPFLANZEN_WASSER_NOTICE, g_DrogenPflanzen[pflanze][DP_iWasser]);
    //     return SendClientMessage(playerid, COLOR_WHITE, message);
    // }

    if (!strcmp(entry,"giessen", true)) {
        new pflanze = GetClosestDrogenPflanze(playerid, 3.0);
        if (pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Spicepflanze in deiner Nähe.");
        if (g_DrogenPflanzen[pflanze][DP_iWasser] > DROGENPFLANZEN_WASSER_NOTICE ) return SendClientMessage(playerid, COLOR_RED, "Diese Spicepflanze benötigt noch kein Wasser.");
        g_DrogenPflanzen[pflanze][DP_iWasser] = DROGENPFLANZEN_WASSER_COOLDOWN;
        return SendClientMessage(playerid, COLOR_YELLOW, "Du hast die Spicepflanze bewässert.");
    }

    if (!strcmp(entry,"abbauen", true)) {
        if (IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Fahrzeug keine Spicepflanze abbauen.");
        new pflanze = GetClosestDrogenPflanze(playerid, 3.0);
        if (pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Spicepflanze in deiner Nähe.");
        if (g_DrogenPflanzen[pflanze][DP_iFortschritt] < DROGENPFLANZE_REIF) return SendClientMessage(playerid, COLOR_RED, "Die Spicepflanze ist noch nicht reif.");
        new randomAmount = RandomEx(10, 15), message[145];
        if(g_DrogenPflanzen[pflanze][DP_bDestroyed] == true) return SendClientMessage(playerid, COLOR_RED, "Die Pflanze wurde bereits geerntet!");
        g_DrogenPflanzen[pflanze][DP_bDestroyed] = true;
        UpdateDynamic3DTextLabelText(g_DrogenPflanzen[pflanze][DP_text3D], COLOR_WHITE, "[ {009D00}Spicepflanze {FFFFFF}]\n{FFFF00}> Die Pflanze wurde geerntet <");
        SetTimerEx("DestroyDrogenPflanze", 2 * 1000, false, "d", pflanze);
        g_DrogenPflanzenCount--;
        MoveDynamicObject(g_DrogenPflanzen[pflanze][DP_iObject], g_DrogenPflanzen[pflanze][DP_fX], g_DrogenPflanzen[pflanze][DP_fY], g_DrogenPflanzen[pflanze][DP_fZ] - 2.0, 0.05);
        FreezePlayer(playerid);
        SetTimerEx("TogglePlayerControllableEx", 2 * 1000, false, "dd", playerid, true);
        g_fraktion[15][Fr_FSSpice] += randomAmount;
        //Spieler[playerid][pKrauterMische] += randomAmount;
		Spieler[playerid][pSpiceSamenPoints]++;
        format(message, sizeof(message), "%s hat %d Gramm Spice abgebaut. Spice in der FSafebox: %i", GetName(playerid), randomAmount, g_fraktion[15][Fr_FSSpice]);
        SendClientMessage(playerid, COLOR_YELLOW, "Die Spicepflanze wird von dir geerntet.");
        return SendFraktionMessage(15, COLOR_LIME, message);
    }

    return SendClientMessage(playerid, COLOR_BLUE, "* Benutze: {00CC00}/Pflanzen für eine Übersicht");
}

COMMAND:usespice(playerid,params[]) {
    return cmd_nimmspice(playerid,params);
}

COMMAND:nimmspice(playerid,params[]) {
    if (Spieler[playerid][pSpice] < 3) return SendClientMessage(playerid, COLOR_RED, "Du benötigst mindestens 3g Spice.");
    if ( gettime() < Spieler[playerid][unixSpiceCooldown] ) {
        SendClientMessage(playerid,COLOR_RED,"Du musst noch einen Moment warten, bis du wieder Spice nehmen kannst.");
        return 1;
    }
    if (IsEnemyInZone(playerid)) return 1;

    new
        Float:armor;
    GetPlayerArmour(playerid,armor);
    if ( armor >= 100.0 ) {
        SendClientMessage(playerid,COLOR_RED,"Du kannst kein Spice nehmen, da deine AP bereits voll sind.");
        return 1;
    }
    if (damagesperre[playerid]>0)
    {
        SendClientMessage(playerid,COLOR_RED,"Du kannst noch kein Spice nehmen, da du gerade Schaden genommen hast.");
        return 1;
    }
    armor += 30.0;
    if( armor > 100.0 ) armor = 100.0;
    SetPlayerArmour(playerid,armor);
    Spieler[playerid][unixSpiceCooldown] = gettime() + 10;

    pDrogenEinfluss[playerid] = 1;
    Spieler[playerid][pSpice] -= 3;
    KillTimer(DrogenTimer[playerid]);
    SetPlayerDrunkLevel(playerid, 2500);
    ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
    // DrogenTimer[playerid] = SetTimerEx("Drogen_Clear", 30000, 0, "i", playerid);

    new Float:x, Float:y, Float:z;
    new string[128];
    GetPlayerPos(playerid, x,y,z);
    if(Spieler[playerid][bMaske]){
        format(string, sizeof(string), "* Ein Maskierter nimmt Spice zu sich.");
    }else{
        format(string, sizeof(string), "* %s nimmt Spice zu sich.", GetName(playerid));
    }
    SendRoundMessage(x,y,z, COLOR_PURPLE, string);

    return 1;
}
CMD:usedrugs(playerid) {
    return cmd_nimmdrogen(playerid);
}

CMD:nimmdrogen(playerid)
{
    new string[128];
    if(Spieler[playerid][pDrugs] < 5) return SendClientMessage(playerid, COLOR_RED, "Du benötigst mindestens 5g Drogen.");

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    new Float:health;
    GetPlayerHealth(playerid, health);
    if (IsEnemyInZone(playerid)) return 1;

    if(damagesperre[playerid]>0)
    {
        SendClientMessage(playerid,COLOR_RED,"Da du Schaden genommen hast, kannst du erst nach 5 Sekunden deine HP wieder pushen.");
    }
    else if(health < 100.0 && health > 1.0)
    {
        if(Spieler[playerid][bMaske])
        {
	        pDrogenEinfluss[playerid] = 1;
	        health = health >= 85.0 ? 100.0 : health + 15.0;
	        SetPlayerHealth(playerid, health);
	        KillTimer(DrogenTimer[playerid]);
	        DrogenTimer[playerid] = SetTimerEx("Drogen_Clear", 30000, 0, "i", playerid);
	        Spieler[playerid][pDrugs] -= 5;
	        format(string, sizeof(string), "* Maskierter hat sich nen Joint gedreht.");
	        SendRoundMessage(x,y,z, COLOR_PURPLE, string);
	        SetPlayerDrunkLevel(playerid, 2500);
	  		ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
        }
        else
        {
	        pDrogenEinfluss[playerid] = 1;
	        health = health >= 85.0 ? 100.0 : health + 15.0;
	        SetPlayerHealth(playerid, health);
	        KillTimer(DrogenTimer[playerid]);
	        DrogenTimer[playerid] = SetTimerEx("Drogen_Clear", 30000, 0, "i", playerid);
	        Spieler[playerid][pDrugs] -= 5;
	        format(string, sizeof(string), "* %s hat sich nen Joint gedreht.", GetName(playerid));
	        SendRoundMessage(x,y,z, COLOR_PURPLE, string);
	        SetPlayerDrunkLevel(playerid, 2500);
	  		ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.0, 0, 0, 0, 0, 0);//Essen
		}
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Joint rauchen. (Leben zu hoch oder zu niedrig)");
        return 1;
    }
    return 1;
}
/*COMMAND:sellkrauter(playerid,params[]) {
    new pID, menge, Float:x, Float:y, Float:z;
    if(sscanf(params, "ui", pID, menge))return SendClientMessage(playerid, COLOR_BLUE, "* Benutze: {00CC00}/Sellkrauter [SpielerID/Name] [Menge]");
    if(Spieler[playerid][pFraktion] != 15)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Member der Nine Demons.");
    GetPlayerPos(pID, x,y,z);
    if(playerid==pID)return SendClientMessage(playerid, COLOR_RED, "Du kannst Kräuter nicht an dich selbst verkaufen.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pFraktion] != 19) return SendClientMessage(playerid, COLOR_RED, "Kräuter können nur an Terroristen verkauft werden!");
    if(!IsPlayerInRangeOfPoint(playerid, 5.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
    if(menge > Spieler[playerid][pKrauterMische]) return SendClientMessage(playerid, COLOR_RED, "Soviel Kräuter hast du nicht.");
    //if(menge < 1 || menge > 10000)return SendClientMessage(playerid, COLOR_RED, "Der Wert sollte zwischen 1 und 10.000 liegen.");
    SetPVarString(playerid,"SellSpice",params);

    ShowPlayerDialog(playerid,DIALOG_SELLSPICE,DIALOG_STYLE_MSGBOX,"Kräuter Verkauf Information","\
    Der aktuelle Preis je Gramm Kräuter $1.000!","Einverstanden","Ablehnen");

    return 1;
}*/

COMMAND:sellspice(playerid,params[]) {
    new pID, menge, preis, Float:x, Float:y, Float:z;
    if(sscanf(params, "uii", pID, menge, preis))return SendClientMessage(playerid, COLOR_BLUE, "* Benutze: {00CC00}/Sellspice [SpielerID/Name] [Menge] [Preis]");
    if(Spieler[playerid][pFraktion] != 15)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Member der Nine Demons.");
    //if(CheckPlayerSpice(pID,menge)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler kann maximal 3.000 Gramm Spice besitzen!");
    GetPlayerPos(pID, x,y,z);
    if(playerid==pID)return SendClientMessage(playerid, COLOR_RED, "Du kannst Spice nicht an dich selbst verkaufen.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(!IsPlayerInRangeOfPoint(playerid, 5.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
    if(menge > Spieler[playerid][pSpice]) return SendClientMessage(playerid, COLOR_RED, "Soviel Spice hast du nicht.");
    #if !defined NEUE_WIRTSCHAFT
        if(menge < 1 || menge > 10000)return SendClientMessage(playerid, COLOR_RED, "Der Wert sollte zwischen 1 und 10.000 liegen.");
    #endif
    SetPVarString(playerid,"SellSpice",params);
    if(preis >= 1 && preis < 100000000)
    {
        #if defined NEUE_WIRTSCHAFT
            ShowPlayerDialog(playerid,DIALOG_SELLSPICE,DIALOG_STYLE_MSGBOX,"Spice Verkauf Information","\
            Jeder Drogenhandel wird gespeichert!","Einverstanden","Ablehnen");
        #else
            ShowPlayerDialog(playerid,DIALOG_SELLSPICE,DIALOG_STYLE_MSGBOX,"Spice Verkauf Information","\
            Der aktuelle Preis je Gramm Spice ist im Rahmen von 1.000$ bis 1.500$!\n\
            Höhere Beträge werden laut Server Regel §6 als Geldwäsche gewertet und Administrativ bestraft!\n\
            Die Strafe könnte sein: Perm-/Timeban, Admin-Verwarnung, Prison oder Drogen/Geld wird eingezogen!\n\
            Jeder Drogenhandel wird gespeichert!","Einverstanden","Ablehnen");
        #endif
    }
    else
        SendClientMessage(playerid, COLOR_GREY, "Der Preis sollte zwischen $1 und $100.000.000 liegen.");
    
    return 1;
}

COMMAND:getsamen(playerid, params[]) {
    if (Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Du kannst mit Samen nichts anfangen.");
    new bool:bAtPoint = false;
    for (new i = 0; i < sizeof(seedPoints); i++) {
        if (IsPlayerInRangeOfPoint(playerid, 3.0, seedPoints[i][SEED_POINT_fX], seedPoints[i][SEED_POINT_fY], seedPoints[i][SEED_POINT_fZ])) {
            bAtPoint = true;
			if(i == 0 && Samen1Bestand < GetPlayerSamenSkillLevelValue(playerid)) return SendClientMessage(playerid, COLOR_RED, "Hier sind zu wenig Samen!");
			if(i == 1 && Samen2Bestand < GetPlayerSamenSkillLevelValue(playerid)) return SendClientMessage(playerid, COLOR_RED, "Hier sind zu wenig Samen!");
			if(i == 2 && Samen3Bestand < GetPlayerSamenSkillLevelValue(playerid)) return SendClientMessage(playerid, COLOR_RED, "Hier sind zu wenig Samen!");
			if(i == 3 && Samen4Bestand < GetPlayerSamenSkillLevelValue(playerid)) return SendClientMessage(playerid, COLOR_RED, "Hier sind zu wenig Samen!");
			if(i == 4 && Samen5Bestand < GetPlayerSamenSkillLevelValue(playerid)) return SendClientMessage(playerid, COLOR_RED, "Hier sind zu wenig Samen!");
			
			if(i == 0) { Samen1Bestand -= GetPlayerSamenSkillLevelValue(playerid) - Spieler[playerid][pDrogenSamen]; }
			if(i == 1) { Samen2Bestand -= GetPlayerSamenSkillLevelValue(playerid) - Spieler[playerid][pDrogenSamen]; }
			if(i == 2) { Samen3Bestand -= GetPlayerSamenSkillLevelValue(playerid) - Spieler[playerid][pDrogenSamen]; }
			if(i == 3) { Samen4Bestand -= GetPlayerSamenSkillLevelValue(playerid) - Spieler[playerid][pDrogenSamen]; }
			if(i == 4) { Samen5Bestand -= GetPlayerSamenSkillLevelValue(playerid) - Spieler[playerid][pDrogenSamen]; }
			
            break;
        }
    }

    if (!bAtPoint) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist an keinem Samenpunkt (/samenpunkte).");
    if (Spieler[playerid][pDrogenSamen] >= MAX_SAMEN) return SCMFormatted(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Du hast bereits %d Samen bei dir.", MAX_SAMEN);
	
	if (Spieler[playerid][pDrogenSamen] >= GetPlayerSamenSkillLevelValue(playerid)) return SCMFormatted(playerid, COLOR_ORANGE, "[INFO] {FFFFFF}Du hast bereits %d Samen bei dir.", GetPlayerSamenSkillLevelValue(playerid));
	
	SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast nun %d Samen (+ %d Stück).", GetPlayerSamenSkillLevelValue(playerid), GetPlayerSamenSkillLevelValue(playerid) - Spieler[playerid][pDrogenSamen]);
	
	Spieler[playerid][pDrogenSamen] = GetPlayerSamenSkillLevelValue(playerid);
	
	//SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast nun %d Samen (+ %d Stück).", MAX_SAMEN, MAX_SAMEN - Spieler[playerid][pDrogenSamen]);
    //Spieler[playerid][pDrogenSamen] = MAX_SAMEN;
    return 1;
}

COMMAND:storepakete(playerid, params[]) {
	if (Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Du kannst mit Samen nichts anfangen.");
    for (new i = 0; i < sizeof(seedPoints); i++) {
        if (IsPlayerInRangeOfPoint(playerid, 3.0, seedPoints[i][SEED_POINT_fX], seedPoints[i][SEED_POINT_fY], seedPoints[i][SEED_POINT_fZ])) {
			new vehicleid = GetPlayerVehicleID(playerid);
			new vehiclemodel = GetVehicleModel(vehicleid);
			new fraktion = GetVehicleFraktion(vehicleid);
			if(fraktion != Spieler[playerid][pFraktion]) return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Nine-Demons Burrito!");
			if(vehiclemodel != 482) return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Nine-Demons Burrito!");
			if(bestand[vehicleid] < 1)return SendClientMessage(playerid, COLOR_RED, "Du hast nichts beladen!");
			new samenpakete = bestand[vehicleid];
			new string[128];
			format(string, sizeof(string), "Du hast %d Pakete abgeliefert und somit %d Samen in das Samenlager eingelagert.", bestand[vehicleid], samenpakete*5);
			SendClientMessage(playerid, COLOR_GREEN, string);
			bestand[vehicleid] = 0;
			if(i == 0){ Samen1Bestand += samenpakete*5; }
			if(i == 1){ Samen2Bestand += samenpakete*5; }
			if(i == 2){ Samen3Bestand += samenpakete*5; }
			if(i == 3){ Samen4Bestand += samenpakete*5; }
			if(i == 4){ Samen5Bestand += samenpakete*5; }
		}
	}
	return 1;
}

COMMAND:storesamen(playerid, params[]) {
	if (Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Du kannst mit Samen nichts anfangen.");
    for (new i = 0; i < sizeof(seedPoints); i++) {
        if (IsPlayerInRangeOfPoint(playerid, 3.0, seedPoints[i][SEED_POINT_fX], seedPoints[i][SEED_POINT_fY], seedPoints[i][SEED_POINT_fZ])) {
			new String[128];
			if(i == 0){
				if(Spieler[playerid][pDrogenSamen] <= 0) return SendClientMessage(playerid, COLOR_RED, "Du hast keine Samen zum einlagern!");
				Samen1Bestand += Spieler[playerid][pDrogenSamen];
				format(String, sizeof(String), "Du hast %i Samen eingelagert. Lagerstatus: %i Samen", Spieler[playerid][pDrogenSamen], Samen1Bestand);
				SendClientMessage(playerid, COLOR_YELLOW, String);
				Spieler[playerid][pDrogenSamen] = 0;
				break;
			}
			if(i == 1){
				if(Spieler[playerid][pDrogenSamen] <= 0) return SendClientMessage(playerid, COLOR_RED, "Du hast keine Samen zum einlagern!");
				Samen2Bestand += Spieler[playerid][pDrogenSamen];
				format(String, sizeof(String), "Du hast %i Samen eingelagert. Lagerstatus: %i Samen", Spieler[playerid][pDrogenSamen], Samen1Bestand);
				SendClientMessage(playerid, COLOR_YELLOW, String);
				Spieler[playerid][pDrogenSamen] = 0;
				break;
			}
			if(i == 2){
				if(Spieler[playerid][pDrogenSamen] <= 0) return SendClientMessage(playerid, COLOR_RED, "Du hast keine Samen zum einlagern!");
				Samen3Bestand += Spieler[playerid][pDrogenSamen];
				format(String, sizeof(String), "Du hast %i Samen eingelagert. Lagerstatus: %i Samen", Spieler[playerid][pDrogenSamen], Samen1Bestand);
				SendClientMessage(playerid, COLOR_YELLOW, String);
				Spieler[playerid][pDrogenSamen] = 0;
				break;
			}
			if(i == 3){
				if(Spieler[playerid][pDrogenSamen] <= 0) return SendClientMessage(playerid, COLOR_RED, "Du hast keine Samen zum einlagern!");
				Samen4Bestand += Spieler[playerid][pDrogenSamen];
				format(String, sizeof(String), "Du hast %i Samen eingelagert. Lagerstatus: %i Samen", Spieler[playerid][pDrogenSamen], Samen1Bestand);
				SendClientMessage(playerid, COLOR_YELLOW, String);
				Spieler[playerid][pDrogenSamen] = 0;
				break;
			}
			if(i == 4){
				if(Spieler[playerid][pDrogenSamen] <= 0) return SendClientMessage(playerid, COLOR_RED, "Du hast keine Samen zum einlagern!");
				Samen5Bestand += Spieler[playerid][pDrogenSamen];
				format(String, sizeof(String), "Du hast %i Samen eingelagert. Lagerstatus: %i Samen", Spieler[playerid][pDrogenSamen], Samen1Bestand);
				SendClientMessage(playerid, COLOR_YELLOW, String);
				Spieler[playerid][pDrogenSamen] = 0;
				break;
			}
        }
    }
	return 1;
}

COMMAND:samenlagerstatus(playerid, params[]) {
	if (Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Du kannst mit Samen nichts anfangen.");
    for (new i = 0; i < sizeof(seedPoints); i++) {
        if (IsPlayerInRangeOfPoint(playerid, 3.0, seedPoints[i][SEED_POINT_fX], seedPoints[i][SEED_POINT_fY], seedPoints[i][SEED_POINT_fZ])) {
			new String[128];
			if(i == 0){
				format(String, sizeof(String), "Lager ID: %i | Lagerstatus: %i Samen", i+1, Samen1Bestand);
				SendClientMessage(playerid, COLOR_YELLOW, String);
				break;
			}
			if(i == 1){
				format(String, sizeof(String), "Lager ID: %i | Lagerstatus: %i Samen", i+1, Samen2Bestand);
				SendClientMessage(playerid, COLOR_YELLOW, String);
				break;
			}
			if(i == 2){
				format(String, sizeof(String), "Lager ID: %i | Lagerstatus: %i Samen", i+1, Samen3Bestand);
				SendClientMessage(playerid, COLOR_YELLOW, String);
				break;
			}
			if(i == 3){
				format(String, sizeof(String), "Lager ID: %i | Lagerstatus: %i Samen", i+1, Samen4Bestand);
				SendClientMessage(playerid, COLOR_YELLOW, String);
				break;
			}
			if(i == 4){
				format(String, sizeof(String), "Lager ID: %i | Lagerstatus: %i Samen", i+1, Samen5Bestand);
				SendClientMessage(playerid, COLOR_YELLOW, String);
				break;
			}
        }
    }
	return 1;
}

CMD:samenpunkte(playerid, params[]) {
    if (Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Du brauchst nicht zu wissen, wo sich die Samenpunkte befinden.");
    new dialogText[512];
	new Lagerstatus;
    for (new i = 0; i < sizeof(seedPoints); i++) {
		if(i == 0) { Lagerstatus = Samen1Bestand; }
		if(i == 1) { Lagerstatus = Samen2Bestand; }
		if(i == 2) { Lagerstatus = Samen3Bestand; }
		if(i == 3) { Lagerstatus = Samen4Bestand; }
		if(i == 4) { Lagerstatus = Samen5Bestand; }
		format(dialogText, sizeof(dialogText), "%s%s - Lagerbestand: %i\n", dialogText, seedPoints[i][SEED_POINT_LOCATION_NAME], Lagerstatus);
    }
	return ShowPlayerDialog(playerid, DIALOG_SEEDPOINTS, DIALOG_STYLE_LIST, "{c3d038}Samenpunkte", dialogText, "Markieren", "Abbrechen");
}

CMD:samen(playerid, params[]) {
    if (Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Du hast keine Samen.");
    new message[145];
    if (Spieler[playerid][pDrogenSamen] == 0) message = "[INFO] {FFFFFF}Du hast {FFFF00}keine {FFFFFF}Samen bei dir.";
    else if (Spieler[playerid][pDrogenSamen] == 1) message = "[INFO] {FFFFFF}Du hast {FFFF00}einen {FFFFFF}Samen bei dir.";
    else format(message, sizeof(message), "[INFO] {FFFFFF}Du hast {FFFF00}%d {FFFFFF}Samen bei dir.", Spieler[playerid][pDrogenSamen]);
    return SendClientMessage(playerid, COLOR_YELLOW, message);
}
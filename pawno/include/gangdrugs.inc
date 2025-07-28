#include <YSI\y_hooks>

// Defines and variables

#define MAX_DROGEN_gang_pflaNZEN 1000
#define DROGENgang_pflaNZE_REIF 120*60
#define DROGENgang_pflaNZE_UEBERREIF 60*60
#define DROGENgang_pflaNZEN_WASSER_COOLDOWN 120*60
#define DROGENgang_pflaNZEN_WASSER_NOTICE 60*60

#define MAX_SAMEN 25

enum e_Drogengang_pflanzen {
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

new const gang_pflaNZEN_HELP[][] = {
    "/gangpflanzen help{FFFFFF}\t\tDiese Liste anzeigen",
    "/gangpflanzen anzahl{FFFFFF}\tDie Anzahl der angebauten Drogenpflanzen anzeigen",
    //"/gangpflanzen suchen{FFFFFF}\tEine gang_pflanze auf der Karte anzeigen",
    //"/gangpflanzen info{FFFFFF}\t\tInfo ‹ber n‰chstgelegene gang_pflanze (Reifezeit, Gieﬂzeit)",
    "/gangpflanzen anbauen{FFFFFF}\tEine gang_pflanze anbauen (maximal 1000 gang_pflanzen gleichzeitig)",
    //"/gangpflanzen giessen{FFFFFF}\tN‰chstgelegene gang_pflanze giessen (Zeit zum Gieﬂen: 600 Sekunden)",
    "/gangpflanzen verbrennen{FFFFFF}\tN‰chstgelegene Drogenpflanze wird verbrannt",
    "/gangpflanzen abbauen{FFFFFF}\tN‰chstgelegene gang_pflanze wird geerntet"
    //"/Nimmspice{FFFFFF}\t\tEin Gramm Spice einnehmen (10 Sekunden Cooldown)",
    //"/Sellspice{FFFFFF}\t\tSpice verkaufen",
    //"{00FF33}/Geben [ID] Spice [Menge]\tEinem Spieler Spice geben",
    //"/Samen{FFFFFF}\t\t\tSamenanzahl im Inventar anzeigen",
    //"/Getsamen{FFFFFF}\t\tAn einem Samenpunkt Samen holen",
    //"/Samenpunkte{FFFFFF}\t\tDie Samenpunkte auf der Karte anzeigen"
};

new g_Drogengang_pflanzenCount = 0;
new g_Drogengang_pflanzen[MAX_DROGEN_gang_pflaNZEN][e_Drogengang_pflanzen];


// Function hooks

hook OnPlayerDisconnect(playerid, reason) {
    RemPlayerFromPlantArrayDataGang(playerid);
    return 1;
}

/*hook OnGameModeInit() {
    for (new i = 0; i < sizeof(seedPoints); i++) {
        CreateDynamicPickup(1279, 1, seedPoints[i][SEED_POINT_fX], seedPoints[i][SEED_POINT_fY], seedPoints[i][SEED_POINT_fZ], 0);
        CreateDynamic3DTextLabel("Spice Drogensamen\n" COLOR_HEX_WHITE "Tippe /Getsamen", COLOR_YELLOW, seedPoints[i][SEED_POINT_fX], seedPoints[i][SEED_POINT_fY], seedPoints[i][SEED_POINT_fZ], 15.0);
    }
}*/

// Custom functions

stock InitDrogengang_pflanzen() {
    for (new i = 0; i < sizeof(g_Drogengang_pflanzen); i++) g_Drogengang_pflanzen[i][DP_text3D] = STREAMER_TAG_3D_TEXT_LABEL:INVALID_3DTEXT_ID;
    SetTimer("Pulse_Drogengang_pflanzen",997,true);
    return 1;
}

stock Showgang_pflanzenHelp(playerid) {
    new dialogText[1024];
    for (new i = 0; i < sizeof(gang_pflaNZEN_HELP); i++) format(dialogText, sizeof(dialogText), "%s{B4C12E}%s\n", dialogText, gang_pflaNZEN_HELP[i]);
    return ShowPlayerDialog(playerid, DIALOG_NO_RESPONSE, DIALOG_STYLE_LIST, "{FFFFFF}Drogenpflanzen Hilfe", dialogText, "Schlieﬂen", "");
}

stock RemPlayerFromPlantArrayDataGang(playerid) {
    for (new i = 0; i < sizeof(g_Drogengang_pflanzen); i++) {
        if (g_Drogengang_pflanzen[i][DP_text3D] == STREAMER_TAG_3D_TEXT_LABEL:INVALID_3DTEXT_ID) continue;
        Streamer_RemoveArrayData(STREAMER_TYPE_3D_TEXT_LABEL, g_Drogengang_pflanzen[i][DP_text3D], E_STREAMER_PLAYER_ID, playerid);
    }
    
    return 1;
}

stock AddPlayerToPlantArrayDataGang(playerid) {
    if( !IsAFightFaction( Spieler[playerid][pFraktion] ) ) return 1;
    for (new i = 0; i < sizeof(g_Drogengang_pflanzen); i++) {
        if (g_Drogengang_pflanzen[i][DP_text3D] == STREAMER_TAG_3D_TEXT_LABEL:INVALID_3DTEXT_ID) continue;
        Streamer_AppendArrayData(STREAMER_TYPE_3D_TEXT_LABEL, g_Drogengang_pflanzen[i][DP_text3D], E_STREAMER_PLAYER_ID, playerid);
    }
    
    return 1;
}

stock CreateDrogengang_pflanzen(playerid, Float:x, Float:y, Float:z) {
    new index = GetFreeDrogengang_pflanzenSlot();
    if (index == -1) return 0;

    g_Drogengang_pflanzen[index][DP_fX] = x;
    g_Drogengang_pflanzen[index][DP_fY] = y;
    g_Drogengang_pflanzen[index][DP_fZ] = z;
    g_Drogengang_pflanzen[index][DP_iWasser] = DROGENgang_pflaNZEN_WASSER_COOLDOWN + 15;
    g_Drogengang_pflanzen[index][DP_iFortschritt] = 0;
    g_Drogengang_pflanzen[index][DP_bInUse] = true;
    g_Drogengang_pflanzen[index][DP_bDestroyed] = false;
    g_Drogengang_pflanzenCount++;
    g_Drogengang_pflanzen[index][DP_iObject] = CreateDynamicObject(812, x, y, z - 1.5, 0.0, 0.0, 0.0);
    g_Drogengang_pflanzen[index][DP_text3D] = CreateDynamic3DTextLabel("[ {009D00}Drogenpflanze {FFFFFF}]", COLOR_WHITE, x, y, z, 20.0, .testlos = 1, .streamdistance = 30.0);
    new pArray[1];
    pArray[0] = playerid;
    Streamer_SetArrayData(STREAMER_TYPE_3D_TEXT_LABEL, g_Drogengang_pflanzen[index][DP_text3D], E_STREAMER_PLAYER_ID, pArray);

    for (new i = 0; i <= GetPlayerPoolSize(); i++){
        /*if( IsAFightFaction( Spieler[i][pFraktion] ) ) */Streamer_AppendArrayData(STREAMER_TYPE_3D_TEXT_LABEL, g_Drogengang_pflanzen[index][DP_text3D], E_STREAMER_PLAYER_ID, i);
    }

    g_Drogengang_pflanzen[index][DP_iFireObject] = INVALID_OBJECT_ID;
    MoveDynamicObject(g_Drogengang_pflanzen[index][DP_iObject], x, y, z, 0.1);
    return 1;
}
stock GetFreeDrogengang_pflanzenSlot() {
    for(new i ; i < sizeof(g_Drogengang_pflanzen) ; i++) {
        if( g_Drogengang_pflanzen[i][DP_bInUse] == false ) {
            return i;
        }
    }
    return -1;
}

new BrenennTimerGang[MAX_DROGEN_gang_pflaNZEN];

stock SetDrogengang_pflanzenOnFire(index) {
    g_Drogengang_pflanzen[index][DP_iFireObject] = CreateDynamicObject( 18688 , g_Drogengang_pflanzen[index][DP_fX] , g_Drogengang_pflanzen[index][DP_fY], g_Drogengang_pflanzen[index][DP_fZ] - 2.0, 0.0,0.0,0.0 );
    g_Drogengang_pflanzen[index][DP_bDestroyed] = true;
    UpdateDynamic3DTextLabelText(g_Drogengang_pflanzen[index][DP_text3D], COLOR_WHITE, "[ {009D00}Drogenpflanze {FFFFFF}]\n{FF9900}> Die Drogenpflanze wurde verbrannt <");
    //SetTimerEx("DestroyDrogengang_pflanze",10*1000,false,"d",index);
	BrenennTimerGang[index] = SetTimerEx("DestroyDrogengang_pflanze",60*10000,false,"d",index);
    return 1;
}

stock Drogengang_pflanzenFeuerLoes(index) {
	DestroyDynamicObject(g_Drogengang_pflanzen[index][DP_iFireObject]);
    g_Drogengang_pflanzen[index][DP_bDestroyed] = false;
    Pulse_Drogengang_pflanzen();
	KillTimer(BrenennTimerGang[index]);
    return 1;
}

forward DestroyDrogengang_pflanze(index);
public DestroyDrogengang_pflanze(index) {
    DestroyDynamicObject(g_Drogengang_pflanzen[index][DP_iObject]);
    g_Drogengang_pflanzen[index][DP_iObject] = INVALID_OBJECT_ID;
    DestroyDynamicObject(g_Drogengang_pflanzen[index][DP_iFireObject]);
    g_Drogengang_pflanzen[index][DP_iFireObject] = INVALID_OBJECT_ID;
    DestroyDynamic3DTextLabel(g_Drogengang_pflanzen[index][DP_text3D]);
    g_Drogengang_pflanzen[index][DP_text3D] = STREAMER_TAG_3D_TEXT_LABEL:INVALID_3DTEXT_ID;

    g_Drogengang_pflanzen[index][DP_bInUse] = false;
    g_Drogengang_pflanzen[index][DP_bDestroyed] = false;

    g_Drogengang_pflanzenCount--;
    return 1;
}
stock GetClosestDrogengang_pflanze(playerid,Float:radius = 8.0) {
    new
        index = -1,
        Float:distance,
        Float:best_distance = 100.0,
        Float:x,
        Float:y,
        Float:z;
    GetPlayerPos(playerid,x,y,z);
    for(new i ; i < sizeof(g_Drogengang_pflanzen) ; i++) {
        if( g_Drogengang_pflanzen[i][DP_bInUse] == true/* && !g_Drogengang_pflanzen[i][DP_bDestroyed]*/) {
            distance = GetDistance(x,y,z,g_Drogengang_pflanzen[i][DP_fX],g_Drogengang_pflanzen[i][DP_fY],g_Drogengang_pflanzen[i][DP_fZ]);
            if( distance < best_distance && distance <= radius ) {
                best_distance = distance;
                index = i;
            }
        }
    }
    return index;
}

forward Pulse_Drogengang_pflanzen();
public Pulse_Drogengang_pflanzen() {
    for (new i; i < sizeof(g_Drogengang_pflanzen); i++) {
        if (!g_Drogengang_pflanzen[i][DP_bInUse] || g_Drogengang_pflanzen[i][DP_bDestroyed]) continue;

        g_Drogengang_pflanzen[i][DP_iFortschritt]++;
        if (g_Drogengang_pflanzen[i][DP_iFortschritt] >= (DROGENgang_pflaNZE_REIF + DROGENgang_pflaNZE_UEBERREIF)) {
            DestroyDrogengang_pflanze(i);
            g_Drogengang_pflanzenCount--;
        }
        else if (g_Drogengang_pflanzen[i][DP_iFortschritt] < DROGENgang_pflaNZE_REIF) {
            g_Drogengang_pflanzen[i][DP_iWasser]--;
            if (g_Drogengang_pflanzen[i][DP_iWasser] <= 0) {
                DestroyDrogengang_pflanze(i);
                g_Drogengang_pflanzenCount--;
            }
        }

        if (!g_Drogengang_pflanzen[i][DP_bInUse] || g_Drogengang_pflanzen[i][DP_bDestroyed]) continue;

        new labelText[256] = "[ {009D00}Drogenpflanze {FFFFFF}]\n";
        if (g_Drogengang_pflanzen[i][DP_iFortschritt] >= DROGENgang_pflaNZE_REIF)
            format(labelText, sizeof(labelText), "%s{FFFF00}> Die Drogenpflanze ist reif <", labelText);
        /*else if (g_Drogengang_pflanzen[i][DP_iWasser] < DROGENgang_pflaNZEN_WASSER_NOTICE) {
            format(labelText, sizeof(labelText), "%s{FFFF00}Reif in: {FFFFFF}%i Minute(n)\n{FFFF00}Vertrocknet in: {FFFFFF}%i Minute(n)\n{FFFF00}> Jetzt gieﬂen <", labelText, 
                floatround(float(DROGENgang_pflaNZE_REIF - g_Drogengang_pflanzen[i][DP_iFortschritt]) / 60.0, floatround_ceil), 
                floatround(float(g_Drogengang_pflanzen[i][DP_iWasser]) / 60.0, floatround_ceil));
        }*/
        else
            /*format(labelText, sizeof(labelText), "%s{FFFF00}Reif in: {FFFFFF}%i Minute(n)\n{FFFF00}Gieﬂen in: {FFFFFF}%i Minute(n)\n{FFFF00}Vertrocknet in: {FFFFFF}%i Minute(n)", labelText, 
                floatround(float(DROGENgang_pflaNZE_REIF - g_Drogengang_pflanzen[i][DP_iFortschritt]) / 60.0, floatround_ceil));*/
            format(labelText, sizeof(labelText), "%s{FFFF00}Reif in: {FFFFFF}%i Minute(n)", labelText, 
                floatround(float(DROGENgang_pflaNZE_REIF - g_Drogengang_pflanzen[i][DP_iFortschritt]) / 60.0, floatround_ceil));

        UpdateDynamic3DTextLabelText(g_Drogengang_pflanzen[i][DP_text3D], COLOR_WHITE, labelText);
    }

    return 1;
}

// Commands

COMMAND:gangpflanzeverbrennen(playerid) {
    if (!IsPlayerExecutive(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Exekutivbeamter.");
    if(bIsSpectating[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du kannst beim Spectaten keine Pflanzen verbrennen.");
    new gang_pflanze = GetClosestDrogengang_pflanze(playerid, 3.0);
    if (gang_pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Drogenpflanze in deiner N‰he.");
    SendClientMessage(playerid, COLOR_YELLOW, "Die Drogenpflanze wurde verbrannt.");
    SetDrogengang_pflanzenOnFire(gang_pflanze);
    return 1;
}

COMMAND:gangpflanzen(playerid, params[]) {
    if( !IsAFightFaction( Spieler[playerid][pFraktion] )) return SendClientMessage(playerid, COLOR_RED, "Du bist in keiner Gang.");
    if (isnull(params)) return Showgang_pflanzenHelp(playerid);

    new entry[32], value;
    if (sscanf(params, "s[32]D(-1)", entry, value)) return SendClientMessage(playerid, COLOR_BLUE, "* Benutze: {00CC00}/gang_pflanzen f¸r eine ‹bersicht");
	
	if (!strcmp(entry, "loeschen", true)) {
        new gang_pflanze = GetClosestDrogengang_pflanze(playerid, 3.0);
        if (gang_pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Drogenpflanze in deiner N‰he.");
		if(g_Drogengang_pflanzen[gang_pflanze][DP_bDestroyed] != true) return SendClientMessage(playerid, COLOR_RED, "Diese Drogenpflanze brennt nicht.");
        SendClientMessage(playerid, COLOR_YELLOW, "Das Feuer wurde gelˆscht.");

        /*new message[145];
        format(message, sizeof(message), "Member %s hat eine Drogenpflanze gelˆscht.", GetName(playerid));*/
        Drogengang_pflanzenFeuerLoes(gang_pflanze);
        return 1;
    }
	
    if (!strcmp(entry, "verbrennen", true)) {
        new gang_pflanze = GetClosestDrogengang_pflanze(playerid, 3.0);
        if (gang_pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Drogenpflanze in deiner N‰he.");
        SendClientMessage(playerid, COLOR_YELLOW, "Die Drogenpflanze wurde zerstoert.");

        /*new message[145];
        format(message, sizeof(message), "Member %s hat eine Drogenpflanze zerstoert.", GetName(playerid));*/
        SetDrogengang_pflanzenOnFire(gang_pflanze);
        return 1;
    }

    /*if (!strcmp(entry, "suchen", true)) {
        if (value == -1) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/gang_pflanzen suchen [Index]");
        if (g_Drogengang_pflanzenCount == 0) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Es sind momentan keine gang_pflanzen angebaut.");
        if (value > MAX_DROGEN_gang_pflaNZEN || value < 1) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Index muss zwischen 1 und 200 liegen.");
        if (!g_Drogengang_pflanzen[value - 1][DP_bInUse]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Die gang_pflanze ist nicht angebaut.");
        SetPlayerCheckpointEx(playerid, g_Drogengang_pflanzen[value - 1][DP_fX], g_Drogengang_pflanzen[value - 1][DP_fY], g_Drogengang_pflanzen[value - 1][DP_fZ], 1.0, CP_NAVI4);
        return SendClientMessage(playerid, COLOR_GREEN, "[INFO] {FFFFFF}Die gang_pflanze wurde auf der Karte Rot markiert.");
    }*/

    if (!strcmp(entry, "help", true)) return Showgang_pflanzenHelp(playerid);

    if (!strcmp(entry, "anzahl", true)) {
        if (g_Drogengang_pflanzenCount == 0) return SendClientMessage(playerid, COLOR_GREEN, "Es sind momentan {7FFFD4}keine {009D00}Drogenpflanzen angebaut.");
        if (g_Drogengang_pflanzenCount == 1) return SendClientMessage(playerid, COLOR_GREEN, "Es ist momentan {7FFFD4}eine von 1000 {009D00}Drogenpflanzen angebaut.");

        new message[148];
        format(message, sizeof(message), "Es sind momentan {7FFFD4}%i von 200 {009D00}Drogenpflanze angebaut.", g_Drogengang_pflanzenCount);
        return SendClientMessage(playerid, COLOR_GREEN, message);
    }

    if (!strcmp(entry, "anbauen", true)) {
        if (IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Fahrzeug keine Drogenpflanzen anbauen.");
        if (g_Drogengang_pflanzenCount >= 200) return SendClientMessage(playerid, COLOR_RED, "Es sind bereits 200 Drogenpflanzen angebaut.");
        new gang_pflanze = GetClosestDrogengang_pflanze(playerid); 
        if (gang_pflanze != -1) return SendClientMessage(playerid, COLOR_RED, "Hier ist bereits eine Drogenpflanze.");
        if (Spieler[playerid][pGangDrogenSamen] < 1) return SendClientMessage(playerid, COLOR_RED, "Du besitzt keine Samen, um eine Drogenpflanze anzubauen.");

        new Float:x, Float:y, Float:z;
        GetPlayerPos(playerid, x, y, z);
        if (!CreateDrogengang_pflanzen(playerid, x, y, z)) return SendClientMessage(playerid, COLOR_RED, "Du kannst gerade keine gang_pflanze anbauen.");
        Spieler[playerid][pGangDrogenSamen]--;
        new message[145];
        if (Spieler[playerid][pGangDrogenSamen] == 0) message = "Eine Drogenpflanze wird gezogen. Du hast {FFFFFF}keine {FFFF00}Samen mehr ¸brig.";
        else if (Spieler[playerid][pGangDrogenSamen] == 1) message = "Eine Drogenpflanze wird gezogen. Du hast noch {FFFFFF}einen {FFFF00}Samen ¸brig.";
        else format(message, sizeof(message), "Eine Drogenpflanze wird gezogen. Du hast noch {FFFFFF}%d {FFFF00}Samen ¸brig.", Spieler[playerid][pGangDrogenSamen]);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        SetTimerEx("TogglePlayerControllableEx", 1000, false, "dd", playerid, true);
        FreezePlayer(playerid);
        SetPlayerPos(playerid, x, y, z + 0.01);
        return 1;
    }
    
    if (!strcmp(params, "info", true)) {
        new gang_pflanze = GetClosestDrogengang_pflanze(playerid, 3.0);
        if (gang_pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Drogenpflanze in deiner N‰he.");
        if (g_Drogengang_pflanzen[gang_pflanze][DP_iFortschritt] > DROGENgang_pflaNZE_REIF) return SendClientMessage(playerid,COLOR_YELLOW,"Diese Drogenpflanze ist reif.");
    
        new message[145];
        format(message, sizeof(message), "Die Drogenpflanze ist reif in: %d Sekunden.", DROGENgang_pflaNZE_REIF - g_Drogengang_pflanzen[gang_pflanze][DP_iFortschritt]);
        SendClientMessage(playerid, COLOR_WHITE, message);
        format(message, sizeof(message), "Die Drogenpflanze benˆtigt Wasser in: %d bis %d Sekunden.", g_Drogengang_pflanzen[gang_pflanze][DP_iWasser] - DROGENgang_pflaNZEN_WASSER_NOTICE, g_Drogengang_pflanzen[gang_pflanze][DP_iWasser]);
        return SendClientMessage(playerid, COLOR_WHITE, message);
    }

    /*if (!strcmp(entry,"giessen", true)) {
        new gang_pflanze = GetClosestDrogengang_pflanze(playerid, 3.0);
        if (gang_pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Drogenpflanze in deiner N‰he.");
        if (g_Drogengang_pflanzen[gang_pflanze][DP_iWasser] > DROGENgang_pflaNZEN_WASSER_NOTICE ) return SendClientMessage(playerid, COLOR_RED, "Diese Drogenpflanze benˆtigt noch kein Wasser.");
        g_Drogengang_pflanzen[gang_pflanze][DP_iWasser] = DROGENgang_pflaNZEN_WASSER_COOLDOWN;
        return SendClientMessage(playerid, COLOR_YELLOW, "Du hast die Drogenpflanze bew‰ssert.");
    }*/

    if (!strcmp(entry,"abbauen", true)) {
        if (IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Fahrzeug keine Drogenpflanzen abbauen.");
        new gang_pflanze = GetClosestDrogengang_pflanze(playerid, 3.0);
        if (gang_pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Drogenpflanze in deiner N‰he.");
        if (g_Drogengang_pflanzen[gang_pflanze][DP_iFortschritt] < DROGENgang_pflaNZE_REIF) return SendClientMessage(playerid, COLOR_RED, "Die Drogenpflanze ist noch nicht reif.");
        new randomAmount = RandomEx(10, 14), message[145];
        if(g_Drogengang_pflanzen[gang_pflanze][DP_bDestroyed] == true) return SendClientMessage(playerid, COLOR_RED, "Die Pflanze wurde bereits geerntet!");
        g_Drogengang_pflanzen[gang_pflanze][DP_bDestroyed] = true;
        UpdateDynamic3DTextLabelText(g_Drogengang_pflanzen[gang_pflanze][DP_text3D], COLOR_WHITE, "[ {009D00}Drogenpflanze {FFFFFF}]\n{FFFF00}> Die Drogenpflanze wurde geerntet <");
        SetTimerEx("DestroyDrogengang_pflanze", 2 * 1000, false, "d", gang_pflanze);
        g_Drogengang_pflanzenCount--;
        MoveDynamicObject(g_Drogengang_pflanzen[gang_pflanze][DP_iObject], g_Drogengang_pflanzen[gang_pflanze][DP_fX], g_Drogengang_pflanzen[gang_pflanze][DP_fY], g_Drogengang_pflanzen[gang_pflanze][DP_fZ] - 2.0, 0.05);
        FreezePlayer(playerid);
        SetTimerEx("TogglePlayerControllableEx", 2 * 1000, false, "dd", playerid, true);
        Spieler[playerid][pDrugs] += randomAmount;
		format(message, sizeof(message), "%s hat %d Gramm Spice abgebaut. FSafebox: %s Gramm Spice.", GetName(playerid), randomAmount, AddDelimiters(g_fraktion[15][Fr_FSSpice]));
        SendClientMessage(playerid, COLOR_YELLOW, "Die Drogenpflanze wird von dir geerntet.");
        return 1;
    }

    return SendClientMessage(playerid, COLOR_BLUE, "* Benutze: {00CC00}/Gangpflanzen f¸r eine ‹bersicht");
}
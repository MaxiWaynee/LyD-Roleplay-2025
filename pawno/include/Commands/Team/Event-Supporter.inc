#include <YSI\y_hooks>


enum e_Event {
    bool:E_bStatus,
    Float:E_fX,
    Float:E_fY,
    Float:E_fZ,
    E_iInterior,
    E_iVirtualworld
}

new g_Event[e_Event];


new Text3D:dlabel;
new dlabelid=0;
new Text3D:dlabeldevent[500];
CMD:addlabel(playerid, params[]){
	new String[128], Float:x, Float:y, Float:z, Float:Draw, VW;
	if(Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
	if(sscanf(params, "s", String)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Addlabel [Text]");
	GetPlayerPos(playerid, x, y, z);
	VW = GetPlayerVirtualWorld(playerid);
	Draw = 10;
	dlabel = Create3DTextLabel(String, 0xFFFFFFFF, x, y, z, Draw, VW, 0);
    SCMFormatted(playerid,COLOR_YELLOW,"[INFO] {FFFFFF}Das Label wurde erstellt! Label-ID: %d", dlabelid);
	dlabeldevent[dlabelid] = dlabel;
    dlabelid++;
    return 1;
}



CMD:removelabel(playerid, params[]){
	new deldlabelid;
	if(Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
	if(sscanf(params, "i", dlabelid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Removelabel [Server Label-ID]");
	Delete3DTextLabel(dlabeldevent[deldlabelid]);
	return 1;
}



CMD:removealllabels(playerid, params[]){
	if(Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
	for(new i = 0; i <=500; i++){
	    Delete3DTextLabel(dlabeldevent[i]);
	}
	SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Es wurden alle Labels gelöscht");
	return 1;
}



new objects;
new objectmodel[5000];
CMD:objectlist(playerid, params[]){
    if(Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
	for(new i = 100; i <=5000; i++){
        new string[128];
 		new Float:xo, Float:yo, Float:zo;
		GetObjectPos(i, xo, yo, zo);
		if(xo!=0 && yo!=0 && zo!=0){
			format(string, sizeof(string), "ID:%dCreateObject(%d,%f,%f,%f);",i,objectmodel[i],xo,yo,zo);
			SendClientMessage(playerid, COLOR_BLUE, string);
		}
	}
	return 1;
}



CMD:addobject(playerid, params[]){
    new oid,myobject;
    if(Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "i", oid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Addobject [Objekt-ID]");
	new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    myobject = CreateObject(oid, x+2, y+2, z+2, 0.0, 0.0, 90.0);
    SCMFormatted(playerid,COLOR_YELLOW,"[INFO] {FFFFFF}Das Objekt wurde erstellt! Server-ID: %d",myobject);
    objectmodel[myobject]=oid;
    objects++;
    return 1;
}



CMD:removeallobjects(playerid, params[]){
	if(Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
	for(new i = 100; i <=5000; i++){//Erst ab 100, weil darunter andere Objekte sind!!!
	    DestroyObject(i);
	}
	SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Es wurden alle Objekte gelöscht.");
	return 1;
}



CMD:removeobject(playerid, params[]){
	new oid;
	if(Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
	if(sscanf(params, "i", oid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Removeobject [Server Objekt-ID]");
	DestroyObject(oid);
	return 1;
}



CMD:editobject(playerid, params[]){
    new oid;
    if(Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "i", oid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Editobject [Server Object-ID]");
	EditObject(playerid, oid);
	return 1;
}



CMD:gotoobject(playerid, params[]){
    new oid;
    if(Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "i", oid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Gotoobject [Server Object-ID]");
	new Float:xo, Float:yo, Float:zo;
	GetObjectPos(oid, xo, yo, zo);
	SetPlayerPos(playerid,xo+1,yo+1,zo+1);
	SCMFormatted(playerid,COLOR_YELLOW,"[INFO] {FFFFFF}Du hast dich zur Objekt-ID: %d teleportiert.",oid);
	return 1;
}



CMD:delallvehs(playerid,params[]) {
    #pragma unused params
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    new
        String[128],
        c = 0;
    for(new i = 0 ; i < MAX_VEHICLES ; i++) {
        if( aiVehicles[i] == VEH_CAR ) {
            DestroyVehicleEx(i);
            aiVehicles[i] = VEH_INVALID;
            c++;
        }
    }
    format(String,sizeof(String),"%s %s hat alle /VEH Fahrzeuge entfernt (Anzahl: %d)", GetPlayerAdminRang(playerid), GetName(playerid),c);
    SendAdminMessage(COLOR_ORANGE,String);
    return 1;
}



CMD:clearweapons(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);

    new pID;
    if (sscanf(params, "u", pID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Clearweapons [Spieler ID/Name]");
    if (!IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht online.");
    ResetPlayerWeapons(pID);
    SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Waffen von %s gecleart.", GetName(pID));
    return SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}%s %s hat deine Waffen gecleart.", GetPlayerAdminRang(playerid), GetName(playerid));
}




CMD:eventuhr(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    if( g_EventUhr[EU_tTimer] != INVALID_TIMER_ID ) {
        return SendClientMessage(playerid,COLOR_RED,"Ein Eventtimer läuft gerade");
    }
    g_EventUhr[EU_tTimer] = SetTimer("EventUhr",1000,true);
    g_EventUhr[EU_iLeft] = 5 + 1;
    return 1;
}


CMD:eventmarker(playerid,params[]) {
    new funktion[32];
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    if(sscanf(params,"s[32]",funktion)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Eventmarker [START/LOESCHEN/ABBRECHEN/ERSTELLEN]");
    if(!strcmp(params,"start")) {
        if( g_EventMarker[EV_iState] == 1 ) {
            new String[128];
            format(String,sizeof(String),"%s %s startet das Event", GetPlayerAdminRang(playerid), GetName(playerid));
            SendClientMessageToAll(COLOR_GREEN,String);
            foreach(new i : Player) {
                SetPlayerRaceCheckpoint(i,0,
                    g_EventMarkerCheckpoints[0][0],
                    g_EventMarkerCheckpoints[0][1],
                    g_EventMarkerCheckpoints[0][2],
                    g_EventMarkerCheckpoints[1][0],
                    g_EventMarkerCheckpoints[1][1],
                    g_EventMarkerCheckpoints[1][2],
                    5.0);
                EventCP[i] = 0;
            }
            g_EventMarker[EV_iState] = 2;
        } else {
            SendClientMessage(playerid,COLOR_RED,"Eventstart nicht möglich");
        }
        return 1;
    } else if(!strcmp(params,"erstellen")) {
        if( g_EventMarker[EV_iState] == 0 ) {
            new Float:X, Float:Y,  Float:Z, Float:Rot, cp;
            g_EventMarker[EV_iState] = 1;
            g_EventMarker[EV_iPlayerID] = playerid;
            g_EventMarker[EV_iCheckpoints] = 0;
            cp = g_EventMarker[EV_iCheckpoints];
            GetPlayerPos(playerid,X,Y,Z);
            GetPlayerFacingAngle(playerid,Rot);
            g_EventMarkerCheckpoints[cp][0] = X;
            g_EventMarkerCheckpoints[cp][1] = Y;
            g_EventMarkerCheckpoints[cp][2] = Z;
            g_EventMarkerCheckpoints[cp][3] = Rot;
            SendClientMessage(playerid,COLOR_GREEN,"Erstellen gestartet");
            SendClientMessage(playerid,COLOR_GREEN,"Weitere Positionen kannst du mit /Eventmarker erstellen");
            g_EventMarker[EV_iCheckpoints]++;
        } else if( g_EventMarker[EV_iState] == 1 ) {
            if( g_EventMarker[EV_iPlayerID] != playerid ) return SendClientMessage(playerid,COLOR_RED,"Das Event wird bereits von einem Spieler erstellt");
            new Float:X, Float:Y, Float:Z, Float:Rot, String[128], cp;
            cp = g_EventMarker[EV_iCheckpoints];
            GetPlayerPos(playerid,X,Y,Z);
            GetPlayerFacingAngle(playerid,Rot);
            g_EventMarkerCheckpoints[cp][0] = X;
            g_EventMarkerCheckpoints[cp][1] = Y;
            g_EventMarkerCheckpoints[cp][2] = Z;
            g_EventMarkerCheckpoints[cp][3] = Rot;
            format(String,sizeof(String),"%d. Checkpoint gespeichert!", cp + 1 );
            SendClientMessage(playerid,COLOR_YELLOW,String);
            g_EventMarker[EV_iCheckpoints]++;
        } else if ( g_EventMarker[EV_iState] == 2 ) return SendClientMessage(playerid,COLOR_RED,"Event läuft bereits");
    } else if(!strcmp(params,"loeschen")) {
        if( g_EventMarker[EV_iState] == 1 ) {
            for(new i ; i < sizeof(g_EventMarkerCheckpoints) ; i++) {
                g_EventMarkerCheckpoints[i][0] = 0.0;
                g_EventMarkerCheckpoints[i][1] = 0.0;
                g_EventMarkerCheckpoints[i][2] = 0.0;
                g_EventMarkerCheckpoints[i][3] = 0.0;
            }
            g_EventMarker[EV_iCheckpoints] = 0;
            g_EventMarker[EV_iState] = 0;
            g_EventMarker[EV_iPlayerID] = INVALID_PLAYER_ID;
            SendClientMessage(playerid,COLOR_YELLOW,"Eventmarker gelöscht!");
        } else {
            SendClientMessage(playerid,COLOR_RED,"Eventmarker können nicht gelöscht werden");
        }
    } else if(!strcmp(params,"abbrechen")) {
        if( g_EventMarker[EV_iState] == 2 ) {
            new
                String[128];
            for(new i ; i < sizeof(g_EventMarkerCheckpoints) ; i++) {
                g_EventMarkerCheckpoints[i][0] = 0.0;
                g_EventMarkerCheckpoints[i][1] = 0.0;
                g_EventMarkerCheckpoints[i][2] = 0.0;
                g_EventMarkerCheckpoints[i][3] = 0.0;
            }
            g_EventMarker[EV_iState] = 0;
            g_EventMarker[EV_iPlayerID] = INVALID_PLAYER_ID;
            g_EventMarker[EV_iCheckpoints] = 0;
            for(new i ; i < MAX_PLAYERS ; i++) {
                DisablePlayerRaceCheckpoint(i);
                EventCP[playerid] = 0;
            }
            format(String,sizeof(String),"%s %s hat das Event abgebrochen", GetPlayerAdminRang(playerid), GetName(playerid));
            SendClientMessageToAll(COLOR_RED,String);
        } else {
            SendClientMessage(playerid,COLOR_RED,"Das Event kann nicht abgebrochen werden, da es nicht läuft");
        }
    } else return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Eventmarker [START/LOESCHEN/ABBRECHEN/ERSTELLEN]");
    return 1;
}



CMD:aeventitem(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
    return ShowEventItemDialog(playerid);
}



CMD:eventpunkte(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
    new playerName[MAX_PLAYER_NAME], pID, points;
    if (GetPVarString(playerid, "OFFEP.NAME", playerName, sizeof(playerName)) != 0) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du verteilst gerade noch Eventpunkte.");
    if (sscanf(params, "ui", pID, points) || !points) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Eventpunkte [Spieler ID/Name] [Punkte]");
    if (pID == INVALID_PLAYER_ID) {
        if (sscanf(params, "s[24] i", playerName, points)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du hast keinen gültigen Spieler angegeben.");
        new query[256];
        mysql_real_escape_string(playerName, playerName);
        format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `Name` = '%s'", playerName);
        SetPVarString(playerid, "OFFEP.NAME", playerName);
        SetPVarInt(playerid, "OFFEP.POINTS", points);
        mysql_pquery(query, THREAD_OFFEPOINTS_CHECK, playerid, gSQL, MySQLThreadOwner);
        return 1;
    }
    Spieler[pID][pEventPoints] += points;
    SCMFormatted(playerid, COLOR_ORANGE, "[EVENT] {FFFFFF}Du hast %s %d Eventpunkte gegeben.", GetName(pID), points);
    SCMFormatted(pID, COLOR_ORANGE, "[EVENT] {FFFFFF}%s %s hat dir %d Eventpunkte gegeben.", GetPlayerAdminRang(playerid), GetName(playerid), points);
    if (points > 0) SendClientMessage(pID, COLOR_ORANGE, "[EVENT] {FFFFFF}Benutze /Eventpreise um zu sehen, wofür du diese einlösen kannst.");
    new message[145];
    format(message, sizeof(message), "%s %s hat die Daten von Spieler %s überarbeitet! (Eventpunkte gegeben: %d)", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), points);
    AdminLog(message);
    return 1;
}



CMD:startevent(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
    if( g_Event[E_bStatus] ) return SendClientMessage(playerid, COLOR_RED, "Ein Event läuft noch");
    new String[128],  Float:X,Float:Y,Float:Z;
    GetPlayerPos(playerid,X,Y,Z);
    format(String,sizeof(String),"[EVENT] %s %s startet ein Event!", GetPlayerAdminRang(playerid), GetName(playerid));
    SendClientMessageToAll(COLOR_GREEN,String);
    SendClientMessageToAll(COLOR_ORANGE,"Mit /Gotoevent könnt Ihr euch zum Event teleportieren!");
    g_Event[E_fX] = X;
    g_Event[E_fY] = Y;
    g_Event[E_fZ] = Z;
    g_Event[E_bStatus] = true;
    g_Event[E_iInterior] =  GetPlayerInterior(playerid);
    g_Event[E_iVirtualworld] = GetPlayerVirtualWorld(playerid);
    return 1;
}



CMD:stopevent(playerid,params[]) {
    if(Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
    if( !g_Event[E_bStatus] ) return SendClientMessage(playerid, COLOR_RED, "Aktuell läuft kein Event");
    new String[128];
    format(String,sizeof(String),"[EVENT] %s %s stoppt das Event. Ihr könnt euch nicht mehr zum Start teleportieren!", GetPlayerAdminRang(playerid), GetName(playerid));
    SendClientMessageToAll(COLOR_LIGHTRED2,String);
    g_Event[E_bStatus] = false;
    return 1;
}



CMD:awb(playerid, params[]) return cmd_awiederbeleben(playerid, params);
CMD:awiederbeleben(playerid, params[])
{
    new pID, string[128];
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Awiederbeleben [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pTot] == 0)return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht tot.");
    format(string, sizeof(string), "* Du hast %s wiederbelebt.", GetName(pID));
    SendClientMessage(playerid, COLOR_GREEN, string);
    Spieler[pID][pTot] = 0;
    Spieler[pID][pTotTime] = 0;
    format(string, sizeof(string), "Du wurdest von %s %s wiederbelebt.", GetPlayerAdminRang(playerid), GetName(playerid));
    SendClientMessage(pID, COLOR_GREEN, string);
    UnfreezePlayer(pID);
    SetCameraBehindPlayer(pID);
    ResetPlayerWeapons(pID);
    ReStore_PlayerWeapons(pID);
    SetPlayerHealth(pID, 100.0);
    ClearAnimations(pID, 1);
    if( Spieler[pID][pSpawnWeste] > gettime() ) SetPlayerArmour(pID, 100);
    return 1;
}



CMD:sethp(playerid, params[]) {
    new pID, string[128], health;
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "ui", pID, health))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Sethp [SpielerID/Name] [Leben]");
    if(health < 1 || health > 100) return SendClientMessage(playerid,COLOR_BLUE,INFO_STRING"[1-100 HP]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    SetPlayerHealth(pID, health);
    format(string, sizeof(string), "Du hast das Leben von %s auf %d gesetzt.", GetName(pID), health);
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "* %s %s hat das Leben von Spieler %s auf %d Prozent gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), health);
    SendAdminMessage(COLOR_YELLOW, string);
    printf("%s hat das Leben von %s auf %d gesetzt.", GetName(playerid), GetName(pID), health);
    return 1;
}



CMD:setarmor(playerid, params[]) {
    new pID, string[128], health;
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "ui", pID, health))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Setarmor [SpielerID/Name] [Leben]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    SetPlayerArmour(pID, health);
    format(string, sizeof(string), "Du hast die Rüstung von %s auf %d gesetzt.", GetName(pID), health);
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "* %s %s hat Spieler %s eine Schutzweste (%d Prozent) gesetzt.", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), health);
    SendAdminMessage(COLOR_YELLOW, string);
    printf("%s hat die Rüstung von %s auf %d gesetzt.", GetName(playerid), GetName(pID), health);
    return 1;
}



CMD:setmark(playerid) {
	new Float:x, Float:y, Float:z;
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    GetPlayerPos(playerid, x, y, z);
    Spieler[playerid][pAMarkX] = x;
    Spieler[playerid][pAMarkY] = y;
    Spieler[playerid][pAMarkZ] = z;
    SetPlayerMapIcon(playerid, 75, x, y, z, 56, 0, MAPICON_GLOBAL);
    SendClientMessage(playerid, COLOR_BLUE, "Punkt gesetzt! Benutze '/gotomark' um dich hier hin zu teleportieren!");
    return 1;
}



CMD:gotomark(playerid){
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    if(Spieler[playerid][pAMarkX] == 0)return SendClientMessage(playerid, COLOR_RED, "Es wurde kein gesetzter Punkt gefunden!");
    SetPlayerPos(playerid, Spieler[playerid][pAMarkX], Spieler[playerid][pAMarkY], Spieler[playerid][pAMarkZ]);
    SendClientMessage(playerid, COLOR_BLUE, "Du wurdest zu deinem gesetzen Punkt teleportiert!");
    return 1;
}



CMD:delmark(playerid){
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    if(Spieler[playerid][pAMarkX] == 0)return SendClientMessage(playerid, COLOR_RED, "Es wurde kein gesetzter Punkt gefunden!");
    Spieler[playerid][pAMarkX] = 0;
    Spieler[playerid][pAMarkY] = 0;
    Spieler[playerid][pAMarkZ] = 0;
    RemovePlayerMapIcon(playerid, 75);
    SendClientMessage(playerid, COLOR_BLUE, "Dein gesetzter Punkt wurde gelöscht!");
    return 1;
}



CMD:waffeumgebung(playerid,params[]) {
    new waffeid, munition, Float:reichweite, string[128], Float:giveposx, Float:giveposy, Float:giveposz, Float:getposx, Float:getposy, Float:getposz, Float:distance;
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "iif", waffeid, munition, reichweite))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Waffeumgebung [WAFFE] [MUNITION] [REICHWEITE]");
    if (Spieler[playerid][pAdmin] < 5 && (waffeid == 38 || waffeid == 37 || waffeid == 36 || waffeid == 35 || waffeid == 45 || waffeid == 44 || waffeid == 40 || waffeid == 39 || waffeid == 26 || waffeid == 28)) return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Waffe nicht vergeben!");
    GetPlayerPos(playerid, giveposx, giveposy, giveposz);
	foreach(new i : Player){
	    if(IsPlayerConnected(i)) {
			GetPlayerPos(i, getposx, getposy, getposz);
			distance = GetDistance(giveposx, giveposy, giveposz, getposx, giveposy, giveposz);
			if(distance <= reichweite){
			    GivePlayerWeapon(i, waffeid, munition);
				format(string, sizeof(string), "Du hast %s (Munition: %i) von %s %s erhalten!", ReturnWeaponName(waffeid), munition, GetPlayerAdminRang(playerid), GetName(playerid));
				SendClientMessage(i, COLOR_BLUE, string);
			}
		}
	}
    format(string,sizeof(string),"%s %s gab %s (Munition: %i) an seine Spieler in der Umgebung!", GetPlayerAdminRang(playerid), GetName(playerid), ReturnWeaponName(waffeid), munition);
    SendAdminMessage(COLOR_YELLOW, string);
    return 1;
}



CMD:healumgebung(playerid,params[]) {
    new Float:reichweite, string[128], Float:giveposx, Float:giveposy, Float:giveposz, Float:getposx, Float:getposy, Float:getposz, Float:distance;
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "f", reichweite))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Healumgebung [REICHWEITE]");
    GetPlayerPos(playerid, giveposx, giveposy, giveposz);
	foreach(new i : Player){
	    if(IsPlayerConnected(i)) {
			GetPlayerPos(i, getposx, getposy, getposz);
			distance = GetDistance(giveposx, giveposy, giveposz, getposx, giveposy, giveposz);
			if(distance <= reichweite){
			    SetPlayerHealth(i, 100);
				format(string, sizeof(string), "Du hast 100HP von %s %s erhalten!", GetPlayerAdminRang(playerid), GetName(playerid));
				SendClientMessage(i, COLOR_BLUE, string);
			}
		}
	}
    format(string,sizeof(string),"%s %s gab 100HP an seine Spieler in der Umgebung!", GetPlayerAdminRang(playerid), GetName(playerid));
    SendAdminMessage(COLOR_YELLOW, string);
    return 1;
}



CMD:armorumgebung(playerid,params[]) {
    new Float:reichweite, string[128], Float:giveposx, Float:giveposy, Float:giveposz, Float:getposx, Float:getposy, Float:getposz, Float:distance;
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "f", reichweite))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Armorumgebung [REICHWEITE]");
    GetPlayerPos(playerid, giveposx, giveposy, giveposz);
	foreach(new i : Player){
	    if(IsPlayerConnected(i)) {
			GetPlayerPos(i, getposx, getposy, getposz);
			distance = GetDistance(giveposx, giveposy, giveposz, getposx, giveposy, giveposz);
			if(distance <= reichweite){
			    SetPlayerArmour(i, 100);
				format(string, sizeof(string), "Du hast 100AP von %s %s erhalten!", GetPlayerAdminRang(playerid), GetName(playerid));
				SendClientMessage(i, COLOR_BLUE, string);
			}
		}
	}
    format(string,sizeof(string),"%s %s gab 100AP an seine Spieler in der Umgebung!", GetPlayerAdminRang(playerid), GetName(playerid));
    SendAdminMessage(COLOR_YELLOW, string);
    return 1;
}



CMD:freezeumgebung(playerid,params[]) {
    new Float:reichweite, string[128], Float:giveposx, Float:giveposy, Float:giveposz, Float:getposx, Float:getposy, Float:getposz, Float:distance;
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "f", reichweite))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Freezeumgebung [REICHWEITE]");
    GetPlayerPos(playerid, giveposx, giveposy, giveposz);
	foreach(new i : Player){
	    if(IsPlayerConnected(i)) {
			GetPlayerPos(i, getposx, getposy, getposz);
			distance = GetDistance(giveposx, giveposy, giveposz, getposx, giveposy, giveposz);
			if(distance <= reichweite){
			    FreezePlayer(i);
				format(string, sizeof(string), "Du wurdest von %s %s gefreezt!", GetPlayerAdminRang(playerid), GetName(playerid));
				SendClientMessage(i, COLOR_BLUE, string);
			}
		}
	}
    format(string,sizeof(string),"%s %s freezte all seine Spieler in der Umgebung!", GetPlayerAdminRang(playerid), GetName(playerid));
    SendAdminMessage(COLOR_YELLOW, string);
    return 1;
}



CMD:unfreezeumgebung(playerid,params[]) {
    new Float:reichweite, string[128], Float:giveposx, Float:giveposy, Float:giveposz, Float:getposx, Float:getposy, Float:getposz, Float:distance;
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "f", reichweite))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Unfreezeumgebung [REICHWEITE]");
    GetPlayerPos(playerid, giveposx, giveposy, giveposz);
	foreach(new i : Player){
	    if(IsPlayerConnected(i)) {
			GetPlayerPos(i, getposx, getposy, getposz);
			distance = GetDistance(giveposx, giveposy, giveposz, getposx, giveposy, giveposz);
			if(distance <= reichweite){
			    UnfreezePlayer(i);
				format(string, sizeof(string), "Du wurdest von %s %s ungefreezt!", GetPlayerAdminRang(playerid), GetName(playerid));
				SendClientMessage(i, COLOR_BLUE, string);
			}
		}
	}
    format(string,sizeof(string),"%s %s unfreezte all seine Spieler in der Umgebung!", GetPlayerAdminRang(playerid), GetName(playerid));
    SendAdminMessage(COLOR_YELLOW, string);
    return 1;
}



CMD:veh(playerid, params[]) {
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    new vID, color1 = 3, color2 = 3, Float:x, Float:y, Float:z, Float:angle, vehName[32];
    if(sscanf(params, "iI(3)I(3)", vID, color1, color2)) {
        if (sscanf(params, "s[32]", vehName))
            return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Veh [Vehicle ID/Name] optional:[[Color 1] [Color 2]]");

        for (new j = 0; j < sizeof(CarName); j++) {
            if (strfind(CarName[j], vehName, true, 0) == 0) {
                vID = 400 + j;
                break;
            }
        }
        if (!vID) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Veh [Vehicle ID/Name]");
    }
    if (!IsValidVehicleModelID(vID)) return SendClientMessage(playerid, COLOR_RED, "Ungültige Fahrzeug Model-ID.");
    if(IsPlayerInAnyVehicle(playerid))return SendClientMessage(playerid, COLOR_RED, "Du darfst in keinem Fahrzeug sitzen!");
    GetPlayerFacingAngle(playerid, angle);
    GetPlayerPos(playerid, x,y,z);
    new vehicle;
    vehicle = CreateVehicle(vID, x,y,z, angle, color1, color2, -1);
    SetVehicleNumberPlate(vehicle, ""COLOR_HEX_BLACK"ADMIN");
    SetVehicleVirtualWorld(vehicle, GetPlayerVirtualWorld(playerid));
    LinkVehicleToInterior(vehicle, GetPlayerInterior(playerid));
    PutPlayerInVehicle(playerid, vehicle, 0);
    gGas[vehicle] = GetMaxTank(vehicle);
    gMaxGas[vehicle] = GetMaxTank(vehicle);
    aiVehicles[ vehicle ] = VEH_CAR;
    new string[128];
    format(string, sizeof(string), "%s %s hat ein Fahrzeug gespawnt (%s [%d])", GetPlayerAdminRang(playerid), GetName(playerid), CarName[vID - 400], vID);
    SendAdminMessage(COLOR_BLUE, string);
    return 1;
}


CMD:spawnall(playerid,params[]) {
    new string[128];
    if(Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
    foreach(new i : Player) {
        if(Spieler[i][pTot] == 1) {
            Spieler[i][pTot] = 0;
            Spieler[i][pTotTime] = 0;
        }
        SpawnPlayerEx(i);
        SCMFormatted(i, COLOR_LIGHTGREY, "Du wurdest von %s %s gespawnt!", GetPlayerAdminRang(playerid), GetName(playerid));
    }
    format(string, sizeof(string), "* %s %s hat alle Spieler gespawnt.", GetPlayerAdminRang(playerid), GetName(playerid));
    SendAdminMessage(COLOR_YELLOW, string);
    return 1;
}



CMD:givegun(playerid, params[])
{
    new pID, wID, ammo, string[128];
    if(Spieler[playerid][pAdmin] < 2)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "uii", pID, wID, ammo))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Givegun [Spieler/Name] [Waffen-ID] [Munition]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (Spieler[playerid][pAdmin] < 5 && (wID == 38 || wID == 37 || wID == 36 || wID == 35 || wID == 45 || wID == 44 || wID == 40 || wID == 39 || wID == 26 || wID == 28)) return SendClientMessage(playerid, COLOR_DARKRED, "Dein Rang erlaubt es dir nicht, dem Spieler diese Waffe zu geben.");
    if (Spieler[playerid][pAdmin] > 5) {
        format(string, sizeof(string), "%s %s hat dem Spieler %s eine %s gegeben. (ID: %d, Munition: %d)", GetPlayerAdminRang(playerid), GetName(playerid), GetName(pID), ReturnWeaponName(wID), wID, ammo);
        SendAdminMessage(COLOR_ORANGE, string);
    }
    format(string, sizeof(string), "Du hast von %s %s eine Waffe erhalten. (ID: %d, Munition: %d)", GetPlayerAdminRang(playerid), GetName(playerid), wID, ammo);
    SendClientMessage(pID, COLOR_YELLOW, string);
    format(string, sizeof(string), "Du hast dem Spieler %s eine Waffe gegeben. (ID: %d, Munition: %d)", GetName(pID), wID, ammo);
    SendClientMessage(playerid, COLOR_YELLOW, string);
    GivePlayerWeapon(pID, wID, ammo);
    if( GetPlayerState(pID) == PLAYER_STATE_PASSENGER ) {
        if( wID == 29 || wID == 31 ) {
            SetPlayerArmedWeapon(pID,wID);
        }
        else {
            SetPlayerArmedWeapon(pID,0);
        }
    }
    return 1;
}



CMD:gotocp(playerid, params[]) return cmd_gotomarker(playerid, params);
new markertimer[MAX_PLAYERS];
CMD:gotomarker(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 2) return ERROR_RANG_MSG(playerid);
    markertimer[playerid] = SetTimerEx("triggergotopos", 500, false, "i", playerid);
    /*if (!GetPVarFloat(playerid, "MARKER.X")) return SendClientMessage(playerid, COLOR_DARKRED, "Du hast keinen Checkpoint auf der Karte.");
    format(params, 128, "%f %f %f", GetPVarFloat(playerid, "MARKER.X"), GetPVarFloat(playerid, "MARKER.Y"), GetPVarFloat(playerid, "MARKER.Z"));
    return cmd_gotopos(playerid, params);*/
    return 1;
}
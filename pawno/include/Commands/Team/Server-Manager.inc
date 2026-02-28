#include <YSI\y_hooks>


CMD:vehcolor(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 5) return ERROR_RANG_MSG(playerid);
    new color1, color2, vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if (!vehicleid) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du musst in einem Fahrzeug sitzen.");
    if (sscanf(params, "ii", color1, color2)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Vehcolor [Color 1] [Color 2]");
    
    ChangeVehicleColor(vehicleid, color1, color2);
    new owner = GetCarOwner(vehicleid);
    if (owner != INVALID_PLAYER_ID) {
        new slot = GetCarOwnerSlot(owner, vehicleid);
        if (slot != 555) {
            PlayerCar[owner][slot][CarC1] = color1;
            PlayerCar[owner][slot][CarC2] = color2;
        }
    }

    return SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Farben des Fahrzeugs geändert.");
}


CMD:animationdebug(playerid, params[]) {
	if (Spieler[playerid][pAdmin] < 5) return ERROR_RANG_MSG(playerid);

	new animlib[32], animname[32];
	if (sscanf(params, "s[32]s[32]", animlib, animname)) return SendClientMessage(playerid, COLOR_WHITE, "Usage: /debug [animlib] [animname]");

	LoopingAnim(playerid, animlib, animname, 4.0, 1, 0, 0, 0, 0);
	SendClientMessage(playerid, COLOR_WHITE, "{00FF00}>> {FFFFFF}Animation set.");
	return 1;
}


CMD:givepayday(playerid,params[])
{
    new pID;
    if(Spieler[playerid][pAdmin] < 5) return ERROR_RANG_MSG(playerid);
    if(sscanf(params,"u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/givepayday [SpielerID]");
    new string[200];
    format(string,200, "[PAYDAY]{FFFFFF} Du hast %s einen Payday gegeben.", GetName(pID));
    SendClientMessage(playerid, COLOR_ORANGE,string);
    Spieler[pID][pPayDay] = 60;
    UpdatePayDayTextdraw(pID);
    return 1;
}


CMD:debugpos(playerid, params[]) {
    if (Spieler[playerid][pAdmin] < 5) return ERROR_RANG_MSG(playerid);

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    return SCMFormatted(playerid, COLOR_WHITE, "Current Pos: %f %f %f", x, y, z);
}


CMD:startlotto(playerid, params[])
{
    new entry, string[128];
    if(sscanf(params, "i", entry))
    {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING" /Startlotto [Nummer]");
        return 1;
    }
    if(Spieler[playerid][pAdmin] < 5)return ERROR_RANG_MSG(playerid);
    if(entry < 1 || entry > 100)return SendClientMessage(playerid, COLOR_ORANGE, "Die Nummer sollte zwischen 1 und 100 sein.");
    format(string, sizeof(string), "** [LOTTO] >> %s hat die Losziehung manuell gestartet. Nummer: %d << **", GetName(playerid), entry);
    SendClientMessageToAll(COLOR_YELLOW, string);
    Lotto(entry);
    return 1;
}


CMD:gmx(playerid)
{
    if(Spieler[playerid][pAdmin] < 5)return ERROR_RANG_MSG(playerid);
    if(GMXMode == 1)
    {
        SendClientMessageToAll(COLOR_RED, "ACHTUNG! Der Server wird restartet, warte bitte einen Moment!");
        GMXMode = 0;
        KillTimer(gmxtimer);
        for(new i = 0 ; i < MAX_PLAYERS ; i++)
        {
            SpawnPlayerEx(i);
        }
    }
    else if(GMXMode == 0)
    {
        for(new i = 0 ; i < MAX_PLAYERS ; i++)
        {
            SetPlayerInterior(i, 0);
            SetPlayerVirtualWorld(i, 0);
            SetPlayerPos(i, 381.1510, -1881.4520, 3.7626);
            InterpolateCameraPos(i, 369.837097, -2046.207153, 7.430351, 370.996215, -1818.170532, 8.961493, 60000);
            InterpolateCameraLookAt(i, 370.090270, -2041.220214, 7.687465, 371.139587, -1813.225585, 9.687144, 60000);
            SendClientMessage(i, COLOR_RED, "Speichere Daten ... Es kann zu starken Lags kommen!");
        }
        CallLocalFunction("SaveAll", ""); // y_hooks
        GMXMode = 1;
        gmxtimer = SetTimer("GMXModeTimer", 10000, 1);
        SendAdminMessage(COLOR_YELLOW, "Der Server kann nun restartet werden!");
    }
    return 1;
}


CMD:createtanke(playerid, params[])
{
    new chName[32], Preis;
    if(sscanf(params, "is[32]", Preis, chName))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Createtanke [Preis] [Name]");
    if(Spieler[playerid][pAdmin] < 5)return ERROR_RANG_MSG(playerid);
    new query[512], Float:x, Float:y, Float:z;GetPlayerPos(playerid, x,y,z);
    format(query, sizeof(query), "INSERT INTO `tanken` (`ID`,`EnterX`, `EnterY`, `EnterZ`, `Besitzer`, `Name`, `FillCost`, `Kasse`, `Benzin`, `MaxBenzin`, `Preis`) VALUES (NULL,%.2f, %.2f, %.2f, '%s', '%s', %d, %d, %d, %d, %d)", x,y,z, "Niemand", chName, 50, 0, 0, 1000, Preis);
    mysql_pquery(query,THREAD_CREATETANKE,playerid,gSQL,MySQLThreadOwner);
    return 1;
}


CMD:createaplatz(playerid, params[])
{
    if(Spieler[playerid][pAdmin] < 5)return ERROR_RANG_MSG(playerid);
    new fische, query[256];
    if(sscanf(params, "i", fische))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Createaplatz [Fische]");
    if(fische < 0 || fische > 150)return SendClientMessage(playerid, COLOR_RED, "Die Anzahl sollte sich zwischen 0 und 150 befinden!");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    new Float:angle;
    GetPlayerFacingAngle(playerid, angle);
    //Create Platz
    format(query, sizeof(query), "INSERT INTO `angel` (`ID`,`PosX`, `PosY`, `PosZ`, `Fische`, `FacingAngle`) VALUES (NULL,%.2f, %.2f, %.2f, %d, %.2f)", x, y, z, fische, angle);
    mysql_pquery(query,THREAD_CREATEAPLATZ,playerid,gSQL,MySQLThreadOwner);
    // -> THREADED
    return 1;
}


CMD:event(playerid, params[])
{
    new eingabe[12], entry, string[128];
    if(Spieler[playerid][pAdmin] < 5)return ERROR_RANG_MSG(playerid);
    if(sscanf(params, "s[12]i", eingabe, entry))
    {
        SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Event [Typ] [Anzahl]");
        SendClientMessage(playerid, COLOR_ORANGE, "* Typen *: Respekt, Geld, Gehalt, Level");
        return 1;
    }
    if(strcmp(eingabe, "respekt", true) == 0)
    {
        if(entry < 1 || entry > 50)return SendClientMessage(playerid, COLOR_ORANGE, "Die Respektpunkte müssen zwischen RP1 und RP10 liegen.");
        for(new i = 0 ; i < MAX_PLAYERS ; i++)
        {
            if(IsPlayerConnected(i) && gPlayerLogged[i] == 1)
            {
                GivePlayerRP(i, entry);
            }
        }
        format(string, sizeof(string), COLOR_HEX_WHITE"Alle Spieler haben von "COLOR_HEX_ORANGE"%s "COLOR_HEX_GREEN"+%d "COLOR_HEX_WHITE"Respektpunkte erhalten.", GetName(playerid), entry);
        SendClientMessageToAll(COLOR_WHITE, string);
    }
    else if(strcmp(eingabe, "gehalt", true) == 0)
    {
        if(entry < 1 || entry > 100000)return SendClientMessage(playerid, COLOR_ORANGE, "Der Gehalt muss zwischen $1 und $100.000 liegen.");
        for(new i = 0 ; i < MAX_PLAYERS ; i++)
        {
            if(IsPlayerConnected(i) && gPlayerLogged[i] == 1)
            {
                Spieler[i][pPayCheck] += entry;
            }
        }
        format(string, sizeof(string), COLOR_HEX_WHITE"Alle Spieler haben von "COLOR_HEX_ORANGE"%s "COLOR_HEX_GREEN"$%s "COLOR_HEX_WHITE"für den nächsten Zahltag erhalten.", GetName(playerid), AddDelimiters(entry));
        SendClientMessageToAll(COLOR_WHITE, string);
    }
    else if(strcmp(eingabe, "geld", true) == 0)
    {
        if(entry < 1 || entry > 1000000)return SendClientMessage(playerid, COLOR_ORANGE, "Das Geld muss zwischen $1 und $1.000.000 liegen.");
        for(new i = 0 ; i < MAX_PLAYERS ; i++)
        {
            if(IsPlayerConnected(i) && gPlayerLogged[i] == 1)
            {
                GivePlayerCash(i, entry);
            }
        }
        format(string, sizeof(string), COLOR_HEX_WHITE"Alle Spieler haben von "COLOR_HEX_ORANGE"%s "COLOR_HEX_GREEN"$%s "COLOR_HEX_WHITE"erhalten.", GetName(playerid), AddDelimiters(entry));
        SendClientMessageToAll(COLOR_WHITE, string);
    }
    if(strcmp(eingabe, "level", true) == 0)
    {
        if(entry < 1 || entry > 3)return SendClientMessage(playerid, COLOR_ORANGE, "Es kann nur 1 bis 3 Levels verschenkt werden!");
        for(new i = 0 ; i < MAX_PLAYERS ; i++)
        {
            if(IsPlayerConnected(i) && gPlayerLogged[i] == 1)
            {
                Spieler[i][pLevel] += entry;
                SetPlayerScore(playerid, Spieler[i][pLevel]);
            }
        }
        format(string, sizeof(string), COLOR_HEX_WHITE"Alle Spieler haben von "COLOR_HEX_ORANGE"%s "COLOR_HEX_GREEN"+%d "COLOR_HEX_WHITE"Level-Up erhalten.", GetName(playerid), entry);
        SendClientMessageToAll(COLOR_WHITE, string);
    }
    return 1;
}



CMD:amaske(playerid) return cmd_adminmaske(playerid);
CMD:adminmaske(playerid) {
    if (Spieler[playerid][pAdmin] < 5) return ERROR_RANG_MSG(playerid);
    new poolSize = GetPlayerPoolSize();
    Spieler[playerid][abMaske] = !Spieler[playerid][abMaske];
    if (!Spieler[playerid][abMaske]) {
        SetPlayerColor(playerid, GetPlayerColor(playerid) | 0xFF);
        for (new i; i <= poolSize; i++) ShowPlayerNameTagForPlayer(i, playerid, 1);
        return SendClientMessage(playerid, COLOR_ORANGE, "Du hast deine Maske abgenommen.");
    }

    SendClientMessage(playerid, COLOR_GREEN, "Du hast deine Maske aufgezogen.");
    SetPlayerColor(playerid, GetPlayerColor(playerid) & 0xFFFFFF00);
    for (new i; i < MAX_PLAYERS; i++)  ShowPlayerNameTagForPlayer(i, playerid, 0);
    return 1;
}


CMD:createhotelroom(playerid, params[])
{
    new chName[32], HotelType, Preis;
    if(sscanf(params, "iis[32]", HotelType, Preis, chName))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Createhotelroom [Hotel-Typ] [MietPreis] [Name]");
    if(Spieler[playerid][pAdmin] < 5)return ERROR_RANG_MSG(playerid);
    new query[1024], Float:x, Float:y, Float:z, Float:iX, Float:iY, Float:iZ;
    GetPlayerPos(playerid, x, y, z);
    new interior;
    new enterinterior = GetPlayerInterior(playerid);
    new virtualworld = GetPlayerVirtualWorld(playerid);
    if(HotelType < 1 || HotelType > 11)return SendClientMessage(playerid, COLOR_RED, "Der Hotel-Typ muss zwischen 1 und 14 liegen.");
    else if(HotelType == 1)
    {
            interior = 3;
            iX = 235.508994;
            iY = 1189.169897;
            iZ = 1080.339966;
    }
    else if(HotelType == 2)
    {
            interior = 2;
            iX = 225.756989;
            iY = 1240.000000;
            iZ = 1082.149902;
    }
    else if(HotelType == 3)
    {
            interior = 1;
            iX = 223.043991;
            iY = 1289.259888;
            iZ = 1082.199951;
    }
    else if(HotelType == 4)
    {
            interior = 7;
            iX = 225.630997;
            iY = 1022.479980;
            iZ = 1084.069946;
    }
    else if(HotelType == 5)
    {
            interior = 15;
            iX = 295.138977;
            iY = 1474.469971;
            iZ = 1080.519897;
    }
    else if(HotelType == 6)
    {
            interior = 15;
            iX = 328.493988;
            iY = 1480.589966;
            iZ = 1084.449951;
    }
    else if(HotelType == 7)
    {
            interior = 15;
            iX = 385.803986;
            iY = 1471.769897;
            iZ = 1080.209961;
    }
    else if(HotelType == 8)
    {
            interior = 1;
            iX = 244.411987;
            iY = 305.032989;
            iZ = 999.148437;
    }
    else if(HotelType == 9)
    {
            interior = 5;
            iX = 2233.7566;
            iY = -1114.8241;
            iZ = 1050.8828;
    }
    else if(HotelType == 10)
    {
            interior = 2;
            iX = 2468.0276;
            iY = -1698.2456;
            iZ = 1013.5078;
    }
    else if(HotelType == 11)
    {
            interior = 12;
            iX = 2324.419921;
            iY = -1145.568359;
            iZ = 1050.710083;
    }

    format(query, sizeof(query), "INSERT INTO `hotel` (`ID`,`EnterX`, `EnterY`, `EnterZ`, `ExitX`, `ExitY`, `ExitZ`, `Besitzer`, `Name`, `Lock`, `MietPreis`, `EnterInterior`, `ExitInterior`,`EnterVirtualWorld`) VALUES (NULL,%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, '%s', '%s', %d, %d, %d , %d , %d )", x,y,z, iX, iY, iZ,  "Niemand", chName, 1, Preis, enterinterior , interior,virtualworld);
    mysql_pquery(query,THREAD_CREATEHOTEL,playerid,gSQL,MySQLThreadOwner);
    return 1;
}



CMD:getobjects(playerid, params[]) return SCMFormatted(playerid, COLOR_RED, "Es sind %i Dynamische Objekte erstellt!", CountDynamicObjects());

CMD:countobjects(playerid, params[]){
    for(new i = 0; i < 10000; i++){
        new string[128];
 		new Float:xo, Float:yo, Float:zo;
		GetObjectPos(i, xo, yo, zo);
		if(xo!=0 && yo!=0 && zo!=0){
			format(string, sizeof(string), "ID:%dCreateObject(%f,%f,%f);",i,xo,yo,zo);
			SendClientMessage(playerid, COLOR_BLUE, string);
		}
    }
    SendClientMessage(playerid, COLOR_RED, "ENDE");
    return 1;
}



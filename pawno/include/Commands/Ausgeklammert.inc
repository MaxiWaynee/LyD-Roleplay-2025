#include <YSI\y_hooks>


/*
CMD:fpreis(playerid,params[]) {
    if( Spieler[playerid][pFraktion] != 8 ) {
        return SendClientMessage(playerid, COLOR_RED, "Dieser Befehl ist nur für Fahrlehrer");
    }
    new
        giveid,
        modus = 0,
        pruefung[16];
    if(sscanf(params,"us[16]",giveid,pruefung)) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/fpreis [ID] [Prüfung]");
    }
    if( isnull(pruefung)) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/fpreis [ID] [Prüfung]");
    }
    else if( !strcmp(pruefung,"autoschein",true)) {
        modus = 1;
        if(Spieler[giveid][pCarLic]!=0)
        {
            return SendClientMessage(playerid,COLOR_RED,"Der Spieler besitzt bereits diesen Schein.");
        }
        if(Spieler[giveid][punixFSperre]!=0)
        {
            return SendClientMessage(playerid,COLOR_RED,"Der Spieler hat eine gültige Scheinsperre auf dem Schein.");
        }
    }
    else if( !strcmp(pruefung,"motorradschein",true)) {
        modus = 2;
        if(Spieler[giveid][pMotoLic]!=0)
        {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler besitzt bereits diesen Schein");
        }
        if(Spieler[giveid][punixMotoSperre]!=0)
        {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler hat eine gültige Scheinsperre auf dem Schein");
        }
    }
    else if( !strcmp(pruefung,"flugschein",true)) {
        modus = 3;
        if(Spieler[giveid][pFlyLic]!=0)
        {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler besitzt bereits diesen Schein");
        }
        if(Spieler[giveid][punixFlSperre]!=0)
        {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler hat eine gültige Scheinsperre auf dem Schein");
        }
    }
    else if( !strcmp(pruefung,"bootsschein",true)) {
        modus = 4;
        if(Spieler[giveid][pBoatLic]!=0)
        {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler besitzt bereits diesen Schein");
        }
    }
    else if( !strcmp(pruefung,"lkwschein",true)) {
        modus = 5;
        if(Spieler[giveid][pLKWLic]!=0)
        {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler besitzt bereits diesen Schein");
        }
        if(Spieler[giveid][punixLKWSperre]!=0)
        {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler hat eine gültige Scheinsperre auf dem Schein");
        }
    }
    else if( !strcmp(pruefung,"awaffenschein",true)) {
        modus = 6;
        if(Spieler[giveid][pGunLic]!=0)
        {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler besitzt bereits diesen Schein");
        }
        if(Spieler[giveid][punixGunSperre]!=0)
        {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler hat eine gültige Scheinsperre auf dem Schein");
        }
    }
    else if( !strcmp(pruefung,"bwaffenschein",true)) {
        modus = 7;
        if(Spieler[giveid][pGunLicB]!=0)
        {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler besitzt bereits diesen Schein");
        }
        if(Spieler[giveid][punixGunSperre]!=0)
        {
            return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler hat eine gültige Scheinsperre auf dem Schein");
        }
    }
    if(!modus) {
        SendClientMessage(playerid, COLOR_RED,INFO_STRING"/fpreis [ID] [Prüfung]");
        SendClientMessage(playerid, COLOR_RED, "Autoschein - 8.000$");
        SendClientMessage(playerid, COLOR_RED, "Motorradschein - 11.000$");
        SendClientMessage(playerid, COLOR_RED, "Flugschein - 50.000$");
        SendClientMessage(playerid, COLOR_RED, "Bootsschein - 17.000$");
        SendClientMessage(playerid, COLOR_RED, "Lkwschein - 22.000$");
        SendClientMessage(playerid, COLOR_RED, "Awaffenschein - 65.000$");
        SendClientMessage(playerid, COLOR_RED, "Bwaffenschein - 85.000$");
        return 1;
    }
    if(!IsPlayerConnected(giveid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( giveid == playerid ) return SendClientMessage(playerid, COLOR_RED, "Diese Aktion ist nicht möglich.");
    new
        Float:x,
        Float:y,
        Float:z;
    GetPlayerPos(playerid,x,y,z);
    if( !IsPlayerInRangeOfPoint(giveid,5.0,x,y,z)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner nähe");
    }
    new
        String[128];
    format(String,sizeof(String),"{FFFFFF}Fahrlehrer: %s\nBetrag: $%s\nPrüfung: %s",GetName(playerid), AddDelimiters(g_FahrPruefung[modus][FP_iPrice]),g_FahrPruefung[modus][FP_sName]);
    ShowPlayerDialog(giveid,DIALOG_FPREIS,DIALOG_STYLE_MSGBOX,"Fahrprüfung",String,"Annehmen","Ablehnen");
    Spieler[giveid][pFLehrer] = playerid;
    Spieler[giveid][pFModus] = modus;
    format(String,sizeof(String),"* Du hast %s ein Angebot zur Prüfung %s unterbreitet",GetName(giveid),g_FahrPruefung[modus][FP_sName]);
    SendClientMessage(playerid,COLOR_YELLOW,String);
    return 1;
}
*/


/*CMD:bk(playerid)
{
    if(Spieler[playerid][pDuty] == 0)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Dienst.");
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16))return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    new string[128];
    new ort[28];
    GetPlayer2DZone(playerid, ort, 28);
    new Rang[32];
    if(Spieler[playerid][pFraktion] == 1){Rang="Officer";}
    else if(Spieler[playerid][pFraktion] == 2){Rang="Agent";}
    format(string, sizeof(string), "HQ: %s %s (ID: %d) benötigt dringend Verstärkung in %s, over.", Rang, GetName(playerid), playerid, ort);
    SendClientMessage(playerid, COLOR_BLUE, "INFO: "COLOR_HEX_WHITE"Nach 30 Sekunden verschwindet der Marker automatisch für alle LSPD/FBI Mitglieder wieder.");
    SendFraktionMessage(1, COLOR_COP_VERST, string);
    SendFraktionMessage(2, COLOR_COP_VERST, string);
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    for(new i = 0 ; i < MAX_PLAYERS ; i++)
    {
        if(Spieler[i][pFraktion] == 1 || Spieler[i][pFraktion] == 2)
        {
            if(Spieler[i][pDuty] == 0)continue;
            if(i != playerid)
            {
                KillTimer(pBackupTimer[i]);
                SetPlayerCheckpointEx(i, x, y, z, 5.0, CP_BACKUP);
                pBackupTimer[i] = SetTimerEx("RemoveBackupCP", 30000, 0, "i", i);
            }
        }
    }
    return 1;
}*/



/*CMD:selltanke(playerid, params[])
{
    new
        tank_index,
        pTanke = Spieler[playerid][pTankKey];
    tank_index = GetTankIndexByID( Spieler[playerid][pTankKey] );
    if(pTanke == 999)return SendClientMessage(playerid, COLOR_RED, "Du besitzt garkeine Tanke.");
    if(strcmp(GetName(playerid), Tanke[tank_index][tBesitzer], true) == 0)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, Tanke[tank_index][EnterX], Tanke[tank_index][EnterY], Tanke[tank_index][EnterZ]))
        {
            new string[128];
            SendClientMessage(playerid, COLOR_GREEN, "Du hast deine Tankstelle verkauft.");
            format(string, sizeof(string), "Du hast die Hälfte des Grundpreises deiner Tankstelle erhalten. ($%d)", Tanke[tank_index][tPreis]);
            SendClientMessage(playerid, COLOR_GREEN, string);
            format(Tanke[tank_index][tBesitzer], MAX_PLAYER_NAME, "Niemand");
            Spieler[tank_index][pTankKey] = 999;
            GivePlayerCash(playerid, Tanke[tank_index][tKasse]);
            Tanke[tank_index][tKasse] = 0;
            Tanke[tank_index][tVideoueberwachung] = false;
            Tanke[tank_index][tAutomatischerNotruf] = false;
            GivePlayerCash(playerid, Tanke[tank_index][tPreis]/2);
            UpdateTankeText(tank_index);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du musst vor deiner Tankstelle stehen.");
            return 1;
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Die Tankstelle gehört dir nicht.");
        return 1;
    }
    return 1;
}

CMD:sellbiz(playerid, params[])
{
    new pBiz = Spieler[playerid][pBizKey];
    if(pBiz == 999)return SendClientMessage(playerid, COLOR_RED, "Du besitzt garkein Geschäft.");
    if(strcmp(GetName(playerid), Biz[pBiz][bBesitzer], true) == 0)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, Biz[pBiz][EnterX], Biz[pBiz][EnterY], Biz[pBiz][EnterZ]))
        {
            new string[128];
            SendClientMessage(playerid, COLOR_GREEN, "Du hast dein Geschäft verkauft.");
            format(string, sizeof(string), "Du hast die Hälfte des Grundpreises deines Geschäftes erhalten. ($%d)", Biz[pBiz][bPreis]/2);
            SendClientMessage(playerid, COLOR_GREEN, string);
            format(Biz[pBiz][bBesitzer], MAX_PLAYER_NAME, "Niemand");
            Biz[pBiz][bLock] = 1;
            Spieler[playerid][pBizKey] = 999;
            GivePlayerCash(playerid, Biz[pBiz][bKasse]);
            Biz[pBiz][bKasse] = 0;
            GivePlayerCash(playerid, Biz[pBiz][bPreis]/2);
            UpdateBizText(pBiz);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du musst vor deinem Geschäft stehen.");
            return 1;
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Das Geschäft gehört dir nicht!");
        return 1;
    }
    return 1;
}*/

/*CMD:hausabgeben(playerid, params[])
{
    new pHouse = Spieler[playerid][pHouseKey];
    new house_index = GetHouseIndexByID( pHouse );
    if(pHouse == 999)return SendClientMessage(playerid, COLOR_RED, "Du besitzt garkein Haus.");
    if(strcmp(GetName(playerid), Haus[house_index][hBesitzer], true) == 0)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, Haus[house_index][EnterX], Haus[house_index][EnterY], Haus[house_index][EnterZ]))
        {
            new string[128];
            SendClientMessage(playerid, COLOR_GREEN, "Du hast dein Haus verkauft und lebst nun wieder auf der Straße.");
            format(string, sizeof(string), "Du hast ein Drittel des Grundpreises deines Hauses erhalten. ($%d)", Haus[house_index][hPreis]);
            format(Haus[house_index][hBesitzer], MAX_PLAYER_NAME, "Niemand");
            Haus[house_index][hMieten] = 0;
            Haus[house_index][hLock] = 1;
            GivePlayerCash(playerid, Haus[house_index][hKasse]);
            Haus[house_index][hKasse] = 0;
            GivePlayerCash(playerid, Haus[house_index][hPreis]/3);
            Spieler[playerid][pSpawnChange] = 0;
            new hStr[128];
            format(hStr, sizeof(hStr), "Dieses Haus ist zu verkaufen\n\nBeschreibung: %s\nPreis: %d$\nZum kaufen tippe /Hauskaufen ein", Haus[house_index][hName], Haus[house_index][hPreis]);
            UpdateHouseText(house_index);
            new query[256];

            CreateHouseSellObject(house_index);
            format(query, sizeof(query), "UPDATE `accounts` SET \
            `UpgradeWaffenlager` = '0',\
            `UpgradeSafebox` = '0',\
            `HausWaffenlager` = '0',\
            `HausSafeboxSpice` = '0',\
            `HausSafeboxDrogen` = '0' \
            WHERE `HouseMieteKey` = %d", Spieler[playerid][pHouseKey] );
            mysql_pquery(query,THREAD_SELLHOUSE,playerid,gSQL,MySQLThreadOwner);
            Spieler[playerid][pHouseMieteKey] = 999;
            SendClientMessage(playerid, COLOR_LIGHTBLUE, "Alle Mieter aus deinem Haus wurden rausgeworfen!");
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du musst vor deinem Haus stehen.");
            return 1;
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Du bist nicht der Besitzer, kannst aber /Hausentmieten eingeben sofern du eingemietet bist.");
        return 1;
    }
    return 1;
}*/



/*CMD:innenraum(playerid, params[])
{
    new iID, string[128];
    if(sscanf(params, "i", iID))
    {
        SendClientMessage(playerid, COLOR_GREY, "* Benutze /innenraum [ID(1-11)]");
        SendClientMessage(playerid, COLOR_GREY, "Im Forum findest du eine detaillierte Liste aller verfügbaren Innenräume.");
        SendClientMessage(playerid, COLOR_GREY, "Wenn du eine falsche ID aussuchst, wird dir kein Geld erstattet!");
        return 1;
    }
    new h = IsPlayerAtHouse(playerid);
    if(h == 999)return SendClientMessage(playerid, COLOR_GREY, "Du bist nicht in der Nähe eines Hauses.");
    if(iID < 1 || iID > 11)return SendClientMessage(playerid, COLOR_GREY, "Du kannst nur Innenraum-IDs zwischen 1 und 11 auswählen.");
    if(strcmp(GetName(playerid), Haus[h][hBesitzer], true) == 0)
    {
        new interior, Float:iX, Float:iY, Float:iZ, typ[32];
        if(iID == 1)
        {
            interior = 3;
            iX = 235.508994;
            iY = 1189.169897;
            iZ = 1080.339966;
            typ = "Großes Haus";
        }
        else if(iID == 2)
        {
            interior = 2;
            iX = 225.756989;
            iY = 1240.000000;
            iZ = 1082.149902;
            typ ="Mittleres Haus";
        }
        else if(iID == 3)
        {
            interior = 1;
            iX = 223.043991;
            iY = 1289.259888;
            iZ = 1082.199951;
            typ = "Kleines Haus";
        }
        else if(iID == 4)
        {
            interior = 7;
            iX = 225.630997;
            iY = 1022.479980;
            iZ = 1084.069946;
            typ = "Großes Haus";
        }
        else if(iID == 5)
        {
            interior = 15;
            iX = 295.138977;
            iY = 1474.469971;
            iZ = 1080.519897;
            typ = "Mittleres Haus";
        }
        else if(iID == 6)
        {
            interior = 15;
            iX = 328.493988;
            iY = 1480.589966;
            iZ = 1084.449951;
            typ = "Mittleres Haus";
        }
        else if(iID == 7)
        {
            interior = 15;
            iX = 385.803986;
            iY = 1471.769897;
            iZ = 1080.209961;
            typ = "Kleines Haus";
        }
        else if(iID == 8)
        {
            interior = 1;
            iX = 244.411987;
            iY = 305.032989;
            iZ = 999.148437;
            typ = "Kleines Haus";
        }
        else if(iID == 9)
        {
            interior = 2;
            iX = 266.8322;
            iY = 304.8475;
            iZ = 999.1484;
            typ = "Kleines Haus";
        }
        else if(iID == 10)
        {
            interior = 2;
            iX = 2468.0276;
            iY = -1698.2456;
            iZ = 1013.5078;
            typ = "Mittleres Haus";
        }
        else if(iID == 11)
        {
            interior = 12;
            iX = 2324.419921;
            iY = -1145.568359;
            iZ = 1050.710083;
            typ = "Großes Haus";
        }
        Haus[h][ExitX] = iX;
        Haus[h][ExitY] = iY;
        Haus[h][ExitZ] = iZ;
        Haus[h][hInterior] = interior;
        format(string, sizeof(string), "Du hast deinen Innenraum gewechselt. (ID: %d - Typ: %s)", iID, typ);
        SendClientMessage(playerid, COLOR_WHITE, string);
    }
    else
    {
        SendClientMessage(playerid, COLOR_GREY, "Du bist nicht der Besitzer dieses Hauses.");
        return 1;
    }
    return 1;
}*/

/*CMD:spawnchange(playerid)
{
    if(Spieler[playerid][pSpawnChange]== 0)
    {
        if(GetPlayerHouse(playerid) == 999 && Spieler[playerid][pPlayerHotel] == 999 ) return SendClientMessage(playerid, COLOR_RED, "Du bist in keinem Haus / Hotel eingemietet oder besitzt keins.");
        if(GetPlayerHouse(playerid) != 999 ) {
            SendClientMessage(playerid, COLOR_GREEN, "Du hast deinen Spawn auf dein Haus verlegt.");
        }
        else if(Spieler[playerid][pPlayerHotel] != 999 ) {
            SendClientMessage(playerid, COLOR_GREEN, "Du hast deinen Spawn auf dein Hotelzimer verlegt.");
        }
        Spieler[playerid][pSpawnChange] = 1;
    }
    else if(Spieler[playerid][pSpawnChange] == 1)
    {
        Spieler[playerid][pSpawnChange] = 0;
        SendClientMessage(playerid, COLOR_GREEN, "Du hast deinen Spawn auf den Fraktions bzw. Zivi-Spawn geändert.");
    }
    return 1;
}*/


/*CMD:entmieten(playerid)
{
    if(pCar[playerid] == INVALID_VEHICLE_ID)return SendClientMessage(playerid, COLOR_WHITE, "Du hast kein Fahrzeug gemietet.");
    SendClientMessage(playerid, COLOR_GREEN, "Du hast dein Mietfahrzeug wieder abgegeben.");
    DestroyVehicleEx(pCar[playerid]);
    aiVehicles[ pCar[playerid] ] = VEH_INVALID;
    pCar[playerid] = INVALID_VEHICLE_ID;
    return 1;
}*/


/*CMD:givewanted(playerid, params[])
{
    new pID, wanteds, string[128], reason[64];
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16))return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    if(sscanf(params, "uis[64]", pID, wanteds, reason))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Givewanted [SpielerID/Name] [Wanteds] [Grund]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(wanteds < 1 || wanteds > 200)return SendClientMessage(playerid, COLOR_RED, "Du kannst nicht mehr als 200 Wanteds aufeinmal vergeben!");
    // if(Spieler[pID][pFraktion] == 1 || Spieler[pID][pFraktion] == 2)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Wanteds an Beamte vergeben.");
    Spieler[pID][pWanteds] += wanteds;
    format(string, sizeof(string), "Du hast ein Verbrechen begangen. (%s) Reporter: Polizeibeamter %s", reason, GetName(playerid));
    SendClientMessage(pID, COLOR_DARKRED, string);
    format(string, sizeof(string), "Du hast %i Wanteds erhalten!", wanteds);
    SendClientMessage(pID, COLOR_DARKRED, string);
    format(string, sizeof(string), "Dein Aktuelles Wanted Level: %d", Spieler[pID][pWanteds]);
    SendClientMessage(pID, COLOR_YELLOW, string);
    format(string, sizeof(string), "HQ: %s (ID: %d) hat ein Verbrechen begangen: %s, over.", GetName(pID), pID, reason, GetName(playerid));
    SendFraktionMessage(1, COLOR_COP_MELDUNG, string);
    SendFraktionMessage(2, COLOR_COP_MELDUNG, string);
    SendFraktionMessage(16, COLOR_COP_MELDUNG, string);
    SendFraktionMessage(18, COLOR_COP_MELDUNG, string);
    format(string, sizeof(string), "HQ: Reporter: Polizeibeamter %s, Aktuelles Wantedlevel: %d, over.", GetName(playerid), Spieler[pID][pWanteds]);
    SendFraktionMessage(1, COLOR_COP_MELDUNG, string);
    SendFraktionMessage(2, COLOR_COP_MELDUNG, string);
    SendFraktionMessage(16, COLOR_COP_MELDUNG, string);
    SendFraktionMessage(18, COLOR_COP_MELDUNG, string);
    return 1;
}*/


/*
CMD:terrorwaffen(playerid)
{
    if(HasWeaponBlock(playerid)) {
        SendClientMessage(playerid,COLOR_RED,"Du kannst diesen Befehl nicht ausführen");
        return SendWeaponBlockInfo(playerid);
    }
    if(IsPlayerInRangeOfPoint(playerid, 2.0, g_fraktion[19][Fr_WaffenX],g_fraktion[19][Fr_WaffenY],g_fraktion[19][Fr_WaffenZ]))//Terroristen
    {
        if(Spieler[playerid][pGunLic] == 0)return SendClientMessage(playerid, COLOR_RED, "Du besitzt keinen Waffenschein.");
        if(CheckMoney(playerid) < 7500)return SendClientMessage(playerid, COLOR_RED, "Du benötigst $7500.");
        if(!(Spieler[playerid][pFraktion] == 19))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Terrorist.");
        GiveTerrorWeapons(playerid);
        SendClientMessage(playerid, COLOR_GREEN, "Du hast dich ausgeruestet. (Desert Eagle, Uzi & AK-47)");
        GameTextForPlayer(playerid, "~r~-$7500", 2000, 1);
        GivePlayerCash(playerid, -7500);
    }
    return 1;
}

stock GiveTerrorWeapons(playerid)
{
    GivePlayerWeapon(playerid, 24, 100);
    GivePlayerWeapon(playerid, 28, 200);
    GivePlayerWeapon(playerid, 30, 250);
    SendClientMessage(playerid, COLOR_GREEN, "Du hast dich ausgeruestet. (Desert Eagle, Uzi & AK-47)");
    GameTextForPlayer(playerid, "~r~-$5000", 2000, 1);
    GivePlayerCash(playerid, -5000);
    return 1;
}
*/


/*CMD:frachtladen(playerid)
{
    if(Spieler[playerid][pJob] == 11)
    if(IsPlayerInRangeOfPoint(playerid, 5.0, BOATCARGOJOB_LOADGARGO_POINT))
    {
       SendClientMessage(playerid, COLOR_YELLOW, "Du hast die Fracht aufs Schiff geholt! Fahre LV-Hafen");
    }
    return 1;
}

CMD:frachtentladen(playerid)
{
    if(Spieler[playerid][pJob] == 11)
    if(IsPlayerInRangeOfPoint(playerid, 5.0, BOATCARGOJOB_UNLOADCARGO_POINT))
    {
       SendClientMessage(playerid, COLOR_YELLOW, "Du hast die Fracht vom Schiff abgeladen! Fahre wieder zurück!");
    }
    return 1;
}*/


/*CMD:adventskalender(playerid)
{
    if(!(Spieler[playerid][pLevel] > 2))return SendClientMessage(playerid, COLOR_RED, "Du musst Level 3 sein!");
    {
        SendClientMessage(playerid,COLOR_GREEN,"Du hast dich erfolgreich für die Zufallswahl des heutigen Adventstürchen eingetragen!");
        SendClientMessage(playerid,COLOR_GREEN,"Um 21:00 Uhr entscheidet unser System nach Zufall, wer das Geschenk hinter dem heutigen Adventstürchen erhält.");
        SendClientMessage(playerid,COLOR_ORANGE,"HINWEIS: Es bringt nichts sich mehrmals für das heutige Adventstürchen einzutragen.");
        SendClientMessage(playerid,COLOR_RED,"> Wer sich mehrmals versucht für das heutige Adventstürchen einzutragen, wird aus der Zufallswahl ausgeschlossen!");
        new adventslogstring[128];
        format(adventslogstring, sizeof(adventslogstring), "Name: %s", GetName(playerid));
        LogAdvents(adventslogstring);
    }
    return 1;
}*/



/*CMD:respawnanhanger(playerid)
{
    new string[128];
	if(Spieler[playerid][pFraktion] == 8)
    {
        if(FrakCarInfo[i][f_frak] != Spieler[playerid][pFraktion]) continue;
		if(!IsVehicleOccupied(i)){
		    if(!GetTowedCar(i)){
				SetVehicleToRespawn(i);
			}
		}
        format(string, sizeof(string), "* Die Fahrschul Anhänger wurden von %s respawnt.", GetName(playerid));
        SendFraktionMessage(8, COLOR_DARKRED, string);
        return 1;
    }
    return 1;
}*/



/*
CMD:autofasas(playerid)
{
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, 1378.3748,-1643.1202,13.5469))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe der Automatischen Fahrschule.");
    if(pMakeTutorial[playerid] == 0)return SendClientMessage(playerid, COLOR_RED, "Nur für Spieler im Tutorial verfügbar.");
    if(pFahrschulCar[playerid] != INVALID_VEHICLE_ID)return SendClientMessage(playerid, COLOR_RED, "Du hast bereits ein Fahrschul-Auto erstellen lassen!");
    pFahrschulCar[playerid] = CreateVehicle(405, 1370.7351,-1634.2760,12.9573,180.6515,1,1,-1);
    aiVehicles[ pFahrschulCar[playerid] ] = VEH_FAHRSCHULCAR;
    SetPlayerCheckpointEx(playerid, 1418.3213,-1648.3510,13.2559,5.0,CP_FAHRSCHULE1);
    SendClientMessage(playerid, COLOR_SAMP, "Fahre nun die Strecke ab. Achte dabei auf folgende Dinge!");
    SendClientMessage(playerid, COLOR_SAMP, "Innerorts maximal 80 km/h. Außerorts maximal 120 km/h.");
    SendClientMessage(playerid, COLOR_SAMP, "Von 19 bis 6 Uhr muss das Licht angeschaltet sein.");
    SendClientMessage(playerid, COLOR_SAMP, "Viel Erfolg! PS: Steige nicht aus!");
    PutPlayerInVehicle(playerid, pFahrschulCar[playerid], 0);
    LockCar(pFahrschulCar[playerid]);
    gGas[pFahrschulCar[playerid]] = GetMaxTank(pFahrschulCar[playerid]);
    return 1;
}*/



/*
CMD:abgeben(playerid, params[]){
    new string[128], eingabe[24];
    if(sscanf(params, "s[24]", eingabe))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Abgeben [Drogen/Waffenteile/WCodes/Spice]");
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 1754.412963, -1592.894897, 13.532833)){
        if(strcmp(eingabe, "drogen", true) == 0){
            format(string, sizeof(string), "Bestätige bitte den Verkauf von %i Drogen für $%i.", Spieler[playerid][pDrugs], Spieler[playerid][pDrugs] * 300);
            ShowPlayerDialog(playerid, DIALOG_CONFIRM_DRUGS, DIALOG_STYLE_MSGBOX, "Verkauf von Drogen an den Server", string, "Bestätigen", "Abbrechen");
        }else if(strcmp(eingabe, "waffenteile", true) == 0){
            format(string, sizeof(string), "Bestätige bitte den Verkauf von %i Waffenteilen für $%i.", Spieler[playerid][pWaffenteile], Spieler[playerid][pWaffenteile] * 22);
            ShowPlayerDialog(playerid, DIALOG_CONFIRM_WT, DIALOG_STYLE_MSGBOX, "Verkauf von Waffenteilen an den Server", string, "Bestätigen", "Abbrechen");
        }else if(strcmp(eingabe, "wcodes", true) == 0){
            format(string, sizeof(string), "Bestätige bitte den Verkauf von %i Wantedcodes für $%i.", Spieler[playerid][pWantedCodes], Spieler[playerid][pWantedCodes] * 1502);
            ShowPlayerDialog(playerid, DIALOG_CONFIRM_WCODES, DIALOG_STYLE_MSGBOX, "Verkauf von Wantedcodes an den Server", string, "Bestätigen", "Abbrechen");
        }else if(strcmp(eingabe, "spice", true) == 0){
            format(string, sizeof(string), "Bestätige bitte den Verkauf von %i Spice für $%i.", Spieler[playerid][pSpice], Spieler[playerid][pSpice] * 700);
            ShowPlayerDialog(playerid, DIALOG_CONFIRM_SPICE, DIALOG_STYLE_MSGBOX, "Verkauf von Spice an den Server", string, "Bestätigen", "Abbrechen");
        }else{
            SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Fehlerhafte Eingabe!");
        }
    }
    return 1;
}*/

/*CMD:entnehmen(playerid, params[])
{
    new pID, string[128], eingabe[24];
    if(sscanf(params, "us[24]", pID, eingabe))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Entnehmen [SpielerID/Name] [Drogen/Waffenteile/Waffen/Codes/Spice/Samen/Krauter]");
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Beamter.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x,y,z);
    if(strcmp(eingabe, "drogen", true) == 0)
    {
        if(IsPlayerInRangeOfPoint(playerid, 4.0, x,y,z))
        {
            Spieler[pID][pDrugs] = 0;
            format(string, sizeof(string), "* Du hast die Drogen von %s abgenommen.", GetName(pID));
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
            format(string, sizeof(string), "* %s nahm die Drogen von %s ab.", GetName(playerid), GetName(pID));
            SendRoundMessage(x,y,z, COLOR_PURPLE, string);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
            return 1;
        }
    }
    else if(strcmp(eingabe, "waffenteile", true) == 0)
    {
        if(IsPlayerInRangeOfPoint(playerid, 4.0, x,y,z))
        {
            Spieler[pID][pWaffenteile] = 0;
            format(string, sizeof(string), "* Du hast die Waffenteile von %s abgenommen.", GetName(pID));
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
            format(string, sizeof(string), "* %s nahm die Waffenteile von %s ab.", GetName(playerid), GetName(pID));
            SendRoundMessage(x,y,z, COLOR_PURPLE, string);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
            return 1;
        }
    }
    else if(strcmp(eingabe, "waffen", true) == 0)
    {
        if(IsPlayerInRangeOfPoint(playerid, 4.0, x,y,z))
        {
            ResetPlayerWeapons(pID);
            format(string, sizeof(string), "* Du hast die Waffen von %s abgenommen.", GetName(pID));
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
            format(string, sizeof(string), "* %s nahm die Waffen von %s ab.", GetName(playerid), GetName(pID));
            SendRoundMessage(x,y,z, COLOR_PURPLE, string);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
            return 1;
        }
    }
    else if(strcmp(eingabe, "codes", true) == 0)
    {
        if(IsPlayerInRangeOfPoint(playerid, 4.0, x,y,z))
        {
            Spieler[pID][pWantedCodes] = 0;
            format(string, sizeof(string), "* Du hast die Hacker-Codes von %s abgenommen.", GetName(pID));
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
            format(string, sizeof(string), "* %s nahm die Wanted-Hacker Codes von %s ab.", GetName(playerid), GetName(pID));
            SendRoundMessage(x,y,z, COLOR_PURPLE, string);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
            return 1;
        }
    }
    else if(strcmp(eingabe, "spice", true) == 0)
    {
        if(IsPlayerInRangeOfPoint(playerid, 4.0, x,y,z))
        {
            Spieler[pID][pSpice] = 0;
            format(string, sizeof(string), "* Du hast die Spice-Drogen von %s abgenommen.", GetName(pID));
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
            format(string, sizeof(string), "* %s nahm die Spice-Drogen von %s ab.", GetName(playerid), GetName(pID));
            SendRoundMessage(x,y,z, COLOR_PURPLE, string);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
            return 1;
        }
    }
    else if(strcmp(eingabe, "samen", true) == 0)
    {
        if(IsPlayerInRangeOfPoint(playerid, 4.0, x,y,z))
        {
            Spieler[pID][pDrogenSamen] = 0;
            Spieler[pID][pGangDrogenSamen] = 0;
            format(string, sizeof(string), "* Du hast die Samen von %s abgenommen.", GetName(pID));
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
            format(string, sizeof(string), "* %s nahm die Samen von %s ab.", GetName(playerid), GetName(pID));
            SendRoundMessage(x,y,z, COLOR_PURPLE, string);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
            return 1;
        }
    }
    else if(strcmp(eingabe, "krauter", true) == 0)
    {
        if(IsPlayerInRangeOfPoint(playerid, 4.0, x,y,z))
        {
            Spieler[pID][pKrauterMische] = 0;
            format(string, sizeof(string), "* Du hast die Kräuter von %s abgenommen.", GetName(pID));
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
            format(string, sizeof(string), "* %s nahm die Kräuter von %s ab.", GetName(playerid), GetName(pID));
            SendRoundMessage(x,y,z, COLOR_PURPLE, string);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
            return 1;
        }
    }
    return 1;
}*/



/*
CMD:startstunde(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Startstunde [SpielerID/Name]");
    if(Spieler[playerid][pFraktion] != 8)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Fahrlehrer.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( playerid == pID ) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Du kannst die Prüfung nicht bei dir selbst starten!");
    }
    pFahrStunde[pID] = 1;
    format(string, sizeof(string), "* Fahrlehrer %s hat deine Fahrstunde gestartet. Befolge nun seinen Anweisungen!", GetName(playerid));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "* Du hast die Fahrstunde von %s gestartet. Gebe ihm/ihr nun Anweisungen!", GetName(pID));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    return 1;
}
CMD:startwastunde(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Startwastunde [SpielerID/Name]");
    if(Spieler[playerid][pFraktion] != 8)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Fahrlehrer.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pLevel] < 3)return SendClientMessage(playerid, COLOR_RED, "Der Spieler muss mindestens Level 3 erreicht haben!");
    if( playerid == pID ) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Du kannst die Prüfung nicht bei dir selbst starten!");
    }
    if( gettime() < Spieler[pID][punixGunSperre] ) {
        return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler besitzt eine Lizenzsperre!");
    }
    pFahrStunde[pID] = 1;
    format(string, sizeof(string), "* Fahrlehrer %s hat die Waffenschein Kl.A Prüfung gestartet. Befolge nun seinen/ihren Anweisungen!", GetName(playerid));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "* Du hast die Waffenschein Kl.A Prüfung von %s gestartet. Gebe ihm/ihr nun Anweisungen!", GetName(pID));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    GivePlayerWeapon(pID, 24, 29);
    return 1;
}
CMD:startwbstunde(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Startwbstunde [SpielerID/Name]");
    if(Spieler[playerid][pFraktion] != 8)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Fahrlehrer.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pLevel] < 6)return SendClientMessage(playerid, COLOR_RED, "Der Spieler muss mindestens Level 6 erreicht haben!");
    if( playerid == pID ) {
        return SendClientMessage(playerid,COLOR_LIGHTRED2,"Du kannst die Prüfung nicht bei dir selbst starten!");
    }
    if( gettime() < Spieler[pID][punixGunSperre] ) {
        return SendClientMessage(playerid,COLOR_YELLOW,"Der Spieler besitzt eine Lizenzsperre!");
    }
    pFahrStunde[pID] = 1;
    format(string, sizeof(string), "* Fahrlehrer %s hat die Waffenschein Kl.B Prüfung gestartet. Befolge nun seinen/ihren Anweisungen!", GetName(playerid));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "* Du hast die Waffenschein Kl.B Prüfung von %s gestartet. Gebe ihm/ihr nun Anweisungen!", GetName(pID));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    GivePlayerWeapon(pID, 31, 29);
    return 1;
}
CMD:stopstunde(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Stopstunde [SpielerID/Name]");
    if(Spieler[playerid][pFraktion] != 8)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Fahrlehrer.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    pFahrStunde[pID] = 0;
    if(IsPlayerInAnyVehicle(pID)){FreezePlayer(pID); UnfreezePlayer(pID); RemovePlayerFromVehicle(pID);}
    format(string, sizeof(string), "* Fahrlehrer %s hat deine Fahrstunde gestoppt.", GetName(playerid));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "* Du hast die Fahrstunde von %s gestoppt.", GetName(pID));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    return 1;
}
CMD:stopwastunde(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Stopwastunde [SpielerID/Name]");
    if(Spieler[playerid][pFraktion] != 8)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Fahrlehrer.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pLevel] < 3)return SendClientMessage(playerid, COLOR_RED, "Der Spieler muss mindestens Level 3 erreicht haben!");
    pFahrStunde[pID] = 0;
    format(string, sizeof(string), "* Fahrlehrer %s hat die Waffenschein Kl.A Prüfung gestoppt.", GetName(playerid));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "* Du hast die Waffenschein Kl.A Prüfung von %s gestoppt.", GetName(pID));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    ResetPlayerWeapons(pID);
    return 1;
}
CMD:stopwbstunde(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Stopwbstunde [SpielerID/Name]");
    if(Spieler[playerid][pFraktion] != 8)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Fahrlehrer.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[pID][pLevel] < 5)return SendClientMessage(playerid, COLOR_RED, "Der Spieler muss mindestens Level 5 erreicht haben!");
    pFahrStunde[pID] = 0;
    format(string, sizeof(string), "* Fahrlehrer %s hat die Waffenschein Kl.B Prüfung gestoppt.", GetName(playerid));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "* Du hast die Waffenschein Kl.B Prüfung von %s gestoppt.", GetName(pID));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    ResetPlayerWeapons(pID);
    return 1;
}
*/



/*CMD:setgwtime(playerid,params[]) {
    new
        index,
        zeit;
    if(sscanf(params,"dd",index,zeit)) {
        return SendClientMessage(playerid,COLOR_RED,"Idiot! /Setgwtime [index] [zeit]");
    }
    FightSystem[index][fsFightTime] = zeit;
    return 1;
}*/


/*CMD:robninedemons(playerid,params[]) {
	if (!(IsPlayerInRangeOfPoint(playerid, 2.0, NINEDEMONS_INTERIOR_SAFEBOX_ROBPOINT)))return SendClientMessage(playerid,COLOR_RED,"Du bist nicht an der NineDemons-Safebox Tür!");
	if(Spieler[playerid][pFraktion] == 15)return SendClientMessage(playerid,COLOR_RED,"Du kannst nicht als NineDemons-Mitglied deine Safebox ausrauben.");
	if (g_aSettings[ASETTING_ROBBLOCK][ASETTING_TOGGLE]) return SendClientMessage(playerid, COLOR_RED, "Zurzeit ist die Überfallsperre aktiviert.");
	if(g_fraktion[15][Fr_FSSpice] == 0)return SendClientMessage(playerid, COLOR_RED,"Die NineDemons haben kein Spice in der Safebox!");
	if(GetPVarInt(playerid, "ROB.NINEDEMONS")) return SendClientMessage(playerid, COLOR_RED, "Du raubst die Safebox der NineDemons bereits aus!");
	if( g_iNDRobStatus == Bankraub_Wartezeit ) {
        SendClientMessage(playerid, COLOR_RED, "Die Safebox kann zur Zeit nicht ausgeraubt werden.");
        return 1;
    }
    if( g_iNDRobStatus == Bankraub_Aktiv ) {
        SendClientMessage(playerid, COLOR_RED, "Die Safebox der NineDemons wird bereits ausgeraubt.");
        return 1;
    }
	if( !HasPlayerWeapon(playerid) ) {
        SendClientMessage(playerid, COLOR_RED, "Du kannst die Safebox nicht ohne eine Waffe ausrauben.");
        return 1;
    }
    if( GetOnlineND(playerid) < 1) {//3
        SendClientMessage(playerid, COLOR_RED, "Es sind nicht genug Spieler der NineDemons online.");
	    return 1;
	}
	new string[128];
	format(string,sizeof(string),"[SAFEBOX]: Achtung! %s raubt eure Fraktionssafebox aus! Geht hin und verteidigt die Safebox!",GetName(playerid));
	SendFraktionMessage(15,COLOR_RED,string);
	PlayerPlaySound(playerid,1058,0.0,0.0,0.0);
	SendClientMessage(playerid,COLOR_RED,"Du beginnst damit die NineDemons-Safebox auszurauben!");
	SendClientMessage(playerid,COLOR_RED,"Die Alarmanlage der NineDemons ist angegangen! Sie wurden informiert.");
	new Float:fX, Float:fY, Float:fZ;
 	GetDynamicObjectPos(object_nineDemonsInterior_door, fX, fY, fZ);
  	if (fX != NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_OPEN_Y && (ndInterior_pIDControllingDoor == playerid || ndInterior_pIDControllingDoor == INVALID_PLAYER_ID)) // door will be open
   	MoveDynamicObject(object_nineDemonsInterior_door, fX, NINEDEMONS_INTERIOR_SAFEBOX_ROOM_DOOR_OPEN_Y, fZ, 1.0);
   	g_tPulseRobPosition = SetTimerEx("NDRob_Position",1373,1,"d",playerid);
   	g_iNDRobStatus = Bankraub_Aktiv;
   	g_unixNDRob = gettime();
   	SetPlayerAttachedObject( playerid, 0, 1550, 15, 0.000000, 0.280000, -0.310000, 0.000000, 15.000000, 0.000000, 1.000000, 1.000000, 1.000000 );
   	ndrobspawn[15]=1; // ninedemons spawn will be changed
   	SetPVarInt(playerid, "ROB.NINEDEMONS", 1);
	return 1;
}*/


/*
CMD:hexenhut(playerid,params[]){

    if( IsPlayerAttachedObjectSlotUsed(playerid,8) ) {
        RemovePlayerAttachedObject(playerid,8);
        SendClientMessage(playerid,COLOR_YELLOW,"Hexen-Hut abgenommen.");
    }
    else {
        SetPlayerAttachedObject(playerid, 8, 19528, 2, 0.114997, 0.006998, 0.001999, 90.000000, -23.199983, 4.999997, 0.615999, 1.008998, 1.222000, 0xFFFF0000, 0xFFFF0000); //hat bottom
        SendClientMessage(playerid,COLOR_GREEN,"Hexen-Hut aufgesetzt.");
    }
    return 1;
}

CMD:kurbiskopf(playerid,params[]){

    if( IsPlayerAttachedObjectSlotUsed(playerid,8) ) {
        RemovePlayerAttachedObject(playerid,8);
        SendClientMessage(playerid,COLOR_YELLOW,"Kürbiskopf abgenommen.");
    }
    else {
        SetPlayerAttachedObject(playerid, 8, 19320, 2, 0.162564, 0.009463, 0.003660, 243.790893, 93.450889, 346.318786, 0.699999, 0.699999, 0.699999); //Kürbiskopf
        SendClientMessage(playerid,COLOR_GREEN,"Kürbiskopf aufgesetzt.");
    }
    return 1;
}

CMD:messerkopf(playerid,params[]){
    if( IsPlayerAttachedObjectSlotUsed(playerid,8) ) {
        RemovePlayerAttachedObject(playerid,8);
        SendClientMessage(playerid,COLOR_YELLOW,"Entfernt");
    }
    else {
        SetPlayerAttachedObject( playerid, 8, 335, 2, 0.392242, -0.182094, 0.153530, 30.000000, 223.276199, 36.263126, 1.500000, 1.500000, 1.200000 ); // TheParrot1 - papagei
        SendClientMessage(playerid,COLOR_YELLOW,"Messer in Kopf gesteckt.");
    }
    return 1;
}*/


/*
CMD:vfahr(playerid,params[]){
    if( !(Spieler[playerid][pAdmin] == 5 || Spieler[playerid][pFraktion] == 8) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Fahrlehrer!");
    }
    new
        modelid,
        vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst diese Funktion nur in einem Fahrzeug nutzen");
    }
    modelid = GetVehicleModel(vehicleid);
    if( (modelid != 405) &&  (modelid != 560) &&  (modelid != 445) &&  (modelid != 507) ) {
        return SendClientMessage(playerid, COLOR_RED, "Kein Fahrschul-Auto ");
    }
    if( _:g_t3dPolizeiKontrolle[vehicleid] != INVALID_3DTEXT_ID ) {
        // Entfernen
        Delete3DTextLabel( g_t3dPolizeiKontrolle[vehicleid] );
        g_t3dPolizeiKontrolle[vehicleid] = Text3D:INVALID_3DTEXT_ID;
    }
    else {
        g_t3dPolizeiKontrolle[vehicleid] = Create3DTextLabel("!VORSICHT!\n*FAHRSCHULE*", 0xFF4500FF, 0.0, 0.0, 0.0, 23.0, 0, 1);
        Attach3DTextLabelToVehicle( g_t3dPolizeiKontrolle[vehicleid],vehicleid,0.0,0.0,0.5);
    }
    return 1;
}*/


/*CMD:staatssystem(playerid,params[]) {
    #pragma unused params
    if(Spieler[playerid][pFraktion] != 16 ) {
        return SendClientMessage(playerid, COLOR_GREY, "Du bist kein Mitglied des Stadtamts.");
    }
    SendClientMessage(playerid,COLOR_LIGHTRED,"________Staats-System________");
    SendClientMessage(playerid,COLOR_WHITE,"/Kfzzulassen");
    SendClientMessage(playerid,COLOR_WHITE,"/Kfzabmelden");
    SendClientMessage(playerid,COLOR_WHITE,"/Kfzsuchen");
    SendClientMessage(playerid,COLOR_WHITE,"/Jobfeuern");
    SendClientMessage(playerid,COLOR_WHITE,"/Amtssteuern");
    SendClientMessage(playerid,COLOR_WHITE,"/Staatmelden");
    return 1;
}*/


/*
CMD:kfzzulassen(playerid,params[]) {
    if(Spieler[playerid][pFraktion] != 16 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied des Stadtamts.");
    }
    new
        giveid,
        slot,
        kennzeichen[32];
    if(sscanf(params,"uds[32]",giveid,slot,kennzeichen)) {
        return SendClientMessage(playerid,COLOR_GREEN,"Benutze: /kfzzulassen [Spieler] [Fahrzeug] [Kennzeichen]");
    }
    if( !IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid, COLOR_GREY, "Der Spieler ist nicht Online.");
    }
    if( !( 0 <= slot <= MaxVeh ) ) {
        return SendClientMessage(playerid, COLOR_RED, "Das Fahrzeug muss zwischen 0 und "#MaxVeh" liegen.");
    }
    if( !PlayerHaveCar[giveid][slot] ) {
        return SendClientMessage(playerid, COLOR_GREY, "Der Spieler hat in diesem Slot kein Fahrzeug");
    }
    if( !strcmp(KEIN_KENNZEICHEN,kennzeichen) ) {
        return SendClientMessage(playerid, COLOR_GREY, "Dieses Kennzeichen ist bereits belegt");
    }
    new len = strlen(kennzeichen);
    if( !( 4 < len < 32) ) { // 32 sind theoretisch Möglich,es passen aber nur 8 sichtbare Buchstaben auf das Nummernschild
        return SendClientMessage(playerid, COLOR_RED, "Ein Kennzeichen muss zwischen 4 und 32 Zeichen haben");
    }
    if( !isnull( g_KFZZulassung[giveid][slot] ) ) {
        return SendClientMessage(playerid, COLOR_RED, "Dem Spieler wurde bereits für diese Fahrzeug eine Zulassung angeboten");
    }
    if( HasVehicleLicence(giveid,slot) ) {
        return SendClientMessage(playerid, COLOR_RED, "Das Fahrzeug hat bereits eine KFZ-Zulassung");
    }
    PlayerSQLExtra(playerid,params);
    IsNumberplateFree(playerid,kennzeichen);
    // -> THREADED
    return 1;
}

CMD:kennzeichen(playerid,params[]) {
    new
        vehicleid;
    vehicleid = GetPlayerVehicleID(playerid);
    if(!vehicleid) {
        return SendClientMessage(playerid, COLOR_RED, "Diese Funktion ist nur in einem Fahrzeug möglich.");
    }
    for(new x=0;x<MaxVeh;x++)
    {
        if( PlayerHaveCar[playerid][x] )
        {
            if( vehicleid == PlayerCar[playerid][x][CarId] ) {
                // in seinem Fahrzeug
                if( !isnull(g_KFZZulassung[playerid][x]) ) {
                    // Neue Kennzeichen möglich
                    if( !IsNumberplateFree( g_KFZZulassung[playerid][x] )) {
                        new
                            String[128];
                        format(String,sizeof(String),"Zu spät,dass Kennzeichen %s wurde in der Zwischenzeit bereits belegt!", g_KFZZulassung[playerid][x] );
                        SendClientMessage(playerid,COLOR_RED,String);
                        g_KFZZulassung[playerid][x][0] = '\0';
                        return 1;
                    }
                    new
                        String[128];
                    format(String,sizeof(String),"Dein Fahrzeug ist nun offiziell zugelassen! Dein Amtlicheskennzeichen: '%s', Gute Weiterfahrt!", g_KFZZulassung[playerid][x] );
                    SendClientMessage(playerid,COLOR_GREEN,String);
                    format(PlayerCar[playerid][x][CarNumberplate],32,"%s",g_KFZZulassung[playerid][x]);
                    SetVehicleNumberPlate( vehicleid ,g_KFZZulassung[playerid][x]);
                    g_KFZZulassung[playerid][x][0] = '\0';
                    SavePlayerCar(playerid,x);
                }
                else {
                    // Kein Kennzeichen neu vergeben
                    SendClientMessage(playerid, COLOR_RED, "Für diese Fahrzeug wurde dir kein neues Kennzeichen zugewiesen");
                }
                return 1;
            }
        }
    }
    SendClientMessage(playerid, COLOR_RED, "Diese Fahrzeug gehört nicht dir.");
    return 1;
}
CMD:kfzabmelden(playerid,params[]) {
    if(Spieler[playerid][pFraktion] != 16 ) {
        return SendClientMessage(playerid, COLOR_GREY, "Du bist kein Mitglied des Stadtamts.");
    }
    new
        giveid,
        slot;
    if(sscanf(params,"ud",giveid,slot)) {
        return SendClientMessage(playerid,COLOR_GREEN,"Benutze: /kfzabmelden [Spieler] [Fahrzeug]");
    }
    if( !IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid, COLOR_GREY, "Der Spieler ist nicht Online.");
    }
    if( !( 0 <= slot < MaxVeh ) ) {
        return SendClientMessage(playerid, COLOR_GREY, "Das Fahrzeug muss zwischen 0 und "#MaxVeh" liegen.");
    }
    if( !PlayerHaveCar[giveid][slot] ) {
        return SendClientMessage(playerid, COLOR_GREY, "Der Spieler hat in diesem Slot kein Fahrzeug");
    }
    new
        String[128];

    format(PlayerCar[giveid][slot][CarNumberplate] ,32, KEIN_KENNZEICHEN);
    SetVehicleNumberPlate( PlayerCar[giveid][slot][CarId], ".");

    format(String,sizeof(String),"Stadtamt Mitarbeiter %s hat dein KFZ abgemeldet ( Fahrzeug: %d )",GetName(playerid),slot);
    SendClientMessage(giveid,COLOR_WHITE,String);

    format(String,sizeof(String),"Du hast die KFZ Zulassung %s entzogen ( Fahrzeug: %d )",GetName(giveid),slot);
    SendClientMessage(playerid,COLOR_WHITE,String);

    SavePlayerCar(playerid,slot);
    return 1;
}*/




/*CMD:inventar(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    new giveid = playerid;
    if (!isnull(params)) {
        if (sscanf(params, "u", giveid)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Inventar [Spieler ID/Name]");
        if (giveid != playerid) {
            if (giveid >= MAX_PLAYERS || !gPlayerLogged[giveid]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht online.");
            if (Spieler[giveid][pAdminDienst]) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist gerade im Admindienst.");
            if (!IsPlayerInRangeOfPlayer(playerid, giveid, 5.0)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht in deiner Nähe.");

            SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du zeigst %s dein Inventar.", GetName(giveid));
            SCMFormatted(giveid, COLOR_YELLOW, "[INFO] {FFFFFF}%s zeigt dir sein Inventar.", GetName(playerid));
        }
    }

    SendClientMessage(giveid, COLOR_GREEN, "======= {FFFFFF}[ INVENTAR ] {009D00}=======");
    SCMFormatted(giveid, COLOR_YELLOW, "Inventar von: {FFFFFF}%s", GetName(playerid));
    SCMFormatted(giveid, COLOR_YELLOW, "Drogen: {FFFFFF}%s Gramm", AddDelimiters(Spieler[playerid][pDrugs]));
    SCMFormatted(giveid, COLOR_YELLOW, "Spice: {FFFFFF}%s Gramm", AddDelimiters(Spieler[playerid][pSpice]));
    SCMFormatted(giveid, COLOR_YELLOW, "Waffenteile: {FFFFFF}%s Stück", AddDelimiters(Spieler[playerid][pWaffenteile]));
    SCMFormatted(giveid, COLOR_YELLOW, "Wantedcodes: {FFFFFF}%s Stück", AddDelimiters(Spieler[playerid][pWantedCodes]));
    SCMFormatted(giveid, COLOR_YELLOW, "Kanister: {FFFFFF}%d Stück", Spieler[playerid][pKanister]);
    SCMFormatted(giveid, COLOR_YELLOW, "Kekse: {FFFFFF}%s Stück", AddDelimiters(Spieler[playerid][pKekse]));
    SCMFormatted(giveid, COLOR_YELLOW, "Zigaretten: {FFFFFF}%s Stück", AddDelimiters(Spieler[playerid][pZigaretten]));
    SCMFormatted(giveid, COLOR_YELLOW, "Pfandflaschen: {FFFFFF}%s Stück", AddDelimiters(Spieler[playerid][pPfand]));
	if (Spieler[playerid][pFraktion] == 15) SCMFormatted(giveid, COLOR_YELLOW, "Spice-Samen: {FFFFFF}%s Stück", AddDelimiters(Spieler[playerid][pDrogenSamen]));
	if (Spieler[playerid][pZollValid] == 0) SendClientMessage(giveid, COLOR_YELLOW, "Zollpass: {FFFFFF}Nicht vorhanden");
    else {
        new year, month, day, hour, minute, sec, unix = Spieler[playerid][pZollValid];
        TimestampToDate(unix, year, month, day, hour, minute, sec, 1, 0);
        SCMFormatted(giveid, COLOR_YELLOW, "Zollpass: {FFFFFF}Gültig bis %02d/%02d/%d", day, month, year);
    }

    return SendClientMessage(giveid, COLOR_GREEN, "==========================");
}*/



// REMOVE_THIS
/*
CMD:myname(playerid, params[]) {
    SetPlayerName(playerid, params);
    return 1;
}*/



/*CMD:makespice(playerid, params[]){
    if(Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "[MAKESPICE] {FFFFFF}Du bist kein Terrorist!");
    new needDrogen = 2, needKrauter = 1, Anzahl;
    if(sscanf(params,"i",Anzahl)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Makespice [Anzahl]");
    if(Spieler[playerid][pDrugs] < needDrogen*Anzahl) return SendClientMessage(playerid, COLOR_RED, "[MAKESPICE] {FFFFFF}Du benötigst mehr Drogen!");
    if(Spieler[playerid][pKrauterMische] < needKrauter*Anzahl) return SendClientMessage(playerid, COLOR_RED, "[MAKESPICE] {FFFFFF}Du benötigst mehr Kräuter!");

    Spieler[playerid][pSpice] += Anzahl;
    Spieler[playerid][pDrugs] -= needDrogen*Anzahl;
    Spieler[playerid][pKrauterMische] -= needKrauter*Anzahl;

    SCMFormatted(playerid, COLOR_GREEN, "[MAKESPICE] {FFFFFF}Du hast %i Spice aus %i Drogen und %i Kräutern hergestellt!", Anzahl, needDrogen*Anzahl, needKrauter*Anzahl);
    return 1;
}*/




/*CMD:adventsinfop(playerid,params[]) {
    new
        giveid;
    if( !IsPlayerExecutive(playerid) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist/FBI!");
    }
    if( sscanf(params,"u",giveid)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/adventsinfop [Spieler]");
    }
    if(!IsPlayerConnected(giveid)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    }
    new
        String[128];
    format(String,sizeof(String),"[WEIHNACHTEN] {00FF00}Nimm am täglichen Gewinnspiel teil und gewinne ein Adventstürchen! Befehl: /Adventskalender.");
    SendClientMessageToAll(COLOR_TURKIS,String);
    return 1;
}*/


/*CMD:einfuehrung(playerid,params[]) {
    if( Spieler[playerid][pLevel] < 2 ) {
        return SendClientMessage(playerid, COLOR_RED, "Nur Spieler unter Level 2 können diese Funktion nutzen");
    }
    if( !IsPlayerInRangeOfPoint(playerid,8.0,0.0,0.0,0.0) ) {
        return SendClientMessage(playerid, COLOR_RED, "Diese Funktion kannst du hier nicht aufrufen");
    }
    new
        String[128];
    format(String,sizeof(String),"Neuling %s benötigt für den Start eine Einführung!",GetName(playerid));
    SendAdminMessage(COLOR_YELLOW, String);
    return 1;
}*/


/*CMD:freizeitpark(playerid,params[]) {
    SetPlayerPos(playerid,352.8312,-2143.1543,7.8359);
    Streamer_Update(playerid);
    return 1;
}
*/


/*
CMD:inmyhouse(playerid,params[]) {
    new
        house = Spieler[playerid][pPlayerHouse];
    if(house != 999) {
        if( IsPlayerInHouse(playerid, GetHouseIDByIndex(house) )) {
            SendClientMessage(playerid,COLOR_GREEN,"Jap! Dein Haus!");
        }
        else {
            SendClientMessage(playerid,COLOR_RED,"Nein,nicht dein Haus!");
        }
    }
    return 1;
}
CMD:myvw(playerid,params[]) {
    new
        vw;
    sscanf(params,"d",vw);
    SetPlayerVirtualWorld(playerid,vw);
    SendClientMessage(playerid,COLOR_YELLOW,"Ok");
    return 1;
}
*/


/*
#if defined WEIHNACHTS_EVENT
CMD:halloween(playerid,params[]) {
	if( Spieler[playerid][pLevel] < 3 ) {
	    return SendClientMessage(playerid, COLOR_RED, "Du musst Level 3 erreicht haben, um ein Geschenk öffnen zu können.");
	}
	for(new i ; i < sizeof(g_Geschenk); i++) {
	    if( g_Geschenk[i][G_bFound] == false ) {
	        if( IsPlayerInRangeOfPoint(playerid,3.0,g_Geschenk[i][G_fX],g_Geschenk[i][G_fY],g_Geschenk[i][G_fZ]) ) {
				new
				    String[128];
	            g_iGeschenk++;
	            format(String,sizeof(String),"[HALLOWEEN] %s hat ein Kürbis gefunden! Kürbisse: %d/%d",GetName(playerid),g_iGeschenk,sizeof(g_Geschenk));
	            SendClientMessageToAll(COLOR_YELLOW,String);
	            DestroyDynamic3DTextLabel( g_Geschenk[i][G_t3dLabel] );
	            DestroyDynamicObject( g_Geschenk[i][G_iObjectID] );
	            g_Geschenk[i][G_bFound] = true;
				GivePlayerCash(playerid,50000);
				Spieler[playerid][pLevel] += 1;
	            if( g_iGeschenk == sizeof(g_Geschenk) ) {
	                // Alle wurden gefunden
	                SendClientMessageToAll(COLOR_YELLOW,"Alle Kürbisse wurden gefunden! LyD wünscht euch gruselige Halloween!");
	            }
	            return 1;
	        }
	    }
	}
	SendClientMessage(playerid,COLOR_WHITE,"Kein Paket in deiner nähe!");
	return 1;
}
#endif*/
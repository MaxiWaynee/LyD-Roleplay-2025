#include <YSI\y_hooks>


CMD:hauskaufen(playerid, params[])
{
    if (Spieler[playerid][pPlayerHouse] != 999) return SendClientMessage(playerid, COLOR_RED, "Du besitzt bereits ein Haus!");
    if (Spieler[playerid][pHouseMieteKey] != 999) return SendClientMessage(playerid, COLOR_RED, "Du bist noch in einem Haus eingemietet!");
    if (Spieler[playerid][pPlayerHotel] != 999) return SendClientMessage(playerid, COLOR_RED, "Du mietest bereits ein Hotelzimmer!");
    if (Spieler[playerid][pLevel] < 5) return SendClientMessage(playerid, COLOR_RED, "Dein Level ist zu niedrig um ein Haus zu kaufen! Du musst Level 5 erreichen um ein Haus kaufen zu können.");

    for (new i = 0; i < iHaus; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, Haus[i][EnterX], Haus[i][EnterY], Haus[i][EnterZ]))
        {
            // new index = GetHouseIndexByID( Spieler[playerid][pHouseKey] );
            // if(Spieler[playerid][pHouseKey] != 999 && strcmp(GetName(playerid), Haus[index][hBesitzer], true) == 0)return SendClientMessage(playerid, COLOR_RED, "Du besitzt bereits ein Haus. Verkaufe es zuerst per /sellhouse.");
            if(strcmp(Haus[i][hBesitzer], "Niemand", true) == 0)
            {
                if(Spieler[playerid][pPerso] == 0)return SendClientMessage(playerid, COLOR_RED, "Du benötigst einen Personalausweis.");
                if(CheckMoney(playerid) < Haus[i][hPreis])return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht genügend Geld.");
                new string[128];
                Spieler[playerid][pPlayerHouse] = Haus[i][hID]; // <- Nicht Index, sondern ID
                Haus[i][hMieten] = 0;
                Haus[i][hMieterAnzahl] = 0;
                strmid(Haus[i][hBesitzer], GetName(playerid), 0, MAX_PLAYER_NAME, 255);
                GivePlayerCash(playerid, -Haus[i][hPreis]);

                new index = GetHouseInteriorIndexByID( Haus[i][HouseInteriorID] );
                SetPlayerInterior(playerid, g_HouseInterior[index][HI_iInterior]);
                // SetPlayerInterior(playerid, Haus[i][hInterior]);

                SetPlayerVirtualWorld(playerid, i);
                SetPlayerPos(playerid, g_HouseInterior[index][HI_fExitX], g_HouseInterior[index][HI_fExitY], g_HouseInterior[index][HI_fExitZ]);
                // SetPlayerPos(playerid, Haus[i][ExitX], Haus[i][ExitY], Haus[i][ExitZ]);
                format(string, sizeof(string), "Du hast erfolgreich dieses Haus gekauft. ($-%d)", Haus[i][hPreis]);
                SendClientMessage(playerid, COLOR_GREEN, string);
                SendClientMessage(playerid, COLOR_WHITE, "Du kannst deinen Spawn-Ort per /spawnchange wechseln.");
                SendClientMessage(playerid, COLOR_WHITE, "Andere Befehle findest du unter /Help -> Hausbefehle.");
                SendClientMessage(playerid, COLOR_RED, "HINWEIS: Mach zur Datensicherung bitte ein Relog!");
                ShowBuyInformation(playerid,"~y~Haus ~w~gekauft!");
                //new hStr[128];
                //format(hStr, sizeof(hStr), "Besitzer: %s\nBeschreibung: %s", Haus[i][hBesitzer], Haus[i][hName]);
                CheckPlayerHouse(playerid);
                UpdateHouseText(i);
                DestroyHouseSellObject(i);
                return 1;
            }
            else
                return SendClientMessage(playerid, COLOR_RED, "Dieses Haus besitzt bereits jemand.");
        }
    }

    return 1;
}

CMD:hausentmieten(playerid)
{
    new pHouse = Spieler[playerid][pHouseMieteKey];
    if( pHouse == 999)return SendClientMessage(playerid, COLOR_RED, "Du bist bereits ausgemietet.");
    new index = GetHouseIndexByID(pHouse);
    if( Spieler[playerid][pPlayerHouse] != 999 ) return SendClientMessage(playerid, COLOR_ORANGE, "Wenn du dein Haus nicht mehr haben möchtest, tippe /sellhouse.");
    Spieler[playerid][pHouseMieteKey] = 999;
    SendClientMessage(playerid, COLOR_WHITE, "Du lebst nun wieder auf der Straße!");
    ShowBuyInformation(playerid,"~y~Haus ~w~entmietet!");
    Haus[index][hMieterAnzahl]--;

    Spieler[playerid][pUpgradeWaffenlager] = 0;
    Spieler[playerid][pUpgradeSafebox] = 0;
    Spieler[playerid][pHausWaffenlager1] = 0;
    Spieler[playerid][pHausWaffenlager2] = 0;
    Spieler[playerid][pHausWaffenlager3] = 0;
    Spieler[playerid][pHausSafeboxSpice] = 0;
    Spieler[playerid][pHausSafeboxDrogen] = 0;
    return 1;
}

CMD:hausmieten(playerid)
{
    if( GetPlayerHouse(playerid) != 999)return SendClientMessage(playerid, COLOR_RED, "Du besitzt bereits ein Haus!");
    if(Spieler[playerid][pPlayerHotel] != 999)return SendClientMessage(playerid, COLOR_RED, "Du mietest bereits ein Hotelzimmer!");
    new h = IsPlayerAtHouse(playerid);
    if(h == 999)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe eines Hauses.");
    if(Haus[h][hMieten] == 0)return SendClientMessage(playerid, COLOR_RED, "Das Haus lässt Mieten nicht zu.");
    if(CheckMoney(playerid) < Haus[h][hMietPreis])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld hast du nicht.");
    if( Haus[h][hMieterAnzahl] >= Haus[h][hMieterMax])return SendClientMessage(playerid, COLOR_RED, "Die maximale Anzahl an Mietern für dieses Haus ist erreicht!");
    Spieler[playerid][pHouseMieteKey] = GetHouseIDByIndex(h);
    GivePlayerCash(playerid, -Haus[h][hMietPreis]);
    Haus[h][hKasse]+=Haus[h][hMietPreis];
    Haus[h][hMieterAnzahl]++;
    SendClientMessage(playerid, COLOR_WHITE, "Du hast dich erfolgreich ins Haus eingemietet und zahlst jeden Zahltag einen gewissen Betrag an Miete.");
    SendClientMessage(playerid, COLOR_WHITE, "Mit /Spawnchange kannst du deinen Spawn zwischen Haus oder Fraktion bzw. Zivi-Spawn wechseln.");
    ShowBuyInformation(playerid,"~y~Wohnung ~w~gemietet!");

    return 1;
}

CMD:hausmietung(playerid, params[])
{
    new status[12];
    if(sscanf(params, "s[12]", status))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Hausmietung [An/Aus]");
    new h = GetPlayerHouse(playerid);
    if((h == 999) || (h != 999 && !IsPlayerInHouse(playerid, Haus[h][hID])) ) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe eines Hauses.");
    if(strcmp(status, "AN", true) == 0)
    {
        if(Spieler[playerid][pPlayerHouse] == h)
        {
            if(Haus[h][hMieten] == 0)
            {
                Haus[h][hMieten] = 1;
                Haus[h][hMietPreis] = 50;
                SendClientMessage(playerid, COLOR_WHITE, "Es kann nun gemietet werden.");
                UpdateHouseText(h);
            }
            else
            {
                SendClientMessage(playerid, COLOR_ORANGE, "Es kann bereits gemietet werden.");
                return 1;
            }
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer des Hauses.");
            return 1;
        }
    }
    else if(strcmp(status, "AUS", true) == 0)
    {
        if(Spieler[playerid][pPlayerHouse] == h)
        {
            if(Haus[h][hMieten] == 1)
            {
                new query[128];
                format(query, sizeof(query), "UPDATE `accounts` SET `HouseMieteKey` = '999' WHERE `HouseMieteKey` = %d", Haus[h][hID] );
                mysql_pquery(query,THREAD_HAUSMIETUNGRAUS,playerid,gSQL,MySQLThreadOwner);

                Haus[h][hMieten] = 0;
                Haus[h][hMieterAnzahl] = 0;
                SendClientMessage(playerid, COLOR_GREEN, "Es kann nun nicht weiter gemietet werden.");
                UpdateHouseText(h);
            }
            else
            {
                SendClientMessage(playerid, COLOR_ORANGE, "Das Mieten ist bereits deaktiviert.");
                return 1;
            }
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer dieses Hauses.");
            return 1;
        }
    }
    else return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Hausmietung [An/Aus]");
    return 1;
}


CMD:mietpreis(playerid, params[])
{
    new preis, string[128];
    if(sscanf(params, "i", preis))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Mietpreis [Betrag]");
    new h = GetPlayerHouse(playerid);
    if( h == 999 || !IsPlayerInHouse(playerid, Haus[h][hID]) )return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe eines Hauses.");
    if(preis < 100 || preis > 10000)return SendClientMessage(playerid, COLOR_ORANGE, "Der Preis muss zwischen $100 und $10.000 liegen!");
    if(Spieler[playerid][pPlayerHouse] == h)
    {
        format(string, sizeof(string), "Du hast den Mietpreis in $%s geändert.", AddDelimiters(preis));
        SendClientMessage(playerid, COLOR_GREEN, string);
        SendClientMessage(playerid, COLOR_RED, "ACHTUNG! Der Mietpreis muss fair nach Hausinterior, Zustand und Ort bestimmt werden!");
        SendClientMessage(playerid, COLOR_RED, "Zum Beispiel eine Villa in Vinewood darf kein Mietpreis von 500$, sondern muss höher sein.");
        SendClientMessage(playerid, COLOR_RED, "Bei Missachtung dieser Regel(§33) kann das Haus entzogen werden!");
        format(string,sizeof(string),"[HAUS-INFO] Dein Vermieter hat den Mietpreis von $%s auf $%s geändert.", AddDelimiters(Haus[h][hMietPreis]), AddDelimiters(preis));
        for(new i ; i < MAX_PLAYERS ; i++) {
            if( IsPlayerConnected(i) ) {
                if( Spieler[i][pHouseMieteKey] == Haus[h][hID] ) {
                    SendClientMessage(playerid,COLOR_WHITE,string);
                }
            }
        }
        Haus[h][hMietPreis] = preis;
        UpdateHouseText(h);
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer des Hauses.");
        return 1;
    }
    return 1;
}

CMD:hausrausalle(playerid)
{
    new h = IsPlayerAtHouse(playerid);
    if(h == 999)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe eines Hauses.");
    // printf("pPlayerHouse %d h %d",Spieler[playerid][pPlayerHouse],h);
    if(Spieler[playerid][pPlayerHouse] == h)
    {
        new query[256];
        format(query, sizeof(query), "\
        UPDATE `accounts` SET \
        `HouseMieteKey` = '999', \
        `UpgradeWaffenlager` = '0',\
        `UpgradeSafebox` = '0',\
        `HausWaffenlager` = '0',\
        `HausSafeboxSpice` = '0',\
        `HausSafeboxDrogen` = '0'\
        WHERE `HouseMieteKey` = %d", Spieler[playerid][pPlayerHouse]);
        mysql_pquery(query,THREAD_HAUSRAUSALLE,playerid,gSQL,MySQLThreadOwner);
        format(query,sizeof(query),"Du hast alle Spieler (%d) aus deinem Haus rausgeschmissen.",Haus[h][hMieterAnzahl]);
        SendClientMessage(playerid, COLOR_LIGHTBLUE,query);
        Haus[h][hMieterAnzahl] = 0;
        for(new i = 0 ; i < MAX_PLAYERS ; i++)
        {
            if(i != playerid)
            {
                if(IsPlayerConnected(i))
                {
                    if(Spieler[i][pHouseMieteKey] == Haus[h][hID])
                    {
                        Spieler[i][pHouseMieteKey] = 999;
                        SendClientMessage(i, COLOR_LIGHTBLUE, "Du wurdest aus deinem Haus geschmissen.");
                        // return 1;
                    }
                }
            }
        }
        UpdateHouseText(h);
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer dieses Hauses.");
        return 1;
    }
    return 1;
}

CMD:hausraus(playerid, params[])
{
    new pID, string[128];
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Hausraus [SpielerID/Name]");
    if(pID == playerid)return SendClientMessage(playerid, COLOR_RED, "Du kannst dich selber nicht rausschmeißen.");
    new h = IsPlayerAtHouse(playerid);
    if(h == 999)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe eines Hauses.");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[playerid][pPlayerHouse] == h )
    {
        if(Spieler[pID][pHouseMieteKey] == Haus[h][hID]) // MietKey ist Haus-ID
        {
            Spieler[pID][pHouseMieteKey] = 999;
            Spieler[pID][pSpawnChange] = 0;
            format(string, sizeof(string), "Du wurdest von %s aus deinem Haus geschmissen.", GetName(playerid));
            SendClientMessage(pID, COLOR_LIGHTBLUE, string);
            format(string, sizeof(string), "Du hast %s aus deinem Haus geschmissen.", GetName(pID));
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
            Haus[h][hMieterAnzahl]--;
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Der Spieler wohnt nicht in deinem Haus.");
            return 1;
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer des Hauses.");
        return 1;
    }
    return 1;
}


CMD:haustuer(playerid, params[])
{
    new status[12];
    new index;
    if(sscanf(params, "s[12]", status))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Haustuer [Auf/Zu]");
    if(strcmp(status, "AUF", true) == 0)
    {
        for(new h = 0; h < MAX_HOUSES; h++)
        {
            index = GetHouseInteriorIndexByID( Haus[h][HouseInteriorID] );
            if( index == 999 ) continue;
            if(IsPlayerInRangeOfPoint(playerid, 2.0, Haus[h][EnterX], Haus[h][EnterY], Haus[h][EnterZ]) || (IsPlayerInRangeOfPoint(playerid, 4.0, g_HouseInterior[index][HI_fExitX], g_HouseInterior[index][HI_fExitY], g_HouseInterior[index][HI_fExitZ]) && GetPlayerVirtualWorld(playerid) == h))
            {
                if(Spieler[playerid][pPlayerHouse] == h )
                {
                    if(Haus[h][hLock] == 1)
                    {
                        Haus[h][hLock] = 0;
                        GameTextForPlayer(playerid, "~w~Haus ~g~Auf", 5000, 6);
                    }
                    else
                    {
                        SendClientMessage(playerid, COLOR_ORANGE, "Das Haus ist bereits offen.");
                        return 1;
                    }
                }
                else
                {
                    SendClientMessage(playerid, COLOR_RED, "Dieses Haus gehört dir nicht oder du bist nicht eingemietet.");
                    return 1;
                }
            }
        }
    }
    else if(strcmp(status, "ZU", true) == 0)
    {
        for(new h = 0; h < MAX_HOUSES; h++)
        {
            index = GetHouseInteriorIndexByID( Haus[h][HouseInteriorID] );
            if( index == 999 ) continue;
            if(IsPlayerInRangeOfPoint(playerid, 2.0, Haus[h][EnterX], Haus[h][EnterY], Haus[h][EnterZ]) || (IsPlayerInRangeOfPoint(playerid, 4.0, g_HouseInterior[index][HI_fExitX], g_HouseInterior[index][HI_fExitY], g_HouseInterior[index][HI_fExitZ]) && GetPlayerVirtualWorld(playerid) == h))
            {
                if(Spieler[playerid][pPlayerHouse] == h)
                {
                    if(Haus[h][hLock] == 0)
                    {
                        Haus[h][hLock] = 1;
                        GameTextForPlayer(playerid, "~w~Haus ~r~Zu", 5000, 6);
                    }
                    else
                    {
                        SendClientMessage(playerid, COLOR_ORANGE, "Das Haus ist bereits zu.");
                        return 1;
                    }
                }
                else
                {
                    SendClientMessage(playerid, COLOR_RED, "Dieses Haus gehört dir nicht.");
                    return 1;
                }
            }
        }
    }
    else return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/haustuer [Auf/Zu]");
    return 1;
}



CMD:zuhause(playerid, params[])
{
    if(GetPlayerHouse(playerid) == 999)return SendClientMessage(playerid, COLOR_RED, "Du hast kein Haus.");
    new pHouse = GetPlayerHouse(playerid);
    if( pHouse != 999 ) {
        SetPlayerCheckpointEx(playerid, Haus[pHouse][EnterX], Haus[pHouse][EnterY], Haus[pHouse][EnterZ], 3.0, CP_HOME);
        SendClientMessage(playerid, COLOR_SAMP, "Dein Haus wurde dir Rot auf der Karte markiert!");
    }
    return 1;
}


CMD:hauskassestand(playerid)
{
    new h=IsPlayerAtHouse(playerid);
    if(h==999)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich vor keinem Haus.");
    if(Spieler[playerid][pAdmin] > 3 || Spieler[playerid][pPlayerHouse] == h )
    {
        new string[128];
        format(string, sizeof(string), "* Haus-Kasse: $%s *", AddDelimiters(Haus[h][hKasse]));
        SendClientMessage(playerid, COLOR_GREEN, string);
        SendClientMessage(playerid, COLOR_WHITE, "Um Geld von der Kasse zu nehmen oder anzulegen tippe /Hauskasse [Anlegen/Nehmen].");
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Da du nicht der Besitzer bist, kannst du auch nicht auf die Kasse schauen.");
        return 1;
    }
    return 1;
}

CMD:hauseinbrechen(playerid,params[]) {
    if( !Spieler[playerid][pBrecheisen] ) {
        SendClientMessage(playerid,COLOR_RED,"Du hast keine Brechstange um die Tür aufzubrechen");
        return 1;
    }
    new
        house;
    house = GetClosestHouse(playerid);
    if(house == 999 ) {
        SendClientMessage(playerid,COLOR_RED,"Du befindest dich nicht am Eingang eines Hauses");
        return 1;
    }
    new
        String[128],
        Float:x,
        Float:y,
        Float:z;
    Spieler[playerid][unixHausAufbrechen] = gettime() + 8;
    Spieler[playerid][pBrecheisen]--;
    KillTimer(Spieler[playerid][tEinbrechen]);
    Spieler[playerid][tEinbrechen] = SetTimerEx("Pulse_Einbrechen",1868,true,"dd",playerid,house);
    format(String,sizeof(String),"%s versucht in ein Haus einzubrechen!",GetName(playerid));
    GetPlayerPos(playerid,x,y,z);
    SendRoundMessage(x,y,z, COLOR_RED, String);
    /*
        for(new i=0; i < iHaus ;i++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, Haus[i][EnterX], Haus[i][EnterY], Haus[i][EnterZ]))
            {
                new index = GetHouseIndexByID( Spieler[playerid][pHouseKey] );
    */
    return 1;
}


CMD:savehouseobject(playerid,params[]) {
    new h = IsPlayerAtHouse(playerid,4.0);
    if(h == 999)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe eines Hauses.");
    new
        Float:x,
        Float:y,
        Float:z,
        Float:rot,
        query[400];
    GetPlayerPos(playerid,x,y,z);
    GetPlayerFacingAngle(playerid,rot);
    format(query,sizeof(query),"UPDATE `houses` SET \
        `SellX` = %.2f, \
        `SellY` = %.2f, \
        `SellZ` = %.2f, \
        `SellRot` = '%.1f' \
        WHERE `ID` = %d",
            x,
            y,
            z,
            rot,
            Haus[h][hID]
    );
    print(query);
    SendClientMessage(playerid,COLOR_YELLOW,"Gespeichert!");
    return 1;
}



CMD:miethotelraum(playerid,params[]) {
    #pragma unused params
    if(GetPlayerHouse(playerid) != 999)return SendClientMessage(playerid, COLOR_RED, "Du besitzt bereits ein Haus und kannst somit kein Hotel mieten!");
    if(Spieler[playerid][pPlayerHotel] != 999)return SendClientMessage(playerid, COLOR_RED, "Du mietest bereits ein Hotelzimmer!");
    new
        hotel = IsPlayerAtHotel(playerid);
    if(hotel == 999) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keinem Hotelzimmer.");
    if( strcmp(Hotel[hotel][hBesitzer],"Niemand") != 0 )return SendClientMessage(playerid, COLOR_GREY, "Das Hotel wird bereits gemietet");

    Spieler[playerid][pPlayerHotel] = hotel;
    format( Hotel[hotel][hBesitzer] , MAX_PLAYER_NAME , GetName(playerid) );
    SendClientMessage(playerid, COLOR_WHITE, "Du hast dich erfolgreich ins Hotel eingemietet und zahlst jeden Zahltag einen gewissen Betrag an Miete.");
    SendClientMessage(playerid, COLOR_WHITE, "Mit /Spawnchange kannst du deinen Spawn zwischen Haus/Hotel oder Fraktion bzw. Zivi-Spawn wechseln.");
    new hStr[256];
    format(hStr, sizeof(hStr), "Besitzer: %s\nBeschreibung: %s", Hotel[hotel][hBesitzer], Hotel[hotel][hName]);
    UpdateDynamic3DTextLabelText(Hotel[hotel][hText],COLOR_PROP,hStr);
    return 1;
}
CMD:entmietenhotelraum(playerid,params[]){
    if(Spieler[playerid][pPlayerHotel] == 999)return SendClientMessage(playerid, COLOR_RED, "Du mietest kein Hotelzimmer!");
    new
        //query[128],
        hStr[256],
        hotel = Spieler[playerid][pPlayerHotel];
    format( Hotel[hotel][hBesitzer] , MAX_PLAYER_NAME , "Niemand" );
    Hotel[hotel][hLock] = 1;
    Spieler[playerid][pSpawnChange] = 0;
    Spieler[playerid][pPlayerHotel] = 999;
    SendClientMessage(playerid, COLOR_WHITE, "Du hast das Hotelzimmer entmietet und lebst nun wieder auf der Straße.");
    format(hStr, sizeof(hStr), "Dieses Hotelzimmer ist noch zu vermieten!\n\
                                %s\n\
                                Zimmer Mietpreis: %d$\n\
                                Mit /miethotelraum mietest du ein Hotelzimmer", Hotel[hotel][hName], Hotel[hotel][hMietPreis]);
    UpdateDynamic3DTextLabelText(Hotel[hotel][hText],COLOR_PROP,hStr);

    //format(query, sizeof(query), "UPDATE `accounts` SET `HotelKey` = '999' WHERE `Name` = '%s'", GetName(playerid) );
    //mysql_pquery(query,THREAD_SELLHOTEL,playerid,gSQL,MySQLThreadOwner);

    return 1;
}
CMD:hoteltuer(playerid, params[])
{
    new status[12];
    new hotel;
    if(sscanf(params, "s[12]", status))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Hoteltuer [Auf/Zu]");
    hotel = IsPlayerAtHotel(playerid);
    if(hotel == 999) return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keinem Hotelzimmer.");
    if(strcmp(status, "AUF", true) == 0)
    {
        if(Spieler[playerid][pPlayerHotel] == hotel )
        {
            if(Hotel[hotel][hLock] == 1)
            {
                Hotel[hotel][hLock] = 0;
                GameTextForPlayer(playerid, "~w~Hotelzimmer ~g~Auf", 5000, 6);
            }
            else
            {
                SendClientMessage(playerid, COLOR_ORANGE, "Das Hotelzimmer ist bereits offen.");
                return 1;
            }
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Dieses Hotelzimmer hast du nicht gemietet.");
            return 1;
        }
    }
    else if(strcmp(status, "ZU", true) == 0)
    {
        if(Spieler[playerid][pPlayerHotel] == hotel )
        {
            if(Hotel[hotel][hLock] == 0)
            {
                Hotel[hotel][hLock] = 1;
                GameTextForPlayer(playerid, "~w~Hotelzimmer ~g~Zu", 5000, 6);
            }
            else
            {
                SendClientMessage(playerid, COLOR_ORANGE, "Das Hotelzimmer ist bereits geschlossen.");
                return 1;
            }
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Dieses Hotelzimmer hast du nicht gemietet.");
            return 1;
        }
    }
    return 1;
}



CMD:hausupgrade(playerid,params[]) {
    new
        String[128],
        house_index,
        vw;
    vw = GetPlayerVirtualWorld(playerid);
    house_index = vw;
    //printf("vw %d house_index %d",vw,house_index);
    if( !( 0 <= vw < MAX_HOUSES )  ) return SendClientMessage(playerid,COLOR_RED,"Du stehst in keinem Haus-Upgrade Pickup.");
    new index;
    index = GetHouseInteriorIndexByID( Haus[house_index][HouseInteriorID] );
    if( index == 999 ) return SendClientMessage(playerid,COLOR_RED,"Du stehst in keinem Haus-Upgrade Pickup.");
    if( !IsPlayerInRangeOfPoint(playerid, 3.0 , g_HouseInterior[index][HI_fPickupX], g_HouseInterior[index][HI_fPickupY], g_HouseInterior[index][HI_fPickupZ] )) return SendClientMessage(playerid,COLOR_RED,"Du stehst in keinem Haus-Upgrade Pickup.");
    if( Spieler[playerid][pUpgradeWaffenlager] ) {
        format(String,sizeof(String),"Haus Waffenlager - FREIGESCHALTET");
    }
    else {
        format(String,sizeof(String),"Haus Waffenlager - NICHT FREIGESCHALTET");
    }
    if( Spieler[playerid][pUpgradeSafebox] ) {
        format(String,sizeof(String),"%s\nHaus Safebox - FREIGESCHALTET",String);
    }
    else {
        format(String,sizeof(String),"%s\nHaus Safebox - NICHT FREIGESCHALTET",String);
    }
    ShowPlayerDialog(playerid,DIALOG_HAUSUPGRADE,DIALOG_STYLE_LIST,"Haus Upgrades",String,"Weiter","Abbruch");
    return 1;
}


CMD:hausverkaufen(playerid,params[]) {
    new
        giveid,
        price;
    if(sscanf(params,"ud",giveid,price)) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Hausverkaufen [ID] [PREIS](20.000$ bis 30.000.000$)");
    }
    if( !( 20000 <= price <= 30000000 )) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Hausverkaufen [ID] [PREIS](20.000$ bis 30.000.000$)");
    }
    new pHouse = GetPlayerHouse(playerid);
    if( pHouse == 999 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du besitzt kein Haus!");
    }
    if( Spieler[playerid][pPlayerHouse] == 999 ) {
        return SendClientMessage(playerid, COLOR_RED, "Das Haus, dessen Schlüssel du besitzt, gehört nicht dir!");
    }
    if( !IsPlayerConnected(giveid) || giveid == playerid) {
        SendClientMessage(playerid,COLOR_RED,"Ungültiger Spieler");
        return 1;
    }
    if( Spieler[playerid][pHouseAngebot][0] != INVALID_PLAYER_ID ) {
        SendClientMessage(playerid,COLOR_RED,"Du hast das Haus bereits einem Spieler angeboten");
        return 1;
    }
    if( Spieler[giveid][pLevel] < 4 ) {
        SendClientMessage(playerid,COLOR_RED,"Du kannst ein Haus nur an Spieler verkaufen, dessen Level über 4 liegt");
        return 1;
    }
    new
        Float:x,
        Float:y,
        Float:z;
    GetPlayerPos(playerid,x,y,z);
    if( !IsPlayerInRangeOfPoint(giveid,5.0,x,y,z)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Spieler muss sich in deiner nähe befinden");
    }
    ShowPlayerDialog(playerid,DIALOG_BESTAETIGEN,DIALOG_STYLE_MSGBOX,"Möchtest du diesen Befehl genauso ausführen?",
    "Um Fehleingaben zu vermeiden, wird bei diesem Befehl sicherheitshalber nochmal um Bestätigung gebeten.",
    "AUSFÜHREN","ABBRECHEN");
    sichervar[playerid][1]=1,sichervar[playerid][2]=giveid,sichervar[playerid][3]=price;
    return 1;
}
CMD:hausankaufen(playerid,params[]) {
    new
        giveid;
    if(sscanf(params,"u",giveid)) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Hausankaufen [ID]");
    }
    if( !IsPlayerConnected(playerid) || playerid == giveid) {
        SendClientMessage(playerid,COLOR_RED,"Ungültiger Spieler");
        return 1;
    }
    new pHouse = GetPlayerHouse(playerid);
    if( pHouse != 999) {
        return SendClientMessage(playerid, COLOR_RED, "Du besitzt bereits ein Haus oder bist in eines eingemietet!");
    }
    pHouse = GetPlayerHouse(giveid);
    if( pHouse == 999) {
        return SendClientMessage(playerid, COLOR_RED, "Der Verkäufer ist nicht mehr in Besitz des Angebotenen Hauses");
    }
    if(Spieler[giveid][pPlayerHouse] == 999 ) {
        return SendClientMessage(playerid, COLOR_RED, "Der Verkäufer ist nicht mehr der Besitzer des Angebotenen Hauses");
    }
    if( Spieler[giveid][pHouseAngebot][0] != playerid ) {
        SendClientMessage(playerid,COLOR_RED,"Dieser Spieler hat dir kein Haus zum Verkauf angeboten");
        return 1;
    }
    new
        string[128],
        price,
        Float:x,
        Float:y,
        Float:z;
    GetPlayerPos(playerid,x,y,z);
    if( !IsPlayerInRangeOfPoint(giveid,5.0,x,y,z)) {
        return SendClientMessage(playerid, COLOR_RED, "Der Verkäufer muss sich in deiner nähe befinden");
    }
    price = Spieler[giveid][pHouseAngebot][1];
    if( price > Spieler[playerid][pCash] ) {
        format(string,sizeof(string),"Du hast nicht genug Geld auf der Hand um das Haus zu kaufen ($%s)", AddDelimiters(price));
        return SendClientMessage(playerid, COLOR_RED, string);
    }
    format(string,sizeof(string),"Dein Haus hast du an %s verkauft! Er hat dein Angebot angenommen und ist nun der neue Besitzer.",GetName(playerid));
    SendClientMessage(giveid,COLOR_GREEN,string);
    format(string,sizeof(string),"Du hast das Haus erfolgreich von %s abgekauft!",GetName(giveid));
    SendClientMessage(playerid,COLOR_GREEN,string);
    SendClientMessage(playerid, COLOR_RED, "HINWEIS: Mach zur Datensicherung bitte ein Relog!");
    SendClientMessage(giveid, COLOR_RED, "HINWEIS: Mach zur Datensicherung bitte ein Relog!");

    format(string,sizeof(string),"[HAUSKAUF] Verkäufer: %s, Käufer: %s, Preis: %d",GetName(giveid),GetName(playerid),price);
    KaufLog(string);

    Spieler[giveid][pHouseAngebot][0] = INVALID_PLAYER_ID;
    Spieler[giveid][pHouseAngebot][1] = 0;
    Spieler[giveid][pPlayerHouse] = 999;
    format( Haus[pHouse][hBesitzer] , MAX_PLAYER_NAME , GetName(playerid) );
    CheckPlayerHouse(playerid);
    // Spieler[playerid][pPlayerHouse] = pHouse;
    GivePlayerCash(playerid, -price);
    GivePlayerCash(giveid, price);
    Haus[pHouse][hMieterAnzahl] = 0;
    Haus[pHouse][hKasse] = 0;
    UpdateHouseText(pHouse);
    // Alle alten Leute mit Schlüssel rauswerfen
    for(new i ; i < MAX_PLAYERS ; i++) {
        if( i != playerid ) {
            if( Spieler[i][pHouseMieteKey] == pHouse ) {
                Spieler[i][pHouseMieteKey] = 999;
            }
        }
    }
    format(string,sizeof(string),"UPDATE `accounts` SET `HouseMieteKey` = 999 WHERE `HouseMieteKey` = %d",pHouse);
    mysql_oquery( string ,  THREAD_DUMMY , INVALID_PLAYER_ID ,gSQL);
    return 1;
}


CMD:haussuchen(playerid,params[]) {
    new
        index = -1,
        hausid;
    if(sscanf(params,"d",hausid)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Haussuchen [ID]");
    }
    if( hausid < 1 || hausid > 10000 ) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Haussuchen [ID] ( 1 - 10000 )");
    }
    for(new i ; i < MAX_HOUSES ; i++) {
        if( Haus[i][hID] == hausid ) {
            index = i;
            break;
        }
    }
    if( index == -1 ) {
        return SendClientMessage(playerid,COLOR_RED,"Kein Haus mit der genannten ID gefunden");
    }
    SendClientMessage(playerid,COLOR_GREEN,"Das Haus wurde Ihnen auf der Map markiert!");
    SendClientMessage(playerid,COLOR_YELLOW,"=====================");
    SetPlayerCheckpointEx(playerid, Haus[index][EnterX], Haus[index][EnterY], Haus[index][EnterZ], 2.0, CP_HAUSSUCHEN);
    return 1;
}

CMD:hausmieter(playerid,params[]) {
    #pragma unused params
    if( Spieler[playerid][pPlayerHouse] == 999 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du besitzt kein Haus!");
    }
    new
        index = Spieler[playerid][pPlayerHouse],
        String[128];
    format(String,sizeof(String),"SELECT `Name` FROM `accounts` WHERE `HouseMieteKey` = %d ORDER BY `Name` DESC",Haus[index][hID]);
    mysql_pquery(String,THREAD_HAUSMIETER,playerid,gSQL,MySQLThreadOwner);
    return 1;
}

CMD:offhausraus(playerid,params[]) {
    if( Spieler[playerid][pPlayerHouse] == 999 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du besitzt kein Haus!");
    }
    new name[MAX_PLAYER_NAME];
    if(sscanf(params,"s[24]",name)) {
        return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Offhausraus [Name]");
    }
    new
        String[128];
    mysql_real_escape_string(name,name);
    format(String,sizeof(String),"SELECT `Name`,`HouseMieteKey` FROM `accounts` WHERE `Name` = '%s' LIMIT 1",name);
    mysql_pquery(String,THREAD_OFFHAUSRAUS,playerid,gSQL,MySQLThreadOwner);
    return 1;
}


CMD:hausmenu(playerid,params[]) {
    new h = GetPlayerHouse(playerid);
    if( h == 999)return SendClientMessage(playerid, COLOR_RED, "Du besitzt kein Haus!");
    /*
    if(h == 999)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe eines Hauses.");
    */
    if( Spieler[playerid][pPlayerHouse] != h ) {
        return SendClientMessage(playerid,COLOR_RED,"Dieses Haus gehört nicht dir!");
    }
    if( !IsPlayerInHouse(playerid, Haus[h][hID]) ) {
        return SendClientMessage(playerid,COLOR_RED,"Du befindest dich nicht in deinem Haus");
    }
    /*
    if( h != GetPlayerHouse(playerid) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe deines Hauses.");
    }
    */
    ShowPlayerDialog(playerid,DIALOG_HAUSMENU,DIALOG_STYLE_LIST,"Hausmenu","\
    Haustuer AUF/ZU\n\
    Mietstatus: AN/AUS\n\
    Mieter anzeigen\n\
    Mieteranzahl ändern\n\
    Mietpreis ändern\n\
    Möbelkatalog\n\
    Möbel kaufen\n\
    Möbel bearbeiten\n\
    Möbel verkaufen\n","Weiter","Abbruch");
    return 1;
}


CMD:hausverstaatlichen(playerid,params[]) {
    new pHouse = GetPlayerHouse(playerid);
    if( pHouse == 999 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du besitzt kein Haus!");
    }
    if( Spieler[playerid][pPlayerHouse] == 999 ) {
        return SendClientMessage(playerid, COLOR_RED, "Das Haus, dessen Schlüssel du besitzt, gehört nicht dir!");
    }
    new h = IsPlayerAtHouse(playerid);
    if(h == 999) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe eines Hauses.");
    if( h != pHouse ) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe deines Hauses.");
    ShowPlayerDialog(playerid,DIALOG_BESTAETIGEN,DIALOG_STYLE_MSGBOX,"Möchtest du diesen Befehl genauso ausführen?",
    "Um Fehleingaben zu vermeiden, wird bei diesem Befehl sicherheitshalber nochmal um Bestätigung gebeten.",
    "AUSFÜHREN","ABBRECHEN");
    sichervar[playerid][0]=1;
    return 1;
}



CMD:hauskasse(playerid, params[])
{
    new entry, string[128], eingabe[16];
    if(sscanf(params, "s[16]i", eingabe, entry))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Hauskasse [Anlegen/Nehmen] [Betrag]");
    new h=IsPlayerAtHouse(playerid);
    if(h==999)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich vor keinem Haus.");
    if(entry < 1 || entry > 100000000)return SendClientMessage(playerid, COLOR_RED, "Der Betrag sollte zwischen $1 und $100.000.000 liegen.");
    if(strcmp(eingabe, "anlegen", true) == 0)
    {
        if(CheckMoney(playerid) < entry)return SendClientMessage(playerid, COLOR_RED, "Soviel Geld hast du nicht.");
        if(Spieler[playerid][pPlayerHouse] == h )
        {
            GivePlayerCash(playerid, -entry);
            Haus[h][hKasse] += entry;
            format(string, sizeof(string), "Du hast $%s in die Hauskasse eingezahlt. Neuer Stand: $%s.", AddDelimiters(entry), AddDelimiters(Haus[h][hKasse]));
            SendClientMessage(playerid, COLOR_WHITE, string);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer dieses Hauses.");
            return 1;
        }
    }
    else if(strcmp(eingabe, "nehmen", true) == 0)
    {
        if(Spieler[playerid][pPlayerHouse] == h )
        {
            if(entry > Haus[h][hKasse])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            GivePlayerCash(playerid, entry);
            Haus[h][hKasse] -= entry;
            format(string, sizeof(string), "Du hast $%s aus der Hauskasse ausgezahlt. Neuer Stand: $%s.", AddDelimiters(entry), AddDelimiters(Haus[h][hKasse]));
            SendClientMessage(playerid, COLOR_WHITE, string);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer dieses Hauses.");
            return 1;
        }
    }
    else return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Hauskasse [Anlegen/Nehmen] [Betrag]");
    return 1;
}



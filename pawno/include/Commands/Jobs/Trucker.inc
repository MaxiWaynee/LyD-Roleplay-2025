#include <YSI\y_hooks>


CMD:ladung(playerid, params[])
{
    new string[128];
    if(Spieler[playerid][pJob] == 3)
    {
        new vID = GetPlayerVehicleID(playerid);
        new model = GetVehicleModel(vID);
        if(model == 514)
        {
            if(IsTrailerAttachedToVehicle(vID))
            {
                if(GetVehicleModel(GetVehicleTrailer(vID)) == 584)
                {
                    new tempBenzin = Benzin[GetVehicleTrailer(vID)];
                    format(string, sizeof(string), "* Benzin-Stand: %d/4000 Liter *", tempBenzin);
                    SendClientMessage(playerid, COLOR_LIGHTGREEN, string);
                }
            }
        }
        else if(model == 515)
        {
            if(IsTrailerAttachedToVehicle(vID))
            {
                if(GetVehicleModel(GetVehicleTrailer(vID)) == 435)
                {
                    new tempWaren = Waren[vID];
                    format(string, sizeof(string), "* Waren-Stand: %d/2000 Waren *", tempWaren);
                    SendClientMessage(playerid, COLOR_LIGHTGREEN, string);
                 }
            }
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist kein Trucker!");
        return 1;
    }
    return 1;
}


CMD:loadwaren(playerid, params[])
{
    new string[128];
    new waren;
    if(sscanf(params, "i", waren))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Loadwaren [Waren] - $5 pro Ware!");
    if( Spieler[playerid][tickJobCheckpoint] > gettime() ) {
        return SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du kannst erst in {FFFF00}%d Sekunden {FFFFFF}weiterarbeiten.", Spieler[playerid][tickJobCheckpoint] - gettime());
        //return Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
    }
    if(IsPlayerInRangeOfPoint(playerid, 10.0, 577.4390,1221.7273,11.2689))
    {
        new vID = GetPlayerVehicleID(playerid);
        new model = GetVehicleModel(vID);
        if(model == 515)
        {
        if(IsTrailerAttachedToVehicle(vID))
            {
                new trailer = GetVehicleTrailer(vID);
                if(GetVehicleModel(trailer) == 435)
                {
                    new tempRechnung = waren*5;
                    if(CheckMoney(playerid) < tempRechnung)
                    {
                        format(string, sizeof(string), "Du hast nicht genügend Geld. ($%s)", AddDelimiters(tempRechnung));
                        SendClientMessage(playerid, COLOR_RED, string);
                        return 1;
                    }
                    if (waren < 1 || waren > 2000) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur zwischen 1 Ware und 2.000 Waren einladen!");
                    if (waren + Waren[vID] > 2000) return SendClientMessage(playerid, COLOR_RED, "Diese Menge an Waren passen nicht in den Anhänger nicht mehr hinein (/Ladung)!");
                    Waren[vID] += waren;
                    GivePlayerCash(playerid, -tempRechnung);
                    Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
                    format(string, sizeof(string), "* Du hast %d Waren für $%s gekauft.", waren, AddDelimiters(tempRechnung));
                    SendClientMessage(playerid, COLOR_LIGHTGREEN, string);
                    SendClientMessage(playerid, COLOR_YELLOW, "Mit '/Startwaren' erfährst du deinen Ablieferungsort!");
                    }
                    else
                    {
                        SendClientMessage(playerid, COLOR_RED, "Du hast nicht den passenden Anhänger angekoppelt.");
                        return 1;
                    }
                }
                else
                {
                    SendClientMessage(playerid, COLOR_RED, "Du hast keinen Anhänger angekoppelt.");
                    return 1;
                }
            }
            else
            {
                SendClientMessage(playerid, COLOR_RED, "Du sitzt nicht in den kleinen Transportern!");
                return 1;
            }
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht an der Waren-Vergabe in LV. Tippe /Navi -> Weitere Orte -> LV Waren-Vergabe.");
        return 1;
    }
    return 1;
}

CMD:loadbenzin(playerid, params[])
{
    new string[128];
    new benzin;
    if(sscanf(params, "i", benzin))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Loadbenzin [Benzin] - $6 pro Liter!");
    if( Spieler[playerid][tickJobCheckpoint] > gettime() ) {
        return SCMFormatted(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du kannst erst in {FFFF00}%d Sekunden {FFFFFF}weiterarbeiten.", Spieler[playerid][tickJobCheckpoint] - gettime());
        //return Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
    }
    if(IsPlayerInRangeOfPoint(playerid, 20.0, 268.9609,1384.2981,10.1610))
    {
        new vID = GetPlayerVehicleID(playerid);
        new model = GetVehicleModel(vID);
        if(model == 514)
        {
            if(IsTrailerAttachedToVehicle(vID))
            {
                new trailer = GetVehicleTrailer(vID);
                if(GetVehicleModel(trailer) == 584)
                {
                    new tempRechnung = benzin*6;
                    if(CheckMoney(playerid) < tempRechnung)
                    {
                        format(string, sizeof(string), "Du hast nicht genügend Geld. ($%s)", AddDelimiters(tempRechnung));
                        SendClientMessage(playerid, COLOR_RED, string);
                        return 1;
                    }
                    if(benzin < 1 || benzin > 4000)return SendClientMessage(playerid, COLOR_RED, "Du kannst mindestens 1 Liter und höchstens 4000 Liter beladen!");
                    if(benzin + Benzin[trailer] > 4000)
                    {
                        SendClientMessage(playerid, COLOR_RED, "Diese Menge an Benzin passt in den Anhänger nicht mehr hinein (/Ladung)!");
                        return 1;
                    }
                    Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
                    Benzin[trailer] += benzin;
                    GivePlayerCash(playerid, -tempRechnung);
                    format(string, sizeof(string), "* Du hast %d Liter für $%s gekauft.", benzin, AddDelimiters(tempRechnung));
                    SendClientMessage(playerid, COLOR_LIGHTGREEN, string);
                    SendClientMessage(playerid, COLOR_YELLOW, "Mit '/Startbenzin' erfährst du deinen Ablieferungsort!");
                }
                else
                {
                    SendClientMessage(playerid, COLOR_RED, "Du hast nicht den passenden Anhänger angekoppelt.");
                    return 1;
                }
            }
            else
            {
                SendClientMessage(playerid, COLOR_RED, "Du hast keinen Anhänger angekoppelt.");
                return 1;
            }
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du sitzt nicht im Tanker.");
            return 1;
        }
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht an der Öl-Raffinerie. Tippe /Navi -> Weitere Orte -> Öl-Raffinerie.");
        return 1;
    }
    return 1;
}


CMD:entladen(playerid,params[]) {
    if( Spieler[playerid][pJob] != 3 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du musst Trucker sein, für diese Funktion.");
    }
    if( CP_TRUCKERWAREN == pCheckpoint[playerid] || CP_TRUCKERWAREN2 == pCheckpoint[playerid]) {
        // Waren
        new vehicleid = GetPlayerVehicleID(playerid);
        if( !vehicleid ) {
            return SendClientMessage(playerid,COLOR_RED,"Du sitzt in keinem Fahrzeug.");
        }
        new modelid = GetVehicleModel(vehicleid);
        if ( !(modelid == 514 || modelid == 515) ) {
            return SendClientMessage(playerid,COLOR_RED,"Du musst in einem LKW sitzen für diese Funktion.");
        }
        new trailer = GetVehicleTrailer(vehicleid);
        if( !trailer ) {
            return SendClientMessage(playerid, COLOR_RED, "Du hast keinen Anhänger hinten dran.");
        }
        if( GetVehicleModel(trailer) != 435) {
                return SendClientMessage(playerid, COLOR_RED, "Du hast nicht den passenden Anhänger dran.");
        }
        if( Waren[vehicleid] < 1 ) {
            return SendClientMessage(playerid,COLOR_RED,"Du hast keine Waren aufgeladen.");
        }
        if( CP_TRUCKERWAREN == pCheckpoint[playerid] && !IsPlayerInRangeOfPoint(playerid,6.0,2187.6926,-2263.8967,13.4674) ) {
            return SendClientMessage(playerid,COLOR_RED,"Du kannst die Ware hier nicht abladen.");
        }
        if( CP_TRUCKERWAREN2 == pCheckpoint[playerid] && !IsPlayerInRangeOfPoint(playerid,6.0,2571.6233,-2226.6980,13.3550) ) {
            return SendClientMessage(playerid,COLOR_RED,"Du kannst die Ware hier nicht abladen.");
        }
        new ppw = RandomEx(14, 16);
        new preis = ppw * Waren[vehicleid];
        new String[128];
        format(String,sizeof(String),"Du hast %d Waren für je $%d pro Ware verkauft ($%s).",Waren[vehicleid],ppw, AddDelimiters(preis));
        SendClientMessage(playerid,COLOR_YELLOW,String);
        GivePlayerCash(playerid,preis);        
        g_Firma[GetJobFirmaIndex(3)][F_iKasse] += floatround(preis / 4, floatround_floor);
        Spieler[playerid][tickJobCheckpoint] = gettime() + (3*60);
        if( CP_TRUCKERWAREN == pCheckpoint[playerid] ) {
            StaticBiz[0][SBD_iWaren] += Waren[vehicleid];
            UpdateStaticBizText(0);
        }
        else if( CP_TRUCKERWAREN2 == pCheckpoint[playerid] ) {
            StaticBiz[1][SBD_iWaren] += Waren[vehicleid];
            UpdateStaticBizText(1);
        }
        Waren[vehicleid] = 0;
        DisablePlayerCheckpointEx(playerid);
    }
    else if( CP_TRUCKERTANK == pCheckpoint[playerid] || CP_TRUCKERTANK2 == pCheckpoint[playerid]) {
        // Benzin
        new vehicleid = GetPlayerVehicleID(playerid);
        if( !vehicleid ) {
            return SendClientMessage(playerid,COLOR_RED,"Du sitzt in keinem Fahrzeug.");
        }
        new modelid = GetVehicleModel(vehicleid);
        if( modelid != 514 ) {
            return SendClientMessage(playerid,COLOR_RED,"Du musst dafür in einem Tanklaster sitzen.");
        }
        new trailer = GetVehicleTrailer(vehicleid);
        if( !trailer ) {
            return SendClientMessage(playerid, COLOR_RED, "Du hast keinen Anhänger hinten dran.");
        }
        if( GetVehicleModel(trailer) != 584) {
            return SendClientMessage(playerid, COLOR_RED, "Du hast nicht den passenden Anhänger dran.");
        }
        if( Benzin[trailer] < 1 ) {
            return SendClientMessage(playerid,COLOR_RED,"Du hast kein Benzin beladen.");
        }
        if( CP_TRUCKERTANK == pCheckpoint[playerid] && !IsPlayerInRangeOfPoint(playerid,6.0,-1034.6223,-626.2365,32.0078) ) {
            return SendClientMessage(playerid,COLOR_RED,"Du kannst das Benzin hier nicht abladen.");
        }
        if( CP_TRUCKERTANK2 == pCheckpoint[playerid] && !IsPlayerInRangeOfPoint(playerid,6.0,2482.8813,-2084.2239,13.5469) ) {
            return SendClientMessage(playerid,COLOR_RED,"Du kannst das Benzin hier nicht abladen.");
        }
        new ppw = RandomEx(11,12);
        new preis = ppw * Benzin[trailer];
        new String[128];
        format(String,sizeof(String),"Du hast %d Liter Benzin für je $%d pro Liter verkauft ($%s).",Benzin[trailer],ppw, AddDelimiters(preis));
        SendClientMessage(playerid,COLOR_YELLOW,String);
        GivePlayerCash(playerid,preis);
        g_Firma[GetJobFirmaIndex(3)][F_iKasse] += floatround(preis / 4, floatround_floor);
        Spieler[playerid][tickJobCheckpoint] = gettime() + (3*60);
        if( CP_TRUCKERTANK == pCheckpoint[playerid] ) {
            StaticBiz[2][SBD_iWaren] += Benzin[trailer];
            UpdateStaticBizText(2);
        }
        else if( CP_TRUCKERTANK2 == pCheckpoint[playerid] ) {
            StaticBiz[3][SBD_iWaren] += Benzin[trailer];
            UpdateStaticBizText(3);
        }
        Benzin[trailer] = 0;
        DisablePlayerCheckpointEx(playerid);
    }
    else {
        return SendClientMessage(playerid,COLOR_ORANGE,"Du hast die Mission gar nicht gestartet.");
    }
    return 1;
}


CMD:startwaren(playerid,params[]) {
    if( Spieler[playerid][pJob] != 3 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du musst Trucker sein, für diese Funktion.");
    }
    new vehicleid = GetPlayerVehicleID(playerid);
    if( !vehicleid ) {
        return SendClientMessage(playerid,COLOR_RED,"Du sitzt in keinem Fahrzeug.");
    }
    new modelid = GetVehicleModel(vehicleid);
    if( modelid != 515) {
        return SendClientMessage(playerid,COLOR_RED,"Du musst in einem LKW sitzen für diese Funktion.");
    }
    new trailer = GetVehicleTrailer(vehicleid);
    if( !trailer ) {
        return SendClientMessage(playerid, COLOR_RED, "Du hast keinen Anhänger hinten dran.");
    }
    if( GetVehicleModel(trailer) != 435) {
        return SendClientMessage(playerid, COLOR_RED, "Du hast nicht den passenden Anhänger dran.");
    }
    if( Waren[vehicleid] < 1 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du hast keine Waren aufgeladen.");
    }
    if( Spieler[playerid][pTruckerBlock] > gettime() ) {
        return SendClientMessage(playerid,COLOR_RED,"Eine neue Route kann für dich aktuell nicht kalkuliert werden.");
    }
    new
        r = random(2);
    if(r == 0 ) {
        SetPlayerCheckpointEx(playerid,2187.6926,-2263.8967,13.4674,5.0,CP_TRUCKERWAREN);
    }
    else if(r == 1 ) {
        SetPlayerCheckpointEx(playerid,2571.6233,-2226.6980,13.3550,5.0,CP_TRUCKERWAREN2);
    }
    SendClientMessage(playerid,COLOR_YELLOW,"Du kannst die Waren nun zu der markierten Position liefern.");
    Spieler[playerid][pTruckerBlock] = gettime() + 5*60;
    return 1;
}
CMD:startbenzin(playerid,params[]) {
    if( Spieler[playerid][pJob] != 3 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du musst Trucker sein, für diese Funktion.");
    }
    new vehicleid = GetPlayerVehicleID(playerid);
    new modelid = GetVehicleModel(vehicleid);
    if( modelid != 514 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du musst in einem Tanklaster sitzen für diese Funktion.");
    }
    new trailer = GetVehicleTrailer(vehicleid);
    if( !trailer ) {
        return SendClientMessage(playerid, COLOR_RED, "Du hast keinen Anhänger hinten dran.");
    }
    if( GetVehicleModel(trailer) != 584) {
        return SendClientMessage(playerid, COLOR_RED, "Du hast nicht den passenden Anhänger dran.");
    }
    if( Benzin[trailer] < 1 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du hast kein Benzin beladen.");
    }
    if( Spieler[playerid][pTruckerBlock] > gettime() ) {
        return SendClientMessage(playerid,COLOR_RED,"Eine neue Route kann für dich aktuell nicht kalkuliert werden.");
    }
    new
        r = random(2);
    if(r == 0 ) {
        SetPlayerCheckpointEx(playerid,-1034.6223,-626.2365,32.0078,5.0,CP_TRUCKERTANK);
    }
    else if(r == 1 ) {
        SetPlayerCheckpointEx(playerid,2482.8813,-2084.2239,13.5469,5.0,CP_TRUCKERTANK2);
    }
    SendClientMessage(playerid,COLOR_YELLOW,"Du kannst das Benzin nun zu der markierten Position liefern.");
    Spieler[playerid][pTruckerBlock] = gettime() + 5*60;
    return 1;
}
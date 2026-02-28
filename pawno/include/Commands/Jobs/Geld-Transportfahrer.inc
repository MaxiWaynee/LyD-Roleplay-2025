#include <YSI\y_hooks>




CMD:starttransport(playerid)
{
    if(!(Spieler[playerid][pJob] == 12))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Geldtransport-Fahrer.");
    if( Spieler[playerid][pTransportActive] ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist bereits im Transport-Modus");
        return 1;
    }
    if( Spieler[playerid][tickJobCheckpoint] > gettime() ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst nur alle 5 Minuten arbeiten, bitte warte einen Moment!");
        //return Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
    }
    new
        vehicleid = GetPlayerVehicleID(playerid);
    if( !(aiVehicles[ vehicleid ] & VEH_GELDT) ) {
        return SendClientMessage(playerid, COLOR_RED, "Du befindest dich in keinem Geldtransporter.");
    }
    Spieler[playerid][pGELDT][0] = 0;
    Spieler[playerid][pGELDT][1] = 0;
    ShowNextGeldTStation(playerid);
    Spieler[playerid][tickJobCheckpoint] = gettime() + (5*60);
    SendClientMessage(playerid, COLOR_GREEN, "Du bist nun im Dienst und musst Bankautomaten mit Geld befüllen. Fahre die Marker ab und befolge die Anweisungen.");
    Spieler[playerid][pTransportActive] = true;
    return 1;
}

CMD:stoptransport(playerid)
{
    if(!(Spieler[playerid][pJob] == 12))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Geld-Transportfahrer.");
    SendClientMessage(playerid, COLOR_RED, "Du hast die Arbeit abgebrochen.");
    DisablePlayerCheckpointEx(playerid);
    return 1;
}


CMD:geldeinladen(playerid,params[]) {
    if(!(Spieler[playerid][pJob] == 12))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Geldtransport-Fahrer.");
    if( !(pCheckpoint[playerid] == CP_GELDT_ENTLEEREN) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst jetzt kein Geld in ein Automat laden.");
    new
        cp = Spieler[playerid][pGeldTCP];
    if( !IsPlayerInRangeOfPoint(playerid,2.0,GT_GELDT[cp][GT_fPosX],GT_GELDT[cp][GT_fPosY],GT_GELDT[cp][GT_fPosZ])) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist nicht am Geldautomaten!");
    }
    new vID = GetPlayerVehicleID(playerid);
    new model = GetVehicleModel(vID);
    if(model == 428)
    return SendClientMessage(playerid, COLOR_RED, "Du sitzt in keinem Geldtransporter!");
    new
        c;
    c += GetBitCount(Spieler[playerid][pGELDT][0]);
    c += GetBitCount(Spieler[playerid][pGELDT][1]);
    if( c >= 6 ) {
        SendClientMessage(playerid,COLOR_YELLOW,"Du hast alle 6 Geldautomaten befüllt! Fahre nun zurück zur Station.");
        SetPlayerCheckpointEx(playerid,1551.6464,-1019.4492,23.9063,5.0,CP_GELDTFINISH);
    }
    else {
        new
            String[128];
        format(String,sizeof(String),"Du hast den Geldautomaten befüllt! Steig ein und fahr zur nächsten (%d/6)",c);
        SendClientMessage(playerid,COLOR_YELLOW,String);
        ShowNextGeldTStation(playerid);
    }
    return 1;
}



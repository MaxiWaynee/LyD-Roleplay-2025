#include <YSI\y_hooks>


CMD:tascheklauen(playerid,params[]) {
    new giveid, Float:X, Float:Y, Float:Z, String[128];
    if( Spieler[playerid][pJob] != 19 ) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Taschendieb");
    if(Spieler[playerid][pLevel] < 3)return SendClientMessage(playerid, COLOR_RED, "Du musst mindestens Level 3 sein um andere beklauen zu können!");
    if( Spieler[playerid][pTimerTaschendieb] != INVALID_TIMER_ID ) return SendClientMessage(playerid,COLOR_RED,"Du hast erst vor kurzem jemanden beklaut! Warte 1 Minute.");
    if(sscanf(params,"u",giveid)) return SendClientMessage(playerid,COLOR_BLUE, INFO_STRING"/Tascheklauen [Spieler]");
    if( !IsPlayerConnected(giveid) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if( playerid == giveid )return SendClientMessage(playerid, COLOR_RED, "Du kannst dich nicht selber berauben.");
    if(IsAFK[playerid] == 1) return SendClientMessage(playerid,COLOR_RED,"Der Spieler ist im AFK-Modus.");
    GetPlayerPos(playerid,X,Y,Z);
    if( !IsPlayerInRangeOfPoint(giveid, 4.0 , X, Y, Z ) ) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist zu weit von dir entfernt.");
    if( IsPlayerInAnyVehicle(playerid) ) return SendClientMessage(playerid, COLOR_RED, "Du kannst nicht aus einem Fahrzeug heraus bestehlen.");
    if( IsPlayerInAnyVehicle(giveid) )return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Spieler in einem Fahrzeug bestehlen.");
    if( Spieler[giveid][pLevel] <= 2 ) return SendClientMessage(playerid, COLOR_RED, "Du kannst keinen Spieler mit einem Level unter 2 bestehlen.");
    if( Spieler[playerid][pUnixTaschendieb] > gettime() ) return SendClientMessage(playerid, COLOR_ORANGE, "Du musst ein einen Moment warten, bist du erneut jemanden beklauen kannst.");
    if( Spieler[playerid][pJailed] ) return SendClientMessage(playerid, COLOR_RED, "Im Knast kannst du kein anderen Spieler beklauen!");
    if( 1 <= Spieler[playerid][pJailed] <= 3 ) return SendClientMessage(playerid, COLOR_RED, "Du kannst keine eingesperrten Spieler beklauen!");
    // Wir können rauben!
    format(String,sizeof(String),"%s"#COLOR_HEX_WHITE" versucht "#COLOR_HEX_ORANGE"%s "#COLOR_HEX_WHITE"zu "#COLOR_HEX_RED"überfallen!",GetName(playerid),GetName(giveid));
    SendRoundMessage(X,Y,Z, COLOR_ORANGE, String , 25.0);
    format(String,sizeof(String),"Du wirst von %s überfallen! Renne schnell weg!",GetName(playerid));
    SendClientMessage(giveid, COLOR_BLUE, String );
    Spieler[playerid][pTimerTaschendieb] = SetTimerEx("Pulse_Taschendieb",491,true,"dd",playerid,giveid);
    Spieler[playerid][pTaschendiebCount] = 0;
    Spieler[playerid][pUnixTaschendieb] = gettime() + 60; // 60sec = 1min;
    format(String,sizeof(String),"Taschendieb %s versucht %s zu überfallen. ",GetName(playerid),GetName(giveid));
    TaschendiebLog(String);
    return 1;
}
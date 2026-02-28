#include <YSI\y_hooks>

new AusbruchTimer[MAX_PLAYERS];
new InfoTimer[MAX_PLAYERS];
new brichtaus[MAX_PLAYERS];

enum AusbruchSpawn {Float:SpawnX, Float:SpawnY, Float:SpawnZ}
new e_ausbruchspawn[][AusbruchSpawn] = {
{1555.9565,-1746.9595,14.0469},
{1540.9618,-1713.3969,13.9816},
{1503.6793,-1661.4690,13.2964},
{1492.9340,-1609.1428,13.2964},
{1598.8845,-1556.8953,13.5903},
{1636.0522,-1666.2041,13.5815},
{1644.3580,-1746.5144,14.1419},
{1543.0597,-1831.6046,14.0469} 
};

new e_ausbruchtext[] = {
    " Du wurdest von Berkan Tekin erwischt und zurück in die Zelle geboxt.",
    " Du bist auf einen großen Stein gestoßen und deine Schaufel ist gebrochen.",
    " Du hast eine Elektro-Leitung getroffen und deine Schaufel wurde zerstört.",
    " Ein Wasserrohr ist im Weg, hier kommst du nicht weiter."
};

CMD:ausbrechen(playerid) {
    if(Spieler[playerid][pJailed] != 1) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht im Gefängnis.");
    if(!Spieler[playerid][pSchaufel]) return SendClientMessage(playerid, COLOR_RED,"Du hast keine Schaufel.");
    if(brichtaus[playerid]) return SendClientMessage(playerid, COLOR_RED,"Du versuchst bereits auszubrechen.");
    if(Spieler[playerid][pJailTime] < 90) return SendClientMessage(playerid, COLOR_RED,"Du bist weniger als 90 Sekunden im Gefängnis.");
    SendClientMessage(playerid,COLOR_YELLOW,"[Ausbruch]{FFFFFF} Du versuchst aus dem Gefängnis auszubrechen.");
    AusbruchTimer[playerid] = SetTimerEx("Ausbruch", 90000, false, "d",playerid);
    InfoTimer[playerid] = SetTimerEx("AusbruchInfo", 30000, false, "d",playerid);
    brichtaus[playerid] = 1;
    ClearAnimations(playerid);
    SetPlayerAttachedObject(playerid,9,337,6,0.122999,-0.027999,0.179000,1.499999,51.000011,-2.299999,1.000000,1.000000,1.000000);
    LoopingAnim(playerid,"CHAINSAW", "CSAW_G", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

forward AusbruchInfo(playerid);
public AusbruchInfo(playerid) {
    new string[128];
    format(string,sizeof(string),"[Ausbruch]{FFFFFF}Man hört Geräusche im Zellentrakt.");
    SendExecutiveMessage(COLOR_DARKRED,string);
    KillTimer(InfoTimer[playerid]);
    return 1;
}

forward Ausbruch(playerid);
public Ausbruch(playerid) {
    
    new ausbruchwanteds = floatround(Spieler[playerid][pJailTime] / 90, floatround_ceil);
    new ausbruchchance = RandomEx(0,9);
    new randommsg = RandomEx(0,3);
    if(ausbruchchance < 4) {
        SCMFormatted(playerid,COLOR_RED,"%s",e_ausbruchtext[randommsg]);
        RemovePlayerAttachedObject(playerid, 9);
        Spieler[playerid][pSchaufel] -= 1;
        brichtaus[playerid] = 0;
        ClearAnimations(playerid);
        KillTimer(AusbruchTimer[playerid]);
    } else {
        Spieler[playerid][pJailed] = 0;
        Spieler[playerid][pWanteds] += ausbruchwanteds;
        SendClientMessage(playerid,COLOR_DARKRED,"Du hast ein Verbrechen begangen (Gefängnis-Ausbruch) Reporter: Überwachungssystem");
        SCMFormatted(playerid,COLOR_DARKRED,"Du hast %d Wanteds erhalten!",Spieler[playerid][pWanteds]);
        new string[128];
        format(string,sizeof(string),"%s hat ein Verbrechen begangen (Gefängnis-Ausbruch) Wanteds: %d",GetName(playerid),Spieler[playerid][pWanteds]);
        SendExecutiveMessage(COLOR_DARKRED,string);
        brichtaus[playerid] = 0;
        new aspawn = RandomEx(0,7);
        SetPlayerPosEx(playerid,e_ausbruchspawn[aspawn][SpawnX],e_ausbruchspawn[aspawn][SpawnY],e_ausbruchspawn[aspawn][SpawnZ],0,0);
        RemovePlayerAttachedObject(playerid, 9);
        ApplyAnimation(playerid, "Attractors", "Stepsit_out", 4.1, 0, 0, 0, 1, 0);
        KillTimer(AusbruchTimer[playerid]);
    }
    return 1;
}

hook OnPlayerSpawn(playerid) {
    brichtaus[playerid] = 0;
    return 1;
}

hook OnPlayerTot(playerid) {
    brichtaus[playerid] = 0;
    return 1;
}

hook OnPlayerDeath(playerid) {
    brichtaus[playerid] = 0;
    return 1;
}

hook OnPlayerConnect(playerid) {
    brichtaus[playerid] = 0;
    Spieler[playerid][pSchaufel] = 0;
    return 1;
}
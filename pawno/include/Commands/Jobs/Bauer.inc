#include <YSI\y_hooks>


CMD:stopharvest(playerid)
{
    if(!(Spieler[playerid][pJob] == 1))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Farmer.");
    SendClientMessage(playerid, COLOR_RED, "Du hast die Arbeit abgebrochen.");
    DisablePlayerCheckpointEx(playerid);
    return 1;
}


CMD:startbauer(playerid,params[]) {
    if(!(Spieler[playerid][pJob] == 1))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Farmer.");
    if( Spieler[playerid][tickJobCheckpoint] > gettime() ) {
        SendClientMessage(playerid, COLOR_RED, "Du kannst nur alle 5 Minuten arbeiten, bitte warte einen Moment!");
        return 1;
    }
    if( Spieler[playerid][pCowJob] != 0 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du bist noch in einem Farmer Job aktiv.");
    }
    ShowPlayerDialog(playerid,DIALOG_STARTBAUER,DIALOG_STYLE_LIST,"Bauer","Feld abernten\nKühe melken","Ausüben","Abbruch");
    return 1;
}
CMD:stopbauer(playerid,params[]) {
    DisablePlayerCheckpointEx(playerid);
    Spieler[playerid][pCow][0] = 0;
    Spieler[playerid][pCow][1] = 0;
    Spieler[playerid][pCow][2] = 0;
    Spieler[playerid][pCow] = 0;
    Spieler[playerid][pCowJob] = 0;
    RemovePlayerAttachedObject(playerid, ATTACHED_INDEX_JOB );
    return 1;
}
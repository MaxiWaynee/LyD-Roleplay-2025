#include <YSI\y_hooks>


CMD:dfinden(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pJob] != 14) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist kein Detektiv.");
    if ((Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22)) return SendClientMessage(playerid, COLOR_RED, "Du bist ein Exekutivbeamter. Nutze /finden.");
    new giveid;
    if (sscanf(params, "u", giveid) || giveid == INVALID_PLAYER_ID) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Dfinden [Spieler]");
    if (playerid == giveid) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst dich selber nicht orten!");
    if (Spieler[giveid][pAdminDienst] || bIsSpectating[giveid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler kann nicht geortet werden.");
    if (Spieler[playerid][tickDfind] > gettime()) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst noch nicht wieder orten.");

    new Float:X, Float:Y, Float:Z, zoneText[MAX_ZONE_NAME];
    GetPlayerPos(giveid,X,Y,Z);
    SetPlayerCheckpointEx(playerid, X, Y, Z, 1.0, CP_FINDEN);
    GetPlayer2DZone(giveid, zoneText, sizeof(zoneText));
    Spieler[playerid][tickDfind] = gettime() + GetPlayerDetectivSkillValue(playerid);
    PlayerSkillUpgrade(playerid, pDetektivPoints, 1, 1);
    return SCMFormatted(playerid, COLOR_ORANGE, "[DETEKTIV] {FFFFFF}%s befindet sich in %s, Gebäude-Komplex: %d.", GetName(giveid), zoneText, GetPlayerInterior(giveid));
}


CMD:dzeigen(playerid, params[]) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pJob] != 14) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist kein Detektiv.");
    if ((Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22)) return SendClientMessage(playerid, COLOR_RED, "Du bist ein Exekutivbeamter. Nutze /finden.");
    new giveid, pID;
    if (sscanf(params, "uu", pID, giveid) || pID == INVALID_PLAYER_ID || giveid == INVALID_PLAYER_ID)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING " /Dzeigen [Spieler (dem zu zeigenden)] [Spieler (den zu suchenden)]");
    if (playerid == giveid) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst dich selber nicht orten!");
    if (playerid == pID) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Nutze /DFinden um dir selber die Position eines Spieler anzuzeigen.");
    if (pID == giveid) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst einem Spieler nicht sich selbst zeigen.");

    if (Spieler[giveid][pAdminDienst] || bIsSpectating[giveid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler kann nicht geortet werden.");
    if (Spieler[playerid][tickDfind] > gettime()) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst noch nicht wieder orten.");

    if (!IsPlayerInRangeOfPlayer(playerid, pID, 15.0)) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Dein Kunde ist nicht in deiner Nähe.");

    new Float:X, Float:Y, Float:Z;
    GetPlayerPos(giveid, X, Y, Z);
    SetPlayerCheckpointEx(pID, X, Y, Z, 1.0, CP_FINDEN);
    Spieler[playerid][tickDfind] = gettime() + GetPlayerDetectivSkillValue(playerid);
    PlayerSkillUpgrade(playerid, pDetektivPoints, 1, 1);
    SCMFormatted(playerid, COLOR_GREEN, "[DETEKTIV] {FFFFFF}Du hast %s den Standort von %s gezeigt.", GetName(pID), GetName(giveid));
    SCMFormatted(pID, COLOR_GREEN, "[DETEKTIV] {FFFFFF}%s zeigt dir den Standort von %s.", GetName(playerid), GetName(giveid));
    return 1;
}


CMD:rufdetektiv(playerid,params[])
{
	new money, string[128];
	if(Spieler[playerid][pDuty] == 0)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht im Dienst.");
	if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist.");
	if(sscanf(params, "i",money))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Rufdetektiv [Vergütung]");
	if (money < 1000 || money > 80000) return SendClientMessage(playerid, COLOR_ORANGE, "Die Vergütung muss zwischen $1.000 und $80.000 liegen.");
	SCMFormatted(playerid, COLOR_BLUE,"Du hast ein Detektiv angefordert! Vergütung: $%s - Der Detektiv wurde zum Eingangsbereich des LSPD angefordert.",AddDelimiters(money));
	format(string, sizeof(string), "Beamter %s benötigt ein Detektiv. Bitte beim Eingangsbereich der Los Santos Polizei melden! Vergütung: $%s", GetName(playerid), AddDelimiters(money));
	SendJobMessage(14, COLOR_YELLOW, string);
	return 1;
}



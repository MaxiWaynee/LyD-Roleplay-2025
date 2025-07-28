#include <YSI\y_hooks>

CMD:frakwarn(playerid, params[]) {
    new spielerid, wanzahl;
    if (Spieler[playerid][pRank] < 5) return SendClientMessage(playerid, COLOR_RED, "Dafür hast du keine Berechtigung.");
    if (sscanf(params, "ui", spielerid, wanzahl)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/frakwarn [Spielername] [Anzahl]");
    if (!IsPlayerConnected(spielerid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (Spieler[playerid][pFraktion] != Spieler[spielerid][pFraktion]) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Fraktion.");
    if (Spieler[spielerid][pRank] > 4) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Leader nicht verwarnen.");
    if (wanzahl < 1) return SendClientMessage(playerid, COLOR_RED, "Du musst mindestens eine Verwarnung erteilen.");

    Spieler[spielerid][pfrakwarn] += wanzahl;
    SCMFormatted(playerid, COLOR_YELLOW, "Du hast dem Spieler %s erfolgreich %i Verwarnungen erteilt.", GetName(spielerid), wanzahl);
    SCMFormatted(spielerid, COLOR_RED, "Du hast von %s %i Verwarnungen bekommen, du hast nun %i Verwarnungen.", GetName(playerid), wanzahl, Spieler[spielerid][pfrakwarn]);
    if (Spieler[spielerid][pfrakwarn] >= 3) {
        RemovePlayerFromFaction(spielerid);
        SendClientMessage(spielerid, COLOR_RED, "Du wurdest wegen zu vielen Verwarnungen aus der Fraktion gekickt.");
    }

    return 1;
}


CMD:delfrakwarn(playerid, params[]) {
    new spielerid, wanzahl;
    if (Spieler[playerid][pRank] < 5) return SendClientMessage(playerid, COLOR_RED, "Dafür hast du keine Berechtigung.");
    if (sscanf(params, "ui", spielerid, wanzahl)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/delfrakwarn [Spielername] [Anzahl]");
    if (!IsPlayerConnected(spielerid)) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (Spieler[playerid][pFraktion] != Spieler[spielerid][pFraktion]) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Fraktion.");
    if (Spieler[spielerid][pRank] > 5) return SendClientMessage(playerid, COLOR_RED, "Du kannst den Leader nicht verwarnen.");
    if (wanzahl < 1) return SendClientMessage(playerid, COLOR_RED, "Du musst mindestens eine Verwarnung erlassen.");

    Spieler[spielerid][pfrakwarn] -= wanzahl;
    if (Spieler[spielerid][pfrakwarn] < 0) Spieler[spielerid][pfrakwarn] = 0;
    SCMFormatted(playerid, COLOR_YELLOW, "Du hast dem Spieler %s erfolgreich %i Verwarnungen entzogen.", GetName(spielerid), wanzahl);
    SCMFormatted(spielerid, COLOR_RED, "Du hast von %s %i Verwarnungen entzogen bekommen, du hast nun %i Verwarnungen.", GetName(playerid), wanzahl, Spieler[spielerid][pfrakwarn]);
    return 1;
}


CMD:einladen(playerid, params[])
{
    new pID, string[128];
    if(Spieler[playerid][pRank] < 5)return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du besitzt keinen Leader-Rank.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Einladen [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht online.");
    if(Spieler[pID][pFraktion] > 0)return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist noch in einer Fraktion.");
    if(IsGangInFight(Spieler[playerid][pFraktion])) return SendClientMessage(playerid,COLOR_RED,"[SPERRE]{FFFFFF} In einem Aktiven Gangfight nicht möglich.");
    if(HasBizfight(Spieler[playerid][pFraktion])) return SendClientMessage(playerid,COLOR_RED,"[SPERRE]{FFFFFF} In einem Aktiven Bizfight nicht möglich.");
    if(Spieler[pID][pFrakSperre]) {
        new String[128];
        format(String,sizeof(String),"%s hat versucht dich in die Fraktion einzuladen. Du hast allerdings noch eine Fraktionssperre!",GetName(playerid));
        SendClientMessage(pID,COLOR_RED,String);
        format(String,sizeof(String),"Du kannst %s nicht zur Fraktion einladen, da er noch eine Fraktions-Sperre hat",GetName(pID));
        SendClientMessage(playerid,COLOR_RED,String);
        return 1;
    }
    if(Spieler[pID][pLevel] < 4 ) {//4
        SendClientMessage(playerid,COLOR_RED,"[FEHLER] {FFFFFF}Du kannst den Spieler nicht einladen, da er unter Level 4 ist!");//4
        return 1;
    }

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x,y,z);
    if(IsPlayerInRangeOfPoint(pID, 5.0, x,y,z))
    {
        new team[50];
        ReturnPlayerFraktion(playerid, team);
        format(string, sizeof(string), "Du wurdest von %s in die Fraktion %s eingeladen.", GetName(playerid), team);
        SendClientMessage(pID, COLOR_YELLOW, string);
        SendClientMessage(pID, COLOR_YELLOW, "Tippe '/Accept Fraktion' um die Einladung anzunehmen.");
        FrakInviteID[pID] = Spieler[playerid][pFraktion];
        format(string, sizeof(string), "Du hast %s in die Fraktion eingeladen.", GetName(pID));
        SendClientMessage(playerid, COLOR_YELLOW, string);
        printf("%s lädt %s in Fraktion %s ein.", GetName(playerid), GetName(pID), team);
        return 1;
    }
    else return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist nicht in deiner Nähe.");
}


CMD:feuern(playerid, params[])
{
    new pID, string[128];
    if(Spieler[playerid][pRank] < 5)return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du besitzt keinen Co/Leader-Rank.");
    if(sscanf(params, "u", pID))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Feuern [SpielerID/Name]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht online.");
    if(!(Spieler[pID][pFraktion] == Spieler[playerid][pFraktion]))return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Der Spieler ist nicht in deiner Fraktion.");
    if(Spieler[pID][pRank] > 4)return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst den Leader nicht aus der Fraktion schmeißen.");
    format(string, sizeof(string), "Du wurdest von %s aus der Fraktion gefeuert. Du bist nun wieder Zivilist.", GetName(playerid));
    SendClientMessage(pID, COLOR_YELLOW, string);
    format(string, sizeof(string), "Du hast %s aus der Fraktion gefeuert.", GetName(pID));
    SendClientMessage(playerid, COLOR_YELLOW, string);
    RemovePlayerFromFaction(pID);
    printf("%s feuert %s aus Fraktion %d", GetName(playerid), GetName(pID), Spieler[playerid][pFraktion]);
    return 1;
}


CMD:setlohn(playerid, params[])
{
    new pID, string[128], lohn;
    if(!Spieler[playerid][pFraktion]) return SendClientMessage(playerid, COLOR_RED, "Du bist in keiner Fraktion.");
    if(Spieler[playerid][pRank] < 5)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Leader.");
    if(sscanf(params, "ui", pID, lohn))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Setlohn [SpielerID/Name] [Lohn]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(Spieler[playerid][pFraktion] != Spieler[pID][pFraktion])return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Fraktion.");
    new dFaction = IsADutyFaction(Spieler[playerid][pFraktion]);
    if (lohn < 0 || lohn > (dFaction ? 50000 : 40000)) return SCMFormatted(playerid, COLOR_RED, "Der Lohn sollte zwischen $1 und $%s liegen.", dFaction ? "50.000" : "40.000");
    Spieler[pID][pFrakLohn] = lohn;
    format(string, sizeof(string), "Dein Lohn wurde von Leader %s auf $%s gesetzt.", GetName(playerid), AddDelimiters(lohn));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    format(string, sizeof(string), "Du hast den Lohn von %s auf $%s gesetzt.", GetName(pID), AddDelimiters(lohn));
    SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    return 1;
}

CMD:setrank(playerid, params[])
{
    new pID, string[128], rankid;
    if(Spieler[playerid][pRank] < 5)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Leader.");
    if(sscanf(params, "ui", pID, rankid))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Setrank [SpielerID/Name] [Rank-ID]");
    if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if(pID == playerid)return SendClientMessage(playerid, COLOR_RED, "Du kannst deinen eigenen Rank nicht verändern!");
    if(Spieler[playerid][pFraktion] != Spieler[pID][pFraktion])return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht in deiner Fraktion.");
    if(Spieler[pID][pRank] > 5)return SendClientMessage(playerid, COLOR_RED, "Du kannst den Rank eines Leaders nicht verändern!");
    if(rankid < 0 || rankid > 5)return SendClientMessage(playerid, COLOR_RED, "Du musst eine Rank-ID zwischen 0 und 5 eingeben.");
    Spieler[pID][pRank] = rankid;
    format(string, sizeof(string), "[FRAKTIONS-NEWS] Der Rank von %s wurde von %s geändert. Er ist nun %s.", GetName(pID), GetName(playerid), GetRankName(Spieler[pID][pFraktion], Spieler[pID][pRank]));
    SendFraktionMessage(Spieler[playerid][pFraktion], COLOR_YELLOW, string);
    format(string, sizeof(string), "Du wurdest von %s auf den Rank %s gestuft.", GetName(playerid), GetRankName(Spieler[pID][pFraktion], Spieler[pID][pRank]));
    SendClientMessage(pID, COLOR_LIGHTBLUE, string);
    return 1;
}

CMD:offsetrank(playerid, params[]) {
    if (Spieler[playerid][pRank] < 5) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Leader.");

    new sSpieler[MAX_PLAYER_NAME], pID, amount;
    GetPVarString(playerid, "OFFSETRANK.NAME", sSpieler, sizeof(sSpieler));
    if (!isnull(sSpieler)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du gibst gerade noch jemandem offline einen Rank.");
    if (sscanf(params, "s[24]i", sSpieler, amount) || !amount) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Offsetrank [Spielername] [Rang]");
    if (!sscanf(sSpieler, "u", pID) && IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist zurzeit online. Benutze /Setrank.");
    if (amount < 0 || amount > 5) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Nein, das geht nicht!");
    new query[256];
    mysql_real_escape_string(sSpieler, sSpieler);
    SetPVarString(playerid, "OFFSETRANK.NAME", sSpieler);
    SetPVarInt(playerid, "OFFSETRANK.AMOUNT", amount);
    format(query, sizeof(query), "SELECT `Name`, `Fraktion`, `Rank` FROM `accounts` WHERE `Name` = '%s' LIMIT 1", sSpieler);
    mysql_pquery(query, THREAD_OFFSETRANK_CHECK, playerid, gSQL, MySQLThreadOwner);
    return 1;
}

CMD:offsetlohn(playerid, params[]) {
    if (Spieler[playerid][pRank] < 5) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Leader.");

    new sSpieler[MAX_PLAYER_NAME], pID, amount;
    GetPVarString(playerid, "OFFSETLOHN.NAME", sSpieler, sizeof(sSpieler));
    if (!isnull(sSpieler)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du gibst gerade noch jemandem offline einen Lohn.");
    if (sscanf(params, "s[24]i", sSpieler, amount) || !amount) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Offsetlohn [Spielername] [Lohn]");
    if (!sscanf(sSpieler, "u", pID) && IsPlayerConnected(pID)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Der Spieler ist zurzeit online. Benutze /Setlohn.");
    if (amount < 0 || amount > 40000) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Nein, das geht nicht!");
    new query[256];
    mysql_real_escape_string(sSpieler, sSpieler);
    SetPVarString(playerid, "OFFSETLOHN.NAME", sSpieler);
    SetPVarInt(playerid, "OFFSETLOHN.AMOUNT", amount);
    format(query, sizeof(query), "SELECT `Name`, `Fraktion`, `FrakLohn` FROM `accounts` WHERE `Name` = '%s' LIMIT 1", sSpieler);
    mysql_pquery(query, THREAD_OFFSETLOHN_CHECK, playerid, gSQL, MySQLThreadOwner);
    return 1;
}


CMD:configrank(playerid)
{
    new frakID = Spieler[playerid][pFraktion];
	if(Spieler[playerid][pFraktion] < 1)return SendClientMessage(playerid, COLOR_WHITE, ERROR_FRAKTION);
	if(Spieler[playerid][pRank] < 5)return SendClientMessage(playerid, COLOR_WHITE, ERROR_FRAKTION);
	strdel(DialogString, 0, sizeof(DialogString));
	format(DialogString, sizeof(DialogString), "{247BA6}0. {FFFFFF}Rang 0: %s\n{247BA6}1. {FFFFFF}Rang 1: %s\n{247BA6}2. {FFFFFF}Rang 2: %s\n{247BA6}3. {FFFFFF}Rang 3: %s\n{247BA6}4. {FFFFFF}Rang 4: %s\n{247BA6}5. {FFFFFF}Rang 5: %s\n{247BA6}6. {FFFFFF}Rang 6: %s",
	fRang[frakID][fRangName0],fRang[frakID][fRangName1], fRang[frakID][fRangName2], fRang[frakID][fRangName3], fRang[frakID][fRangName4], fRang[frakID][fRangName5],
	fRang[frakID][fRangName6]);
	ShowPlayerDialog(playerid, DIALOG_CONFIGRANK, DIALOG_STYLE_LIST, "{247BA6}Fraktion {FFFFFF}| Ränge Verwaltung", DialogString, "OK", "Abbrechen");
	return 1;
}


CMD:leaderhelp(playerid)
{
    new frak = Spieler[playerid][pFraktion];
    if( gPlayerLogged[playerid] == 0 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht eingeloggt");
    if(Spieler[playerid][pRank] < 5)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Leader.");
    SendClientMessage(playerid, COLOR_BLUE, "* LEADER *: {FFFFFF}/Einladen, /Feuern, /Setrank, /Setlohn, /Configrank");
    SendClientMessage(playerid, COLOR_BLUE, "* LEADER *: {FFFFFF}/Frakwarn, /Delfrakwarn, /Offsetrank, /Offsetlohn");
    if (frak == 1 || frak == 2 || frak == 3) { SendClientMessage(playerid, COLOR_BLUE, "* STAATSFRAKTION-LEADER *: {FFFFFF}/PMsg"); }
    if (IsAFightFaction(frak)) {
	    SendClientMessage(playerid, COLOR_BLUE, "* GANG-LEADER *: {FFFFFF}/Buendnisanfrage, /Buendnisannehmen, /Buendnisabbrechen, /Waffenlagerstatus, /Gebietinfo");
    }
    if(frak == 15) {
        SendClientMessage(playerid, COLOR_BLUE, "* NineDemons *: {FFFFFF}/WTSperre, /Drogensperre, /Spicesperre, /Wcodessperre");
    }
    SendClientMessage(playerid, COLOR_BLUE, "* FAHRZEUGE *: {FFFFFF}/FPark, /FRespawn");
    return 1;
}


CMD:fpark(playerid,params[]) {
    if(Spieler[playerid][pRank] < 5)return SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Co/Leader dieser Fraktion.");
	new veh = GetPlayerVehicleID(playerid);
    if(!IsPlayerInVehicle(playerid,veh)) return SendClientMessage(playerid,COLOR_RED,"Du sitzt in keinem Fraktionsfahrzeug.");
    if(FrakCarInfo[veh][f_frak] == Spieler[playerid][pFraktion]) {
        new query[256],Float:x,Float:y,Float:z,Float:r;
        GetVehiclePos(veh,x,y,z);
        GetVehicleZAngle(veh,r);
        format(query,sizeof(query),"UPDATE `"#SERVERFRAKCARS_DB"` SET `X`='%.3f', `Y`='%.3f',`Z`='%.3f',`R`='%.3f',`world`='%i' WHERE `id`='%i'",x,y,z,r,GetPlayerVirtualWorld(playerid),FrakCarInfo[veh][f_dbid]);
        mysql_tquery(gSQL,query);
		format(query,sizeof(query),"SELECT * FROM `"#SERVERFRAKCARS_DB"` WHERE `id`='%i'",FrakCarInfo[veh][f_dbid]);
		DestroyVehicle(veh);
        mysql_tquery(gSQL, query, "Reload_FCars");
        return SendClientMessage(playerid,COLOR_GREEN,"[INFO] "COLOR_HEX_WHITE"Du hast das Fraktionsfahrzeug umgeparkt.");
    }
    return 1;
}


CMD:frespawn(playerid) return cmd_respawncars(playerid);

CMD:respawncars(playerid)
{
	new string[128];
    if(Spieler[playerid][pFraktion] == 0) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst diesen Befehl nicht nutzen!");
	if(Spieler[playerid][pRank] < 3) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist kein Rank 3!");
	for(new i=0;i<GetVehiclePoolSize()+1;i++){
 		if(!IsValidVehicle(i)) continue;
 		if(FrakCarInfo[i][f_frak] != Spieler[playerid][pFraktion]) continue;
		if(!IsVehicleOccupied(i)){
		    if(!GetTowedCar(i)){
				SetVehicleToRespawn(i);
			}
		}
	}
	format(string, sizeof(string), "* Die %s Fahrzeuge wurden von %s respawnt.",factionNames[Spieler[playerid][pFraktion]], GetName(playerid));
	SendFraktionMessage(Spieler[playerid][pFraktion], COLOR_DARKRED, string);
	return 1;
}

CMD:findfcars(playerid){
    if(Spieler[playerid][pFraktion] == 0) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du kannst diesen Befehl nicht nutzen!");
    new String[2048];
    for(new i; i < MAX_VEHICLES; i++){
        if(Spieler[playerid][pFraktion] == FrakCarInfo[i][f_frak]){
            new modelid = GetVehicleModel(FrakCarInfo[i][f_veh]);
            if(FrakCarInfo[i][f_sperre] == true){
                format(String, sizeof(String), "%s{FFFFFF}%s [ID: %i] [{D84F18}ABGESCHLEPPT{FFFFFF}]\n", String, CarName[modelid-400], FrakCarInfo[i][f_veh]);
            }else{
                format(String, sizeof(String), "%s{FFFFFF}%s [ID: %i]\n", String, CarName[modelid-400], FrakCarInfo[i][f_veh]);
            }
        }else {
            //ShowPlayerDialog(playerid, DIALOG_NO_RESPONSE, DIALOG_STYLE_MSGBOX, "{D84F18}Information", "{FFFFFF}Deine Fraktion verfügt über keine Fraktionsfahrzeuge", "Schließen", "");
        }
    }
    ShowPlayerDialog(playerid, DIALOG_FINDFCAR, DIALOG_STYLE_LIST, "{D84F18}Fahrzeugliste", String, "Finden", "Schließen");
    return 1;
}


CMD:fc(playerid,params[])
{
	new text[96], string[128];
	if(Spieler[playerid][bMundbinde]) return SendClientMessage(playerid, COLOR_WHITE, "{AFAFAF}Du kannst momentan nicht sprechen.");
	if(sscanf(params, "s[96]", text))return SendClientMessage(playerid, COLOR_WHITE, "{247BA6}* Benutze: {00CC00}/fc [Nachricht]");
	if(Spieler[playerid][pMuted] > 0)
	{
		SendClientMessage(playerid, COLOR_WHITE, "{AFAFAF}Du wurdest stummgeschaltet.");
		return 1;
	}
	if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pFraktion] == 4 || Spieler[playerid][pFraktion] == 5
	|| Spieler[playerid][pFraktion] == 6 || Spieler[playerid][pFraktion] == 7 || Spieler[playerid][pFraktion] == 8 || Spieler[playerid][pFraktion] == 9 || Spieler[playerid][pFraktion] == 10
	|| Spieler[playerid][pFraktion] == 11 || Spieler[playerid][pFraktion] == 12 || Spieler[playerid][pFraktion] == 13 || Spieler[playerid][pFraktion] == 14 || Spieler[playerid][pFraktion] == 15
	|| Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 17 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 19 || Spieler[playerid][pFraktion] == 20
	|| Spieler[playerid][pFraktion] == 21 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_WHITE, ERROR_FRAKTION);
	format(string ,sizeof(string), "{33CCFF}** %s %s: %s **", GetRankName(Spieler[playerid][pFraktion], Spieler[playerid][pRank]), GetName(playerid), text);
	for(new i=0;i<GetMaxPlayers();i++)
	{
		if(IsPlayerConnected(i) && gPlayerLogged[i])
		{
			if(Spieler[i][pFraktion] == Spieler[playerid][pFraktion])
			{
				SendClientMessage(i, COLOR_WHITE, string);
			}
		}
	}
	return 1;
}



CMD:mitglieder(playerid)
{
    if(Spieler[playerid][pFraktion] < 1)return SendClientMessage(playerid, COLOR_RED, "Du bist in keiner Fraktion!");
    new
        query[160];
    pCurrentSite[playerid] = 0;
    format(query, sizeof(query), "SELECT `Name`, `Level`, `Rank`, `Fraktion`, `FrakLohn` FROM `accounts` WHERE `Fraktion` =%d ORDER BY `Rank` DESC LIMIT 0,30", Spieler[playerid][pFraktion]);
    mysql_pquery(query,THREAD_MITGLIEDER,playerid,gSQL,MySQLThreadOwner);
    return 1;
}



CMD:staatskasse(playerid, params[])
{
    new entry, string[128];
    if(sscanf(params, "i", entry))
    {
        SendClientMessage(playerid, COLOR_GREEN, "* Benutze /Staatskasse [Betrag] um dem Staat Geld zu spenden!");
        format(string, sizeof(string), "* Staats Kasse: $%s *", AddDelimiters(Kasse[Staat]));
        SendClientMessage(playerid, COLOR_ORANGE, string);
        return 1;
    }
    if(entry < 1 || entry > 50000000)return SendClientMessage(playerid, COLOR_RED, "Der Wert sollte zwischen $1 und $50.000.000 liegen.");
    if(CheckMoney(playerid) < entry)return SendClientMessage(playerid, COLOR_RED, "Soviel Geld hast du nicht!");
    TreasuryDeposit(entry);
    GivePlayerCash(playerid, -entry);
    format(string, sizeof(string), "* Du hast dem Staat $%s gespendet. Vielen Danke für die Spende!", AddDelimiters(entry));
    SendClientMessage(playerid, COLOR_GREEN, string);
    return 1;
}


new tickOpenGangJail, tOpenGangJail = INVALID_TIMER_ID;
CMD:aufbrechen(playerid,params[]) {
    if(Spieler[playerid][pTot] == 1 || Spieler[playerid][pTot] == 2 )return SendClientMessage(playerid, COLOR_RED, "Während du Tot bist, kannst du diese Funktion nicht nutzen.");
    if(!(Spieler[playerid][pFraktion] == 6 || Spieler[playerid][pFraktion] == 7 || Spieler[playerid][pFraktion] == 10 || Spieler[playerid][pFraktion] == 11 || Spieler[playerid][pFraktion] == 12 || Spieler[playerid][pFraktion] == 13 || Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2
    || Spieler[playerid][pFraktion] == 15 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 17 || Spieler[playerid][pFraktion] == 20 || Spieler[playerid][pFraktion] == 21  || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Polizist, Wheelmen oder Gang/Mafia Mitglied.");
    if(!IsPlayerInRangeOfPoint(playerid,5.0,2160.4111,-98.0815,2.8239)) return SendClientMessage(playerid,COLOR_GREEN,"Du bist nicht am Gangjail");
    if( Spieler[playerid][pJailed] == 4 ) return SendClientMessage(playerid,COLOR_RED,"Als Gefangener kannst du das Gangjail nicht knacken");
    if( tOpenGangJail != INVALID_TIMER_ID ) return SendClientMessage(playerid,COLOR_RED,"Es wird bereits versucht das Gangjail zu knacken");
    new Float:X, Float:Y, Float:Z, String[128];
    GetPlayerPos(playerid,X,Y,Z);
    format(String,sizeof(String),"%s versucht die Gangjail Tore aufzubrechen",GetName(playerid));
    tOpenGangJail = SetTimerEx("checkGangJail",1669,true,"d",playerid);
    tickOpenGangJail = gettime() + 30;
    SendRoundMessage(X,Y,Z,COLOR_LIGHTRED2,String);
    return 1;
}


CMD:leader(playerid,params[]) {
    //mysql_pquery("SELECT `Name`,`Fraktion` FROM `accounts` WHERE `Rank` >= 6 AND `Fraktion` <> 0 ORDER BY `Fraktion`",THREAD_LEADER,playerid,gSQL,MySQLThreadOwner);
    mysql_pquery("SELECT `Name`, `Level`, `Fraktion` FROM `accounts` WHERE `Rank` >= 6 AND `Fraktion` <> 0 ORDER BY `Fraktion`",THREAD_LEADER,playerid,gSQL,MySQLThreadOwner);
    return 1;
}


CMD:wantedticket(playerid,params[]) {
	#pragma unused params
	if( !IsPlayerInRangeOfPoint(playerid,3.0,LSPD_INTERIOR_WANTED_TICKET_POINT) )
 		return SendClientMessage(playerid, COLOR_RED, "Du kannst hier keine Wanted-Tickets kaufen");

	ShowWantedTicketList(playerid);
	return 1;
}
ShowWantedTicketList(playerid) {
    new
        String[128];
    if( !(1 <= Spieler[playerid][pWanteds] <= 3) ) {
        return SendClientMessage(playerid,COLOR_RED,"Du kannst kein Wanted-Ticket kaufen, weil du nicht unter 3 Wanted hast!");
    }
    for(new i ; i < sizeof(g_WantedTicket) ; i++) {
        format(String,sizeof(String),"%s%d Wanteds - $%s\n",String,g_WantedTicket[i][WT_iPoints], AddDelimiters(g_WantedTicket[i][WT_iPrice]));
    }
    ShowPlayerDialog(playerid,DIALOG_WANTEDTICKET,DIALOG_STYLE_LIST,"WantedTicket",String,"Kaufen","Abbruch");
    return 1;
}


CMD:zerbrechen(pID, params[])
{
    new string[128];
    if( !IsPlayerInRangeOfPoint(pID, 2.0, -382.0342,-1426.4521,26.0822) ) {
        return SendClientMessage(pID, COLOR_RED, "Du bist nicht beim Schmied!");
    }
    new Float:x, Float:y, Float:z;
    GetPlayerPos(pID, x,y,z);
    if( IsPlayerAttachedObjectSlotUsed(pID,ATTACHED_INDEX_HANDSCHELLE) ) {
        format(string, sizeof(string), "Der Schmied zerbricht die Handschellen von %s", GetName(pID));
        for(new i = 0 ; i < MAX_PLAYERS ; i++)
        {
            if(IsPlayerInRangeOfPoint(i, 10.0, x,y,z))
            {
                SendClientMessage(i, COLOR_PURPLE, string);
            }
        }
        SetPlayerSpecialAction(pID,SPECIAL_ACTION_NONE);
        RemovePlayerAttachedObject(pID,ATTACHED_INDEX_HANDSCHELLE);
        Cuffed[pID] = 0;
        GivePlayerCash(pID, -500);
    }
    return 1;
}


CMD:ergeben(playerid,params[]) {
	#pragma unused params
	if( !IsPlayerInRangeOfPoint(playerid,3.0, LSPD_INTERIOR_ERGEBEN_POINT))
	    return SendClientMessage(playerid, COLOR_RED, "Du kannst dich hier nicht ergeben");
	else
	if( Spieler[playerid][pJailed] )
		return SendClientMessage(playerid, COLOR_RED, "Du kannst dich nicht ergeben, wenn du schon im Knast bist!");
	else
	if( Spieler[playerid][pWanteds] < 1 )
	    return SendClientMessage(playerid, COLOR_RED, "Du hast keine Wanteds.");

	new
	    String[128];
	format(String,sizeof(String)," >> Straftäter %s hat sich der Polizei gestellt. <<",GetName(playerid));
	SendFraktionMessage(1, COLOR_RED, String);
	SendFraktionMessage(2, COLOR_RED, String);
	SendFraktionMessage(16, COLOR_RED, String);
	SendFraktionMessage(18, COLOR_RED, String);
	SendFraktionMessage(22, COLOR_RED, String);

    Spieler[playerid][pJailed] = 1;
    Spieler[playerid][pTot] = 0;
    Spieler[playerid][pJailTime] = 40 * Spieler[playerid][pWanteds];
    Spieler[playerid][pTotTime] = 0;
    Spieler[playerid][pTotX] = 0.0;
    Spieler[playerid][pTotY] = 0.0;
    Spieler[playerid][pTotZ] = 0.0;
    Spieler[playerid][pWanteds] = 0;
    DestroyDeathIcon(playerid);
    Cuffed[playerid] = 0;
    SpawnPlayerEx(playerid);

    format(String, sizeof(String), "Du hast dich ergeben! Pro Wanted werden dir 40 Sekunden Haftstrafe angerechnet. (Summe: %d)", Spieler[playerid][pJailTime]);
    SendClientMessage(playerid, COLOR_ORANGE, String);
    return 1;
}


CMD:findmpark(playerid) {
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "[FEHLER] {FFFFFF}Du bist nicht eingeloggt.");
    if (Spieler[playerid][pFraktion] < 1) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du bist in keiner Fraktion.");

    new dialogText[256];
    for (new i = 0; i < sizeof(g_FraktionAbschleppen); i++) {
        if (g_FraktionAbschleppen[i][FA_bAbgeschleppt] && g_FraktionAbschleppen[i][FA_fraktion] == Spieler[playerid][pFraktion])
            format(dialogText, sizeof(dialogText), "%s%s\n", dialogText, CarName[GetVehicleModel(i) - 400]);
    }

    if (isnull(dialogText)) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Es sind keine Fraktionsmotorräder abgeschleppt.");
    return ShowPlayerDialog(playerid, DIALOG_FINDMPARK, DIALOG_STYLE_LIST, "{FF9900}Abgeschleppte Motorräder", dialogText, "Orten", "Schließen");
}


CMD:kassenstand(playerid)
{
    new stand, string[128];
    if(Spieler[playerid][pFraktion] == 0)return SendClientMessage(playerid, COLOR_YELLOW, "Tippe /Staatskasse ein.");
    else if(Spieler[playerid][pFraktion] == 1)return SendClientMessage(playerid, COLOR_YELLOW, "Tippe /Staatskasse ein.");
    else if(Spieler[playerid][pFraktion] == 2)return SendClientMessage(playerid, COLOR_YELLOW, "Tippe /Staatskasse ein.");
    else if(Spieler[playerid][pFraktion] == 3){ stand = Kasse[Samd]; }
    else if(Spieler[playerid][pFraktion] == 4){ stand = Kasse[Sana]; }
    else if(Spieler[playerid][pFraktion] == 5){ stand = Kasse[Oamt]; }
    else if(Spieler[playerid][pFraktion] == 6){ stand = Kasse[Grove]; }
    else if(Spieler[playerid][pFraktion] == 7){ stand = Kasse[Ballas]; }
    else if(Spieler[playerid][pFraktion] == 8){ stand = Kasse[Fahrschule]; }
    else if(Spieler[playerid][pFraktion] == 9){ stand = Kasse[Staat]; }
    else if(Spieler[playerid][pFraktion] == 10){ stand = Kasse[Yakuza];}
    else if(Spieler[playerid][pFraktion] == 11){ stand = Kasse[Aztecas];}
    else if(Spieler[playerid][pFraktion] == 12){ stand = Kasse[LCN];}
    else if(Spieler[playerid][pFraktion] == 13){ stand = Kasse[Vagos];}
    else if(Spieler[playerid][pFraktion] == 14){ stand = Kasse[Hitman];}
    else if(Spieler[playerid][pFraktion] == 15){ stand = Kasse[BBikerZ];}
    else if(Spieler[playerid][pFraktion] == 16)return SendClientMessage(playerid, COLOR_YELLOW, "Tippe /Staatskasse ein.");
    else if(Spieler[playerid][pFraktion] == 17){ stand = Kasse[Wheelmenk];}
    else if(Spieler[playerid][pFraktion] == 18)return SendClientMessage(playerid, COLOR_YELLOW, "Tippe /Staatskasse ein.");
    else if(Spieler[playerid][pFraktion] == 19){ stand = Kasse[TerrorK];}
    else if(Spieler[playerid][pFraktion] == 20){ stand = Kasse[OutlawzK];}
    else if(Spieler[playerid][pFraktion] == 21){ stand = Kasse[ndgradethaK];}
    else if(Spieler[playerid][pFraktion] == 22)return SendClientMessage(playerid, COLOR_YELLOW, "Tippe /Staatskasse ein.");
    format(string, sizeof(string), "* Fraktionskasse: $%s *", AddDelimiters(stand));
    SendClientMessage(playerid, COLOR_GREEN, string);
    return 1;
}

CMD:kasse(playerid, params[])
{
    new entry, string[128], eingabe[32], fkasselog[128];
    if(sscanf(params, "s[32]i", eingabe, entry))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Kasse [Anlegen/Nehmen]");
    if(entry < 1 || entry > 100000000)return SendClientMessage(playerid, COLOR_RED, "Der Betrag sollte zwischen $1 und $100.000.000 liegen.");
    if(strcmp(eingabe, "anlegen", true) == 0)
    {
        if(CheckMoney(playerid) < entry)return SendClientMessage(playerid, COLOR_RED, "Soviel Geld hast du nicht!");
        if(Spieler[playerid][pFraktion] == 0)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Staatskasse [Betrag]");
        else if(Spieler[playerid][pFraktion] == 1)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Staatskasse [Betrag]");
        else if(Spieler[playerid][pFraktion] == 2)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Staatskasse [Betrag]");
        else if(Spieler[playerid][pFraktion] == 3)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Samd] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 4)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Sana] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 5)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Oamt] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 6)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Grove] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 7)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Ballas] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 8)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Fahrschule] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 9)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            TreasuryDeposit(entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 10)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Yakuza] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 11)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Aztecas] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 12)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[LCN] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 13)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Vagos] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 14)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Hitman] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 15)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[BBikerZ] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 16)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Staatskasse [Betrag]");
        else if(Spieler[playerid][pFraktion] == 17)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Wheelmenk] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 18)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Staatskasse [Betrag]");
        else if(Spieler[playerid][pFraktion] == 19)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[TerrorK] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 20)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[OutlawzK] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 21)
        {
            GivePlayerCash(playerid, -entry);
            format(string, sizeof(string), "* Du hast $%s in die %s Kasse eingezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[ndgradethaK] += entry;
            format(fkasselog, sizeof(fkasselog), "%s hat $%s in die %s Kasse eingezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 22)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Staatskasse [Betrag]");
    }
    else if(strcmp(eingabe, "nehmen", true) == 0)
    {
        if(Spieler[playerid][pRank] != 6 && Spieler[playerid][pFraktion] != 4)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Leader!");
        if(Spieler[playerid][pFraktion] == 0)return SendClientMessage(playerid, COLOR_RED, "* Du kannst nichts von der Staatskasse nehmen.");
        else if(Spieler[playerid][pFraktion] == 1)return SendClientMessage(playerid, COLOR_RED, "* Du kannst nichts von der Staatskasse nehmen.");
        else if(Spieler[playerid][pFraktion] == 2)return SendClientMessage(playerid, COLOR_RED, "* Du kannst nichts von der Staatskasse nehmen.");
        else if(Spieler[playerid][pFraktion] == 3)
        {
            if(entry > Kasse[Samd])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Samd] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 4)
        {
            if (Spieler[playerid][pRank] < 5) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Leader oder Co-Leader!");
            if(entry > Kasse[Sana])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Sana] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 5)
        {
            if(entry > Kasse[Oamt])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Oamt] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 6)
        {
            if(entry > Kasse[Grove])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Grove] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 7)
        {
            if(entry > Kasse[Ballas])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Ballas] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 8)
        {
            if(entry > Kasse[Fahrschule])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Fahrschule] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 9)
        {
            if(entry > Kasse[Staat])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Staatskasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Staat] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 10)
        {
            if(entry > Kasse[Yakuza])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Yakuza] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 11)
        {
            if(entry > Kasse[Aztecas])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Aztecas] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 12)
        {
            if(entry > Kasse[LCN])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[LCN] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 13)
        {
            if(entry > Kasse[Vagos])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Vagos] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 14)
        {
            if(entry > Kasse[Hitman])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Hitman] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 15)
        {
            if(entry > Kasse[BBikerZ])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[BBikerZ] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 16)return SendClientMessage(playerid, COLOR_RED, "* Du kannst nichts von der Staatskasse nehmen.");
        else if(Spieler[playerid][pFraktion] == 17)
        {
            if(entry > Kasse[Wheelmenk])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[Wheelmenk] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 18)return SendClientMessage(playerid, COLOR_RED, "* Du kannst nichts von der Staatskasse nehmen.");
        else if(Spieler[playerid][pFraktion] == 19)
        {
            if(entry > Kasse[TerrorK])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[TerrorK] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 20)
        {
            if(entry > Kasse[OutlawzK])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[OutlawzK] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 21)
        {
            if(entry > Kasse[ndgradethaK])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            format(string, sizeof(string), "* Du hast $%s aus der %s Kasse ausgezahlt.", AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            SendClientMessage(playerid, COLOR_WHITE, string);
            Kasse[ndgradethaK] -= entry;
            GivePlayerCash(playerid, entry);
            format(fkasselog, sizeof(fkasselog), "%s hat $%s aus der %s Kasse ausgezahlt", GetName(playerid), AddDelimiters(entry), factionNames[Spieler[playerid][pFraktion]]);
            LogFrakkasse(fkasselog);
        }
        else if(Spieler[playerid][pFraktion] == 22)return SendClientMessage(playerid, COLOR_RED, "* Du kannst nichts von der Staatskasse nehmen.");
    }
    else return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/kasse [Anlegen/Nehmen/Stand]");
    return 1;
}



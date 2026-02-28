#include <YSI\y_hooks>



CMD:tankekaufen(playerid, params[])
{
    #if defined NEUE_WIRTSCHAFT
        return SendClientMessage(playerid, COLOR_RED, "Diese Funktion ist momentan deaktiviert!");
    #else
        if(Spieler[playerid][pPlayerTank] != 999 ) {
            return SendClientMessage(playerid, COLOR_RED, "Du besitzt bereits eine Tankstelle!");
        }
        if( Spieler[playerid][pLevel] < 5 ) {
            return SendClientMessage(playerid, COLOR_RED, "Dein Level ist zu niedrig um eine Tankstelle zu kaufen! Du musst Level 5 erreichen um eine Tankstelle kaufen zu können.");
        }
        for(new i=0;i<sizeof(Tanke);i++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, Tanke[i][EnterX], Tanke[i][EnterY], Tanke[i][EnterZ]))
            {
                if(strcmp(Tanke[i][tBesitzer], "Niemand", true) == 0)
                {
                    if(Spieler[playerid][pPerso] == 0)return SendClientMessage(playerid, COLOR_RED, "Du benötigst einen Personalausweis.");
                    if(CheckMoney(playerid) < Tanke[i][tPreis])return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht genügend Geld.");
                    new string[128];
                    Spieler[playerid][pPlayerTank] = i;
                    strmid(Tanke[i][tBesitzer], GetName(playerid), 0, MAX_PLAYER_NAME, 255);
                    GivePlayerCash(playerid, -Tanke[i][tPreis]);
                    format(string, sizeof(string), "Du hast erfolgreich diese Tankstelle gekauft. (-$%s)", AddDelimiters(Tanke[i][tPreis]));
                    SendClientMessage(playerid, COLOR_GREEN, string);
                    SendClientMessage(playerid, COLOR_WHITE, "Wichtige Befehle um deine Tankstelle zu verwalten findest du unter /Help -> Geschäfts-Befehle.");
                    SendClientMessage(playerid, COLOR_RED, "HINWEIS: Mach zur Datensicherung bitte ein Relog!");
                    ShowBuyInformation(playerid,"~y~Tankstelle ~w~gekauft!");
                    UpdateTankeText(i);
                }
                else {
                    SendClientMessage(playerid,COLOR_RED,"Diese Tankstelle gehört bereits einem Spieler.");
                }
                return 1;
            }
        }
        SendClientMessage(playerid,COLOR_RED,"Du befindest dich an keiner Tankstelle.");
        return 1;
    #endif
}


CMD:maxbenzin(playerid)
{
    new t = IsPlayerAtTanke(playerid);
    if(t == 999)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keiner Tankstelle.");
    if(strcmp(GetName(playerid), Tanke[t][tBesitzer], true) == 0)
    {
        ShowPlayerDialog(playerid, DIALOG_MAXBENZIN, DIALOG_STYLE_LIST, "Maximale Liter Anzahl ändern", "1000 Liter ($10.000)\n2000 Liter ($20.000)\n3000 Liter ($30.000)\n4000 Liter ($40.000)\n5000 Liter ($50.000)", "Auswählen", "Abbrechen");
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer der Tankstelle.");
        return 1;
    }
    return 1;
}

CMD:tankpreis(playerid, params[])
{
    new benzin, Preis, Benzintyp[16], string[128];
    if(sscanf(params, "is[16]", Preis,Benzintyp))
        return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Tankpreis [Preis] [Typ]");
    new t = IsPlayerAtTanke(playerid);
    if(t == 999)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keiner Tankstelle.");
    if( !strcmp(Benzintyp,"Benzin", true)) {
        benzin = 0;
    }
    else if( !strcmp(Benzintyp,"Super", true)) {
        benzin = 1;
    }
    else if( !strcmp(Benzintyp,"Diesel", true)) {
        benzin = 2;
    }
    else {
        benzin = -1;
    }
    if( benzin == -1 ) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Tankpreis [Preis] [Typ ( Benzin, Diesel, Super ) ]");

    if(strcmp(GetName(playerid), Tanke[t][tBesitzer], true) == 0)
    {
        if(Preis < 500 || Preis > 2000)return SendClientMessage(playerid, COLOR_ORANGE, "Der Preis muss zwischen $500 und $2000 liegen.");
        Tanke[t][taiFillCost][benzin] = Preis;
        format(string, sizeof(string), "[TANKE] {FFFFFF}Du hast den Benzinpreis von %s auf $%d gesetzt.", Benzintyp,Preis);
        SendClientMessage(playerid, 0x6DC0F4FF, string);
        UpdateTankeText(t);
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer der Tankstelle.");
        return 1;
    }
    return 1;
}


CMD:tankkassestand(playerid)
{
    new t = IsPlayerAtTanke(playerid);
    if(t == 999)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keiner Tankstelle.");
    if(Spieler[playerid][pAdmin] > 3 || strcmp(GetName(playerid), Tanke[t][tBesitzer], true) == 0)
    {
        new string[128];
        format(string, sizeof(string), "* Tankstellen-Kasse: $%s *", AddDelimiters(Tanke[t][tKasse]));
        SendClientMessage(playerid, COLOR_GREEN, string);
        SendClientMessage(playerid, COLOR_WHITE, "Um Geld von der Kasse zu nehmen oder anzulegen tippe /Tankkasse [Anlegen/Nehmen].");
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Da du nicht der Besitzer bist, kannst du auch nicht auf die Kasse schauen.");
        return 1;
    }
    return 1;
}

CMD:tankkasse(playerid, params[])
{
    new entry, string[128], eingabe[16];
    if(sscanf(params, "s[16]i", eingabe, entry))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Tankkasse [Anlegen/Nehmen] [Betrag]");
    new t = IsPlayerAtTanke(playerid);
    if(entry < 1 || entry > 100000000)return SendClientMessage(playerid, COLOR_RED, "Der Betrag sollte zwischen $1 und $100.000.000 liegen.");
    if(t == 999)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich vor keiner Tankstelle.");
    if(strcmp(eingabe, "anlegen", true) == 0)
    {
        if(CheckMoney(playerid) < entry)return SendClientMessage(playerid, COLOR_RED, "Soviel Geld hast du nicht.");
        if(strcmp(GetName(playerid), Tanke[t][tBesitzer], true) == 0)
        {
            GivePlayerCash(playerid, -entry);
            Tanke[t][tKasse] += entry;
            format(string, sizeof(string), "Du hast $%s in die Tankstellenkasse eingezahlt. Neuer Stand: $%s.", AddDelimiters(entry), AddDelimiters(Tanke[t][tKasse]));
            SendClientMessage(playerid, COLOR_WHITE ,string);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer dieser Tankstelle.");
            return 1;
        }
    }
    else if(strcmp(eingabe, "nehmen", true) == 0)
    {
        if(strcmp(GetName(playerid), Tanke[t][tBesitzer], true) == 0)
        {
            if(entry > Tanke[t][tKasse])return SendClientMessage(playerid, COLOR_RED, "Soviel Geld ist auf der Kasse nicht vorhanden.");
            GivePlayerCash(playerid, entry);
            Tanke[t][tKasse] -= entry;
            format(string, sizeof(string), "Du hast $%s aus der Tankstellenkasse ausgezahlt. Neuer Stand: $%s.", AddDelimiters(entry), AddDelimiters(Tanke[t][tKasse]));
            SendClientMessage(playerid, COLOR_WHITE, string);
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Du bist nicht der Besitzer dieser Tankstelle.");
            return 1;
        }
    }
    else return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Tankkasse [Anlegen/Nehmen] [Betrag]");
    return 1;
}


CMD:tankeverstaatlichen(playerid)
{
    new t=IsPlayerAtTanke(playerid);
    if(t==999)
    {
        SendClientMessage(playerid,COLOR_RED,"Du stehst an keiner Tankstelle.");
    }
    else if(strcmp(Tanke[t][tBesitzer],GetName(playerid),true)==0)
    {
        new
            erstattung,
            String[128];
        erstattung = (Tanke[t][tPreis] / 4);
        format(Tanke[t][tBesitzer],MAX_PLAYER_NAME,"Niemand");
        Spieler[playerid][pPlayerTank] = 999;
        if(Tanke[t][tKasse] > 0 ) {
            format(String,sizeof(String),"In deiner Tankkasse waren noch $%s. Du erhältst diese noch vor dem Verkauf zurück.", AddDelimiters(Tanke[t][tKasse]));
            SendClientMessage(playerid,COLOR_YELLOW,String);
            Spieler[playerid][pBank] += Tanke[t][tKasse];
        }
        Tanke[t][tKasse] = 0;
        Spieler[playerid][pBank] += erstattung;
        format(String,sizeof(String),"Du hast deine Tanke '%s' an den Staat für $%s verkauft.",Tanke[t][tName], AddDelimiters(erstattung));
        SendClientMessage(playerid,COLOR_WHITE,String);
        UpdateTankeText(t);
    }
    return 1;
}

CMD:tankstelleverkaufen(playerid,params[]) {
    new
        giveid,
        price;
    if(sscanf(params,"ud",giveid,price)) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Tankstelleverkaufen [ID] [PREIS](1.000.000$ bis 80.000.000$) ");
    }
    if( !( 1000000 <= price <= 80000000 )) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Tankstelleverkaufen [ID] [PREIS](1.000.000$ bis 80.000.000$) ");
    }
    new indextanke = Spieler[playerid][pPlayerTank];
    if( indextanke == 999) {
        return SendClientMessage(playerid, COLOR_RED, "Du besitzt keine Tankstelle!");
    }
    if( !IsPlayerConnected(giveid) || giveid == playerid) {
        SendClientMessage(playerid,COLOR_RED,"Ungültiger Spieler.");
        return 1;
    }
    if( Spieler[playerid][pTankeAngebot][0] != INVALID_PLAYER_ID ) {
        SendClientMessage(playerid,COLOR_RED,"Du hast die Tankstelle bereits einem Spieler angeboten.");
        return 1;
    }
    if( Spieler[giveid][pLevel] < 5 ) {
        SendClientMessage(playerid,COLOR_RED,"Du kannst eine Tankstelle nur an Spieler verkaufen, dessen Level über 5 liegt.");
        return 1;
    }
    ShowPlayerDialog(playerid,DIALOG_BESTAETIGEN,DIALOG_STYLE_MSGBOX,"Möchtest du diesen Befehl genauso ausführen?",
    "Um Fehleingaben zu vermeiden, wird bei diesem Befehl sicherheitshalber nochmal um Bestätigung gebeten.",
    "AUSFÜHREN","ABBRECHEN");
    sichervar[playerid][7]=1,sichervar[playerid][8]=giveid,sichervar[playerid][9]=price;
    return 1;
}
CMD:tankeverkaufen(playerid,params[]) {
    return cmd_tankstelleverkaufen(playerid,params);
}
CMD:tankstelleankaufen(playerid,params[]) {
    new
        giveid;
    if(sscanf(params,"u",giveid)) {
        return SendClientMessage(playerid, COLOR_RED,INFO_STRING"/Tankstelleankaufen [ID]");
    }
    if( !IsPlayerConnected(giveid) || giveid == playerid) {
        SendClientMessage(playerid,COLOR_RED,"Ungültiger Spieler");
        return 1;
    }
    if( Spieler[playerid][pPlayerTank] != 999 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du besitzt bereits ein Geschäft.");
    }
    if( Spieler[giveid][pPlayerTank] == 999) {
        return SendClientMessage(playerid, COLOR_RED, "Der Verkäufer ist nicht mehr in Besitz der Angebotenen Tankstelle");
    }
    if( Spieler[giveid][pTankeAngebot][0] != playerid ) {
        SendClientMessage(playerid,COLOR_RED,"Dieser Spieler hat dir keine Tankstelle zum Verkauf angeboten");
        return 1;
    }
    new indextanke = Spieler[giveid][pPlayerTank];
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
    price = Spieler[giveid][pTankeAngebot][1];
    if( price > Spieler[playerid][pCash] ) {
        format(string,sizeof(string),"Du hast nicht genug Geld auf der Hand um die Tankstelle zu kaufen ($%s)", AddDelimiters(price));
        return SendClientMessage(playerid, COLOR_RED, string);
    }
    format(string,sizeof(string),"Deine Tankstelle hast du an %s verkauft! Er hat dein Angebot angenommen und ist nun der neue Besitzer.",GetName(playerid));
    SendClientMessage(giveid,COLOR_YELLOW,string);
    format(string,sizeof(string),"Du hast die Tankstelle erfolgreich von %s abgekauft!",GetName(giveid));
    SendClientMessage(playerid,COLOR_YELLOW,string);
    SendClientMessage(playerid, COLOR_RED, "HINWEIS: Mach zur Datensicherung bitte ein Relog!");
    SendClientMessage(giveid, COLOR_RED, "HINWEIS: Mach zur Datensicherung bitte ein Relog!");

    format(string,sizeof(string),"[TANKEKAUF] Verkäufer: %s, Käufer: %s, Preis: %d",GetName(giveid),GetName(playerid),price);
    KaufLog(string);

    Spieler[giveid][pTankeAngebot][0] = INVALID_PLAYER_ID;
    Spieler[giveid][pTankeAngebot][1] = 0;
    Spieler[giveid][pPlayerTank] = 999;

    Tanke[indextanke][tVideoueberwachung] = false;
    Tanke[indextanke][tAutomatischerNotruf] = false;

    Tanke[indextanke][tErpresserFraktion] = 0;
    Tanke[indextanke][tErpresserForderung] = 0;
    Tanke[indextanke][tErpresserState] = 0;
    Tanke[indextanke][tKasse] = 0;

    Spieler[playerid][pPlayerTank] = indextanke;
    format( Tanke[indextanke][tBesitzer] , MAX_PLAYER_NAME , GetName(playerid) );
    GivePlayerCash(playerid, -price);
    GivePlayerCash(giveid, price);

    UpdateTankeText(indextanke);
    return 1;
}


CMD:tankstellensecurity(playerid,params[]) {
    new
        tank_index = Spieler[playerid][pPlayerTank];
    if(tank_index == 999)return SendClientMessage(playerid, COLOR_RED, "Du besitzt keine Tankstelle");
    if(strcmp(GetName(playerid), Tanke[tank_index][tBesitzer], true) == 0)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, Tanke[tank_index][EnterX], Tanke[tank_index][EnterY], Tanke[tank_index][EnterZ]))
        {
            ShowPlayerDialog(playerid,DIALOG_TANKSTELLEN_OPTION,DIALOG_STYLE_LIST,"Tankstellen Sicherheitsoptionen","Videoüberwachung - 30.000$\nAutomatischer Notruf an die Polizei - 120.000$","Weiter","Abbruch");
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


CMD:tankstelleausrauben(playerid,params[]) {
    if( Spieler[playerid][pLevel] < 5 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du musst mindestens Level 5 sein, um diese Aktion durchzuführen.");
    }
    new t = IsPlayerAtTanke(playerid);
    if(t == 999) {
        return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keiner Tankstelle.");
    }
    if( Spieler[playerid][tTankeUnix] != 0 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du überfällst bereits eine Tankstelle.");
    }
    if( !strcmp(Tanke[t][tBesitzer],"Niemand")) {
        return SendClientMessage(playerid, COLOR_RED, "Die Tankstelle kann nicht ausgeraubt werden");
    }
    if( Tanke[t][tRobberID] != INVALID_PLAYER_ID ) {
        return SendClientMessage(playerid, COLOR_RED, "Die Tankstelle wird bereits überfallen");
    }
    if( gettime() < Tanke[t][tUnixRob] ) {
        return SendClientMessage(playerid, COLOR_RED, "Die Tankstelle wurde erst vor kurzem ausgeraubt. Du musst noch warten.");
    }

    if( GetOnlineExecutive() < 4 ) {
        return SendClientMessage(playerid, COLOR_RED, "Es sind nicht genug Polizisten online.");
    }
    new
        String[128];
    // Nachricht an Täter
    SendClientMessage(playerid,COLOR_YELLOW,"Der Überfall wurde gestartet! Warte 3 Minuten und entferne dich nicht zu weit von der Stelle, ansonsten ist der Überfall fehlgeschlagen!");
    if( Tanke[t][tVideoueberwachung] == true && Tanke[t][tAutomatischerNotruf] == true ) {
        SendClientMessage(playerid,COLOR_RED,"Die Tankstelle besitzt ein Alarmsystem!");
        SendClientMessage(playerid,COLOR_RED,"Es wurde automatisch ein Notruf an die Polizei gesendet und der Inhaber über den Überfall benachrichtigt!");
    }
    else if( Tanke[t][tVideoueberwachung] == true ) {
        SendClientMessage(playerid,COLOR_RED,"Die Tankstelle wird Videoüberwacht! Der Inhaber wurde über den Überfall benachrichtigt.");
    }
    else if( Tanke[t][tAutomatischerNotruf] == true ) {
        SendClientMessage(playerid,COLOR_RED,"Die Tankstelle besitzt ein Alarmsystem und hat ein Notruf an die Polizei gesendet!");
    }
    // Nachricht an Besitzer
    if( Tanke[t][tVideoueberwachung] == true ) {
        new besitzerid;
        sscanf( Tanke[t][tBesitzer], "u",besitzerid);
        if( IsPlayerConnected(besitzerid) ) {
            SendClientMessage(besitzerid,COLOR_ORANGE,"Deine Tankstelle wird von einem Räuber überfallen! Die Polizei wurde darüber benachrichtigt.");
        }
    }
    // Nachricht an Polizei
    if( Tanke[t][tAutomatischerNotruf] == true ) {
        new ort[28];
        GetPoint2DZone(Tanke[t][EnterX], Tanke[t][EnterY], ort, 28);
        format(String,sizeof(String),"[ZENTRALE] Die Tankstelle von %s wird von %s überfallen! Ort: %s.",Tanke[t][tBesitzer],GetName(playerid), ort);
        SendExecutiveMessage(COLOR_RED,String);
    }

    Spieler[playerid][tTankeUeberfall] = SetTimerEx("Tankstelle_Ueberfall",7649,true,"dd",playerid,t);
    Spieler[playerid][tTankeUnix] = gettime() + 3*60;// 15min
    Tanke[t][tRobberID] = playerid;
    return cmd_me(playerid,"überfällt eine Tankstelle!");
}
CMD:tankeausrauben(playerid,params[]) {
    return cmd_tankstelleausrauben(playerid,params);
}



CMD:tankkaufen(playerid,params[]) {
    new
        idx = -1,
        menge;
    if(sscanf(params,"d",menge)) {
        return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Tankkaufen [Menge]");
    }
    if( menge < 1 ) {
        return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Tankkaufen [Menge]");
    }
    if( IsPlayerInRangeOfPoint(playerid,6.0,-1034.6223,-626.2365,32.0078) ) {
        idx = 2;
    }
    if( IsPlayerInRangeOfPoint(playerid,6.0,2482.8813,-2084.2239,13.5469) ) {
        idx = 3;
    }
    if( idx == -1 ) {
        return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keinem Ort, wo du Benzin kaufen kannst.");
    }
    new indextanke = Spieler[playerid][pPlayerTank];
    if( indextanke == 999) {
        return SendClientMessage(playerid, COLOR_RED, "Du besitzt keine Tankstelle!");
    }
    if( StaticBiz[idx][SBD_iWaren] < menge ) {
        return SendClientMessage(playerid, COLOR_RED, "Das Lager kann deinen Bedarf am Benzin nicht decken.");
    }
    new
        String[128];
    if( Tanke[indextanke][tMaxBenzin] < Tanke[indextanke][tBenzin] + menge ) {
        format(String,sizeof(String),"Diese Menge kannst du nicht kaufen, da deine Tanke nur maximal %d Liter Benzin halten kann (noch %d).",Tanke[indextanke][tMaxBenzin],( Tanke[indextanke][tMaxBenzin] - Tanke[indextanke][tBenzin] ) );
        return SendClientMessage(playerid, COLOR_RED, String);
    }
    new price = menge * 25;
    if( Spieler[playerid][pCash] < price ) {
        return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht genug Geld. Jeder Liter kostet $25.");
    }
    format(String,sizeof(String),"Du hast für deine Tankstelle %d Liter Benzin für je $25 pro Liter gekauft (-$%s).",menge, AddDelimiters(price));
    SendClientMessage(playerid,COLOR_YELLOW,String);
    GivePlayerCash(playerid,-price);
    Tanke[indextanke][tBenzin] += menge;
    StaticBiz[idx][SBD_iWaren] -= menge;
    UpdateStaticBizText(idx);
    return 1;
}


CMD:tankshop(playerid,params[])
{
    #pragma unused params
    new t = IsPlayerAtTanke(playerid);
    if(t == 999)return SendClientMessage(playerid, COLOR_RED, "Du befindest dich an keiner Tanke!");
    if(strcmp(Tanke[t][tBesitzer], "Niemand", true) == 0)return SendClientMessage(playerid, COLOR_RED, "Die Tankstelle hat keinen Besitzer.");
    new
        sTitle[64],
        sDialog[256];
    format(sDialog, sizeof(sDialog), "%sPower-Riegel - $5.000\n", sDialog);
    format(sDialog, sizeof(sDialog), "%sBooster - $20.000\n", sDialog);
    format(sDialog, sizeof(sDialog), "%sKanister - $20.000 (10 Liter)", sDialog);
    format(sTitle,sizeof(sTitle),"%s - Tankstellenshop",Tanke[t][tName]);
    ShowPlayerDialog(playerid,DIALOG_SNACKSHOP,DIALOG_STYLE_LIST,sTitle,sDialog,"Kaufen","Abbruch");
    return 1;
}



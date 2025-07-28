#include <YSI\y_hooks>


CMD:krankenversicherung(playerid,params[]) {
    if (!IsPlayerInRangeOfPoint(playerid, 5.0, SAMD_INTERIOR_HEALTH_INSURANCE_COORDS)) {
        SendClientMessage(playerid,COLOR_RED,"Du kannst hier keine Krankenversicherung kaufen.");
        return 1;
    }
    if( CheckMoney(playerid) < 50000 ) {
        SendClientMessage(playerid,COLOR_RED,"Du hast nicht genug Geld um eine Krankenversicherung zu kaufen");
        return 1;
    }
    if( HasKrankenversicherung(playerid) ) {
        SendClientMessage(playerid,COLOR_RED,"Du besitzt bereits eine Krankenversicherung!");
        return 1;
    }
    new
        String[128];

    format(String,sizeof(String),"Du hast dir eine Krankenversicherung gekauft für 50000$. Diese ist für 7 Tage gültig!");
    SendClientMessage(playerid,COLOR_YELLOW,String);
    GivePlayerCash(playerid,-50000);
    Kasse[Samd] += 50000;
    Spieler[playerid][unixKrankenversicherung] = gettime() + 604800;
    return 1;
}


CMD:versicherungen(playerid,params[]) {
    new
        sperren,
        sekunden,
        minuten,
        stunden,
        time_left,
        String[128],
        unix = gettime();
    SendClientMessage(playerid,COLOR_RED,"=============MEINE VERSICHERUNGEN=============");
    if( unix < Spieler[playerid][unixKrankenversicherung] ) { // car
        time_left = Spieler[playerid][unixKrankenversicherung] - unix;
        ConvertSec( time_left , sekunden,minuten,stunden );

        format(String,sizeof(String),"Krankenversicherung für %d Stunden und %d Minuten!",stunden,minuten);
        SendClientMessage(playerid,COLOR_ORANGE,String);

        sperren++;
    }
    if( unix < Spieler[playerid][pExperte] ) { // boat
        time_left = Spieler[playerid][pExperte] - unix;
        ConvertSec( time_left , sekunden,minuten,stunden );

        format(String,sizeof(String),"Rechtsschutzversichert für %d Stunden und %d Minuten!",stunden,minuten);
        SendClientMessage(playerid,COLOR_ORANGE,String);

        sperren++;
    }
    if( unix < Spieler[playerid][pKFZVersicherung] ) { // fly
        time_left = Spieler[playerid][pKFZVersicherung] - unix;
        ConvertSec( time_left , sekunden,minuten,stunden );

        format(String,sizeof(String),"KFZ-Versicherung für %d Stunden und %d Minuten!",stunden,minuten);
        SendClientMessage(playerid,COLOR_ORANGE,String);

        sperren++;
    }
    if(!sperren) {
        SendClientMessage(playerid,COLOR_GREEN,"Du hast keine Versicherungen abgeschlossen!");
    }
    return 1;
}



CMD:zollpass(playerid,params[]) {
	if (!IsPlayerInRangeOfPoint(playerid, 3.0, CITYHALL_INTERIOR_DESK1)) return SendClientMessage(playerid, COLOR_RED, "Du kannst hier keinen Zollpass kaufen.");

	ShowPlayerDialog(playerid, DIALOG_ZOLLPASS, DIALOG_STYLE_MSGBOX, "Zollpass", "Du kannst für $45.000 einen Zollpass kaufen.\nDamit kannst du für 7 Tage den Zoll ohne Zahlung passieren.", "Kaufen", "Abbruch");
	return 1;
}



CMD:kfzversicherung(playerid,params[]) {
    if( !IsPlayerInRangeOfPoint(playerid,3.0,2309.3276,-8.2968,26.7422))return SendClientMessage(playerid, COLOR_RED, "Du kannst hier keine KFZ-Versicherung abschließen.");
    if( Spieler[playerid][pKFZVersicherung] > gettime() ) return SendClientMessage(playerid, COLOR_RED, "Deine KFZ-Versicherung läuft noch.");
    if( Spieler[playerid][pCash] < 50000 ) return SendClientMessage(playerid, COLOR_RED, "Die KFZ-Versicherung kostet $50.000. Du besitzt leider nicht so viel Geld.");

    SendClientMessage(playerid,COLOR_YELLOW,"Glückwunsch! Du hast eine KFZ-Versicherung für 7 Tage für $50.000 abgeschlossen.");
    GivePlayerCash(playerid,-10000);
    TreasuryDeposit(10000);
    Spieler[playerid][pKFZVersicherung] = gettime() + 7*24*60*60;
    return 1;
}

CMD:rechtsschutz(playerid,params[]) {
    if (!IsPlayerInRangeOfPoint(playerid, 3.0, CITYHALL_INTERIOR_DESK2)) return SendClientMessage(playerid, COLOR_RED, "Du kannst hier keine Rechtsschutzversicherung abschließen.");
    if( Spieler[playerid][pExperte] > gettime() ) return SendClientMessage(playerid, COLOR_RED, "Deine Rechtsschutz-Versicherung läuft noch");

    ShowPlayerDialog(playerid, DIALOG_RECHTSSCHUTZ, DIALOG_STYLE_MSGBOX, "Rechtsschutz-Versicherung", "Eine Rechtsschutzversicherung deckt im Falle eines Rechtsstreits entstandene Kosten ab.\n\nDie entstandenen Prozesskosten werden bis zu 40% von der Rechtsschutzversicherung gedeckt.\nDie Kosten für einen Rechtsanwalt, welcher die Durchsetzung der rechtlichen Interesse vertritt,\nwerden bis zu 65% von der Rechtsschutzversicherung gedeckt.\n\nVersichert für: 62 Tage\nPreis: $1.000.000", "Abschließen", "Ablehnen");
    return 1;
}




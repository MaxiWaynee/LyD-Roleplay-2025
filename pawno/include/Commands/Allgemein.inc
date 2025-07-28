#include <YSI\y_hooks>



enum e_JobSkins {
    Float:JS_fX,
    Float:JS_fY,
    Float:JS_fZ,
    JS_iJob,
    JS_iSkin
};

new const g_JobSkins[][e_JobSkins] = {
    // X    Y       Z     Job , SkinID
    {-90.4999,  -10.3628,  3.1094,  1, 161 }, //Bauer
    {BUSSTATION_JOBSKIN_POINT,  2, 255 }, //Busfahrer
    {TRUCKERBASE_JOBSKIN_POINT,  3, 32 }, //Trucker
    {AIRPORTLS_JOBSKIN_POINT,  4, 61 }, //Pilot
    {980.6174,  -933.2461,   41.3419,  5, 50 }, //Mechaniker
    {1945.9237,-1793.6355,13.5469,  5, 50 }, //Mechaniker
    {662.6830,-579.0665,16.3359,  5, 50 }, //Mechaniker
    {-93.9144,-1196.9713,2.4775,  5, 50 }, //Mechaniker
    { LSPD_INTERIOR_LAWYER_SKIN_POINT,  6, 57 }, // Lawyer (Anwalt)
    {2046.2723,  -1913.2064,  13.5469,  7, 260 }, //Straßenreiniger
    {2118.6157,  -2085.0828,  13.5544,  8, 260 }, //Müllmann
    {GARDENERBASE_JOBSKIN_POINT, 9, 35 }, //Gärtner
    {831.2045,  865.6005,  12.5911,  10, 27 }, //Bauarbeiter
    {BOATCARGOJOB_JOBSKIN_POINT,  11, 37 }, //Schiffsfahrer
    {1551.5492,  -1005.0830,  24.0781,  12, 295 }, //Geldtransport
    {1021.9334,  -1371.0099,  13.5585,  13, 264 }, //Eisfahrer
    {2117.3662,  -1790.0100,  13.5547,  15, 155 }, //Pizzalieferant
    {TAXISTATIONS_JOBSKIN_POINT_CITYHALL, 16, 189 }, //Taxifahrer
    {1437.4211,  -1694.0231,    13.5469,  16, 189 }, //Taxifahrer am Werbepunkt
    //{1735.0045,  -1944.0450,  13.5681,  23, 253 }, //Zugfahrer
    {2417.1555,  -1220.1472,  25.3914,  20, 63 }, //Hure
    {2384.0181,  -1915.5509,  13.5469,  23, 168 } //Hotdog
};

CMD:info1(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2306.2896,-13.4087,26.7422))//Info
    {
        SendClientMessage(playerid, COLOR_BLUE, "================INFORMATIONEN ZU WAFFEN================");
        SendClientMessage(playerid, COLOR_WHITE, "Auf diesem Server gibt es Bereiche wo allgemein schlagen und schießen");
        SendClientMessage(playerid, COLOR_WHITE, "strengstens untersagt ist! Diese Bereiche nennen sich 'NO-DM ZONE'");
        SendClientMessage(playerid, COLOR_WHITE, "Wer in einer NO-DM ZONE DM betreibt, wird administrativ bestraft.");
        SendClientMessage(playerid, COLOR_WHITE, "NO-DM Zonen sind oftmals Bereiche wo sich viele Neulinge und Dienstleistende aufhalten oder Behörden sind.");
        SendClientMessage(playerid, COLOR_WHITE, "Waffen die sich auf dem Boden drehen kann man mit dem Befehl /Pickwaffe aufheben.");
    }
    return 1;
}
CMD:info2(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2307.9524,-13.3947,26.7422))//Info
    {
        SendClientMessage(playerid, COLOR_BLUE, "================INFORMATIONEN ZU BERUFEN================");
        SendClientMessage(playerid, COLOR_WHITE, "Auf diesem Server gibt es um die 23 Berufe.");
        SendClientMessage(playerid, COLOR_WHITE, "Bei vielen Berufe, überwigend legalen Berufen, erhält man ein fest Einkommen.");
        SendClientMessage(playerid, COLOR_WHITE, "Um dein Lebensstatus auf dem Server gut zu gestalten, sollte man einen Beruf ausführen.");
        SendClientMessage(playerid, COLOR_WHITE, "Zu jedem Beruf der im Stadtamt angeboten wird, werden die Voraussetzungen, Gehalt und Risiko");
        SendClientMessage(playerid, COLOR_WHITE, "angezeigt. Unter Voraussetzungen könnte stehen, dass man um diesen Beruf ausführen zu können, einen ");
        SendClientMessage(playerid, COLOR_WHITE, "Autoschein benötigt oder unter Risiken, dass man von der Polizei erwischt werden könnte.");
        SendClientMessage(playerid, COLOR_WHITE, "Suche dir unter unseren vielen Berufsangeboten dein Wunschberuf aus!");
    }
    return 1;
}
CMD:info3(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2310.4695,-13.3777,26.7422))//Info
    {
        SendClientMessage(playerid, COLOR_BLUE, "================INFORMATIONEN ZU FRAKTIONEN================");
        SendClientMessage(playerid, COLOR_WHITE, "Um in einer Fraktion beitreten zu könnten, werden oftmals Bewerbungen");
        SendClientMessage(playerid, COLOR_WHITE, "von der Leaderschaft der entsprechenden Fraktion verlangt.");
        SendClientMessage(playerid, COLOR_WHITE, "Bei Staatlichen-Fraktionen wie Polizei oder Rettungsdienst gibt es feste");
        SendClientMessage(playerid, COLOR_WHITE, "Voraussetzungen und eine Bewerbungspflicht.");
        SendClientMessage(playerid, COLOR_WHITE, "Bei Gangfraktionen ist es dem Leader selbst überlassen wie er seine verlangten");
        SendClientMessage(playerid, COLOR_WHITE, "Voraussetzungen für den Beitritt aufstellt, ob nun Bewerbung oder Teamspeak-Gespräch usw.");
        SendClientMessage(playerid, COLOR_WHITE, "Unter www.LyD-Roleplay.de findest du weitere Informationen über alle Fraktionen!");
    }
    return 1;
}
CMD:info4(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2312.3950,-13.3340,26.7422))//Info
    {
        SendClientMessage(playerid, COLOR_BLUE, "================INFORMATIONEN ZUM SHOP================");
        SendClientMessage(playerid, COLOR_WHITE, "Du hast Lust dem Server etwas gutes zu tun?");
        SendClientMessage(playerid, COLOR_WHITE, "Dann kannst du in unserem Shop unter www.LyD-Roleplay.de für den Server spenden!");
        SendClientMessage(playerid, COLOR_WHITE, "Im Shop kannst du entsprechende Pakete wie ein Clubstatus oder ein Wunschfahrzeug");
        SendClientMessage(playerid, COLOR_WHITE, "usw. bestellen. Als Clubmitglied erhält man tolle Sachen mit hinzu.");
        SendClientMessage(playerid, COLOR_WHITE, "Jede Zahlung wird als eine Spende an das Projekt gesehen, wofür wir ein Dankeschön geben.");
        SendClientMessage(playerid, COLOR_WHITE, "Folgende Zahlmethoden werden angenommen: PayPal, Banküberweisung, Geld per Post und Paysafecard.");
    }
    return 1;
}
CMD:info5(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2314.0818,-13.2958,26.7422))//Info
    {
        SendClientMessage(playerid, COLOR_BLUE, "================INFORMATIONEN ZU BEFEHLEN================");
        SendClientMessage(playerid, COLOR_WHITE, "Unter /HELP werden alle nötigen und wichtige Server-Befehle,");
        SendClientMessage(playerid, COLOR_WHITE, "darunter auf Job-, Fraktions und Geschäft/Hausbefehle angezeigt.");
    }
    return 1;
}
CMD:info6(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2314.3340,-11.8980,26.7422))//Info
    {
        SendClientMessage(playerid, COLOR_BLUE, "================INFORMATIONEN ZUM NAVI================");
        SendClientMessage(playerid, COLOR_WHITE, "Unter dem Befehl /NAVI werden alle wichtigen und nötigen Orte");
        SendClientMessage(playerid, COLOR_WHITE, "angezeigt, darunter Joborte, Fraktionsorte, Restaurants und Tankstele und vieles mehr.");
    }
    return 1;
}
CMD:info7(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2314.3203,-10.3251,26.7422))//Info
    {
        SendClientMessage(playerid, COLOR_BLUE, "================INFORMATIONEN ZU HÄUSERN================");
        SendClientMessage(playerid, COLOR_WHITE, "Unter dem Befehl /Hauskaufen kaufst du ein freies Haus und bist somit der Eigentümer.");
        SendClientMessage(playerid, COLOR_WHITE, "Mit dem Befehl /MIETEN kannst du dich in einem Haus einmieten wo Mieter toleriert werden.");
        SendClientMessage(playerid, COLOR_WHITE, "Die Miete wird jeden PayDay vom Mieter abgezogen.");
        SendClientMessage(playerid, COLOR_WHITE, "Jedem PayDay zahlt der Hausbesitzer Stromkosten.");
    }
    return 1;
}
CMD:info8(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2313.1909,-9.6363,26.7422))//Info
    {
        SendClientMessage(playerid, COLOR_BLUE, "================INFORMATIONEN ZU GESCHÄFTEN================");
        SendClientMessage(playerid, COLOR_WHITE, "Mit dem Befehl /Bizkaufen kann man sich ein freies Geschäft kaufen.");
        SendClientMessage(playerid, COLOR_WHITE, "Jeder Art von Einkäufe im Geschäft geht an den Geschäftseingentümer.");
        SendClientMessage(playerid, COLOR_WHITE, "Der Geschäftseingentümer zahlt jeden PayDay für sein Geschäft Stromkosten.");
    }
    return 1;
}
//INFOCENTER-HELP END
CMD:info(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, NOOBSPAWN_SERVERINFO_POINT))//Info
    {
        SendClientMessage(playerid, COLOR_BLUE, "================INFORMATIONEN================");
        SendClientMessage(playerid, COLOR_WHITE, "Dieser Server ist ein Roleplay Server!");
        SendClientMessage(playerid, COLOR_WHITE, "Mit /Navi und /Help findest du dich hier zurecht.");
        SendClientMessage(playerid, COLOR_WHITE, "Unser Forum ist unter www.LyD-Roleplay.de zu erreichen.");
        SendClientMessage(playerid, COLOR_WHITE, "In unserem Forum kannst du weitere Informationen nach lesen");
        SendClientMessage(playerid, COLOR_WHITE, "und dich eventuell bei einer Fraktion als Leader/Member vorstellen.");
        SendClientMessage(playerid, COLOR_WHITE, "Unsere Teamspeak IP lautet TS.LyD-Roleplay.de");
        SendClientMessage(playerid, COLOR_WHITE, "Wir besitzen auch eine User Control Panel wo du deine Statistiken mitverfolgen kannst!");
        SendClientMessage(playerid, COLOR_WHITE, "Die Internet-Adresse zur User Control Panel lautet: www.UCP.LyD-Roleplay.de");
    }
    return 1;
}

CMD:stadtamtinfo(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 1481.7039,-1740.6183,13.5469))//Info
    {
        SendClientMessage(playerid, COLOR_BLUE, "===================STADTAMT INFORMATIONEN===================");
        SendClientMessage(playerid, COLOR_WHITE, "Hier befindet sich das Stadtamt.");
        SendClientMessage(playerid, COLOR_WHITE, "Im Stadtamt befindet sich auch das Arbeitsamt, wo eine");
        SendClientMessage(playerid, COLOR_WHITE, "eine große Anzahl an Berufen angeboten wird.");
        SendClientMessage(playerid, COLOR_WHITE, "Staatsangehörigkeit, Fahrzeugzulassung, Meldestelle, all");
        SendClientMessage(playerid, COLOR_WHITE, "diese Verwaltungsangelegenheiten lassen sich beim Stadtamt erledigen.");
    }
    return 1;
}


CMD:serverinfo(playerid)
{
    SendClientMessage(playerid, COLOR_BLUE, "* SERVER IP *: {FFFFFF}Server.LyD-Roleplay.de");
    SendClientMessage(playerid, COLOR_BLUE, "* TEAMSPEAK IP *: {FFFFFF}TS.LyD-Roleplay.de");
    SendClientMessage(playerid, COLOR_BLUE, "* FORUM ADRESSE *: {FFFFFF}www.LyD-Roleplay.de");
    SendClientMessage(playerid, COLOR_BLUE, "* USER PANEL *: {FFFFFF}www.UCP.LyD-Roleplay.de");
    SendClientMessage(playerid, COLOR_BLUE, "* PROJEKTLEITER *: {FFFFFF}DOPE");
    //SendClientMessage(playerid, COLOR_BLUE, "* MANAGEMENT *: {FFFFFF}[LyD]Shadow");
    SendClientMessage(playerid, COLOR_BLUE, "* ENTWICKLER *: {FFFFFF}dape. & PatrickJ.");
    return 1;
}


CMD:help(playerid)
{
    if( gPlayerLogged[playerid] == 0 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht eingeloggt");
    ShowPlayerDialog(playerid,DIALOG_CMDHELP,DIALOG_STYLE_LIST,"Hilfebox","{FF0000}Hilfsdatenbank (Suche){FFFFFF}\nAllgemeine Befehle\nFinanz Befehle\nDeathmatch Befehle\nVerkauf Befehle\nCasino Befehle\nFahrzeug Befehle\nHaus Befehle\nBusiness Befehle\nTankstellen Befehle\nFirmen Befehle\nChat Befehle\nHaustier Befehle\nLeader Befehle\nJob Befehle\nFraktions Befehle\nAdmin Befehle","Ansehen","Abbruch");
    return 1;
}

CMD:clubhelp(playerid)
{
    if(Spieler[playerid][pDonateRank] != 1)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Clubmitglied!");
    SendClientMessage(playerid, COLOR_BLUE, "* CLUB-BEFEHLE *: {FFFFFF}/Clubwaffen, /Getraenk, /Clubheal, /Clubshop, /CC (Club-Chat), /Clubdance[1 bis 7]");
    return 1;
}


CMD:admins(playerid){
    if( gPlayerLogged[playerid] == 0 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht eingeloggt");
    new query[160];
    format(query, sizeof(query), "SELECT `Name`, `Level`, `Admin` FROM `accounts` WHERE `Admin` > 0 ORDER BY `Admin` DESC LIMIT 0,30", Spieler[playerid][pAdmin]);
    mysql_pquery(query,THREAD_ADMINLIST,playerid,gSQL,MySQLThreadOwner);
    return 1;
}


CMD:liste(playerid)
{
    if( gPlayerLogged[playerid] == 0 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht eingeloggt");
    if(Spieler[playerid][pFraktion] == 3)
    {
        ShowPlayerDialog(playerid, DIALOG_LISTE, DIALOG_STYLE_LIST, COLOR_HEX_ORANGE"Spieler-Liste", COLOR_HEX_WHITE"Busfahrer\nTrucker\nPilote\nKFZ-Mechatroniker\nAnwälte\nTaxifahrer\nAdmins\nNews Reporter\nSanitäter\nOrdnungsbeamte\nLSPD\nLeaderliste\n"COLOR_HEX_ORANGE"Gestorbene", "Auswählen", "Abbrechen");
        return 1;
    }
    ShowPlayerDialog(playerid, DIALOG_LISTE, DIALOG_STYLE_LIST, COLOR_HEX_ORANGE"Spieler-Liste",COLOR_HEX_WHITE"Busfahrer\nTrucker\nPilote\nKFZ-Mechatroniker\nAnwälte\nTaxifahrer\nAdmins\nNews Reporter\nSanitäter\nOrdnungsbeamte\nLSPD\nLeaderliste", "Auswählen", "Abbrechen");
    return 1;
}


CMD:service(playerid)
{
    ShowPlayerDialog(playerid, DIALOG_SERVICE, DIALOG_STYLE_LIST, "Service", "Polizei\nRettungsdienst\nADAC Pannenhilfe\nOrdnungsamt\nTaxi-Service\nPizza-Service\nAgency-Service\nAnwalt\nDetektiv", "Auswählen", "Abbrechen");
    return 1;
}



CMD:navi(playerid)
{
    adminnavi[playerid] = false;
    if( gPlayerLogged[playerid] == 0 ) return SendClientMessage(playerid,COLOR_RED,"Du bist nicht eingeloggt");
    ShowPlayerDialog(playerid, DIALOG_NAVI, DIALOG_STYLE_LIST, "Navigation", "Ämter und Behörden\nPolizei u. Notdienste\nFahrschule\nFahrzeugverkauf\nCarSharing-Stationen\nHotel\nBanken\nVersicherungen\n24/7 Shops\nTankstellen\nKleidungsgeschäfte\nRestaurant\nCasinos\nWaffenverkauf\nVerkaufshäuser\nTuning-Garagen\nArbeitsstellen\nGang/Mafien Base\nIllegale Orte\nWeitere Orte\nNächster ATM", "Markieren", "Abbrechen");
    return 1;
}

CMD:showjob(playerid)
{
    if(Spieler[playerid][pJob] == 0) return SendClientMessage(playerid, COLOR_RED, "Du bist Arbeitslos.");
    else if(Spieler[playerid][pJob] == 1)
    {
        SetPlayerCheckpointEx(playerid, -51.4131,-0.0881,3.1172, 7.0, CP_SHOWJOB1);
    }
    else if(Spieler[playerid][pJob] == 2)
    {
        SetPlayerCheckpointEx(playerid, BUSSTATION_JOBSKIN_POINT, 2.0, CP_SHOWJOB2);
    }
    else if(Spieler[playerid][pJob] == 3)
    {
        SetPlayerCheckpointEx(playerid, 65.0772,-254.8746,1.5781, 7.0, CP_SHOWJOB3);
    }
    else if(Spieler[playerid][pJob] == 4)
    {
        SetPlayerCheckpointEx(playerid, 1962.5402,-2203.2803,13.1212, 7.0, CP_SHOWJOB4);
    }
    else if(Spieler[playerid][pJob] == 5)
    {
        return SendClientMessage(playerid, COLOR_YELLOW, "Die Utility Vans und Jobkleidungspunkte sind an allen Tankstellen in LS zu finden (/navi->Tankstellen).");
        //SetPlayerCheckpointEx(playerid, -78.5111,-1125.9220,1.0781, 7.0, CP_SHOWJOB4);
    }
    else if(Spieler[playerid][pJob] == 6)
    {
        SetPlayerCheckpointEx(playerid, 960.7043, -1580.0457, 13.5469, 7.0, CP_SHOWJOB5);
    }
    else if(Spieler[playerid][pJob] == 7)
    {
        SetPlayerCheckpointEx(playerid, 2059.9531,-1911.7333,13.5469, 7.0, CP_SHOWJOB6);
    }
    else if(Spieler[playerid][pJob] == 8)
    {
        SetPlayerCheckpointEx(playerid, 2112.8879,-2100.7773,13.5469, 7.0, CP_SHOWJOB8);
    }
    else if(Spieler[playerid][pJob] == 9)
    {
        SetPlayerCheckpointEx(playerid, GARDENERBASE_JOBSKIN_POINT, 2.0, CP_SHOWJOB9);
    }
    else if(Spieler[playerid][pJob] == 10)
    {
        SetPlayerCheckpointEx(playerid, 855.4802,861.9259,13.3516, 7.0, CP_SHOWJOB10);
    }
    else if(Spieler[playerid][pJob] == 11)
    {
        SetPlayerCheckpointEx(playerid, 2518.3513,-2248.2808,13.5469, 7.0, CP_SHOWJOB11);
    }
    else if(Spieler[playerid][pJob] == 12)
    {
        SetPlayerCheckpointEx(playerid, 1557.0809,-1020.2286,23.9063, 7.0, CP_SHOWJOB12);
    }
    else if(Spieler[playerid][pJob] == 13)
    {
        SetPlayerCheckpointEx(playerid, 1004.8211,-1350.0563,13.3412, 7.0, CP_SHOWJOB13);
    }
    else if(Spieler[playerid][pJob] == 14)
    {
        return SendClientMessage(playerid, COLOR_ORANGE, "Als Detektiv musst du nirgendwo hin. Nutze /Help!");
    }
    else if(Spieler[playerid][pJob] == 15)
    {
        SetPlayerCheckpointEx(playerid, 2114.5002,-1777.3717,13.3907, 7.0, CP_SHOWJOB6);
    }
    else if(Spieler[playerid][pJob] == 16)
    {
        SetPlayerCheckpointEx(playerid, 1272.3879,-1353.3357,13.5069, 7.0, CP_SHOWJOB6);
    }
    else if(Spieler[playerid][pJob] == 17)
    {
        SetPlayerCheckpointEx(playerid, 318.9959,-60.6508,1.5781, 7.0, CP_SHOWJOB6);
    }
    else if(Spieler[playerid][pJob] == 18)
    {
        SetPlayerCheckpointEx(playerid, 2298.2554,-2350.6294,13.5469, 7.0, CP_SHOWJOB7);
    }
    else if(Spieler[playerid][pJob] == 19)
    {
        return SendClientMessage(playerid, COLOR_YELLOW, "Deine Opfer musst du dir selbst suchen.");
    }
    else if(Spieler[playerid][pJob] == 20)
    {
        SetPlayerCheckpointEx(playerid, 2417.1555,-1220.1472,25.3914, 7.0, CP_SHOWJOB7);
    }
    else if(Spieler[playerid][pJob] == 21)
    {
        SetPlayerCheckpointEx(playerid, WANTEDHACKERBASE_POINT, 2.0, CP_SHOWJOB7);
    }
    else if(Spieler[playerid][pJob] == 22)
    {
        return SendClientMessage(playerid, COLOR_YELLOW, "Suche ein Auto, welches du klauen kannst.");
    }
    /*else if(Spieler[playerid][pJob] == 23)
    {
        SetPlayerCheckpointEx(playerid, 1735.0045,-1944.0450,13.5681, 7.0, CP_SHOWJOB7);
    }*/
    else if(Spieler[playerid][pJob] == 23)
    {
        SetPlayerCheckpointEx(playerid, 2384.0181,-1915.5509,13.5469, 7.0, CP_SHOWJOB7);
    }

    SendClientMessage(playerid, COLOR_WHITE, "Es wurde ein Checkpoint auf der Karte zu deinem Job angezeigt.");
    return 1;
}
CMD:warenverkaufsstelle1(playerid)
{
    SetPlayerCheckpointEx(playerid, 2187.6926,-2263.8967,13.4674, 3.0, CP_SHOWJOB1);
    SendClientMessage(playerid, COLOR_WHITE, "Es wurde ein Checkpoint auf der Karte zum Warenverkaufsplatz in Los Santos (Lagerhalle) gesetzt.");
    return 1;
}
CMD:warenverkaufsstelle2(playerid)
{
    SetPlayerCheckpointEx(playerid, 2571.6233,-2226.6980,13.3550, 3.0, CP_SHOWJOB1);
    SendClientMessage(playerid, COLOR_WHITE, "Es wurde ein Checkpoint auf der Karte zum Warenverkaufsplatz in Los Santos (Hafen) gesetzt.");
    return 1;
}
CMD:spritverkaufsstelle1(playerid)
{
    SetPlayerCheckpointEx(playerid, -1034.6223,-626.2365,32.0078, 3.0, CP_SHOWJOB1);
    SendClientMessage(playerid, COLOR_WHITE, "Es wurde ein Checkpoint auf der Karte zum Spritverkaufsplatz im Vorort Los Santos gesetzt.");
    return 1;
}
CMD:spritverkaufsstelle2(playerid)
{
    SetPlayerCheckpointEx(playerid, 2482.8813,-2084.2239,13.5469, 3.0, CP_SHOWJOB1);
    SendClientMessage(playerid, COLOR_WHITE, "Es wurde ein Checkpoint auf der Karte zum Spritverkaufsplatz in der Stadt Los Santos gesetzt.");
    return 1;
}



CMD:sliste(playerid, params[])
{
    new entry[24];
    new string[128];
    new str2[2048];
    if(sscanf(params, "s[24]", entry))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Sliste [Fraktion/Job]");
    if(strcmp(entry, "fraktion", true) == 0)
    {
        if(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16)
        {
            new bool:IsOnline;
            for(new i = 0 ; i < MAX_PLAYERS ; i++)
            {
                if(IsPlayerConnected(i) && gPlayerLogged[i] == 1)
                {
                    if(NeedCop[i] == 1)
                    {
                        format(string, sizeof(string), COLOR_HEX_BLUE"%s meldet ein Notruf! (ID: %d) (Nummer: %i)\n", GetName(i), i, Spieler[i][pHandyNr]);
                        strcat(str2, string);
                        IsOnline = true;
                    }
                }
            }
            if(!IsOnline)
            {
                SendClientMessage(playerid, COLOR_RED, "Niemand benötigt einen Polizist.");
                return 1;
            }
            SendClientMessage(playerid, COLOR_BLUE, "INFO: "COLOR_HEX_WHITE"Sie können mit /Acceptcop ein Notruf annehmen!");
            ShowPlayerDialog(playerid, DIALOG_SLISTCOP, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"NOTRUFZENTRALE: "COLOR_HEX_WHITE"Polizei", str2, "Schließen", "");
        }
        else if(Spieler[playerid][pFraktion] == 3)
        {
            new bool:IsOnline;
            for(new i = 0 ; i < MAX_PLAYERS ; i++)
            {
                if(IsPlayerConnected(i) && gPlayerLogged[i] == 1)
                {
                    if(NeedMedic[i] == 1)
                    {
                        format(string, sizeof(string), "%s benögtigt meldet ein Notruf! (ID: %d) (Nummer: %i)\n", GetName(i), i, Spieler[i][pHandyNr]);
                        strcat(str2, string);
                        IsOnline = true;
                    }
                }
            }
            if(!IsOnline)
            {
                SendClientMessage(playerid, COLOR_RED, "Niemand benötigt einen Sanitäter.");
                return 1;
            }
            SendClientMessage(playerid, COLOR_BLUE, "INFO: "COLOR_HEX_WHITE"Sie können mit /Acceptsani ein Notruf annehmen!");
            ShowPlayerDialog(playerid, DIALOG_SLISTSANI, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"NOTRUFZENTRALE: "COLOR_HEX_WHITE"Sanitäter", str2, "Schließen", "");
        }
        else if(Spieler[playerid][pFraktion] == 5)
        {
            new bool:IsOnline;
            for(new i = 0 ; i < MAX_PLAYERS ; i++)
            {
                if(IsPlayerConnected(i) && gPlayerLogged[i] == 1)
                {
                    if(NeedOAMT[i] == 1)
                    {
                        format(string, sizeof(string), "%s meldet ein Anliegen! (ID: %d) (Nummer: %i)\n", GetName(i), i, Spieler[i][pHandyNr]);
                        strcat(str2, string);
                        IsOnline = true;
                    }
                }
            }
            if(!IsOnline)
            {
                SendClientMessage(playerid, COLOR_RED, "Niemand benötigt einen Ordnungsbeamten.");
                return 1;
            }
            SendClientMessage(playerid, COLOR_BLUE, "INFO: "COLOR_HEX_WHITE"Du kannst mit /Acceptoamt [ID] einen Service-Anruf annehmen!");
            ShowPlayerDialog(playerid, DIALOG_SLISTOAMT, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"Service-Liste: "COLOR_HEX_WHITE"Ordnungsamt", str2, "Schließen", "");
        }
    }
    else if(strcmp(entry, "job", true) == 0)
    {
        if(Spieler[playerid][pJob] == 5)
        {
            new bool:IsOnline;
            for(new i = 0 ; i < MAX_PLAYERS ; i++)
            {
                if(IsPlayerConnected(i) && gPlayerLogged[i] == 1)
                {
                    if(NeedKFZ[i] == 1)
                    {
                        format(string, sizeof(string), "%s benötigt einen Mechatroniker! (ID: %d) (Nummer: %i)\n", GetName(i), i, Spieler[i][pHandyNr]);
                        strcat(str2, string);
                        IsOnline = true;
                    }
                }
            }
            if(!IsOnline)
            {
                SendClientMessage(playerid, COLOR_RED, "Niemand benötigt einen Mechatroniker.");
                return 1;
            }
            SendClientMessage(playerid, COLOR_BLUE, "INFO: "COLOR_HEX_WHITE"Du kannst mit /Acceptkfz [ID] einen Service-Anruf annehmen!");
            ShowPlayerDialog(playerid, DIALOG_SLISTKFZ, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"Service-Liste: "COLOR_HEX_WHITE"Mechatroniker", str2, "Schließen", "");
        }
        else if(Spieler[playerid][pJob] == 6)
        {
            new bool:IsOnline;
            for(new i = 0 ; i < MAX_PLAYERS ; i++)
            {
                if(IsPlayerConnected(i) && gPlayerLogged[i] == 1)
                {
                    if(NeedAWALT[i] == 1)
                    {
                        format(string, sizeof(string), "%s benötigt einen Anwalt! (ID: %d) (Nummer: %i)\n", GetName(i), i, Spieler[i][pHandyNr]);
                        strcat(str2, string);
                        IsOnline = true;
                    }
                }
            }
            if(!IsOnline)
            {
                SendClientMessage(playerid, COLOR_RED, "Niemand benötigt einen Anwalt.");
                return 1;
            }
            SendClientMessage(playerid, COLOR_BLUE, "INFO: "COLOR_HEX_WHITE"Du kannst mit /Acceptanwalt [ID] einen Service-Anruf annehmen!");
            ShowPlayerDialog(playerid, DIALOG_SLISTAWALT, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"Service-Liste: "COLOR_HEX_WHITE"Anwalt", str2, "Schließen", "");
        }
        else if(Spieler[playerid][pJob] == 15)
        {
            new bool:IsOnline;
            for(new i = 0 ; i < MAX_PLAYERS ; i++)
            {
                if(IsPlayerConnected(i) && gPlayerLogged[i] == 1)
                {
                    if(NeedPIZZA[i] == 1)
                    {
                        format(string, sizeof(string), "%s hat eine Pizza bestellt! (ID: %d) (Nummer: %i)\n", GetName(i), i, Spieler[i][pHandyNr]);
                        strcat(str2, string);
                        IsOnline = true;
                    }
                }
            }
            if(!IsOnline)
            {
                SendClientMessage(playerid, COLOR_RED, "Niemand hat eine Pizza bestellt!");
                return 1;
            }
            SendClientMessage(playerid, COLOR_BLUE, "INFO: "COLOR_HEX_WHITE"Du kannst mit /Acceptpizza [ID] einen Service-Anruf annehmen!");
            ShowPlayerDialog(playerid, DIALOG_SLISTPIZZA, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"Service-Liste: "COLOR_HEX_WHITE"Pizza", str2, "Schließen", "");
        }
        else if(Spieler[playerid][pJob] == 16)
        {
            new bool:IsOnline;
            for(new i = 0 ; i < MAX_PLAYERS ; i++)
            {
                if(IsPlayerConnected(i) && gPlayerLogged[i] == 1)
                {
                    if(NeedTAXI[i] == 1)
                    {
                        format(string, sizeof(string), "%s hat ein Taxi gerufen! (ID: %d) (Nummer: %i)\n", GetName(i), i, Spieler[i][pHandyNr]);
                        strcat(str2, string);
                        IsOnline = true;
                    }
                }
            }
            if(!IsOnline)
            {
                SendClientMessage(playerid, COLOR_RED, "Niemand hat ein Taxi gerufen!");
                return 1;
            }
            SendClientMessage(playerid, COLOR_BLUE, "INFO: "COLOR_HEX_WHITE"Du kannst mit /Accepttaxi [ID] einen Service-Anruf annehmen!");
            ShowPlayerDialog(playerid, DIALOG_SLISTTAXI, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"Service-Liste: "COLOR_HEX_WHITE"Taxi", str2, "Schließen", "");
        }
        else if(Spieler[playerid][pFraktion] == 17)
        {
            new bool:IsOnline;
            for(new i = 0 ; i < MAX_PLAYERS ; i++)
            {
                if(IsPlayerConnected(i) && gPlayerLogged[i] == 1)
                {
                    if(NeedWHEEL[i] == 1)
                    {
                        format(string, sizeof(string), "%s ruft ein Wheelman! (ID: %d) (Nummer: %i)\n", GetName(i), i, Spieler[i][pHandyNr]);
                        strcat(str2, string);
                        IsOnline = true;
                    }
                }
            }
            if(!IsOnline)
            {
                SendClientMessage(playerid, COLOR_RED, "Niemand hat ein Wheelman gerufen!");
                return 1;
            }
            SendClientMessage(playerid, COLOR_BLUE, "INFO: "COLOR_HEX_WHITE"Du kannst mit /Acceptwheel [ID] einen Service-Anruf annehmen!");
            ShowPlayerDialog(playerid, DIALOG_SLISTWHEEL, DIALOG_STYLE_MSGBOX, COLOR_HEX_ORANGE"Service-Liste: "COLOR_HEX_WHITE"Pizza", str2, "Schließen", "");
        }
    }
    return 1;
}



CMD:jobkleidung(playerid,params[]) {
    #pragma unused params
    new
        job = Spieler[playerid][pJob];
    if(!job) {
        SendClientMessage(playerid,COLOR_RED,"Du hast keinen Job.");
    }
    else {
        for(new i ; i < sizeof(g_JobSkins) ; i++) {
            if( IsPlayerInRangeOfPoint(playerid,5.0,g_JobSkins[i][JS_fX],g_JobSkins[i][JS_fY],g_JobSkins[i][JS_fZ] )) {
                if( job == g_JobSkins[i][JS_iJob] ) {
                    if( GetPlayerSkin(playerid) == Spieler[playerid][pSkin] ) {
                        SetPlayerSkin(playerid,g_JobSkins[i][JS_iSkin]);
                        SendClientMessage(playerid,COLOR_GREEN,"Du hast deinen Job-Skin angezogen.");
                    }
                    else {
                        SetPlayerSkin(playerid,Spieler[playerid][pSkin]);
                        SendClientMessage(playerid,COLOR_YELLOW,"Du hast deinen Job-Skin ausgezogen.");
                    }
                }
                else {
                    SendClientMessage(playerid,COLOR_RED,"Falscher Job für diese Wechselposition.");
                }
                return 1;
            }
        }
        SendClientMessage(playerid,COLOR_RED,"Du kannst deine Jobkleidung hier nicht wechseln.");
    }
    return 1;
}


CMD:illegalejobs(playerid)
{
    if(!IsPlayerInRangeOfPoint(playerid, 5.0, JEFF_COORDS)) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht bei Jeff.");
    if(IsBeamter(playerid)) return SendClientMessage(playerid, COLOR_RED, "Als Beamter kannst du keine Illegalen Jobs ausführen.");
    SendClientMessage(playerid, COLOR_WHITE, "Jeff sagt: Mh.. Du willst also dein Geld auf eine andere Weise verdienen?");
    SendClientMessage(playerid, COLOR_WHITE, "Ich hab da so einige Jobs für dich auf Lager. Schau dich um!");  
    ShowPlayerDialog(playerid, DIALOG_SCHWARZBERUF, DIALOG_STYLE_LIST, "ILLEGALE JOBS", COLOR_HEX_WHITE">> aktuellen Beruf kündigen\nWaffendealer\nTaschendieb\nProstituierte\nWanted-Hacker\nAutodieb", "Auswählen", "Abbrechen");
    return 1;
}


CMD:stadthalle(playerid)
{
    if(pCheckpoint[playerid] == CP_TUTORIAL4)
    {
        SendClientMessage(playerid, COLOR_GREEN, "Den Personalausweis sowie deinen Job kannst du natürlich auch im späteren Verlauf aussuchen!");
        SendClientMessage(playerid, COLOR_GREEN, "Du kannst ihn natürlich auch jetzt aussuchen. Wenn du dies getan hast, gehe wieder nach draußen!");
        SetPlayerCheckpointEx(playerid, 387.5433,173.5221,1008.3828, 5.0, CP_TUTORIAL5);
    }
    if (!IsPlayerInRangeOfPoint(playerid, 2.0, CITYHALL_INTERIOR_STADTHALLE)) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Stadthalle am Informationspunkt.");
    new String[228];
    String = COLOR_HEX_WHITE"Personalausweis beantragen"COLOR_HEX_ORANGE" ($200)"COLOR_HEX_WHITE"\n------------\nArbeitsamt:\nBerufe\nSelbstständigkeit\n------------";
    if( Spieler[playerid][pHartz4]  == 0) {
        format(String,sizeof(String),"%s\nArbeitslosengeld beantragen (+$"#HARTZ4_GELD")",String);
    }
    else {
        format(String,sizeof(String),"%s\nArbeitslosengeld stornieren",String);
    }
    ShowPlayerDialog(playerid, DIALOG_STADTHALLE, DIALOG_STYLE_LIST, "Stadthalle", String, "Auswählen", "Abbrechen");
    return 1;
}

CMD:leavekartbahn(playerid, params[]) {
    if(Spieler[playerid][pFahrgeschaeft] != 4)
        return SendClientMessage(playerid, COLOR_RED, "Du befindest dich nicht in der Kartbahn!");

    RemovePlayerKartbahn(playerid);
    UnfreezePlayer(playerid);
    return SendClientMessage(playerid, COLOR_YELLOW, "Du hast die Kartbahn erfolgreich verlassen");
}


CMD:ticketkaufen(playerid,params[]) {
    new
        fahrgeschaeft = -1;
    if( IsPlayerInRangeOfPoint(playerid,3.0,374.6658,-2121.6416,7.8820) ) { // fallturm
        fahrgeschaeft = 0;
    }
    else if( IsPlayerInRangeOfPoint(playerid,3.0,373.8057,-2056.3586,7.9260) ) {// autoscooter
        fahrgeschaeft = 1;
    }
    else  if( IsPlayerInRangeOfPoint(playerid,3.0,356.7114,-2149.5613,7.8779) ) {// breakdancer
        fahrgeschaeft = 2;
    }
    else  if( IsPlayerInRangeOfPoint(playerid,3.0,382.0282,-2165.8818,7.8511) ) {// schiff
        fahrgeschaeft = 3;
    }
    else  if( IsPlayerInRangeOfPoint(playerid,3.0, KARTPARCOUR_TICKETPOINT) ) {// Kartbahn
        fahrgeschaeft = 4;
    }
    else  if( IsPlayerInRangeOfPoint(playerid,3.0,396.3516,-2152.5928,7.8399) ) {// Wasserbahn
        fahrgeschaeft = 5;
    }
    if( fahrgeschaeft == -1 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du befindest dich nicht an einem Fahrgeschäft");
    }
    if( Spieler[playerid][pCash] < 300 ) {
        return SendClientMessage(playerid,COLOR_RED,"Eine Fahrt kostet 300$");
    }
    if( Spieler[playerid][pFahrgeschaeft] != -1 ) {
        return SendClientMessage(playerid,COLOR_RED,"Du bist noch in einem Fahrgeschäft");
    }
    SetPlayerToFahrgeschaeft(playerid,fahrgeschaeft);
    return 1;
}
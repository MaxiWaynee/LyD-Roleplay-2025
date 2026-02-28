#include <YSI\y_hooks>

CMD:guthaben(playerid)
{
    new string[128];
    if( Spieler[playerid][pHandyGeld] == HANDY_VERTRAG ) {
        format(string, sizeof(string), COLOR_HEX_WHITE"Dein Handy-Guthaben beträgt "COLOR_HEX_ORANGE"$/. ( Handy-Vertrag )");
    }
    else {
        format(string, sizeof(string), COLOR_HEX_WHITE"Dein Handy-Guthaben beträgt "COLOR_HEX_ORANGE"$%s.", AddDelimiters(Spieler[playerid][pHandyGeld]));
    }
    SendClientMessage(playerid, COLOR_WHITE, string);
    return 1;
}

CMD:abnehmen(playerid)
{
    new string[128];
    if(CurrentPhone[playerid] != 999)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Du telefonierst bereits...");
        return 1;
    }
    for(new i = 0 ; i < MAX_PLAYERS ; i++)
    {
        if(IsPlayerConnected(i))
        {
            if(CurrentPhone[i] == playerid)
            {
                if(Spieler[playerid][pMuted]== 1) return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du kannst nicht telefonieren während zu gemuted bist");
                if(Spieler[playerid][pTot] == 1) return SendClientMessage(playerid, COLOR_RED, "Du kannst nicht telefonieren während du tot bist!");
                new Float:x, Float:y, Float:z;
                GetPlayerPos(playerid, x,y,z);
                CurrentPhone[playerid] = i;
                SendClientMessage(i, COLOR_YELLOW, "Der Spieler hat den Hörer abgenommen.");
                format(string, sizeof(string), "* %s geht an sein/ihr Handy.", GetName(playerid));
                SendRoundMessage(x,y,z, COLOR_PURPLE, string);

                SetPlayerSpecialAction( playerid, SPECIAL_ACTION_USECELLPHONE );

                if( TelefonzelleAn[i] == playerid ) {
                    // Telefonzellen anrufen
                    GameTextForPlayer(i, "~r~$-150", 3000, 1);
                    GivePlayerCash(i,-150);
                }
                else {
                    SetPlayerSpecialAction( i, SPECIAL_ACTION_USECELLPHONE );
                }
            }
        }
    }
    return 1;
}

CMD:auflegen(playerid)
{
    new caller = CurrentPhone[playerid];
    if(IsPlayerConnected(caller))
    {
        if(caller != INVALID_PLAYER_ID)
        {
            if(caller != 999)
            {
                if(caller < 999)
                {
                    SendClientMessage(caller, COLOR_YELLOW, "Der Spieler hat aufgelegt ...");
                    SendClientMessage(playerid, COLOR_WHITE, "Du hast aufgelegt.");
                    CurrentPhone[caller] = 999;
                    CurrentPhone[playerid] = 999;
                    if( Spieler[playerid][pHandyGeld] == HANDY_VERTRAG ) {
                    }
                    else {
                        Spieler[playerid][pHandyGeld] -= 100;
                        GameTextForPlayer(playerid, "~r~$-100", 3000, 1);
                    }
                    if( TelefonzelleAn[caller] == playerid ) {
                        TelefonzelleAn[caller] = INVALID_PLAYER_ID;
                        UnfreezePlayer(caller);
                    }
                    if( TelefonzelleAn[playerid] == caller ) {
                        TelefonzelleAn[playerid] = INVALID_PLAYER_ID;
                        UnfreezePlayer(playerid);
                    }
                    SetPlayerSpecialAction( caller, SPECIAL_ACTION_STOPUSECELLPHONE );
                    SetPlayerSpecialAction( playerid, SPECIAL_ACTION_STOPUSECELLPHONE );

                    return 1;
                }
            }
        }
    }
    return 1;
}

CMD:sms(playerid, params[])
{
    if(Spieler[playerid][pMuted]== 1)return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du bist gemutet.");
    if(Spieler[playerid][pHandyGeld] < 30)return SendClientMessage(playerid, COLOR_RED, "Du hast nicht mehr genügend Handygeld. ($30)");
    if(Spieler[playerid][pPrisonRun] > 0 ) return SendClientMessage(playerid, COLOR_RED, "Du kannst niemaden anrufen oder Anrufe entgegennehmen wenn du im Straflauf bist!");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du Tod bist, kannst du keine SMS schreiben.");
    if(Spieler[playerid][pHandyState] == 0)return SendClientMessage(playerid, COLOR_RED, "Dein Handy ist ausgeschaltet! Mit /Handystatus schaltest du es wieder an.");
    new pPhone, pID, string[144], text[128];
    if(sscanf(params, "is[96]", pPhone, text))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Sms [Nummer] [Nachricht]");
    if(pPhone == Spieler[playerid][pHandyNr])return SendClientMessage(playerid, COLOR_RED, "Du kannst dir selbst keine Nachricht senden.");
    if(Spieler[playerid][pHandyNr] == 0 )return SendClientMessage(playerid, COLOR_RED, "Du hast noch keine Handy-Nr.");
    if( Spieler[playerid][pLevel] < 2 ) {
        return SendClientMessage(playerid, COLOR_RED, "Aus Sicherheitsgründen musst du Level 2 sein um diese Funktion nutzen zu können!");
    }
    if( Spieler[playerid][pJailed] ) {
        return SendClientMessage(playerid, COLOR_RED, "Du kannst vom Gefängnis aus keine SMS verschicken!");
    }
    if( bBlockTelecom ) {
        return SendClientMessage(playerid, COLOR_RED, "Die Telekommunikation wurde vom Staat vorübergehend abgeschaltet.");
    }
    for(new i = 0 ; i < MAX_PLAYERS ; i++)
    {
        if(IsPlayerConnected(i))
        {
            if(Spieler[i][pHandyNr] == pPhone && Spieler[i][pHandyNr] != 0 && pPhone != 0)
            {
                pID = i;
                if(Spieler[pID][pHandyState] == 0)return SendClientMessage(playerid, COLOR_RED, "Das Handy des Spielers ist aus.");
                if(IsPlayerConnected(pID))
                {
                    if(pID != INVALID_PLAYER_ID)
                    {
                        PlayAudioStreamForPlayer(pID, "http://LyD-Roleplay.de/musik/sms.mp3");
                        format(string, sizeof(string), "[SMS]: %s, Von: %s (Nr. %d)", text, GetName(playerid), Spieler[playerid][pHandyNr]);
                        SendClientMessage(pID, COLOR_YELLOW, string);
                        format(string, sizeof(string), "[SMS] Nachricht versendet - %s, An: %s (Nr: %d)", text, GetName(pID), Spieler[pID][pHandyNr]);
                        SendClientMessage(playerid, COLOR_YELLOW, string);
                        if( Spieler[playerid][pHandyGeld] == HANDY_VERTRAG ) {
                        }
                        else {
                            GameTextForPlayer(playerid, "~r~$-50", 3000, 1);
                            Spieler[playerid][pHandyGeld] -= 50;
                        }
                        return 1;
                    }
                }
            }
        }
    }
    return 1;
}

CMD:nummer(playerid, params[])
{
    new pID, string[128];
    if (sscanf(params, "u", pID)) return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING "/Nummer [Spieler ID/Name]");
    if (pID == INVALID_PLAYER_ID || !gPlayerLogged[pID]) return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
    if (Spieler[playerid][pPhoneBook] == 0) return SendClientMessage(playerid, COLOR_RED, "Du besitzt noch kein Telefonbuch, kaufe dir eines in einem 24/7-Shop.");
    format(string, sizeof(string), COLOR_HEX_BLUE"Name: "COLOR_HEX_WHITE"%s "COLOR_HEX_ORANGE"|"COLOR_HEX_BLUE" Nummer: "COLOR_HEX_WHITE"%d", GetName(pID), Spieler[pID][pHandyNr]);
    SendClientMessage(playerid, COLOR_WHITE, string);
    return 1;
}


CMD:handystatus(playerid, params[]) {
    new status[16];
    if(sscanf(params, "s[16]", status))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Handystatus [An/Aus]");
    if(strcmp(status, "an", true) == 0)
    {
        if (!Spieler[playerid][pHandyState]) SendClientMessage(playerid, COLOR_WHITE, "Du hast dein Handy angeschaltet.");
        else SendClientMessage(playerid, COLOR_WHITE, "Dein Handy ist bereits angeschaltet.");
        Spieler[playerid][pHandyState] = 1;
    }
    else if(strcmp(status, "aus", true) == 0)
    {
        if (Spieler[playerid][pHandyState]) SendClientMessage(playerid, COLOR_WHITE, "Du hast dein Handy ausgeschaltet.");
        else SendClientMessage(playerid, COLOR_WHITE, "Dein Handy ist bereits ausgeschaltet.");
        Spieler[playerid][pHandyState] = 0;
    }
    else return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Handystatus [An/Aus]");
    return 1;
}

CMD:anrufen(playerid, params[])
{
    if(Spieler[playerid][pMuted]== 1)return SendClientMessage(playerid, COLOR_CHAT_MUTED, "Du bist gemutet.");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst niemaden anrufen oder Anrufe entgegennehmen wenn du Tod bist!");
    if(Spieler[playerid][pPrisonRun] > 0 ) return SendClientMessage(playerid, COLOR_RED, "Du kannst niemaden anrufen oder Anrufe entgegennehmen wenn du im Straflauf bist!");
    if(Spieler[playerid][pHandyState] == 0)return SendClientMessage(playerid, COLOR_RED, "Dein Handy ist ausgeschaltet! Mit /Handystatus schaltest du es wieder an.");
    new pPhone, pID, string[128];
    if(CurrentPhone[playerid] != 999)return SendClientMessage(playerid, COLOR_RED, "Du telefonierst bereits.");
    if(sscanf(params, "i", pPhone))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Anrufen [Nummer]");
    if(Spieler[playerid][pHandyNr] == 0 )return SendClientMessage(playerid, COLOR_RED, "Du hast noch keine Handy-Nr.");
    if(Spieler[playerid][pHandyGeld] < 50 && pPhone != 110 && pPhone != 112 && pPhone != 113 )return SendClientMessage(playerid, COLOR_RED, "Du hast nicht genügend Handyguthaben. ($50)");
    if(pPhone == Spieler[playerid][pHandyNr])return SendClientMessage(playerid, COLOR_RED, "Du kannst dich selbst nicht anrufen.");
    if( Spieler[playerid][pLevel] < 2 ) return SendClientMessage(playerid, COLOR_RED, "Aus Sicherheitsgründen musst du Level 2 sein, um diese Funktion nutzen zu können!");
    if( Spieler[playerid][pJailed] ) return SendClientMessage(playerid, COLOR_RED, "Du kannst vom Gefängnis aus nicht telefonieren!");
    if( bBlockTelecom ) return SendClientMessage(playerid, COLOR_RED, "Die Telekommunikation wurde vom Staat vorübergehend abgeschaltet.");
    if(pPhone == 110 ) {
        // Notruf
        SetPlayerSpecialAction( playerid, SPECIAL_ACTION_USECELLPHONE );

        SendClientMessage(playerid,COLOR_RED,"POLIZEI-NOTRUF");
        SendClientMessage(playerid,COLOR_WHITE,"Hier ist der Notruf der San Andreas Polizei!");
        SendClientMessage(playerid,COLOR_WHITE,"Schilderen Sie bitte kurz die Notsituation.");
        CurrentPhone[playerid] = INVALID_PLAYER_ID;

        // SetRandomPoliceTask(playerid);
        return 1;
    }
    if(pPhone == 111 ) {
        // Notruf
        SetPlayerSpecialAction( playerid, SPECIAL_ACTION_USECELLPHONE );
        PlayerPlaySound(playerid, 20600, 0.0, 0.0, 0.0);
        SendClientMessage(playerid, COLOR_YELLOW, "[SMS]: Hey, Soll ich dir dein Fahrzeug bringen? [Ja/Nein], Von: Mechaniker (Nr. 111)");
        CurrentPhone[playerid] = INVALID_PLAYER_ID + 4;

        // SetRandomPoliceTask(playerid);
        return 1;
    }
    else if(pPhone == 112 ) {
        // Rettungsdienst Notruf
        SetPlayerSpecialAction( playerid, SPECIAL_ACTION_USECELLPHONE );

        SendClientMessage(playerid,COLOR_RED,"RETTUNGSDIENST-NOTRUF");
        SendClientMessage(playerid,COLOR_WHITE,"Hier ist die Notrufzentrale der Feuerwehr und Rettungsdienst.");
        SendClientMessage(playerid,COLOR_WHITE,"Schilderen Sie bitte kurz die Notsituation.");
        CurrentPhone[playerid] = INVALID_PLAYER_ID + 1;

        // SetRandomPoliceTask(playerid);
        return 1;
    }
    else if(pPhone == 113 ) {
        // Ordnungsamt Notruf
        SetPlayerSpecialAction( playerid, SPECIAL_ACTION_USECELLPHONE );

        SendClientMessage(playerid,COLOR_RED,"ORDNUNGSAMT-SERVICERUF");
        SendClientMessage(playerid,COLOR_WHITE,"Hier ist der Serviceruf des Ordnungsamtes.");
        SendClientMessage(playerid,COLOR_WHITE,"Schilderen Sie bitte kurz den Sachverhalt.");
        CurrentPhone[playerid] = INVALID_PLAYER_ID + 2;

        // SetRandomPoliceTask(playerid);
        return 1;
    }
    else if(pPhone == 7575 ) {
        // Rettungsdienst Notruf
        SetPlayerSpecialAction( playerid, SPECIAL_ACTION_USECELLPHONE );

        SendClientMessage(playerid,COLOR_YELLOW,"WHEELMEN-SERVICERUF");
        SendClientMessage(playerid,COLOR_WHITE,"Wir sind ein Befreiungs- und Personenschutzservice.");
        SendClientMessage(playerid,COLOR_WHITE,"Schildere uns bitte kurz den Sachverhalt.");
        CurrentPhone[playerid] = INVALID_PLAYER_ID + 3;

        // SetRandomPoliceTask(playerid);
        return 1;
    }
    for(new i = 0 ; i < MAX_PLAYERS ; i++)
    {
        if(IsPlayerConnected(i))
        {
            if(Spieler[i][pHandyNr] == pPhone && Spieler[i][pHandyNr] != 0 && pPhone != 0)
            {
                pID = i;
                if(Spieler[pID][pHandyState] == 0)return SendClientMessage(playerid, COLOR_ORANGE, "Das Handy des Spielers ist aus.");
                if (CurrentPhone[pID] != 999) return SendClientMessage(playerid, COLOR_ORANGE, "Die Leitung ist besetzt...");
                CurrentPhone[playerid] = pID;
                if(IsPlayerConnected(pID))
                {
                    if(pID != INVALID_PLAYER_ID)
                    {
                        PlayerPlaySound(playerid, 3600, 0.0, 0.0, 0.0);
                        SendClientMessage(playerid, COLOR_WHITE, "Es klingelt...");
                        PlayerPlaySound(pID, 20600, 0.0, 0.0, 0.0);
                        // PlayAudioStreamForPlayer(pID, "http://LyD-Roleplay.de/musik/anruf.mp3");
                        format(string, sizeof(string), "Dein Handy klingelt. Anrufer: %s. Tippe '/Abnehmen' um den Anruf anzunehmen.", GetName(playerid));
                        SendClientMessage(pID, COLOR_YELLOW, string);
                        format(string, sizeof(string), "* %s's %s klingelt.", GetName(pID) , GetPlayerHandyName(pID) );
                        new Float:x, Float:y, Float:z;
                        GetPlayerPos(pID, x,y,z);
                        SendRoundMessage(x,y,z,COLOR_PURPLE, string);
                        SetPlayerSpecialAction( playerid, SPECIAL_ACTION_USECELLPHONE );
                    }
                }
            }
        }
    }
    return 1;
}


CMD:telefonzelle(playerid,params[]) {
    if( IsPlayerAtTelefonzelle(playerid) == 999 ) {
        SendClientMessage(playerid,COLOR_RED,"Du befindest dich nicht an einer Telefonzelle.");
        return 1;
    }
    if( Spieler[playerid][pLevel] < 2 ) {
        return SendClientMessage(playerid, COLOR_RED, "Aus Sicherheitsgründen musst du Level 2 sein um diese Funktion nutzen zu können!");
    }
    if( TelefonzelleAn[playerid] != INVALID_PLAYER_ID ) {
        SendClientMessage(playerid,COLOR_RED,"Du tätigst bereits einen Anruf.");
        return 1;
    }
    if( bBlockTelecom ) {
        return SendClientMessage(playerid, COLOR_RED, "Die Telekommunikation wurde vom Staat vorübergehend abgeschaltet.");
    }
    ShowPlayerDialog(playerid,DIALOG_TELEFONZELLE,DIALOG_STYLE_LIST,"Telefonzelle","Anrufen\nSMS","Weiter","Abbruch");
    return 1;
}



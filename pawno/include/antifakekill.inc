
#define ADMINNAME "Server-System"
//-------------------
#define Kickplayer

//Variables:
new AntiFakekill[MAX_PLAYERS];

stock Fakekill_OnPlayerDeath(playerid, killerid, reason)
{
	#pragma unused killerid,reason
    AntiFakekill[playerid]++;
    SetTimerEx("AntiFakekillTimer", 5009,false,"i",playerid); // 3sec Cooldown pro Death
    //SendDeathMessage(killerid,playerid,reason);
    return 1;
}

forward AntiFakekillTimer(playerid);
public AntiFakekillTimer(playerid)
{
	if( IsPlayerConnected(playerid) ) {
	    AntiFakekill[playerid]--;
	    if(AntiFakekill[playerid] > 2) {
	        new
			    querystring[256],
	            stringtu[128];
	        SendClientMessage(playerid, COLOR_RED, "Du wurdest gebannt!");
	        format(stringtu, sizeof(stringtu), "Name: %s", GetName(playerid));
	        SendClientMessage(playerid, COLOR_WHITE, stringtu);
	        SendClientMessage(playerid, COLOR_WHITE, "Grund: Fakekill");
	        SendClientMessage(playerid, COLOR_WHITE, "Admin: "#ADMINNAME"");
	        format(stringtu, sizeof(stringtu), "Datum: %s", GetDate());
	        SendClientMessage(playerid, COLOR_WHITE, stringtu);
	        format(stringtu, sizeof(stringtu), "Uhrzeit: %s", GetTime());
	        SendClientMessage(playerid, COLOR_WHITE, stringtu);
	        format(stringtu, sizeof(stringtu), "IP: %s", GetIP(playerid));
	        SendClientMessage(playerid, COLOR_WHITE, stringtu);
		    new weburl[64];
		    GetServerVarAsString("weburl", weburl, sizeof(weburl));
			TogglePlayerControllable(playerid, false);

			format(querystring,sizeof(querystring),"INSERT INTO `akte` (`id`, `time`, `spieler`, `admin`, `content`) VALUES (NULL, CURRENT_TIMESTAMP, '%s', '%s', '%s');",GetName(playerid),("Server-System"),("Verdacht auf Fakekill") );
			mysql_oquery(querystring,THREAD_AKTENEINTRAG,INVALID_PLAYER_ID,gWebSQL);
			format(stringtu,sizeof(stringtu),"Spieler %s wurde wegen Server gekickt. Grund: Verdacht auf FakeKill",GetName(playerid));
            SendAdminMessage(COLOR_LIGHTRED2,stringtu);
			BanDelay(playerid);
	    }
	}
    return 1;
}

stock GetTime()
{
    new Zeit[20],Stunde,Minute,Sekunde;
    gettime(Stunde,Minute,Sekunde);
    format(Zeit,sizeof(Zeit),"%02d:%02d:%02d",Stunde,Minute,Sekunde);
    return Zeit;
}

stock GetDate()
{
    new Datum[40],Tag,Monat,Jahr;
    getdate(Jahr,Monat,Tag);
    format(Datum,sizeof(Datum),"%d. %s %d",Tag,GetMonth(Monat),Jahr);
    return Datum;
}

stock GetMonth(month)
{
    new string[40];
    string="Unknown month";
    switch(month)
    {
        case 1:
            string="January";
        case 2:
            string="February";
        case 3:
            string="March";
        case 4:
            string="April";
        case 5:
            string="May";
        case 6:
            string="June";
        case 7:
            string="July";
        case 8:
            string="August";
        case 9:
            string="September";
        case 10:
            string="October";
        case 11:
            string="November";
        case 12:
            string="December";
    }
    return string;
}

stock GetIP(playerid)
{
    new ip[24];
    GetPlayerIp(playerid, ip,sizeof(ip));
    return ip;
}

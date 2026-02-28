
stock IsIPBan(playerid) {
	new
	    // rows,
	    query[128],
	    ip[16],
	    iprange[16];
	GetPlayerIp(playerid,ip,sizeof(ip));
	iprange = IP2RootIP( ip , 2);
	format(query,sizeof(query),"SELECT * FROM `rangeban` WHERE `IPRange` = '%s'",iprange);
	mysql_pquery( query , THREAD_ISIPBAN , playerid , gSQL , MySQLThreadOwner );
	/*
	mysql_store_result();
	rows = mysql_num_rows();
	mysql_free_result();
	if( rows ) {
	    new
	        name[MAX_PLAYER_NAME];
		GetPlayerName(playerid,name,sizeof(name));
	    return !IsWhitelist(name);
	}
	*/
	return 0;
}

stock AddIPBan( ip[16] ) {
	new
	    query[128],
	    iprange[16];
	iprange = IP2RootIP( ip , 2);
	format(query,sizeof(query),"INSERT INTO `rangeban` VALUES (NULL, '%s')",iprange);
	mysql_oquery(query,THREAD_ADDIPBAN,INVALID_PLAYER_ID,gSQL );
	return 1;
}

stock IsIPBanned( ip[16] ) {
	new
	    query[128],
	    iprange[16];
	iprange = IP2RootIP( ip , 2);
	format(query,sizeof(query),"SELECT * FROM `rangeban` WHERE `IPRange` = '%s'",iprange);
	mysql_oquery( query , THREAD_ISIPBANNED , INVALID_PLAYER_ID , gSQL  );
	/*
	mysql_store_result();
	rows = mysql_num_rows();
	mysql_free_result();
	return rows;
	*/
	return 1;
}

stock IsWhitelist( name[MAX_PLAYER_NAME] , extraid ) {
	new
	    query[128];
	mysql_real_escape_string(name,name);
	format(query,sizeof(query),"SELECT * FROM `whitelist` WHERE `Name` = '%s'",name,false );
	mysql_pquery( query , THREAD_ISWHITELIST , extraid , gSQL, MySQLThreadOwner);
	PlayerSQLExtra(extraid, name );
	/*
	mysql_store_result();
	rows = mysql_num_rows();
	mysql_free_result();
	if( rows ) return 1;
	return 0;
	*/
}
stock AddWhitelist( name[MAX_PLAYER_NAME]) {
	new
	    query[128];
	mysql_real_escape_string(name,name);
	format(query,sizeof(query),"INSERT INTO `whitelist` VALUES (NULL, '%s');",name);
	mysql_oquery( query , THREAD_ADDWHITELIST , INVALID_PLAYER_ID , gSQL  );
	return 1;
}
stock IP2RootIP(ip[16], blocks) { //breadfish
	new
		rootend,
		i,
		rootip[16];
	if (blocks >= 4) {
	    rootip = ip;
	} else {
		for (i=1;i<=blocks;i++) {
			rootend = strfind(ip, ".", true, rootend) + 1;
		}
		strmid(rootip, ip, 0, rootend - 1);
	}

	for (i=1;i<=4-blocks;i++) {
	    strcat(rootip, ".*");
	}
	return rootip;
}


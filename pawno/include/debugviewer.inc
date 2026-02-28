/*****************************************************************************
*
*	Projekt:		gF4A
*	Lizenz:			GNU Version 3
*	Datei:			gF4A\0system\debugviewer.inc
*	Nutzung:		ingame debugviewer
*
*       gF4A  -  by Goldkiller
*
*****************************************************************************/

#define _include_debugviewer_

#define Debug::\
	Debug_

#define MAX_DEBUG_MESSAGE 1600
#define MAX_DEBUG_MESSAGES 10

#define DEBUG_FILE_PATH "debugviewer.txt"
new bool:FALSE = false;
enum e_DebugViewer {
	DV_sDebug[MAX_DEBUG_MESSAGE]
}
new
	g_iDebugTick,
	g_iDebugMessagesCount,
	g_DebugViewer[MAX_DEBUG_MESSAGES][e_DebugViewer];

#define Debug_AddEntry(%0,%1)\
	do { \
    	format(g_DebugViewer[g_iDebugMessagesCount],MAX_DEBUG_MESSAGE,%0,%1);\
    	g_iDebugMessagesCount++;\
    	Debug_WriteDebug();\
	}\
	while(FALSE)

stock Debug::Debug() {
	print("+ Init: Debug");
    g_iDebugMessagesCount = 0;
	for(new i ; i < MAX_DEBUG_MESSAGES ; i++) {
	    g_DebugViewer[i][DV_sDebug][0] = '\0';
	}
	g_iDebugTick = GetTickCount();
	
	SetTimer("Debug_TryCatch",1007,true);
	return 1;
}

forward Debug_TryCatch();
public Debug_TryCatch() {
	new
	    differenz;
	differenz = GetTickCount() - g_iDebugTick;
	if( differenz > 1370 ) {
	    printf(">> ERROR: Debug_TryCatch ticks: %d",differenz);
	}
    g_iDebugTick += differenz;
    return 1;
}

stock Debug::DebugClose() {
    Debug_WriteDebugEx();
    return 1;
}


stock Debug_WriteDebug() {
	if( g_iDebugMessagesCount == sizeof(g_DebugViewer) ) {
		new
		    File:fFile,
		    sDebug[MAX_DEBUG_MESSAGE + 10];
		if( !fexist(DEBUG_FILE_PATH) ) {
			fFile = fopen(DEBUG_FILE_PATH,io_write);
			fclose(fFile);
		}
		fFile = fopen(DEBUG_FILE_PATH,io_append);
		if(!fFile) {
		    printf("Debug_WriteDebug -- fFile");
			return 0;
		}
		for(new i ; i < sizeof(g_DebugViewer) ; i++) {
		    format(sDebug,sizeof(sDebug),"%s\r\n", g_DebugViewer[i][DV_sDebug] );
		    fwrite(fFile,sDebug);
		}
		g_iDebugMessagesCount = 0;
		fclose(fFile);
		return 1;
	}
	return 0;
}
stock Debug_WriteDebugEx() {
	new
	    File:fFile,
	    sDebug[MAX_DEBUG_MESSAGE + 10];
	if( !fexist(DEBUG_FILE_PATH) ) {
		fFile = fopen(DEBUG_FILE_PATH,io_write);
		fclose(fFile);
	}
	fFile = fopen(DEBUG_FILE_PATH,io_append);
	if(!fFile) {
	    printf("Debug_WriteDebug -- fFile");
		return 0;
	}
	for(new i ; i < sizeof(g_iDebugMessagesCount) ; i++) {
	    format(sDebug,sizeof(sDebug),"%s\r\n", g_DebugViewer[i][DV_sDebug] );
	    fwrite(fFile,sDebug);
	}
	g_iDebugMessagesCount = 0;
	fclose(fFile);
	return 1;
}


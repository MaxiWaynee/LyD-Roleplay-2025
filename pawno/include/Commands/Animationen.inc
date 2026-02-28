#include <YSI\y_hooks>


//Animationen
CMD:animlist(playerid)
{
    SendClientMessage(playerid, COLOR_GREEN, "==> Verügbare Animationen:");
    SendClientMessage(playerid,COLOR_WHITE,"/Handsup, /Drunk, /Bomb, /Getarrested, /Laugh, /Lookout, /Robman, /Wank, /Chairsit, /Celebrate");
    SendClientMessage(playerid,COLOR_WHITE,"/Crossarms, /Lay, /Hide, /Vomit, /Eat, /Wave[1-2], /Taichi, /Pee, /Dance[1-4], /Idles, /Tired");
    SendClientMessage(playerid,COLOR_WHITE,"/Deal, /Smokem, /Smokef, /Groundsit[1-3], /Chat, /Fucku, /Kiss[1-6], /Angry, /Follow, /Cry");
    SendClientMessage(playerid,COLOR_WHITE,"Stoppen mit Enter");
    return 1;
}

CMD:handsup(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    SetPlayerSpecialAction(playerid,SPECIAL_ACTION_HANDSUP);
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    SetPlayerSpecialAction(playerid,SPECIAL_ACTION_HANDSUP);
    return 1;
}
CMD:drunk(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    LoopingAnim(playerid,"PED","WALK_DRUNK",4.0,1,1,1,1,0);
    return 1;
}
CMD:cry(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"GRAVEYARD","mrnF_loop", 4.0, 1, 0, 0, 0, 0);
    return 1;
}
CMD:tired(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"PED", "IDLE_tired", 4.0, 1, 0, 0, 0, 0, 1);
    return 1;
}
CMD:bomb(playerid)
{
    if (Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if (Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if (GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    OnePlayAnim(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0); // Place Bomb
    return 1;
}
CMD:getarrested(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    LoopingAnim(playerid,"ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1); // Gun Arrest
    return 1;
}
CMD:laugh(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    OnePlayAnim(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0); // Laugh
    return 1;
}
CMD:lookout(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    OnePlayAnim(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0); // Rob Lookout
    return 1;
}
CMD:robman(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    LoopingAnim(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0); // Rob
    return 1;
}
CMD:wank(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"PAULNMAC", "wank_loop", 1.800001, 1, 0, 0, 1, 600);
    return 1;
}
CMD:angry(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"RIOT","RIOT_ANGRY",4.0,0,0,0,0,0);
    return 1;
}
CMD:follow(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"WUZI","Wuzi_follow",4.0,0,0,0,0,0);
    return 1;
}
CMD:crossarms(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    LoopingAnim(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1); // Arms crossed
    return 1;
}
CMD:lay(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    LoopingAnim(playerid,"BEACH", "bather", 4.0, 1, 0, 0, 0, 0); // Lay down
    return 1;
}
CMD:hide(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    LoopingAnim(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0); // Taking Cover
    return 1;
}
CMD:vomit(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    OnePlayAnim(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0); // Vomit BAH!
    return 1;
}
CMD:eat(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    OnePlayAnim(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0); // Eat Burger
    return 1;
}

CMD:wave(playerid, params[])
{
    new nr;
    if(sscanf(params, "i", nr))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Wave [1-2]");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    if(nr > 2 || nr < 1)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Wave [1-2]");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    if(nr == 1)
    {
        LoopingAnim(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0); // Wav
    }
    else if(nr == 2)
    {
        ApplyAnimation(playerid, "PED", "endchat_03", 4.0, 1, 0, 0, 0, 0, 1);
    }
    return 1;
}

CMD:taichi(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    LoopingAnim(playerid,"PARK","Tai_Chi_Loop",4.0,1,0,0,0,0);
    return 1;
}
CMD:pee(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_PISSING);
    return 1;
}
CMD:chairsit(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"PED","SEAT_idle", 4.0, 1, 0, 0, 0, 0);
    return 1;
}
CMD:stretch(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"PLAYIDLES","stretch",4.0,0,0,0,0,0);
    return 1;
}

CMD:idles(playerid, params[])
{
    new nr;
    if(sscanf(params, "i", nr))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Idles [1-2]");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    if(nr > 2 || nr < 1)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Idles [1-2]");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    if(nr == 1)
    {
        LoopingAnim(playerid,"COP_AMBIENT","Coplook_shake",4.1, 1, 0, 0, 0, 0, 1);
    }
    else if(nr == 2)
    {
        LoopingAnim(playerid, "COP_AMBIENT", "Coplook_think", 4.1, 1, 0, 0, 0, 0, 1);
    }
    return 1;
}

CMD:celebrate(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"benchpress","gym_bp_celebrate", 4.0, 1, 0, 0, 0, 0);
    return 1;
}
CMD:dance(playerid, params[])
{
    new nr;
    if(sscanf(params, "i", nr))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Dance [1-4]");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    if(nr > 4 || nr < 1)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Dance [1-4]");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    if(nr == 1)
    {
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE1);
    }
    else if(nr == 2)
    {
        SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
    }
    else if(nr == 3)
    {
        SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
    }
    else if(nr == 4)
    {
        SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE4);
    }
    return 1;
}
CMD:copanim(playerid, params[])
{
    new nr;
    if(sscanf(params, "i", nr))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Copanim [1-6]");
    if(!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 16 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))return SendClientMessage(playerid, COLOR_RED, "Du bist kein LSPD/FBI Mitglied.");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    if(nr > 6 || nr < 1)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Copanim [1-6]");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    if(nr == 1)
    {
        ApplyAnimation(playerid,"POLICE", "CopTraf_Away", 4.1, 0, 0, 0, 0, 0, 1);
    }
    else if(nr == 2)
    {
        ApplyAnimation(playerid,"POLICE", "Cop_move_FWD", 4.1, 1, 1, 1, 1, 1, 1);
    }
    else if(nr == 3)
    {
        ApplyAnimation(playerid,"POLICE", "CopTraf_Come", 4.1, 0, 0, 0, 0, 0, 1);
    }
    else if(nr == 4)
    {
        ApplyAnimation(playerid,"POLICE", "CopTraf_Stop", 4.0, 1, 0, 0, 0, 0, 1);
    }
    else if(nr == 5)
    {
        ApplyAnimation(playerid,"SWORD","sword_block",50.0,0,1,1,1,1);
    }
    else if(nr == 6)
    {
        ApplyAnimation(playerid,"GANGS","leanIN",50.0,0,1,1,1,1);
    }
    return 1;
}
CMD:deal(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    OnePlayAnim(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0); // Deal Drugs
    return 1;
}
CMD:smokem(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    LoopingAnim(playerid,"SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0); // Smoke
    return 1;
}
CMD:smokef(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    LoopingAnim(playerid, "SMOKING", "F_smklean_loop", 4.0, 1, 0, 0, 0, 0); // Female Smoking
    return 1;
}

CMD:groundsit(playerid, params[])
{
    new nr;
    if(sscanf(params, "i", nr))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Groundsit [1-3]");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    if(nr > 3 || nr < 1)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Groundsit [1-3]");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    if(nr == 1)
    {
        LoopingAnim(playerid, "BEACH", "ParkSit_W_loop", 4.0, 1, 0, 0, 0, 0, 1);
    }
    else if(nr == 2)
    {
        ApplyAnimation(playerid, "BEACH", "SitnWait_loop_W", 4.0, 1, 0, 0, 0, 0, 1);
    }
    else if(nr == 3)
    {
        ApplyAnimation(playerid, "BEACH", "SitnWait_loop_W", 4.0, 1, 0, 0, 0, 0, 1);
    }
    return 1;
}

CMD:chatanim(playerid)
{
    if (!gPlayerLogged[playerid]) return SendClientMessage(playerid, COLOR_RED, "Du bist noch nicht eingeloggt!");
    new bUseChatAnim = GetPVarInt(playerid, "USE_CHAT_ANIM");
    SetPVarInt(playerid, "USE_CHAT_ANIM", !bUseChatAnim);
    if (bUseChatAnim) return SendClientMessage(playerid, COLOR_PURPLE, "Du hast die Chat-Animation ausgeschaltet.");
    return SendClientMessage(playerid, COLOR_GREEN, "Du hast die Chat-Animation eingeschaltet.");
}

CMD:chat(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    OnePlayAnim(playerid,"PED","IDLE_CHAT",4.0,0,0,0,0,0);
    return 1;
}
CMD:fucku(playerid)
{
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    OnePlayAnim(playerid,"PED","fucku",4.0,0,0,0,0,0);
    return 1;
}
CMD:kiss(playerid, params[])
{
    new nr;
    if(sscanf(params, "i", nr))return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Kiss [1-6]");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    if(nr > 6 || nr < 1)return SendClientMessage(playerid, COLOR_BLUE, INFO_STRING"/Kiss [1-6]");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    if(nr == 1)
    {
        ApplyAnimation(playerid,"KISSING", "Grlfrd_Kiss_01", 1.800001, 1, 0, 0, 1, 600);
    }
    else if(nr == 2)
    {
        ApplyAnimation(playerid,"KISSING", "Grlfrd_Kiss_02", 1.800001, 1, 0, 0, 5300, 600);
    }
    else if(nr == 3)
    {
        ApplyAnimation(playerid,"KISSING", "Grlfrd_Kiss_03", 1.800001, 1, 0, 0, 1, 600);
    }
    else if(nr == 4)
    {
        ApplyAnimation(playerid,"KISSING", "Playa_Kiss_01", 1.800001, 1, 0, 0, 1, 600);
    }
    else if(nr == 5)
    {
        ApplyAnimation(playerid,"KISSING", "Playa_Kiss_02", 1.800001, 1, 0, 0, 1, 600);
    }
    else if(nr == 6)
    {
        ApplyAnimation(playerid,"KISSING", "Playa_Kiss_03", 1.800001, 1, 0, 0, 1, 600);
    }
    return 1;
}
//Clubmitglied Animationen
CMD:clubdance1(playerid)
{
    if(!(Spieler[playerid][pDonateRank] == 1))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Clubmitglied!");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"DANCING", "DAN_Down_A", 4.0, 1, 0, 0, 0, 0);
    return 1;
}
CMD:clubdance2(playerid)
{
    if(!(Spieler[playerid][pDonateRank] == 1))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Clubmitglied!");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"DANCING", "DAN_Loop_A", 4.0, 1, 0, 0, 0, 0);
    return 1;
}
CMD:clubdance3(playerid)
{
    if(!(Spieler[playerid][pDonateRank] == 1))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Clubmitglied!");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"DANCING", "DAN_Up_A", 4.0, 1, 0, 0, 0, 0);
    return 1;
}
CMD:clubdance4(playerid)
{
    if(!(Spieler[playerid][pDonateRank] == 1))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Clubmitglied!");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"DANCING", "dnce_M_a", 4.0, 1, 0, 0, 0, 0);
    return 1;
}
CMD:clubdance5(playerid)
{
    if(!(Spieler[playerid][pDonateRank] == 1))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Clubmitglied!");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"DANCING", "dnce_M_b", 4.0, 1, 0, 0, 0, 0);
    return 1;
}
CMD:clubdance6(playerid)
{
    if(!(Spieler[playerid][pDonateRank] == 1))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Clubmitglied!");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"DANCING", "dnce_M_d", 4.0, 1, 0, 0, 0, 0);
    return 1;
}
CMD:clubdance7(playerid)
{
    if(!(Spieler[playerid][pDonateRank] == 1))return SendClientMessage(playerid, COLOR_RED, "Du bist kein Clubmitglied!");
    if(Spieler[playerid][pTot] == 1)return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animationen ausühren während du verletzt bist.");
    if(Cuffed[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du gefesselt bist kannst du keine Animationen ausühren.");
    if(Tazered[playerid] == 1)return SendClientMessage(playerid, COLOR_RED, "Während du getazert bist kannst du keine Animationen ausführen.");
    if(IsAFK[playerid] == 1)return SendClientMessage(playerid,COLOR_RED,"Im AFK-Modus kannst du keine Animationen ausühren.");
    if(damagesperre[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Du kannst gerade keine Animationen ausühren.");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)return 1;
    if (gettime() < Spieler[playerid][unixSpiceCooldown]) return SendClientMessage(playerid, COLOR_RED, "Du kannst die Animation im Moment nicht ausühren.");
    if (IsPlayerFalling(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst nur eine Animation ausühren, wenn du auf dem Boden bist.");
    if(GetPVarInt(playerid, "OPEN.AIRDROP"))return SendClientMessage(playerid, COLOR_RED, "Du kannst keine Animation im Moment ausühren.");
    if(wertpaptimer[playerid]) return SendClientMessage(playerid,COLOR_RED,"Du kannst keine Animation im Moment ausühren.");
    MakeAnimation[playerid] = 1;
    TextDrawShowForPlayer(playerid, Leer);
    ApplyAnimation(playerid,"DANCING", "dnce_M_e", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

//Animationen Ende
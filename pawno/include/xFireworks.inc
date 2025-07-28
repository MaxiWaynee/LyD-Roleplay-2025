#include <a_samp>

//------------------------------------------------------------------------------

#if defined _xfireworks_included
	#endinput
#endif
#define _xfireworks_included
#pragma library xfireworks

/*
native xFireworks_OnObjectMoved();
native CreateFirework(Float:x,Float:y,Float:z,Float:height,Float:leandir,Float:windoffset,Float:climespeed,expltype,Float:explsize);
*/

//------------------------------------------------------------------------------

enum fireworks
{
	Float:f_height,
	Float:f_leandir,
	f_status,
	f_expltype,
	f_objectid,
	Float:f_explsize,
	Float:f_climespeed,
	Float:f_windoffset,
	bool:f_inuse
}

new Fireworks[MAX_OBJECTS][fireworks];

new colortypes[] = {354, 3666};
new lighteffects[] = { /* 19281,19282,19283,19284,19285,19286,19287,19288,19289,19290,19291,19292,19293,19294,*/ 19295,19296,19297,19298};

xFireworks_OnObjectMoved(objectid)
{
	new id = GetFireworkID(objectid);
	//printf("xFireworks_OnObjectMoved(%d) id %d",objectid,id);
	if(id == -1) return 0;
	//printf("xFireworks_OnObjectMoved(%d) f_status %d",objectid,Fireworks[id][f_status]);
	switch(Fireworks[id][f_status])
	{
	    case 1..4:
	    {
	        new Float:x, Float:y, Float:z;
	        GetObjectPos(objectid,x,y,z);
    		GetXYInFrontOfPosition(x,y,Fireworks[id][f_leandir],Fireworks[id][f_windoffset] / 5);
			z += Fireworks[id][f_height] / 5;
    		Fireworks[id][f_status]++;
    		MoveObject(Fireworks[id][f_objectid],x,y,z,Fireworks[id][f_climespeed]);
	    }
	    default:
	    {
	        new Float:x, Float:y, Float:z;
	        GetObjectPos(objectid,x,y,z);
	        CreateExplosion(x,y,z,Fireworks[id][f_expltype],Fireworks[id][f_explsize]);
	        DestroyFirework(id);

	        {
	            new
	                obj,
	                time,
	                r;
				r = 10 + random(15);
				for(new i ; i < r ; i++) {
				    random(10000);
		            obj = CreateObject( lighteffects[random(sizeof(lighteffects))] , x + frandom(5.0,-5.0), y + frandom(5.0,-5.0), z + frandom(3.0,-3.0),0.0,0.0,0.0);
					MoveObject( obj , x + frandom(9.0,-9.0), y + frandom(9.0,-9.0), z + frandom(5.0,-5.0) , frandom(6.0,2.5,2) );
                    time = 350 + random(700);
					SetTimerEx("DestroyLightEffectEx", time ,false,"d",obj);
				}
	        }

	    }
	}
	return 1;
}

forward DestroyLightEffectEx(objectid);
public DestroyLightEffectEx(objectid) {
	/*
	if(random(4) == 0 ) {
	
	}
	*/
	return DestroyObject(objectid);
}
stock CreateFirework(Float:x,Float:y,Float:z,Float:height,Float:leandir,Float:windoffset,Float:climespeed,expltype,Float:explsize)
{
	new id = GetFreeID();
	printf("CreateFirework() id = %d",id);
	if(id == -1) return 0;
	Fireworks[id][f_objectid] = CreateObject(colortypes[random(sizeof(colortypes))],x,y,z,0.0,0.0,0.0);
	printf("CreateFirework() f_objectid = %d", Fireworks[id][f_objectid]);
	Fireworks[id][f_height] = height;
	Fireworks[id][f_leandir] = leandir;
	Fireworks[id][f_expltype] = expltype;
	Fireworks[id][f_climespeed] = climespeed;
	Fireworks[id][f_windoffset] = windoffset;
	Fireworks[id][f_explsize] = explsize;
	Fireworks[id][f_inuse] = true;
    Fireworks[id][f_status] = 1;
    z += height / 5;
    GetXYInFrontOfPosition(x,y,leandir,windoffset / 5);
    printf("CreateFirework() MoveObject ms %d", MoveObject(Fireworks[id][f_objectid],x,y,z,climespeed) );
    return 1;
}

stock GetFreeID()
{
	for(new i = 0; i < sizeof(Fireworks); i++)
	{
	    if(!Fireworks[i][f_inuse])
	    {
	        return i;
		}
	}
	return -1;
}

stock GetFireworkID(objectid)
{
	for(new i = 0; i < sizeof(Fireworks); i++)
	{
	    if(Fireworks[i][f_objectid] == objectid)
	    {
	        return i;
		}
	}
	return -1;
}

stock DestroyFirework(id)
{
	DestroyObject(Fireworks[id][f_objectid]);
	Fireworks[id][f_inuse] = false;
}

stock GetXYInFrontOfPosition(&Float:x, &Float:y, Float:a, Float:distance)
{
	x += (distance * floatsin(-a, degrees));
	y += (distance * floatcos(-a, degrees));
}

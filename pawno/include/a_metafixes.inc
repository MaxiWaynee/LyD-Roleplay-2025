#if defined _meta_fixes_included
	#endinput
#endif
#define _meta_fixes_included



main() { CallLocalFunction("fix_main", ""); }

#if defined _ALS_main
	#undef main
#else
	#define _ALS_main
#endif
#define main forward fix_main(); public fix_main



stock bool:fix_fclose(File:handle)
{
	if(handle) return fclose(handle);
	return false;
}
#if defined _ALS_fclose
	#undef fclose
#else
	#define _ALS_fclose
#endif
#define fclose fix_fclose


stock fix_fwrite(File:handle, const string[])
{
	if(handle) return fwrite(handle, string);
	return 0;
}
#if defined _ALS_fwrite
	#undef fwrite
#else
	#define _ALS_fwrite
#endif
#define fwrite fix_fwrite


stock fix_fread(File:handle, string[], size = sizeof string, bool: pack = false)
{
	if(handle) return fread(handle, string, size, pack);
	return 0;
}
#if defined _ALS_fread
	#undef fread
#else
	#define _ALS_fread
#endif
#define fread fix_fread


stock bool:fix_fputchar(File:handle, value, bool: utf8 = true)
{
	if(handle) return fputchar(handle, value, utf8);
	return false;
}
#if defined _ALS_fputchar
	#undef fputchar
#else
	#define _ALS_fputchar
#endif
#define fputchar fix_fputchar


stock fix_fgetchar(File:handle, value, bool: utf8 = true)
{
	if(handle) return fgetchar(handle, value, utf8);
	return 0;
}
#if defined _ALS_fgetchar
	#undef fgetchar
#else
	#define _ALS_fgetchar
#endif
#define fgetchar fix_fgetchar


stock fix_fblockwrite(File:handle, const buffer[], size = sizeof buffer)
{
	if(handle) return fblockwrite(handle, buffer, size);
	return 0;
}
#if defined _ALS_fblockwrite
	#undef fblockwrite
#else
	#define _ALS_fblockwrite
#endif
#define fblockwrite fix_fblockwrite


stock fix_fblockread(File:handle, buffer[], size = sizeof buffer)
{
	if(handle) return fblockread(handle, buffer, size);
	return 0;
}
#if defined _ALS_fblockread
	#undef fblockread
#else
	#define _ALS_fblockread
#endif
#define fblockread fix_fblockread


stock fix_fseek(File:handle, position = 0, seek_whence: whence = seek_start)
{
	if(handle) return fseek(handle, position, whence);
	return 0;
}
#if defined _ALS_fseek
	#undef fseek
#else
	#define _ALS_fseek
#endif
#define fseek fix_fseek


stock fix_flength(File:handle)
{
	if(handle) return flength(handle);
	return 0;
}
#if defined _ALS_flength
	#undef flength
#else
	#define _ALS_flength
#endif
#define flength fix_flength

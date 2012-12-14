/*********************************************************************
For Further Information on KDIS:
http://p.sf.net/kdis/UserGuide
*********************************************************************/

#if defined( WIN32 ) | defined( WIN64 )

// Building a DLL for windows example, you will may need to make changes for other OS.
#include <Windows.h>

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved )
{
    return TRUE;
}

#else

void __attribute__ ( ( constructor ) ) my_load( void );
void __attribute__ ( ( destructor ) ) my_unload( void );

void my_load( void )
{
}

void my_unload( void )
{
}

#endif

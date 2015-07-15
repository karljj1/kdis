/*********************************************************************
Copyright 2013 Karl Jones
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

/********************************************************************
    KDefines
    created:    14/07/2015
    author:     Karl Jones

    purpose:    Defines some of the core data types that KDIS Link16 uses.                
*********************************************************************/

#pragma once

/************************************************************************/
/*  Export Options                                                      */
/************************************************************************/

#ifdef EXPORT_KDIS_LINK16
	#ifdef IMPORT_KDIS_LINK16
		#pragma error( "IMPORT_KDIS_LINK16 & EXPORT_KDIS_LINK16 Can Not Be Both Defined" )
	#endif
#endif

#if defined( WIN32 ) | defined( WIN64 )
	#if defined EXPORT_KDIS_LINK16
		#define KDIS_EXPORT_LINK16 __declspec( dllexport )
	#elif defined IMPORT_KDIS_LINK16
		#define KDIS_EXPORT_LINK16 __declspec( dllimport  )
	#else
		#define KDIS_EXPORT_LINK16
	#endif
#else
	#define KDIS_EXPORT_LINK16
#endif
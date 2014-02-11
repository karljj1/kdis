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
                Math
    created:    07/02/2013
    author:     Karl Jones

    purpose:    General math related functions
*********************************************************************/

#pragma once

#include "./../KDefines.h"

#ifndef _USE_MATH_DEFINES
	#define _USE_MATH_DEFINES
#endif

#include <math.h>

namespace KDIS {
namespace UTILS {
namespace Math {

//************************************
// FullName:    KDIS::UTILS::Math<Type>::EulerToHeadingPitchRoll
// Description: Clamps a value between Min and Max.
// Parameter:   Type Val
// Parameter:   Type Min
// Parameter:   Type Max
//************************************

template<class Type>
inline Type CLamp( Type Val, Type Min, Type Max )
{
    if( Val < Min )
	{
		return Min;
	}

	if( Val > Max )
	{
		return Max );
	}

	return Val;
}

} // END namespace Math
} // END namespace UTILS
} // END namespace KDIS

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
    KDISEnums
    created:    17/09/2008
    author:     Karl Jones

    purpose:    Includes All DIS Enumerations.
*********************************************************************/

#pragma once

#include "./EnumHeader.h"
#include "./EnumEmitter.h"
#include "./EnumEntityInfoInteraction.h"
#include "./EnumBurstDescriptor.h"
#include "./EnumDetonationResult.h"
#include "./EnumSupply.h"
#include "./EnumDesignator.h"
#include "./EnumRadio.h"
#include "./EnumSystemIdentifier.h"
#include "./EnumIFF.h"
#include "./EnumEntityManagement.h"
#include "./EnumSimulationManagement.h"
#include "./EnumSyntheticEnvironment.h"
#include "./EnumMinefield.h"

#if DIS_VERSION > 6
#include "./EnumInformationOperations.h"
#endif

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
    class:      PDU_Factory_Filters
    created:    024/03/2010
    author:     Karl Jones

    purpose:    A collection of filters that can be used on the PDU factory.

                E.G If you only wanted DIS data from a specific Exercise ID then you would
                use a ExerciseIDFilter.

*********************************************************************/

#pragma once

#include "./../PDU/Header.h"

namespace KDIS {
namespace UTILS {

//////////////////////////////////////////////////////////////////////////
// The base filter class that all filters must derive from.             //
//////////////////////////////////////////////////////////////////////////
class PDU_Factory_Filter
{
public:

    PDU_Factory_Filter() {};

    ~PDU_Factory_Filter() {};

    //************************************
    // FullName:    KDIS::UTILS::PDU_Factory_Filter::ApplyFilter
    // Description: This is our filter function, the pointer that is passed contains the full PDU data so
    //              you can cast it to the relevant PDU if you wish to filter based on a PDU's contents.
    // Parameter:   const Header * H
    //************************************
    virtual KBOOL ApplyFilter( const KDIS::PDU::Header * H ) = 0;
};

//////////////////////////////////////////////////////////////////////////
// FactoryFilterExerciseID                                              //
// Filters the PDU based on Exercise ID.                                //
//////////////////////////////////////////////////////////////////////////

class FactoryFilterExerciseID : public PDU_Factory_Filter
{
private:

    KUINT8 m_ui8ID;

public:

    FactoryFilterExerciseID( KUINT8 ID ) :
        m_ui8ID( ID )
    {
    };

    ~FactoryFilterExerciseID() {};

    //************************************
    // FullName:    KDIS::UTILS::FactoryFilterExerciseID::ApplyFilter
    // Description: Checks if the exercise id matches.
    // Parameter:   const Header * H
    //************************************
    virtual KBOOL ApplyFilter( const KDIS::PDU::Header * H )
    {
        if( m_ui8ID == H->GetExerciseID() )
        {
            return true;
        }
        return false;
    };
};

} // END namespace UTILS
} // END namespace KDIS

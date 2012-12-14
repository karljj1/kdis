/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

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

using KDIS::PDU::Header;

//////////////////////////////////////////////////////////////////////////
// The base filter class that all filters must derive from.             //
//////////////////////////////////////////////////////////////////////////
class PDU_Factory_Filter
{
public:

    PDU_Factory_Filter( void ) {};

    ~PDU_Factory_Filter( void ) {};

    //************************************
    // FullName:    KDIS::UTILS::PDU_Factory_Filter::ApplyFilter
    // Description: This is our filter function, the pointer that is passed contains the full PDU data so
    //              you can cast it to the relevant PDU if you wish to filter based on a PDU's contents.
    // Parameter:   const Header * H
    //************************************
    virtual KBOOL ApplyFilter( const Header * H ) = 0;
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

    ~FactoryFilterExerciseID( void ) {};

    //************************************
    // FullName:    KDIS::UTILS::FactoryFilterExerciseID::ApplyFilter
    // Description: Checks if the exercise id matches.
    // Parameter:   const Header * H
    //************************************
    virtual KBOOL ApplyFilter( const Header * H )
    {
        if( m_ui8ID == H->GetExerciseID() )
        {
            return true;
        }
        return false;
    };
};

}; // End namespace UTILS
}; // End namespace KDIS

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
    class:      DIS_Logger_Playback
    created:    2008/12/06
    author:     Karl Jones

    purpose:    This class will allow you to play back data recorded using
                DIS_Logger_Record.
*********************************************************************/

#pragma once

#include <fstream>
#include <time.h>
#include "./../PDU/Header.h"
#include <queue>

namespace KDIS {
namespace UTILS {

using std::queue;
using std::fstream;

class KDIS_EXPORT DIS_Logger_Playback
{
protected:

    struct Log
    {
        KString sStamp;

        KString sData;
    };

    fstream m_File;

    KUINT16 m_ui16PreLoadLines;

    queue<Log> m_qLog;

    //************************************
    // FullName:    KDIS::UTILS::DIS_Logger_Playback::loadFromFile
    // Description: Load data from file
    //************************************
    void loadFromFile() throw( KException );

public:

    // BufferSz - how many lines of the log to load into memory at a time,
    // set to 0 to load all data.
    DIS_Logger_Playback( const KString & FileName, KUINT16 BufferSz );

    ~DIS_Logger_Playback( void );

    //************************************
    // FullName:    KDIS::UTILS::DIS_Logger_Playback::Record
    // Description: Returns the next item in the log.
    //              If the end of the log has been reached returns false.
    // Parameter:   Type & Stamp
    // Parameter:   KDataStream & Stream
    //************************************
    template<class Type>
    KBOOL GetNext( Type & Stamp, KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::UTILS::DIS_Logger_Playback::EndOfLogReached
    // Description: Returns true if the end of the logged data has
    //              reached.
    //************************************
    KBOOL EndOfLogReached() const;
};

//////////////////////////////////////////////////////////////////////////
// Template Operators
//////////////////////////////////////////////////////////////////////////

template<class Type>
KBOOL DIS_Logger_Playback::GetNext( Type & Stamp, KDataStream & Stream ) throw( KException )
{
    if( EndOfLogReached() )return false;

    if( m_qLog.size() == 0 )loadFromFile();

    KStringStream ssStamp( m_qLog.front().sStamp );
    ssStamp >> Stamp;

    Stream.ReadFromString( m_qLog.front().sData );

    m_qLog.pop();

    return true;
}

//////////////////////////////////////////////////////////////////////////

}; // End namespace UTILS
}; // End namespace KDIS


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

class KDIS_EXPORT DIS_Logger_Playback
{
protected:

    struct Log
    {
        KString sStamp;

        KString sData;
    };

    std::fstream m_File;

    KUINT16 m_ui16PreLoadLines;

    std::queue<Log> m_qLog;

    //************************************
    // FullName:    KDIS::UTILS::DIS_Logger_Playback::loadFromFile
    // Description: Load data from file
    //************************************
    void loadFromFile() throw( KException );

public:

    // BufferSz - how many lines of the log to load into memory at a time,
    // set to 0 to load all data.
    DIS_Logger_Playback( const KString & FileName, KUINT16 BufferSz );

    ~DIS_Logger_Playback();

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

} // END namespace UTILS
} // END namespace KDIS


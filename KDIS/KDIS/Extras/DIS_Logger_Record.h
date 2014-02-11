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
    class:      DIS_Logger_Record
    created:    06:12:2008
    author:     Karl Jones

    purpose:    This class will record DIS data to a file.
                Each PDU can have additional data attached such as
                a timestamp which can be used for playing the data
                back using DIS_Logger_Playback.
                The files are saved as simple ASCII text files with each
                PDUs octets written in hex for easy debugging(well easy if you read binary!).

                Note: You could actually use this class to record any
                      type of network data.
*********************************************************************/

#pragma once

#include <memory>
#include <fstream>
#include <time.h>
#include "./../PDU/Header.h"
#include <vector>

namespace KDIS {
namespace UTILS {

class KDIS_EXPORT DIS_Logger_Record
{
protected:

    std::fstream m_File;

    KBOOL m_bWriteToFile;

    std::vector<KString> m_vsLog;

    //************************************
    // FullName:    KDIS::UTILS::DIS_Logger_Record::writeToFile
    // Description: Saves to the file as text.
    // Parameter:   const KString & S
    //************************************
    void writeToFile( const KString & S ) throw( KException );

    //************************************
    // FullName:    KDIS::UTILS::DIS_Logger_Record::writeToBuffer
    // Description: Saves to the buffer.
    // Parameter:   const KString & S
    //************************************
    void writeToBuffer( const KString & S );

public:

    // WriteToFile - if true each logged PDU will be written straight
    // to the file, if false the recorded data is stored untill Save() is
    // called.
    DIS_Logger_Record( const KString & FileName, KBOOL WriteToFile );

    ~DIS_Logger_Record();

    //************************************
    // FullName:    KDIS::UTILS::DIS_Logger_Record::Record
    // Description: Record a PDU to the log, Stamp
    //              can be used for playback (timestamp)
    //              or simply to add comments to each PDU etc,
    //              Stamp will be written above each PDU in the file.
    // Parameter:   Type Stamp
    // Parameter:   const KDataStream & Stream
    //************************************
    template<class Type>
    void Record( Type Stamp, const KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::UTILS::DIS_Logger_Record::Save
    // Description: If we are not writing each logged
    //              PDU straight to file this will write
    //              the buffered data to the file and clear
    //              the buffer.
    //************************************
    void Save() throw( KException );

    //************************************
    // FullName:    KDIS::UTILS::DIS_Logger_Record::Save
    // Description: If we are not writing each logged
    //              PDU straight to file this will clear
    //              the buffered data.
    //************************************
    void Clear();

    //************************************
    // FullName:    KDIS::UTILS::DIS_Logger_Record::GetBufferSize
    // Description: Returns number of entries in the buffer if we are
    //              buffering data instead of writing straight
    //              to the file.
    //************************************
    KUINT16 GetBufferSize() const;
};

//////////////////////////////////////////////////////////////////////////
// Template Operators
//////////////////////////////////////////////////////////////////////////

template<class Type>
void DIS_Logger_Record::Record( Type Stamp, const KDataStream & Stream ) throw( KException )
{
    KStringStream ss;
    ss << Stamp << "\n" << Stream.GetAsString();
    m_bWriteToFile ? writeToFile( ss.str() ) : writeToBuffer( ss.str() );
}

//////////////////////////////////////////////////////////////////////////

} // END namespace UTILS
} // END namespace KDIS


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

using std::fstream;
using std::vector;

class KDIS_EXPORT DIS_Logger_Record
{
protected:

    fstream m_File;

    KBOOL m_bWriteToFile;

    vector<KString> m_vsLog;

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

    ~DIS_Logger_Record( void );

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

}; // End namespace UTILS
}; // End namespace KDIS


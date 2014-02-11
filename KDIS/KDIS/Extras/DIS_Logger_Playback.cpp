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

#include "./DIS_Logger_Playback.h"

using namespace std;
using namespace KDIS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

void DIS_Logger_Playback::loadFromFile() throw( KException )
{
    if( m_File.is_open() == false )throw KException( __FUNCTION__, FILE_NOT_OPEN );

    Log l;

    while( m_File.eof() == false )
    {
        getline( m_File, l.sStamp );
        getline( m_File, l.sData );

        m_qLog.push( l );

        if( m_ui16PreLoadLines != 0 )
        {
            if( m_ui16PreLoadLines >= m_qLog.size() )break;
        }
    }
}

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

DIS_Logger_Playback::DIS_Logger_Playback(  const KString & FileName, KUINT16 BufferSz  ) :
    m_ui16PreLoadLines( BufferSz )
{
    m_File.open( FileName.c_str(), ios::in );
}

//////////////////////////////////////////////////////////////////////////

DIS_Logger_Playback::~DIS_Logger_Playback()
{
    m_qLog.empty();
    m_File.close();
}

//////////////////////////////////////////////////////////////////////////

KBOOL DIS_Logger_Playback::EndOfLogReached() const
{
    if( m_File.eof() && m_qLog.size() == 0 )return true;
    return false;
}

//////////////////////////////////////////////////////////////////////////

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

#include "./DIS_Logger_Record.h"

using namespace std;
using namespace KDIS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

void DIS_Logger_Record::writeToFile( const KString & S ) throw( KException )
{
    if( m_File.is_open() == false )throw KException( __FUNCTION__, FILE_NOT_OPEN );

    m_File << S << endl;
}

//////////////////////////////////////////////////////////////////////////

void DIS_Logger_Record::writeToBuffer( const KString & S )
{
    m_vsLog.push_back( S );
}

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

DIS_Logger_Record::DIS_Logger_Record( const KString & FileName, KBOOL WriteToFile ) :
    m_bWriteToFile( WriteToFile )
{
    m_File.open( FileName.c_str(), ios::out );
}

//////////////////////////////////////////////////////////////////////////

DIS_Logger_Record::~DIS_Logger_Record()
{
    m_vsLog.clear();
}

//////////////////////////////////////////////////////////////////////////

void DIS_Logger_Record::Save() throw( KException )
{
    vector<KString>::const_iterator citr = m_vsLog.begin();
    vector<KString>::const_iterator citrEnd = m_vsLog.end();

    for( ; citr != citrEnd; ++citr )
    {
        writeToFile( *citr );
    }

    Clear();
}

//////////////////////////////////////////////////////////////////////////

void DIS_Logger_Record::Clear()
{
    m_vsLog.clear();
}

//////////////////////////////////////////////////////////////////////////

KUINT16 DIS_Logger_Record::GetBufferSize() const
{
    return m_vsLog.size();
}

//////////////////////////////////////////////////////////////////////////

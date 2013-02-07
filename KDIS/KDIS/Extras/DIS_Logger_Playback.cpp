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

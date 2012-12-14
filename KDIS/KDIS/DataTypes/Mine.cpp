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

#include "./Mine.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace std;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

map< KUINT16, vector<Vector> >::iterator Mine::getWire( KUINT16 Index ) throw( KException )
{
    map< KUINT16, vector<Vector> >::iterator itr = m_mvVertices.find( Index );
    if( itr == m_mvVertices.end() )throw KException( __FUNCTION__, OUT_OF_BOUNDS, "Invalid Wire Index." );
    return itr;
}

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Mine::Mine( void ) :
    m_ui16ID( 0 ),
    m_f32GrndOffset( 0 ),
    m_f32WtrOffset( 0 ),
    m_f32SnwOffset( 0 ),
    m_f32ThrmCont( 0 ),
    m_f32Rflt( 0 ),
    m_ui8NumTrpDetWrs( 0 ),
    m_ui16NextIndex( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Mine::Mine( const Vector & Location, KUINT16 ID ) :
    m_Loc( Location ),
    m_ui16ID( ID ),
    m_f32GrndOffset( 0 ),
    m_f32WtrOffset( 0 ),
    m_f32SnwOffset( 0 ),
    m_f32ThrmCont( 0 ),
    m_f32Rflt( 0 ),
    m_ui8NumTrpDetWrs( 0 ),
    m_ui16NextIndex( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Mine::~Mine( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Mine::SetLocation( const Vector & L )
{
    m_Loc = L;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Mine::GetLocation() const
{
    return m_Loc;
}

//////////////////////////////////////////////////////////////////////////

void Mine::SetID( KUINT16 ID )
{
    m_ui16ID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Mine::GetID() const
{
    return m_ui16ID;
}

//////////////////////////////////////////////////////////////////////////

void Mine::SetGroundBurialDepthOffsetValue( KFLOAT32 GBO )
{
    m_f32GrndOffset = GBO;
    SetGroundBurialDepthOffset( true );
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Mine::GetGroundBurialDepthOffsetValue() const
{
    return m_f32GrndOffset;
}

//////////////////////////////////////////////////////////////////////////

void Mine::SetWaterBurialDepthOffsetValue( KFLOAT32 WBO )
{
    m_f32WtrOffset = WBO;
    SetWaterBurialDepthOffset( true );
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Mine::GetWaterBurialDepthOffsetValue() const
{
    return m_f32WtrOffset;
}

//////////////////////////////////////////////////////////////////////////

void Mine::SetSnowBurialDepthOffsetValue( KFLOAT32 SBO )
{
    m_f32SnwOffset = SBO;
    SetSnowBurialDepthOffset( true );
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Mine::GetSnowBurialDepthOffsetValue() const
{
    return m_f32SnwOffset;
}

//////////////////////////////////////////////////////////////////////////

void Mine::SetMineOrientationValue( const EulerAngles & O )
{
    SetMineOrientation( true );
    m_Ori = O;
}

//////////////////////////////////////////////////////////////////////////

const EulerAngles & Mine::GetMineOrientationValue() const
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & Mine::GetMineOrientationValue()
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

void Mine::SetThermalContrastValue( KFLOAT32 TC )
{
    SetThermalContrast( true );
    m_f32ThrmCont = TC;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Mine::GetThermalContrastValue() const
{
    return m_f32ThrmCont;
}

//////////////////////////////////////////////////////////////////////////

void Mine::SetReflectanceValue( KFLOAT32 R )
{
    SetReflectance( true );
    m_f32Rflt = R;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Mine::GetReflectanceValue() const
{
    return m_f32Rflt;
}

//////////////////////////////////////////////////////////////////////////

void Mine::SetMineEmplacementAgeValue( const ClockTime & MET )
{
    SetMineEmplacementAge( true );
    m_MET = MET;
}

//////////////////////////////////////////////////////////////////////////

const ClockTime & Mine::GetMineEmplacementAgeValue() const
{
    return m_MET;
}

//////////////////////////////////////////////////////////////////////////

ClockTime & Mine::GetMineEmplacementAgeValue()
{
    return m_MET;
}

//////////////////////////////////////////////////////////////////////////

void Mine::AddScalarDetectionCoefficientValue( KUINT8 SDC )
{
    SetScalarDetectionCoefficient( true );
    m_vui8SDC.push_back( SDC );
}

//////////////////////////////////////////////////////////////////////////

void Mine::SetScalarDetectionCoefficientValues( const vector<KUINT8> & SDC )
{
    SetScalarDetectionCoefficient( true );
    m_vui8SDC = SDC;
}

//////////////////////////////////////////////////////////////////////////

const vector<KUINT8> & Mine::GetScalarDetectionCoefficientValues() const
{
    return m_vui8SDC;
}

//////////////////////////////////////////////////////////////////////////

vector<KUINT8> & Mine::GetScalarDetectionCoefficientValues()
{
    return m_vui8SDC;
}

//////////////////////////////////////////////////////////////////////////

void Mine::ClearScalarDetectionCoefficientValues()
{
    m_vui8SDC.clear();
}

//////////////////////////////////////////////////////////////////////////

void Mine::SetFusingValue( const MineFusing & MF )
{
    SetFusing( true );
    m_MF = MF;
}

//////////////////////////////////////////////////////////////////////////

const MineFusing & Mine::GetFusingValue() const
{
    return m_MF;
}

//////////////////////////////////////////////////////////////////////////

MineFusing & Mine::GetFusingValue()
{
    return m_MF;
}

//////////////////////////////////////////////////////////////////////////

void Mine::SetPaintSchemeValue( const MinePaintScheme & MPS )
{
    SetPaintScheme( true );
    m_MPS = MPS;
}

//////////////////////////////////////////////////////////////////////////

const MinePaintScheme & Mine::GetPaintSchemeValue() const
{
    return m_MPS;
}

//////////////////////////////////////////////////////////////////////////

MinePaintScheme & Mine::GetPaintSchemeValue()
{
    return m_MPS;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Mine::GetNumberTripDetonationWires() const
{
    return m_ui8NumTrpDetWrs;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Mine::AddTripDetonationWire( const std::vector<Vector> & Vertices )
{
    SetTripDetonationWire( true );
    m_mvVertices[m_ui16ID] = Vertices;
    m_ui8NumTrpDetWrs++;
    return m_ui16ID++;
}

//////////////////////////////////////////////////////////////////////////

const map< KUINT16, vector<Vector> > & Mine::GetTripDetonationWire() const
{
    return m_mvVertices;
}

//////////////////////////////////////////////////////////////////////////

void Mine::ClearWires()
{
    m_mvVertices.clear();
    m_ui8NumTrpDetWrs = 0;
    SetTripDetonationWire( false );
}

//////////////////////////////////////////////////////////////////////////

void Mine::AddVertexToTripDetonationWire( KUINT16 Index, const Vector & Vertex ) throw( KException )
{
    map< KUINT16, vector<Vector> >::iterator itr = getWire( Index );
    itr->second.push_back( Vertex );
}

//////////////////////////////////////////////////////////////////////////

void Mine::SetTripDetonationWireVertices( KUINT16 Index, const std::vector<Vector> & Vertices ) throw( KException )
{
    map< KUINT16, vector<Vector> >::iterator itr = getWire( Index );
    itr->second = Vertices;
}

//////////////////////////////////////////////////////////////////////////

void Mine::RemoveTripDetonationWire( KUINT16 Index ) throw( KException )
{
    map< KUINT16, vector<Vector> >::iterator itr = getWire( Index );
    m_mvVertices.erase( itr );
    m_ui8NumTrpDetWrs--;
}

//////////////////////////////////////////////////////////////////////////

const vector<Vector> & Mine::GetWireVertices( KUINT16 Index ) throw( KException )
{
    map< KUINT16, vector<Vector> >::iterator itr = getWire( Index );
    return itr->second;
}

//////////////////////////////////////////////////////////////////////////

void Mine::ClearWireVertices( KUINT16 Index ) throw( KException )
{
    map< KUINT16, vector<Vector> >::iterator itr = getWire( Index );
    itr->second.clear();
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Mine::GetLength() const
{
    KUINT16 ui16Len = 14; // Min Size

    if( IsGroundBurialDepthOffset() )       ui16Len += 4;
    if( IsWaterBurialDepthOffset() )        ui16Len += 4;
    if( IsSnowBurialDepthOffset() )         ui16Len += 4;
    if( IsMineOrientation() )               ui16Len += m_Ori.EULER_ANGLES_SIZE;
    if( IsThermalContrast() )               ui16Len += 4;
    if( IsReflectance() )                   ui16Len += 4;
    if( IsMineEmplacementAge() )            ui16Len += m_MET.CLOCK_TIME_SIZE;
    if( IsFusing() )                        ui16Len += m_MF.MINE_FUSING_SIZE;
    if( IsScalarDetectionCoefficient() )    ui16Len += 1 * m_vui8SDC.size();
    if( IsPaintScheme() )                   ui16Len += m_MPS.MINE_PAINT_SCHEME_SIZE;
    if( IsTripDetonationWire() )
    {
        ++ui16Len;
        map< KUINT16, vector<Vector> >::const_iterator citrM = m_mvVertices.begin();
        map< KUINT16, vector<Vector> >::const_iterator citrMEnd = m_mvVertices.end();
        for( ; citrM != citrMEnd; ++citrM )
        {
            ui16Len += citrM->second.size() * Vector::VECTOR_SIZE;
        }
    }

    return ui16Len;
}

//////////////////////////////////////////////////////////////////////////

KString Mine::GetAsString() const
{
    KStringStream ss;

    ss << "Mine:"
       << "\n\tLocation: " << m_Loc.GetAsString()
       << "\n\tID: "       << m_ui16ID
       << "\n";

    if( IsGroundBurialDepthOffset() )
    {
        ss << "\tGround Burial Offset: " << m_f32GrndOffset << "\n";
    }

    if( IsWaterBurialDepthOffset() )
    {
        ss << "\tWater Burial Offset: " << m_f32WtrOffset << "\n";
    }

    if( IsSnowBurialDepthOffset() )
    {
        ss << "\tSnow Burial Offset: " << m_f32SnwOffset << "\n";
    }

    if( IsMineOrientation() )
    {
        ss << "\tOrientation: " << m_Ori.GetAsString();
    }

    if( IsThermalContrast() )
    {
        ss << "\tThermal Contrast: " << m_f32ThrmCont << "\n";
    }

    if( IsReflectance() )
    {
        ss << "\tReflectance: " << m_f32Rflt << "\n";
    }

    if( IsMineEmplacementAge() )
    {
        ss << "\tMine Emplacement Age:\n" << IndentString( m_MET.GetAsString(), 2 );
    }

    if( IsFusing() )
    {
        ss << IndentString( m_MF.GetAsString(), 1 );
    }

    if( IsScalarDetectionCoefficient() )
    {
        ss << "\tScalar Detection Coefficients:\n";
        vector<KUINT8>::const_iterator citr = m_vui8SDC.begin();
        vector<KUINT8>::const_iterator citrEnd = m_vui8SDC.end();
        for( ; citr != citrEnd; ++citr )
        {
            ss << "\t\t" << ( KUINT16 )*citr << "\n";
        }
    }

    if( IsPaintScheme() )
    {
        ss << IndentString( m_MPS.GetAsString(), 1 );
    }

    if( IsTripDetonationWire() )
    {
        ss << "\tNumber Trip/Det Wires: " << ( KUINT16 )m_ui8NumTrpDetWrs << "\n";

        map< KUINT16, vector<Vector> >::const_iterator citrM = m_mvVertices.begin();
        map< KUINT16, vector<Vector> >::const_iterator citrMEnd = m_mvVertices.end();
        for( ; citrM != citrMEnd; ++citrM )
        {
            ss << "\tNumber Of Vertices: " << citrM->second.size() << "\n";

            vector<Vector>::const_iterator citrV = citrM->second.begin();
            vector<Vector>::const_iterator citrVEnd = citrM->second.end();
            for( ; citrV != citrVEnd; ++citrV )
            {
                ss << IndentString( citrV->GetAsString(), 2 );
            }
        }
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mine::operator == ( const Mine & Value ) const
{
    if( m_Loc               != Value.m_Loc )            return false;
    if( m_ui16ID            != Value.m_ui16ID )         return false;
    if( m_f32GrndOffset     != Value.m_f32GrndOffset )  return false;
    if( m_f32WtrOffset      != Value.m_f32WtrOffset )   return false;
    if( m_f32SnwOffset      != Value.m_f32SnwOffset )   return false;
    if( m_Ori               != Value.m_Ori )            return false;
    if( m_f32ThrmCont       != Value.m_f32ThrmCont )    return false;
    if( m_f32Rflt           != Value.m_f32Rflt )        return false;
    if( m_MET               != Value.m_MET )            return false;
    if( m_MF                != Value.m_MF )             return false;
    if( m_vui8SDC           != Value.m_vui8SDC )        return false;
    if( m_MPS               != Value.m_MPS )            return false;
    if( m_ui8NumTrpDetWrs   != Value.m_ui8NumTrpDetWrs )return false;
    if( m_mvVertices        != Value.m_mvVertices )     return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mine::operator != ( const Mine & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


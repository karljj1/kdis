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
    class:      Mine
    created:    11/06/2010
    author:     Karl Jones

    purpose:    Encapsulates the common attributes for a Mine.
                Note: These values are not encoded sequentially into the minefield data PDU,
                all encoding and decoding is done by the hosting PDU.
    size:       112 bits / 14 octets
*********************************************************************/

#pragma once

#include "./MinefieldDataFilter.h"
#include "./Vector.h"
#include "./EulerAngles.h"
#include "./ClockTime.h"
#include "./MineFusing.h"
#include "./MinePaintScheme.h"
#include <vector>
#include <map>

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT Mine : public MinefieldDataFilter // Data filter used to keep track of what fields are being used in this mine.
{
protected:

    Vector m_Loc;

    KUINT16 m_ui16ID;

    KFLOAT32 m_f32GrndOffset;

    KFLOAT32 m_f32WtrOffset;

    KFLOAT32 m_f32SnwOffset;

    EulerAngles m_Ori;

    KFLOAT32 m_f32ThrmCont;

    KFLOAT32 m_f32Rflt;

    ClockTime m_MET;

    MineFusing m_MF;

    std::vector<KUINT8> m_vui8SDC;

	KDIS::DATA_TYPE::MinePaintScheme m_MPS;

    KUINT8 m_ui8NumTrpDetWrs;

	std::map< KUINT16, std::vector<KDIS::DATA_TYPE::Vector> >m_mvVertices;
    KUINT16 m_ui16NextIndex;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::getWire
    // Description: Return wire or throw exception if not found.
    // Parameter:   KUINT16 Index
    //************************************
    std::map< KUINT16, std::vector<Vector> >::iterator getWire( KUINT16 Index ) throw( KException );

    // Not Used. It is not possible to use this method of decoding/encoding as the values are
    // not all stored sequentially in the Minefield Data PDU. The PDU must do all the encoding/decoding.
    virtual void Decode( KDataStream & stream ) throw( KException ) {};
    virtual KDataStream Encode() const {
        return KDataStream();
    };
    virtual void Encode( KDataStream & stream ) const {};

public:

    Mine();

    Mine( const Vector & Location, KUINT16 ID );

    virtual ~Mine();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::SetLocation
    //              KDIS::DATA_TYPE::Mine::GetLocation
    // Description: Location of the mine, relative to the Minefield Location
    //              field, given in the corresponding Minefield State PDU field.
    //              Represented by an Entity Coordinate Vector record.
    // Parameter:   const Vector & L
    //************************************
    void SetLocation( const Vector & L );
    const Vector & GetLocation() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::SetID
    //              KDIS::DATA_TYPE::Mine::GetID
    // Description: Identifies the mine entity.
    //              NOTE: The Minefield number in conjunction with the Site Number
    //              and Application Number values from the Minefield ID (found in
    //              the Minefield Data PDU) forms the unique identifier for each mine.
    // Parameter:   KUINT16 ID
    //************************************
    void SetID( KUINT16 ID );
    KUINT16 GetID() const;

    /************************************************************************/
    /* The following values are all optional however you MUST use the same  */
    /* optional values in ALL mines that go into the Minefield Data PDU.    */
    /* NOTE:                                                                */
    /* When the set function's are called the bit in the relevant minefield */
    /* data filter will automatically be set to 'on', if you wish to then   */
    /* turn it back to 'off' you should use the relevant filter function to */
    /* do so.                                                               */
    /* E.G                                                                  */
    /* SetGroundBurialDepthOffsetValue( 1.0f ); // Bit will be set to 'on'  */
    /* SetGroundBurialDepthOffset( false ); // Turn the bit back to 'off'   */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::SetGroundBurialDepthOffsetValue
    //              KDIS::DATA_TYPE::Mine::GetGroundBurialDepthOffsetValue
    // Description: Specifies the offset of the origin of the mine coordinate
    //              system with respect to the ground surface. This offset can
    //              be used in conjunction with the mine orientation to determine
    //              the actual ground burial depth of the surfaces of a mine.
    //              Ground burial depth offset is specified as a positive
    //              measurement in meters below the terrain surface along the up vector.
    //              Although mine locations are specified in three dimensions in
    //              the Mine Location field, the ground burial depth offset field is
    //              provided so that the positions of mines relative to the terrain
    //              surface are accurately conveyed. Ground burial depth offset provides
    //              the frame of reference for the other two burial depth offsets
    //              (water and snow). If any of the three burial depth offsets are
    //              sent in the PDU, ground burial depth offset and mine orientation
    //              shall also be sent. If a terrain database does not include
    //              the ground surface (such as under a water feature), an arbitrary
    //              ground burial depth offset  shall be specified.
    // Parameter:   KFLOAT32 GBO
    //************************************
    void SetGroundBurialDepthOffsetValue( KFLOAT32 GBO );
    KFLOAT32 GetGroundBurialDepthOffsetValue() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::SetWaterBurialDepthOffsetValue
    //              KDIS::DATA_TYPE::Mine::GetWaterBurialDepthOffsetValue
    // Description: Specifies the offset of the origin of the mine coordinate
    //              system with respect to the water surface. This offset can
    //              be used in conjunction with the mine orientation to determine
    //              the actual water burial depth of the surfaces of a mine. Water
    //              burial depth offset is specified as a positive measurement in
    //              meters below the water surface along the up vector. Although
    //              mine locations are specified in three dimensions in the Mine
    //              Location field, the water burial depth offset field is provided
    //              so that the positions of mines relative to the water surface
    //              are accurately conveyed. Ground burial depth offset provides
    //              the frame of reference for this burial depth offset. If any of
    //              the three burial depth offsets are sent in the PDU, ground burial
    //              depth offset and mine orientation shall also be sent. The value
    //              of the water burial depth offset field shall be set to the value
    //              of the ground burial depth offset to indicate there is no water
    //              for the mine to be buried in.
    // Parameter:   KFLOAT32 WBO
    //************************************
    void SetWaterBurialDepthOffsetValue( KFLOAT32 WBO );
    KFLOAT32 GetWaterBurialDepthOffsetValue() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::SetSnowBurialDepthOffsetValue
    // Description: Specifies the offset of the origin of the mine coordinate system
    //              with respect to the snow surface. This offset can be used in
    //              conjunction with the mine orientation to determine the actual snow
    //              burial depth of the surfaces of a mine. Snow burial depth offset is
    //              specified as a positive measurement in meters below the snow surface
    //              along the up vector. Although mine locations are specified in three
    //              dimensions in the Mine Location field, the snow burial depth offset
    //              field is provided so that the positions of mines relative to the snow
    //              surface are accurately conveyed. Ground burial depth offset provides
    //              the frame of reference for this burial depth offset. If any of the
    //              three burial depth offsets are sent in the PDU, ground burial depth
    //              offset and mine orientation shall also be sent. The value of the snow
    //              burial depth offset field shall be set to the value of the ground
    //              burial depth offset to indicate there is no snow.
    // Parameter:   KFLOAT32 SBO
    //************************************
    void SetSnowBurialDepthOffsetValue( KFLOAT32 SBO );
    KFLOAT32 GetSnowBurialDepthOffsetValue() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::SetMineOrientationValue
    //              KDIS::DATA_TYPE::Mine::GetMineOrientationValue
    // Description: The orientation of the center axis direction of fire of the mine,
    //              relative to the minefield Entity Coordinate System.
    //              If any of the three burial depth offsets is sent in the PDU,
    //              this field shall also be sent.
    // Parameter:   const EulerAngles & O
    //************************************
    void SetMineOrientationValue( const EulerAngles & O );
    const EulerAngles & GetMineOrientationValue() const;
    EulerAngles & GetMineOrientationValue();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::SetThermalContrastValue
    //              KDIS::DATA_TYPE::Mine::GetThermalContrastValue
    // Description: The temperature difference between the mine and the surrounding
    //              soil in degrees Centigrade. In the case of a buried mine, the
    //              delta temperature shall be measured between the ground surface
    //              above the mine and the surrounding ground surface temperature.
    // Parameter:   KFLOAT32 TC
    //************************************
    void SetThermalContrastValue( KFLOAT32 TC );
    KFLOAT32 GetThermalContrastValue() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::SetReflectanceValue
    //              KDIS::DATA_TYPE::Mine::GetReflectanceValue
    // Description: The local dielectric difference between the mine and the surrounding soil.
    // Parameter:   KFLOAT32 R
    //************************************
    void SetReflectanceValue( KFLOAT32 R );
    KFLOAT32 GetReflectanceValue() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::SetMineEmplacementAgeValue
    //              KDIS::DATA_TYPE::Mine::GetMineEmplacementAgeValue
    // Description: The real-world (UTC) emplacement time of the mine.
    // Parameter:   const ClockTime & MET
    //************************************
    void SetMineEmplacementAgeValue( const ClockTime & MET );
    const ClockTime & GetMineEmplacementAgeValue() const;
    ClockTime & GetMineEmplacementAgeValue();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::SetFusingValue
    //              KDIS::DATA_TYPE::Mine::GetFusingValue
    // Description: The primary, secondary fuse and anti-handling device.
    // Parameter:   const MineFusing & MF
    //************************************
    void SetFusingValue( const MineFusing & MF );
    const MineFusing & GetFusingValue() const;
    MineFusing & GetFusingValue();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::AddScalarDetectionCoefficientValue
    //              KDIS::DATA_TYPE::Mine::SetScalarDetectionCoefficientValues
    //              KDIS::DATA_TYPE::Mine::GetScalarDetectionCoefficientValue
    //              KDIS::DATA_TYPE::Mine::ClearScalarDetectionCoefficientValues
    // Description: The coefficient to be utilized for proper correlation between
    //              detectors located on different simulation platforms.
    //              In statistically based detection system applications, the
    //              detection system simulation will generally compare a random number
    //              against an internally calculated probability of detection.
    //              The scalar detection coefficient, scaled appropriately to a 0 to
    //              1 range, should be compared against the internally calculated
    //              probability of detection to determine whether a detection has
    //              occurred. If the scalar detection coefficient is equal to or less
    //              than the probability of detection, then a detection has occurred.
    //              If the scalar detection coefficient is greater than the probability
    //              of detection, then a detection has not occurred. Internally generated
    //              random numbers should not be used because they will not provide for
    //              proper correlation across distributed detection system simulations.
    //              Random processes within the detector that are not determined by
    //              external environmental factors can be incorporated into the calculation
    //              of the appropriate probability of detection prior to its comparison
    //              with the scalar detection coefficient.
    //              Note: The number of SDC values should be equal to the number of sensor
    //              types in the Minefield Data PDU. I.E one SDC value per sensor type.
    //              If the number is not equal then an exception will be thrown from the Minefield Data PDU
    //              when you try to Encode.
    // Parameter:   KUINT8 SDC
    //************************************
    void AddScalarDetectionCoefficientValue( KUINT8 SDC );
    void SetScalarDetectionCoefficientValues( const std::vector<KUINT8> & SDC );
    const std::vector<KUINT8> & GetScalarDetectionCoefficientValues() const;
    std::vector<KUINT8> & GetScalarDetectionCoefficientValues();
    void ClearScalarDetectionCoefficientValues();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::SetPaintSchemeValue
    //              KDIS::DATA_TYPE::Mine::GetPaintSchemeValue
    // Description: The paint scheme of the mine including details about algae coverage.
    // Parameter:   const MinePaintScheme & MPS
    //************************************
    void SetPaintSchemeValue( const MinePaintScheme & MPS );
    const MinePaintScheme & GetPaintSchemeValue() const;
    MinePaintScheme & GetPaintSchemeValue();

    /************************************************************************/
    /* The following functions are all related to the mines trip detonation */
    /* wires. (bit 7 in filter)                                             */

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::GetNumberTripDetonationWires
    // Description: The number of trip/detonation wires attached to this mine.
    //************************************
    KUINT8 GetNumberTripDetonationWires() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::AddTripDetonationWire
    //              KDIS::DATA_TYPE::Mine::GetTripDetonationWire
    // Description: Add a new trip/detonation wire. Get the existing wires. Wires are stored in a map where
    //              the key is the id/index and the second value is the Vertices.
    //              Vertices is the location of the trip/detonation wire vertices relative to the minefield
    //              location field given in the corresponding Minefield State PDU field.
    //              Represented by an Entity Coordinate Vector record.
    //              Returns the index/id which can be used to access this wire, note the index value is not transmitted
    //              over DIS, it is just provided to allow you to access the wire.
    // Parameter:   const vector<Vector> & Vertices
    //************************************
    KUINT16 AddTripDetonationWire( const std::vector<Vector> & Vertices );
    const std::map< KUINT16, std::vector<Vector> > & GetTripDetonationWire() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::ClearWires
    // Description: Clears all wires and resets the SetTripDetonationWire filter back to false.
    //************************************
    void ClearWires();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::AddVertexToTripDetonationWire
    //              KDIS::DATA_TYPE::Mine::SetTripDetonationWireVertices
    //              KDIS::DATA_TYPE::Mine::RemoveTripDetonationWire
    //              KDIS::DATA_TYPE::Mine::GetWireVertices
    //              KDIS::DATA_TYPE::Mine::ClearWireVertices
    // Description: Change/Remove an existing wire or its Vertices.
    // Parameter:   KUINT16 Index - OUT_OF_BOUNDS exception thrown if invalid.
    // Parameter:   const Vector & Vertex, const vector<Vector> & Vertices
    //************************************
	void AddVertexToTripDetonationWire( KUINT16 Index, const KDIS::DATA_TYPE::Vector & Vertex ) throw( KException );
	void SetTripDetonationWireVertices( KUINT16 Index, const std::vector<KDIS::DATA_TYPE::Vector> & Vertices ) throw( KException );
    void RemoveTripDetonationWire( KUINT16 Index ) throw( KException );
	const std::vector<KDIS::DATA_TYPE::Vector> & GetWireVertices( KUINT16 Index ) throw( KException );
    void ClearWireVertices( KUINT16 Index ) throw( KException );

    /* End of trip detonation wire functions                                */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::GetLength
    // Description: Returns the total length of the mine including the
    //              optional parameters that are set to true.
    //************************************
    KUINT16 GetLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mine::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    KBOOL operator == ( const Mine & Value ) const;
    KBOOL operator != ( const Mine & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

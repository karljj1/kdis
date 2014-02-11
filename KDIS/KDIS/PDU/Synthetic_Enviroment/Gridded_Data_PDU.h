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
    class:      Gridded_Data_PDU
    DIS:        (6) 1278.1a - 1998
    created:    06/10/2009
    author:     Karl Jones

    purpose:    Information about global, spatially varying environmental effects
                shall be communicated using one or more Gridded Data PDUs.

    size:       512 bits / 64 octets - Min size
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/EnvironmentType.h"
#include "./../../DataTypes/EulerAngles.h"
#include "./../../DataTypes/GridAxisIrregular.h"
#include "./../../DataTypes/GridDataType0.h"
#include "./../../DataTypes/GridDataType1.h"
#include "./../../DataTypes/GridDataType2.h"
#include "./../../Extras/KRef_Ptr.h"
#include <vector>

namespace KDIS {

namespace DATA_TYPE {

// Some PDU specific data types.
typedef KDIS::UTILS::KRef_Ptr<GridAxisRegular> GridAxisDescriptor;
typedef KDIS::UTILS::KRef_Ptr<GridData> GridDataPtr;

} // END namespace DATA_TYPE

namespace PDU {

class KDIS_EXPORT Gridded_Data_PDU : public Header
{
protected:

    KDIS::DATA_TYPE::EntityIdentifier m_EnvProcID;

    KUINT16 m_ui16FieldNum;

    KUINT16 m_ui16PDUNum;

    KUINT16 m_ui16PDUTotal;

    KUINT16 m_ui16CordSys;

    KUINT8 m_ui8NumAxis;

    KUINT8 m_ui8ConstGrid;

    KDIS::DATA_TYPE::EnvironmentType m_EnvType;

    KDIS::DATA_TYPE::EulerAngles m_Ori;

    KUINT64 m_ui64SampleTime;

    KUINT32 m_ui32TotalValues;

    KUINT8 m_ui8VecDim;

    KUINT16 m_ui16Padding1; // 24 bits unused for alignment of Grid Axis Descriptor
    KUINT8 m_ui8Padding1;

	std::vector<KDIS::DATA_TYPE::GridAxisDescriptor> m_vpGridAxisDesc;

	std::vector<KDIS::DATA_TYPE::GridDataPtr> m_vGridData;

public:

    static const KUINT16 GRIDDED_DATA_PDU_SIZE = 64; // Min size

    Gridded_Data_PDU();

    Gridded_Data_PDU( KDataStream & stream ) throw( KException );

	Gridded_Data_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Gridded_Data_PDU( const KDIS::DATA_TYPE::EntityIdentifier & EnvironmentalProcessID, KUINT16 FieldNumber, KUINT16 PduNum,
                      KUINT16 PduTotal, KDIS::DATA_TYPE::ENUMS::CoordinateSystem CS, KDIS::DATA_TYPE::ENUMS::ConstantGrid CG, 
					  const KDIS::DATA_TYPE::EnvironmentType & ET, const KDIS::DATA_TYPE::EulerAngles & Ori, KUINT64 SampleTime );

    virtual ~Gridded_Data_PDU();

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::SetEnvironmentalProcessID
    //              KDIS::PDU::Gridded_Data_PDU::GetEnvironmentalProcessID
    // Description: Identifies the environmental simulation application issuing the PDU.
    //              This field is also known as "Environmental Simulation ID" in DIS version 7.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetEnvironmentalProcessID( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetEnvironmentalProcessID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetEnvironmentalProcessID();

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::SetFieldNumber
    //              KDIS::PDU::Gridded_Data_PDU::GetFieldNumber
    // Description: Specifies a unique identifier for each environmental variable transmitted
    //              during an exercise.
    // Parameter:   KUINT16 FN
    //************************************
    void SetFieldNumber( KUINT16 FN );
    KUINT16 GetFieldNumber() const;

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::SetPDUNumber
    //              KDIS::PDU::Gridded_Data_PDU::GetPDUNumber
    // Description: Specifies an index number of the current PDU within the total number
    //              of PDUs used to transmit the environmental data.
    //              SetPDUNumberAndTotal will throw an exception if Num is greater than Total.
    //              No error checking is done if you use the 2 separate accessors SetPDUNumber
    //              and SetPDUTotal so be careful not to make the PDU number greater than the total.
    // Parameter:   KUINT16 PN
    //************************************
    void SetPDUNumber( KUINT16 PN );
    KUINT16 GetPDUNumber() const;
    void SetPDUNumberAndTotal( KUINT16 Num, KUINT16 Total ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::SetPDUTotal
    //              KDIS::PDU::Gridded_Data_PDU::GetPDUTotal
    // Description: Specifies the total number of PDUs used to transmit this environmental data.
    //              This value should not be less than PDU number.
    // Parameter:   KUINT16 PT
    //************************************
    void SetPDUTotal( KUINT16 PT );
    KUINT16 GetPDUTotal() const;

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::SetCoordinateSystem
    //              KDIS::PDU::Gridded_Data_PDU::GetCoordinateSystem
    // Description: Specifies the coordinate system of the grid for the environmental
    //              data contained in the Gridded Data PDU.
    // Parameter:   CoordinateSystem CS
    //************************************
    void SetCoordinateSystem( KDIS::DATA_TYPE::ENUMS::CoordinateSystem CS );
    KDIS::DATA_TYPE::ENUMS::CoordinateSystem GetCoordinateSystem() const;

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::Decode
    // Description: Number of grid axis in the PDU.
    //              e.g. three grid axes for an x, y, z coordinate system.
    //************************************
    KUINT8 GetNumberAxis() const;

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::SetConstantGrid
    //              KDIS::PDU::Gridded_Data_PDU::GetConstantGrid
    // Description: Specifies whether the domain grid axes are identical to those of the previous
    //              domain update grid for the environmental data sample contained in the PDU
    // Parameter:   ConstantGrid CG
    //************************************
    void SetConstantGrid( KDIS::DATA_TYPE::ENUMS::ConstantGrid CG );
    KDIS::DATA_TYPE::ENUMS::ConstantGrid GetConstantGrid() const;

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::SetEnvironmentType
    //              KDIS::PDU::Gridded_Data_PDU::GetEnvironmentType
    // Description: DIS enumeration identifying the type of environmental effect being described.
    // Parameter:   const EnvironmentType & ET
    //************************************
    void SetEnvironmentType( const KDIS::DATA_TYPE::EnvironmentType & ET );
    const KDIS::DATA_TYPE::EnvironmentType & GetEnvironmentType() const;
    KDIS::DATA_TYPE::EnvironmentType & GetEnvironmentType();

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::SetOrientation
    //              KDIS::PDU::Gridded_Data_PDU::GetOrientation
    // Description: Specifies the orientation of the data grid.
    // Parameter:   const EulerAngles & O
    //************************************
    void SetOrientation( const KDIS::DATA_TYPE::EulerAngles & O );
    const KDIS::DATA_TYPE::EulerAngles & GetOrientation() const;
    KDIS::DATA_TYPE::EulerAngles & GetOrientation();

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::SetSampleTime
    //              KDIS::PDU::Gridded_Data_PDU::GetSampleTime
    // Description: Specifies the valid time of the environmental data sample contained in the PDU.
    // Parameter:   KUINT64 ST
    //************************************
    void SetSampleTime( KUINT64 ST );
    KUINT64 GetSampleTime() const;

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::SetTotalValues
    //              KDIS::PDU::Gridded_Data_PDU::GetTotalValues
    // Description: Specifies the total number of data values for all PDUs for an environmental
    //              sample. This total includes vector-valued environmental data and equals the
    //              product of the vector dimension and the total number of grid points.
    // Parameter:   KUINT32 TV
    //************************************
    void SetTotalValues( KUINT32 TV );
    KUINT32 GetTotalValues() const;

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::SetVectorDimension
    //              KDIS::PDU::Gridded_Data_PDU::GetVectorDimension
    // Description: This field shall specify the total number of data values at each grid point and
    //              accommodates scalar or vector-valued environmental data.
    //              Vector Dimension shall be one for scalar data, and shall be greater than one when
    //              multiple enumerated environmental data values are sent for each grid location
    //              (e.g., u, v, w wind components have V = 3). (I.E Number of GridData values).
    // Parameter:   KUINT8 VD
    //************************************
    void SetVectorDimension( KUINT8 VD );
    KUINT8 GetVectorDimension() const;

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::AddGridAxisDescriptor
    //              KDIS::PDU::Gridded_Data_PDU::SetGridAxisDescriptors
    //              KDIS::PDU::Gridded_Data_PDU::GetSetGridAxisDescriptors
    // Description: Specifies the detailed information about the grid dimensions (axes)
    //              and coordinates for environmental state variables.
    //              More than one Grid Data record is allowed in a single Gridded Data PDU
    //              corresponding to each enumerated sample type.
    // Parameter:   const GridAxisDescriptor & GAD, const vector<GridAxisDescriptor> & GADS
    //************************************
    void AddGridAxisDescriptor( const KDIS::DATA_TYPE::GridAxisDescriptor & GAD );
	void SetGridAxisDescriptors( const std::vector<KDIS::DATA_TYPE::GridAxisDescriptor> & GADS );
	const std::vector<KDIS::DATA_TYPE::GridAxisDescriptor> & GetSetGridAxisDescriptors() const;

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::AddGridData
    //              KDIS::PDU::Gridded_Data_PDU::SetGridData
    //              KDIS::PDU::Gridded_Data_PDU::GetGridData
    // Description: Specifies the environmental state data at the grid locations specified by
    //              parameters in the Grid Axis Descriptor record.
    // Parameter:   const GridDataPtr & GD, const vector<GridDataPtr> & GD
    //************************************
    void AddGridData( const KDIS::DATA_TYPE::GridDataPtr & GD );
	void SetGridData( const std::vector<KDIS::DATA_TYPE::GridDataPtr> & GD );
	const std::vector<KDIS::DATA_TYPE::GridDataPtr> & GetGridData() const;

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Gridded_Data_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Gridded_Data_PDU & Value ) const;
    KBOOL operator != ( const Gridded_Data_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS

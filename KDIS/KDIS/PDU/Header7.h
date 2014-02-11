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
    class:      Header7
	DIS:        (7) 1278.1 - 200x draft 15
    created:    03/02/2011
    author:     Karl Jones

    purpose:    Provides access to the PDU status field introduced in the DIS 7 standard.

                This field is used to indicate status information that either:
                (1) affects the processing of this specific PDU as a whole
                    without regard to any specific data field in the PDU.
                (2) provides information related to the interpretation of
                    one or more data fields or their content.
                (3) provides information that affects the processing of an
                    entity, other object or environmental process associated with this PDU.
	            
				Note: Some of these fields are specific to certain PDU, the 
                following shows the PDU status associated with each PDU Type:

                -- PDU Type --                          -- PDU status associated -- 
                1 Entity State                          TEI LVC CEI 
                2 Fire                                      LVC CEI FTI
                3 Detonation                                LVC CEI     DTI 
                4 Collision                                     CEI
                5 Service Request                               CEI 
                6 Resupply Offer                                CEI
                7 Resupply Received                             CEI
                8 Resupply Cancel                               CEI 
                9 Repair Complete                               CEI 
               10 Repair Response                               CEI 
               11 Create Entity                                 CEI
               12 Remove Entity                                 CEI
               13 Start Resume                                  CEI 
               14 Stop Freeze                                   CEI 
               15 Acknowledge                                   CEI 
               16 Action Request                                CEI 
               17 Action Response                               CEI 
               18 Data Query                                    CEI 
               19 Set Data                                      CEI 
               20 Data                                          CEI 
               21 Event Report                                  CEI 
               22 Message                                       CEI 
               23 Electromagnetic Emission              TEI LVC CEI
               24 Designator                            TEI LVC CEI
               25 Transmitter                           TEI LVC CEI         RAI
               26 Signal                                TEI LVC CEI         RAI
               27 Receiver                              TEI LVC CEI         RAI
               28 IFF ATC NAVAIDS                       TEI LVC CEI                 SM
               29 UnderwaterAcoustic                            CEI
               30 SupplementalEmission EntityState              CEI
               31 IntercomSignal                        TEI LVC CEI             IAI
               32 IntercomControl                       TEI LVC CEI             IAI
               33 AggregateState                                CEI
               34 IsGroupOf                                     CEI 
               35 TransferControl                               CEI
               36 IsPartOf                                      CEI 
               37 MinefieldState                                CEI 
               38 MinefieldQuery                                CEI 
               39 MinefieldData                                 CEI 
               40 MinefieldResponseNAK                          CEI 
               41 EnvironmentalProcess                  TEI LVC CEI
               42 GriddedData                                   CEI 
               43 PointObjectState                              CEI 
               44 LinearObjectState                             CEI 
               45 ArealObjectState                              CEI 
               46 TSPI                                          CEI 
               47 Appearance                                    CEI 
               48 ArticulatedParts                              CEI 
               49 LEFire                                        CEI 
               50 LEDetonation                                  CEI 
               51 CreateEntity R                                CEI 
               52 RemoveEntity R                                CEI 
               53 Start Resume R                                CEI 
               54 Stop Freeze R                                 CEI 
               55 Acknowledge R                                 CEI 
               56 ActionRequest R                               CEI 
               57 ActionResponse R                              CEI 
               58 DataQuery R                                   CEI 
               59 SetData R                                     CEI 
               60 Data R                                        CEI 
               61 EventReport R                                 CEI 
               62 Comment R                                     CEI 
               63 Record R                                      CEI
               64 SetRecord R                                   CEI 
               65 RecordQuery R                                 CEI 
               66 Collision Elastic                             CEI 
               67 EntityStateUpdate                     TEI LVC CEI
               68 DirectedEnergyFire                        LVC CEI
               69 DirectedEnergyDamageStatus                LVC CEI
               70 IO Action                                 LVC CEI
               71 IO Report                                 LVC CEI
               72 Attribute                

    Legend:     CEI - Coupled Extension Indicator
                TEI - Transferred Entity Indicator
                LVC - LVC Indicator
                FTI - Fire Type Indicator
                DTI - Detonation Type Indicator
                RAI - Radio Attached Indicator
                IAI - Intercom Attached Indicator
                SM  - Simulation Mode

    size:       Same as Header6
*********************************************************************/

#pragma once

#include "./Header6.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Header7 : public Header6
{
protected:

	union
	{
		struct
		{
			KUINT8 m_ui8PDUStatusTEI : 1;                   // Bit  0.
			KUINT8 m_ui8PDUStatusLVC : 2;                   // Bits 1-2.
			KUINT8 m_ui8PDUStatusCEI : 1;                   // Bit  3. 

			union
			{
				struct
				{
					KUINT8 m_ui8PDUStatusFTI  : 1;        // Bit  4. 
					KUINT8 m_ui8PDUStatusBit5 : 1;        // Bit  5.
				};

				KUINT8 m_ui8PDUStatusDTI_RAI_IAI : 2;        // Bits 4-5. Could be used for DTI, RAI or IAI.
			};

			KUINT8 m_ui8PDUStatusBit6 : 1;                      // Bit  6. Unused.
			KUINT8 m_ui8PDUStatusSM   : 1;                      // Bit  7.
		};

		KUINT8 m_ui8PDUStatus;

	} m_PDUStatusUnion;

public:

    Header7();

    Header7( KDataStream & stream ) throw( KException );

    Header7( KDIS::DATA_TYPE::ENUMS::ProtocolVersion PV, KUINT8 ExerciseID, KDIS::DATA_TYPE::ENUMS::PDUType PT,
		     KDIS::DATA_TYPE::ENUMS::ProtocolFamily PF, const KDIS::DATA_TYPE::TimeStamp & TS, KUINT16 PDULength );

    virtual ~Header7();

    //************************************
    // FullName:    KDIS::PDU::Header7::SetPDUStatus
    //              KDIS::PDU::Header7::GetPDUStatus
    // Description: The entire PDU status field.
    // Parameter:   KUINT8 S
    //************************************
    void SetPDUStatus( KUINT8 S );
    KUINT8 GetPDUStatus() const;

	//************************************
	// FullName:    KDIS::PDU::Header7::SetPDUStatusCEI
	//              KDIS::PDU::Header7::GetPDUStatusCEI
	// Description: Indicates whether the PDU is Coupled true(1)  
	//              or Not Coupled false(0) with an Attribute PDU.
	// PDU:         Applies to all PDU's(1-71) except the Attribute PDU.       
	// Parameter:   KBOOL TEI
	//************************************
	void SetPDUStatusCEI( KBOOL CEI );
	KBOOL GetPDUStatusCEI() const;

    //************************************
    // FullName:    KDIS::PDU::Header7::SetPDUStatusTEI
    //              KDIS::PDU::Header7::GetPDUStatusTEI
	// Description: Identifies whether the Simulation Address of the Entity ID contained
    //              in this PDU is the owner of the entity.
    //              false(0) = no difference. The Simulation Address of the Entity ID is the owner of Indicator.
    //              true(1) = difference. The Simulation Address of the Entity ID is not the owner of this entity.
	// PDU:         See Header7 description to see which PDU's use this field.              
	// Parameter:   KBOOL TEI
    //************************************
    void SetPDUStatusTEI( KBOOL TEI );
    KBOOL GetPDUStatusTEI() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::Header7::SetPDUStatusLVC
	//              KDIS::DATA_TYPE::Header7::GetPDUStatusLVC
	// Description: Indicates whether the data contained in this PDU is related to a
	//              live(1), virtual(2) or constructive(3) entity. If the LVC designation is not
	//              able to be determined, this field shall be set to No Statement(0).
	//				For more information on LVC try the Wikipedia page: 
	//              http://en.wikipedia.org/wiki/Live,_Virtual,_and_Constructive
	// PDU:         See Header7 description to see which PDU's use this field.    
	// Parameter:   LVCIndicator LVC
	//************************************
	void SetPDUStatusLVC( KDIS::DATA_TYPE::ENUMS::LVCIndicator LVC );
	KDIS::DATA_TYPE::ENUMS::LVCIndicator GetPDUStatusLVC() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::Header7::SetPDUStatusFTI
	//              KDIS::DATA_TYPE::Header7::GetPDUStatusFTI
	// Description: Indicates whether the type of object fired was
	//              a Munition false(0) or an Expendable true(1).
	// PDU:         Fire(2) 
	// Parameter:   KBOOL FTI
	//************************************
	void SetPDUStatusFTI( KBOOL FTI );
	KBOOL GetPDUStatusFTI() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::Header7::SetPDUStatusDTI
	//              KDIS::DATA_TYPE::Header7::GetPDUStatusDTI
	// Description: Indicates whether the type of object that detonated,
	//              exploded or burst was a Munition (0), Expendable (1),
	//              or Non-Munition Explosion (2).
	// PDU:         Detonation(3) 
	// Parameter:   DetonationType DTI
	//************************************
	void SetPDUStatusDTI( KDIS::DATA_TYPE::ENUMS::DetonationType DTI );
	KDIS::DATA_TYPE::ENUMS::DetonationType GetPDUStatusDTI() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::Header7::SetPDUStatusRAI
	//              KDIS::DATA_TYPE::Header7::GetPDUStatusRAI
	// Description: Used to indicate whether the radio transmitter or receiver
	//              is attached to an entity or object as follows: No Statement(0),
	//              Unattached (1) and Attached (2).
	// PDU:         Transmitter(25), Signal(26), Receiver(27)
	// Parameter:   AttachedIndicator RAI
	//************************************
	void SetPDUStatusRAI( KDIS::DATA_TYPE::ENUMS::AttachedIndicator RAI );
	KDIS::DATA_TYPE::ENUMS::AttachedIndicator GetPDUStatusRAI() const;
	
	//************************************
	// FullName:    KDIS::DATA_TYPE::Header7::SetPDUStatusIAI
	//              KDIS::DATA_TYPE::Header7::GetPDUStatusIAI
	// Description: Used to indicate whether the intercom is attached to an entity or
	//              object as follows: No Statement(0), Unattached (1) and Attached (2).	
	// PDU:         IntercomSignal(31), IntercomControl(32)
	// Parameter:   AttachedIndicator IAI
	//************************************
	void SetPDUStatusIAI( KDIS::DATA_TYPE::ENUMS::AttachedIndicator RAI );
	KDIS::DATA_TYPE::ENUMS::AttachedIndicator GetPDUStatusIAI() const;

	//************************************
	// FullName:    KDIS::PDU::Header7::SetPDUStatusSM
	//              KDIS::PDU::Header7::GetPDUStatusSM
	// Description: Indicates whether the Simulation Mode field of the Change/Options record
	//              for this IFF PDU is set to Regeneration false(0) or Interactive true(1).
	// PDU:         IFF ATC NAVAIDS(28)      
	// Parameter:   KBOOL SM
	//************************************
	void SetPDUStatusSM( KBOOL SM );
	KBOOL GetPDUStatusSM() const;
	
    //************************************
    // FullName:    KDIS::PDU::Header7::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Header7::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
	// Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Header7::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Header7 & Value ) const;
    KBOOL operator != ( const Header7 & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS


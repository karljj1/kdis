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
class:      KRef_Ptr
created:    2009/07/22
author:     Karl Jones

purpose:    Implementation of a referenced smart pointer.
            Holds a counter of how many references are currently held of a pointer.
            When the final reference is released the memory is released.

            -*How To Use:*-

            KRef_Ptr<MyClass> pObj = new MyClass;

            pObj can now be used like a normal pointer.

            E.G

            pObj->func();
            *pObj.func();

            -*Note:*-

            Be carefull of the following mistakes:

            - MyClass * p = pObj.GetPtr(); // p is not safe. It could be deleted when the KRef_Ptr goes out of scope leaving you with a NULL pointer.

            - KRef_Ptr<MyClass> pRef = pObj.GetPtr(); // This will create a second reference to the pointer which will cause problems.

              instead use

              KRef_Ptr<MyClass> pRef = pObj;
*********************************************************************/

#pragma once

#include "./../KDefines.h"

namespace KDIS {
namespace UTILS {

typedef KDIS::KUINT16 RefCounter; // Change the counter to KUINT32 if you expect to have over 65,535 references.

template<class Type>
class KRef_Ptr
{
private:

    typedef KRef_Ptr<Type> ThisType;

    Type * m_pRef;

    RefCounter * m_piCount;

    //************************************
    // FullName:    KRef_Ptr<Type>::ref
    // Description: Increments reference counter
    //************************************
    void ref()
    {
        if( m_pRef )++( *m_piCount );
    };

    //************************************
    // FullName:    KRef_Ptr<Type>::unRef
    // Description: Decrements reference counter, cleans
    //              up if no other references exist.
    //************************************
    void unRef()
    {
        if( m_pRef )
        {
            --( *m_piCount );
            if( *m_piCount == 0 )
            {
                delete m_piCount;
                delete m_pRef;
                m_piCount = NULL;
                m_pRef = NULL;
            }
        }
    };

public:

    KRef_Ptr() :
        m_pRef( NULL ),
        m_piCount( NULL )
    {
    };

    KRef_Ptr( Type * p )
    {
        m_pRef = p;
        m_piCount = new RefCounter;
        *m_piCount = 0;
        ref();
    };

    KRef_Ptr( const KRef_Ptr<Type> & p ) :
        m_pRef( p.m_pRef ),
        m_piCount( p.m_piCount )
    {
        ref();
    };

    virtual ~KRef_Ptr()
    {
        unRef();
    };

    //************************************
    // FullName:    KRef_Ptr<Type>::Clear
    // Description: Removes the current reference held.
    //************************************
    void Clear()
    {
        unRef();
        m_pRef = NULL;
        m_piCount = NULL;
    };

    //************************************
    // FullName:    KRef_Ptr<Type>::GetPtr
    // Description: Returns pointer to the current reference
    //              or NULL if no reference exists.
    //              Note: The returned pointer will not be safe. Avoid using this function.
    //************************************
    Type * GetPtr() const
    {
        return m_pRef;
    };

    //************************************
    // FullName:    KRef_Ptr<Type>::GetCount
    // Description: Returns number of reference that currently exist
    //              for this pointer or 0 if no reference is held.
    //************************************
    RefCounter GetCount() const
    {
        if( m_piCount )return *m_piCount;
    };

    //************************************
    // FullName:    KRef_Ptr<Type>::operator=
    // Description: Assignment of an other KRef_Ptr.
    // Parameter:   const KRef_Ptr<Type> & p
    //************************************
    KRef_Ptr<Type> & operator=( const KRef_Ptr<Type> & p )
    {
        if( m_pRef == p.m_pRef )return *this;
        unRef();
        m_pRef = p.m_pRef;
        m_piCount = p.m_piCount;
        ref();
        return *this;
    };

    //************************************
    // FullName:    KRef_Ptr<Other>::operator=
    // Description: Assignment of an other KRef_Ptr of a different type.
    // Parameter:   const KRef_Ptr<Other> & p
    //************************************
    template<class Other>
    KRef_Ptr<Type> & operator=( const KRef_Ptr<Other> & p )
    {
        unRef();
        m_pRef = p.m_pRef;
        m_piCount = p.m_piCount;
        ref();
        return *this;
    };

    //************************************
    // FullName:    KRef_Ptr<Type>::operator=
    // Description: Assignment of a new reference.
    // Parameter:   Type * p
    //************************************
    KRef_Ptr<Type> & operator=( Type * p )
    {
        if( m_pRef == p )return *this;
        unRef();
        m_pRef = p;
        m_piCount = new RefCounter;
        *m_piCount = 0;
        ref();
        return *this;
    };

    //************************************
    // FullName:    KRef_Ptr<Other>::operator=
    // Description: Assignment of a new reference of a different type.
    // Parameter:   Other * p
    //************************************
    template<class Other>
    KRef_Ptr<Type> & operator=( Other * p )
    {
        unRef();
        m_pRef = p;
        m_piCount = new RefCounter;
        *m_piCount = 0;
        ref();
        return *this;
    };

    //************************************
    // FullName:    KRef_Ptr<Type>::operator==
    // Description: Comparison equals. Checks if both references are the same.
    // Parameter:   const KRef_Ptr<Type> & p
    //************************************
    KBOOL operator==( const KRef_Ptr<Type> & p )const
    {
        return m_pRef == p.m_pRef;
    };

    //************************************
    // FullName:    KRef_Ptr<Other>::operator==
    // Description: Comparison equals. Checks if both references are the same of a
    //              different type.
    //              E.G An upast/downcast of the current type.
    // Parameter:   const KRef_Ptr<Other> & p
    //************************************
    template<class Other>
    KBOOL operator==( const KRef_Ptr<Other> & p )const
    {
        return m_pRef == p.m_pRef;
    };

    //************************************
    // FullName:    KRef_Ptr<Type>::operator*
    // Description: When referencing the KRef_Ptr return our referenced object.
    //************************************
    Type & operator*() const
    {
        return *m_pRef;
    };

	//************************************
	// FullName:    KRef_Ptr<Type>::operator Type *
	// Description: Implicit conversion support.
	//************************************
	operator Type *() 
	{ 
		return m_pRef;
	}

    //************************************
    // FullName:    KRef_Ptr<Type>::operator->
    // Description: Returns the referenced pointer.
    //************************************
    Type * operator->() const
    {
        return m_pRef;
    };

    //************************************
    // FullName:    KRef_Ptr<Type>::operator!=
    // Description: Comparison does not equals. Compares the referenced pointer to an unsafe pointer.
    // Parameter:   const Type * p
    //************************************
    KBOOL operator!= ( const Type * p ) const
    {
        return m_pRef != p;
    };

    //************************************
    // FullName:    KRef_Ptr<Other>::operator!=
    // Description: Comparison does not equals. Compares the referenced pointer to an unsafe pointer of a different type.
    //              E.G a derrived type.
    // Parameter:   const Other * p
    //************************************
    template<class Other>
    KBOOL operator!= ( const Other * p ) const
    {
        return m_pRef != p;
    };

    //************************************
    // FullName:    KRef_Ptr<Type>::operator!=
    // Description: Comparison does not equals. Compares the referenced pointer to an other KRef_Ptr.
    // Parameter:   const KRef_Ptr<Type> & p
    //************************************
    KBOOL operator!= ( const KRef_Ptr<Type> & p ) const
    {
        return m_pRef != p.m_pRef;
    };

    //************************************
    // FullName:    KRef_Ptr<Other>::operator!=
    // Description: Comparison does not equals. Compares the referenced pointer to an other KRef_Ptr of a different type.
    // Parameter:   const KRef_Ptr<Other> & p
    //************************************
    template<class Other>
    KBOOL operator!= ( const KRef_Ptr<Other> & p ) const
    {
        return m_pRef != p.m_pRef;
    };

    //************************************
    // FullName:    KRef_Ptr<Type>::operator bool() const
    // Description: This conversion operator allows KRef_Ptr objects to be used in boolean contexts, like if(p && p->valid()) {}.
    //************************************
    typedef Type * ThisType::*UnspecifiedBoolType;

    operator UnspecifiedBoolType() const // never throws
    {
        return m_pRef == 0? 0: &ThisType::m_pRef;
    }

    // operator! is redundant, but some compilers need it
    KBOOL operator! () const // never throws
    {
        return m_pRef == 0;
    }
};


} // END namespace UTILS
} // END namespace KDIS

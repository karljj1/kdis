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

#pragma once

//
// Determine which header we should use for all PDU.
//

#include "./../KDefines.h"

#if DIS_VERSION > 6
	#include "./Header7.h"
#else
	#include "./Header6.h"
#endif

namespace KDIS {
namespace PDU {

#if DIS_VERSION > 6
	typedef Header7 Header;
#else
	typedef Header6 Header;
#endif

}; // END namespace PDU
}; // END namespace KDIS

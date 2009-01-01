/***************************************************************************
                        CDebug.cpp  -  description
							-------------------
	begin                : December 29th, 2008
	copyright            : (C) 2008 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id$
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

// Framework headers
#include "CDebug.h"				// System::Diagnostics::Debug class
#include "../CConsole.h"		// System::Console class
#include "../CString.h"			// System::String class


   /*=====================================================================*/
namespace System
{
namespace Diagnostics
{
	Debug::Debug() {}


	Debug::~Debug() {}


   /*=====================================================================*/
	void Debug::Assert(bool condition)
	{
		if (condition)
			return;

		System::Terminal << "Assertion failed\n";
	}


   /*=====================================================================*/
	String Debug::ToString() const
	{
		return String("System::Diagnostics::Debug");
	}

} // namespace System::Diagnostics
} // namespace System
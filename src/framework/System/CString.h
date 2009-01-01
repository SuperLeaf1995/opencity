/***************************************************************************
                        CString.h  -  description
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

#ifndef _OPENCITY_FRAMEWORK_SYSTEM_CSTRING_H_
#define _OPENCITY_FRAMEWORK_SYSTEM_CSTRING_H_ 1

// Framework headers
#include "CObject.h"

// Standard C++ headers
#include <string>
#include <ostream>

namespace System
{
	class String : public Object
	{
		public:
			String();
			String(char const* value);
			String(std::string value);
			virtual ~String();

			virtual String ToString() const;

			String& operator+(const String& value);
			friend std::ostream& operator<<(std::ostream& os, const String& value);

		private:
			std::string msString;
	}; // class System::String
} // namespace System

#endif
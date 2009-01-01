/***************************************************************************
                        main.cpp  -  description
							-------------------
	begin                : December 31th, 2008
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

#include "System/CType.h"
#include "System/CConsole.h"
#include "System/CException.h"
#include "System/Diagnostics/CDebug.h"

// System::String test
int TestString()
{
	System::Terminal << "System::String test suite\n";

	System::String s1 = System::String("String assignment test\n");
	System::Terminal << s1;
	System::String sA = "String A ";
	System::String sB = System::String("String B\n");
	System::String sC = sA + sB;
	System::Terminal << sC;

	System::Terminal << "\n";
	return 0;
}


// System::Exception test
int TestException()
{
	System::Terminal << "System::Exception test suite\n";

	try
	{
		throw System::Exception("System::Exception test\n");
	}
	catch (System::Exception& ex)
	{
		System::Terminal << ex;
		System::String s = ex.GetMessage();
		System::Terminal << s;
		System::Terminal << ex.GetMessage();
		System::Terminal << (System::String)ex.GetMessage();
	}

	System::Terminal << "\n";
	return 0;
}


// System::Type test
int TestType()
{
	System::Terminal << "System::Type test suite\n";

	System::Object object;
	System::Type t = object.GetType();
	System::Terminal << t.GetName() << "\n";
	System::Terminal << t.GetType().GetName() << "\n";

	System::Terminal << System::Terminal.GetType().GetName() << "\n";

	System::String s = System::String("String object");
	System::Terminal << s.GetType().GetName() << "\n";

	System::Exception ex;
	System::Terminal << ex.GetType().GetName() << "\n";

	System::Diagnostics::Debug debug;
	System::Terminal << debug.GetType().GetName() << "\n";

	System::Terminal << "\n";
	return 0;
}


// Main test procedure
int main()
{
	// System::Console test
	System::Terminal << "OpenCity C++ framework test suite\n";
	System::Terminal << System::String("System::Console System::String output test\n");

	// System::String test
	TestString();

	// System::Exception test
	TestException();

	// System::Type test
	TestType();

	// System::Diagnostics::Debug test
	System::Diagnostics::Debug::Assert(false);
	System::Diagnostics::Debug::Assert(0 == 1);

}
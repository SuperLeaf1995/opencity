/***************************************************************************
                        CXmlDocument.h  -  description
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

#ifndef _OPENCITY_FRAMEWORK_XML_CXMLDOCUMENT_H_
#define _OPENCITY_FRAMEWORK_XML_CXMLDOCUMENT_H_ 1

// Framework headers
#include "CXmlNode.h"

SPF_NAMESPACE_BEGIN(System)

// Forward System::String class declaration
class String;

SPF_NAMESPACE_BEGIN(Xml)

/**
	Represents a XML document
*/
class XmlDocument : XmlNode
{
	public:
		XmlDocument();
		virtual ~XmlDocument();

		/**
			Gets the root XmlElement for the document.
		*/
		//XmlElement GetDocumentElement() const;

		/**
			Loads the XML document from the specified URL.
			\param url URL for the file containing the XML document to load.
		The URL can be either a local file or an HTTP URL (a Web address).
		*/
		virtual void Load(String url);

		virtual String ToString() const;

}; // class System::Xml::XmlDocument

// namespace System::Xml
SPF_NAMESPACE_END

// namespace System
SPF_NAMESPACE_END

#endif

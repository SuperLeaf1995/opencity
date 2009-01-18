/***************************************************************************
                        CXmlDocument.cpp  -  description
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
#include "CXmlDocument.h"
#include "../CString.h"
#include "../CException.h"				// FIXME: file not found exception

// libxml headers
#include <libxml/parser.h>
#include <libxml/tree.h>
#ifndef LIBXML_TREE_ENABLED
	#error "LibXml tree support required."
#endif

SPF_NAMESPACE_NESTED_BEGIN(System, Xml)


   /*=====================================================================*/
XmlDocument::XmlDocument() {}


XmlDocument::~XmlDocument() {}


   /*=====================================================================*/
void XmlDocument::Load(String url)
{
	xmlDoc* psXmlDoc = xmlReadFile(url, NULL, 0);

	if (psXmlDoc == NULL) {
		throw Exception("File not found");
	}

	// Get the root element node
/*
	root_element = xmlDocGetRootElement(psXmlDoc);
	print_element_names(root_element);
*/

	xmlFreeDoc(psXmlDoc);
	xmlCleanupParser();
}


   /*=====================================================================*/
String XmlDocument::ToString() const
{
	return String("System::Xml::XmlDocument");
}


   /*=====================================================================*/


SPF_NAMESPACE_NESTED_END

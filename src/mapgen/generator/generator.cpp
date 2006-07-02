/***************************************************************************
						generator.cpp  -  description
							-------------------
	begin                : july 2nd, 2006
	copyright            : (C) 2006 by Fr�d�ric RODRIGO
	email                : f.rodrigo free.fr
	
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

#include "generator.h"


   /*=====================================================================*/
Generator::Generator()
{
	MAP_DEBUG( "ctor" );
}


   /*=====================================================================*/
Generator::~Generator()
{
	MAP_DEBUG( "dtor" );
}


   /*=====================================================================*/
Map* Generator::render()
{
	return new Map( 50, 50 );
}

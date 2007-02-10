/***************************************************************************
						shapeTopRound.h  -  description
							-------------------
	begin                : fev 10th, 2007
	copyright            : (C) 2006 by Fr�d�ric RODRIGO
	email                : f.rodrigo free.fr
	
	$Id: shapeTopRound.h 124 2007-01-13 17:28:49Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_SHAPETOPROUND_H_
#define _OPENCITY_SHAPETOPROUND_H_ 1

#include "shape.h"

namespace MapGen
{


//========================================================================
/** Apply bubble shape
*/
class ShapeTopRound: public Shape {
public:
	ShapeTopRound( const uint w, const uint h, const float base, const float rude, const uint l );
	virtual ~ShapeTopRound();

	float value( const uint x, const uint y ) const;

private:
	uint		_w2;
	uint		_h2;
	uint		_c;
	float		_base;
	float		_rude;
	uint		_l;

};


}

#endif

/***************************************************************************
						mapmaker.h    -  description
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

#ifndef _OPENCITY_MAPMAKER_H_
#define _OPENCITY_MAPMAKER_H_ 1

#include "map.h"

#include "generator/generator.h"
#include "filter/filter.h"
#include <vector>
using std::vector;

namespace MapGen
{

/**
	Map generators and filters interface
*/
class MapMaker {
public:
	enum MAP_TYPE {
		PLAIN = 0,
		HILL,
		MOUNTAIN
	};

	enum WATER_TYPE {
		DRY = 0,
		LAKE,
		COAST,
		ISLAND
	};

	enum TREE_DENSITY_TYPE {
		SPARSE = 0,
		NORMAL,
		DENSE
	};

	MapMaker(
		const uint w,
		const uint h,
		const MAP_TYPE mapType,
		const WATER_TYPE waterType,
		const TREE_DENSITY_TYPE treeDensityType );

	~MapMaker();

	int* getMap();
	int* getTreeDensity();

private:
	uint		_w;
	uint		_h;

	MAP_TYPE	_mapType;
	WATER_TYPE	_waterType;
	Map*		_map;

	TREE_DENSITY_TYPE	_treeDensityType;
	Map*		_treeDensity;


   /*=====================================================================*/
   /*                         PRIVATE     METHODS                         */
   /*=====================================================================*/
	Map* _generate(
    		const Generator* generator,
    		vector<Filter*> filters ) const;

	void _generateMap();

	void _generateTreeDensity();

};

}

#endif

/***************************************************************************
						renderer.h  -  description
							-------------------
	begin                : jeu mai 29 2003
	copyright            : (C) 2003-2006 by Duong-Khang NGUYEN
	email                : neoneurone @ users sourceforge net
	
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

#ifndef _OPENCITY_RENDERER_H_
#define _OPENCITY_RENDERER_H_ 1

#include "main.h"


// OpenGL viewport default parameters
#define OC_VIEW_ANGLE		50.0
#define OC_Z_NEAR			0.1
#define OC_Z_NEAR_ORTHO		-1000
#define OC_Z_FAR			1000.0

// OpenGL projection type paramaters
#define OC_PERSPECTIVE		1
#define OC_ORTHOGONAL		2


class Layer;
class Map;


//========================================================================
/** Deal with the OpenGL library to render game's objects. This class
	shouldn't play with SDL functions but OpenGL
*/
class Renderer
{
public:

	Renderer(
		const uint & cityW, const uint & cityH,
		const bool & rcboolUseDL );

	~Renderer(  );


	void RotateLeft( const uint & factor = 1 );
	void RotateRight( const uint & factor = 1 );
	void MoveLeft( const uint & factor = 1 );
	void MoveRight( const uint & factor = 1 );
	void MoveUp( const uint & factor = 1 );
	void MoveDown( const uint & factor = 1 );

//========================================================================
/** Reinit the map's position as if the game has just been launched
*/
	void Home();

	void ZoomIn(  );
	void ZoomOut(  );

/* TOKILL, unused 6 august 06
	void SetGrid( const bool & rcbState );
*/
	void ToggleGrid();
	void ToggleCompass();
	void ToggleProjection();
	void ToggleWireFrame();

//========================================================================
/** Display the splash screen at the specified coordinates
*/
	void
	DisplaySplash(
		const uint & rcuiX = 0,
		const uint & rcuiY = 0 ) const;


//========================================================================
/** Display the layer and the map to the back buffer. The caller must
	swap the buffers to show the changes
*/
	void
	Display(
		const Map* pcMap,
		const Layer* pcLayer );


	void
	DisplayHighlight(
		const Map* pcMap,
		const Layer* pcLayer,
		const OPENCITY_TOOL_CODE & enumTool );


	void
	DisplayHighlight(
		const Map* pcMap,
		const Layer* pcLayer,
		uint uiW1,
		uint uiL1,
		uint uiW2,
		uint uiL2,
		const OPENCITY_TOOL_CODE & enumTool );


//========================================================================
/** Display the specified graphic code with a bounding rectangle
*/
	void DisplayBuildPreview(
		const uint & uiW,
		const uint & uiL,
		const GLubyte & rcubR,
		const GLubyte & rcubG,
		const GLubyte & rcubB,
		const OPENCITY_GRAPHIC_CODE & gcode ) const;


	void
	DisplaySelection(
		const Map* pcMap,
		const Layer* pcLayer );


	void
	DisplaySelection(
		const Map* pcMap,
		const Layer* pcLayer,
		const uint & rcuiW1,
		const uint & rcuiL1,
		const uint & rcuiW2,
		const uint & rcuiL2 );


//========================================================================
	void
	DisplayText(
		const uint & rcuiX,
		const uint & rcuiY,
		const GLubyte & rcubR,
		const GLubyte & rcubG,
		const GLubyte & rcubB,
		const string & rcText );


	const bool
	GetSelectedWHFrom(
		const uint & rcuiMouseX,
		const uint & rcuiMouseY,
		uint & ruiW,
		uint & ruiL,
		const Map* pcMap,
		const Layer* pcLayer );


	const bool
	GetSelectedWHFrom(
		const uint & rcuiMouseX,
		const uint & rcuiMouseY,
		uint & ruiW,
		uint & ruiL,
		const Map* pcMap,
		const Layer* pcLayer,
		const uint & rcuiW1,
		const uint & rcuiL1,
		const uint & rcuiW2,
		const uint & rcuiL2 );


//========================================================================
/** This method _must_ be called whenever the window's size changes. It
	calculates the viewport and set the correct internal window's width
	and height
*/
	void SetWinSize(
		const int & rciWidth,
		const int & rciHeight );


//========================================================================
/** The City class use this to notify the renderer class that the 
	height of the map has changed and the current buffered informations
	need to be recalculated
*/
	bool boolHeightChange;


private:
	bool bDisplayGrid;
	bool bDisplayCompass;
	bool bWireFrame;
	OC_UBYTE ubProjectionType;
	GLfloat fScaleRatio;
	GLfloat fXTransDelta;	///< The delta used for translation in the X direction
	GLfloat fZTransDelta;

	GLdouble dEyeX;			///< kept for the future when the user can
	GLdouble dEyeY;			///< move the eye's coordinates
	GLdouble dEyeZ;

// GL display lists
	bool boolUseDisplayList;
	GLuint uiGridList;		///< GL list of the grid
	GLuint uiFontBase;		///< The base font list index
	GLuint _uiTerrainList;	///< GL list of the terrain

// Terrain Texture
	GLuint uiTerrainTex;


/** Contains the X value for the translation of the layer. It is used by
	MoveLeft() and MoveRight()
   */
	GLdouble dDeltaX;

/** Contains the Z value for the translation. It is used by
	MoveUp() and MoveDown()
*/
	GLdouble dDeltaZ;

/// used for calculating the rotation of the map
	GLdouble dYRotateAngle;
	GLdouble dmatrixRotate[16];

/// used for calculating the viewport & the perspective ratio
	int iWinHeight;
	int iWinWidth;

/// The city width & height
	uint uiCityWidth;
	uint uiCityHeight;

/// pointer to the screen SDL display surface
	SDL_Surface* psurfaceScreen;

   /*=====================================================================*/
   /*                        PRIVATE     METHODS                          */
   /*=====================================================================*/
/** Draw the terrain as an _unique_ TRIANGLE_STRIP which is known
	as the fastest primitive in OpenGL. It starts at the north-west and
	when it reaches the north-east map edge, it starts drawing from
	the north-east to the north-west eadge. Finally the algorithm
	draws from the north to the south.
*/
	void _DisplayTerrain() const;


//========================================================================
/** Draw the dotted grid. This method uses OpenGL display list inside.
*/
	void
	_DisplayMapGrid(
		const Map* pcmap );


	void _DisplayCompass() const;

	void _DisplayStatusBar() const;


//========================================================================
/** Prepare the world before drawing the entire scene
*/
	void _PrepareView() const;

};

#endif





























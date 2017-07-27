//***************************************************************************************
//
// File supervisor: Softimage Rendering & Pipeline team
//
// (c) Copyright 2001-2005 Avid Technology, Inc. . All rights reserved.
//
//***************************************************************************************

/**************************************************************************************
THIS CODE IS PUBLISHED AS A SAMPLE ONLY AND IS PROVIDED "AS IS".
IN NO EVENT SHALL SOFTIMAGE, AVID TECHNOLOGY, INC. AND/OR THEIR RESPECTIVE
SUPPLIERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY
DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS CODE .

COPYRIGHT NOTICE. Copyright © 1999-2005 Avid Technology Inc. . All rights reserved. 

SOFTIMAGE is a registered trademark of Avid Technology Inc. or its subsidiaries 
or divisions. Windows NT is a registered trademark of Microsoft Corp. All other
trademarks contained herein are the property of their respective owners. 
****************************************************************************************/


/*! \file COLLADAMaterialLibrary.h
/*!
	COLLADA material library class definition
*/

#ifndef COLLADAMATERIALLIBRARY_H
#define COLLADAMATERIALLIBRARY_H

#include "MaterialLibrary.h"


class CSLCOLLADAMaterial;
class CSLCOLLADAFX;

/** 
* CSLCOLLADAMaterialLibrary class
* Handles the material library. From this class you can add or remove materials that can be used
* in the scene.
*/

class XSIEXPORT CSLCOLLADAMaterialLibrary : public CSLMaterialLibrary
{
public:
	///////////////////////////////////////////////////////////////////////////
	// Construction/destruction
	///////////////////////////////////////////////////////////////////////////
	CSLCOLLADAMaterialLibrary(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
	virtual ~CSLCOLLADAMaterialLibrary();
	
	/*!	Add a new XSI material to the material library.
		\return	CSLXSIMaterial*	Pointer to the newly created XSI material object.
	*/
	virtual CSLXSIMaterial* AddXSIMaterial();

};


#endif // COLLADAMATERIALLIBRARY_H

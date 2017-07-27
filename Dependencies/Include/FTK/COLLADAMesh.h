/****************************************************************************************
THIS CODE IS PUBLISHED AS A SAMPLE ONLY AND IS PROVIDED "AS IS".
IN NO EVENT SHALL SOFTIMAGE, AVID TECHNOLOGY, INC. AND/OR THEIR RESPECTIVE 
SUPPLIERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY
DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS CODE . 
 
COPYRIGHT NOTICE. Copyright © 1999-2002 Avid Technology Inc. . All rights reserved. 

SOFTIMAGE is a registered trademark of Avid Technology Inc. or its subsidiaries 
or divisions. Windows NT is a registered trademark of Microsoft Corp. All other
trademarks contained herein are the property of their respective owners. 
****************************************************************************************/

#ifndef _COLLADAMESH_H
#define _COLLADAMESH_H

#include "Template.h"
#include "Logger.h"
#include "Scene.h"
#include "COLLADATemplate.h"
#include "Model.h"
#include "XSIMesh.h"
#include "COLLADAShape.h"
#include "COLLADAScene.h"
#include "COLLADAVertexList.h"

/** 
* CSLCOLLADAModel Class
* 
*/

class XSIEXPORT CSLCOLLADAMesh : public CSLXSIMesh
{
public:
	///////////////////////////////////////////////////////////////////////////
	// Construction/destruction
	///////////////////////////////////////////////////////////////////////////
	CSLCOLLADAMesh(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
	virtual ~CSLCOLLADAMesh();

	virtual CSLXSITriangleList*				AddXSITriangleList();
	virtual CSLXSIPolygonList* 				AddXSIPolygonList();

	SI_Error	CreateXSITriangleList(CCOLLADATemplate* in_pContainer);
	SI_Error	CreateXSIPolygonList(CCOLLADATemplate* in_pContainer);

	/*! Create a new shape animation for the geometry.
	* \param	EFCurveInterpolationType	Type of interpolation for the new shape animation.
	* \return CSLXSIShapeAnimation*	Pointer to the newly created shape animation.
	*/
	virtual CSLXSIShapeAnimation*	CreateXSIShapeAnimation(EFCurveInterpolationType in_Type);

	virtual SI_Error				Fix();
	virtual SI_Error				Synchronize();

protected:

	CCOLLADATemplate*	m_pMeshContainerTemplate;
	CCOLLADATemplate*	m_pVerticesTemplate;
	CdotXSIParam*		m_pVertexIDParam;
	CdotXSIParam*		m_pSourceParam;
public:

};

#endif

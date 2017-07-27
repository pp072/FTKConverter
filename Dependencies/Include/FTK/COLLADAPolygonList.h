//***************************************************************************************
//
// File supervisor: Softimage 3D Games & 3D Bridge team
//
// (c) Copyright 2001-2005 Avid Technology, Inc. . All rights reserved.
//
//***************************************************************************************

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

#ifndef _COLLADAPOLYGONLIST_H
#define _COLLADAPOLYGONLIST_H

#include "XSIPolygonList.h"
#include "XSISubComponentList.h"
#include "COLLADATemplate.h"
#include "Material.h"


class XSIEXPORT CSLCOLLADAPolygonList
	: public CSLXSIPolygonList
{
public:
	/*! Constructor	
	* \param in_pScene Parent scene
	* \param in_pModel Parent model
	* \param in_pTemplate Refered template
	* \return an instance of CSLXSITriangleList
	*/
	CSLCOLLADAPolygonList(CSLScene *in_pScene, 
							CSLModel *in_pModel, 
							CdotXSITemplate *in_pTemplate, 
							CCOLLADATemplate *in_pCOLLADATemplate,
							CCOLLADATemplate *in_pVertexDef);

	/*! Destructor
	*/
	virtual ~CSLCOLLADAPolygonList();

	/*!	Add a new index list. If one already exists, it is deleted and replaced.
	* \return	CSLXSIIndexList*	Pointer to the newly created index list.
	*/
	virtual CSLXSIIndexList*	AddIndexList();

	virtual SI_Error Synchronize();

	/*! GetInputSemantics - Returns all input semantics used by this polylist
	* \return CdotXSITemplates*
	*/
	virtual CdotXSITemplates* GetInputSemantics();

protected:

	CCOLLADATemplate	*m_szTemplate;
	CCOLLADATemplate	*m_szSemantic;
	CdotXSIParam*		m_pSource;
	CdotXSIParam*		m_pCount;
	CdotXSIParam*		m_pAttribMaterial;
};

#endif

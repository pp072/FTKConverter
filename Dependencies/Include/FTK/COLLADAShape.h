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

#ifndef _COLLADASHAPE_H
#define _COLLADASHAPE_H

#include "Template.h"
#include "Logger.h"
#include "Scene.h"
#include "COLLADATemplate.h"
#include "Model.h"
#include "XSIShape.h"
#include "COLLADAScene.h"
#include "COLLADASubComponentAttributeList.h"

/** 
* CSLCOLLADAShape Class
* 
*/
class CSLCOLLADAMesh;

class XSIEXPORT CSLCOLLADAShape : public CSLXSIShape
{
public:
	///////////////////////////////////////////////////////////////////////////
	// Construction/destruction
	///////////////////////////////////////////////////////////////////////////
	CSLCOLLADAShape(CSLScene* in_pScene, 
					CSLModel *in_pModel, 
					CdotXSITemplate* in_pTemplate, 
					CCOLLADATemplate* in_pVerticesDecl,
					CdotXSITemplates* in_pInputSemantics);
	virtual ~CSLCOLLADAShape();

	virtual SI_Error Synchronize();

	virtual CSLXSISubComponentAttributeList*	AddAttributeList(CSLXSISubComponentAttributeList::EAttributeType in_AttributeType);

	virtual void			SetParentMesh(CSLCOLLADAMesh* in_pCOLLADAMesh);
	virtual CSLCOLLADAMesh*	GetParentMesh();
protected:

	CCOLLADATemplate*	m_pVerticesDecl;

private:
	CSLCOLLADAMesh*		m_pParentMesh;
	bool				m_bSynchronized;

public:

};

#endif

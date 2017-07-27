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

#ifndef _COLLADASUBCOMPONENTATTRIBUTELIST_H
#define _COLLADASUBCOMPONENTATTRIBUTELIST_H

#include "COLLADATemplate.h"
#include "XSISubComponentAttributeList.h"


//! Sub-component attribute list class for dotXSI 5.0+
/** 
* Describes a sub-component attribute list
*
* The CSLXSISubComponentAttributeList holds a list of values for a specific attribute of a given type and semantic.
*
* This class allows an attribute (position, normal, color, texcoord, etc.) to be associated with vertices or polynodes.
*/
class XSIEXPORT CSLCOLLADASubComponentAttributeList
	: public CSLXSISubComponentAttributeList
{
public:
	
	CSLCOLLADASubComponentAttributeList(CSLScene *in_pScene, CSLModel *in_pModel, CdotXSITemplate *in_pTemplate);

	/*! Destructor
	*/
	virtual ~CSLCOLLADASubComponentAttributeList();
	virtual SI_Void		SetAttributeType(EAttributeType in_AttributeType);
	virtual SI_Char*	GetSemantic() { return m_szSemantic.GetText(); };
	virtual SI_Void		SetSemantic(SI_Char* in_Semantic) { m_szSemantic.SetText(in_Semantic);};
	virtual SI_Char*	GetSource() { return m_pMainID->GetVariantPtr()->p_cVal; };

	virtual SI_Error	Synchronize();
	
	SI_Void	SetVerticesDeclarationTemplate( CCOLLADATemplate* in_pDecl );
	SI_Void SetInputSemantics ( CdotXSITemplates* in_pTemplates );

private:
	CCOLLADATemplate* m_pAttributeArrayTemplate;
	CCOLLADATemplate *m_accessor ;
	CCOLLADATemplate*	m_pVertexDeclarationTemplate;
	CSIBCString m_szSemantic;

	CdotXSIParam*	m_pCountAttribute;
	CdotXSIParam*	m_pIDAttribute;

	CdotXSIParam*	m_pInnerCountAttribute;
	CdotXSIParam*	m_pStrideCountAttribute;
	CdotXSIParam*	m_pSourceIDAttribute;

	CdotXSIParam*	m_pMainID;
	CdotXSIParam*	m_pAttribArray;
};

#endif

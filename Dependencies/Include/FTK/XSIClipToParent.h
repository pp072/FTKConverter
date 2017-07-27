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
#ifndef _XSICLIPTOPARENT_H
#define _XSICLIPTOPARENT_H

#include "Template.h"

/** 
* Class CSLClipToParent
*
* Defines clip to parent properties
* \note This template was introduced in dotXSI Version 6.0
*/

class XSIEXPORT CSLXSIClipToParent
    : public CSLTemplate
{
public:
	/*! Constructor
		\param in_pScene Parent scene
		\param in_pModel Parent model
		\param in_pTemplate Refered template
	*/
	CSLXSIClipToParent(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);

	//! Destructor
	virtual ~CSLXSIClipToParent();

    virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);

	virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szParameterName);

	/*! Returns the type of this template
		\retval CSLTemplate::XSI_EXTRAPOLATION
	*/
	CSLTemplate::ETemplateType Type(){ return CSLTemplate::XSI_CLIP_TO_PARENT; }

	/*! Get the Start value
		\return SI_Bool	Start
	*/
	SI_Bool GetStart();

	/*! Set the Start value
		\param	SI_Bool	new Start value
	*/
	SI_Void SetStart( SI_Bool in_bValue );

    CSLBoolProxy* 	GetStartProxy() { return &m_Start; };

	/*! Get the End value
		\return SI_Bool	End
	*/
	SI_Bool GetEnd();

	/*! Set the End value
		\param	SI_Bool	new End value
	*/
	SI_Void SetEnd( SI_Bool in_bValue );

    CSLBoolProxy* 	GetEndProxy() { return &m_End; };

private:
    CSLBoolProxy	m_Start;
    CSLBoolProxy	m_End;

	SI_Void			*m_pReserved;
};

#endif

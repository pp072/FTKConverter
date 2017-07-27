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
#ifndef _XSIUSERKEYWORD_H
#define _XSIUSERKEYWORD_H

#include "Template.h"

/** 
* Class CSLXSIUserKeyword
*
* UserKeyword string
* \note This template was introduced in dotXSI Version 6.0
*/

class XSIEXPORT CSLXSIUserKeyword
    : public CSLTemplate
{
public:
	/*! Constructor
		\param in_pScene Parent scene
		\param in_pModel Parent model
		\param in_pTemplate Refered template
	*/
	CSLXSIUserKeyword(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);

	//! Destructor
	virtual ~CSLXSIUserKeyword();

	/*! Gets the type of this template
		\return ETemplateType The type of this template (XSI_USER_KEYWORD)
	*/
	ETemplateType Type(){ return XSI_USER_KEYWORD; }

	/*! Get the user keyword string list
		\return SI_Char*	UserKeyword
	*/
    SI_Char* GetList();

	/*! Set the user keyword string list value
		\param	SI_Char*	new UserKeyword value
	*/
	SI_Void SetList( SI_Char* in_pValue);

    CSLStringProxy* 									GetListProxy() { return &m_List; };

private:
    CSLStringProxy	m_List;

	SI_Void *m_pReserved;
};

#endif

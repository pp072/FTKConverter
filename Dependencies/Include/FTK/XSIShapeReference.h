//***************************************************************************************
//
// File supervisor: Softimage 3D Games & 3D Bridge team
//
// (c) Copyright 2001-2002 Avid Technology, Inc. . All rights reserved.
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


#ifndef _XSISHAPEREFERENCE_H
#define _XSISHAPEREFERENCE_H

#include "Template.h"

// Forward declaration
class CSLXSIShape;

/*! An shape reference is a pointer to an existing shape defined else where in the file.
    This is used in shape key actions (CSLAction) so that the associated shape key (CSLXSIShape)
	can be identified.

	\sa CSLAction
	\sa CSLMixer
	\sa CSLTimeControl
	\sa CSLTrack
	\sa CSLXSIShape
	\sa CSLXSIShape
	\sa CSLXSIShapeAnimation
*/
class XSIEXPORT CSLXSIShapeReference
    : public CSLTemplate
{
public:

	/*! Constructor
		\param in_pScene	Pointer to the scene containing the ActionClip
		\param in_pModel	Pointer to the model containing the ActionClip
		\param in_pTemplate	Pointer to the CdotXSITemplate defining the ActionClip
	*/
    CSLXSIShapeReference(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);

	/*! Destructor
	*/
    virtual ~CSLXSIShapeReference();

	SI_Error Synchronize();

	/*! Gets the type of this template
		\return CSLTemplate::XSI_SHAPEREFERENCE
	*/
	CSLTemplate::ETemplateType Type(){ return CSLTemplate::XSI_SHAPEREFERENCE; }

	/*! Gets the referenced shape
		\retval Pointer to the referenced shape
		\retval NULL The referenced shape corresponding to the current XSI path was not found in the file.
	*/
	CSLXSIShape* GetReference();

	/*! Sets the referenced shape. Note, the XSI Path is not set automatically, you also need to use SetReferenceXSIPath.
		\param in_ReferenceShape The the referenced shape
	*/
	SI_Void				SetReference(CSLXSIShape* in_ReferenceShape);

	/*! Gets the XSI path of the referenced shape
		\return SI_Char The XSI Path of the referenced shape
	*/
	SI_Char*			GetReferenceXSIPath();

	/*! Sets the XSI path of the referenced shape
		\param in_szPath The XSI Path of the referenced shape
	*/
	SI_Void				SetReferenceXSIPath( SI_Char* in_szPath );

	/*! Gets the referenced shape XSI path proxy 
		\return CSLStringProxy* Pointer to the referenced shape XSI path proxy
	*/
	CSLStringProxy*		GetReferencePathProxy(){return &m_ReferencePath;};

private:
	CSLStringProxy m_ReferencePath;
	CSLXSIShape* m_pReference;
	SI_Void *m_pReserved;
};

#endif // XSISHAPEREFERENCE

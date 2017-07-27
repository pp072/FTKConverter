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

#ifndef _XSICAMERAFOCALLENGTH_H
#define _XSICAMERAFOCALLENGTH_H

#include "Template.h"

//! Base class representing XSICameraFocalLength
class XSIEXPORT CSLXSICameraFocalLength
	: public CSLTemplate
{
public:

	/*! Constructor
	* \param in_pScene	Pointer to the scene containing the Camera
	* \param in_pModel	Pointer to the model containing the Camera
	* \param in_pTemplate	Pointer to the CdotXSITemplate containing the Camera
	* \return an instance of CSLCamera
	*/
	CSLXSICameraFocalLength(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);

	/*! Destructor
	*/
	virtual ~CSLXSICameraFocalLength();

	/*! Return the camera projection plane distance.
	* \return SI_Float the camera projection plane distance.
	*/
	SI_Float GetFocalLength();

	/*! Change the camera projection plane distance.
	* \param SI_Float New camera projection plane distance.
	* \return SI_Void
	*/
	SI_Void SetFocalLength(SI_Float in_lValue);


	/*! Returns the type of this template (XSI_CAMERA_FOCALLENGTH)
		\return CSLTemplate::ETemplateType The type of this template (XSI_CAMERA_FOCALLENGTH)
	*/
	virtual ETemplateType			Type() { return XSI_CAMERA_FOCALLENGTH; }

	/*! Synchronizes this Camera instance with its IO layer representation
	* \return SI_Error
	* \retval SI_SUCCESS this function always returns SI_SUCCESS
	*/
    virtual SI_Error Synchronize();

	/*! Gets a handle on one of this Camera's parameters by using its name
	* \param in_szName the name of the parameter to get the handle from
	* \return CSLAnimatableType* the handle to the parameter
	*/
    virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);

	/*! Gets a handle on one of this Camera's parameters by using its type
	* \param in_szName the name of the parameter to get the handle from
	* \return CSLAnimatableType* the handle to the parameter
	*/
    virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szName);

	/*!	Return the name (string) of a specified sub parameter.
		\param	in_pParameter	The sub parameter
		\return	SI_Char*	Name of the sub parameter.
	*/
    virtual const SI_Char* GetParameterName(CSLAnimatableType* in_pParameter);

	CSLFloatProxy*	GetFocalLengthProxy() { return &m_FocalLength; };

private:

	CSLFloatProxy	m_FocalLength;

	void *m_pReserved;	// reserved for future extension
};

#endif

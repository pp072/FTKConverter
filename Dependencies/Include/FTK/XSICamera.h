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

#ifndef _XSICAMERA_H
#define _XSICAMERA_H

#include "Primitive.h"

class CSLXSICameraFocalLength;

//! Base class representing XSICamera, handles xsi shape animation functionality for dotXSI 5.0+.
class XSIEXPORT CSLXSICamera
	: public CSLPrimitive
{
public:

	/*! Constructor
	* \param in_pScene	Pointer to the scene containing the Camera
	* \param in_pModel	Pointer to the model containing the Camera
	* \param in_pTemplate	Pointer to the CdotXSITemplate containing the Camera
	* \return an instance of CSLCamera
	*/
	CSLXSICamera(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);

	/*! Destructor
	*/
	virtual ~CSLXSICamera();

	/*! Return the camera field of view dominance.
	* \return SI_Int the camera field of view dominance.
	*/
	SI_Int GetStandard();

	/*! Change the camera field of view dominance.
	* \param SI_Int New camera field of view dominance.
	* \return SI_Void
	*/
	SI_Void SetStandard(SI_Int in_lValue);

	/*! Return the camera picture ratio.
	* \return SI_Float the camera picture ratio.
	*/
	SI_Float GetPictureRatio();

	/*! Change the camera picture ratio.
	* \param SI_Float New camera picture ratio.
	* \return SI_Void
	*/
	SI_Void SetPictureRatio(SI_Float in_lValue);

	/*! Return the camera field of view.
	* \return SI_Float the camera field of view.
	*/
	SI_Float GetFieldOfView();

	/*! Change the camera field of view.
	* \param SI_Float New camera field of view.
	* \return SI_Void
	*/
	SI_Void SetFieldOfView(SI_Float in_lValue);

	/*! Return the camera field of view dominance.
	* \return SI_Int the camera field of view dominance.
	*/
	SI_Int GetFieldOfViewType();

	/*! Change the camera field of view dominance.
	* \param SI_Int New camera field of view dominance.
	* \return SI_Void
	*/
	SI_Void SetFieldOfViewType(SI_Int in_lValue);

	/*! Return the camera projection type.
	* \return SI_Int the camera projection type.
	*/
	SI_Int GetProjectionType();

	/*! Change the camera projection type.
	* \param SI_Int New camera projection type.
	* \return SI_Void
	*/
	SI_Void SetProjectionType(SI_Int in_lValue);

	/*! Return the camera orthographic height.
	* \return SI_Float the camera orthographic height.
	*/
	SI_Float GetOrthoHeight();

	/*! Change the camera orthographic height.
	* \param SI_Float New camera orthographic height.
	* \return SI_Void
	*/
	SI_Void SetOrthoHeight(SI_Float in_lValue);

	/*! Return the camera interest distance.
	* \return SI_Float the camera interest distance.
	*/
	SI_Float GetInterestDistance();

	/*! Change the camera interest distance.
	* \param SI_Float New camera interest distance.
	* \return SI_Void
	*/
	SI_Void SetInterestDistance(SI_Float in_lValue);

	/*! Return the camera near clipping plane.
	* \return SI_Float the camera near clipping plane.
	*/
	SI_Float GetNearPlane();

	/*! Change the camera near clipping plane.
	* \param SI_Float New camera near clipping plane.
	* \return SI_Void
	*/
	SI_Void SetNearPlane(SI_Float in_lValue);

	/*! Return the camera far clipping plane.
	* \return SI_Float the camera far clipping plane.
	*/
	SI_Float GetFarPlane();

	/*! Change the camera far clipping plane.
	* \param SI_Float New camera far clipping plane.
	* \return SI_Void
	*/
	SI_Void SetFarPlane(SI_Float in_lValue);

	/*! Return the camera projection plane.
	* \return SI_Bool the camera projection plane.
	*/
	SI_Bool GetProjectionPlaneEnable();

	/*! Change the camera projection plane.
	* \param SI_Int New camera projection plane.
	* \return SI_Void
	*/
	SI_Void SetProjectionPlaneEnable(SI_Bool in_lValue);

	/*! Return the camera projection plane width.
	* \return SI_Float the camera projection plane width.
	*/
	SI_Float GetProjPlaneWidth();

	/*! Change the camera projection plane width.
	* \param SI_Float New camera projection plane width.
	* \return SI_Void
	*/
	SI_Void SetProjPlaneWidth(SI_Float in_lValue);

	/*! Return the camera projection plane height.
	* \return SI_Float the camera projection plane height.
	*/
	SI_Float GetProjPlaneHeight();

	/*! Change the camera projection plane height.
	* \param SI_Float New camera projection plane height.
	* \return SI_Void
	*/
	SI_Void SetProjPlaneHeight(SI_Float in_lValue);

	/*! Return the camera projection plane offset X.
	* \return SI_Float the camera projection plane offset X.
	*/
	SI_Float GetProjPlaneOffsetX();

	/*! Change the camera projection plane offset X.
	* \param SI_Float New camera projection plane offset X.
	* \return SI_Void
	*/
	SI_Void SetProjPlaneOffsetX(SI_Float in_lValue);

	/*! Return the camera projection plane offset Y.
	* \return SI_Float the camera projection plane offset Y.
	*/
	SI_Float GetProjPlaneOffsetY();

	/*! Change the camera projection plane offset Y.
	* \param SI_Float New camera projection plane offset Y.
	* \return SI_Void
	*/
	SI_Void SetProjPlaneOffsetY(SI_Float in_lValue);

	/*! Returns the type of this template (XSI_CAMERA)
		\return CSLTemplate::ETemplateType The type of this template (XSI_CAMERA)
	*/
	virtual ETemplateType			Type() { return XSI_CAMERA; }

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

	CSLIntProxy*	GetStandardProxy() { return &m_Standard;};
	CSLFloatProxy*	GetPictureRatioProxy() { return &m_PictureAspect;};
	CSLFloatProxy*	GetFieldOfViewProxy() { return &m_Fov;};
	CSLIntProxy*	GetFieldOfViewTypeProxy() { return &m_FovType;};
	CSLIntProxy*	GetProjectionTypeProxy() { return &m_ProjType;};
	CSLFloatProxy*	GetOrthoHeightProxy() { return &m_OrthoHeight;};
	CSLFloatProxy*	GetInterestDistanceProxy() { return &m_InterestDistance;};
	CSLFloatProxy*	GetNearPlaneProxy() { return &m_NearPlane;};
	CSLFloatProxy*	GetFarPlaneProxy() { return &m_FarPlane;};
	CSLBoolProxy*	GetProjectionPlaneEnableProxy() { return &m_useProjPlane;};
	CSLFloatProxy*	GetProjPlaneWidthProxy() { return &m_ProjPlaneWidth;};
	CSLFloatProxy*	GetProjPlaneHeightProxy() { return &m_ProjPlaneHeight;};
	CSLFloatProxy*	GetProjPlaneOffsetXProxy() { return &m_ProjPlaneOffsetX;};
	CSLFloatProxy*	GetProjPlaneOffsetYProxy() { return &m_ProjPlaneOffsetY;};

	CSLXSICameraFocalLength*	CreateXSICameraFocalLength();
	CSLXSICameraFocalLength*	GetXSICameraFocalLength();
	CSLXSICameraFocalLength*	ConnectXSICameraFocalLength(CSLXSICameraFocalLength* in_pToConnect);

private:

	CSLIntProxy		m_Standard;
	CSLFloatProxy	m_PictureAspect;
	CSLFloatProxy	m_Fov;
	CSLIntProxy		m_FovType;
	CSLIntProxy		m_ProjType;
	CSLFloatProxy	m_OrthoHeight;
	CSLFloatProxy	m_InterestDistance;
	CSLFloatProxy	m_NearPlane;
	CSLFloatProxy	m_FarPlane;
	CSLBoolProxy	m_useProjPlane;
	CSLFloatProxy	m_ProjPlaneWidth;
	CSLFloatProxy	m_ProjPlaneHeight;
	CSLFloatProxy	m_ProjPlaneOffsetX;
	CSLFloatProxy	m_ProjPlaneOffsetY;
	CSLXSICameraFocalLength*	m_pXSICameraFocalLength;

	void *m_pReserved;	// reserved for future extension
};

#endif

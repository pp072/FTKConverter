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

#ifndef _COLLADAACTION_H
#define _COLLADAACTION_H

#include "Action.h"
#include "ActionFCurve.h"

/*! Actions, also known as action sources, are reusable animation segments. 
	They can be created with the CSLMixer::AddAction method and instanciated
	in the mixer's tracks (CSLTrack) as action clips (CSLActionClip).

	\note Actions are not supported by SI3D

	\sa CSLActionClip
	\sa CSLActionFCurve
	\sa CSLMixer
	\sa CSLShapeAnimation
	\sa CSLStaticValue
*/
class XSIEXPORT CSLCOLLADAAction
    : public CSLAction
{
public:
	/*! Constructor
		\param in_pScene	Pointer to the scene containing the CSLAction
		\param in_pModel	Pointer to the model containing the CSLAction
		\param in_pTemplate	Pointer to the CdotXSITemplate defining the CSLAction data
	*/
    CSLCOLLADAAction(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);

	/*! Destructor
	*/
    virtual ~CSLCOLLADAAction();

	/*! Synchronizes internal data to be coherent with the IO layer
		\return success or failure
	*/
	virtual SI_Error Synchronize();

	/*! Fixes internal data to be coherent with the IO layer at creation time
		\return success or failure
	*/
	virtual SI_Error Fix();

	/*! Gets the end time
		\return The end time
	*/
	virtual SI_Float GetEndTime();

	/*! Sets the end time of the action
		\param in_fTime The end time
	*/
	virtual SI_Void SetEndTime( SI_Float in_fTime );

	/*! Gets the start time of the action
		\return The start time
	*/
	virtual SI_Float GetStartTime();

	/*! Sets the start time of the action
		\param in_fTime The new start time
	*/
	virtual SI_Void SetStartTime( SI_Float in_fTime );

	/*! Adds a new animation with default interpolation ( constant interpolation )
		\return Pointer to the newly added Animation
	*/
	virtual CSLActionFCurve* AddAnimation();

	/*! Adds a new animation
		\param in_InterpolationType FCurve interpolation type
		\return Pointer to the newly added Animation
	*/
	virtual CSLActionFCurve* AddAnimation( EFCurveInterpolationType in_InterpolationType );

private:
	
	SI_Void *m_pReserved;
	CdotXSIParam *m_pStart;
	CdotXSIParam *m_pEnd;

};

#include "BaseFCurve.h"

/*! Wraps all functionality for an FCurve used in a mixer.
	\sa CSLMixer
	\sa CSLAction
*/
class XSIEXPORT CSLCOLLADAActionFCurve
    : public CSLActionFCurve
{
public:

	/*! Constructor
		\param in_pScene	Pointer to the scene containing the ActionFCurve
		\param in_pModel	Pointer to the model containing the ActionFCurve
		\param in_pTemplate	Pointer to the CdotXSITemplate containing the ActionFCurve
		\param in_InterpolationType	FCurve interpolation type
		\param in_pParamReference the animation parameter to connect to
	*/
    CSLCOLLADAActionFCurve(CSLScene* in_pScene,
						 CSLModel *in_pModel,
						 CdotXSITemplate* in_pTemplate,
						 EFCurveInterpolationType in_InterpolationType);

	/*! Destructor
	*/
	virtual ~CSLCOLLADAActionFCurve();

	/*! Synchronizes internal data to be coherent with the IO layer
		\return success or failure
	*/
	virtual SI_Error Synchronize();
  
	/*! Connects an existing COLLADA animation template
	* \param in_offset	Offset when reading data. Needed to synchronized with stride attribut
	* \return SI_Error
	*/
    virtual SI_Error ConnectCOLLADAAnimation( CCOLLADATemplate* in_pChannel, const int in_offset = 0);

	/*! Returns the parameter reference
	* \return the parameter reference
	*/

	virtual CSLAnimatableType* ParameterReference();

private:

	SI_Void		GetFloatArrayFromCurve ( CSIBCArray<float>& inout_Array, int in_iElement );
	SI_Void		AddSource ( CCOLLADATemplate* in_pAnimation, 
							int in_iElement, 
							SI_Char* in_szPrefix, 
							SI_Char* in_szID, 
							SI_Char* in_szOutput,
							CCOLLADATemplate* in_pSampler);
	
	CSLAnimatableType *m_pParamReference;
	SI_Void *m_pReserved;
};


#endif _COLLADAACTION_H
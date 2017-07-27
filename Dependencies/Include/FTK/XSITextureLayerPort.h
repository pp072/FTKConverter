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
#ifndef _XSITEXTURELAYERPORT_H
#define _XSITEXTURELAYERPORT_H

#include "Template.h"

/** 
* Class CSLXSITextureLayerPort
*
* Defines texture layer port
* \note This template was introduced in dotXSI Version 6.0
*/

class XSIEXPORT CSLXSITextureLayerPort
    : public CSLTemplate
{
public:
	/*! Constructor
		\param in_pScene Parent scene
		\param in_pModel Parent model
		\param in_pTemplate Refered template
	*/
	CSLXSITextureLayerPort(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);

	//! Destructor
	virtual ~CSLXSITextureLayerPort();

	/*! Gets the type of this template
		\return ETemplateType The type of this template (XSI_IMAGE_FX)
	*/
	ETemplateType Type(){ return XSI_TEXTURE_LAYER_PORT; }

    virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);

	virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szParameterName);


	/*! Get the Target value
		\return SI_Char*	Target
	*/
	SI_Char* GetTarget();

	/*! Set the Target value
		\param	SI_Char*	new Target value
	*/
	SI_Void SetTarget( SI_Char* in_pValue );

	/*! Get the Mute value
		\return SI_Bool	Exposure
	*/
	SI_Bool GetMute();

	/*! Set the Mute value
		\param	SI_Bool	new Mute value
	*/
	SI_Void SetMute( SI_Bool in_bValue );

	/*! Get the Scale value
		\return SI_Float	Scale
	*/
	SI_Float GetScale();

	/*! Set the Scale value
		\param	SI_Float	new Scale value
	*/
	SI_Void SetScale( SI_Float in_fValue );

	/*! Get the ColorSource value
		\return SI_Int	ColorSource
	*/
	SI_Int GetColorSource();

	/*! Set the ColorSource value
		\param	SI_Int	new ColorSource value
	*/
	SI_Void SetColorSource( SI_Int in_nValue );

	/*! Get the Invert value
		\return SI_Bool	Invert
	*/
    SI_Bool GetInvert();

	/*! Set the Invert value
		\param	SI_Bool	new RenderColorProfile value
	*/
	SI_Void SetInvert( SI_Bool in_bValue);


	CSLStringProxy* 									GetTargetProxy()		{ return &m_Target; };
	CSLBoolProxy* 										GetMuteProxy()			{ return &m_Mute; };
    CSLFloatProxy* 										GetScaleProxy()			{ return &m_Scale; };
	CSLIntProxy*										GetColorSourceProxy()	{ return &m_ColorSource; };
    CSLBoolProxy*										GetInvertProxy()		{ return &m_Invert; };

private:
    CSLStringProxy	m_Target;
    CSLBoolProxy	m_Mute;
    CSLFloatProxy	m_Scale;
	CSLIntProxy		m_ColorSource;
    CSLBoolProxy	m_Invert;

	SI_Void *m_pReserved;
};

#endif

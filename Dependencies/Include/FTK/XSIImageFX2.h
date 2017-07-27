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
#ifndef _XSIIMAGEFX2_H
#define _XSIIMAGEFX2_H

#include "Template.h"
class CSLImage;

/**
* Class CSLImageFX2
*
* Defines more image effects
* \note This template was introduced in dotXSI Version 6.0
*/

class XSIEXPORT CSLImageFX2
    : public CSLTemplate
{
public:
	//! Defines the various scaling types
	enum EImageDefinitionType
	{
		SI_LOAD_IN_MEMORY,	/*!< 0-Load in memory */
		SI_USE_FROM_DISK,	/*!< 1-Use from disk */
		SI_BROADCAST,		/*!< 2-Broadcast */
	};

	/*! Defines the kind of optimization that will be used to smooth
	textures that are far from or near to the camera (OGL MipMapping).
	*/
	enum EOglFilter
	{
		SI_UNINTERPOLATED_PIXEL = 9728,							/*!< Uninterpolated pixel (quickest but lowest-quality optimization) */
		SI_INTERPOLATED_PIXEL = 9729,							/*!< Interpolated pixel (slowest but best-quality optimization for Texture Magnification Filter (Near) */
		SI_UNINTERPOLATED_PIXEL_NEAREST_MIPMAP = 9984,			/*!< Uninterpolated pixel using Nearest MipMap resolution. \note Only available for Texture Minification (Far) */
		SI_INTERPOLATED_PIXEL_NEAREST_MIPMAP = 9985,			/*!< Interpolated pixel using Nearest MipMap resolution. \note Only available for Texture Minification (Far) */
		SI_UNINTERPOLATED_PIXEL_INTERPOLATED_MIPMAP = 9986,		/*!< Uninterpolated pixel using Interpolated MipMap resolution. \note Only available for Texture Minification (Far) */
		SI_INTERPOLATED_PIXEL_INTERPOLATED_MIPMAP = 9987		/*!< Interpolated pixel using Interpolated MipMap resolution (slowest but best-quality optimization). \note Only available for Texture Minification (Far) */
	};

	//! Specifies the field order for video images clips.
	enum EFieldType
	{
		SI_NONE,	/* None */
		SI_ODD,		/* Upper Field First / Odd (PAL and HD Formats) */
		SI_EVEN		/* Lower Field First / Even (NTSC and DVFormats) */
	};

	/*! Constructor
		\param in_pScene Parent scene
		\param in_pModel Parent model
		\param in_pTemplate Refered template
	*/
	CSLImageFX2(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);

	//! Destructor
	virtual ~CSLImageFX2();

	/*! Gets the type of this template
		\return ETemplateType The type of this template (XSI_IMAGE_FX)
	*/
	ETemplateType Type(){ return XSI_IMAGE_FX2; }

    virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);

	virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szParameterName);



	/*! Get the Exposure value
		\return SI_Float	Exposure
	*/
	SI_Float GetExposure();

	/*! Set the Exposure value
		\param	SI_Float	new Exposure value
	*/
	SI_Void SetExposure( SI_Float in_fValue );

	/*! Get the DisplayGamma value
		\return SI_Float	DisplayGamma
	*/
	SI_Float GetDisplayGamma();

	/*! Set the DisplayGamma value
		\param	SI_Float	new DisplayGamma value
	*/
	SI_Void SetDisplayGamma( SI_Float in_fValue );

	/*! Get the DisplayGammaAffectsRendering value
		\return SI_Bool	DisplayGammaAffectsRendering
	*/
	SI_Bool GetDisplayGammaAffectsRendering();

	/*! Set the DisplayGammaAffectsRendering value
		\param	SI_Bool	new DisplayGammaAffectsRendering value
	*/
	SI_Void SetDisplayGammaAffectsRendering( SI_Bool in_bValue );

	/*! Get the RenderColorProfile value
		\return SI_Char*	RenderColorProfile
	*/
    SI_Char* GetRenderColorProfile();

	/*! Set the RenderColorProfile value
		\param	SI_Char*	new RenderColorProfile value
	*/
	SI_Void SetRenderColorProfile( SI_Char* in_pValue);

	/*! Get the RenderGamma value
		\return SI_Float	RenderGamma
	*/
    SI_Float GetRenderGamma();

	/*! Set the RenderGamma value
		\param	SI_Float	new RenderGamma value
	*/
	SI_Void SetRenderGamma( SI_Float in_fValue );

	/*! Get the ImageDefinitionType value
		\return EImageDefinitionType	ImageDefinitionType
	*/
	EImageDefinitionType GetImageDefinitionType();

	/*! Set the ImageDefinitionType value
		\param	EImageDefinitionType	new ImageDefinitionType value
	*/
	SI_Void SetImageDefinitionType( EImageDefinitionType in_Value );

	/*! Get the EnableMipMap radius value
		\return SI_Bool	EnableMipMap
	*/
	SI_Bool GetEnableMipMap();

	/*! Set the EnableMipMap radius value
		\param	SI_Bool	new EnableMipMap value
	*/
	SI_Void SetEnableMipMap( SI_Bool in_bValue );

	/*! Get the MipMapScale value
		\return SI_Float	MipMapScale
	*/
	SI_Float GetMipMapScale();

	/*! Set the MipMapScale value
		\param	SI_Float	new MipMapScale value
	*/
	SI_Void SetMipMapScale( SI_Float in_fValue );

	/*! Get the OglMaxSize value
		\return SI_Int	OglMaxSize
	*/
	SI_Int GetOglMaxSize();

	/*! Set the OglMaxSize value
		\param	SI_Int	new OglMaxSize value
	*/
	SI_Void SetOglMaxSize( SI_Int in_nValue );

	/*! Get the OglMipMap
		\return SI_Bool	OglMipMap
	*/
	SI_Bool GetOglMipMap();

	/*! Set the OglMipMap value
		\param	SI_Bool the new OglMipMap value
	*/
	SI_Void SetOglMipMap( SI_Bool in_Value );

	/*! Get the OglMinFilter value
		\return EOglFilter	OglMinFilter
	*/
	EOglFilter GetOglMinFilter();

	/*! Set the OglMinFilter value
		\param EOglFilter	OglMinFilter
	*/
	SI_Void SetOglMinFilter( EOglFilter in_Value );

	/*! Get the OglMagFilter value
		\return EOglFilter	OglMagFilter value
	*/
	EOglFilter GetOglMagFilter();

	/*! Set the OglMagFilter value
		\param EOglFilter	OglMagFilter
	*/
	SI_Void SetOglMagFilter( EOglFilter in_Value );

	/*! Get the FieldType value
		\return EFieldType	FieldType value
	*/
	EFieldType GetFieldType();

	/*! Set the FieldType value
		\param EFieldType	new FieldType value
	*/
	SI_Void SetFieldType( EFieldType in_Value );

	/*! Get the SourceTrack value
		\return SI_Int	SourceTrack value
	*/
	SI_Int GetSourceTrack();

	/*! Set the SourceTrack value
		\param SI_Int	new SourceTrack value
	*/
	SI_Void SetSourceTrack( SI_Int in_bValue );


    CSLFloatProxy*										GetExposureProxy() { return &m_Exposure; };
    CSLFloatProxy*										GetDisplayGammaProxy() { return &m_DisplayGamma; };
    CSLBoolProxy* 										GetDisplayGammaAffectsRenderingProxy() { return &m_DisplayGammaAffectsRendering; };

    CSLStringProxy* 									GetRenderColorProfileProxy() { return &m_RenderColorProfile; };
    CSLFloatProxy* 										GetRenderGammaProxy() { return &m_RenderGamma; };

	CSLEnumProxy<EImageDefinitionType, SI_BROADCAST>*	GetImageDefinitionTypeProxy() { return &m_ImageDefinitionType; };
    CSLBoolProxy* 										GetEnableMipMapProxy() { return &m_EnableMipMap; };
    CSLFloatProxy* 										GetMipMapScaleProxy() { return &m_MipMapScale; };

	CSLIntProxy*															GetOglMaxSizeProxy() { return &m_OglMaxSize; };
    CSLBoolProxy*															GetOglMipMapProxy() { return &m_OglMipMap; };
    CSLEnumProxy<EOglFilter, SI_INTERPOLATED_PIXEL_INTERPOLATED_MIPMAP>*	GetOglMinFilterProxy() { return &m_OglMinFilter; };
    CSLEnumProxy<EOglFilter, SI_INTERPOLATED_PIXEL>*						GetOglMagFilterProxy() { return &m_OglMagFilter; };

	CSLEnumProxy<EFieldType, SI_EVEN>* 					GetFieldTypeProxy() { return &m_FieldType; };
    CSLIntProxy* 										GetSourceTrackProxy() { return &m_SourceTrack; };

private:
	CSLFloatProxy	m_Exposure;
    CSLFloatProxy	m_DisplayGamma;
    CSLBoolProxy	m_DisplayGammaAffectsRendering;

    CSLStringProxy	m_RenderColorProfile;
    CSLFloatProxy	m_RenderGamma;

	CSLEnumProxy<EImageDefinitionType, SI_BROADCAST>	m_ImageDefinitionType;
    CSLBoolProxy										m_EnableMipMap;
    CSLFloatProxy										m_MipMapScale;

	CSLIntProxy																m_OglMaxSize;
    CSLBoolProxy															m_OglMipMap;
    CSLEnumProxy<EOglFilter, SI_INTERPOLATED_PIXEL_INTERPOLATED_MIPMAP>		m_OglMinFilter;
    CSLEnumProxy<EOglFilter, SI_INTERPOLATED_PIXEL>							m_OglMagFilter;

	CSLEnumProxy<EFieldType, SI_EVEN>	m_FieldType;
    CSLIntProxy							m_SourceTrack;

	SI_Void *m_pReserved;
};

#endif

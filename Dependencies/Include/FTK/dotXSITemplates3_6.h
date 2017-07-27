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

#ifndef	DOTXSI_36_DEFINED
#define	DOTXSI_36_DEFINED
#include "dotXSITemplate.h"
#include "dotXSITemplates3_5.h"

//***************************************************************************************
// Defines
//***************************************************************************************

#define	XSI_IMAGE_LIBRARY_NB_IMAGE		0
#define	XSI_IMAGE_LIBRARY_NUM_PARAMS	1

#define	XSI_NURBS_TRIM_BOUNDARY			0
#define	XSI_NURBS_TRIM_PROJECTIONTYPE	1
#define	XSI_NURBS_TRIM_NUM_PARAMS		2

#define	XSI_NURBS_PROJECTION_PROJECTIONTYPE		0
#define	XSI_NURBS_PROJECTION_NUM_PARAMS			1

#define	XSI_IMAGE_FILE_NAME				0
#define	XSI_IMAGE_SIZE_X				1
#define	XSI_IMAGE_SIZE_Y				2
#define	XSI_IMAGE_NUM_CHANNELS			3
#define	XSI_IMAGE_BITS_PER_PIXEL		4
#define	XSI_IMAGE_CROP_MIN_X			5
#define	XSI_IMAGE_CROP_MAX_X			6
#define	XSI_IMAGE_CROP_MIN_Y			7
#define	XSI_IMAGE_CROP_MAX_Y			8
#define	XSI_IMAGE_FRAME_RATE			9
#define	XSI_IMAGE_NUM_FRAMES			10
#define	XSI_IMAGE_FIRST_FRAME			11
#define	XSI_IMAGE_LAST_FRAME			12
#define	XSI_IMAGE_NUM_PARAMS			13

#define XSI_IMAGE_DATA_NUM_ENTRIES		0
#define	XSI_IMAGE_DATA_COMPRESS			1
#define	XSI_IMAGE_DATA_STREAM			2
#define	XSI_IMAGE_DATA_NUM_PARAMS		3

#define	XSI_IMAGE_FX_HUE				0
#define	XSI_IMAGE_FX_GAIN				1
#define	XSI_IMAGE_FX_SATURATION			2
#define	XSI_IMAGE_FX_BRIGHTNESS			3
#define	XSI_IMAGE_FX_RADIUS				4
#define	XSI_IMAGE_FX_AMOUNT				5
#define	XSI_IMAGE_FX_BLUR_ALPHA			6
#define	XSI_IMAGE_FX_SCALING_TYPE		7
#define	XSI_IMAGE_FX_SCALE_X			8
#define	XSI_IMAGE_FX_SCALE_Y			9
#define	XSI_IMAGE_FX_FLIP_HORIZONTAL	10
#define	XSI_IMAGE_FX_FLIP_VERTICAL		11
#define	XSI_IMAGE_FX_RGBA_2_GREYSCALE	12
#define	XSI_IMAGE_FX_8_BITS_2_16_BITS	13
#define	XSI_IMAGE_FX_NUM_PARAMS			14

#define SI_LIGHT_INFO_FALLOFF_ACTIVE	0
#define SI_LIGHT_INFO_MODE				1
#define SI_LIGHT_INFO_START				2
#define SI_LIGHT_INFO_END				3
#define SI_LIGHT_INFO_SHADOWS_ACTIVE	4
#define SI_LIGHT_INFO_UMBRA				5
#define SI_LIGHT_INFO_LIGHT_AS_ENERGY	6
#define SI_LIGHT_INFO_FACTOR			7
#define SI_LIGHT_INFO_INTENSITY			8
#define	SI_LIGHT_INFO_NUM_PARAMS		9

#define	XSI_MATERIAL_INFO_U_WRAP		0
#define	XSI_MATERIAL_INFO_V_WRAP		1
#define	XSI_MATERIAL_INFO_NUM_PARAMS	2

#define	XSI_CUSTOM_PARAM_INFO_MIN_VALUE		0
#define	XSI_CUSTOM_PARAM_INFO_MAX_VALUE		1
#define	XSI_CUSTOM_PARAM_INFO_CAPABILITIES	2
#define	XSI_CUSTOM_PARAM_INFO_NUM_PARAMS	3

#define	XSI_USERDATA_LIST_NUM_ENTRIES		0
#define	XSI_USERDATA_LIST_LITTLE_ENDIAN  	1
#define	XSI_USERDATA_LIST_NUM_PARAMS		2

#define	XSI_USERDATA_SIZE					0
#define	XSI_USERDATA_NUM_ENTITIES			1
#define	XSI_USERDATA_DATA_STREAM			2
#define	XSI_USERDATA_ENTITIES				3
#define	XSI_USERDATA_NUM_PARAMS				4

#define	XSI_FXTREE_NUM_ENTITIES				0
#define	XSI_FXTREE_NUM_PARAMS				1

#define XSI_FXOPERATOR_NAME					0
#define	XSI_FXOPERATOR_OUTPUT_TYPE			1
#define	XSI_FXOPERATOR_NUMBER_PARAMS		2
#define	XSI_FXOPERATOR_NUM_CONNECTIONS		3
#define	XSI_FXOPERATOR_NUM_PARAMS			4

#define	XSI_CLUSTERINFO_TYPE				0
#define	XSI_CLUSTERINFO_NUM_PARAMS			1

//***************************************************************************************
// Registration
//***************************************************************************************

extern	TemplateCreation	RegistrationTable36[];

/*! \addtogroup regfunc_36 Registration functions for dotXSI 3.6
*  @{
*/

/*! XSI_ImageLibrary template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_ImageLibrary template
*/
CdotXSITemplate*	Register_XSI_ImageLibrary();

/*! XSI_NurbsProjection template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_NurbsProjection template
*/
CdotXSITemplate*	Register_XSI_NurbsProjection();

/*! XSI_NurbsTrim template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_NurbsTrim template
*/
CdotXSITemplate*	Register_XSI_NurbsTrim();

/*! XSI_Image template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Image template
*/
CdotXSITemplate*	Register_XSI_Image();

/*! XSI_ImageData template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_ImageData template
*/
CdotXSITemplate*	Register_XSI_ImageData();

/*! XSI_ImageFX template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_ImageFX template
*/
CdotXSITemplate*	Register_XSI_ImageFX();

/*! SI_LightInfo template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_LightInfo template
*/
CdotXSITemplate*	Register_SI_LightInfo();

/*! XSI_MaterialInfo template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_MaterialInfo template
*/
CdotXSITemplate*	Register_XSI_MaterialInfo();

/*! XSI_CustomParamInfo template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_CustomParamInfo template
*/
CdotXSITemplate*	Register_XSI_CustomParamInfo();

/*! XSI_UserDataList template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_UserDataList template
*/
CdotXSITemplate*	Register_XSI_UserDataList();

/*! XSI_UserData template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_UserData template
*/
CdotXSITemplate*	Register_XSI_UserData();

/*! XSI_FxTree template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_FxTree template
*/
CdotXSITemplate*	Register_XSI_FxTree();

/*! XSI_FxOperator template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_FxOperator template
*/
CdotXSITemplate*	Register_XSI_FxOperator();

/*! XSI_ClusterInfo template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_ClusterInfo template
*/
CdotXSITemplate*	Register_XSI_ClusterInfo();

/*! @} */

#endif

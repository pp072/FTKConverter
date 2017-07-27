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


#ifndef	DOTXSI_60_DEFINED
#define	DOTXSI_60_DEFINED
#include "dotXSITemplate.h"
#include "dotXSITemplates3_5.h"
#include "dotXSITemplates3_6.h"
#include "dotXSITemplates5_0.h"


//***************************************************************************************
// Defines
//***************************************************************************************

#define XSI_IK_RESPLANE_TYPE			0
#define XSI_IK_RESPLANE_ROLL			1
#define XSI_IK_RESPLANE_PREFROTX_ROLL	2
#define XSI_IK_RESPLANE_UPX				3
#define XSI_IK_RESPLANE_UPY				4
#define XSI_IK_RESPLANE_UPZ				5
#define XSI_IK_RESPLANE_UPVCTRELROOT	6
#define XSI_IK_RESPLANE_PREFX			7
#define XSI_IK_RESPLANE_PREFY			8
#define XSI_IK_RESPLANE_PREFZ			9
#define XSI_IK_RESPLANE_PREFRELROOT		10
#define XSI_IK_RESPLANE_NUM_PARAMS		11

#define XSI_CAMERA_PRESET					0
#define XSI_CAMERA_PICTURE_RATIO			1
#define XSI_CAMERA_FIELD_OF_VIEW			2
#define XSI_CAMERA_FIELD_OF_VIEW_TYPE		3
#define XSI_CAMERA_PROJECTION_TYPE			4
#define XSI_CAMERA_ORTHO_HEIGHT				5
#define XSI_CAMERA_INTEREST_DISTANCE		6
#define XSI_CAMERA_NEAR_PLANE				7
#define XSI_CAMERA_FAR_PLANE				8
#define XSI_CAMERA_PROJ_PLANE_ENABLE		9
#define XSI_CAMERA_FILM_APERTURE_X			10
#define XSI_CAMERA_FILM_APERTURE_Y			11
#define XSI_CAMERA_OPTICAL_CENTER_SHIFT_X	12
#define XSI_CAMERA_OPTICAL_CENTER_SHIFT_Y	13
#define XSI_CAMERA_NUM_PARAMS				14

#define XSI_TRANSLATE_X						0
#define XSI_TRANSLATE_Y						1
#define XSI_TRANSLATE_Z						2
#define XSI_TRANSLATE_NUM_PARAMS			3

#define XSI_SCALE_X							0
#define XSI_SCALE_Y							1
#define XSI_SCALE_Z							2
#define XSI_SCALE_NUM_PARAMS				3

#define XSI_ROTATE_X						0
#define XSI_ROTATE_Y						1
#define XSI_ROTATE_Z						2
#define XSI_ROTATE_ANGLE					3
#define XSI_ROTATE_NUM_PARAMS				4

#define XSI_SHEAR_X1						0
#define XSI_SHEAR_Y1						1
#define XSI_SHEAR_Z1						2
#define XSI_SHEAR_X2						3
#define XSI_SHEAR_Y2						4
#define XSI_SHEAR_Z2						5
#define XSI_SHEAR_ANGLE						6
#define XSI_SHEAR_NUM_PARAMS				7

#define XSI_LOOKAT_PX						0
#define XSI_LOOKAT_PY						1
#define XSI_LOOKAT_PZ						2
#define XSI_LOOKAT_IX						3
#define XSI_LOOKAT_IY						4
#define XSI_LOOKAT_IZ						5
#define XSI_LOOKAT_UX						6
#define XSI_LOOKAT_UY						7
#define XSI_LOOKAT_UZ						8
#define XSI_LOOKAT_NUM_PARAMS				9

#define XSI_MATRIX_00						0
#define XSI_MATRIX_01						1
#define XSI_MATRIX_02						2
#define XSI_MATRIX_03						3
#define XSI_MATRIX_10						4
#define XSI_MATRIX_11						5
#define XSI_MATRIX_12						6
#define XSI_MATRIX_13						7
#define XSI_MATRIX_20						8
#define XSI_MATRIX_21						9
#define XSI_MATRIX_22						10
#define XSI_MATRIX_23						11
#define XSI_MATRIX_30						12
#define XSI_MATRIX_31						13
#define XSI_MATRIX_32						14
#define XSI_MATRIX_33						15
#define XSI_MATRIX_NUM_PARAMS				16

#define XSI_SHAPEREFERENCE_REFERENCE		0
#define XSI_SHAPEREFERENCE_NUM_PARAMS		1

#define XSI_INDEX_LIST_NBATTRIBUTES		0
#define XSI_INDEX_LIST_ARRAY			1
#define	XSI_INDEX_LIST_NUM_PARAMS		1

#define XSI_CAMERA_FOCALLENGTH_FOCALLENGTH			0
#define XSI_CAMERA_FOCALLENGTH_NUM_PARAMS			1

#define XSI_SHADER_MULTI_PORT_NBPORTS		0
#define XSI_SHADER_MULTI_PORT_PORT_NAME_ARRAY	1
#define XSI_SHADER_MULTI_PORT_PORT_TYPE_ARRAY	2
#define XSI_SHADER_MULTI_PORT_NUM_PARAMS	1

#define XSI_SHADER_MULTI_PORT_CONNECTION_PARAMETER	0
#define XSI_SHADER_MULTI_PORT_CONNECTION_PORT_NAME	1
#define XSI_SHADER_MULTI_PORT_CONNECTION_NUM_PARAMS	2

#define	XSI_IMAGE_FX2_EXPOSURE							0
#define	XSI_IMAGE_FX2_DISPLAY_GAMMA						1
#define	XSI_IMAGE_FX2_DISPLAY_GAMMA_AFFECTS_RENDERING	2
#define	XSI_IMAGE_FX2_RENDER_COLOR_PROFILE				3
#define	XSI_IMAGE_FX2_RENDER_GAMMA						4
#define	XSI_IMAGE_FX2_IMAGE_DEFINITION_TYPE				5
#define	XSI_IMAGE_FX2_ENABLE_MIPMAP						6
#define	XSI_IMAGE_FX2_MIPMAP_SCALE						7
#define	XSI_IMAGE_FX2_OGL_MAXSIZE						8
#define	XSI_IMAGE_FX2_OGL_MIPMAP						9
#define	XSI_IMAGE_FX2_OGL_MINFILTER						10
#define	XSI_IMAGE_FX2_OGL_MAGFILTER						11
#define	XSI_IMAGE_FX2_FIELD_TYPE						12
#define	XSI_IMAGE_FX2_SOURCE_TRACK						13
#define	XSI_IMAGE_FX2_NUM_PARAMS						14

#define	XSI_TEXTURE_LAYER_ORDER							0
#define	XSI_TEXTURE_LAYER_MUTE							1
#define	XSI_TEXTURE_LAYER_SOLO							2
#define	XSI_TEXTURE_LAYER_COLOR_CONNECTION				3
#define	XSI_TEXTURE_LAYER_R								4
#define	XSI_TEXTURE_LAYER_G								5
#define	XSI_TEXTURE_LAYER_B								6
#define	XSI_TEXTURE_LAYER_A								7
#define	XSI_TEXTURE_LAYER_COLOR_PREMULTIPLIED			8
#define	XSI_TEXTURE_LAYER_IGNORE_COLOR_ALPHA			9
#define	XSI_TEXTURE_LAYER_INVERT_COLOR_ALPHA			10
#define	XSI_TEXTURE_LAYER_ALPHA_COLOR					11
#define	XSI_TEXTURE_LAYER_MASK_CONNECTION				12
#define	XSI_TEXTURE_LAYER_MASK							13
#define	XSI_TEXTURE_LAYER_INVERT_MASK					14
#define	XSI_TEXTURE_LAYER_MASK_MODE						15
#define	XSI_TEXTURE_LAYER_MASK_THRESHOLD				16
#define	XSI_TEXTURE_LAYER_WEIGHT						17
#define	XSI_TEXTURE_LAYER_MODE							18
#define	XSI_TEXTURE_LAYER_NUM_PARAMS					19

#define	XSI_TEXTURE_LAYER_PORT_TARGET					0
#define	XSI_TEXTURE_LAYER_PORT_MUTE						1
#define	XSI_TEXTURE_LAYER_PORT_SCALE					2
#define	XSI_TEXTURE_LAYER_PORT_COLOR_SOURCE				3
#define	XSI_TEXTURE_LAYER_PORT_INVERT					4
#define	XSI_TEXTURE_LAYER_PORT_NUM_PARAMS				5

#define	XSI_USER_KEYWORD_LIST							0
#define	XSI_USER_KEYWORD_NUM_PARAMS						1

#define	XSI_CLIP_TO_PARENT_START						0
#define	XSI_CLIP_TO_PARENT_END							1
#define	XSI_CLIP_TO_PARENT_NUM_PARAMS					2

//***************************************************************************************
// Registration
//***************************************************************************************

extern	TemplateCreation	RegistrationTable60[];

/*! XSI_IK_ResolutionPlane template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_IK_ResolutionPlane template
*/
CdotXSITemplate*	Register_XSI_IK_ResolutionPlane();

/*! XSI_Camera template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Camera template
*/
CdotXSITemplate*	Register_XSI_Camera();

/*! XSI Polymatricks template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Polymatricks template
*/
CdotXSITemplate*	Register_XSI_Polymatricks();

/*! XSI translate template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Translate template
*/
CdotXSITemplate*	Register_XSI_Translate();

/*! XSI Rotate template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Rotate template
*/
CdotXSITemplate*	Register_XSI_Rotate();

/*! XSI Scale template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Scale template
*/
CdotXSITemplate*	Register_XSI_Scale();

/*! XSI Shear template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Shear template
*/
CdotXSITemplate*	Register_XSI_Shear();

/*! XSI Lookat template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Lookat template
*/
CdotXSITemplate*	Register_XSI_Lookat();

/*! XSI Matrix template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Matrix template
*/
CdotXSITemplate*	Register_XSI_Matrix();

/*! XSI Shape Reference template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_ShapeReference template
*/
CdotXSITemplate*	Register_XSI_ShapeReference();

/*! XSI Action Clip Container template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_ActionClipContainer template
*/
CdotXSITemplate*	Register_XSI_ActionClipContainer();

/*! XSI_IndexList template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_IndexList template
*/
CdotXSITemplate*	Register_XSI_IndexList();
/*! XSI_CameraFocalLength template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_CameraFocalLength template
*/
CdotXSITemplate*	Register_XSI_CameraFocalLength();

/*! XSI_ShaderMultiPortConnection template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_ShaderMultiPortConnection template
*/
CdotXSITemplate*	Register_XSI_ShaderMultiPortConnection();

/*! XSI_ImageFX2 template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_ImageFX2 template
*/
CdotXSITemplate*	Register_XSI_ImageFX2();

/*! XSI_TextureLayer template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_TextureLayer template
*/
CdotXSITemplate*	Register_XSI_TextureLayer();

/*! XSI_TextureLayerPort template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_TextureLayerPort template
*/
CdotXSITemplate*	Register_XSI_TextureLayerPort();

/*! XSI_UserKeyword template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_UserKeyword template
*/
CdotXSITemplate*	Register_XSI_UserKeyword();

/*! XSI_ClipToParent template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_ClipToParent template
*/
CdotXSITemplate*	Register_XSI_ClipToParent();

#endif //DOTXSI_60_DEFINED

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

COPYRIGHT NOTICE. Copyright � 1999-2002 Avid Technology Inc. . All rights reserved. 

SOFTIMAGE is a registered trademark of Avid Technology Inc. or its subsidiaries 
or divisions. Windows NT is a registered trademark of Microsoft Corp. All other
trademarks contained herein are the property of their respective owners. 
****************************************************************************************/


#ifndef	DOTXSI_30_DEFINED
#define	DOTXSI_30_DEFINED
#include "dotXSITemplate.h"

//***************************************************************************************
// Defines
//***************************************************************************************

#define SI_2DJOINT_EFF_ROT_FLAG			0
#define SI_2DJOINT_EFF_NUM_PARAMS		1

#define SI_2DJOINT_JOINT_ROTX			0
#define SI_2DJOINT_JOINT_ROTY			1
#define SI_2DJOINT_JOINT_ROTZ			2
#define SI_2DJOINT_JOINT_NUM_PARAMS		3

#define SI_2DJOINT_ROOT_JOINT1_NAME		0
#define SI_2DJOINT_ROOT_JOINT2_NAME		1
#define SI_2DJOINT_ROOT_EFF_NAME		2
#define SI_2DJOINT_ROOT_NUM_PARAMS		3

#define SI_AMBIENCE_R       			0
#define SI_AMBIENCE_G		    	    1
#define SI_AMBIENCE_B			    	2
#define SI_AMBIENCE_NUM_PARAMS			3

#define SI_ANGLE_TYPE					0
#define SI_ANGLE_NUM_PARAMS				1

#define SI_CAMERA_POSX					0
#define SI_CAMERA_POSY					1
#define SI_CAMERA_POSZ					2
#define SI_CAMERA_INTX					3
#define SI_CAMERA_INTY					4
#define SI_CAMERA_INTZ					5
#define SI_CAMERA_VECTORUPX				6
#define SI_CAMERA_VECTORUPY				7
#define SI_CAMERA_VECTORUPZ				8
#define SI_CAMERA_ROLL					6
#define SI_CAMERA_FOV					7
#define SI_CAMERA_NEAR_PLANE			8
#define SI_CAMERA_FAR_PLANE				9
#define SI_CAMERA_NUM_PARAMS			10

#define SI_CAM_ANIM_NB_FCV				0
#define SI_CAM_ANIM_NUM_PARAMS			1

#define SI_CLUSTER_OBJ_NAME				0
#define SI_CLUSTER_ANIM_MODE			1
#define SI_CLUSTER_CENTER_NAME			2
#define SI_CLUSTER_NB_SUBELEM			3
#define SI_CLUSTER_SUBELEM				4
#define SI_CLUSTER_NUM_PARAMS			5

#define SI_CONSTRAINT_OBJ_NAME			0
#define SI_CONSTRAINT_CONS_TYPE			1
#define SI_CONSTRAINT_NB_CONS_OBJ		2
#define SI_CONSTRAINT_CONS_OBJ_NAME		3
#define SI_CONSTRAINT_NUM_PARAMS		4

#define SI_COORDSYS_HAND_ROT			0
#define SI_COORDSYS_U					1
#define SI_COORDSYS_V					2
#define SI_COORDSYS_X					3
#define SI_COORDSYS_Y					4
#define SI_COORDSYS_Z					5
#define SI_COORDSYS_NUM_PARAMS			6

#define SI_ENVELOPE_ENV					0
#define SI_ENVELOPE_REF					1
#define SI_ENVELOPE_NB_VRT				2
#define SI_ENVELOPE_VRT_WEIGHTS			3
#define SI_ENVELOPE_NUM_PARAMS			4

#define SI_ENVELOPE_LIST_NB_ENV			0
#define SI_ENVELOPE_LIST_NUM_PARAMS		1

#define SI_FILEINFO_PROJ_NAME			0
#define SI_FILEINFO_USER_NAME			1
#define SI_FILEINFO_SAVED_TIME			2
#define SI_FILEINFO_ORIGINATOR			3
#define SI_FILEINFO_NUM_PARAMS			4

#define SI_FCURVE_OBJ_NAME				0
#define SI_FCURVE_FCURVE				1
#define SI_FCURVE_INTERPOL				2
#define SI_FCURVE_NB_FCV				3
#define SI_FCURVE_NB_KEY_VAL			4
#define SI_FCURVE_NB_KEYS				5
#define SI_FCURVE_KEY_VAL				6
#define SI_FCURVE_NUM_PARAMS			7

#define SI_FOG_TYPE						0
#define SI_FOG_INTERPOL					1
#define SI_FOG_R						2
#define SI_FOG_G    					3
#define SI_FOG_B						4
#define SI_FOG_NEAR						5
#define SI_FOG_FAR						6
#define SI_FOG_NUM_PARAMS				7

#define SI_FRAME_POSE_MAT_11			0
#define SI_FRAME_POSE_MAT_12			1
#define SI_FRAME_POSE_MAT_13			2
#define SI_FRAME_POSE_MAT_14			3
#define SI_FRAME_POSE_MAT_21			4
#define SI_FRAME_POSE_MAT_22			5
#define SI_FRAME_POSE_MAT_23			6
#define SI_FRAME_POSE_MAT_24			7
#define SI_FRAME_POSE_MAT_31			8
#define SI_FRAME_POSE_MAT_32			9
#define SI_FRAME_POSE_MAT_33			10
#define SI_FRAME_POSE_MAT_34			11
#define SI_FRAME_POSE_MAT_41			12
#define SI_FRAME_POSE_MAT_42			13
#define SI_FRAME_POSE_MAT_43			14
#define SI_FRAME_POSE_MAT_44			15
#define SI_FRAME_POSE_MAT_NUM_PARAMS	16

#define SI_FRAME_XFO_MAT_11				0
#define SI_FRAME_XFO_MAT_12				1
#define SI_FRAME_XFO_MAT_13				2
#define SI_FRAME_XFO_MAT_14				3
#define SI_FRAME_XFO_MAT_21				4
#define SI_FRAME_XFO_MAT_22				5
#define SI_FRAME_XFO_MAT_23				6
#define SI_FRAME_XFO_MAT_24				7
#define SI_FRAME_XFO_MAT_31				8
#define SI_FRAME_XFO_MAT_32				9
#define SI_FRAME_XFO_MAT_33				10
#define SI_FRAME_XFO_MAT_34				11
#define SI_FRAME_XFO_MAT_41				12
#define SI_FRAME_XFO_MAT_42				13
#define SI_FRAME_XFO_MAT_43				14
#define SI_FRAME_XFO_MAT_44				15
#define SI_FRAME_XFO_MAT_NUM_PARAMS		16

#define SI_GLOBAL_MATERIAL_REFERENCE	0
#define SI_GLOBAL_MATERIAL_PROPAGATION	1
#define SI_GLOBAL_MATERIAL_NUM_PARAMS	2

#define SI_IMAGE_CLIP_TEX_REF			0
#define SI_IMAGE_CLIP_NB_IMAGES			1
#define SI_IMAGE_CLIP_START				2
#define SI_IMAGE_CLIP_END				3
#define SI_IMAGE_CLIP_FRAME_RATE		4
#define SI_IMAGE_CLIP_LOOP				5
#define SI_IMAGE_CLIP_IMAGES			6
#define SI_IMAGE_CLIP_NUM_PARAMS		7

#define SI_INSTANCE_MASTER				0
#define SI_INSTANCE_NUM_PARAMS			1

#define SI_IK_EFF_ROT_FLAG				0
#define SI_IK_EFF_NUM_PARAMS			1

#define SI_IK_JOINT_SOLVER_TYPE			0
#define SI_IK_JOINT_LENGTH				1
#define SI_IK_JOINT_ROTX				2
#define SI_IK_JOINT_ROTY				3
#define SI_IK_JOINT_ROTZ				4
#define SI_IK_JOINT_ROTLIMIT_ACTIVE		5
#define SI_IK_JOINT_ROTX_MIN			6
#define SI_IK_JOINT_ROTY_MIN			7
#define SI_IK_JOINT_ROTZ_MIN			8
#define SI_IK_JOINT_ROTX_MAX			9
#define SI_IK_JOINT_ROTY_MAX			10
#define SI_IK_JOINT_ROTZ_MAX			11
#define SI_IK_JOINT_PSEUDO_ROOT			12
#define SI_IK_JOINT_STIFFNESS_ACTIVE	13
#define SI_IK_JOINT_STIFFNESS			14
#define SI_IK_JOINT_NUM_PARAMS			15

#define SI_IK_ROOT_NB_JOINTS			0
#define SI_IK_ROOT_JOINT_NAMES			1
#define SI_IK_ROOT_EFF_NAME				2
#define SI_IK_ROOT_NUM_PARAMS			3

#define SI_LIGHT_TYPE_POINT				0
#define SI_LIGHT_TYPE_INFINITE			1
#define SI_LIGHT_TYPE_SPOT				2
#define SI_LIGHT_TYPE_XSI_INFINITE		3

#define SI_LIGHT_TYPE					0
#define SI_LIGHT_R  					1
#define SI_LIGHT_G	    				2
#define SI_LIGHT_B  					3
#define SI_LIGHT_POSX					4
#define SI_LIGHT_POSY					5
#define SI_LIGHT_POSZ					6
#define SI_LIGHT_INTX					7
#define SI_LIGHT_INTY					8
#define SI_LIGHT_INTZ					9
#define SI_LIGHT_ORIX					7
#define SI_LIGHT_ORIY					8
#define SI_LIGHT_ORIZ					9
#define SI_LIGHT_CONE_ANGLE				10
#define SI_LIGHT_SPREAD_ANGLE			11
#define SI_LIGHT_NUM_PARAMS				12

#define SI_LIGHT_ANIM_NBFCURVES			0
#define SI_LIGHT_ANIM_NUM_PARAMS		1

#define SI_MAT_FACE_R			        0
#define SI_MAT_FACE_G		        	1
#define SI_MAT_FACE_B		        	2
#define SI_MAT_FACE_A		    	    3
#define SI_MAT_POWER				    4
#define SI_MAT_SPECULAR_R				5
#define SI_MAT_SPECULAR_G	        	6
#define SI_MAT_SPECULAR_B	        	7
#define SI_MAT_EMISSIVE_R	        	8
#define SI_MAT_EMISSIVE_G				9
#define SI_MAT_EMISSIVE_B				10
#define SI_MAT_SHADING_MODEL       	    11
#define SI_MAT_AMBIENT_R	           	12
#define SI_MAT_AMBIENT_G	            13
#define SI_MAT_AMBIENT_B 				14
#define SI_MAT_NUM_PARAMS				15

#define SI_MAT_LIB_NBMAT	        	0
#define SI_MAT_LIB_NUM_PARAMS			1

#define SI_MAX_NAME_LENGTH				256

#define SI_NRB_CRV_DEGREE				0
#define SI_NRB_CRV_CLOSED				1
#define SI_NRB_CRV_PARAMTYPE			2
#define SI_NRB_CRV_NBKNOTS				3
#define	SI_NRB_CRV_KNOTS				4
#define SI_NRB_CRV_NBCONTROL_PTS		5
#define SI_NRB_CRV_CONTROL_PTS			6
#define SI_NRB_CRV_NUM_PARAMS			7

#define SI_NRB_SRF_UDEGREE		    	0
#define SI_NRB_SRF_VDEGREE		    	1
#define SI_NRB_SRF_UCLOSED		    	2
#define SI_NRB_SRF_VCLOSED		    	3
#define SI_NRB_SRF_PARAMTYPE	    	4
#define SI_NRB_SRF_NBUKNOTS             5   
#define SI_NRB_SRF_NBVKNOTS		        6
#define SI_NRB_SRF_UKNOTS		    	7
#define SI_NRB_SRF_VKNOTS		    	8
#define SI_NRB_SRF_NBCONTROL_PTS	    9	
#define SI_NRB_SRF_NBUCONTROL_PTS	    10
#define SI_NRB_SRF_NBVCONTROL_PTS	    11
#define SI_NRB_SRF_CONTROL_PTS		    12
#define SI_NRB_SRF_NUM_PARAMS			13

#define SI_PTCH_UTYPE				    0
#define SI_PTCH_VTYPE				    1
#define SI_PTCH_UTENSION			    2
#define SI_PTCH_VTENSION				3
#define SI_PTCH_UCLOSED					4
#define SI_PTCH_VCLOSED					5
#define SI_PTCH_NBTOTALCONTROL_PTS		6
#define SI_PTCH_NBUCONTROL_PTS			7
#define SI_PTCH_NBVCONTROL_PTS			8
#define SI_PTCH_CONTROL_PTS			    9
#define SI_PTCH_NUM_PARAMS				10

#define SI_POLYGONLIST_NBPOLYGONS		0
#define SI_POLYGONLIST_INFORMATION		1
#define SI_POLYGONLIST_MATERIAL			2
#define SI_POLYGONLIST_NBVERTICES		3
#define SI_POLYGONLIST_NUM_PARAMS		4

// According to the template there are only 4 parameters, but because of the
// way the template was implemented there are actually 2 more parameters; however, the
// value for SI_POLYGONLIST_NUM_PARAMS should stay at 4 until the code in the
// reading and writing of templates is updated.
#define SI_POLYGONLIST_VERTICESPERPOLY_ARRAY 	4
#define SI_POLYGONLIST_VERTICES_ARRAY	5

#define SI_SCENE_TIMING					0
#define SI_SCENE_START					1
#define SI_SCENE_END					2
#define SI_SCENE_FRAMERATE				3
#define SI_SCENE_NUM_PARAMS				4

#define SI_SHAPE_NBSHAPEARRAYS			0
#define SI_SHAPE_TYPE					1
#define SI_SHAPE_NUM_PARAMS				2
#define SI_SHAPE_ARRAYx_NB_ENTRIES(i)	((SI_SHAPE_TYPE+1)+(i*3))
#define SI_SHAPE_ARRAYx_TYPE(i)			((SI_SHAPE_TYPE+1)+(i*3)+1)
#define SI_SHAPE_ARRAYx(i)		 		((SI_SHAPE_TYPE+1)+(i*3)+2)

#define SI_SHAPE_ANIM_TYPE				0
#define SI_SHAPE_ANIM_NBSHAPE			1
#define SI_SHAPE_ANIM_NUM_PARAMS		2

#define SI_TXT2D_IMAGENAME			    0
#define SI_TXT2D_MAPPINGTYPE		    1
#define SI_TXT2D_WIDTH				    2
#define SI_TXT2D_HEIGHT				    3
#define SI_TXT2D_CROPUMIN			    4
#define SI_TXT2D_CROPUMAX			    5
#define SI_TXT2D_CROPVMIN			    6
#define SI_TXT2D_CROPVMAX			    7
#define SI_TXT2D_UVSWAP				    8
#define SI_TXT2D_UREPEAT			    9	
#define SI_TXT2D_VREPEAT			    10
#define SI_TXT2D_UALTERNATE			    11
#define SI_TXT2D_VALTERNATE			    12
#define SI_TXT2D_USCALE				    13
#define SI_TXT2D_VSCALE				    14	
#define SI_TXT2D_UOFFSET			    15
#define SI_TXT2D_VOFFSET			    16
#define SI_TXT2D_PROJ_MAT11			    17
#define SI_TXT2D_PROJ_MAT12			    18
#define SI_TXT2D_PROJ_MAT13			    19
#define SI_TXT2D_PROJ_MAT14			    20
#define SI_TXT2D_PROJ_MAT21			    21
#define SI_TXT2D_PROJ_MAT22			    22
#define SI_TXT2D_PROJ_MAT23			    23
#define SI_TXT2D_PROJ_MAT24			    24
#define SI_TXT2D_PROJ_MAT31			    25
#define SI_TXT2D_PROJ_MAT32			    26
#define SI_TXT2D_PROJ_MAT33			    27
#define SI_TXT2D_PROJ_MAT34			    28
#define SI_TXT2D_PROJ_MAT41			    29
#define SI_TXT2D_PROJ_MAT42			    30
#define SI_TXT2D_PROJ_MAT43			    31
#define SI_TXT2D_PROJ_MAT44			    32
#define SI_TXT2D_BLENDINGTYPE		    33
#define SI_TXT2D_BLENDING			    34
#define SI_TXT2D_AMBIENT			    35
#define SI_TXT2D_DIFFUSE			    36
#define SI_TXT2D_SPECULAR			    37
#define SI_TXT2D_TRANSPARENCY		    38
#define SI_TXT2D_REFLECTIVITY		    39
#define SI_TXT2D_ROUGHNESS			    40
#define SI_TXT2D_NUM_PARAMS				41
    
#define SI_TRANSFORM_SCALX				0
#define SI_TRANSFORM_SCALY				1
#define SI_TRANSFORM_SCALZ				2
#define SI_TRANSFORM_ROTX				3
#define SI_TRANSFORM_ROTY				4
#define SI_TRANSFORM_ROTZ				5
#define SI_TRANSFORM_TRANSX				6
#define SI_TRANSFORM_TRANSY				7
#define SI_TRANSFORM_TRANSZ				8
#define SI_TRANSFORM_NUM_PARAMS			9
			
#define SI_TRANSFORM_ANIM_NBFCURVES		0
#define SI_TRANSFORM_ANIM_NUM_PARAMS	1

#define SI_TRIANGLELIST_NBTRIANGLES		0
#define SI_TRIANGLELIST_INFORMATION		1
#define SI_TRIANGLELIST_MATERIAL		2
#define SI_TRIANGLELIST_NUM_PARAMS		3

// According to the template there are only 3 parameters, but because of the
// way the template was implemented there is actually 1 more parameter; however, the
// value for SI_TRIANGLELIST_NUM_PARAMS should stay at 3 until the code in the
// reading and writing of templates is updated.
#define SI_TRIANGLELIST_VERTICES_ARRAY	3

#define SI_TRISTRIP_NBVERTICES			0
#define SI_TRISTRIP_NUM_PARAMS			1

#define SI_TRISTRIPLIST_NBTRISTRIPS		0
#define SI_TRISTRIPLIST_INFORMATION		1
#define SI_TRISTRIPLIST_MATERIAL		2
#define SI_TRISTRIPLIST_LIST_NUM_PARAMS	3

#define SI_VECTOR4D_X					0
#define SI_VECTOR4D_Y					1
#define SI_VECTOR4D_Z					2
#define SI_VECTOR4D_W					3
#define SI_VECTOR4D_NUM_PARAMS			4

#define SI_VERTEXWEIGHT_VERTEXINDEX		0
#define SI_VERTEXWEIGHT_WEIGHT			1
#define SI_VERTEXWEIGHT_NUM_PARAMS		2

#define SI_VISIBILITY_FLAG				0
#define SI_VISIBILITY_NUM_PARAMS		1

#define XSI_ACTION_START_TIME			0
#define XSI_ACTION_DURATION				1
#define XSI_ACTION_SKILL_TYPE			2
#define XSI_ACTION_NUM_PARAMS			3

#define XSI_ACTIONCLIP_START_TIME		0
#define XSI_ACTIONCLIP_DURATION			1
#define XSI_ACTIONCLIP_ACTION_SRC		2
#define XSI_ACTIONCLIP_ACTIVE			3
#define XSI_ACTIONCLIP_WEIGHT			4
#define XSI_ACTIONCLIP_FILL_ACTION		5
#define XSI_ACTIONCLIP_FILL_PRIORITY	6
#define XSI_ACTIONCLIP_NUM_PARAMS		7

#define XSI_CUSTOM_PSET_PROPAGATION		0
#define XSI_CUSTOM_PSET_NUM_PARAMS		1

#define XSI_EXTRAPOLATION_TYPE			0
#define XSI_EXTRAPOLATION_VALUE			1
#define XSI_EXTRAPOLATION_NUM_PARAMS	2

#define XSI_MIXER_AUTO_TRANSITION		0
#define XSI_MIXER_ACTIVE				1
#define XSI_MIXER_NORMALIZE				2
#define XSI_MIXER_QUATERNION_MIXING		3
#define XSI_MIXER_REMOVE_SPINS			4
#define XSI_MIXER_MAINTAIN_CONTINUITY	5
#define XSI_MIXER_NUM_PARAMS			6

#define XSI_STATIC_VALUE_ACTIVE			0
#define XSI_STATIC_VALUE_PARAM			1
#define XSI_STATIC_VALUE_VALUE			2
#define XSI_STATIC_VALUE_NUM_PARAMS		3

#define XSI_TIMECONTROL_IN				0
#define XSI_TIMECONTROL_OUT				1
#define XSI_TIMECONTROL_START_OFFSET	2
#define XSI_TIMECONTROL_SCALE			3
#define XSI_TIMECONTROL_NUM_PARAMS		4

#define XSI_TRACK_RIPPLE				0
#define XSI_TRACK_MUTE					1
#define XSI_TRACK_SOLO					2
#define XSI_TRACK_NUM_PARAMS			3



//***************************************************************************************
// Registration
//***************************************************************************************
extern	TemplateCreation	RegistrationTable30[];

/*! \addtogroup regfunc_30 Registration functions for dotXSI 3.0
*  @{
*/

/*! SI_Ambience template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Ambience template
*/
CdotXSITemplate*	Register_SI_Ambience();

/*! SI_Angle template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Angle template
*/
CdotXSITemplate*	Register_SI_Angle();

/*! SI_Camera template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Camera template
*/
CdotXSITemplate*	Register_SI_Camera();

/*! SI_Cluster template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Cluster template
*/
CdotXSITemplate*	Register_SI_Cluster();

/*! SI_Constraint template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Constraint template
*/
CdotXSITemplate*	Register_SI_Constraint();

/*! SI_CoordinateSystem template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_CoordinateSystem template
*/
CdotXSITemplate*	Register_SI_CoordinateSystem();

/*! XSI_CurveList template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_CurveList template
*/
CdotXSITemplate*	Register_XSI_CurveList();

/*! SI_Envelope template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Envelope template
*/
CdotXSITemplate*	Register_SI_Envelope();

/*! SI_EnvelopeList template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_EnvelopeList template
*/
CdotXSITemplate*	Register_SI_EnvelopeList();

/*! SI_FileInfo template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_FileInfo template
*/
CdotXSITemplate*	Register_SI_FileInfo();

/*! SI_FCurve template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_FCurve template
*/
CdotXSITemplate*	Register_SI_FCurve();

/*! SI_Fog template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Fog template
*/
CdotXSITemplate*	Register_SI_Fog();

/*! SI_FrameBasePoseMatrix template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_FrameBasePoseMatrix template
*/
CdotXSITemplate*	Register_SI_FrameBasePoseMatrix();

/*! FrameTransformMatrix template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the FrameTransformMatrix template
*/
CdotXSITemplate*	Register_FrameTransformMatrix();

/*! SI_GlobalMaterial template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_GlobalMaterial template
*/
CdotXSITemplate*	Register_SI_GlobalMaterial();

/*! SI_IK_Effector template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_IK_Effector template
*/
CdotXSITemplate*	Register_SI_IK_Effector();

/*! SI_IK_Joint template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_IK_Joint template
*/
CdotXSITemplate*	Register_SI_IK_Joint();

/*! SI_IK_Root template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_IK_Root template
*/
CdotXSITemplate*	Register_SI_IK_Root();

/*! SI_ImageClip template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_ImageClip template
*/
CdotXSITemplate*	Register_SI_ImageClip();

/*! SI_Instance template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Instance template
*/
CdotXSITemplate*	Register_SI_Instance();

/*! SI_Light template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Light template
*/
CdotXSITemplate*	Register_SI_Light();

/*! SI_Material template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Material template
*/
CdotXSITemplate*	Register_SI_Material();

/*! SI_MaterialLibrary template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_MaterialLibrary template
*/
CdotXSITemplate*	Register_SI_MaterialLibrary();

/*! SI_Mesh template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Mesh template
*/
CdotXSITemplate*	Register_SI_Mesh();

/*! SI_Model template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Model template
*/
CdotXSITemplate*	Register_SI_Model();

/*! Frame template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the Frame template
*/
CdotXSITemplate*	Register_Frame();

/*! SI_Null template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Null template
*/
CdotXSITemplate*	Register_SI_Null();

/*! SI_NurbsSurface template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_NurbsSurface template
*/
CdotXSITemplate*	Register_SI_NurbsSurface();

/*! SI_NurbsCurve template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_NurbsCurve template
*/
CdotXSITemplate*	Register_SI_NurbsCurve();

/*! SI_PatchSurface template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_PatchSurface template
*/
CdotXSITemplate*	Register_SI_PatchSurface();

/*! SI_PolygonList template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_PolygonList template
*/
CdotXSITemplate*	Register_SI_PolygonList();

/*! SI_Scene template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Scene template
*/
CdotXSITemplate*	Register_SI_Scene();

/*! SI_Shape template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Shape template
*/
CdotXSITemplate*	Register_SI_Shape();

/*! SI_ShapeAnimation template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_ShapeAnimation template
*/
CdotXSITemplate*	Register_SI_ShapeAnimation();

/*! XSI_SurfaceMesh template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_SurfaceMesh template
*/
CdotXSITemplate*	Register_XSI_SurfaceMesh();

/*! SI_Texture2D template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Texture2D template
*/
CdotXSITemplate*	Register_SI_Texture2D();

/*! SI_Transform template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Transform template
*/
CdotXSITemplate*	Register_SI_Transform();

/*! SI_TriangleList template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_TriangleList template
*/
CdotXSITemplate*	Register_SI_TriangleList();

/*! SI_TriStrip template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_TriStrip template
*/
CdotXSITemplate*	Register_SI_TriStrip();

/*! SI_TriStripList template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_TriStripList template
*/
CdotXSITemplate*	Register_SI_TriStripList();

/*! SI_VertexWeight template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_VertexWeight template
*/
CdotXSITemplate*	Register_SI_VertexWeight();

/*! SI_Visibility template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the SI_Visibility template
*/
CdotXSITemplate*	Register_SI_Visibility();

/*! XSI_CustomPSet template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_CustomPSet template
*/
CdotXSITemplate*	Register_XSI_CustomPSet();

/*! XSI_StaticValues template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_StaticValues template
*/
CdotXSITemplate*	Register_XSI_StaticValues();

/*! XSI_Mixer template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Mixer template
*/
CdotXSITemplate*	Register_XSI_Mixer();

/*! XSI_Action template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Action template
*/
CdotXSITemplate*	Register_XSI_Action();

/*! XSI_Track template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Track template
*/
CdotXSITemplate*	Register_XSI_Track();

/*! XSI_ActionClip template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_ActionClip template
*/
CdotXSITemplate*	Register_XSI_ActionClip();

/*! XSI_TimeControl template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_TimeControl template
*/
CdotXSITemplate*	Register_XSI_TimeControl();

/*! XSI_Extrapolation template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Extrapolation template
*/
CdotXSITemplate*	Register_XSI_Extrapolation();

/*! @} */

extern	TemplateCreation	RegistrationTable30[];




#endif

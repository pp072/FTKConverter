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

#ifndef	DOTXSI_50_DEFINED
#define	DOTXSI_50_DEFINED
#include "dotXSITemplate.h"
#include "dotXSITemplates3_5.h"
#include "dotXSITemplates3_6.h"

//***************************************************************************************
// Defines
//***************************************************************************************

#define XSI_SHAPE_TYPE						0
#define	XSI_SHAPE_NUM_PARAMS				1

#define XSI_SUBCOMPONENT_ATTRIBUTE_LIST_SEMANTIC		0
#define XSI_SUBCOMPONENT_ATTRIBUTE_LIST_TYPE			1
#define XSI_SUBCOMPONENT_ATTRIBUTE_LIST_NBATTRIBUTES	2
#define	XSI_SUBCOMPONENT_ATTRIBUTE_LIST_NUM_PARAMS		3
#define XSI_SUBCOMPONENT_ATTRIBUTE_LIST_ARRAY			3

#define XSI_VERTEX_LIST_ATTRIBUTE_ARRAY		0
#define XSI_VERTEX_LIST_NBVERTICES			1
#define	XSI_VERTEX_LIST_NUM_PARAMS			2
#define	XSI_VERTEX_LIST_ARRAY				2

#define XSI_TRIANGLE_LIST_ATTRIBUTE_ARRAY	0
#define XSI_TRIANGLE_LIST_MATERIAL			1
#define XSI_TRIANGLE_LIST_NB_TRIANGLES		2
#define	XSI_TRIANGLE_LIST_NUM_PARAMS		3
#define	XSI_TRIANGLE_LIST_ARRAY				3

#define XSI_POLYGON_LIST_ATTRIBUTE_ARRAY	0
#define XSI_POLYGON_LIST_MATERIAL			1
#define XSI_POLYGON_LIST_NB_POLYNODES		2
#define XSI_POLYGON_LIST_NB_POLYGONS		3
#define	XSI_POLYGON_LIST_NUM_PARAMS			4
#define	XSI_POLYGON_LIST_ARRAY				4

#define XSI_TRIANGLESTRIP_LIST_ATTRIBUTE_ARRAY		0
#define XSI_TRIANGLESTRIP_LIST_MATERIAL				1
#define XSI_TRIANGLESTRIP_LIST_NB_POLYNODES			2
#define XSI_TRIANGLESTRIP_LIST_NB_TRIANGLESTRIPS	3
#define	XSI_TRIANGLESTRIP_LIST_NUM_PARAMS			4
#define	XSI_TRIANGLESTRIP_LIST_ARRAY				4

#define XSI_SHAPE_ANIM_TYPE					0
#define XSI_SHAPE_ANIM_NBSHAPE				1
#define XSI_SHAPE_ANIM_NUM_PARAMS			2

#define XSI_USERDATABLOB_SIZE			0
#define XSI_USERDATABLOB_NUM_PARAMS		1
#define XSI_USERDATABLOB_ARRAY			1

#define XSI_TRANSFORM_POSX					0
#define XSI_TRANSFORM_POSY					1
#define XSI_TRANSFORM_POSZ					2
#define XSI_TRANSFORM_ROTX					3
#define XSI_TRANSFORM_ROTY					4
#define XSI_TRANSFORM_ROTZ					5
#define XSI_TRANSFORM_ROTATION_ORDER		6
#define XSI_TRANSFORM_SCLX					7
#define XSI_TRANSFORM_SCLY					8
#define XSI_TRANSFORM_SCLZ					9
#define XSI_TRANSFORM_HIERARCHICAL_SCALING	10
#define XSI_TRANSFORM_SCLORIX				11
#define XSI_TRANSFORM_SCLORIY				12
#define XSI_TRANSFORM_SCLORIZ				13
#define XSI_TRANSFORM_PPOSX					14
#define XSI_TRANSFORM_PPOSY			    	15
#define XSI_TRANSFORM_PPOSZ					16
#define XSI_TRANSFORM_PROTX					17
#define XSI_TRANSFORM_PROTY					18
#define XSI_TRANSFORM_PROTZ					19
#define XSI_TRANSFORM_PSCLX					20
#define XSI_TRANSFORM_PSCLY					21
#define XSI_TRANSFORM_PSCLZ					22
#define XSI_TRANSFORM_PCPOSX				23
#define XSI_TRANSFORM_PCPOSY				24
#define XSI_TRANSFORM_PCPOSZ				25
#define XSI_TRANSFORM_PCROTX				26
#define XSI_TRANSFORM_PCROTY				27
#define XSI_TRANSFORM_PCROTZ				28
#define XSI_TRANSFORM_PCSCLX				29
#define XSI_TRANSFORM_PCSCLY				30
#define XSI_TRANSFORM_PCSCLZ				31
#define XSI_TRANSFORM_NPOSX					32
#define XSI_TRANSFORM_NPOSY					33
#define XSI_TRANSFORM_NPOSZ					34
#define XSI_TRANSFORM_NROTX					35
#define XSI_TRANSFORM_NROTY					36
#define XSI_TRANSFORM_NROTZ					37
#define XSI_TRANSFORM_NSCLX					38
#define XSI_TRANSFORM_NSCLY					39
#define XSI_TRANSFORM_NSCLZ					40
#define XSI_TRANSFORM_NSCLORIX				41
#define XSI_TRANSFORM_NSCLORIY				42
#define XSI_TRANSFORM_NSCLORIZ				43
#define XSI_TRANSFORM_NUM_PARAMS			44

#define XSI_BASEPOSE_POSX				0
#define XSI_BASEPOSE_POSY				1
#define XSI_BASEPOSE_POSZ				2
#define XSI_BASEPOSE_ROTX				3
#define XSI_BASEPOSE_ROTY				4
#define XSI_BASEPOSE_ROTZ				5
#define XSI_BASEPOSE_SCLX				6
#define XSI_BASEPOSE_SCLY				7
#define XSI_BASEPOSE_SCLZ				8
#define XSI_BASEPOSE_NUM_PARAMS			9

#define XSI_LIMIT_PARAMETER_NAME		0
#define XSI_LIMIT_MINIMUM_ACTIVE		1
#define XSI_LIMIT_MINIMUM				2
#define XSI_LIMIT_MAXIMUM_ACTIVE		3
#define XSI_LIMIT_MAXIMUM				4
#define XSI_LIMIT_NUM_PARAMS			5

//***************************************************************************************
// Registration
//***************************************************************************************
extern	TemplateCreation	RegistrationTable50[];

/*! XSI_Mesh template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Mesh template
*/
CdotXSITemplate*	Register_XSI_Mesh();

/*! XSI_Shape template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Shape template
*/
CdotXSITemplate*	Register_XSI_Shape();

/*! XSI_ShapeAnimation template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_ShapeAnimation template
*/
CdotXSITemplate*	Register_XSI_ShapeAnimation();

/*! XSI_SubComponentAttributeList template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_SubComponentAttributeList template
*/
CdotXSITemplate*	Register_XSI_SubComponentAttributeList();

/*! XSI_VertexList template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_VertexList template
*/
CdotXSITemplate*	Register_XSI_VertexList();

/*! XSI_TriangleList template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_TriangleList template
*/
CdotXSITemplate*	Register_XSI_TriangleList();

/*! XSI_PolygonList template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_PolygonList template
*/
CdotXSITemplate*	Register_XSI_PolygonList();

/*! XSI_TriangleStripList template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_TriangleStripList template
*/
CdotXSITemplate*	Register_XSI_TriangleStripList();

/*! XSI_UserDataBlob template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_UserDataBlob template
*/
CdotXSITemplate*	Register_XSI_UserDataBlob();

/*! XSI_Transform template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Transform template
*/
CdotXSITemplate*	Register_XSI_Transform();

/*! XSI_BasePose template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_BasePose template
*/
CdotXSITemplate*	Register_XSI_BasePose();

/*! XSI_CustomPSet template registration function for version 5.0
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_CustomPSet template
*/
CdotXSITemplate*	Register_XSI_CustomPSet50();

/*! XSI_Limit template registration function
* \return CdotXSITemplate* an instance of CdotXSITemplate that supports the XSI_Limit template
*/
CdotXSITemplate*	Register_XSI_Limit();

#endif //DOTXSI_50_DEFINED

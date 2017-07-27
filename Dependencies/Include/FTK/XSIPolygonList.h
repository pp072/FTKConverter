//***************************************************************************************
//
// File supervisor: Softimage 3D Games & 3D Bridge team
//
// (c) Copyright 2001-2005 Avid Technology, Inc. . All rights reserved.
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

#ifndef _XSIPOLYGONLIST_H
#define _XSIPOLYGONLIST_H

#include "XSISubComponentList.h"
#include "Material.h"
#include "Scene.h"
#include "Model.h"
#include "XSIIndexList.h"

//!Describes a list of n-sided polygons for dotXSI 5.0+
/**
* The CSLXSIPolygonList class describes a list of polygons that are made up of N number of vertices.
* The polynodes in this list can have N number of attibutes like vertex, normals, UV and color information. 
*
* To find out, you may use GetVertexIndices() to get the mendatory vertex index attributes and
* the parent class (CSLXSISubComponentList) functionality to get the other generic attributes index.
*
* To get the number of polygons in the list, use GetPolygonCount(). 
* To find out how many vertices a particular polygon uses, get the list of polygon vertex count
* using GetPolygonNodeCountArray().
* 
*/
class XSIEXPORT CSLXSIPolygonList
	: public CSLXSISubComponentList
{
public:
	/**
	* Proxy class that allows modifying a list of SI_Int like an array.
	*/
	typedef CSLArrayProxy<SI_Int, SI_Int, 1> CSLIntArray;

	/*! Constructor	
	* \param in_pScene Parent scene
	* \param in_pModel Parent model
	* \param in_pTemplate Refered template
	* \return an instance of CSLXSIPolygonList
	*/
	CSLXSIPolygonList(CSLScene *in_pScene, CSLModel *in_pModel, CdotXSITemplate *in_pTemplate);

	/*! Destructor
	*/
	virtual ~CSLXSIPolygonList();

	/*! Returns the type of this template (XSI_POLYGON_LIST)
		\return CSLTemplate::ETemplateType The type of this template (XSI_POLYGON_LIST)
	*/
	virtual ETemplateType			Type() { return XSI_POLYGON_LIST; }

	/*!	Return the material object of the polygon list.
		\return	CSLBaseMaterial*	Material object.
	*/
	CSLBaseMaterial*				GetMaterial() { return m_pMaterial; }

	/*! Return the material object name of the polygon list or an empty string if there's none.
		\return CSIBCString			Material object name.
	*/
	CSIBCString						GetMaterialName();

	/*!	Change the material object of the polygon list.
		\param	CSLBaseMaterial*	New material object.
		\return	None
	*/
	SI_Void							SetMaterial(CSLBaseMaterial *in_pNewMaterial);

	/*!	Change the material object name of the polygon list. Should ONLY be called if we don't export the material.
		\param	const CSIBCString&	New material object name.
		\return	None
	*/
	SI_Void							SetMaterialName(const CSIBCString& in_szNewMaterialName);

	/*! Get the number of polygon.
	* \return	SI_Int	Number of polygon.
	*/
	SI_Int							GetPolygonCount();

	/*! Get the polygon count array.
	* \return	CSLIntArray	Array of polygon node count.
	*/
	CSLIntArray*					GetPolygonNodeCountArray();

	/*! Get the polynode vertex indices array.
	* \return	CSLIntArray	Array of polynode vertex indices.
	*/
	CSLIntArray*					GetVertexIndices();

	/*! Commit the current template information
		\return SI_Error Whether or not the commit was successful
	*/
	SI_Error Synchronize();

	/*! Set the number of polynode in this polygon list.
	* \return	SI_Error	Error code.
	*/
	virtual SI_Error					SetCount(SI_Int);

	//**********************************************************************************
	// Index position helper (always only one index position list)
	//**********************************************************************************

	/*!	Connect a new index list.
	* \return	CSLXSIIndexList		The newly connected index list.
	*/
	CSLXSIIndexList*	ConnectIndexList( CSLXSIIndexList* in_pNewXSIIndexList );

	/*!	Add a new index list. If an index list already exists, it will be deleted, and replaced.
	* \return	CSLXSIIndexList*	Pointer to the newly created index list.
	*/
	virtual CSLXSIIndexList*	AddIndexList();

	/*!	Get the index list. May return NULL if it does not exist.
	* \return	CSLXSIIndexList*	Pointer to the index list.
	*/
	CSLXSIIndexList*	GetIndexList();

	/*!	Remove the index list.
	* \return	SI_Error	Error code.
	*/
	SI_Error							RemoveIndexList();

private:
	CSLIntArray						m_PolygonNodeCountArray;

	CSLIntArray						m_VertexIndices;

	CSLBaseMaterial*				m_pMaterial;

	CSIBCString						m_szMaterialName;

	CSLXSIIndexList *				m_IndexList;

	void *m_pReserved;	// reserved for future extension
};

#endif

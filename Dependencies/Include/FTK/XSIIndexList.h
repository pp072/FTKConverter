//***************************************************************************************
//
// File supervisor: Softimage Crosswalk team
//
// (c) Copyright 2001-2007 Avid Technology, Inc. . All rights reserved.
//
//***************************************************************************************

/****************************************************************************************
THIS CODE IS PUBLISHED AS A SAMPLE ONLY AND IS PROVIDED "AS IS".
IN NO EVENT SHALL SOFTIMAGE, AVID TECHNOLOGY, INC. AND/OR THEIR RESPECTIVE
SUPPLIERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY
DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS CODE .

COPYRIGHT NOTICE. Copyright © 1999-2007 Avid Technology Inc. . All rights reserved.

SOFTIMAGE is a registered trademark of Avid Technology Inc. or its subsidiaries
or divisions. Windows NT is a registered trademark of Microsoft Corp. All other
trademarks contained herein are the property of their respective owners.
****************************************************************************************/

#ifndef _XSIINDEXLIST_H
#define _XSIINDEXLIST_H

#include "Template.h"


//! Index list class for dotXSI 6.0+
/**
* Describes an index list
*
* The CSLXSIIndexList holds a list of values for a specific attribute of a given type and semantic.
*
* This class allows an attribute (position, normal, color, texcoord, etc.) to be associated with vertices or polynodes.
*/
class XSIEXPORT CSLXSIIndexList
	: public CSLTemplate
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
	* \param in_Type the type of attribute to construct
	* \return an instance of CSLXSIIndexList
	*/
	CSLXSIIndexList(CSLScene *in_pScene, CSLModel *in_pModel, CdotXSITemplate *in_pTemplate);

	/*! Destructor
	*/
	virtual ~CSLXSIIndexList();

	/*! Get the number of values in the attribute list.
	* \return	SI_Int	Number of attribute values.
	*/
	SI_Int							GetCount();

	/*! Get the the attribute value array so that the values can be edited.
	* \return	CSLIntArray*	The attribute value array.
	*/
	CSLIntArray*					GetIndexArray() { return &m_IndexArray; }

	/*! Get the template type
	* \return ETemplateType the template type of the index list (XSI_INDEX_LIST)
	*/
	virtual ETemplateType			Type() { return XSI_INDEX_LIST; }

	/*! Commit the current template information
		\return SI_Error Whether or not the commit was successful
	*/
	virtual SI_Error Synchronize();

private:
	CSLIntArray						m_IndexArray;

	void *m_pReserved;	// reserved for future extension
};

#endif

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

#ifndef _COLLADAINDEXLIST_H
#define _COLLADAINDEXLIST_H

#include "COLLADATemplate.h"
#include "XSIIndexList.h"


//! Index attribute list class for dotXSI 6.0+
/**
* Describes an index list
*
* The CSLXSIIndexList holds a list of polygon indices values.
*
* This class allows an attribute (position, normal, color, texcoord, etc.) to be associated with vertices or polynodes.
*/
class XSIEXPORT CSLCOLLADAIndexList
	: public CSLXSIIndexList
{
public:

	CSLCOLLADAIndexList(CSLScene *in_pScene, CSLModel *in_pModel, CdotXSITemplate *in_pTemplate);

	/*! Destructor
	*/
	virtual ~CSLCOLLADAIndexList();

	virtual SI_Error	Synchronize();

private:

};

#endif

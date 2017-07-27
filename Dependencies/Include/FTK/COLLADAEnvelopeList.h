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

#ifndef _COLLADAENVELOPELIST_H
#define _COLLADAENVELOPELIST_H

#include "EnvelopeList.h"
#include "COLLADAEnvelope.h"
 
typedef CSIBCArray<CSLCOLLADAEnvelope*>	EnvelopeGroup;

//! Describes the envelope list.
class XSIEXPORT CSLCOLLADAEnvelopeList
	: public CSLEnvelopeList
{
public:
	/*! Constructor
	* \param in_pScene	Pointer to the scene containing the envelope
	* \param in_pModel	Pointer to the model containing the envelope
	* \param in_pTemplate	Pointer to the CdotXSITemplate containing the envelope
	* \return an instance of CSLEnvelope
	*/
	CSLCOLLADAEnvelopeList(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);

	/*! Destructor
	*/
	virtual ~CSLCOLLADAEnvelopeList();

	/*!	Add a new envelope to the list.
	* \return	CSLEnvelope*	Pointer to the newly created envelope object.
	*/
	CSLEnvelope* AddEnvelope();

	/*! Synchronizes this envelope list instance with its IO layer representation
	* \return SI_Error
	* \retval SI_SUCCESS this function always returns SI_SUCCESS
	*/
    virtual SI_Error Synchronize();

private:

	SI_Void	ExportGroup ( EnvelopeGroup* in_pGroup );

	CSIBCArray<EnvelopeGroup> m_Groups;
};

#endif

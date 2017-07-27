//***************************************************************************************
//
// File supervisor: Softimage Rendering & Pipeline team
//
// (c) Copyright 2001-2005 Avid Technology, Inc. . All rights reserved.
//
//***************************************************************************************

/**************************************************************************************
THIS CODE IS PUBLISHED AS A SAMPLE ONLY AND IS PROVIDED "AS IS".
IN NO EVENT SHALL SOFTIMAGE, AVID TECHNOLOGY, INC. AND/OR THEIR RESPECTIVE
SUPPLIERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY
DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS CODE .

COPYRIGHT NOTICE. Copyright © 1999-2005 Avid Technology Inc. . All rights reserved. 

SOFTIMAGE is a registered trademark of Avid Technology Inc. or its subsidiaries 
or divisions. Windows NT is a registered trademark of Microsoft Corp. All other
trademarks contained herein are the property of their respective owners. 
****************************************************************************************/
/*! \file COLLADAEffectLibrary.h
/*!
	COLLADA Effect Library class definition
*/

#ifndef COLLADAEFFECTLIBRARY_H
#define COLLADAEFFECTLIBRARY_H

#include "COLLADATemplate.h"
#include "COLLADAEffect.h"

class XSIEXPORT CSLCOLLADAEffectLibrary : public CSLTemplate
{
public:
	CSLCOLLADAEffectLibrary(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
	virtual ~CSLCOLLADAEffectLibrary();

	/*!	Add a new Effect to the Effect library.
		\return	CSLEffect*	Pointer to the newly created Effect object.
	*/
	CSLCOLLADAFX* AddEffect();

	/*!	Remove all Effects from the Effect library.
		\return	SI_Error	Error code.
	*/
	SI_Error ClearEffects();

	/*!	Return an array of all Effects in the library.
		\return	CSLCOLLADAFX**	Array of pointers to Effect objects.
	*/
	CSLCOLLADAFX** GetEffectList();

	/*!	Return the number of Effects in the library.
		\return	SI_Int	Number of Effects.
	*/
	SI_Int GetEffectCount();

	/*!	Remove a single Effect from the library.
		\param	SI_Int	Index of the Effect to remove.
		\return	SI_Error	Error code.
	*/
	SI_Error RemoveEffect(SI_Int in_nIndex);

	/*!	Remove a single Effect from the library.
		\param	CSLCOLLADAFX*	Pointer to the Effect to remove.
		\return	SI_Error	Error code.
	*/
	SI_Error RemoveEffect(CSLCOLLADAFX *in_pEffect);

	CSLCOLLADAFX* FindEffect( const SI_Char* in_szName );

	CSLCOLLADAFX* ConnectEffect(CSLCOLLADAFX* in_pNewEffect);

    virtual SI_Error Synchronize();
	virtual ETemplateType Type();

private:
	CSIBCArray<CSLCOLLADAFX *>	m_Effects;

	void*							m_pReserved;
};


#endif // COLLADAEFFECTLIBRARY_H


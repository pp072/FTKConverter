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

#ifndef _COLLADAFCURVE_H
#define _COLLADAFCURVE_H

#include "FCurve.h"
#include "SL_Enum.h"

#define ELEM_TIME		0
#define ELEM_VALUE		1
#define ELEM_IN_TAN		2
#define ELEM_OUT_TAN	3
#define ELEM_INTERP		4


//! CSLCOLLADAFCurve class
class XSIEXPORT CSLCOLLADAFCurve
    : public CSLFCurve
{
public:
	/*! Constructor
	* \param in_pScene	Pointer to the scene containing the fcurve
	* \param in_pModel	Pointer to the model containing the fcurve
	* \param in_pTemplate	Pointer to the CdotXSITemplate containing the fcurve
	* \param in_Type	Type of fcurve
	* \param in_InterpolationType	Interpolation type for this fcurve
	* \param in_pParamReference	Reference to the CSLAnimatableType that this fcurve animates
	* \return an instance of CSLFCurve
	*/
    CSLCOLLADAFCurve
	(
		CSLScene* in_pScene,
		CSLModel *in_pModel,
		CdotXSITemplate* in_pTemplate, 
		EFCurveType in_Type,
		EFCurveInterpolationType in_InterpolationType,
		CSLAnimatableType *in_pParamReference
	);

	/*! Destructor
	*/
    virtual ~CSLCOLLADAFCurve();

	/*! Synchronizes this fcurve instance with its IO layer representation
	* \return SI_Error
	* \retval SI_SUCCESS this function always returns SI_SUCCESS
	*/
    virtual SI_Error Synchronize();

	/*! Connects an existing COLLADA animation template
	* \param in_offset	Offset when reading data. Needed to synchronized with stride attribut
	* \return SI_Error
	*/
    virtual SI_Error ConnectCOLLADAAnimation( CCOLLADATemplate* in_pChannel, const int in_offset = 0);

	/*! Returns the parameter reference
	* \return the parameter reference
	*/

	virtual CSLAnimatableType* ParameterReference();
private:

	SI_Void		GetFloatArrayFromCurve ( CSIBCArray<float>& inout_Array, int in_iElement );
	SI_Void		AddSource ( CCOLLADATemplate* in_pAnimation, 
							int in_iElement, 
							SI_Char* in_szPrefix, 
							SI_Char* in_szID, 
							SI_Char* in_szOutput,
							CCOLLADATemplate* in_pSampler);
	
	CSLAnimatableType *m_pParamReference;
};

#endif

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

#ifndef _COLLADAINSTANCE_H
#define _COLLADAINSTANCE_H

#include <Instance.h> 

//! Describes an instance primitive..
class XSIEXPORT CSLCOLLADAInstance
	: public CSLInstance
{
public:
	/*! Constructor
	* \param in_pScene	Pointer to the scene containing the instance
	* \param in_pModel	Pointer to the model containing the instance
	* \param in_pTemplate	Pointer to the CdotXSITemplate containing the instance
	* \return an instance of CSLInstance
	*/
	CSLCOLLADAInstance(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate) : CSLInstance(in_pScene, in_pModel, in_pTemplate){};

	/*! Destructor
	*/
	virtual ~CSLCOLLADAInstance() {};

	/*! Synchronizes this instance with its IO layer representation
	* \return SI_Error
	* \retval SI_SUCCESS this function always returns SI_SUCCESS
	*/
    virtual SI_Error Synchronize();

private:

	void *m_pReserved;	// reserved for future extension
};

#endif //_COLLADAINSTANCE_H
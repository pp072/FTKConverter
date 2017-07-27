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

#ifndef _XSISHADERMULTIPORTCONNECTION_H
#define _XSISHADERMULTIPORTCONNECTION_H

#include "Template.h"

class CSLVariantParameter;

/*! A shader multi-port connection describes to which port a given shader parameter
	is connected on a multiple output port shader.

	\sa CSLXSIShader
	\sa CSLXSIShaderMultiPort
*/
class XSIEXPORT CSLXSIShaderMultiPortConnection
    : public CSLTemplate
{
public:

	/*! Constructor
		\param in_pScene	Pointer to the scene containing the CSLXSIShaderMultiPortConnection
		\param in_pModel	Pointer to the model containing the CSLXSIShaderMultiPortConnection
		\param in_pTemplate	Pointer to the CdotXSITemplate defining the CSLXSIShaderMultiPortConnection
	*/
    CSLXSIShaderMultiPortConnection(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);

	/*! Destructor
	*/
    virtual ~CSLXSIShaderMultiPortConnection();

	SI_Error Synchronize();

	/*! Gets the type of this template
		\return CSLTemplate::XSI_SHADER_MULTI_PORT_CONNECTION
	*/
	CSLTemplate::ETemplateType Type(){ return CSLTemplate::XSI_SHADER_MULTI_PORT_CONNECTION; }

	/*! Gets the name of the parameter to which this CSLXSIShaderMultiPortConnection applies to
		\retval SI_Char The name of the parameter
	*/
	SI_Char* GetParameter();

	/*! Sets the name of the parameter to which this CSLXSIShaderMultiPortConnection applies to
		\param in_pParameter The name of the parameter
	*/
	SI_Void				SetParameter(SI_Char* in_pParameter);

	/*! Gets the parameter name proxy 
		\return CSLStringProxy* Pointer to parameter name proxy
	*/
	CSLStringProxy*		GetParameterProxy(){return &m_szParameter;};

	/*! Gets the name of the port connected to the parameter
		\return SI_Char The name of the port
	*/
	SI_Char*			GetPortName();

	/*! Sets the name of the port connected to the parameter
		\param in_szPortName The name of the port connected to the parameter
	*/
	SI_Void				SetPortName( SI_Char* in_pPortName );

	/*! Gets the port name proxy 
		\return CSLStringProxy* Pointer to port name proxy
	*/
	CSLStringProxy*		GetPortNameProxy(){return &m_szPortName;};

private:
	CSLStringProxy m_szParameter;
	CSLStringProxy m_szPortName;
	SI_Void *m_pReserved;
};

#endif // XSISHADERMULTIPORTCONNECTION

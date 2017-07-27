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
#ifndef _XSITEXTURELAYER_H
#define _XSITEXTURELAYER_H

#include "Template.h"

class CSLXSITextureLayerPort;
class CSLXSIShaderMultiPortConnection;

/** 
* Class CSLXSITextureLayer
*
* Defines more image effects
* \note This template was introduced in dotXSI Version 6.0
*/

class XSIEXPORT CSLXSITextureLayer
    : public CSLTemplate
{
public:
	/*! Constructor
		\param in_pScene Parent scene
		\param in_pModel Parent model
		\param in_pTemplate Refered template
	*/
	CSLXSITextureLayer(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);

	//! Destructor
	virtual ~CSLXSITextureLayer();

	/*! Commit the current template information
		\return SI_Error Whether or not the commit was successful
	*/
	SI_Error Synchronize();

	/*! Gets the type of this template
		\return ETemplateType The type of this template (XSI_TEXTURE_LAYER)
	*/
	ETemplateType Type(){ return XSI_TEXTURE_LAYER; }

    virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);

	virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szParameterName);

	/*! Get the Order value
		\return SI_Float	Order
	*/
	SI_Int GetOrder();

	/*! Set the Order value
		\param	SI_Float	new Order value
	*/
	SI_Void SetOrder( SI_Int in_nValue );

	/*! Get the Mute value
		\return SI_Float	Mute
	*/
	SI_Bool GetMute();

	/*! Set the Mute value
		\param	SI_Float	new Mute value
	*/
	SI_Void SetMute( SI_Bool in_bValue );

	/*! Get the Solo value
		\return SI_Float	Solo
	*/
	SI_Bool GetSolo();

	/*! Set the Solo value
		\param	SI_Float	new Solo value
	*/
	SI_Void SetSolo( SI_Bool in_bValue );

	/*! Get the ColorConnection value
		\return SI_Char*	ColorConnection
	*/
	SI_Char* GetColorConnection();

	/*! Set the ColorConnection value
		\param	SI_Char*	new ColorConnection value
	*/
	SI_Void SetColorConnection( SI_Char* in_pValue );

	/*! Get the Red value
		\return SI_Float	Red
	*/
	SI_Float GetRed();

	/*! Set the Red value
		\param	SI_Float	new Red value
	*/
	SI_Void SetRed( SI_Float in_fValue );

	/*! Get the Green value
		\return SI_Float	Green
	*/
	SI_Float GetGreen();

	/*! Set the Green value
		\param	SI_Float	new Green value
	*/
	SI_Void SetGreen( SI_Float in_fValue );

	/*! Get the Blue value
		\return SI_Float	Blue
	*/
	SI_Float GetBlue();

	/*! Set the Blue value
		\param	SI_Float	new Blue value
	*/
	SI_Void SetBlue( SI_Float in_fValue );

	/*! Get the Alpha value
		\return SI_Float	Alpha
	*/
	SI_Float GetAlpha();

	/*! Set the Alpha value
		\param	SI_Float	new Alpha value
	*/
	SI_Void SetAlpha( SI_Float in_fValue );

	/*! Get the ColorPremultiplied value
		\return SI_Float	ColorPremultiplied
	*/
	SI_Bool GetColorPremultiplied();

	/*! Set the ColorPremultiplied value
		\param	SI_Float	new ColorPremultiplied value
	*/
	SI_Void SetColorPremultiplied( SI_Bool in_bValue );

	/*! Get the IgnoreColorAlpha value
		\return SI_Float	IgnoreColorAlpha
	*/
	SI_Bool GetIgnoreColorAlpha();

	/*! Set the IgnoreColorAlpha value
		\param	SI_Float	new IgnoreColorAlpha value
	*/
	SI_Void SetIgnoreColorAlpha( SI_Bool in_bValue );

	/*! Get the InvertColorAlpha value
		\return SI_Float	InvertColorAlpha
	*/
	SI_Bool GetInvertColorAlpha();

	/*! Set the InvertColorAlpha value
		\param	SI_Float	new InvertColorAlpha value
	*/
	SI_Void SetInvertColorAlpha( SI_Bool in_bValue );

	/*! Get the AlphaColor value
		\return SI_Float	AlphaColor
	*/
	SI_Bool GetAlphaColor();

	/*! Set the AlphaColor value
		\param	SI_Float	new AlphaColor value
	*/
	SI_Void SetAlphaColor( SI_Bool in_bValue );

	/*! Get the MaskConnection value
		\return SI_Char*	MaskConnection
	*/
	SI_Char* GetMaskConnection();

	/*! Set the MaskConnection value
		\param	SI_Char*	new MaskConnection value
	*/
	SI_Void SetMaskConnection( SI_Char* in_pValue );

	/*! Get the Mask value
		\return SI_Float	Mask
	*/
	SI_Float GetMask();

	/*! Set the Mask value
		\param	SI_Float	new Mask value
	*/
	SI_Void SetMask( SI_Float in_fValue );

	/*! Get the InvertMask value
		\return SI_Float	InvertMask
	*/
	SI_Bool GetInvertMask();

	/*! Set the InvertMask value
		\param	SI_Float	new InvertMask value
	*/
	SI_Void SetInvertMask( SI_Bool in_bValue );

	/*! Get the MaskMode value
		\return SI_Float	MaskMode
	*/
	SI_Int GetMaskMode();

	/*! Set the MaskMode value
		\param	SI_Float	new MaskMode value
	*/
	SI_Void SetMaskMode( SI_Int in_nValue );

	/*! Get the MaskThreshold value
		\return SI_Float	MaskThreshold
	*/
	SI_Float GetMaskThreshold();

	/*! Set the MaskThreshold value
		\param	SI_Float	new MaskThreshold value
	*/
	SI_Void SetMaskThreshold( SI_Float in_fValue );

	/*! Get the Weight value
		\return SI_Float	Weight
	*/
	SI_Float GetWeight();

	/*! Set the Weight value
		\param	SI_Float	new Weight value
	*/
	SI_Void SetWeight( SI_Float in_fValue );

	/*! Get the Mode value
		\return SI_Float	Mode
	*/
	SI_Int GetMode();

	/*! Set the Mode value
		\param	SI_Float	new Mode value
	*/
	SI_Void SetMode( SI_Int in_nValue );

	CSLIntProxy*	GetOrderProxy() { return &m_Order; };
	CSLBoolProxy*	GetMuteProxy() { return &m_Mute; };
	CSLBoolProxy*	GetSoloProxy() { return &m_Solo; };
	CSLStringProxy*	GetColorConnectionProxy() { return &m_ColorConnection; };
	CSLFloatProxy*	GetRedProxy() { return &m_Red; };
	CSLFloatProxy*	GetGreenProxy() { return &m_Green; };
	CSLFloatProxy*	GetBlueProxy() { return &m_Blue; };
	CSLFloatProxy*	GetAlphaProxy() { return &m_Alpha; };
	CSLBoolProxy*	GetColorPremultipliedProxy() { return &m_ColorPremultiplied; };
	CSLBoolProxy*	GetIgnoreColorAlphaProxy() { return &m_IgnoreColorAlpha; };
	CSLBoolProxy*	GetInvertColorAlphaProxy() { return &m_InvertColorAlpha; };
	CSLBoolProxy*	GetAlphaColorProxy() { return &m_AlphaColor; };
	CSLStringProxy*	GetMaskConnectionProxy() { return &m_MaskConnection; };
	CSLFloatProxy*	GetMaskProxy() { return &m_Mask; };
	CSLBoolProxy*	GetInvertMaskProxy() { return &m_InvertMask; };
	CSLIntProxy*	GetMaskModeProxy() { return &m_MaskMode; };
	CSLFloatProxy*	GetMaskThresholdProxy() { return &m_MaskThreshold; };
	CSLFloatProxy*	GetWeightProxy() { return &m_Weight; };
	CSLIntProxy*	GetModeProxy() { return &m_Mode; };

	///////////////////////////////////////////////////////////////////////
	// Texture Layer port functionality ////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	
	/*! Add a texture layer port to the texture layer port list
		\return					The added texture layer port
	*/
	CSLXSITextureLayerPort* AddTextureLayerPort();

	/*! Remove a texture layer port from the texture layer port list
		\param in_nIndex	Index of the texture layer port to remove
	*/
	SI_Error RemoveTextureLayerPort(SI_Int in_nIndex);

	/*! Remove a texture layer port from the texture layer port list
		\param in_pToRemove	The texture layer port to remove
	*/
	SI_Error RemoveTextureLayerPort(CSLXSITextureLayerPort* in_pToRemove);

	/*! Get the CSLXSITextureLayerPort object by index.
		\param in_nIndex	Index of the texture layer port to get
		\return CSLXSITextureLayerPort  The CSLXSITextureLayerPort.
	*/
	CSLXSITextureLayerPort* GetTextureLayerPort(SI_Int in_nIndex);

	/*! Get the number of texture layer port in the texture layer port list
		\return SI_Int The number of texture layer port in the texture layer port list
	*/
	SI_Int GetTextureLayerPortCount();

	/*! Deletes all the texture layer port form the texture layer port list
	*/
	SI_Error ClearTextureLayerPorts();

	/*! Gets a pointer to the internally-stored texture layer port pointer list
		\return CSLXSITextureLayerPort Pointer to the list
	*/
	CSLXSITextureLayerPort** GetTextureLayerPortList();

	/*! Adds an exisiting texture layer port to the texture layer port list
		\param in_pToConnect Pointer to the texture layer port to add
		\return The added texture layer port
	*/
	CSLXSITextureLayerPort* ConnectTextureLayerPort( CSLXSITextureLayerPort* in_pToConnect );

	///////////////////////////////////////////////////////////////////////
	// Multi Port Connection functionality ////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	
	/*! Add a multi port connection to the multi port connection list
		\param in_pParameter	Name of the new multi port connection parameter
		\param in_pPortName		Name of the new multi port connection port name
		\return					The added multi port connection
	*/
	CSLXSIShaderMultiPortConnection* AddMultiPortConnection();

	/*! Remove a multi port connection from the multi port connection list
		\param in_nIndex	Index of the multi port connection to remove
	*/
	SI_Error RemoveMultiPortConnection(SI_Int in_nIndex);

	/*! Remove a multi port connection from the multi port connection list
		\param in_pToRemove	The multi port connection to remove
	*/
	SI_Error RemoveMultiPortConnection(CSLXSIShaderMultiPortConnection* in_pToRemove);

	/*! Get the CSLXSIShaderMultiPortConnection object of a given multi port connection by index.
		\param in_nIndex	Index of the multi port connection to get
		\return CSLXSIShaderMultiPortConnection  The CSLXSIShaderMultiPortConnection that holds the name and the type of a multi port connection.
	*/
	CSLXSIShaderMultiPortConnection* GetMultiPortConnection(SI_Int in_nIndex);

	/*! Get the CSLXSIShaderMultiPortConnection object of a given multi port connection by parameter name.
		\param in_pParameter						Name of the multi port connection parameter you're looking for
		\return CSLXSIShaderMultiPortConnection		Pointer to the CSLXSIShaderMultiPortConnection found
		\return NULL								If not found
	*/
	CSLXSIShaderMultiPortConnection* GetMultiPortConnectionByParameter(SI_Char* in_pParameter);

	/*! Get the number of multi port connection in the multi port connection list
		\return SI_Int The number of multi port connection in the multi port connection list
	*/
	SI_Int GetMultiPortConnectionCount();

	/*! Deletes all the multi port connection form the multi port connection list
	*/
	SI_Error ClearMultiPortConnections();

	/*! Gets a pointer to the internally-stored multi port connection pointer list
		\return CSLXSIShaderMultiPortConnection Pointer to the list
	*/
	CSLXSIShaderMultiPortConnection** GetMultiPortConnectionList();

	/*! Adds an exisiting multi port connection to the multi port connection list
		\param in_pToConnect Pointer to the multi port connection to add
		\return The added multi port connection
	*/
	CSLXSIShaderMultiPortConnection* ConnectMultiPortConnection( CSLXSIShaderMultiPortConnection* in_pToConnect );

	/*! Search the multi port connection list for one with a corresponding parameter name
		\param in_pName The parameter name to look for
		\return Pointer on the multi port connection if found, NULL if not found
	*/
	CSLXSIShaderMultiPortConnection* FindMultiPortConnectionByParameterName(SI_Char *in_pName);

private:
	CSLIntProxy		m_Order;
	CSLBoolProxy	m_Mute;
	CSLBoolProxy	m_Solo;
	CSLStringProxy	m_ColorConnection;
	CSLFloatProxy	m_Red;
	CSLFloatProxy	m_Green;
	CSLFloatProxy	m_Blue;
	CSLFloatProxy	m_Alpha;
	CSLBoolProxy	m_ColorPremultiplied;
	CSLBoolProxy	m_IgnoreColorAlpha;
	CSLBoolProxy	m_InvertColorAlpha;
	CSLBoolProxy	m_AlphaColor;
	CSLStringProxy	m_MaskConnection;
	CSLFloatProxy	m_Mask;
	CSLBoolProxy	m_InvertMask;
	CSLIntProxy		m_MaskMode;
	CSLFloatProxy	m_MaskThreshold;
	CSLFloatProxy	m_Weight;
	CSLIntProxy		m_Mode;

	CSIBCArray<CSLXSITextureLayerPort*> m_TextureLayerPorts;

	CSIBCArray<CSLXSIShaderMultiPortConnection *> m_MultiPortConnections;

	SI_Void *m_pReserved;
};

#endif

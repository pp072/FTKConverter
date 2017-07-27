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

#ifndef _XSIMATERIAL_H
#define _XSIMATERIAL_H

#include "Material.h"

class CSLConnectionPoint;
class CSLXSIShader;
class CSLXSIMaterialInfo;
class CSLXSIShaderMultiPortConnection;
class CSLXSITextureLayer;

/** 
* Class CSLXSIMaterial
*
* Describes an XSIMaterial
*
* The role of the XSIMaterial class is to help build a shader tree that describes an effect.
* They are containers of CSLXSIShader objects and CSLConnectionPoint objects.
*
* To get more information on XSI Material, see also the SOFTIMAGE|XSI Documentation on the
* render tree and the SOFTIMAGE|XSI SDK Documentation on Realtime Shaders.
*
* \note This template was introduced in dotXSI Version 3.6
*/
class XSIEXPORT CSLXSIMaterial
    : public CSLBaseMaterial
{
public:
	/*! Constructor
		\param in_pScene Parent scene
		\param in_pModel Parent model
		\param in_pTemplate Refered template
	*/
    CSLXSIMaterial(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
	
	//! Destructor
	virtual ~CSLXSIMaterial();

	/*! Returns the type of this template (XSI_MATERIAL)
		\return CSLTemplate::ETemplateType The type of this template (XSI_MATERIAL)
	*/
	CSLTemplate::ETemplateType Type(){ return XSI_MATERIAL; }

	/*! Commit the current template information
		\return SI_Error Whether or not the commit was successful
	*/
	SI_Error Synchronize();

	/*! Searches for a parameter
		\param in_szName Name of the parameter to look for
		\return CSLAnimatableType Pointer to the found parameter, null otherwise
	*/
	virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);

	///////////////////////////////////////////////////////////////////////////
	// Connection points functionality ////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	
	/*! Add a connection point to the connection point list
		\return CSLConnectionPoint Pointer to the newly added connection point
	*/
	CSLConnectionPoint* AddConnectionPoint();

	/*! Removes a connection point from the connection point list
		\param in_nIndex Index of the connection point to remove
		\return SI_Error Whether or not the connection point could be removed
	*/
	SI_Error RemoveConnectionPoint( SI_Int in_nIndex );

	/*! Removes a connection point from the connection point list
		\param in_pToRemove Pointer to the connection point to remove
		\return SI_Error Whether or not the connection point could be removed
	*/
	SI_Error RemoveConnectionPoint( CSLConnectionPoint* in_pToRemove );

	/*! Removes all connections points from the connection point list
		\return SI_Error Whether or not the list could be cleared
	*/
	SI_Error ClearConnectionPoints();

	/*! Adds an exisiting connection point to the connection point list
		\param in_pToConnect Pointer to the connection point to add
		\return The added connection point or null if it already exists in the list
	*/
	CSLConnectionPoint* ConnectConnectionPoint( CSLConnectionPoint* in_pToConnect );

	/*! Gets a pointer to the internally-stored connection point pointer list
		\return CSLConnectionPoint Pointer to the list
	*/
	CSLConnectionPoint** GetConnectionPointList();

	/*! Gets the total number of connection points 
		\return SI_Int Number of connection points
	*/
	SI_Int GetConnectionPointCount();
	
	///////////////////////////////////////////////////////////////////////////
	// Shaders functionality //////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	
	/*! Adds a shader to the shader list
		\return CSLXSIShaderPointer to the newly added shader
	*/
	CSLXSIShader* AddShader();

	/*! Removes a shader from the shader list
		\param in_nIndex Index of the shader to remove
		\return SI_Error Whether or not the shader could be removed
	*/
	SI_Error RemoveShader( SI_Int in_nIndex );

	/*! Removes a shader from the shader list
		\param in_pToRemove Pointer to the shader to remove
		\return SI_Error Whether or not the shader could be removed
	*/
	SI_Error RemoveShader( CSLXSIShader* in_pToRemove );

	/*! Removes all connections points from the shader list
		\return SI_Error Whether or not the list could be cleared
	*/
	SI_Error ClearShaders();

	/*! Adds an exisiting shader to the shader list
		\param in_pToConnect Pointer to the shader to add
		\return The added shader or null if it already exists in the list
	*/
	CSLXSIShader* ConnectShader( CSLXSIShader* in_pToConnect );

	/*! Gets a pointer to the internally-stored shader pointer list
		\return CSLXSIShader Pointer to the list
	*/
	CSLXSIShader** GetShaderList();

	/*! Gets the total number of Shaders 
		\return SI_Int Number of Shaders
	*/
	SI_Int GetShaderCount();

	/*! Searches for a given shader
		\param in_szShaderName Name of the shader to look for
		\return CSLXSIShader Pointer to the shader or null if it cannot be found
	*/
	CSLXSIShader* FindShader( SI_Char* in_szShaderName );

	///////////////////////////////////////////////////////////////////////////
	// Material Info functionality ////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////

	/*! Creates a new material info
		\return The new material info or null if there's already one
	*/
	CSLXSIMaterialInfo* CreateMaterialInfo();

	/*! Destroys the material info
		\return SI_Error Whether or not the material info could be destroyed
	*/
	SI_Error DestroyMaterialInfo();

	/*! Connects an exisiting material info
		\param in_pToConnect Pointer to the material info to use
		\return The added material info or null if there's already one
	*/
	CSLXSIMaterialInfo* ConnectMaterialInfo( CSLXSIMaterialInfo* in_pToConnect );

	/*! Gets a pointer to the material info
		\return CSLXSIMaterialInfo Pointer to the material info
	*/
	CSLXSIMaterialInfo* GetMaterialInfo();

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

	///////////////////////////////////////////////////////////////////////
	// Texture Layer functionality ////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	
	/*! Add a texture layer to the texture layer list
		\return					The added texture layer
	*/
	CSLXSITextureLayer* AddTextureLayer();

	/*! Remove a texture layer from the texture layer list
		\param in_nIndex	Index of the texture layer to remove
	*/
	SI_Error RemoveTextureLayer(SI_Int in_nIndex);

	/*! Remove a texture layer from the texture layer list
		\param in_pToRemove	The texture layer to remove
	*/
	SI_Error RemoveTextureLayer(CSLXSITextureLayer* in_pToRemove);

	/*! Get the CSLXSITextureLayer object by index.
		\param in_nIndex	Index of the texture layer to get
		\return CSLXSITextureLayer  The CSLXSITextureLayer.
	*/
	CSLXSITextureLayer* GetTextureLayer(SI_Int in_nIndex);

	/*! Search the texture layer list for one with a corresponding order index
		\param in_nOrder	The order index of the texture layer to look for
		\return Pointer on the texture layer if found, NULL if not found
	*/
	CSLXSITextureLayer* FindTextureLayerByOrder(SI_Int in_nOrder);

	/*! Get the number of texture layer in the texture layer list
		\return SI_Int The number of texture layer in the texture layer list
	*/
	SI_Int GetTextureLayerCount();

	/*! Deletes all the texture layer form the texture layer list
	*/
	SI_Error ClearTextureLayers();

	/*! Gets a pointer to the internally-stored texture layer pointer list
		\return CSLXSITextureLayer Pointer to the list
	*/
	CSLXSITextureLayer** GetTextureLayerList();

	/*! Adds an exisiting texture layer to the texture layer list
		\param in_pToConnect Pointer to the texture layer to add
		\return The added texture layer
	*/
	CSLXSITextureLayer* ConnectTextureLayer( CSLXSITextureLayer* in_pToConnect );

// Members
private:
    CSIBCArray<CSLConnectionPoint*> m_ConnectionPoints;
    CSIBCArray<CSLXSIShader*> m_Shaders;
	CSLXSIMaterialInfo *m_pMaterialInfo;
	CSIBCArray<CSLXSIShaderMultiPortConnection *> m_MultiPortConnections;
	CSIBCArray<CSLXSITextureLayer*> m_TextureLayers;

	SI_Void *m_pReserved;	// reserved for future use
};

#endif // _XSIMATERIAL_H

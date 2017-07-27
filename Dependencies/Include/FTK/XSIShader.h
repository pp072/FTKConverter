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

/******************************************************************************\
*
* File:          XSIShader.h
* Creation date: January 23, 2002 10:59
* Author:        ClassBuilder
*                XXXX
* Purpose:       Declaration of class 'CSLXSIShader'
*
* Modifications: @INSERT_MODIFICATIONS(* )
* January 23, 2002 10:59 Frederic O'Reilly
*     Added method 'DestructorInclude'
*     Added method 'ConstructorInclude'
*     Added method '~CSLXSIShader'
*     Added inheritance 'CSLTemplate'
*     Added member 'm_pProgID'
*     Added member 'm_pOutputType'
*     Added member 'm_pConnectionPoints'
*     Added member 'm_pParameters'
*
* Copyright 2002, XXXXX
* All rights are reserved. Reproduction in whole or part is prohibited
* without the written consent of the copyright owner.
*
\******************************************************************************/
#ifndef _XSISHADER_H
#define _XSISHADER_H

#include "Template.h"
class CSLVariantParameter;
class CSLShaderConnectionPoint;
class CSLShaderInstanceData;
class CSLImage;
class CSLXSIShaderMultiPortConnection;
class CSLXSITextureLayer;
class CSLXSIMaterial;

/** 
* Class CSLXSIShader
*
* Describes a single XSI Shader node
* \note This template was introduced in dotXSI Version 3.6
* \sa CSLVariantParameter
* \sa CSLShaderConnectionPoint
* \sa CSLShaderInstanceData
* \sa CSLXSIShaderMultiPortConnection
* \sa CSLXSITextureLayer
*/

class XSIEXPORT CSLXSIShader
    : public CSLTemplate
{
public:

	/*! Constructor
		\param in_pScene Parent scene
		\param in_pModel Parent model
		\param in_pTemplate Refered template
		\param in_pParentMaterial Parent material
	*/
	CSLXSIShader(CSLScene* in_pScene, CSLModel *in_pParentModel, CdotXSITemplate* in_pTemplate, CSLXSIMaterial* in_pParentMaterial = NULL);
    
	//! Destructor
	virtual ~CSLXSIShader();
	
	/*! Commit the current template information
		\return SI_Error Whether or not the commit was successful
	*/
	SI_Error Synchronize();

	/*! Returns the type of this template (XSI_SHADER)
		\return CSLTemplate::ETemplateType The type of this template (XSI_SHADER)
	*/
	CSLTemplate::ETemplateType Type(){ return XSI_SHADER; }	

	// Parameters Functionality ///////////////////////////////////////////////
	/*! Add a parameter to the parameter list
		\return CSLParameter Pointer to the newly added parameter
	*/
	CSLVariantParameter* AddParameter();

	/*! Removes a parameter from the parameter list
		\param in_nIndex Index of the parameter to remove
		\return SI_Error Whether or not the parameter could be removed
	*/
	SI_Error RemoveParameter( SI_Int in_nIndex );

	/*! Removes a parameter from the parameter list
		\param in_pToRemove Pointer to the parameter to remove
		\return SI_Error Whether or not the parameter could be removed
	*/
	SI_Error RemoveParameter( CSLVariantParameter* in_pToRemove );

	/*! Removes all parameters from the parameter list
		\return SI_Error Whether or not the list could be cleared
	*/
	SI_Error ClearParameters();

	/*! Adds an exisiting parameter to the parameter list
		\param in_pToConnect Pointer to the parameter to add
		\return The added parameter or null if it already exists in the list
	*/
	CSLVariantParameter* ConnectParameter( CSLVariantParameter* in_pToConnect );

	/*! Gets a pointer to the internally-stored parameter pointer list
		\return CSLParameter Pointer to the list
	*/
	CSLVariantParameter** GetParameterList();

	/*! Finds a parameter by its name
		\return CSLVariantParameter the parameter
	*/
	CSLVariantParameter* FindParameterByName(char *in_pName);

	/*! Gets the total number of parameters 
		\return SI_Int Number of parameters
	*/
	SI_Int GetParameterCount();

	/*! Searches for a parameter by name
		\param in_szName Name of the parameter to look for
		\return CSLAnimatableType Pointer to the found parameter or null if not found
	*/
	virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);
    virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szParameterName);

	// Connection points functionality ////////////////////////////////////////
	
	/*! Add a connection point to the connection point list
		\return CSLShaderConnectionPoint Pointer to the newly added connection point
	*/
	CSLShaderConnectionPoint* AddConnectionPoint();

	/*! Removes a connection point from the connection point list
		\param in_nIndex Index of the connection point to remove
		\return SI_Error Whether or not the connection point could be removed
	*/
	SI_Error RemoveConnectionPoint( SI_Int in_nIndex );

	/*! Removes a connection point from the connection point list
		\param in_pToRemove Pointer to the connection point to remove
		\return SI_Error Whether or not the connection point could be removed
	*/
	SI_Error RemoveConnectionPoint( CSLShaderConnectionPoint* in_pToRemove );

	/*! Removes all connections points from the connection point list
		\return SI_Error Whether or not the list could be cleared
	*/
	SI_Error ClearConnectionPoints();

	/*! Adds an exisiting connection point to the connection point list
		\param in_pToConnect Pointer to the connection point to add
		\return The added connection point or null if it already exists in the list
	*/
	CSLShaderConnectionPoint* ConnectConnectionPoint( CSLShaderConnectionPoint* in_pToConnect );

	/*! Gets a pointer to the internally-stored connection point pointer list
		\return CSLConnectionPoint Pointer to the list
	*/
	CSLShaderConnectionPoint** GetConnectionPointList();

	/*! Gets the total number of connection points 
		\return SI_Int Number of connection points
	*/
	SI_Int GetConnectionPointCount();

	// instance data functionality ////////////////////////////////////////
	
	/*! Retrieves a parameter from a model referenced by an instance
		data.

		\param in_szParamName Name of the parameter to fetch.
		\param in_pFromModel Pointer to the model to get the parameter from
		\return CSLAnimatableType* Pointer to the found parameter or NULL if 
				the model or the parameter does not exist.
	*/
	CSLAnimatableType* GetParameterFromModel( SI_Char *in_szParamName, CSLModel *in_pFromModel );

	/*! Adds an instance data to the instance data list
		\return CSLShaderInstanceData Pointer to the newly added instance data
	*/
	CSLShaderInstanceData* AddInstanceData();

	/*! Removes an instance data from the instance data list
		\param in_nIndex Index of the instance data to remove
		\return SI_Error Whether or not the instance data could be removed
	*/
	SI_Error RemoveInstanceData( SI_Int in_nIndex );

	/*! Removes an instance data from the instance data list
		\param in_pToRemove Pointer to the instance data to remove
		\return SI_Error Whether or not the instance data could be removed
	*/
	SI_Error RemoveInstanceData( CSLShaderInstanceData* in_pToRemove );

	/*! Removes all instance datas from the shader
		\return SI_Error Whether or not the list could be cleared
	*/
	SI_Error ClearInstanceDatas();

	/*! Adds an exisiting instance data to the instance data list
		\param in_pToConnect Pointer to the instance data to add
		\return The added instance data or null if it already exists in the list
	*/
	CSLShaderInstanceData* ConnectInstanceData( CSLShaderInstanceData* in_pToConnect );

	/*! Gets a pointer to the internally-stored instance data pointer list
		\return CSLInstanceData Pointer to the list
	*/
	CSLShaderInstanceData** GetInstanceDataList();

	/*! Gets the total number of instance datas 
		\return SI_Int Number of instance datas
	*/
	SI_Int GetInstanceDataCount();

	// Prog ID Accessors //////////////////////////////////////////////////////

	/*! Gets the ProgID
		\return SI_Char Pointer to a string representing the ProgID
	*/
	SI_Char* GetProgID();

	/*! Sets the ProgID
		\param in_szProgID Pointer to a string representing the ProgID
	*/
	SI_Void SetProgID( SI_Char* in_szProgID );

	/*! Connects a subshader to this shader
		\parm in_pSource pointer to the subshader to connect
		\parm in_pConnection name of the connection
	*/
	CSLShaderConnectionPoint *ConnectShader( CSLXSIShader *in_pSource, char *in_pConnection);
	/*! Connects an image to this shader
		\param	in_pSource	Image to connect to this shader
		\param	in_pConnection name of the connection
	*/
	CSLShaderConnectionPoint  *ConnectImage(CSLImage *in_pSource, char *in_pConnection);

	// Output Type Accessors //////////////////////////////////////////////////
	//! Output types
	enum EOutputType
	{
		SI_OT_UNKNOWN,		/*!< Unknown output type */
		SI_OT_BOOLEAN,		/*!< Boolean shader output type */ 
		SI_OT_INTEGER,		/*!< Integer shader output type */ 
		SI_OT_SCALAR,		/*!< Scalar shader output type */ 
		SI_OT_COLOR,		/*!< Color shader output type */ 
		SI_OT_VECTOR,		/*!< Vector shader output type */ 
		SI_OT_TEXTURE_SPACE,/*!< Texture space shader output type */ 
		SI_OT_TEXTURE,		/*!< Texture shader output type */ 
		SI_OT_STRING,		/*!< String shader output type */ 
		SI_OT_FILENAME,		/*!< Filename shader output type */ 
		SI_OT_LENS,			/*!< Lens shader output type */ 
		SI_OT_LIGHT,		/*!< Light shader output type */ 
		SI_OT_MATERIAL,		/*!< Material shader output type */ 
		SI_OT_MODEL,		/*!< Model shader output type */ 
		SI_OT_MULTI,		/*!< Multiple output port shader */ 
	};

	/*! Gets the OutputType
		\return SI_Int The OutputType
	*/
	EOutputType GetOutputType();

	/*! Sets the OutputType
		\param in_OutputType New output type to use
	*/
	SI_Void SetOutputType( EOutputType in_OutputType );

	// Multi Port Connection functionality ////////////////////////////////////////
	
	/*! Add a multi port connection to the multi port connection list
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

	// Texture Layer functionality ////////////////////////////////////////
	
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

	/*!	Set the material parent of this template.
		\param in_pParentMaterial	Pointer to the parent material.
	*/
	void SetParentMaterial(CSLXSIMaterial* in_pParentMaterial);

	/*!	Return the material parent of this template.
		\return	CSLModel*	Pointer to the parent material.
	*/
	CSLXSIMaterial* ParentMaterial();

private:

	CSLShaderInstanceData* InstanceDataFromModel( CSLModel *in_pModel );

	CSIBCArray<CSLVariantParameter *> m_Parameters;
    CSIBCArray<CSLShaderConnectionPoint *> m_ConnectionPoints;
	CSIBCArray<CSLShaderInstanceData*> m_InstanceDatas;
    CSLEnumProxy<EOutputType, SI_OT_MULTI> m_OutputType;
    CSLStringProxy m_ProgID;
	CSIBCArray<CSLXSIShaderMultiPortConnection *> m_MultiPortConnections;
	CSIBCArray<CSLXSITextureLayer *> m_TextureLayers;
	CSLXSIMaterial* m_pParentMaterial;

	SI_Void *m_pReserved;	// reserved for future use
};

#endif

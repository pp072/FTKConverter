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

#ifndef _COLLADAMODEL_H
#define _COLLADAMODEL_H

#include "Template.h"
#include "Logger.h"
#include "Scene.h"
#include "COLLADATemplate.h"
#include "Model.h"


class CSLModel;
class CSLAmbience;
class CSLAngle;
class CSLCoordinateSystem;
class CSLFileInfo;
class CSLSceneInfo;
class CSLEnvelopeList;
class CSLMaterialLibrary;
class CSLFog;
class CSLActionFCurve;
class CSLFCurve;
class CSLTransform;
class CSLAction;
class CSLShapeAnimation;
class CSLVisibility;
class CSLXSIMaterial;
class CSLImageLibrary;
class CSLImage;
class CSLXSIShader;
class CSLBaseMaterial;

/** 
* CSLCOLLADAModel Class
* 
*/

class XSIEXPORT CSLCOLLADAModel : public CSLModel
{
public:
	///////////////////////////////////////////////////////////////////////////
	// Construction/destruction
	///////////////////////////////////////////////////////////////////////////

	/*! Constructor
	* \param in_pScene Parent Scene
	* \param in_pModel Parent Model
	* \param in_pTemplate Parent Template
	* \return an instance of CSLModel
	*/
	CSLCOLLADAModel(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);

	//! Destructor
	virtual ~CSLCOLLADAModel();


	/*! Fixes all problems in the model to ensure it is valid
	* \return SI_Error Whether or not the model could be fixed
	*/
	virtual SI_Error Fix();

	/*! Updates the template with information from this instance
	* \return SI_Error Whether or not the template could be updated
	*/
	virtual SI_Error Synchronize();

	/*! Adds a model to the children list
	* \return Pointer to the new children
	*/
	virtual CSLModel*	AddModel();

	/*! Adds a point light to the children list
	* \return Pointer to the new children
	*/
	virtual CSLModel*	AddPointLight();

	/*! Adds a directional light to the children list
	* \return Pointer to the new children
	*/
	virtual CSLModel*	AddDirectionalLight();

	/*! Adds an infinite light to the children list
	* \return Pointer to the new children
	*/
	virtual CSLModel*	AddInfiniteLight();

	/*! Adds a spot light to the children list
	* \return Pointer to the new children
	*/
	virtual CSLModel*	AddSpotLight();

	/*! Adds a camera to the children list
	* \return Pointer to the new children
	*/
	virtual CSLModel*	AddCamera();

	/*! Adds a mesh to the children list
	* \return Pointer to the new children
	*/
	virtual CSLModel*	AddXSIMesh();

	/*! Adds an XSI_Camera to the children list
	* \return Pointer to the new children
	*/
	virtual CSLModel*	AddXSICamera();

	/*! Adds an instance of another model to the children list
	* \return Pointer to the new children
	*/
	virtual CSLModel*	AddInstance();
	
	/*! Finds the instance_material template with a given name material
	* \param in_pName the name of the material
	* \return the template of the instance_material
	*/
	CCOLLADATemplate*	FindInstanceMaterial(char *in_pName);

	/*!	Return the name (string) of a specified parameter.
		\param	in_pParameter	The parameter
		\return	SI_Char*	Name of the parameter.
	*/
	virtual const SI_Char* GetParameterName(CSLAnimatableType* in_pParameter);

	/*!	Return the instance target name from its symbol.
		\param	in_pParameter	The symbol
		\return	SI_Char*	The name of the target.
	*/
	const char* GetInstanceTarget(char* in_pSymbol);

	/*!	Return the instance target symbol from its name.
		\param	in_pParameter	The symbol
		\return	SI_Char*	The name of the target.
	*/
	const char* GetInstanceSymbol(char* in_pTarget);

	/*! Allocates and connects a new mixer to the model
	* \return CSLMixer Pointer to the newly allocated mixer
	*/
	virtual CSLMixer* CreateMixer();

	/*! Sets the pointer to the <bind_material> <technique_common> template
	* \param in_pName the <technique_common> template pointer
	*/
	void SetTechniqueCommon(CCOLLADATemplate* in_pTechniqueCommon)
	{
		m_pTechniqueCommon = in_pTechniqueCommon;
	}

	/*! Adds a symbol vs target <instance_material> association to the list
	* \param in_pSymbol the symbol
	* \param in_pTarget the associated target
	*/
	void AddInstanceMaterialSymbol(char* in_pSymbol, char* in_pTarget);

protected:

private:
	// private structure for symbol->target association in instance_material elements
	struct COLLADAInstanceMaterial
	{
		SI_Char* m_Symbol;
		SI_Char* m_Target;
	};

	CSLTemplate::ERotationOrder GetRotationOrder(CdotXSITemplates* in_pRotations);

	CCOLLADATemplate* AddInstanceMaterial(CCOLLADATemplate *in_pTechniqueCommon, CSLBaseMaterial* in_pMaterial);
	CCOLLADATemplate* AddInstanceMaterialName(CCOLLADATemplate *in_pTechniqueCommon, CSIBCString in_szMaterialName);


	CCOLLADATemplate* m_pTechniqueCommon;
	CSIBCArray<COLLADAInstanceMaterial>  m_InstanceMaterialSymbols;
};

#endif

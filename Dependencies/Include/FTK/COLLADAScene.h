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

#ifndef _COLLADASCENE_H
#define _COLLADASCENE_H

#include "Template.h"
#include "Logger.h"
#include "Scene.h"
#include "COLLADATemplate.h"
#include "COLLADAMaterialLibrary.h"
#include "COLLADAEffectLibrary.h"
#include <SIBCArray.h>

#if defined(unix)
# include <unistd.h>
# include <limits.h>
# if !defined(MAX_PATH)
#  define MAX_PATH PATH_MAX
# endif
#endif


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


typedef struct tagTemplateMap
{
	CCOLLADATemplate*	m_pCollada;
	CdotXSITemplate*	m_pLegacy;
} TemplateMap;

typedef struct tagSkinMap
{
	CCOLLADATemplate*	m_pSkinTemplate;
	CSLModel*			m_pEnvelope;
} SkinMap;

typedef struct tagSIDMap {
	CSLTemplate*				m_pTemplate;
	char						m_szSID[1024];
	CSLAnimatableType*			m_pProxy;
	CSLTemplate::EFCurveType	m_CurveType;
	char						m_szXSIName[1024];
} SIDMap;

typedef struct tagUnresolvedMaterialMap
{
	CSLCOLLADAMaterial*	m_pMaterial;
	CCOLLADATemplate*	m_pEffectTemplate;
	CCOLLADATemplate*	m_pInstanceEffect;
} UnresolvedMaterialMap;

/** 
* CSLCOLLADALibrary Class
* 
*/
class XSIEXPORT CSLCOLLADALibrary : public CCOLLADATemplate
{
public:
	CSLCOLLADALibrary(CCOLLADATemplate* in_pParent, const SI_Char* in_szName);
	virtual ~CSLCOLLADALibrary();
	
	// valid for library_visual_scenes only
	CdotXSITemplate*	GetSceneTemplate(CSLCOLLADAScene* in_pScene);

	SI_Char*			GenerateID();

private:
	char				m_szSuffix[MAX_PATH];
	char				m_szID[MAX_PATH];
	LONG				m_iCount;
};

/** 
* CSLCOLLADAScene Class
* 
* This is the top level object for a dotXSI abstraction using the SemanticLayer. From this class, you can
* access all the models, primitives, material etc. contained in the dotXSI.
*/

class XSIEXPORT CSLCOLLADAScene : public CSLScene
{
public:
	///////////////////////////////////////////////////////////////////////////
	// Construction/destruction
	///////////////////////////////////////////////////////////////////////////
	CSLCOLLADAScene();
	virtual ~CSLCOLLADAScene();
	
	static CSLCOLLADAScene * CreateScene();

	/*! CSLTemplate overrides
	*/
	virtual SI_Error Fix();
	virtual SI_Error Synchronize();
	virtual SI_Error Write();
	virtual SI_Error Write(SI_Char* in_szFileName);
	virtual CSLImageLibrary* CreateImageLibrary();
	virtual CSLEnvelopeList* CreateEnvelopeList();

	/*! Adds a template to the extra list
	*/
	void	AddExtra( CCOLLADATemplate* in_pExtra );

	/*! Returns a named COLLADA library
	*/
	CSLCOLLADALibrary*	GetLibrary( const SI_Char* in_szLibrarySuffix );

	/*! Sets wether to export extra templates or not
	*/
	SI_Void	ExportExtra ( bool in_bExtra ) { m_bExportExtra = in_bExtra; };
	bool ExportExtra() { return m_bExportExtra; };

	/*! Generates a unique ID for an object and instanciate a node in the scene
	*/
	SI_Void	GenerateIDAndInstanciate ( CCOLLADATemplate *in_pNode, CCOLLADATemplate *in_pLib, const SI_Char* in_szLibSuffix );

	/*! Generates a unique ID for a scene and instanciate the visual scene in the scene template
	*/
	SI_Void	InstanciateScene ( CCOLLADATemplate *in_pScene );
	
	/*! Returns the instanciated scene template()
	*/
	CCOLLADATemplate*		GetInstanciatedSceneTemplate ();
	
	/*! Changes an existing instanciated node to another lib and URL (useful for controllers)
	*/
	SI_Bool	ChangeNodeInstanciation		( SI_Char* in_szNodeID, SI_Char* in_szNewLib, SI_Char* in_szNewURL );

	/*! Gets the EffectLibrary object
	*	\return CSLCOLLADAEffectLibrary*	The Effect Library object
	*/
	virtual CSLCOLLADAEffectLibrary* GetEffectLibrary();

	/*! Connect an existing CSLEffectLibrary object to the scene
		\param	CSLCOLLADAEffectLibrary*	The new CSLCOLLADAEffectLibrary
		\return CSLCOLLADAEffectLibrary*	The old CSLCOLLADAEffectLibrary
	*/
	virtual CSLCOLLADAEffectLibrary* ConnectEffectLibrary(CSLCOLLADAEffectLibrary *in_pNewEffectLibrary);

	
	SI_Void	AddSIDMap ( CSLTemplate* in_pTemplate, const char* in_szSID,
						const char* in_szSIDSuffix, CSLAnimatableType* in_pProxy,
						CSLTemplate::EFCurveType in_CurveType, const char* in_szXSIName );
	SI_Void	ResetSIDMap();

	SIDMap* ResolveTarget(CSLTemplate* in_pTemplate, char* in_szSID);
	SIDMap* ResolveTarget(char* in_szOwner, char* in_szSID);
	SIDMap* FindParameterSID(CSLAnimatableType* in_pParam);

	const char*		GetXSINameFromSIDTable ( CSLAnimatableType* in_pParam );

	SI_Void	AddSource ( CCOLLADATemplate *in_pParent,
								SI_Char* in_szName, 
								SI_Char* in_szType, 
								SI_TinyVariant* in_pData,
								SI_Long	in_lCount,
								SI_Long in_lStride,
								SI_Char* in_szAccessorType );

protected:

	virtual SI_Error RegisterAllCallbacks();
	virtual SI_Error PopulateScene();

	
	///////////////////////////////////////////////////////////////////////////
	// Helpers
	///////////////////////////////////////////////////////////////////////////

	void	FixWriteCallbacks( CdotXSITemplate* in_pTemplate);
	void	ReorderExtra( CdotXSITemplate* in_pTemplate);

	///////////////////////////////////////////////////////////////////////////
	// Members
	///////////////////////////////////////////////////////////////////////////

	CCOLLADATemplate*							m_pTechTemplate;
	CCOLLADATemplate*							m_pRootTemplate;
	CSLCOLLADAEffectLibrary*					m_pEffectLibrary;

	CSIBCArray<CSLCOLLADALibrary*>				m_Librairies;
	CSIBCArray<TemplateMap>						m_pReparentMap;
	bool										m_bExportExtra;
	CSIBCArray<CCOLLADATemplate*>				m_pInstanciatedNodes;
	CSIBCArray<SIDMap>							m_pSIDMap;

};

#endif

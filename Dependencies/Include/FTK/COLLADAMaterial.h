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
/*! \file COLLADAMaterial.h
/*!
	COLLADA material class definition
*/

#ifndef COLLADAMATERIAL_H
#define COLLADAMATERIAL_H

#include "XSIMaterial.h"
#include "COLLADATemplate.h"
#include "COLLADAEffect.h"
#include "VariantParameter.h"

class CSLCOLLADAModel;

typedef struct 
{
	CSLXSIShader*	m_pShader;
	char*			m_pSemantic;
	char*			m_pParameter;
} COLLADAMaterialTCInstanceData;
/**************************************************************************************
CSLCOLLADASetParam
****************************************************************************************/

class XSIEXPORT CSLCOLLADASetParam : public CSLTemplate
{
public:
	CSLCOLLADASetParam(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
	virtual ~CSLCOLLADASetParam();

	virtual	char*						GetRef();
	virtual void						SetRef(char *in_pRef);
	
	virtual CSLTemplate::ETemplateType	Type();
    virtual SI_Error					Synchronize();

private:

};

/**************************************************************************************
CSLCOLLADAMaterial
****************************************************************************************/

class XSIEXPORT CSLCOLLADAMaterial : public CSLXSIMaterial
{
public:
	CSLCOLLADAMaterial(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
	virtual ~CSLCOLLADAMaterial();

	CSLCOLLADAFX*		GetEffect();
	void				ConnectEffect(CSLCOLLADAFX* in_pEffect);
	void				ConnectInstanceEffect(CCOLLADATemplate* in_pInstanceEffect);


	virtual CSLTemplate::ETemplateType	Type();
    virtual SI_Error					Synchronize();
	virtual	SI_Error					ConvertToCOLLADAFX();
	virtual	SI_Error					ConvertToCommonProfile(CSLConnectionPoint *in_pRoot);
	virtual	SI_Error					ConvertToCGProfile(CSLConnectionPoint *in_pRoot);
	virtual	SI_Error					ConvertToXSIShaderTree();
	virtual	SI_Error					ConvertFromCommonProfile();
	virtual SI_Error					ConvertFromCGProfile();


	virtual CSLCOLLADASetParam*			AddSetParam();
	virtual CSLCOLLADASetParam*			ConnectSetParam(CSLCOLLADASetParam *in_pSetParam);
	virtual	int							GetSetParamCount();
	virtual CSLCOLLADASetParam**		GetSetParamList();

	virtual void						RemoveSetParam(CSLCOLLADASetParam *in_pSetParam);
	virtual void						RemoveSetParam(int index);
	virtual CSLCOLLADASetParam*			FindSetParam(char *in_pRefName);
	virtual void						ClearSetParams();

	CSIBCArray<CSLCOLLADAModel*>&					Owners();
	CSIBCArray<COLLADAMaterialTCInstanceData>&		TexcoordInstanceData();
	virtual SI_Error								ResolveInstanceData();

	virtual void						ProcessCgFXParameter
											(
												CSLXSIShader			*in_pCGFX,
												int						in_ParameterCount,
												CSLVariantParameter		**in_pParameterList,
												CSLVariantParameter		*in_pParamValue,
												int						&io_ParamIndex,
												int						&io_TextureID
											);

private:

	bool				ConvertCommonTexture(char *in_pParamName, char* in_pPortName, bool& l_bFlag, CSLXSIShader* in_pImageShader, CSLCOLLADAFXCommonColorTexture* in_pCOLLADAParam);
	void				SetParamTextureOrColor(CSLCOLLADAFXCommonColorTexture *in_pParam, CSLXSIShader *in_pShader, char *in_pParamName);
	void				SetParamColor(CSLXSIShader* in_pShader, char *in_pParamName, CSIBCColorf in_Color);
	void				SetParamFloat(CSLXSIShader* in_pShader, char *in_pParamName, float in_Value);
	void				SetParamBoolean(CSLXSIShader* in_pShader, char *in_pParamName, bool in_Value);

	CSLCOLLADAFX*								m_pEffect;
	CCOLLADATemplate*							m_pInstanceEffect;
	CSIBCArray<CSLCOLLADASetParam*>				m_SetParams;
	CSIBCArray<CSLCOLLADAModel*>				m_Owners;
	CSIBCArray<COLLADAMaterialTCInstanceData>	m_TexcoordInstanceData;

};


#endif // COLLADAMATERIAL_H

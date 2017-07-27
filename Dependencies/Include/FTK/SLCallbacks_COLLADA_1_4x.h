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
#ifndef _SLCALLBACKS_COLLADA_1_4X_H
#define _SLCALLBACKS_COLLADA_1_4X_H

#include "Template.h"
#include "Scene.h"

// registration function

XSIEXPORT SI_Error Register_COLLADA_1_4x(CSLScene *in_pScene);

// scene Load callbacks
XSIEXPORT CSLTemplate *COLLADALightCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADANodeCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAMeshCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAControllerCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAEnvelopeCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAShapeAnimationCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext, CCOLLADATemplate *in_pMorphTemplate = NULL);
XSIEXPORT CSLTemplate *COLLADAModelCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADACameraCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAAnimationLibraryNodeCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAImageLibraryCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAImageCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAMaterialLibraryCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAMaterialCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAEffectLibraryCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAEffectCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAFXCommonProfileCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAFXCommonShaderCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADASetParamCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADATranslateCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADARotateCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAScaleCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAShearCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADALookatCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAMatrixCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAXSIParamCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAInstanceCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *COLLADAAnimationClipCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);

// node Post load callbacks
XSIEXPORT SI_Error	    COLLADAPostChildrenModelCallback(CSLTemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT SI_Error		COLLADAMaterialPostChildrenCallback(CSLTemplate *in_pTemplate, SLContext *in_pContext);

// scene Post load callbacks
XSIEXPORT SI_Error		COLLADAAnimationLibraryCallback(SLContext *in_pContext);
XSIEXPORT SI_Error		COLLADAControllerLibraryCallback(SLContext *in_pContext);
XSIEXPORT SI_Error		COLLADAMaterialLibraryPostCallback(SLContext *in_pContext);
XSIEXPORT SI_Error		COLLADAMaterialLibraryPostLoadCallback(SLContext *in_pContext);
XSIEXPORT SI_Error		COLLADADotXSIFixupPostCallback(SLContext *in_pContext);
XSIEXPORT SI_Error		COLLADAInstancePostCallback(SLContext *in_pContext);

#endif
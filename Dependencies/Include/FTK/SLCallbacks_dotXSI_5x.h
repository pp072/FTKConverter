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
#ifndef _SLCALLBACKS_DOTXSI_5X_H
#define _SLCALLBACKS_DOTXSI_5X_H

#include "Template.h"
#include "Scene.h"

// registration function

XSIEXPORT SI_Error Register_dotXSI_5x(CSLScene *in_pScene);

// Load callback

XSIEXPORT CSLTemplate *XSIUserDataBlobCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *XSITransformCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *XSIBasePoseCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *XSILimitCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *XSIMeshCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *XSIShapeCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *XSIShapeAnimationCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *XSIPolygonListCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *XSITriangleListCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *XSITriangleStripListCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *XSIVertexListCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *XSISubComponentAttributeListCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);
XSIEXPORT CSLTemplate *XSIClusterInfoCallback(CdotXSITemplate *in_pTemplate, SLContext *in_pContext);

// Post load callbacks

XSIEXPORT SI_Error XSIPolygonListPostLoadCallback(SLContext *in_pContext);
XSIEXPORT SI_Error XSITriangleListPostLoadCallback(SLContext *in_pContext);
XSIEXPORT SI_Error XSITriangleStripListPostLoadCallback(SLContext *in_pContext);

#endif
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

#ifndef _COLLADASHAPEANIMATION_H
#define _COLLADASHAPEANIMATION_H

#include "Template.h"
#include "Logger.h"
#include "Scene.h"
#include "COLLADATemplate.h"
#include "Model.h"
#include "XSIShapeAnimation.h"
#include "COLLADAScene.h"
#include "COLLADASubComponentAttributeList.h"

/** 
* CSLCOLLADAShapeAnimation Class
* 
*/

class XSIEXPORT CSLCOLLADAShapeAnimation : public CSLXSIShapeAnimation
{
public:
	///////////////////////////////////////////////////////////////////////////
	// Construction/destruction
	///////////////////////////////////////////////////////////////////////////
	CSLCOLLADAShapeAnimation(CSLScene* in_pScene, 
								CSLModel *in_pModel, 
								CdotXSITemplate* in_pTemplate,
								EFCurveInterpolationType in_Type);
	virtual ~CSLCOLLADAShapeAnimation();

	virtual SI_Error Synchronize();

protected:
	virtual CSLXSIShape* CreateXSIShape();
};

#endif

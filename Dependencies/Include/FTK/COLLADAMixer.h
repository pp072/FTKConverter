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

#ifndef _COLLADAMIXER_H
#define _COLLADAMIXER_H

#include "Mixer.h"

// Forward declaration
class CSLAction;
class CSLTrack;

/*! The animation mixer provides high-level control over animation.  The 
	mixer contains a database of short animations called action sources 
	(CSLAction).  An action source can be instantiated in the form of an
	action clip (CSLActionClip) in tracks (CSLTrack) to compose complex 
	animation.  You can create an animation mixer with the 
	CSLModel::CreateMixer method.

	\note This template is not supported by SI3D.
	
	\sa CSLAction
	\sa CSLActionClip
	\sa CSLModel
	\sa CSLTrack
*/
class XSIEXPORT CSLCOLLADAMixer
    : public CSLMixer
{
public:
	/*! Constructor
		\param in_pScene	Pointer to the scene containing the mixer
		\param in_pModel	Pointer to the model containing the mixer
		\param in_pTemplate	Pointer to the CdotXSITemplate containing the mixer
	*/
    CSLCOLLADAMixer(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
    virtual ~CSLCOLLADAMixer();

	/*! Adds a new action
		\return CSLAction Pointer to the newly added action
	*/
	virtual CSLAction* AddAction();
private:
	
	SI_Void *m_pReserved;

};


#endif _COLLADAMIXER_H
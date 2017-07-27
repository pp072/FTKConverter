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

#ifndef _ACTIONCLIPCONTAINER_H
#define _ACTIONCLIPCONTAINER_H

#include "Template.h"
#include "ActionClip.h"

// Forward declaration

class CSLAction;
class CSLTrack;

/*! An action clip container is a specialisation of the action clip (CSLActionClip).
	It's an action clip that can contain a list of track (CSLTrack).
	You can create an action clip with the CSLTrack::AddActionClip method.

	\sa CSLActionClip
	\sa CSLAction
	\sa CSLMixer
	\sa CSLTimeControl
	\sa CSLTrack
*/
class XSIEXPORT CSLActionClipContainer
    : public CSLActionClip
{
public:
	/*! Constructor
		\param in_pScene	Pointer to the scene containing the mixer
		\param in_pModel	Pointer to the model containing the mixer
		\param in_pTemplate	Pointer to the CdotXSITemplate containing the mixer
	*/
    CSLActionClipContainer(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
    virtual ~CSLActionClipContainer();
    
	/*! Synchronizes internal data to be coherent with the IO layer
		\return success or failure
	*/
	virtual SI_Error Synchronize();

	/*! Returns the type of this template
		\retval CSLTemplate::XSI_ACTIONCLIPCONTAINER
	*/
	CSLTemplate::ETemplateType Type(){ return CSLTemplate::XSI_ACTIONCLIPCONTAINER; }

	// Tracks functionality //////////////////////////////////////////////////
	
	/*! Removes a track
		\param in_nIndex Index of the track to remove
		\retval SI_SUCCESS The element was removed
		\retval SI_ERR_BAD_ARGUMENT Invalid index
	*/
	SI_Error RemoveTrack( SI_Int in_nIndex );

	/*! Removes a track
		\param in_pToRemove Pointer to the track to remove
		\retval SI_SUCCESS The element was removed
		\retval SI_ERR_BAD_ARGUMENT The element could not be found
	*/
	SI_Error RemoveTrack( CSLTrack *io_pToRemove );

	/*! Gets the list of all tracks
		\return Pointer to the list of pointer of all tracks
	*/
    CSLTrack** GetTrackList();

	/*! Get the total number of tracks
		\return SI_Int The number of tracks
	*/
	SI_Int GetTrackCount();

	/*! Adds a new track
		\return CSLTrack Pointer to the newly added track
	*/
	CSLTrack* AddTrack();

	/*! Removes all Tracks
		\return SI_Error Whether or not removal was successful
	*/
	SI_Error ClearTracks();

	/*! Adds a preallocated Track to the Track list
		\param CSLTrack Pointer to the Track to add
		\return CSLTrack The newly added Track or null if it was already added
	*/
	CSLTrack* ConnectTrack(CSLTrack* in_pNewTrack);
	
private:
    CSIBCArray<CSLTrack *> m_Tracks;

	SI_Void *m_pReserved;
};

#endif // _ACTIONCLIPCONTAINER_H

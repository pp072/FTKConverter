//***************************************************************************************
//
// File supervisor: Softimage 3D Games & 3D Bridge team
//
// (c) Copyright 2001-2005 Avid Technology, Inc. . All rights reserved.
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

//***************************************************************************************
// Defines
//***************************************************************************************
#ifndef __COLLADATEMPLATE_H
#define __COLLADATEMPLATE_H

//***************************************************************************************
// Includes
//***************************************************************************************
#include "SIBCArray.h"
#include "SIBCNode.h"
#include "SIBCString.h"
#include "dotXSIParams.h"
#include "dotXSITemplate.h"
#define XSI_TECHNIQUE_NAME	"XSI"

//
// COLLADA 1.4 Types
//
enum ColladaSimpleType
{
 CT_INVALIDTYPE = 0,
 CT_BOOL,
 CT_DATETIME,
 CT_FLOAT,
 CT_INT,
 CT_NAME,
 CT_STRING,
 CT_TOKEN,
 CT_LISTOFBOOLS,
 CT_LISTOFFLOATS,
 CT_LISTOFHEXBINARY,
 CT_LISTOFINTS,
 CT_LISTOFNAMES,
 CT_LISTOFTOKENS,
 CT_FLOAT2,
 CT_FLOAT3,
 CT_FLOAT4,
 CT_FLOAT7,
 CT_FLOAT1X1,
 CT_FLOAT1X2,
 CT_FLOAT1X3,
 CT_FLOAT1X4,
 CT_FLOAT2X1,
 CT_FLOAT2X2,
 CT_FLOAT2X3,
 CT_FLOAT2X4,
 CT_FLOAT3X1,
 CT_FLOAT3X2,
 CT_FLOAT3X3,
 CT_FLOAT3X4,
 CT_FLOAT4X1,
 CT_FLOAT4X2,
 CT_FLOAT4X3,
 CT_FLOAT4X4,
 CT_INT2,
 CT_INT3,
 CT_INT4,
 CT_INT1X1,
 CT_INT1X2,
 CT_INT1X3,
 CT_INT1X4,
 CT_INT2X1,
 CT_INT2X2,
 CT_INT2X3,
 CT_INT2X4,
 CT_INT3X1,
 CT_INT3X2,
 CT_INT3X3,
 CT_INT3X4,
 CT_INT4X1,
 CT_INT4X2,
 CT_INT4X3,
 CT_INT4X4,
 CT_BOOL2,
 CT_BOOL3,
 CT_BOOL4,
 CT_BOOL1X1,
 CT_BOOL1X2,
 CT_BOOL1X3,
 CT_BOOL1X4,
 CT_BOOL2X1,
 CT_BOOL2X2,
 CT_BOOL2X3,
 CT_BOOL2X4,
 CT_BOOL3X1,
 CT_BOOL3X2,
 CT_BOOL3X3,
 CT_BOOL3X4,
 CT_BOOL4X1,
 CT_BOOL4X2,
 CT_BOOL4X3,
 CT_BOOL4X4
 };

typedef struct tagCOLLADASimpleTypeEntry {
	char*					m_szName;
	ColladaSimpleType		m_iID;
	int						m_iCount;
} COLLADASimpleTypeEntry;

int	GetSimpleCount( int s );
const char* GetSimpleTypeName ( int s );
ColladaSimpleType GetSimpleType ( int s );

ColladaSimpleType GetColladaListType ( const char* in_szTag );
int					GetColladaListTypeCount ( const char* in_szTag );

//***************************************************************************************
// Typedefs
//***************************************************************************************
class CXSIParser;

// @type DOTXSICALLBACK | dotXSI Native Templates callback function.
typedef SI_Error ( *DOTXSIREADCALLBACK ) ( CXSIParser *in_pParser, CdotXSITemplate *i_pCurrentTemplate, CdotXSITemplate *i_pNewTemplate );
typedef SI_Error ( *DOTXSIWRITECALLBACK ) ( CXSIParser *in_pParser, CdotXSITemplate *i_pCurrentTemplate, CdotXSITemplate *i_pNewTemplate, SI_Int i_nLevel );

//***************************************************************************************
// @class COLLADATemplate | a template
// @base public | CSIBCNode
//***************************************************************************************

class XSIEXPORT CCOLLADATemplate : public CdotXSITemplate
{
public:

	/*! Default constructor.
		Sets the default version information, and the default read and write callbacks
		for the template.
	* \return an instance of CCOLLADATemplate
	*/
	CCOLLADATemplate();	
	
	/*! Constructor.
		Sets the type name of the template to the name give by \p i_sName.
	* \param	i_sName	Type name of the new template.
	* \return	an instance of CCOLLADATemplate
	*/
	CCOLLADATemplate( CSIBCString *i_sName );

	/*! Destructor
	*/
    virtual ~CCOLLADATemplate();

	/*! Gets the attributes.
	* \return	CdotXSIParams&	Reference to the CdotXSIParams container holding the CdotXSIParam attributes
				for this template.
	*/
	CdotXSIParams &Attributes() { return m_AttribCol; }

	/*! Adds a new attribute
	*/
	CdotXSIParam *AddAttribute(const SI_Char* in_szName, const SI_Char* in_szValue);


	/*! Adds a new parameter
	*/
	CdotXSIParam *AddParam(const SI_Char* in_szName, int in_iType, const SI_Char* in_pStringValue = NULL);
	CdotXSIParam *AddParam(const SI_Char* in_szName, int in_iType, SI_Float in_fValue);
	CdotXSIParam *AddParam(const SI_Char* in_szName, int in_iType, SI_Int in_lValue);
	CdotXSIParam *AddParam(const SI_Char* in_szName, int in_iType, SI_Short in_sValue);
	CdotXSIParam *AddParam(const SI_Char* in_szName, int in_iType, SI_Bool in_sValue);

	/*! Adds a template to the extra of this template
	* \return	CCOLLADATemplate*	The extra template
	*/
	CCOLLADATemplate*	AddExtra ( const SI_Char* in_szName );

	/*! Attaches an existing template as an extra
	*/
	SI_Void				AttachExtra ( CdotXSITemplate* in_pExtra );

	/*! Attaches an existing template as an extra in a foreign profile
	*/
	SI_Void				AttachExtraForeignProfile ( CdotXSITemplate* in_pExtra );
	

	/*! Retrieves an extra template
	*/
	CCOLLADATemplate*	GetExtra ( const SI_Char* in_szExtraName );

	/*! Create a named child template of this template
	* \return	CCOLLADATemplate*	The child template
	*/
	CCOLLADATemplate*	CreateChildTemplate( const SI_Char* in_szName );

	/*! Initialized the template from it's name
	*/
	SI_Void				InitializeFromName( SI_Char *i_pChar, CXSIParser *in_pParser );

	/*! Sets the instance name of the template
	*/
	virtual				SI_Void SetInstanceName( CSIBCString i_sInstanceName );


	/*! Set wether this template can carry COLLADA extras 
	*/
	SI_Void					SetCanCarryExtra (bool in_bValue) { m_bCanCarryExtra = in_bValue;};

	/*! Get wether this template can carry COLLADA extras 
	*/
	bool					GetCanCarryExtra () { return m_bCanCarryExtra ;};

	/*! Returns the template associated with the source attribute
	*/
	CCOLLADATemplate*		ResolveSource();
	
	CSIBCString&			InstanciatedName() { return m_InstanciatedName; };
	
	virtual					CdotXSITemplate *Clone();
	void					Serialize ( CSIBCString& in_szBuffer );
	void					SerializeXML ( CSIBCString& in_szBuffer );
	void					UnSerialize ( CSIBCString& in_szBuffer );

protected:

	CCOLLADATemplate*		ResolveSource(SI_Char* in_pSourceName);
	CCOLLADATemplate*		CreateExtra();

	CdotXSIParams			m_AttribCol;
	CCOLLADATemplate*		m_pExtra;
	bool					m_bCanCarryExtra;
	CSIBCString				m_InstanciatedName;
};


//***************************************************************************************
// Functions
//***************************************************************************************

/*! \addtogroup glbfunc_template Global dotXSI template functions
*  @{
*/

/*! Allocate a CCOLLADATemplate
* \return CCOLLADATemplate* the newly created CCOLLADATemplate
*/
XSIEXPORT CCOLLADATemplate* CreateCOLLADATemplate(CdotXSITemplate* in_pParent = NULL, const SI_Char* in_szName = NULL);							// 


/*! Allocate a CCOLLADATemplate for a dotXSI template
* \return CCOLLADATemplate* the newly created CCOLLADATemplate
*/
XSIEXPORT CCOLLADATemplate* CreateCOLLADAdotXSITemplate(CdotXSITemplate* in_pParent, const SI_Char* in_szName, CXSIParser *in_pParser);		

/* @} */

//***************************************************************************************
// Function prototype to create templates....
//***************************************************************************************

typedef	CCOLLADATemplate* (*COLLADATemplateCreation)();
CCOLLADATemplate*	CreateGenericCOLLADATemplate ( const SI_Char* in_szName, SI_Int in_pParamCount, SI_Int in_VariantType );

//***************************************************************************************
// Write callbacks
//***************************************************************************************

SI_Error COLLADACompatibleWrite ( CXSIParser *in_pParser, CdotXSITemplate *i_pCurrentTemplate, CdotXSITemplate *i_pNewTemplate, SI_Int i_nLevel );
SI_Error COLLADAGenericWrite ( CXSIParser *in_pParser, CdotXSITemplate *i_pCurrentTemplate, CdotXSITemplate *i_pNewTemplate, SI_Int i_nLevel );
SI_Error COLLADAGenericWritePost ( CXSIParser *in_pParser, CdotXSITemplate *i_pCurrentTemplate, CdotXSITemplate *i_pNewTemplate, SI_Int i_nLevel );
SI_Error COLLADACompatibleWritePost ( CXSIParser *in_pParser, CdotXSITemplate *i_pCurrentTemplate, CdotXSITemplate *i_pNewTemplate, SI_Int i_nLevel );
SI_Error COLLADAGenericWriteNull ( CXSIParser *in_pParser, CdotXSITemplate *i_pCurrentTemplate, CdotXSITemplate *i_pNewTemplate, SI_Int i_nLevel );


SI_Error COLLADATransformWriteCallback ( CXSIParser *in_pParser, CdotXSITemplate *i_pCurrentTemplate, CdotXSITemplate *i_pNewTemplate, SI_Int i_nLevel );
SI_Error COLLADACustomPropertySetWriteCallback ( CXSIParser *in_pParser, CdotXSITemplate *i_pCurrentTemplate, CdotXSITemplate *i_pNewTemplate, SI_Int i_nLevel );
SI_Error COLLADAInstanceAnimatioNWriteCallback ( CXSIParser *in_pParser, CdotXSITemplate *i_pCurrentTemplate, CdotXSITemplate *i_pNewTemplate, SI_Int i_nLevel );


//***************************************************************************************
// Helper Functions
//***************************************************************************************

CCOLLADATemplate*	FindNestedTemplateByName ( CCOLLADATemplate* in_pParent, SI_Char* in_szName, int in_iNth = 0, bool in_bSearchNodeOnly=false);
CCOLLADATemplate*	FindNestedTemplateByNameRec ( CCOLLADATemplate* in_pParent, SI_Char* in_szName, int in_iNth, int& i_iNth, bool in_bSearchNodeOnly);

#endif // __COLLADATEMPLATE_H

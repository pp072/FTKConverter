/******************************************************************************\
*
* File:          Transform.h
* Creation date: January 15, 2002
* Purpose:       Declaration of class 'Transform'
*
\******************************************************************************/
#ifndef _XSITRANSFORM_H
#define _XSITRANSFORM_H

#include "Template.h"
#include "XSILimit.h"

/** 
* CSLXSITranslate class
* This class handles an XSI translation in the polymatricks operator of a model.
*/
class XSIEXPORT CSLXSITranslate
    : public CSLTemplate
{
public:
    CSLXSITranslate(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
    virtual ~CSLXSITranslate();

    virtual ETemplateType Type();

	virtual SI_Error Synchronize();

	CSIBCVector3D		GetTranslation();
	CSLVector3DProxy&	GetTranslationProxy();
	void				SetTranslation(CSIBCVector3D& in_Translation);

	virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);
    virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szParameterName);

	/*!	Return the name (string) of a specified sub parameter.
		\param	in_pParameter	The sub parameter
		\return	SI_Char*	Name of the sub parameter.
	*/
    virtual const SI_Char* GetParameterName(CSLAnimatableType* in_pParameter);
private:
	CSLVector3DProxy	m_Translation;
};

/** 
* CSLXSIRotate class
* This class handles an XSI rotation in the polymatricks operator of a model.
*/
class XSIEXPORT CSLXSIRotate
    : public CSLTemplate
{
public:
    CSLXSIRotate(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
    virtual ~CSLXSIRotate();

    virtual ETemplateType Type();

	virtual SI_Error Synchronize();

	CSIBCVector3D		GetAxis();
	CSLVector3DProxy&	GetAxisProxy();
	void				SetAxis(CSIBCVector3D& in_Axis);

	float				GetAngle();
	CSLFloatProxy&		GetAngleProxy();
	void				SetAngle(float in_Angle);

	virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);
    virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szParameterName);

	/*!	Return the name (string) of a specified sub parameter.
		\param	in_pParameter	The sub parameter
		\return	SI_Char*	Name of the sub parameter.
	*/
    virtual const SI_Char* GetParameterName(CSLAnimatableType* in_pParameter);
private:
	CSLVector3DProxy	m_Axis;
	CSLFloatProxy		m_Angle;
};

/** 
* CSLXSIScale class
* This class handles an XSI scale in the polymatricks operator of a model.
*/
class XSIEXPORT CSLXSIScale
    : public CSLTemplate
{
public:
    CSLXSIScale(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
    virtual ~CSLXSIScale();

    virtual ETemplateType Type();

	virtual SI_Error Synchronize();

	CSIBCVector3D		GetScale();
	CSLVector3DProxy&	GetScaleProxy();
	void				SetScale(CSIBCVector3D& in_Scale);

	virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);
    virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szParameterName);

	/*!	Return the name (string) of a specified sub parameter.
		\param	in_pParameter	The sub parameter
		\return	SI_Char*	Name of the sub parameter.
	*/
    virtual const SI_Char* GetParameterName(CSLAnimatableType* in_pParameter);
private:
	CSLVector3DProxy	m_Scale;
};

/** 
* CSLXSIShear class
* This class handles an XSI shear in the polymatricks operator of a model.
*/
class XSIEXPORT CSLXSIShear
    : public CSLTemplate
{
public:
    CSLXSIShear(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
    virtual ~CSLXSIShear();

    virtual ETemplateType Type();

	virtual SI_Error Synchronize();

	CSIBCVector3D		GetFirstAxis();
	CSLVector3DProxy&	GetFirstAxisProxy();
	void				SetFirstAxis(CSIBCVector3D& in_Axis);

	CSIBCVector3D		GetSecondAxis();
	CSLVector3DProxy&	GetSecondAxisProxy();
	void				SetSecondAxis(CSIBCVector3D& in_Axis);

	float				GetAngle();
	CSLFloatProxy&		GetAngleProxy();
	void				SetAngle(float in_Angle);

	virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);
    virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szParameterName);

	/*!	Return the name (string) of a specified sub parameter.
		\param	in_pParameter	The sub parameter
		\return	SI_Char*	Name of the sub parameter.
	*/
    virtual const SI_Char* GetParameterName(CSLAnimatableType* in_pParameter);
private:
	CSLVector3DProxy	m_Axis1;
	CSLVector3DProxy	m_Axis2;
	CSLFloatProxy		m_Angle;
};

/** 
* CSLXSILookat class
* This class handles an XSI lookat in the polymatricks operator of a model.
*/
class XSIEXPORT CSLXSILookat
    : public CSLTemplate
{
public:
    CSLXSILookat(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
    virtual ~CSLXSILookat();

    virtual ETemplateType Type();

	virtual SI_Error Synchronize();

	CSIBCVector3D		GetPosition();
	CSLVector3DProxy&	GetPositionProxy();
	void				SetPosition(CSIBCVector3D& in_Position);
	CSIBCVector3D		GetInterest();
	CSLVector3DProxy&	GetInterestProxy();
	void				SetInterest(CSIBCVector3D& in_Interest);
	CSIBCVector3D		GetUpvector();
	CSLVector3DProxy&	GetUpvectorProxy();
	void				SetUpvector(CSIBCVector3D& in_Upvector);

	virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);
    virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szParameterName);
	/*!	Return the name (string) of a specified sub parameter.
		\param	in_pParameter	The sub parameter
		\return	SI_Char*	Name of the sub parameter.
	*/
    virtual const SI_Char* GetParameterName(CSLAnimatableType* in_pParameter);

private:
	CSLVector3DProxy	m_Position;
	CSLVector3DProxy	m_Interest;
	CSLVector3DProxy	m_Upvector;
};

/** 
* CSLXSIMatrix class
* This class handles an XSI matrix in the polymatricks operator of a model.
*/
class XSIEXPORT CSLXSIMatrix
    : public CSLTemplate
{
public:
    CSLXSIMatrix(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
    virtual ~CSLXSIMatrix();

    virtual ETemplateType Type();

	virtual SI_Error Synchronize();

	CSIBCMatrix4x4		GetMatrix();
	void				SetMatrix(CSIBCMatrix4x4& in_Matrix);

	virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);
    virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szParameterName);

	/*!	Return the name (string) of a specified sub parameter.
		\param	in_pParameter	The sub parameter
		\return	SI_Char*	Name of the sub parameter.
	*/
    virtual const SI_Char* GetParameterName(CSLAnimatableType* in_pParameter);
private:
	CSLMatrix4x4Proxy	m_Matrix;
};

/** 
* CSLXSIPolymatricks class
* This class handles the XSI polymatricks operator of a model.
*/
class XSIEXPORT CSLXSIPolymatricks
    : public CSLTemplate
{
public:
    CSLXSIPolymatricks(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
    virtual ~CSLXSIPolymatricks();

    virtual ETemplateType Type();

	virtual SI_Error Synchronize();

	CSLTemplate**				GetTransformNodes();
	int							GetTransformNodeCount();
	SI_Error					RemoveTransformNode(CSLTemplate *in_pNode);
	SI_Error					RemoveTransformNode(int index);
	SI_Error					ClearTransformNodes();

	CSLXSITranslate*			AddXSITranslate();
	CSLXSIRotate*				AddXSIRotate();
	CSLXSIScale*				AddXSIScale();
	CSLXSIShear*				AddXSIShear();
	CSLXSILookat*				AddXSILookat();
	CSLXSIMatrix*				AddXSIMatrix();

	CSLXSITranslate*			ConnectXSITranslate(CSLXSITranslate *in_pNode);
	CSLXSIRotate*				ConnectXSIRotate(CSLXSIRotate *in_pNode);
	CSLXSIScale*				ConnectXSIScale(CSLXSIScale *in_pNode);
	CSLXSIShear*				ConnectXSIShear(CSLXSIShear *in_pNode);
	CSLXSILookat*				ConnectXSILookat(CSLXSILookat *in_pNode);
	CSLXSIMatrix*				ConnectXSIMatrix(CSLXSIMatrix *in_pNode);

    virtual const SI_Char*		GetParameterName(CSLAnimatableType* in_pParameter);

private:
	CSIBCArray<CSLTemplate*>	m_TransformNodes;
};

/** 
* CSLXSITransform class
* This class handles the XSI transformation matrix of a model. It provides functions to set
* all aspects of the XSI transformation like SRT, pivots, shearing, etc.
*/
class XSIEXPORT CSLXSITransform
    : public CSLTemplate
{
public:
    CSLXSITransform(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
    virtual ~CSLXSITransform();

	/*!	Return the transformation matrix.
		\return	CSIBCMatrix4x4	Transformation matrix.
	*/
	CSIBCMatrix4x4 GetMatrix();

	/*!	Return the actual rotation in euler representation.
		\return	CSIBCVector3D	Rotation value.
	*/
	CSIBCVector3D GetEulerRotation();

	/*!	Change the rotation value in euler representation.
		\param	CSIBCVector3D&	New rotation value
		\return	None
	*/
	SI_Void SetEulerRotation(CSIBCVector3D &in_rValue);

	/*!	Return the actual scale.
		\return	CSIBCVector3D	Scale value.
	*/
	CSIBCVector3D GetScale();

	/*!	Change the scale value.
		\param	CSIBCVector3D&	New scale value
		\return	None
	*/
	SI_Void SetScale(CSIBCVector3D &in_rValue);

	/*!	Return the actual translation.
		\return	CSIBCVector3D	Translation value.
	*/
	CSIBCVector3D GetTranslation();

	/*!	Change the translation value.
		\param	CSIBCVector3D&	New translation value
		\return	None
	*/
	SI_Void SetTranslation(CSIBCVector3D &in_rValue);

	/*!	Return the shear.
		\return	CSIBCVector3D	Shear value.
	*/
	CSIBCVector3D GetShear();

	/*!	Change the shear value.
		\param	CSIBCVector3D&	New translation value
		\return	None
	*/
	SI_Void SetShear(CSIBCVector3D &in_rValue);

	/*!	Return the pivot position.
		\return	CSIBCVector3D	Pivot position value.
	*/
	CSIBCVector3D GetPivotPosition();

	/*!	Change the pivot position value.
		\param	CSIBCVector3D&	New pivot position value
		\return	None
	*/
	SI_Void SetPivotPosition(CSIBCVector3D &in_rValue);

	/*!	Return the pivot rotation.
		\return	CSIBCVector3D	Pivot rotation value.
	*/
	CSIBCVector3D GetPivotRotation();

	/*!	Change the pivot rotation value.
		\param	CSIBCVector3D&	New pivot rotation value
		\return	None
	*/
	SI_Void SetPivotRotation(CSIBCVector3D &in_rValue);

	/*!	Return the pivot scale.
		\return	CSIBCVector3D	Pivot scale value.
	*/
	CSIBCVector3D GetPivotScale();

	/*!	Change the pivot scale value.
		\param	CSIBCVector3D&	New translation value
		\return	None
	*/
	SI_Void SetPivotScale(CSIBCVector3D &in_rValue);

	/*!	Return the pivot compensation position.
		\return	CSIBCVector3D	pivot compensation position value.
	*/
	CSIBCVector3D GetPivotCompPosition();

	/*!	Change the pivot compensation position value.
		\param	CSIBCVector3D&	New pivot compensation position value
		\return	None
	*/
	SI_Void SetPivotCompPosition(CSIBCVector3D &in_rValue);

	/*!	Return the pivot compensation rotation.
		\return	CSIBCVector3D	pivot compensation rotation value.
	*/
	CSIBCVector3D GetPivotCompRotation();

	/*!	Change the pivot compensation rotation value.
		\param	CSIBCVector3D&	New pivot compensation rotation value
		\return	None
	*/
	SI_Void SetPivotCompRotation(CSIBCVector3D &in_rValue);

	/*!	Return the pivot compensation scale.
		\return	CSIBCVector3D	pivot compensation scale value.
	*/
	CSIBCVector3D GetPivotCompScale();

	/*!	Change the pivot compensation scale value.
		\param	CSIBCVector3D&	New pivot compensation scale value
		\return	None
	*/
	SI_Void SetPivotCompScale(CSIBCVector3D &in_rValue);

	/*!	Return the neutral pose position.
		\return	CSIBCVector3D	neutral pose position value.
	*/
	CSIBCVector3D GetNeutralPosePosition();

	/*!	Change the neutral pose position value.
		\param	CSIBCVector3D&	New neutral pose position value
		\return	None
	*/
	SI_Void SetNeutralPosePosition(CSIBCVector3D &in_rValue);

	/*!	Return the neutral pose rotation.
		\return	CSIBCVector3D	neutral pose rotation value.
	*/
	CSIBCVector3D GetNeutralPoseRotation();

	/*!	Change the neutral pose rotation value.
		\param	CSIBCVector3D&	New neutral pose rotation value
		\return	None
	*/
	SI_Void SetNeutralPoseRotation(CSIBCVector3D &in_rValue);

	/*!	Return the neutral pose scale.
		\return	CSIBCVector3D	neutral pose scale value.
	*/
	CSIBCVector3D GetNeutralPoseScale();

	/*!	Change the neutral pose scale value.
		\param	CSIBCVector3D&	New neutral pose scale value
		\return	None
	*/
	SI_Void SetNeutralPoseScale(CSIBCVector3D &in_rValue);

	/*!	Return the neutral pose shear.
		\return	CSIBCVector3D	neutral pose shear value.
	*/
	CSIBCVector3D GetNeutralPoseShear();

	/*!	Change the neutral pose shear value.
		\param	CSIBCVector3D&	New neutral pose shear value
		\return	None
	*/
	SI_Void SetNeutralPoseShear(CSIBCVector3D &in_rValue);

	/*!	Return the hirearchical scaling flag.
		\return	bool	hirearchical scaling flag value.
	*/
	SI_Bool GetHierarchicalScaling();

	/*!	Change the hirearchical scaling flag value.
		\param	bool&	New hirearchical scaling flag value
		\return	None
	*/
	SI_Void SetHierarchicalScaling(SI_Bool in_bValue);

	/*!	Return the rotation order.
		\return	CSIBCVector3D	Rotation order.
	*/
	CSLTemplate::ERotationOrder	GetRotationOrder();

	/*!	Return the rotation order as a string.
		\return	SI_Char* 	Rotation order.
	*/
	const SI_Char*				GetRotationOrderAsString();

	/*!	Change the rotation order.
		\param	CSLTemplate::ERotationOrder	New rotation order
		\return	SI_Error Operation successful or not.
	*/
	SI_Error					SetRotationOrder(CSLTemplate::ERotationOrder);

	/*!	Change the rotation order using a string value.
		\param	SI_Char*	New rotation order
		\return	SI_Error Operation successful or not.
	*/
	SI_Error					SetRotationOrderAsString(const SI_Char*);


	/*!	Computes this CSLTransform's local matrix.
	\return	Error code
	*/
	SI_Error ComputeLocalMatrix();

	/*!	Computes this CSLTransform's global matrix.
	\return	Error code
	*/
	SI_Error ComputeGlobalMatrix();

	/*!	Returns the global matrix
	\return	CSIBCMatrix4x4 The global matrix
	*/
	CSIBCMatrix4x4 &GetGlobalMatrix();

	/*!	Computes this CSLTransform's local matrix at the specified time value.
	\param	in_fTime	The time
	\return	Error code
	*/
	SI_Error ComputeLocalMatrix( SI_Float in_fTime );

	/*!	Computes this CSLTransform's global matrix at the specified time value.
		Also forces an evaluation of the parent global matrix to ensure a correct global matrix. 
	\param	in_fTime	The time
	\return	Error code
	*/
	SI_Error ComputeGlobalMatrix( SI_Float in_fTime );



	virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);
    virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szParameterName);
    virtual ETemplateType Type();

	virtual SI_Error Synchronize();

	/*!	Return the name (string) of a specified sub parameter.
		\param	in_pParameter	The sub parameter
		\return	SI_Char*	Name of the sub parameter.
	*/
    virtual const SI_Char* GetParameterName(CSLAnimatableType* in_pParameter);

	/*!	Returns the proxy to the scale vector
	\return	CSLVector3DProxy* 
	*/
	CSLVector3DProxy*	ScaleProxy() { return &m_Scale;};

	/*!	Returns the proxy to the hierarchical scaling value
	\return	CSLBoolProxy* 
	*/
	CSLBoolProxy*		HierarchicalScalingProxy() { return &m_HierarchicalScaling;};

	/*! Returns the proxy to the Rotation vector
	\return CSLVector3DProxy*
	*/
	CSLVector3DProxy*	RotationProxy() { return &m_Rotation;};
	/*! Returns the proxy to the Translation vector
	\return CSLVector3DProxy*
	*/
	CSLVector3DProxy*	TranslationProxy() { return &m_Translation;};
	/*! Returns the proxy to the Shear vector
	\return CSLVector3DProxy*
	*/
	CSLVector3DProxy*	ShearProxy() { return &m_Shear;};
	
	/*! Returns the proxy to the Pivot Position vector
	\return CSLVector3DProxy*
	*/
	CSLVector3DProxy*	PivotPositionProxy() { return &m_PivotPosition;};
	/*! Returns the proxy to the Pivot Rotation vector
	\return CSLVector3DProxy*
	*/
	CSLVector3DProxy*	PivotRotationProxy() { return &m_PivotRotation;};
	/*! Returns the proxy to the Pivot Scale vector
	\return CSLVector3DProxy*
	*/
	CSLVector3DProxy*	PivotScaleProxy() { return &m_PivotScale;};

	/*! Returns the proxy to the Pivot Comp Position vector
	\return CSLVector3DProxy*
	*/
	CSLVector3DProxy*   PivotCompPositionProxy() { return &m_PivotCompPosition;};
	/*! Returns the proxy to the Pivot Comp Rotation vector
	\return CSLVector3DProxy*
	*/
	CSLVector3DProxy*	PivotCompRotationProxy() { return &m_PivotCompRotation;};
	/*! Returns the proxy to the Pivot Comp Scale vector
	\return CSLVector3DProxy*
	*/
	CSLVector3DProxy*	PivotCompScaleProxy() { return &m_PivotCompScale;};

	/*! Returns the proxy to the Neutral Pose Scale vector
	\return CSLVector3DProxy*
	*/
	CSLVector3DProxy*	NeutralPoseScaleProxy() { return &m_NeutralPoseScale;};
	/*! Returns the proxy to the Neutral Pose Rotation vector
	\return CSLVector3DProxy*
	*/
	CSLVector3DProxy*	NeutralPoseRotationProxy() { return &m_NeutralPoseRotation;};
	/*! Returns the proxy to the Neutral Pose Position vector
	\return CSLVector3DProxy*
	*/
	CSLVector3DProxy*	NeutralPosePositionProxy() { return &m_NeutralPosePosition;};
	/*! Returns the proxy to the Neutral Pose Shear vector
	\return CSLVector3DProxy*
	*/
	CSLVector3DProxy*	NeutralPoseShearProxy() { return &m_NeutralPoseShear;};
	/*! Returns the proxy to the Rotation Order value
	\return CSLStrEnumProxy<ERotationOrder, SI_ZYX>*
	*/
	CSLStrEnumProxy<ERotationOrder, SI_ZYX>* RotationOrderProxy() { return &m_RotationOrder;};

	SI_Void SetMatrix ( CSIBCMatrix4x4& in_mMatrix ) { m_TransformMatrix = in_mMatrix;  m_bCanDecompose = false; };
	bool	CanDecompose ( ) { return m_bCanDecompose; };

	////////////// LIMIT
	/*!	Connects a limit to this template
		\param	CSLXSILimit*	the limit to connect
		\return	CSLXSILimit*	Pointer to the specified limit
	*/
	CSLXSILimit *ConnectXSILimit(CSLXSILimit *in_pXSILimit);


	/*!	Adds a limit to this template
		\return	CSLXSILimit*	Pointer to the newly created limit, NULL if failed
	*/
	CSLXSILimit* AddXSILimit(CSLAnimatableType* in_pParameter);

	/*!	Clears all limits on that template
		\return	SI_Error whether the function failed or succeeded
	*/
	SI_Error ClearXSILimits();

	/*!	Return the list of limits on that template
		\return	CSLXSILimit**	array of XSI limits
	*/
	CSLXSILimit** GetXSILimitList();

	/*!	Return the number of limits on that template
		\return	SI_Int the number of limits on that template
	*/
	SI_Int GetXSILimitCount();

	/*!	Removes a limit by index
		\return	SI_Error whether the function failed or succeeded
	*/
	SI_Error RemoveXSILimit(SI_Int in_nIndex);

	/*!	Removes a limit
		\return	SI_Error whether the function failed or succeeded
	*/
	SI_Error RemoveXSILimit(CSLXSILimit *in_pToRemove);

	CSLXSIPolymatricks*	CreatePolymatricks();
	CSLXSIPolymatricks*	GetPolymatricks();
	void				ConnectPolymatricks(CSLXSIPolymatricks* in_pPolymatricks);
	bool				CollapsePolymatricks();

private:
	void										MoveAnimation(CSLTemplate* in_pFrom, CSLAnimatableType *in_pParam, char* in_pNewName);

private:
	CSLStrEnumProxy<ERotationOrder, SI_ZYX>		m_RotationOrder;

    CSLVector3DProxy 							m_Scale;
	CSLBoolProxy	 							m_HierarchicalScaling;
    CSLVector3DProxy 							m_Rotation;
    CSLVector3DProxy 							m_Translation;
	CSLVector3DProxy 							m_Shear;
	
	CSLVector3DProxy 							m_PivotPosition;
	CSLVector3DProxy 							m_PivotRotation;
	CSLVector3DProxy 							m_PivotScale;

	CSLVector3DProxy 							m_PivotCompPosition;
	CSLVector3DProxy 							m_PivotCompRotation;
	CSLVector3DProxy 							m_PivotCompScale;

	CSLVector3DProxy 							m_NeutralPoseScale;
    CSLVector3DProxy 							m_NeutralPoseRotation;
    CSLVector3DProxy 							m_NeutralPosePosition;
	CSLVector3DProxy 							m_NeutralPoseShear;

	CSIBCMatrix4x4 								m_TransformMatrix;
	CSIBCMatrix4x4 								m_GlobalMatrix;
	bool										m_bCanDecompose;

    CSIBCArray<CSLXSILimit *>					m_XSILimits;
	CSLXSIPolymatricks*							m_pPolymatricks;
	void *										m_pReserved;	// reserved for future extension
};

/** 
* CSLXSIBasePose class
* This class handles the XSI base pose matrix of a model. It provides functions to set
* all aspects of the XSI base pose like SRT, pivots, shearing, etc.
*/
class XSIEXPORT CSLXSIBasePose
    : public CSLTemplate
{
public:
    CSLXSIBasePose(CSLScene* in_pScene, CSLModel *in_pModel, CdotXSITemplate* in_pTemplate);
    virtual ~CSLXSIBasePose();

	/*!	Return the BasePoseation matrix.
		\return	CSIBCMatrix4x4	Base pose matrix.
	*/
	CSIBCMatrix4x4 GetMatrix();

	/*!	Return the actual rotation in euler representation.
		\return	CSIBCVector3D	Rotation value.
	*/
	CSIBCVector3D GetEulerRotation();

	/*!	Change the rotation value in euler representation.
		\param	CSIBCVector3D&	New rotation value
		\return	None
	*/
	SI_Void SetEulerRotation(const CSIBCVector3D &in_rValue);

	/*!	Return the actual scale.
		\return	CSIBCVector3D	Scale value.
	*/
	CSIBCVector3D GetScale();

	/*!	Change the scale value.
		\param	CSIBCVector3D&	New scale value
		\return	None
	*/
	SI_Void SetScale(CSIBCVector3D &in_rValue);

	/*!	Return the actual translation.
		\return	CSIBCVector3D	Translation value.
	*/
	CSIBCVector3D GetTranslation();

	/*!	Change the translation value.
		\param	CSIBCVector3D&	New translation value
		\return	None
	*/
	SI_Void SetTranslation(CSIBCVector3D &in_rValue);

	virtual CSLAnimatableType* ParameterFromName(SI_Char *in_szName);
    virtual CSLAnimatableType* ParameterFromType(EFCurveType in_Type, SI_Char *in_szParameterName);
    virtual ETemplateType Type();

	virtual SI_Error Synchronize();

	/*!	Return the name (string) of a specified sub parameter.
		\param	in_pParameter	The sub parameter
		\return	SI_Char*	Name of the sub parameter.
	*/
    virtual const SI_Char* GetParameterName(CSLAnimatableType* in_pParameter);

	/*!	Computes this CSLBasePose's local matrix.
	\return	Error code
	*/
	SI_Error ComputeMatrix();

	/*! Return the value of the scale proxy vector.
		\return CSLVector3DProxy&	Scale proxy vector value
	*/
	CSLVector3DProxy& GetScaleProxy();

	/*! Return the value of the rotation proxy vector.
		\return CSLVector3DProxy&	Rotation proxy vector value
	*/
	CSLVector3DProxy& GetRotationProxy();

	/*! Return the value of the Translation proxy vector.
		\return CSLVector3DProxy&	Translation proxy vector value
	*/
	CSLVector3DProxy& GetTranslationProxy();

	/*!	Change the base pose matrix values. The scale, rotation and translation values are also updated. 
		\param	CSIBCMatrix4x4&	The matrix that contains the new values
		\return	None
	*/
	SI_Void SetMatrix( CSIBCMatrix4x4 &in_Matrix );

private:
    CSLVector3DProxy m_Scale;
    CSLVector3DProxy m_Rotation;
    CSLVector3DProxy m_Translation;
	CSIBCMatrix4x4 m_BasePoseMatrix;

	void *m_pReserved;	// reserved for future extension
};


#endif

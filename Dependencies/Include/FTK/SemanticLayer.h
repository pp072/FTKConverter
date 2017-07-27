#ifndef _SEMANTICLAYER_H
#define _SEMANTICLAYER_H

// Disable "identifier was truncated to '255' characters in the debug information" warning.
#if defined(_WIN32) || defined(_WIN32_WCE) || defined (_XBOX)
#pragma warning( disable : 4786 )
#endif

// Include classes, for declarations
#include <SIBCVector4Dd.h>
#include "Template.h"
#include "Action.h"
#include "ActionClip.h"
#include "Ambience.h"
#include "Angle.h"
#include "Primitive.h"
#include "Camera.h"
#include "Cluster.h"
#include "Constraint.h"
#include "CoordinateSystem.h"
#include "CurveList.h"
#include "CustomPSet.h"
#include "Envelope.h"
#include "EnvelopeList.h"
#include "Extrapolation.h"
#include "BaseFCurve.h"
#include "FCurve.h"
#include "FileInfo.h"
#include "SceneInfo.h"
#include "Fog.h"
#include "Geometry.h"
#include "GlobalMaterial.h"
#include "IK.h"
#include "IKEffector.h"
#include "IKJoint.h"
#include "IKRoot.h"
#include "ImageClip.h"
#include "Instance.h"
#include "Light.h"
#include "Material.h"
#include "MaterialLibrary.h"
#include "Mesh.h"
#include "Mixer.h"
#include "Model.h"
#include "Null.h"
#include "NurbsCurve.h"
#include "NurbsSurface.h"
#include "PatchSurface.h"
#include "PolygonList.h"
#include "Scene.h"
#include "BaseShape.h"
#include "ShapeAnimation.h"
#include "StaticValue.h"
#include "SurfaceMesh.h"
#include "Texture2D.h"
#include "TimeControl.h"
#include "Track.h"
#include "Transform.h"
#include "TriangleList.h"
#include "TriangleStrip.h"
#include "TriangleStripList.h"
#include "Visibility.h"
#include "XSIMaterial.h"
#include "XSIShader.h"
#include "ShaderInstanceData.h"
#include "ConnectionPoint.h"
#include "ShaderConnectionPoint.h"
#include "PointLight.h"
#include "InfiniteLight.h"
#include "DirectionalLight.h"
#include "SpotLight.h"
#include "ActionFCurve.h"
#include "VariantParameter.h"
#include "UVCoordArray.h"
#include "Shape.h"
#include "Shape_35.h"
#include "XSIImageLibrary.h"
#include "XSIImage.h"
#include "XSIImageData.h"
#include "XSIImageFX.h"
#include "LightInfo.h"
#include "XSIMaterialInfo.h"
#include "XSINurbsProjectionList.h"
#include "XSINurbsTrimList.h"
#include "CustomParamInfo.h"
#include "FXTree.h"
#include "FXNode.h"
#include "FXNodeConnection.h"
#include "XSIUserData.h"
#include "XSIUserDataList.h"
#include "XSIVertexList.h"
#include "XSITriangleList.h"
#include "XSIPolygonList.h"
#include "XSIShape.h"
#include "XSITriangleStripList.h"
#include "XSISubComponentList.h"
#include "XSISubComponentAttributeList.h"
#include "XSIMesh.h"
#include "XSIGeometry.h"
#include "XSIShapeAnimation.h"
#include "XSIShapeReference.h"
#include "XSIShaderMultiPortConnection.h"
#include "XSIImageFX2.h"
#include "XSICameraFocalLength.h"
#include "XSITextureLayer.h"
#include "XSITextureLayerPort.h"
#include "XSIUserKeyword.h"
#include "XSIClipToParent.h"

#endif

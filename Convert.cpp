#include "Convert.h"
#include "utils.h"
#include "SL_Array.h"
#include "XSITransform.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <direct.h>
#include "MeshOptimizer.h"
using namespace std;
//#include "Functions.h"
Convert::Convert(void)
{
	//	_nodes=0x0;
	_frameCount = 0;
//	_lastAccumVertCount = 0;
	optimize=true;
}

Convert::~Convert(void)
{
	for( unsigned int i = 0; i < _joints.size(); ++i ) delete _joints[i];
	for( unsigned int i = 0; i < _meshes.size(); ++i ) delete _meshes[i];
}
bool Convert::parse( string &fileName)
{
	/*char *fileNametmp=  new char[((int)fileName.length()+1)];
	wchar_t* tmp=new wchar_t[(int)fileName.length()];
	wcscpy(tmp,fileName.c_str());
	size_t convertedChars=0;
	wcstombs_s( &convertedChars, fileNametmp, ((int)fileName.length()+1)*2, tmp,((int)fileName.length()+1)*2);*/
	//string tmp = fileName;
	char *fileNametmp=  new char[((int)fileName.length()+1)];
	strcpy(fileNametmp, fileName.c_str() );
	CSLScene Scene;
	stop
	if (Scene.Open( fileNametmp ) == SI_SUCCESS)
	{
		Scene.Read();
		////Вытаскиваем joint'ы
		CSLSceneInfo* _SceneInfo = Scene.SceneInfo();
		_start = _SceneInfo->GetStart();
		_end   =_SceneInfo->GetEnd();
		_framerate = _SceneInfo->GetFrameRate();
		_frameCount =_end-_start;
		FFrameCount =ceil( _frameCount);
 		CSLImageLibrary* materials=Scene.GetImageLibrary();
		LoadMaterials(materials);


		CSLCoordinateSystem* CoordSys= Scene.CoordinateSystem();
		//EAxisOrientation YOrient= CoordSys->
		stop
		CSLEnvelopeList* envelopeList = Scene.EnvelopeList();
		if(envelopeList!=0x0)
		{
			int countEnv = envelopeList->GetEnvelopeCount();
			CSLEnvelope **   Envelopes = envelopeList->Envelopes();
			for (int i=0;i<countEnv;i++)
			{
				CSLModel* joint= Envelopes[i]->GetDeformer();
				CSLModel* mesh= Envelopes[i]->GetEnvelope();

				ProcessJoint(joint,mesh);
				stop
			}
		}
		Recurse( Scene.Root());
		ProcessMesh(Scene.Root());
		
 		for (unsigned int i=0;i<_joints.size();i++)
 		{
 			_joints[i]->index = i+1;
 		}
	}


	calcTangentSpaceBasis( _vertices );
	// Clean up
	for( unsigned int i = 0; i < _meshes.size(); ++i )
	{
		for( unsigned int j = 0; j < _meshes[i]->triGroups.size(); ++j )
		{
			delete[] _meshes[i]->triGroups[j].posIndexToVertices;
			_meshes[i]->triGroups[j].posIndexToVertices = 0x0;
		}
	}

	stop
	return true;
}

void Convert::LoadMaterials( CSLImageLibrary* matlib )
{
	CSLImage** matlist= matlib->GetImageList();

 	int count = matlib->GetImageCount();
	for (int i=0;i<count;i++ )
	{
		string matname = matlist[i]->GetName();
		string matpath=matlist[i]->GetSourceFile();
		if (!matname.empty() && !matpath.empty())
		{
			Image * imageNode = new Image();
			imageNode->name = matname;
			imageNode->path = matpath;
			_images.push_back(imageNode);
		}
		stop
	}
// 	for (int i=0;i<count;i++ )
// 	{
// 		if (matlist[i]->Type()==CSLTemplate::XSI_MATERIAL)
// 		{
// 			CSLXSIMaterial* xsimat =(CSLXSIMaterial*)matlist[i];
// 			int shadeCount= xsimat->GetShaderCount();
// 			CSLXSIShader** shadelist = xsimat->GetShaderList();
//  			for (int i = 0; i < shadeCount ; i++)
//  			{
//  				//shadelist[i]->
//  			}
// 
// 			//CSLXSITextureLayer** textLayer =  xsimat->GetTextureLayerList();
// 			//textLayer[0].get
// 			CSLXSIMaterialInfo* infoMat=xsimat->GetMaterialInfo();
// 
// 			//infoMat->get
// 
// 			stop
// 		}
// 		stop
// 
// 	}
}
void Convert::ProcessJoint( CSLModel* in_child, CSLModel* mesh )
{
	JointInstance *oNode = new JointInstance;
	string JointName= in_child->GetName();
	strcpy( oNode->name, JointName.c_str() );
	CSLXSIBasePose* BasePose=mesh->GetXSIBasePose();


	Matrix4f BasePoseMatrix;
	if (BasePose!=0x0)
	{
		BasePose->ComputeMatrix();
		CSIBCMatrix4x4 BasePoseMatrix=BasePose->GetMatrix();


		oNode->BaseModelPose=BasePoseMatrix;
		stop
	}
	_jointInstances.push_back(oNode);

	stop

}
void Convert::Recurse( CSLModel* in_child )
{
	log(in_child->GetName() );
	Strip( in_child );
	CSLModel* *l_childrenList = in_child->GetChildrenList();
	for (int i = 0; i < in_child->GetChildrenCount(); i++ )
	{
		Recurse( l_childrenList[i] );
	}
	stop
}
void Convert::ProcessMesh( CSLModel* in_child )
{
	//Strip( in_child );
	if (in_child->GetPrimitiveType()==CSLTemplate::XSI_MESH)
	{
		CSLXSIMesh*  left_primitive = (CSLXSIMesh*) in_child->Primitive();
		StripMesh( left_primitive );
	}
	CSLModel* *l_childrenList = in_child->GetChildrenList();
	for (int i = 0; i < in_child->GetChildrenCount(); i++ )
	{
		ProcessMesh( l_childrenList[i] );
	}
}
int Convert::Strip( CSLModel* in_left )
{
		int type= in_left->GetPrimitiveType();
		string name = in_left->GetName();
		if(name!="" && type!=CSLTemplate::SI_MATERIAL_LIBRARY &&
			type!=CSLTemplate::SI_DIRECTIONAL_LIGHT )	
		{
			string ModelName= in_left->GetName();
			//in_left->en
			if(_SI_STRCMP(ModelName.c_str(),"Scene_Root")==0  )
			{
				//CSLTransform *Transform=in_left->Coo
				//stop

			}
			if(_SI_STRCMP(ModelName.c_str(),"Scene_Root")!=0  )
			{
					SceneNode *oNode = new SceneNode();
					strcpy( oNode->name, ModelName.c_str() );
					//oNode->typeJoint=false;

					//Получаем локальную и глобальную матрицы
					//in_left->Tra
					
					CSLXSITransform *Transform=in_left->XSITransform();
					//m_aScalingAnims[0]=Transform->GetSpecificFCurve(CSLTemplate::EFCurveType::SI_SCALING_X);
					//Transform->GetMatrix();
					//Transform->ComputeLocalMatrix();
					//Transform->ComputeGlobalMatrix();
					Transform->ComputeLocalMatrix();
					stop
					CSIBCMatrix4x4 transMatrixLocal=Transform->GetMatrix();
					//transMatrixLocal.Transpose();
					//transMatrixLocal.Transpose();
					CSIBCMatrix4x4 transMatrixGlobal=Transform->GetGlobalMatrix();
					
					//transMatrixLocal.Normalize();
					CSLXSIBasePose* BasePose=in_left->GetXSIBasePose();
					//transMatrixLocal.Get(oNode->matRel.x);
					stop
					oNode->matRel=FromSCIMatrix4x4toMatrix4f(transMatrixLocal);

					stop
					//oNode->matRel=oNode->matRel.transposed();
					//oNode->matAbs=FromSCIMatrix4x4toMatrix4f(transMatrixGlobal);
					
					Matrix4f BasePoseMatrix;
					Matrix4f MeshBasePoseMatrix;
					if (BasePose!=0x0 && IsJoint(string(oNode->name)) && type!=CSLTemplate::XSI_MESH)
					{

						CSIBCMatrix4x4 BaseMatrix=BasePose->GetMatrix();
						CSIBCMatrix4x4 MeshBasePose = GetMeshBasePose(ModelName);
						stop


						BasePoseMatrix= FromSCIMatrix4x4toMatrix4f(BaseMatrix);
						MeshBasePoseMatrix = FromSCIMatrix4x4toMatrix4f(MeshBasePose);

						BasePoseMatrix.inverted();

						Matrix4f MatForBasePose = oNode->matRel;
						BasePoseMatrix=(MatForBasePose*BasePoseMatrix);
						BasePoseMatrix=(BasePoseMatrix.inverted()*MatForBasePose)*MeshBasePoseMatrix;

						SceneNode *parentNode = findNodeFromName(string(in_left->Parent()->GetName()));
						if (parentNode==0x0 || parentNode->typeJoint)
						{
							//oNode->matRel=oNode->matRel;
						}else
						{
							oNode->matRel=parentNode->matRel*oNode->matRel;
							stop
						}


						oNode->daeInvBindMat = BasePoseMatrix;
						Vec3f Rtransl, Rvrot, Rscal;
						//Matrix4f testmatr;
 						if (type==CSLTemplate::XSI_MESH)
 						{
 							if(oNode->matRel.x[0]==0)
 								oNode->matRel.x[0]=1;
 							if(oNode->matRel.x[5]==0)
 								oNode->matRel.x[5]=1;
 							if(oNode->matRel.x[10]==0)
 								oNode->matRel.x[10]=1;
 						}
 						oNode->matRel.decompose( Rtransl, Rvrot, Rscal );
 						Rvrot.x = radToDeg( Rvrot.x );
 						Rvrot.y = radToDeg( Rvrot.y );
 						Rvrot.z = radToDeg( Rvrot.z );
						
						//BaseMatrix.GetTransforms(scale,rotate,trans);
						//delete oNode;
						Joint * joint = new Joint();
						//joint = (Joint *)oNode;
						joint->matAbs = oNode->matAbs;
						joint->matRel= oNode->matRel;
						joint->daeInvBindMat = oNode->daeInvBindMat;
						joint->typeJoint =true;
						//joint->invBindMat = Matrix4f();
						strcpy( joint->name, oNode->name );
						//joint->name
						delete oNode;
						oNode = (SceneNode*)joint;
						_joints.push_back(joint);
						stop
						
					}else
					{
						oNode->matRel=oNode->matRel;
					}
					Vec3f Rtransl, Rvrot, Rscal;
					oNode->matRel.decompose( Rtransl, Rvrot, Rscal );

					Rvrot.x = radToDeg( Rvrot.x );
					Rvrot.y = radToDeg( Rvrot.y );
					Rvrot.z = radToDeg( Rvrot.z );
					stop
					

					SceneNode *parentNode = findNodeFromName(string(in_left->Parent()->GetName()));
					oNode->matAbs = oNode->matRel;
					if(parentNode!=0x0)
					{
						Vec3f Rtransl, Rvrot, Rscal;
						//oNode->matRel =FromSCIMatrix4x4toMatrix4f(transMatrixLocal) ;
						/*if(!parentNode->typeJoint&&!oNode->typeJoint)
							oNode->matRel=parentNode->matRel*oNode->matRel;*/
						oNode->matRel.decompose( Rtransl, Rvrot, Rscal );

						Rvrot.x = radToDeg( Rvrot.x );
						Rvrot.y = radToDeg( Rvrot.y );
						Rvrot.z = radToDeg( Rvrot.z );

						stop

						parentNode->children.push_back(oNode);
						oNode->parent = parentNode;
						//Matrix4f LocalBasePose=parentNode->matRel* BasePoseMatrix.inverted();
						float det= BasePoseMatrix.determinant();
						//stop
						//if (BasePoseMatrix.determinant()==1)
							//oNode->matAbs =FromSCIMatrix4x4toMatrix4f(transMatrixGlobal);
							oNode->matAbs=oNode->parent->matAbs * oNode->matRel;
						//else
							//oNode->matAbs = BasePoseMatrix;

						if (Transform)
						{
							for (int i=0;i<_frameCount;i++)
							{	
									Transform->ComputeLocalMatrix(/*(_frameCount/(_framerate))**/i);
									CSIBCMatrix4x4 transAnimaLocal=Transform->GetMatrix();
									oNode->frames.push_back(oNode->parent->frames[i]*FromSCIMatrix4x4toMatrix4f(transAnimaLocal));	
							}
						}
					}
					if(parentNode!=0x0 && !parentNode->typeJoint &&oNode->typeJoint)
					{
						oNode->parent=0x0;
						oNode->matAbs = oNode->matRel;

						//Анимация
						oNode->frames.clear();
						if (Transform)
						{
							for (int i=0;i<_frameCount;i++)
							{	
									Transform->ComputeLocalMatrix(/*(_frameCount/(_framerate))**/i);
									CSIBCMatrix4x4 transAnimaLocal=Transform->GetMatrix();
									oNode->frames.push_back(FromSCIMatrix4x4toMatrix4f(transAnimaLocal));
									stop
							}
							stop
						}


//						transAccum = Matrix4f();
					}else
					{
						//Анимация
						stop
						//CSLXSITransform *pTransform=in_left->XSITransform();
						oNode->frames.clear();
						if (Transform)
						{
							for (int i=0;i<_frameCount;i++)
							{	
									Transform->ComputeLocalMatrix(/*(_frameCount/(_framerate))**/i);
									CSIBCMatrix4x4 transAnimaLocal=Transform->GetMatrix();
									oNode->frames.push_back(FromSCIMatrix4x4toMatrix4f(transAnimaLocal));
									stop
							}
							stop
						}
//						transAccum = oNode->matRel;
						//oNode->matAbs =oNode->matRel;
					}
					Vec3f Ltransl, Lvrot, Lscal;

					oNode->matAbs.decompose( Ltransl, Lvrot, Lscal );
					Lvrot.x = radToDeg( Lvrot.x );
					Lvrot.y = radToDeg( Lvrot.y );
					Lvrot.z = radToDeg( Lvrot.z );


					_nodes.push_back(oNode);
					stop
			}
		}
	return 0;
}
CSIBCMatrix4x4 Convert::GetMeshBasePose( string & Name )
{
	for (int i = 0; i < _jointInstances.size() ; i++)
	{
		if(_SI_STRCMP(Name.c_str(), _jointInstances[i]->name)==0)
			return _jointInstances[i]->BaseModelPose;
	}
	return CSIBCMatrix4x4();
}
int Convert::StripMesh( CSLXSIMesh* in_left )
{
	int l_lIndex = 0;
	CSLXSITriangleList** left;
	left = in_left->XSITriangleLists();
	string name=in_left->GetName();
	int Count = in_left->GetXSITriangleListCount();
	

	CSLModel *model=in_left->ParentModel();

	CSLXSITransform *Transform=model->XSITransform();
	Transform->ComputeLocalMatrix();
	CSIBCMatrix4x4 transMatrixLocal=Transform->GetGlobalMatrix();

	
	string ModelName= in_left->GetName();
	Mesh *oNode = new Mesh();
	SceneNode * node = findNodeFromName(ModelName);
	oNode->children = node->children;
	oNode->daeInvBindMat = node->daeInvBindMat;
	//oNode->name = node->name;
	strcpy( oNode->name, node->name );
	oNode->matAbs = node->matAbs;
	oNode->matRel = node->matRel;
	oNode->parent = node->parent;
	oNode->frames = node->frames;

	//delete node;
	//node = (SceneNode*)oNode;
	//model->Get
	//oNode->matRel = Matrix4f();
	//oNode->matRel=oNode->matRel.inverted();
	//oNode->parent = node->parent;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
 	Vec3f Rtransl, Rvrot, Rscal;
 
 	oNode->matRel.decompose( Rtransl, Rvrot, Rscal );
 	Rvrot.x = radToDeg( Rvrot.x );
 	Rvrot.y = radToDeg( Rvrot.y );
 	Rvrot.z = radToDeg( Rvrot.z );
		
		
	stop
	//strcpy( oNode->name, ModelName.c_str() );
	//oNode->typeJoint=false;

	//Получаем локальную и глобальную матрицы
	//CSLXSITransform *Transform=model->XSITransform();
	//CSIBCMatrix4x4 transMatrixLocal=Transform->GetMatrix();
	//CSIBCMatrix4x4 transMatrixGlobal=Transform->GetGlobalMatrix();

	//SI_Matrix *transMatrixLocalSiMatrix=transMatrixLocal.GetSIMatrix();
	//SI_Matrix *transMatrixGlobalSiMatrix=transMatrixGlobal.GetSIMatrix();
// 	for (int i = 0; i < 4 ; i++)
// 	{
// 		for (int j = 0; j < 4 ; j++)
// 		{
// 			oNode->matRel.c[i][j]=transMatrixGlobalSiMatrix[0][i][j];
// 			oNode->matAbs.c[i][j]=transMatrixLocalSiMatrix[0][i][j];
// 		}
// 	}

// 	SceneNode *parentNode = findNodeFromName(string(model->Parent()->GetName()));
// 	if(parentNode!=0x0)
// 	{
// 		parentNode->children.push_back(oNode);
// 		oNode->parent = parentNode;
// 	}
//	_nodes.push_back(oNode);
	//oNode->triGroups.clear();
	_meshes.push_back(oNode);

	in_left->GetXSITriangleListCount();
	for (l_lIndex = 0; l_lIndex < in_left->GetXSITriangleListCount(); l_lIndex++)
	{

		StripTriangleList( left[l_lIndex], in_left, oNode);
	}
	return 0;
}
int Convert::StripTriangleList( CSLXSITriangleList* in_left, CSLXSIMesh* in_mesh, Mesh *oNode )
{

	unsigned int firstGeoVert = (unsigned int)_vertices.size();

	//Получаем индексы вершин

	CSLXSIIndexList::CSLIntArray* vertex_ptr= in_left->GetVertexIndices();

	//Получаем индексы для нормалей и UV
	CSLXSISubComponentList::CSLStringArray* atrNamesArray= in_left->GetAttributeNameArray();
	CSLArrayProxy<SI_Int, SI_Int, 1>* normal_ptr=0x0;
	CSLArrayProxy<SI_Int, SI_Int, 1>* textureUV_ptr=0x0;
	for (int i=0;i<atrNamesArray->GetUsed();i++)
	{
		//cout<<atrNamesArray[0][i]<<endl;
		if (_SI_STRCMP(atrNamesArray[0][i],"XSINormal")==0)
			normal_ptr=in_left->GetAttributeByName(atrNamesArray[0][i]);
		if (_SI_STRCMP(atrNamesArray[0][i],"Texture_Projection")==0)
			textureUV_ptr=in_left->GetAttributeByName(atrNamesArray[0][i]);
	}

	//Test
	int TriangleCount = in_left->GetTriangleCount();


	//Получаем Списки для вершин, нормалей, UV
	CSLXSIShape *shape = in_mesh->XSIShape();


	CSLXSISubComponentAttributeList *vertexPositionsList=shape->GetVertexPositionList();
	CSLXSISubComponentAttributeList *XsiNormalList=shape->GetFirstNormalList();
	CSLXSISubComponentAttributeList *XsiUVList=shape->GetFirstTexCoordList();

	CSLXSISubComponentAttributeList::CSLFloatArray* vertexPositionsArray=vertexPositionsList->GetAttributeArray();

	CSLXSISubComponentAttributeList::CSLFloatArray* vertexNormalsArray=XsiNormalList->GetAttributeArray();
	CSLXSISubComponentAttributeList::CSLFloatArray* vertexUVsArray=XsiUVList->GetAttributeArray();


	TriGroup oTriGroup;
	oTriGroup.first = (unsigned int)_indices.size();
	oTriGroup.count = (unsigned int)(TriangleCount*3);
	oTriGroup.vertRStart = (unsigned int)_vertices.size();
	oTriGroup.numPosIndices = (unsigned int)(vertexPositionsList->GetCount());
	
	oTriGroup.posIndexToVertices = new vector< unsigned int >[oTriGroup.numPosIndices];
	//Записываем позиции точек

	for( unsigned int k = 0; k < oTriGroup.count ; ++k )
	{
		vector< unsigned int > &vertList = oTriGroup.posIndexToVertices[vertex_ptr[0][k]];
		bool found = false;
		unsigned int index = (unsigned int)_vertices.size();

		// Проверяем есть ли для вершины индексы позиций
		for( unsigned int l = 0; l < vertList.size(); ++l )
		{
			Vertex &v = _vertices[vertList[l]];

			if( v.storedPos == getPos( vertex_ptr[0][k], vertexPositionsArray) &&
				v.storedNormal == ((normal_ptr!=0x0)?getNormal( normal_ptr[0][k], vertexNormalsArray):Vec3f()) &&
				v.texCoords[0] == ((textureUV_ptr!=0x0)?getTexCoords( textureUV_ptr[0][k+0], 0 , vertexUVsArray):Vec3f())/* &&
				v.texCoords[1] == iTriGroup.getTexCoords( textureUV_ptr[0][k+1], 1 , vertexUVsArray) &&
				v.texCoords[2] == iTriGroup.getTexCoords( textureUV_ptr[0][k+2], 2 , vertexUVsArray) &&
				v.texCoords[3] == iTriGroup.getTexCoords( textureUV_ptr[0][k+3], 3 , vertexUVsArray)*/ )
			{
				found = true;
				index = vertList[l];
				break;
			}
		}
		if( found )
		{
			_indices.push_back( index );	
		}else
		{
			Vertex v;
			v.daePosIndex = vertex_ptr[0][k];

			int normIndex = (normal_ptr!=0x0) ? normal_ptr[0][k] : 0;
			v.storedPos = getPos( v.daePosIndex,vertexPositionsArray );
			v.pos = v.storedPos;

			//float tmp=v.pos.y;
			//v.pos.y = v.pos.z;
			//v.pos.z = -tmp;

			v.texCoords[0] = textureUV_ptr!=0x0 ? getTexCoords( textureUV_ptr[0][k+0], 0 ,vertexUVsArray ):Vec3f() ;

			v.storedNormal = normal_ptr !=0x0 ? getNormal( normal_ptr[0][k],vertexNormalsArray ):Vec3f();
			Matrix4f ModelBASE;
			CSLModel *model=in_mesh->ParentModel();
			CSLXSIBasePose* modelBase= model->GetXSIBasePose();
			if (modelBase!=0x0)
			{
				CSIBCMatrix4x4 MatrixBasse=modelBase->GetMatrix();
				ModelBASE = FromSCIMatrix4x4toMatrix4f(MatrixBasse);
			}
			


			//Если есть кости для данной модели
			if (model->GetEnvelopeCount()>0)
			{	
				CSLEnvelope** envelopeList=model->GetEnvelopeList();
				vector< float >		_VWeights;
				vector< Joint * >	_VJoints;

				for (int i=0;i<model->GetEnvelopeCount();i++)
				{
					CSLEnvelope* envlope =envelopeList[i];
					CSLEnvelope::CSLVertexWeightArray* weightlist=envlope->GetVertexWeightList();
					
					
					if(weightlist[0][v.daePosIndex].m_fWeight!=0)
					{
						//cout<<weightlist[0][v.daePosIndex].m_fWeight;
						_VWeights.push_back(weightlist[0][v.daePosIndex].m_fWeight);
						_VJoints.push_back((Joint*)findNodeFromName((string)envlope->GetDeformer()->GetName()));
						//v.joints[0]
						stop
					}
					stop
				}

				if( _VWeights.size() > 4 )
				{
					for( unsigned int xx = 0; xx < _VWeights.size(); ++xx )
					{
						for( unsigned int yy = 0; yy < _VWeights.size(); ++yy )
						{
							if( _VWeights[xx] >_VWeights[yy] )
							{
								swap(_VWeights[xx] , _VWeights[yy] );
								swap(_VJoints[xx] , _VJoints[yy] );
							}
						}
					}
				}

				for (int i = 0; i < _VWeights.size() ; i++)
				{
					if( i == 4 ) break;
					v.weights[i]=_VWeights[i]/100.0;
					
					v.joints[i]=_VJoints[i];
					//v.joints[i]->daeInvBindMat *= oNode->matAbs.transposed();

				}
				//string namik=model->GetName();
				
				// Применяем скиннинг к вершинам
				
 				if( v.joints[0] != 0x0 || v.joints[1] != 0x0 || v.joints[2] != 0x0 || v.joints[3] != 0x0 )
 				{
 					Vec3f newPos( 0, 0, 0 );
  					if( v.joints[0] != 0x0 )
  						newPos += v.joints[0]->matAbs* v.joints[0]->daeInvBindMat * v.pos * v.weights[0];

 					Matrix4f TestMatrix =v.joints[0]->matAbs * v.joints[0]->daeInvBindMat;

  					if( v.joints[1] != 0x0 )
  						newPos += v.joints[1]->matAbs* v.joints[1]->daeInvBindMat * v.pos * v.weights[1];
  					if( v.joints[2] != 0x0 )
  						newPos += v.joints[2]->matAbs* v.joints[2]->daeInvBindMat * v.pos * v.weights[2];
  					if( v.joints[3] != 0x0 )
  						newPos += v.joints[3]->matAbs* v.joints[3]->daeInvBindMat * v.pos * v.weights[3];
					stop
 					v.pos = newPos;
					stop
 				}
			}
			_vertices.push_back( v );
			_indices.push_back( index );
			vertList.push_back( (unsigned int)_vertices.size() - 1 );
		}
	}
	oTriGroup.vertREnd = (unsigned int)_vertices.size() - 1;

	unsigned int numDegTris = MeshOptimizer::removeDegeneratedTriangles( oTriGroup, _vertices, _indices );

	if( optimize )
		MeshOptimizer::optimizeIndexOrder( oTriGroup, _vertices, _indices );


	oTriGroup.matName = in_left->GetMaterialName().GetText();
	CSLBaseMaterial* mat=in_left->GetMaterial();
	Material* mater=FindMaterialByName(oTriGroup.matName);
	if (mater==0x0)
	{
		Material* matNode = new Material();
		matNode->name = oTriGroup.matName;
		if (mat->Type()==CSLTemplate::XSI_MATERIAL)
		{
			CSLXSIMaterial* xsimat =(CSLXSIMaterial*)mat;

			int shadeCount= xsimat->GetShaderCount();
			CSLXSIShader** shadelist = xsimat->GetShaderList();
			for (int i = 0; i < shadeCount ; i++)
			{
				string ShaderName= shadelist[i]->GetName();
				if (ShaderName=="Phong")
				{
					CSLVariantParameter** varPar = shadelist[i]->GetParameterList();
					CSLShaderConnectionPoint** PointList=shadelist[i]->GetConnectionPointList();
					int ConPointCount = shadelist[i]->GetConnectionPointCount();
					for (int k=0;k<ConPointCount-1;k++)
					{
						string paramName=PointList[i]->GetName();
						if (paramName=="ambient" || paramName=="diffuse")
						{
							CSLXSIShader* textShader =PointList[i]->GetShader();
							CSLShaderConnectionPoint** PointListImage=textShader->GetConnectionPointList();
							if (PointListImage!=0x0)
							{
								string ImageName=PointListImage[0]->GetImage();
								Image* pImage=FindImageByName(ImageName);
								if(pImage!=0x0)
								{
									matNode->TexturePath = extractFileName(pImage->path,false);
								}
							}
							
						}
						
					}

					if(matNode->TexturePath == "")
					{
						for (int t=0;t<shadelist[i]->GetParameterCount();t++)
						{
							CSLVariantParameter* parametr = varPar[t];
							string name = parametr->GetName();
							if(name=="diffuse.red")
								matNode->r= parametr->GetValue()->fVal;
							if(name=="diffuse.green")
								matNode->g= parametr->GetValue()->fVal;
							if(name=="diffuse.blue")
								matNode->b= parametr->GetValue()->fVal;
						}
					}
				}
			}
		}
		_materials.push_back(matNode);
		stop
	}
	oNode->triGroups.push_back( oTriGroup );
		stop
}
Vec3f Convert::getPos( int posIndex ,CSLXSISubComponentAttributeList::CSLFloatArray* PosArray )
{
	Vec3f v;
	v.x=PosArray[0][posIndex*3+0];
	v.y=PosArray[0][posIndex*3+1];
	v.z=PosArray[0][posIndex*3+2];
	return v;
}
Vec3f Convert::getNormal( int normIndex,CSLXSISubComponentAttributeList::CSLFloatArray* NormArray )
{
	Vec3f v;
	v.x=NormArray[0][normIndex*3+0];
	v.y=NormArray[0][normIndex*3+1];
	v.z=NormArray[0][normIndex*3+2];
	return v;
}
Vec3f Convert::getTexCoords( int texIndex, unsigned int set, CSLXSISubComponentAttributeList::CSLFloatArray* UVArray )
{
	Vec3f v;
	if( set < 4 )
	{
			// Assume the float buffer has at least 2 values per element
			//v.x = source->floatArray[texIndex * source->elemsPerEntry + 0];
			//v.y = source->floatArray[texIndex * source->elemsPerEntry + 1];
			v.x=UVArray[0][texIndex*2+0];
			v.y=UVArray[0][texIndex*2+1];
	}
	return v;
}
SceneNode * Convert::findNodeFromName( string &name )
{
	if(_nodes.empty())return 0x0;
	for (unsigned int i=0 ; i<_nodes.size() ; i++)
	{
		if(_SI_STRCMP(_nodes[i]->name , name.c_str())==0)
		{
			return _nodes[i];
		}
	}
	return 0x0;
}
Mesh *Convert::findMeshFromName( string &name)
{
	if(_meshes.empty())return 0x0;
	for (unsigned int i=0 ; i<_meshes.size() ; i++)
	{
		if(_SI_STRCMP(_meshes[i]->name , name.c_str())==0)
		{
			return _meshes[i];
		}
	}
	return 0x0;
}

void Convert::calcTangentSpaceBasis( vector<Vertex> &verts )
{
	for( unsigned int i = 0; i < verts.size(); ++i )
	{
		verts[i].normal = Vec3f( 0, 0, 0 );
		verts[i].tangent = Vec3f( 0, 0, 0 );
		verts[i].bitangent = Vec3f( 0, 0, 0 );
	}
	// Algorithm: Eric Lengyel, Mathematics for 3D Game Programming & Computer Graphics
	for( unsigned int i = 0; i < _meshes.size(); ++i )
	{
		for( unsigned int j = 0; j < _meshes[i]->triGroups.size(); ++j )
		{
			TriGroup &triGroup = _meshes[i]->triGroups[j];

			for( unsigned int k = triGroup.first; k < triGroup.first + triGroup.count; k += 3 )
			{
				Vec3f &v0 = verts[_indices[k + 0]].pos;
				Vec3f &v1 = verts[_indices[k + 1]].pos;
				Vec3f &v2 = verts[_indices[k + 2]].pos;

				Vec3f &v0_str = verts[_indices[k + 0]].texCoords[0];
				Vec3f &v1_str = verts[_indices[k + 1]].texCoords[0];
				Vec3f &v2_str = verts[_indices[k + 2]].texCoords[0];

				Plane plane( v0, v1, v2 );
				Vec3f xyz0 = v1 - v0;
				Vec3f xyz1 = v2 - v0;
				Vec3f st0 = v1_str - v0_str;
				Vec3f st1 = v2_str - v0_str;

				float r = 0.0f;
				if( st0.x * st1.y - st1.x * st0.y != 0 )
					r = 1.0f / (st0.x * st1.y - st1.x * st0.y);
				Vec3f sdir( (st1.y * xyz0.x - st0.y * xyz1.x) * r,
					(st1.y * xyz0.y - st0.y * xyz1.y) * r, (st1.y * xyz0.z - st0.y * xyz1.z) * r );
				Vec3f tdir( (st0.x * xyz1.x - st1.x * xyz0.x) * r,
					(st0.x * xyz1.y - st1.x * xyz0.y) * r, (st0.x * xyz1.z - st1.x * xyz0.z) * r );

				verts[_indices[k + 0]].normal += plane.normal;
				verts[_indices[k + 1]].normal += plane.normal;
				verts[_indices[k + 2]].normal += plane.normal;
				verts[_indices[k + 0]].tangent += sdir;
				verts[_indices[k + 1]].tangent += sdir;
				verts[_indices[k + 2]].tangent += sdir;
				verts[_indices[k + 0]].bitangent += tdir;
				verts[_indices[k + 1]].bitangent += tdir;
				verts[_indices[k + 2]].bitangent += tdir;

				// Handle texture seams where vertices were split
				for( unsigned int l = 0; l < 3; ++l )
				{
					vector< unsigned int > &vertList =
						triGroup.posIndexToVertices[verts[_indices[k + l]].daePosIndex];

					for( unsigned int m = 0; m < vertList.size(); ++m )
					{
						if( _indices[k + l] == vertList[m] ) continue;

						if( verts[vertList[m]].storedNormal == verts[_indices[k + l]].storedNormal )
						{
							verts[vertList[m]].normal += plane.normal;
							verts[vertList[m]].tangent += sdir;
							verts[vertList[m]].bitangent += tdir;
						}
					}
				}
			}
		}
	}
	// Normalize tangent space basis
	for( unsigned int i = 0; i < verts.size(); ++i )
	{
		const Vec3f &n = verts[i].normal.normalized();
		const Vec3f &t = verts[i].tangent;
		verts[i].tangent = (t - n * (n * t)).normalized();
		verts[i].normal = n;

		if( n.crossProduct( t ) * verts[i].bitangent < 0.0f )
			verts[i].bitangent = (n * -1).crossProduct( t );
		else
			verts[i].bitangent = n.crossProduct( t );
	}
}

bool Convert::saveModel(  string &name )
{
	//переводим путь в string
// 	char* OutNameID=wtoc(name.c_str(), (wcslen(name.c_str())+1)*2);
// 	string OutNameSTR = OutNameID;
// 	delete[] OutNameID;

	writeGeometry(name);
	writeSceneGraph(name);
	return true;

}
bool Convert::writeGeometry( const string &name )
{
	_mkdir( (extractFilePath(name)+"\\"+"models").c_str() );
	FILE *f = fopen( (extractFilePath(name)+"\\"+"models/"+extractFileName(name,true) + ".cgm").c_str(), "wb" );

	// Write header
	unsigned int version = 1;
	fwrite( "CRM", 3, 1, f );
	fwrite( &version, sizeof( int ), 1, f );

	//Записываем кол=во костей

	unsigned int count = (unsigned int)_joints.size() + 1;
	fwrite( &count, sizeof( int ), 1, f );

	// Write default identity matrix
	for( unsigned int j = 0; j < 16; ++j )
		fwrite( &Matrix4f().x[j], sizeof( float ), 1, f );

	for( unsigned int i = 0; i < _joints.size(); ++i )
	{
 		// Inverse bind matrix
		Matrix4f tmp=_joints[i]->matAbs.inverted();
		for (unsigned int k = 0; k < 16; ++k)
		{
			_joints[i]->invBindMat.x[k]=tmp.x[k];
		}
 		for( unsigned int j = 0; j < 16; ++j )
 		{
 			fwrite( &_joints[i]->invBindMat.x[j], sizeof( float ), 1, f );
			if(i==8)
			{
				stop
			}
			stop
 		}
 	}

	// Write vertex stream data
	if( _joints.empty() ) count = 6; else count = 8;	// Number of streams
	fwrite( &count, sizeof( int ), 1, f );
	count = (unsigned int)_vertices.size();
	fwrite( &count, sizeof( int ), 1, f );

	for( unsigned int i = 0; i < 8; ++i )
	{
		if( _joints.empty() && (i == 4 || i == 5) ) continue;

		unsigned char uc;
		short sh;
		unsigned int streamElemSize;
		switch( i )
		{
		case 0:		// Position
			fwrite( &i, sizeof( int ), 1, f );
			streamElemSize = 3 * sizeof( float ); fwrite( &streamElemSize, sizeof( int ), 1, f );
			for( unsigned int j = 0; j < count; ++j )
			{
				//???????????????????  storedPos ->pos
				fwrite( &_vertices[j].pos.x, sizeof( float ), 1, f );
				fwrite( &_vertices[j].pos.y, sizeof( float ), 1, f );
				fwrite( &_vertices[j].pos.z, sizeof( float ), 1, f );
			}
			break;
			 		case 1:		// Normal
			 			fwrite( &i, sizeof( int ), 1, f );
			 			streamElemSize = 3 * sizeof( short ); fwrite( &streamElemSize, sizeof( int ), 1, f );
			 			for( unsigned int j = 0; j < count; ++j )
			 			{
			 				sh = (short)(_vertices[j].normal.x * 32767); fwrite( &sh, sizeof( short ), 1, f );
			 				sh = (short)(_vertices[j].normal.y * 32767); fwrite( &sh, sizeof( short ), 1, f );
			 				sh = (short)(_vertices[j].normal.z * 32767); fwrite( &sh, sizeof( short ), 1, f );
			 			}
			 			break;
			 		case 2:		// Tangent
			 			fwrite( &i, sizeof( int ), 1, f );
			 			streamElemSize = 3 * sizeof( short ); fwrite( &streamElemSize, sizeof( int ), 1, f );
			 			for( unsigned int j = 0; j < count; ++j )
			 			{
			 				sh = (short)(_vertices[j].tangent.x * 32767); fwrite( &sh, sizeof( short ), 1, f );
			 				sh = (short)(_vertices[j].tangent.y * 32767); fwrite( &sh, sizeof( short ), 1, f );
			 				sh = (short)(_vertices[j].tangent.z * 32767); fwrite( &sh, sizeof( short ), 1, f );
			 			}
			 			break;
			 		case 3:		// Bitangent
			 			fwrite( &i, sizeof( int ), 1, f );
			 			streamElemSize = 3 * sizeof( short ); fwrite( &streamElemSize, sizeof( int ), 1, f );
			 			for( unsigned int j = 0; j < count; ++j )
			 			{
			 				sh = (short)(_vertices[j].bitangent.x * 32767); fwrite( &sh, sizeof( short ), 1, f );
			 				sh = (short)(_vertices[j].bitangent.y * 32767); fwrite( &sh, sizeof( short ), 1, f );
			 				sh = (short)(_vertices[j].bitangent.z * 32767); fwrite( &sh, sizeof( short ), 1, f );
			 			}
			 			break;
			 		case 4:		// Joint indices
			 			fwrite( &i, sizeof( int ), 1, f );
			 			streamElemSize = 4 * sizeof( char ); fwrite( &streamElemSize, sizeof( int ), 1, f );
			 			for( unsigned int j = 0; j < count; ++j )
			 			{
			 				unsigned char jointIndices[4] = { 0, 0, 0, 0 };
			 				if( _vertices[j].joints[0] != 0x0 )
			 					jointIndices[0] = (unsigned char)_vertices[j].joints[0]->index;
			 				if( _vertices[j].joints[1] != 0x0 )
			 					jointIndices[1] = (unsigned char)_vertices[j].joints[1]->index;
			 				if( _vertices[j].joints[2] != 0x0 )
			 					jointIndices[2] = (unsigned char)_vertices[j].joints[2]->index;
			 				if( _vertices[j].joints[3] != 0x0 )
			 					jointIndices[3] = (unsigned char)_vertices[j].joints[3]->index;
			 				fwrite( &jointIndices[0], sizeof( char ), 1, f );
			 				fwrite( &jointIndices[1], sizeof( char ), 1, f );
			 				fwrite( &jointIndices[2], sizeof( char ), 1, f );
			 				fwrite( &jointIndices[3], sizeof( char ), 1, f );
			 			}
			 			break;
			 		case 5:		// Weights
			 			fwrite( &i, sizeof( int ), 1, f );
			 			streamElemSize = 4 * sizeof( char ); fwrite( &streamElemSize, sizeof( int ), 1, f );
			 			for( unsigned int j = 0; j < count; ++j )
			 			{
			 				uc = (unsigned char)(_vertices[j].weights[0] * 255); fwrite( &uc, sizeof( char ), 1, f );
			 				uc = (unsigned char)(_vertices[j].weights[1] * 255); fwrite( &uc, sizeof( char ), 1, f );
			 				uc = (unsigned char)(_vertices[j].weights[2] * 255); fwrite( &uc, sizeof( char ), 1, f );
			 				uc = (unsigned char)(_vertices[j].weights[3] * 255); fwrite( &uc, sizeof( char ), 1, f );
			 			}
			 			break;
			 		case 6:		// Texture Coord Set 1
			 			fwrite( &i, sizeof( int ), 1, f );
			 			streamElemSize = 2 * sizeof( float ); fwrite( &streamElemSize, sizeof( int ), 1, f );
			 			for( unsigned int j = 0; j < count; ++j )
			 			{
			 				fwrite( &_vertices[j].texCoords[0].x, sizeof( float ), 1, f );
			 				fwrite( &_vertices[j].texCoords[0].y, sizeof( float ), 1, f );
			 			}
			 			break;
			 		case 7:		// Texture Coord Set 2
			 			fwrite( &i, sizeof( int ), 1, f );
			 			streamElemSize = 2 * sizeof( float ); fwrite( &streamElemSize, sizeof( int ), 1, f );
			 			for( unsigned int j = 0; j < count; ++j )
			 			{
			 				fwrite( &_vertices[j].texCoords[0].x, sizeof( float ), 1, f );
			 				fwrite( &_vertices[j].texCoords[0].y, sizeof( float ), 1, f );
			 			}
						break;
		}
	}
	count = (unsigned int)_indices.size();
	fwrite( &count, sizeof( int ), 1, f );

	for( unsigned int i = 0; i < _indices.size(); ++i )
	{
		fwrite( &_indices[i], sizeof( int ), 1, f );
	}
	// Write morph targets
	count = (unsigned int)_morphTargets.size();
	fwrite( &count, sizeof( int ), 1, f );

	for( unsigned int i = 0; i < _morphTargets.size(); ++i )
	{
		fwrite( &_morphTargets[i].name, 256, 1, f );

		// Write vertex indices
		count = (unsigned int)_morphTargets[i].diffs.size();
		fwrite( &count, sizeof( int ), 1, f );

		for( unsigned int j = 0; j < count; ++j )
		{
			fwrite( &_morphTargets[i].diffs[j].vertIndex, sizeof( int ), 1, f );
		}

		// Write stream data
		unsigned int numStreams = 4, streamElemSize;
		fwrite( &numStreams, sizeof( int ), 1, f );

		for( unsigned int j = 0; j < 4; ++j )
		{
			switch( j )
			{
			case 0:		// Position
				fwrite( &j, sizeof( int ), 1, f );
				streamElemSize = 3 * sizeof( float ); fwrite( &streamElemSize, sizeof( int ), 1, f );
				for( unsigned int k = 0; k < count; ++k )
				{
					fwrite( &_morphTargets[i].diffs[k].posDiff.x, sizeof( float ), 1, f );
					fwrite( &_morphTargets[i].diffs[k].posDiff.y, sizeof( float ), 1, f );
					fwrite( &_morphTargets[i].diffs[k].posDiff.z, sizeof( float ), 1, f );
				}
				break;
			case 1:		// Normal
				fwrite( &j, sizeof( int ), 1, f );
				streamElemSize = 3 * sizeof( float ); fwrite( &streamElemSize, sizeof( int ), 1, f );
				for( unsigned int k = 0; k < count; ++k )
				{
					fwrite( &_morphTargets[i].diffs[k].normDiff.x, sizeof( float ), 1, f );
					fwrite( &_morphTargets[i].diffs[k].normDiff.y, sizeof( float ), 1, f );
					fwrite( &_morphTargets[i].diffs[k].normDiff.z, sizeof( float ), 1, f );
				}
				break;
			case 2:		// Tangent
				fwrite( &j, sizeof( int ), 1, f );
				streamElemSize = 3 * sizeof( float ); fwrite( &streamElemSize, sizeof( int ), 1, f );
				for( unsigned int k = 0; k < count; ++k )
				{
					fwrite( &_morphTargets[i].diffs[k].tanDiff.x, sizeof( float ), 1, f );
					fwrite( &_morphTargets[i].diffs[k].tanDiff.y, sizeof( float ), 1, f );
					fwrite( &_morphTargets[i].diffs[k].tanDiff.z, sizeof( float ), 1, f );
				}
				break;
			case 3:		// Bitangent
				fwrite( &j, sizeof( int ), 1, f );
				streamElemSize = 3 * sizeof( float ); fwrite( &streamElemSize, sizeof( int ), 1, f );
				for( unsigned int k = 0; k < count; ++k )
				{
					fwrite( &_morphTargets[i].diffs[k].bitanDiff.x, sizeof( float ), 1, f );
					fwrite( &_morphTargets[i].diffs[k].bitanDiff.y, sizeof( float ), 1, f );
					fwrite( &_morphTargets[i].diffs[k].bitanDiff.z, sizeof( float ), 1, f );
				}
				break;
			}
		}
	}





	fclose( f );
	return true;
}
bool Convert::writeSceneGraph(  string &name )
{
	
	stop
	ofstream outf;

	//_mkdir( (extractFilePath(name)+"\\"+"models").c_str() );
	//FILE *f = fopen( (extractFilePath(name)+"\\"+"models/"+extractFileName(name,true) + ".cgm").c_str(), "wb" );

	outf.open( (extractFilePath(name)+"\\"+"models/"+extractFileName(name,true) + ".scene.scn").c_str(), ios::out );

	outf << "<Model name=\"" << extractFileName(name,true) << "\" geometry=\"" << extractFileName(name,true) << ".cgm\">\n";

	// Output morph target names as comment
	if( !_morphTargets.empty() )
	{
		outf << "\t<!-- Morph targets: ";
		for( unsigned int i = 0; i < _morphTargets.size(); ++i )
		{
			outf << "\"" << _morphTargets[i].name << "\" ";
		}
		outf << "-->\n\n";
	}

	// Joints
	for( unsigned int i = 0; i < _joints.size(); ++i )
	{
		if( _joints[i]->parent == 0x0 ) writeSGNode( extractFileName(name,true) , _joints[i], 0, outf );
	}

	outf << "\n";

	// Meshes
	for( unsigned int i = 0; i < _meshes.size(); ++i )
	{
		if( _meshes[i]->parent == 0x0 ) writeSGNode( extractFileName(name,true) , _meshes[i], 0, outf );
	}

	outf << "</Model>\n";

	outf.close();

	return true;
}
void Convert::writeSGNode( const string &modelName, SceneNode *node, unsigned int depth, ofstream &outf )
{	
	Vec3f trans, rot, scale;
	node->matRel.decompose( trans, rot, scale );
	rot.x = radToDeg( rot.x );
	rot.y = radToDeg( rot.y );
	rot.z = radToDeg( rot.z );

	// Write mesh
	if( !node->typeJoint )
	{
		Mesh *mesh =findMeshFromName(string(node->name)); //(Mesh *)node;
		
		
		// Write triangle groups as submeshes of first triangle group
		for( unsigned int i = 0; i < mesh->triGroups.size(); ++i )
		{
			for( unsigned int j = 0; j < depth + 1; ++j ) outf << "\t";
			if( i > 0 ) outf << "\t";
			outf << "<Mesh ";
			outf << "name=\"" << mesh->name << "\" ";
			outf << "material=\"";
			outf << modelName + "/" + mesh->triGroups[i].matName + ".material.xml\" ";

			if( i == 0 )
			{
				if( trans != Vec3f( 0, 0, 0 ) )
					outf << "tx=\"" << trans.x << "\" ty=\"" << trans.y << "\" tz=\"" << trans.z << "\" ";
				if( rot != Vec3f( 0, 0, 0 ) )
					outf << "rx=\"" << rot.x << "\" ry=\"" << rot.y << "\" rz=\"" << rot.z << "\" ";
				if( scale != Vec3f( 1, 1, 1 ) )
					outf << "sx=\"" << scale.x << "\" sy=\"" << scale.y << "\" sz=\"" << scale.z << "\" ";
			}

			outf << "batchStart=\"";
			outf << mesh->triGroups[i].first;
			outf << "\" batchCount=\"";
			outf << mesh->triGroups[i].count;
			outf << "\" vertRStart=\"";
			outf << mesh->triGroups[i].vertRStart;
			outf << "\" vertREnd=\"";
			outf << mesh->triGroups[i].vertREnd;
			outf << "\"";

			if( i == 0 && mesh->triGroups.size() > 1 ) outf << ">\n";
			if( i > 0 ) outf << " />\n";
		}
		
	}
	else
	{
		Joint *joint = (Joint *)node;

		for( unsigned int i = 0; i < depth + 1; ++i ) outf << "\t";
		outf << "<Joint ";
		outf << "name=\"" << joint->name << "\" ";
		if( trans != Vec3f( 0, 0, 0 ) )
			outf << "tx=\"" << trans.x << "\" ty=\"" << trans.y << "\" tz=\"" << trans.z << "\" ";
		if( rot != Vec3f( 0, 0, 0 ) )
			outf << "rx=\"" << rot.x << "\" ry=\"" << rot.y << "\" rz=\"" << rot.z << "\" ";
		if( scale != Vec3f( 1, 1, 1 ) )
			outf << "sx=\"" << scale.x << "\" sy=\"" << scale.y << "\" sz=\"" << scale.z << "\" ";
		outf << "jointIndex=\"" << joint->index << "\"";
	}

	if( node->children.size() == 0 )
	{
		Mesh *mesh =findMeshFromName(string(node->name));
		if( !node->typeJoint && mesh->triGroups.size() > 1 )
		{
			for( unsigned int j = 0; j < depth + 1; ++j ) outf << "\t";
			outf << "</Mesh>\n";
		}
		else
		{
			outf << " />\n";
		}
	}
	else
	{
		outf << ">\n";
		for( unsigned int j = 0; j < node->children.size(); ++j )
			writeSGNode( modelName, node->children[j], depth + 1, outf );

		// Closing tag
		for( unsigned int j = 0; j < depth + 1; ++j ) outf << "\t";
		if( !node->typeJoint ) outf << "</Mesh>\n";
		else outf << "</Joint>\n";	
	}
}

Matrix4f Convert::FromSCIMatrix4x4toMatrix4f( CSIBCMatrix4x4 &transMatrixLocal )
{
	CSIBCVector3D scale;
	CSIBCVector3D rotate;
	CSIBCVector3D trans;



	transMatrixLocal.GetTransforms(scale,rotate,trans);
	//scale.Normalize();
	//rotate.Normalize();
	//trans.Normalize();



 	double torX=radToDeg(rotate.GetX());
 	double torY=radToDeg(rotate.GetY());
 	double torZ=radToDeg(rotate.GetZ());

	Matrix4f TranslateMat;
	Matrix4f RotateMat;
	Matrix4f ScaleMat;
	Matrix4f ClearMatrix;

	TranslateMat.translate(trans.GetX(),trans.GetY(),trans.GetZ());
	//RotateMat.rotate( rotate.GetX(), rotate.GetY(),rotate.GetX() );
	RotateMat.SetRotation(degToRad(torX),degToRad(torY),degToRad(torZ));
	//RotateMat.rotate(degToRad(torX),degToRad(torY),degToRad(torZ));

	ScaleMat.scale(scale.GetX(),scale.GetY(),scale.GetZ());


	ClearMatrix = TranslateMat*RotateMat*ScaleMat;
	//float det=ClearMatrix.determinant();
	//ClearMatrix = ClearMatrix * 1*det;


	return ClearMatrix;
}

Matrix4f Convert::makeMatrix4f( float *floatArray16, bool y_up )
{
	Matrix4f mat( floatArray16 );
	//mat = mat.transposed();

	// Flip matrix if necessary
	if( !y_up )
	{
		// Swap y/z rows
		swap( mat.c[0][1], mat.c[0][2] );
		swap( mat.c[1][1], mat.c[1][2] );
		swap( mat.c[2][1], mat.c[2][2] );
		swap( mat.c[3][1], mat.c[3][2] );

		// Swap y/z columns
		swap( mat.c[1][0], mat.c[2][0] );
		swap( mat.c[1][1], mat.c[2][1] );
		swap( mat.c[1][2], mat.c[2][2] );
		swap( mat.c[1][3], mat.c[2][3] );

		// Invert z-axis to make system right-handed again
		// (The swapping above results in a left-handed system)
		mat.c[0][2] *= -1;
		mat.c[1][2] *= -1;
		mat.c[3][2] *= -1;
		mat.c[2][0] *= -1;
		mat.c[2][1] *= -1;
		mat.c[2][3] *= -1;
	}

	return mat;
}

bool Convert::IsJoint( string & Name )
{
	for (int i=0;i<_jointInstances.size();i++)
	{
		if (_SI_STRCMP(Name.c_str(),_jointInstances[i]->name)==0)
			return true;
	}
	return false;
}

bool Convert::hasAnimation()
{
	return _frameCount > 0;
}

bool Convert::writeAnimation( const string &name )
{
	/*char* OutNameID=wtoc(name.c_str(), (wcslen(name.c_str())+1)*2);
	string OutNameSTR = OutNameID;
	delete[] OutNameID;*/
	string OutNameSTR = name;

	
	//FILE *f = fopen( (extractFilePath(name)+"\\"+"models/"+extractFileName(name,true) + ".cgm").c_str(), "wb" );
	FILE *f = fopen( (extractFilePath(name)+"\\"+"models/"+extractFileName(name,true) + ".cam").c_str(), "wb" );

	// Write header
	unsigned int version = 1;
	fwrite( "CRM", 3, 1, f );
	fwrite( &version, sizeof( int ), 1, f ); 

	// Write number of nodes
	unsigned int count = 0;
	for( unsigned int i = 0; i < _joints.size(); ++i )
		if( _joints[i]->frames.size() > 0 ) ++count;
	for( unsigned int i = 0; i < _meshes.size(); ++i )
		if( _meshes[i]->frames.size() > 0 ) ++count;
	fwrite( &count, sizeof( int ), 1, f );
	fwrite( &FFrameCount, sizeof( int ), 1, f );

	for( unsigned int i = 0; i < _joints.size(); ++i )
	{
		if( _joints[i]->frames.size() == 0 ) continue;

		writeAnimFrames( *_joints[i], f );
	}

	for( unsigned int i = 0; i < _meshes.size(); ++i )
	{
		if( _meshes[i]->frames.size() == 0 ) continue;

		writeAnimFrames( *_meshes[i], f );
	}

	fclose( f );
	return true;
}

void Convert::writeAnimFrames( SceneNode &node, FILE *f )
{
	fwrite( &node.name, 256, 1, f );

	for( unsigned int i = 0; i < node.frames.size(); ++i )
	{
		Vec3f transVec, rotVec, scaleVec;
		node.frames[i].decompose( transVec, rotVec, scaleVec );
		Quaternion rotQuat( rotVec.x, rotVec.y, rotVec.z );

		fwrite( &rotQuat.x, sizeof( float ), 1, f );
		fwrite( &rotQuat.y, sizeof( float ), 1, f );
		fwrite( &rotQuat.z, sizeof( float ), 1, f );
		fwrite( &rotQuat.w, sizeof( float ), 1, f );
		fwrite( &transVec.x, sizeof( float ), 1, f );
		fwrite( &transVec.y, sizeof( float ), 1, f );
		fwrite( &transVec.z, sizeof( float ), 1, f );
		fwrite( &scaleVec.x, sizeof( float ), 1, f );
		fwrite( &scaleVec.y, sizeof( float ), 1, f );
		fwrite( &scaleVec.z, sizeof( float ), 1, f );
	}
}

Image* Convert::FindImageByName( string &name )
{
	for (int i=0;i<_images.size();i++)
	{
		if (_images[i]->name==name)
			return _images[i];
	}
	return 0x0;
}

Material* Convert::FindMaterialByName( string &name )
{
	for (int i=0;i<_materials.size();i++)
	{
		if (_materials[i]->name==name)
			return _materials[i];
	}
	return 0x0;
}

bool Convert::writeMaterials(  string &name,  string &defShader )
{
	/*char* OutNameID=wtoc(name.c_str(), (wcslen(name.c_str())+1)*2);
	string OutNameSTR = OutNameID;
	delete[] OutNameID;

	char* OutNameshadeID=wtoc(defShader.c_str(), (wcslen(defShader.c_str())+1)*2);
	string OutNameShaderSTR = OutNameshadeID;
	delete[] OutNameshadeID;*/
	string OutNameSTR = name;
	string OutNameShaderSTR = defShader;
	

	_mkdir( (extractFilePath(OutNameSTR)+"\\"+"materials").c_str() );
	_mkdir( (extractFilePath(OutNameSTR)+"\\"+"materials/" + extractFileName(OutNameSTR,true) ).c_str() );

	for( unsigned int i = 0; i < _materials.size(); ++i )
	{

		ofstream outf;
		string fileName = extractFilePath(OutNameSTR)+"\\"+"materials/" + extractFileName(OutNameSTR,true) + "/" + _materials[i]->name + ".material.xml";
		outf.open( fileName.c_str(), ios::out );

		

		if( _materials[i]->TexturePath != "" )
		{
			outf << "<Material>\n";
			outf << "\t<Shader source=\"" + OutNameShaderSTR + "\" />\n\n";
			outf << "\t<TexUnit unit=\"0\" map=\"";
			outf << _materials[i]->TexturePath+".jpg";
			outf << "\" />\n";
		}else
		{
			outf << "<Material>\n";
			outf << "\t<Shader source=\"" + string("geo.shader.xml") + "\" />\n\n";
			outf << "\t<Uniform name=\"mBlinn\" a=\"" <<_materials[i]->r<< "\" ";
			outf << "b=\"" <<_materials[i]->g<< "\" ";
			outf << "c=\"" <<_materials[i]->b<< "\" ";
			outf << "d=\"0\"";
			outf << "/>\n\n";
		}

		outf << "</Material>\n";

		outf.close();
	}

	return true;
}
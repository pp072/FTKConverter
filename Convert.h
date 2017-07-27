#pragma once
#include "CMathE.h"
//#include <fstream>
//#include <sstream>
//#include <direct.h>
//#include <iostream>
#include "SemanticLayer.h"
#include <vector>
using namespace std;
#define stop __asm nop

struct Joint;
struct Vertex
{
	Vec3f			storedPos, pos;
	Vec3f			storedNormal, normal, tangent, bitangent;
	Vec3f			texCoords[4];
	Joint			*joints[4];
	float			weights[4];	
	int				daePosIndex;


	Vertex()
	{
		joints[0] = 0x0; joints[1] = 0x0; joints[2] = 0x0; joints[3] = 0x0;
		weights[0] = 1; weights[1] = 0; weights[2] = 0; weights[3] = 0;
		tangent, bitangent;
	}
};

struct TriGroup
{
	unsigned int	first, count;
	unsigned int	vertRStart, vertREnd;
	string			matName;

	unsigned int			numPosIndices;
	vector< unsigned int >	*posIndexToVertices;


	TriGroup() : posIndexToVertices( 0x0 )
	{
	}
};

struct SceneNode
{
	bool					typeJoint;

	char					name[256];
	Matrix4f				matRel, matAbs;
	//	ColladaNode				*daeNode;
	//	ColladaInstance			*daeInstance;
	SceneNode				*parent;
	vector< SceneNode * >	children;

	// Animation
	vector< Matrix4f >		frames;			// Relative transformation for every frame
	Matrix4f				daeInvBindMat;
	SceneNode()
	{
		//daeNode = 0x0;
		//daeInstance = 0x0;
		typeJoint = false;
		parent = 0x0;
	}

};
struct Mesh : public SceneNode
{
	vector< TriGroup >		triGroups;

	Mesh()
	{
		typeJoint = false;
		parent = 0x0;
	}
};

struct Joint : public SceneNode
{
	unsigned int			index;
	Matrix4f				invBindMat;
	bool					used;

	// Temporary

	Joint()
	{
		typeJoint = true;
		used = false;
	}
};

struct MorphDiff
{
	unsigned int			vertIndex;
	Vec3f					posDiff;
	Vec3f					normDiff, tanDiff, bitanDiff;
};

struct MorphTarget
{
	char					name[256];
	vector< MorphDiff >		diffs;
};
struct	JointInstance
{
	char					name[256];
	CSIBCMatrix4x4 			BaseModelPose;
};
struct Material
{
	string name;
	//bool used;
	string TexturePath;
	float r;
	float g;
	float b;
	
 	Material()
 	{
 		r=0;
		g=0;
		b=0;
 	}	
};
struct Image
{
	string name;
	string path;
};
class Convert
{

public:
	vector<JointInstance*>  _jointInstances;
	vector< string >		_JointNames;
	vector< Vertex >		_vertices;
	vector< unsigned int >	_indices;
	vector< Mesh * >		_meshes;
	vector< Joint * >		_joints;
	vector< SceneNode * >	_nodes;
	vector< MorphTarget >	_morphTargets;
	vector<	Material * >	_materials;
	vector< Image* >		_images;
	float					_frameCount;

	bool					optimize;

	float					_start;
	float					_end;
	float					_framerate;
	int						FFrameCount;



public:
	Convert(void);
	~Convert(void);
	bool parse( string &fileName);
	void ProcessJoint( CSLModel* in_child,  CSLModel* mesh );
	void Recurse( CSLModel* in_child );
	void ProcessMesh(CSLModel* in_child);
	int Strip( CSLModel* in_left);
	Matrix4f FromSCIMatrix4x4toMatrix4f( CSIBCMatrix4x4 &transMatrixLocal );
	int StripMesh( CSLXSIMesh* in_left);
	int StripTriangleList( CSLXSITriangleList* in_left, CSLXSIMesh* in_mesh,Mesh *oNode );
	bool saveModel(  string &name );
	bool writeGeometry( const string &name );
	SceneNode *findNodeFromName( string &name);
	Mesh *findMeshFromName( string &name);
	void calcTangentSpaceBasis( vector<Vertex> &verts );
	bool writeSceneGraph(  string &name );
	void writeSGNode( const string &modelName, SceneNode *node, unsigned int depth, ofstream &outf );
	Vec3f getPos( int posIndex ,CSLXSISubComponentAttributeList::CSLFloatArray* PosArray);
	Vec3f getNormal( int normIndex,CSLXSISubComponentAttributeList::CSLFloatArray* NormArray );
	Vec3f getTexCoords( int texIndex, unsigned int set, CSLXSISubComponentAttributeList::CSLFloatArray* UVArray );
	bool IsJoint(string & Name);
	CSIBCMatrix4x4 GetMeshBasePose(string & Name);
	Matrix4f makeMatrix4f( float *floatArray16, bool y_up );
	bool hasAnimation();
	bool writeAnimation( const string &name );
	void writeAnimFrames( SceneNode &node, FILE *f );
	void LoadMaterials(CSLImageLibrary* matlib);
	Image* FindImageByName(string &name);
	Material* FindMaterialByName(string &name);
	bool writeMaterials(  string &name,  string &defShader );
	


};

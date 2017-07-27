#pragma once
#include <vector>
#include <set>

using namespace std;

struct TriGroup;
struct Vertex;
struct OptFace;

struct OptVertex
{
	unsigned int		index;		// Index in vertex array
	float				score;
	set< OptFace * >	faces;		// Faces that are using this vertex

	void updateScore( int cacheIndex );
};

struct OptFace
{
	OptVertex	*verts[3];

	float getScore()  { return verts[0]->score + verts[1]->score + verts[2]->score; }
};




class MeshOptimizer
{
public:

	static const int OptCacheSize = 32;

	static unsigned int removeDegeneratedTriangles( TriGroup &triGroup, vector< Vertex > &vertices,
		vector< unsigned int > &indices );
	static void optimizeIndexOrderNV( TriGroup &triGroup, vector< Vertex > &vertices,
		vector< unsigned int > &indices );
	static void optimizeIndexOrder( TriGroup &triGroup, vector< Vertex > &vertices,
		vector< unsigned int > &indices );
};

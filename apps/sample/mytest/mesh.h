#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <vcg/complex/complex.h>

class MyFace;
class MyVertex;

struct MyUsedTypes : public vcg::UsedTypes<	vcg::Use<MyVertex>   ::AsVertexType,
										   vcg::Use<MyFace>     ::AsFaceType>{};

class MyVertex  :
	public vcg::Vertex<
		MyUsedTypes,
		vcg::vertex::Coord3d,
		vcg::vertex::Normal3d,
		vcg::vertex::VFAdj,
		vcg::vertex::Qualityd,
		vcg::vertex::CurvatureDird,
		vcg::vertex::BitFlags  >
{};

class MyFace :
	public vcg::Face<
		MyUsedTypes,
		vcg::face::FFAdj,
		vcg::face::VFAdj,
		vcg::face::Normal3d,
		vcg::face::VertexRef,
		vcg::face::BitFlags >
{};

class MyMesh :
	public vcg::tri::TriMesh< std::vector<MyVertex>, std::vector<MyFace> >
{};

#endif // HEADERFILE_H

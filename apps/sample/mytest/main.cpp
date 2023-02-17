/****************************************************************************
* VCGLib                                                            o o     *
* Visual and Computer Graphics Library                            o     o   *
*                                                                _   O  _   *
* Copyright(C) 2004-2016                                           \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
/*! \file trimesh_curvature.cpp
\ingroup code_sample

\brief an example showing various techniques for computing curvatures

*/

#include "mesh.h"

#include<wrap/io_trimesh/import_ply.h>
#include<wrap/io_trimesh/import_obj.h>
#include<wrap/io_trimesh/export_ply.h>

#include <vcg/complex/algorithms/intersection.h>

int main( int /*argc*/, char **/*argv*/ )
{
	MyMesh m, res;

	int mask;
	vcg::tri::io::ImporterOBJ<MyMesh>::Open(m, "/home/alessandro/Drive/Research/3DMeshes/bimba.obj", mask);

	vcg::Sphere3<double> s(vcg::Point3d(0,0,0), 0.3);
	vcg::IntersectionBallMesh(m, s, res);

	vcg::tri::io::ExporterPLY<MyMesh>::Save(res, "/home/alessandro/tmp/inters.ply");

	return 0;
}

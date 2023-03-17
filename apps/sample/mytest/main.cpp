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
#include "timer.h"

#include<wrap/io_trimesh/import_ply.h>
#include<wrap/io_trimesh/import_obj.h>
#include<wrap/io_trimesh/export_ply.h>

#include <vcg/simplex/face/distance.h>



int main( int /*argc*/, char **/*argv*/ )
{
	MyMesh m;

	int mask;
	vcg::tri::io::ImporterOBJ<MyMesh>::Open(m, "/home/alessandro/Drive/Research/3DMeshes/cube.obj", mask);

	vcg::Point3d p(2, 1, 0);

	vcg::Point3d c;

	for (uint f = 0; f < m.face.size(); ++f) {
		double dist = std::numeric_limits<double>::max();
		vcg::face::PointDistanceBase(m.face[f], p, dist, c);

		std::cerr << "Face " << f << ": \n";
		std::cerr << "\tdist: " << dist<< ";\n";
		std::cerr << "\tclos: [" << c.X() << "; " << c.Y() << "; " << c.Z() << "]\n";
	}

	return 0;
}

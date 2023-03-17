#ifndef CURV_H
#define CURV_H

#include "mesh.h"
#include "timer.h"

#include<wrap/io_trimesh/import_ply.h>
#include<wrap/io_trimesh/import_obj.h>
#include<wrap/io_trimesh/export_ply.h>

#include <vcg/complex/algorithms/intersection.h>
#include <vcg/complex/algorithms/update/bounding.h>
#include <vcg/complex/algorithms/update/curvature.h>
#include <vcg/complex/algorithms/update/quality.h>
#include <vcg/complex/algorithms/update/color.h>

void curv() {

	MyMesh m, res;

	int mask;
	vcg::tri::io::ImporterOBJ<MyMesh>::Open(m, "/home/alessandro/Drive/Research/3DMeshes/bimba.obj", mask);

	//	vcg::Sphere3<double> s(vcg::Point3d(0,0,0), 0.3);
	//	vcg::IntersectionBallMesh(m, s, res);

	vcg::tri::UpdateBounding<MyMesh>::Box(m);
	double r = m.bbox.Diag() * 0.1;

	timer t;
	t.start();
	vcg::tri::UpdateCurvature<MyMesh>::PrincipalDirectionsPCA(m, r, false);
	t.stop();

	std::cerr << t.delay() << "\n";

	vcg::tri::UpdateQuality<MyMesh>::VertexMeanFromCurvatureDir(m);

	vcg::Histogram<double> h;
	vcg::tri::Stat<MyMesh>::ComputePerVertexQualityHistogram(m, h);

	vcg::tri::UpdateColor<MyMesh>::PerVertexQualityRamp(m, h.Percentile(0.1), h.Percentile(0.9));

	mask = 0;
	mask |= vcg::tri::io::Mask::IOM_VERTCOLOR;

	vcg::tri::io::ExporterPLY<MyMesh>::Save(m, "/home/alessandro/tmp/bimba_curv.ply", mask);


	std::cout << "Curvature range: " << h.MinV() << " " << h.MaxV() << "\n";
	std::cout << "Used 90 percentile: " << h.Percentile(0.1) << " " << h.Percentile(0.9) << "\n";

}

#endif // CURV_H

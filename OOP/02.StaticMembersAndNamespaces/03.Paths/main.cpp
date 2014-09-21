#include <iostream>
#include "Point3D.h"
#include "Path3D.h"
#include "Storage.h"

int main()
{
	Point3D p1(1, 1, 1);
	Point3D p2(2, 2, 2);
	Point3D p3(3, 3, 3);
	Point3D p4(4, 4, 4);
	Point3D p5(5, 5, 5);

	Path3D path;
	path.AddPoint(p1);
	path.AddPoint(p2);
	path.AddPoint(p3);
	path.AddPoint(p4);
	path.AddPoint(p5);

	Storage::Save(path);

	Path3D loadedPath;
	Storage::Load(loadedPath);

	system("pause");
	return 0;
}
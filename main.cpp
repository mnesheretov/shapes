#include"tobj.h"
#include"point.h"
#include"vector.h"
#include"complex.h"
#include "line.h"
#include"square.h"
#include"circle.h"
#include"triangle.h"
#include"setOfFigures.h"
#include"tetrahedron.h"

int main() {
	TSet<int> set;
	TTetrahedron<int> tt;
	TCircle<int> circle(10);
	
	set.SetObj(&tt);
	set.SetObj(&circle);
	

	return 0;
}
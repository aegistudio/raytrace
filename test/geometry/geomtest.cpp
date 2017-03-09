#include "geomtest.h"
#include "common.h"
#include "../testing.h"

void expectIntersect(Geometry& g, Vector d, Vector c, Vector uv, Vector n, Vector j) {
	Maybe<Vector> i = g.intersect(d, c);
	ASSERT_FALSE(!i);

	// Validate some value.
	ASSERT_TRUE(expect(uv, *i));
	ASSERT_TRUE(expect(n, g.normal(*i)));
	ASSERT_TRUE(expect(j, g.joint(*i)));
}

void expectDisjoint(Geometry& g, Vector d, Vector c) {
	ASSERT_TRUE(!(g.intersect(d, c)));
}

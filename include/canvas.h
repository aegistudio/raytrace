#include "geometry/vector.h"

/**
 * This class defines a writable canvas that could
 * either be a screen device or an output image 
 * file. It depends on the actual implementation
 * of the canvas.
 *
 * You should provide implementation or adapt current
 * implementations of canvas synonyms.
 */

class Canvas {
public:
	virtual void set(int, int, const Vector&) = 0;
};

#include "sdlcanvas.h"

void SdlCanvas::set(int x, int y, const Vector& c) {
	SDL(Rect) pixel = {x, y, 1, 1};
	SDL(FillRect)(m_surface, &pixel, 
		SDL(MapRGB)(m_surface -> format, c.x, c.y, c.z));
}

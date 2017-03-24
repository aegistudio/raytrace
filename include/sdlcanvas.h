#include "canvas.h"
#include <SDL2/SDL.h>

#define SDL(ID) SDL_##ID

class SdlCanvas {
	SDL(Surface)* m_surface;
public:
	SdlCanvas(SDL(Surface)* p_surface)
		: m_surface(p_surface) {}

	virtual ~SdlCanvas() {}

	virtual void set(int x, int y, const Vector& c);
};

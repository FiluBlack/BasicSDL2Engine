#include "pch.h"
#include "Geometry.h"

#include <iostream>

int Geometry::drawRectSurface(SDL_Renderer* renderer, int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Surface* s = SDL_CreateRGBSurface(0, 1, 1, 32, 0, 0, 0, 0);
	if (SDL_FillRect(s, NULL, SDL_MapRGBA(s->format, r, g, b, a)) < 0) return -1;
	
	SDL_Texture* t = SDL_CreateTextureFromSurface(renderer, s);
	SDL_FreeSurface(s);

	SDL_Rect desr;
	desr.x = x;
	desr.y = y;
	desr.w = w;
	desr.h = h;

	if (SDL_RenderCopy(renderer, t, NULL, &desr) < 0) return -1;
	SDL_DestroyTexture(t);
	return 0;
}

int Geometry::drawRectRenderer(SDL_Renderer* renderer, int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	Uint8 tr, tg, tb, ta;
	SDL_GetRenderDrawColor(renderer, &tr, &tg, &tb, &ta);
	std::cout << (Uint32)tr << std::endl;
	SDL_SetRenderDrawColor(renderer, r, g, b, a);


	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tr, tg, tb, ta);
	return 0;
}

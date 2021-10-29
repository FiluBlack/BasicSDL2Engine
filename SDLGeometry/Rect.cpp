#include "pch.h"
#include "Rect.h"

Rect::Rect()
	: position(Position2D<int>()), size(Size2D<unsigned int>()), border(0), color(Color())
{
}

Rect::Rect(Position2D<int> position)
	: position(position), size(Size2D<unsigned int>()), border(0), color(Color())
{
}

Rect::Rect(Position2D<int> position, Size2D<unsigned int> size)
	: position(position), size(size), border(0), color(Color())
{
}

Rect::Rect(Position2D<int> position, Size2D<unsigned int> size, Color color)
	: position(position), size(size), border(0), color(color)
{
}

Rect::Rect(Position2D<int> position, Size2D<unsigned int> size, unsigned int border)
	: position(position), size(size), border(border), color(Color())
{
}

Rect::Rect(Position2D<int> position, Size2D<unsigned int> size, unsigned int border, Color color)
	: position(position), size(size), border(border), color(color)
{
}

Rect::~Rect()
{
}

void Rect::setPosition(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
}

void Rect::setPosition(Position2D<int> position)
{
	this->position = position;
}

void Rect::setSize(unsigned int w, unsigned int h)
{
	this->size.w = w;
	this->size.w = h;
}

void Rect::setSize(Size2D<unsigned int> size)
{
	this->size = size;
}

void Rect::setBorder(unsigned int border)
{
	this->border = border;
}

void Rect::setColor(Uint8 r, Uint8 g, Uint8 b)
{
	this->color.r = r;
	this->color.g = g;
	this->color.b = b;
	this->color.a = 255;
}

void Rect::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	this->color.r = r;
	this->color.g = g;
	this->color.b = b;
	this->color.a = a;
}

void Rect::setColor(Color color)
{
	this->color = color;
}

void Rect::draw(SDL_Renderer* renderer)
{
	this->draw(renderer, true);
}

void Rect::draw(SDL_Renderer* renderer, bool fill)
{
	SDL_Rect rect;
	rect.x = this->position.x;
	rect.y = this->position.y;
	rect.w = this->size.w;
	rect.h = this->size.h;

	Uint8 tr, tg, tb, ta;
	SDL_GetRenderDrawColor(renderer, &tr, &tg, &tb, &ta);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	if (fill || this->size.w < (this->border*2) || this->size.h < (this->border * 2)) {
		SDL_RenderFillRect(renderer, &rect);
		std::cout << 1 << std::endl;
	}
	else {
		for (int i = this->border; i > 0; i--) {
			SDL_RenderDrawRect(renderer, &rect);
			rect.x++;
			rect.y++;
			rect.w -= 2;
			rect.h -= 2;
		}
	}
	

	SDL_SetRenderDrawColor(renderer, tr, tg, tb, ta);
}


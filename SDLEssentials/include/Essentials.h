#pragma once

#include "Macros.h"

template <class T>
class Vector2D;
template <class T>
class Position2D;
template <class T>
class Size2D;
template <class T>
class Rect2D;

class Color;


template <class T>
class Vector2D 
{
public:
	T x, y;

	inline Vector2D() : x((T)0), y((T)0) {}
	inline Vector2D(T x, T y) : x(x), y(y) {}

	inline Vector2D(SDL_Point point) : x((T)point.x), y((T)point.y) {}
	inline Vector2D(SDL_FPoint point) : x((T)point.x), y((T)point.y) {}

	inline Vector2D(Position2D<T> p) : x(p.x), y(p.y) {}
	inline Vector2D(Size2D<T> s) : x(s.w), y(s.h) {}
	
	template <class U>
	inline Vector2D<U> convertTo() { return Vector2D<U>((U)this->x, (U)this->y); }	

	inline SDL_Point convertToSDL_Point() { return SDL_Point{ (int)this->x, (int)this->y }; }
	inline SDL_FPoint convertToSDL_FPoint() { return SDL_FPoint{ (float)this->x, (float)this->y }; }


};

template <class T>
class Position2D
{
public:
	T x, y;

	inline Position2D() : x((T)0), y((T)0) {}
	inline Position2D(T x, T y) : x(x), y(y) {}

	inline Position2D(SDL_Point point) : x((T)point.x), y((T)point.y) {}
	inline Position2D(SDL_FPoint point) : x((T)point.x), y((T)point.y) {}

	inline Position2D(Vector2D<T> v) : x(v.x), y(v.y) {}
	inline Position2D(Size2D<T> s) : x(s.w), y(s.h) {}

	template <class U>
	inline Position2D<U> convertTo() { return Position2D<U>((U)this->x, (U)this->y); }

	inline SDL_Point convertToSDL_Point() { return SDL_Point{ (int)this->x, (int)this->y }; }
	inline SDL_FPoint convertToSDL_FPoint() { return SDL_FPoint{ (float)this->x, (float)this->y }; }
};

template <class T>
class Size2D
{
public:
	T w, h;

	inline Size2D() : w((T)0), h((T)0) {}
	inline Size2D(T w, T h) : w(w), h(h) {}

	inline Size2D(Vector2D<T> v) : w(v.x), h(v.y) {}
	inline Size2D(Position2D<T> p) : w(p.x), h(p.y) {}

	inline Size2D(SDL_Point point) : w((T)point.x), h((T)point.y) {}
	inline Size2D(SDL_FPoint point) : w((T)point.x), h((T)point.y) {}

	template <class U>
	inline Size2D<U> convertTo() { return Size2D<U>((U)w, (U)h); }

	inline SDL_Point convertToSDL_Point() { return SDL_Point{ (int)w, (int)h }; }
	inline SDL_FPoint convertToSDL_FPoint() { return SDL_FPoint{ (float)w, (float)h }; }

	inline T area() { return w * h; }
};

template <class T>
class Rect2D
{
public:
	T x, y, w, h;

	inline Rect2D() : x((T)0), y((T)0), w((T)0), h((T)0) {}
	inline Rect2D(T x, T y, T w, T h) : x(x), y(y), w(w), h(h) {}

	inline Rect2D(Vector2D<T> p, Vector2D<T> s) : x(p.x), y(p.y), w(s.x), h(s.y) {}
	inline Rect2D(Position2D<T> p, Size2D<T> s) : x(p.x), y(p.y), w(s.w), h(s.h) {}

	inline Rect2D(SDL_Rect r) : x((T)r.x), y((T)r.y), w((T)r.w), h((T)r.h) {}
	inline Rect2D(SDL_FRect r) : x((T)r.x), y((T)r.y), w((T)r.w), h((T)r.h) {}

	template <class U>
	inline Rect2D<U> convertTo() { return Rect2D<U>((U)x, (U)y, (U)w, (U)h); }

	inline SDL_Rect convertToSDL_Rect() { return SDL_Rect{ (int)x,(int)y,(int)w,(int)h }; }
	inline SDL_FRect convertToSDL_FRect() { return SDL_FRect{ (float)x,(float)y,(float)w,(float)h }; }
};

class Color
{
public:
	Uint8 r, g, b, a;

	inline Color() : r(0), g(0), b(0), a(255) {}
	inline Color(Uint8 r, Uint8 g, Uint8 b): r(r), g(g), b(b), a(255) {}
	inline Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) : r(r), g(g), b(b), a(a) {}

	inline Color(SDL_Color color) : r(color.r), g(color.g), b(color.b), a(color.a) {}

	inline SDL_Color convertToSDL_Color() { return SDL_Color{ r, g, b, a }; }
};
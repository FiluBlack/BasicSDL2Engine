#pragma once
class Rect
{
private:
public:
	Position2D<int> position;
	Size2D<unsigned int> size;
	unsigned int border;
	Color color;

	Rect();
	Rect(Position2D<int> position);
	Rect(Position2D<int> position, Size2D<unsigned int> size);
	Rect(Position2D<int> position, Size2D<unsigned int> size, Color color);
	Rect(Position2D<int> position, Size2D<unsigned int> size, unsigned int border);
	Rect(Position2D<int> position, Size2D<unsigned int> size, unsigned int border, Color color);
	~Rect();

	void setPosition(int x, int y);
	void setPosition(Position2D<int> position);

	void setSize(unsigned int w, unsigned int h);
	void setSize(Size2D<unsigned int> size);

	void setBorder(unsigned int border);

	void setColor(Uint8 r, Uint8 g, Uint8 b);
	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void setColor(Color color);

	void draw(SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer, bool fill);
};


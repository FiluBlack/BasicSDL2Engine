#pragma once
class Image
{
private:
	SDL_Surface* m_imageSurface;
	SDL_Texture* m_image;
	Size2D<int> m_textureSize;

public:
	SDL_Renderer* renderer; 
	Position2D<int> position;
	Size2D<unsigned int> size;
	Uint8 alpha;

	// Constructors and Deconstructor

	Image();
	Image(Image const& i);
	Image(Image&& i);
	Image(SDL_Renderer* renderer, const char* file);
	Image(SDL_Renderer* renderer, const char* file, Position2D<int> position);
	Image(SDL_Renderer* renderer, const char* file, Position2D<int> position, Uint8 alpha);
	Image(SDL_Renderer* renderer, const char* file, Position2D<int> position, Size2D<unsigned int> size);
	Image(SDL_Renderer* renderer, const char* file, Position2D<int> position, Size2D<unsigned int> size, Uint8 alpha);
	~Image();

	Image& operator=(const Image& other);
	Image& operator=(Image&& other);

	void loadImage(const char* file);
	void loadImageBySurface(SDL_Surface* surface);
	void unloadImage();

	inline Size2D<int> getTextureSize() const { return m_textureSize; }

	void setPosition(int x, int y);
	void setPosition(Position2D<int> position);

	void setSize(unsigned int w, unsigned int h);
	void setSize(Size2D<unsigned int> size);

	void setAlpha(Uint8 alpha);

	Image getImagePart(int x, int y, unsigned int w, unsigned int h) const;
	Image getImagePart(SDL_Rect* srcrect) const;

	void log() { DEBUG(m_imageSurface); DEBUG(m_image); }

	//rendering functions

	/*
	Renders the scaled Image.
	*/
	void render() const;
	/*
	Renders a scaled rectangular part of the Image.

	x and y are the upper left coordinates of the rectangle.
	w and h are width and height of the rectangle.
	*/
	void renderPart(int x, int y, unsigned int w, unsigned int h) const;
	/*
	Renders a scaled rectangular part of the Image using SDL_Rect.
	*/
	void renderPart(SDL_Rect* srcrect) const;
};


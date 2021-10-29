#include "pch.h"
#include "Image.h"
#include <iostream>

Image::Image()
	: renderer(nullptr), m_imageSurface(nullptr), m_image(nullptr), m_textureSize(Size2D<int>()), 
	position(Position2D<int>()), size(Size2D<unsigned int>()), alpha(255)
{
}

Image::Image(Image const& other)
	: renderer(other.renderer), m_imageSurface(nullptr), m_image(nullptr), m_textureSize(other.m_textureSize), 
	position(other.position), size(other.size), alpha(other.alpha)
{
	this->loadImageBySurface(other.m_imageSurface);
}

Image::Image(Image&& other)
	: renderer(other.renderer), m_imageSurface(nullptr), m_image(nullptr), m_textureSize(other.m_textureSize), 
	position(other.position), size(other.size), alpha(other.alpha)
{
	m_imageSurface = other.m_imageSurface;
	other.m_imageSurface = nullptr;

	m_image = other.m_image;
	other.m_image = nullptr;
}

Image::Image(SDL_Renderer* renderer, const char* file)
	: renderer(renderer), m_imageSurface(nullptr), m_image(nullptr), m_textureSize(Size2D<int>()), 
	position(Position2D<int>()), size(Size2D<unsigned int>()), alpha(255)
{
	loadImage(file);
	this->size = m_textureSize.convertTo<unsigned int>();
}

Image::Image(SDL_Renderer* renderer, const char* file, Position2D<int> position)
	: renderer(renderer), m_imageSurface(nullptr), m_image(nullptr), m_textureSize(Size2D<int>()), position(position), size(Size2D<unsigned int>()), alpha(255)
{
	loadImage(file);
	this->size = m_textureSize.convertTo<unsigned int>();
}

Image::Image(SDL_Renderer* renderer, const char* file, Position2D<int> position, Uint8 alpha)
	: renderer(renderer), m_imageSurface(nullptr), m_image(nullptr), m_textureSize(Size2D<int>()), position(position), size(Size2D<unsigned int>()), alpha(alpha)
{
	loadImage(file);
	this->size = m_textureSize.convertTo<unsigned int>();
}

Image::Image(SDL_Renderer* renderer, const char* file, Position2D<int> position, Size2D<unsigned int> size)
	: renderer(renderer), m_imageSurface(nullptr), m_image(nullptr), m_textureSize(Size2D<int>()), position(position), size(size), alpha(255)
{
	loadImage(file);
}

Image::Image(SDL_Renderer* renderer, const char* file, Position2D<int> position, Size2D<unsigned int> size, Uint8 alpha)
	: renderer(renderer), m_imageSurface(nullptr), m_image(nullptr), m_textureSize(Size2D<int>()), position(position), size(size), alpha(alpha)
{
	loadImage(file);
}

Image::~Image()
{
	this->unloadImage();
}

Image& Image::operator=(const Image& other)
{
	this->unloadImage();

	m_textureSize = other.m_textureSize;

	this->renderer = other.renderer;
	this->position = other.position;
	this->size = other.size;
	this->alpha = other.alpha;

	this->loadImageBySurface(other.m_imageSurface);
	
	return *this;
}

Image& Image::operator=(Image&& other)
{
	this->unloadImage();

	this->renderer = other.renderer;
	this->position = other.position;
	this->size = other.size;
	this->alpha = other.alpha;

	m_imageSurface = other.m_imageSurface;
	other.m_imageSurface = nullptr;

	m_image = other.m_image;
	other.m_image = nullptr;

	return *this;
}

void Image::loadImage(const char* file)
{
	m_imageSurface = IMG_Load(file);
	m_image = SDL_CreateTextureFromSurface(this->renderer, m_imageSurface);
	SDL_QueryTexture(m_image, NULL, NULL, &(m_textureSize.w), &(m_textureSize.h));
}

void Image::loadImageBySurface(SDL_Surface* surface)
{
	this->unloadImage();

	m_imageSurface = SDL_CreateRGBSurface(
		0,
		surface->w,
		surface->h,
		32,
		surface->format->Rmask,
		surface->format->Gmask,
		surface->format->Bmask,
		surface->format->Amask);

	if (SDL_BlitSurface(surface, NULL, m_imageSurface, NULL) < 0) std::cout << SDL_GetError() << std::endl;

	m_image = SDL_CreateTextureFromSurface(this->renderer, m_imageSurface);

	SDL_QueryTexture(m_image, NULL, NULL, &(m_textureSize.w), &(m_textureSize.h));
}

void Image::unloadImage()
{
	if (m_image != nullptr) SDL_DestroyTexture(m_image);
	if (m_imageSurface != nullptr) SDL_FreeSurface(m_imageSurface);
	m_textureSize.w = 0;
	m_textureSize.h = 0;
}

void Image::setPosition(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
}

void Image::setPosition(Position2D<int> position)
{
	this->position = position;
}

void Image::setSize(unsigned int w, unsigned int h)
{
	this->size.w = w;
	this->size.h = h;
}

void Image::setSize(Size2D<unsigned int> size)
{
	this->size = size;
}

void Image::setAlpha(Uint8 alpha)
{
	this->alpha = alpha;
}

Image Image::getImagePart(int x, int y, unsigned int w, unsigned int h) const
{
	SDL_Rect srcr = { x, y, w, h };

	return this->getImagePart(&srcr);
}

Image Image::getImagePart(SDL_Rect* srcrect) const
{
	SDL_Surface* temp_surface = SDL_CreateRGBSurface(
		0,
		srcrect->w,
		srcrect->h,
		32,
		m_imageSurface->format->Rmask,
		m_imageSurface->format->Gmask,
		m_imageSurface->format->Bmask,
		m_imageSurface->format->Amask);

	if (SDL_BlitSurface(m_imageSurface, srcrect, temp_surface, NULL) < 0)
		LOG("Image.getImagePart(): " << SDL_GetError());

	Image temp_image;

	temp_image.renderer = this->renderer;
	temp_image.loadImageBySurface(temp_surface);
	temp_image.setSize(Size2D<unsigned int>(srcrect->w, srcrect->h));

	return temp_image;
}

void Image::render() const
{
	SDL_Rect desr{
		this->position.x,
		this->position.y,
		this->size.w,
		this->size.h
	};

	if (SDL_RenderCopy(this->renderer, m_image, NULL, &desr) < 0)
		LOG("Image.render(): " << SDL_GetError());
}

void Image::renderPart(int x, int y, unsigned int w, unsigned int h) const
{
	SDL_Rect srcr{ x, y, w, h };

	this->renderPart(&srcr);
}

void Image::renderPart(SDL_Rect* srcrect) const
{
	if (m_image == nullptr) return;

	SDL_Rect desr{
		this->position.x,
		this->position.y,
		this->size.w * ((float)srcrect->w / (float)m_textureSize.w),
		this->size.h * ((float)srcrect->h / (float)m_textureSize.h)
	};

	if (SDL_RenderCopy(this->renderer, m_image, srcrect, &desr) < 0)
		LOG("Image.renderPart(): " << SDL_GetError());
}

#include "pch.h"
#include "Spritesheet.h"
/*
Spritesheet::Spritesheet()
	: m_sheet(new Image()), m_sheetSize(Size2D<unsigned int>()), m_spriteSize(Size2D<unsigned int>()), 
	m_spriteCount(0), m_currentSpriteCount(0), m_offset(Vector2D<unsigned int>())
{
}

Spritesheet::Spritesheet(const Spritesheet& other)
	: m_sheet(nullptr), m_sheetSize(other.m_sheet->getTextureSize()), m_spriteSize(other.m_spriteSize), 
	m_spriteCount(other.m_spriteCount), m_currentSpriteCount(other.m_currentSpriteCount), m_offset(other.m_offset)
{
	Image tempImage = *other.m_sheet;
	m_sheet = &tempImage;
}

Spritesheet::Spritesheet(Spritesheet&& other)
	: m_sheet(other.m_sheet), m_sheetSize(m_sheet->getTextureSize()), m_spriteSize(other.m_spriteSize),
	m_spriteCount(other.m_spriteCount), m_currentSpriteCount(other.m_currentSpriteCount), m_offset(other.m_offset)
{
	other.m_sheet = nullptr;
}

Spritesheet::Spritesheet(SDL_Renderer* renderer, const char* file)
	:  m_sheet(new Image(renderer, file)), m_sheetSize(m_sheet->getTextureSize()), m_spriteSize(m_sheetSize.convertTo<unsigned int>()), 
	m_spriteCount(0), m_currentSpriteCount(0), m_offset(Vector2D<unsigned int>())
{
}

Spritesheet::Spritesheet(SDL_Renderer* renderer, const char* file, Size2D<unsigned int> spriteSize)
	: m_sheet(new Image(renderer, file)), m_sheetSize(m_sheet->getTextureSize()), m_spriteSize(spriteSize), 
	m_spriteCount(0), m_currentSpriteCount(0), m_offset(Vector2D<unsigned int>())
{
	m_spriteCount = (m_sheetSize.w / m_spriteSize.w) * (m_sheetSize.h / m_spriteSize.h);
}

Spritesheet::Spritesheet(SDL_Renderer* renderer, const char* file, Size2D<unsigned int> spriteSize, unsigned int spriteCount)
	: m_sheet(new Image(renderer, file)), m_sheetSize(m_sheet->getTextureSize()), m_spriteSize(spriteSize), 
	m_spriteCount(spriteCount), m_currentSpriteCount(0), m_offset(Vector2D<unsigned int>())
{
	unsigned int temp = (m_sheetSize.w / m_spriteSize.w) * (m_sheetSize.h / m_spriteSize.h);
	m_spriteCount = (m_spriteCount > temp) ? temp : m_spriteCount;
}

Spritesheet::Spritesheet(SDL_Renderer* renderer, const char* file, Size2D<unsigned int> spriteSize, Vector2D<unsigned int> offset)
	: m_sheet(new Image(renderer, file)), m_sheetSize(m_sheet->getTextureSize()), m_spriteSize(spriteSize), 
	m_spriteCount(0), m_currentSpriteCount(0), m_offset(offset)
{
	Size2D<int> tempMod(m_sheetSize.w % (m_spriteSize.w + m_offset.x), m_sheetSize.h % (m_spriteSize.h + m_offset.y));
	Size2D<int> tempSpriteCount((m_sheetSize.w / (m_spriteSize.w + m_offset.x)), (m_sheetSize.h / m_spriteSize.h + m_offset.y)); 
	//if(temp)
}

Spritesheet::Spritesheet(SDL_Renderer* renderer, const char* file, Size2D<unsigned int> spriteSize, unsigned int spriteCount, Vector2D<unsigned int> offset)
	: m_sheet(new Image(renderer, file)), m_sheetSize(m_sheet->getTextureSize()), m_spriteSize(spriteSize), 
	m_spriteCount(spriteCount), m_currentSpriteCount(0), m_offset(offset)
{
	unsigned int temp = (m_sheetSize.w / m_spriteSize.w) * (m_sheetSize.h / m_spriteSize.h); // TODO: add offset
	m_spriteCount = (m_spriteCount > temp) ? temp : m_spriteCount;
}

Spritesheet::Spritesheet(Image& sheet)
	: m_sheet(sheet), m_sheetSize(m_sheet.getTextureSize()), m_spriteSize(m_sheetSize)
{
}

Spritesheet::Spritesheet(Image& sheet, Size2D<unsigned int> spriteSize)
{
}

Spritesheet::Spritesheet(Image& sheet, Size2D<unsigned int> spriteSize, unsigned int spriteCount)
{
}

Spritesheet::Spritesheet(Image& sheet, Size2D<unsigned int> spriteSize, Vector2D<unsigned int> offset)
{
}

Spritesheet::Spritesheet(Image& sheet, Size2D<unsigned int> spriteSize, unsigned int spriteCount, Vector2D<unsigned int> offset)
{
}

Spritesheet::~Spritesheet()
{
}

void Spritesheet::setSpriteSize(unsigned int w, unsigned int h)
{
	this->spriteSize.w = w;
	this->spriteSize.h = h;
}

void Spritesheet::setSpriteSize(Size2D<unsigned int> size)
{
	this->spriteSize = 
}

void Spritesheet::setSpriteCount(unsigned int currentCount)
{
}

void Spritesheet::setCurrentSpriteCount(unsigned int count)
{
}*/






SpritesheetAlt::SpritesheetAlt(const SpritesheetAlt& other)
	: renderer(other.renderer), m_sheet(Image(other.m_sheet)), m_sheetSize(other.m_sheetSize), m_spriteSize(other.m_spriteSize), 
	m_maxSpriteCount(other.m_maxSpriteCount), m_maxSpriteCountSize(other.m_maxSpriteCountSize), m_spriteCount(other.m_spriteCount), 
	m_currentSpriteIndex(other.m_currentSpriteIndex)
{
}

SpritesheetAlt::SpritesheetAlt(SpritesheetAlt&& other)
	: renderer(other.renderer), m_sheet(other.m_sheet), m_sheetSize(other.m_sheetSize), m_spriteSize(other.m_spriteSize), 
	m_maxSpriteCount(other.m_maxSpriteCount),m_maxSpriteCountSize(other.m_maxSpriteCountSize), m_spriteCount(other.m_spriteCount),
	m_currentSpriteIndex(other.m_currentSpriteIndex)
{
}

SpritesheetAlt::SpritesheetAlt(SDL_Renderer* renderer, const char* file)
	: renderer(renderer), m_sheet(Image(renderer, file)), m_sheetSize(m_sheet.getTextureSize()), m_spriteSize(m_sheetSize), 
	m_maxSpriteCount(1), m_spriteCount(1), m_currentSpriteIndex(0)
{
}

SpritesheetAlt::SpritesheetAlt(SDL_Renderer* renderer, const char* file, Size2D<unsigned int> spriteSize)
	: renderer(renderer), m_sheet(Image(renderer, file)), m_sheetSize(m_sheet.getTextureSize()), m_spriteSize(spriteSize), 
	m_maxSpriteCount(determineSpriteCountBySpriteSize(spriteSize)), m_spriteCount(m_maxSpriteCount), m_currentSpriteIndex(0)
{
}

SpritesheetAlt::SpritesheetAlt(SDL_Renderer* renderer, const char* file, Size2D<unsigned int> spriteSize, unsigned int spriteCount)
	: renderer(renderer), m_sheet(Image(renderer, file)), m_sheetSize(m_sheet.getTextureSize()), m_spriteSize(spriteSize),
	m_maxSpriteCount(determineSpriteCountBySpriteSize(spriteSize)), m_spriteCount(spriteCount ? spriteCount < m_maxSpriteCount : m_maxSpriteCount), 
	m_currentSpriteIndex(0)
{
}

unsigned int SpritesheetAlt::determineSpriteCountBySpriteSize(Size2D<unsigned int> spriteSize) const
{
	return (m_sheetSize.w % spriteSize.w) * (m_sheetSize.h % spriteSize.h);
}

void SpritesheetAlt::setCurrentSpriteIndex(unsigned int spriteIndex)
{
	m_currentSpriteIndex = m_maxSpriteCount % spriteIndex;
}

void SpritesheetAlt::resetCurrentSpriteIndex()
{
	m_currentSpriteIndex = 0;
}

void SpritesheetAlt::nextSpriteIndex()
{
	setCurrentSpriteIndex(++m_currentSpriteIndex);
}

Image& SpritesheetAlt::getCurrentSprite() const
{
	// TODO: finish the function
	Image i;
	return i;
}

Image& SpritesheetAlt::getNextSprite(bool changeSpriteIndex)
{
	// TODO: finish the function
	Image i;
	return i;
}

Image& SpritesheetAlt::getSpriteByIndex(unsigned int spriteIndex) const
{
	// example: sheet: 10x14    sprite: 2x2    m_maxSpriteCount: 34    spriteIndex: 16

	/*
		
	*/

	// TODO: finish the function

	spriteIndex = spriteIndex % m_maxSpriteCount;    // spriteIndex = 16


	unsigned int spriteCountY = m_sheetSize.w / m_spriteSize.w;    // spriteCountY = 8
	unsigned int spriteCountX = m_sheetSize.h / m_spriteSize.h;    // spriteCountx = 8
	if (spriteCountY == 0) spriteCountY = 1;
	if (spriteCountX == 0) spriteCountX = 1;
	unsigned int spriteIndexY = spriteIndex / spriteCountY;
	unsigned int spriteIndexX = spriteIndex % spriteCountX;

	Image i;
	return i;

}

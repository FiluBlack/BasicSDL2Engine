#pragma once

#include <array>
#include <vector>
#include "Image.h"
/*
class Spritesheet
{
private:
	Image* m_sheet;
	Size2D<unsigned int> m_sheetSize;

	Size2D<unsigned int> m_spriteSize;

	unsigned int m_spriteCount;
	unsigned int m_currentSpriteCount;

	Vector2D<unsigned int> m_offset;


public:
	Spritesheet();
	Spritesheet(const Spritesheet& other);
	Spritesheet(Spritesheet&& other);
	Spritesheet(SDL_Renderer* renderer, const char* file);
	Spritesheet(SDL_Renderer* renderer, const char* file, Size2D<unsigned int> spriteSize);
	Spritesheet(SDL_Renderer* renderer, const char* file, Size2D<unsigned int> spriteSize, unsigned int spriteCount);
	Spritesheet(SDL_Renderer* renderer, const char* file, Size2D<unsigned int> spriteSize, Vector2D<unsigned int> offset);
	Spritesheet(SDL_Renderer* renderer, const char* file, Size2D<unsigned int> spriteSize, unsigned int spriteCount, Vector2D<unsigned int> offset);
	/*Spritesheet(Image& sheet);
	Spritesheet(Image& sheet, Size2D<unsigned int> spriteSize);
	Spritesheet(Image& sheet, Size2D<unsigned int> spriteSize, unsigned int spriteCount);
	Spritesheet(Image& sheet, Size2D<unsigned int> spriteSize, Vector2D<unsigned int> offset);
	Spritesheet(Image& sheet, Size2D<unsigned int> spriteSize, unsigned int spriteCount, Vector2D<unsigned int> offset);
	~Spritesheet();

	void setSpriteCount(unsigned int count);

	Size2D<unsigned int> getSheetSize() { return m_sheetSize; }

	void log() { m_sheet->log(); }

	void setCurrentSpriteCount(unsigned int currentCount);
	void resetCurrentSpriteCount();

};*/

class SpritesheetAlt
{
private:
	const Image& m_sheet;
	Size2D<unsigned int> m_sheetSize;

	Size2D<unsigned int> m_spriteSize;

	unsigned int m_maxSpriteCount;
	Size2D<unsigned int> m_maxSpriteCountSize;
	unsigned int m_spriteCount;

	unsigned int m_currentSpriteIndex;

public:
	SDL_Renderer* renderer;

	SpritesheetAlt(const SpritesheetAlt& other);
	SpritesheetAlt(SpritesheetAlt&& other);

	SpritesheetAlt(SDL_Renderer* renderer, const char* file);
	SpritesheetAlt(SDL_Renderer* renderer, const char* file, Size2D<unsigned int> spriteSize);
	SpritesheetAlt(SDL_Renderer* renderer, const char* file, Size2D<unsigned int> spriteSize, unsigned int spriteCount);

	unsigned int determineSpriteCountBySpriteSize(Size2D<unsigned int> spriteSize) const;

	void setCurrentSpriteIndex(unsigned int spriteIndex);
	void resetCurrentSpriteIndex();
	void nextSpriteIndex();

	inline unsigned int getCurrentSpriteIndex() const { return m_currentSpriteIndex; }

	Image& getCurrentSprite() const;
	Image& getNextSprite(bool changeSpriteIndex = true);
	Image& getSpriteByIndex(unsigned int spriteIndex) const;
};
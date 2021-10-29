#pragma once



class Window
{
public:
	Window();
	~Window();

	inline SDL_Window* getSDLWindow() { return window; }

	inline SDL_Window* createWindow(const char* title, int x, int y, int w, int h, Uint32 flags) {
		window = SDL_CreateWindow(title, x, y, w, h, flags);
		return window;
	}

private:
	SDL_Window* window;

};


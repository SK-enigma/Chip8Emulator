#pragma once


#include <cstdint>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <SDL.h>

class Platform
{
	friend class Imgui;

public:
	Platform(char const* title, int windowWidth, int windowHeight, int textureWidth, int textureHeight);
	~Platform();
	void Update(void const* buffer, int pitch);
	bool ProcessInput(uint8_t* keys);

private:
	SDL_Window* window;
	SDL_GLContext gl_context;
	GLuint framebuffer_texture;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
};
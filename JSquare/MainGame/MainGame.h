#pragma once
#include<iostream>
#include<SDL.h>
#include<glew.h>
#include<string>
#include "../Graphics/Sprite.h"

enum class GameState{PLAY,EXIT};
class MainGame
{
private:
	SDL_Window *_Window1;
	int _ScreenWidth;
	int _ScreenHeight;
	GameState _CGameState;
public:
	MainGame();
	~MainGame();
	void run();
private:
	void Initialize();
	void GameLoop();
	void ProcessInput();
	void DrawGame();

	Sprite sprite1;
};


#include "MainGame.h"

void FatalError(std::string errorString)
{
	std::cout <<"Error! : "<< errorString << std::endl;
	std::cout << "press any key to exit..." << std::endl;
	std::cin.get();
	SDL_Quit();
	exit(1);
}

MainGame::MainGame()
{
	_Window1 = nullptr;
	_ScreenWidth = 800;
	_ScreenHeight = 500;
	_CGameState = GameState::PLAY;
}


MainGame::~MainGame()
{

}

void MainGame::run()
{
	Initialize();
	sprite1.Init(-0.8f, -0.8f, 1.0f, 1.0f);
	sprite1.Draw();
	GameLoop();
}

void MainGame::Initialize()
{
	//Initialization
	SDL_Init(SDL_INIT_EVERYTHING);

	//Starting Window
	_Window1 = SDL_CreateWindow("JSquare",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, _ScreenWidth, _ScreenHeight, SDL_WINDOW_OPENGL);

	if (_Window1 == nullptr)
	{
		FatalError("SDL Window cannot be created!");
	}
	
	SDL_GLContext GLcontext = SDL_GL_CreateContext(_Window1);

	if (GLcontext == nullptr)
	{
		FatalError("SDL-GL Context cannot be created!");
	}

	glewInit();
	if (!glewInit != GLEW_OK)
	{
		FatalError("Glew cannot be initialized!");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.2f, 0.2f, 0.8f, 1.0f);

}

void MainGame::GameLoop()
{
	while (_CGameState != GameState::EXIT)
	{
		ProcessInput();
		DrawGame();
	}
}

void MainGame::ProcessInput()
{
	SDL_Event evnt;
	if (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			_CGameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			//std::cout << evnt.motion.x << ", " << evnt.motion.y << std::endl;
			break;
		default:
			break;
		}
	}
}

void MainGame::DrawGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// This region is to test legacy OpenGL. Plese do not consider it in the project. Its an example.
	/*
	glEnableClientState(GL_COLOR_ARRAY);

	glBegin(GL_TRIANGLES);
	glVertex2f(0.0f, 0.4f);
	glVertex2f( 0.5f, -0.4f);
	glVertex2f( -0.5f, -0.4f);
	glEnd();
	*/
	SDL_GL_SwapWindow(_Window1);
}
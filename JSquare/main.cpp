#include <iostream>
#include<SDL.h>
#include"MainGame/MainGame.h"

int SDL_main(int argc, char** argv)
{
	MainGame Alpha;
	Alpha.run();
	//std::cin.get();
	return 0;
}

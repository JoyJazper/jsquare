#include "ErrorC.h"

#include<iostream>
#include<SDL.h>

void FatalError(std::string errorString)
{
	std::cout << "Error! : " << errorString << std::endl;
	std::cout << "press any key to exit..." << std::endl;
	std::cin.get();
	SDL_Quit();
	exit(1);
}
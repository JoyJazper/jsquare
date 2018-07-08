#pragma once
#include<glew.h>
#include<iostream>
#include<SDL.h>

class Sprite
{
private:
	float _x;
	float _y;
	float _width;
	float _height;
	GLuint _vboID;
public:
	Sprite();
	~Sprite();

	void Init(float x, float y, float width, float height);

	void Draw();

};


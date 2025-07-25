//--------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//--------------------------------------------------------------


//TODO: Inclucde ManageMent

#include "Game.h"
#include "File.h"

using namespace Azul;



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	int ValueReturn;
	File::SetBaseDir("");

	Azul::Game* poGame = new Azul::Game("Engine Prototype 0.2", 1920, 1080);
	ValueReturn = poGame->wWinMain(hInstance, prevInstance, cmdLine, cmdShow);

	delete poGame;

	return ValueReturn;
}

// --- End of File ---

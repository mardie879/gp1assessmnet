#ifndef _GAME_H
#define _GAME_H

/*
==================================================================================
cGame.h
==================================================================================
*/

#include <SDL.h>

// Game specific includes
#include "asteroidsGame.h"


using namespace std;

class cGame
{
public:
	cGame();

	void initialise(SDL_Window* theSDLWND, SDL_Renderer* theRenderer);
	void run(SDL_Window* theSDLWND, SDL_Renderer* theRenderer);
	void cleanUp(SDL_Window* theSDLWND);
	void render(SDL_Window* theSDLWND, SDL_Renderer* theRenderer);
	void render(SDL_Window* theSDLWND, SDL_Renderer* theRenderer, double rotAngle, SDL_Point* spriteCentre);
	void update();
	void update(double deltaTime);
	bool getInput(bool theLoop);
	double getElapsedSeconds();

	static cGame* getInstance();

private:

	static cGame* pInstance;
	// for framerates
	time_point< high_resolution_clock > m_lastTime;
	time_point< high_resolution_clock > m_CurrentTime;
	duration< double > deltaTime;

	// Sprites for displaying background and rocket textures
	cSprite spriteBkgd;
	cSprite spriteMbkd;
	cRocket theRocket;
	cAsteroid theAsteroid;
	cBullet theBullet;
	// game related variables
	vector<LPCSTR> textureName;
	vector<LPCSTR> texturesToUse;
	vector<cAsteroid*> theAsteroids;
	vector<cBullet*> theBullets;
	vector<LPCSTR> fontList;
	vector<LPCSTR> fontsToUse;
	//txt for game
	vector<LPCSTR> gameTextNames;
	vector<LPCSTR> gameTextList;
	// Game objects
	//button
	// Create vector array of button textures
	vector<LPCSTR> btnNameList;
	vector<LPCSTR> btnTexturesToUse;
	vector<SDL_Point> btnPos;
	vector <cButton> theButtons;
	// Define the elements and there position in/on the array/map
	gameState theGameState;
	btnTypes theBtnType;
	SDL_Point theAreaClicked;
	int renderWidth, renderHeight;
	SDL_Rect pos;
	FPoint scale;
	SDL_Rect aRect;
	SDL_Color aColour;
	cTexture* tempTextTexture;
	cFileHandler theFile;
	// Sounds
	vector<LPCSTR> soundList;
	vector<soundType> soundTypes;
	vector<LPCSTR> soundsToUse;

	bool fileAvailable;
	bool loop;
	string scorestr;
	string scoretxt;
	int score;
		
};

#endif

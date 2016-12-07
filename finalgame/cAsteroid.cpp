/*
=================
cAsteroid.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cAsteroid.h"

/*
=================================================================
Defualt Constructor
=================================================================
*/
cAsteroid::cAsteroid() : cSprite()
{
	this->asteroidVelocity = { 0.0, 0.0 };
}
/*
=================================================================
Update the sprite position
=================================================================
*/

void cAsteroid::update(double deltaTime)
{

	//this->setSpriteRotAngle(this->getSpriteRotAngle() +(5.0f * deltaTime)); 
	//if (this->getSpriteRotAngle() > 360)
	//{
		//this->setSpriteRotAngle(this->getSpriteRotAngle() -360);
	//}

	SDL_Rect currentSpritePos = this->getSpritePos();
	currentSpritePos.x = currentSpritePos.x;
	currentSpritePos.y = currentSpritePos.y + this->getSpriteTranslation().y;

	this->setSpritePos({ currentSpritePos.x, currentSpritePos.y });
	cout << "Asteroid position - x: " << this->getSpritePos().x << " y: " << this->getSpritePos().y << " deltaTime: " << deltaTime << endl;
	this->setBoundingRect(this->getSpritePos());

	if (currentSpritePos.y <= 0 || currentSpritePos.y > 700)
	{
		this->setSpriteTranslation({ 0, (this->getSpriteTranslation().y)*(-1) });
	}
	
}
/*
=================================================================
  Sets the velocity for the Asteroid
=================================================================
*/
void cAsteroid::setAsteroidVelocity(SDL_Point AsteroidVel)
{
	asteroidVelocity = AsteroidVel;
}
/*
=================================================================
  Gets the Asteroid velocity
=================================================================
*/
SDL_Point cAsteroid::getAsteroidVelocity()
{
	return asteroidVelocity;
}

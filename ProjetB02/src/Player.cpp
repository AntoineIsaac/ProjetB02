#include "../include/Player.h"

Player::Player(float xPosition, float yPosition, string textureString):Entity(xPosition, yPosition, textureString)
{
    setScale(scale);
}

Player::~Player()
{

}

Player::Player(const Player& other):Entity(other)
{
    //copy ctor
}

Player& Player::operator=(const Player& rhs)
{
    if(this != &rhs)
    {
        Entity::operator=(rhs);
    }
    return *this;
}

Sprite Player::getSprite()const
{
    return Entity::getSprite();
}

float Player::getXPosition()const
{
    return Entity::getXPosition();
}

float Player::getYPosition()const
{
    return Entity::getYPosition();
}

void Player::setXPosition(float x)
{
    Entity::setXPosition(x);
}

void Player::move(float x, float y)
{
    Entity::move(x, y);
}

void Player::setYPosition(float y)
{
    Entity::setYPosition(y);
}

void Player::setPosition(float x, float y)
{
    Entity::setPosition(x, y);
}

void Player::setScale(float x)
{
    Entity::setScale(x);
}

FloatRect Player::getGlobalBounds()
{
    return Entity::getGlobalBounds();
}

FloatRect Player::getGlobalBoundsHitBox()
{
    FloatRect rect = Entity::getGlobalBounds();
    rect.left += hitBoxWidth[0];
    rect.top += hitBoxHeight[0];
    rect.height = hitBoxHeight[1] - hitBoxHeight[0];
    rect.width = hitBoxWidth[1] - hitBoxWidth[0];
    return rect;
}

float Player::getXSpeed()const
{
    return Entity::getXSpeed();
}

float Player::getYSpeed()const
{
    return Entity::getYSpeed();
}

void Player::setXSpeed(float xSpeed)
{
    Entity::setXSpeed(xSpeed);
}

void Player::setYSpeed(float ySpeed)
{
    Entity::setYSpeed(ySpeed);
}

void Player::update(bool left, bool right, bool space, float fps, vector<Platform*> level)
{
    int newXPosition = getXPosition();
    int newYPosition = getYPosition();

    setXSpeed(0);

    if(left)
    {
        setXSpeed(-5.0 * fps);
    }
    if(right)
    {
        setXSpeed(5.0 * fps);
    }
    if(space)
    {
        setYSpeed(-10.0);
        newYPosition += getYSpeed();
    }
    if(!space)
    {
//        setYSpeed(1.0);
//        newYPosition += getYSpeed() * fps;
    }

    newXPosition += getXSpeed() * fps;

    setPosition(newXPosition, newYPosition);

    collision(newXPosition, newYPosition, level);


}

void Player::collision(int &newXPosition, int &newYPosition, vector<Platform*> level)
{

    for(Platform* platform : level)
    {
        //If the player touch the platform
        if(getGlobalBoundsHitBox().intersects(platform->getGlobalBounds()))
        {
            //Bottom collision
            if(getYSpeed() > 0)
               {
                   newXPosition = getXPosition();
                   newYPosition = platform->getYPosition() - getGlobalBounds().height + (getGlobalBounds().height - hitBoxHeight[1]);
               }
            //Top collision
            if(getYSpeed() < 0)
               {
                   newXPosition = getXPosition();
                   newYPosition = platform->getYPosition() + platform->getSize() - hitBoxHeight[0];
               }
            //Right collision
            if(getXSpeed() > 0)
               {
                   newXPosition = platform->getXPosition() - getGlobalBounds().width + (getGlobalBounds().width - hitBoxWidth[1]);
                   newYPosition = getYPosition();
               }
            //Left collision
            if(getXSpeed() < 0)
               {
                   newXPosition = platform->getXPosition() + platform->getSize() - hitBoxWidth[0];
                   newYPosition = getYPosition();
               }
        }
    }

    setPosition(newXPosition, newYPosition);

}

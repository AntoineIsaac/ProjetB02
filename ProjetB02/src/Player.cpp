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

FloatRect Player::getLocalBounds()
{
    return Entity::getLocalBounds();
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

void Player::update(bool left, bool right, bool space, float fps, float groundHeight)
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
        newYPosition += getYSpeed() - 100;
    }
    if(!space)
    {
        setYSpeed(10.0);
        newYPosition += getYSpeed() * fps;
    }

    newXPosition += getXSpeed() * fps;

    setPosition(newXPosition, newYPosition);

    collision(newXPosition, newYPosition);


}

void Player::collision(int &newXPosition, int &newYPosition)
{

    bool collisionLeft = false, collisionRight = false, collisionTop = false, collisionBottom = false;

    if(getXPosition() + hitBoxWidth[0] < 0)
    {
        collisionLeft = true;
    }
    if(getXPosition() + hitBoxWidth[1] > 800)
    {
        collisionRight = true;
    }
    if(getYPosition() + hitBoxHeight[0] < 0)
    {
        collisionTop = true;
    }
    if(getYPosition() + hitBoxHeight[1] > 400)
    {
        collisionBottom = true;
    }

    if(collisionLeft)
        newXPosition = 0 - hitBoxWidth[0];

    if(collisionRight)
        newXPosition = 800 - hitBoxWidth[1];

    if(collisionTop)
        newYPosition = 0 - hitBoxHeight[0];

    if(collisionBottom)
        newYPosition = 400 - hitBoxHeight[1];

    setPosition(newXPosition, newYPosition);

}

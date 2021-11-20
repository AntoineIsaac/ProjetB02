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
        setYSpeed(-20.0 * fps);
        onGround = false;
    }
    if(!space)
    {
        setYSpeed(10.0 * fps);
    }

    newXPosition += getXSpeed();
    newYPosition += getYSpeed();

    collision(newXPosition, newYPosition, level);


}

void Player::collision(int &newXPosition, int &newYPosition, vector<Platform*> level)
{

    float withoutCollX = newXPosition;
    float withoutCollY = newYPosition;

    for(Platform * platform : level)
    {
        bool coll = false;
        //Left
        if(onGround == true)
        {
            //Left
            if( newXPosition + hitBoxWidth[0] < platform->getXPosition() + platform->getSize() && getXPosition() + hitBoxWidth[0] >= platform->getXPosition() + platform->getSize()
           && (((getYPosition()  + hitBoxHeight[1] < platform->getYPosition() + platform->getSize() ) && (getYPosition() + hitBoxHeight[1] > platform->getYPosition()) ) || ((getYPosition() + hitBoxHeight[0] + (height/2) < platform->getYPosition() + platform->getSize()) && (getYPosition()  + hitBoxHeight[0] + (height/2) > platform->getYPosition())) || ((getYPosition() + hitBoxHeight[0] < platform->getYPosition() + platform->getSize() ) && (getYPosition()  + hitBoxHeight[0] > platform->getYPosition())) ))
           {
                newXPosition =  platform->getXPosition() + platform->getSize() - hitBoxWidth[0];
                coll = true;
           }

           //Bottom
           if( newYPosition + hitBoxHeight[1] > platform->getYPosition() && getYPosition() + hitBoxHeight[1] <= platform->getYPosition()
           && (((getXPosition() +hitBoxWidth[0] < platform->getXPosition() + platform->getSize()) && (getXPosition() + hitBoxWidth[0] > platform->getXPosition())) || ((getXPosition() + hitBoxWidth[0] + (width/2) < platform->getXPosition() + platform->getSize()) && (getXPosition() + hitBoxWidth[0] + (width/2) > platform->getXPosition())) || ((getXPosition() + hitBoxWidth[1] < platform->getXPosition() + platform->getSize()) && (getXPosition() + hitBoxWidth[1] > platform->getXPosition()))))
            {
                newYPosition =  platform->getYPosition() - height - hitBoxHeight[0];
                onGround = true;
                coll = true;
            }

            //Right
            if( newXPosition + hitBoxWidth[1] > platform->getXPosition() && getXPosition() + hitBoxWidth[1] <= platform->getXPosition()
               && (((getYPosition() + hitBoxHeight[1] < platform->getYPosition() + platform->getSize()) && (getYPosition()  + hitBoxHeight[1] > platform->getYPosition())) || ((getYPosition()  + hitBoxHeight[0] +(height/2) < platform->getYPosition() + platform->getSize()) && (getYPosition()  + hitBoxHeight[0] + (height/2) > platform->getYPosition())) || ((getYPosition() + hitBoxHeight[0] < platform->getYPosition() + platform->getSize()) && (getYPosition()  + hitBoxHeight[0] > platform->getYPosition())) ))
            {
                newXPosition =  platform->getXPosition() - width - hitBoxWidth[0];
                coll = true;
            }


        }
        else
        {
            //Left
            if( newXPosition + hitBoxWidth[0] < platform->getXPosition() + platform->getSize() && getXPosition() + hitBoxWidth[0] >= platform->getXPosition() + platform->getSize()
                    && (((getYPosition()  + hitBoxHeight[1] <= platform->getYPosition() + platform->getSize() ) && (getYPosition() + hitBoxHeight[1] >= platform->getYPosition()) ) || ((getYPosition() + hitBoxHeight[0] + (height/2) < platform->getYPosition() + platform->getSize()) && (getYPosition()  + hitBoxHeight[0] + (height/2) > platform->getYPosition())) || ((getYPosition() + hitBoxHeight[0] < platform->getYPosition() + platform->getSize() ) && (getYPosition()  + hitBoxHeight[0] > platform->getYPosition())) ))
            {
                newXPosition =  platform->getXPosition() + platform->getSize() - hitBoxWidth[0];
                coll = true;
            }

            //Bottom
            if( newYPosition + hitBoxHeight[1] > platform->getYPosition() && getYPosition() + hitBoxHeight[1] <= platform->getYPosition()
                    && (((getXPosition() +hitBoxWidth[0] <= platform->getXPosition() + platform->getSize()) && (getXPosition() + hitBoxWidth[0] >= platform->getXPosition())) || ((getXPosition() + hitBoxWidth[0] + (width/2) < platform->getXPosition() + platform->getSize()) && (getXPosition() + hitBoxWidth[0] + (width/2) > platform->getXPosition())) || ((getXPosition() + hitBoxWidth[1] <= platform->getXPosition() + platform->getSize()) && (getXPosition() + hitBoxWidth[1] >= platform->getXPosition()))))
            {
                newYPosition =  platform->getYPosition() - height - hitBoxHeight[0];
                onGround = true;
                coll = true;
            }

                    //Right
            if( newXPosition + hitBoxWidth[1] > platform->getXPosition() && getXPosition() + hitBoxWidth[1] <= platform->getXPosition()
               && (((getYPosition() + hitBoxHeight[1] <= platform->getYPosition() + platform->getSize()) && (getYPosition()  + hitBoxHeight[1] >= platform->getYPosition())) || ((getYPosition()  + hitBoxHeight[0] +(height/2) < platform->getYPosition() + platform->getSize()) && (getYPosition()  + hitBoxHeight[0] + (height/2) > platform->getYPosition())) || ((getYPosition() + hitBoxHeight[0] < platform->getYPosition() + platform->getSize()) && (getYPosition()  + hitBoxHeight[0] > platform->getYPosition())) ))
            {
                newXPosition =  platform->getXPosition() - width - hitBoxWidth[0];
                coll = true;
            }

            //Top
            if( newYPosition + hitBoxHeight[0] < platform->getYPosition() + platform->getSize() && getYPosition() + hitBoxHeight[0] >= platform->getYPosition() + platform->getSize()
               && (((getXPosition() +hitBoxWidth[0] < platform->getXPosition() + platform->getSize()) && (getXPosition() + hitBoxWidth[0] > platform->getXPosition())) || ((getXPosition() + hitBoxWidth[0] + (width/2) < platform->getXPosition() + platform->getSize()) && (getXPosition() + hitBoxWidth[0] + (width/2) > platform->getXPosition())) || ((getXPosition() + hitBoxWidth[1] < platform->getXPosition() + platform->getSize()) && (getXPosition() + hitBoxWidth[1] > platform->getXPosition()))))
            {
                newYPosition =  platform->getYPosition() + platform->getSize() - hitBoxHeight[0];
                coll = true;
            }


        }

        if(coll == true)
        {
            if(platform->getType() == 3)
            {
                Checkpoint* c = (Checkpoint*) platform;
                c->switchCheckpoint();
                newXPosition = withoutCollX;
                newYPosition = withoutCollY;
            }
        }
    }
    setPosition(newXPosition, newYPosition);

}

#include "../include/Player.h"

Player::Player(float xPosition, float yPosition, string textureString):Entity(xPosition, yPosition, textureString)
{
    setScale(scale);
    //sprite.setOrigin(width/2, height/2);
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
    // +125 pour que ce soit sa tête qui soit en collision avec le zombie et non ses pieds
    rect.width = hitBoxWidth[1] - hitBoxWidth[0] + (125*scale);
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

void Player::update(bool left, bool right, bool space, float fps, vector<Platform*> level, vector<Zombie*> enemies)
{
    int newXPosition = getXPosition();
    int newYPosition = getYPosition();
    bool move = false;
    setXSpeed(0);

    if(left)
    {
//        if(direction == Direction::droite)
//        {
//            sprite.setScale(Vector2f(-0.2, 0.2));
//            direction = Direction::gauche;
//        }
            setXSpeed(-5.0 * fps);
            move = true;
    }
    if(right)
    {
//        if(direction == Direction::gauche)
//        {
//            sprite.setScale(Vector2f(0.2, 0.2));
//            direction = Direction::droite;
//        }
        setXSpeed(5.0 * fps);
        move = true;
    }

    if(space)
    {
        setYSpeed(-30.0 * fps);
    }

    newXPosition += getXSpeed();
    newYPosition += getYSpeed();


    collision(newXPosition, newYPosition, level);
    collisionEnemies(newXPosition, newYPosition, enemies);


    if(onGround == false && newYPosition <  getYPosition() - jumpHeight)
    {
        setYSpeed(15.0 * fps);
        setPosition(getXPosition(), getYPosition() + getYSpeed());
    }


    if(move == true)
    {
        if(onGround == false)
            loadTextureJump();
        else
        {
            animation++;
            if(animation > 8)
                animation = 1;
            loadTexture();
        }
    }else
    {
        if(onGround == false)
            loadTextureJump();
        else
            loadTextureIdle();
    }



}

void Player::collision(int &newXPosition, int &newYPosition, vector<Platform*> level)
{
    float withoutCollX = newXPosition;
    float withoutCollY = newYPosition;

    bool colGround = false;

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
                colGround = true;
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
                colGround = true;
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

                newXPosition = withoutCollX;
                newYPosition = withoutCollY;

                if(c->isActivated() == false)
                {
                    c->switchCheckpoint();
                    setRespawnPosition(c->getXPosition(), c->getYPosition() - 100);
                }
            }

            //Respawn si il touche un bloc de lave
            if(platform->getType() == 2)
            {
                newXPosition = getRespawnPosition().x;
                newYPosition = getRespawnPosition().y;
            }
        }
    }

    //Lorsqu"il tombe dans le vide, onGround = false
    if(colGround == false)
    {
        onGround = false;
    }

    setPosition(newXPosition, newYPosition);

    //Respawn si il tombe dans le vide
    if(getYPosition() > 700)
    {
        setPosition(getRespawnPosition().x, getRespawnPosition().y);
    }

}

void Player::collisionEnemies(int& newXPosition, int& newYposition, vector<Zombie*>enemies)
{
    for(Zombie* zombie : enemies)
    {
        if(getGlobalBoundsHitBox().intersects(zombie->getGlobalBoundsHitBox()))
        {
            setPosition(getRespawnPosition().x, getRespawnPosition().y);
            break;
        }
    }
}



void Player::loadTexture()
{
    if(!texture.loadFromFile("./Images/jackfree/png/Run ("+to_string(animation)+").png"))
    {
        cout << "Erreur dans le chargement de la texture"<<endl;
    }
}

void Player::loadTextureIdle()
{
    if(!texture.loadFromFile("./Images/jackfree/png/Idle (1).png"))
    {
        cout << "Erreur dans le chargement de la texture"<<endl;
    }
}

void Player::loadTextureJump()
{
    if(!texture.loadFromFile("./Images/jackfree/png/Jump (3).png"))
    {
        cout << "Erreur dans le chargement de la texture"<<endl;
    }
}

Vector2f Player::getRespawnPosition() const
{
    return respawnPosition;
}

void Player::setRespawnPosition(float x, float y)
{
    this->respawnPosition.x = x;
    this->respawnPosition.y = y;
}


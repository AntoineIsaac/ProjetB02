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


void Player::update(bool left, bool right, bool space, float fps, vector<Platform*> level, vector<Zombie*> enemies, Game* game)
{
    int newXPosition = getXPosition();
    int newYPosition = getYPosition();
    bool move = false;
    setXSpeed(0);




    if(left)
    {
            setXSpeed(-5.0 * fps);
            if(web == true){
               setXSpeed(-2.0 * fps);
            }
            move = true;
    }
    if(right)
    {
        setXSpeed(5.0 * fps);
        if(web == true){
           setXSpeed(2.0 * fps);
        }
        move = true;
    }

    if(space && canJump == true)
    {
        //récupérer le y du bloc du quel on saute
        jumpBlock = getYPosition();
        setYSpeed(-15.0 * fps);
        canJump = false;
        web = false;
    }

    newXPosition += getXSpeed();
    newYPosition += getYSpeed();

    if(alreadyTouched == false){
        setYSpeed(90 * fps);
        alreadyTouched = true;
    }

    if (onGround == false && ((newYPosition < (jumpBlock - jumpHeight) || colTop == true)))
    {
        space = false;
        setYSpeed(8 * fps);
    }

    colTop = collision(newXPosition, newYPosition, level, game);
    collisionEnemies(newXPosition, newYPosition, enemies, game);

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
    }
    else
    {
        if(onGround == false)
            loadTextureJump();
        else
            loadTextureIdle();
    }
}

bool Player::collision(int &newXPosition, int &newYPosition, vector<Platform*> level, Game* game)
{
    float withoutCollX = newXPosition;
    float withoutCollY = newYPosition;

    bool colGround = false;
    bool colTop = false;

    bool dead = false;

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
                canJump = true;
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
                colTop = true;
            }


        }

        if(coll == true)
        {
            //Respawn si il touche un bloc de lave
            if(platform->getType() == "LavaBlock" || platform->getType() == "CactusBlock" || platform->getType() == "TntBlock")
            {
                dead = true;
            }

            //Si toile d'araignée
            if(platform->getType() == "SpiderWebBlock" || platform->getType() == "Water")
            {
                web = true;
                newXPosition = withoutCollX;
                newYPosition = withoutCollY;

            }

//            if(platform->getType() != "SpiderWebBlock")
//            {
//                web = false;
//            }


            //Il active la JackOLantern si il marche dessus et active le checkpoint
            if(platform->getType() == "Checkpoint")
            {
                Checkpoint* j = (Checkpoint*) platform;

                if(j->isActivated() == false)
                {
                    j->switchCheckpoint();

                    setRespawnPosition(j->getXPosition(), j->getYPosition() - (height + 20));
                }
            }

            //Passe au travers des bloc d'obsidian pour pouvoir rentrer dans le portail
            if(platform->getType() == "ObsidianBlock" || platform->getType() == "NetherWoodBlock" || platform->getType() == "QuicksandBlock" || platform->getType() == "RedQuicksandBlock")
            {
                newXPosition = withoutCollX;
                newYPosition = withoutCollY;
                onGround = false;
            }

            if(platform->getType() == "PortalBlock")
            {
                if(onGround == true)
                {
                    game->setEndLevel(true);
                }
                else
                {
                    newXPosition = withoutCollX;
                    newYPosition = withoutCollY;
                }
            }


        }

    }

    //Lorsqu"il tombe dans le vide, onGround = false
    if(colGround == false)
    {
        onGround = false;
        canJump = false;
    }
    if(newXPosition < 0)
        setPosition(0, newYPosition);
    else
        setPosition(newXPosition, newYPosition);

    //Respawn si il tombe dans le vide
    if(getYPosition() > 1000 || dead == true)
    {
        setPosition(getRespawnPosition().x, getRespawnPosition().y);
        HP--;
        if(HP == 0)
        {
            game->setLevelFailed(true);
        }
    }
    return colTop;

}

void Player::collisionEnemies(int& newXPosition, int& newYposition, vector<Zombie*>enemies, Game* game)
{
    for(Zombie* zombie : enemies)
    {
        if(getGlobalBoundsHitBox().intersects(zombie->getGlobalBoundsHitBox()))
        {
            setPosition(getRespawnPosition().x, getRespawnPosition().y);
            HP--;
            if(HP == 0)
            {
                game->setLevelFailed(true);
            }

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

void Player::setHP(int hp)
{
    this->HP = hp;
}

int Player::getHP() const
{
    return HP;
}


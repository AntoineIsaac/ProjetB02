#ifndef PLATFORM_H
#define PLATFORM_H
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "NetherBlock.h"
#include "PortalBlock.h"
#include "ObsidianBlock.h"
#include "SpiderWebBlock.h"
#include "NetherWoodBlock.h"
#include "LeafBlock.h"
#include "FireBlock.h"
#include "SandBlock.h"
#include "NetherFence.h"
#include "CactusBlock.h"
#include "QuicksandBlock.h"
#include "RedQuicksandBlock.h"
#include "RedSandBlock.h"
#include "RedSmoothSandBlock.h"
#include "SandBlock.h"
#include "SmoothSandBlock.h"
#include "SugarCaneBlock.h"
#include "NetherLianaBlock.h"
#include "NetherWartBlock.h"
#include "CloudBlock.h"
#include "AcasiaLeafBlock.h"
#include "AcasiaWoodBlock.h"
#include "LianaBlock.h"
#include "Dirt.h"
#include "WheatBlock.h"
#include "WoodPlank.h"
#include "Water.h"
#include "TntBlock.h"

using namespace sf;
using namespace std;


class Platform
{
    private:
        float xPosition;
        float yPosition;
        Texture texture;
        Sprite sprite;

    public:
        static inline float scale = 3.5;
        static inline float size = 16*scale;

        Platform(float xPosition=0, float yPosition=0);
        virtual ~Platform();
        Platform(const Platform& other);
        Platform& operator=(const Platform& other);

        //Getters and setters
        virtual float getXPosition()const;
        virtual void setXPosition(float x);

        virtual float getYPosition()const;
        virtual void setYPosition(float y);
        //Permet de récupérer les dimensions d'un block
        virtual FloatRect getGlobalBounds();
        virtual float getSize();

        virtual Sprite getSprite()const;
        virtual void setSprite(string textureString, IntRect coord);

        virtual void setScale(float x);

        //Renvoi le type du block
        virtual string getType()const = 0;

        Platform* platformFactory(string type, int i, int j);

};

#endif // PLATFORM_H

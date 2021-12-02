#include "../include/Platform.h"

Platform::Platform(float xPosition, float yPosition):xPosition(xPosition), yPosition(yPosition)
{
    setScale(scale);
}

Platform::~Platform()
{
    //dtor
}

Platform::Platform(const Platform& other):xPosition(other.xPosition), yPosition(other.yPosition)
{
    //copy ctor
}

Platform& Platform::operator=(const Platform& rhs)
{
    if (this != &rhs)
    {
        xPosition = rhs.xPosition;
        yPosition = rhs.yPosition;
        sprite = rhs.sprite;
    }

    return *this;
}

float Platform::getXPosition()const
{
    return xPosition;
}

void Platform::setXPosition(float x)
{
    xPosition = x;
}

float Platform::getYPosition()const
{
    return yPosition;
}

void Platform::setYPosition(float y)
{
    yPosition = y;
}

FloatRect Platform::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

float Platform::getSize()
{
    return size;
}

Sprite Platform::getSprite()const
{
    return sprite;
}

void Platform::setSprite(string textureString, IntRect coord)
{
    texture.loadFromFile(textureString);
    sprite.setTexture(texture);
    sprite.setTextureRect(coord);
    sprite.setPosition(xPosition, yPosition);
}

void Platform::setScale(float x)
{
    sprite.scale(x, x);
}

Platform* Platform::platformFactory(string type, int i, int j)
{

        if(type == "AcasiaLeafBlock") return new AcasiaLeafBlock(i, j);

//        case "AcasiaWoodBlock": return new AcasiaWoodBlock(i, j); break;
//        case "CactusBlock": return new CactusBlock(i, j); break;
//        case "Checkpoint": return new Checkpoint(i, j); break;
//        case "CloudBlock": return new CloudBlock(i, j); break;
//        case "Dirt": return new Dirt(i, j); break;
//        case "FireBlock": return new FireBlock(i, j); break;
//        case "GrassBlock": return new GrassBlock(i, j); break;
//        case "LavaBlock": return new LavaBlock(i, j); break;
//        case "LeafBlock": return new LeafBlock(i, j); break;
//        case "LianaBlock": return new LianaBlock(i, j); break;
//        case "NetherBlock": return new NetherBlock(i, j); break;
//        case "NetherFence": return new NetherFence(i, j); break;
//        case "NetherLianaBlock": return new NetherLianaBlock(i, j); break;
//        case "NetherWartBlock": return new NetherWartBlock(i, j); break;
//        case "NetherWoodBlock": return new NetherWoodBlock(i, j); break;
//        case "ObsidianBlock": return new ObsidianBlock(i, j); break;
//        case "PortalBlock": return new PortalBlock(i, j); break;
//        case "QuicksandBlock": return new QuicksandBlock(i, j); break;
//        case "RedQuicksandBlock": return new RedQuicksandBlock(i, j); break;
//        case "RedSandBlock": return new RedSandBlock(i, j); break;
//        case "RedSmoothSandBlock": return new RedSmoothSandBlock(i, j); break;
//        case "SandBlock": return new SandBlock(i, j); break;
//        case "SmoothSandBlock": return new SmoothSandBlock(i, j); break;
//        case "SpiderWebBlock": return new SpiderWebBlock(i, j); break;
//        case "SugarCaneBlock": return new SugarCaneBlock(i, j); break;
//        case "TntBlock": return new TntBlock(i, j); break;
//        case "Water": return new Water(i, j); break;
//        case "WheatBlock": return new WheatBlock(i, j); break;
//        case "WoodPlank": return new WoodPlank(i, j); break;
}

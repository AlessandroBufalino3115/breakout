#include "MovableObj.h"
MovableObj::MovableObj()
{
  if (!texture.loadFromFile("Data/Images/ballBlue.png"))
  {
    printf("ball not balling");
  }
  sprite.setTexture(texture);
}

MovableObj::MovableObj(std::string filename)
{
  if (!texture.loadFromFile(filename))
  {
    printf("ball not balling filename");
  }
  sprite.setTexture(texture);
}

MovableObj::~MovableObj()
{
  cout << "movable obj deleted" << endl;
}

sf::Sprite* MovableObj::getSprite()
{
  return &sprite;
}

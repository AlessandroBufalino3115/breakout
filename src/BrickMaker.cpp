#include "BrickMaker.h"

BrickMaker::BrickMaker()
{
  if (!texture.loadFromFile("Data/Images/element_purple_rectangle_glossy.png"))
  {
    printf ("no default");
  }
  sprite.setTexture(texture);
}

void BrickMaker::setTexture(std::string filename)
{
  if (!texture.loadFromFile(filename))
  {
    printf ("no");
  }
  sprite.setTexture(texture);
}

BrickMaker::~BrickMaker()
{
  printf ("static brick deleted");
}

sf::Sprite* BrickMaker::getSprite()
{
  return &sprite;
}

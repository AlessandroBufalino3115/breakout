#ifndef BREAKOUT_GAMEOBJECT_H
#define BREAKOUT_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class BrickMaker
{
 public:
  BrickMaker();
  ~BrickMaker();
  void setTexture(std::string filename);

  sf::Sprite* getSprite();

 private:

  sf::Sprite sprite;
  sf::Texture texture;

};

#endif // BREAKOUT_GAMEOBJECT_H
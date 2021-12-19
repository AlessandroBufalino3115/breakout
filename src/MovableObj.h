#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include <iostream>

#ifndef BREAKOUTSFML_MOVABLEOBJ_H
#define BREAKOUTSFML_MOVABLEOBJ_H
using namespace std;
class MovableObj
{
 public:

  MovableObj();
  MovableObj(std::string filename);
  ~MovableObj();

  sf::Sprite* getSprite();

  Vector2 direction = {0,0};
  float speed = 175;
  int pick_up_type = 0;

 private:
  sf::Sprite sprite;
  sf::Texture texture;

};

#endif // BREAKOUTSFML_MOVABLEOBJ_H

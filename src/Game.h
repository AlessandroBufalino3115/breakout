
#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include "BrickMaker.h"
#include "Vector2.h"
#include "levels_design.h"
#include "MovableObj.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void collisionCheck();

  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  void mousePos(sf::Event event);

  void levelSetup(int level); // takes the number of the level that needs to get loaded, saves the array containing the values of each brick into a clean vector
  void levelCreation(std::vector<LevelDesigner>); //creates an array of length of the vector of type Brick and instantiating each brick into the game

  void driveBall(MovableObj* ball);  //called when a new ball is instantiated to give it motion
  void addLife();
  void resetStats(); //called when in need to start a new game
  void pickUpSpawn(int x,int y); //spawn a buff or debuff depending on the probability
  void pickUpEffect(int type); //apply the buff or debuff that the player picked up

 private:
  std::vector<MovableObj*> balls;
  std::vector<MovableObj*> pick_ups;

  MovableObj* paddle;
  MovableObj* bullet;

  sf::Font font;
  sf::RenderWindow& window;

  sf::Text start_text_menu; // this starts form lv 1
  sf::Text levels_text_menu; // this is where the player can choose the level
  sf::Text description_text_menu; // this is where the player can choose the level

  sf::Text description_text_levelsel;
  sf::Text back_text_levelsel;
  sf::Text LV1_levelsel; //different levels the player can choose
  sf::Text LV2_levelsel;
  sf::Text LV3_levelsel;
  sf::Text LV4_levelsel;
  sf::Text LV5_levelsel;

  sf::Text score_display;  // in game text
  sf::Text life_display;
  sf::Text ammo_display;
  sf::Text game_start_display;

  sf::Text game_ending_description; //description of how the game ended
  sf::Text game_ending_menu;
  sf::Text game_ending_start;

  sf::Clock clock;
  sf::Time second = sf::seconds(10);

  enum CurrentScreen
  {
    MAIN_MENU_SCREEN = 0,
    LEVEL_SELECTION_SCREEN,
    GAME_SCREEN,
    END_GAME_SCREEN
  };

  std::string red_filename = "Data/Images/element_red_rectangle_glossy.png";
  std::string green_filename = "Data/Images/element_green_rectangle_glossy.png";
  std::string yellow_filename = "Data/Images/element_yellow_rectangle_glossy.png";

  std::string drop_points_filename = "Data/Images/element_red_polygon_glossy.png";
  std::string drop_mpoints_filename = "Data/Images/element_yellow_diamond_glossy.png";
  std::string drop_bullet_filename = "Data/Images/ballGrey.png";
  std::string drop_ball_filename = "Data/Images/ballBlue.png";
  std::string drop_scalep_filename = "Data/Images/paddleBlue.png";
  std::string drop_scalem_filename = "Data/Images/paddleRed.png";


  std::vector<LevelDesigner> current_level_vector;
  BrickMaker* brick_array = nullptr;

  //different levels
  LevelDesigner LV1[80] =   {{1,1,1, 0},{1,1,1, 1},{1,1,1, 2},{1,1,1, 3},{1,1,1, 4},{1,1,1, 5},{1,1,1, 6},{1,1,1, 7},{1,1,1, 8},{1,1,1, 9},{1,1,1, 10},{1,1,1, 11},{1,1,1, 12},{1,1,1, 13},{1,1,1, 14},{1,1,1, 15},{1,1,1, 16},{1,1,1, 17},{1,1,1, 18},{1,1,1, 19}
                            ,{1,2,2, 0},{1,2,2, 1},{1,2,2, 2},{1,2,2, 3},{1,2,2, 4},{1,2,2, 5},{1,2,2, 6},{1,2,2, 7},{1,2,2, 8},{1,2,2, 9},{1,2,2, 10},{1,2,2, 11},{1,2,2, 12},{1,2,2, 13},{1,2,2, 14},{1,2,2, 15},{1,2,2, 16},{1,2,2, 17},{1,2,2, 18},{1,2,2, 19}
                            ,{1,3,3, 0},{1,3,3, 1},{1,3,3, 2},{1,3,3, 3},{1,3,3, 4},{1,3,3, 5},{1,3,3, 6},{1,3,3, 7},{1,3,3, 8},{1,3,3, 9},{1,3,3, 10},{1,3,3, 11},{1,3,3, 12},{1,3,3, 13},{1,3,3, 14},{1,3,3, 15},{1,3,3, 16},{1,3,3, 17},{1,3,3, 18},{1,3,3, 19}
                            ,{1,0,4, 0},{1,0,4, 1},{1,0,4, 2},{1,0,4, 3},{1,0,4, 4},{1,0,4, 5},{1,0,4, 6},{1,0,4, 7},{1,0,4, 8},{1,0,4, 9},{1,0,4, 10},{1,0,4, 11},{1,0,4, 12},{1,0,4, 13},{1,0,4, 14},{1,0,4, 15},{1,4,4, 16},{1,0,4, 17},{1,0,4, 18},{1,0,4, 19}};

  LevelDesigner LV2[44] =   {{1,1,3, 4},{1,1,4, 4},{1,1,5, 4},{1,1,6, 4},{1,1,7, 4},{1,1,8, 4},{1,1,9, 4}
                            ,{1,2,5, 5},{1,2,6, 5},{1,2,7, 5},{1,2,8, 5},{1,2,9, 5}
                            ,{1,1,6, 6},{1,1,7, 6},{1,1,8, 6},{1,1,9, 6}
                            ,{1,2,7, 7},{1,2,8, 7},{1,2,9, 7}
                            ,{1,3,8, 8},{1,3,9, 8}
                            ,{1,0,9, 9}
                            ,{1,0,9, 10}
                            ,{1,3,8, 11},{1,3,9, 11}
                            ,{1,2,7, 12},{1,2,8, 12},{1,2,9, 12}
                            ,{1,1,6, 13},{1,1,7, 13},{1,1,8, 13},{1,1,9, 13}
                            ,{1,2,5, 14},{1,2,6, 14},{1,2,7, 14},{1,2,8, 14},{1,2,9, 14}
                            ,{1,1,3, 15},{1,1,4, 15},{1,1,5, 15},{1,1,6, 15},{1,1,7, 15},{1,1,8, 15},{1,1,9, 15}};

  LevelDesigner LV3[48] = {{1,1,2, 5},{1,3,2, 7},{1,1,2, 9},{1,2,2, 11},{1,0,2, 13},{1,3,2, 15}
                            ,{1,3,3, 6},{1,3,3, 8},{1,0,3, 10},{1,2,3, 12},{1,1,3, 14},{1,2,3, 16}
                            ,{1,2,4, 5},{1,1,4, 7},{1,2,4, 9},{1,1,4, 11},{1,0,4, 13},{1,1,4, 15}
                            ,{1,0,5, 6},{1,2,5, 8},{1,3,5, 10},{1,0,5, 12},{1,1,5, 14},{1,3,5, 16}

                            ,{1,1,6, 5},{1,3,6, 7},{1,1,6, 9},{1,2,6, 11},{1,0,6, 13},{1,3,6, 15}
                            ,{1,3,7, 6},{1,3,7, 8},{1,0,7, 10},{1,2,7, 12},{1,1,7, 14},{1,2,7, 16}
                            ,{1,2,8, 5},{1,1,8, 7},{1,2,8, 9},{1,1,8, 11},{1,0,8, 13},{1,1,8, 15}
                            ,{1,0,9, 6},{1,2,9, 8},{1,3,9, 10},{1,0,9, 12},{1,1,9, 14},{1,3,9, 16}};

  LevelDesigner LV4[80] = {{1,0,2, 0},{1,0,3, 0},{1,0,4, 0},{1,0,5, 0},{1,0,6, 0},{1,0,7, 0},{1,0,8, 0},{1,0,9, 0},
                          {1,3,2, 2},{1,3,3, 2},{1,3,4, 2},{1,3,5, 2},{1,3,6, 2},{1,3,7, 2},{1,3,8, 2},{1,3,9, 2}
                          ,{1,1,2, 4},{1,1,3, 4},{1,1,4, 4},{1,1,5, 4},{1,1,6, 4},{1,1,7, 4},{1,1,8, 4},{1,1,9, 4}
                          ,{1,2,2, 6},{1,2,3, 6},{1,2,4, 6},{1,2,5, 6},{1,2,6, 6},{1,2,7, 6},{1,2,8, 6},{1,2,9, 6}
                          ,{1,0,2, 8},{1,0,3, 8},{1,0,4, 8},{1,0,5, 8},{1,0,6, 8},{1,0,7, 8},{1,0,8, 8},{1,0,9, 8}
                          ,{1,1,2, 10},{1,1,3, 10},{1,1,4, 10},{1,1,5, 10},{1,1,6, 10},{1,1,7, 10},{1,1,8, 10},{1,1,9, 10}
                          ,{1,3,2, 12},{1,3,3, 12},{1,3,4, 12},{1,3,5, 12},{1,3,6, 12},{1,3,7, 12},{1,3,8, 12},{1,3,9, 12}
                          ,{1,2,2, 14},{1,2,3, 14},{1,2,4, 14},{1,2,5, 14},{1,2,6, 14},{1,2,7, 14},{1,2,8, 14},{1,2,9, 14}
                          ,{1,0,2, 16},{1,0,3, 16},{1,0,4, 16},{1,0,5, 16},{1,0,6, 16},{1,0,7, 16},{1,0,8, 16},{1,0,9, 16}
                          ,{1,1,2, 18},{1,1,3, 18},{1,1,4, 18},{1,1,5, 18},{1,1,6, 18},{1,1,7, 18},{1,1,8, 18},{1,1,9, 18}};

  LevelDesigner LV5[120] = {{1,0,15, 8},{1,0,15, 11}
                            ,{1,0,14, 8},{1,0,14, 11}
                            ,{1,0,13, 7},{1,0,13, 12},{1,0,13, 5},{1,0,13, 14}
                            ,{1,0,12, 7},{1,0,12, 12},{1,0,12, 5},{1,0,12, 14}
                            ,{1,0,11, 5},{1,0,11, 7},{1,0,11, 8},{1,0,11, 9},{1,0,11, 10},{1,0,11, 11},{1,0,11, 12},{1,0,11, 14},
    {1,0,10, 5},{1,0,10, 7},{1,0,10, 8},{1,0,10, 9},{1,0,10, 10},{1,0,10, 11},{1,0,10, 12},{1,0,10, 14},{1,0,10, 13},{1,0,10, 6},
    {1,0,9, 5},{1,0,9, 7},{1,0,9, 8},{1,0,9, 9},{1,0,9, 10},{1,0,9, 11},{1,0,9, 12},{1,0,9, 14},{1,0,9, 13},{1,0,9, 6},
    {1,0,8, 5},{1,0,8, 7},{1,0,8, 8},{1,0,8, 9},{1,0,8, 10},{1,0,8, 11},{1,0,8, 12},{1,0,8, 14},{1,0,8, 13},{1,0,8, 6},
    {1,0,6, 7},{1,1,6, 8},{1,0,6, 9},{1,0,6, 10},{1,1,6, 11},{1,0,6, 12},{1,0,6, 13},{1,0,6, 6},
    {1,0,7, 7},{1,1,7, 8},{1,0,7, 9},{1,0,7, 10},{1,1,7, 11},{1,0,7, 12},{1,0,7, 13},{1,0,7, 6},
    {1,0,5, 7},{1,0,5, 8},{1,0,5, 9},{1,0,5, 10},{1,0,5, 11},{1,0,5, 12},
    {1,0,4, 7},{1,0,4, 8},{1,0,4, 9},{1,0,4, 10},{1,0,4, 11},{1,0,4, 12},
    {1,0,3, 8},{1,0,3, 11},
    {1,0,2, 8},{1,0,2, 11},
    {1,3,1, 7},{1,3,1, 12},
    {1,3,0, 7},{1,3,0, 12},};

  CurrentScreen current_screen = MAIN_MENU_SCREEN;

  int player_score = 0;
  int player_ammo = 3;
  int player_lives = 5;
  int paddle_scale_modifier = 0;

  int curr_level = 0;
  bool ready_to_draw;
  bool lock_ball = true;
  bool end_game = true;
  bool shoot = false; // true if it can be shot and no other bullet is present in the scene
};

#endif // BREAKOUT_GAME_H

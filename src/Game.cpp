#include "Game.h"
#include <iostream>
#include <string>
#include <cmath>

#define BETWEEN(value, min, max) (value <= max && value >= min)

Game::Game(sf::RenderWindow& game_window): window(game_window)
{
  srand(time(NULL));
}
Game::~Game()
{}

bool Game::init()
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))  //loading font
  {
    std::cout << "font did not load \n";
  }

#pragma region setstring

  life_display.setFillColor(sf::Color(255,255,255,140));
  life_display.setFont(font);
  life_display.setCharacterSize(20);
  life_display.setPosition(0, window.getSize().y - 200);

  ammo_display.setFillColor(sf::Color(255,255,255,140));
  ammo_display.setFont(font);
  ammo_display.setCharacterSize(20);
  ammo_display.setPosition(0, window.getSize().y - 100);

  score_display.setFillColor(sf::Color(255,255,255,140));
  score_display.setFont(font);
  score_display.setCharacterSize(20);
  score_display.setPosition(window.getSize().x/2, window.getSize().y - 200);

  game_start_display.setString("Press enter to launch the ball\nPress esc at any time to go back\n\nYou can use 'A' and 'D' to choose\nA general direction to start from\n\nRemember to pick up buffs but avoid debuffs\nand you can use 'Space' to shoot");
  game_start_display.setFillColor(sf::Color(255,255,255,140));
  game_start_display.setFont(font);
  game_start_display.setCharacterSize(20);
  game_start_display.setPosition(window.getSize().x - game_start_display.getGlobalBounds().width - 30, window.getSize().y -300);

  //---------------------------------------------------------------------------------------------------------------------------------------

  start_text_menu.setString("Click on me to start the game");
  start_text_menu.setFillColor(sf::Color(255,255,255,255));
  start_text_menu.setFont(font);
  start_text_menu.setCharacterSize(20);
  start_text_menu.setPosition(window.getSize().x - start_text_menu.getGlobalBounds().width*2, window.getSize().y/8);

  levels_text_menu.setString("Choose the level");
  levels_text_menu.setFillColor(sf::Color(255,255,255,255));
  levels_text_menu.setFont(font);
  levels_text_menu.setCharacterSize(20);
  levels_text_menu.setPosition( levels_text_menu.getGlobalBounds().width * 2, window.getSize().y/8);

  description_text_menu.setString("                                           Use the mouse to select things\n\nYou can press the 'Esc' key to come back to the main menu at any time\n\nYou have a max of 5 lives and you will gain 1 for every level you beat\n\n"
                                  "                                         Pick ups list:"
                                  "\n                                           Grey ball = + 1 bullet"
                                  "\n                                           Blue ball = Spawns a new ball"
                                  "\n                                           Red paddle = scales down paddle"
                                  "\n                                           Blue paddle = scales up paddle"
                                  "\n                                           Gold diamond = 400"
                                  "\n                                           Red diamond = 200 points");
  description_text_menu.setFillColor(sf::Color(255,255,255,255));
  description_text_menu.setFont(font);
  description_text_menu.setCharacterSize(20);
  description_text_menu.setPosition(window.getSize().x/2 - description_text_menu.getGlobalBounds().width / 2, window.getSize().y/1.2 - description_text_menu.getGlobalBounds().height);

  //-----------------------------------------------------------------------------------------

  description_text_levelsel.setString("Choose the level you want to play");
  description_text_levelsel.setCharacterSize(20);
  description_text_levelsel.setFillColor(sf::Color(255,255,255,255));
  description_text_levelsel.setFont(font);
  description_text_levelsel.setPosition(window.getSize().x/2 -(description_text_levelsel.getGlobalBounds().width/2) , 0);

  back_text_levelsel.setString("Return to the main menu");
  back_text_levelsel.setFillColor(sf::Color(255,255,255,255));
  back_text_levelsel.setFont(font);
  back_text_levelsel.setCharacterSize(20);
  back_text_levelsel.setPosition(window.getSize().x/2 - (back_text_levelsel.getGlobalBounds().width/2), window.getSize().y - back_text_levelsel.getGlobalBounds().height * 2);

  LV1_levelsel.setString("Play level 1");
  LV1_levelsel.setFillColor(sf::Color(255,255,255,255));
  LV1_levelsel.setFont(font);
  LV1_levelsel.setCharacterSize(20);
  LV1_levelsel.setPosition(window.getSize().x/2 - (LV1_levelsel.getGlobalBounds().width/2), 150);

  LV2_levelsel.setString("Play level 2");
  LV2_levelsel.setFillColor(sf::Color(255,255,255,255));
  LV2_levelsel.setFont(font);
  LV2_levelsel.setCharacterSize(20);
  LV2_levelsel.setPosition(window.getSize().x/2 - (LV2_levelsel.getGlobalBounds().width/2), 300);

  LV3_levelsel.setString("Play level 3");
  LV3_levelsel.setFillColor(sf::Color(255,255,255,255));
  LV3_levelsel.setFont(font);
  LV3_levelsel.setCharacterSize(20);
  LV3_levelsel.setPosition(window.getSize().x/2 - LV3_levelsel.getGlobalBounds().width/2, 450);

  LV4_levelsel.setString("Play level 4");
  LV4_levelsel.setFillColor(sf::Color(255,255,255,255));
  LV4_levelsel.setFont(font);
  LV4_levelsel.setCharacterSize(20);
  LV4_levelsel.setPosition(window.getSize().x/2 - LV3_levelsel.getGlobalBounds().width/2, 600);

  LV5_levelsel.setString("Play level 5");
  LV5_levelsel.setFillColor(sf::Color(255,255,255,255));
  LV5_levelsel.setFont(font);
  LV5_levelsel.setCharacterSize(20);
  LV5_levelsel.setPosition(window.getSize().x/2 - LV3_levelsel.getGlobalBounds().width/2, 750);

  //-------------------------------------------------------------------------------------------------------------------

  game_ending_description.setString("this is a description");
  game_ending_description.setFillColor(sf::Color(255,255,255,255));
  game_ending_description.setFont(font);
  game_ending_description.setCharacterSize(20);
  game_ending_description.setPosition(window.getSize().x/2 - game_ending_description.getGlobalBounds().width/2, window.getSize().y/6);

  game_ending_menu.setString("Go back to the menu");
  game_ending_menu.setFillColor(sf::Color(255,255,255,255));
  game_ending_menu.setFont(font);
  game_ending_menu.setCharacterSize(20);
  game_ending_menu.setPosition(100, window.getSize().y/1.5);

  game_ending_start.setString("Start from the beginning");
  game_ending_start.setFillColor(sf::Color(255,255,255,255));
  game_ending_start.setFont(font);
  game_ending_start.setCharacterSize(20);
  game_ending_start.setPosition(window.getSize().x - game_ending_start.getGlobalBounds().width - 100, window.getSize().y/1.5);

#pragma endregion

  paddle = new MovableObj("Data/Images/paddleBlue.png");
  resetStats();

  return true;
}

void Game::update(float dt)
{
  if (current_screen == GAME_SCREEN)
  {
    score_display.setString(to_string(player_score));
    score_display.setPosition(window.getSize().x/2 - (score_display.getGlobalBounds().width/2), window.getSize().y - 200);

    life_display.setString("Lives left: "+ to_string(player_lives));
    ammo_display.setString("Ammo left: "+ to_string(player_ammo));

    end_game = true;

    if (shoot)
      bullet->getSprite()->move(bullet->direction.x * bullet->speed * dt, bullet->direction.y * bullet->speed * dt);


    switch (paddle_scale_modifier)
    {
      case -2:
        paddle->getSprite()->setScale(0.8f,1);
        break;
      case -1:
        paddle->getSprite()->setScale(0.9f,1);
        break;

      case 0:
        paddle->getSprite()->setScale(1,1);
        break;

      case 1:
        paddle->getSprite()->setScale(1.1,1);
        break;
      case 2:
        paddle->getSprite()->setScale(1.3,1);
        break;
      case 3:
        paddle->getSprite()->setScale(1.5,1);
        break;
    }

    if (player_lives < 0)
    {
      game_ending_description.setString("You have lost due to losing all of your lives at your disposal");
      game_ending_description.setPosition(window.getSize().x/2 - game_ending_description.getGlobalBounds().width/2, window.getSize().y/6);

      score_display.setString("You ended with a score of " + to_string(player_score));
      score_display.setPosition(window.getSize().x/2 - (score_display.getGlobalBounds().width/2), window.getSize().y - 200);
      current_screen = END_GAME_SCREEN;
    }

    for (int i = 0; i < balls.size(); ++i)
    {
      balls[i]->direction.normalise();
      balls[i]->getSprite()->move(balls[i]->direction.x * balls[i]->speed * dt, balls[i]->direction.y * balls[i]->speed * dt);
    }

    for (int i = 0; i < pick_ups.size(); ++i)
    {
      pick_ups[i]->getSprite()->move(0, pick_ups[i]->direction.y * pick_ups[i]->speed * dt);
    }

    if (!lock_ball)
    {
      paddle->getSprite()->move(paddle->direction.x * paddle->speed * dt, paddle->direction.y * paddle->speed * dt);

      sf::Time elapsed1 = clock.getElapsedTime();
      if (elapsed1 > second)
      {
        clock.restart();
        pickUpSpawn(rand() % 1200, -20);
      }
    }

    collisionCheck();

    if (ready_to_draw)
    {
      for (auto & i : current_level_vector)
      {
        if (i.show == 1)
        {
          end_game = false;
          break;
        }
      }

     if (balls.size() == 0 && !lock_ball)
     {
       player_lives--;

       while (pick_ups.size() != 0)
       {
         delete pick_ups[pick_ups.size() -1];
         pick_ups.erase(pick_ups.begin() + (pick_ups.size() -1));
       }

       lock_ball = true;
       paddle->getSprite()->setPosition(window.getSize().x / 2 - (paddle->getSprite()->getGlobalBounds().width/2), window.getSize().y - (paddle->getSprite()->getGlobalBounds().height));
       paddle_scale_modifier = 0;
     }

      if (end_game)
      {
        levelSetup(curr_level + 1);

        while (balls.size() != 0)
        {
          delete balls[balls.size() -1];
          balls.erase(balls.begin() + (balls.size() -1));
        }
        while (pick_ups.size() != 0)
        {
          delete pick_ups[pick_ups.size() -1];
          pick_ups.erase(pick_ups.begin() + (pick_ups.size() -1));
        }

        lock_ball = true;
        addLife();
      }
    }
  }
}
void Game::collisionCheck()
{
  for (int i = 0; i < balls.size(); ++i)
  {
    #pragma region ball_bounding_box
    int x_max = balls[i]->getSprite()->getPosition().x + balls[i]->getSprite()->getGlobalBounds().width;
    int x_min = balls[i]->getSprite()->getPosition().x;
    int y_min = balls[i]->getSprite()->getPosition().y;
    int y_max = balls[i]->getSprite()->getPosition().y + balls[i]->getSprite()->getGlobalBounds().height;

    int mid_ball_x = round((x_max + x_min)/2);
    int mid_ball_y = round((y_max + y_min)/2);

    #pragma endregion

    #pragma region paddle_ball_interaction
    if (y_max  >= paddle->getSprite()->getPosition().y )  //left paddle hit checks
    {
      //head on
      if ((x_min >= paddle->getSprite()->getPosition().x) && (x_max <= paddle->getSprite()->getPosition().x + paddle->getSprite()->getGlobalBounds().width))// works
      {

        if (paddle->direction.x < 0)
        {
          if (balls[i]->direction.x > 0)
          {
            balls[i]->speed *= 0.95;
            balls[i]->direction.x -= (balls[i]->direction.x * 0.15f);
          }

          else if (balls[i]->direction.x < 0)
          {
            balls[i]->speed *= 1.15;
            balls[i]->direction.x += (balls[i]->direction.x * 0.15f);
          }
        }
        else if (paddle->direction.x > 0)
        {
          if (balls[i]->direction.x < 0)
          {
            balls[i]->speed *= 0.95;
            balls[i]->direction.x -= (balls[i]->direction.x * 0.15f);
          }

          else if (balls[i]->direction.x > 0)
          {
            balls[i]->speed *= 1.15;
            balls[i]->direction.x += (balls[i]->direction.x * 0.15f);
          }

        }
        balls[i]->direction.y *= -1;
      }
        //corner hit 1
      else if ((x_min < paddle->getSprite()->getPosition().x) && (x_max>= paddle->getSprite()->getPosition().x))
      {
        if(balls[i]->direction.x < 0 && balls[i]->direction.y > 0)
        {
          balls[i]->direction.y *= -1;
        }
        else
        {
          balls[i]->direction.x *= -1;
          balls[i]->direction.y *= -1;
        }
      }
        //corner hit 2
      else if ((x_min <= paddle->getSprite()->getPosition().x + paddle->getSprite()->getGlobalBounds().width) && (x_max > paddle->getSprite()->getPosition().x +paddle->getSprite()->getGlobalBounds().width))
      {
        if(balls[i]->direction.x > 0 && balls[i]->direction.y > 0)
        {
          balls[i]->direction.y *= -1;
        }
        else
        {
          balls[i]->direction.x *= -1;
          balls[i]->direction.y *= -1;
        }
      }
    }
    #pragma endregion

    #pragma region ball_screen_interactions
    if (shoot)
    {
      if (bullet->getSprite()->getPosition().y <= 0)
      {
        delete bullet;
        shoot = false;
      }
    }

    if (x_min <= 0)    //left collision
      balls[i]->direction.x = 1;

    else if (x_max >= window.getSize().x)    // right collision
      balls[i]->direction.x = -1;

    else if (y_min <= 0)     //top collision
      balls[i]->direction.y = 1;

    else if (y_max >= window.getSize().y  - (paddle->getSprite()->getGlobalBounds().height/2) )   //bottom collision
    {
      delete balls[i];
      balls.erase(balls.begin() + i);
    }
    #pragma endregion

    #pragma region ball_brick_interactions
    if (ready_to_draw)
    {
      for (int x = 0; x < current_level_vector.size(); ++x)
      {
        if (current_level_vector[x].show == 1)
        {
          if (shoot)
          {
            if (bullet->getSprite()->getGlobalBounds().intersects(brick_array[x].getSprite()->getGlobalBounds()))
            {
              player_score += 50;
              current_level_vector[x].show = 0;
              delete bullet;
              shoot = false;
            }
          }

          if (balls[i]->getSprite()->getGlobalBounds().intersects(brick_array[x].getSprite()->getGlobalBounds()))
          {
            int mid_brick_x = round(((brick_array[x].getSprite()->getPosition().x) + (brick_array[x].getSprite()->getPosition().x + brick_array[x].getSprite()->getGlobalBounds().width))/2);
            int mid_brick_y = round(((brick_array[x].getSprite()->getPosition().y) + (brick_array[x].getSprite()->getPosition().y + brick_array[x].getSprite()->getGlobalBounds().height))/2);

            int mid_x_diff = mid_brick_x - mid_ball_x;
            int mid_y_diff = mid_brick_y - mid_ball_y;

            if (BETWEEN(mid_x_diff, -47, -36))
            {
              balls[i]->direction.x = 1;
              current_level_vector[x].show = 0;
              player_score += 100;
              pickUpSpawn(mid_brick_x ,brick_array[x].getSprite()->getPosition().y);
            }

            else if (BETWEEN(mid_x_diff, 36, 47))
            {
              balls[i]->direction.x = -1;
              current_level_vector[x].show = 0;
              player_score += 100;
              pickUpSpawn(mid_brick_x ,brick_array[x].getSprite()->getPosition().y);
            }

            else if (BETWEEN(mid_y_diff, 20, 31))
            {
              balls[i]->direction.y = -1;
              current_level_vector[x].show = 0;
              player_score += 100;
              pickUpSpawn(mid_brick_x ,brick_array[x].getSprite()->getPosition().y);
            }

            else if (BETWEEN(mid_y_diff, -31, -20))
            {
              balls[i]->direction.y = 1;
              current_level_vector[x].show = 0;
              player_score += 100;
              pickUpSpawn(mid_brick_x ,brick_array[x].getSprite()->getPosition().y);
            }
          }
        }
      }
    }
    #pragma endregion
  }

  #pragma region paddle_pickup_interactions
  for (int i = 0; i < pick_ups.size(); ++i)
  {
    if (paddle->getSprite()->getGlobalBounds().intersects(pick_ups[i]->getSprite()->getGlobalBounds()))
    {
      pickUpEffect(pick_ups[i]->pick_up_type);
      delete pick_ups[i];
      pick_ups.erase(pick_ups.begin() + i);
    }

    if (pick_ups[i]->getSprite()->getPosition().y + pick_ups[i]->getSprite()->getGlobalBounds().height/2  >= window.getSize().y)   //bottom collision
    {
      delete pick_ups[i];
      pick_ups.erase(pick_ups.begin() + i);
    }
  }
  #pragma endregion

  // clamping of the paddle
  if (paddle->getSprite()->getPosition().x < 0)
  {
    paddle->direction.x = 0;
    paddle->getSprite()->setPosition(0,window.getSize().y - paddle->getSprite()->getGlobalBounds().height);
  }
  else if (paddle->getSprite()->getPosition().x  > window.getSize().x - paddle->getSprite()->getGlobalBounds().width)
  {
    paddle->direction.x = 0;
    paddle->getSprite()->setPosition(window.getSize().x -paddle->getSprite()->getGlobalBounds().width ,window.getSize().y - paddle->getSprite()->getGlobalBounds().height);
  }
}
void Game::render()
{
  switch(current_screen) {
    case MAIN_MENU_SCREEN:
      window.draw (start_text_menu);
      window.draw (levels_text_menu);
      window.draw (description_text_menu);
      break;

    case LEVEL_SELECTION_SCREEN:
      window.draw(description_text_levelsel);
      window.draw(LV1_levelsel);
      window.draw(LV2_levelsel);
      window.draw(LV3_levelsel);
      window.draw(LV4_levelsel);
      window.draw(LV5_levelsel);
      window.draw(back_text_levelsel);
      break;

    case END_GAME_SCREEN:
      window.draw(game_ending_description);
      window.draw(game_ending_menu);
      window.draw(game_ending_start);
      window.draw(score_display);
      break;

    case GAME_SCREEN:
      window.draw(*paddle->getSprite());
      window.draw(score_display);
      window.draw(life_display);
      window.draw(ammo_display);

      for (int i = 0; i < balls.size(); ++i)
      {
        window.draw(*balls[i]->getSprite());
      }

      if (shoot)
      {
        window.draw(*bullet->getSprite());
      }

      if (lock_ball)
      {
        window.draw(game_start_display);
      }
      if (ready_to_draw)
      {
        for (int i = 0; i < current_level_vector.size(); ++i)
        {
          if (current_level_vector[i].show == 1)
          {
            window.draw(*(brick_array[i].getSprite()));
          }
        }
      }

      for (int i = 0; i < pick_ups.size(); ++i)
      {
        window.draw(*pick_ups[i]->getSprite());
      }
      break;
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

  switch(current_screen)
  {
    case MAIN_MENU_SCREEN:
      if ((click.x >= start_text_menu.getPosition().x && click.x <= start_text_menu.getPosition().x +
                      start_text_menu.getGlobalBounds().width)
          && (click.y >= start_text_menu.getPosition().y && click.y <= start_text_menu.getPosition().y + start_text_menu.getGlobalBounds().height))
      {
        current_screen = GAME_SCREEN;
        levelSetup(1);
      }

      if ((click.x >= levels_text_menu.getPosition().x && click.x <= levels_text_menu.getPosition().x +
                      levels_text_menu.getGlobalBounds().width)
          && (click.y >= levels_text_menu.getPosition().y && click.y <= levels_text_menu.getPosition().y +
                      levels_text_menu.getGlobalBounds().height))
      {
        current_screen = LEVEL_SELECTION_SCREEN;
      }
      break;

    case LEVEL_SELECTION_SCREEN:
      if ((click.x >= back_text_levelsel.getPosition().x && click.x <= back_text_levelsel.getPosition().x +back_text_levelsel.getGlobalBounds().width)
          && (click.y >= back_text_levelsel.getPosition().y && click.y <= back_text_levelsel.getPosition().y + back_text_levelsel.getGlobalBounds().height))
      {
        current_screen = MAIN_MENU_SCREEN;
        resetStats();
      }

      if ((click.x >= LV1_levelsel.getPosition().x && click.x <= LV1_levelsel.getPosition().x + LV1_levelsel.getGlobalBounds().width)
          && (click.y >= LV1_levelsel.getPosition().y && click.y <= LV1_levelsel.getPosition().y + LV1_levelsel.getGlobalBounds().height))
      {
        levelSetup(1);
        current_screen = GAME_SCREEN;
      }

      if ((click.x >= LV2_levelsel.getPosition().x && click.x <= LV2_levelsel.getPosition().x +LV2_levelsel.getGlobalBounds().width)
          && (click.y >= LV2_levelsel.getPosition().y && click.y <= LV2_levelsel.getPosition().y + LV2_levelsel.getGlobalBounds().height))
      {
        levelSetup(2);
        current_screen = GAME_SCREEN;
      }

      if ((click.x >= LV3_levelsel.getPosition().x && click.x <= LV3_levelsel.getPosition().x +LV3_levelsel.getGlobalBounds().width)
          && (click.y >= LV3_levelsel.getPosition().y && click.y <= LV3_levelsel.getPosition().y + LV3_levelsel.getGlobalBounds().height))
      {
        levelSetup(3);
        current_screen = GAME_SCREEN;
      }

      if ((click.x >= LV4_levelsel.getPosition().x && click.x <= LV4_levelsel.getPosition().x +LV4_levelsel.getGlobalBounds().width)
          && (click.y >= LV4_levelsel.getPosition().y && click.y <= LV4_levelsel.getPosition().y + LV4_levelsel.getGlobalBounds().height))
      {
        levelSetup(4);
        current_screen = GAME_SCREEN;
      }


      if ((click.x >= LV5_levelsel.getPosition().x && click.x <= LV5_levelsel.getPosition().x +LV5_levelsel.getGlobalBounds().width)
          && (click.y >= LV5_levelsel.getPosition().y && click.y <= LV5_levelsel.getPosition().y + LV5_levelsel.getGlobalBounds().height))
      {
        levelSetup(5);
        current_screen = GAME_SCREEN;
      }
      break;

    case END_GAME_SCREEN:
      if ((click.x >= game_ending_start.getPosition().x && click.x <= game_ending_start.getPosition().x +
                      game_ending_start.getGlobalBounds().width)
          && (click.y >= game_ending_start.getPosition().y && click.y <= game_ending_start.getPosition().y +
                      game_ending_start.getGlobalBounds().height))
      {
        levelSetup(1);
        current_screen = GAME_SCREEN;
        resetStats();
      }

      if ((click.x >= game_ending_menu.getPosition().x && click.x <= game_ending_menu.getPosition().x +
                      game_ending_menu.getGlobalBounds().width)
          && (click.y >= game_ending_menu.getPosition().y && click.y <= game_ending_menu.getPosition().y +
                      game_ending_menu.getGlobalBounds().height))
      {
        current_screen = MAIN_MENU_SCREEN;
        resetStats();
      }

      break;
  }
}
void Game::mousePos(sf::Event event)
{
  sf::Vector2i position = sf::Mouse::getPosition(window); // position of the cursor

  switch(current_screen)
  {
    case MAIN_MENU_SCREEN:

      if ((position.x >= levels_text_menu.getPosition().x && position.x <= levels_text_menu.getPosition().x + levels_text_menu.getGlobalBounds().width)&& (position.y >= levels_text_menu.getPosition().y && position.y <= levels_text_menu.getPosition().y + levels_text_menu.getGlobalBounds().height))
        levels_text_menu.setString("<Choose the level>");
      else
        levels_text_menu.setString("Choose the level");

      if ((position.x >= start_text_menu.getPosition().x && position.x <= start_text_menu.getPosition().x +start_text_menu.getGlobalBounds().width)&& (position.y >= start_text_menu.getPosition().y && position.y <= start_text_menu.getPosition().y +start_text_menu.getGlobalBounds().height))
        start_text_menu.setString("<Click on me to start the game>");
      else
        start_text_menu.setString("Click on me to start the game");

      break;

    case LEVEL_SELECTION_SCREEN:

      if ((position.x >= back_text_levelsel.getPosition().x && position.x <= back_text_levelsel.getPosition().x + back_text_levelsel.getGlobalBounds().width)&& (position.y >= back_text_levelsel.getPosition().y && position.y <= back_text_levelsel.getPosition().y +back_text_levelsel.getGlobalBounds().height))
        back_text_levelsel.setString("<Return to the main menu>");
      else
        back_text_levelsel.setString("Return to the main menu");

      if ((position.x >= LV1_levelsel.getPosition().x && position.x <= LV1_levelsel.getPosition().x + LV1_levelsel.getGlobalBounds().width)&& (position.y >= LV1_levelsel.getPosition().y && position.y <= LV1_levelsel.getPosition().y +LV1_levelsel.getGlobalBounds().height))
        LV1_levelsel.setString("<Play level 1>");
      else
        LV1_levelsel.setString("Play level 1");

      if ((position.x >= LV2_levelsel.getPosition().x && position.x <= LV2_levelsel.getPosition().x + LV2_levelsel.getGlobalBounds().width)&& (position.y >= LV2_levelsel.getPosition().y && position.y <= LV2_levelsel.getPosition().y + LV2_levelsel.getGlobalBounds().height))
        LV2_levelsel.setString("<Play level 2>");
      else
        LV2_levelsel.setString("Play level 2");

      if ((position.x >= LV3_levelsel.getPosition().x && position.x <= LV3_levelsel.getPosition().x + LV3_levelsel.getGlobalBounds().width)&& (position.y >= LV3_levelsel.getPosition().y && position.y <= LV3_levelsel.getPosition().y + LV3_levelsel.getGlobalBounds().height))
        LV3_levelsel.setString("<Play level 3>");
      else
        LV3_levelsel.setString("Play level 3");

      if ((position.x >= LV4_levelsel.getPosition().x && position.x <= LV4_levelsel.getPosition().x + LV4_levelsel.getGlobalBounds().width)&& (position.y >= LV4_levelsel.getPosition().y && position.y <= LV4_levelsel.getPosition().y + LV4_levelsel.getGlobalBounds().height))
        LV4_levelsel.setString("<Play level 4>");
      else
        LV4_levelsel.setString("Play level 4");

      if ((position.x >= LV5_levelsel.getPosition().x && position.x <= LV5_levelsel.getPosition().x + LV5_levelsel.getGlobalBounds().width)&& (position.y >= LV5_levelsel.getPosition().y && position.y <= LV5_levelsel.getPosition().y + LV5_levelsel.getGlobalBounds().height))
        LV5_levelsel.setString("<Play level 5>");

      else
        LV5_levelsel.setString("Play level 5");

      break;

    case END_GAME_SCREEN:
      if ((position.x >= game_ending_start.getPosition().x && position.x <= game_ending_start.getPosition().x +game_ending_start.getGlobalBounds().width)&& (position.y >= game_ending_start.getPosition().y && position.y <= game_ending_start.getPosition().y +game_ending_start.getGlobalBounds().height))
        game_ending_start.setString("<Start from the beginning>");
      else
        game_ending_start.setString("Start from the beginning");


      if ((position.x >= game_ending_menu.getPosition().x && position.x <= game_ending_menu.getPosition().x +game_ending_menu.getGlobalBounds().width)&& (position.y >= game_ending_menu.getPosition().y && position.y <= game_ending_menu.getPosition().y +game_ending_menu.getGlobalBounds().height))
        game_ending_menu.setString("<Go back to the menu>");
      else
        game_ending_menu.setString("Go back to the menu");

      break;
  }
}
void Game::keyPressed(sf::Event event)
{
  if (current_screen == GAME_SCREEN)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
      if (lock_ball)
      {
        balls.push_back(new MovableObj);
        driveBall(balls[balls.size() - 1]);
      }
      lock_ball = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
      if (lock_ball)
        paddle->getSprite()->setPosition(paddle->getSprite()->getPosition().x + 4,paddle->getSprite()->getPosition().y);

      else
        paddle->direction.x = 3;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
      if (lock_ball)
        paddle->getSprite()->setPosition(paddle->getSprite()->getPosition().x - 4,paddle->getSprite()->getPosition().y);

      else
        paddle->direction.x = -3;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      if (player_ammo > 0 && !shoot && !lock_ball)
      {
        player_ammo --;
        shoot = true;
        bullet = new MovableObj("Data/Images/ballGrey.png");
        bullet->speed = 400;
        bullet->direction.y = -1;
        bullet->direction.x = 0;
        bullet->getSprite()->setPosition( paddle->getSprite()->getPosition().x + paddle->getSprite()->getGlobalBounds().width/2 - bullet->getSprite()->getGlobalBounds().width/2, paddle->getSprite()->getPosition().y + 4);
      }
    }
  }

  if (current_screen != MAIN_MENU_SCREEN)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
      current_screen = MAIN_MENU_SCREEN;
      resetStats();
    }
  }
}
void Game::keyReleased(sf::Event event)
{
  paddle->direction.x = 0;
}

void Game::levelSetup(int level)
{
  ready_to_draw = false;
  current_level_vector.clear();
  curr_level = level;

  if (shoot)
  {
    delete bullet;
    shoot = false;
  }

  lock_ball = true;
  paddle->getSprite()->setPosition(window.getSize().x / 2 - (paddle->getSprite()->getGlobalBounds().width/2), window.getSize().y - (paddle->getSprite()->getGlobalBounds().height));

  addLife();

  switch(level)
  {
    case 1:
      for (const LevelDesigner& data : LV1)
        current_level_vector.push_back(data);

      levelCreation(current_level_vector);
      break;

    case 2:
      for (const LevelDesigner& data : LV2)
        current_level_vector.push_back(data);

      levelCreation(current_level_vector);
      break;

    case 3:
      for (const LevelDesigner& data : LV3)
        current_level_vector.push_back(data);

      levelCreation(current_level_vector);
      break;

    case 4:
      for (const LevelDesigner& data : LV4)
        current_level_vector.push_back(data);

      levelCreation(current_level_vector);
      break;

    case 5:
      for (const LevelDesigner& data : LV5)
        current_level_vector.push_back(data);

      levelCreation(current_level_vector);
      break;

    case 6: // one of the cases is an overflow for when there are no more levels, therefore the game ends with a victory
      game_ending_description.setString("You have won WOWWOWO! You beat all of the levels\nWould you like to start from the start or\nchoose a specific level");
      game_ending_description.setPosition(window.getSize().x/2 - game_ending_description.getGlobalBounds().width/2, window.getSize().y/6);

      score_display.setString("You ended with a score of " + to_string(player_score));
      score_display.setPosition(window.getSize().x/2 - (score_display.getGlobalBounds().width/2), window.getSize().y - 200);
      current_screen = END_GAME_SCREEN;
      break;
  }
}
void Game::levelCreation(std::vector<LevelDesigner> levelformat)
{
  if (brick_array != nullptr)
  {
    delete[] brick_array;
    brick_array = nullptr;
  }

  brick_array = new BrickMaker[levelformat.size()];

  for (int i = 0; i < levelformat.size(); ++i)
  {
    switch(levelformat[i].colour)    //set the colour
    {
      case 1:
        brick_array[i].setTexture(yellow_filename);
        break;

      case 2:
        brick_array[i].setTexture(green_filename);
        break;

      case 3:
        brick_array[i].setTexture(red_filename);
        break;
    }
    brick_array[i].getSprite()->setPosition(levelformat[i].coloum * 64,levelformat[i].row * 32);
  }
  ready_to_draw = true;
}

void Game::driveBall(MovableObj* ball)
{
  ball->getSprite()->setPosition((paddle->getSprite()->getPosition().x + paddle->getSprite()->getGlobalBounds().width/2) - ball->getSprite()->getGlobalBounds().width/2 ,window.getSize().y - ball->getSprite()->getGlobalBounds().height * 2.5);
  ball->direction.y = -1;
  ball->speed = 375;
  ball->direction.x =  (rand() % 10 -5) / 10.00;

  if (ball->direction.x == 0)
    driveBall(ball);
}
void Game::addLife()
{
  if (player_lives < 5)
    player_lives ++;
}
void Game::resetStats()
{
  player_score = 0;
  player_lives = 5;
  player_ammo = 3;
  paddle_scale_modifier = 0;
  paddle->getSprite()->setScale(1,1);

  while (balls.size() != 0)
  {
    delete balls[balls.size() -1];
    balls.erase(balls.begin() + (balls.size() -1));
  }
}

void Game::pickUpSpawn(int x,int y)
{
  int num = rand() % 3 + 1;

  if (num == 2)
  {
    num = rand() % 6 + 1;

    switch (num)
    {
      case 1:
        pick_ups.push_back(new MovableObj(drop_points_filename));
        break;
      case 2:
        pick_ups.push_back(new MovableObj(drop_mpoints_filename));
        break;

      case 3:
        pick_ups.push_back(new MovableObj(drop_bullet_filename));
        break;
      case 4:
        pick_ups.push_back(new MovableObj(drop_ball_filename));
        break;

      case 5:
        pick_ups.push_back(new MovableObj(drop_scalep_filename));
        break;
      case 6:
        pick_ups.push_back(new MovableObj(drop_scalem_filename));
        break;
    }

    pick_ups[pick_ups.size() - 1]->pick_up_type = num;
    pick_ups[pick_ups.size() - 1]->getSprite()->scale(0.7,0.7);
    pick_ups[pick_ups.size() - 1]->getSprite()->setPosition(x - pick_ups[pick_ups.size() - 1]->getSprite()->getGlobalBounds().width/2, y);
    pick_ups[pick_ups.size() - 1]->direction.y = 1;
  }
}
void Game::pickUpEffect(int type)
{
  switch (type)
  {
    case 1:
      player_score += 200;
      break;
    case 2:
      player_score += 400;
      break;

    case 3:
      player_ammo ++;
      break;
    case 4:
      balls.push_back(new MovableObj);
      driveBall(balls[balls.size() - 1]);
      break;

    case 5:
      if (paddle_scale_modifier < 3)
        paddle_scale_modifier ++;
      break;
    case 6:
      if (paddle_scale_modifier > -2)
        paddle_scale_modifier --;
      break;
  }
}

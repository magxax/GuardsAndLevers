
#ifndef H_LEVEL
#define H_LEVEL

#include <SFML/Graphics.hpp>
#include <memory>
#include <deque>
#include <random>

#include "Scene.hpp"
#include "WorldState.hpp"
#include "AnimationState.hpp"

class Inputs;

class Level : public Scene {
public:
  Level();

  void onKeyFirstPressed(Inputs& inputs, sf::Keyboard::Key key);
  // void onKeyReleased(Inputs& inputs, sf::Keyboard::Key key);
  // void onMbFirstPressed(Inputs& inputs, sf::Mouse::Button b, sf::Vector2f cursor);
  // void onMbReleased(Inputs& inputs, sf::Mouse::Button b, sf::Vector2f cursor);

  void update(Inputs& inputs);
  void display(sf::RenderTarget& window) const;

  using Rng = std::default_random_engine;

  using float_dice = std::uniform_real_distribution<float>;
  using double_dice = std::uniform_real_distribution<double>;
  using int_dice = std::uniform_int_distribution<int>;

private:
  void drawWorld(sf::RenderTarget& window) const;
  void playerMove(sf::Keyboard::Key key);
  UnitAction guardAi(size_t i) const;

  bool waitingForAnimations() const;

  WorldState m_world;
  AnimationState m_animations;

  std::vector<WorldState::Unit> m_units;

  std::deque<AnimationState> m_nextAnimations;
  time_t m_msTimeUntilNext = 0;
};

#endif // !H_LEVEL

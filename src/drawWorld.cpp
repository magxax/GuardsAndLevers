
#include <SFML/Graphics.hpp>
#include "WorldState.hpp"
#include "Level.hpp"

const sf::Vector2f tileSize = { 50.0f, 50.0f };

const sf::Color tileColors[(size_t)Tile::TileCount] = {
  sf::Color(0x303030FF),
  sf::Color(0x101010FF),
  sf::Color(0x0F0F2FFF),
  sf::Color(0x0000FFFF)
};

void Level::drawWorld(sf::RenderTarget& window) const {
  float x0 = 0;
  float y0 = 0;

  sf::RectangleShape rectangle;
  rectangle.setSize(tileSize);

  Pos worldSize = m_world.tiles.getSize();
  for (long x = 0; x < worldSize.x; ++x) {
    for (long y = 0; y < worldSize.y; ++y) {
      const Tile tileId = m_world.tiles.get(x, y);
      rectangle.setFillColor(tileColors[(size_t)tileId]);
      rectangle.setPosition(x0 + x * tileSize.x, y0 + y * tileSize.y);
      window.draw(rectangle);
    }
  }

  // ---
  // DRAW PLAYER AND GUARDS
  // ---

  sf::CircleShape circle;
  circle.setRadius(std::min(tileSize.x, tileSize.y) * 0.4f);
  circle.setPointCount(16);

  for (size_t i = 0; i < m_units.size(); ++i) {
    const WorldState::Unit& unit = m_units[i];

    circle.setFillColor(unit.color);

    sf::Vector2f basePos = {
      x0 + unit.pos->x * tileSize.x,
      y0 + unit.pos->y * tileSize.y
    };
    circle.setPosition(basePos);
    window.draw(circle);
  }
}

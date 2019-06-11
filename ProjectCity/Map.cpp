#include "map.h"

void Map::AddTileVertices (Tile tile, sf::Vector2f position) {
		vertexArray->append (*new sf::Vertex ((*new sf::Vector2f (0.f, 0.f) + position) * tileWorldDimension, 
							*new sf::Vector2f (tileTextureDimension * tile.getX(), tileTextureDimension * tile.getY())));
		vertexArray->append (*new sf::Vertex ((*new sf::Vector2f (1.f, 0.f) + position) * tileWorldDimension,
							*new sf::Vector2f (tileTextureDimension * tile.getX () + tileTextureDimension, tileTextureDimension * tile.getY ())));
		vertexArray->append (*new sf::Vertex ((*new sf::Vector2f (1.f, 1.f) + position) * tileWorldDimension, 
							*new sf::Vector2f (*new sf::Vector2f (tileTextureDimension * tile.getX () + tileTextureDimension, tileTextureDimension * tile.getY () + tileTextureDimension))));
		vertexArray->append (*new sf::Vertex ((*new sf::Vector2f (0.f, 1.f) + position) * tileWorldDimension,
							*new sf::Vector2f (*new sf::Vector2f (tileTextureDimension * tile.getX (), tileTextureDimension + tile.getY ()))));
}

Map::Map () {
}

Map::Map (sf::Texture tileset, int width, int height, float tileTextureDimension, float tileWorldDimension) {
		this->tileset = tileset;

		this->width = width;
		this->height = height;
		this->tileTextureDimension = tileTextureDimension;
		this->tileWorldDimension = tileWorldDimension;

		vertexArray = new sf::VertexArray (sf::PrimitiveType::Quads, (unsigned int)(width * height * 4));

		Tile *tile = new Tile (2, 4, sf::Color::White);

		for (int i = 0; i < width; i++) {
			for (int x = 0; x < height; x++) {
				AddTileVertices (*tile, *new sf::Vector2f((float) i, (float) x));
			}
		}
}

void Map::draw (sf::RenderTarget &target, sf::RenderStates states) const {
}
#ifndef MAPPOSITIONITERATOR_H_INCLUDED
#define MAPPOSITIONITERATOR_H_INCLUDED

#include <stdint.h>

#include "Map/Map.h"
#include "Map/MapPosition.h"

/**
* Hilfsklasse um �ber die Position einer Karte zu Iterieren.
*/
class MapPositionIterator {
	private:
		uint32_t position;
		const uint16_t mapWidth;

	public:
		MapPositionIterator(const Map& map) :
			position(0),
			mapWidth(map.getWidth()) {}

		MapPositionIterator(const Map& map, uint32_t position) :
			position(position),
			mapWidth(map.getWidth()) {}

		MapPositionIterator(const Map& map, const MapPosition& position) :
			position((uint32_t)position.getY() * (uint32_t)map.getWidth() + position.getX()),
			mapWidth(map.getWidth()) {}

		~MapPositionIterator() {};

		/// Geht einen Schritt nach Norden
		uint32_t toNorth() {
			return position += -mapWidth;
		}

		/// Geht einen Schritt nach NordOsten
		uint32_t toNorthEast() {
			return position += 1 - mapWidth;
		}

		/// Geht einen Schritt nach Osten
		uint32_t toEast() {
			return position += 1;
		}

		/// Geht einen Schritt nach S�dOsten
		uint32_t toSouthEast() {
			return position += 1 + mapWidth;
		}

		/// Geht einen Schritt nach S�den
		uint32_t toSouth() {
			return position += mapWidth;
		}

		/// Geht einen Schritt nach S�dWesten
		uint32_t toSouthWest() {
			return position += mapWidth - 1;
		}

		/// Geht einen Schritt nach Westen
		uint32_t toWest() {
			return position += -1;
		}

		/// Geht einen Schritt nach Westen
		uint32_t toNorthWest() {
			return position += -mapWidth - 1;
		}

		/// Gibt die aktuelle Position zur�ck
		uint32_t getPosition() const {
			return position;
		}

		/// Gibt die aktuelle X Position zur�ck
		uint16_t getX() const {
			return position % mapWidth;
		}

		/// Gibt die aktuelle Y Position zur�ck
		uint16_t getY() const {
			return position / mapWidth;
		}

		/// Setzt die Position
		void setPosition(uint32_t position) {
			this->position = position;
		}

		/// Setzt die Position �ber x und y Werte
		uint32_t setPosition(uint16_t x, uint16_t y) {
			return position = (uint32_t)y * (uint32_t)mapWidth + x;
		}

		/// Setzt die Position �ber ein MapPosition Objekt
		uint32_t setPosition(const MapPosition& position) {
			return setPosition(position.getX(), position.getY());
		}
};


#endif // MAPPOSITIONITERATOR_H_INCLUDED

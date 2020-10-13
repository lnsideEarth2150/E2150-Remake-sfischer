#ifndef MAPPOSITION_H_INCLUDED
#define MAPPOSITION_H_INCLUDED

#include <stdint.h>

class Map;

/**
* Stellt eine Position auf einer Karte da
*/
class MapPosition {
	private:
		uint16_t x;
		uint16_t y;

	public:
		/// Standardkonstruktur, erzeugt eine "InvalidPosition"
		MapPosition();

		/// Konstruktor
		MapPosition(uint16_t x, uint16_t y);

		/// Destruktor
		virtual ~MapPosition() {};

		bool operator<(const MapPosition& cc) const {
			return x < cc.getX() ? true : (x > cc.getX() ? false : (y < cc.getY()));
		}

		bool operator==(const MapPosition& other) const {
			return x == other.x && y == other.y;
		}

		bool operator!=(const MapPosition& other) const {
			return x != other.x || y != other.y;
		}

		/// Gibt die X-Position zur�ck
		uint16_t getX() const {
			return x;
		}

		/// Gibt die Y-Position zur�ck
		uint16_t getY() const {
			return y;
		}

		/// Setter
		void setX(uint16_t x) {this->x = x;}
		void setY(uint16_t y) {this->y = y;}
		void setXY(uint16_t x, uint16_t y) {this->x = x; this->y = y;}

		/// Pr�ft ob eine Position gesetzt wurde
		bool isValid() const;

		/// Pr�ft ob die Position auf einer bestimmten Karte g�ltig ist
		bool isValidOnMap(const Map& map) const;

		/// Pr�ft ob die Position innerhalb des "MapBorders" liegt
		bool isValidOnUsableMapArea(const Map& map) const;

		/// Verschiebt die Position auf die Kartenfl�che
		void makeValidOnMap(const Map& map);

		/// Gibt die kleinste Distanz zum Kartenrand auf der X-Achse zur�ck (Nicht dem nutzbaren Rand!)
		uint16_t getDistToMapBorderX(const Map& map) const;

		/// Gibt die kleinste Distanz zum Kartenrand auf der Y-Achse zur�ck (Nicht dem nutzbaren Rand!)
		uint16_t getDistToMapBorderY(const Map& map) const;

		/// Gibt die kleinste Distanz zum nutzbaren Kartenrand auf der X-Achse zur�ck
		uint16_t getDistToUseableMapBorderX(const Map& map) const;

		/// Gibt die kleinste Distanz zum nutzbaren Kartenrand auf der Y-Achse zur�ck
		uint16_t getDistToUseableMapBorderY(const Map& map) const;

		/// Gibt eine ung�ltige Position zur�ck (isValid == false)
		static MapPosition InvalidPosition() {
			return MapPosition();
		}
};

#endif

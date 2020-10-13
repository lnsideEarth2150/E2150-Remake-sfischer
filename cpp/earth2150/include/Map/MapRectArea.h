#ifndef MAPRECTAREA_H_INCLUDED
#define MAPRECTAREA_H_INCLUDED

#include "Map/MapPosition.h"

/**
* Definiert einen Rechteckigen Bereich auf der Spielkarte.
* Es werden Methoden bereitgestellt, um zu Pr�fen ob Punkte
* oder Bereiche innerhalb dieses Bereiches liegen.
*/
class MapRectArea {
	private:
		/// Erste Ecke, die kleinere im Wertebereich
		MapPosition minEdge;

		/// Zweite Position, ist >= der ersten Ecke
		MapPosition maxEdge;

		/// Stellt sicher, dass minEdge < maxEdge ist (X und Y)
		void repair();

	public:
		/// Standardkonstruktur, erzeugt eine ung�ltige Fl�che!
		MapRectArea();

		/// Definiert die Fl�che durch zwei Eckpunkte (Reihenfolge ist beliebig)
		MapRectArea(const MapPosition& pos1, const MapPosition& pos2);

		/// Definiert die Fl�che durch eine MinEcke sowie die Breite und L�nge
		MapRectArea(const MapPosition& pos, uint16_t width, uint16_t height);

		/// Definiert die Fl�che durch das Zentrum um einem Radius (ggf. auf Karte ung�ltig da > Width/Height)
		MapRectArea(const MapPosition& pos, uint16_t radius);

		/// Gibt die Ecke der kleineren Koorinaten zur�ck
		const MapPosition& getMinEdge() const {
			return minEdge;
		}

		/// Gibt die Ecke der gr��reren Koordinaten zur�ck
		const MapPosition& getMaxEdge() const {
			return maxEdge;
		}

		/// Gibt die Breite zur�ck (X-Achse)
		uint16_t getWidth() const {
			return (maxEdge.getX() - minEdge.getX()) + 1;
		}

		/// Gibt die H�he zur�ck (Y-Achse)
		uint16_t getHeight() const {
			return (maxEdge.getY() - minEdge.getY()) + 1;
		}

		/// Gibt die Anzahl an Feldern zur�ck (Die Fl�che)
		uint32_t getFieldCount() const {
			return (uint32_t)getWidth() * (uint32_t)getHeight();
		}

		/// Pr�ft ob eine Position innerhalb ist
		bool isInside(const MapPosition& position) const;

		/// Pr�ft ob eine andere Fl�che komplett innerhalb dieser ist
		bool isInside(const MapRectArea& area) const;

		/// Pr�ft ob das Gebiet auf der Karte g�ltig ist
		bool isValidOnMap(const Map& map) const;

		/// Pr�ft ob das Gebiet im nutzbaren Bereich der Karte liegt
		bool isValidOnUsableMapArea(const Map& map) const;

		/// Verschiebt die Eckpunkte auf den G�ltigen Bereich der Karte
		void makeValidOnMap(const Map& map);

};


#endif // MAPRECTAREA_H_INCLUDED

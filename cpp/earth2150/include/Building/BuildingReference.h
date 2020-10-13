#ifndef BUILDINGREFERENCE_H_INCLUDED
#define BUILDINGREFERENCE_H_INCLUDED

#include "Map/MapRectArea.h"

/**
* Einfache Referenz auf den Eintrag, welcher die konkreten Geb�udeinformationen
* enth�lt.
*/
class BuildingReference {
	private:
		uint32_t id;

		/// Referenz ID auf den Eintrag in der Geb�udeliste
		uint32_t refID;

		/// Die Grundfl�che des Geb�udes (muss nicht vollst�ndig genutzt sein)
		MapRectArea buildingArea;

	public:
		BuildingReference();
		BuildingReference(uint32_t id, uint32_t refID, const MapRectArea& area);
		~BuildingReference();

		/// Gibt die ID zur�ck
		uint32_t getID() const {
			return id;
		}

		/// Gibt die Referenz ID zur�ck
		uint32_t getRefID() const {
			return refID;
		}

		/// Setzt eine neue Referenz ID
		void setRefID(uint32_t newRefID) {
			this->id = newRefID;
		}

		/// Die Grundfl�che des Geb�udes
		const MapRectArea& BuildingArea() const {
			return buildingArea;
		}

		/// Die Grundfl�che des Geb�udes
		MapRectArea& BuildingArea() {
			return buildingArea;
		}

};


#endif // BUILDINGREFERENCE_H_INCLUDED

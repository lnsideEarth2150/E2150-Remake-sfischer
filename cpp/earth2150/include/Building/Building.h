#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED

#include "e2150/Entity.h"

/**
* Diese Klasse stellt eine Oberklasse f�r jegliches Geb�ude dar, welches in der Spielwelt erstellt wurde.
*/
class Building : public Entity {
	private:
		const BuildingTyp typ;

	protected:
		Building(BuildingTyp typ): typ(typ) {}

	public:
		/// Auflistung aller m�glichen Geb�udearten
		enum BuildingTyp {
			POWERSTATION,		// Kraftwerk
			HOMEBASE,			// Hauptbasis / Hauptgeb�ude
			FACTORY				// Fabrik
		};

		virtual ~Building();

		/// Gibt den Typ des Geb�udes zur�ck
		BuildingTyp getTyp() const { return typ; };

};

#endif // BUILDING_H_INCLUDED

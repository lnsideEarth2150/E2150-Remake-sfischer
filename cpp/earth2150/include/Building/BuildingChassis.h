#ifndef BUILDINGCHASSIS_H_INCLUDED
#define BUILDINGCHASSIS_H_INCLUDED

#include "Building/BuildingGround.h"

#include <string>

/**
* Stellt die Geb�ude Grundinformationen dar.
* Speichert Modell, Gr��e, Typ usw. des Geb�udes.
* Jedes Geb�ude das erstellt wird, bezieht sich auf ein
* Objekt dieser Klasse.
*/
class BuildingChassis {
	private:
		/// Objekt das die Bodenfl�che des Geb�udes bestimmt
		BuildingGround ground;

		/// Name des Chassis
		std::string name;

	public:
		BuildingChassis(uint8_t width, uint8_t height, const std::string& name);
		~BuildingChassis();

		/// Gibt den BuildingGround zur�ck, die Fl�chennutzung auf der Karte
		BuildingGround& getBuildingGround() {
			return ground;
		}

		/// Gibt den BuildingGround zur�ck, die Fl�chennutzung auf der Karte
		const BuildingGround& getBuildingGround() const {
			return ground;
		}

		/// Gibt den Namen des Geb�udes zur�ck
		const std::string& getName() const {
			return name;
		}

};

#endif // BUILDINGCHASSIS_H_INCLUDED

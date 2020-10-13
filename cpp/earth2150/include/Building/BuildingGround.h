#ifndef BUILDINGGROUND_H_INCLUDED
#define BUILDINGGROUND_H_INCLUDED

#include <stdint.h>
#include <memory.h>

class BuildingDirection;

class BuildingGround {
	private:
		/// Geb�ude Breite (X Achse)
		uint8_t width;

		/// Geb�ude H�he (Y Achse)
		uint8_t height;

		/// Array der Felder (siehe GroundType)
		uint8_t* field;

		/// Berechnet den Index in dem Feld-Array
		size_t getIndex(uint8_t x, uint8_t y) const;

		BuildingGround(const BuildingGround& cc);
		BuildingGround& operator=(const BuildingGround& cc);

	public:
		/// Definition der Bodenfl�chenarten
		enum GroundType {
			FIELD_FREE,	// Geb�ude blockiert/nutzt dieses Feld nicht
			FIELD_SOLID,	// Geb�ude steht auf diesem Feld
			FIELD_ENTRY	// Von/auf dieses Feld fahren Einheiten, welche mit dem Geb�ude interagieren
		};

		/// Konstruktor
		/// Erstellt die Untergrundfl�che f�r Geb�ude.
		/// Die Fl�che wird mit dem Wert startType initiiert.
		BuildingGround(uint8_t width, uint8_t height, GroundType startType = FIELD_SOLID);

		/// Destruktor
		~BuildingGround();

		/// Gibt die Breite der Bodenfl�che zur�ck
		uint8_t getWidth() const {
			return width;
		}

		/// Gibt die H�he der Bodenfl�che zur�ck
		uint8_t getHeight() const {
			return height;
		}

		/// Gibt den Typ der Bodenfl�che zur�ck
		GroundType getField(uint8_t x, uint8_t y) const;

		GroundType getField(uint8_t x, uint8_t y, const BuildingDirection& buildingDirection) const;

		/// Setzt den Typ eines Feldes
		void setField(uint8_t x, uint8_t y, GroundType type);

};

#endif // BUILDINGGROUND_H_INCLUDED

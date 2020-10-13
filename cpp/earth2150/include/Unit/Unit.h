#ifndef UNIT_H
#define UNIT_H

#include "e2150/Entity.h"
#include <list>

class UnitChassis;

class Unit : public Entity {
	private:
		/// Beschreibt den Status der Einheit, siehe FLAG_ Konstanten
		uint8_t statusFlags;

		/// Die Chassis aus welcher die Einheit besteht
		const UnitChassis& chassis;

		std::list<uint32_t> wayPoints;

	public:
		static const uint8_t FLAG_INBUILDING	= (1 << 0);
		static const uint8_t FLAG_ONMOVE		= (1 << 1);

		Unit(uint32_t id, const UnitChassis& chassis);
		virtual ~Unit();

		/**
		* Gibt an ob auf Spielerbefehle direkt reagiert werden kann
		* Nicht der fall wenn Einheit aus Werkshalle f�hrt, unter einfluss von Signalst�rern o.�. steht
		*/
		bool isControlable() const;

		/// Setzt ein Status-Bit f�r das angegebene Feld
		void setStatusFlag(uint8_t statusFlag, bool value);

		/// Gibt das Status-Bit des angegebenen Feldes zur�ck
		bool getStatusFlag(uint8_t statusFlag) const;

		/// Gibt das Chassis zur�ck, aus dem die Einheit besteht
		const UnitChassis& getChassis() const {return chassis;}

		/// Bewegt die Einheit ein Feld in die entsprechende Richtung
		void move(uint8_t direction);

		/// Setzt Wegpunkte welche die Einheit abfahren soll
		void setWay(const std::list<uint32_t> way) {wayPoints = way;};

		/// Gibt den n�chsten Wegpunkt aus der Wegliste zur�ck, und entfernt ihn
		uint32_t getNextWaypoint() const {return wayPoints.front();}

		/// Entfernt den aktuellen Wegpunkt aus der Liste (darauf ist der folgende der erste ...)
		void removeCurrentWaypoint() {wayPoints.pop_front();}

		/// Gibt die Anzahl der Wegpunkte zur�ck
		uint32_t countWaypoints() const {return wayPoints.size();}

		int32_t dumpData(char* buffer) const;
		uint32_t dumpDataSize() const;
};

#endif

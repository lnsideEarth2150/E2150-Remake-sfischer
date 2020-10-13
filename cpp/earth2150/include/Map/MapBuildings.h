#ifndef MAPBUILDINGS_H_INCLUDED
#define MAPBUILDINGS_H_INCLUDED

#include "Util/MemoryBlock.h"
#include "Building/BuildingReference.h"

#include <stdint.h>
#include <vector>

class IMapBuildingsObserver;

/**
* Verwaltet alle Geb�ude auf einer Map.
* Bietet eine Schnittstelle f�r Observer, welche �ber neue und entfernte Geb�ude
* informiert werden.
*/
class MapBuildings {
	private:
		/// Referenzliste der Geb�ude
		MemoryBlock<BuildingReference> buildings;

		/// Liste der Observer, welche �ber �nderungen Benachrichtigt werden sollen
		std::vector<IMapBuildingsObserver*> observers;

		MapBuildings(const MapBuildings&);
		MapBuildings operator=(const MapBuildings&);

	public:
		MapBuildings();
		~MapBuildings();

		/// Gibt die Anzahl an Geb�uden zur�ck
		uint32_t getCount() const;

		/// F�gt einen Observer in die Benachrichtigungsliste ein
		void attachObserver(IMapBuildingsObserver* observer);

		/// Entfernt einen Observer aus der Benachrichtigungsliste
		void detachObserver(IMapBuildingsObserver* observer);

};


#endif // MAPBUILDINGS_H_INCLUDED

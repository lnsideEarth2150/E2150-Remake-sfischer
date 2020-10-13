#ifndef IMAPBUILDINGSOBSERVER_H_INCLUDED
#define IMAPBUILDINGSOBSERVER_H_INCLUDED

/**
* Interface Klasse f�r einen Beobachter von Geb�uden.
* Soll dazu dienen, �ber hinzuf�gen und entfernen von Geb�uden Informiert zu werden.
*/
class IMapBuildingsObserver {
	private:
		IMapBuildingsObserver(const IMapBuildingsObserver&);
		IMapBuildingsObserver operator=(const IMapBuildingsObserver&);

	public:
		IMapBuildingsObserver();
		virtual ~IMapBuildingsObserver();

		/// Wird aufgerufen, wenn ein Geb�ude erstellt wird
		virtual void OnEvent_NewBuilding(const BuildingReference& buildingRef) = 0;

		/// Wird aufgerufen, wenn ein Geb�ude entfernt wird
		virtual void OnEvent_RemoveBuilding(const BuildingReference& buildingRef) = 0;

};


#endif // IMAPBUILDINGSOBSERVER_H_INCLUDED

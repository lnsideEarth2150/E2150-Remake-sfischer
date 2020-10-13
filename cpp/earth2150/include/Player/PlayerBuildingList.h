#ifndef PLAYERBUILDINGLIST_H_INCLUDED
#define PLAYERBUILDINGLIST_H_INCLUDED

#include <vector>
#include <stdint.h>

class GlobalBuildingList;
class BuildingChassis;

/**
* Liste der Geb�ude welche der Spieler bauen kann.
* Die Eintr�ge sind verwei�e auf die Eintr�ge der GlobalBuildingList.
*/
class PlayerBuildingList {
	private:
		PlayerBuildingList(const PlayerBuildingList&);
		PlayerBuildingList operator=(const PlayerBuildingList&);

		/// Referenz auf die Globale Geb�udeliste
		const GlobalBuildingList& globalBuildingList;

		std::vector<uint32_t> buildingIDs;

	public:
		PlayerBuildingList(const GlobalBuildingList& globalBuildingList);
		~PlayerBuildingList();

		/// F�gt ein Geb�ude �ber seine ID hinzu
		void addID(uint32_t id);

		/// Entfernt ein bestimmtes Geb�ude aus der Liste
		bool removeID(uint32_t id);

		/// Entfernt alle Geb�ude aus der Liste
		void removeAll();

		/// F�gt alle Verf�gbaren Geb�ude in die Liste ein
		void addAll();

		/// Gibt die Anzahl der Geb�ude zur�ck
		uint32_t getCount() const {
			return buildingIDs.size();
		}

		/// Gibt das BuildingChassis zum angegebenen Index zur�ck
		const BuildingChassis& getBuilding(uint32_t index) const;
};


#endif // PLAYERBUILDINGLIST_H_INCLUDED

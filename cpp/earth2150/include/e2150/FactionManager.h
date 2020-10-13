#ifndef FACTIONMANAGER_H_INCLUDED
#define FACTIONMANAGER_H_INCLUDED

#include "e2150/Faction.h"

#include <vector>
#include <stdint.h>

/**
* Klasse um alle existierende Fraktionen zu verwalten.
* Bietet Lesezugriff auf Fraktionsdaten.
*/
class FactionManager {
	private:
		/// Gespeicherte Fraktionen
		std::vector<Faction> faction;

		/// Gibt true zur�ck, wenn der angesprochene Index g�ltig ist
		bool isValidIndex(uint32_t index) const;

		/// Gibt die n�chste ID zur�ck, welcher einer Fraktion gegeben werden kann
		uint32_t getNextFreeID() const;

		FactionManager(const FactionManager&);
		FactionManager operator=(const FactionManager&);

	public:
		FactionManager();
		~FactionManager();

		/// Gibt die Anzahl an Vorhandenen Fraktionen zur�ck
		uint32_t getCount() const {
			return faction.size();
		}

		/// Gibt die Referenz auf eine Fraktion zur�ck
		const Faction& getFaction(uint32_t index) const;

		/// Gibt die Referenz auf eine Fraktion zur�ck
		Faction& getFaction(uint32_t index);

		/// F�gt eine neue Fraktion mit dem Namen ein
		/// \return Die ID der Fraktion
		uint32_t addFaction(const std::wstring& name);

		/// F�gt eine neue Fraktion mit Namen und ID ein
		/// \return True wenn Einf�gen erfolgreich, false wenn nicht (ID vergeben)
		bool addFaction(uint32_t id, const std::wstring& name);

		/// F�gt eine neue Fraktion ein
		/// \return True wenn Einf�gen erfolgreich, false wenn nicht (ID vergeben)
		bool addFaction(const Faction& faction);

};


#endif // FACTIONMANAGER_H_INCLUDED

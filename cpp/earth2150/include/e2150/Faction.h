#ifndef FRACTION_H
#define FRACTION_H

#include <stdint.h>
#include <string>

/**
* Speicherstruktur f�r Fraktionen.
* Speichert ID und Name der Fraktion.
*/
class Faction {
	private:
		uint32_t uID;
		std::wstring name;

	public:
		Faction(uint32_t uID, const std::wstring& name);

		/// Gibt die ID der Fraktion zur�ck
		uint32_t getID() const {
			return uID;
		}

		/// Gibt den Namen der Fraktion zur�ck
		const std::wstring& getName() const {
			return name;
		}

		/// Setzt einen neuen Namen f�r die Fraktion
		void setName(const std::wstring& name) {
			this->name = name;
		}
};

#endif

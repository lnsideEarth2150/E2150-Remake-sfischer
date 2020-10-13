#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <irrlicht.h>

/**
* Speichert die Grafikkonfiguration.
* Bietet Methoden um diese in eine XML Datei zu speichern und zu laden.
*/
class ClientConfig {
	private:
		/// Versionsnr der Config Datei, diese Nr sollte bei jedem �ndern dieser Klasse erh�ht werden.
		/// Immer wenn diese Nr != der gespeicherten ist, sollte die Config neu geschrieben werden.
		static const irr::u16 CONFIG_VERSION = 3;

		/// Irrlicht Parameter f�r Grafikeinstellungen
		irr::SIrrlichtCreationParameters param;

		/// Wenn gesetzt werden keine modernen GPU features vorrausgesetzt
		bool useCompatibilityRenderer;

		/// Pfard Angabe zu den Spieldaten von The Moon Project
		irr::io::path path_TheMoonProject;

		/// Pfard Angabe zu den Spieldaten von Lost Souls
		irr::io::path path_LostSouls;

		irr::u32 inactiveFPSLimit;

		/// Angabe ob die geladene Config in der aktuellen Version ist (siehe CONFIG_VERSION)
		bool latestConfigVersion;

		/// Gibt den Namen f�r die Config f�r den Treibertyp zur�ck.
		static const wchar_t* DriverName(irr::video::E_DRIVER_TYPE driverType);

		/// Gibt den Enum-Wert f�r den Namen des Treibertyps zur�ck.
		static irr::video::E_DRIVER_TYPE DriverType(const irr::core::stringw& name);

	public:
		ClientConfig();

		/// Setzt die Standardwerte f�r Aufl�sung, Ausgabeger�t ect.
		void setDefaultValues();

		void loadXMLFile(irr::io::IXMLReader* reader);
		void saveXMLFile(irr::io::IXMLWriter* writer) const;

		/// Gibt Zugriff auf die Parameter f�r das IrrlichtDevice.
		irr::SIrrlichtCreationParameters& Parameter() {return param;};
		const irr::SIrrlichtCreationParameters& Parameter() const {return param;};

		/// Gibt an ob der Kompatibilit�tsrenderer verwendet werden soll (keine modernen GPU features)
		bool getUseCompatibilityRenderer() const {return useCompatibilityRenderer;}

		/// Gibt den Pfard zu dem Spielordner von The Moon Project zur�ck (kann "" sein)
		const irr::io::path& getTheMoonProjectPath() const {return path_TheMoonProject;}

		/// Gibt den Pfard zu dem Spielordner von Lost Souls zur�ck (kann "" sein)
		const irr::io::path& getLostSoulsPath() const {return path_LostSouls;}

		irr::u32 getInactiveFPSLimit() const {return inactiveFPSLimit;}

		/// Gibt zur�ck ob die geladene Config in der aktuellen Version ist (siehe CONFIG_VERSION)
		bool isLatestConfigVersion() const {return latestConfigVersion;}
};


#endif // CONFIG_H_INCLUDED

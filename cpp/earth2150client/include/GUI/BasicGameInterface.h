#ifndef BASICGAMEINTERFACE_H_INCLUDED
#define BASICGAMEINTERFACE_H_INCLUDED

#include "GUI/IGUI.h"

/**
* Baut das Grundlegende Interface f�r das Spiel auf.
* Unterklassen k�nnen die Bereiche dann mit Inhalt f�llen.
*/
class BasicGameInterface : public IGUI, public irr::IEventReceiver {
	private:
		/// Nur n�tig um Screen Resize Events senden zu k�nnen -> mit Irrlicht 1.9 nicht mehr n�tig
		irr::IrrlichtDevice* device;

		irr::gui::IGUIWindow* menuPanel;
		irr::gui::IGUIStaticText* mapName;

		irr::gui::IGUIComboBox* menuButton;

		irr::gui::IGUIWindow* mapPanel;

		irr::gui::IGUIWindow* controlPanel;

		BasicGameInterface(const BasicGameInterface&);
		BasicGameInterface& operator=(const BasicGameInterface&);

		/// Baut die GUI auf
		void buildGUI();

		void buildMenuPanel();
		void resizeMenuPanel(const irr::core::dimension2du& newWindowSize);

		void buildMapPanel();
		void resizeMapPanel(const irr::core::dimension2du& newWindowSize);

		void buildControlPanel();
		void resizeControlPanel(const irr::core::dimension2du& newWindowSize);

	protected:
		/// Entfernt Titelleiste, Titelbuttons und verschiebbarkeit
		void makeWindowToPanel(irr::gui::IGUIWindow* window) const;

		irr::gui::IGUIWindow* getMenuPanel() {
			return menuPanel;
		}

		irr::gui::IGUIWindow* getMapPanel() {
			return mapPanel;
		}

		irr::gui::IGUIWindow* getControlPanel() {
			return controlPanel;
		}

	public:
		BasicGameInterface(irr::gui::IGUIEnvironment* guiEnv, irr::IrrlichtDevice* device);
		virtual ~BasicGameInterface();

		/// Setzt den Kartennamen im entsprechenden Feld
		void setMapName(const wchar_t* name);

		/// Passt die GUI Elemente an eine neue Aufl�sung an
		virtual void onResize(const irr::core::dimension2du& newSize);

		virtual bool isMouseOverGUIElement(const irr::core::position2di& mousePosition) const;

		virtual bool OnEvent(const irr::SEvent& event);
};


#endif // BASICGAMEINTERFACE_H_INCLUDED

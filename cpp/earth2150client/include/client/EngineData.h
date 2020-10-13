#ifndef ENGINEDATA_H_INCLUDED
#define ENGINEDATA_H_INCLUDED

#include "config/ClientConfig.h"

namespace irr {
class IrrlichtDevice;
}

/**
* H�lt Zentrale Datenstrukturen f�r die Spielengine.
* Darunter die Config sowie das Irrlicht Device.
* Bietet entsprechende Zugriffsm�glichkeiten an.
*/
class EngineData {
	private:
		/// Das verwendete Irrlicht Device
		irr::IrrlichtDevice* device;

		/// Die Config des Clients
		ClientConfig config;

		EngineData(const EngineData&);
		EngineData operator=(const EngineData&);

	public:
		EngineData();
		~EngineData();

		/// Setzt das zu verwendente Irrlicht Device
		void setDevice(irr::IrrlichtDevice* device);

		/// Gibt die Referenz auf die ClientConfig
		const ClientConfig& getConfig() const {
			return config;
		};

		/// Gibt die Referenz auf die ClientConfig
		ClientConfig& getConfig() {
			return config;
		};

		/// Gibt einen Ptr auf das Irrlicht Device zur�ck
		irr::IrrlichtDevice* getIrrlichtDevice() {
			return device;
		};

};


#endif // ENGINEDATA_H_INCLUDED

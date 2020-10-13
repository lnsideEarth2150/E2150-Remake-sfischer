#include "Building/GlobalBuildingList.h"

#include "Building/BuildingChassis.h"

#include <cassert>

GlobalBuildingList::GlobalBuildingList() :
	buildings() {
}

GlobalBuildingList::~GlobalBuildingList() {
	for (size_t i = 0; i < buildings.size(); ++i) {
		delete buildings[i];
	}
}

void GlobalBuildingList::addTestBuildings() {
	BuildingChassis* b;

	// 1x1 Geb�ude
	b = new BuildingChassis(1, 1, "1x1 Test");
	buildings.push_back(b);

	// 3x4 Geb�ude, wobei 3x3 Geb�ude und 1 Feld f�r Eingang
	b = new BuildingChassis(3, 4, "3x3 Test mit Ausfahrt");
	BuildingGround& ground = b->getBuildingGround();
	ground.setField(0, 0, BuildingGround::FIELD_FREE);
	ground.setField(1, 0, BuildingGround::FIELD_ENTRY);
	ground.setField(2, 0, BuildingGround::FIELD_FREE);
	buildings.push_back(b);

	// 2x1 Geb�ude
	b = new BuildingChassis(2, 1, "2x1 Test");
	buildings.push_back(b);
}

const BuildingChassis& GlobalBuildingList::getBuilding(uint32_t index) const {
	assert(index < buildings.size());

	return *buildings[index];
}

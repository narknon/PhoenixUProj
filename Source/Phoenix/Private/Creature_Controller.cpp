#include "Creature_Controller.h"

ACreature_Controller::ACreature_Controller() {
    this->NavmeshQueryHorizontalRadius = 200.00f;
    this->NavmeshQueryVerticalUpRadius = 1000.00f;
    this->NavmeshQueryVerticalDownRadius = 1000.00f;
    this->NavmeshQueryOffMeshMaxRadius = 1000.00f;
    this->CreaturePathFollowingComp = NULL;
    this->CreatureUtilityContext = NULL;
}


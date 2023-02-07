#include "Creature_PathTeleportComponent.h"

UCreature_PathTeleportComponent::UCreature_PathTeleportComponent() {
    this->PathEndBuffer = 200.00f;
    this->TeleportFreeAreaTestRadius = 200.00f;
    this->TeleportGroundLineCheckLength = 500.00f;
    this->TeleportLocationUpOffset = 30.00f;
    this->CreatureCharacter = NULL;
    this->CreaturePathFollowingComponent = NULL;
}


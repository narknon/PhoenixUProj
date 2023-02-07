#include "InstancedCharacterBoneSwarmComponent.h"
#include "CharacterBoneProjector.h"

void UInstancedCharacterBoneSwarmComponent::UnhideNext() {
}

void UInstancedCharacterBoneSwarmComponent::UnhideAll() {
}

int32 UInstancedCharacterBoneSwarmComponent::UnHide(int32 howMany) {
    return 0;
}

void UInstancedCharacterBoneSwarmComponent::Reset() {
}

int32 UInstancedCharacterBoneSwarmComponent::RemainingHidden() const {
    return 0;
}

void UInstancedCharacterBoneSwarmComponent::Poof() {
}

void UInstancedCharacterBoneSwarmComponent::KillAll() {
}

UInstancedCharacterBoneSwarmComponent::UInstancedCharacterBoneSwarmComponent() {
    this->Projector = CreateDefaultSubobject<UCharacterBoneProjector>(TEXT("Projector"));
    this->SkinEffect = NULL;
    this->ParamProjectionsCenterRadius = TEXT("ProjectionsCenterRadius");
    this->ParamProjectionsMin = TEXT("ProjectionsMin");
    this->ParamProjectionsMax = TEXT("ProjectionsMax");
    this->ParamTotalProjectionsCenterRadius = TEXT("TotalProjectionsCenterRadius");
    this->ParamActorCenterRadius = TEXT("ActorCenterRadius");
    this->bParamProjectionsCenterRadius = false;
    this->bParamProjectionsMin = false;
    this->bParamProjectionsMax = false;
    this->bParamTotalProjectionsCenterRadius = true;
    this->bParamActorCenterRadius = false;
    this->OnFirstBoneTouch = NULL;
    this->OnPoof = NULL;
    this->PoofLimitParticles = 0;
    this->bPoofLimitParticles = false;
    this->bDisableMotionBlur = true;
    this->NextUnhide = 0;
    this->SwarmMeshes = NULL;
    this->SkinFXComponent = NULL;
    this->bDebugDraw = false;
    this->bDebugBounds = false;
    this->bDebugProjectionResults = false;
}


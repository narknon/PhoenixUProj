#pragma once
#include "CoreMinimal.h"
#include "EMultiFXLocation.generated.h"

UENUM(BlueprintType)
enum class EMultiFXLocation : uint8 {
    DefaultLoc,
    AnchorLoc,
    ObjectCenterLoc,
    ObjectTopLoc,
    ObjectBottomLoc,
    ObjectFrontLoc,
    ObjectBackLoc,
    ObjectRightLoc,
    ObjectLeftLoc,
    GroundBelowLoc,
    ComponentCenterLoc,
    ComponentTopLoc,
    ComponentBottomLoc,
    ComponentFrontLoc,
    ComponentBackLoc,
    ComponentRightLoc,
    ComponentLeftLoc,
    WandtipLoc,
    ImpactPoint,
    TargetPoint,
    BoneLoc,
    MeshPointNearestInstigator,
    ActorPointNearestInstigator,
    MeshPointNearestLoc,
    ActorPointNearestLoc,
    WaterSurfaceLoc,
    WeaponLoc,
    ProjectileLoc,
};


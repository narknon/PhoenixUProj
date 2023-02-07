#pragma once
#include "CoreMinimal.h"
#include "EMultiFXLoc.generated.h"

UENUM(BlueprintType)
enum class EMultiFXLoc : uint8 {
    Location,
    Location_Attached,
    Location_ObjectOrient,
    Location_ObjectOrient_Attached,
    Location_ZeroOrient,
    Location_ZeroOrient_Attached,
    ObjectCenterLoc,
    ObjectCenterLoc_Attached,
    ObjectCenterLoc_ObjectOrient,
    ObjectCenterLoc_ObjectOrient_Attached,
    ObjectCenterLoc_ZeroOrient,
    ObjectCenterLoc_ZeroOrient_Attached,
    ObjectBottomLoc,
    ObjectBottomLoc_Attached,
    ObjectBottomLoc_ObjectOrient,
    ObjectBottomLoc_ObjectOrient_Attached,
    ObjectBottomLoc_ZeroOrient,
    ObjectBottomLoc_ZeroOrient_Attached,
    ObjectAnchorLoc,
    ObjectAnchorLoc_Attached,
    ObjectAnchorLoc_ObjectOrient,
    ObjectAnchorLoc_ObjectOrient_Attached,
    ObjectAnchorLoc_ZeroOrient,
    ObjectAnchorLoc_ZeroOrient_Attached,
    BoneLocation,
    BoneLocation_Attached,
    GroundBelowLoc,
    GroundBelowLoc_ObjectOrient,
    GroundBelowLoc_ZeroOrient,
    GroundBelowLoc_NormalOrient,
    GroundBelowCenterLoc,
    GroundBelowCenterLoc_ObjectOrient,
    GroundBelowCenterLoc_ZeroOrient,
    GroundBelowCenterLoc_NormalOrient,
    Wandtip_Attached,
};


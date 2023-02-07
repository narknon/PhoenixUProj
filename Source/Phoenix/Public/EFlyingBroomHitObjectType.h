#pragma once
#include "CoreMinimal.h"
#include "EFlyingBroomHitObjectType.generated.h"

UENUM(BlueprintType)
enum EFlyingBroomHitObjectType {
    Unknown,
    Creature,
    Character,
    CharacterOnBroom,
    NoMount,
};


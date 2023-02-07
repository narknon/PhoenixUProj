#pragma once
#include "CoreMinimal.h"
#include "ECharacterOptionsCollisionResponse.generated.h"

UENUM()
enum class ECharacterOptionsCollisionResponse : int8 {
    DoNotSetCollisionResponse,
    Ignore,
    Block,
    Overlap,
};


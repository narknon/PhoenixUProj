#pragma once
#include "CoreMinimal.h"
#include "EExternalActorRole.generated.h"

UENUM()
enum class EExternalActorRole : int8 {
    NONE,
    Foreground,
    Background,
    Extra,
};


#pragma once
#include "CoreMinimal.h"
#include "EAkCommSystem.generated.h"

UENUM()
enum class EAkCommSystem : int32 {
    Socket,
    HTCS,
};


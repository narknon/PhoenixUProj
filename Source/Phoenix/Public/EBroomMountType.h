#pragma once
#include "CoreMinimal.h"
#include "EBroomMountType.generated.h"

UENUM(BlueprintType)
enum EBroomMountType {
    FromIdleMount,
    FromWalkMount,
    FromJogMount,
    FromSwimming,
    FromFalling,
    InstantMount,
};


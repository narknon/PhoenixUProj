#pragma once
#include "CoreMinimal.h"
#include "EHoudiniRuntimeSettingsSessionType.generated.h"

UENUM(BlueprintType)
enum EHoudiniRuntimeSettingsSessionType {
    HRSST_InProcess,
    HRSST_Socket,
    HRSST_NamedPipe,
    HRSST_MAX UMETA(Hidden),
};


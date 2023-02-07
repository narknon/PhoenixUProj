#pragma once
#include "CoreMinimal.h"
#include "EHoudiniRuntimeSettingsAxisImport.generated.h"

UENUM(BlueprintType)
enum EHoudiniRuntimeSettingsAxisImport {
    HRSAI_Unreal,
    HRSAI_Houdini,
    HRSAI_MAX UMETA(Hidden),
};


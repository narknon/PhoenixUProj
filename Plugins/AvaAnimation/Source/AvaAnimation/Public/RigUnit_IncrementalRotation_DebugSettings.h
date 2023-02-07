#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RigUnit_IncrementalRotation_DebugSettings.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_IncrementalRotation_DebugSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform WorldOffset;
    
    AVAANIMATION_API FRigUnit_IncrementalRotation_DebugSettings();
};


#pragma once
#include "CoreMinimal.h"
#include "CurtainStageOptions.h"
#include "CurtainStageEntry.generated.h"

USTRUCT(BlueprintType)
struct FCurtainStageEntry {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double EnableAtTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCurtainStageOptions StageOptions;
    
    UTILITIESRUNTIME_API FCurtainStageEntry();
};


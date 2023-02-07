#pragma once
#include "CoreMinimal.h"
#include "HardSwapBatchComponentSettings.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FHardSwapBatchComponentSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MIDCreatesAllowedPerFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaterialsToSwapPerFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDetachAndDestoryWhenDone;
    
    FHardSwapBatchComponentSettings();
};


#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesReplaceLevelSuffix.generated.h"

USTRUCT(BlueprintType)
struct LERPVOLUMES_API FLerpVolumesReplaceLevelSuffix {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LevelSuffix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ReplaceWith;
    
    FLerpVolumesReplaceLevelSuffix();
};


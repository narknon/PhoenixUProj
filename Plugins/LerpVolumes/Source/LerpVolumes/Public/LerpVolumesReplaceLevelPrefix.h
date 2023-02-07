#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesReplaceLevelPrefix.generated.h"

USTRUCT(BlueprintType)
struct LERPVOLUMES_API FLerpVolumesReplaceLevelPrefix {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LevelPrefix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ReplaceWith;
    
    FLerpVolumesReplaceLevelPrefix();
};


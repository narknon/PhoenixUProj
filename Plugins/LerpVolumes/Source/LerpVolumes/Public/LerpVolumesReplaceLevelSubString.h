#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesReplaceLevelSubString.generated.h"

USTRUCT(BlueprintType)
struct LERPVOLUMES_API FLerpVolumesReplaceLevelSubString {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LevelSubString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ReplaceWith;
    
    FLerpVolumesReplaceLevelSubString();
};


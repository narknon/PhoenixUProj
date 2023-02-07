#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesAudioStateGroupNameBase.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesAudioStateGroupNameBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    LERPVOLUMES_API FLerpVolumesAudioStateGroupNameBase();
};


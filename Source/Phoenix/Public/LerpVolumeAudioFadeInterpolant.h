#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeInterpolant.h"
#include "LerpVolumeAudioFadeInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULerpVolumeAudioFadeInterpolant : public ULerpVolumeInterpolant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateThreshold;
    
    ULerpVolumeAudioFadeInterpolant();
};


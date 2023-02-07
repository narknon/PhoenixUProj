#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeLevelNameInterpolantBase.h"
#include "LerpVolumesAudioStateGroupLocation.h"
#include "LerpVolumesTagName.h"
#include "LerpVolumeLevelAudioLocationNameInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeLevelAudioLocationNameInterpolant : public ULerpVolumeLevelNameInterpolantBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesTagName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesAudioStateGroupLocation LevelName;
    
    ULerpVolumeLevelAudioLocationNameInterpolant();
};


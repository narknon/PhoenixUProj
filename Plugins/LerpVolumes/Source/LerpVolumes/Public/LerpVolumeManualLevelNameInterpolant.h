#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeLevelNameInterpolantBase.h"
#include "LerpVolumesTagName.h"
#include "LerpVolumeManualLevelNameInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeManualLevelNameInterpolant : public ULerpVolumeLevelNameInterpolantBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesTagName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UseLevelName;
    
    ULerpVolumeManualLevelNameInterpolant();
};


#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeInterpolant.h"
#include "LerpVolumesTagName.h"
#include "LerpVolumeDynamicTagInterpolant.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeDynamicTagInterpolant : public ULerpVolumeInterpolant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesTagName Name;
    
    ULerpVolumeDynamicTagInterpolant();
};


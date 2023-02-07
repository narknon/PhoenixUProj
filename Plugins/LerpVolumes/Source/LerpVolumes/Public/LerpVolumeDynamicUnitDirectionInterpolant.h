#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeInterpolant.h"
#include "LerpVolumesUnitDirectionName.h"
#include "LerpVolumeDynamicUnitDirectionInterpolant.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeDynamicUnitDirectionInterpolant : public ULerpVolumeInterpolant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesUnitDirectionName Name;
    
    ULerpVolumeDynamicUnitDirectionInterpolant();
};


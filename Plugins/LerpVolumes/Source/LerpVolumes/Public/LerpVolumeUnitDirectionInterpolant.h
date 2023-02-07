#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LerpVolumeInterpolant.h"
#include "LerpVolumesUnitDirectionName.h"
#include "LerpVolumeUnitDirectionInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeUnitDirectionInterpolant : public ULerpVolumeInterpolant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesUnitDirectionName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Value;
    
    ULerpVolumeUnitDirectionInterpolant();
};


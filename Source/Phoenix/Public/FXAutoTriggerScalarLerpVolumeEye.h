#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "LerpVolumesScalarName.h"
#include "FXAutoTriggerScalarLerpVolumeEye.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarLerpVolumeEye : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesScalarName LerpVolumesScalar;
    
    UFXAutoTriggerScalarLerpVolumeEye();
};


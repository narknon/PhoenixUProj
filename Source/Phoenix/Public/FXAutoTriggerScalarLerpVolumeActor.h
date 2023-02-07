#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "LerpVolumesScalarName.h"
#include "FXAutoTriggerScalarLerpVolumeActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarLerpVolumeActor : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesScalarName LerpVolumesScalar;
    
    UFXAutoTriggerScalarLerpVolumeActor();
};


#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "EFXAutoTriggerZLocation.h"
#include "EFXAutoTriggerZType.h"
#include "FXAutoTriggerScalarPlayerWorldZ.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarPlayerWorldZ : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFXAutoTriggerZLocation Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFXAutoTriggerZType Type;
    
    UFXAutoTriggerScalarPlayerWorldZ();
};


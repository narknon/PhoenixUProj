#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "EFXAutoTriggerZLocation.h"
#include "EFXAutoTriggerZType.h"
#include "FXAutoTriggerScalarActorWorldZ.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarActorWorldZ : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFXAutoTriggerZLocation Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFXAutoTriggerZType Type;
    
    UFXAutoTriggerScalarActorWorldZ();
};


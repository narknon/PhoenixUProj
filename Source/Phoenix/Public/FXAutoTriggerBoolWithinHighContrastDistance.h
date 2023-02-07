#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "EHighContrastDistanceType.h"
#include "FXAutoTriggerBoolWithinHighContrastDistance.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolWithinHighContrastDistance : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHighContrastDistanceType Type;
    
    UFXAutoTriggerBoolWithinHighContrastDistance();
};


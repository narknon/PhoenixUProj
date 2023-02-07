#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterKeyProperty.h"
#include "FXAutoTriggerConditionBase.h"
#include "FXAutoTriggerConditionIsSwappable.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerConditionIsSwappable : public UFXAutoTriggerConditionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterKeyProperty Key;
    
    UFXAutoTriggerConditionIsSwappable();
};


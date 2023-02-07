#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "FXAutoTriggerBoolIsInteractibleItem.generated.h"

class UFXAutoTriggerInteractibleItemsFilter;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolIsInteractibleItem : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerInteractibleItemsFilter* Filter;
    
    UFXAutoTriggerBoolIsInteractibleItem();
};


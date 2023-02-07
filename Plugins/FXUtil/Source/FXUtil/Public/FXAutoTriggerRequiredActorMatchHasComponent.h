#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRequiredActorsMatchBase.h"
#include "FXAutoTriggerRequiredActorMatchHasComponent.generated.h"

class UActorComponent;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerRequiredActorMatchHasComponent : public UFXAutoTriggerRequiredActorsMatchBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UActorComponent> HasComponentType;
    
    UFXAutoTriggerRequiredActorMatchHasComponent();
};


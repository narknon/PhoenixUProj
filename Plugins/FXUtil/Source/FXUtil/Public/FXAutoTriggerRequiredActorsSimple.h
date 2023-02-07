#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRequiredActorsBase.h"
#include "FXAutoTriggerRequiredActorsSimple.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerRequiredActorsSimple : public UFXAutoTriggerRequiredActorsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ActorType;
    
    UFXAutoTriggerRequiredActorsSimple();
};


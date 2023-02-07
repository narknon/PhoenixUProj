#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRequiredActorsMatchBase.h"
#include "FXAutoTriggerRequiredActorsMatchChildOf.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerRequiredActorsMatchChildOf : public UFXAutoTriggerRequiredActorsMatchBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ParentActorType;
    
    UFXAutoTriggerRequiredActorsMatchChildOf();
};


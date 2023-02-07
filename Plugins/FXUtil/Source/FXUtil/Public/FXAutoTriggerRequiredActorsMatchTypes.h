#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRequiredActorsMatchBase.h"
#include "FXAutoTriggerRequiredActorsMatchTypes.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerRequiredActorsMatchTypes : public UFXAutoTriggerRequiredActorsMatchBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> ActorTypes;
    
    UFXAutoTriggerRequiredActorsMatchTypes();
};


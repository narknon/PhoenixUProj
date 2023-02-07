#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRequiredActorsMatchBase.h"
#include "FXAutoTriggerRequiredActorsMatchOr.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerRequiredActorsMatchOr : public UFXAutoTriggerRequiredActorsMatchBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXAutoTriggerRequiredActorsMatchBase*> Conditions;
    
    UFXAutoTriggerRequiredActorsMatchOr();
};


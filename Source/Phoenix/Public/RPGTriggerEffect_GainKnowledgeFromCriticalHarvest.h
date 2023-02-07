#pragma once
#include "CoreMinimal.h"
#include "EKnowledgeAction.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_GainKnowledgeFromCriticalHarvest.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_GainKnowledgeFromCriticalHarvest : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EKnowledgeAction> KnowledgeAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInDisplayTicker;
    
public:
    URPGTriggerEffect_GainKnowledgeFromCriticalHarvest();
};


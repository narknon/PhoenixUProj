#pragma once
#include "CoreMinimal.h"
#include "EOpportunityType.h"
#include "ablOpportunityWindowTagTask.h"
#include "ablOpportunityWindowTask_ModifyAOECast.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UablOpportunityWindowTask_ModifyAOECast : public UablOpportunityWindowTagTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOpportunityType OpportunityType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RemainingLifeTime;
    
    UablOpportunityWindowTask_ModifyAOECast();
};


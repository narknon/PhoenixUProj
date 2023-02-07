#pragma once
#include "CoreMinimal.h"
#include "FXAdjustments.h"
#include "FXAdjustmentsKillFXAutoGroup.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAdjustmentsKillFXAutoGroup : public UFXAdjustments {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Group;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bImmediate;
    
    UFXAdjustmentsKillFXAutoGroup();
};


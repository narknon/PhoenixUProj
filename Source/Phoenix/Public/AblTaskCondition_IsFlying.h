#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "AblTaskCondition_IsFlying.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAblTaskCondition_IsFlying : public UAblTaskCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNegate;
    
    UAblTaskCondition_IsFlying();
};


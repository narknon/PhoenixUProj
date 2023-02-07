#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "AblTaskCondition_DamageOverTime.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UAblTaskCondition_DamageOverTime : public UAblTaskCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DoT_Type;
    
    UAblTaskCondition_DamageOverTime();
};


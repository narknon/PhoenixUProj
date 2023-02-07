#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_Weakness.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_Weakness : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
public:
    URPGTriggerEffect_Weakness();
};


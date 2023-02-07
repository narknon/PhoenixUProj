#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_ExtendDuration.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_ExtendDuration : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtendedTime;
    
public:
    URPGTriggerEffect_ExtendDuration();
};


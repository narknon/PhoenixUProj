#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_ProtegoReflectAttack.h"
#include "RPGTriggerEffect_ProtegoReflectRewards.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_ProtegoReflectRewards : public URPGTriggerEffect_ProtegoReflectAttack {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FocusAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RequirePerfect;
    
public:
    URPGTriggerEffect_ProtegoReflectRewards();
};


#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_Potion.generated.h"

class URPGAbility;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_Potion : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URPGAbility* OwnerAbility;
    
public:
    URPGTriggerEffect_Potion();
};


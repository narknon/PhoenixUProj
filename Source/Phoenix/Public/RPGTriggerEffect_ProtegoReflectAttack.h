#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_ProtegoReflectAttack.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_ProtegoReflectAttack : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Owner;
    
public:
    URPGTriggerEffect_ProtegoReflectAttack();
};


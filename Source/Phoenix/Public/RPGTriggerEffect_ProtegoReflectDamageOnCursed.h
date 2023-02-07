#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_ProtegoReflectAttack.h"
#include "RPGTriggerEffect_ProtegoReflectDamageOnCursed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_ProtegoReflectDamageOnCursed : public URPGTriggerEffect_ProtegoReflectAttack {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageScale;
    
public:
    URPGTriggerEffect_ProtegoReflectDamageOnCursed();
};


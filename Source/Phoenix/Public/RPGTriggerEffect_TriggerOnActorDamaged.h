#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_ActorDamaged.h"
#include "RPGTriggerEffect_TriggerOnActorDamaged.generated.h"

class URPGTriggerEffect_Base;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URPGTriggerEffect_TriggerOnActorDamaged : public URPGTriggerEffect_ActorDamaged {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URPGTriggerEffect_Base* TriggerEffect;
    
public:
    URPGTriggerEffect_TriggerOnActorDamaged();
};


#pragma once
#include "CoreMinimal.h"
#include "RPGAbilityEventListener.h"
#include "RPGAbilityCustomTargetEventListener.generated.h"

class AActor;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class URPGAbilityCustomTargetEventListener : public URPGAbilityEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* TargetActor;
    
public:
    URPGAbilityCustomTargetEventListener();
};


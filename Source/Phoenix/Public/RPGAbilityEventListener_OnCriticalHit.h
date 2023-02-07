#pragma once
#include "CoreMinimal.h"
#include "RPGAbilityEventListener.h"
#include "RPGAbilityEventListener_OnCriticalHit.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_OnCriticalHit : public URPGAbilityEventListener {
    GENERATED_BODY()
public:
    URPGAbilityEventListener_OnCriticalHit();
};


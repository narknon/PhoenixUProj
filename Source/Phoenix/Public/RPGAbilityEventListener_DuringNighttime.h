#pragma once
#include "CoreMinimal.h"
#include "DayNightEventInterface.h"
#include "RPGAbilityEventListener.h"
#include "RPGAbilityEventListener_DuringNighttime.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_DuringNighttime : public URPGAbilityEventListener, public IDayNightEventInterface {
    GENERATED_BODY()
public:
    URPGAbilityEventListener_DuringNighttime();
    
    // Fix for true pure virtual functions not being implemented
};


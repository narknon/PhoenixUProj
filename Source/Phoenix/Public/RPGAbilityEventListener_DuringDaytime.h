#pragma once
#include "CoreMinimal.h"
#include "DayNightEventInterface.h"
#include "RPGAbilityEventListener.h"
#include "RPGAbilityEventListener_DuringDaytime.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_DuringDaytime : public URPGAbilityEventListener, public IDayNightEventInterface {
    GENERATED_BODY()
public:
    URPGAbilityEventListener_DuringDaytime();
    
    // Fix for true pure virtual functions not being implemented
};


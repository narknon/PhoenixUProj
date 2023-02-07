#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RPGAbilityEventListener_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class URPGAbilityEventListener_Base : public UObject {
    GENERATED_BODY()
public:
    URPGAbilityEventListener_Base();
};


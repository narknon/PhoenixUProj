#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AvatarPresetOverride_Interface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UAvatarPresetOverride_Interface : public UInterface {
    GENERATED_BODY()
};

class IAvatarPresetOverride_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FName GetFullbodyPreset();
    
};


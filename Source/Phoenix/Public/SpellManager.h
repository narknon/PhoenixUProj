#pragma once
#include "CoreMinimal.h"
#include "PhxDbRegistryTypeManager.h"
#include "SpellManager.generated.h"

UCLASS(Blueprintable)
class USpellManager : public UPhxDbRegistryTypeManager {
    GENERATED_BODY()
public:
    USpellManager();
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
};


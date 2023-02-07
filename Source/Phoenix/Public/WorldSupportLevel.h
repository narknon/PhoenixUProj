#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorldSupportLevel.generated.h"

UCLASS(Blueprintable)
class UWorldSupportLevel : public UObject {
    GENERATED_BODY()
public:
    UWorldSupportLevel();
    UFUNCTION(BlueprintCallable)
    void OnUnload();
    
    UFUNCTION(BlueprintCallable)
    void OnShow();
    
    UFUNCTION(BlueprintCallable)
    void OnLoad();
    
    UFUNCTION(BlueprintCallable)
    void OnHidden();
    
};


#pragma once
#include "CoreMinimal.h"
#include "AmbulatoryHUD.h"
#include "CharacterStateHUD.generated.h"

UCLASS(Blueprintable, NonTransient)
class PHOENIX_API ACharacterStateHUD : public AAmbulatoryHUD {
    GENERATED_BODY()
public:
    ACharacterStateHUD();
    UFUNCTION(BlueprintCallable)
    void ToggleCharacterStateHUD();
    
};


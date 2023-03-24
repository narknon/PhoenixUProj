#pragma once
#include "CoreMinimal.h"
#include "AbleHUD.h"
#include "AmbulatoryHUD.generated.h"

UCLASS(Blueprintable, NonTransient)
class AMBULATORY_API AAmbulatoryHUD : public AAbleHUD {
    GENERATED_BODY()
public:
    AAmbulatoryHUD(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ToggleAmbulatoryHUD();
    
    UFUNCTION(BlueprintCallable)
    void OnIntegrate();
    
};


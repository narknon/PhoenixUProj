#pragma once
#include "CoreMinimal.h"
#include "PreloadArchitectHUD.h"
#include "AbleHUD.generated.h"

class AActor;

UCLASS(Blueprintable, NonTransient)
class ABLECORE_API AAbleHUD : public APreloadArchitectHUD {
    GENERATED_BODY()
public:
    AAbleHUD(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UpdateDebugTarget();
    
    UFUNCTION(BlueprintCallable)
    void ToggleAbleHUD();
    
    UFUNCTION(BlueprintCallable)
    void SetTarget(AActor* InActor);
    
};


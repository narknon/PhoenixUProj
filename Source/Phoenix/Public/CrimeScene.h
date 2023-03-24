#pragma once
#include "CoreMinimal.h"
#include "WorldObject.h"
#include "CrimeScene.generated.h"

UCLASS(Blueprintable)
class ACrimeScene : public AWorldObject {
    GENERATED_BODY()
public:
    ACrimeScene(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    static void GlobalEnableCrime(bool i_Enable);
    
};


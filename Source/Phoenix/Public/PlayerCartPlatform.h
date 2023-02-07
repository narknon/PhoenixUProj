#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "PlayerCartPlatform.generated.h"

UCLASS(Blueprintable)
class APlayerCartPlatform : public AActor {
    GENERATED_BODY()
public:
    APlayerCartPlatform();
protected:
    UFUNCTION(BlueprintCallable)
    void SetDismountLocation(AActor* Target, FTransform DismountLocation, FTransform CompanionDismountLocation);
    
};


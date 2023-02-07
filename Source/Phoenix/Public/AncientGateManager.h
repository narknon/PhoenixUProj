#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "AncientGateManager.generated.h"

class AActor;
class UActorComponent;
class UAncientGateManager;

UCLASS(Blueprintable)
class UAncientGateManager : public UObject {
    GENERATED_BODY()
public:
    UAncientGateManager();
    UFUNCTION(BlueprintCallable)
    static void SetAncientGateCollision(AActor* Actor, TEnumAsByte<ECollisionResponse> CollisionResponse);
    
    UFUNCTION(BlueprintCallable)
    static void GetAncientGatePrimitives(AActor* Actor, TArray<UActorComponent*>& Primitives);
    
    UFUNCTION(BlueprintCallable)
    static UAncientGateManager* Get();
    
};


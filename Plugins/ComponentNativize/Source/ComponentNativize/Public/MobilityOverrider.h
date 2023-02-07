#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EMobilityOverride.h"
#include "MobilityOverrider.generated.h"

class AActor;
class USceneComponent;

UCLASS(Blueprintable)
class COMPONENTNATIVIZE_API UMobilityOverrider : public UObject {
    GENERATED_BODY()
public:
    UMobilityOverrider();
    UFUNCTION(BlueprintCallable)
    static void ComponentOverrideMobility(USceneComponent* SceneComponent, EMobilityOverride mobilityOverride, EMobilityOverride lightMobilityOverride, bool includeChildren);
    
    UFUNCTION(BlueprintCallable)
    static void ActorOverrideMobility(AActor* Actor, EMobilityOverride mobilityOverride, EMobilityOverride lightMobilityOverride, bool includeChildren);
    
};


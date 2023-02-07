#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "ConjuredDragonComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UConjuredDragonComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UConjuredDragonComponent();
    UFUNCTION(BlueprintCallable)
    void HeadTrackActor(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    void EndEncounter();
    
    UFUNCTION(BlueprintCallable)
    void BeginEncounter();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void ApproachVector(FVector& Out, const FVector& curr, const FVector& Dest, float Rate, float dt);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float ApproachScalar(float curr, float Dest, float Rate, float dt);
    
};


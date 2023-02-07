#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "StateEffectComponent.h"
#include "TransformationOverlandData.h"
#include "TransformationOverlandComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTransformationOverlandComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* newActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTransformationOverlandData Data;
    
public:
    UTransformationOverlandComponent();
private:
    UFUNCTION(BlueprintCallable)
    void OnActorEndPlay(AActor* DestroyedActor, TEnumAsByte<EEndPlayReason::Type> EndPlayReason);
    
    UFUNCTION(BlueprintCallable)
    void HealthZero(AActor* InActor);
    
};


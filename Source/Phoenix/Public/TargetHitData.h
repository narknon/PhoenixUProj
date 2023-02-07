#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "TargetHitData.generated.h"

class AActor;

UCLASS(Blueprintable)
class UTargetHitData : public UObject {
    GENERATED_BODY()
public:
    UTargetHitData();
    UFUNCTION(BlueprintCallable)
    void Remove();
    
    UFUNCTION(BlueprintCallable)
    void OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
};


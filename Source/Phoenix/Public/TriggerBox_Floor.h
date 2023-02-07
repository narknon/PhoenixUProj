#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/TriggerBox.h"
#include "TriggerBox_Floor.generated.h"

class AActor;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class PHOENIX_API ATriggerBox_Floor : public ATriggerBox {
    GENERATED_BODY()
public:
    ATriggerBox_Floor();
    UFUNCTION(BlueprintCallable)
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};


#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "CreatureNurturingVolumeBase.generated.h"

class AActor;

UCLASS(Abstract, Blueprintable)
class ACreatureNurturingVolumeBase : public ATriggerBox {
    GENERATED_BODY()
public:
    ACreatureNurturingVolumeBase(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginOverlap(AActor* SelfActor, AActor* OtherActor);
    
};


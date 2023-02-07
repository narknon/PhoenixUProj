#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GuideSuppressionVolume.generated.h"

class AActor;

UCLASS(Blueprintable)
class AGuideSuppressionVolume : public ATriggerBox {
    GENERATED_BODY()
public:
    AGuideSuppressionVolume();
private:
    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginOverlap(AActor* SelfActor, AActor* OtherActor);
    
};


#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "ECreaturePerceptionVolumeType.h"
#include "CreaturePerceptionVolume.generated.h"

class AActor;

UCLASS(Blueprintable)
class ACreaturePerceptionVolume : public AVolume {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreaturePerceptionVolumeType VolumeType;
    
public:
    ACreaturePerceptionVolume();
private:
    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginOverlap(AActor* SelfActor, AActor* OtherActor);
    
};


#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AkAmbientSound.generated.h"

class UAkAudioEvent;
class UAkComponent;

UCLASS(Blueprintable)
class AKAUDIO_API AAkAmbientSound : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* AkAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* AkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta=(AllowPrivateAccess=true))
    bool StopWhenOwnerIsDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta=(AllowPrivateAccess=true))
    bool AutoPost;
    
    AAkAmbientSound();
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void StopAmbientSound();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void StartAmbientSound();
    
};


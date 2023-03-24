#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ECameraStackLookAtStrength.h"
#include "CameraStackLookAtTargetActor.generated.h"

class ATriggerVolume;

UCLASS(Blueprintable)
class CAMERASTACK_API ACameraStackLookAtTargetActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackLookAtStrength LookAtStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<ATriggerVolume> TriggerVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeoutAfterTriggerEntered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTriggerOnReEntry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<AActor> CameraActorOverride;
    
    ACameraStackLookAtTargetActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StopPlayerInitiation(int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable)
    void StartPlayerInitiation(int32 PlayerIndex);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnTriggerEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnTriggerBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerInitiationActive(int32 PlayerIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActiveLookAtTargetForPlayer(int32 PlayerIndex) const;
    
    UFUNCTION(BlueprintCallable)
    void DeactivateLookAt(int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable)
    void ActivateLookAt(int32 PlayerIndex, float Duration);
    
};


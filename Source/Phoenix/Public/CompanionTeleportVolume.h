#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CompanionTeleportVolume.generated.h"

class UBoxComponent;

UCLASS(Blueprintable, MinimalAPI)
class ACompanionTeleportVolume : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* CollisionComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAlwaysActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTriggerOnEnter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> Locators;
    
    ACompanionTeleportVolume();
    UFUNCTION(BlueprintCallable)
    void SetTemporarilyActive(bool bActive, float Timeout);
    
    UFUNCTION(BlueprintCallable)
    void SetActive(bool bActive);
    
    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginOverlap(AActor* SelfActor, AActor* OtherActor);
    
};


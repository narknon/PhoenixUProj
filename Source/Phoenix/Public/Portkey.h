#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "DbSingleColumnInfo.h"
#include "GameFramework/Actor.h"
#include "Biped_Interact_Interface.h"
#include "Portkey.generated.h"

class ATargetPoint;
class UBTService_AvaAITree;
class UParticleSystem;
class UParticleSystemComponent;

UCLASS(Blueprintable)
class APortkey : public AActor, public IBiped_Interact_Interface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* ParticleSystemComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* ActorToTeleport;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* ExitEmitter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* EntryEmitter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* BeaconEmitter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseBeaconEmitter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ATargetPoint* TargetA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ATargetPoint* TargetB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo FastTravelDestinationA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo FastTravelDestinationB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AtA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EjectForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EntryCamDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExitCamDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator EnterCameraRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator ExitCameraRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseAdvancedExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OnGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OptimalDistance;
    
    APortkey(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Transport();
    
    UFUNCTION(BlueprintCallable)
    void Touch();
    
    UFUNCTION(BlueprintCallable)
    void PlacePlayerOptimally();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Interact(UBTService_AvaAITree* AvaService);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_TeleportStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_TeleportEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_ActivateExitCamera();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_ActivateEnterCamera();
    
    UFUNCTION(BlueprintCallable)
    ATargetPoint* GetTarget();
    
    UFUNCTION(BlueprintCallable)
    void FindNonBlockingCameraLocation(FVector& Target1, FVector& Target2, FVector& CameraLocation, float CameraDistance, float CameraHeight);
    
    UFUNCTION(BlueprintCallable)
    void Drop();
    
    UFUNCTION(BlueprintCallable)
    void ActivateExitCamera();
    
    UFUNCTION(BlueprintCallable)
    void ActivateEnterCamera();
    
    
    // Fix for true pure virtual functions not being implemented
};


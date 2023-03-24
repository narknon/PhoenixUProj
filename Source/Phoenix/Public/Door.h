#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "BeaconableObject.h"
#include "EBlockNavMeshOverride.h"
#include "EDoorCurveAdjustment.h"
#include "EDoorState.h"
#include "EOpenDoorDirection.h"
#include "Lockable.h"
#include "PlayerClosedDoorDelegate.h"
#include "PlayerOpenedDoorDelegate.h"
#include "Door.generated.h"

class AActor;
class AAkAcousticPortal;
class ADoor;
class ALerpVolume;
class ARenderSettingsCustomBlendDomainVolume;
class UAkAudioEvent;
class UArrowComponent;
class UCurveFloat;
class UDoorBoxComponent;
class UFastTravelForDoorsComponent;
class UObject;
class UOdcObstacleComponent;
class UPrimitiveComponent;
class UStaticMesh;
class UStaticMeshComponent;
class UWidgetComponent;

UCLASS(Blueprintable)
class ADoor : public ALockable, public IBeaconableObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EnvInt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PropIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<UStaticMesh>, bool> MeshSelect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseDoorFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ADoor* ChildDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RegisterNamedDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BeaconableObjectID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Open;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool KeepDoorOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DefaultOpenDoorForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToOpenDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToKeepDoorOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToHoldDoorWhenInVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToCloseDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseCharacterSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseHingeDistanceRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinOpenSpeedMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxOpenSpeedMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDoorAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDoorAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowNPCToPassThroughLockedDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BlockNPCsIfLocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SlowPlayerInFrontOfDoor;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 ExpiryTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ForceTickEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeverBlockNavGuide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAkAcousticPortal* AcousticPortal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARenderSettingsCustomBlendDomainVolume* RenderSettingsCustomBlendDomainVolumeAttached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ALerpVolume* LerpVolumeAttached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* OpeningSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* OpenedSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* ClosingSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* ClosedSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* BellSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FrontCaresAboutStreaming;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BackCaresAboutStreaming;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FrontIsExterior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BackIsExterior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* OpenCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CloseCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDoorCurveAdjustment CloseDoorCurveAdjustment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* DoorMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* FrameMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOdcObstacleComponent* NavObstacle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UArrowComponent* ForwardArrow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOdcObstacleComponent* ClosedDoorNavObstacle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDoorBoxComponent* EnterTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDoorBoxComponent* ExitTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDoorBoxComponent* PlayerCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWidgetComponent* WidgetComponentSpinner;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerOpenedDoor OnPlayerOpenedDoor;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerClosedDoor OnPlayerClosedDoor;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFastTravelForDoorsComponent* FastTravelComponent;
    
public:
    ADoor(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable)
    void SwingDoorFinished();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetState(EDoorState DoorState, bool LockVisible, bool PlaySoundsAndEffects);
    
    UFUNCTION(BlueprintCallable)
    void SetLockLevel(const UObject* Caller, int32 Int);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetKeepDoorOpen(bool InKeepDoorOpen);
    
private:
    UFUNCTION(BlueprintCallable)
    void RotateDoorToAlpha(float Alpha);
    
public:
    UFUNCTION(BlueprintCallable)
    void OpenDoor(bool KeepOpen, float SecondsToDelayClosing, bool bPushedOpen, EOpenDoorDirection Direction);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnEnterTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* ActorInTrigger, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
public:
    UFUNCTION(BlueprintCallable)
    void ObjectPickedUp(UObject* Caller);
    
private:
    UFUNCTION(BlueprintCallable)
    void DestroyWidgetComponentSpinner();
    
public:
    UFUNCTION(BlueprintCallable)
    void CloseDoor(bool ForceClose);
    
private:
    UFUNCTION(BlueprintCallable)
    void BlockPlayer(bool ShouldBlock);
    
    UFUNCTION(BlueprintCallable)
    void BlockOrUnblockDoor();
    
    UFUNCTION(BlueprintCallable)
    void BlockNavMesh(bool ShouldBlock, EBlockNavMeshOverride Override);
    
    
    // Fix for true pure virtual functions not being implemented
};


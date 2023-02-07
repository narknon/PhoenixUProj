#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "CameraInputMappings.h"
#include "CameraStackActorBehaviorTreePair.h"
#include "CameraStackData.h"
#include "Templates/SubclassOf.h"
#include "CameraStackActor.generated.h"

class UBehaviorTree;
class UCameraStack;
class UCameraStackBehavior;
class UCameraStackBehaviorCore;
class UCameraStackCineComponent;
class UCameraStackInput;
class UCameraStackTarget;
class UInputComponent;
class UObject;

UCLASS(Blueprintable, CollapseCategories)
class CAMERASTACK_API ACameraStackActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackCineComponent* CameraComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraStackData DefaultData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackTarget* Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBehaviorTree*> BehaviorTrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyIfSpawnedOnEndViewTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InputPriorityOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideInputMappings;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraInputMappings InputMappingsOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bUnbindInputOnEndViewTarget;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStack* BehaviorStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackInput* Input;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInputComponent* CameraInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCameraStackActorBehaviorTreePair> BehaviorTreePairs;
    
public:
    ACameraStackActor();
    UFUNCTION(BlueprintCallable)
    void SetNamedSecondaryTargetActor(FName InName, AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    void SetCameraContext(FName InContextName, bool bSet);
    
    UFUNCTION(BlueprintCallable)
    void ResetRotationToTarget(float InBlendDuration, const FRotator& InDesiredDelta, bool bInResetYaw, bool bInResetPitch);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCameraContextSet(FName InContextName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetUnblendedCameraViewTransform() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCameraStackTarget* GetTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetNamedSecondaryTargetActor(FName InName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCameraStackInput* GetInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetCameraViewTransform() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCameraStack* GetBehaviors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator GetArmRotation() const;
    
    UFUNCTION(BlueprintCallable)
    void ForceSetArmRotationTowardsLocation(FVector InLocation);
    
    UFUNCTION(BlueprintCallable)
    void ForceSetArmRotation(FRotator InRotation, bool bUseDefaultPitch);
    
    UFUNCTION(BlueprintCallable)
    void ForceCameraReset();
    
    UFUNCTION(BlueprintCallable)
    UCameraStackBehavior* CreateNonCoreBehavior(TSubclassOf<UCameraStackBehavior> BehaviorClass, UObject* Template);
    
    UFUNCTION(BlueprintCallable)
    UCameraStackBehaviorCore* CreateCoreBehavior(TSubclassOf<UCameraStackBehaviorCore> BehaviorClass, UObject* Template);
    
    UFUNCTION(BlueprintCallable)
    void ClearCameraContext(FName InContextName);
    
};


#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "AudioLayerBehaviorState.h"
#include "OnRagdollHitActorEventSignatureDelegate.h"
#include "RagdollBehaviorComponent.generated.h"

class AActor;
class URagdollBehavior;
class URagdollBehaviorConfigAsset;
class URagdollControlComponent;
class URagdollRecoveryAssistBehavior;
class USkeletalMeshComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RAGDOLL_API URagdollBehaviorComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URagdollBehaviorConfigAsset* Config;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRagdollHitActorEventSignature OnRagdollHitActor;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    URagdollControlComponent* RagdollControlComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URagdollBehavior* CurBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URagdollBehavior* PriorBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URagdollRecoveryAssistBehavior* CurRecoveryAssistBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URagdollRecoveryAssistBehavior* PriorRecoveryAssistBehavior;
    
public:
    URagdollBehaviorComponent();
    UFUNCTION(BlueprintCallable)
    void SetSkeletalMeshComponent(USkeletalMeshComponent* InSkeletalMeshComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    bool IsSensoryStateStatisfied(FName targetSensoryState);
    
    UFUNCTION(BlueprintCallable)
    bool IsPoseStateStatisfied(FName targetPose);
    
    UFUNCTION(BlueprintCallable)
    bool IsGetupAllowed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasValidSetup() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void DoAudioBehaviorChangeEvent(FAudioLayerBehaviorState& rLayerState);
    
};


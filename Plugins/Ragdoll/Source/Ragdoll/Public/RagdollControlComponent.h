#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "EImpactReactionStrength.h"
#include "ERagdollCOMLocationDrivingMode.h"
#include "ERagdollCOMRotationDrivingMode.h"
#include "ERagdollPoseDrivingMode.h"
#include "OnRagdollControlEventSignatureDelegate.h"
#include "RagdollControlPostAnimationTickFunction.h"
#include "Templates/SubclassOf.h"
#include "RagdollControlComponent.generated.h"

class AActor;
class URagdollBehaviorComponent;
class URagdollBehaviorConfigAsset;
class URagdollControlConfig;
class USkeletalMeshComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RAGDOLL_API URagdollControlComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URagdollControlConfig* Config;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URagdollBehaviorComponent> RagdollBehaviorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URagdollBehaviorConfigAsset* RagdollBehaviorConfig;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRagdollControlEventSignature OnBakedRigidBodyAttachedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRagdollControlEventSignature OnBakedRigidbodyRemovedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRagdollControlEventSignature OnFullRagdollStartEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRagdollControlEventSignature OnFullRagdollEndEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRagdollControlPostAnimationTickFunction PostAnimationTickFunction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    URagdollBehaviorComponent* RagdollBehaviorComponent;
    
public:
    URagdollControlComponent();
    UFUNCTION(BlueprintCallable)
    void StartReaction();
    
    UFUNCTION(BlueprintCallable)
    void StartImpactReaction(EImpactReactionStrength InReactionStrength, const FVector& InWorldLocation, const FVector& InWorldDirection, const float InWorldImpactStrength);
    
    UFUNCTION(BlueprintCallable)
    void ShowImpactReaction(EImpactReactionStrength InReactionStrength, const FVector& InWorldLocation, const FVector& InWorldDirection, const float InWorldImpactStrength);
    
    UFUNCTION(BlueprintCallable)
    void SetSkeletalMeshComponent(USkeletalMeshComponent* InSkeletalMeshComponent);
    
    UFUNCTION(BlueprintCallable)
    void SetPoseDrivingMode(ERagdollPoseDrivingMode InPoseDrivingMode, float InBlendDuration);
    
    UFUNCTION(BlueprintCallable)
    void SetOwnerResurrected();
    
    UFUNCTION(BlueprintCallable)
    void SetOwnerIsDead();
    
    UFUNCTION(BlueprintCallable)
    void SetInWater(bool bInWater);
    
    UFUNCTION(BlueprintCallable)
    void SetCOMDrivingModes(ERagdollCOMLocationDrivingMode InLocationDrivingMode, ERagdollCOMRotationDrivingMode InRotationDrivingMode);
    
    UFUNCTION(BlueprintCallable)
    void SetBodyConstraintContext(FName InContextName, bool bInEnable);
    
    UFUNCTION(BlueprintCallable)
    void RemoveBakedRigidbody();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFullRagdoll() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBakedToRigidbody() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasValidSetup() const;
    
    UFUNCTION(BlueprintCallable)
    void ForcePopOutOfRagdollImmediately();
    
    UFUNCTION(BlueprintCallable)
    void DisallowBlendingOutOfRagdollUntilForced();
    
    UFUNCTION(BlueprintCallable)
    void DisableCcd();
    
    UFUNCTION(BlueprintCallable)
    void DeepFreezeWithActor(AActor* InActor, const FName InCollisionProfile);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanGetup() const;
    
    UFUNCTION(BlueprintCallable)
    void BlendBack(bool bInStationaryCapsuleWhileBlending, float InBlendDurationOverride);
    
    UFUNCTION(BlueprintCallable)
    void AttachBakedRigidbody();
    
};


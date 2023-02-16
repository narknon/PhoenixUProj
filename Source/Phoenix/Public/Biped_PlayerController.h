#pragma once
#include "CoreMinimal.h"
#include "Perception/AIPerceptionListenerInterface.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/PlayerController.h"
#include "HermesBPDelegateHandle.h"
#include "ELockOnReticleType.h"
#include "ETargetingMode.h"
#include "ForcedConversation.h"
#include "Templates/SubclassOf.h"
#include "Biped_PlayerController.generated.h"

class AActor;
class AActor_LockOnReticle;
class AAmbulatory_Character;
class AOnScreenObjectIndicator;
class UAISense;
class UAISense_CogGroup;
class UAISense_CogGroup_Aim;
class UAISense_CogGroup_AutoTarget;
class UAISense_CogGroup_Climb;
class UAISense_CogGroup_Interact;
class UAISense_CogGroup_Station;
class UAISense_CogGroup_TargetOfInterest;
class UCogGroupEvaluation;
class UCogGroupFocusDirection;
class UCogGroupPerceiverPoint;
class UCogGroupUpDirection;
class UCognitionComponent;
class UCurveFloat;
class UObject;
class UPlayerInput;

UCLASS(Blueprintable)
class ABiped_PlayerController : public APlayerController, public IAIPerceptionListenerInterface {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesOnForcedConversationDelegate, const UObject*, Caller, const FForcedConversation&, FForcedConversation);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseAutoTargetCameraModes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimModeFarDistanceRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimModeNarrowRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETargetingMode::Type> TargetingMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionComponent* CognitionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAISense> SenseForAutoTargeting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> LockOnReticleActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor_LockOnReticle* LockOnReticleActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LockOnReticleLookAtSpeedScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowLockOn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AOnScreenObjectIndicator> OppugnoIndicatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AOnScreenObjectIndicator* OppugnoIndicatorActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTargetingCameraAllowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoTargetDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReticuleVerticalScreenPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoingAutoTargeting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCogGroupEvaluation*> ShadowBlinkTargetEvaluationArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNearInteractable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CurrentInteractTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InteractionRange;
    
    ABiped_PlayerController();
    UFUNCTION(BlueprintCallable)
    void TutorialAutoTargetBitChanged(bool bNewValue);
    
    UFUNCTION(BlueprintCallable)
    void TargetSighted(UAISense* Sense, const AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    void TargetLost(UAISense* Sense, const AActor* OldTarget);
    
    UFUNCTION(BlueprintCallable)
    void TargetChanged(UAISense* Sense, const AActor* NewTarget, const AActor* OldTarget);
    
    UFUNCTION(BlueprintCallable)
    void StickClick(bool bOnlyOn, bool bOnlyOff);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingSpecialAutoTarget(AActor* InSpecialActor, const UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingAutoTargetAlwaysTargetActor(AActor* InTargetActor, const UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void StartAimModeTimeDilation(const float Dilation, const float EaseIn);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetingMode(const TEnumAsByte<ETargetingMode::Type> InMode, bool bLockOnInAimMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetSpecialAutoTarget(AActor* InSpecialActor) const;
    
    UFUNCTION(BlueprintCallable)
    void SetSenseEnabled(UAISense_CogGroup* InSense, bool bInFlag, bool bInForce);
    
    UFUNCTION(BlueprintCallable)
    void SetOppugnoAlwaysTargetActor(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    void SetInteractStickyTarget(bool bSet);
    
    UFUNCTION(BlueprintCallable)
    void SetCameraRotation(const FRotator& DesiredRotation);
    
    UFUNCTION(BlueprintCallable)
    void SetCameraLookAt_TimeBased(const FVector& LookAtPoint, float LookAtTime);
    
    UFUNCTION(BlueprintCallable)
    void SetCameraLookAt_ActorAndTime(AActor* LookAtActor, float LookAtTime);
    
    UFUNCTION(BlueprintCallable)
    void SetCameraLookAt_Actor(AActor* LookAtActor, float SpeedScalar);
    
    UFUNCTION(BlueprintCallable)
    void SetCameraLookAt(const FVector& LookAtPoint, float SpeedScalar);
    
    UFUNCTION(BlueprintCallable)
    void SetAutoTargetAlwaysTargetActor(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    void ResetCameraRotation(float ResetSpeed, UCurveFloat* ResetSpeedCurve);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseLockFromTarget(ELockOnReticleType InLockOnType);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseCameraLookAt();
    
    UFUNCTION(BlueprintCallable)
    void PawnTeleported(AAmbulatory_Character* TeleportedCharacter, FVector AmountDisplaced, FRotator AmountRotated);
    
    UFUNCTION(BlueprintCallable)
    void OnInteractTargetRegistered(AActor* InTarget);
    
    UFUNCTION(BlueprintCallable)
    void OnCurtainLowered();
    
    UFUNCTION(BlueprintCallable)
    void MaxSpeedChanged(float InSpeed);
    
    UFUNCTION(BlueprintCallable)
    void LockOntoAutoTargetActor(ELockOnReticleType InLockOnType, AActor* AutoTargetActor);
    
    UFUNCTION(BlueprintCallable)
    void IsTargetCritical(AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    bool IsSenseEnabled(UAISense_CogGroup* InSense);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool IsPlayerInAnimagusForm(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    bool IsLockedOntoTarget();
    
    UFUNCTION(BlueprintCallable)
    bool IsActorInBestList(TSubclassOf<UAISense> SenseClass, const AActor* TestActor);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindForcedConversation(FHermesOnForcedConversationDelegate Delegate_OnForcedConversation, const UObject* InOwner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    UAISense_CogGroup_TargetOfInterest* GetTargetOfInterestSense();
    
    UFUNCTION(BlueprintCallable)
    UAISense_CogGroup_Station* GetStationInteractSense();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPlayerInput* GetPlayerInput() const;
    
    UFUNCTION(BlueprintCallable)
    AActor* GetOppugnoAlwaysTargetActor();
    
    UFUNCTION(BlueprintCallable)
    AActor* GetLockedOnActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLastValidMountLocation(FVector& OutLocation) const;
    
    UFUNCTION(BlueprintCallable)
    FRotator GetLastControlRotation();
    
    UFUNCTION(BlueprintCallable)
    UAISense_CogGroup_Interact* GetInteractSense();
    
    UFUNCTION(BlueprintCallable)
    UAISense_CogGroup_Climb* GetClimbSense();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetBestReparoActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetBestOppugnoActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetBestLockOnActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetBestAutoTargetActor_WorldLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetBestAutoTargetActor() const;
    
    UFUNCTION(BlueprintCallable)
    UAISense_CogGroup_AutoTarget* GetAutoTargetSense();
    
    UFUNCTION(BlueprintCallable)
    UAISense_CogGroup_Aim* GetAimSense();
    
    UFUNCTION(BlueprintCallable)
    float GetAimBlendParameter();
    
    UFUNCTION(BlueprintCallable)
    void FullyResetCamera(float ResetSpeed, UCurveFloat* ResetSpeedCurve);
    
    UFUNCTION(BlueprintCallable)
    void FlushInputKeys();
    
    UFUNCTION(BlueprintCallable)
    bool FlickToTarget(FVector2D StickFlickDirection);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingSpecialAutoTarget(const UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingAutoTargetAlwaysTargetActor(const UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void FinishAimModeTimeDilation(const float EaseOut);
    
    UFUNCTION(BlueprintCallable)
    void ClearOppugnoAlwaysTargetActor();
    
    UFUNCTION(BlueprintCallable)
    void ClearAutoTargetAlwaysTargetActor();
    
    UFUNCTION(BlueprintCallable)
    void CanStickReset(bool& bCanReset);
    
    UFUNCTION(BlueprintCallable)
    void AutoTarget_UseShadowBlinkEval();
    
    UFUNCTION(BlueprintCallable)
    void AutoTarget_UseDefaultUpDirectionClass();
    
    UFUNCTION(BlueprintCallable)
    void AutoTarget_UseDefaultPerceiverPointClass();
    
    UFUNCTION(BlueprintCallable)
    void AutoTarget_UseDefaultFocusDirectionClass();
    
    UFUNCTION(BlueprintCallable)
    void AutoTarget_UseDefaultEval();
    
    UFUNCTION(BlueprintCallable)
    void AutoTarget_SetUpDirectionClass(UCogGroupUpDirection* InUpDirectionClass);
    
    UFUNCTION(BlueprintCallable)
    void AutoTarget_SetPerceiverPointClass(UCogGroupPerceiverPoint* InPerceiverPointClass);
    
    UFUNCTION(BlueprintCallable)
    void AutoTarget_SetFocusDirectionClass(UCogGroupFocusDirection* InFocusDirectionClass);
    
    UFUNCTION(BlueprintCallable)
    void AllowLockOn(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void ActivateReparoSense(bool bFlag, bool bForce);
    
    UFUNCTION(BlueprintCallable)
    void ActivateOppugnoSense(bool bFlag, bool bForce);
    
    UFUNCTION(BlueprintCallable)
    void ActivateInteractSense(bool bFlag, bool bForce);
    
    UFUNCTION(BlueprintCallable)
    void ActivateClimbSense(bool bFlag, bool bForce);
    
    UFUNCTION(BlueprintCallable)
    void ActivateAutoTargetSense(bool bFlag, bool bForce);
    
    
    // Fix for true pure virtual functions not being implemented
};


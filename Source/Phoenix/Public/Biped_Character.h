#pragma once
#include "CoreMinimal.h"
#include "Perception/AISightTargetInterface.h"
#include "EClimbingLedgeState.h"
#include "EJumpingType.h"
#include "EStairsState.h"
#include "ETargetID.h"
#include "ETargetSpeedMode.h"
#include "ETargetType.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/PlayerController.h"
#include "Engine/EngineTypes.h"
#include "GameplayProperty_Float.h"
#include "EHoverDroneControlMode.h"
#include "Base_Character.h"
#include "Biped_Character_Interface.h"
#include "EAdditiveBodyState.h"
#include "EFullBodyState.h"
#include "EParryState.h"
#include "EPartialBodyState.h"
#include "ERightArmPriority.h"
#include "ERightArmState.h"
#include "InventoryResult.h"
#include "SpellLoadOutData.h"
#include "Templates/SubclassOf.h"
#include "Biped_Character.generated.h"

class AActor;
class AMunitionType_Base;
class APickupTool;
class ASpellTool;
class ATool;
class AWandTool;
class UAnimationComponent;
class UBTCustomComponent;
class UBipedStateComponent;
class UBlackboardComponent;
class UCognitionStimuliSourceComponent;
class UContextFilterComponent;
class UFacialComponent;
class UObject;
class UPrimitiveComponent;
class URPGAbilityComponent;
class USkeletalMeshComponent;
class USpellToolRecord;
class UToolSetComponent;

UCLASS(Blueprintable)
class PHOENIX_API ABiped_Character : public ABase_Character/*, public IBiped_Character_Interface*/, public IAISightTargetInterface {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnSpellCast, AActor*, Target, FVector, Location, ASpellTool*, Spell, FName, SpellType, AMunitionType_Base*, Munition);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProtegoStart);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProtegoEnd);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnProtegoDeflected, ASpellTool*, Spell);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLumosStart);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLumosEnd);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDisillusionmentStart);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDisillusionmentEnd);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAccioStart, AActor*, Target, FVector, Location);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAccioEnd, AActor*, Target);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UToolSetComponent* ToolSetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CognitionStimuliSourceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBTCustomComponent* BehaviorComp_Primary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBTCustomComponent* BehaviorComp_Secondary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBlackboardComponent* BlackboardComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBipedStateComponent* ObjectStateComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UContextFilterComponent* ContextFilterComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URPGAbilityComponent* RPGAbilityComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFacialComponent* FacialComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationComponent* AnimationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MAX_HEIGHT_FOR_CLIMB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MAX_HEIGHT_FOR_HANG;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MAX_HEIGHT_FOR_JUMPWAIST;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* ledgeActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CrouchCapsuleHalfHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CrouchCapsuleRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CrouchStartCapsuleBlendDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CrouchEndCapsuleBlendDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EParryState::Type> ParryState;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSpellCast OnSpellCast;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLumosStart OnLumosStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLumosEnd OnLumosEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAccioStart OnAccioStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAccioEnd OnAccioEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnProtegoStart OnProtegoStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnProtegoEnd OnProtegoEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnProtegoDeflected OnProtegoDeflected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDisillusionmentStart OnDisillusionmentStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDisillusionmentEnd OnDisillusionmentEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSpellLoadOutData SpellLoadOutData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpellCastHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float DoubleItemAbilityDurationChanceModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float RefreshAllCooldownChanceModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreFallDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAirHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastGroundHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ABiped_Character> m_studentActorClassM;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ABiped_Character> m_studentActorClassF;
    
    ABiped_Character(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ZeroKinematicIntegratorLinearVelocity();
    
    UFUNCTION(BlueprintCallable)
    void ZeroKinematicIntegratorAngularVelocity();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UnEquipWand();
    
    UFUNCTION(BlueprintCallable)
    void StartCrouching(const UObject* Provider, TEnumAsByte<ETargetSpeedMode::Type> SpeedMode, TEnumAsByte<ETargetSpeedMode::Type> SpeedModifier);
    
    UFUNCTION(BlueprintCallable)
    void StairsStateHasChanged(TEnumAsByte<EStairsState::Type> InLastStairsState, TEnumAsByte<EStairsState::Type> InNewStairsState);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetDirection(FVector i_targetDirection);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetDestination(FVector i_targetDestination);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetComponent(UPrimitiveComponent* i_pTargetComponent);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetBoneName(FName i_targetBoneName);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetSpellCastHandle(int32 InSpellCastHandle);
    
    UFUNCTION(BlueprintCallable)
    void SetSpell(int32 Group, int32 Index, USpellToolRecord* Spell);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetRightArmState(ERightArmState::Type InState, ERightArmPriority::Type InPriority, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable)
    void SetRayCastActor(AActor* i_pRayCastActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetPickupTool(APickupTool* InPickupTool);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetPartialBodyState(const TEnumAsByte<EPartialBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetParryState(const TEnumAsByte<EParryState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetFullBodyStateLast(const TEnumAsByte<EFullBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetFullBodyState(const TEnumAsByte<EFullBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetFinisherOptimalRatio(const float OptimalRatio, EDynamicForceFeedbackAction::Type FeedbackAction);
    
    UFUNCTION(BlueprintCallable)
    void SetFinisher(int32 Index, USpellToolRecord* Spell);
    
    UFUNCTION(BlueprintCallable)
    void SetCombatReadyMode(const bool Flag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetAdditiveBodyState(const TEnumAsByte<EAdditiveBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FName ParkourJump(FName DefaultNode);
    
    UFUNCTION(BlueprintCallable)
    void OnHoverDroneControlModeChanged(TEnumAsByte<EHoverDroneControlMode::Type> NewMode);
    
    UFUNCTION(BlueprintCallable)
    void OnEquippedChanged(ATool* ActivatedTool, ATool* DeactivatedTool);
    
    UFUNCTION(BlueprintCallable)
    void Landed(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    bool IsWandEquipped();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsDead();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentLedgeAnOverhang() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsBlockedByWall();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    AWandTool* GetWand() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetToTargetDirection();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetTargetDirection();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FVector GetTargetDestination() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UPrimitiveComponent* GetTargetComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FName GetTargetBoneName();
    
    UFUNCTION(BlueprintCallable)
    bool GetSpellsByGroup(int32 Group, TArray<USpellToolRecord*>& ToolRecordArray);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetSpellCastHandle(int32& OutSpellCastHandle);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    USkeletalMeshComponent* GetSkeletalMesh() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ERightArmState::Type GetRightArmState(ERightArmPriority::Type InPriority);
    
    UFUNCTION(BlueprintCallable)
    AActor* GetRayCastActor();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetPutdownToolHeight();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetPickupToolHeight();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    APickupTool* GetPickupTool();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetPartialBodyState(TEnumAsByte<EPartialBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetParryState(TEnumAsByte<EParryState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetOriginalLedgeTransform() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AActor* GetLockedOnActor();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FInventoryResult GetInventoryResult();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AActor* GetHighlitActor();
    
    UFUNCTION(BlueprintCallable)
    float GetHealth();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetFullBodyStateLast(TEnumAsByte<EFullBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetFullBodyState(TEnumAsByte<EFullBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable)
    bool GetFinishers(TArray<USpellToolRecord*>& ToolRecordArray);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetCharacterID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AActor* GetBestLockOnActor();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AActor* GetBestAutoTargetActor();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetAutoTargetUpDirection();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetAutoTargetFocusDirection();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetAdditiveBodyState(TEnumAsByte<EAdditiveBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable)
    void FinishCrouching(const UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void FacingTargetsListIsNowEmpty(TEnumAsByte<ETargetType::Type> LastTargetType, TEnumAsByte<ETargetID::Type> LastTargetID);
    
    UFUNCTION(BlueprintCallable)
    void FacingNotifyOfNewBestTarget(TEnumAsByte<ETargetType::Type> NewTargetType, TEnumAsByte<ETargetID::Type> NewTargetID);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void EquipWand();
    
    UFUNCTION(BlueprintCallable)
    void EnablePawnInteraction(const bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    bool DetectFallIntoWater();
    
    UFUNCTION(BlueprintCallable)
    bool DetectDiveIntoWater();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ComputeAttack(AActor*& TargetActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float ComputeAngleToDesiredDirection();
    
    UFUNCTION(BlueprintCallable)
    void ClimbLedgeStart();
    
    UFUNCTION(BlueprintCallable)
    void ClimbLedgeEnd();
    
    UFUNCTION(BlueprintCallable)
    void CleanUpFinisherSpell();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanLandOnLedge() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void CancelCurrentSpell(bool RemoveDisillusionment) const;
    
    UFUNCTION(BlueprintCallable)
    void CalculateLedgePullUpState(TEnumAsByte<EClimbingLedgeState::Type>& OutState, TEnumAsByte<EJumpingType::Type>& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void CalculateClimbingLedgeState(TEnumAsByte<EClimbingLedgeState::Type>& OutState, TEnumAsByte<EJumpingType::Type>& OutType);
    
    UFUNCTION(BlueprintCallable)
    bool AdjustHealth(float change, bool bDontKill);
    
    
    // Fix for true pure virtual functions not being implemented
};


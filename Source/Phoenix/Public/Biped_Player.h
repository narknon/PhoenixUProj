#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/Scene.h"
#include "Name_GameLogicVarBool.h"
#include "Name_GameLogicVarInt32.h"
#include "GameplayProperty_Float.h"
#include "GameplayProperty_Int.h"
#include "GameplayTagContainer.h"
#include "ECustomInterpType.h"
#include "Biped_Character.h"
#include "CharacterMount_Interface.h"
#include "ECharacterDeathType.h"
#include "EComboType.h"
#include "EEdgeState.h"
#include "EEnemy_ParryButtonPressed.h"
#include "EGenderPronoun.h"
#include "ENPC_TargetAwareState.h"
#include "ESpellCategory.h"
#include "EWandLinkResult.h"
#include "GearItem.h"
#include "OnClothTargetsEndDelegate.h"
#include "OnClothTargetsStartDelegate.h"
#include "SocialHeritageStatusIDs.h"
#include "SpellCooldownData.h"
#include "StationInteractor_Interface.h"
#include "Templates/SubclassOf.h"
#include "VendorTransactionInfo.h"
#include "Biped_Player.generated.h"

class AActor;
class ABiped_Player;
class AFieldGuideHotSpot;
class APlayer_AttackIndicator;
class ASocialReasoning;
class AStation;
class UAISense;
class UAblAbility;
class UAkAudioEvent;
class UAkComponent;
class UBiped_AnimInstance;
class UCameraComponent;
class UConversationComponent;
class UCurveFloat;
class UCustomizableCharacterComponent;
class UInteractionArchitectAsset;
class UInventoryItemToolRecord;
class UMaterialInstanceDynamic;
class UMultiFX2_Base;
class UObject;
class USpellToolRecord;
class USplineComponent;
class UStickFlickWatcherRecord;
class UToolSetComponent;
class UVegetationInteractionComponent;

UCLASS(Blueprintable)
class PHOENIX_API ABiped_Player : public ABiped_Character, public IStationInteractor_Interface, public ICharacterMount_Interface {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStationInteractionExitComplete);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnTeleportTo, FVector, PrevLocation, FRotator, PrevRotation, bool, bIsATest, bool, bNoCheck, bool, bSuccess);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSpellCooldownChanged, FName, SpellName, float, CooldownPct);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFocusChanged, AActor*, Target, float, InFocusChange);
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UConversationComponent* ConversationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterComponent* Customization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASocialReasoning* PlayerSocialReasoning;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UToolSetComponent* InventoryToolSetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowFastWalk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* WalkSlowModeSpeedCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* WalkModeSpeedCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* WalkOnlyModeSpeedCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* WalkFastModeSpeedCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* WalkFastOnlyModeSpeedCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* JogModeSpeedCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* JogOnlyModeSpeedCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* SprintModeSpeedCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* JogModeSpeedGovernorCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* GryffindorMaleBedAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* GryffindorFemaleBedAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* RavenClawMaleBedAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* RavenClawFemaleBedAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* HufflePuffMaleBedAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* HufflePuffFemaleBedAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* SlytherinMaleBedAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* SlytherinFemaleBedAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APlayer_AttackIndicator> AttackIndicatorActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlayer_AttackIndicator* AttackIndicatorActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerDeadZoneMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerDeadZoneMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterDeadZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EEdgeState::Type> EdgeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector EdgeLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector EdgeNormal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EdgeDistanceToGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EdgeDistanceFromEdge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector EdgeImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SyncToSplineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SyncToSplineDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SyncToSplineDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> DefaultIdleAbility;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxChompingCabbage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxVenomousTentacula;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowPlayerCamContorlOnOtherActorCam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InvertCameraPitchControl;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InvertCameraYawControl;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InvertMoveLeftRightControl;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InvertMoveForwardBackControl;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableFadeSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AFieldGuideHotSpot* PlayerInThisFieldGuideHotSpot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FinisherDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ElderWandFinisherDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFocus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InitialNumBarsFilled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FinisherFocusCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ManagedFinisherFocusCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PushFocusCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> FocusMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FinisherAvailableFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ComboResetTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalComboResetTimeOnParry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CooldownPickupFirstTierSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CooldownPickupTierSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> CooldownPickupCountArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtendedCombatTime;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnClothTargetsStart ClothTargetsStartDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnClothTargetsEnd ClothTargetsEndDelegate;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthIncreasePerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LeftFootSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RightFootSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* LeftStickMagWalkingCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* LeftStickMagJoggingCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BulletTimeStartSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* BulletTimeDilationCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BulletTimeDurationSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BulletTimeDialation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CutBackToPlayerCamAfterTimeDialationSec;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeightedBlendable DamageEffectBlendable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* DamageEffectMaterialInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* DamageEffectCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageEffectDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageEffectScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> CriticalHealthFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CriticalHealthPulseTimeCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> CriticalHealthPulseFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CriticalHealthFadeOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> DamageDirectionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentHealthRecoverdPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SecondsAfterCombatBeforeRecoveryStarts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoDamageOnNextLanding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseDodgeCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InHoverDrone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLookAtHips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float cameraOffsetScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLockOutPlayerCamControl;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLockOutPlayerCamControlPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FGearItem> CachedGearPieces;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float OffenseStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float DefenseStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float CooldownStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Int InventorySizeModification;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float HiddenAfterTakedownTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float StatDamageMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float StatDamageReduction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float StatCooldownReduction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float GainKnowledgeModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float GainExperienceModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float CompanionBondingPointsModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float VendorPricesModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float EnemyEvadeChanceModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float EnemyProtegoChanceModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float EnemyAwarenessRateModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float CriticalSuccessChanceModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float LootDropCountModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float LootDropRareChanceModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float StealRateModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float CaptureToolRangeModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float CaptureToolDecayPenaltyModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float CaptureToolCaptureSpeedModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float CreatureAgroFleeDistanceModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float FocusModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float FocusOnHitModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float UseConsumeableForFreeChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float UsePotionForFreeChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Int ObscurePerkDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float MaliciousPerkMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float ExpelliarmusLootDropChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Int CombatAuxPerk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float CombatAuxPerkDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float CombatAuxPerkCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Int DirectAIPerk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Int ExtendedCompanionInventoryCapacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float PlantDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float VenomousTentaculaPoisonDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float VenomousTentaculaWeakenEnemyDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float HealingCooldownGroupModifier;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> LastStupefyTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float CabbageVampireModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float PlantDamageFocus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float PlayerStupifyPlantDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float MandrakeBonusReactionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float PlantSummonHealthPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float DifficultyAttackCooldownModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float DisillusionmentModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float CrimeSceneInvestigationModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float SneakOScopeWindupModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float SilencioRangeModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowEdgeCheck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInCombatMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInCombatModeDelayed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* FollowActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CautiousMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Int BonusAncientMagicBars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Int BonusSpellLoadouts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InStealthMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInvisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InCinematic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWandLinkResult WandLinkResult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHoldingProtegoParry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> EnemyDetectionFXClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* EnemyDetectionSFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* EnemyAlertSFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* EnemyAggroSFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSpellCooldownChanged OnSpellCooldownChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusChanged OnFocusChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FSpellCooldownData> CooldownMap;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStationInteractionExitComplete OnStationInteractionExitComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DesiredFocusDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDesiredFocusDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVegetationInteractionComponent* VegetationInteraction;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTeleportTo OnTeleportTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> LastCriticalFinisher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeoutLookAtCameraDirection;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* MotionListenerCameraOrientation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* MotionListenerPlayerOrientation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* DamageDirectionActor;
    
public:
    ABiped_Player();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool UseNewConversations() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool UseInventoryItemByName(FName InventoryObjectID, FName HolderID);
    
    UFUNCTION(BlueprintCallable)
    void UseFinisherFocus();
    
    UFUNCTION(BlueprintCallable)
    void UpdateFinsherAvailableFX();
    
    UFUNCTION(BlueprintCallable)
    void UpdateDifficulty();
    
    UFUNCTION(BlueprintCallable)
    void UpdateCamMove(float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    bool ToadStatueTeleport(const AActor* InDestinationActor, const FVector InOffset);
    
    UFUNCTION(BlueprintCallable)
    void TargetSighted(UAISense* Sense, const AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    void TargetLost(UAISense* Sense, const AActor* OldTarget);
    
    UFUNCTION(BlueprintCallable)
    void TargetChanged(UAISense* Sense, const AActor* NewTarget, const AActor* OldTarget);
    
    UFUNCTION(BlueprintCallable)
    void SuspendStoryModeArmor(bool bFlag);
    
protected:
    UFUNCTION(BlueprintCallable)
    bool StopPlayerInput();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StopMove();
    
    UFUNCTION(BlueprintCallable)
    AActor* StartCriticalFinisher();
    
    UFUNCTION(BlueprintCallable)
    void StartBulletTime(float Dilation, float Duration, bool DoFixedCam, float PlayerDilation, float EaseInDuration, float EaseOutDuration);
    
    UFUNCTION(BlueprintCallable)
    void SpawnRockSlide(UClass* InActorClass, float ProjectForward);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SpawnItemMountCallback(UInventoryItemToolRecord* InToolRecord);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AActor* SpawnFaceTarget(TSubclassOf<AActor> SpawnActorClass);
    
    UFUNCTION(BlueprintCallable)
    bool ShadowBlinkTeleport(const AActor* InBlinkTarget, const float InBlinkDistanceFromTarget, const bool bIsGate, const bool bIsStealth, FVector& OutBlinkLocation, FRotator& OutBlinkRotation);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetWandStyle(FName WandStyle);
    
    UFUNCTION(BlueprintCallable)
    void SetWandBaseStyle(FName InWandBase);
    
    UFUNCTION(BlueprintCallable)
    void SetUsingElderWand(bool bUsing);
    
    UFUNCTION(BlueprintCallable)
    void SetStartingMovementTime(const float InStartingMovementTime);
    
    UFUNCTION(BlueprintCallable)
    static bool SetPlayerSocialHeritage(TEnumAsByte<SocialHeritageStatusIDs> NewHeritage);
    
    UFUNCTION(BlueprintCallable)
    static bool SetPlayerGenderPronoun(EGenderPronoun NewGenderPronoun);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetPhoenixCameraRotation(const FRotator& DesiredRotation);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetPhoenixCameraLookAt_TimeBased(const FVector& LookAtPoint, float LookAtTime);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetPhoenixCameraLookAt_ActorAndTime(AActor* LookAtActor, float LookAtTime);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetPhoenixCameraLookAt_Actor(AActor* LookAtActor, float ScaleSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetPhoenixCameraLookAt(const FVector& LookAtPoint, float ScaleSpeed);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetOverrideWandStyle(FName WandStyle);
    
    UFUNCTION(BlueprintCallable)
    void SetMotionListener(UAkComponent* AkComponent, bool PlayerOrientation);
    
    UFUNCTION(BlueprintCallable)
    void SetManagedAM(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetLastSafeInteractLocation(FVector Location);
    
    UFUNCTION(BlueprintCallable)
    void SetLastEdgeState(EEdgeState::Type InEdgeState);
    
    UFUNCTION(BlueprintCallable)
    void SetInvulnerableTime(float invulnerableTime);
    
    UFUNCTION(BlueprintCallable)
    void SetInvulnerable(bool bInInvulnerable);
    
    UFUNCTION(BlueprintCallable)
    void SetInteractStickyTarget(bool bSet);
    
    UFUNCTION(BlueprintCallable)
    void SetInLockOnMode(const bool bInFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetHighlitActor(AActor* InHighlitActor);
    
    UFUNCTION(BlueprintCallable)
    void SetFieldGuideHotSpot(AFieldGuideHotSpot* InFieldGuideHotSpot);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetDodgeDirection();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetDisableCombatPlantHideOnSuspendEnemies(bool bInVal);
    
    UFUNCTION(BlueprintCallable)
    void SetCooldownRateScale(float RateScale);
    
    UFUNCTION(BlueprintCallable)
    void SetCauseOfDeath(const ECharacterDeathType InCauseOfDeath);
    
    UFUNCTION(BlueprintCallable)
    static void SetCameraStyle(FName CameraStyle);
    
    UFUNCTION(BlueprintCallable)
    void SetAutoTargetingDirection(FVector InWorldDirection);
    
    UFUNCTION(BlueprintCallable)
    void SetAccessibilitySpellToggle(bool ToggleOn);
    
    UFUNCTION(BlueprintCallable)
    AActor* Set_WandCast_TargetTrackerTargets(bool bIgnoreTargets, AActor* InTargetOverride, FVector InTargetOverrideWorldLocation);
    
    UFUNCTION(BlueprintCallable)
    void SendCriticalMunitionImpactToTarget(AActor* TargetActor, const FName UniqueTag, const TArray<UInteractionArchitectAsset*>& MunitionDataAssets, const FGameplayTagContainer& MunitionTagContainer, const float Damage);
    
    UFUNCTION(BlueprintCallable)
    bool SafeTeleportTo(const FVector& DestLocation, const FRotator& DestRotation, bool bIsATest, bool bNoCheck);
    
protected:
    UFUNCTION(BlueprintCallable)
    bool RestorePlayerInput();
    
public:
    UFUNCTION(BlueprintCallable)
    void RestoreHealth();
    
    UFUNCTION(BlueprintCallable)
    void RestartComboTimeout();
    
    UFUNCTION(BlueprintCallable)
    void ResetStickTime();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ResetPhoenixCameraRotation(float ResetSpeed, UCurveFloat* ResetSpeedCurve);
    
    UFUNCTION(BlueprintCallable)
    void ResetComboPoints();
    
    UFUNCTION(BlueprintCallable)
    void ResetCloth();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RequestStick(float StickX, float StickY);
    
    UFUNCTION(BlueprintCallable)
    void RepairOrientation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ReleasePhoenixCameraLookAt();
    
    UFUNCTION(BlueprintCallable)
    void RecordSafeLocation();
    
    UFUNCTION(BlueprintCallable)
    void RecordSafeInteractLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool QuickActionInteract(int32 Index);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PutPlayerIntoCinematicState(bool bFlag, bool bAlterAbilities);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void PushDisableStack(FName_GameLogicVarInt32 StackName);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ProcessStick(float StickX, float StickY, const float DeltaTime, const UCurveFloat* DeadZoneCurve, const UCurveFloat* SpeedCurve, const UCurveFloat* SpeedGovernorCurve, float& WorldSpeed, FVector& WorldDirection, ECustomInterpType::Type InterpType, float InterpSpeed, float StickMagReductionDelayTimer);
    
    UFUNCTION(BlueprintCallable)
    bool ProcessFollowTarget(AActor* InFollowActor, const UCurveFloat* SpeedCurve, float& OutWorldSpeed, FVector& OutWorldDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void PopDisableStack(FName_GameLogicVarInt32 StackName);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PlayerGetOutOfBed(AStation* BedStation, UClass* PlayerBedAbility);
    
    UFUNCTION(BlueprintCallable)
    bool PlacePlayerInBed(AStation*& BedStation, UClass*& PlayerBedAbility);
    
public:
    UFUNCTION(BlueprintCallable)
    bool PlaceOnGround(const float DownDistance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PauseMenuStart();
    
    UFUNCTION(BlueprintCallable)
    void PauseComboTimeout();
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnQuickItemSlotted(const UObject* InCaller, const FName& ItemName);
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame(const UObject* InCaller, const bool bInIsIntro);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnCurtainRaised();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCharacterLoadComplete(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnBlackboardInitialized(const bool bSuccess);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnAboutToSaveGame();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnAbilityAnimationBecameActive();
    
public:
    UFUNCTION(BlueprintCallable)
    void NotifySucessfulBlock();
    
    UFUNCTION(BlueprintCallable)
    void NotifyDodgeFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void LockOnCamFlick(UStickFlickWatcherRecord* InStickFlickWatcherRecord);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void LockOnCameraMoving(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    bool LoadInventoryItemByName(FName InventoryObjectID, FName HolderID);
    
    UFUNCTION(BlueprintCallable)
    void LevelUp();
    
protected:
    UFUNCTION(BlueprintCallable)
    void LEDDamageEffect(AActor* InActor, AActor* InInstigator, float InDamage, const FHitResult& InHit);
    
public:
    UFUNCTION(BlueprintCallable)
    void LeafNodeSwitched();
    
    UFUNCTION(BlueprintCallable)
    bool IsVenomousTentaculaAtMax();
    
    UFUNCTION(BlueprintCallable)
    bool IsSwimming();
    
    UFUNCTION(BlueprintCallable)
    bool IsPlayingIntro();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPerfectRetaliate() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsManagedAMEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsLockedOn();
    
    UFUNCTION(BlueprintCallable)
    bool IsInventoryItemHighlighted();
    
    UFUNCTION(BlueprintCallable)
    bool IsInLockOnMode();
    
    UFUNCTION(BlueprintCallable)
    bool IsHoverDroneActive();
    
    UFUNCTION(BlueprintCallable)
    bool IsFinisherAvailable();
    
    UFUNCTION(BlueprintCallable)
    bool IsCrawling();
    
    UFUNCTION(BlueprintCallable)
    bool IsChompingCabbageAtMax();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCameraMoving() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsAMPushAvailable();
    
    UFUNCTION(BlueprintCallable)
    void InteractingWithActor(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool InstaUseInventoryItem();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool InLockOnMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool InCombatModeDelayed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool InCombatMode() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    bool IgnoreRetaliateTarget(AActor* RetaliateTarget);
    
    UFUNCTION(BlueprintCallable)
    void HighestEnemyChanged(AActor* InEnemyActor, int32 InLevelDiff);
    
public:
    UFUNCTION(BlueprintCallable)
    void HideReticle(bool bHide);
    
    UFUNCTION(BlueprintCallable)
    bool HasMandrakeTalent();
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleVenomousTentaculaCountChanged();
    
public:
    UFUNCTION(BlueprintCallable)
    bool HandleDodgeUnblockable(AActor*& OutAttacker);
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleChompingCabbageCountChanged();
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetWandStyle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetWandBaseStyle() const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetVenomousTentaculaMax();
    
    UFUNCTION(BlueprintCallable)
    int32 GetVenomousTentaculaCount();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ABiped_Player* GetTheBipedPlayer();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UCurveFloat* GetSpeedGovernorCurve();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UCurveFloat* GetSpeedCurve(bool& bIgnoreGovernor);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<SocialHeritageStatusIDs> GetPlayerSocialHeritage();
    
    UFUNCTION(BlueprintCallable)
    float GetPlayerMovementDuration();
    
    UFUNCTION(BlueprintCallable)
    static float GetPlayerLastUsedItemEffectiveness();
    
    UFUNCTION(BlueprintCallable)
    static EGenderPronoun GetPlayerGenderPronoun();
    
    UFUNCTION(BlueprintCallable)
    int32 GetPlantCount(const FString& trackerName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetOffenseStat();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetMoveStickValues(float& X, float& Y) const;
    
    UFUNCTION(BlueprintCallable)
    UAkComponent* GetMotionListenerPlayerOrientation();
    
    UFUNCTION(BlueprintCallable)
    UAkComponent* GetMotionListenerCameraOrientation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxFocus() const;
    
    UFUNCTION(BlueprintCallable)
    FVector GetLastSafeLocation();
    
    UFUNCTION(BlueprintCallable)
    FVector GetLastSafeInteractLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsOnAMountOrInTransition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetInventorySizeModification();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHiddenAfterTakedownTime();
    
    UFUNCTION(BlueprintCallable)
    bool GetGameLogicBoolVariable(FName_GameLogicVarBool BoolVar);
    
    UFUNCTION(BlueprintCallable)
    float GetFocusPercent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFocus() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFinisherDamage() const;
    
    UFUNCTION(BlueprintCallable)
    float GetExpectedDistanceFromTarget(bool bIgnoreTargets, AActor* InTargetOverride, bool& bFound, FVector& ToTarget);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDefenseStat();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentCriticalHealthFadeOutPercent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCooldownStat();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCooldownRateScale() const;
    
    UFUNCTION(BlueprintCallable)
    float GetCooldownPercentByName(FName SpellName);
    
    UFUNCTION(BlueprintCallable)
    float GetCooldownPercent(USpellToolRecord* InSpellToolRecord);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetConsecutiveEnemyHits() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCompanionsAtMaxLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetComboPoints() const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetChompingCabbageMax();
    
    UFUNCTION(BlueprintCallable)
    int32 GetChompingCabbageCount();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECharacterDeathType GetCauseOfDeath();
    
    UFUNCTION(BlueprintCallable)
    int32 GetBonusSpellLoadouts();
    
    UFUNCTION(BlueprintCallable)
    int32 GetBonusAncientMagicBars();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBiped_AnimInstance* GetBipedAnimInstance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetBestLockOnActor_WorldLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetBestLockOnActor_ScreenLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetBestAutoTargetActor_WorldLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBaseOffenseStat() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBaseDefenseStat() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBaseCooldownStat() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAccessibilitySpellToggle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FullyResetPhoenixCamera(float ResetSpeed, UCurveFloat* ResetSpeedCurve);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ForceEndDisillusionment();
    
public:
    UFUNCTION(BlueprintCallable)
    void EndCriticalFinisher(AActor* InTargetActor);
    
    UFUNCTION(BlueprintCallable)
    void EndBulletTime(float EaseOutDuration);
    
    UFUNCTION(BlueprintCallable)
    void EnableManagedAM(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    static void DisablePlayerHealthRecovery(bool bDisable);
    
    UFUNCTION(BlueprintCallable)
    void DisableCooldownPickups(bool bDisable);
    
    UFUNCTION(BlueprintCallable)
    void DetectEdgeChange(FVector TestActorLocation, float TraceRadius, bool bSendEvents, bool bDebugDraw);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DEBUG_SetGlobalTimeDilation(const UObject* WorldContextObject, float TimeDilation);
    
protected:
    UFUNCTION(BlueprintCallable)
    void DamageDirectionEffect(AActor* InActor, AActor* InInstigator, float InDamage, const FHitResult& InHit);
    
public:
    UFUNCTION(BlueprintCallable)
    bool CreateLinkToAttackingActor(const EEnemy_ParryButtonPressed ParryEventReason, bool& bOutDodgeWindow);
    
    UFUNCTION(BlueprintCallable)
    void ComputeAimOffset(const FName BoneName, float& Pitch, float& Yaw);
    
    UFUNCTION(BlueprintCallable)
    void CognitionTargetPlayerAwareStateChanged(ENPC_TargetAwareState InAwareState);
    
    UFUNCTION(BlueprintCallable)
    void CognitionTargetHealthChanged(AActor* Target, float InHealthChanged, bool bIndicateHUD);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ClearStick();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ClearOverrideWandStyle();
    
    UFUNCTION(BlueprintCallable)
    void ClearInvulnerable();
    
    UFUNCTION(BlueprintCallable)
    static void ClearCustomCameras();
    
    UFUNCTION(BlueprintCallable)
    void ChangeManagedAM(float change);
    
    UFUNCTION(BlueprintCallable)
    void CameraStickLastMovedChanged(bool InCameraStickMoved);
    
    UFUNCTION(BlueprintCallable)
    float CalculateVendorPricesModifier(const FVendorTransactionInfo& Info);
    
    UFUNCTION(BlueprintCallable)
    float CalculateStealRateModifier();
    
    UFUNCTION(BlueprintCallable)
    float CalculateSneakOScopeWindupModifier();
    
    UFUNCTION(BlueprintCallable)
    float CalculateSilencioRangeModifier();
    
    UFUNCTION(BlueprintCallable)
    float CalculatePlantDamageModifier(FName DbId);
    
    UFUNCTION(BlueprintCallable)
    float CalculateMandrakeBonusReaction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector CalculateLookAtDirection();
    
    UFUNCTION(BlueprintCallable)
    int32 CalculateExtendedCompanionInventoryCapacity();
    
    UFUNCTION(BlueprintCallable)
    bool AutoNavToTarget(AActor* InTarget, const float InSpeed, const float DistanceFromTarget);
    
    UFUNCTION(BlueprintCallable)
    bool AllowStop(const float InWorldSpeed, const FVector InWorldDirection, float DeltaTime, float MinTime);
    
    UFUNCTION(BlueprintCallable)
    bool AllowMove(const float InWorldSpeed, const FVector InWorldDirection, float DeltaTime, float MinTime);
    
    UFUNCTION(BlueprintCallable)
    void AdjustFocusByName(FName Name, float ExternalFocusModifier);
    
    UFUNCTION(BlueprintCallable)
    void AdjustFocus(float change, float ExternalFocusModifier);
    
    UFUNCTION(BlueprintCallable)
    void AdjustCooldownsByCategory(float Time, ESpellCategory SpellCategory);
    
    UFUNCTION(BlueprintCallable)
    void AdjustCooldown(FName SpellName, float Time, bool AddIfNoneExists);
    
    UFUNCTION(BlueprintCallable)
    void AdjustComboPoints(EComboType ComboType, AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    static void AddCustomCamera(UCameraComponent* customCam, float weight);
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    void SetClothTargetsStartDelegate(const FOnClothTargetsStart& Delegate) override PURE_VIRTUAL(SetClothTargetsStartDelegate,);
    
    UFUNCTION(BlueprintCallable)
    void SetClothTargetsEndDelegate(const FOnClothTargetsEnd& Delegate) override PURE_VIRTUAL(SetClothTargetsEndDelegate,);
    
};


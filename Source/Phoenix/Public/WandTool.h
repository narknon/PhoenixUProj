#pragma once
#include "CoreMinimal.h"
#include "EWandCastType.h"
#include "BTCustomAction.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "ComboSplitData.h"
#include "DialogueConversationReference.h"
#include "ERightArmState.h"
#include "ItemTool.h"
#include "Templates/SubclassOf.h"
#include "WandTool.generated.h"

class AActor;
class AFlyingBook;
class AProtegoSpellTool;
class ASpellTool;
class ATool;
class UAblAbility;
class UAkAudioEvent;
class UButtonWatcherRecord;
class UMeshComponent;
class UNiagaraSystem;
class UReticule;
class USpellToolRecord;
class UToolSetComponent;
class UTriggerEffect;

UCLASS(Blueprintable)
class AWandTool : public AItemTool {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpellCast, ASpellTool*, SpellTool);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSpellCast OnSpellCast;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSpellCast OnSpellStop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UButtonWatcherRecord* SpellButtonWatcher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* EquipExecutionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* UnequipExecutionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* HoldExecutionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* HandOnlyAbleExecutionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* SpecialAbleExecutionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* TargetSightedExecutionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* AlertedExecutionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* HeavyAnticipationExecutionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* StartLumosExecutionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* ChannelingExecutionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* WandCastFailExecutionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* WandCastFailMoveExecutionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTagContainer> ComboAnimationTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> NextLightCastAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> NextHeavyCastAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> StartingCasualLightCastAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> StartingCombatLightCastAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_chargeEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_chargeTimeUpgrade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_chargeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_fireEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_fireRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* m_failDueToCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueConversationReference m_failDueToCooldownDialogEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* m_failDueToCooldownVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFinishersActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBTCustomAction ProtegoAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeleeRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeleeHalfAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* SpellBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* SpellBlockDH;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* SpellPewPew;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* SpellPewPewDH;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* StealthAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AvailableSpellLoadoutIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* ProtegoRetaliateSpell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<AFlyingBook*> BooksList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTriggerEffect> RightTriggerDefaultEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTriggerEffect> LeftTriggerDefaultEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USpellToolRecord*> PreloadSpells;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USpellToolRecord*> DeathlyHallowPreloadSpells;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTriggerEffect* pRightTriggerDefaultEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTriggerEffect* pLeftTriggerDefaultEffect;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UToolSetComponent* ToolSetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<USpellToolRecord*, ASpellTool*> SpellToolMap;
    
public:
    AWandTool();
    UFUNCTION(BlueprintCallable)
    void WandCastFailedTimerExpired();
    
    UFUNCTION(BlueprintCallable)
    void TurnOnTriggerEffects();
    
    UFUNCTION(BlueprintCallable)
    void TurnOffTriggerEffects();
    
    UFUNCTION(BlueprintCallable)
    void TargetSpellSelected(bool Immediate);
    
    UFUNCTION(BlueprintCallable)
    bool StopLastSpell(ASpellTool* NewSpellTool, bool& OutAlreadyActivated);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartHeavyComboSplitTimer(FComboSplitData ComboSplitData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartComboSplitTimer(FComboSplitData ComboSplitData);
    
    UFUNCTION(BlueprintCallable)
    void SpellPreload();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetWandStyle(FName WandStyle);
    
    UFUNCTION(BlueprintCallable)
    void SetProjectileSpeedMultiplier(float Multiplier);
    
    UFUNCTION(BlueprintCallable)
    void SetNextWandCastType(EWandCastType::Type WandCastState);
    
    UFUNCTION(BlueprintCallable)
    void SetNextLightCastAbility(TSubclassOf<UAblAbility> InAbility);
    
    UFUNCTION(BlueprintCallable)
    void SetNextHeavyCastAbility(TSubclassOf<UAblAbility> InAbility);
    
    UFUNCTION(BlueprintCallable)
    void SetFinishersActive(bool bActive);
    
    UFUNCTION(BlueprintCallable)
    void SetContextsOnBarSpell(int32 Index, bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetAttackingActor(AActor* i_attackingActor);
    
    UFUNCTION(BlueprintCallable)
    void SetAimTransform(FVector Target);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResetLightCombo();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResetHeavyCombo();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResetCombos();
    
    UFUNCTION(BlueprintCallable)
    void ResetComboOnBranch();
    
    UFUNCTION(BlueprintCallable)
    void RemoveCollectibleBook(AFlyingBook* book);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSpellLoaded(USpellToolRecord* SpellToolRecord);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnSpellCasted();
    
    UFUNCTION(BlueprintCallable)
    void OnSpell_Released(const int32 SpellSlot);
    
    UFUNCTION(BlueprintCallable)
    void OnSpell_Pressed(const int32 SpellSlot);
    
    UFUNCTION(BlueprintCallable)
    void OnRightArmStateChanged(ERightArmState::Type RightArmState, ERightArmState::Type LastRightArmState);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCharacterLoadComplete(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnActiveSpellToolChanged(ATool* ActivatedSpell, ATool* DeactivatedSpell);
    
public:
    UFUNCTION(BlueprintCallable)
    static bool LoadSpellByName(AActor* InActor, const FString& Spell, bool Async, bool HighPriority);
    
    UFUNCTION(BlueprintCallable)
    static bool LoadAllSlottedSpells(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static bool LoadAllAccessibleSpells(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    bool IsSpellToolAvailable(USpellToolRecord* SpellToolRecord, bool bImmediate);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UMeshComponent* GetWandMesh();
    
    UFUNCTION(BlueprintCallable)
    int32 GetTargetSpellIndex();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASpellTool* GetSpellTool(USpellToolRecord* SpellToolRecord) const;
    
    UFUNCTION(BlueprintCallable)
    USpellToolRecord* GetSpellRecordFromSlot(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    UReticule* GetReticleWidget();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AProtegoSpellTool* GetProtegoSpellTool();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetProjectileSpeedMultiplier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASpellTool* GetFinisherSpellTool(const int32 SpellSlot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASpellTool* GetActiveSpellTool() const;
    
    UFUNCTION(BlueprintCallable)
    void EndSpellCast(ASpellTool*& InSpellTool);
    
    UFUNCTION(BlueprintCallable)
    void ComputeParryAimTransform();
    
    UFUNCTION(BlueprintCallable)
    bool CheckRequiredPerks(const FGameplayTagContainer& PerkContainer);
    
    UFUNCTION(BlueprintCallable)
    bool CastStealthTakedown();
    
    UFUNCTION(BlueprintCallable)
    bool CastSpell(ASpellTool* InSpellTool, bool bImmediate);
    
    UFUNCTION(BlueprintCallable)
    bool CastPewPewSpell();
    
    UFUNCTION(BlueprintCallable)
    bool CastActiveSpell();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CancelHeavyComboSplitTimer();
    
    UFUNCTION(BlueprintCallable)
    void CancelCurrentSpell();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CancelComboSplitTimer();
    
    UFUNCTION(BlueprintCallable)
    bool BlockStart();
    
    UFUNCTION(BlueprintCallable)
    void BlockEnd();
    
    UFUNCTION(BlueprintCallable)
    static void BarItemSelected(AActor* InActor, int32 Index, bool bFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreFinishersActive() const;
    
    UFUNCTION(BlueprintCallable)
    static bool AreAllSlottedSpellsLoaded(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static bool AreAllAccessibleSpellsLoaded(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    void ApplyTriggerEffectDefault(bool RightTrigger, bool LeftTrigger);
    
    UFUNCTION(BlueprintCallable)
    void AddCollectibleBook(AFlyingBook* book);
    
    UFUNCTION(BlueprintCallable)
    ASpellTool* ActivateSpellTool(USpellToolRecord* SpellToolRecord, bool bImmediate);
    
    UFUNCTION(BlueprintCallable)
    bool ActivateInstantSpellTool(int32 Index);
    
};


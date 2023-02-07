#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EInteractiveState.h"
#include "AnalyticsManager.generated.h"

class AActor;
class UAnalyticsManager;

UCLASS(Blueprintable)
class UAnalyticsManager : public UObject {
    GENERATED_BODY()
public:
    UAnalyticsManager();
    UFUNCTION(BlueprintCallable)
    static void SetUsingFloo(const bool UsingFloo);
    
    UFUNCTION(BlueprintCallable)
    static void SetSaveSlot(const int32 SaveSlot);
    
    UFUNCTION(BlueprintCallable)
    static void SetNaturalPlaythrough(const bool bNatural);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    static void HeartbeatUpdateMountState(const FString& MountType);
    
    UFUNCTION(BlueprintCallable)
    static void HandleSphinxPuzzle(const FString& Name, const FString& Type, const EInteractiveState InteractiveState);
    
    UFUNCTION(BlueprintCallable)
    static void HandleSpellFunnel(const bool Conjuration, const int32 StepNumber, const FString& FunnelAction, const FString& Selection, const FString& Transformation, const FString& Color, const FString& SelectionID);
    
    UFUNCTION(BlueprintCallable)
    static void HandleResourceFlow(const FString& Resource, const float ChangeAmount, const float FinalAmount, const FString& Source, const FString& SourceDetail, const FString& ResourceFlowID, const FString& ResourceCategory);
    
    UFUNCTION(BlueprintCallable)
    static void HandlePuzzle(const FString& PuzzleName, const bool Start, const FString& PuzzleType);
    
    UFUNCTION(BlueprintCallable)
    static void HandlePlayerAvatarUpdate(const FString& PresetType, const FString& PresetValue);
    
    UFUNCTION(BlueprintCallable)
    static void HandleOptionSet(const FString& OptionName, const FString& OptionType, const FString& StringValue, const bool BoolValue, const float FloatValue);
    
    UFUNCTION(BlueprintCallable)
    static void HandleNPCAction(const FString& NPCID, const FString& Action, const FString& ActionDetail, const FString& ConversationID, const FString& DialogueText, const int32 ChoiceNum, const int32 NumChoices);
    
    UFUNCTION(BlueprintCallable)
    static void HandleMenuItemSelect(const FName menuItemName, const FString& selectAction);
    
    UFUNCTION(BlueprintCallable)
    static void HandleMenuAction(const FString& MenuName, const FString& Action, const FString& Selection, const FString& SelectionDetail, const bool LockedToPage);
    
    UFUNCTION(BlueprintCallable)
    static void HandleInteraction(const AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    static void HandleFirstTimeLaunch();
    
    UFUNCTION(BlueprintCallable)
    static void HandleConversationChoice(const FString& DialogueID, const int32 ChoiceNum, const int32 NumChoices);
    
    UFUNCTION(BlueprintCallable)
    FString GetCharacterID();
    
    UFUNCTION(BlueprintCallable)
    static UAnalyticsManager* Get();
    
    UFUNCTION(BlueprintCallable)
    static void AnalyticsEventAction(const FString& ActionName, const FString& SubactionName, const bool ActionResult, const FString& ResultExplained, const FString& ActionDetail);
    
};


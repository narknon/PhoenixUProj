#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_Blueprint.generated.h"

class UObject;
class USceneActionState_Blueprint;
class USceneRig;
class UTimeRig_StoryGraph;
class UTimeRig_StoryGraphNode;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_Blueprint : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USceneActionState_Blueprint* State;
    
    USceneAction_Blueprint();
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetBranchID(FName BranchID) const;
    
    UFUNCTION(BlueprintCallable)
    void SetAutoDurationBP(float Duration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetTimeInsideIntervalPostActorTick(float Time, float LocalTime, bool IsScrubbing);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetTimeInsideInterval(float Time, float LocalTime, bool IsScrubbing);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPauseInsideInterval(bool bPause);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInstantPostActorTick(float Time, bool IsScrubbing);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInstant(float Time, bool IsScrubbing);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnExitInterval(float Time, bool Cancelled, bool IsScrubbing);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnterInterval(float Time, bool IsScrubbing);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDestroy();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCreate(UObject* ActionState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsProxyRequiredBP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsInstant() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInEditor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEnabledBP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool HasPostActorTick() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool HasNormalTick() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    void GetValidBranchIDsBP(UObject* Caller, TSet<FName>& BranchIDs) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTimeRig_StoryGraphNode* GetStoryGraphNode(UObject* Caller) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTimeRig_StoryGraph* GetStoryGraph(UObject* Caller) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStartTimeBP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetSortOrderPostActorTick() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetSortOrder() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USceneRig* GetSceneRig() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    float GetIterationLength() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FText GetDisplayName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetContext() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetAutoDurationBP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetActionObjectBP();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FLinearColor GetActionColor() const;
    
    UFUNCTION(BlueprintCallable)
    void FinishNow();
    
    UFUNCTION(BlueprintCallable)
    void FinishIn(float SecondsFromNow);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DevOnly_IsHammerTime() const;
    
};


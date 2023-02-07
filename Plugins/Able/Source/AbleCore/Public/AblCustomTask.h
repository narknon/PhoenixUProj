#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AblAbilityTask.h"
#include "EAblAbilityTaskRealm.h"
#include "EAblAbilityTaskResult.h"
#include "AblCustomTask.generated.h"

class AActor;
class UAblAbilityContext;
class UAblCustomTaskScratchPad;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblCustomTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UAblCustomTask();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTaskTickBP(const UAblAbilityContext* Context, float DeltaTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTaskStartBP(const UAblAbilityContext* Context) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTaskEndBP(const UAblAbilityContext* Context, const EAblAbilityTaskResult Result) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsSingleFrameBP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsDoneBP(const UAblAbilityContext* Context) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    EAblAbilityTaskRealm GetTaskRealmBP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FText GetTaskNameBP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FText GetTaskDescriptionBP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FLinearColor GetTaskColorBP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FText GetTaskCategoryBP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAblCustomTaskScratchPad* GetScratchPad(UAblAbilityContext* Context) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FText GetDescriptiveTaskNameBP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetActorsForTaskBP(const UAblAbilityContext* Context, TArray<AActor*>& OutActorArray) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UAblCustomTaskScratchPad* CreateScratchPadBP(UAblAbilityContext* Context) const;
    
};


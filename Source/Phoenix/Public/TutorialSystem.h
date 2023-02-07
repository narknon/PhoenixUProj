#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NewTutorialInfo.h"
#include "NewTutorialSequence.h"
#include "TutorialSystem.generated.h"

class UDataTable;
class UPhoenixUserWidget;
class UTutorialScreen;
class UTutorialSystem;

UCLASS(Blueprintable)
class UTutorialSystem : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* TutorialDataTable;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FNewTutorialInfo CurrentTutorialStepData;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FNewTutorialSequence CurrentTutorialData;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTutorialScreen* CurrentTutorialScreen;
    
public:
    UTutorialSystem();
private:
    UFUNCTION(BlueprintCallable)
    void ZoomLowerHogsfield(const UObject* sender);
    
public:
    UFUNCTION(BlueprintCallable)
    void UnpauseTutorialQueue(const FString& Context);
    
    UFUNCTION(BlueprintCallable)
    bool TutorialsAvailable();
    
private:
    UFUNCTION(BlueprintCallable)
    void StopCallAttentionToAnnex(const UObject* sender);
    
public:
    UFUNCTION(BlueprintCallable)
    bool StartTutorialStepExpiryTimerByAlias(const FName TutorialName, const FName TutorialStepAlias);
    
    UFUNCTION(BlueprintCallable)
    bool StartTutorialStepExpiryTimer(const FName TutorialName, const int32 TutorialStep);
    
    UFUNCTION(BlueprintCallable)
    bool StartTutorial(const FName TutorialName, const bool AfterNotifications);
    
private:
    UFUNCTION(BlueprintCallable)
    void StartNextTutorial();
    
    UFUNCTION(BlueprintCallable)
    void SetZZDActivate(const UObject* sender);
    
    UFUNCTION(BlueprintCallable)
    void SetupMapTutorials(const UObject* sender);
    
    UFUNCTION(BlueprintCallable)
    void SetupMapIconsForOverlandTutorial(const UObject* sender);
    
    UFUNCTION(BlueprintCallable)
    void SetupMapFastTravelTutorial(const UObject* sender);
    
    UFUNCTION(BlueprintCallable)
    void ResetMapFastTravelTutorial(const UObject* sender);
    
    UFUNCTION(BlueprintCallable)
    void ResetMap(const UObject* sender);
    
public:
    UFUNCTION(BlueprintCallable)
    void PauseTutorialQueue(const FString& Context);
    
private:
    UFUNCTION(BlueprintCallable)
    void OverlandZoomOut(const UObject* sender);
    
    UFUNCTION(BlueprintCallable)
    void OverlandZoomIn(const UObject* sender);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnMissionFailedScreenLoaded(const UObject* sender);
    
    UFUNCTION(BlueprintCallable)
    void OnIntroEnded(UPhoenixUserWidget* PhoenixWidget, int32 OutroType);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCurrentScreenOutroEnded(UPhoenixUserWidget* PhoenixWidget, int32 OutroType);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTutorialStepActiveOrAboutToBeByAlias(const FName TutorialName, const FName TutorialStepAlias) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTutorialStepActiveOrAboutToBe(const FName TutorialName, const int32 TutorialStep) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTutorialStepActiveByAlias(const FName TutorialName, const FName TutorialStepAlias) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTutorialStepActive(const FName TutorialName, const int32 TutorialStep) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTutorialQueuePaused() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTutorialQueued(const FName TutorialName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTutorialActiveOrAboutToBe(const FName TutorialName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTutorialActive(const FName TutorialName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsModalTutorialQueued() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentTutorialActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnyTutorialQueued() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void HighlightCharmsClass(const UObject* sender);
    
    UFUNCTION(BlueprintCallable)
    void HideLivingQuarters(const UObject* sender);
    
    UFUNCTION(BlueprintCallable)
    void HermesStartNextTutorial();
    
public:
    UFUNCTION(BlueprintCallable)
    bool GetInitialTutorialStepInProgress();
    
    UFUNCTION(BlueprintCallable)
    static UTutorialSystem* Get();
    
    UFUNCTION(BlueprintCallable)
    bool ForceCompleteTutorial(const FName TutorialName, bool DontFireCompletionMessages);
    
private:
    UFUNCTION(BlueprintCallable)
    void CompleteTutorialStepInternal();
    
public:
    UFUNCTION(BlueprintCallable)
    bool CompleteTutorialStepByAlias(const FName TutorialName, const FName TutorialStepAlias);
    
    UFUNCTION(BlueprintCallable)
    bool CompleteTutorialStep(const FName TutorialName, const int32 TutorialStep);
    
    UFUNCTION(BlueprintCallable)
    bool CompleteTutorialCurrentStep(const FName TutorialName);
    
private:
    UFUNCTION(BlueprintCallable)
    void ClosePauseMenu(const UObject* sender);
    
    UFUNCTION(BlueprintCallable)
    void CallAttentionToAnnex(const UObject* sender);
    
    UFUNCTION(BlueprintCallable)
    void BackOutOfRegion(const UObject* sender);
    
    UFUNCTION(BlueprintCallable)
    void AllowTravelToAnnex(const UObject* sender);
    
public:
    UFUNCTION(BlueprintCallable)
    bool AbortTutorial(const FName TutorialName, const bool bInstant);
    
    UFUNCTION(BlueprintCallable)
    void AbortQueuedTutorials(const UObject* sender);
    
};


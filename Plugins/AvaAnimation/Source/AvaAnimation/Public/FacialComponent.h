#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "EFacialEmotion.h"
#include "DialogueLineAnimTablesFinishedLoadingDelegate.h"
#include "DialogueLineEmotionChangedDelegate.h"
#include "EManagedEyeStatePriority.h"
#include "GazeStatesEnum.h"
#include "OnDialogueLineAnimFinishedDelegate.h"
#include "OnDialogueLineAnimStartedDelegate.h"
#include "FacialComponent.generated.h"

class AActor;
class UAimEyesData;
class UAnimRequest_AmbientEyes;
class UAnimRequest_Dialogue;
class UAnimRequest_FacialAnimation;
class UAnimRequest_FacialEmotion;
class UAnimSequence;
class UDataTable;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class AVAANIMATION_API UFacialComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimRequest_Dialogue* DialogueAnimRequest;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueLineAnimTablesFinishedLoading OnDialogueLineAnimTablesFinishedLoading;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDialogueLineAnimStarted OnDialogueLineAnimStartedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDialogueLineAnimFinished OnDialogueLineAnimFinishedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAimEyesData* IdleAimEyes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAimEyesData* ListeningAimEyes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAimEyesData* SpeakingAimEyes;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueLineEmotionChanged DialogueLineEmotionChangedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimRequest_FacialEmotion* FacialEmotionAnimRequest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimRequest_FacialAnimation* FacialAnimationAnimRequest;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimRequest_AmbientEyes* AmbientEyesAnimRequest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UDataTable*> DialogueLineDataTables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimSequence* CurrentDialogueLineAnim;
    
public:
    UFacialComponent();
    UFUNCTION(BlueprintCallable)
    void StartSettingGazeState(const GazeStatesEnum InGazeState, const EManagedEyeStatePriority InPriority);
    
    UFUNCTION(BlueprintCallable)
    void SetAmbientEyesDefaultValue(bool bValue);
    
    UFUNCTION(BlueprintCallable)
    void SetAdditiveEyeTargetDefaultValue(bool bValue);
    
    UFUNCTION(BlueprintCallable)
    void ReloadAnimDataTables();
    
    UFUNCTION(BlueprintCallable)
    void OnHealthChanged(AActor* Actor, float Delta, bool bIndicateHUD);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCharacterLoadComplete(AActor* Actor);
    
public:
    UFUNCTION(BlueprintCallable)
    bool IsPlayingDialogueLine();
    
    UFUNCTION(BlueprintCallable)
    bool IsLoadingDialogueLineAnimDataTables();
    
    UFUNCTION(BlueprintCallable)
    UAnimSequence* GetFacialEmotionAnim(FName Emotion, FGameplayTagContainer AnimTags);
    
    UFUNCTION(BlueprintCallable)
    UAnimSequence* GetFacialAnimByTags(FGameplayTagContainer AnimTags);
    
    UFUNCTION(BlueprintCallable)
    TSoftObjectPtr<UAnimSequence> GetDialogueLineAnim(FName DialogueLine);
    
    UFUNCTION(BlueprintCallable)
    EFacialEmotion GetActiveFacialEmotion();
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingGazeState(const EManagedEyeStatePriority InPriority);
    
    UFUNCTION(BlueprintCallable)
    bool EditorPlayDialogueLine(FName DialogueLine, FName OverrideDialogueLineEmotion);
    
    UFUNCTION(BlueprintCallable)
    bool EditorLoadLanguage(const FString& Lang);
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> EditorGetDialogueLineIds();
    
    UFUNCTION(BlueprintCallable)
    bool EditorCancelPlayingCurrentDialogueLine();
    
    UFUNCTION(BlueprintCallable)
    void DoubleBlinkNow();
    
    UFUNCTION(BlueprintCallable)
    void BlinkNow();
    
};


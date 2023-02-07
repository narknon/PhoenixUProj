#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Moddable.h"
#include "EStandardManagedPriority.h"
#include "AmbientChatterTopicIDs.h"
#include "DetermineLeaderChange_BannerDelegate.h"
#include "SocialActionTypes.h"
#include "SocialConversationData.h"
#include "SocialInteractionTypeIDs.h"
#include "SocialSemanticIDs.h"
#include "SocialReactor.generated.h"

class AActor;
class APawn;
class UAblAbilityContext;
class USocialReactor;

UCLASS(Blueprintable)
class PHOENIX_API USocialReactor : public UObject, public IModdable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDetermineLeaderChange_Banner DetermineLeaderChange_Banner;
    
    USocialReactor();
    UFUNCTION(BlueprintCallable)
    bool ValidateInteractionType(FName InTargetName, AActor* InTargetActor, TEnumAsByte<SocialInteractionTypeIDs> InInteractionType);
    
    UFUNCTION(BlueprintCallable)
    void ToggleAmbientChatterTopic(AmbientChatterTopicIDs InTopic, bool bInTurnOn);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingMissionGossipCalloutsMuted(bool InMuted, EStandardManagedPriority InPriority, UObject* InCaller);
    
    UFUNCTION(BlueprintCallable)
    void StartEmoAbility(APawn* InActorPawn);
    
    UFUNCTION(BlueprintCallable)
    void SetEmotionalState(FName InActorName, TEnumAsByte<SocialSemanticIDs> InSocialEmotion, int32 InMagnitude);
    
    UFUNCTION(BlueprintCallable)
    void ReportSocialAction(SocialActionTypes inActionID, const FString& inActionData, const FString& inLocationName, const FString& InTargetName);
    
private:
    UFUNCTION(BlueprintCallable)
    void PerformNewDay();
    
    UFUNCTION(BlueprintCallable)
    void PerformEndOfDayCleanup();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnAbilityStart(int32 ChannelIndex, UAblAbilityContext* AbilityContext);
    
    UFUNCTION(BlueprintCallable)
    bool MissionGossipCalloutsMuted();
    
    UFUNCTION(BlueprintCallable)
    bool HasIdentity(const FName& InTargetName, TEnumAsByte<SocialSemanticIDs> Identity);
    
    UFUNCTION(BlueprintCallable)
    static USocialReactor* GetTheSocialReactor();
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetIdentityNames(const FName& InTargetName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetIdentityList() const;
    
    UFUNCTION(BlueprintCallable)
    void GetConversationOptions(FName InTargetName, AActor* InTargetActor, TArray<FSocialConversationData>& outConversationOptions);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingMissionGossipCalloutsMuted(EStandardManagedPriority InPriority, UObject* InCaller);
    
    UFUNCTION(BlueprintCallable)
    void EndDialogInteraction(FName InTargetName);
    
    UFUNCTION(BlueprintCallable)
    void BeginDialogInteraction(FName InTargetName);
    
    UFUNCTION(BlueprintCallable)
    bool AllowConversation(const FString& InTargetName, const FString& inMyName);
    
    UFUNCTION(BlueprintCallable)
    bool AddNewIdentity(const FName& InCharacterName, const FName& InIdentityName);
    
    
    // Fix for true pure virtual functions not being implemented
};


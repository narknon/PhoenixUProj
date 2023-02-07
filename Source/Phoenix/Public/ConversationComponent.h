#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BPGenericOnConversationFinishedDelegate.h"
#include "BPGenericOnConversationStartedDelegate.h"
#include "BPOnConversationStartedDelegate.h"
#include "ConversationOption.h"
#include "EConversationType.h"
#include "StaticConversationRegistrationPerUser.h"
#include "StaticVendorEntry.h"
#include "ConversationComponent.generated.h"

class AActor;
class UConversationComponent;
class UConversationState;
class USceneRig_SimpleConversation;
class UScheduledEntity;
class UStationArchitectAsset;
class UStoryGraph_Conversation;
class UTimeRig_StoryGraphNode;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UConversationComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConversationState* ConversationState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UConversationState*> PreInitializedConversationMap;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UScheduledEntity> RequestingFleshForSE;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> RequestingInteractionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UStoryGraph_Conversation*> VendorConditionalConversationMap;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStaticConversationRegistrationPerUser> StaticRegistrations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStationArchitectAsset* ConversationSceneRigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRig_SimpleConversation* PresentChoicesSR;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStoryGraph_Conversation* VendorStoryGraph;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStaticVendorEntry> StaticVendorEntries;
    
    UConversationComponent();
    UFUNCTION(BlueprintCallable)
    static void UnregisterConversation(FName CharacterID, FName ConversationID);
    
    UFUNCTION(BlueprintCallable)
    static void UnregisterAllConversation(FName CharacterID);
    
    UFUNCTION(BlueprintCallable)
    static bool StartConversationWithAssetBP(FName CharacterID, FName ConversationID, UStoryGraph_Conversation* ConversationAsset);
    
    UFUNCTION(BlueprintCallable)
    static bool StartConversationWithActorBP(AActor* interactionActor, FName ConversationID, FBPOnConversationStarted OnConversationStarted, FBPOnConversationStarted OnConversationFinished);
    
    UFUNCTION(BlueprintCallable)
    static bool StartConversationBP(FName CharacterID, FName ConversationID, FBPOnConversationStarted OnConversationStarted, FBPOnConversationStarted OnConversationFinished);
    
    UFUNCTION(BlueprintCallable)
    void SetBranchIDStateUsed(const FName BranchID);
    
    UFUNCTION(BlueprintCallable)
    static void RegisterVendorConversationBP(AActor* InteractingActor, UConversationComponent* ConversationComponent);
    
    UFUNCTION(BlueprintCallable)
    static void RegisterConversationNoCallbacksBP(FName CharacterID, FName ConversationID, EConversationType ConversationType);
    
    UFUNCTION(BlueprintCallable)
    static void RegisterConversationBP(FName CharacterID, FName ConversationID, FBPOnConversationStarted OnConversationStarted, FBPOnConversationStarted OnConversationFinished, EConversationType ConversationType);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool NewConversations();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UConversationState* GetCurrentConversation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetConversationOptions(AActor* interactionActor, FName CharacterID, const UTimeRig_StoryGraphNode* SGNode, TArray<FConversationOption>& UIParameters, TArray<FName>& BranchIDs) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetConversationLastLineID(const UTimeRig_StoryGraphNode* SGNode, FName& LastLineID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UConversationComponent* Get();
    
    UFUNCTION(BlueprintCallable)
    static void BindGenericConversationStart(const FBPGenericOnConversationStarted& OnConversationStarted);
    
    UFUNCTION(BlueprintCallable)
    static void BindGenericConversationFinish(const FBPGenericOnConversationFinished& OnConversationFinished);
    
    UFUNCTION(BlueprintCallable)
    bool BeginInteraction(AActor* interactionActor);
    
};


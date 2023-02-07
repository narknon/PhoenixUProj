#include "ConversationComponent.h"

class AActor;
class UConversationComponent;
class UConversationState;
class UStoryGraph_Conversation;
class UTimeRig_StoryGraphNode;

void UConversationComponent::UnregisterConversation(FName CharacterID, FName ConversationID) {
}

void UConversationComponent::UnregisterAllConversation(FName CharacterID) {
}

bool UConversationComponent::StartConversationWithAssetBP(FName CharacterID, FName ConversationID, UStoryGraph_Conversation* ConversationAsset) {
    return false;
}

bool UConversationComponent::StartConversationWithActorBP(AActor* interactionActor, FName ConversationID, FBPOnConversationStarted OnConversationStarted, FBPOnConversationStarted OnConversationFinished) {
    return false;
}

bool UConversationComponent::StartConversationBP(FName CharacterID, FName ConversationID, FBPOnConversationStarted OnConversationStarted, FBPOnConversationStarted OnConversationFinished) {
    return false;
}

void UConversationComponent::SetBranchIDStateUsed(const FName BranchID) {
}

void UConversationComponent::RegisterVendorConversationBP(AActor* InteractingActor, UConversationComponent* ConversationComponent) {
}

void UConversationComponent::RegisterConversationNoCallbacksBP(FName CharacterID, FName ConversationID, EConversationType ConversationType) {
}

void UConversationComponent::RegisterConversationBP(FName CharacterID, FName ConversationID, FBPOnConversationStarted OnConversationStarted, FBPOnConversationStarted OnConversationFinished, EConversationType ConversationType) {
}

void UConversationComponent::OnSaveGameLoaded() {
}

bool UConversationComponent::NewConversations() {
    return false;
}

UConversationState* UConversationComponent::GetCurrentConversation() {
    return NULL;
}

bool UConversationComponent::GetConversationOptions(AActor* interactionActor, FName CharacterID, const UTimeRig_StoryGraphNode* SGNode, TArray<FConversationOption>& UIParameters, TArray<FName>& BranchIDs) const {
    return false;
}

bool UConversationComponent::GetConversationLastLineID(const UTimeRig_StoryGraphNode* SGNode, FName& LastLineID) const {
    return false;
}

UConversationComponent* UConversationComponent::Get() {
    return NULL;
}

void UConversationComponent::BindGenericConversationStart(const FBPGenericOnConversationStarted& OnConversationStarted) {
}

void UConversationComponent::BindGenericConversationFinish(const FBPGenericOnConversationFinished& OnConversationFinished) {
}

bool UConversationComponent::BeginInteraction(AActor* interactionActor) {
    return false;
}

UConversationComponent::UConversationComponent() {
    this->ConversationState = NULL;
    this->ConversationSceneRigs = NULL;
    this->PresentChoicesSR = NULL;
    this->VendorStoryGraph = NULL;
}


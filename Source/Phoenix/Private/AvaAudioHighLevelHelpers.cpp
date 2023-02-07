#include "AvaAudioHighLevelHelpers.h"

class AActor;

void UAvaAudioHighLevelHelpers::UnregisterForcedACKWitness(FName CharacterID, bool bUnregisterAll) {
}

void UAvaAudioHighLevelHelpers::UnregisterExclusiveMissionDialogue(const FName& CharacterID, const FString& ExclusiveEventNamePattern, const FName& FromMissionID) {
}

bool UAvaAudioHighLevelHelpers::SetAudioToPortraitTransform(AActor* Actor, FTransform Transform) {
    return false;
}

bool UAvaAudioHighLevelHelpers::RestoreAudioFromPortraitTransform(AActor* Actor) {
    return false;
}

void UAvaAudioHighLevelHelpers::RegisterForcedACKWitness(FName CharacterID) {
}

void UAvaAudioHighLevelHelpers::RegisterExclusiveMissionDialogue(const FName& CharacterID, const FString& ExclusiveEventNamePattern, const FName& FromMissionID) {
}

void UAvaAudioHighLevelHelpers::PlayGreetingForPlayerChatStarted(const AActor* Actor, const FString& AudioConversationName) {
}

bool UAvaAudioHighLevelHelpers::DEBUG_IsAvatarInSiteVolume(const FString& SiteName) {
    return false;
}

UAvaAudioHighLevelHelpers::UAvaAudioHighLevelHelpers() {
}


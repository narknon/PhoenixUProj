#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AvaAudioHighLevelHelpers.generated.h"

class AActor;

UCLASS(Blueprintable)
class UAvaAudioHighLevelHelpers : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAvaAudioHighLevelHelpers();
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void UnregisterForcedACKWitness(FName CharacterID, bool bUnregisterAll);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void UnregisterExclusiveMissionDialogue(const FName& CharacterID, const FString& ExclusiveEventNamePattern, const FName& FromMissionID);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static bool SetAudioToPortraitTransform(AActor* Actor, FTransform Transform);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static bool RestoreAudioFromPortraitTransform(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void RegisterForcedACKWitness(FName CharacterID);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void RegisterExclusiveMissionDialogue(const FName& CharacterID, const FString& ExclusiveEventNamePattern, const FName& FromMissionID);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void PlayGreetingForPlayerChatStarted(const AActor* Actor, const FString& AudioConversationName);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static bool DEBUG_IsAvatarInSiteVolume(const FString& SiteName);
    
};


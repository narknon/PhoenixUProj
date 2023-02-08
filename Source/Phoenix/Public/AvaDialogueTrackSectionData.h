#pragma once
#include "CoreMinimal.h"
#include "AnimNotify_PlayAvaAudioDialogue.h"
#include "AvaDialogueTrackSectionData.generated.h"


USTRUCT(BlueprintType)
struct FAvaDialogueTrackSectionData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAvaAudioDialogueEvent* Event;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FString> RequiredParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StopWhenAttachedToDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 flags;
    
    PHOENIX_API FAvaDialogueTrackSectionData();
};


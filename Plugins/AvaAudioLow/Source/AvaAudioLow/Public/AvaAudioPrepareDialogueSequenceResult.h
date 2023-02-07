#pragma once
#include "CoreMinimal.h"
#include "AvaAudioDialogueMetaData.h"
#include "AvaAudioPrepareDialogueSequenceResult.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct AVAAUDIOLOW_API FAvaAudioPrepareDialogueSequenceResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FString> Parameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvaAudioDialogueMetaData MetaData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* LineActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LineActorID;
    
    FAvaAudioPrepareDialogueSequenceResult();
};


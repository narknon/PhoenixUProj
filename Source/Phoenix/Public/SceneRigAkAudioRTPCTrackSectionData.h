#pragma once
#include "CoreMinimal.h"
#include "SceneRigAkAudioRTPCTrackSectionData.generated.h"

USTRUCT(BlueprintType)
struct FSceneRigAkAudioRTPCTrackSectionData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RTPCName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RTPCValue;
    
    PHOENIX_API FSceneRigAkAudioRTPCTrackSectionData();
};


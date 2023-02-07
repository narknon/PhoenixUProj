#pragma once
#include "CoreMinimal.h"
#include "SceneRigAvaAudioMusicTrackSectionData.generated.h"

USTRUCT(BlueprintType)
struct FSceneRigAvaAudioMusicTrackSectionData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    PHOENIX_API FSceneRigAvaAudioMusicTrackSectionData();
};


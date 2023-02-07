#pragma once
#include "CoreMinimal.h"
#include "SceneRigAkAudioStateTrackSectionData.generated.h"

USTRUCT(BlueprintType)
struct FSceneRigAkAudioStateTrackSectionData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName stateGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName State;
    
    PHOENIX_API FSceneRigAkAudioStateTrackSectionData();
};


#pragma once
#include "CoreMinimal.h"
#include "SceneRigAvaAudioStateTrackSectionData.generated.h"

USTRUCT(BlueprintType)
struct FSceneRigAvaAudioStateTrackSectionData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName stateGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    PHOENIX_API FSceneRigAvaAudioStateTrackSectionData();
};


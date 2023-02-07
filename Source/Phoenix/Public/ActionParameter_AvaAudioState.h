#pragma once
#include "CoreMinimal.h"
#include "SceneRigAvaAudioStateTrackSectionData.h"
#include "SceneRigParameterBinding_AvaAudioState.h"
#include "ActionParameter_AvaAudioState.generated.h"

USTRUCT(BlueprintType)
struct FActionParameter_AvaAudioState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_AvaAudioState BoundParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAvaAudioStateTrackSectionData DefaultState;
    
    PHOENIX_API FActionParameter_AvaAudioState();
};


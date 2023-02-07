#pragma once
#include "CoreMinimal.h"
#include "SceneRigAkAudioStateTrackSectionData.h"
#include "SceneRigParameterBinding_AkAudioState.h"
#include "ActionParameter_AkAudioState.generated.h"

USTRUCT(BlueprintType)
struct FActionParameter_AkAudioState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_AkAudioState BoundParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAkAudioStateTrackSectionData DefaultState;
    
    PHOENIX_API FActionParameter_AkAudioState();
};


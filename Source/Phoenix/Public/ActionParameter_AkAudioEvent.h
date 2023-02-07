#pragma once
#include "CoreMinimal.h"
#include "SceneRigAkAudioEventTrackSectionData.h"
#include "SceneRigParameterBinding_AkAudioEvent.h"
#include "ActionParameter_AkAudioEvent.generated.h"

USTRUCT(BlueprintType)
struct FActionParameter_AkAudioEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_AkAudioEvent BoundParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAkAudioEventTrackSectionData DefaultEvent;
    
    PHOENIX_API FActionParameter_AkAudioEvent();
};


#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "ActionParameter_AkAudioState.h"
#include "SceneAction_AkAudioState.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AkAudioState : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActionParameter_AkAudioState StateInfo;
    
    USceneAction_AkAudioState();
};


#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "ActionParameter_AvaAudioState.h"
#include "SceneAction_AvaAudioState.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AvaAudioState : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActionParameter_AvaAudioState StateInfo;
    
    USceneAction_AvaAudioState();
};


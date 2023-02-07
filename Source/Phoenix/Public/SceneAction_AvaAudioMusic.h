#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "ActionParameter_AvaAudioMusic.h"
#include "SceneAction_AvaAudioMusic.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AvaAudioMusic : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActionParameter_AvaAudioMusic MusicInfo;
    
    USceneAction_AvaAudioMusic();
};


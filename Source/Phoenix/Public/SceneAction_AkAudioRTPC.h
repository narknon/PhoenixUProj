#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "ActionParameter_AkAudioRTPC.h"
#include "SceneAction_AkAudioRTPC.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AkAudioRTPC : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActionParameter_AkAudioRTPC RTPCInfo;
    
    USceneAction_AkAudioRTPC();
};


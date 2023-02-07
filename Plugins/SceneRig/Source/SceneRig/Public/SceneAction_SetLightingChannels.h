#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_SetLightingChannels.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_SetLightingChannels : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightingChannels LightingChannels;
    
    USceneAction_SetLightingChannels();
};


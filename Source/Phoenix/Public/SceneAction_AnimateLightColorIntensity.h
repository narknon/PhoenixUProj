#pragma once
#include "CoreMinimal.h"
#include "SceneAction_SpawnActorAllowAsChild.h"
#include "SceneAction_AnimateLightColorIntensity.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AnimateLightColorIntensity : public USceneAction_SpawnActorAllowAsChild {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRestoreLights;
    
    USceneAction_AnimateLightColorIntensity();
};


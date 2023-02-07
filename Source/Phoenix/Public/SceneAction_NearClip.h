#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_NearClip.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_NearClip : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NearClip;
    
    USceneAction_NearClip();
};


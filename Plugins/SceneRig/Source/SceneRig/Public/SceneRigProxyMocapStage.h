#pragma once
#include "CoreMinimal.h"
#include "SceneRigProxyActor.h"
#include "SceneRigProxyMocapStage.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class SCENERIG_API USceneRigProxyMocapStage : public USceneRigProxyActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Visible;
    
    USceneRigProxyMocapStage();
};


#pragma once
#include "CoreMinimal.h"
#include "SceneActionFunctionEventReference.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_FunctionEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_FunctionEvent : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneActionFunctionEventReference FunctionReference;
    
    USceneAction_FunctionEvent();
};


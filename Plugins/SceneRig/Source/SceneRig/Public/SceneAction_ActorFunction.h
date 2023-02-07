#pragma once
#include "CoreMinimal.h"
#include "SceneActionActorFunctionReference.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_ActorFunction.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_ActorFunction : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneActionActorFunctionReference FunctionReference;
    
    USceneAction_ActorFunction();
};


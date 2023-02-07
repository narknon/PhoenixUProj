#pragma once
#include "CoreMinimal.h"
#include "SceneActionActorFunctionReference.h"
#include "SceneActionActorTickFunctionReference.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_ActorIntervalFunctions.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_ActorIntervalFunctions : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneActionActorFunctionReference OnEnterFunction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneActionActorTickFunctionReference TickFunction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneActionActorFunctionReference OnExitFunction;
    
    USceneAction_ActorIntervalFunctions();
};


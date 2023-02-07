#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_Actor.h"
#include "SceneRigStage_NamedParameter.h"
#include "SceneRigStage_NamedActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigStage_NamedActor : public USceneRigStage_NamedParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor Parameter;
    
    USceneRigStage_NamedActor();
};


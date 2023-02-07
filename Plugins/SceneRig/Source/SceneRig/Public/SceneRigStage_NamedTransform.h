#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_NamedParameter.h"
#include "SceneRigStage_Transform.h"
#include "SceneRigStage_NamedTransform.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigStage_NamedTransform : public USceneRigStage_NamedParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Transform Parameter;
    
    USceneRigStage_NamedTransform();
};


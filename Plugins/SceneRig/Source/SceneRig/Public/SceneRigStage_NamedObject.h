#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_NamedParameter.h"
#include "SceneRigStage_Object.h"
#include "SceneRigStage_NamedObject.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigStage_NamedObject : public USceneRigStage_NamedParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Object Parameter;
    
    USceneRigStage_NamedObject();
};


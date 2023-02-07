#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_Bool.h"
#include "SceneRigStage_NamedParameter.h"
#include "SceneRigStage_NamedBool.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigStage_NamedBool : public USceneRigStage_NamedParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Bool Parameter;
    
    USceneRigStage_NamedBool();
};


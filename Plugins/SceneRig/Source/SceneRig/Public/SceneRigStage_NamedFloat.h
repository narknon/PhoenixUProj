#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_Float.h"
#include "SceneRigStage_NamedParameter.h"
#include "SceneRigStage_NamedFloat.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigStage_NamedFloat : public USceneRigStage_NamedParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Float Parameter;
    
    USceneRigStage_NamedFloat();
};


#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_Name.h"
#include "SceneRigStage_NamedParameter.h"
#include "SceneRigStage_NamedName.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigStage_NamedName : public USceneRigStage_NamedParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Name Parameter;
    
    USceneRigStage_NamedName();
};


#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_NamedParameter.h"
#include "SceneRigStage_Vector.h"
#include "SceneRigStage_NamedVector.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigStage_NamedVector : public USceneRigStage_NamedParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Vector Parameter;
    
    USceneRigStage_NamedVector();
};


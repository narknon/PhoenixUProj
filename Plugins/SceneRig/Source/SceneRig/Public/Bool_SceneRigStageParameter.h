#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "SceneRigStage_BoolReference.h"
#include "Bool_SceneRigStageParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UBool_SceneRigStageParameter : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_BoolReference Reference;
    
    UBool_SceneRigStageParameter();
};


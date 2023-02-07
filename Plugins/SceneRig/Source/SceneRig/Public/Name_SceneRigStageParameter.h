#pragma once
#include "CoreMinimal.h"
#include "NameProvider.h"
#include "SceneRigStage_NameReference.h"
#include "Name_SceneRigStageParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UName_SceneRigStageParameter : public UNameProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_NameReference Reference;
    
    UName_SceneRigStageParameter();
};


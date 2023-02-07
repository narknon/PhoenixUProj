#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_NamedParameter.h"
#include "SceneRigStage_String.h"
#include "SceneRigStage_NamedString.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigStage_NamedString : public USceneRigStage_NamedParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_String Parameter;
    
    USceneRigStage_NamedString();
};


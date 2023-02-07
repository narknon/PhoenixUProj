#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_Int.h"
#include "SceneRigStage_NamedParameter.h"
#include "SceneRigStage_NamedInt.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigStage_NamedInt : public USceneRigStage_NamedParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Int Parameter;
    
    USceneRigStage_NamedInt();
};


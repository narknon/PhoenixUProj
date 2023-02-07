#pragma once
#include "CoreMinimal.h"
#include "IntProvider.h"
#include "SceneRigStage_IntReference.h"
#include "Int_SceneRigStageParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UInt_SceneRigStageParameter : public UIntProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_IntReference Reference;
    
    UInt_SceneRigStageParameter();
};


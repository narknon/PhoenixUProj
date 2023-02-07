#pragma once
#include "CoreMinimal.h"
#include "StringProvider.h"
#include "SceneRigStage_StringReference.h"
#include "String_SceneRigStageParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UString_SceneRigStageParameter : public UStringProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_StringReference Reference;
    
    UString_SceneRigStageParameter();
};


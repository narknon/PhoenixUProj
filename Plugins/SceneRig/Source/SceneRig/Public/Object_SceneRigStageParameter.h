#pragma once
#include "CoreMinimal.h"
#include "ObjectProvider.h"
#include "SceneRigStage_ObjectReference.h"
#include "Object_SceneRigStageParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UObject_SceneRigStageParameter : public UObjectProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_ObjectReference Reference;
    
    UObject_SceneRigStageParameter();
};


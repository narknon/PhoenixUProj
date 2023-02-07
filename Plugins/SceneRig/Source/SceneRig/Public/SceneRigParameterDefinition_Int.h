#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameterDefinition.h"
#include "SceneRigParameterDefinition_Int.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigParameterDefinition_Int : public USceneRigParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultValue;
    
    USceneRigParameterDefinition_Int();
};


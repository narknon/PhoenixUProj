#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameterDefinition.h"
#include "SceneRigParameterDefinition_Object.generated.h"

class UObjectProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigParameterDefinition_Object : public USceneRigParameterDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjectProvider* DefaultObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EvaluateOnce;
    
    USceneRigParameterDefinition_Object();
};


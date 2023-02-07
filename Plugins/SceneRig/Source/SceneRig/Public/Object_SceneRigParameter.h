#pragma once
#include "CoreMinimal.h"
#include "ObjectProvider.h"
#include "SceneRigParameterBinding_Object.h"
#include "Object_SceneRigParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UObject_SceneRigParameter : public UObjectProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_Object BoundParameter;
    
    UObject_SceneRigParameter();
};


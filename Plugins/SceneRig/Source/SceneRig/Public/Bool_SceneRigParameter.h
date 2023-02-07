#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "SceneRigParameterBinding_Bool.h"
#include "Bool_SceneRigParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UBool_SceneRigParameter : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_Bool BoundParameter;
    
    UBool_SceneRigParameter();
};


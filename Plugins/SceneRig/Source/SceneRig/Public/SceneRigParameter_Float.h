#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameter.h"
#include "SceneRigParameter_Float.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigParameter_Float : public USceneRigParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    USceneRigParameter_Float();
};


#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameter.h"
#include "SceneRigParameter_Int.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigParameter_Int : public USceneRigParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    USceneRigParameter_Int();
};


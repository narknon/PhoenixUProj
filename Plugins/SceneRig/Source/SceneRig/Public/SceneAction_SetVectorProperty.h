#pragma once
#include "CoreMinimal.h"
#include "SceneAction_SetProperty.h"
#include "SceneAction_SetVectorProperty.generated.h"

class UVectorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_SetVectorProperty : public USceneAction_SetProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVectorProvider* InputValue;
    
    USceneAction_SetVectorProperty();
};


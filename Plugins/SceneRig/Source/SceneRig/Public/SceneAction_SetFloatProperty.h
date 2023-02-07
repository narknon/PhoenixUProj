#pragma once
#include "CoreMinimal.h"
#include "SceneAction_SetProperty.h"
#include "SceneAction_SetFloatProperty.generated.h"

class UFloatProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_SetFloatProperty : public USceneAction_SetProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* InputValue;
    
    USceneAction_SetFloatProperty();
};


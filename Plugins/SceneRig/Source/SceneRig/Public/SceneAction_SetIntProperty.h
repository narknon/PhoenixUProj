#pragma once
#include "CoreMinimal.h"
#include "SceneAction_SetProperty.h"
#include "SceneAction_SetIntProperty.generated.h"

class UIntProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_SetIntProperty : public USceneAction_SetProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UIntProvider* InputValue;
    
    USceneAction_SetIntProperty();
};


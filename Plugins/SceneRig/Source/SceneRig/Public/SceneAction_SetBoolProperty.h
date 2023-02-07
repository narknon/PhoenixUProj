#pragma once
#include "CoreMinimal.h"
#include "SceneAction_SetProperty.h"
#include "SceneAction_SetBoolProperty.generated.h"

class UBoolProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_SetBoolProperty : public USceneAction_SetProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* InputValue;
    
    USceneAction_SetBoolProperty();
};


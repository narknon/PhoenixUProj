#pragma once
#include "CoreMinimal.h"
#include "StencilManagerGroupName.h"
#include "SceneAction_StencilFXEnableInterface.h"
#include "SceneAction_StencilFXDisableAll.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_StencilFXDisableAll : public USceneAction_StencilFXEnableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStencilManagerGroupName> ExceptGroups;
    
    USceneAction_StencilFXDisableAll();
};


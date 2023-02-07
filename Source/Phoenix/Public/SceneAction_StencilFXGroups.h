#pragma once
#include "CoreMinimal.h"
#include "StencilManagerGroupName.h"
#include "SceneAction_StencilFXEnableInterface.h"
#include "SceneAction_StencilFXGroups.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_StencilFXGroups : public USceneAction_StencilFXEnableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStencilManagerGroupName> Groups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExclusive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableStencilManager;
    
    USceneAction_StencilFXGroups();
};


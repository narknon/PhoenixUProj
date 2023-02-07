#pragma once
#include "CoreMinimal.h"
#include "StencilManagerEffectName.h"
#include "SceneAction_StencilFXBase.h"
#include "SceneAction_StencilFX.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_StencilFX : public USceneAction_StencilFXBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerEffectName StencilFX;
    
    USceneAction_StencilFX();
};


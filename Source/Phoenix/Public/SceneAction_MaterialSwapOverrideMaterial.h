#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoOverrideMaterial.h"
#include "MaterialSwapParameters.h"
#include "SceneAction_MaterialSwap.h"
#include "SceneAction_MaterialSwapOverrideMaterial.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_MaterialSwapOverrideMaterial : public USceneAction_MaterialSwap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapInfoOverrideMaterial Swap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters InitialParameters;
    
    USceneAction_MaterialSwapOverrideMaterial();
};


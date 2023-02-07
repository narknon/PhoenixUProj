#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoOverrideMaterials.h"
#include "MaterialSwapParameters.h"
#include "SceneAction_MaterialSwap.h"
#include "SceneAction_MaterialSwapOverrideMaterials.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_MaterialSwapOverrideMaterials : public USceneAction_MaterialSwap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapInfoOverrideMaterials Swap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters InitialParameters;
    
    USceneAction_MaterialSwapOverrideMaterials();
};


#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapKeyUI.h"
#include "MaterialSwapParameters.h"
#include "MaterialSwapKeyBundlePreload.h"
#include "SceneAction_MaterialSwap.h"
#include "SceneAction_MaterialSwapKey.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_MaterialSwapKey : public USceneAction_MaterialSwap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapKeyUI Swap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapKeyBundlePreload PreloadMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters InitialParameters;
    
    USceneAction_MaterialSwapKey();
};


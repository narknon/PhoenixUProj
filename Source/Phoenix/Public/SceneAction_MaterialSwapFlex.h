#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapParameters.h"
#include "MaterialSwapKeyBundlePreload.h"
#include "SceneAction_MaterialSwap.h"
#include "SceneAction_MaterialSwapFlex.generated.h"

class UMaterialSwapInfoObject;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_MaterialSwapFlex : public USceneAction_MaterialSwap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMaterialSwapInfoObject* Swap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapKeyBundlePreload PreloadMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters InitialParameters;
    
    USceneAction_MaterialSwapFlex();
};


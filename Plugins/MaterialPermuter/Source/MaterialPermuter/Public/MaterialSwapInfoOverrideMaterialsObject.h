#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoObject.h"
#include "MaterialSwapInfoOverrideMaterials.h"
#include "MaterialSwapInfoOverrideMaterialsObject.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class MATERIALPERMUTER_API UMaterialSwapInfoOverrideMaterialsObject : public UMaterialSwapInfoObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapInfoOverrideMaterials SwapInfo;
    
    UMaterialSwapInfoOverrideMaterialsObject();
};


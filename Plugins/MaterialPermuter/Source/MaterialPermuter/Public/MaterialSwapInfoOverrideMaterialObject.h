#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoObject.h"
#include "MaterialSwapInfoOverrideMaterial.h"
#include "MaterialSwapInfoOverrideMaterialObject.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class MATERIALPERMUTER_API UMaterialSwapInfoOverrideMaterialObject : public UMaterialSwapInfoObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapInfoOverrideMaterial SwapInfo;
    
    UMaterialSwapInfoOverrideMaterialObject();
};


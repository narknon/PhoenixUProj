#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoOverrideMaterials.h"
#include "MultiFX2_MaterialPermuterSwapInfoBase.h"
#include "MultiFX2_MaterialPermuterSwapInfoOverrideMaterials.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMultiFX2_MaterialPermuterSwapInfoOverrideMaterials : public UMultiFX2_MaterialPermuterSwapInfoBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapInfoOverrideMaterials SwapInfo;
    
    UMultiFX2_MaterialPermuterSwapInfoOverrideMaterials();
};


#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoOverrideMaterial.h"
#include "MultiFX2_MaterialPermuterSwapInfoBase.h"
#include "MultiFX2_MaterialPermuterSwapInfoOverrideMaterial.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMultiFX2_MaterialPermuterSwapInfoOverrideMaterial : public UMultiFX2_MaterialPermuterSwapInfoBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapInfoOverrideMaterial SwapInfo;
    
    UMultiFX2_MaterialPermuterSwapInfoOverrideMaterial();
};


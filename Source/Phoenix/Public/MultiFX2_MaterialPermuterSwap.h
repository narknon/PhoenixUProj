#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapParameters.h"
#include "MultiFX2_Filtered.h"
#include "MultiFX2_MaterialPermuterSwap.generated.h"

class UMultiFX2_MaterialPermuterSwapInfoBase;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_MaterialPermuterSwap : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NoClear, meta=(AllowPrivateAccess=true))
    UMultiFX2_MaterialPermuterSwapInfoBase* SwapInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters Parameters;
    
public:
    UMultiFX2_MaterialPermuterSwap();
};


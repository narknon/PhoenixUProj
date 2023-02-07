#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapKeyUI.h"
#include "MultiFX2_MaterialPermuterSwapInfoBase.h"
#include "MultiFX2_MaterialPermuterSwapInfoKey.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMultiFX2_MaterialPermuterSwapInfoKey : public UMultiFX2_MaterialPermuterSwapInfoBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapKeyUI SwapInfo;
    
    UMultiFX2_MaterialPermuterSwapInfoKey();
};


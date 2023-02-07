#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoInPlaceMIDs.h"
#include "MultiFX2_MaterialPermuterSwapInfoBase.h"
#include "MultiFX2_MaterialPermuterSwapInfoInPlaceMIDs.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMultiFX2_MaterialPermuterSwapInfoInPlaceMIDs : public UMultiFX2_MaterialPermuterSwapInfoBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapInfoInPlaceMIDs SwapInfo;
    
    UMultiFX2_MaterialPermuterSwapInfoInPlaceMIDs();
};


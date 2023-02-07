#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoObject.h"
#include "MaterialSwapKeyUI.h"
#include "MaterialSwapInfoMaterialPermuterKeyUIObject.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class MATERIALPERMUTER_API UMaterialSwapInfoMaterialPermuterKeyUIObject : public UMaterialSwapInfoObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapKeyUI SwapInfo;
    
    UMaterialSwapInfoMaterialPermuterKeyUIObject();
};


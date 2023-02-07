#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoObjectBase.h"
#include "MaterialSwapKey.h"
#include "MaterialSwapInfoMaterialPermuterKeyObject.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class MATERIALPERMUTER_API UMaterialSwapInfoMaterialPermuterKeyObject : public UMaterialSwapInfoObjectBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapKey SwapInfo;
    
    UMaterialSwapInfoMaterialPermuterKeyObject();
};


#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoInPlaceMIDs.h"
#include "MaterialSwapInfoObject.h"
#include "MaterialSwapInfoInPlaceMIDsObject.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class MATERIALPERMUTER_API UMaterialSwapInfoInPlaceMIDsObject : public UMaterialSwapInfoObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapInfoInPlaceMIDs SwapInfo;
    
    UMaterialSwapInfoInPlaceMIDsObject();
};


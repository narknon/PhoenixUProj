#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogBasicParametersRelative.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogParamsRelativeBasic.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsRelativeBasic : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogBasicParametersRelative Basic;
    
    UExpHeightFogParamsRelativeBasic();
};


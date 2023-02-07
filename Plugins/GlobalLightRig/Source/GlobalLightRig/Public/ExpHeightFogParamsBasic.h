#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogBasicParameters.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogParamsBasic.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsBasic : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogBasicParameters Basic;
    
    UExpHeightFogParamsBasic();
};


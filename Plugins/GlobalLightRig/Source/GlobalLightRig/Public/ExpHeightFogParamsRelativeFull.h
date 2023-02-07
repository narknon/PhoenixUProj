#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParametersRelative.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogParamsRelativeFull.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsRelativeFull : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogParametersRelative Parameters;
    
    UExpHeightFogParamsRelativeFull();
};


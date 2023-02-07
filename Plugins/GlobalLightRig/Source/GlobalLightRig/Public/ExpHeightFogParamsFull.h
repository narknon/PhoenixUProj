#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParameters.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogParamsFull.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsFull : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogParameters Parameters;
    
    UExpHeightFogParamsFull();
};


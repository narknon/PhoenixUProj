#pragma once
#include "CoreMinimal.h"
#include "AdjustedValueFloat.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogParamsRelativeVolumetricFogExtinctionScale.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsRelativeVolumetricFogExtinctionScale : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricFogExtinctionScale;
    
    UExpHeightFogParamsRelativeVolumetricFogExtinctionScale();
};


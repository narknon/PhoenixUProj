#pragma once
#include "CoreMinimal.h"
#include "LumosScalabilityModifyWithRule.h"
#include "LumosScalabilityModifyPostProcessing.generated.h"

class ULumosPostProcessingAsset;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilityModifyPostProcessing : public ULumosScalabilityModifyWithRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULumosPostProcessingAsset* PostProcessing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsePostProcessing;
    
    ULumosScalabilityModifyPostProcessing();
};


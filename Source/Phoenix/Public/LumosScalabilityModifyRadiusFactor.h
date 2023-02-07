#pragma once
#include "CoreMinimal.h"
#include "LumosScalabilityModifyWithRule.h"
#include "LumosScalabilityModifyRadiusFactor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilityModifyRadiusFactor : public ULumosScalabilityModifyWithRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LightRadiusFactor;
    
    ULumosScalabilityModifyRadiusFactor();
};


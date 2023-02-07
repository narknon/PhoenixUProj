#pragma once
#include "CoreMinimal.h"
#include "LumosScalabilityOverrideWithRule.h"
#include "LumosScalabilityOverride.generated.h"

class ULumosScalabilityAsset;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilityOverride : public ULumosScalabilityOverrideWithRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULumosScalabilityAsset* LumosAsset;
    
    ULumosScalabilityOverride();
};


#pragma once
#include "CoreMinimal.h"
#include "EPhoenixScalabilityLevel.h"
#include "LumosScalabilityOverrideWithRule.h"
#include "LumosScalabilityOverrideScalabilityLevel.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilityOverrideScalabilityLevel : public ULumosScalabilityOverrideWithRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPhoenixScalabilityLevel Level;
    
    ULumosScalabilityOverrideScalabilityLevel();
};


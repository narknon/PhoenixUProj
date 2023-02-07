#pragma once
#include "CoreMinimal.h"
#include "EPhoenixScalabilityLevel.h"
#include "LumosScalabilityOverrideWithRule.h"
#include "LumosScalabilityOverrideCustomScalabilityLevel.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilityOverrideCustomScalabilityLevel : public ULumosScalabilityOverrideWithRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Custom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPhoenixScalabilityLevel Level;
    
    ULumosScalabilityOverrideCustomScalabilityLevel();
};


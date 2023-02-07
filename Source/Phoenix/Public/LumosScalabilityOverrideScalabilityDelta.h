#pragma once
#include "CoreMinimal.h"
#include "EPhoenixScalabilityLevel.h"
#include "LumosScalabilityOverrideWithRule.h"
#include "LumosScalabilityOverrideScalabilityDelta.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilityOverrideScalabilityDelta : public ULumosScalabilityOverrideWithRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelDelta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPhoenixScalabilityLevel MinLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPhoenixScalabilityLevel MaxLevel;
    
    ULumosScalabilityOverrideScalabilityDelta();
};


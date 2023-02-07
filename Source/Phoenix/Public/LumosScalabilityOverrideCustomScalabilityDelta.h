#pragma once
#include "CoreMinimal.h"
#include "EPhoenixScalabilityLevel.h"
#include "LumosScalabilityOverrideWithRule.h"
#include "LumosScalabilityOverrideCustomScalabilityDelta.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilityOverrideCustomScalabilityDelta : public ULumosScalabilityOverrideWithRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Custom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelDelta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPhoenixScalabilityLevel MinLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPhoenixScalabilityLevel MaxLevel;
    
    ULumosScalabilityOverrideCustomScalabilityDelta();
};


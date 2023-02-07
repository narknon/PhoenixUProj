#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsScalarName.h"
#include "PostProcessingVarsDriver.h"
#include "PostProcessingVarsDriverEnvironmentalGlobalsExtra.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UPostProcessingVarsDriverEnvironmentalGlobalsExtra : public UPostProcessingVarsDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsScalarName EnvironmentalGlobal;
    
    UPostProcessingVarsDriverEnvironmentalGlobalsExtra();
};


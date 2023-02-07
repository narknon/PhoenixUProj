#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentalGlobalsValue.h"
#include "PostProcessingVarsDriver.h"
#include "PostProcessingVarsDriverEnvironmentalGlobalsValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UPostProcessingVarsDriverEnvironmentalGlobalsValue : public UPostProcessingVarsDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnvironmentalGlobalsValue EnvironmentalGlobal;
    
    UPostProcessingVarsDriverEnvironmentalGlobalsValue();
};


#pragma once
#include "CoreMinimal.h"
#include "PostProcessingVarsDriver.h"
#include "PostProcessingVarsDriverConst.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UPostProcessingVarsDriverConst : public UPostProcessingVarsDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPostProcessingVarsDriverConst();
};


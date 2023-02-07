#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPProbesToneMapping.h"
#include "RenderSettingsPPProbes.generated.h"

USTRUCT(BlueprintType)
struct RENDERSETTINGS_API FRenderSettingsPPProbes {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FRenderSettingsPPProbesToneMapping ToneMapping;
    
    FRenderSettingsPPProbes();
};


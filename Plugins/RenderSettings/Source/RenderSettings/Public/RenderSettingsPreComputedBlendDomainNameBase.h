#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPreComputedBlendDomainNameBase.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPreComputedBlendDomainNameBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsPreComputedBlendDomainNameBase();
};


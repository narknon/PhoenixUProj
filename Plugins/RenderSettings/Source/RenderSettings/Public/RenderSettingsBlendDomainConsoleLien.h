#pragma once
#include "CoreMinimal.h"
#include "ConsoleVariableLienEntry.h"
#include "BlendDomain.h"
#include "ERenderSettingsBlendDomainConsoleLienMode.h"
#include "RenderSettingsBlendDomainConsoleLien.generated.h"

USTRUCT(BlueprintType)
struct RENDERSETTINGS_API FRenderSettingsBlendDomainConsoleLien {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyAfterBeginPlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERenderSettingsBlendDomainConsoleLienMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConsoleVariableLienEntry> ConsoleVariables;
    
    FRenderSettingsBlendDomainConsoleLien();
};


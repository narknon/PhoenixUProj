#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainConsoleEntry.generated.h"

USTRUCT(BlueprintType)
struct RENDERSETTINGS_API FRenderSettingsCustomBlendDomainConsoleEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName domain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ConsoleVariable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExplicitCompare;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvertValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseExplicitCompare;
    
    FRenderSettingsCustomBlendDomainConsoleEntry();
};


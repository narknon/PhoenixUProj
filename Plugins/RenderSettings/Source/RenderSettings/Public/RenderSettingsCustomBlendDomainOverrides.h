#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainValueOverrides.h"
#include "RenderSettingsCustomBlendDomainOverrides.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FRenderSettingsCustomBlendDomainOverrides {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> InterfaceOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsCustomBlendDomainValueOverrides ValueOverrides;
    
    RENDERSETTINGS_API FRenderSettingsCustomBlendDomainOverrides();
};


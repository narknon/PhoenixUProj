#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainValueStore.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsCustomBlendDomainValueStore {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> Values;
    
    RENDERSETTINGS_API FRenderSettingsCustomBlendDomainValueStore();
};


#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RenderSettingsBlendDomainAsset.generated.h"

UCLASS(Abstract, Blueprintable)
class RENDERSETTINGS_API URenderSettingsBlendDomainAsset : public UDataAsset {
    GENERATED_BODY()
public:
    URenderSettingsBlendDomainAsset();
};


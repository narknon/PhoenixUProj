#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RenderSettingsCustomBlendDomainPresetAsset.generated.h"

class URenderSettingsCustomBlendDomain;

UCLASS(Blueprintable)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainPresetAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URenderSettingsCustomBlendDomain*> Domains;
    
    URenderSettingsCustomBlendDomainPresetAsset();
};


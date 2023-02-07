#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RenderSettingsBlendDomainConsoleLien.h"
#include "RenderSettingsBlendDomainConsoleLiens.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API URenderSettingsBlendDomainConsoleLiens : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsBlendDomainConsoleLien> Liens;
    
    URenderSettingsBlendDomainConsoleLiens();
};


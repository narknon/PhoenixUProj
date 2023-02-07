#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainName.h"
#include "RenderSettingsCustomBlendDomainOverrideComponentBase.h"
#include "RenderSettingsCustomBlendDomainOverrideNamedComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainOverrideNamedComponent : public URenderSettingsCustomBlendDomainOverrideComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsCustomBlendDomainName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    URenderSettingsCustomBlendDomainOverrideNamedComponent();
};


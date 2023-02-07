#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainOverrideComponentBase.h"
#include "RenderSettingsCustomBlendDomainOverrideRawComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainOverrideRawComponent : public URenderSettingsCustomBlendDomainOverrideComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    URenderSettingsCustomBlendDomainOverrideRawComponent();
};


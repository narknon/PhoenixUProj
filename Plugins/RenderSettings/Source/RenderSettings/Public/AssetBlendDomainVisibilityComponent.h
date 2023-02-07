#pragma once
#include "CoreMinimal.h"
#include "BlendDomainVisibilityComponentBase.h"
#include "AssetBlendDomainVisibilityComponent.generated.h"

class URenderSettingsBlendDomainAsset;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API UAssetBlendDomainVisibilityComponent : public UBlendDomainVisibilityComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsBlendDomainAsset* BlendDomain;
    
    UAssetBlendDomainVisibilityComponent();
};


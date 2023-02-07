#pragma once
#include "CoreMinimal.h"
#include "AssetBlendDomainVisibilityComponent.h"
#include "AssetBlendDomainComponentVisibilityComponent.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API UAssetBlendDomainComponentVisibilityComponent : public UAssetBlendDomainVisibilityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetDitheredAlpha;
    
    UAssetBlendDomainComponentVisibilityComponent();
};


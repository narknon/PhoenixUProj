#pragma once
#include "CoreMinimal.h"
#include "AssetBlendDomainComponentVisibilityComponent.h"
#include "AssetBlendDomainChildVisibilityComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API UAssetBlendDomainChildVisibilityComponent : public UAssetBlendDomainComponentVisibilityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bChildrenOfChildren;
    
    UAssetBlendDomainChildVisibilityComponent();
};


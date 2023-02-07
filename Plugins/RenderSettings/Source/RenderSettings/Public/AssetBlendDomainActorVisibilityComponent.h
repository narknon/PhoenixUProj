#pragma once
#include "CoreMinimal.h"
#include "AssetBlendDomainComponentVisibilityComponent.h"
#include "AssetBlendDomainActorVisibilityComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API UAssetBlendDomainActorVisibilityComponent : public UAssetBlendDomainComponentVisibilityComponent {
    GENERATED_BODY()
public:
    UAssetBlendDomainActorVisibilityComponent();
};


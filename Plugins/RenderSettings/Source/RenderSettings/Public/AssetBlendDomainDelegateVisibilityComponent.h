#pragma once
#include "CoreMinimal.h"
#include "AssetBlendDomainVisibilityComponent.h"
#include "AssetBlendDomainVisibiltyDelegateDelegate.h"
#include "AssetBlendDomainDelegateVisibilityComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API UAssetBlendDomainDelegateVisibilityComponent : public UAssetBlendDomainVisibilityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssetBlendDomainVisibiltyDelegate VisibilityDelegate;
    
    UAssetBlendDomainDelegateVisibilityComponent();
};


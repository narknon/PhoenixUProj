#pragma once
#include "CoreMinimal.h"
#include "BlendDomainVisibilityComponent.h"
#include "BlendDomainComponentVisibilityComponent.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API UBlendDomainComponentVisibilityComponent : public UBlendDomainVisibilityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetDitheredAlpha;
    
    UBlendDomainComponentVisibilityComponent();
};


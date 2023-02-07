#pragma once
#include "CoreMinimal.h"
#include "BlendDomainVisibilityComponent.h"
#include "BlendDomainVisibiltyDelegateDelegate.h"
#include "BlendDomainDelegateVisibilityComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API UBlendDomainDelegateVisibilityComponent : public UBlendDomainVisibilityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomainVisibiltyDelegate VisibilityDelegate;
    
    UBlendDomainDelegateVisibilityComponent();
};


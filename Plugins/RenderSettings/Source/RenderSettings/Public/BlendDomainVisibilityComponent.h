#pragma once
#include "CoreMinimal.h"
#include "BlendDomain.h"
#include "BlendDomainVisibilityComponentBase.h"
#include "BlendDomainVisibilityComponent.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API UBlendDomainVisibilityComponent : public UBlendDomainVisibilityComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UBlendDomainVisibilityComponent();
};


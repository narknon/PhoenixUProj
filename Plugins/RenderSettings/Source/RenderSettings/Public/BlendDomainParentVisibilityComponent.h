#pragma once
#include "CoreMinimal.h"
#include "BlendDomainComponentVisibilityComponent.h"
#include "BlendDomainParentVisibilityComponent.generated.h"

class UBlendDomainParentVisibilityComponent;
class USceneComponent;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API UBlendDomainParentVisibilityComponent : public UBlendDomainComponentVisibilityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPropagateToChildren;
    
    UBlendDomainParentVisibilityComponent();
    UFUNCTION(BlueprintCallable)
    static UBlendDomainParentVisibilityComponent* CreateForParentComponent(USceneComponent* Parent, bool bTransient, bool bStartEnabled);
    
};


#pragma once
#include "CoreMinimal.h"
#include "BlendDomainComponentVisibilityComponent.h"
#include "BlendDomainChildVisibilityComponent.generated.h"

class UBlendDomainChildVisibilityComponent;
class USceneComponent;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API UBlendDomainChildVisibilityComponent : public UBlendDomainComponentVisibilityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bChildrenOfChildren;
    
    UBlendDomainChildVisibilityComponent();
    UFUNCTION(BlueprintCallable)
    static UBlendDomainChildVisibilityComponent* CreateForChildComponents(USceneComponent* Parent, bool bTransient, bool bStartEnabled);
    
};


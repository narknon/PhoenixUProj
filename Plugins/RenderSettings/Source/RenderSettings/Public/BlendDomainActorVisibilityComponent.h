#pragma once
#include "CoreMinimal.h"
#include "BlendDomainComponentVisibilityComponent.h"
#include "BlendDomainActorVisibilityComponent.generated.h"

class AActor;
class UBlendDomainActorVisibilityComponent;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API UBlendDomainActorVisibilityComponent : public UBlendDomainComponentVisibilityComponent {
    GENERATED_BODY()
public:
    UBlendDomainActorVisibilityComponent();
    UFUNCTION(BlueprintCallable)
    static UBlendDomainActorVisibilityComponent* CreateForActor(AActor* Actor, bool bTransient, bool bStartEnabled);
    
};


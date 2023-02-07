#pragma once
#include "CoreMinimal.h"
#include "HighContrastGameplayMarkupComponent.h"
#include "StencilValueRenderCustomDepthFilter.h"
#include "EHighContrastGameplayMarkup.h"
#include "HighContrastGameplayMarkupActorComponent.generated.h"

class AActor;
class UStencilManagerDynamicLock;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UHighContrastGameplayMarkupActorComponent : public UHighContrastGameplayMarkupComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHighContrastGameplayMarkup Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilValueRenderCustomDepthFilter Filter;
    
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, UStencilManagerDynamicLock*> StateMap;
    
public:
    UHighContrastGameplayMarkupActorComponent();
};


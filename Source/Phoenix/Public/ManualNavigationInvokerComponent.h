#pragma once
#include "CoreMinimal.h"
#include "NavigationInvokerComponent.h"
#include "ManualNavigationInvokerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UManualNavigationInvokerComponent : public UNavigationInvokerComponent {
    GENERATED_BODY()
public:
    UManualNavigationInvokerComponent();
};


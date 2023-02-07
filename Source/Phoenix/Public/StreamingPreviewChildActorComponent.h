#pragma once
#include "CoreMinimal.h"
#include "Components/ChildActorComponent.h"
#include "StreamingPreviewChildActorComponent.generated.h"

UCLASS(Blueprintable, HideDropdown, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UStreamingPreviewChildActorComponent : public UChildActorComponent {
    GENERATED_BODY()
public:
    UStreamingPreviewChildActorComponent();
};


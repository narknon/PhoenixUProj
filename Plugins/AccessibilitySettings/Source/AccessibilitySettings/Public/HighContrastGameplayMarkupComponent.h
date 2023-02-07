#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HighContrastGameplayMarkupComponent.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ACCESSIBILITYSETTINGS_API UHighContrastGameplayMarkupComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UHighContrastGameplayMarkupComponent();
};


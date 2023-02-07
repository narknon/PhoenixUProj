#pragma once
#include "CoreMinimal.h"
#include "HighContrastGameplayMarkupActorComponent.h"
#include "HighContrastGameplayMarkupOwnerComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UHighContrastGameplayMarkupOwnerComponent : public UHighContrastGameplayMarkupActorComponent {
    GENERATED_BODY()
public:
    UHighContrastGameplayMarkupOwnerComponent();
};


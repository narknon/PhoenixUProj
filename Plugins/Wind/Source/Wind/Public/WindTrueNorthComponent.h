#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "WindTrueNorthComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WIND_API UWindTrueNorthComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UWindTrueNorthComponent();
};


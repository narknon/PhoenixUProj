#pragma once
#include "CoreMinimal.h"
#include "UberExposureComponent.h"
#include "UberExposureComponentExposureExpression.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API UUberExposureComponentExposureExpression : public UUberExposureComponent {
    GENERATED_BODY()
public:
    UUberExposureComponentExposureExpression();
};


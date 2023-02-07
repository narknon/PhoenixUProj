#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "OdcCanvasTextComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOdcCanvasTextComponent : public UPrimitiveComponent {
    GENERATED_BODY()
public:
    UOdcCanvasTextComponent();
};


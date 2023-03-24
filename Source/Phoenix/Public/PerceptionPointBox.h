#pragma once
#include "CoreMinimal.h"
#include "PerceptionPointArea.h"
#include "PerceptionPointBox.generated.h"

UCLASS(Blueprintable)
class APerceptionPointBox : public APerceptionPointArea {
    GENERATED_BODY()
public:
    APerceptionPointBox(const FObjectInitializer& ObjectInitializer);
};


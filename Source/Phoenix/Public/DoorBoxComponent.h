#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "DoorBoxComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDoorBoxComponent : public UBoxComponent {
    GENERATED_BODY()
public:
    UDoorBoxComponent();
};


#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "DrawRoomComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDrawRoomComponent : public UPrimitiveComponent {
    GENERATED_BODY()
public:
    UDrawRoomComponent();
};


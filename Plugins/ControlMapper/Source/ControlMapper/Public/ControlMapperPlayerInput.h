#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerInput.h"
#include "ControlMapperPlayerInput.generated.h"

UCLASS(Blueprintable, NonTransient)
class CONTROLMAPPER_API UControlMapperPlayerInput : public UPlayerInput {
    GENERATED_BODY()
public:
    UControlMapperPlayerInput();
};


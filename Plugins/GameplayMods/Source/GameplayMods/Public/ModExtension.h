#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ModExtension.generated.h"

UCLASS(Abstract, Blueprintable, MinimalAPI)
class UModExtension : public UObject {
    GENERATED_BODY()
public:
    GAMEPLAYMODS_API UModExtension();
};


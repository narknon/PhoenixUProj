#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ObjectStateDataContainerBase.generated.h"

UCLASS(Abstract, Blueprintable, Transient)
class PHOENIX_API UObjectStateDataContainerBase : public UObject {
    GENERATED_BODY()
public:
    UObjectStateDataContainerBase();
};


#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AmbulatoryAnimTask.generated.h"

UCLASS(Abstract, Blueprintable)
class AMBULATORY_API UAmbulatoryAnimTask : public UObject {
    GENERATED_BODY()
public:
    UAmbulatoryAnimTask();
};


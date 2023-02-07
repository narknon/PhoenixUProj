#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "SchedulerTimeProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API USchedulerTimeProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    USchedulerTimeProvider();
};


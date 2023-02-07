#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "StringProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UStringProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UStringProvider();
};


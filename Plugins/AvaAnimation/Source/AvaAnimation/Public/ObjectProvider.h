#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "ObjectProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UObjectProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UObjectProvider();
};


#pragma once
#include "CoreMinimal.h"
#include "ObjectProvider.h"
#include "Object_IsCaller.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UObject_IsCaller : public UObjectProvider {
    GENERATED_BODY()
public:
    UObject_IsCaller();
};


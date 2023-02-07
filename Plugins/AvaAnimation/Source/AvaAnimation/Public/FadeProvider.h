#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "FadeProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UFadeProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UFadeProvider();
};


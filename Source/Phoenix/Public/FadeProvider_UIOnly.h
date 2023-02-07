#pragma once
#include "CoreMinimal.h"
#include "FadeProvider.h"
#include "FadeProvider_UIOnly.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFadeProvider_UIOnly : public UFadeProvider {
    GENERATED_BODY()
public:
    UFadeProvider_UIOnly();
};


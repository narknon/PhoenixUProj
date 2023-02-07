#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "DialogueLineProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UDialogueLineProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UDialogueLineProvider();
};


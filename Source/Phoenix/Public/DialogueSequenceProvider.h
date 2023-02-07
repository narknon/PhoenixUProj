#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "DialogueSequenceProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UDialogueSequenceProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UDialogueSequenceProvider();
};


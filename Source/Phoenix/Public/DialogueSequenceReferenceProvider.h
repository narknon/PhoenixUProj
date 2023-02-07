#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "DialogueSequenceReferenceProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UDialogueSequenceReferenceProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UDialogueSequenceReferenceProvider();
};


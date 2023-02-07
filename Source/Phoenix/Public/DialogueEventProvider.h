#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "DialogueEventProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UDialogueEventProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UDialogueEventProvider();
};


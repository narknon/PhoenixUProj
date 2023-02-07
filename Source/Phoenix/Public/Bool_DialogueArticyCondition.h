#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "DialogueLineReference.h"
#include "Bool_DialogueArticyCondition.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UBool_DialogueArticyCondition : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueLineReference DialogueLine;
    
    UBool_DialogueArticyCondition();
};


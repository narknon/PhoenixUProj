#pragma once
#include "CoreMinimal.h"
#include "DialogueSequenceProvider.h"
#include "DialogueSequenceReference.h"
#include "DialogueSequence_Direct.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UDialogueSequence_Direct : public UDialogueSequenceProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueSequenceReference DialogueSequence;
    
    UDialogueSequence_Direct();
};


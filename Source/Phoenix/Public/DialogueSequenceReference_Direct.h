#pragma once
#include "CoreMinimal.h"
#include "DialogueSequenceReference.h"
#include "DialogueSequenceReferenceProvider.h"
#include "DialogueSequenceReference_Direct.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDialogueSequenceReference_Direct : public UDialogueSequenceReferenceProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueSequenceReference Value;
    
    UDialogueSequenceReference_Direct();
};


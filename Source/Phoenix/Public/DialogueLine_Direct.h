#pragma once
#include "CoreMinimal.h"
#include "DialogueLineProvider.h"
#include "DialogueLineReference.h"
#include "DialogueLine_Direct.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UDialogueLine_Direct : public UDialogueLineProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueLineReference DialogueLine;
    
    UDialogueLine_Direct();
};


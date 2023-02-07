#pragma once
#include "CoreMinimal.h"
#include "StringProvider.h"
#include "DialogueLineReference.h"
#include "String_DialogueArticyID.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UString_DialogueArticyID : public UStringProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueLineReference DialogueLine;
    
    UString_DialogueArticyID();
};


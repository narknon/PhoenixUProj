#pragma once
#include "CoreMinimal.h"
#include "DialogueSequenceReference.generated.h"

USTRUCT(BlueprintType)
struct FDialogueSequenceReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EventID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SequenceID;
    
    PHOENIX_API FDialogueSequenceReference();
};


#pragma once
#include "CoreMinimal.h"
#include "DialogueLineReference.generated.h"

USTRUCT(BlueprintType)
struct FDialogueLineReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DialogueLineID;
    
    PHOENIX_API FDialogueLineReference();
};


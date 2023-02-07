#pragma once
#include "CoreMinimal.h"
#include "AblReactionsList.generated.h"

class UAblReactionData;

USTRUCT(BlueprintType)
struct ABLECORE_API FAblReactionsList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAblReactionData*> Reactions;
    
    FAblReactionsList();
};


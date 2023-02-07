#pragma once
#include "CoreMinimal.h"
#include "ConversationLayeredAnimationWeight.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversationLayeredAnimationWeight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WeightEntryName;
    
    FConversationLayeredAnimationWeight();
};


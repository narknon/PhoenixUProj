#pragma once
#include "CoreMinimal.h"
#include "SocialCapitalChangeReasons.h"
#include "SocialReasoningComparison.generated.h"

USTRUCT(BlueprintType)
struct FSocialReasoningComparison {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialCapitalChangeReasons> ComparedToReasoning;
    
    PHOENIX_API FSocialReasoningComparison();
};


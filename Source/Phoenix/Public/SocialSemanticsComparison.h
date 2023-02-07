#pragma once
#include "CoreMinimal.h"
#include "EValueComparison.h"
#include "SocialSemanticIDs.h"
#include "SocialSemanticsComparison.generated.h"

USTRUCT(BlueprintType)
struct FSocialSemanticsComparison {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialSemanticIDs> SocialSemantic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EValueComparison ComparisonOperator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ComparisonValue;
    
    PHOENIX_API FSocialSemanticsComparison();
};


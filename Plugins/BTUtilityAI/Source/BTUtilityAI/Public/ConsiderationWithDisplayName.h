#pragma once
#include "CoreMinimal.h"
#include "ConsiderationWithDisplayName.generated.h"

class UQualifierConsideration;

USTRUCT(BlueprintType)
struct FConsiderationWithDisplayName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* Consideration;
    
    BTUTILITYAI_API FConsiderationWithDisplayName();
};


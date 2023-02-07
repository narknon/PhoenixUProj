#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "AblHasTagTaskCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblHasTagTaskCondition : public UAblTaskCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInverse;
    
public:
    UAblHasTagTaskCondition();
};


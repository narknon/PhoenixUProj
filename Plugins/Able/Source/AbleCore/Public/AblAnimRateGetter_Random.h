#pragma once
#include "CoreMinimal.h"
#include "AblAnimRateGetter.h"
#include "AblAnimRateGetter_Random.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimRateGetter_Random : public UAblAnimRateGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinPlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxPlayRate;
    
public:
    UAblAnimRateGetter_Random();
};


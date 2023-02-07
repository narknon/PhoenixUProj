#pragma once
#include "CoreMinimal.h"
#include "AblAnimRateGetter.h"
#include "AblAnimRateGetter_Protego.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimRateGetter_Protego : public UAblAnimRateGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ImpactFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxMultiplier;
    
public:
    UAblAnimRateGetter_Protego();
};


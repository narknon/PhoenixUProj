#pragma once
#include "CoreMinimal.h"
#include "AblAnimRateGetter.h"
#include "AblAnimRateGetter_WandCast.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimRateGetter_WandCast : public UAblAnimRateGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FireWandFrame;
    
public:
    UAblAnimRateGetter_WandCast();
};


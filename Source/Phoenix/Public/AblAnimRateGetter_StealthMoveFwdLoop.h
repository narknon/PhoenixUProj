#pragma once
#include "CoreMinimal.h"
#include "AblAnimRateGetter.h"
#include "AblAnimRateGetter_StealthMoveFwdLoop.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimRateGetter_StealthMoveFwdLoop : public UAblAnimRateGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinWadingAnimRate;
    
public:
    UAblAnimRateGetter_StealthMoveFwdLoop();
};


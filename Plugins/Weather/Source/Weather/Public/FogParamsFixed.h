#pragma once
#include "CoreMinimal.h"
#include "FogParameters.h"
#include "FogParams.h"
#include "FogParamsFixed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class WEATHER_API UFogParamsFixed : public UFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFogParameters Parameters;
    
    UFogParamsFixed();
};


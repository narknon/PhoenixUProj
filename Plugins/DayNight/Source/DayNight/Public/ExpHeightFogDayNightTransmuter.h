#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogTransmuter.h"
#include "ExpHeightFogDayNightTransmuter.generated.h"

class UDayNightExpHeightFogAdjustments;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UExpHeightFogDayNightTransmuter : public UExpHeightFogTransmuter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDayNightExpHeightFogAdjustments* OverrideAdjustments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UExpHeightFogDayNightTransmuter();
};


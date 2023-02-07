#pragma once
#include "CoreMinimal.h"
#include "DateInput.h"
#include "UberExposureDriver.h"
#include "UberExposureDriverNormalizedTime.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UUberExposureDriverNormalizedTime : public UUberExposureDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateInput DefaultDay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAssumeNoonIfNoDayNight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDefaultDay;
    
    UUberExposureDriverNormalizedTime();
};


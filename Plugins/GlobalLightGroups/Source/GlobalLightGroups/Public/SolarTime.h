#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SolarTime.generated.h"

USTRUCT(BlueprintType)
struct FSolarTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimespan Time;
    
    GLOBALLIGHTGROUPS_API FSolarTime();
};


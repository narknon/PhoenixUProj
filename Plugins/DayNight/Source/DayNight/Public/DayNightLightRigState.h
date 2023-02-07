#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DayNightLightRigSetup.h"
#include "DayNightLightRigState.generated.h"

USTRUCT(BlueprintType)
struct FDayNightLightRigState : public FDayNightLightRigSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Direction;
    
    DAYNIGHT_API FDayNightLightRigState();
};


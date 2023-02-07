#pragma once
#include "CoreMinimal.h"
#include "TypeWeight.h"
#include "PathScheduleData.generated.h"

USTRUCT(BlueprintType)
struct AIPATHSCHEDULER_API FPathScheduleData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 DaysMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpawnDensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 HouseAndGender;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 HoboType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTypeWeight> Weights;
    
    FPathScheduleData();
};


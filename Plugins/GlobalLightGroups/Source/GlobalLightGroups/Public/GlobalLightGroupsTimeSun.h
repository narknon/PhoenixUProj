#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightGroupsSunAngle.h"
#include "EGlobalLightGroupsSunDirection.h"
#include "GlobalLightGroupsTimeSun.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsTimeSun {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightGroupsSunAngle Angle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightGroupsSunDirection Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AngleOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VarianceMinutesMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VarianceMinutesMax;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsTimeSun();
};


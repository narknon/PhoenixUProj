#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsTimeHMS.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsTimeHMS {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Hour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Minute;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Second;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VarianceMinutesMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VarianceMinutesMax;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsTimeHMS();
};


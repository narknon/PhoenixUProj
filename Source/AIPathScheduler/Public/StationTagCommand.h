#pragma once
#include "CoreMinimal.h"
#include "BaseTagCommand.h"
#include "StationTagCommand.generated.h"

USTRUCT(BlueprintType)
struct AIPATHSCHEDULER_API FStationTagCommand : public FBaseTagCommand {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 UUID_AIPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FromPathPointIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Probability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SiteLocation;
    
    FStationTagCommand();
};


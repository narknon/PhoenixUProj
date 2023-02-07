#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "LocationCreatorData.generated.h"

class ADynamicObjectVolume;
class AStation;

USTRUCT(BlueprintType)
struct FLocationCreatorData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo LocationID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LocationSchedule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AStation* LocationStation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ADynamicObjectVolume*> LocationSpawners;
    
    PHOENIX_API FLocationCreatorData();
};


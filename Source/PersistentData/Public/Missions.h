#pragma once
#include "CoreMinimal.h"
#include "Missions.generated.h"

USTRUCT(BlueprintType)
struct FMissions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FString> Missions;
    
    PERSISTENTDATA_API FMissions();
};


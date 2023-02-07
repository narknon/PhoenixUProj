#pragma once
#include "CoreMinimal.h"
#include "MissionName.generated.h"

USTRUCT(BlueprintType)
struct FMissionName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MissionName;
    
    PHOENIX_API FMissionName();
};


#pragma once
#include "CoreMinimal.h"
#include "MissionID.generated.h"

USTRUCT(BlueprintType)
struct FMissionID {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    PHOENIX_API FMissionID();
};


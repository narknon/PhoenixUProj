#pragma once
#include "CoreMinimal.h"
#include "DatabaseMissionList.generated.h"

USTRUCT(BlueprintType)
struct FDatabaseMissionList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    PHOENIX_API FDatabaseMissionList();
};


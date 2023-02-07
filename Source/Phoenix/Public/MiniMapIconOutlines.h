#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MiniMapIconOutlines.generated.h"

USTRUCT(BlueprintType)
struct FMiniMapIconOutlines : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString IconName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString OutlineName;
    
    PHOENIX_API FMiniMapIconOutlines();
};


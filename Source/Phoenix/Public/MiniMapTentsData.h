#pragma once
#include "CoreMinimal.h"
#include "MiniMapTentsData.generated.h"

USTRUCT(BlueprintType)
struct FMiniMapTentsData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentLevel;
    
    PHOENIX_API FMiniMapTentsData();
};


#pragma once
#include "CoreMinimal.h"
#include "DebugMapPoint.h"
#include "DebugMapLine.generated.h"

USTRUCT(BlueprintType)
struct FDebugMapLine {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDebugMapPoint> Points;
    
    PHOENIX_API FDebugMapLine();
};


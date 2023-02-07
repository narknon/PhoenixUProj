#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DebugMapLine.h"
#include "DebugMapPoint.h"
#include "DebugMapData.generated.h"

class APhoenixPathActor;

USTRUCT(BlueprintType)
struct FDebugMapData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDebugMapLine> DrawLines;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDebugMapPoint> drawPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Width;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APhoenixPathActor*> meshActors;
    
    PHOENIX_API FDebugMapData();
};


#pragma once
#include "CoreMinimal.h"
#include "OdcFlags.h"
#include "OdcObstacleBehavior.h"
#include "OdcObstacleData.generated.h"

USTRUCT(BlueprintType)
struct FOdcObstacleData {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Layers;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    OdcObstacleBehavior Behavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Cost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcFlags BlockageFlags;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 MarkupFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
public:
    ODYSSEYRUNTIME_API FOdcObstacleData();
};


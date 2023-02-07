#pragma once
#include "CoreMinimal.h"
#include "OdcLayerConfig.generated.h"

USTRUCT(BlueprintType)
struct ODYSSEYRUNTIME_API FOdcLayerConfig {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Height;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtrusionRadius;
    
public:
    FOdcLayerConfig();
};


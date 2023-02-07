#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Chaos/ChaosEngineInterface.h"
#include "SurfaceTypeChanged.generated.h"

USTRUCT(BlueprintType)
struct AMBULATORY_API FSurfaceTypeChanged {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EPhysicalSurface> LastSurfaceType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EPhysicalSurface> NewSurfaceType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Normal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Friction;
    
    FSurfaceTypeChanged();
};


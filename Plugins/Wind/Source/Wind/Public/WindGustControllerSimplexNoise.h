#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WindGustController.h"
#include "EWindGustSimplexNoiseMode.h"
#include "WindGustControllerSimplexNoise.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWindGustControllerSimplexNoise : public UWindGustController {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PositionScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWindGustSimplexNoiseMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Seed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector InvPositionScale;
    
public:
    UWindGustControllerSimplexNoise();
};


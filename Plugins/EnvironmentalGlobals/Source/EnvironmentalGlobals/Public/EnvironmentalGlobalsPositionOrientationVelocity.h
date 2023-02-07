#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnvironmentalGlobalsPositionOrientation.h"
#include "EnvironmentalGlobalsPositionOrientationVelocity.generated.h"

USTRUCT(BlueprintType)
struct ENVIRONMENTALGLOBALS_API FEnvironmentalGlobalsPositionOrientationVelocity : public FEnvironmentalGlobalsPositionOrientation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Velocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector VelocityDir;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    
    FEnvironmentalGlobalsPositionOrientationVelocity();
};


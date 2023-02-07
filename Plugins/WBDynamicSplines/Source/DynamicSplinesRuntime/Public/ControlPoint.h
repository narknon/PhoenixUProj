#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ControlPoint.generated.h"

USTRUCT(BlueprintType)
struct FControlPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector4 Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector4 Normal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector4 ArriveTangent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector4 LeaveTangent;
    
    DYNAMICSPLINESRUNTIME_API FControlPoint();
};


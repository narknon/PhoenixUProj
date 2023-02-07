#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EUMGInputAction.h"
#include "InputCheckpoint.generated.h"

USTRUCT(BlueprintType)
struct FInputCheckpoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUMGInputAction InputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D InputWindow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PathSplineIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D Location;
    
    PHOENIX_API FInputCheckpoint();
};


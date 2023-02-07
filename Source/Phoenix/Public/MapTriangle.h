#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MapTriangle.generated.h"

USTRUCT(BlueprintType)
struct FMapTriangle {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 Index;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Indices[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Vertex[3];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LayerIndex;
    
    PHOENIX_API FMapTriangle();
};


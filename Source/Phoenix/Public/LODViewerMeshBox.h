#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LODViewerMeshBox.generated.h"

USTRUCT(BlueprintType)
struct FLODViewerMeshBox {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MeshName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Min;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Max;
    
    PHOENIX_API FLODViewerMeshBox();
};


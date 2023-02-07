#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NPC_NavPath.generated.h"

USTRUCT(BlueprintType)
struct FNPC_NavPath {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPathGenerated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> Points;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPathIsPartial;
    
    PHOENIX_API FNPC_NavPath();
};


#pragma once
#include "CoreMinimal.h"
#include "TransfigurationResource.generated.h"

USTRUCT(BlueprintType)
struct FTransfigurationResource {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Count;
    
    PHOENIX_API FTransfigurationResource();
};


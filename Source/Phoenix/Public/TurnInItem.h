#pragma once
#include "CoreMinimal.h"
#include "TurnInItem.generated.h"

USTRUCT(BlueprintType)
struct FTurnInItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ObjectID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Quantity;
    
    PHOENIX_API FTurnInItem();
};


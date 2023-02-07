#pragma once
#include "CoreMinimal.h"
#include "TransfigSlotPoolExpansion.generated.h"

USTRUCT(BlueprintType)
struct FTransfigSlotPoolExpansion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LockId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SlotID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SlotAmount;
    
    PHOENIX_API FTransfigSlotPoolExpansion();
};


#pragma once
#include "CoreMinimal.h"
#include "EGearSlotIDEnum.h"
#include "GearItemID.generated.h"

USTRUCT(BlueprintType)
struct FGearItemID {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GearID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GearVariation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsEquipped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGearSlotIDEnum GearItemSlot;
    
    PHOENIX_API FGearItemID();
};


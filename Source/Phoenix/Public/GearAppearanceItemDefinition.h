#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EGearSlotIDEnum.h"
#include "GearCharacterPieceDefinition.h"
#include "GearAppearanceItemDefinition.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API UGearAppearanceItemDefinition : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GearAppearanceID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGearSlotIDEnum GearSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGearCharacterPieceDefinition> OutfitItems;
    
    UGearAppearanceItemDefinition();
};


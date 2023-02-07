#pragma once
#include "CoreMinimal.h"
#include "EGearHouseID.h"
#include "MaterialParameterDefinition.h"
#include "GearCharacterPieceDefinition.generated.h"

class UCharacterPiece;

USTRUCT(BlueprintType)
struct PHOENIX_API FGearCharacterPieceDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCharacterPiece* CharacterPiece;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialParameterDefinition MaterialParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGearHouseID, FMaterialParameterDefinition> HouseMaterialParams;
    
    FGearCharacterPieceDefinition();
};


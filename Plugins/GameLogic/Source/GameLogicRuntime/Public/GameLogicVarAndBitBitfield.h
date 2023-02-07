#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "GameLogicVarAndBitBitfield.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGameLogicVarAndBitBitfield : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BitfieldType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BitValue;
    
    FGameLogicVarAndBitBitfield();
};


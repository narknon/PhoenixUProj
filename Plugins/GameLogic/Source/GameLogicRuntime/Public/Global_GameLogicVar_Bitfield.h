#pragma once
#include "CoreMinimal.h"
#include "Global_GameLogicElement.h"
#include "Global_GameLogicVar_Bitfield.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGlobal_GameLogicVar_Bitfield : public FGlobal_GameLogicElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BitfieldType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BitfieldValue;
    
    FGlobal_GameLogicVar_Bitfield();
};


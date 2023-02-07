#pragma once
#include "CoreMinimal.h"
#include "Global_GameLogicElement.h"
#include "Global_GameLogicVar_Enum.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGlobal_GameLogicVar_Enum : public FGlobal_GameLogicElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EnumType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EnumValue;
    
    FGlobal_GameLogicVar_Enum();
};


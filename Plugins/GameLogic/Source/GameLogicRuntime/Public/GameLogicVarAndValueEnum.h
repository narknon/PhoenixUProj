#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "GameLogicVarAndValueEnum.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGameLogicVarAndValueEnum : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EnumType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EnumValue;
    
    FGameLogicVarAndValueEnum();
};


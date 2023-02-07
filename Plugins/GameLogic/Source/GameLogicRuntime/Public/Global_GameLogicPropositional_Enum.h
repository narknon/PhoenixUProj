#pragma once
#include "CoreMinimal.h"
#include "Global_GameLogicPropositional.h"
#include "Global_GameLogicPropositional_Enum.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGlobal_GameLogicPropositional_Enum : public FGlobal_GameLogicPropositional {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EnumType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> Values;
    
    FGlobal_GameLogicPropositional_Enum();
};


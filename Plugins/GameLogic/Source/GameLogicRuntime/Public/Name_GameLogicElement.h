#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ElementName;
    
    FName_GameLogicElement();
};


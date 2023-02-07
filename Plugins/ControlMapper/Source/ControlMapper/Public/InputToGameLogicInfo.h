#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicVarBool.h"
#include "InputToGameLogicInfo.generated.h"

USTRUCT(BlueprintType)
struct CONTROLMAPPER_API FInputToGameLogicInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicVarBool BoolVarName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExecuteWhenPaused;
    
    FInputToGameLogicInfo();
};


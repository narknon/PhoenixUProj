#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicVarFloat.h"
#include "InputToGameLogicInfo.h"
#include "AxisToGameLogicInfo.generated.h"

USTRUCT(BlueprintType)
struct CONTROLMAPPER_API FAxisToGameLogicInfo : public FInputToGameLogicInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicVarFloat FloatVarName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnterValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExitValue;
    
    FAxisToGameLogicInfo();
};


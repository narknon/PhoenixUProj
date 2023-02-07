#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Name_GameLogicRealm.h"
#include "ActionToGameLogicInfo.h"
#include "AxisToGameLogicInfo.h"
#include "Name_ControlMapperAction.h"
#include "Name_ControlMapperAxis.h"
#include "ControlMapperSettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Input)
class CONTROLMAPPER_API UControlMapperSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicRealm UsesRealm;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName_ControlMapperAction, FActionToGameLogicInfo> ActionToGameLogicBool;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName_ControlMapperAxis, FAxisToGameLogicInfo> AxisToGameLogicBool;
    
    UControlMapperSettings();
};


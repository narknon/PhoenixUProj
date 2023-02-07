#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ERPGEffect.h"
#include "MultiFXPlus.h"
#include "RPGSettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class URPGSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ERPGEffect, FMultiFXPlus> Effects;
    
    URPGSettings();
};


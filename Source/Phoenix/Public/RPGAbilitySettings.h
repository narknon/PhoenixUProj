#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RPGAbilitySettings.generated.h"

class URPGAbilityBase;

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class URPGAbilitySettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, TSoftObjectPtr<URPGAbilityBase>> RPGAbilityMap;
    
    URPGAbilitySettings();
};


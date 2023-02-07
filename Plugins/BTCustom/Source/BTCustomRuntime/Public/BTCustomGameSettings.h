#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BTCustomGameSettings.generated.h"

class UBTCustomGameSettings;

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class BTCUSTOMRUNTIME_API UBTCustomGameSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Actions;
    
    UBTCustomGameSettings();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UBTCustomGameSettings* GetInputSettings();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetActionNames(TArray<FName>& ActionNames) const;
    
};


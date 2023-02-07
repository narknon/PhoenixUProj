#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AutomationEnvironment.generated.h"

UCLASS(Blueprintable, Config=Game)
class UAutomationEnvironment : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> EnvironmentSettings;
    
public:
    UAutomationEnvironment();
};


#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "MastermindSettings.generated.h"

class UMastermindActorComponent;
class UMastermindDebugCommandManager;

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Mastermind)
class MASTERMIND_API UMastermindSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, NoClear, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UMastermindDebugCommandManager> MastermindDebugCommandManagerClass;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MastermindTickInterval;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, NoClear, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UMastermindActorComponent> MastermindActorComponentClass;
    
protected:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsActivatedByDefault;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MastermindTCPPort;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxClientConnections;
    
public:
    UMastermindSettings();
};


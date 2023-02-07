#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "UObject/Interface.h"
#include "QueryFinishedData.h"
#include "SocialResponse.h"
#include "SocialReasoning_Interface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class USocialReasoning_Interface : public UInterface {
    GENERATED_BODY()
};

class ISocialReasoning_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RunEQS_FindStations(EEnvQueryRunMode::Type RunMode, FQueryFinishedData& QueryFinishedDelegate);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RunEQS_FindSocialReasonings(EEnvQueryRunMode::Type RunMode, FQueryFinishedData& QueryFinishedDelegate);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayerSighted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool Nevermind();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool Goodbye();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExcuseMe();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ConverseWithProxy(FSocialResponse& SocialResponse);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Converse(FSocialResponse& SocialResponse);
    
};


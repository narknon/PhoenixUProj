#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "FireInterface.generated.h"

class UIncendioComponent;

UINTERFACE(Blueprintable, MinimalAPI)
class UFireInterface : public UInterface {
    GENERATED_BODY()
};

class IFireInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool StartFire(float Amount, FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFireExtinguished();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFailedToLight();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCompletelyCharred();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCaughtFire(UIncendioComponent* IncendioComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAttemptToSetOnFire(FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsPointOnFire(FVector Point, bool& OnFire);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IncreaseFire(float increaseAmount, FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool DecreaseFire(float decreaseAmount);
    
};


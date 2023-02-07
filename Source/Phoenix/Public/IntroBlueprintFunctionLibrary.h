#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EIntroCheckpoint.h"
#include "IntroBlueprintFunctionLibrary.generated.h"

class UObject;

UCLASS(Blueprintable)
class UIntroBlueprintFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UIntroBlueprintFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static void SetLoadingRootLevel(bool bLoadingRootLevel);
    
    UFUNCTION(BlueprintCallable)
    static void SetCheating(bool bCheating);
    
    UFUNCTION(BlueprintCallable)
    static bool IsLoadingRootLevel(bool bReset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsCheating();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void IntroStart(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void IntroSave(UObject* WorldContextObject, EIntroCheckpoint Checkpoint, FVector PlayerSpawnLocation);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void IntroEnd(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EIntroCheckpoint GetIntroCheckpoint();
    
};


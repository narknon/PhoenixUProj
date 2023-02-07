#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/EngineBaseTypes.h"
#include "InputCoreTypes.h"
#include "ETestSuccess.h"
#include "MastermindCommandResult.h"
#include "MastermindProgressUpdate.h"
#include "MastermindTestResult.h"
#include "MastermindTestResultMessage.h"
#include "MastermindBPLibrary.generated.h"

class UMastermindJsonObject;
class UObject;

UCLASS(Blueprintable, MinimalAPI)
class UMastermindBPLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMastermindBPLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static void SimulateTappedInput(const UObject* InWorldContextObject, FKey InInputKey);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static void SimulateInput(const UObject* InWorldContextObject, FKey InInputKey, EInputEvent InInputEvent);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static void SimulateAxis(const UObject* InWorldContextObject, FKey InInputKey, float InDelta);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static void MastermindSendTestResults(const UObject* InWorldContextObject, const TArray<FMastermindTestResult>& InTestResults);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static void MastermindSendTestResultMessage(const UObject* InWorldContextObject, const FMastermindTestResultMessage& InResult);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static void MastermindSendTestResult(const UObject* InWorldContextObject, const FString& InName, bool bInIsSuccess);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static void MastermindSendStepResult(const UObject* InWorldContextObject, const FString& InMessage, bool bInIsSuccess, ETestSuccess InTestSuccess, const TArray<FString>& InArtifacts, const UMastermindJsonObject* InData);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static void MastermindSendProgressUpdateMessage(const UObject* InWorldContextObject, const FMastermindProgressUpdate& InUpdate);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static void MastermindSendProgressUpdate(const UObject* InWorldContextObject, const FString& InMessage);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static void MastermindSendCommandResultMessage(const UObject* InWorldContextObject, const FMastermindCommandResult& InResult);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static FMastermindTestResult CreateMastermindTestResult(const UObject* InWorldContextObject, const FString& InName, bool bInIsSuccess);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static FMastermindProgressUpdate CreateMastermindProgressUpdate(const UObject* InWorldContextObject, const FString& InMessage);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static FMastermindCommandResult CreateMastermindCommandResult(const UObject* InWorldContextObject, const FString& InMessage, bool bInIsSuccess, ETestSuccess InTestSuccess, const TArray<FString>& InArtifacts, const UMastermindJsonObject* InData);
    
};


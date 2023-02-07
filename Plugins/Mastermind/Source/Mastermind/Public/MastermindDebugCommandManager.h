#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MastermindMessage.h"
#include "MastermindDebugCommandManager.generated.h"

UCLASS(Blueprintable)
class MASTERMIND_API UMastermindDebugCommandManager : public UObject {
    GENERATED_BODY()
public:
    UMastermindDebugCommandManager();
    UFUNCTION(BlueprintCallable)
    void SetSessionId(const FString& InSessionId);
    
    UFUNCTION(BlueprintCallable)
    void SetBuild(const FString& InBuild);
    
protected:
    UFUNCTION(BlueprintCallable)
    static void SendMastermindMessage(const FMastermindMessage& InMastermindMessage);
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void QATakeScreenshot(const FString& InFilename);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAHangGame();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGameIsReady();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QADelayedConsoleCommand(const FString& InCommand, int32 InDelayTime);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QACreateLargeLogResponse();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QACreateArtifactFolder(const FString& InData, const FString& InFilename, int32 InNumArtifacts);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QACreateArtifact(const FString& InData, const FString& InFilename);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QACrashGame();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAConsoleCommand(const FString& InCommand);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAAssertVerify(bool bInIsSuccess);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAAssertEnsure(bool bInIsSuccess);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAAssertCheck(bool bInIsSuccess);
    
    UFUNCTION(BlueprintCallable)
    void QAAppendToFile(const FString& inString, const FString& InFilename);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Exec)
    void PMMC(int32 InPlayerIndex, const FString& InCommand);
    
    UFUNCTION(BlueprintCallable)
    bool NativeIsGameReady() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Exec)
    void MMC(const FString& InCommand);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool IsGameReady() const;
    
    UFUNCTION(BlueprintCallable)
    void DoMMC(const FString& InCommand, int32 InPlayerIndex);
    
};


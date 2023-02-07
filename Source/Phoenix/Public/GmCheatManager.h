#pragma once
#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "GmCheatManager.generated.h"

UCLASS(Blueprintable)
class UGmCheatManager : public UCheatManager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UCheatManager*> OtherCheatManagers;
    
public:
    UGmCheatManager();
    UFUNCTION(BlueprintCallable, Exec)
    void QARunScalabilityAutomationTest(int32 QualityPreset, const FString& TestName) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void QARunMultiplePointOfInterestAutomationTest(const FString& TestName) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void QARunMemoryAutomationTest(const FString& TestName) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void QARunLoadTimingsAutomationTest(const FString& TestName) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void QARunConjurationPerformanceTest(const FString& TestName) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void QARunBroomFlightAutomationTest(const FString& Command) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void QARunAutomationTest(const FString& TestName) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetEnvironmentInformation(int32 Index);
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAGetBeaconList();
    
    UFUNCTION(BlueprintCallable, Exec)
    void QAConsoleCommand(const FString& Command);
    
    UFUNCTION(BlueprintCallable, Exec)
    void BICaptureObjListMemory(const FString& Label);
    
    UFUNCTION(BlueprintCallable, Exec)
    void BICaptureLLM(const FString& Label);
    
};


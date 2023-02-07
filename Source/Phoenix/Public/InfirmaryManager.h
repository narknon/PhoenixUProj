#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TimeEvent.h"
#include "EInfirmaryPriority.h"
#include "InfirmaryEventDelegateDelegate.h"
#include "InfirmaryStudentStatus.h"
#include "InfirmaryManager.generated.h"

class UInfirmaryManager;

UCLASS(Blueprintable)
class UInfirmaryManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInfirmaryEventDelegate StudentAddedToInfirmary;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInfirmaryEventDelegate StudentRemovedToInfirmary;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInfirmaryStudentStatus> StudentList;
    
public:
    UInfirmaryManager();
private:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
public:
    UFUNCTION(BlueprintCallable)
    bool IsStudentIn(const FString& UniqueId);
    
private:
    UFUNCTION(BlueprintCallable)
    void HourlyCheck(const FTimeEvent& InTimeEvent);
    
public:
    UFUNCTION(BlueprintCallable)
    void GetStudents(TArray<FString>& OutStudents);
    
    UFUNCTION(BlueprintCallable)
    static UInfirmaryManager* Get();
    
    UFUNCTION(BlueprintCallable)
    void AddStudent(const FString& UniqueId, int64 SecondsInTheInfirmary, EInfirmaryPriority Priority);
    
};


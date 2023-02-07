#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EUtilityTrackedErrorType.h"
#include "UtilityTrackedErrorManager.generated.h"

class AActor;
class UUtilityTrackedErrorManager;

UCLASS(Blueprintable)
class BTUTILITYAI_API UUtilityTrackedErrorManager : public UObject {
    GENERATED_BODY()
public:
    UUtilityTrackedErrorManager();
    UFUNCTION(BlueprintCallable)
    void ResetError_Type(const AActor* InOwner, EUtilityTrackedErrorType InType);
    
    UFUNCTION(BlueprintCallable)
    void ResetError_NameType(const AActor* InOwner, FName InName, EUtilityTrackedErrorType InType);
    
    UFUNCTION(BlueprintCallable)
    void ResetError_NameAccessory(const AActor* InOwner, FName InName, const AActor* InAccessory);
    
    UFUNCTION(BlueprintCallable)
    void ResetError_Name(const AActor* InOwner, FName InName);
    
    UFUNCTION(BlueprintCallable)
    void ResetError_AccessoryType(const AActor* InOwner, const AActor* InAccessory, EUtilityTrackedErrorType InType);
    
    UFUNCTION(BlueprintCallable)
    void ResetError_Accessory(const AActor* InOwner, const AActor* InAccessory);
    
    UFUNCTION(BlueprintCallable)
    void ResetError(const AActor* InOwner, FName InName, const AActor* InAccessory, EUtilityTrackedErrorType InType);
    
    UFUNCTION(BlueprintCallable)
    void ReportError(const AActor* InOwner, FName InName, const AActor* InAccessory, EUtilityTrackedErrorType InType, float InTimeToReset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReportedError_Type(const AActor* InOwner, EUtilityTrackedErrorType InType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReportedError_NameType(const AActor* InOwner, FName InName, EUtilityTrackedErrorType InType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReportedError_NameAccessory(const AActor* InOwner, FName InName, const AActor* InAccessory) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReportedError_Name(const AActor* InOwner, FName InName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReportedError_AccessoryType(const AActor* InOwner, const AActor* InAccessory, EUtilityTrackedErrorType InType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReportedError_Accessory(const AActor* InOwner, const AActor* InAccessory) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReportedError(const AActor* InOwner, FName InName, const AActor* InAccessory, EUtilityTrackedErrorType InType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAccessories_Type(const AActor* InOwner, EUtilityTrackedErrorType InType, TSet<AActor*>& OutAccessories) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAccessories_NameType(const AActor* InOwner, FName InName, EUtilityTrackedErrorType InType, TSet<AActor*>& OutAccessories) const;
    
    UFUNCTION(BlueprintCallable)
    static UUtilityTrackedErrorManager* Get();
    
};


#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HermesBPDelegateHandle.h"
#include "MunitionImpactData.h"
#include "TargetedByMunition.h"
#include "MunitionsBPLibrary.generated.h"

class AMunitionType_Base;
class UObject;

UCLASS(Blueprintable)
class UMunitionsBPLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesTargetedByMunitionWithDataDelegate, const UObject*, Caller, const FTargetedByMunition&, TargetedByMunitionWithData);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesMunitionTypeDelegate, const UObject*, Caller, const AMunitionType_Base*, MunitionType);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesMunitionImpactDataDelegate, const UObject*, Caller, const FMunitionImpactData&, MunitionImpactData);
    
    UMunitionsBPLibrary();
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedTargetedByMunitionWithData(const FString& Name, const UObject* Owner, const UObject* Caller, const FTargetedByMunition& TargetedByMunitionWithData);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedMunitionType(const FString& Name, const UObject* Owner, const UObject* Caller, const AMunitionType_Base* MunitionType);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedMunitionImpactData(const FString& Name, const UObject* Owner, const UObject* Caller, const FMunitionImpactData& MunitionImpactData);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllTargetedByMunitionWithData(const FString& Name, const UObject* Caller, const FTargetedByMunition& TargetedByMunitionWithData);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllMunitionType(const FString& Name, const UObject* Caller, const AMunitionType_Base* MunitionType);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllMunitionImpactData(const FString& Name, const UObject* Caller, const FMunitionImpactData& MunitionImpactData);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindTargetedByMunitionWithData(UMunitionsBPLibrary::FHermesTargetedByMunitionWithDataDelegate Delegate_TargetedByMunitionWithData, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindMunitionType(UMunitionsBPLibrary::FHermesMunitionTypeDelegate Delegate_MunitionType, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindMunitionImpactData(UMunitionsBPLibrary::FHermesMunitionImpactDataDelegate Delegate_MunitionImpactData, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
};


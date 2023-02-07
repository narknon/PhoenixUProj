#include "MunitionsBPLibrary.h"

class AMunitionType_Base;
class UObject;

void UMunitionsBPLibrary::HermesExecuteOwnedTargetedByMunitionWithData(const FString& Name, const UObject* Owner, const UObject* Caller, const FTargetedByMunition& TargetedByMunitionWithData) {
}

void UMunitionsBPLibrary::HermesExecuteOwnedMunitionType(const FString& Name, const UObject* Owner, const UObject* Caller, const AMunitionType_Base* MunitionType) {
}

void UMunitionsBPLibrary::HermesExecuteOwnedMunitionImpactData(const FString& Name, const UObject* Owner, const UObject* Caller, const FMunitionImpactData& MunitionImpactData) {
}

void UMunitionsBPLibrary::HermesExecuteAllTargetedByMunitionWithData(const FString& Name, const UObject* Caller, const FTargetedByMunition& TargetedByMunitionWithData) {
}

void UMunitionsBPLibrary::HermesExecuteAllMunitionType(const FString& Name, const UObject* Caller, const AMunitionType_Base* MunitionType) {
}

void UMunitionsBPLibrary::HermesExecuteAllMunitionImpactData(const FString& Name, const UObject* Caller, const FMunitionImpactData& MunitionImpactData) {
}

void UMunitionsBPLibrary::HermesBindTargetedByMunitionWithData(UMunitionsBPLibrary::FHermesTargetedByMunitionWithDataDelegate Delegate_TargetedByMunitionWithData, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UMunitionsBPLibrary::HermesBindMunitionType(UMunitionsBPLibrary::FHermesMunitionTypeDelegate Delegate_MunitionType, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UMunitionsBPLibrary::HermesBindMunitionImpactData(UMunitionsBPLibrary::FHermesMunitionImpactDataDelegate Delegate_MunitionImpactData, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

UMunitionsBPLibrary::UMunitionsBPLibrary() {
}


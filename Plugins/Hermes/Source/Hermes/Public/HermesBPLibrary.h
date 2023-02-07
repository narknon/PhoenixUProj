#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/EngineTypes.h"
#include "HermesBPDelegateHandle.h"
#include "HermesBPLibrary.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable)
class HERMES_API UHermesBPLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesVectorDelegate, const UObject*, Caller, const FVector&, Vector);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesIntDelegate, const UObject*, Caller, int32, Int);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesHitResultDelegate, const UObject*, Caller, const FHitResult&, HitResult);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesGuidDelegate, const UObject*, Caller, const FGuid&, Guid);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesFTextDelegate, const UObject*, Caller, const FText&, Text);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesFStringDelegate, const UObject*, Caller, const FString&, String);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesFNameDelegate, const UObject*, Caller, const FName&, String);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesFloatDelegate, const UObject*, Caller, float, Float);
    DECLARE_DYNAMIC_DELEGATE_OneParam(FHermesEventDelegate, const UObject*, Caller);
    DECLARE_DYNAMIC_DELEGATE_ThreeParams(FHermesDoubleIntDelegate, const UObject*, Caller, int32, Int1, int32, Int2);
    DECLARE_DYNAMIC_DELEGATE_ThreeParams(FHermesDoubleFStringDelegate, const UObject*, Caller, const FString&, String1, const FString&, String2);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesAActorDelegate, const UObject*, Caller, const AActor*, Actor);
    
    UHermesBPLibrary();
    UFUNCTION(BlueprintCallable)
    static void HermesUnbind(const FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedVector(const FString& Name, const UObject* Owner, const UObject* Caller, const FVector& Vector);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedInt(const FString& Name, const UObject* Owner, const UObject* Caller, int32 Int);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedHitResult(const FString& Name, const UObject* Owner, const UObject* Caller, const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedGuid(const FString& Name, const UObject* Owner, const UObject* Caller, const FGuid& Guid);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedFText(const FString& Name, const UObject* Owner, const UObject* Caller, const FText& Text);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedFString(const FString& Name, const UObject* Owner, const UObject* Caller, const FString& String);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedFName(const FString& Name, const UObject* Owner, const UObject* Caller, const FName& String);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedFloat(const FString& Name, const UObject* Owner, const UObject* Caller, float Float);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedEvent(const FString& Name, const UObject* Owner, const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedDoubleInt(const FString& Name, const UObject* Owner, const UObject* Caller, int32 Int, int32 Int2);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedDoubleFString(const FString& Name, const UObject* Owner, const UObject* Caller, const FString& String1, const FString& String2);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedAActor(const FString& Name, const UObject* Owner, const UObject* Caller, const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllVector(const FString& Name, const UObject* Caller, const FVector& Vector);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllInt(const FString& Name, const UObject* Caller, int32 Int);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllHitResult(const FString& Name, const UObject* Caller, const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllGuid(const FString& Name, const UObject* Caller, const FGuid& Guid);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllFText(const FString& Name, const UObject* Caller, const FText& Text);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllFString(const FString& Name, const UObject* Caller, const FString& String);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllFName(const FString& Name, const UObject* Caller, const FName& String);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllFloat(const FString& Name, const UObject* Caller, float Float);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllEvent(const FString& Name, const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllDoubleInt(const FString& Name, const UObject* Caller, int32 Int1, int32 Int2);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllDoubleFString(const FString& Name, const UObject* Caller, const FString& String1, const FString& String2);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllAActor(const FString& Name, const UObject* Caller, const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindVector(UHermesBPLibrary::FHermesVectorDelegate Delegate_Vector, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindInt(UHermesBPLibrary::FHermesIntDelegate Delegate_Int, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindHitResult(UHermesBPLibrary::FHermesHitResultDelegate Delegate_HitResult, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindGuid(UHermesBPLibrary::FHermesGuidDelegate Delegate_Guid, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindFText(UHermesBPLibrary::FHermesFTextDelegate Delegate_FText, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindFString(UHermesBPLibrary::FHermesFStringDelegate Delegate_FString, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindFName(UHermesBPLibrary::FHermesFNameDelegate Delegate_FName, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindFloat(UHermesBPLibrary::FHermesFloatDelegate Delegate_Float, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindEvent(const UHermesBPLibrary::FHermesEventDelegate& Delegate_Event, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindDoubleInt(UHermesBPLibrary::FHermesDoubleIntDelegate Delegate_DoubleInt, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindDoubleFString(UHermesBPLibrary::FHermesDoubleFStringDelegate Delegate_DoubleFString, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindAActor(UHermesBPLibrary::FHermesAActorDelegate Delegate_AActor, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
};


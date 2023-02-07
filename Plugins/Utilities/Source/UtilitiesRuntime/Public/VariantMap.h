#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "VariantMapHandle.h"
#include "VariantMap.generated.h"

class UVariantMap;

UCLASS(Blueprintable)
class UTILITIESRUNTIME_API UVariantMap : public UObject {
    GENERATED_BODY()
public:
    UVariantMap();
    UFUNCTION(BlueprintCallable)
    static bool VariantExists_FromHandle(FVariantMapHandle VarMapHandle, FName Name);
    
    UFUNCTION(BlueprintCallable)
    bool VariantExists(FName Name);
    
    UFUNCTION(BlueprintCallable)
    static UVariantMap* RetrieveVariantMap(FVariantMapHandle VarMapHandle);
    
    UFUNCTION(BlueprintCallable)
    static FName GetVariantName_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FName DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    FName GetVariantName(FName Name, FName DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetVariantInt32_FromHandle(FVariantMapHandle VarMapHandle, FName Name, int32 DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    int32 GetVariantInt32(FName Name, int32 DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    static FVector GetVariantFVector_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FVector DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    static FVector2D GetVariantFVector2D_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FVector2D DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetVariantFVector2D(FName Name, FVector2D DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    FVector GetVariantFVector(FName Name, FVector DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    static FTransform GetVariantFTransform_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FTransform DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    FTransform GetVariantFTransform(FName Name, FTransform DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    static FString GetVariantFString_FromHandle(FVariantMapHandle VarMapHandle, FName Name, const FString& DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    FString GetVariantFString(FName Name, const FString& DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    static FRotator GetVariantFRotator_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FRotator DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    FRotator GetVariantFRotator(FName Name, FRotator DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    static float GetVariantFloat_FromHandle(FVariantMapHandle VarMapHandle, FName Name, float DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    float GetVariantFloat(FName Name, float DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    static bool GetVariantBool_FromHandle(FVariantMapHandle VarMapHandle, FName Name, bool DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    bool GetVariantBool(FName Name, bool DefaultValue, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    static FVariantMapHandle GetHandle_FromObject(UObject* InObject);
    
    UFUNCTION(BlueprintCallable)
    FVariantMapHandle GetHandle();
    
    UFUNCTION(BlueprintCallable)
    static FVariantMapHandle DuplicateVariantMap(FVariantMapHandle VarMapHandle, bool bDestroy);
    
    UFUNCTION(BlueprintCallable)
    static FVariantMapHandle DestroyVariantMap(FVariantMapHandle VarMapHandle);
    
    UFUNCTION(BlueprintCallable)
    static FVariantMapHandle CreateVariantMap();
    
    UFUNCTION(BlueprintCallable)
    static void AddVariantName_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FName Value);
    
    UFUNCTION(BlueprintCallable)
    void AddVariantName(FName Name, FName Value);
    
    UFUNCTION(BlueprintCallable)
    static void AddVariantInt32_FromHandle(FVariantMapHandle VarMapHandle, FName Name, int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void AddVariantInt32(FName Name, int32 Value);
    
    UFUNCTION(BlueprintCallable)
    static void AddVariantFVector_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FVector Value);
    
    UFUNCTION(BlueprintCallable)
    static void AddVariantFVector2D_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FVector2D Value);
    
    UFUNCTION(BlueprintCallable)
    void AddVariantFVector2D(FName Name, FVector2D Value);
    
    UFUNCTION(BlueprintCallable)
    void AddVariantFVector(FName Name, FVector Value);
    
    UFUNCTION(BlueprintCallable)
    static void AddVariantFTransform_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FTransform Value);
    
    UFUNCTION(BlueprintCallable)
    void AddVariantFTransform(FName Name, FTransform Value);
    
    UFUNCTION(BlueprintCallable)
    static void AddVariantFString_FromHandle(FVariantMapHandle VarMapHandle, FName Name, const FString& Value);
    
    UFUNCTION(BlueprintCallable)
    void AddVariantFString(FName Name, const FString& Value);
    
    UFUNCTION(BlueprintCallable)
    static void AddVariantFRotator_FromHandle(FVariantMapHandle VarMapHandle, FName Name, FRotator Value);
    
    UFUNCTION(BlueprintCallable)
    void AddVariantFRotator(FName Name, FRotator Value);
    
    UFUNCTION(BlueprintCallable)
    static void AddVariantFloat_FromHandle(FVariantMapHandle VarMapHandle, FName Name, float Value);
    
    UFUNCTION(BlueprintCallable)
    void AddVariantFloat(FName Name, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void AddVariantBool_FromHandle(FVariantMapHandle VarMapHandle, FName Name, bool Value);
    
    UFUNCTION(BlueprintCallable)
    void AddVariantBool(FName Name, bool Value);
    
    UFUNCTION(BlueprintCallable)
    static void AbsorbVariantMap_FromHandle(FVariantMapHandle MasterVarMapHandle, FVariantMapHandle VarMapHandleToAbsorb);
    
    UFUNCTION(BlueprintCallable)
    void AbsorbVariantMap(UVariantMap* VarMapHandleToAbsorb);
    
};


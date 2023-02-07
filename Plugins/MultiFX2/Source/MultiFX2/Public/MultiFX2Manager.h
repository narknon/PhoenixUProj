#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "MultiFX2DataArray.h"
#include "MultiFX2Handle.h"
#include "MultiFX2Var.h"
#include "MultiFX2Manager.generated.h"

class AActor;
class UMultiFX2Asset;

UCLASS(Blueprintable)
class MULTIFX2_API UMultiFX2Manager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FMultiFX2DataArray> FXDataArray;
    
    UMultiFX2Manager();
private:
    UFUNCTION(BlueprintCallable)
    void UpdateFX();
    
public:
    UFUNCTION(BlueprintCallable)
    static FMultiFX2Handle SpawnFXAsset(const UMultiFX2Asset* FXAsset, UObject* Target, AActor* Instigator, FVector Location, FRotator Rotation, FName AttachPointName);
    
    UFUNCTION(BlueprintCallable)
    static FMultiFX2Handle SpawnFXArray(const TArray<FMultiFX2Var>& Var, UObject* Target, AActor* Instigator, FVector Location, FRotator Rotation, FName AttachPointName);
    
    UFUNCTION(BlueprintCallable)
    static FMultiFX2Handle SpawnFX(const FMultiFX2Var& Var, UObject* Target, AActor* Instigator, FVector Location, FRotator Rotation, FName AttachPointName);
    
    UFUNCTION(BlueprintCallable)
    static void SetRotation(const FMultiFX2Handle& InHandle, const FRotator& InRotation);
    
    UFUNCTION(BlueprintCallable)
    static void SetLocation(const FMultiFX2Handle& InHandle, const FVector& InLocation);
    
    UFUNCTION(BlueprintCallable)
    static void SetFootprintLifetimeScale(float Scale);
    
    UFUNCTION(BlueprintCallable)
    static void SetCustomTimeDilation(const FMultiFX2Handle& InHandle, float Dilation);
    
    UFUNCTION(BlueprintCallable)
    static bool IsLooping(const FMultiFX2Handle& InHandle);
    
    UFUNCTION(BlueprintCallable)
    static bool IsActive(const FMultiFX2Handle& InHandle);
    
    UFUNCTION(BlueprintCallable)
    static void DestroyFXHandle(const FMultiFX2Handle& InHandle, bool bImmediate);
    
};


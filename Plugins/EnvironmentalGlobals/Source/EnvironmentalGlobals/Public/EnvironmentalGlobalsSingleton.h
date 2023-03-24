#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "EnvironmentalGlobals.h"
#include "EnvironmentalGlobalsIndoors.h"
#include "EnvironmentalGlobalsSeason.h"
#include "EnvironmentalGlobalsVelocityTracker.h"
#include "EnvironmentalGlobalsSingleton.generated.h"

class UMaterialParameterCollection;
class UNiagaraParameterCollection;
class UObject;

UCLASS(Blueprintable, Transient)
class ENVIRONMENTALGLOBALS_API AEnvironmentalGlobalsSingleton : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobals Globals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MaterialParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraParameterCollection* NiagaraParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsVelocityTracker PlayerVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsVelocityTracker CameraVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsIndoors AccumulateIndoors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDirty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDiscontinuity;
    
public:
    AEnvironmentalGlobalsSingleton(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetEnvironmentalGlobals(UObject* WorldContextObject, FEnvironmentalGlobals& EnvironmentalGlobals);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void EnvironmentalGlobalsSetExtraVector(UObject* WorldContextObject, FName Name, FVector Value, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void EnvironmentalGlobalsSetExtraScalar(UObject* WorldContextObject, FName Name, float Value, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void EnvironmentalGlobalsSetExtraColor(UObject* WorldContextObject, FName Name, FLinearColor Value, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void EnvironmentalGlobalsGetSeason(UObject* WorldContextObject, FEnvironmentalGlobalsSeason& Season, bool bAllowOverrides);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void EnvironmentalGlobalsGetExtraVector(UObject* WorldContextObject, FName Name, FVector& Value, bool& bExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void EnvironmentalGlobalsGetExtraScalar(UObject* WorldContextObject, FName Name, float& Value, bool& bExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void EnvironmentalGlobalsGetExtraColor(UObject* WorldContextObject, FName Name, FLinearColor& Value, bool& bExists);
    
};

